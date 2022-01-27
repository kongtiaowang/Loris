CREATE TABLE `med_records_SA` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`child_birth_length` varchar(255) default NULL,
`child_birth_length_status` enum('not_answered') default NULL,
`child_birth_weight` varchar(255) default NULL,
`child_birth_weight_status` enum('not_answered') default NULL,
`head_circum` varchar(255) default NULL,
`head_circum_status` enum('not_answered') default NULL,
`gest_age_weeks` varchar(255) default NULL,
`gest_age_weeks_status` enum('not_answered') default NULL,
`gest_age_months` varchar(255) default NULL,
`gest_age_months_status` enum('not_answered') default NULL,
`apgar_1_minute` varchar(255) default NULL,
`apgar_1_minute_status` enum('not_answered') default NULL,
`apgar_5_minute` varchar(255) default NULL,
`apgar_5_minute_status` enum('not_answered') default NULL,
`mode_of_delivery` enum("vaginal","vaginal_with_forceps","vaginal_with_vacuum","c_section","nr") default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
              INSERT INTO `test_names` (`Test_name`, `Full_name`, `Sub_group`) VALUES ('med_records_SA', 'Medical Records Form -School Age ', '1');
-- Adding to test battery
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('med_records_SA', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);

