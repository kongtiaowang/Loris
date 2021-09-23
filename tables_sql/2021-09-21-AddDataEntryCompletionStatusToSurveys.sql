-- ----------------------------------------------------------------------------
--
-- 1. Adds column Data_entry_completion_status to the surveys 
--    that do not already have it (tanner_boys_survey & tanner_girls_survey).
--
-- ----------------------------------------------------------------------------

-- ----------------------------
--      tanner_boys_survey
-- ----------------------------
ALTER TABLE tanner_boys_survey
    ADD COLUMN Testdate timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP AFTER Date_taken;
ALTER TABLE tanner_boys_survey
    ADD COLUMN Data_entry_completion_status enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete' AFTER Testdate;

UPDATE tanner_boys_survey tbs
JOIN flag f USING(CommentID)
SET tbs.Testdate=f.testdate;

-- ----------------------------
--      tanner_girls_survey
-- ----------------------------
ALTER TABLE tanner_girls_survey ADD COLUMN Testdate timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP AFTER Date_taken;
ALTER TABLE tanner_girls_survey ADD COLUMN Data_entry_completion_status enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete' AFTER Testdate;

UPDATE tanner_girls_survey tgs
JOIN flag f USING(CommentID)
SET tgs.Testdate=f.testdate;

-- ----------------------------------------------------------------------------
--
-- 2. Sets the Data_entry_completion_status to 'Complete' for all surveys
--    that have a corresponding record in table participant_accounts with a
--    status set to 'Complete' (i.e the survey has been filled out by the 
--    participant).
--
-- ----------------------------------------------------------------------------

UPDATE ABC2 t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ABC2')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ABC2')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ABCL_DAD_ON_MOM t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ABCL_DAD_ON_MOM')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ABCL_DAD_ON_MOM')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ABCL_MOM_ON_DAD t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ABCL_MOM_ON_DAD')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ABCL_MOM_ON_DAD')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ACEFamilyMedicalHistorySurvey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ACEFamilyMedicalHistorySurvey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ACEFamilyMedicalHistorySurvey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE acesubjectmedical_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='acesubjectmedical_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='acesubjectmedical_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ADULT_SELF_REPORT_DAD t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ADULT_SELF_REPORT_DAD')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ADULT_SELF_REPORT_DAD')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ADULT_SELF_REPORT_MOM t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ADULT_SELF_REPORT_MOM')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ADULT_SELF_REPORT_MOM')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE air_pollution t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='air_pollution')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='air_pollution')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE apsi_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='apsi_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='apsi_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE BISQ_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='BISQ_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='BISQ_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE BRIEF2_Parent t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='BRIEF2_Parent')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='BRIEF2_Parent')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE BRIEF2_Teacher t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='BRIEF2_Teacher')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='BRIEF2_Teacher')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE BRQ_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='BRQ_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='BRQ_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE BSRC_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='BSRC_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='BSRC_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE caars_SelfReport_dad t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='caars_SelfReport_dad')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='caars_SelfReport_dad')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE caars_SelfReport_mom t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='caars_SelfReport_mom')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='caars_SelfReport_mom')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CBCL_1_To_5_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CBCL_1_To_5_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CBCL_1_To_5_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CBCL_1_To_5_survey_sibling t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CBCL_1_To_5_survey_sibling')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CBCL_1_To_5_survey_sibling')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CBCL_6_To_18 t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CBCL_6_To_18')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CBCL_6_To_18')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CBCL_6_To_18_survey_sibling t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CBCL_6_To_18_survey_sibling')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CBCL_6_To_18_survey_sibling')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CBCL_6_To_18_survey_subject t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CBCL_6_To_18_survey_subject')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CBCL_6_To_18_survey_subject')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CCC2 t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CCC2')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CCC2')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CCTQ_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CCTQ_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CCTQ_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE conners_parent t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='conners_parent')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='conners_parent')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE conners_teacher t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='conners_teacher')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='conners_teacher')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE COVID_Child_Self_Report_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='COVID_Child_Self_Report_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='COVID_Child_Self_Report_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE COVID_Parent_Report_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='COVID_Parent_Report_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='COVID_Parent_Report_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE CSHQ t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='CSHQ')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='CSHQ')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE DS_Infant_Intervention_History_Form_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='DS_Infant_Intervention_History_Form_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='DS_Infant_Intervention_History_Form_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ECBQ_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ECBQ_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ECBQ_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE fyi_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='fyi_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='fyi_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE IBIS_SA_SLEEP_Consent_Form t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='IBIS_SA_SLEEP_Consent_Form')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='IBIS_SA_SLEEP_Consent_Form')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE ibq_r_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='ibq_r_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='ibq_r_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE Infant_social_motivation_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='Infant_social_motivation_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='Infant_social_motivation_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE macarthur_words_gestures_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='macarthur_words_gestures_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='macarthur_words_gestures_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE MASC2_Parent t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='MASC2_Parent')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='MASC2_Parent')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE MASC2_Self_Report t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='MASC2_Self_Report')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='MASC2_Self_Report')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE mcdi_words_gestures_sentences_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='mcdi_words_gestures_sentences_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='mcdi_words_gestures_sentences_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE Med_Psych_History_Abbreviated_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='Med_Psych_History_Abbreviated_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='Med_Psych_History_Abbreviated_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE Med_Psych_History_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='Med_Psych_History_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='Med_Psych_History_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE MEQC_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='MEQC_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='MEQC_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE NDAR_Consent_SA_Form t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='NDAR_Consent_SA_Form')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='NDAR_Consent_SA_Form')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE peer_socialcontact t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='peer_socialcontact')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='peer_socialcontact')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE perinatal_data t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='perinatal_data')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='perinatal_data')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE pspq_InformantReport_dad_on_mom t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='pspq_InformantReport_dad_on_mom')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='pspq_InformantReport_dad_on_mom')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE pspq_InformantReport_mom_on_dad t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='pspq_InformantReport_mom_on_dad')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='pspq_InformantReport_mom_on_dad')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE pspq_SelfReport_dad t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='pspq_SelfReport_dad')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='pspq_SelfReport_dad')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE pspq_SelfReport_mom t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='pspq_SelfReport_mom')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='pspq_SelfReport_mom')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE QRS t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='QRS')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='QRS')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE QRS_Fxs_Subject t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='QRS_Fxs_Subject')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='QRS_Fxs_Subject')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE QRS_Proband t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='QRS_Proband')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='QRS_Proband')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE rbs_ecs t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='rbs_ecs')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='rbs_ecs')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE RBS_EC_G_V12_V24_Survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='RBS_EC_G_V12_V24_Survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='RBS_EC_G_V12_V24_Survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE rbs_ec_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='rbs_ec_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='rbs_ec_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE rbs_r t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='rbs_r')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='rbs_r')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE rbs_r_fxs_subject t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='rbs_r_fxs_subject')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='rbs_r_fxs_subject')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE rbs_r_proband t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='rbs_r_proband')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='rbs_r_proband')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE Saliva_Collection_Tracking_Form t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='Saliva_Collection_Tracking_Form')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='Saliva_Collection_Tracking_Form')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SA_Consent_Form t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SA_Consent_Form')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SA_Consent_Form')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SCAARED_Dad t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SCAARED_Dad')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SCAARED_Dad')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SCAARED_Mom t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SCAARED_Mom')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SCAARED_Mom')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SCARED_Parent_Sibling t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SCARED_Parent_Sibling')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SCARED_Parent_Sibling')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SCARED_Parent_Subject t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SCARED_Parent_Subject')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SCARED_Parent_Subject')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SCARED_Sibling t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SCARED_Sibling')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SCARED_Sibling')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SCARED_Subject t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SCARED_Subject')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SCARED_Subject')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE scq_fxs_subject_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='scq_fxs_subject_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='scq_fxs_subject_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE scq_proband_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='scq_proband_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='scq_proband_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE scq_subject_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='scq_subject_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='scq_subject_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE Seizure_Questionnaire t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='Seizure_Questionnaire')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='Seizure_Questionnaire')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SEQ3 t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SEQ3')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SEQ3')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SEQ3_Subject_Survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SEQ3_Subject_Survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SEQ3_Subject_Survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE sibling_socialcontact t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='sibling_socialcontact')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='sibling_socialcontact')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_InformantReport_Dad_On_Mom t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_InformantReport_Dad_On_Mom')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_InformantReport_Dad_On_Mom')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_InformantReport_Mom_On_Dad t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_InformantReport_Mom_On_Dad')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_InformantReport_Mom_On_Dad')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_Preschool_Sibling_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_Preschool_Sibling_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_Preschool_Sibling_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_Preschool_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_Preschool_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_Preschool_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SchoolAge t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SchoolAge')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SchoolAge')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SchoolAge_Fxs_Subject t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SchoolAge_Fxs_Subject')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SchoolAge_Fxs_Subject')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SchoolAge_Parent t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SchoolAge_Parent')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SchoolAge_Parent')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SchoolAge_Parent_proband t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SchoolAge_Parent_proband')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SchoolAge_Parent_proband')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SchoolAge_Sibling t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SchoolAge_Sibling')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SchoolAge_Sibling')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SelfReport_Dad t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SelfReport_Dad')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SelfReport_Dad')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SRS2_SelfReport_Mom t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SRS2_SelfReport_Mom')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SRS2_SelfReport_Mom')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SSIS_Parent t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SSIS_Parent')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SSIS_Parent')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE SSIS_Teacher t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='SSIS_Teacher')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='SSIS_Teacher')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE tanner_boys_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='tanner_boys_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='tanner_boys_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE tanner_girls_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='tanner_girls_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='tanner_girls_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE Teachers_Report_Form_6_To_18 t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='Teachers_Report_Form_6_To_18')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='Teachers_Report_Form_6_To_18')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE toddler_social_motivation_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='toddler_social_motivation_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='toddler_social_motivation_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE UCD_Charge_GI_History t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='UCD_Charge_GI_History')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='UCD_Charge_GI_History')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

UPDATE vrRSB_survey t
JOIN flag f ON(t.commentid=f.commentid AND f.test_name='vrRSB_survey')
JOIN session s ON(s.id=f.sessionid)
JOIN participant_accounts pa ON(pa.sessionid=s.id AND pa.test_name='vrRSB_survey')
SET Data_entry_completion_status='Complete'
WHERE pa.status = 'Complete';

