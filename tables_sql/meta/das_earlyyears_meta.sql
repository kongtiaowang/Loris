INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('das_earlyyears', 'DAS (Differential Ability
    Scales) - Early Years', '1');

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page1', 'Verbal Comprehension', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page2', 'Picture Similarities', 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page3', 'Naming Vocabulary', 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page4', 'Recall of Objects - Immediate', 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page5', 'Pattern Construction', 5);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page6', 'Matrices', 6);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page7', 'Recall of Objects - Delayed', 7);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page8', 'Copying', 8);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page9', 'Recall of Digits Forward', 9);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page10', 'Recognition of Pictures', 10);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page11', 'Early Number Concepts', 11);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page12', 'Matching Letter-Like Forms', 12);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page13', 'Recall of Sequential Order', 13);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page14', 'Speed of Information Processing', 14);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page15', 'Recall of Digits Backward', 15);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page16', 'Phonological Processing', 16);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page17', 'Optional Core Analysis', 17);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page18', 'Behavioral Observations', 18);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('das_earlyyears', '1', '99999', 'Y', 'Visit', '1', 'V37Plus', NULL);