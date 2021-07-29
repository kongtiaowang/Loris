INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('TSI_IDS_FOH', "TSI (Telephone Screening Interview ) - iDS - FOH", 9, 0);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDS_FOH','TSI_IDS_FOH_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDS_FOH','TSI_IDS_FOH_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDS_FOH','TSI_IDS_FOH_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_IDS_FOH','TSI_IDS_FOH_page4', "Page 4", 4);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_IDS_FOH', '0', '0', 'Y', 'Visit', 20, 'iDS-FOH', NULL);

