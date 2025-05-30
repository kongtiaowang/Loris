<?php declare(strict_types=1);

/**
 * This is used by the survey accounts module to validate inputs
 * before the email message popup appears
 *
 * PHP Version 7
 *
 * @category Survey
 * @package  Loris
 * @author   David Blader <dblader.mcin@gmail.com>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

$user = \User::singleton();
if (!$user->hasPermission('survey_accounts_view')) {
    header("HTTP/1.1 403 Forbidden");
    exit(0);
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

$db = \NDB_Factory::singleton()->database();


$numCandidates = $db->pselectOne(
    "SELECT COUNT(*) FROM candidate
            WHERE PSCID=:v_PSCID
            AND CandID=:v_CandID AND Active='Y'",
    [
        'v_PSCID'  => $_REQUEST['pscid'],
        'v_CandID' => $_REQUEST['dccid'],
    ]
);
$error_msg     = "PSCID and DCC ID do not match or candidate does not exist.";
if ($numCandidates != 1) {
    echo json_encode(
        ['error_msg' => $error_msg]
    );
    exit(0);
}

$numSessions = $db->pselectOne(
    "SELECT COUNT(*) FROM session s
            JOIN candidate c ON (c.ID=s.CandidateID)
            WHERE c.CandID=:v_CandID
            AND UPPER(Visit_label)=UPPER(:v_VL)
            AND s.Active='Y'",
    [
        'v_CandID' => $_REQUEST['dccid'],
        'v_VL'     => $_REQUEST['VL'],
    ]
);

if ($numSessions != 1) {
    echo json_encode(
        [
            'error_msg' => "Visit ". $_REQUEST['VL'].
                             " does not exist for given candidate",
        ]
    );
    exit(0);
}

if (empty($_REQUEST['TN'])) {
    echo json_encode(
        ['error_msg' => 'Please choose an instrument']
    );
    exit(0);
}

$instrument_list = $db->pselect(
    "SELECT tn.Test_name FROM flag f
             JOIN session s on s.ID = f.SessionID
             JOIN candidate c ON c.ID = s.CandidateID
             JOIN test_names tn ON tn.ID = f.TestID
             WHERE c.CandID=:v_CandID
             AND UPPER(s.Visit_label)=UPPER(:v_VL)
             AND s.Active='Y'",
    [
        'v_CandID' => $_REQUEST['dccid'],
        'v_VL'     => $_REQUEST['VL'],
    ]
);
foreach ($instrument_list as $instrument) {
    if ($_REQUEST['TN'] == $instrument['Test_name']) {
        echo json_encode(
            [
                'error_msg' => "Instrument ". $_REQUEST['TN'].
                " already exists for given candidate for visit ". $_REQUEST['VL'],
            ]
        );
        exit(0);
    }
}

if (!empty($_REQUEST['Email']) ) {
    if (!filter_var($_REQUEST['Email'], FILTER_VALIDATE_EMAIL) ) {
        echo json_encode(
            ['error_msg' => 'The email address is not valid.']
        );
        exit(0);
    }
}

print "";


