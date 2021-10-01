<?php
/**
 * This file contains the Quality_Control class
 *
 * PHP Version 7
 *
 * @category Module
 * @package  Quality_Control
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris
 */
namespace LORIS\quality_control;

/**
 * Main class for quality control module corresponding to /quality_control/
 * endpoint.
 *
 * PHP Version 7
 *
 * @category Module
 * @package  Quality_Control
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris
 */
class Quality_Control extends \NDB_Menu_Filter
{
    public $AjaxModule = true;
    public $fieldOptions;

    /**
     * Check user permissions
     *
     * @param \User $user UserID
     *
     * @return bool
     * @throws \ConfigurationException
     */
    function _hasAccess(\User $user) : bool
    {
        // FIXME This module should have its own permission.
        return $user->hasPermission('data_team_helper');
    }

    /**
     * BEGIN OVERRIDE
     *
     * Function _getScanTypes has been rewritten for IBIS. Refer to IBIS PR#1178
     * for details on how it differs from the LORIS 20.0 version.
     */

    /**
     * Checks configuration module to find which scans are relevant
     * to the given project
     *
     * @return array $scan_types of desired scan types.
     */
    function _getScanTypes(): array
    {
        $config = \NDB_Config::singleton();
        $db     = \Database::singleton();

        //-------------------------------------------//
        // Build associative array of all scan types //
        //-------------------------------------------//
        $all_scan_types_2d = $db->pselect(
            "SELECT ID, Scan_type FROM mri_scan_type mri",
            array()
        );
        foreach ($all_scan_types_2d as $row) {
            $all_scan_types[$row['ID']] = $row['Scan_type'];
        }

        //---------------------------------------------------------------//
        // Build array of the scan types that belong to any of the scan  //
        // type groups listed in $toTable_scan_type_groups               //
        //---------------------------------------------------------------//
        $toTable_scan_type_groups = $config->getSetting('tblScanTypeGroups');
        $toTable_scan_type_groups = explode(',', $toTable_scan_type_groups);

        $query = sprintf(
            "
             SELECT DISTINCT ID, Scan_type
             FROM mri_scan_type mri
             JOIN mri_scan_type_groups_rel mstgr ON (mri.ID=mstgr.MriScanTypeID)
             JOIN mri_scan_type_groups mstg ON (mstgr.MriScanTypeGroupID=mstg.MriScanTypeGroupID)
             WHERE mstg.Name IN (%s)
            ",
            implode(",", array_fill(0, count($toTable_scan_type_groups), '?'))
        );
        $scan_types_in_all_groups_2d = $db->pselect($query, $toTable_scan_type_groups);
        foreach ($scan_types_in_all_groups_2d as $row) {
            $scan_types_in_all_groups[$row['ID']] = $row['Scan_type'];
        }

        // Get the intersection between all the scan types and those
        // that are desired to go into imaging browser table, based on
        // array values rather than keys (hence the array_flip), then flip
        // the resulting array back to revert it to a key/value (i.e.
        // acquisition protocol ID/scan type) combination.
        $scan_id_types =array_flip(
            array_intersect_key(
                array_flip($scan_types_in_all_groups),
                array_flip($all_scan_types)
            )
        );
        $scan_types    =[];

        foreach ($scan_id_types as $scan) {
            $scan_types[$scan] = $scan;
        }

        return $scan_types;
    }

    /**
     * END OVERRIDE
     */


    /**
     * BEGIN OVERRIDE
     *
     * Function _buildQuery has been rewritten for IBIS. Refer to IBIS PR#1178
     * for details on how it differs from the LORIS 20.0 version.
     */

    /**
     * Builds query for given modality. Works with t1w, t2w, dti.
     *
     * @param string $scan_type       One of 't1w', 't2w', 'dti'
     * @param string $mriPfColumn     Name of column to check in the MRI parameter form
     * @param string $mriPfTable      Name of the table that contains the MRI parameter form
     * @param string $acqID           Aquisition protocol ID for given modality
     * @param string $mriPfDoneValues Comma separated list of values indicating that a particular
     *                                scan modality was done in the MRI parameter form
     *
     * @return string $query for the given modality
     */
    function _buildQuery($scan_type, $mriPfColumn, $mriPfTable, $acqID, $mriPfDoneValues): string
    {
        $mriPfTableAlias ='';
        $noMriPf = 0;

        // Set the value of $mriPfTable to be the table alias used in
        // the SQL statement below
        switch ($mriPfTable) {
            case null:
                $noMriPf = 1;
                break;
            case 'mri_parameter_form_sa':
                $mriPfTableAlias = 'm_sa';
                break;
            case 'mri_parameter_form':
                $mriPfTableAlias = 'm';
                break;
            default: throw new \InvalidArgumentException("Unsupported MRI parameter form table $mriPfTable");
        }

        $scanDoneSQL = '';
        if($noMriPf || is_null($mriPfTable) || is_null($mriPfColumn)) {
            $scanDoneSQL = "''";
        } else {
            $db =& \Database::singleton();
            $mriPfDoneValueSet = is_null($mriPfDoneValues)
                ? ''
                : $db->quote(implode(',', $mriPfDoneValues));

            $scanDoneSQL = "
                CASE
                  WHEN {$mriPfTableAlias}.$mriPfColumn IS NULL THEN ''
                  WHEN FIND_IN_SET({$mriPfTableAlias}.$mriPfColumn, $mriPfDoneValueSet)>0 THEN 'Yes'
                  ELSE 'No'
                END
            ";
        }

        $select =  " SELECT DISTINCT
           c.PSCID,
           s.ID as SessionID,
           s.CandID as cand_id,
           (SELECT name FROM psc WHERE CenterID=s.CenterID) as site,
           s.Visit_label as visit_label,
           '".$scan_type."' as scan_type,
           t.TarchiveID as tarchiveID,
           CASE
              WHEN EXISTS(
                  SELECT
                      *
                  FROM
                      tarchive_series ts
                  LEFT JOIN mri_protocol mp ON mp.Scan_type=".$acqID."
                  WHERE
                      ts.TarchiveID = t.TarchiveID
                      AND (ts.EchoTime BETWEEN mp.TE_min AND mp.TE_max)
                      AND (ts.RepetitionTime BETWEEN mp.TR_min AND mp.TR_max)".
               " ) THEN 'In DICOM'".
              " ELSE 'Missing'
           END as tarchive_loc,
           (SELECT Name FROM Project WHERE ProjectID=c.RegistrationProjectID) as project,".
            " (SELECT title FROM subproject WHERE SubprojectID=s.SubprojectID)
           as subproject,".
            " CASE
              WHEN m.Data_entry_completion_status='Incomplete' THEN 'Incomplete'
              ELSE 'Complete'
           END AS mri_parameter_form,
           $scanDoneSQL as scan_done,
           CASE
              WHEN (fi.fileID IS NULL AND mvl.PatientName IS NULL) THEN 'Missing'
              WHEN fi.fileID IS NOT NULL THEN 'In Imaging Browser'
              WHEN mvl.PatientName IS NOT NULL THEN 'In MRI Violated Scans'
           END as scan_location,
           CASE
              WHEN qc.Selected = '' THEN 'False'
              WHEN qc.Selected = 'true' THEN 'True'
           END as selected,
           qc.QCStatus as qc_status,
           mu.uploadedBy as uploaded_by,
           f.CommentID as CommentID ";

        $joins = " FROM flag f
           LEFT JOIN session s ON (f.SessionID=s.ID)
           LEFT JOIN mri_parameter_form m ON (m.CommentID=f.CommentID)
           LEFT JOIN mri_parameter_form_sa m_sa ON (m_sa.CommentID=f.CommentID)
           LEFT JOIN tarchive t ON (t.SessionID=s.ID)
           LEFT JOIN files fi ON (fi.SessionID=s.ID AND fi.AcquisitionProtocolID=$acqID)
           LEFT JOIN mri_violations_log mvl
              ON (
                      mvl.CandID = s.CandID
                  AND mvl.Scan_type=$acqID
                  AND mvl.PatientName LIKE CONCAT ('%', s.Visit_label,'%')
              )
           LEFT JOIN candidate c ON (s.CandID=c.CandID)
           LEFT JOIN files_qcstatus qc ON (qc.FileID = fi.FileID)
           LEFT JOIN mri_upload mu ON (mu.SessionID = f.SessionID) ";

        $where = " WHERE 1=1
          AND NOT f.CommentID LIKE 'DDE%'
          AND s.Active='Y'
          AND s.CenterID <> '1'
          AND f.Test_name=" . (is_null($mriPfTable) ? "''" : "'$mriPfTable'");

        $query = $select.$joins.$where;

        return $query;
    }

    /**
     * END OVERRIDE
     */

    /**
     * Build a list of imaging QC to display in Data Table
     *
     * @return void
     * @throws \DatabaseException
     */
    function _setupVariables(): void
    {

        $this->skipTemplate = true;
        $user      = \User::singleton();
        $db        = \Database::singleton();
        $siteList  = array();
        $visitList = \Utility::getVisitList();
        // allow to view all sites data through filter
        if ($user->hasPermission('imaging_browser_qc')) {
            $siteList = \Utility::getSiteList();
            // Index sites using their names (used to filter react tables)
            foreach ($siteList as $key => $site) {
                unset($siteList[$key]);
                $siteList[$site] = $site;
            }
        } else {
            // allow only to view own site data
            $siteIDs = $user->getData('CenterIDs');
            foreach ($siteIDs as $val) {
                $site = &Site::singleton($val);
                if ($site->isStudySite()) {
                     $siteList[$site->getCenterName()] = $site->getCenterName();
                }
            }
        }

        $scan_types = $this->_getScanTypes();

        $projectList  = \Utility::getProjectList();
        $projectList2 = array();
        foreach ($projectList as $key => $value) {
            $projectList2[$value] = $value;
        }
        $subprojectList  = \Utility::getSubprojectList();
        $subprojectList2 = array();
        foreach ($subprojectList as $key => $value) {
            $subprojectList2[$value] = $value;
        }
        //print_r($subprojectList2);
        $uploaderList = array();
        $uploaders    = $db -> pselect(
            "SELECT UploadedBy FROM mri_upload GROUP BY UploadedBy",
            array()
        );
        foreach ($uploaders as $up) {
            $uploaderList[$up['UploadedBy']] = $up['UploadedBy'];
        }

        $scan_location = array(
                          "In Imaging Browser"    => "Found in Imaging Browser",
                          "In MRI Violated Scans" => "Found in MRI Violated Scans",
                          "Missing"               => "Missing",
                         );

        $this->fieldOptions
            = [
               'site'             => $siteList,
               'project'          => $projectList2,
               'subproject'       => $subprojectList2,
               'scanType'         => $scan_types,
               'mRIParameterForm' => array(
                                      "Incomplete" => "Incomplete",
                                      "Complete"   => "Complete",
                                     ),
               'scanDoneInMRIPF'  => array(
                                      "Yes" => "Yes",
                                      "No"  => "No",
                                     ),
               'tarchive'         => array(
                                      "In DICOM" => "In DICOM Archives",
                                      "Missing"  => "Missing",
                                     ),
               'scanLocation'     => $scan_location,
               'qCStatus'         => array(
                                      "Pass" => "Pass",
                                      "Fail" => "Fail",
                                     ),
               'uploadedBy'       => $uploaderList,
               'selected'         => array(
                                      "True"  => "True",
                                      "False" => "False",
                                     ),
               'visitLabel'       => $visitList,
              ];

        $scan_types = $this->_getScanTypes();
        foreach ($scan_types as $scan_type) {
            $query_params        = array('scan_type' => $scan_type);
            $acq_IDs[$scan_type] = $db->pselectOne(
                "SELECT ID FROM mri_scan_type WHERE Scan_type=:scan_type",
                $query_params
            );
        }

        foreach ($scan_types as $scan_type) {
            $mriPfDoneValues = $this->_getMriPfDoneValues($scan_type);
            $scan_types[$scan_type] = $this->_buildQuery(
                $scan_type,
                $this->_getMriPfColumnName($scan_type),
                $this->_getMriPfTableName($scan_type),
                $acq_IDs[$scan_type],
                $mriPfDoneValues
            );
        }

        $query = implode(
            "
          UNION ALL
          ",
            $scan_types
        );

        $this->query = " FROM ( " . $query . " ) as tmp";

        $this->columns = [
                          'PSCID',
                          'SessionID',
                          'cand_id',
                          'site',
                          'project',
                          'subproject',
                          'visit_label',
                          'scan_type',
                          'mri_parameter_form',
                          'scan_done',
                          'tarchive_loc',
                          'scan_location',
                          'qc_status',
                          'uploaded_by',
                          'selected',
                          'CommentID',
                          'TarchiveID',
                         ];

        $this->group_by = 'PSCID,
            SessionID,
            cand_id,
            site,
            project,
            subproject,
            visit_label,
            scan_type,
            mri_parameter_form,
            scan_done,
            tarchive_loc,
            scan_location,
            qc_status,
            selected,
            uploaded_by,
            CommentID,
            TarchiveID ';

        $this->order_by = 'PSCID';
    }

    /**
     * BEGIN OVERRIDE
     *
     * New methods _getMriPfTableName, _getMriPfColumnName and _getMriPfDoneValues
     * for IBIS.
     *
     * See IBIS PR#1178.
     */

    /**
     * Gets the name of the table where the MRI parameter form info is stored
     * for the given scan type.
     *
     * @param $scanType a scan type from table mri_scan_types.
     *
     * @return string the table name.
     */
    function _getMriPfTableName(string $scanType) : ?string
    {
        if (preg_match('/SA$/', $scanType)) {
            return 'mri_parameter_form_sa';
        } elseif (preg_match('/EP$/', $scanType)) {
            return null;
        }

        return 'mri_parameter_form';
    }

    /**
     * Gets the name of the column in the table returned by _getMriPfTableName
     * that tells whether the given scan type was acquired or not.
     *
     * @param string $scanType a scan type from table mri_scan_types.
     *
     * @return string the column name.
     */
    function _getMriPfColumnName(string $scanType) : ?string
    {
        switch ($scanType) {
            case 't1w':
            case 't1relx':      return 'T1_Scan_done';
            case 't2w':         return 'T2_Scan_done';
            case 'dti':         return 'DTI_Scan_done';
            case 'DTI65':
            case 'DTI65_B1000': return 'DTI65_Scan_done';
            case 'fMRI':        return 'BOLD_Scan_done';
            case 'T1wNormSA':
            case 'T1wRawSA':    return 't1w_acquired';
            case 'T2wNormSA':
            case 'T2wRawSA':    return 't2w_acquired';
        }

        return null;
    }

    /**
     * Gets the set of values in the column whose name is returned by
     * _getMriPfColumnName indicating the a partial or complete (including multiple)
     * scan of the given type was acquired.
     *
     * @param string $scanType a scan type from table mri_scan_types.
     *
     * @return array the set of values as an array of strings.
     */
    function _getMriPfDoneValues(string $scanType) : ?array
    {
        if (preg_match('/EP$/', $scanType)) {
            return null;
        }

        switch ($scanType) {
            case 'T1wRawSA':
            case 'T1wNormSA':
            case 'T2RawSA':
            case 'T2NormSA': return array('Yes_2', 'Yes_1');
        }

        return array('Complete', 'Partial');
    }

    /**
     * END OVERRIDE
     */

    /**
     * Include additional JS files
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
             $baseURL . "/quality_control/js/qualityControlIndex.js",
            )
        );
    }
}

