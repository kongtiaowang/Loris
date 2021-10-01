<?php
namespace LORIS\reliability;
/**
 * The menu for the reliability checking
 *
 * @package    mri
 * @subpackage NIHPD
 */
function map_cIDs($array)
{
    $new_array;
    for ($i = 0; $i < count($array); $i++) {
        $element = $array[$i];
        $new_array[$element['CommentID']] = $element['reliability_center_id'];
    }
    return $new_array;
}

function find_cID($cID, $array)
{
    if (empty($array)) {
        return false;
    }
    foreach ($array as $key=>$value) {
        if ($key == $cID) {
            return true;
        }
    }
    return false;
}

function array_remove($item, $array)
{
    $index = array_search($item, $array);
    if ($index === false) {
        return $array;
    } else {
        unset($array[$index]);
        return array_values($array);
    }
}

class Reliability extends \NDB_Menu_Filter
{

    var $centerIDMap;

    var $site_id = array(
                    'SEA'  => 2,
                    'PHI'  => 3,
                    'STL'  => 4,
                    'UNC'  => 5,
                    'UofA' => 6,
                   );

    var $reliability_table;

    //@codingStandardsIgnoreEnd
    /**
     * GetSiteID Load
     *
     * @param string $site the value of site
     *
     * @return void
     */
    static function getSiteID($site)
    {
        $siteList = \Utility::getSiteList();
        foreach ($siteList as $id=>$name) {
            $site_id[$name] = $id;
        }
        $id = $site_id[$site];
        return $id;

    }
    function _setupVariables()
    {
        $user =& \User::singleton();

        // create the centerID map
        $db      =& \Database::singleton();
        $pscRows = array();
        $pscRows = $db->pselect("SELECT CenterID, Name FROM psc",array());
        foreach ($pscRows AS $row) {
            $this->centerIDMap[$row['CenterID']] = $row['Name'];
        }

        $this->_populate_reliability_table();


        if (isset($_REQUEST['EARLI']) && $_REQUEST['EARLI'] == 1) {
            $extra_where = " AND EARLI_Candidate='yes'";
        } else {
            $extra_where = " AND EARLI_Candidate='no'";
        }
        $video_query = "CASE
                        WHEN videos.record_id IS NULL THEN 'No'
                        ELSE videos.record_id
                        END";
        $query       = " FROM candidate
                JOIN session ON (candidate.CandID=session.CandID)
                JOIN flag ON (session.ID=flag.SessionID)
                JOIN reliability ON (reliability.CommentID=flag.CommentID )
                JOIN psc p ON (reliability.reliability_center_id=p.CenterID)
                JOIN Project pr ON (candidate.RegistrationProjectID=pr.ProjectID)
                LEFT JOIN videos ON (videos.PSCID=candidate.PSCID AND videos.visitLabel=session.Visit_label AND videos.instrument =reliability.Instrument)
                    $extra_where ".
                "WHERE ".
                "TRUE ";

        // only view their own profiles, unless they have permission to see all
        if (!($user->hasPermission('reliability_edit_all') || $user->hasPermission('access_all_profiles'))) {
            $site_arr = implode(",", $user->getCenterIDs());
            $query .= " AND candidate.RegistrationcenterID IN (" . $site_arr . ") ";
        }

        $config      =& \NDB_Config::singleton();

        $this->columns = array(
            'candidate.PSCID',
            'reliability.reliability_center_id',
            'p.name as site',
            'session.SubprojectID as Cohort',
            'session.CandID AS DCCID',
            'candidate.Sex',
            'session.Visit_label',
        );

            $this->columns[] = 'pr.Name as Project';

        $this->columns  =array_merge(
            $this->columns,
            array(
                'reliability.CommentID',
                'reliability.Instrument',
                "$video_query as File_in_DB",
                'reliability.Reliability_score',
                'session.Current_stage',
                'reliability.invalid',
                'reliability.Manual_Swap',
            )
        );

        $this->query        = $query;
        $this->group_by     = '';
        $this->order_by     = 'reliability.Instrument, session.CandID, session.Visit_label';
        $this->headers  = array(
            'PSCID',
            'SiteID',
            'Site of Reliability Test',
            'Cohort',
            'DCCID',
            'Sex',
            'Visit_label',
        );

            $this->headers[] = 'Project';

        $this->headers =array_merge($this->headers, array('CommentID', 'Instrument','File_in_DB', 'reliability_score', 'Current Stage', 'Invalid', 'Manual Swap', 'Reliable'));

        // Set header as hidden from the data table
        $this->tpl_data['hiddenHeaders'] = json_encode(['SiteID', 'CommentID', 'Current Stage', 'Invalid', 'Manual Swap']);
        $this->validFilters = array(
                               'reliability.reliability_center_id',
                               'session.SubprojectID',
                               'candidate.RegistrationCenterID',
                               'session.CandID',
                               'candidate.PSCID',
                               'candidate.Gender',
                               'session.Visit_label',
                               'reliability.Instrument',
                               'reliability.Reliability_score',
                               'session.Current_stage',
                               'reliability.invalid',
                               'candidate.RegistrationProjectID',
                              );

        $this->formToFilter = array(
                               'SubprojectID'          => 'session.SubprojectID',
                               'CenterID'              => 'candidate.RegistrationCenterID',
                               'reliability_center_id' => 'reliability.reliability_center_id',
                               'DCCID'                 => 'session.CandID',
                               'PSCID'                 => 'candidate.PSCID',
                               'Gender'                => 'candidate.Gender',
                               'Visit_label'           => 'session.Visit_label',
                               'Instrument'            => 'reliability.Instrument',
                               'reliability_score'     => 'reliability.Reliability_score',
                               'Current_stage'         => 'session.Current_stage',
                               'Invalid'               => 'reliability.invalid',
                               'ProjectID'             => 'candidate.RegistrationProjectID',
            // 'Lock_record' => 'session.Lock_record'
                              );
        return true;
    }


    function _setFilterForm()
    {
        // create user object
        $user =& \User::singleton();

        // allow to view all sites data through filter
        if ($user->hasPermission('access_all_profiles') || $user->hasPermission('reliability_edit_all')) {
            // get the list of study sites - to be replaced by the Site object
            $list_of_sites = \Utility::getSiteList(false);

            if (is_array($list_of_sites)) {
                // This doesn't work, it causes all the indexes to change
                // and the index is supposed to be the CenterID number
                // $list_of_sites = array_merge(array('' => 'Any'), $list_of_sites);

                // So instead, manually iterate through and set everything
                // in a new array
                $new_list = array('' => 'Any');
                foreach ($list_of_sites as $key => $val) {
                    $new_list[$key] = $val;
                }
                $list_of_sites = $new_list;
            }
        } else {
            // allow only to view own site data
            $list_of_sites      = $user->getStudySites();
            $default_site_array =array('All User Sites' => 'All User Sites');
            $list_of_sites      = $default_site_array + $list_of_sites;
            //}
        }

        /// hack for Visit Labels... maybe get all the real visit labels from DB?
        $list_of_visit_labels      = array(
                                      null  => 'Any',
                                      'V06' => 'V06',
                                      'V12' => 'V12',
                                      'V24' => 'V24',
                                      'V36' => 'V36',
                                      'VSA' => 'VSA'
                                     );
        $list_of_visit_labels_only = array(
                                      'V06' => 'V06',
                                      'V12' => 'V12',
                                      'V24' => 'V24',
                                      'V36' => 'V36',
                                      'VSA' => 'VSA'
                                     );
        $subproject_options        = \Utility::getSubprojectList();
        $subproject_options        = array(null => 'Any') + $subproject_options;
        $gender_options            = array(
                                      null     => 'Any',
                                      'Male'   => 'Male',
                                      'Female' => 'Female',
                                     );
        $list_of_instruments       = array(
                                      null            => 'Any',
                                      'csbs'          => 'CSBS',
                                      'adi_r'         => 'ADI-R',
                                      'ados'          => 'ADOS',
                                      'aosi'          => 'AOSI',
                                      'aims'          => 'AIMS',
                                      'ados2_module1' => 'ADOS2 Module1',
                                      'ados2_module2' => 'ADOS2 Module2',
                                      'ados2_module3' => 'ADOS2 Module3',
                                     );
        $list_of_instruments_only  = array(
                                      'csbs'          => 'CSBS',
                                      'adi_r_proband' => 'ADI-R (Proband)',
                                      'adi_r_subject' => 'ADI-R (Subject)',
                                      'ados_module1'  => 'ADOS (Module 1)',
                                      'ados_module2'  => 'ADOS (Module 2)',
                                      'aosi'          => 'AOSI',
                                      'ados2_module1' => 'ADOS2 (Module 1)',
                                      'ados2_module2' => 'ADOS2 (Module2)',
                                      'ados2_module3' => 'ADOS2 (Module3)',
                                     );
        $lock_options     = array(
                             null       => '',
                             'Locked'   => 'Locked',
                             'Unlocked' => 'Unlocked',
                            );
        $list_of_projects =& \Utility::getProjectList();

        // Form Elements
        $this->addSelect('SubprojectID', 'Subproject:', $subproject_options);
        $this->addSelect('CenterID', 'Site:', $list_of_sites);
        $this->addSelect('reliability_center_id', 'Site of Reliability:', $list_of_sites);
        $this->addBasicText('DCCID', 'DCCID:', array("size" => 9, "maxlength" => 6));
        $this->addBasicText('PSCID', 'PSCID:', array("size" => 9, "maxlength" => 7));
        $this->addSelect('Gender', 'Gender:', $gender_options);
        $this->addSelect('Visit_label', 'Visit Label:', $list_of_visit_labels);
        $this->addSelect('Instrument', 'Instrument:', $list_of_instruments);
        $this->addSelect('Invalid', 'Invalid Candidate:', array('' => '', 'yes' => 'Yes', 'no' => 'No'));
        $config =&\NDB_Config::singleton();

            $this->addSelect('ProjectID', 'Project:', array('' => 'All') + $list_of_projects);


        // $this->addSelect('Lock_record', 'Lock_record:', $lock_options);

        // For swapping candidates
        if ($user->hasPermission('reliability_swap_candidates')) {
            $this->tpl_data['reliability_swap_candidates'] = true;
            $this->addSelect('Cand1Visit_label', 'Visit Label:', $list_of_visit_labels_only);
            $this->addBasicText('Cand1PSCID', 'PSCID:');
            $this->addSelect('Cand2Visit_label', 'Visit Label:', $list_of_visit_labels_only);
            $this->addBasicText('Cand2PSCID', 'PSCID:');
            $this->addSelect('SwapInstrument', 'Instrument:', $list_of_instruments_only);
        } else {
            $this->tpl_data['reliability_swap_candidates'] = false;
        }

        if ($user->hasPermission('data_entry')) {
            $this->tpl_data['IBIS_Access'] = true;
        } else {
            $this->tpl_data['IBIS_Access'] = false;
        }
        if ($user->hasPermission('EARLI_Reliability')) {
            $this->tpl_data['EARLI_Reliability'] = true;
            $this->addBasicText('AddPSCID', 'PSCID:');
            $this->addSelect('AddVisit_label', 'Visit Label:', array_merge(array('' => 'Any'), $list_of_visit_labels_only));
            $this->addSelect('AddReliabilityCenter', 'Site of Reliability:', $list_of_sites);
            $this->addSelect('AddInstrument', 'Instrument:', array_merge(array('' => 'Any'), $list_of_instruments_only));
        } else {
            $this->tpl_data['EARLI_Reliability'] = false;
        }

        // Doing this here is a hack. Since this is a menu filter and not a Form, there's no
        // _process/_save functions automagically called. There should probably be something like
        // a Menu_Filter_Form base class for instances like this or the conflict resolver, but as
        // things stand you either need to work with the $_POST array/DB directly in a Menu_Filter,
        // or rewrite/imitate the Menu_Filter in an NDB_Form. -- Dave
        $swap = isset($_POST['swap']) ? $_POST['swap'] : '';
        if ($swap == 'Swap Candidates' || $swap == 'swap') {
            $message = $this->_swap_candidates();
            if (isset($message['error'])) {
                $this->form->addElement('static', 'error', $message['error']);
            }
            if (isset($message['message'])) {
                $this->form->addElement('static', 'message', $message['message']);
            }
        } else if ($swap == "Add Candidate" || $swap == 'addnew') {
            $message = $this->_addCandidate();
            if (isset($message['error'])) {
                $this->form->addElement('static', 'error', $message['error']);
            }
            if (isset($message['message'])) {
                $this->form->addElement('static', 'message', $message['message']);
            }
        }
        return true;
    }

    // This is used both by setDataTableRows, and reliability statistics
    function getThreshholds()
    {
        //return array("adi_r_proband" => 90, "adi_r_subject" => 90, "adi_r" => 90, 'aosi' => 78.9, 'csbs' => 80, 'ados_module1' => 80, 'ados_module2' => 80);
        $config            =& \NDB_Config::singleton();
        $reliabilityConfig = $config->getSetting("ReliabilityInstruments");
        $threshold         = array();

        foreach (\Utility::associativeToNumericArray($reliabilityConfig) AS $reliabilityInstrument) {
            $instrument_list = $reliabilityInstrument['Instrument'];
            foreach ($instrument_list AS $instrument) {
                $threshold[$instrument['Testname']] = $instrument['Threshold'];
            }
        }
        return $threshold;
        //return array("adi_r_proband" => 89.5, "adi_r_subject" => 89.5, "adi_r" => 89.5, 'aosi' => 78.0, 'csbs' => 79.5, 'ados_module1' => 79.5, 'ados_module2' => 79.5);
    }

    function _populate_reliability_table()
    {
        $db =& \Database::singleton();
        $this->reliability_table = $db->pselect("SELECT CommentID, reliability_center_id FROM reliability", array());

        $this->reliability_table = map_cIDs($this->reliability_table);

        // WITHIN SITE
        $site_list = array(
                      'SEA',
                      'PHI',
                      'STL',
                      'UNC',
                     );

        foreach ($site_list as $site) {

            $this->within_site_flagging("adi_r_subject", 0.1, $site, $db, 1);
            $this->within_site_flagging("adi_r_proband", 0.15, $site, $db, 1);
            $this->within_site_flagging("csbs", 0.1, $site, $db, 1);
            $this->within_site_flagging_visitlevel("aosi", 0.1, $site, $db, 'V06', 1);
            $this->within_site_flagging_visitlevel("aosi", 0.1, $site, $db, 'V12', 1);
            $this->within_site_flagging_visitlevel("ados_module1", 0.1, $site, $db, 'V24', 1);
            $this->within_site_flagging_visitlevel("ados_module1", 0.1, $site, $db, 'V36', 1);
            $this->within_site_flagging_visitlevel("ados_module1", 0.1, $site, $db, 'VSA', 1);
            $this->within_site_flagging_visitlevel("ados_module2", 0.1, $site, $db, 'V24', 1);
            $this->within_site_flagging_visitlevel("ados_module2", 0.1, $site, $db, 'V36', 1);
            $this->within_site_flagging_visitlevel("ados_module2", 0.1, $site, $db, 'VSA', 1);
            $this->within_site_flagging_visitlevel("ados_module3", 0.1, $site, $db, 'V24', 1);
            $this->within_site_flagging_visitlevel("ados_module3", 0.1, $site, $db, 'V36', 1);
            $this->within_site_flagging_visitlevel("ados_module3", 0.1, $site, $db, 'VSA', 1);

            $this->within_site_flagging_visitlevel("ados2_module1", 0.1, $site, $db, 'V24', 1);
            $this->within_site_flagging_visitlevel("ados2_module1", 0.1, $site, $db, 'V36', 1);
            $this->within_site_flagging_visitlevel("ados2_module1", 0.1, $site, $db, 'VSA', 1);
            $this->within_site_flagging_visitlevel("ados2_module2", 0.1, $site, $db, 'V24', 1);
            $this->within_site_flagging_visitlevel("ados2_module2", 0.1, $site, $db, 'V36', 1);
            $this->within_site_flagging_visitlevel("ados2_module2", 0.1, $site, $db, 'VSA', 1);
            $this->within_site_flagging_visitlevel("ados2_module3", 0.1, $site, $db, 'V24', 1);
            $this->within_site_flagging_visitlevel("ados2_module3", 0.1, $site, $db, 'V36', 1);
            $this->within_site_flagging_visitlevel("ados2_module3", 0.1, $site, $db, 'VSA', 1);

            //ibis 2 reliability
            $this->within_site_flagging_visitlevel("aims", 0.1, $site, $db, 'V03', 2);
            $this->within_site_flagging_visitlevel("aims", 0.05, $site, $db, 'V06', 2);
            $this->within_site_flagging_visitlevel("aims", 0.05, $site, $db, 'V09', 2);
            $this->within_site_flagging_visitlevel("aims", 0.05, $site, $db, 'V12', 2);
            $this->within_site_flagging_visitlevel("aims", 0.05, $site, $db, 'V15', 2);
            $this->within_site_flagging("adi_r_subject", 0.1, $site, $db, 2);
            $this->within_site_flagging("adi_r_proband", 0.1, $site, $db, 2);
            $this->within_site_flagging("aosi", 0.1, $site, $db, 2);
            $this->within_site_flagging("csbs", 0.1, $site, $db, 2);
            $this->within_site_flagging_visitlevel("ados2_module1", 0.1, $site, $db, 'V24', 2);
            $this->within_site_flagging_visitlevel("ados2_module1", 0.1, $site, $db, 'V36', 2);
            $this->within_site_flagging_visitlevel("ados2_module1", 0.1, $site, $db, 'VSA', 2);
            $this->within_site_flagging_visitlevel("ados2_module2", 0.1, $site, $db, 'V24', 2);
            $this->within_site_flagging_visitlevel("ados2_module2", 0.1, $site, $db, 'V36', 2);
            $this->within_site_flagging_visitlevel("ados2_module2", 0.1, $site, $db, 'VSA', 2);
            $this->within_site_flagging_visitlevel("ados2_module3", 0.1, $site, $db, 'V24', 2);
            $this->within_site_flagging_visitlevel("ados2_module3", 0.1, $site, $db, 'V36', 2);
            $this->within_site_flagging_visitlevel("ados2_module3", 0.1, $site, $db, 'VSA', 2);
        }

        foreach ($site_list as $site) {

            $this->cross_site_flagging("adi_r_subject", $site, array_remove($site, $site_list), $db, 1);
            $this->cross_site_flagging("aosi", $site, array("UofA"), $db, 1);
            $this->cross_site_flagging("csbs", $site, array_remove($site, $site_list), $db, 1);

            $this->cross_site_flagging_visitlevel("ados_module1", $site, array_remove($site, $site_list), $db, 'V24', 1);
            $this->cross_site_flagging_visitlevel("ados_module1", $site, array_remove($site, $site_list), $db, 'V36', 1);
            $this->cross_site_flagging_visitlevel("ados_module1", $site, array_remove($site, $site_list), $db, 'VSA', 1);
            $this->cross_site_flagging_visitlevel("ados_module2", $site, array_remove($site, $site_list), $db, 'V24', 1);
            $this->cross_site_flagging_visitlevel("ados_module2", $site, array_remove($site, $site_list), $db, 'V36', 1);
            $this->cross_site_flagging_visitlevel("ados_module2", $site, array_remove($site, $site_list), $db, 'VSA', 1);
            $this->cross_site_flagging_visitlevel("ados_module3", $site, array_remove($site, $site_list), $db, 'V24', 1);
            $this->cross_site_flagging_visitlevel("ados_module3", $site, array_remove($site, $site_list), $db, 'V36', 1);
            $this->cross_site_flagging_visitlevel("ados_module3", $site, array_remove($site, $site_list), $db, 'VSA', 1);
            $this->cross_site_flagging_visitlevel("ados2_module1", $site, array_remove($site, $site_list), $db, 'V24', 1);
            $this->cross_site_flagging_visitlevel("ados2_module1", $site, array_remove($site, $site_list), $db, 'V36', 1);
            $this->cross_site_flagging_visitlevel("ados2_module1", $site, array_remove($site, $site_list), $db, 'VSA', 1);
            $this->cross_site_flagging_visitlevel("ados2_module2", $site, array_remove($site, $site_list), $db, 'V24', 1);
            $this->cross_site_flagging_visitlevel("ados2_module2", $site, array_remove($site, $site_list), $db, 'V36', 1);
            $this->cross_site_flagging_visitlevel("ados2_module2", $site, array_remove($site, $site_list), $db, 'VSA', 1);
            $this->cross_site_flagging_visitlevel("ados2_module3", $site, array_remove($site, $site_list), $db, 'V24', 1);
            $this->cross_site_flagging_visitlevel("ados2_module3", $site, array_remove($site, $site_list), $db, 'V36', 1);
            $this->cross_site_flagging_visitlevel("ados2_module3", $site, array_remove($site, $site_list), $db, 'VSA', 1);

            // IBIS2 reliability
            $this->cross_site_flagging("aosi", $site, array("UofA"), $db, 2);
            //$this->cross_site_flagging("adi_r_subject", $site, array_remove($site, $site_list), $db, 2);
            $this->cross_site_flagging("csbs", $site, array_remove($site, $site_list), $db, 2);

            $this->cross_site_flagging_visitlevel("ados2_module1", $site, array_remove($site, $site_list), $db, 'V24', 2);
            $this->cross_site_flagging_visitlevel("ados2_module1", $site, array_remove($site, $site_list), $db, 'V36', 2);
            $this->cross_site_flagging_visitlevel("ados2_module1", $site, array_remove($site, $site_list), $db, 'VSA', 2);
            $this->cross_site_flagging_visitlevel("ados2_module2", $site, array_remove($site, $site_list), $db, 'V24', 2);
            $this->cross_site_flagging_visitlevel("ados2_module2", $site, array_remove($site, $site_list), $db, 'V36', 2);
            $this->cross_site_flagging_visitlevel("ados2_module2", $site, array_remove($site, $site_list), $db, 'VSA', 2);
            $this->cross_site_flagging_visitlevel("ados2_module3", $site, array_remove($site, $site_list), $db, 'V24', 2);
            $this->cross_site_flagging_visitlevel("ados2_module3", $site, array_remove($site, $site_list), $db, 'V36', 2);
            $this->cross_site_flagging_visitlevel("ados2_module3", $site, array_remove($site, $site_list), $db, 'VSA', 2);
            //ados2 module3

        }

    }

    function within_site_flagging($instrument, $ratio, $current_site, $db, $projectID){
        $db =& \Database::singleton();

        $phi_site_clause = '';
        if ($current_site == "PHI" && ($instrument == "adi_r_subject" || $instrument == "adi_r_proband")) {
            $phi_site_clause = " AND Date_taken >= '2009-11-11' ";
        }

        if ($current_site == "STL" && ($instrument == "aosi")) {
            $phi_site_clause = " AND Date_taken >= '2010-02-15' ";
        }


        $instrument_records = $db->pselect("SELECT i.CommentID FROM {$instrument} as i, flag as f, session as s, candidate as c WHERE i.CommentID=f.CommentID AND f.sessionID=s.ID AND s.CandID = c.CandID AND s.Current_stage<>'Recycling Bin' AND f.Data_entry='Complete' AND i.CommentID LIKE CONCAT('%',:currpsc,'%') AND s.visit_label<>'v18' AND i.CommentID NOT LIKE 'DDE%' {$phi_site_clause} AND f.Administration <> 'None' AND c.RegistrationProjectID =:pid ORDER BY RIGHT(i.CommentID, 6)", array("currpsc"=>$current_site,"pid"=>$projectID));
        $params = array();
        $params['currentSite']    = $current_site;
        $params['projectID']      = $projectID;
        $total_records_count = $db->pselectOne("SELECT COUNT(i.CommentID)
FROM {$instrument} as i, flag as f, session as s, candidate as c
WHERE i.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.CandID = c.CandID
AND s.Current_stage<>'Recycling Bin'
AND f.Data_entry='Complete'
AND i.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND s.visit_label<>'v18'
AND i.CommentID NOT LIKE 'DDE%'
AND f.Administration <> 'None'
AND c.RegistrationProjectID = :projectID
ORDER BY RIGHT(i.CommentID, 6)",$params);

        //$current_count = $db->selectOne("SELECT count(*) FROM reliability WHERE CommentID LIKE '%{$current_site}%' AND Instrument='{$instrument}' AND reliability_center_id={$this->site_id[$current_site]}");
        $params1=array();
        $params1['currentSite']    = $current_site;
        $params1['instrument'] = $instrument;
        $params1['currentSite_id'] = Reliability::getSiteID($current_site);
        $current_count = $db->pselectOne("SELECT count(*) FROM
(SELECT DISTINCT r.CommentID FROM reliability as r, flag as f, session as s
WHERE r.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND r.Instrument= :instrument
AND r.reliability_center_id=:currentSite_id
AND r.invalid = 'no'
AND r.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.Current_stage<>'Recycling Bin') as t",$params1);
        $total_count   = count($instrument_records);
        if ($ratio*$total_records_count >= $total_count) {
            $max = $total_count;
        } else {
            $max = floor($ratio * $total_records_count);
        }

        //echo("Site: {$current_site} <BR>");
        //echo($current_count . " --- " . $total_count . "<BR>");
        //echo("Max (ratio: {$ratio}/jump: {$jump_step}): {$max} <BR><BR>");

        for ($i = 0; $i < count($instrument_records) && $current_count + 1 <= $max; $i += 2) {
            $commentID = $instrument_records[$i]["CommentID"];
            if (!find_cID($commentID, $this->reliability_table)) {
                $db->insert(
                    'reliability',
                    array(
                     'CommentID'             => $instrument_records[$i]["CommentID"],
                     'reliability_center_id' => $this->site_id[$current_site],
                     'Instrument'            => $instrument,
                    )
                );
                $this->reliability_table[$instrument_records[$i]["CommentID"]] = $this->site_id[$current_site];
                $current_count++;
            }
        }
    }

    function cross_site_flagging($instrument, $current_site, $reliability_sites, $db, $projectID){
        $db =& \Database::singleton();

        $ratio = 0.1;
        $reliability_site_index = 0;
        // We want the site to be random, starting from 0 causes a bias towards the first entry
        // in $reliability_sites.. so shuffle the array to eliminate the bias
        shuffle($reliability_sites);

        $query_extra = '';
        if ($instrument == "adi_r_subject") {
            $query_extra = " AND (s.visit_label='v24' OR s.visit_label='v36')";
        }

        $phi_site_clause = '';
        if ($current_site == "PHI" && ($instrument == "adi_r_subject" || $instrument == "adi_r_proband")) {
            $phi_site_clause = " AND Date_taken >= '2009-11-11' ";
        }
        if ($current_site == "STL" && ($instrument == "aosi")) {
            $phi_site_clause = " AND Date_taken >= '2010-02-15' ";
        }

        $instrument_records = $db->pselect("SELECT i.CommentID FROM {$instrument} as i, flag as f, session as s, candidate as c WHERE i.CommentID=f.CommentID AND f.sessionID=s.ID AND s.CandID = c.CandID AND s.Current_stage<>'Recycling Bin' AND f.Data_entry='Complete' AND i.CommentID LIKE CONCAT('%',:currpsc,'%') AND s.visit_label<>'v18' {$query_extra} AND i.CommentID NOT LIKE 'DDE%' {$phi_site_clause} AND f.Administration <> 'None' AND c.RegistrationProjectID = :pid ORDER BY RIGHT(i.CommentID, 6)", array("currpsc"=>$current_site,"pid"=>$projectID));
        $params = array();
        $params['currentSite']    = $current_site;
        $params['projectID']      = $projectID;
        $total_records_count = $db->pselectOne("SELECT COUNT(i.CommentID) FROM {$instrument}
 as i, flag as f, session as s, candidate c
 WHERE i.CommentID=f.CommentID
 AND f.sessionID=s.ID
 AND s.CandID=c.CandID
 AND s.Current_stage<>'Recycling Bin'
 AND f.Data_entry='Complete'
 AND i.CommentID LIKE CONCAT('%', :currentSite ,'%')
 AND s.visit_label<>'v18'{$query_extra}
 AND i.CommentID NOT LIKE 'DDE%'
 AND f.Administration <> 'None'
 AND c.RegistrationProjectID =:projectID
 ORDER BY RIGHT(i.CommentID, 6)",$params);
        $params1=array();
        $params1['currentSite']    = $current_site;
        $params1['instrument'] = $instrument;
        $params1['currentSite_id'] = Reliability::getSiteID($current_site);
        $current_count = $db->pselectOne("SELECT count(*) FROM
(SELECT DISTINCT r.CommentID
FROM reliability as r, flag as f, session as s
WHERE r.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND r.Instrument=:instrument
AND r.reliability_center_id<>:currentSite_id
AND r.invalid = 'no'
AND r.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.Current_stage<>'Recycling Bin') as t",$params1);
        $total_count   = count($instrument_records);
        if ($ratio*$total_records_count >= $total_count) {
            $max = $total_count;
        } else {
            $max = floor($ratio * $total_records_count);
        }
        //
        // echo("Site: {$current_site} <BR>");
        // echo($current_count . " --- " . $total_count . "<BR>");
        // echo("Max (ratio: {$ratio}/jump: {$jump_step}): {$max} <BR><BR>");

        for ($i = 0; $i < count($instrument_records) && $current_count + 1 <= $max; $i += 2) {
            $commentID = $instrument_records[$i]["CommentID"];
            if (!find_cID($commentID, $this->reliability_table)) {
                $db->insert(
                    'reliability',
                    array(
                     'CommentID'             => $instrument_records[$i]["CommentID"],
                     'reliability_center_id' => $this->site_id[$reliability_sites[$reliability_site_index]],
                     'Instrument'            => $instrument,
                    )
                );
                $this->reliability_table[$instrument_records[$i]["CommentID"]] = $this->site_id[$current_site];
                $current_count++;
            }
            $reliability_site_index = ($reliability_site_index + 1) % count($reliability_sites);
        }
    }
    function within_site_flagging_visitlevel($instrument, $ratio, $current_site, $db,$visit_label, $projectID){
        $db =& \Database::singleton();

        $instrument_records = $db->pselect("SELECT i.CommentID FROM {$instrument} as i, flag as f, session as s, candidate as c WHERE i.CommentID=f.CommentID AND f.sessionID=s.ID AND s.CandID = c.CandID AND s.Current_stage<>'Recycling Bin' AND f.Data_entry='Complete' AND i.CommentID LIKE CONCAT('%',:currpsc,'%') AND s.visit_label =:vl AND i.CommentID NOT LIKE 'DDE%' AND f.Administration <> 'None' AND c.RegistrationProjectID = :pid ORDER BY RIGHT(i.CommentID, 6)", array("currpsc"=>$current_site,"vl"=>$visit_label,"pid"=>$projectID));
        $params = array();
        $params['currentSite']    = $current_site;
        $params['projectID']      = $projectID;
        $params['vl']=$visit_label;
        $total_records_count = $db->pselectOne("
SELECT COUNT(i.CommentID)
FROM {$instrument} as i, flag as f, session as s, candidate as c
WHERE i.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.CandID = c.CandID
AND s.Current_stage<>'Recycling Bin'
AND f.Data_entry='Complete'
AND i.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND s.visit_label =:vl
AND i.CommentID NOT LIKE 'DDE%'
AND f.Administration <> 'None'
AND c.RegistrationProjectID =:projectID
ORDER BY RIGHT(i.CommentID, 6)",$params);
        // $current_count = $db->selectOne("SELECT count(*) FROM reliability WHERE CommentID LIKE '%{$current_site}%' AND Instrument='{$instrument}' AND reliability_center_id={$this->site_id[$current_site]}");
        $params1=array();
        $params1['currentSite']    = $current_site;
        $params1['instrument'] = $instrument;
        $params1['currentSite_id'] = Reliability::getSiteID($current_site);
        $current_count = $db->pselectOne("SELECT count(*)
FROM (SELECT DISTINCT r.CommentID FROM reliability as r, flag as f, session as s
WHERE r.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND r.Instrument=:instrument
AND r.reliability_center_id=:currentSite_id
AND r.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.Current_stage<>'Recycling Bin') as t",$params1);
        $total_count   = count($instrument_records);
        if ($ratio*$total_records_count >= $total_count) {
            $max = $total_count;
        } else {
            $max = floor($ratio * $total_records_count);
        }

        //echo("Site: {$current_site} <BR>");
        //echo($current_count . " --- " . $total_count . "<BR>");
        //echo("Max (ratio: {$ratio}/jump: {$jump_step}): {$max} <BR><BR>");

        for ($i = 0; $i < count($instrument_records) && $current_count + 1 <= $max; $i += 2) {
            $commentID = $instrument_records[$i]["CommentID"];
            if (!find_cID($commentID, $this->reliability_table)) {
                $db->insert(
                    'reliability',
                    array(
                     'CommentID'             => $instrument_records[$i]["CommentID"],
                     'reliability_center_id' => $this->site_id[$current_site],
                     'Instrument'            => $instrument,
                    )
                );
                $this->reliability_table[$instrument_records[$i]["CommentID"]] = $this->site_id[$current_site];
                $current_count++;
            }
        }
    }

    function cross_site_flagging_visitlevel($instrument, $current_site, $reliability_sites, $db, $visit_label, $projectID){
        $db =& \Database::singleton();

        $ratio = 0.1;
        $reliability_site_index = 0;
        // We want the site to be random, starting from 0 causes a bias towards the first entry
        // in $reliability_sites.. so shuffle the array to eliminate the bias
        shuffle($reliability_sites);

        $query_extra = '';
        if ($instrument == "adi_r_subject") {
            $query_extra = " AND (s.visit_label='v24' OR s.visit_label='v36')";
        }

        $phi_site_clause = '';
        if ($current_site == "PHI" && ($instrument == "adi_r_subject" || $instrument == "adi_r_proband")) {
            $phi_site_clause = " AND Date_taken >= '2009-11-11' ";
        }
        if ($current_site == "STL" && ($instrument == "aosi")) {
            $phi_site_clause = " AND Date_taken >= '2010-02-15' ";
        }
        $instrument_records = $db->pselect("SELECT i.CommentID FROM {$instrument} as i, flag as f, session as s, candidate as c WHERE i.CommentID=f.CommentID AND f.sessionID=s.ID AND s.CandID = c.CandID AND s.Current_stage<>'Recycling Bin' AND f.Data_entry='Complete' AND i.CommentID LIKE CONCAT('%',:currpsc,'%') AND s.visit_label=:vl {$query_extra} AND i.CommentID NOT LIKE 'DDE%' {$phi_site_clause} AND f.Administration <> 'None' AND c.RegistrationProjectID =:pid ORDER BY RIGHT(i.CommentID, 6)", array("currpsc"=>$current_site,"vl"=>$visit_label,"pid"=>$projectID));
        $params = array();
        $params['currentSite']    = $current_site;
        $params['projectID']      = $projectID;
        $params['vl']=$visit_label;
        $total_records_count = $db->pselectOne("SELECT COUNT(i.CommentID)
FROM {$instrument} as i, flag as f, session as s, candidate as c
WHERE i.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.CandID = c.CandID
AND s.Current_stage<>'Recycling Bin'
AND f.Data_entry='Complete'
AND i.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND s.visit_label=:vl
{$query_extra}
AND i.CommentID NOT LIKE 'DDE%'
AND f.Administration <> 'None'
AND c.RegistrationProjectID =:projectID
ORDER BY RIGHT(i.CommentID, 6)",$params);
        $params1=array();
        $params1['currentSite']    = $current_site;
        $params1['instrument'] = $instrument;
        $params1['currentSite_id'] = Reliability::getSiteID($current_site);
        $current_count = $db->pselectOne("SELECT count(*)
FROM (SELECT DISTINCT r.CommentID FROM reliability as r, flag as f, session as s
WHERE r.CommentID LIKE CONCAT('%', :currentSite ,'%')
AND r.Instrument=:instrument
AND r.reliability_center_id<>:currentSite_id
AND r.CommentID=f.CommentID
AND f.sessionID=s.ID
AND s.Current_stage<>'Recycling Bin') as t",$params1);
        $total_count   = count($instrument_records);
        if ($ratio*$total_records_count >= $total_count) {
            $max = $total_count;
        } else {
            $max = floor($ratio * $total_records_count);
        }
        //
        // echo("Site: {$current_site} <BR>");
        // echo($current_count . " --- " . $total_count . "<BR>");
        // echo("Max (ratio: {$ratio}/jump: {$jump_step}): {$max} <BR><BR>");
        for ($i = 0; $i < count($instrument_records) && $current_count + 1 <= $max; $i += 2) {
            $commentID = $instrument_records[$i]["CommentID"];
            if (!find_cID($commentID, $this->reliability_table)) {
                $db->insert(
                    'reliability',
                    array(
                     'CommentID'             => $instrument_records[$i]["CommentID"],
                     'reliability_center_id' => $this->site_id[$reliability_sites[$reliability_site_index]],
                     'Instrument'            => $instrument,
                    )
                );
                $this->reliability_table[$instrument_records[$i]["CommentID"]] = $this->site_id[$current_site];
                $current_count++;
            }
            $reliability_site_index = ($reliability_site_index + 1) % count($reliability_sites);
        }
    }
    /* To be discussed with Tanya
     function cross_site_flagging_aims($current_site, $reliability_sites, $db, $projectID){
         $ratio = 0.1;
         $reliability_site_index = 0;
         // We want the site to be random, starting from 0 causes a bias towards the first entry
         // in $reliability_sites.. so shuffle the array to eliminate the bias
         shuffle($reliability_sites);

         $query_extra = '';
         $instrument = "aims";
         $db->select("SELECT i.CommentID FROM {$instrument} as i, flag as f, session as s, candidate as c WHERE i.CommentID=f.CommentID AND f.sessionID=s.ID AND s.CandID = c.CandID AND s.Current_stage<>'Recycling Bin' AND f.Data_entry='Complete' AND i.CommentID LIKE '%{$current_site}%' AND s.visit_label<>'v18'{$query_extra} AND i.CommentID NOT LIKE 'DDE%'  AND f.Administration <> 'None' AND c.RegistrationProjectID = $projectID ORDER BY RIGHT(i.CommentID, 6)", $instrument_records);
         $total_records_count = $db->selectOne("SELECT COUNT(i.CommentID) FROM {$instrument} as i, flag as f, session as s, candidate c WHERE i.CommentID=f.CommentID AND f.sessionID=s.ID AND s.CandID=c.CandID AND s.Current_stage<>'Recycling Bin' AND f.Data_entry='Complete' AND i.CommentID LIKE '%{$current_site}%' AND s.visit_label<>'v18'{$query_extra} AND i.CommentID NOT LIKE 'DDE%' AND f.Administration <> 'None' AND c.RegistrationProjectID = $projectID ORDER BY RIGHT(i.CommentID, 6)");

          $current_count = $db->selectOne("SELECT count(*) FROM (SELECT DISTINCT r.CommentID FROM reliability as r, flag as f, session as s  WHERE r.CommentID LIKE '%{$current_site}%' AND r.Instrument='{$instrument}' AND r.reliability_center_id<>{$this->site_id[$current_site]} AND r.invalid = 'no' AND r.CommentID=f.CommentID AND f.sessionID=s.ID AND s.Current_stage<>'Recycling Bin') as t");
         $total_count = count($instrument_records);
         if($ratio*$total_records_count >= $total_count) {
             $max = $total_count;
         } else {
             $max = floor($ratio * $total_records_count);
         }

        for($i = 0; $i < count($instrument_records) && $current_count + 1 <= $max; $i += 2){
           $commentID = $instrument_records[$i]["CommentID"];
           if(!find_cID($commentID, $this->reliability_table)){
             $db->insert('reliability', array('CommentID' => $instrument_records[$i]["CommentID"],
                                               'reliability_center_id' => $this->site_id[$reliability_sites[$reliability_site_index]],
                                               'Instrument' => $instrument
                                               ));
             $this->reliability_table[$instrument_records[$i]["CommentID"]] = $this->site_id[$current_site];
             $current_count++;
           }
           $reliability_site_index = ($reliability_site_index + 1) % count($reliability_sites);
        }
     }
 */
    function get_current_index($instrument, $current_site, $reliability_sites, $db){
        $db =& \Database::singleton();

        $site_name = array_flip($this->site_id);
        $params1=array();
        $params1['currentSite']    = $current_site;
        $params1['instrument'] = $instrument;
        $params1['currentSite_id'] = Reliability::getSiteID($current_site);
        $last_site = $db->pselectOne("SELECT reliability_center_id
FROM reliability where ID=(select max(ID) FROM reliability
WHERE CommentID LIKE CONCAT('%', :currentSite ,'%')
AND Instrument=:instrument
AND reliability_center_id<>:currentSite_id)",$params1);
        if (empty($last_site)) {
            return 0;
        } else {
            return (array_search($site_name[$last_site], $reliability_sites) + 1) % count($reliability_sites);
        }
    }

    function _swap_candidates()
    {
        $user =& \User::singleton();

        if (!($user->hasPermission('reliability_swap_candidates'))) {
            return array("error" => "You do not have permission to swap candidates");
        }
        $user =& \User::singleton();
        if (!($user->hasPermission('reliability_swap_candidates'))) {
            return array(
                "error" => "You do not have permission".
                    " to swap candidates",
            );
        }
        $DB            =& \Database::singleton();
        $params        = array();
        $params['pid'] = $_POST['Cand1PSCID'];
        $params['measure'] = $_POST['SwapInstrument'];
        $params['id_V']    = $_POST['Cand1Visit_label'];
        $params_new        = array();
        $params_new['id_Replace']  = $_POST['Cand2PSCID'];
        $params_new['id_replaceV'] = $_POST['Cand2Visit_label'];
        $query ="SELECT reliability.CommentID as OldID,".
            " reliability.reliability_center_id as CenterID,".
            " reliability.Reliability_score as Score,".
            " candidate.RegistrationCenterID as OldCenterID ".
            " FROM candidate JOIN session ON ".
            "(session.CandID = candidate.CandID) ".
            "JOIN flag ON (flag.SessionID = session.ID) ".
            "JOIN reliability ON ( reliability.CommentID=flag.CommentID)".
            " WHERE candidate.PSCID=:pid AND".
            " reliability.Instrument=:measure and ".
            "session.Visit_label=:id_V AND flag.Data_entry ".
            "IS NOT NULL and flag.Data_entry <> 'None'";
        $CommentID = $DB->pselectRow($query, $params);
        if (!$CommentID) {
            return array(
                'error' => $params_new['id_Replace']."/".
                    $params_new['id_replaceV']." did not complete".
                    $params['measure'].
                    " or data not entered. Cannot swap candidates.",
            );
        }
        $params_new['Instrument'] = $_POST['SwapInstrument'];
        $query        ="SELECT f.CommentID as NewID, c.CenterID as NewCenterID".
            " FROM session s join flag f ON (f.SessionID=s.ID)".
            " JOIN candidate c ON (c.CandID=s.CandID)".
            " WHERE f.Test_name=:Instrument and c.PSCID=:id_Replace".
            " AND s.Visit_label=:id_replaceV AND".
            " f.Data_entry IS NOT NULL and f.Data_entry <> 'None'";
        $newCommentID = $DB->pselectRow($query, $params_new);
        if (!$newCommentID) {
            $error_msg = $params_new['id_Replace']."/".
                $params_new['id_replaceV']." did not complete".
                $params_new['Instrument'].
                " or data not entered. Cannot swap candidates.";
            return array('error' => $error_msg);
        }
        if ($newCommentID['NewCenterID'] !== $CommentID['OldCenterID']) {
            return array(
                'error' => "Candidates are not from the same site.".
                    " Cannot swap candidates across sites.",
            );
        } elseif (!in_array($newCommentID['NewCenterID'], $user->getCenterIDs())) {
            $error_msg = $params_new['id_Replace']."/".
                $params_new['id_replaceV'].
                " is from a different site than you.".
                " Can only swap candidates from the same site.";
            return array('error' => $error_msg);
        } elseif (!in_array($CommentID['OldCenterID'], $user->getCenterIDs())) {
            $error_msg = $params_new['id_Replace']."/".
                $params_new['id_replaceV'].
                " is from a different site than you.".
                " Can only swap candidates from the same site.";
            return array('error' => $error_msg);
        }
        $value            = array('NewID' => $newCommentID['NewID']);
        $replacementCheck = $DB->pselectRow(
            "SELECT CommentID FROM reliability WHERE CommentID=:NewID",
            $value
        );
        if (!empty($replacementCheck)) {
            $error_msg = $params_new['id_Replace']."/".
                $params_new['id_replaceV'].
                " already in reliability. Cannot swap".
                $params['pid']."/".$params['id_V']."for it";
            return array('error' => $error_msg);
        }
        $CenterID = $CommentID['CenterID'];
        if (!empty($CommentID['Score'])) {
            return array(
                "error" => "Reliability score already exists for".
                    $params['pid']."/".$params['id_V'].
                    "Can not swap candidate.",
            );
        }
        $where_criteria = array(
            'CommentID'  => $CommentID['OldID'],
            'Instrument' => $params['measure'],
        );
        $values         = array(
            'invalid'     => 'yes',
            'manual_swap' => 'yes',
        );
        $DB->update('reliability', $values, $where_criteria);
        $DB->insert(
            'reliability',
            array(
                'CommentID'             => $newCommentID['NewID'],
                'reliability_center_id' => $CenterID,
                'Instrument'            => $params['measure'],
                'Manual_Swap'           => 'yes',
            )
        );
        return array(
            "message" => "Swapped candidate".$params['pid'].
                " for".$params_new['id_Replace'],
        );
    }

    function _addCandidate()
    {
        $user =& \User::singleton();
        $DB   =& \Database::singleton();

        if (!($user->hasPermission('EARLI_Reliability'))) {
            return array("error" => "You do not have permission to add EARLI candidates");
        }
        $Instrument  = $_POST['AddInstrument'];
        $CenterID    = $_POST['AddReliabilityCenter'];
        $Visit_label = $_POST['AddVisit_label'];
        if (!$Visit_label) {
            return array("error" => "You must specify a visit label");
        }

        if (!$Instrument) {
            return array("error" => "You must specify an instrument");
        }
        if (!$CenterID) {
            return array("error" => "You must specify a center for reliability testing");
        }

        $PSCID     = $_POST['AddPSCID'];
        $params = array();
        $params['pscid']    = $PSCID;
        $params['instrument']      = $Instrument;
        $params['vl']=$Visit_label;
        $CommentID = $DB->pselectOne("SELECT CommentID FROM flag f
JOIN session s ON (s.ID=f.SessionID)
JOIN candidate c USING (CandID)
WHERE f.Test_name=:instrument
AND c.PSCID=:pscid
AND s.Visit_label=:vl",$params);
        if (!$CommentID) {
            return array("error" => "$PSCID/$Visit_label does not have data entered for $Instrument");

        }
        $DB->run("INSERT INTO reliability (CommentID, reliability_center_id, Instrument, Manual_Swap, EARLI_Candidate) VALUES ('$CommentID', $CenterID, '$Instrument', 'no', 'yes')");
        return array("message" => "Inserted new reliability candidate $PSCID/$Visit_label for EARLI collaboration");
    }
    /**
     * Override toJSON to append a calculated field to the default JSON object
     *
     * @return string json encoded string of the headers and data from this table
     */
    function toJSON(): string
    {
        $tableData = $this->toArray();
        $threshold = $this->getThreshholds();
        $cohort    = \Utility::getSubprojectList();

        foreach ($tableData['Data'] as $key => $record) {

            // Calculate and set `Reliable` column
            $instrumentThreshold = isset($record[9], $threshold[$record[9]]) ?
                $threshold[$record[9]] :
                null;
            $instrumentScore     = $record[11];

            // Map cohort id to a string value
            $record[3] = $cohort[$record[3]];

            if ($instrumentScore == null) {
                $isReliable = "";
            } else if ($instrumentScore >= $instrumentThreshold) {
                $isReliable = "Yes";
            } else {
                $isReliable = "No";
            }
           if($record[10]!="No")
            {
                $db           = \Database::singleton();
                $video_params = $db->pselectRow(
                    "SELECT File_name as fn, uploaded_by as up FROM videos WHERE record_id= :rid",
                    array('rid' => $record[10])
                );
                $record[10] ="Yes,".$video_params['up'].",".$video_params['fn'] ;
            }


            $record[] = $isReliable;

            $tableData['Data'][$key] = $record;
        }

        return json_encode($tableData);
    }


    /**
     * Include the column formatter required to display the feedback link colours
     * in the candidate_list menu
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
             $baseURL . "/reliability/js/reliability_helper.js",
                $baseURL . "/reliability/js/columnFormatter.js",

            )
        );
    }
}
?>
