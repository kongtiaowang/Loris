INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCAARED_Adult', "SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCAARED_Adult','SCAARED_Adult_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCAARED_Adult','SCAARED_Adult_page2', "Page 2", 2);

-- Fragile X at VSA
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Adult', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Adult', DEFAULT, 5, 'VSA');