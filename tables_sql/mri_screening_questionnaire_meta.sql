INSERT INTO test_names (test_name, full_name, sub_group, isdirectentry) VALUES ('mri_screening_questionnaire', 'MRI Screening Questionnaire', 1, null);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES 
('mri_screening_questionnaire', 'mri_screening_questionnaire_page1', "Page 1", 1);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) 
VALUES ('mri_screening_questionnaire', '1', '99999', 'Y', 'Visit', '1', 'V1', NULL, NULL, 1);