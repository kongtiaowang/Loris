-- Update correct table & Subtest names

UPDATE instrument_subtests SET Subtest_name="SRS2_Preschool_Sibling_survey_page1" WHERE Test_name="SRS2_Preschool_Sibling_survey" AND Order_number=1;
UPDATE instrument_subtests SET Subtest_name="SRS2_Preschool_Sibling_survey_page2" WHERE Test_name="SRS2_Preschool_Sibling__survey" AND Order_number=2;
UPDATE instrument_subtests SET Test_name="SRS2_Preschool_Sibling_survey" WHERE Subtest_name="SRS2_Preschool_Sibling_survey_page2" AND Order_number=2;
UPDATE instrument_subtests SET Subtest_name="SRS2_Preschool_Sibling_survey_page3" WHERE Test_name="SRS2_Preschool_Sibling_survey" AND Order_number=3;
UPDATE instrument_subtests SET Subtest_name="SRS2_Preschool_Sibling_survey_page4" WHERE Test_name="SRS2_Preschool_Sibling_survey" AND Order_number=4;
