-- Add MRI instruments to IBIS EP
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('EEG', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('EEG', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mri_screening_questionnaire', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mri_screening_questionnaire', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);

DELETE FROM survey_test_battery where Test_name IN ('rbs_r_proband','SRS2_SchoolAge_Parent_proband');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('rbs_r_proband','All');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('SRS2_SchoolAge_Parent_proband','All');

-- Add TSI_DS_Infant to V12, V12-CVD to tsi ds infant and control
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL);

