INSERT INTO test_names(Test_name, Full_name, Sub_Group, IsDirectEntry) VALUES('conners_parent', "CONNERS 3 - Parent Short", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('conners_parent','conners_parent_page1', "Page 1", 1);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('conners_parent', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('conners_parent', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);