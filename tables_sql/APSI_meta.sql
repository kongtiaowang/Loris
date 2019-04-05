INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('APSI', "Autism Parent Screen for Infants (APSI)", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('APSI','APSI_page1', "Page 1", 1);


-- APSI to IBIS EP HR, IBIS EP LR, DS Infant at V06, V12, V24
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 19, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 19, 'V24', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('APSI', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);