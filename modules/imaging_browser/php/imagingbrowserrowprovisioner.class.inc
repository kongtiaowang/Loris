<?php declare(strict_types=1);
/**
 * This file implements a data provisioner to get all possible rows
 * for the imaging browser menu page.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Imaging
 * @author     Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */

namespace LORIS\imaging_browser;

/**
 * This class implements a data provisioner to get all possible rows
 * for the imaging browser menu page.
 *
 * PHP Version 7
 *
 * @category   Behavioural
 * @package    Main
 * @subpackage Imaging
 * @author     Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris/
 */
class ImagingBrowserRowProvisioner extends \LORIS\Data\Provisioners\DBRowProvisioner
{
    /**
     * Create an ImagingBrowserRowProvisioner, which gets rows for
     * the imaging browser menu table.
     *
     * @throws \ConfigurationException
     */
    // IBIS SPECIFIC OVERRIDE CODE
    function __construct()
    {
        $config = \NDB_Config::singleton();
        $DB     = \NDB_Factory::singleton()->database();

        // ===========================================================
        // Get the different scan types to be displayed in data table
        // ===========================================================

        // Grep all the different scan types present in mri_scan_type
        $all_scan_types = \Utility::getScanTypeList();


        //---------------------------------------------------------------------//
        // Build associate array of all groups for which we want info          //
        //---------------------------------------------------------------------//
        $toTable_scan_type_groups = $config->getSetting('tblScanTypeGroups');
        $toTable_scan_type_groups = explode(',', $toTable_scan_type_groups);
        $allGroupsQuery = sprintf(
            "SELECT DISTINCT mstg.Description, mstg.Name, mstg.MriScanTypeGroupID, mgqpt.Threshold, mst.ID, mst.Scan_type
             FROM mri_scan_type mst
             JOIN mri_scan_type_groups_rel mstgr ON (mstgr.MriScanTypeID=mst.ID)
             JOIN mri_scan_type_groups mstg ON (mstg.MriScanTypeGroupID=mstgr.MriScanTypeGroupID)
             JOIN mri_group_qc_pass_threshold mgqpt ON (mgqpt.MriScanTypeGroupID=mstg.MriScanTypeGroupID)
             WHERE mstg.Name IN (%s)
            ",
            implode(",", array_fill(0, count($toTable_scan_type_groups), '?'))
        );
        $toTable_scan_type_groups = $DB->pselect($allGroupsQuery, array_values($toTable_scan_type_groups));

        //----------------------------------------------------------------//
        // Build associative array of properties for each scan type group //
        //----------------------------------------------------------------//
        foreach ($toTable_scan_type_groups as $row) {
            $scanTypeGroups[$row['Name']] = array(
                'Description'        => $row['Description'],
                'MriScanTypeGroupID' => $row['MriScanTypeGroupID'],
                'Threshold'          => $row['Threshold']
            );
            $scanTypeGroups[$row['Name']]['ScanTypeIDs'][]      = $row['ID'];
            $toTable_scan_types[$row['ID']]                     = $row['Scan_type'];
        }

        // Get the intersection between all the scan types and those
        // that are desired to go into imaging browser table, based on
        // array values rather than keys (hence the array_flip), then flip
        // the resulting array back to revert it to a key/value (i.e.
        // acquisition protocol ID/scan type) combination.
//        $toTable_scan_types = $config->getSetting('tblScanTypes');
        $scan_id_types      = array_flip(
            array_intersect_key(
                array_flip($all_scan_types),
                array_flip($toTable_scan_types)
            )
        );

        // =======================================================
        // Create New Data Subquery
        // =======================================================

        if (!empty($scan_id_types)) {
            $isFirst      = true;
            $acqpif       = '';
            $newQueryCase = '';
            foreach ($scan_id_types as $key => $value) {
                if ($isFirst) {
                    $acqpif       = "IF(FIND_IN_SET({$key},GROUP_CONCAT(
                        DISTINCT AcquisitionProtocolID))>0 ";
                    $newQueryCase = "AND(FIND_IN_SET({$key},GROUP_CONCAT(
                        DISTINCT AcquisitionProtocolID))";
                } else {
                    $acqpif       .= "OR FIND_IN_SET({$key},GROUP_CONCAT(
                        DISTINCT AcquisitionProtocolID))>0 ";
                    $newQueryCase .= " OR FIND_IN_SET({$key},GROUP_CONCAT(
                        DISTINCT AcquisitionProtocolID))";
                }
                $isFirst = false;
            }
            $acqpif       .= ",'new','')";
            $newQueryCase .= ")";
        } else {
            $acqpif       = "'new'";
            $newQueryCase ='';
        }

        $NewDataSubquery = "
            CASE
                COALESCE(Max(fqc.QCLastChangeTime), 'new')
                WHEN 'new' THEN {$acqpif}
                WHEN ''    THEN {$acqpif}
                WHEN NULL  THEN {$acqpif}
                ELSE ''
            END";

        // =====================================================
        // Create Pending Fail and Pending New subquery
        // =====================================================
        $case_desc     = array();
        $qc            = array();
        $pass          = array();
        $coalesce_desc = array();

        $PendingFailSubquery = "
            CASE s.MRIQCStatus
                WHEN 'Fail' THEN
                    IF(s.MRIQCPending='Y', 'Pending Fail', 'Fail')
                WHEN 'Pass' THEN
                    IF(s.MRIQCPending='Y', 'Pending Pass', 'Pass')
                ELSE s.MRIQCStatus
            END
            ";

        $PendingNewquery = "
            CASE
                WHEN s.MRIQCPending='Y' THEN 'P'
                WHEN MAX(fqc.QCFirstChangeTime) IS NULL $newQueryCase THEN  'N'
            END";

        // ====================================================
        // Create left join to include QC status for specific
        // scans in the data table
        // ====================================================

        //----------------------------------------------------------------------------//
        // For each group, build (dynamically) a table that will list the QC value of //
        // the scans in that group, for that specific session                         //
        //----------------------------------------------------------------------------//
        $left_joins = "";
        foreach ($scanTypeGroups as $groupName => $properties) {
            // Table alias for the dynamically created table
            $leftJoinTableAlias[$groupName] = $DB->escape("{$groupName}pass");
            // Column name for the column that contains the Qc value of the scans in that group
            $sumColumnName[$groupName]      = $DB->escape("{$groupName}QCValue");
            // Name of the header in the imaging browser's result table for the column that indicates
            // whether Qc for that group is 'Passed', 'Failed' or ''
            $headerName[$groupName]         = "{$properties['Description']}_QC_Status";

            // To compute the Qc value of the group, we compute the sum of each Qc value for each 'Passed' scan that
            // belongs to that group. The scan Qc value for a given scan type is found in mri_scan_type_qc_value.
            $left_joins .= "
                LEFT JOIN (
                    SELECT files.SessionID,
                           SUM(
                               CASE WHEN files_qcstatus.QCStatus = 'Pass' THEN mstqv.Value ELSE 0 END
                           ) as {$sumColumnName[$groupName]}
                    FROM files
                    JOIN files_qcstatus USING (FileID)
                    JOIN mri_scan_type_qc_value mstqv
                        ON (files.AcquisitionProtocolID=mstqv.MriScanTypeID)
                    JOIN mri_scan_type_groups_rel mstgr
                        ON (files.AcquisitionProtocolID=mstgr.MriScanTypeID)
                    JOIN mri_scan_type_groups mstg USING (MriScanTypeGroupID)
                    WHERE files_qcstatus.QCStatus IN ('Pass', 'Fail')
                    AND mstg.MriScanTypeGroupID = '{$properties['MriScanTypeGroupID']}'
                    GROUP BY files.SessionID
                ) {$leftJoinTableAlias[$groupName]} ON ({$leftJoinTableAlias[$groupName]}.SessionID=f.SessionID) ";
        }

        // ===============================================
        // Create modality subquery
        // ===============================================

        //-------------------------------------------------------------------------------------//
        // Set the final value that will appear in the imaging browser's column associated to  //
        // each group. To do this, we compare the total Qc value for that group with the       //
        // group's threshold found in mri_group_qc_pass_threshold:                             //
        // 1. If the total Qcvalue is NULL, then no scans within that group have been Qced, so //
        //    set the value to ''.                                                             //
        // 2. If total >= threshold, set value to 'Passed'.                                    //
        // 3. If total < Threshold, set value to 'Failed'.                                     //
        //-------------------------------------------------------------------------------------//
        foreach ($scanTypeGroups as $groupName => $properties) {
            $groupSubquery[$groupName]  = "
                CASE
                  WHEN ISNULL({$leftJoinTableAlias[$groupName]}.{$sumColumnName[$groupName]}) THEN ''
                  WHEN {$leftJoinTableAlias[$groupName]}.{$sumColumnName[$groupName]} >= {$properties['Threshold']} THEN 'Passed'
                  ELSE 'Failed'
                END AS {$headerName[$groupName]}
            ";
        }
        $groupSubquerySQL = implode(',',$groupSubquery);

        // =================================================
        // Final query
        // =================================================

        $sql = "SELECT
              p.Name as Site,
              c.PSCID as PSCID,
              c.CandID as DCCID,
              Project.Name as project,
              s.Visit_label as visitLabel,
              $PendingFailSubquery as Visit_QC_Status,
              DATE_FORMAT(MIN(pf.Value), \"%Y-%m-%d\") as First_Acquisition,
              FROM_UNIXTIME(MIN(f.InsertTime)) as First_Insertion,
              FROM_UNIXTIME(MAX(fqc.QCLastChangeTime)) as Last_QC,
              $NewDataSubquery as New_Data,
              GROUP_CONCAT(DISTINCT OutputType) as Links,
              s.ID as sessionID,
              GROUP_CONCAT(DISTINCT modality.Scan_type) as sequenceType,
              $PendingNewquery as pending,
              $groupSubquerySQL,
              s.CenterID as CenterID,
              c.Entity_type as entityType,
              s.ProjectID
            FROM psc AS p
              JOIN session s ON (s.CenterID=p.CenterID)
              JOIN candidate c ON (c.CandID=s.CandID)
              LEFT JOIN Project ON (s.ProjectID=Project.ProjectID)
              JOIN files f ON (f.SessionID=s.ID)
              LEFT JOIN files_qcstatus fqc ON (fqc.FileID=f.FileID)
              JOIN parameter_file pf ON (f.FileID=pf.FileID)
              JOIN parameter_type pt USING (ParameterTypeID)
              LEFT JOIN mri_scan_type modality ON
                (f.AcquisitionProtocolID=modality.ID)
              $left_joins
            WHERE
              s.Active = 'Y' AND
              f.FileType IN ('mnc', 'nii') AND
              pt.Name='acquisition_date'
            GROUP BY s.ID
            ORDER BY c.PSCID, s.Visit_label";

        error_log("SQL: $sql");

        parent::__construct(
            "SELECT
              p.Name as Site,
              c.PSCID as PSCID,
              c.CandID as DCCID,
              Project.Name as project,
              s.Visit_label as visitLabel,
              $PendingFailSubquery as Visit_QC_Status,
              DATE_FORMAT(MIN(pf.Value), \"%Y-%m-%d\") as First_Acquisition,
              FROM_UNIXTIME(MIN(f.InsertTime)) as First_Insertion,
              FROM_UNIXTIME(MAX(fqc.QCLastChangeTime)) as Last_QC,
              $NewDataSubquery as New_Data,
              GROUP_CONCAT(DISTINCT OutputType) as Links,
              s.ID as sessionID,
              GROUP_CONCAT(DISTINCT modality.Scan_type) as sequenceType,
              $PendingNewquery as pending,
              $groupSubquerySQL,
              s.CenterID as CenterID,
              c.Entity_type as entityType,
              s.ProjectID
            FROM psc AS p
              JOIN session s ON (s.CenterID=p.CenterID)
              JOIN candidate c ON (c.CandID=s.CandID)
              LEFT JOIN Project ON (s.ProjectID=Project.ProjectID)
              JOIN files f ON (f.SessionID=s.ID)
              LEFT JOIN files_qcstatus fqc ON (fqc.FileID=f.FileID)
              JOIN parameter_file pf ON (f.FileID=pf.FileID)
              JOIN parameter_type pt USING (ParameterTypeID)
              LEFT JOIN mri_scan_type modality ON
                (f.AcquisitionProtocolID=modality.ID)
              $left_joins
            WHERE
              s.Active = 'Y' AND
              f.FileType IN ('mnc', 'nii') AND
              pt.Name='acquisition_date'
            GROUP BY s.ID
            ORDER BY c.PSCID, s.Visit_label
            ",
            array()
        );
    }
    // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    /**
     * Returns an instance of an ImagingBrowserRow object for a given
     * table row.
     *
     * @param array $row The database row from the LORIS Database class.
     *
     * @return \LORIS\Data\DataInstance An instance representing this row.
     */
    public function getInstance($row) : \LORIS\Data\DataInstance
    {
        // XXX This should probably be updated to allow users
        // to access candidates who have any session at one of the
        // user's sites, but for now this maintains the previous
        // behaviour of requiring the registration site to match
        // one of the user's sites.
        $cid = (int )$row['CenterID'];
        $pid = (int )$row['ProjectID'];
        unset($row['CenterID']);
        unset($row['ProjectID']);
        return new ImagingBrowserRow($row, $cid, $pid);
    }
}
