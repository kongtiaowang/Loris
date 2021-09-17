INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('SRS2_2', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('vineland', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);

