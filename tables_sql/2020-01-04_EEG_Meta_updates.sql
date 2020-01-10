--  REMOVE IBIS1 & 2(subprojects) & DS SA VSA visit label
UPDATE test_battery SET Active='N' WHERE  Test_name ='EEG' AND Visit_label = 'VSA';
