<?php
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';
require_once "Database.class.inc";
require_once "Utility.class.inc";
require_once "NDAR_Release_2017.class.inc";

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db        =& Database::singleton();

$run_ibis1 = true;
$run_ibis2 = false;

if ($run_ibis1) 
{
  // $IBIS = array('ados_module1','ados2_module1','ados2_module2','ados2_module3');
  $IBIS = array ('ados_module1','ados2_module1','ados2_module2','ados2_module3','adi_r_proband','aosi','csbs','edi','fyi','ibq_r','m_chat_proband','macarthur_words_gestures','mullen','prefrontal_task','rbs_r','scq_proband','scq_subject','seq','vineland_proband','vineland_subject','charge');
  foreach($IBIS as $instrument) {
      $run = new NDAR_Release_2017 ($instrument, 1);
      $run->run();
  }
}

if ($run_ibis2) 
{
  //$IBIS2 = array('edi2');
  $IBIS2 = array('adi_r_proband','aosi','csbs','head_measurements_subject','ibq_r','macarthur_words_gestures', 'm_chat_proband','ndar_subject', 'scq_proband','mullen','rbs_r','vineland_proband','charge','edi2');
  foreach($IBIS2 as $instrument) {
      $run = new NDAR_Release_2017 ($instrument, 2);
      $run->run();

  }
}

?>

