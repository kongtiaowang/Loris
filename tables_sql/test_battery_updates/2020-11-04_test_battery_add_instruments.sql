-- Missing for IBIS EP High Risk
-- V06
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('LENA_LanguageSampleActivityLog','0','0','Y','Visit','18','V06',NULL);
-- V6-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','18','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','18','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data','0','0','Y','Visit','18','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data_Labels','0','0','Y','Visit','18','V6-CVD',NULL);
-- V12
UPDATE test_battery set Active='Y' where Visit_label='V12' and subprojectID=18 and test_name='head_measurements_subject';
UPDATE test_battery set Active='Y' where Visit_label='V12' and subprojectID=18 and test_name='DSMV_checklist';
UPDATE test_battery set Active='Y' where Visit_label='V12' and subprojectID=18 and test_name='aosi';
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('LENA_LanguageSampleActivityLog','0','0','Y','Visit','18','V12',NULL);
-- V12-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','18','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','18','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','18','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('JointAttentionAssessment','0','0','Y','Visit','18','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','18','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID
)VALUES ('head_measurements_subject','0','0','Y','Visit','18','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','18','V12-CVD',NULL);
-- V24
UPDATE test_battery set Active='Y' where Visit_label='V24' and subprojectID=18 and test_name='csbs';
UPDATE test_battery set Active='Y' where Visit_label='V24' and subprojectID=18 and test_name='DSMV_checklist';
UPDATE test_battery set Active='Y' where Visit_label='V24' and subprojectID=18 and test_name='ESCS';
-- V24-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ados2_module1','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ados2_module2','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ados2_module3','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ESCS','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)VALUES
 ('head_measurements_subject','0','0','Y','Visit','18','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)VALUES
 ('neuro_screen','0','0','Y','Visit','18','V24-CVD',NULL);


-- Missing for DS Infant
-- V6-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','20','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','20','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','20','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','20','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data','0','0','Y','Visit','20','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data_Labels','0','0','Y','Visit','20','V6-CVD',NULL);
-- V12-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','20','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','20','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('JointAttentionAssessment','0','0','Y','Visit','20','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','20','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','20','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','20','V12-CVD',NULL);

-- V24-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject','0','0','Y','Visit','20','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','20','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','20','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ESCS','0','0','Y','Visit','20','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','20','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','20','V24-CVD',NULL);

-- Missing for Control DS Infant
-- V06
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','23','V06',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','23','V06',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','23','V06',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','23','V06',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data','0','0','Y','Visit','23','V06',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data_Labels','0','0','Y','Visit','23','V06',NULL);
-- V6-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','23','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','23','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','23','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','23','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data','0','0','Y','Visit','23','V6-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Shipley2_Data_Labels','0','0','Y','Visit','23','V6-CVD',NULL);
-- V12
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','23','V12',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','23','V12',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','23','V12',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('JointAttentionAssessment','0','0','Y','Visit','23','V12',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','23','V12',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','23','V12',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','23','V12',NULL);
-- V12-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aims','0','0','Y','Visit','23','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('aosi','0','0','Y','Visit','23','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','23','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('JointAttentionAssessment','0','0','Y','Visit','23','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','23','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','23','V12-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','23','V12-CVD',NULL);
-- V24
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ados2_module1','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ados2_module2','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID
)VALUES ('ados2_module3','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject','0','0','Y','Visit','23','V24',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','23','V24',NULL);
-- V24-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject','0','0','Y','Visit','23','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('csbs','0','0','Y','Visit','23','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist','0','0','Y','Visit','23','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ESCS','0','0','Y','Visit','23','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID
)VALUES ('head_measurements_subject','0','0','Y','Visit','23','V24-CVD',NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen','0','0','Y','Visit','23','V24-CVD',NULL);