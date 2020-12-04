-- ------------------------------------------------------
-- Adds the adi_r_subject to the VSA-VCD visits for
-- subproject IDS 1, 2, 3, 9, 10
-- ------------------------------------------------------

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject', '0', '0', 'Y', 'Visit', 1, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject', '0', '0', 'Y', 'Visit', 2, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject', '0', '0', 'Y', 'Visit', 3, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject', '0', '0', 'Y', 'Visit', 9, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_subject', '0', '0', 'Y', 'Visit', 10, 'VSA-CVD', NULL);


-- Add neuroscreen and head measurement subject to IBIS EP HR V6-CVD
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('neuro_screen', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('head_measurements_subject', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);

-- Add TSI_DS_Infant to V12, V12-CVD to tsi ds infant and control
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL);