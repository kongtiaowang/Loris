<?php
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db        = Database::singleton();

$mapping = array('preg_complic'=>'pregnancy_complication_subject','preg_dxdrug'=>'','birth_weight_lbs'=>'birth_weight_lbs',
                 'ldnb_lgthin'=>'ldnb_lgthin', 'full_term'=>'full_term','ldnb_hosptotalmom'=>'ldnb_hosptotalmom',
                 'rev_headfebseiz'=>'rev_headfebseiz','rev_headseizure'=>'q15_seizures_convulsions',
                 'fhxcp'=>'fhxcp','hist_trauma'=>'hist_trauma','rev_eartest'=>'rev_eartest','rev_eartestresult'=>'rev_eartestresult',
                 'rev_neckspinalab'=>'rev_neckspinalab','rev_skinbirthmark'=>'rev_skinbirthmark',
                 'rev_cardiomalfunc'=>'rev_cardiomalfunc','rev_immunomedallergy'=>'med_his_q_6_allergies',
                 'gen_dis'=>'gen_dis','othmem_bipolar','othmem_depression'=>'othmem_depression','othmem_anxiety'=>'othmem_anxiety',
                 'othmem_schizophrenia'=>'othmem_schizophrenia','othmem_adhd'=>'othmem_adhd');
$session = $db->pselect("SELECT s.ID from session s
                         JOIN flag f ON ( f.sessionID = s.ID AND f.Test_name=:tname)
                              AND f.CommentID NOT LIKE 'DDE_%'",
                         array('tname'=>'ACESubjectMedicalHistory'));
foreach ($session as $sessionID ) {

$result = $db->pselect("SELECT t.pregnancy_complication_subject, t.premature_birth, t.weeks_gestation, t.med_his_q_6_allergies,
                        mr.first_measurement_length_units_stat, mr.first_measurement_length_cm,mr.first_measurement_length_inches,
                        mr.not_completed, mr.test_results, m.q6_a_antibio_infections_when_taken, m.q6_b_acne_meds_when_taken,
                        m.q6_c_birth_control_meds_when_taken, m.q6_d_antihypertensives_when_taken, m.q6_e_heart_cardiac_meds_when_taken,
                        m.q6_f_add_meds_when_taken, m.q6_g_antiepilep_anti_seizure_when_taken, m.q6_h_diabetes_meds_when_taken,
                        m.q6_i_thyroid_meds_when_taken, m.q6_j_antidepressants_when_taken, m.q6_k_mood_stabs_anti_psychos_when_taken,
                        m.q6_l_tranquilizers_nerve_pills_when_taken, m.q6_m_pain_killers_when_taken, m.q6_n_sedatives_sleeping_pills_when_taken,
                        m.q6_o_anti_inflam_immune_when_taken,m.q6_p_treatment_for_HIV_when_taken, m.q6_q_thalidomide_when_taken,
                        m.q6_r_misoprostol_when_taken, m.q6_s_other_when_taken,m.q11_birth_weight_lbs, m.q11_birth_weight_ozs,
                        m.q14_child_hospitalised_days, m.q14_child_hospitalised_hours, m.q15_c_fever_seizures, m.q15_seizures_convulsions,
                        m.m_cerebral_palsy,m.m_cerebral_palsy_who, m.q16_has_child_ever, m.q17_birth_defects, m.e_rett_syndrome, m.e_rett_syndrome_who,
                        m.c_tuberous_sclerosis, m.c_tuberous_sclerosis_who, m.b_fragile_x, m.b_fragile_x_who, m.d_neurofibromatosis,
                        m.d_neurofibromatosis_who, m.t_manic_depres_bi, m.t_manic_depres_bi_who, m.s_depression,m.s_depression_who,
                        m.r_panic_anxiety_dis, m.r_panic_anxiety_dis_who, m.u_schizophrenia, m.u_schizophrenia_who, m.q_add,m.q_add_who,
                        n.q23_adenoma_sebaceum,n.q25_shagreen_patches_describe,n.q24_ash_leaf_macules, n.q27_cafe_au_lait_spots
                        FROM session s LEFT JOIN flag tflag ON (s.ID = tflag.SessionID AND tflag.Test_name='tsi' AND tflag.CommentID NOT LIKE 'DDE%')
                        LEFT JOIN flag mflag ON (s.ID = mflag.SessionID AND mflag.Test_name='med_psych_hist' AND mflag.CommentID NOT LIKE 'DDE%')
                        LEFT JOIN flag nflag ON (s.ID = nflag.SessionID AND nflag.Test_name='neuro_screen' AND nflag.CommentID NOT LIKE 'DDE%')
                        LEFT JOIN flag mrflag ON (s.ID = mrflag.SessionID AND mrflag.Test_name='med_records_24' AND mrflag.CommentID NOT LIKE 'DDE%')
                        LEFT JOIN tsi t ON (tflag.CommentID = t.CommentID)
                        LEFT JOIN med_psych_hist m ON (mflag.CommentID = m.CommentID)
                        LEFT JOIN neuro_screen n ON (nflag.CommentID = n.CommentID)
                        LEFT JOIN med_records_24 mr ON (mrflag.CommentID = mr.CommentID) WHERE s.ID =:sid",
                        array('sid'=>$sessionID['ID']));

foreach($result as $row) {
    $final_row = array();
    $final_result['preg_complic'] = $row['pregnancy_complication_subject'];
    $preg_drugs = array($row['q6_a_antibio_infections_when_taken'], $row['q6_b_acne_meds_when_taken'],
                        $row['q6_c_birth_control_meds_when_taken'], $row['q6_d_antihypertensives_when_taken'], $row['q6_e_heart_cardiac_meds_when_taken'],
                        $row['q6_f_add_meds_when_taken'], $row['q6_g_antiepilep_anti_seizure_when_taken'], $row['q6_h_diabetes_meds_when_taken'],
                        $row['q6_i_thyroid_meds_when_taken'], $row['q6_j_antidepressants_when_taken'], $row['q6_k_mood_stabs_anti_psychos_when_taken'],
                        $row['q6_l_tranquilizers_nerve_pills_when_taken'], $row['q6_m_pain_killers_when_taken'], $row['q6_n_sedatives_sleeping_pills_when_taken'],
                        $row['q6_o_anti_inflam_immune_when_taken'],$row['q6_p_treatment_for_HIV_when_taken'], $row['q6_q_thalidomide_when_taken'],
                        $row['q6_r_misoprostol_when_taken'], $row['q6_s_other_when_taken']);

      if (!array_filter($preg_drugs)) {
          $final_result['preg_dxdrug'] = null;
      } else if (in_array("2_both", $preg_drugs) || in_array("1_after", $preg_drugs)
          || in_array("0_before", $preg_drugs)) {
          $final_result['preg_dxdrug'] = "yes";
      } else {
          $final_result['preg_dxdrug'] = "no";
      }

      if ($row['q11_birth_weight_lbs'] == '' && $row['q11_birth_weight_ozs'] == '') {
          $final_result['birth_weight_lbs'] = null;
      } else {
          $final_result['birth_weight_lbs'] = (float)$row['q11_birth_weight_lbs'] + round((float)$row['q11_birth_weight_ozs']*0.0625, 3);
      }

      if ($row['premature_birth'] == 'yes') {
          $final_result['full_term'] = 'no';
          $final_result['info_gest'] = $row['weeks_gestation'];
      } else if ($row['premature_birth'] == 'no') {
          $final_result['full_term'] = 'yes';
          $final_result['info_gest'] = $row['weeks_gestation'];
      }
      else{
          $final_result['full_term'] = $row['premature_birth'];
          $final_result['info_gest'] = $row['weeks_gestation'];
      }

     if ($row['q14_child_hospitalised_days'] == '' && $row['q14_child_hospitalised_hours'] == '') {
         $final_result['ldnb_hosptotalmom'] = null;
     } else {
         $final_result['ldnb_hosptotalmom'] = (float)$row['q14_child_hospitalised_days'] + round((float)$row['q14_child_hospitalised_hours']/24, 3);
     }
     $final_result['rev_headfebseiz'] = null;
     if ($row['q15_c_fever_seizures'] == '1_yes' && $row['q15_seizures_convulsions'] == '1_yes' ) {
         $final_result['rev_headfebseiz'] = 'yes';
     } else if ($row['q15_seizures_convulsions'] == '0_no' ) {
         $final_result['rev_headfebseiz'] = 'no';
     }
     $final_result['rev_headseizure'] = null;
     if ($row['q15_c_fever_seizures'] == '0_no' && $row['q15_seizures_convulsions'] == '1_yes' ) {
         $final_result['rev_headseizure'] = 'yes';
     } else if ($row['q15_seizures_convulsions'] == '0_no' ) {
         $final_result['rev_headseizure'] = 'no';
     }
     $final_result['fhxcp'] = null;
     if ($row['m_cerebral_palsy'] == '1_yes' && (strpos($row['m_cerebral_palsy_who'], 'child') !== false)) {
         $final_result['fhxcp'] = 'yes';
     } else if ($row['m_cerebral_palsy'] == '0_no' && (strpos($row['m_cerebral_palsy_who'], 'child') !== false)) {
         $final_result['fhxcp'] = 'yes';
     }
     $final_result['hist_trauma'] = null;
     if (strpos($row['q16_has_child_ever'] , 'c_lost_consciousness_head_injury') !== false) {
         $final_result['hist_trauma'] = 'yes';
     }

    if ($row['not_completed'] == 'complete') {
        $final_result['rev_eartest'] = 'yes';
    } else if ($row['not_completed'] == 'not_complete' ) {
        $final_result['rev_eartest'] = 'no';
    }
    if (empty($row['test_results'])) {
        $final_result['rev_eartestresult'] = null;
    } else if ($row['test_results']  == 'normal_hearing') {
        $final_result['rev_eartestresult'] = 'normal';
    } else if ($row['test_results']  == 'temporary_hearing_difficulty' || $row['test_results']  == 'permanent_abnormal_hearing') {
        $final_result['rev_eartestresult'] = 'abnormal';
    } else if ($row['test_results']  == 'not_answered' || $row['test_results']  == 'equivocal_evaluation_results') {
        $final_result['rev_eartestresult'] = 'not_answered';
    }
    $final_result['rev_neckspinalab'] = null;
    if ($row['q17_birth_defects'] == 'c_open_spine') {
        $final_result['rev_neckspinalab'] = 'yes';
    }
   $birth_marks = array($row['q27_cafe_au_lait_spots'], $row['q24_ash_leaf_macules'], $row['q23_adenoma_sebaceum']);
   $final_result['rev_skinbirthmark'] = null;
   if (in_array('1_uncertain', $birth_marks) || in_array('2_present', $birth_marks) || in_array('3_six_or_more_spots', $birth_marks)
       || in_array('1_one_three_spots', $birth_marks) || in_array('2_four_or_five_spots', $birth_marks)) {
       $final_result['rev_skinbirthmark'] = 'yes';
   } else if ($row['q27_cafe_au_lait_spots'] == '0_absent' && $row['q24_ash_leaf_macules'] == '0_absent' && $row['q23_adenoma_sebaceum'] == '0_absent') {
       $final_result['rev_skinbirthmark'] = 'no';
   }
  $final_result['rev_cardiomalfunc'] = null;
  if ( strpos($row['q17_birth_defects'] , 'd_heart_defect') !== false) {
      $final_result['rev_cardiomalfunc'] = 'yes';
  }
  $final_result['rev_immunomedallergy'] = $row['med_his_q_6_allergies'];
  $final_result['gen_dis'] = NULL;
  $mental_health = array('e_rett_syndrome'=>'1_rett_syndrome', 'c_tuberous_sclerosis'=>'3_tuberous_sclerosis_complex',
                         'b_fragile_x'=>'4_fragile_x_syndrome', 'd_neurofibromatosis'=>'5_neurofibromatosis_i');
  foreach ($mental_health as $key=>$val) {
      if ($row[$key] == '1_yes' && (strpos($row[$key.'_who'], 'child') !== false)) {
          if (empty($final_result['gen_dis'])) {
              $final_result['gen_dis'] = $val;
          } else {
              $final_result['gen_dis'] .= '{@}'.$val;
          }
      }
  }
  $other_health = array('t_manic_depres_bi'=>'othmem_bipolar', 's_depression'=>'othmem_depression', 'r_panic_anxiety_dis'=>'othmem_anxiety',
                        'u_schizophrenia'=>'othmem_schizophrenia', 'q_add'=>'othmem_adhd');
  foreach ($other_health as $key=>$val) {
      if ($row[$key] == '1_yes' && (strpos($row[$key.'_who'], 'child') !== false)) {
              $final_result[$val] = 'yes';
      }
  }

//print_r($final_result);
  //exit;
}
$WhereCriteria['CommentID'] = $db->pselectOne("SELECT i.CommentID FROM ACESubjectMedicalHistory i
                                               JOIN flag f ON f.CommentID = i.CommentID AND f.CommentID NOT LIKE 'DDE%'
                                               JOIN session s ON s.ID = f.SessionID
                                               WHERE s.ID =:sid",
                                               array('sid'=>$sessionID['ID']));

  if (!empty($final_result)) {
    $result = $db->update('ACESubjectMedicalHistory', $final_result, $WhereCriteria);
    print serialize($WhereCriteria) . " ";
    print serialize($final_result) . "\n";


  }
}
?>