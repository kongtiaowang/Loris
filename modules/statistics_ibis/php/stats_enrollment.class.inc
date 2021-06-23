<?php
/**
 * The module used to display the IBIS enrollment statistics tab.
 *
 * PHP Version 7
 *
 * @category Loris
 * @package  Main
 * @author   Nicolas Brossard
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/IBIS
 */

namespace LORIS\statistics_ibis;

/**
 * The module used to display the IBIS enrollment statistics tab.
 *
 * PHP Version 7
 *
 * @category Loris
 * @package  Main
 * @author   Nicolas Brossard
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/IBIS
 */
class Stats_Enrollment extends \NDB_Form
{
    /**
     * Determine whether the user has access to the module or not.
     *
     * @return bool true if the user has access, false otherwise.
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('data_entry');
    }

    /**
     * InCenter function.
     *
     * @param string $centerID the value of centreID.
     * @param string $Centres  the value of Centres.
     *
     * @return bool
     */
    function _inCenter($centerID, $Centres) {
        foreach ($Centres as $Centre) {
            if($Centre['NumericID'] == $centerID) {
                return true;
            }
        }
        return false;
    }


    /**
     * Sets up the module prior to displaying it.
     *
     * @return void.
     */
    function setup()
    {
        parent::setup();

        $DB =& \Database::singleton();

        $centers = $DB->pselect("SELECT CONCAT('C', CenterID) as ID, CenterID as NumericID, PSCArea as LongName, Name as ShortName FROM psc WHERE CenterID <> '1' AND Study_site = 'Y'", array());

        $this->tpl_data['Centers'] = $centers;
        $this->tpl_data['Sites'] = array('' => 'All Sites');
        $this->tpl_data['SubProjects'] = array('' => 'All SubProjects');
        $projects[null] = 'All Projects';
        foreach(\Utility::getProjectList() as $key => $value) {
            $projects[$key] = $value;
        }
        $this->tpl_data['Projects'] = $projects;

        foreach ($centers as $row) {
            $this->tpl_data['Sites'][$row['NumericID']] = $row['LongName'];
            if($_REQUEST['EnrollmentSite'] == $row['NumericID']) {
                $this->tpl_data['CurrentSite'] = array('ID' => $row['NumericID'], 'Name' => $row['LongName']);
            }
        }
        if(isset($_REQUEST['EnrollmentProject']) && $_REQUEST['EnrollmentProject'] != '') {
            $ExtraProject_Criteria = ' AND (c.RegistrationProjectID IS NULL OR c.RegistrationProjectID=' . $_REQUEST['EnrollmentProject'] . ')';
            $currentProject = $_REQUEST['EnrollmentProject'];
            $this->tpl_data['CurrentProject'] = array('ID' => $currentProject, 'Name' => $projects[$currentProject]);
            $SubProjects= \Utility::getSubprojectsForProject($_REQUEST['EnrollmentProject']);
            if (is_array($SubProjects)) {
                $this->tpl_data['SubProjects'] = array('' => 'All SubProjects') + $SubProjects;
                $currentSubProject = $_REQUEST['EnrollmentSubProject'];
                $this->tpl_data['CurrentSubProject'] = array('ID' => $currentSubProject, 'Name' => $SubProjects[$currentSubProject]);
            }
        } else {
            $ExtraProject_Criteria = '';
        }

        if($_REQUEST['EnrollmentProject'] == $row['NumericID']) {
            $this->tpl_data['CurrentProject'] = array('ID' => $row['NumericID'], 'Name' => $row['LongName']);
        }
        $this->tpl_data['enrollment_completion'] = $this->getEnrollmentData($_REQUEST['EnrollmentSite'],$_REQUEST['EnrollmentProject'],$_REQUEST['EnrollmentSubProject']);
    }

    /**
     * Determine the enrollment stats for a given site/project/subproject
     * trio.
     *
     * @param int site (center) ID.
     * @param int project ID.
     * @param int subproject ID.
     *
     * @return array the enrollment data.
     */
    function getEnrollmentData($siteID= null, $projID= null, $subpjID=null){
        $DB =& \Database::singleton();
        $enroll_data = array();
        $params = array();
        $Extra_Where = '';
        if(!empty($siteID)) {
            $Extra_Where .= " AND sn.CenterID = :site"; //$_REQUEST['site'];
            $params['site'] = $siteID;
        }
        if(!empty($projID)) {
            $Extra_Where .= " AND  cad.RegistrationProjectID = :project"; //$_REQUEST['site'];
            $params['project'] = $projID;
        }
        if(!empty($subpjID)) {
            $Extra_Where .= " AND  sn.SubprojectID = :subproject";
            $params['subproject'] = $subpjID;
        }
        $ethnic_categories = array("hispanic","non_hispanic","not_answered");
        $ethnic_name = array("Hispanic or Latino", "Not Hispanic or Latino",
            "Unknown (individuals not reporting ethnicity)");
        $cat_count = 0;
        $cat_total = array('Female' =>0, 'Male' =>0, 'Unknown' =>0);
        foreach($ethnic_categories as $ethnic_cat){
            $gender = array('Female' => 0, 'Male' => 0, 'Unknown' => 0);
            if($ethnic_cat === "not_answered") {
                $results = $DB->pselect("SELECT RegistrationProjectID, COALESCE(Sex, 'Unknown') as Sex, COUNT( DISTINCT cad.CandID) as val
                    FROM candidate cad
                    JOIN session sn on cad.CandID= sn.CandID
                    JOIN flag fg on sn.ID = fg.SessionID
                    JOIN tsi ti on fg.CommentID = ti.CommentID
                    LEFT JOIN participant_status p ON cad.CandID = p.CandID
                    WHERE (ti.child_ethnicity = '$ethnic_cat' OR ti.child_ethnicity IS NULL)
                    AND fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1' AND sn.Active='Y'
                    AND cad.Active='Y' $Extra_Where AND fg.Administration <> 'None'
                    GROUP BY Sex,RegistrationProjectID
                    ", $params);
            }
            else{
                $results = $DB->pselect("SELECT RegistrationProjectID, COALESCE(Sex, 'Unknown') as Sex, COUNT( DISTINCT cad.CandID) as val
                    FROM candidate cad
                    JOIN session sn on cad.CandID= sn.CandID
                    JOIN flag fg on sn.ID = fg.SessionID
                    JOIN tsi ti on fg.CommentID = ti.CommentID
                    LEFT JOIN participant_status p ON cad.CandID = p.CandID
                    WHERE ti.child_ethnicity = '$ethnic_cat'
                    AND fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1' AND sn.Active='Y'
                    AND cad.Active='Y' $Extra_Where AND fg.Administration <> 'None'
                    GROUP BY Sex,RegistrationProjectID
                    ", $params);
            }
            if(is_null($results)){
            }else{
                foreach($results as $row){
                    $Gender = $row['Sex'];
                    $Count = $row['val'];
                    //$total_count += $Count;
                    if(is_null($Gender)) {
                        $gender['Unknown'] = $Count;
                    } else {
                        $gender[$Gender] = $Count;
                        $cat_total[$Gender] += $Count;
                    }

                }}
            $enroll_data[] = array('ethnic_cat' => $ethnic_name[$cat_count],'female_count' => $gender['Female'],'male_count' => $gender['Male'],'unknown_count' => $gender['Unknown'],'total_count' =>array_sum($gender) );
            $cat_count++;
        }

        $enroll_data_total[] = array('total_name' =>" Ethnic Category: Total of All Subjects",'total_female'=>$cat_total['Female'],'total_male'=>$cat_total['Male'],'total_unknown'=> $cat_total['Unknown'],'total_total'=> array_sum($cat_total));

        $enroll_data_race = array();

        $race_categories = array("american_indian_alaska_native","asian","native_hawaiian_pacific_islander","black_african_american","white","more_than_one_race","unknown_not_reported");
        $race_name = array("American Indian/Alaska Native", "Asian", "Native Hawaiian or Other Pacific Islander","Black or African American","White"," More Than One Race","Unknown or Not Reported");
        $race_count = 0;
        $race_total = array('Female' =>0, 'Male' =>0, 'Unknown' =>0);
        $gender = array('Female' => 0, 'Male' => 0, 'Unknown' => 0);

        foreach($race_categories as $race_cat){
            $gender = array('Female' => 0, 'Male' => 0, 'Unknown' => 0);

            if($race_cat === "more_than_one_race"){
                $race_cat = '%'.$race_cat.'%';
                $results = $DB->pselect("SELECT COALESCE(Sex, 'Unknown') as Sex, COUNT( DISTINCT cad.CandID) as val
                        FROM candidate cad
                        JOIN session sn on cad.CandID= sn.CandID
                        LEFT JOIN flag fg on sn.ID = fg.SessionID
                        LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                        LEFT JOIN participant_status p ON cad.CandID = p.CandID
                        WHERE ( ti.candidate_race LIKE  '$race_cat' OR ti.candidate_race LIKE '%{@}%' )
                        AND fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1' AND sn.Active='Y'
                        AND cad.Active='Y' $Extra_Where
                        AND fg.Administration <> 'None' AND fg.Test_name='tsi'
                        GROUP BY Sex" , $params);
            }
            else if($race_cat === "unknown_not_reported"){
                $results = $DB->pselect("SELECT COALESCE(Sex, 'Unknown') as Sex, COUNT( DISTINCT cad.CandID) as val FROM candidate cad
                        JOIN session sn on cad.CandID= sn.CandID
                        LEFT JOIN flag fg on sn.ID = fg.SessionID
                        LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                        LEFT JOIN participant_status p ON cad.CandID = p.CandID
                        WHERE (ti.candidate_race LIKE  '$race_cat'OR ti.candidate_race IS NULL)
                        AND fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1' AND sn.Active='Y'
                        AND cad.Active='Y' $Extra_Where AND fg.Administration <> 'None'
                        AND fg.Test_name='tsi'
                        GROUP BY Sex" ,$params);

            }else{

                $results = $DB->pselect("SELECT COALESCE(Sex, 'Unknown') as Sex, COUNT( DISTINCT cad.CandID) as val
                        FROM candidate cad
                        JOIN session sn on cad.CandID= sn.CandID
                        LEFT JOIN flag fg on sn.ID = fg.SessionID
                        LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                        LEFT JOIN participant_status p ON cad.CandID = p.CandID
                        WHERE ti.candidate_race LIKE  '$race_cat' AND fg.CommentID NOT LIKE 'DDE%'
                        AND sn.CenterID <> '1' AND sn.Active='Y' AND cad.Active='Y' $Extra_Where
                        AND fg.Administration <> 'None' AND fg.Test_name='tsi'
                        GROUP BY Sex" , $params);
            }

            $Count = 0;
            foreach($results as $row){
                $Gender = $row['Sex'];
                $Count = $row['val'];
                if(is_null($Count)){
                    $Count = 0;
                }
                //$total_count += $Count;
                if(is_null($Gender)) {
                    $gender['Unknown'] = $Count;
                } else {
                    $gender[$Gender] = $Count;
                    $race_total[$Gender] += $Count;
                }

            }


            $enroll_data_race[] = array('race_cat' => $race_name[$race_count],'female_count' => $gender['Female'],'male_count' => $gender['Male'],'unknown_count' => $gender['Unknown'],'total_count' => array_sum($gender));
            $race_count++;

        }
        $enroll_data_racetotal[] = array('total_name' =>" Racial Categories: Total of All Subjects",'total_female'=>$race_total['Female'],'total_male'=>$race_total['Male'],'total_unknown'=> $race_total['Unknown'],'total_total'=> array_sum($race_total));


        $enroll_data_hispanic = array();
        $hispanic_race_count = 0;
        $hispanic_total = array('Female' =>0, 'Male' =>0, 'Unknown' =>0);
        $gender = array('Female' => 0, 'Male' => 0, 'Unknown' => 0);

        foreach($race_categories as $race_cat){
            $gender = array('Female' => 0, 'Male' => 0, 'Unknown' => 0);
            if($race_cat === "more_than_one_race"){
                $race_cat = '%'.$race_cat.'%';
                $results = $DB->pselect("SELECT COALESCE(Sex, 'Unknown') as Sex, COUNT( DISTINCT cad.CandID) as val FROM candidate cad
                        JOIN session sn on cad.CandID= sn.CandID
                        LEFT JOIN flag fg on sn.ID = fg.SessionID
                        LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                        LEFT JOIN participant_status p ON cad.CandID = p.CandID
                        WHERE ( ti.candidate_race LIKE  '$race_cat' OR ti.candidate_race LIKE '%{@}%' )
                        AND ti.child_ethnicity='hispanic' AND fg.CommentID NOT LIKE 'DDE%'
                        AND sn.CenterID <> '1' AND sn.Active='Y' AND cad.Active='Y' $Extra_Where
                        AND fg.Administration <> 'None' AND fg.Test_name='tsi'
                        GROUP BY Sex" , $params);
            }
            else if($race_cat === "unknown_not_reported"){
                $results = $DB->pselect("SELECT COALESCE(Sex,'Unknown') as Sex ,COUNT( DISTINCT cad.CandID) as val FROM candidate cad
                        JOIN session sn on cad.CandID= sn.CandID
                        LEFT JOIN flag fg on sn.ID = fg.SessionID
                        LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                        LEFT JOIN participant_status p ON cad.CandID = p.CandID
                        WHERE (ti.candidate_race LIKE '$race_cat' OR ti.candidate_race IS NULL)
                        AND ti.child_ethnicity='hispanic' AND fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1' AND sn.Active='Y'
                        AND cad.Active='Y' $Extra_Where  AND fg.Administration <> 'None'
                        AND fg.Test_name='tsi'
                        GROUP BY Sex" , $params);
            }else{
                $results = $DB->pselect("SELECT COALESCE(Sex, 'Unknown') as Sex,COUNT( DISTINCT cad.CandID) as val FROM candidate cad
                        JOIN session sn on cad.CandID= sn.CandID
                        LEFT JOIN flag fg on sn.ID = fg.SessionID
                        LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                        LEFT JOIN participant_status p ON cad.CandID = p.CandID
                        WHERE ti.candidate_race LIKE '$race_cat' AND ti.child_ethnicity='hispanic'
                        AND fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1' AND sn.Active='Y'
                        AND cad.Active='Y' $Extra_Where  AND fg.Administration <> 'None'
                        AND fg.Test_name='tsi'
                        GROUP BY Sex" , $params);
            }

            foreach($results as $row){
                $Gender = $row['Sex'];
                $Count = $row['val'];
                if(is_null($Count)){
                    $Count = 0;
                }
                //$total_count += $Count;
                $gender[$Gender] = $Count;
                $hispanic_total[$Gender] += $Count;


            }

            $enroll_data_hispanic[] = array('race_cat' => $race_name[$hispanic_race_count],'female_count' => $gender['Female'],'male_count' => $gender['Male'],'unknown_count' => $gender['Unknown'],'total_count' => array_sum($gender));
            $hispanic_race_count++;

        }
        $enroll_data_hispanictotal[] = array('total_name' =>" Racial Categories: Total of Hispanic or Latinos",'total_female'=>$hispanic_total['Female'],'total_male'=>$hispanic_total['Male'],'total_unknown'=> $hispanic_total['Unknown'],'total_total'=> array_sum($hispanic_total));

        $withdraw = $DB->pselectOne("SELECT COUNT( DISTINCT cad.CandID) as val FROM candidate cad
                JOIN session sn on cad.CandID= sn.CandID
                LEFT JOIN flag fg on sn.ID = fg.SessionID
                LEFT JOIN tsi ti on fg.CommentID = ti.CommentID
                LEFT JOIN participant_status p ON cad.CandID = p.CandID
                WHERE fg.CommentID NOT LIKE 'DDE%' AND sn.CenterID <> '1'
                AND sn.Active='Y' AND cad.Active='Y' $Extra_Where
                AND fg.Administration <> 'None' AND (sn.Screening IN ('Failure','Withdrawal') OR sn.Visit IN ('Withdrawal','Failure') ) " , $params);


        $enroll_results = array('enroll_data'=> $enroll_data,'enroll_data_total'=> $enroll_data_total,'enroll_data_race'=> $enroll_data_race,'enroll_data_racetotal'=>$enroll_data_racetotal,'enroll_data_hispanic'=>$enroll_data_hispanic,'enroll_data_hispanictotal'=> $enroll_data_hispanictotal , 'withdraw' => $withdraw);

        return $enroll_results;

    }

    /**
     * Adds additional Javascript utility classes for this module.
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
                $baseURL . "/statistics_ibis/js/form_stats_enrollment.js",
            )
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
            array($baseURL . "/statistics/css/statistics.css")
        );
    }

} // End class
?>
