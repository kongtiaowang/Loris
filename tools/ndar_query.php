<?php
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';
require_once "Database.class.inc";
require_once "Utility.class.inc";
require_once "NDAR_Release_2018.class.inc";

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db        =& Database::singleton();
if (empty($argv[1]) || $argv[1] == 'help') {
    fwrite(STDERR, "Usage: \n\n");
    fwrite(STDERR, "ndar_query.php help - displays this msg\n");
    fwrite(STDERR, "ndar_query.php ibis1 - ndar query run for ibis1\n");
    fwrite(STDERR, "ndar_query.php ibis2 - ndar query run for ibis2\n");
    return;
}

//$run_ibis1 = false;
//$run_ibis2 = true;

if ($argv[1]=="ibis1")
{
  //$IBIS = array('vineland_subject');
  $IBIS = array ('ados_module1', 'ados_module2', 'ados_module3', 'ados2_module1','ados2_module2','ados2_module3','adi_r_proband','aosi','csbs','edi','fyi','ibq_r','m_chat_proband','macarthur_words_gestures','mullen','prefrontal_task','rbs_r','scq_proband','scq_subject','seq','vineland_proband','vineland_subject','charge');
  foreach($IBIS as $instrument) {
      $run = new NDAR_Release_2018 ($instrument, 1);
      $run->run();
  }
}

if ($argv[1]=="ibis2")
{    //remove charge, head, and ados modules and add other two new
    //run ndar_subject script to get data/files for ndar_subject. Removing from here as it may leads to confusion
    //$IBIS2 = array('scq_proband');
     $IBIS2 = array('adi_r_proband','aosi','csbs','ibq_r','macarthur_words_gestures', 'm_chat_proband', 'scq_proband','mullen','rbs_r','vineland_proband','vineland_subject','edi2','height_weight','phys_neuro_exam', 'charge');
  foreach($IBIS2 as $instrument) {
      $run = new NDAR_Release_2018 ($instrument, 2);
      $run->run();

  }
}

?>

