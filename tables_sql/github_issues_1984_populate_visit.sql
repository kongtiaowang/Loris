
-- subproject 'LR Arousal' 

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('CBCL_1_To_5_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('CBCL_6_To_18', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ECBQ_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ibq_r_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('SEQ3', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Infant_social_motivation_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('toddler_social_motivation_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Med_Psych_History_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Med_Psych_History_Abbreviated_survey', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);

