INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('TSI_IDDRC_FOH', "TSI (Telephone Screening Interview ) - IDDRC + FOH (FXS + AS)", 9, 0);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDDRC_FOH','TSI_IDDRC_FOH_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDDRC_FOH','TSI_IDDRC_FOH_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDDRC_FOH','TSI_IDDRC_FOH_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDDRC_FOH','TSI_IDDRC_FOH_page4', "Page 4", 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDDRC_FOH','TSI_IDDRC_FOH_page5', "Page 5", 5);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDDRC_FOH','TSI_IDDRC_FOH_page6', "Page 6", 6);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_IDDRC_FOH', '0', '0', 'Y', 'Visit', 4, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_IDDRC_FOH', '0', '0', 'Y', 'Visit', 4, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_IDDRC_FOH', '0', '0', 'Y', 'Visit', 5, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_IDDRC_FOH', '0', '0', 'Y', 'Visit', 5, 'VSA-CVD', NULL);
