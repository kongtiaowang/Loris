<?php
/** This is used to update the consents related with an instrument
 */

set_include_path(get_include_path().":../project/libraries:../php/libraries:");
ini_set('default_charset', 'utf-8');

require_once "Database.class.inc";
require_once 'NDB_Config.class.inc';
require_once 'NDB_Client.class.inc';

$config =& NDB_Config::singleton();
$client = new NDB_Client();
$client->initialize();

require_once "Utility.class.inc";
$DB =& Database::singleton();

$commentID=$_POST['comment'];
$candidate = Candidate::singleton($commentID);
$candid = $candidate->getData('CandID');
$participant_vals = array();
$participant_vals['data_entry_date'] = date("Y-m-d H:i:s",time());
$participant_vals['CandID'] = $candid;
if (isset($_POST['consent'])) {
    $consent = $_POST['consent'];
    $participant_vals['air_consent'] = $consent;
    $participant_vals['air_consent_date'] = date("Y-m-d", time());
}
if (isset($_POST['mail_consent'])) {
    $mail_consent = $_POST['mail_consent'];
    $participant_vals['mail_toothkit_consent'] = $mail_consent;
}
    $already_some_consent = $DB->pselectOne(
        "SELECT count(*) FROM consent_info_history WHERE CandID=:candid",
        array('candid' => $candid)
    );


    if($already_some_consent == 0) {
        $DB->insert("consent_info_history", $participant_vals);
    }
    else {
        $WhereCriteria = array('candid' => $candid);
        $DB->update("consent_info_history", $participant_vals, $WhereCriteria);
    }

echo(1);
exit;
