-- ----------------------------------------------------------------------
-- SQL file that inserts in the database all the DDE instruments listed
-- in IBIS' config.xml (as of 2020-10-26).
-- ----------------------------------------------------------------------

-- -----------------------------------------------------------------
-- ace_medical_history has been renamed ACESubjectMedicalHistory
-- -----------------------------------------------------------------
-- INSERT INTO Config (ConfigID, Value) SELECT ID, "ace_medical_history" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ACESubjectMedicalHistory" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";

INSERT INTO Config (ConfigID, Value) SELECT ID, "adi_r_proband" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "adi_r_subject" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ados_module1" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ados_module2" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ados_module3" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "aosi" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";

-- ------------------------------------------------------------------------------------------------
-- Audiology instrument data has been retired, so it's not included in the list of DDE instruments
-- ------------------------------------------------------------------------------------------------
-- INSERT INTO Config (ConfigID, Value) SELECT ID, "audiology" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "csbs" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "DSMIV_checklist" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "edi" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ECBQ" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "figs_year3" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "fyi" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "head_measurements_proband" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "head_measurements_subject" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "i3" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ibq_r" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "macarthur_words_gestures" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "med_psych_hist" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "med_records_24" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "med_records_proband" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "med_records_recruit" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "mri_parameter_form" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "mullen" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "m_chat_subject" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";

-- ------------------------------------------------------------------------------------------------
-- The m_chat instrument is now a survey, so it's not included in the list of DDE instruments
-- ------------------------------------------------------------------------------------------------
-- INSERT INTO Config (ConfigID, Value) SELECT ID, "m_chat" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";

INSERT INTO Config (ConfigID, Value) SELECT ID, "m_chat_proband" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "neuro_screen" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "prefrontal_task" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "rbs_r" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "RSMS" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "scq_proband" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "scq_subject" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "seq" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "tsi" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "tsi_followup" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "intervention_history" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "SRS" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "radiology_review" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "HandPreference" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ados2_module1" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ados2_module2" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "ados2_module3" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "aims" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "edi2" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";

-- ---------------------------------------------
-- The CBCL has been renamed CBCL_1_to_5_yrs
-- ---------------------------------------------
-- INSERT INTO Config (ConfigID, Value) SELECT ID, "CBCL" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "CBCL_1_to_5_yrs" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";

INSERT INTO Config (ConfigID, Value) SELECT ID, "FamilyEnvironmentScales" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "JointAttentionAssessment" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "BSRC" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "DSMV_checklist" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
INSERT INTO Config (ConfigID, Value) SELECT ID, "LENA_DailyActivityLog" FROM ConfigSettings WHERE Name="DoubleDataEntryInstruments";
