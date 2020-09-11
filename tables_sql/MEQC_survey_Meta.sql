INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('MEQC_survey', "MEQC (Morningness Eveningness Questionnaire for Children) - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MEQC_survey','MEQC_survey_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MEQC_survey','MEQC_survey_page2', "Page 2", 2);
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('MEQC_survey','VSA-Sleep');