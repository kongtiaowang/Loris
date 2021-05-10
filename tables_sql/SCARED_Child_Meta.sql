INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCARED_Child', "SCARED (Screen for Child Anxiety Related Disorders) - Child - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Child','SCARED_Child_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Child','SCARED_Child_page2', "Page 2", 2);

-- Fragile X at VSA
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Child', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Child', DEFAULT, 5, 'VSA');