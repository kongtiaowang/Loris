CREATE TABLE `Actigraph_Export` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`UserID` varchar(255) default NULL,
`Status` varchar(255) default NULL,
`File_type` varchar(255) default NULL,
`Data_dir` varchar(255) default NULL,
`File_name` varchar(255) default NULL,
`initials` varchar(255) default NULL,
`full_name` varchar(255) default NULL,
`street_address` varchar(255) default NULL,
`city_state_zip` varchar(255) default NULL,
`phone` varchar(255) default NULL,
`gender` varchar(255) default NULL,
`date_of_birth` varchar(255) default NULL,
`age_at_file_creation` varchar(255) default NULL,
`age_at_data_collection` varchar(255) default NULL,
`other_comments` text default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `test_names` (`Test_name`, `Full_name`, `Sub_group`) VALUES ('Actigraph_Export', 'Actigraph Export Summary Parser', '1');

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 21, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 1, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 2, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 3, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 9, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 10, 'VSA-Sleep', NULL);
