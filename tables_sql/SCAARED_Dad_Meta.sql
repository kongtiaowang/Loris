INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCAARED_Dad', "SCAARED (Screen for Dad Anxiety Related Disorders) - Dad - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCAARED_Dad','SCAARED_Dad_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCAARED_Dad','SCAARED_Dad_page2', "Page 2", 2);

-- Fragile X at VSA and VSA-CVD
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Dad', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Dad', DEFAULT, 5, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Dad', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Dad', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Dad', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Dad', DEFAULT, 7, 'VSA-CVD');