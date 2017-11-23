<?php
/**
 *  Email Notifications to sites for not administered instruments after defined time of MRI PF administration/date of visit has crossed
 *
 *  PHP Version 7
 *
 *  @category Tools
 *  @package  Tools
 *  @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 *  @version  GIT: <git_id>
 *  @link     https://www.github.com/aces/IBIS/
 **/
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');
$db = Database::singleton();

$dcc_list = array();
$stl_list = array();
$phi_list = array();
$sea_list = array();
$unc_list = array();
// select query for mri parameter form
$mrf_array = $db->pselect(
            "SELECT c.CandID,s.ID,s.CenterID,mrf.Date_taken
             FROM candidate c 
            JOIN session s ON (c.CandID=s.CandID)
            JOIN psc ON (s.CenterID = psc.CenterID)
            JOIN flag f ON (f.SessionID=s.ID)
            JOIN mri_parameter_form mrf ON (f.CommentID=mrf.CommentID)  
            AND s.Active='Y'
            AND s.Current_stage <> 'Recycling Bin'
            AND s.Visit_label='VSA'
            AND f.CommentID NOT LIKE '%DDE%'",
            array()
);
//loop through specific/required instruments which share same sessions of mri parameter form
foreach ($mrf_array as $key=>$mrf_vals) {
    // This array can be extended for more instruments as per the request
    $instr_array = array('CBCL', 'adi_r_proband', 'adi_r_subject', 'SRS2_InformantReport','SRS2_1', 'SRS2_2');
    foreach ($instr_array as $key => $instr) {
        $check_array = $db->pselect(
            "SELECT c.CandID as cid,c.PSCID,s.ID,s.CenterID,s.Date_visit,ins.Date_taken,f.Administration as adm,f.test_name,s.Visit_label,f.Data_entry,psc.Name as center
             FROM candidate c 
            JOIN session s ON (c.CandID=s.CandID)
            JOIN psc ON (s.CenterID = psc.CenterID)
            JOIN flag f ON (f.SessionID=s.ID)
            JOIN {$instr} ins ON(f.CommentID=ins.CommentID)
            WHERE s.ID = :sid  
            AND s.Active='Y'
            AND s.Current_stage <> 'Recycling Bin'
            AND s.Visit_label='VSA'
            AND f.CommentID NOT LIKE '%DDE%'",
            array('sid' => $mrf_vals['ID'])
        );
        if ($check_array != NULL) {
            foreach ($check_array as $check_vals) {
                $i = 0;
                // administration not started or admin not none/complete instruments
                $condition2 = ($check_vals['adm'] == NULL || ($check_vals['adm'] != 'None' && $check_vals['Data_entry'] != 'Complete'));
                switch ($instr) {
                    case "CBCL":
                        $check_date_mrf = strtotime("{$mrf_vals['Date_taken']} + 4 weeks + 1 days");
                        $check_date_visit=strtotime("{$check_vals['Date_visit']} + 4 weeks + 1 days");
                        break;
                    case "adi_r_proband":
                    case "adi_r_subject":
                        $check_date_mrf = strtotime("{$mrf_vals['Date_taken']} + 8 weeks + 1 days");
                        $check_date_visit=strtotime("{$check_vals['Date_visit']} + 8 weeks + 1 days");

                        break;
                    default:
                        $check_date_mrf = strtotime("{$mrf_vals['Date_taken']} + 3 months + 1 days");
                        $check_date_visit=strtotime("{$check_vals['Date_visit']} + 3 months + 1 days");

                }
                $check_date_mrf_format = date('Y-m-d', $check_date_mrf);
                $check_date_visit_format= date('Y-m-d', $check_date_visit);
                $today = time();
                $today_date_format = date('Y-m-d', $today);
                //defined time passed after mrf administration has done or defined time after date of visit has passed
                if($mrf_vals['Date_taken']!=NULL || $mrf_vals['Date_taken']!=""){
                    $final_condition =(strtotime($check_date_mrf_format) < strtotime($today_date_format) && $condition2)
                        || (strtotime($check_date_visit_format) < strtotime($today_date_format) && $condition2);
                }
                //mrf admin not done; but check if defined time after date of visit has passed
                else{
                    $final_condition=(strtotime($check_date_visit_format) < strtotime($today_date_format) && $condition2);
                }
                if($final_condition){

                    $push_val = $check_vals['PSCID'] . "_" . $check_vals['cid'] . "_" . $check_vals['Visit_label'] . "_" . $check_vals['test_name'];
                    if ($check_vals['center'] == "DCC") {
                        array_push($dcc_list,$push_val);
                    }
                    if ($check_vals['center'] == "SEA") {
                        array_push($sea_list,$push_val);
                    }
                    if ($check_vals['center'] == "UNC") {
                        array_push($unc_list,$push_val);
                    }
                    if ($check_vals['center'] == "PHI") {
                        array_push($phi_list,$push_val);
                    }
                    if ($check_vals['center'] == "STL") {
                        array_push($stl_list,$push_val);
                    }

                }

            }

        }
    }
}
//print_r($dcc_list);
//Email needs to be send for the appropriate site.
if(!empty($dcc_list))
{
    $msg_data['instr_list']    = $dcc_list;
    $receiver_email="sruthy.mcin@gmail.com";
    Email::send($receiver_email, 'instruments_admin_notification.tpl', $msg_data);
}
if(!empty($phi_list))
{
    $msg_data['instr_list']    = $phi_list;
    $receiver_email="FAGGENA1@email.chop.edu";
    Email::send($receiver_email, 'instruments_admin_notification.tpl', $msg_data);
}
if(!empty($sea_list))
{
    $msg_data['instr_list']    = $sea_list;
    $receiver_email="tstjohn@u.washington.edu, cnm7@uw.edu";
    Email::send($receiver_email, 'instruments_admin_notification.tpl', $msg_data);
}
if(!empty($stl_list))
{
    $msg_data['instr_list']    = $stl_list;
    $receiver_email="flakel@wustl.edu, klohrc@wustl.edu, c.pritchard@wustl.edu";
    Email::send($receiver_email, 'instruments_admin_notification.tpl', $msg_data);
}
if(!empty($unc_list))
{
    $msg_data['instr_list']    = $unc_list;
    $receiver_email="cchappel@med.unc.edu";
    Email::send($receiver_email, 'instruments_admin_notification.tpl', $msg_data);
}




