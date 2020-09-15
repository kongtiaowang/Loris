INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_SA', '0', '0', 'Y', 'Visit', 18, 'V18-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_SA', '0', '0', 'Y', 'Visit', 19, 'V18-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('vrrsb', '0', '0', 'Y', 'Visit', 18, 'V18-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('vrrsb', '0', '0', 'Y', 'Visit', 19, 'V18-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_SA', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_SA', '0', '0', 'Y', 'Visit', 19, 'V18', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('vrrsb', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('vrrsb', '0', '0', 'Y', 'Visit', 19, 'V18', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('LENA_LanguageSampleActivityLog', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('LENA_LanguageSampleActivityLog', '0', '0', 'Y', 'Visit', 19, 'V18', NULL);

-- Configure survey_test_battery
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('apsi_survey','V09');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BISQ_survey','V09');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('rbs_ec_survey','V09');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('Infant_social_motivation_survey','V09');

INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('apsi_survey','V9-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BISQ_survey','V9-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('rbs_ec_survey','V9-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('Infant_social_motivation_survey','V9-CVD');

INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('apsi_survey','V18');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BISQ_survey','V18');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('RBS_EC_G_V12_V24_Survey','V18');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('toddler_social_motivation_survey','V18');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('scq_subject_survey','V18');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('scq_proband_survey','V18');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('m_chat_rf','V18');

INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('apsi_survey','V18-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BISQ_survey','V18-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('RBS_EC_G_V12_V24_Survey','V18-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('toddler_social_motivation_survey','V18-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('scq_subject_survey','V18-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('scq_proband_survey','V18-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('m_chat_rf','V18-CVD');

-- Redmine 18286
ALTER TABLE `DSMV_checklist` ADD COLUMN `dsm_social_disorder_comments` TEXT DEFAULT NULL;
ALTER TABLE `DSMV_checklist` ADD COLUMN `dsm_social_disorder_comments_status` enum('not_answered') DEFAULT NULL;