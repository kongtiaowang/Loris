CREATE TABLE `NIHToolBox_Assessment_Scores` (
`CommentID` varchar(100) NOT NULL default '',

                            `UserID` TEXT default NULL,

                            `Examiner` TEXT default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` TEXT default NULL,
`Window_Difference` TEXT default NULL,
`Uploaded_Assessment_Scores` TEXT default NULL,
`DeviceID_1` TEXT default NULL,
`AssessmentName_1` TEXT default NULL,
`Inst_1` TEXT default NULL,
`RawScore_1` TEXT default NULL,
`Theta_1` TEXT default NULL,
`TScore_1` TEXT default NULL,
`SE_1` TEXT default NULL,
`ItmCnt_1` TEXT default NULL,
`DateFinished_1` TEXT default NULL,
`Column1_1` TEXT default NULL,
`Column2_1` TEXT default NULL,
`Column3_1` TEXT default NULL,
`Column4_1` TEXT default NULL,
`Column5_1` TEXT default NULL,
`Language_1` TEXT default NULL,
`ComputedScore_1` TEXT default NULL,
`Uncorrected_Standard_Score_1` TEXT default NULL,
`Age_Corrected_Standard_Score_1` TEXT default NULL,
`National_Percentile_1` TEXT default NULL,
`Fully_Corrected_T_score_1` TEXT default NULL,
`InstrumentBreakoff_1` TEXT default NULL,
`InstrumentStatus2_1` TEXT default NULL,
`InstrumentRCReason_1` TEXT default NULL,
`InstrumentRCReasonOther_1` TEXT default NULL,
`App_Version_1` TEXT default NULL,
`iPad_Version_1` TEXT default NULL,
`Firmware_Version_1` TEXT default NULL,
`No._2` TEXT default NULL,
`DeviceID_2` TEXT default NULL,
`AssessmentName_2` TEXT default NULL,
`Inst_2` TEXT default NULL,
`RawScore_2` TEXT default NULL,
`Theta_2` TEXT default NULL,
`TScore_2` TEXT default NULL,
`SE_2` TEXT default NULL,
`ItmCnt_2` TEXT default NULL,
`DateFinished_2` TEXT default NULL,
`Column1_2` TEXT default NULL,
`Column2_2` TEXT default NULL,
`Column3_2` TEXT default NULL,
`Column4_2` TEXT default NULL,
`Column5_2` TEXT default NULL,
`Language_2` TEXT default NULL,
`ComputedScore_2` TEXT default NULL,
`Uncorrected_Standard_Score_2` TEXT default NULL,
`Age_Corrected_Standard_Score_2` TEXT default NULL,
`National_Percentile_2` TEXT default NULL,
`Fully_Corrected_T_score_2` TEXT default NULL,
`InstrumentBreakoff_2` TEXT default NULL,
`InstrumentStatus2_2` TEXT default NULL,
`InstrumentRCReason_2` TEXT default NULL,
`InstrumentRCReasonOther_2` TEXT default NULL,
`App_Version_2` TEXT default NULL,
`iPad_Version_2` TEXT default NULL,
`Firmware_Version_2` TEXT default NULL,
`Data_dir_assessment` TEXT default NULL,
  `File_type` varchar(25) DEFAULT NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- META
INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('NIHToolBox_Assessment_Scores', 'NIH ToolBox Assessment Scores', '1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('NIHToolBox_Assessment_Scores', 'NIHToolBox_Assessment_Scores_page1', "Page 1", 1);
-- adding to test battery
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('NIHToolBox_Assessment_Scores', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);