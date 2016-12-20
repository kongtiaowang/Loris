INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('das_schoolage', 'DAS (Differential Ability
    Scales) - School-Age Core', '1');

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_schoolage',
    'das_schoolage_page1', 'Recall of Designs', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_schoolage',
    'das_schoolage_page2', 'Word Definitions', 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_schoolage',
    'das_schoolage_page3', 'Pattern Construction', 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_schoolage',
    'das_schoolage_page4', 'Matrices', 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_schoolage',
    'das_schoolage_page5', 'Verbal Similarities', 5);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_schoolage',
    'das_schoolage_page6', 'Sequential and Quantitative Reasoning', 6);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('das_schoolage', '1', '99999', 'Y', 'Visit', '1', 'V37Plus', null);