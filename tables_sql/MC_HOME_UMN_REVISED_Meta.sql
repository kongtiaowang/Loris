INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('MC_HOME_UMN_REVISED', "HOME-MC University of Minnesota REVISED Version", 1, 0);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page4', "Page 4", 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page5', "Page 5", 5);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page6', "Page 6", 6);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page7', "Page 7", 7);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page8', "Page 8", 8);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page9', "Page 9", 9);

-- Add instrument to the following subprojects at VSA and VSA-CVD:
-- IBIS 2 Low Risk, IBIS 2 High Risk, 6 month recruit, 12 month recruit, Control
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '9', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '10', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '1', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '2', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '3', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '9', 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '10', 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '1', 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '2', 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '3', 'VSA-CVD', NULL);