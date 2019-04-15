INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('toddler_social_motivation', "Toddler Social Motivation Questionnaire", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('toddler_social_motivation','toddler_social_motivation_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('toddler_social_motivation','toddler_social_motivation_page2', "Page 2", 2);


-- toddler_social_motivation to IBIS EP HR, IBIS EP LR, DS Infant at  V12, V24
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('toddler_social_motivation', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('toddler_social_motivation', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('toddler_social_motivation', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('toddler_social_motivation', '0', '0', 'Y', 'Visit', 19, 'V24', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('toddler_social_motivation', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('toddler_social_motivation', '0', '0', 'Y', 'Visit', 20, 'V24', NULL); 