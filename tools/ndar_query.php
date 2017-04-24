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

$run_ibis1 = false;
$run_ibis2 = true;

if ($run_ibis1)
{
  // $IBIS = array('ados_module1', 'ados_module2', 'ados_module3', 'ados2_module1','ados2_module2','ados2_module3');
  $IBIS = array ('ados_module1', 'ados_module2', 'ados_module3', 'ados2_module1','ados2_module2','ados2_module3','adi_r_proband','aosi','csbs','edi','fyi','ibq_r','m_chat_proband','macarthur_words_gestures','mullen','prefrontal_task','rbs_r','scq_proband','scq_subject','seq','vineland_proband','vineland_subject','charge');
  foreach($IBIS as $instrument) {
      $run = new NDAR_Release_2017 ($instrument, 1);
      $run->run();
  }
}

if ($run_ibis2)
{    //remove charge, head, and ados modules and add other two new
  $IBIS2 = array('adi_r_proband','aosi','csbs','ibq_r','macarthur_words_gestures', 'm_chat_proband','ndar_subject', 'scq_proband','mullen','rbs_r','vineland_proband','vineland_subject','edi2','height_weight','phys_neuro_exam');
  foreach($IBIS2 as $instrument) {
      $run = new NDAR_Release_2017 ($instrument, 2);
      $run->run();

  }
}

?>

