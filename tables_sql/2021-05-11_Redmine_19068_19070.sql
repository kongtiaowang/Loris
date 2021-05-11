ALTER TABLE SCAARED_Adult DROP COLUMN respondent_explain;

INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Adult', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Adult', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Adult', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCAARED_Adult', DEFAULT, 7, 'VSA-CVD');

INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Child', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Child', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Child', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('SCARED_Child', DEFAULT, 7, 'VSA-CVD');