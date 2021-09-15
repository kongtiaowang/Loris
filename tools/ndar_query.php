<?php
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';
require_once "Database.class.inc";
require_once "Utility.class.inc";
require_once "NDAR_Release_2019_Rerun.class.inc";

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db        =& Database::singleton();
if (empty($argv[1]) || $argv[1] == 'help') {
    fwrite(STDERR, "Usage: \n\n");
    fwrite(STDERR, "ndar_query.php help - displays this msg\n");
    fwrite(STDERR, "ndar_query.php ibis1 validate - ndar query run for ibis1 with a validate option if needed\n");
    fwrite(STDERR, "ndar_query.php ibis2 validate - ndar query run for ibis2 with a validate option if needed\n");
    return;
}

//$run_ibis1 = false;
//$run_ibis2 = true;
if(!empty($argv[2]) || $argv[2]=="validate")
{
    $validating=TRUE;
}
else{

    $validating=FALSE;
}

if ($argv[1]=="ibis1")
{
    //$IBIS = array('CCC2','ABC2','BOT2_Short','CSHQ','DAS_SA','MASC2_Parent','conners_parent','BRIEF2_Parent','WIAT_III_SA_1','WIAT_III_SA_2');
    //$IBIS = array ('ados_module1', 'ados_module2', 'ados_module3', 'ados2_module1','ados2_module2','ados2_module3','adi_r_proband','aosi','csbs','edi','fyi','ibq_r','m_chat_proband','macarthur_words_gestures','mullen','prefrontal_task','rbs_r','scq_proband','scq_subject','seq','vineland_proband','vineland_subject','charge');
    //IBIS1 SA instrument array
    $IBIS= array('ados2_module1','ados2_module2','ados2_module3','scq_subject','scq_proband_survey','rbs_r',
        'CCC2','ABC2','BOT2_Short','CSHQ','DAS_SA','MASC2_Parent','conners_parent','BRIEF2_Parent','WIAT_III_SA_1','WIAT_III_SA_2');
    // 'CCC2');
    foreach($IBIS as $instrument) {
        $run = new NDAR_Release_2019_Rerun ($instrument, 1, $validating);
        $run->run();
    }
}

if ($argv[1]=="ibis2")
{
    //$IBIS2 = $IBIS = array('CCC2','ABC2','BOT2_Short','CSHQ','DAS_SA','MASC2_Parent','conners_parent','BRIEF2_Parent','WIAT_III_SA_1','WIAT_III_SA_2');
    //$IBIS2 = array('adi_r_proband','aosi','csbs','ibq_r','macarthur_words_gestures', 'm_chat_proband', 'scq_proband','mullen','rbs_r','vineland_proband','vineland_subject','edi2','height_weight','phys_neuro_exam', 'charge',
    //'ados2_module1','ados2_module2','ados2_module3','ECBQ','FamilyEnvironmentScales','BSRC','JointAttentionAssessment','LENA_DataTrackingForm','SRS');

    //IBIS1 SA instrument array

    $IBIS2 = array('adi_r_proband','aosi','csbs','ibq_r','macarthur_words_gestures', 'm_chat_proband', 'scq_proband','mullen','rbs_r','vineland_proband','vineland_subject','edi2','height_weight','phys_neuro_exam', 'charge');
    foreach($IBIS2 as $instrument) {
        $run = new NDAR_Release_2019_Rerun ($instrument, 2, $validating);
        $run->run();

    }
}



?>

