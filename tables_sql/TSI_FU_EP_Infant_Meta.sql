INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('TSI_FU_EP_Infant', "Telephone Screening Interview - Follow-Up - EP-Infant", 9, 0);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_EP_Infant','TSI_FU_EP_Infant_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_EP_Infant','TSI_FU_EP_Infant_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_EP_Infant','TSI_FU_EP_Infant_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_EP_Infant','TSI_FU_EP_Infant_page4', "Page 4", 4);

-- IBIS EP High Risk
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 18, 'V24-CVD', NULL);

-- IBIS EP Low Risk
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 19, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 19, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('TSI_FU_EP_Infant', '0', '0', 'Y', 'Visit', 19, 'V24-CVD', NULL);