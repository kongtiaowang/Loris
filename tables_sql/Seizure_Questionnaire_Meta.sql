INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('Seizure_Questionnaire', "Seizure Questionnaire - Survey", 9, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Seizure_Questionnaire','Seizure_Questionnaire_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Seizure_Questionnaire','Seizure_Questionnaire_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Seizure_Questionnaire','Seizure_Questionnaire_page3', "Page 3", 3);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Seizure_Questionnaire', '0', '0', 'N', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Seizure_Questionnaire', '0', '0', 'N', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Seizure_Questionnaire', '0', '0', 'N', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Seizure_Questionnaire', '0', '0', 'N', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Seizure_Questionnaire', '0', '0', 'N', 'Visit', 10, 'VSA', NULL);