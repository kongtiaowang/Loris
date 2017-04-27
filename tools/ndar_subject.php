<?php
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';
require_once "NDB_Client.class.inc";
require_once "Utility.class.inc";
require_once "Database.class.inc";
//require_once "../../tools/generic_includes.php";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');


$CommentID = $argv[1];
$db        =& Database::singleton();
$project = array(1=>'IBIS1',2=>'IBIS2');
$validating = TRUE; // // Do not forget to set to false if submiting to NDAR!
if ($validating) {
    $test_fields = "c.PSCID, s.Visit_label, s.SubprojectID, ";
} else { $test_fields = ""; }

foreach($project as $key=>$val) { 
$id = $key;
$name = $val;
$query = "SELECT ". $test_fields ."  c.IBISID as src_subject_id, s.CenterID as Site, CASE s.SubprojectID WHEN 1 THEN 'NK' WHEN 2 THEN 'NK' WHEN 3 THEN 'NK' WHEN 9 THEN 'NK' WHEN 10 THEN 'NK' END as phenotype, c.ProbandGUID as subjectkey_sibling1, CASE c.ProbandGender WHEN 'Male' THEN 'M' WHEN 'Female' THEN 'F' END AS sibling_type1, c.CandidateGUID as subjectkey, CASE c.Gender WHEN 'Male' THEN 'M' WHEN 'Female' THEN 'F' END AS Gender, i.Date_taken as interview_date,ROUND(DATEDIFF(i.Date_taken, c.DoB) / (365/12)) AS interview_age, i.Date_taken,ROUND(DATEDIFF(i.Date_taken, c.ProbandDoB) / (365/12)) AS Proband_Age_in_Months, i.Candidate_race as race, i.child_ethnicity as ethnic_group from candidate c join session s on s.CandID = c.CandID join flag f on f.SessionID = s.ID join tsi i on i.CommentID=f.CommentID join participant_status ps on ps.CandID = c.CandID JOIN participant_status_options po on po.ID=ps.participant_status WHERE COALESCE(s.Current_stage, '') <> 'Recycling Bin' AND COALESCE(s.Visit, '') NOT IN ('Failure', 'Withdrawal') AND COALESCE(s.Screening, '') NOT IN ('Failure', 'Withdrawal') AND f.Administration='All' AND f.Data_entry='Complete' AND EXISTS (SELECT 'x' FROM flag df WHERE df.CommentID=CONCAT('DDE_', i.CommentID) AND df.Data_entry='Complete') AND NOT EXISTS (SELECT 'x' FROM conflicts_unresolved cu WHERE cu.CommentId1=i.CommentID OR cu.CommentId2=i.CommentID) AND s.CenterID IN (2, 3, 4, 5) AND ( ps.study_consent = 'yes' AND ps.study_consent_withdrawal IS NULL) AND (ps.ndar_consent = 'yes' AND ps.ndar_consent_withdrawal IS NULL) and c.ProjectID = $id AND COALESCE(c.CandidateGUID, '') <> '' AND po.Description NOT IN ('Excluded', 'Ineligible','Refused/Not Enrolled')";

$record = array();
$record = $db->pselect($query, array());
 $filename = "ndar_subject_".$name.".csv";
  $fd = fopen($filename, 'w+');
  if ($fd === FALSE) {
    exit(-1);
  }
  $header1 = explode('-','ndar_subject-01');
 fputcsv($fd, $header1);
 $test_headers= array('PSCID','Visit_label','SubprojectId');
 $headers = array('src_subject_id','subjectkey','Gender','Site','phenotype','interview_age','interview_date','family_study','race','ethnic_group',
                  'twins_study','sibling_study','sample_taken','phenotype_description','subjectkey_sibling1','src_sibling1_id','sibling_type1');
 if($validating)
 {
     $more_headers = array_merge($test_headers,$headers);
     fputcsv($fd, $more_headers);
 }
 else{
     fputcsv($fd, $headers);
 }

 $data = array('twins_populate'=>'No','sibling_study'=>'Yes','family_study'=>'No','sample_taken'=>'No');
 foreach($record as $row) {
 $row = array_merge($row,$data);
 foreach($row as $key=>$val){
	 if(strpos($key, 'interview_date') !== FALSE || $key == 'DoB' || strpos($key, 'interview_date') !== FALSE) {
		 //print "VAL: $val";
		 $Date = explode('-', $val); //print_r($Date);
		 $row[$key] = $Date[1] . '/' . '01' . '/' . $Date[0];
	 }
 } 
 if($row['interview_age'] < 0){
    $row['interview_age'] =0;
 }
 $type='';
 $type_pr ='';
 if($row['sibling_type1']== 'M') {
   $type = "Full Brother FB";
 } else if($row['sibling_type1'] == 'F'){
   $type = "Full Sister FS";
  } else {
    $type = " ";
   }
 if($row['Gender']== 'M') {
   $type_pr = "Full Brother FB";
 } else if($row['Gender'] == 'F'){
   $type_pr = "Full Sister FS";
  }
 $race = $row['race'];
 if(strpos($race,'more_than_one_race') !== FALSE){
 $race_final = "More than one race";
 } else { 
 if(strpos($race,'white') !== FALSE){
 $race_final = "White";
 } else  if(strpos($race,'asian') !== FALSE){
 $race_final = "Asian";
 } else if(strpos($race,'black_african_american') !== FALSE){
 $race_final = "Black or African American";
 } else if(strpos($race,'white') !== FALSE){
 $race_final = "White";
 }
}
 $candidate_parameters= array($row['PSCID'], $row['Visit_label'],$row['SubprojectID']);
 $candidate = array($row['src_subject_id'], $row['subjectkey'], $row['Gender'], $row['Site'], $row['phenotype'], $row['interview_age'], $row['interview_date'],
                    'No',$race_final,$row['ethnic_group'],'No','Yes','No', $row['phenotype']." Sibling",$row['subjectkey_sibling1'],$row['src_subject_id']."pr", $type);
  if($validating)
  {
    $more_vals=array_merge($candidate_parameters,$candidate);
    fputcsv($fd, $more_vals);
  }
  else {
      fputcsv($fd, $candidate);
  }
 if(!empty($row['ProbandGUID'])){
     $proband   = array($row['src_subject_id']."pr", $row['subjectkey_sibling1'], $row['sibling_type1'], $row['Site'], "Proband", $row['Proband_Age_in_Months'], $row['interview_date'],
                    'No',"Unknown or not reported","Unknown or not reported",'No','Yes','No', "Proband of Sibling",$row['subjectkey'], $row['src_subject_id'], $type_pr);
     fputcsv($fd, $proband);
  }	
 }
}
?>
