INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('QRS_Proband','V06');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('QRS_Proband','V6-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('SRS2_SchoolAge_Parent_proband','V06');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('SRS2_SchoolAge_Parent_proband','V6-CVD');
-- Delete list of surveys added to Screening vist label as per Santiago
DELETE * from survey_test_battery where Visit_label='Screening';