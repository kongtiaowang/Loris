CREATE TABLE `WIAT_III_SA` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `UserID` varchar(255) DEFAULT NULL,
  `Examiner` varchar(255) DEFAULT NULL,
  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `Date_taken` date DEFAULT NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` varchar(255) DEFAULT NULL,
  `File_name` varchar(255) DEFAULT NULL,
  `RC_RAW` varchar(255) DEFAULT NULL,
  `RC_STD_SCORE` varchar(255) DEFAULT NULL,
  `RC_CI` varchar(255) DEFAULT NULL,
  `RC_PER_RANK` varchar(255) DEFAULT NULL,
  `RC_NCE` varchar(255) DEFAULT NULL,
  `RC_STANINE` varchar(255) DEFAULT NULL,
  `RC_GRADE_EQUIV` varchar(255) DEFAULT NULL,
  `RC_AGE_EQUIV` varchar(255) DEFAULT NULL,
  `MPS_RAW` varchar(255) DEFAULT NULL,
  `MPS_STD_SCORE` varchar(255) DEFAULT NULL,
  `MPS_CI` varchar(255) DEFAULT NULL,
  `MPS_PER_RANK` varchar(255) DEFAULT NULL,
  `MPS_NCE` varchar(255) DEFAULT NULL,
  `MPS_STANINE` varchar(255) DEFAULT NULL,
  `MPS_GRADE_EQUIV` varchar(255) DEFAULT NULL,
  `MPS_AGE_EQUIV` varchar(255) DEFAULT NULL,
  `WR_RAW` varchar(255) DEFAULT NULL,
  `WR_STD_SCORE` varchar(255) DEFAULT NULL,
  `WR_CI` varchar(255) DEFAULT NULL,
  `WR_PER_RANK` varchar(255) DEFAULT NULL,
  `WR_NCE` varchar(255) DEFAULT NULL,
  `WR_STANINE` varchar(255) DEFAULT NULL,
  `WR_GRADE_EQUIV` varchar(255) DEFAULT NULL,
  `WR_AGE_EQUIV` varchar(255) DEFAULT NULL,
  `PD_RAW` varchar(255) DEFAULT NULL,
  `PD_STD_SCORE` varchar(255) DEFAULT NULL,
  `PD_CI` varchar(255) DEFAULT NULL,
  `PD_PER_RANK` varchar(255) DEFAULT NULL,
  `PD_NCE` varchar(255) DEFAULT NULL,
  `PD_STANINE` varchar(255) DEFAULT NULL,
  `PD_GRADE_EQUIV` varchar(255) DEFAULT NULL,
  `PD_AGE_EQUIV` varchar(255) DEFAULT NULL,
  `NO_RAW` varchar(255) DEFAULT NULL,
  `NO_STD_SCORE` varchar(255) DEFAULT NULL,
  `NO_CI` varchar(255) DEFAULT NULL,
  `NO_PER_RANK` varchar(255) DEFAULT NULL,
  `NO_NCE` varchar(255) DEFAULT NULL,
  `NO_STANINE` varchar(255) DEFAULT NULL,
  `NO_GRADE_EQUIV` varchar(255) DEFAULT NULL,
  `NO_AGE_EQUIV` varchar(255) DEFAULT NULL,
  `other_comments` text,
  `Status` varchar(45) DEFAULT NULL,
  `Data_dir` varchar(100) DEFAULT NULL,
  `File_type` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
   ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO `test_names` (`Test_name`, `Full_name`, `Sub_group`) VALUES ('WIAT_III_SA', 'WIAT-III (School Age) ', '1');
-- Adding to test battery
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('WIAT_III_SA', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);
-- Removing old wiat instruments from test battery
UPDATE `test_battery` SET `Active`='N' WHERE Test_name='wiat_III_part_1';
UPDATE `test_battery` SET `Active`='N' WHERE Test_name='wiat_III_part_2';
UPDATE `test_battery` SET `Active`='N' WHERE Test_name='WiatIII';


