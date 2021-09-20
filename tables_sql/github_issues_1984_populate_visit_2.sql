DELETE FROM test_battery WHERE Test_name='SRS2_2' AND Visit_label='LR-Arousal-V1';
DELETE FROM survey_test_battery WHERE Test_name='rbs_r' AND Visit_label='LR-Arousal-V1';
DELETE FROM test_battery WHERE Test_name='rbs_r' AND Visit_label='LR-Arousal-V1';

UPDATE test_battery SET Test_name='Vineland-3' WHERE Test_name='vineland';
