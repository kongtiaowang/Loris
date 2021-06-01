INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('caars_SelfReport_scale', "CAARS–Self-Report Scale: Short Version (CAARS–S:S)", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('caars_SelfReport_scale','caars_SelfReport_scale_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('caars_SelfReport_scale','caars_SelfReport_scale_page2', "Page 2", 2);

-- Fragile X at VSA and VSA-CVD
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_scale', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_scale', DEFAULT, 5, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_scale', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_scale', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_scale', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_scale', DEFAULT, 7, 'VSA-CVD');
