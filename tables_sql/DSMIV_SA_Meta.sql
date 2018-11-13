INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('DSMIV_SA', "DSM-IV Autistic Disorder Checklist", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DSMIV_SA','DSMIV_SA_page1', "Page 1", 1);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_SA', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_SA', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);
