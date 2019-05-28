-- Ordering Instruments for the firdt time for IBIS
-- Refreshing the page returns different ordered list every time
INSERT INTO `test_subgroups` (`ID`, `Subgroup_name`) VALUES ('13', 'Parent Forms');
INSERT INTO `test_subgroups` (`ID`, `Subgroup_name`) VALUES ('14', 'Teacher Forms');
INSERT INTO `test_subgroups` (`ID`, `Subgroup_name`) VALUES ('15', 'Direct Administration (with Subject/Parent)');
INSERT INTO `test_subgroups` (`ID`, `Subgroup_name`) VALUES ('16', 'Miscellaneous (Data no more collected)');

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='Parent Forms')
WHERE tn.test_name IN ('ADULT_SELF_REPORT_MOM', 'ADULT_SELF_REPORT_DAD',
'ABCL_DAD_ON_MOM','ABCL_MOM_ON_DAD', 'ABC2','BRIEF2_Parent' 'CBCL_6_To_18',
'UCD_Charge_GI_History','CCC2','conners_parent','SA_Intervention_History',
'MASC2_Parent','QRS','rbs_r','SEQ3','Shipley2_Data', 'Shipley2_Data_Labels',
'SRS2_SchoolAge_Parent','SRS2_InformantReport_Mom_On_Dad','SRS2_InformantReport_Dad_On_Mom',
'SRS2_SelfReport_Dad','SRS2_SelfReport_Mom','SSIS_Parent'
);

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='Teacher Forms')
WHERE tn.test_name IN ('BRIEF2_Teacher',
'conners_teacher','SSIS_Teacher','SRS2_SchoolAge','Teachers_Report_Form_6_To_18'
);

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='Direct Administration (with Subject/Parent)')
WHERE tn.test_name IN ('adi_r_subject',
'ados2_module1','ados2_module2','ados2_module3', 'BOT2_Short', 'DAS_SA','DSMIV_SA','DSMV_checklist','MASC2_Self_Report',
'NIHToolBox_Assessment_Data','NIHToolBox_Assessment_Scores','NIHToolBox_Registration_Data','TANNER_Boys','TANNER_Girls',
'WIAT_III_SA'
);

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='Miscellaneous (Data no more collected)')
WHERE tn.test_name IN ('BOT2');

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='Medical')
WHERE tn.test_name IN ('IEP_Extraction_Form','med_records_SA'
);

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='MRI')
WHERE tn.test_name IN ('dtiprep')

ALTER TABLE `test_battery`
CHANGE COLUMN `instr_order` `instr_order` INT(10) NULL DEFAULT NULL ;

-- adding all survey instruments to testbattery table to get an order number
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('rbs_r','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('CBCL_1_to_5_yrs','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('sibling_socialcontact','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('peer_socialcontact','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('pspq_1','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('pspq_2','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('m_chat_rf','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('air_pollution','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SEQ3','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('CCC2','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('conners_parent','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('conners_teacher','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('UCD_Charge_GI_History','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('MASC2_Parent','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('MASC2_Self_Report','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('CSHQ','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('QRS','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('BRIEF2_Parent','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('BRIEF2_Teacher','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('Seizure_Questionnaire','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('ABC2','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('Teachers_Report_Form_6_To_18','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('scq_proband_survey','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('CBCL_6_To_18','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_SchoolAge','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SSIS_Parent','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SSIS_Teacher','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('ABCL_DAD_ON_MOM','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('ABCL_MOM_ON_DAD','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('ADULT_SELF_REPORT_DAD','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('ADULT_SELF_REPORT_MOM','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_InformantReport_Mom_On_Dad','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_InformantReport_Dad_On_Mom','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_SelfReport_Mom','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_SelfReport_Dad','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_SchoolAge_Parent','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_SchoolAge_Parent_proband','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('EARLI_interview_PART_4','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('pspq_father','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('pspq_mother','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('eye_tracking','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_InformantReport','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_SelfReport','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_1','0','0','N','Visit');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage ) VALUES('SRS2_2','0','0','N','Visit');


UPDATE test_battery SET instr_order='1' where test_name='Aberrant_Behavior_Checklist';
UPDATE test_battery SET instr_order='2' where test_name='ABC2';
UPDATE test_battery SET instr_order='3' where test_name='ACEFamilyMedicalHistory';
UPDATE test_battery SET instr_order='4' where test_name='ACESubjectMedicalHistory';
UPDATE test_battery SET instr_order='5' where test_name='ACESubjectPhysicalExam';
UPDATE test_battery SET instr_order='6' where test_name='adi_r_proband';
UPDATE test_battery SET instr_order='7' where test_name='adi_r_subject';
UPDATE test_battery SET instr_order='8' where test_name='ados_module1';
UPDATE test_battery SET instr_order='9' where test_name='ados_module2';
UPDATE test_battery SET instr_order='10' where test_name='ados_module3';
UPDATE test_battery SET instr_order='11' where test_name='ados2_module1';
UPDATE test_battery SET instr_order='12' where test_name='ados2_module2';
UPDATE test_battery SET instr_order='13' where test_name='ados2_module3';
UPDATE test_battery SET instr_order='14' where test_name='ABCL';
UPDATE test_battery SET instr_order='15' where test_name='ABCL_DAD_ON_MOM';
UPDATE test_battery SET instr_order='16' where test_name='ABCL_MOM_ON_DAD';
UPDATE test_battery SET instr_order='17' where test_name='ADULT_SELF_REPORT';
UPDATE test_battery SET instr_order='18' where test_name='ADULT_SELF_REPORT_DAD';
UPDATE test_battery SET instr_order='19' where test_name='ADULT_SELF_REPORT_MOM';
UPDATE test_battery SET instr_order='20' where test_name='aims';
UPDATE test_battery SET instr_order='21' where test_name='air_pollution';
UPDATE test_battery SET instr_order='22' where test_name='aosi';
UPDATE test_battery SET instr_order='23' where test_name='BRIEF';
UPDATE test_battery SET instr_order='24' where test_name='BOT2';
UPDATE test_battery SET instr_order='25' where test_name='BOT2_Short';
UPDATE test_battery SET instr_order='26' where test_name='BRIEF2_Parent';
UPDATE test_battery SET instr_order='27' where test_name='BRIEF2_Teacher';
UPDATE test_battery SET instr_order='28' where test_name='BSRC';
UPDATE test_battery SET instr_order='29' where test_name='CBCL_1_to_5_yrs';
UPDATE test_battery SET instr_order='30' where test_name='CBCL_6_To_18';
UPDATE test_battery SET instr_order='31' where test_name='UCD_Charge_GI_History';
UPDATE test_battery SET instr_order='32' where test_name='CCC2';
UPDATE test_battery SET instr_order='33' where test_name='CSHQ';
UPDATE test_battery SET instr_order='34' where test_name='conners_parent';
UPDATE test_battery SET instr_order='35' where test_name='conners_teacher';
UPDATE test_battery SET instr_order='36' where test_name='ciss';
UPDATE test_battery SET instr_order='37' where test_name='csbs';
UPDATE test_battery SET instr_order='38' where test_name='csbs_spontaneity';
UPDATE test_battery SET instr_order='39' where test_name='das_earlyyears';
UPDATE test_battery SET instr_order='40' where test_name='das_schoolage';
UPDATE test_battery SET instr_order='41' where test_name='DAS_SA';
UPDATE test_battery SET instr_order='42' where test_name='JointAttentionAssessment';
UPDATE test_battery SET instr_order='43' where test_name='DNA_parameter_form';
UPDATE test_battery SET instr_order='44' where test_name='dna_tracking';
UPDATE test_battery SET instr_order='45' where test_name='DSMIV_checklist';
UPDATE test_battery SET instr_order='46' where test_name='DSMIV_SA';
UPDATE test_battery SET instr_order='47' where test_name='DSMV_checklist';
UPDATE test_battery SET instr_order='48' where test_name='dtiprep';
UPDATE test_battery SET instr_order='49' where test_name='EARLI_interview_S3_inserts';
UPDATE test_battery SET instr_order='50' where test_name='EARLI_interview_S7_inserts';
UPDATE test_battery SET instr_order='51' where test_name='EARLI_interview_PART_3';
UPDATE test_battery SET instr_order='52' where test_name='EARLI_interview_PART_4';
UPDATE test_battery SET instr_order='53' where test_name='EARLI_interview_revised';
UPDATE test_battery SET instr_order='54' where test_name='EARLI_interview_PART_1';
UPDATE test_battery SET instr_order='55' where test_name='EARLI_interview_PART_2';
UPDATE test_battery SET instr_order='56' where test_name='ECBQ';
UPDATE test_battery SET instr_order='57' where test_name='edi';
UPDATE test_battery SET instr_order='58' where test_name='edi2';
UPDATE test_battery SET instr_order='59' where test_name='SA_Intervention_History';
UPDATE test_battery SET instr_order='60' where test_name='eye_tracking';
UPDATE test_battery SET instr_order='61' where test_name='FamilyEnvironmentScales';
UPDATE test_battery SET instr_order='62' where test_name='figs_year3';
UPDATE test_battery SET instr_order='63' where test_name='fyi';
UPDATE test_battery SET instr_order='64' where test_name='head_measurements_proband';
UPDATE test_battery SET instr_order='65' where test_name='head_measurements_subject';
UPDATE test_battery SET instr_order='66' where test_name='HandPreference';
UPDATE test_battery SET instr_order='67' where test_name='ibq_r';
UPDATE test_battery SET instr_order='68' where test_name='IEP_Extraction_Form';
UPDATE test_battery SET instr_order='69' where test_name='i3';
UPDATE test_battery SET instr_order='70' where test_name='intervention_history';
UPDATE test_battery SET instr_order='71' where test_name='LENA_DailyActivityLog';
UPDATE test_battery SET instr_order='72' where test_name='LENA_DataTrackingForm';
UPDATE test_battery SET instr_order='73' where test_name='m_chat_proband';
UPDATE test_battery SET instr_order='74' where test_name='m_chat_rf';
UPDATE test_battery SET instr_order='75' where test_name='m_chat_subject';
UPDATE test_battery SET instr_order='76' where test_name='macarthur_words_gestures';
UPDATE test_battery SET instr_order='77' where test_name='CDI_Words_Sentences';
UPDATE test_battery SET instr_order='78' where test_name='MASC2_Parent';
UPDATE test_battery SET instr_order='79' where test_name='MASC2_Self_Report';
UPDATE test_battery SET instr_order='80' where test_name='med_psych_hist';
UPDATE test_battery SET instr_order='81' where test_name='med_records_24';
UPDATE test_battery SET instr_order='82' where test_name='med_records_recruit';
UPDATE test_battery SET instr_order='83' where test_name='med_records_proband';
UPDATE test_battery SET instr_order='84' where test_name='med_records_SA';
UPDATE test_battery SET instr_order='85' where test_name='mock_scanner_training_form';
UPDATE test_battery SET instr_order='86' where test_name='mri_parameter_form';
UPDATE test_battery SET instr_order='87' where test_name='mri_parameter_form_sa';
UPDATE test_battery SET instr_order='88' where test_name='mullen';
UPDATE test_battery SET instr_order='89' where test_name='neuro_screen';
UPDATE test_battery SET instr_order='90' where test_name='NIHToolBox_Assessment_Data';
UPDATE test_battery SET instr_order='91' where test_name='NIHToolBox_Assessment_Scores';
UPDATE test_battery SET instr_order='92' where test_name='NIHToolBox_Registration_Data';
UPDATE test_battery SET instr_order='93' where test_name='parent_concerns_interview';
UPDATE test_battery SET instr_order='94' where test_name='parental_stress_scale';
UPDATE test_battery SET instr_order='95' where test_name='peer_socialcontact';
UPDATE test_battery SET instr_order='96' where test_name='prefrontal_task';
UPDATE test_battery SET instr_order='97' where test_name='pspq_2';
UPDATE test_battery SET instr_order='98' where test_name='pspq_1';
UPDATE test_battery SET instr_order='99' where test_name='pspq_father';
UPDATE test_battery SET instr_order='100' where test_name='pspq_mother';
UPDATE test_battery SET instr_order='101' where test_name='QRS';
UPDATE test_battery SET instr_order='102' where test_name='radiology_review';
UPDATE test_battery SET instr_order='103' where test_name='rbs_r';
UPDATE test_battery SET instr_order='104' where test_name='RSMS';
UPDATE test_battery SET instr_order='105' where test_name='scq_proband';
UPDATE test_battery SET instr_order='106' where test_name='scq_subject';
UPDATE test_battery SET instr_order='107' where test_name='scq_proband_survey';
UPDATE test_battery SET instr_order='108' where test_name='Seizure_Questionnaire';
UPDATE test_battery SET instr_order='109' where test_name='SEQ3';
UPDATE test_battery SET instr_order='110' where test_name='seq';
UPDATE test_battery SET instr_order='111' where test_name='Shipley2_Data_Labels';
UPDATE test_battery SET instr_order='112' where test_name='Shipley2_Data';
UPDATE test_battery SET instr_order='113' where test_name='sibling_socialcontact';
UPDATE test_battery SET instr_order='114' where test_name='SRS';
UPDATE test_battery SET instr_order='115' where test_name='SRS2_SchoolAge_Parent';
UPDATE test_battery SET instr_order='116' where test_name='SRS2_SchoolAge';
UPDATE test_battery SET instr_order='117' where test_name='SRS2_SchoolAge_Parent_proband';
UPDATE test_battery SET instr_order='118' where test_name='SRS2_SelfReport_Dad';
UPDATE test_battery SET instr_order='119' where test_name='SRS2_InformantReport_Dad_On_Mom';
UPDATE test_battery SET instr_order='120' where test_name='SRS2_InformantReport';
UPDATE test_battery SET instr_order='121' where test_name='SRS2_SelfReport_Mom';
UPDATE test_battery SET instr_order='122' where test_name='SRS2_InformantReport_Mom_On_Dad';
UPDATE test_battery SET instr_order='123' where test_name='SRS2_SelfReport';
UPDATE test_battery SET instr_order='124' where test_name='SRS2_1';
UPDATE test_battery SET instr_order='125' where test_name='SRS2_2';
UPDATE test_battery SET instr_order='126' where test_name='SSIS_Parent';
UPDATE test_battery SET instr_order='127' where test_name='SSIS_Teacher';
UPDATE test_battery SET instr_order='128' where test_name='TANNER_Boys';
UPDATE test_battery SET instr_order='129' where test_name='TANNER_Girls';
UPDATE test_battery SET instr_order='130' where test_name='Teachers_Report_Form_6_To_18';
UPDATE test_battery SET instr_order='131' where test_name='tsi';
UPDATE test_battery SET instr_order='132' where test_name='tsi_followup';
UPDATE test_battery SET instr_order='133' where test_name='TSI_SA';
UPDATE test_battery SET instr_order='134' where test_name='vineland_proband';
UPDATE test_battery SET instr_order='135' where test_name='vineland_subject';
UPDATE test_battery SET instr_order='136' where test_name='wiatIII';
UPDATE test_battery SET instr_order='137' where test_name='WIAT_III_SA';
UPDATE test_battery SET instr_order='138' where test_name='wiatIII_part_1';
UPDATE test_battery SET instr_order='139' where test_name='wiatIII_part_2';







