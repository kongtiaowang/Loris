<?php declare(strict_types=1);

/**
 * The module to display study statistics
 *
 * PHP Version 7
 *
 * @category Loris
 * @package  Main
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
namespace LORIS\statistics;

/**
 * The module to display study statistics
 *
 * PHP Version 7
 *
 * @category Loris
 * @package  Main
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class Stats_MRI extends \NDB_Form
{
    protected array $params;

    /**
     * Checking user's permission
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('data_entry');
    }

    /**
     * InCenter function
     *
     * @param string $centerID the value of centerID
     * @param array  $Centers  the value of centers
     *
     * @return bool
     */
    function _inCenter($centerID, $Centers)
    {
        foreach ($Centers as $Center) {
            if ($Center['NumericID'] == $centerID) {
                return true;
            }
        }
        return false;
    }

    /**
     * RenderStatsTable function
     *
     * @param string      $sectionHeader     the value of sectionHeader
     * @param string      $tableHeader       the value of tableHeader
     * @param array       $subcats           the value of subcats
     * @param array       $visits            the value of visits
     * @param string      $dropdown_name     the value of dropdown_name
     * @param array       $dropdown_opt      the value of dropdown_opt
     * @param string      $dropdown_selected the value of dropdown_selected
     * @param array       $centers           the value of centers
     * @param array       $data              the value of data
     * @param string      $Subsection        the value of Subsection=''
     * @param string      $disclamer         the value of disclamer=''
     * @param ?\ProjectID $projectID         the value of projectID is null
     * @param bool        $renderTable       whether to render the table or display a
     *                                       default error message
     *
     * @return string
     */
    function renderStatsTable($sectionHeader,
        $tableHeader,
        array $subcats,
        array $visits,
        $dropdown_name,
        $dropdown_opt,
        $dropdown_selected,
        array $centers,
        array $data,
        $Subsection="",
        $disclamer='',
        $projectID=null,
        $renderTable=true
    ): string {

        $tpl_data = [];
        // Sanitize test name if present. Otherwise use empty string.
        $tpl_data['test_name']  = isset($_REQUEST['test_name'])
            ? htmlspecialchars(
                $_REQUEST['test_name'],
                ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML5,
                'UTF-8',
                false
            )
            : '';
        $tpl_data['Subsection'] = $Subsection;
        $tpl_data['Visits']     = $visits;
        $smarty = new \Smarty_NeuroDB("statistics");
        $tpl_data['SectionHeader'] = $sectionHeader;
        $tpl_data['TableHeader']   = $tableHeader;
        $tpl_data['Disclamer']     = $disclamer;
        $tpl_data['Subcategories'] = $subcats;
        $tpl_var = \Utility::getCohortsForProject($projectID);
        $tpl_data['Cohorts']          = $tpl_var;
        $tpl_data['DropdownName']     = $dropdown_name;
        $tpl_data['DropdownOptions']  = $dropdown_opt;
        $tpl_data['DropdownSelected'] = $dropdown_selected;
        $tpl_data['Centers']          = $centers;
        foreach ($data as $row) {
            $subproj = $row['CohortID'];
            $vl      = $row['VLabel'];
            $subcat  = $row['Subcat'];
            $center  = $row['CenterID'];

            /* Calculate the totals for each element of the stats table. Each
             * node of this nested array contains a key-value array consisting
             * of the subcategories as they keys and the totals as values.
             * There is one additional key, 'total'.
             * E.g.
             *      array(
             *          'total' = x;
             *          $subcategory1 = y;
             *          $subcategory2 = z;
             *          ...
             *      )
             */
            if (in_array($vl, $visits)
                && in_array($subcat, $subcats)
                && $this->_inCenter($center, $centers)
            ) {
                $C = 'C' . $center;
                /* This array contains all the $subcategories as keys as well
                * as 'total'. All values are 0.
                */
                $blankStatsArray = $this->initializeStatsArray($subcats);
                /* Initialize values for all of the endpoints using the array
                 * just created. This step is done to prevent undefined index
                 * notices from appearing in the PHP logs for uninitialzed keys.
                 */

                // Data
                if (!isset($tpl_data['data'])) {
                    $tpl_data['data'] = $blankStatsArray;
                }
                // Data => Visit_Label
                if (!isset($tpl_data['data'][$vl])) {
                    $tpl_data['data'][$vl] = $blankStatsArray;
                }
                // Data => Cohort
                if (!isset($tpl_data['data'][$subproj])) {
                    $tpl_data['data'][$subproj] = $blankStatsArray;
                }
                // Data => Cohort => Visit_label
                if (!isset($tpl_data['data'][$subproj][$vl])) {
                    $tpl_data['data'][$subproj][$vl] = $blankStatsArray;
                }
                // Data => Cohort => Center
                if (!isset($tpl_data['data'][$subproj][$C])) {
                    $tpl_data['data'][$subproj][$C] = $blankStatsArray;
                }
                // Data => Cohort => Center => Visit_Label
                if (!isset($tpl_data['data'][$subproj][$C][$vl])) {
                    $tpl_data['data'][$subproj][$C][$vl] = $blankStatsArray;
                }
                // Data => Center
                if (!isset($tpl_data['data'][$C])) {
                    $tpl_data['data'][$C] = $blankStatsArray;
                }
                // Data => Center => Visit_Label
                if (!isset($tpl_data['data'][$C][$vl])) {
                    $tpl_data['data'][$C][$vl] = $blankStatsArray;
                }

                // Update the $subcat and total values for each element.
                // Data
                assert(is_array($tpl_data['data']));
                $tpl_data['data'][$subcat] += $row['val'];
                $tpl_data['data']['total'] += $row['val'];
                // Data => Visit_Label
                $tpl_data['data'][$vl][$subcat] += $row['val'];
                $tpl_data['data'][$vl]['total'] += $row['val'];
                // Data => Cohort
                $tpl_data['data'][$subproj][$subcat] += $row['val'];
                $tpl_data['data'][$subproj]['total'] += $row['val'];
                // Data => Cohort => Visit_Label
                $tpl_data['data'][$subproj][$vl][$subcat] += $row['val'];
                $tpl_data['data'][$subproj][$vl]['total'] += $row['val'];
                // Data => Cohort => Center
                $tpl_data['data'][$subproj][$C][$subcat] += $row['val'];
                $tpl_data['data'][$subproj][$C]['total'] += $row['val'];
                // Data => Cohort => Center => Visit_Label
                $tpl_data['data'][$subproj][$C][$vl][$subcat]  = $row['val'];
                $tpl_data['data'][$subproj][$C][$vl]['total'] += $row['val'];
                // Data => Center
                $tpl_data['data'][$C][$subcat] += $row['val'];
                $tpl_data['data'][$C]['total'] += $row['val'];
                // Data => Center => Visit_Label
                $tpl_data['data'][$C][$vl][$subcat] += $row['val'];
                $tpl_data['data'][$C][$vl]['total'] += $row['val'];
            }
        }

        $tpl_data['render_table'] = $renderTable;
        $smarty->assign($tpl_data);
        $html = $smarty->fetch("table_statistics.tpl");
        return $html;
    }

    /**
     * Sets up the template for the MRI tab
     *
     * @return void
     */
    function setup()
    {
        parent::setup();

        $factory = \NDB_Factory::singleton();
        $DB      = $factory->database();
        $user    = $factory->user();

        $bigTable_params = [];
        $this->params    = [];

        $this->tpl_data['showTable'] = true;

        // PROJECTS
        $allProjectList = \Utility::getProjectList();

        $projects     = [];
        $projects[''] = 'All Projects';

        $userProjectsIDs = $user->getProjectIDs();
        foreach ($userProjectsIDs as $ProjectID) {
            $projects["$ProjectID"] = $allProjectList["$ProjectID"];
        }

        $currentProject = null;
        if ($_REQUEST['MRIProject'] ?? '') {
            $currentProject = \ProjectID::singleton(intval($_REQUEST['MRIProject']));
            $this->tpl_data['CurrentProject']
                = [
                    'ID'   => $currentProject,
                    'Name' => $projects[$currentProject->__toString()],
                ];
            $sqlVar        = 'AND (s.ProjectID IS NULL OR s.ProjectID=:pid) ';
            $Param_Project =$sqlVar;
            $this->params['pid']    = htmlspecialchars(
                $_REQUEST['MRIProject'],
                ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML5,
                'UTF-8',
                false
            );
            $bigTable_params['pid'] = htmlspecialchars(
                $_REQUEST['MRIProject'],
                ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML5,
                'UTF-8',
                false
            );
        } else {
            $Param_Project = '';
        }

        //COHORTS
        $cohorts     = \Utility::getCohortsForProject($currentProject);
        $subprojList = implode(',', array_keys($cohorts));
        if (!empty($subprojList)) {
            $suproject_query ="AND s.CohortID IN ($subprojList)";
        } else {
            $suproject_query ='';
        }
        //SITES
        if ($_REQUEST['MRIsite'] ?? '') {
            $Param_Site          ='AND (s.CenterID IS NULL OR s.CenterID=:sid) ';
            $this->params['sid'] = htmlspecialchars(
                $_REQUEST['MRIsite'],
                ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML5,
                'UTF-8',
                false
            );
        } else {
            $Param_Site = '';
        }

        //SITES PERMISSIONS
        if ($user->hasPermission('access_all_profiles')) {
            $list_of_sites = \Utility::getSiteList();
        } else {
            $list_of_sites = $user->getStudySites();
        }
        $sitesString = implode(",", array_keys($list_of_sites));

        $centers   = iterator_to_array(
            $DB->pselect(
                "SELECT CONCAT('C', CenterID) as ID,
                    CenterID as NumericID,
                    IFNULL(PSCArea,Name) as LongName,
                    Name as ShortName
              FROM psc
              WHERE CenterID <> '1'
                AND Study_site = 'Y'
	        AND CenterID IN (" . $sitesString . ")",
                []
            )
        );
        $sites     = [];
        $sites[''] ="All sites";
        foreach ($centers as $row) {
            $sites[$row['NumericID']] = $row['ShortName'];
            if (isset($_REQUEST['MRIsite'])
                && $_REQUEST['MRIsite'] == $row['NumericID']
            ) {
                $this->tpl_data['CurrentSite'] = [
                    'ID'   => $row['NumericID'],
                    'Name' => $row['LongName'],
                ];
            }
        }

        //GET SCAN TYPES
        $Scan_type_results = $DB->pselect(
            "SELECT mst.MriScanTypeID, mst.MriScanTypeName
              FROM mri_scan_type mst
                JOIN mri_protocol mp USING (MriScanTypeID)",
            []
        );

        $scan_types = [];
        foreach ($Scan_type_results as $row) {
            $scan_types[$row['MriScanTypeID']] = $row['MriScanTypeName'];
        }

        $scans_selected = [];
        if ($_REQUEST['Scans'] ?? '') {
            $scans_selected_input = explode(",", $_REQUEST['Scans']);
        }
        if (empty($scans_selected_input)) {
            $scans_selected = $scan_types ?? [];
        } else {
            foreach ($scans_selected_input as $scid) {
                $scans_selected[$scid] =$scan_types[$scid];
            }
        }

        $Visits = \Utility::getVisitList($currentProject);
        $this->tpl_data['scan_types']     = $scan_types;
        $this->tpl_data['Scans_sel_box']  = array_keys($scans_selected ?? []);
        $this->tpl_data['Scans_selected'] = $scans_selected;
        $this->tpl_data['Sites']          = $sites;
        $this->tpl_data['Projects']       = $projects;
        $this->tpl_data['Cohorts']        = $cohorts;
        $this->tpl_data['Visits']         = $Visits;

        //START BIG TABLE
        //if table is not in database handle by displaying error message
        $this->tpl_data['mri_table_exists'] = true;
        if (!$DB->tableExists('mri_parameter_form')) {
            $this->tpl_data['mri_table_exists'] = false;
            return;
        }
        $MRISubcategories = [
            'Complete',
            'Partial Run',
            'No Scan',
        ];

        //Check if a specific scan is requested otherwise display first
        //available scan
        if (empty($_REQUEST['mri_type'])) {
            $MRI_Type = current($scan_types);
        } else {
            $MRI_Type = $scan_types[$_REQUEST['mri_type']];
        }

        $MRI_Type_Field = $MRI_Type . "_Scan_Done";
        $MRIHeader      = "$MRI_Type Breakdown";
        $CaseStatement  = "
                          CASE($MRI_Type_Field)
                          WHEN 'Partial' THEN 'Partial Run'
                          WHEN 'No' THEN 'No Scan'
                          ELSE 'Complete'
                          END";

        // Check if the mri_parameter_form contains the necessary columns before
        // running the query
        $result         = [];
        $scanDoneExists = false;
        if ($DB->columnExists('mri_parameter_form', $MRI_Type . "_Scan_Done")) {
            $scanDoneExists = true;
            $result         = $DB->pselect(
                "SELECT s.CohortID,
                    s.CenterID,
                    s.Visit_label as VLabel,
                    $CaseStatement as Subcat,
                    COUNT(*) as val
                FROM mri_parameter_form m
                    JOIN flag f USING (CommentID)
                    JOIN session s ON (f.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND f.Administration <> 'None'
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND f.CommentID NOT LIKE 'DDE%'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    $suproject_query
                    $Param_Project
                GROUP BY Subcat,
                    s.CohortID,
                    s.CenterID,
                    s.Visit_label",
                $bigTable_params
            );
        }

        $M_Visits = \Utility::getVisitList($currentProject);
        $this->tpl_data['MRI_Done_Table'] = $this->renderStatsTable(
            "Breakdown By Scan Type",
            $MRIHeader,
            $MRISubcategories,
            $M_Visits,
            "mri_type",
            $scan_types,
            $_REQUEST['mri_type'] ?? '',
            $centers,
            $result,
            "mri",
            "",
            $currentProject,
            $scanDoneExists
        );
        //END BIGTABLE

        //considers the naming convention of
        // mri_parameter_form is "scanType_scan_done"
        $Scan_data_results =[];
        foreach ($scans_selected as $key => $scan) {
            $scan_params = array_merge(['scan' => $scan], $this->params);

            //INSERT COUNT TOTAL
            $Scan_data_results[$key]['insert_count']['total'] = $DB->pselectOneInt(
                "SELECT COUNT(*)
                FROM files fi
                    JOIN session s ON (fi.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    AND fi.FileType='mnc'
                    AND fi.File LIKE CONCAT('%_', :scan, '_%')
                    $suproject_query
                    $Param_Project
                    $Param_Site
                ",
                $scan_params
            );
            //INSERT COUNT Values
            $count_data = $DB->pselect(
                "SELECT s.CohortID as subID, COUNT(*) as cnt
                FROM files fi
                    JOIN session s ON (fi.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    AND fi.FileType='mnc'
                    AND fi.File LIKE CONCAT('%_', :scan, '_%')
                    $suproject_query
                    $Param_Project
                    $Param_Site
                GROUP BY s.CohortID",
                $scan_params
            );
            foreach ($count_data as $row) {
                $Scan_data_results[$key]['insert_count'][$row['subID']]
                    = $row['cnt'];
                //no_qc_count is computed by the difference between insertions
                // and the sum of passed qc and failed qc
                $Scan_data_results[$key]['no_qc_count'][$row['subID']]
                    = $row['cnt'];
            }

            //QC STATUS: PASSED TOTAL
            $Scan_data_results[$key]['qc_pass_count']['total'] = $DB->pselectOneInt(
                "SELECT COUNT(*)
                FROM files_qcstatus fqc
                	JOIN files fi on (fi.FileID=fqc.FileID)
                    JOIN session s ON (fi.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND fqc.FileId IS NOT NULL
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    AND fqc.QCStatus='Pass'
                    AND fi.File LIKE CONCAT('%_', :scan, '_%')
                    $suproject_query
                    $Param_Project
                    $Param_Site
                ",
                $scan_params
            );
            //QC STATUS: PASSED values
            $count_data = $DB->pselect(
                "SELECT s.CohortID as subID, COUNT(*) as cnt
                FROM files_qcstatus fqc
                	JOIN files fi on (fi.FileID=fqc.FileID)
                    JOIN session s ON (fi.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND fqc.FileId IS NOT NULL
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    AND fqc.QCStatus='Pass'
                    AND fi.File LIKE CONCAT('%_', :scan, '_%')
                    $suproject_query
                    $Param_Project
                    $Param_Site
                GROUP BY s.CohortID",
                $scan_params
            );
            foreach ($count_data as $row) {
                $Scan_data_results[$key]['qc_pass_count'][$row['subID']]
                    = $row['cnt'];
                //no_qc_count is computed by the difference between insertions
                // and the sum of passed qc and failed qc
                $Scan_data_results[$key]['no_qc_count'][$row['subID']]
                    = intval($Scan_data_results[$key]['no_qc_count'][$row['subID']])
                    - intval($row['cnt']);
            }

            //QC STATUS: FAILED TOTAL
            $Scan_data_results[$key]['qc_fail_count']['total'] = $DB->pselectOneInt(
                "SELECT COUNT(*)
                FROM files_qcstatus fqc
                	JOIN files fi on (fi.FileID=fqc.FileID)
                    JOIN session s ON (fi.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND fqc.FileId IS NOT NULL
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    AND fqc.QCStatus='Fail'
                    AND fi.File LIKE CONCAT('%_', :scan, '_%')
                    $suproject_query
                    $Param_Project
                    $Param_Site
                ",
                $scan_params
            );
            //QC STATUS: FAILED values
            $count_data = $DB->pselect(
                "SELECT s.CohortID as subID, COUNT(*) as cnt
                FROM files_qcstatus fqc
                	JOIN files fi on (fi.FileID=fqc.FileID)
                    JOIN session s ON (fi.SessionID=s.ID)
                    JOIN candidate c ON (c.ID=s.CandidateID)
                WHERE s.Current_stage <> 'Recycling Bin'
                    AND fqc.FileId IS NOT NULL
                    AND s.Active='Y'
                    AND c.Active='Y'
                    AND s.CenterID <> '1'
		    AND s.CenterID IN (" . $sitesString . ")
                    AND fqc.QCStatus='Fail'
                    AND fi.File LIKE CONCAT('%_', :scan, '_%')
                    $suproject_query
                    $Param_Project
                    $Param_Site
                GROUP BY s.CohortID",
                $scan_params
            );
            foreach ($count_data as $row) {
                $Scan_data_results[$key]['qc_fail_count'][$row['subID']]
                    = $row['cnt'];
                //no_qc_count is computed by the difference between insertions
                // and the sum of passed qc and failed qc
                $Scan_data_results[$key]['no_qc_count'][$row['subID']]
                    = $Scan_data_results[$key]['no_qc_count'][$row['subID']]-
                       intval($row['cnt']);
            }

            $Scan_data_results[$key]['no_qc_count']['total']
                = $Scan_data_results[$key]['insert_count']['total'] -
                  $Scan_data_results[$key]['qc_pass_count']['total'] -
                  $Scan_data_results[$key]['qc_fail_count']['total'];
        }
        $this->tpl_data['scan_data_results'] = $Scan_data_results;
    }

    /**
     * Create an associative array where the keys are all the subcategories
     * as well as 'total'. This is used to intialize the arrays keeping track
     * of statistics totals. They will eventually be passed to tpl_data.
     *
     * @param array $subcategories The subcategories being tracked by this
     *                             module. Keys of the returned array.
     *
     * @return array ('total' => 0, $subcat1 => 0, ..., $subcatN => 0)
     */
    function initializeStatsArray(array $subcategories): array
    {
        $to_ret = ['total' => 0];
        // Initialize all values to 0.
        foreach ($subcategories as $subcat) {
            $to_ret[$subcat] = 0;
        }
        return $to_ret;
    }

    /**
     * Include the column formatter required to display the feedback link colours
     * in the statistics menu
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
            [
                $baseURL . "/statistics/js/table_statistics.js",
                $baseURL . "/statistics/js/form_stats_MRI.js",
            ]
        );
    }
    /**
     * Include additional CSS files:
     *
     * @return array of javascript to be inserted
     */
    function getCSSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            [$baseURL . "/statistics/css/statistics.css"]
        );
    }

}

