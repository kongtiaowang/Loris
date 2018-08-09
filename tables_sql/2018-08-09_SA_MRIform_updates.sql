-- Update IBIS SA mri parameter form to be appear in MRI category
UPDATE test_names SET Sub_group=8 WHERE Test_name='mri_parameter_form_sa' ;
-- Remove IBIS old Mri parameter form from VSA battery
UPDATE test_battery SET Active='N' WHERE  Test_name ='mri_paramter_form' and Visit_label='VSA';

