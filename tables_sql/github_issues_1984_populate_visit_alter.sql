
-- delete instruments from test_battery

DELETE FROM test_battery WHERE Test_name='CBCL_1_To_5_survey' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='CBCL_6_To_18' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='ECBQ_survey' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='SEQ3' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='Infant_social_motivation_survey' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='ibq_r_survey' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='toddler_social_motivation_survey' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='Med_Psych_History_survey' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='Med_Psych_History_Abbreviated_survey' AND Visit_label='LR-Arousal-V1';


-- insert instruments to survey_test_battery

INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('CBCL_1_To_5_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('CBCL_6_To_18', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('ECBQ_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SEQ3', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('Infant_social_motivation_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('ibq_r_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('toddler_social_motivation_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('Med_Psych_History_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('Med_Psych_History_Abbreviated_survey', DEFAULT, (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1');

-- create visit 

INSERT INTO `Visit_Windows` (`Visit_label`, `WindowMinDays`, `WindowMaxDays`, `OptimumMinDays`, `OptimumMaxDays`, `WindowMidpointDays`, `ID`) VALUES ('LR-Arousal-V1', NULL, NULL, NULL, NULL, NULL, DEFAULT);

