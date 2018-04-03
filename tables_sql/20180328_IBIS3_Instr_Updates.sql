-- Remove CCC2 instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='CCC2' ;
-- Remove ADULT_SELF_REPORT instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='ADULT_SELF_REPORT' ;
-- Remove UCD_Charge_GI_History instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='UCD_Charge_GI_History' ;
-- Remove Connors_teacher instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='connors_teacher' ;
-- Remove Connors_parent instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='connors_parent' ;
-- Remove MASC2_Self_Report instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='MASC2_Self_Report' ;
-- Remove MASC2_Parent instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='MASC2_Parent' ;
-- Remove seq instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='seq' ;
-- Remove SEQ3 instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='SEQ3' ;
-- Remove CBCL instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='CBCL' ;
-- Remove ABCL instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='ABCL' ;
