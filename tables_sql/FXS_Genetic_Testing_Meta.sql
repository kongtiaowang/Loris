INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('FXS_Genetic_Testing', "FRAGILE X GENETIC TESTING AND FAMILY HISTORY FORM", 1, 0);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FXS_Genetic_Testing','FXS_Genetic_Testing_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('FXS_Genetic_Testing','FXS_Genetic_Testing_page2', "Page 2", 2);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'N', 'Visit', 4, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'N', 'Visit', 5, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'N', 'Visit', 7, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'N', 'Visit', 4, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'N', 'Visit', 5, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'N', 'Visit', 7, 'VSA-CVD', NULL);
