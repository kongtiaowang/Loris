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
$sessionID= $DB->pselectOne("SELECT s.ID from session s join flag f on (f.SessionID=s.ID)
where f.CommentID=:cmid",array('cmid' => $commentID));
$timepoint =& TimePoint::singleton($sessionID);
$candidate =& Candidate::singleton($timepoint->getCandID());
$candid = $candidate->getData('CandID');
$pscid = $DB->pselectOne("SELECT c.PSCID from candidate c where c.CandID=:candid",array('candid' => $candid));
$NDAR_consent_vals_history = array();
$NDAR_consent_vals_history['EntryDate'] = date("Y-m-d H:i:s",time());
$NDAR_consent_vals_history['PSCID'] = $pscid;
//Updates for mail tooth kit consent
if (isset($_POST['NDAR_consent_SA'])) {
    $NDAR_SA_consent = $_POST['NDAR_consent_SA'];
    $participant_vals['NDAR_consent_SA'] = $NDAR_SA_consent;
    $participant_vals['NDAR_consent_SA'] = date("Y-m-d", time());
    //send email notification if SA consent is yes
    if($NDAR_SA_consent=='yes') {

        $cand_info_details = $DB->pselect(
            "SELECT ps.Name as center_name,ca.PSCID as PSCID from psc ps  
             JOIN  candidate ca ON (ca.RegistrationCenterID=ps.CenterID)
             WHERE ca.CandID=:candid",
            array('candid' => $candid)
        );
        foreach ($cand_info_details as $cand_info) {
            switch ($cand_info['center_name']) {

                case "STL":
                    $Consent_Notification_Email = "m.ocampo@wustl.edu; erbstreitj@wustl.edu, joannek@wustl.edu";
                    break;
                case "SEA":
                    $Consent_Notification_Email = "ibisstudy@uw.edu, lcheers@uw.edu";
                    break;
                case "UNC":
                    $Consent_Notification_Email = "hannon_sweeney@med.unc.edu, cchappell@med.unc.edu";
                    break;
                case "PHI":
                    $Consent_Notification_Email = "gottliebb@email.chop.edu, serruyar@email.chop.edu, carneyh2@email.chop.edu";
                    break;
                default:
                    $Consent_Notification_Email = "sruthy.mcin@gmail.com";
            }
            $msg_data['candid']    = $candid;
            $msg_data['PSCID']     = $cand_info['PSCID'];

            //This email notification will be better repalced with LORIS notification later.
            Email::send($Consent_Notification_Email, 'ndar_consent_sa.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
        }
    }
    //Update the SA consent values to database
    $NDAR_SA_consent_more_vals = $DB->pselectRow("SELECT ConsentID,Label from consent where Name='NDAR_consent_SA'",array());
    $NDAR_SA_consent_vals = array();
    $NDAR_SA_consent = $_POST['NDAR_consent_SA'];
    $NDAR_SA_consent_vals['CandidateID'] =$candid;
    $NDAR_SA_consent_vals['ConsentID'] = $NDAR_SA_consent_more_vals['ConsentID'];
    $NDAR_SA_consent_vals['Status'] = $NDAR_SA_consent;
    $NDAR_SA_consent_vals['DateGiven'] = date("Y-m-d", time());
    $NDAR_consent_vals_history['ConsentLabel'] = $NDAR_SA_consent_more_vals['Label'];
    $NDAR_consent_vals_history['ConsentName'] = "NDAR_consent_SA";


    $already_some_NDAR_SA_consent = $DB->pselectOne(
        "SELECT count(*) FROM candidate_consent_rel WHERE CandidateID=:candid and ConsentID=:consentid",
        array('candid' => $candid, 'consentid' => $NDAR_SA_consent_vals['ConsentID'])
    );


    if($already_some_NDAR_SA_consent == 0) {
        $DB->insert("candidate_consent_rel", $NDAR_SA_consent_vals);
    }
    else {
        $WhereCriteria = array('CandidateID' => $candid,'ConsentID' =>$NDAR_SA_consent_vals['ConsentID']);
        $DB->update("candidate_consent_rel", $NDAR_SA_consent_vals, $WhereCriteria);
    }
    unset($NDAR_SA_consent_vals['CandidateID']);
    unset($NDAR_SA_consent_vals['ConsentID']);
    $history_array=array_merge($NDAR_consent_vals_history,$NDAR_SA_consent_vals);
    $DB->insert("candidate_consent_history", $history_array);
}


header("HTTP/1.1 200 OK");
echo(json_encode(array(true)));
exit;
