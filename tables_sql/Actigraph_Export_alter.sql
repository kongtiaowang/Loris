INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 1, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 2, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 3, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 9, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 10, 'VSA-Sleep', NULL);

-- DELETE Instrument from survey battery

DELETE FROM survey_test_battery WHERE Test_name='Actigraph_Export';
