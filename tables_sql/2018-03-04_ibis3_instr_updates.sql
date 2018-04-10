-- Remove CSHQ instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='CSHQ' ;
-- Remove ADULT_SELF_REPORT instrument from test battery  table as it must be added to visit from survey module
UPDATE test_battery SET Active='N' WHERE  Test_name ='QRS' ;

-- Set CSHQ to be a survey instrument
UPDATE test_names SET isDirectEntry=1 WHERE Test_name='CSHQ' ;
-- Set QRS to be a survey instrument
UPDATE test_names SET isDirectEntry=1 WHERE Test_name='QRS' ;
-- Set UCD_Charge_GI_History to be a survey instrument
UPDATE test_names SET isDirectEntry=1 WHERE Test_name='UCD_Charge_GI_History' ;
-- Set ABCL to be a survey instrument
UPDATE test_names SET isDirectEntry=1 WHERE Test_name='ABCL' ;
