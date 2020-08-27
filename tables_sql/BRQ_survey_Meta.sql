INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('BRQ_survey', "BRQ (Bedtime Routine Questionnaire) - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page4', "Page 4", 4);
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BRQ_survey','VSA');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BRQ_survey','VSA-CVD');