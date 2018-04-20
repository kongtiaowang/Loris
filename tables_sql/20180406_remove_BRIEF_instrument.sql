-- Remove original BRIEF instrument from test battery table as it will be replaced by BRIEF-2 
UPDATE test_battery SET Active='N'  WHERE Test_name = 'BRIEF' ;
