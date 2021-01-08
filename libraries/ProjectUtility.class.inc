<?php
require_once 'PEAR.php';

/**
 * A set of (static) utility functions
 *
 * @access public
 * @package main
 */
class ProjectUtility extends PEAR
{
    function getScoredInstruments() {
        $All = Utility::getAllInstruments();
        $Scored = array();
        $Nothing = array();
        foreach($All as $Instrument => $Full_Name) {
            if(ProjectUtility::getScoreColsForInstrument($Instrument) != $Nothing) {
                $Scored[] = $Instrument;
            }
        }
        return $Scored;
    }
    function getScoreColsForInstrument($inst) {
         require_once "NDB_BVL_Instrument.class.inc";
         $i = NDB_BVL_Instrument::factory($inst, '', '', true);
         $score = null;
         if(isset($i->scoreLabels)) {
             $score = $i->scoreLabels;
         } elseif(isset($i->scoreCols)) {
             $score = $i->scoreCols;
         } elseif(isset($i->scores)) {
             $score = $i->scores;
         }
         if(isset($score[0])) {
             return $score;
         } else {
             if($score != null) {
                 return array_keys($score);
             }
         }
         return array();
    }

    function GetSupplementalGrantStatus($sessionID) {
        $timePoint =& TimePoint::singleton($sessionID);

        $tpd = $timePoint->getData();
        if($tpd['Visit_label'] == 'v06' || $tpd['Visit_label'] == 'V06') {
            return 'Parent Grant';
        }

        $DB =& Database::singleton();
        $query = "SELECT fyi.risk_score "
               . "FROM fyi "
               . "JOIN flag ON (flag.CommentID=fyi.CommentID AND fyi.CommentID NOT LIKE 'DDE%') "
               . "WHERE flag.sessionID=:sessionID";
        $fyi_risk_score = $DB->pselectOne($query, array('sessionID' => $sessionID));
        if (is_null($fyi_risk_score)) {
            return 'N/A';
        }
        if ($fyi_risk_score < 10) {
            return 'Supplemental Grant';
        }

        if ($tpd['Visit_label'] == 'v12' || $tpd['Visit_label'] == 'V12') {
            return 'Parent Grant';
        }

        if ($tpd['Visit_label'] == 'v24' || $tpd['Visit_label'] == 'V24') {
            $query = "SELECT a.summary_diagnosis "
                   . "FROM adi_r_subject a "
                   . "JOIN flag f ON (f.CommentID = a.CommentID AND a.CommentID NOT LIKE 'DDE%') "
                   . "WHERE f.sessionID =:sessionID";
            $adi_r_diagnosis = $DB->pselectOne($query, array('sessionID' => $sessionID));
            if ($adi_r_diagnosis == 'ASD+') {
                return 'Parent Grant';
            }
            if ($adi_r_diagnosis == 'ASD-') {
                return 'Supplemental Grant';
            }

            return 'N/A';
        }

        return '';
    }

    function FlattenID($Arr) {
        return $Arr['ID'];
    }
    /* Set the session_status for the Grant Status field for anything that
     * Depends on this SessionID. Note that multiple sessions of the same
     * candidate may be affected by this session, so we just get all
     * sessions for the candidate, and reset them all.
     */

    function SetSupplementalGrantStatus($SessionID) {
        $DB =& Database::singleton();
        $IDs = $DB->pselect("SELECT ID FROM session WHERE Active='Y' AND
                             CandID=(SELECT CandID FROM session WHERE ID=:SessionID)", 
                             array(":SessionID"=>$SessionID));
        $IDs_string = join(',', array_map(array('ProjectUtility', 'FlattenID'),$IDs));
        $DB->run("delete from session_status WHERE ID IN ($IDs_string) AND Name='Grant Status'");
        foreach($IDs as $ID ) {
            $DB->insert("session_status", array(
                'SessionID' => $ID['ID'],
                'Name' => "Grant Status", 
                'Value' => ProjectUtility::GetSupplementalGrantStatus($ID['ID'])));
        }
        //$DB->run("delete from session_status WHERE SessionID IN ($IDs_string) AND Name='Grant Status'");
    }
    /**
* Checks to see if the given table exists
*
* @param unknown_type $options
* @param unknown_type $table
* @param unknown_type $name
* @return unknown
*/
    function ColumnExists($test_name,$column){

        $config =& NDB_Config::singleton();
        $database = $config->getSetting('database');
        $query = "select distinct table_name from information_schema.columns where table_name =:test and COLUMN_NAME =:col and TABLE_SCHEMA =:db";

        //sprint $query . "\n";
        $DB =& Database::singleton();

        $effected = $DB->pselectOne($query, array('test' => $test_name, 'col' => $column, 'db' => $database));
        if ($effected){
            return true;
        }
        return false;
    }

    /**
     * Returns the Visit Label for a given commentID
     * @throws PEAR_Error
     * @return string  visitlabel
     * @access public
     * @static
     */
    function getVisitLabelUsingTestName($test_name)
    {

        $db =& Database::singleton();
        $query = "select distinct s.visit_label from session s
        join flag f on (s.ID = f.SessionID)
        join candidate c on (c.Candid = s.Candid)
        join psc on (s.CenterID = psc.CenterID)
        where s.Active = 'Y' and c.Active= 'Y' and f.Test_name =:test AND psc.CenterID!= '1'";

        //$query = "select distinct Visit_label from test_battery where Test_name = '$test_name'";
        $visitlabels = $db->pselect($query, array('test' => $test_name));

        return $visitlabels;
    }
    /**
     * looks up the test_name for the current full name
     *
     * @return string        test_name of the instrument
     * @access public
     */

    function getTestNameUsingFullName($fullname)
    {
        $db =& Database::singleton();
        //print_r($instument);
        $instrument = $db->pselect("SELECT Test_name from test_names where Full_name =:fname",array('fname'=>$fullname));

        if(is_array($instrument) && count($instrument)) {
            //$full_name = $names[0]
            list(,$test_name) = each($instrument[0]);
        }
        return $test_name;
    }

    /**
     * Returns all the sourcefrom instruments from parameter_type (which exist in the data_integrity flag table) using the test_names
     * full_name
     *
     * @return unknown
     */
    function getSourcefrom(){
        $DB =& Database::singleton();
        $sourcefrom = $DB->pselect("select distinct t.Full_name from parameter_type pt, data_integrity_flag di,test_names t
        where pt.sourcefrom is not null and pt.Name = di.Name and t.test_name = pt.sourcefrom 
        order by t.Full_name", array());

        foreach ($sourcefrom as $table){
            if (!is_null($table)){
                $result[$table['Full_name']] = $table['Full_name'];
            }
        }
        //print_r($result);
        return $result;
    }

    /**
     * Returns all the sourcefrom instruments from parameter_type
     *
     * @return unknown
     */
    function getSourcefields($instrument=null,$commentID=null,$name=null){

        $DB =& Database::singleton();
        //get sourcefield using instrument
        if (!is_null($instrument)){
            $sourcefields = $DB->pselect("select SourceField, Name from parameter_type where queryable = '1' and sourcefrom =:instrum order by Name", array('instrum' => $instrument));
        }

        //get sourcefield using commentid
        elseif (!is_null($commentID)){
            $instrument = $DB->pselectOne("select Test_name from flag where CommentID =:cID", array('cID' => $commentID));
            $sourcefields = $DB->pselect("select SourceField, Name from parameter_type where queryable = '1' and sourcefrom =:instrum order by Name", array('instrum' => $instrument));
        }
        //get all source fields
        elseif (!is_null($name)){
            $sourcefields = $DB->pselectRow("select * from parameter_type where Name =:n", array('n' => $name));
        }

        else {
            //$DB->select("select SourceField, Name from parameter_type where queryable = '1' order by Name",$sourcefields);
        }
        /*
        foreach ($sourcefields as $sourcefield){
        $result[$sourcefield['Name']] = $sourcefield['Name'];
        }
        */
        return $sourcefields;

    }
}
?>
