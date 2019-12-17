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
    var $AjaxModule = true;
    /**
     * Determine whether the user has permission to view this page
     *
     * @return bool whether the user hass access
     */
    function _hasAccess()
    {
        $user =& \User::singleton();

        return ($user->hasPermission('imaging_browser_view_allsites')
               || ($user->hasStudySite()
                   && $user->hasPermission('imaging_browser_view_site')
                  )
               || $user->hasPermission('imaging_browser_phantom_allsites')
               || $user->hasPermission('imaging_browser_phantom_ownsite')
        );
    }

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
            foreach ($scan_id_types as $key => $value) {
                if ($isFirst) {
                    $acqpif = "IF(FIND_IN_SET({$key},GROUP_CONCAT(
                        DISTINCT AcquisitionProtocolID))>0 ";
                } else {
                    $acqpif .= "OR FIND_IN_SET({$key},GROUP_CONCAT(
                        DISTINCT AcquisitionProtocolID))>0 ";
                }
                $isFirst = false;
            }
            $acqpif .= ",'new','')";
        } else {
            $this->acqpid = '';
            $acqpif       = "'new'";
        }
        $NewDataSubquery = "CASE 
            COALESCE(Max(fqc.QCLastChangeTime), 'new')
            WHEN 'new' THEN {$acqpif}
            WHEN ''    THEN {$acqpif}
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

        $this->query = " FROM psc AS p 
            JOIN session s ON (s.CenterID=p.CenterID) 
            JOIN candidate c ON (c.CandID=s.CandID) 
            JOIN files f ON (f.SessionID=s.ID) 
            LEFT JOIN files_qcstatus fqc ON (fqc.FileID=f.FileID) 
            JOIN mri_acquisition_dates md ON (md.SessionID=s.ID)";

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
            f.PendingStaging=0 AND 
            f.FileType='mnc'";

        $this->query .= $left_joins;
        $this->query .= $where;

        $config =& \NDB_Config::singleton();
        $user   =& \User::singleton();
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
                    $this->query .= " AND (c.CenterID IN (" . $site_arr . ") 
                                      OR c.Entity_type = 'Scanner') ";
                } else if ($user->hasPermission('imaging_browser_phantom_ownsite')) {
                    $this->query .= " AND (c.CenterID IN (" . $site_arr . ")
                                      OR (c.Entity_type = 'Scanner'
                                      AND s.CenterID IN (" . $site_arr . "))) ";
                } else {
                    $this->query .= " AND c.CenterID IN (" . $site_arr . ") ";
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
                          'p.MRI_alias as Site',
                          'c.PSCID as PSCID',
                          'c.CandID as DCCID',
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
            $groupSubquery,
            array('s.ID as sessionID')
        );

        $this->order_by = 'c.PSCID, s.Visit_label';
        $this->group_by = 's.ID';

        $this->headers = array(
                          'Site',
                          'PSCID',
                          'DCCID',
                          'Visit_Label',
                          'Visit_QC_Status',
                          'First_Acquisition',
                          'First_Insertion',
                          'Last_QC',
                          'New_Data',
                          'Links',
                         );
        $this->headers = array_merge(
            $this->headers,
            array_values($headerName),
            array('sessionID')
        );

        // Insert project column after DCCID, if useProject config is enabled
        if ($config->getSetting('useProjects') === "true") {
            array_splice(
                $this->columns,
                3,
                0,
                '(SELECT Name FROM Project WHERE ProjectID=c.ProjectID) as project'
            );
            array_splice($this->headers, 3, 0, 'Project');
        }

        $this->validFilters = array(
                               'c.PSCID',
                               's.Visit_label',
                               'c.CandID',
                               'c.ProjectID',
                               's.CenterID',
                               's.MRIQCStatus',
                               'pending',
                               'f.AcquisitionProtocolID',
                              );

        $this->formToFilter    = array(
                                  'pscid'         => 'c.PSCID',
                                  'VL'            => 's.Visit_label',
                                  'DCCID'         => 'c.CandID',
                                  'ProjectID'     => 'c.ProjectID',
                                  'SiteID'        => 's.CenterID',
                                  'VisitQCStatus' => 's.MRIQCStatus',
                                  'Pending'       => 'pending',
                                  'Scan_type'     => 'f.AcquisitionProtocolID',
                                 );
        $this->EqualityFilters = array('f.AcquisitionProtocolID');
        $this->searchKeyword   = array();

        $this->tpl_data['numTimepoints'] = 0;

        // This variable will be used by the columnFormatter javascript
        // to set the default hidden columns in the data table.
        $this->tpl_data['hiddenHeaders'] = json_encode(
            array_map(
                function ($header) {
                    return ucwords(str_replace('_', ' ', $header));
                },
                array('sessionID')
            )
        );
    }

    /**
     * Setup $this->tpl_data for use by Smarty
     *
     * @return void
     */
    function setup()
    {
        parent::setup();
        // create user object
        $user          =& \User::singleton();
        $list_of_sites = array();

        // PSC
        if ($user->hasPermission('imaging_browser_view_allsites')
            || $user->hasPermission('imaging_browser_phantom_allsites')
        ) {
            // get the list of study sites - to be replaced by the Site object
            $list_of_sites = \Utility::getSiteList();
            if (is_array($list_of_sites)) {
                $list_of_sites = array('' => 'All') + $list_of_sites;
            }
        } else {
            // allow only to view own site data
            $list_of_sites = $user->getStudySites();
            $list_of_sites = array('' => 'All User Sites') + $list_of_sites;
        }

        $DB    = \Database::singleton();
        $allAr = array('' => 'All');

        $this->addBasicText(
            'pscid',
            'PSCID',
            array(
             "size"      => 10,
             "maxlength" => 25,
            )
        );
        $this->addBasicText(
            'VL',
            'Visit Label',
            array(
             'size'      => "10",
             "maxlength" => "25",
            )
        );
        $this->addBasicText(
            'DCCID',
            'DCCID',
            array(
             'size'      => 10,
             "maxlength" => 25,
            )
        );

        $config =& \NDB_Config::singleton();
        if ($config->getSetting('useProjects') === "true") {
            $list_of_projects = $allAr;
            $projectList      = \Utility::getProjectList();
            foreach ($projectList as $key => $value) {
                $list_of_projects[$key] =$value;
            }
            $this->addSelect('ProjectID', 'Project', $list_of_projects);
        }

        $this->addSelect('SiteID', 'Site', $list_of_sites);
        $this->addSelect(
            'VisitQCStatus',
            'Visit QC Status',
            array(
             ''     => 'All',
             'Pass' => 'Pass',
             'Fail' => 'Fail',
            )
        );

        $this->addSelect(
            'Pending',
            'Pending and New',
            array(
             ''   => 'All',
             'P'  => 'Pending',
             'N'  => 'New',
             'PN' => 'Pending or New',
            )
        );

        //query to get scan types that exist for the project
        $types_q    = $DB->pselect(
            "SELECT ID, Scan_type FROM mri_scan_type mri
                 JOIN files f ON (f.AcquisitionProtocolID=mri.ID)",
            array()
        );
        $scan_types = $allAr;
        foreach ($types_q as $row) {
            $type = $row['Scan_type'];
            $scan_types[$row['ID']] = $type;
        }
        $this->addSelect('Scan_type', 'Sequence Type', $scan_types);

        $outputTypes = $DB->pselect(
            "SELECT DISTINCT OutputType AS outputType 
            FROM files WHERE FileType='mnc' AND OutputType!='native'",
            array()
        );

        $this->tpl_data['outputTypes'] = array_merge(
            array(
             array('outputType' => 'native'),
             array('outputType' => 'selected'),
            ),
            $outputTypes
        );

        $this->tpl_data['numOutputTypes'] = count($outputTypes);
        $this->addBasicText(
            'keyword',
            'Search keyword in Comments',
            array(
             "size"      => 10,
             "maxlength" => 25,
            )
        );

        $this->tpl_data['backURL'] = $_SERVER['REQUEST_URI'];
    }

    /**
     * Overwrites the function to add a customized filter
     * for Pending and New
     *
     * @param string $prepared_key filter key
     * @param string $field        filter field
     * @param string $val          filter value
     *
     * @return string the new query
     */
    function _addValidFilters($prepared_key, $field, $val)
    {
        $query = '';
        if ((!empty($val) || $val === '0') && $field != 'order') {
            if ($field != 'pending' && $field !='AcquisitionProtocolID') {
                if (in_array($field, $this->CheckboxFilters) && $val) {
                    $query .= " AND $field";
                } elseif (strtolower(substr($field, -8)) == 'centerid'
                    || strtolower(substr($field, -10)) == 'categoryid'
                    || strtolower(substr($field, -6)) == 'gender'
                    || (isset($this->EqualityFilters)
                    && in_array($field, $this->EqualityFilters))
                ) {
                    $query .= " AND $field = :v_$prepared_key";
                    // $qparams["v_$prepared_key"] = $val;
                } else {
                    $query .= " AND $field LIKE CONCAT('%', :v_$prepared_key, '%') ";
                }
            } else if ($field == 'pending') {
                switch ($val) {
                case "P":
                    $query .= " AND s.MRIQCPending='Y'";
                    break;
                case "N":
                    $query .= " AND fqc.QCFirstChangeTime IS NULL " . $this->acqpid;
                    break;
                case "PN":
                    $query .= " AND (s.MRIQCPending='Y' 
                        OR (fqc.QCFirstChangeTime IS NULL ". $this->acqpid ."))";
                    break;
                }
            } else if ($field == 'AcquisitionProtocolID') {
                $query .= " AND $field = :v_$prepared_key";
            }
        }
        return $query;
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
             $baseurl . "/imaging_browser/js/columnFormatter.js",
             $baseurl . "/imaging_browser/js/onSort.js",
            )
        );
    }
}
