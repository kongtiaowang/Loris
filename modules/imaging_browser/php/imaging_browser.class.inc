<?php

/**
 * This class features the code for the menu portion of the Loris imaging
 * browser.
 *
 * PHP Version 5
 *
 *  @category   Behavioural
 *  @package    Main
 *  @subpackage Imaging
 *  @author     Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 *  @license    Loris License
 *  @link       https://www.github.com/aces/Loris-Trunk/
 */
namespace LORIS\imaging_browser;

/**
 * Provides the PHP code for the menu filter for the imaging browser
 *
 *  @category   Behavioural
 *  @package    Main
 *  @subpackage Imaging
 *  @author     Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 *  @license    Loris License
 *  @link       https://www.github.com/aces/Loris-Trunk/
 */
class Imaging_Browser extends \NDB_Menu_Filter
{
    var $AjaxModule      = true;
    public $skipTemplate = true;
    public $fieldOptions;
    /**
     * Determine whether the user has permission to view this page
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool whether the user hass access
     */
    function _hasAccess(\User $user) : bool
    {
        /* User has access if they have an 'all site' permission or if they are
        * part of a study site and are permitted to view their own site.
         */
        return $user->hasAnyPermission(
            array(
             'imaging_browser_view_allsites',
             'imaging_browser_phantom_allsites',
             'imaging_browser_phantom_ownsite',
            )
        )
            || (
                $user->hasStudySite()
                && $user->hasPermission('imaging_browser_view_site')
            );
    }

    /**
     * BEGIN OVERRIDE
     * 
     * The entire _setupVariables method is overridden and differs in almost
     * every way from the LORIS 20.0 version...
     */

    /**
     * Set up the variables required by NDB_Menu_Filter class for constructing
     * a query
     *
     * @return void
     */
    function _setupVariables()
    {
        $config = \NDB_Config::singleton();
        $DB     = \Database::singleton();

        //-------------------------------------------//
        // Build associative array of all scan types //
        //-------------------------------------------//
        $all_scan_types_2d = $DB->pselect(
            "SELECT ID, Scan_type FROM mri_scan_type mri",
            array()
        );

        foreach ($all_scan_types_2d as $row) {
            $all_scan_types[$row['ID']] = $row['Scan_type'];
        }

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
        $scan_id_types =array_flip(
            array_intersect_key(
                array_flip($all_scan_types),
                array_flip($toTable_scan_types)
            )
        );

        if (!empty($scan_id_types)) {
            $this->acqpid = "AND AcquisitionProtocolID IN (".
                implode(",", array_keys($scan_id_types)) .")";
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
            $acqpif .= ",'new','')";
            $newQueryCase .=")";
        } else {
            $this->acqpid = '';
            $acqpif       = "'new'";
            $newQueryCase ='';
        }

        $NewDataSubquery = "CASE 
            COALESCE(Max(fqc.QCLastChangeTime), 'new')
            WHEN 'new' THEN {$acqpif}
            WHEN ''    THEN {$acqpif}
            WHEN NULL  THEN {$acqpif}
            ELSE ''
            END";


        $PendingFailSubquery = "
            CASE s.MRIQCStatus
                WHEN 'Fail' THEN
                    IF(s.MRIQCPending='Y', 'Pending Fail', 'Fail')
                WHEN 'Pass' THEN
                    IF(s.MRIQCPending='Y', 'Pending Pass', 'Pass') 
                ELSE s.MRIQCStatus
            END 
            ";

        $PendingNewquery
            = "CASE " 
            . "  WHEN s.MRIQCPending='Y' THEN 'P' "
            . "  WHEN MAX(fqc.QCFirstChangeTime) IS NULL $newQueryCase THEN  'N' "
            . "END";

        $this->query     = " FROM psc AS p 
            JOIN session s ON (s.CenterID=p.CenterID) 
            JOIN candidate c ON (c.CandID=s.CandID) 
            JOIN files f ON (f.SessionID=s.ID) 
            LEFT JOIN files_qcstatus fqc ON (fqc.FileID=f.FileID) 
            JOIN mri_acquisition_dates md ON (md.SessionID=s.ID)
            LEFT JOIN mri_scan_type modality ON 
            (f.AcquisitionProtocolID=modality.ID)";

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

        $where = "
            WHERE 
            s.Active = 'Y' AND
            f.FileType='mnc'";

        $this->query .= $left_joins;
        $this->query .= $where;

        $config = \NDB_Config::singleton();
        $user   = \User::singleton();
        $DB     = \Database::singleton();
        if (!$user->hasPermission('imaging_browser_view_allsites')) {
            $site_arr = implode(",", $user->getCenterIDs());
            if (!$user->hasPermission('imaging_browser_view_site')) {
                // User must have one of the two phantom permissions to get here
                $this->query .= " AND c.Entity_type = 'Scanner' ";
                if (!$user->hasPermission('imaging_browser_phantom_allsites')) {
                    // Display only the phantom scans at the user's centers
                    // For phantoms, use session centerID
                    $this->query .= " AND s.CenterID IN (" . $site_arr . ") ";
                }
            } else {
                if ($user->hasPermission('imaging_browser_phantom_allsites')) {
                    $this->query .= " AND (c.RegistrationCenterID IN ($site_arr) 
                                      OR c.Entity_type = 'Scanner') ";
                } else if ($user->hasPermission('imaging_browser_phantom_ownsite')) {
                    $this->query .= " AND (c.RegistrationCenterID IN ($site_arr)
                                      OR (c.Entity_type = 'Scanner'
                                      AND s.CenterID IN (" . $site_arr . "))) ";
                } else {
                    $this->query .= " AND c.RegistrationCenterID IN ($site_arr) ";
                }
            }
        }

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

        $this->columns = array(
                          'p.Name as Site',
                          'c.PSCID as PSCID',
                          'c.CandID as DCCID',
                          '(SELECT Name 
                            FROM Project 
                            WHERE ProjectID=c.ProjectID) as project',
                          's.visit_label as Visit_Label',
                          "$PendingFailSubquery as Visit_QC_Status",
                          'MIN(md.AcquisitionDate) as First_Acquisition',
                          'FROM_UNIXTIME(MIN(f.InsertTime)) as First_Insertion',
                          'FROM_UNIXTIME(MAX(fqc.QCLastChangeTime)) as Last_QC',
                          "$NewDataSubquery as New_Data",
                         );
        $this->columns = array_merge(
            $this->columns,
            array("GROUP_CONCAT(DISTINCT OutputType) as Links"),
            array(
             's.ID as sessionID',
             'GROUP_CONCAT(DISTINCT modality.Scan_type) as sequenceType',
             "$PendingNewquery as pending",
            ),
            $groupSubquery
        );

        $this->order_by = 'c.PSCID, s.Visit_label';
        $this->group_by = 's.ID';
    }

    /**
     * END OVERRIDE
     */
     
    /**
     * Setup $this->tpl_data for use by Smarty
     *
     * @return void
     */
    function setup()
    {
        parent::setup();
        // create user object
        $user     = \User::singleton();
        $siteList = array();

        // PSC
        if ($user->hasPermission('imaging_browser_view_allsites')
            || $user->hasPermission('imaging_browser_phantom_allsites')
        ) {
            // get the list of study sites
            $siteList = \Utility::getSiteList();
            // Index sites using their names (used to filter react tables)
            foreach ($siteList as $key => $site) {
                unset($siteList[$key]);
                $siteList[$site] = $site;
            }
        } else {
            $siteIDs = $user->getData('CenterIDs');
            foreach ($siteIDs as $val) {
                $site = \Site::singleton($val);
                if ($site->isStudySite()) {
                    $siteList[$site->getCenterName()] = $site->getCenterName();
                }
            }
        }

        $DB    = \Database::singleton();
        $allAr = array();

        //---------------------------------------------------------------------//
        // Build array of all groups for which we want info                    //
        //---------------------------------------------------------------------//
        $config = \NDB_Config::singleton();
        $toTable_scan_type_groups = $config->getSetting('tblScanTypeGroups');
        $toTable_scan_type_groups = explode(',', $toTable_scan_type_groups);
        $allGroupsQuery = sprintf(
            "SELECT DISTINCT Name, Description 
             FROM mri_scan_type_groups
             WHERE Name IN (%s)",
            implode(",", array_fill(0, count($toTable_scan_type_groups), '?'))
        );
        $toTable_scan_type_groups = $DB->pselect($allGroupsQuery, array_values($toTable_scan_type_groups));
        foreach($toTable_scan_type_groups as $row) {
            $scan_type_ids[$row['Name']] = $row['Description'];
        }

        $list_of_projects = $allAr;
        $projectList      = \Utility::getProjectList();
        foreach ($projectList as $key => $project) {
            unset($projectList[$key]);
            $list_of_projects[$project] = $project;
        }

        $visitQCStatus = array(
                          'Pass' => 'Pass',
                          'Fail' => 'Fail',
                         );

        $pending = array(
                    'P' => 'Pending',
                    'N' => 'New',
                   );

        $types_q    = $DB->pselect(
            "SELECT ID, Scan_type FROM mri_scan_type mri
                 JOIN files f ON (f.AcquisitionProtocolID=mri.ID)",
            array()
        );
        $scan_types = $allAr;
        foreach ($types_q as $key=>$sequenceType) {
            $scan_types[$sequenceType['Scan_type']] = $sequenceType['Scan_type'];
        }

        $outputTypes = $DB->pselect(
            "SELECT DISTINCT OutputType AS outputType 
            FROM files WHERE FileType='mnc' AND OutputType!='native'",
            array()
        );

        $this->fieldOptions = [
                               'sites'         => $siteList,
                               'projects'      => $list_of_projects,
                               'visitQCStatus' => $visitQCStatus,
                               'sequenceTypes' => $scan_types,
                               'pendingNew'    => $pending,
                               'configLabels'  => $scan_type_ids,
                              ];

        $this->tpl_data['backURL'] = $_SERVER['REQUEST_URI'];
    }
    /**
     * Converts this menu filter to an array of the form
     *
     * Headers => (string array)
     * Data => (array of arrays of row data)
     *
     * @note overloaded function
     *         Overloading this method to create a list of sessionID that
     *         will be used for the Navigation Links in  the viewSession
     *         page.
     *
     * @return array
     */
    function toArray()
    {
        $data  = parent::toArray();
        $index = array_search('SessionID', $data['Headers']);
        if ($index !== false) {
            $_SESSION['State']->setProperty(
                'mriSessionsListed',
                array_column($data['Data'], $index)
            );
        }
        return $data;
    }

    /**
     * Include additional CSS files:
     *  1. imaging_browser.css
     *
     * @return array of css to be inserted
     */
    function getCSSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            [$baseURL . "/imaging_browser/css/imaging_browser.css"]
        );
    }



    /**
     * Include the column formatter
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseurl = $factory->settings()->getBaseURL();
        return array_merge(
            parent::getJSDependencies(),
            array(
             $baseurl . "/imaging_browser/js/imagingBrowserIndex.js",
            )
        );
    }
}
