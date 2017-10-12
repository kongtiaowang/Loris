<?php
/** This is used to update the consents related with an instrument
 */

set_include_path(get_include_path().":../project/libraries:../php/libraries:");
ini_set('default_charset', 'utf-8');

require_once __DIR__ . "../../../../../vendor/autoload.php";

$config =& NDB_Config::singleton();
$client = new NDB_Client();
$client->initialize();

require_once "Utility.class.inc";
require_once "Email.class.inc";
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
    $participant_vals['mail_toothkit_consent_date'] = date("Y-m-d", time());
    if($mail_consent=='yes') {

        $cand_info_details = $DB->pselect(
            "SELECT ps.Name as center_name,ca.PSCID as PSCID from psc ps  
             JOIN  candidate ca ON (ca.CenterID=ps.CenterID)
             WHERE ca.CandID=:candid",
            array('candid' => $candid)
        );
        foreach ($cand_info_details as $cand_info) {
            switch ($cand_info['center_name']) {

                case "STL":
                    $Toothkit_Consent_Notification_Email = "flakel@wustl.edu, klohrc@wustl.edu, c.pritchard@wustl.edu";
                    break;
                case "SEA":
                    $Toothkit_Consent_Notification_Email = "tstjohn@u.washington.edu";
                    break;
                case "UNC":
                    $Toothkit_Consent_Notification_Email = "cchappel@med.unc.edu";
                    break;
                case "PHI":
                    $Toothkit_Consent_Notification_Email = "FAGGENA1@email.chop.edu";
                    break;
                default:
                    $Toothkit_Consent_Notification_Email = "leigh.ibis@gmail.com";
            }
            $msg_data['candid']    = $candid;
            $msg_data['PSCID']     = $cand_info['PSCID'];

            //This email notification will be better repalced with LORIS notification later.
            Email::send($Toothkit_Consent_Notification_Email, 'toothkit_consent.tpl', $msg_data);
        }
    }
}
    $already_some_consent = $DB->pselectOne(
        "SELECT count(*) FROM participant_status WHERE CandID=:candid",
        array('candid' => $candid)
    );


    if($already_some_consent == 0) {
        $DB->insert("participant_status", $participant_vals);
    }
    else {
        $WhereCriteria = array('candid' => $candid);
        $DB->update("participant_status", $participant_vals, $WhereCriteria);
    }
$DB->insert("consent_info_history", $participant_vals);

header("HTTP/1.1 200 OK");
echo(json_encode(array(true)));
exit;
