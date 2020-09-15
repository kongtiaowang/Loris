INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('asd_peds', "TELE-ASD-PEDS Rating Form", 1, 0);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('asd_peds','asd_peds_page1', "Page 1", 1);
-- IBIS EP High Risk
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '18', 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '18', 'V24-CVD', NULL);
-- IBIS EP Low Risk
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '19', 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('asd_peds', '0', '0', 'Y', 'Visit', '19', 'V24-CVD', NULL);