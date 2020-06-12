-- Remove old CBCL instrument
UPDATE test_names SET IsDirectEntry = 0 WHERE Test_name = 'CBCL_1_to_5_yrs';

-- Rename new CBCL instrument
UPDATE test_names SET Full_name = 'CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey' WHERE Test_name = 'CBCL_1_To_5_survey';