INSERT INTO test_names(Test_name, Full_name, Sub_Group,isDirectEntry) VALUES('Saliva_Collection_Tracking_Form', "Saliva Collection Tracking Form", 1 , 1);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Saliva_Collection_Tracking_Form','Saliva_Collection_Tracking_Form_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Saliva_Collection_Tracking_Form','Saliva_Collection_Tracking_Form_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Saliva_Collection_Tracking_Form','Saliva_Collection_Tracking_Form_page3', "Page 3", 3);

--  IBIS1 & 2(subprojects) VSA visit lables
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);

--  IBIS1 & 2(subprojects) VSA-CVD visit lables
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 1, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 2, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 3, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 9, 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 10, 'VSA-CVD', NULL);
