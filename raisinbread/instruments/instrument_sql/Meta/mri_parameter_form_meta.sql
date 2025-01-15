INSERT INTO test_names (Test_name, Full_name, Sub_group) SELECT 'mri_parameter_form', 'MRI Parameter Form', ID FROM test_subgroups WHERE Subgroup_name = 'Imaging';

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mri_parameter_form', 'mri_parameter_form_page1', 'Page 1', 1);

