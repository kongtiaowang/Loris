CREATE TABLE `mQST` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`protocol_reqr` enum('complete_protocol','partial_completed','no_protocol_completed','not_answered') default NULL,
`video_reqr` enum('2_angle_completed','1_angle_completed','no_video','not_answered') default NULL,
`attempted_0` enum('Y','N','not_answered') default NULL,
`terminated_0` enum('Y','N','not_answered') default NULL,
`participant_response_0` text default NULL,
`participant_response_0_status` enum('not_answered') default NULL,
`attempted_1` enum('Y','N','not_answered') default NULL,
`terminated_1` enum('Y','N','not_answered') default NULL,
`participant_response_1` text default NULL,
`participant_response_1_status` enum('not_answered') default NULL,
`attempted_2` enum('Y','N','not_answered') default NULL,
`terminated_2` enum('Y','N','not_answered') default NULL,
`participant_response_2` text default NULL,
`participant_response_2_status` enum('not_answered') default NULL,
`attempted_3` enum('Y','N','not_answered') default NULL,
`terminated_3` enum('Y','N','not_answered') default NULL,
`participant_response_3` text default NULL,
`participant_response_3_status` enum('not_answered') default NULL,
`attempted_4` enum('Y','N','not_answered') default NULL,
`terminated_4` enum('Y','N','not_answered') default NULL,
`participant_response_4` text default NULL,
`participant_response_4_status` enum('not_answered') default NULL,
`attempted_5` enum('Y','N','not_answered') default NULL,
`terminated_5` enum('Y','N','not_answered') default NULL,
`participant_response_5` text default NULL,
`participant_response_5_status` enum('not_answered') default NULL,
`attempted_6` enum('Y','N','not_answered') default NULL,
`terminated_6` enum('Y','N','not_answered') default NULL,
`participant_response_6` text default NULL,
`participant_response_6_status` enum('not_answered') default NULL,
`parent_presence` enum('Y','N','not_answered') default NULL,
`general_comments` text default NULL,
`general_comments_status` enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('mQST', "mQST Tracking Form", 1, 0);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('mQST ', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);