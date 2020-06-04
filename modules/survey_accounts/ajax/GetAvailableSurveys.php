<?php
/**
 * This is used by the Loris survey module to retrieve the email
 * template for the current instrument. It is used in the survey_accounts
 * page via AJAX to update the email template with the current page
 *
 * PHP Version 5
 *
 * @category Survey
 * @package  Loris
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
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

$result = $DB->pselect(
    "SELECT Test_name, Full_name from test_names where IsDirectEntry=1 
and Test_name not in (SELECT f.Test_name FROM flag f
             JOIN session s on s.ID = f.SessionID
             WHERE s.CandID=:v_CandID  
             AND UPPER(s.Visit_label)=UPPER(:v_VL) 
             AND s.Active='Y'and f.CommentID not like '%DDE%') ORDER BY Full_name",
    array(
     'v_CandID' => $_REQUEST['dccid'],
     'v_VL'     => $_REQUEST['VL'],
    )
);
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
