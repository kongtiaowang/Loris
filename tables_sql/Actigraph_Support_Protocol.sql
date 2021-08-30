CREATE TABLE `Actigraph_Support_Protocol` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`level1` varchar(255) default NULL,
`level2` varchar(255) default NULL,
`level3` varchar(255) default NULL,
`level4` varchar(255) default NULL,
`level5` varchar(255) default NULL,
`not_answered` varchar(255) default NULL,
`my_child_tolerates_wearing_watches` enum('1','2','3','4','5') default NULL,
`my_child_has_difficulty_with_extra` enum('1','2','3','4','5') default NULL,
`my_child_has_difficulty_with_tags` enum('1','2','3','4','5') default NULL,
`my_child_struggles_with_change` enum('1','2','3','4','5') default NULL,
`my_child_tolerates_change_better` enum('1','2','3','4','5') default NULL,
`my_child_tolerates_when_i_can_tell` enum('1','2','3','4','5') default NULL,
`my_child_tolerates_learns_new_skills` enum('1','2','3','4','5') default NULL,
`my_child_responds_well_to_reinforcement` enum('1','2','3','4','5') default NULL,
`my_child_needs_reminders_about_what` enum('1','2','3','4','5') default NULL,
`my_child_responds_well_to_visual_reminders` enum('1','2','3','4','5') default NULL,
`my_child_responds_well_to_social_stories` enum('1','2','3','4','5') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `test_names` (`Test_name`, `Full_name`, `Sub_group`) VALUES ('Actigraph_Support_Protocol', 'Actigraph Support Protocol', '1');

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Support_Protocol', '0', '0', 'Y', 'Visit', 1, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Support_Protocol', '0', '0', 'Y', 'Visit', 2, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Support_Protocol', '0', '0', 'Y', 'Visit', 3, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Support_Protocol', '0', '0', 'Y', 'Visit', 9, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Support_Protocol', '0', '0', 'Y', 'Visit', 10, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Support_Protocol', '0', '0', 'Y', 'Visit', 21, 'VSA-Sleep', NULL);
