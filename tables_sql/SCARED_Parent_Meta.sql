INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCARED_Parent', "SCARED (Screen for Child Anxiety Related Disorders) - Parent - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Parent','SCARED_Parent_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Parent','SCARED_Parent_page2', "Page 2", 2);

-- Fragile X at VSA and VSA-CVD
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Parent', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Parent', DEFAULT, 5, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Parent', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Parent', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Parent', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Parent', DEFAULT, 7, 'VSA-CVD');