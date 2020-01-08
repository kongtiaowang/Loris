CREATE TABLE `BISQ` (
`CommentID` varchar(100) NOT NULL default '',

                            `UserID` varchar(100) default NULL,

                            `Examiner` varchar(100) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(100) default NULL,
`Window_Difference` varchar(100) default NULL,
`responder` enum('mother','father','step_mother','step_father','other') default NULL,
`other_responder` varchar(100) default NULL,
`birth_order` enum('oldest','middle','youngest','step_father') default NULL,
`sleeping_arrangement` enum('infant_crib_seperate_room','infant_crib_parent_room','parents_bed','infant_crib_in_room_with_sibling','other') default NULL,
`other_sleeping_arrangement` varchar(100) default NULL,
`sleep_position` enum('belly','side','back','not_answered') default NULL,
`night_sleep` time default NULL,
`night_sleep_status` enum('dnk','refusal','not_answered') default NULL,
`day_sleep` time default NULL,
`day_sleep_status` enum('dnk','refusal','not_answered') default NULL,
`night_wakes_average_count` varchar(100) default NULL,
`night_wakes_average_count_status` enum('not_answered') default NULL,
`night_wakefullness` time default NULL,
`night_wakefullness_status` enum('dnk','refusal','not_answered') default NULL,
`time_to_put_to_sleep` time default NULL,
`time_to_put_to_sleep_status` enum('dnk','refusal','not_answered') default NULL,
`sleep_opts` enum('while_feeding','being_rocked','bed_alone','bed_near_parent','not_answered') default NULL,
`when_fall_asleep` time default NULL,
`when_fall_asleep_status` enum('dnk','refusal','not_answered') default NULL,
`is_sleep_problem` enum('belly','side','back','not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('BISQ', 'Brief Infant Sleep Questionnaire (BISQ)', '1');

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 19, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 19, 'V24', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('BISQ', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
