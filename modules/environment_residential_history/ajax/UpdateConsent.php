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
//$candidate = Candidate::singleton($commentID);
$sessionID= $DB->pselectOne("SELECT s.ID from session s join flag f on (f.SessionID=s.ID)
where f.CommentID=:cmid",array('cmid' => $commentID));
$timepoint =& TimePoint::singleton($sessionID);
$candidate =& Candidate::singleton($timepoint->getCandID());
$candid = $candidate->getData('CandID');
$pscid = $DB->pselectOne("SELECT c.PSCID from candidate c where c.CandID=:candid",array('candid' => $candid));
$consent_vals_history = array();
$consent_vals_history['EntryDate'] = date("Y-m-d H:i:s",time());
$consent_vals_history['PSCID'] = $pscid;
//Update for air pollution consent
if (isset($_POST['consent'])) {
    $air_consent_more_vals = $DB->pselectRow("SELECT ConsentID,Label from consent where Name='air_consent'",array());
    $air_consent_vals = array();
    $air_consent = $_POST['consent'];
    $air_consent_vals['CandidateID'] =$candid;
    $air_consent_vals['ConsentID'] = $air_consent_more_vals['ConsentID'];
    $air_consent_vals['Status'] = $air_consent;
    $air_consent_vals['DateGiven'] = date("Y-m-d", time());
    $consent_vals_history['ConsentLabel'] = $air_consent_more_vals['Label'];
    $consent_vals_history['ConsentName'] = "air_consent";


    $already_some_air_consent = $DB->pselectOne(
        "SELECT count(*) FROM candidate_consent_rel WHERE CandidateID=:candid and ConsentID=:consentid",
        array('candid' => $candid, 'consentid' => $air_consent_vals['ConsentID'])
    );


    if($already_some_air_consent == 0) {
        $DB->insert("candidate_consent_rel", $air_consent_vals);
    }
    else {
        $WhereCriteria = array('CandidateID' => $candid,'ConsentID' =>$air_consent_vals['ConsentID']);
        $DB->update("candidate_consent_rel", $air_consent_vals, $WhereCriteria);
    }
    unset($air_consent_vals['CandidateID']);
    unset($air_consent_vals['ConsentID']);
    $history_array=array_merge($consent_vals_history,$air_consent_vals);
    $DB->insert("candidate_consent_history", $history_array);
}
//Updates for mail tooth kit consent
if (isset($_POST['mail_consent'])) {
    $mail_consent = $_POST['mail_consent'];
    $participant_vals['mail_toothkit_consent'] = $mail_consent;
    $participant_vals['mail_toothkit_consent_date'] = date("Y-m-d", time());
    //send email notification if mail consent is yes
    if($mail_consent=='yes') {

        $cand_info_details = $DB->pselect(
            "SELECT ps.Name as center_name,ca.PSCID as PSCID from psc ps  
             JOIN  candidate ca ON (ca.RegistrationCenterID=ps.CenterID)
             WHERE ca.CandID=:candid",
            array('candid' => $candid)
        );
        foreach ($cand_info_details as $cand_info) {
            switch ($cand_info['center_name']) {

                case "STL":
                    $Toothkit_Consent_Notification_Email = "flakel@wustl.edu, klohrc@wustl.edu, c.pritchard@wustl.edu";
                    break;
                case "SEA":
                    $Toothkit_Consent_Notification_Email = "lcheers@uw.edu, ibisstudy@uw.edu";
                    break;
                case "UNC":
                    $Toothkit_Consent_Notification_Email = "cchappel@med.unc.edu";
                    break;
                case "PHI":
                    $Toothkit_Consent_Notification_Email = "FAGGENA1@email.chop.edu";
                    break;
                default:
                    $Toothkit_Consent_Notification_Email = "sruthy.mcin@gmail.com";
            }
            $msg_data['candid']    = $candid;
            $msg_data['PSCID']     = $cand_info['PSCID'];

            //This email notification will be better repalced with LORIS notification later.
            Email::send($Toothkit_Consent_Notification_Email, 'toothkit_consent.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
        }
    }
    //Update the mail consent values to database
    $mail_consent_more_vals = $DB->pselectRow("SELECT ConsentID,Label from consent where Name='mail_toothkit_consent'",array());
    $mail_consent_vals = array();
    $mail_consent = $_POST['mail_consent'];
    $mail_consent_vals['CandidateID'] =$candid;
    $mail_consent_vals['ConsentID'] = $mail_consent_more_vals['ConsentID'];
    $mail_consent_vals['Status'] = $mail_consent;
    $mail_consent_vals['DateGiven'] = date("Y-m-d", time());
    $consent_vals_history['ConsentLabel'] = $mail_consent_more_vals['Label'];
    $consent_vals_history['ConsentName'] = "mail_toothkit_consent";


    $already_some_mail_consent = $DB->pselectOne(
        "SELECT count(*) FROM candidate_consent_rel WHERE CandidateID=:candid and ConsentID=:consentid",
        array('candid' => $candid, 'consentid' => $mail_consent_vals['ConsentID'])
    );


    if($already_some_mail_consent == 0) {
        $DB->insert("candidate_consent_rel", $mail_consent_vals);
    }
    else {
        $WhereCriteria = array('CandidateID' => $candid,'ConsentID' =>$mail_consent_vals['ConsentID']);
        $DB->update("candidate_consent_rel", $mail_consent_vals, $WhereCriteria);
    }
    unset($mail_consent_vals['CandidateID']);
    unset($mail_consent_vals['ConsentID']);
    $history_array=array_merge($consent_vals_history,$mail_consent_vals);
    $DB->insert("candidate_consent_history", $history_array);
}


header("HTTP/1.1 200 OK");
echo(json_encode(array(true)));
exit;
