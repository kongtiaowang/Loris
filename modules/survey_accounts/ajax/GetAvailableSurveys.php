<?php
/**
 * This is used by the Loris survey module to retrieve the instruments
 * available for a candidate on selecting a visit label when
 * creating a survey
 *
 * PHP Version 5
 *
 * @category Survey
 * @package  Loris
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

$user =& User::singleton();
if (!$user->hasPermission('user_accounts')) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}

set_include_path(get_include_path().":../project/libraries:../php/libraries:");
ini_set('default_charset', 'utf-8');

require_once "Database.class.inc";
require_once 'NDB_Config.class.inc';
require_once 'NDB_Client.class.inc';
$config =& NDB_Config::singleton();
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();

$DB = Database::singleton();
$visit_label=$_REQUEST['VL'];
$candid=$_REQUEST['dccid'];
$survey_test_battery_count = $DB->pselectOne("select count(*) from survey_test_battery where Visit_label=:vl",
    array('vl'     => $_REQUEST['VL']));
if($survey_test_battery_count!=0)
{
    $result = $DB->pselect(
        "SELECT tn.Test_name, tn.Full_name from test_names tn
          join survey_test_battery stb ON (stb.Test_name=tn.test_name)
 where stb.Visit_label='{$visit_label}'
and tn.Test_name not in (SELECT f.Test_name FROM flag f
             JOIN session s on s.ID = f.SessionID
             WHERE s.CandID=:v_CandID  
             AND UPPER(s.Visit_label)=UPPER(:v_VL) 
             AND s.Active='Y'and f.CommentID not like '%DDE%') ORDER BY tn.Full_name",
        array(
            'v_CandID' => $_REQUEST['dccid'],
            'v_VL' => $_REQUEST['VL'],
        )
    );
    if(empty($result))
    {
        $result = $DB->pselect(
                "SELECT tn.Test_name, tn.Full_name from test_names tn
          join survey_test_battery stb ON (stb.Test_name=tn.test_name)
 where stb.Visit_label='{$visit_label}' ORDER BY tn.Full_name",array());

    }
}
else {

    $result = $DB->pselect(
        "SELECT Test_name, Full_name from test_names where IsDirectEntry=1 
and Test_name not in (SELECT f.Test_name FROM flag f
             JOIN session s on s.ID = f.SessionID
             WHERE s.CandID=:v_CandID  
             AND UPPER(s.Visit_label)=UPPER(:v_VL) 
             AND s.Active='Y'and f.CommentID not like '%DDE%') ORDER BY Full_name",
        array(
            'v_CandID' => $_REQUEST['dccid'],
            'v_VL' => $_REQUEST['VL'],
        )
    );
    if (empty($result)) {
        $result = $DB->pselect(
            "SELECT Test_name, Full_name from test_names where IsDirectEntry=1 ORDER BY Full_name", array());

    }
}
$visit=$_REQUEST['VL'];
$count=0;
foreach($result as $data)
{
    $count++;

    $option_string.="<option value=".$data['Test_name'].">".$data['Full_name']."</option>";
}
   echo  json_encode(
    array(
    'option_string'=> $option_string)
);

    exit;
?>
