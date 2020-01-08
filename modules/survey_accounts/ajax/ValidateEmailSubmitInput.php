<?php
/**
 * This is used by the survey accounts module to validate inputs
 * before the email message popup appears
 *
 * PHP Version 5
 *
 * @category Survey
 * @package  Loris
 * @author   David Blader <dblader.mcin@gmail.com>
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

$db = Database::singleton();

$numCandidates = $db->pselectOne(
    "SELECT COUNT(*) FROM candidate 
            WHERE PSCID=:v_PSCID 
            AND CandID=:v_CandID AND Active='Y'",
    array(
     'v_PSCID'  => $_REQUEST['pscid'],
     'v_CandID' => $_REQUEST['dccid'],
    )
);
$error_msg     = "PSCID and DCC ID do not match or candidate does not exist.";
if ($numCandidates != 1) {
    echo json_encode(
        array('error_msg' => $error_msg)
    );
    exit;
}

$numSessions = $db->pselectOne(
    "SELECT COUNT(*) FROM session 
            WHERE CandID=:v_CandID 
            AND UPPER(Visit_label)=UPPER(:v_VL) 
            AND Active='Y'",
    array(
     'v_CandID' => $_REQUEST['dccid'],
     'v_VL'     => $_REQUEST['VL'],
    )
);

if ($numSessions != 1) {
    echo json_encode(
        array(
         'error_msg' => "Visit ". $_REQUEST['VL'].
                             " does not exist for given candidate",
        )
    );
    exit;
}
if (empty($_REQUEST['TN'])) {
    echo json_encode(
        array('error_msg' => 'Please choose an instrument')
    );
    exit;
}

$instrument_list = $db->pselect(
    "SELECT f.Test_name FROM flag f
             JOIN session s on s.ID = f.SessionID
             WHERE s.CandID=:v_CandID  
             AND UPPER(s.Visit_label)=UPPER(:v_VL) 
             AND s.Active='Y'and f.CommentID not like '%DDE%'",
    array(
     'v_CandID' => $_REQUEST['dccid'],
     'v_VL'     => $_REQUEST['VL'],
    )
);
$instr_string=$_REQUEST['TN'];
$selected_instr=explode(",", $instr_string);
$existing_instr='';
foreach ($instrument_list as $instrument) {
if(in_array($instrument['Test_name'], $selected_instr)){
    $existing_instr.=$instrument['Test_name'].'<br>';

    }
}
if($existing_instr!='') {
    echo json_encode(
        array(
            'error_msg' => "These instrument(s) already exist for visit ". $values['VL'] .":<br>". $existing_instr
        )
    );
    exit;
}

if (!empty($_REQUEST['Email']) ) {
    if (!filter_var($_REQUEST['Email'], FILTER_VALIDATE_EMAIL) ) {
        echo json_encode(
            array('error_msg' => 'The email address is not valid.')
        );
        exit;
    }
}

print "";

?>
