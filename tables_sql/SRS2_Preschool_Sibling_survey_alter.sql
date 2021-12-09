-- Delete all mispelt table names

DELETE FROM instrument_subtests WHERE Test_name='SRS2_Preschool_Sibling_survey';
DELETE FROM instrument_subtests WHERE Test_name='SRS2_Preschool_Sibling__survey';

-- Insert correct table names

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_Preschool_Sibling_survey','SRS2_Preschool_Sibling_survey_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_Preschool_Sibling_survey','SRS2_Preschool_Sibling_survey_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_Preschool_Sibling_survey','SRS2_Preschool_Sibling_survey_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_Preschool_Sibling_survey','SRS2_Preschool_Sibling_survey_page4', "Page 4", 4);
