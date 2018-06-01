-- Insert patch for this instrument to test_names table is already on production database
-- so adding the rest which seems missing
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('parent_concerns_interview', 'parent_concerns_interview_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('parent_concerns_interview', 'parent_concerns_interview_page2', "Page 2", 2);
-- test battery requirements
-- needs to be added to V3, V6, V12, V15 for HR and LR in IBIS2
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 9, 'V03', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 10, 'V03', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 9, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 10, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 9, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 10, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 9, 'V15', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('parent_concerns_interview', '0', '0', 'Y', 'Visit', 10, 'V15', NULL);

