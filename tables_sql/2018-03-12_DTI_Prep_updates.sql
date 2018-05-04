-- create a new category called analysis and move DTI prep and output there
-- Table Auto Increment not supported; so added the valid ID crosschecking the prod database
INSERT INTO test_subgroups (ID,Subgroup_name) VALUES (11,'Analysis');
UPDATE test_names SET Sub_group=11 WHERE Test_name='dtiprep' ;
-- Update mock scanner to be apper in MRI category
UPDATE test_names SET Sub_group=8 WHERE Test_name='mock_scanner_training_form' ;

