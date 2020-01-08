INSERT INTO test_names(Test_name, Full_name, Sub_Group,isDirectEntry) VALUES('Radiology_Review_VSA', "Radiology Review VSA", 1 , 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Radiology_Review_VSA','Radiology_Review_VSA_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Radiology_Review_VSA','Radiology_Review_VSA_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Radiology_Review_VSA','Radiology_Review_VSA_page3', "Page 3", 3);

--  IBIS1 & 2(subprojects) VSA visit lables
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);

--  DS SA VSA visit label
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 21, 'VSA', NULL);

--  DS Infant gets the Rad review SA form across ALL visits
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 20, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 23, NULL, NULL);



--  IBIS EP High Risk & IBIS EP Low Risk get the Rad review SA form across ALL visits
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 18, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Radiology_Review_VSA', '0', '0', 'Y', 'Visit', 19, NULL, NULL);



