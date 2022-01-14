-- remove instrument from V09 & V12 Visit Label 
DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label IN ('V09', 'V9-CVD', 'V12', 'V12-CVD');

DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label IN ('V06', 'V06-CVD') AND SubprojectID=20;

DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label IN ('V18', 'V18-CVD') AND SubprojectID IN (20,23);

DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label IN ('V24', 'V24-CVD') AND SubprojectID=18;

ALTER TABLE m_chat_rf ADD `specify_recipient` enum('subject','proband') default NULL;
