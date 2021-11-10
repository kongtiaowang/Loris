-- Change m_chat_rf from survey to regular instrument
UPDATE test_names SET IsDirectEntry = 0 WHERE Test_name = 'm_chat_rf';
DELETE FROM participant_accounts WHERE Test_name = 'm_chat_rf';

-- Remove old surveys
DELETE FROM test_names WHERE Test_name = 'CBCL_1_to_5_yrs';
DELETE FROM test_names WHERE Test_name = 'pspq_1';
DELETE FROM test_names WHERE Test_name = 'pspq_2';
DELETE FROM test_names WHERE Test_name = 'SRS2_1';
DELETE FROM test_names WHERE Test_name = 'SRS2_2';
DELETE FROM test_names WHERE Test_name = 'SRS2_InformantReport';
DELETE FROM test_names WHERE Test_name = 'SRS2_SelfReport';