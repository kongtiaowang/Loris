INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('TSI_DS_Infant', "Telephone Screening Interview - DS-Infant", 9, 0);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_DS_Infant','TSI_DS_Infant_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_DS_Infant','TSI_DS_Infant_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_DS_Infant','TSI_DS_Infant_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_DS_Infant','TSI_DS_Infant_page4', "Page 4", 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_DS_Infant','TSI_DS_Infant_page5', "Page 5", 5);

-- DS Infant
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V6-CVD', NULL);

-- Control DS Infant
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V6-CVD', NULL);