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