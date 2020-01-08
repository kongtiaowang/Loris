INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('tsi_ds', "Telephone Screening Interview - Down Syndrome", 9, 0);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('tsi_ds','tsi_ds_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('tsi_ds','tsi_ds_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('tsi_ds','tsi_ds_page3', "Page 3", 3);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('tsi_ds', '0', '0', 'Y', 'Visit', '20', 'V06', NULL);
