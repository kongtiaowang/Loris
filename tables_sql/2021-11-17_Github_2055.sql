-- Github Issue #2055

DELETE FROM survey_test_battery WHERE Test_name = 'caars_SelfReport_dad' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'caars_SelfReport_mom' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'CBCL_1_To_5_survey_sibling' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'CBCL_6_To_18_survey_sibling' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'CBCL_6_To_18_survey_subject' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SCAARED_Dad' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SCAARED_Mom' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SCARED_Parent_Sibling' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SCARED_Parent_Subject' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SCARED_Sibling' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SCARED_Subject' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SRS2_Preschool_Sibling_survey' AND SubprojectID = 7;
DELETE FROM survey_test_battery WHERE Test_name = 'SRS2_SchoolAge_Sibling' AND SubprojectID = 7;

-- CAARS–Self-Report Scale: Self Report Dad (Send to Dad) - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('caars_SelfReport_dad','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('caars_SelfReport_dad','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('caars_SelfReport_dad','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('caars_SelfReport_dad','VSA-CVD', 5);

-- SCARED (Screen for Anxiety Related Disorders) - Child - Subject - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Parent_Subject','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Parent_Subject','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Parent_Subject','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Parent_Subject','VSA-CVD', 5);

-- SCARED (Screen for Child Anxiety Related Disorders) - Parent - Sibling - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Sibling','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Sibling','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Sibling','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Sibling','VSA-CVD', 5);

-- SCARED (Screen for Child Anxiety Related Disorders) - Parent - Subject - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Subject','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Subject','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Subject','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCARED_Subject','VSA-CVD', 5);

-- SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Mom - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCAARED_Mom','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCAARED_Mom','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCAARED_Mom','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SCAARED_Mom','VSA-CVD', 5);

-- SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - FOH Sibling - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_Preschool_Sibling_survey','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_Preschool_Sibling_survey','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_Preschool_Sibling_survey','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_Preschool_Sibling_survey','VSA-CVD', 5);

-- SRS-2 SA (Social Responsiveness Scale – School Age) - FOH Sibling - Survey
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_SchoolAge_Sibling','VSA', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_SchoolAge_Sibling','VSA', 5);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_SchoolAge_Sibling','VSA-CVD', 4);
INSERT INTO survey_test_battery (Test_name, Visit_label, SubprojectID) VALUES ('SRS2_SchoolAge_Sibling','VSA-CVD', 5);

-- CBCL (Child Behavior Checklist) 1.5 to 5 years - FOH Sibling - Survey
UPDATE survey_test_battery SET SubprojectID = 20 WHERE Test_name = 'CBCL_1_To_5_survey_sibling' AND Visit_label = 'iDS-FOH';

-- SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - FOH Sibling - Survey
UPDATE survey_test_battery SET SubprojectID = 20 WHERE Test_name = 'SRS2_Preschool_Sibling_survey' AND Visit_label = 'iDS-FOH';

-- SRS-2 SA (Social Responsiveness Scale – School Age) - FOH Sibling - Survey
UPDATE survey_test_battery SET SubprojectID = 20 WHERE Test_name = 'SRS2_SchoolAge_Sibling' AND Visit_label = 'iDS-FOH';