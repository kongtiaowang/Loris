CREATE TABLE `dtiprep` (
  `CommentID` varchar(255) NOT NULL default '',
  `UserID` varchar(255) default NULL,
  `Examiner` varchar(255) default NULL,
  `Testdate` timestamp NOT NULL,
  `Date_taken` date default NULL,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
  `filetype` enum('ad','fa','md','rd') default NULL,
  `File_name` varchar(255) default NULL,
  `ALIC_L_ad` float(5,5) default NULL,
  `ALIC_R_ad` float(5,5) default NULL,
  `Arcuate_L_ad` float(5,5) default NULL,
  `Arcuate_L_temporofrontal_ad` float(5,5) default NULL,
  `Arcuate_L_temporoparietal_ad` float(5,5) default NULL,
  `Arcuate_R_ad` float(5,5) default NULL,
  `Arcuate_R_frontoparietal_ad` float(5,5) default NULL,
  `ATR_L_ad` float(5,5) default NULL,
  `ATR_R_ad` float(5,5) default NULL,
  `CCbody_ad` float(5,5) default NULL,
  `CCGenu_ad` float(5,5) default NULL,
  `CCSec1_ad` float(5,5) default NULL,
  `CCSec2_ad` float(5,5) default NULL,
  `CCSec3_ad` float(5,5) default NULL,
  `CCSec4_ad` float(5,5) default NULL,
  `CCSec5a_ad` float(5,5) default NULL,
  `CCSec5b_ad` float(5,5) default NULL,
  `CCSplenium_ad` float(5,5) default NULL,
  `Cingulum_L_ad` float(5,5) default NULL,
  `Cingulum_R_ad` float(5,5) default NULL,
  `CST_L_ad` float(5,5) default NULL,
  `CST_R_ad` float(5,5) default NULL,
  `Fornix_column_ad` float(5,5) default NULL,
  `IFOF_L_ad` float(5,5) default NULL,
  `IFOF_R_ad` float(5,5) default NULL,
  `ILF_L_ad` float(5,5) default NULL,
  `ILF_R_ad` float(5,5) default NULL,
  `MCP_ad` float(5,5) default NULL,
  `PCT_ad` float(5,5) default NULL,
  `SCP_L_ad` float(5,5) default NULL,
  `SCP_R_ad` float(5,5) default NULL,
  `Uncinate_L_ad` float(5,5) default NULL,
  `Uncinate_R_ad` float(5,5) default NULL,
  `ALIC_L_fa` float(5,5) default NULL,
  `ALIC_R_fa` float(5,5) default NULL,
  `Arcuate_L_fa` float(5,5) default NULL,
  `Arcuate_L_temporofrontal_fa` float(5,5) default NULL,
  `Arcuate_L_temporoparietal_fa` float(5,5) default NULL,
  `Arcuate_R_fa` float(5,5) default NULL,
  `Arcuate_R_frontoparietal_fa` float(5,5) default NULL,
  `ATR_L_fa` float(5,5) default NULL,
  `ATR_R_fa` float(5,5) default NULL,
  `CCbody_fa` float(5,5) default NULL,
  `CCGenu_fa` float(5,5) default NULL,
  `CCSec1_fa` float(5,5) default NULL,
  `CCSec2_fa` float(5,5) default NULL,
  `CCSec3_fa` float(5,5) default NULL,
  `CCSec4_fa` float(5,5) default NULL,
  `CCSec5a_fa` float(5,5) default NULL,
  `CCSec5b_fa` float(5,5) default NULL,
  `CCSplenium_fa` float(5,5) default NULL,
  `Cingulum_L_fa` float(5,5) default NULL,
  `Cingulum_R_fa` float(5,5) default NULL,
  `CST_L_fa` float(5,5) default NULL,
  `CST_R_fa` float(5,5) default NULL,
  `Fornix_column_fa` float(5,5) default NULL,
  `IFOF_L_fa` float(5,5) default NULL,
  `IFOF_R_fa` float(5,5) default NULL,
  `ILF_L_fa` float(5,5) default NULL,
  `ILF_R_fa` float(5,5) default NULL,
  `MCP_fa` float(5,5) default NULL,
  `PCT_fa` float(5,5) default NULL,
  `SCP_L_fa` float(5,5) default NULL,
  `SCP_R_fa` float(5,5) default NULL,
  `Uncinate_L_fa` float(5,5) default NULL,
  `Uncinate_R_fa` float(5,5) default NULL,
  `ALIC_L_md` float(5,5) default NULL,
  `ALIC_R_md` float(5,5) default NULL,
  `Arcuate_L_md` float(5,5) default NULL,
  `Arcuate_L_temporofrontal_md` float(5,5) default NULL,
  `Arcuate_L_temporoparietal_md` float(5,5) default NULL,
  `Arcuate_R_md` float(5,5) default NULL,
  `Arcuate_R_frontoparietal_md` float(5,5) default NULL,
  `ATR_L_md` float(5,5) default NULL,
  `ATR_R_md` float(5,5) default NULL,
  `CCbody_md` float(5,5) default NULL,
  `CCGenu_md` float(5,5) default NULL,
  `CCSec1_md` float(5,5) default NULL,
  `CCSec2_md` float(5,5) default NULL,
  `CCSec3_md` float(5,5) default NULL,
  `CCSec4_md` float(5,5) default NULL,
  `CCSec5a_md` float(5,5) default NULL,
  `CCSec5b_md` float(5,5) default NULL,
  `CCSplenium_md` float(5,5) default NULL,
  `Cingulum_L_md` float(5,5) default NULL,
  `Cingulum_R_md` float(5,5) default NULL,
  `CST_L_md` float(5,5) default NULL,
  `CST_R_md` float(5,5) default NULL,
  `Fornix_column_md` float(5,5) default NULL,
  `IFOF_L_md` float(5,5) default NULL,
  `IFOF_R_md` float(5,5) default NULL,
  `ILF_L_md` float(5,5) default NULL,
  `ILF_R_md` float(5,5) default NULL,
  `MCP_md` float(5,5) default NULL,
  `PCT_md` float(5,5) default NULL,
  `SCP_L_md` float(5,5) default NULL,
  `SCP_R_md` float(5,5) default NULL,
  `Uncinate_L_md` float(5,5) default NULL,
  `Uncinate_R_md` float(5,5) default NULL,
  `ALIC_L_rd` float(5,5) default NULL,
  `ALIC_R_rd` float(5,5) default NULL,
  `Arcuate_L_rd` float(5,5) default NULL,
  `Arcuate_L_temporofrontal_rd` float(5,5) default NULL,
  `Arcuate_L_temporoparietal_rd` float(5,5) default NULL,
  `Arcuate_R_rd` float(5,5) default NULL,
  `Arcuate_R_frontoparietal_rd` float(5,5) default NULL,
  `ATR_L_rd` float(5,5) default NULL,
  `ATR_R_rd` float(5,5) default NULL,
  `CCbody_rd` float(5,5) default NULL,
  `CCGenu_rd` float(5,5) default NULL,
  `CCSec1_rd` float(5,5) default NULL,
  `CCSec2_rd` float(5,5) default NULL,
  `CCSec3_rd` float(5,5) default NULL,
  `CCSec4_rd` float(5,5) default NULL,
  `CCSec5a_rd` float(5,5) default NULL,
  `CCSec5b_rd` float(5,5) default NULL,
  `CCSplenium_rd` float(5,5) default NULL,
  `Cingulum_L_rd` float(5,5) default NULL,
  `Cingulum_R_rd` float(5,5) default NULL,
  `CST_L_rd` float(5,5) default NULL,
  `CST_R_rd` float(5,5) default NULL,
  `Fornix_column_rd` float(5,5) default NULL,
  `IFOF_L_rd` float(5,5) default NULL,
  `IFOF_R_rd` float(5,5) default NULL,
  `ILF_L_rd` float(5,5) default NULL,
  `ILF_R_rd` float(5,5) default NULL,
  `MCP_rd` float(5,5) default NULL,
  `PCT_rd` float(5,5) default NULL,
  `SCP_L_rd` float(5,5) default NULL,
  `SCP_R_rd` float(5,5) default NULL,
  `Uncinate_L_rd` float(5,5) default NULL,
  `Uncinate_R_rd` float(5,5) default NULL,
  PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO `test_names` (Test_name, Full_name, Sub_group, isDirectEntry) VALUES ('dtiprep', 'DTIPrep and DTI Processing Output', 8, false);
INSERT INTO `instrument_subtests` (`Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES ('dtiprep', 'dtiprep_page1', 'Full Average AD', '1');
INSERT INTO `instrument_subtests` (`Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES ('dtiprep', 'dtiprep_page2', 'Full Average FA', '2');
INSERT INTO `instrument_subtests` (`Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES ('dtiprep', 'dtiprep_page3', 'Full Average MD', '3');
INSERT INTO `instrument_subtests` (`Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES ('dtiprep', 'dtiprep_page4', 'Full Average RD', '4');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 1, 'V09JA', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 1, 'V15JA', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 2, 'V09JA', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 2, 'V15JA', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 3, 'V09JA', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 3, 'V15JA', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 4, 'V24', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 5, 'V24', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 8, 'V03', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 9, 'V03', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 9, 'V06', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 9, 'V09', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 9, 'V12', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 9, 'V15', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 9, 'V24', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 10, 'V03', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 10, 'V06', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 10, 'V09', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 10, 'V12', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 10, 'V15', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 10, 'V24', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 11, 'V03', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 11, 'V06', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 11, 'V12', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 0, 'Y', 'Visit', 11, 'V24', NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 420, 'Y', 'Visit', 1, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 420, 'Y', 'Visit', 2, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 420, 'Y', 'Visit', 3, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 420, 'Y', 'Visit', 4, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 420, 'Y', 'Visit', 5, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 0, 420, 'Y', 'Visit', 7, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 660, 780, 'Y', 'Visit', 1, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 660, 780, 'Y', 'Visit', 2, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 660, 780, 'Y', 'Visit', 3, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 660, 780, 'Y', 'Visit', 4, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 660, 780, 'Y', 'Visit', 5, NULL, NULL, NULL, NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order) VALUES('dtiprep', 660, 780, 'Y', 'Visit', 7, NULL, NULL, NULL, NULL);
