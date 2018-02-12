INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('MASC2_Parent', "MASC2: PARENT", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MASC2_Parent','MASC2_Parent_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MASC2_Parent','MASC2_Parent_page2', "Page 2", 2);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('MASC2_Parent', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('MASC2_Parent', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);