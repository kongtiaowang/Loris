INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('FOH_Intervention_History', 'FOH - EDUCATIONAL/INTERVENTION HISTORY', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FOH_Intervention_History','FOH_Intervention_History_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FOH_Intervention_History','FOH_Intervention_History_page2', "Page 2", 2);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_Intervention_History', '0', '0', 'Y', 'Visit', 4, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_Intervention_History', '0', '0', 'Y', 'Visit', 5, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_Intervention_History', '0', '0', 'Y', 'Visit', 4, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_Intervention_History', '0', '0', 'Y', 'Visit', 5, 'VSA-CVD', NULL);

