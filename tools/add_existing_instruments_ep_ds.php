<?php

require_once __DIR__ . '/../../vendor/autoload.php';
require_once __DIR__ . '/../../tools/generic_includes.php';
require_once "Utility.class.inc";



$instrument_array_VO6 =array("aims","aosi","neuro_screen","ibq_r","mullen","ACEFamilyMedicalHistory","med_psych_hist","head_measurements_subject","tsi","tsi_followup");

$instrument_array_V12=array("aims","aosi","csbs","JointAttentionAssessment","DSMV_checklist","head_measurements_subject","ibq_r","macarthur_words_gestures",
                              "mullen","neuro_screen","SEQ3","med_psych_hist","tsi","tsi_followup",);

$instrument_array_V24=array("ACESubjectMedicalHistory","adi_r_subject","ados2_module1",
    "ados2_module2","ados2_module3","CBCL_1_to_5_yrs", "csbs","DSMV_checklist","head_measurements_subject","BSRC","macarthur_words_gestures",
    "mullen","neuro_screen","QRS","SEQ3","HandPreference","m_chat_subject","med_psych_hist","tsi","tsi_followup",);


foreach ($instrument_array_VO6 as &$instr_V06) {
    //TSI version is different for Infant DS
if($instr_V06=='tsi'|| $instr_V06=='tsi_followup')
{
    $subproject_id_array=array("18","19");
}
else{
    $subproject_id_array=array("18","19","20");
}
    foreach ($subproject_id_array as &$subprojectid) {
        $already_added = $DB->pselectOne(
            "SELECT count(*) FROM test_battery WHERE Test_name=:tname and Visit_label='V06' and SubprojectID=:sp and Active='Y'",
            array('tname' => $instr_V06, 'sp' => $subprojectid)
        );

            if ($already_added == 0) {

                $batter_vals = array();
                $batter_vals['Test_name'] = $instr_V06;
                $batter_vals['AgeMinDays'] = 0;
                $batter_vals['AgeMaxDays'] = 0;
                $batter_vals['Active'] = 'Y';
                $batter_vals['Stage'] = 'Visit';
                $batter_vals['SubprojectID'] = $subprojectid;
                $batter_vals['Visit_label'] = 'V06';
                $batter_vals['CenterID'] = NULL;

                $DB->insert("test_battery", $batter_vals);
                echo "Added $instr_V06 to $subprojectid at V06";
                echo "\n";
            } else {
                echo "Already added $instr_V06 to $subprojectid (subprojectid) at V06";
                echo "\n";
            }
        }



}
foreach ($instrument_array_V12 as &$instr_V12) {
    //TSI version is different for Infant DS
    if($instr_V12=='tsi'|| $instr_V12=='tsi_followup')
    {
        $subproject_id_array=array("18","19");
    }
    else{
        $subproject_id_array=array("18","19","20");
    }


    foreach ($subproject_id_array as &$subprojectid) {
        $already_added = $DB->pselectOne(
            "SELECT count(*) FROM test_battery WHERE Test_name=:tname and Visit_label='V12' and SubprojectID=:sp and Active='Y'",
            array('tname' => $instr_V12, 'sp' => $subprojectid)
        );

            if ($already_added == 0) {

                $batter_vals = array();
                $batter_vals['Test_name'] = $instr_V12;
                $batter_vals['AgeMinDays'] = 0;
                $batter_vals['AgeMaxDays'] = 0;
                $batter_vals['Active'] = 'Y';
                $batter_vals['Stage'] = 'Visit';
                $batter_vals['SubprojectID'] = $subprojectid;
                $batter_vals['Visit_label'] = 'V12';
                $batter_vals['CenterID'] = NULL;

                $DB->insert("test_battery", $batter_vals);
                echo "Added $instr_V12 to $subprojectid at V12";
                echo "\n";
            } else {
                echo "Already added $instr_V12 to $subprojectid (subprojectid) at V12";
                echo "\n";
            }
        }

}
foreach ($instrument_array_V24 as &$instr_V24) {
    //TSI version is different for Infant DS
    if($instr_V24=='tsi'|| $instr_V24=='tsi_followup')
    {
        $subproject_id_array=array("18","19");
    }
    else{
        $subproject_id_array=array("18","19","20");
    }


    foreach ($subproject_id_array as &$subprojectid) {

        $already_added = $DB->pselectOne(
            "SELECT count(*) FROM test_battery WHERE Test_name=:tname and Visit_label='V24' and SubprojectID=:sp and Active='Y'",
            array('tname' => $instr_V24, 'sp' => $subprojectid)
        );

            if ($already_added == 0) {

                $batter_vals = array();
                $batter_vals['Test_name'] = $instr_V24;
                $batter_vals['AgeMinDays'] = 0;
                $batter_vals['AgeMaxDays'] = 0;
                $batter_vals['Active'] = 'Y';
                $batter_vals['Stage'] = 'Visit';
                $batter_vals['SubprojectID'] = $subprojectid;
                $batter_vals['Visit_label'] = 'V24';
                $batter_vals['CenterID'] = NULL;

                $DB->insert("test_battery", $batter_vals);
                echo "Added $instr_V24 to $subprojectid (subprojectid) at V24";
                echo "\n";
            } else {
                echo "Already added $instr_V24 to $subprojectid at V24";
                echo "\n";
            }
        }
}

?>
