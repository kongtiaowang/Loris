CREATE TABLE `DAS_SA` (
`CommentID` varchar(90) NOT NULL default '',

                            `UserID` varchar(90) default NULL,

                            `Examiner` varchar(90) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(90) default NULL,
`Window_Difference` varchar(90) default NULL,
`File_name` varchar(90) default NULL,
`File_type` varchar(90) default NULL,
`Status` varchar(90) default NULL,
`Data_dir` varchar(90) default NULL,
`verbal_T_Score` varchar(90) default NULL,
`verbal_STD_SCORE` varchar(90) default NULL,
`verbal_PERCENTILE` varchar(90) default NULL,
`verbal_CI` varchar(90) default NULL,
`verbal_QD` varchar(90) default NULL,
`spatial_T_Score` varchar(90) default NULL,
`spatial_STD_SCORE` varchar(90) default NULL,
`spatial_PERCENTILE` varchar(90) default NULL,
`spatial_CI` varchar(90) default NULL,
`spatial_QD` varchar(90) default NULL,
`non_verb_reasoning_T_Score` varchar(90) default NULL,
`non_verb_reasoning_STD_SCORE` varchar(90) default NULL,
`non_verb_reasoning_PERCENTILE` varchar(90) default NULL,
`non_verb_reasoning_CI` varchar(90) default NULL,
`non_verb_reasoning_QD` varchar(90) default NULL,
`GCA_T_Score` varchar(90) default NULL,
`GCA_STD_SCORE` varchar(90) default NULL,
`GCA_PERCENTILE` varchar(90) default NULL,
`GCA_CI` varchar(90) default NULL,
`GCA_QD` varchar(90) default NULL,
`SNC_T_Score` varchar(90) default NULL,
`SNC_STD_SCORE` varchar(90) default NULL,
`SNC_PERCENTILE` varchar(90) default NULL,
`SNC_CI` varchar(90) default NULL,
`SNC_QD` varchar(90) default NULL,
`verbal_similarities_RAW` varchar(90) default NULL,
`verbal_similarities_ITEM_SET` varchar(90) default NULL,
`verbal_similarities_ABILITY_SCORE` varchar(90) default NULL,
`verbal_similarities_T_SCORE` varchar(90) default NULL,
`verbal_similarities_PERCENTILE` varchar(90) default NULL,
`verbal_similarities_AGE_EQUIV` varchar(90) default NULL,
`word_defn_RAW` varchar(90) default NULL,
`word_defn_ITEM_SET` varchar(90) default NULL,
`word_defn_ABILITY_SCORE` varchar(90) default NULL,
`word_defn_T_SCORE` varchar(90) default NULL,
`word_defn_PERCENTILE` varchar(90) default NULL,
`word_defn_AGE_EQUIV` varchar(90) default NULL,
`matrices_RAW` varchar(90) default NULL,
`matrices_ITEM_SET` varchar(90) default NULL,
`matrices_ABILITY_SCORE` varchar(90) default NULL,
`matrices_T_SCORE` varchar(90) default NULL,
`matrices_PERCENTILE` varchar(90) default NULL,
`matrices_AGE_EQUIV` varchar(90) default NULL,
`seq_qr_RAW` varchar(90) default NULL,
`seq_qr_ITEM_SET` varchar(90) default NULL,
`seq_qr_ABILITY_SCORE` varchar(90) default NULL,
`seq_qr_T_SCORE` varchar(90) default NULL,
`seq_qr_PERCENTILE` varchar(90) default NULL,
`seq_qr_AGE_EQUIV` varchar(90) default NULL,
`rd_RAW` varchar(90) default NULL,
`rd_ITEM_SET` varchar(90) default NULL,
`rd_ABILITY_SCORE` varchar(90) default NULL,
`rd_T_SCORE` varchar(90) default NULL,
`rd_PERCENTILE` varchar(90) default NULL,
`rd_AGE_EQUIV` varchar(90) default NULL,
`PC_RAW` varchar(90) default NULL,
`PC_ITEM_SET` varchar(90) default NULL,
`PC_ABILITY_SCORE` varchar(90) default NULL,
`PC_T_SCORE` varchar(90) default NULL,
`PC_PERCENTILE` varchar(90) default NULL,
`PC_AGE_EQUIV` varchar(90) default NULL,
`other_comments` text default NULL,
PRIMARY KEY  (`CommentID`)
              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
              INSERT INTO `test_names` (`Test_name`, `Full_name`, `Sub_group`) VALUES ('DAS_SA', 'DAS (Differential Ability Scales) - School-Age Core ', '1');
-- Adding to test battery
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DAS_SA', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);
-- Removing old das from test battery
UPDATE `test_battery` SET `Active`='N' WHERE Test_name='das_schoolage';

