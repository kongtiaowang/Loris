DELETE from survey_test_battery where test_name IN('acesubjectmedical_survey',
'Med_Psych_History_Abbreviated_survey',
'rbs_r') and Visit_label IN ('V06','V6-CVD');

-- V9 & V9-CVD, V12, V12-CVD
--  SRS-2 SA (Social Responsiveness Scale – Schoo Age) - Survey (Add) *

INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('SRS2_Preschool_survey','V09');
INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('SRS2_Preschool_survey','V9-CVD');

DELETE from survey_test_battery where test_name IN('acesubjectmedical_survey',
'mcdi_words_gestures_sentences_survey',
'rbs_r') and Visit_label IN ('V12','V12-CVD');

INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('SRS2_Preschool_survey','V12');
INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('SRS2_Preschool_survey','V12-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('m_chat_rf','V12');
INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('m_chat_rf','V12-CVD');
INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('scq_proband_survey','V12');
INSERT INTO survey_test_battery (Test_name, Visit_label)
VALUES ('scq_proband_survey','V12-CVD');

DELETE from survey_test_battery where test_name IN('acesubjectmedical_survey',
'Med_Psych_History_survey'
'rbs_r',
'rbs_r_proband',
'macarthur_words_gestures_survey') and Visit_label IN ('V24','V24-CVD');