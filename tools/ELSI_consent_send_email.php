<?php
error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';
require_once "Database.class.inc";
require_once "Utility.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');
$yes_list=array();

$DB        =& Database::singleton();

// consider the 'Yes' update status from the history table. Date given might vary in some cases.
$yes_elsi_consents=$DB->pselect("SELECT c.PSCID,cn.Label,ccr.Status,ccr.Dategiven, MAX(cch.Entrydate)as EntryDate from candidate c 
                           join candidate_consent_rel ccr ON(c.CandID=ccr.CandidateID)
                           join consent cn ON (cn.ConsentID=ccr.ConsentID)
                           join candidate_consent_history cch ON(ccr.DateGiven=cch.DateGiven)
                           where ccr.Status='Yes'and cn.Name='elsi_consent'and cch.Status='Yes' and c.CenterID!=1
                           and  DATE(Entrydate)=SUBDATE(CURDATE(),1)
                           group by c.PSCID,cn.Label,ccr.Status,ccr.Dategiven order by EntryDate",array());
$num=0;
foreach ($yes_elsi_consents as $yes_elsi) {
    $num++;
    $push_val = "<tr><td>".$num.".</td><td>".$yes_elsi['PSCID']."</td><td>".$yes_elsi['Label'].
        "</td><td>".$yes_elsi['Status']."</td><td>".$yes_elsi['Dategiven']."</td><td>".$yes_elsi['EntryDate']."</td></tr>";
    array_push($yes_list,$push_val);

}

if(!empty($yes_list))
{
    $today_date=date("Y-m-d");
    $msg_data['yes_consent_list']    = $yes_list;
    $msg_data['today_date']    = $today_date;
    $receiver_email="kmacduffie@gmail.com";
    sendHtmlEmail($receiver_email, 'ELSI_yes_consent_notification.tpl', $msg_data,$headers);
}
function sendHtmlEmail(
    $to,
    $template,
    $tpl_data = array(),
    $reply_to = '',
    $from = '',
    $cc = '',
    $bcc = '',
    $type="text/html"
) {
$config   =& NDB_Config::singleton();
$defaults = $config->getSetting('mail');

// set defaults
if (empty($from)) {
    $from = $defaults['From'];
}
if (empty($reply_to)) {
    $reply_to = $defaults['Reply-to'];
}
// build header
$headers  = "MIME-Version: 1.0\n";
$headers .= "Content-type: $type; charset = UTF-8\n";
$headers .= "Reply-to: $reply_to\n";
$headers .= "From: $from\n";
$headers .= "Return-Path: $from\n";
$headers .= "Content-transfer-encoding: 8bit\n";
$headers .= "Date: " . date('r', time()) . "\n";
$headers .= "Message-ID: <"
    . md5(uniqid(time()))
    . "@"
    . $config->getSetting('host')
    . "\n";
$headers .= "X-Sender: $from\n";
$headers .= "X-Mailer: PHP\n";
$headers .= "X-Priority: 3\n";
$headers .= "X-MSMail-Priority: Normal\n";
$headers .= "X-MimeOLE: " . $defaults['X-MimeOLE'] . "\n";

// optional headers
if (!empty($cc)) {
    $headers .= "Cc: $cc\n";
}
if (!empty($bcc)) {
    $headers .= "Bcc: $bcc\n";
}

// populate the template
$smarty = new Smarty_neurodb;
$smarty->assign($tpl_data);
$message = $smarty->fetch('email/' . $template);

// get the subject
preg_match('/^Subject: (.*)/', $message, $match);

// get rid of the subject from the message body
$message = preg_replace('/^Subject: .*/', '', $message);

// send the email
mail(
    $to,
    $match[1],
    preg_replace("/(?<!\r)\n/s", "\n", $message),
    $headers
);
}
