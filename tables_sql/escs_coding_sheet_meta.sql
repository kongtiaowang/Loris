INSERT INTO test_names (test_name, full_name, sub_group, isdirectentry) VALUES 
('escs_coding_sheet', 'Early Social Communication Scales Coding Sheet', 1, 0);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES 
('escs_coding_sheet', 'escs_coding_sheet_page1', "IJA&RJA", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES 
('escs_coding_sheet', 'escs_coding_sheet_page2', "IBR&RBR", 1);


--  DS Infant project gets the escs_coding_sheet form across ALL visits
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);

--  IBIS EP High Risk & IBIS EP Low Risk get the escs_coding_sheet form across ALL visits
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 19, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('escs_coding_sheet', '0', '0', 'Y', 'Visit', 19, 'V24', NULL);
