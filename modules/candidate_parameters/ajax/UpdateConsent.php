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

if (isset($_POST['consent']))
{
    $consent=$_POST['consent'];
    $commentID=$_POST['comment'];
    $candidate = Candidate::singleton($commentID);
    $candid = $candidate->getData('CandID');
    $participant_vals = array();
    $participant_vals['data_entry_date'] = date("Y-m-d H:i:s",time());
    $participant_vals['air_consent'] = "no";
    $participant_vals['air_consent_date'] = date("Y-m-d",time());
    $participant_vals['CandID']      = $candid;
    $already_consent_no = $DB->pselectOne(
        "SELECT count(*) FROM consent_info_history WHERE air_consent='no' and CandID=:candid",
        array('candid' => $candid)
    );
    $already_consent_yes = $DB->pselectOne(
        "SELECT count(*) FROM consent_info_history WHERE air_consent='yes' and CandID=:candid",
        array('candid' => $candid)
    );
    if($already_consent_no==0) {
        $DB->insert("consent_info_history", $participant_vals);
    }
    else{
        $WhereCriteria = array('candid' => $candid);
        $DB->update("consent_info_history", $participant_vals, $WhereCriteria);
    }

    echo 1;
    exit(1);

}
?>;