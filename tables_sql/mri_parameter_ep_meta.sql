INSERT INTO test_names (test_name, full_name, sub_group, isdirectentry) values('mri_parameter_ep', 'MRI Parameter form EP & Infant DS', 1, 0);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mri_parameter_ep', 'mri_parameter_ep_page1', "Record", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mri_parameter_ep', 'mri_parameter_ep_page2', "Structuaral", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mri_parameter_ep', 'mri_parameter_ep_page3', "BOLD", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mri_parameter_ep', 'mri_parameter_ep_page4', "DTI", 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mri_parameter_ep', 'mri_parameter_ep_page5', "BOLD+", 5);


--  DS Infant project gets the mri_parameter_ep form across ALL visits
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);

--  IBIS EP High Risk & IBIS EP Low Risk get the mri_parameter_ep form across ALL visits
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 19, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('mri_parameter_ep', '0', '0', 'Y', 'Visit', 19, 'V24', NULL);