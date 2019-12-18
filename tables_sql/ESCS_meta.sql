INSERT INTO test_names (test_name, full_name, sub_group, isdirectentry) VALUES 
('ESCS', 'Early Social Communication Scales Coding Sheet', 1, 0);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES 
('ESCS', 'ESCS_page1', "IJA&RJA", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES 
('ESCS', 'ESCS_page2', "IBR&RBR", 1);


--  DS Infant project gets the ESCS form for V24 visit
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('ESCS', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);
