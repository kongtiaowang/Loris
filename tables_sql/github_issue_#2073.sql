-- Delete surveys (outdated) from survey module

DELETE FROM survey_test_battery WHERE Test_name='CBCL_1_to_5_yrs';
DELETE FROM survey_test_battery WHERE Test_name='m_chat_rf';
DELETE FROM survey_test_battery WHERE Test_name='SRS2_1';
DELETE FROM survey_test_battery WHERE Test_name='SRS2_2';
DELETE FROM survey_test_battery WHERE Test_name='SRS2_InformantReport';
DELETE FROM survey_test_battery WHERE Test_name='SRS2_SelfReport';
DELETE FROM survey_test_battery WHERE Test_name='pspq_1';
DELETE FROM survey_test_battery WHERE Test_name='pspq_2';
