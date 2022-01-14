-- remove instrument from V09 & V12 Visit Label 
DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label='V09';
DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label='V12';


ALTER TABLE m_chat_rf ADD `specify_recipient` enum('subject','proband') default NULL;

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);

