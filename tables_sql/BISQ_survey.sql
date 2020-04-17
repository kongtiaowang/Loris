CREATE TABLE `BISQ_survey` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`responder` enum('mother','father','step_mother','step_father','other') default NULL,
`other_responder` varchar(255) default NULL,
`birth_order` enum('oldest','middle','youngest','step_father') default NULL,
`sleeping_arrangement` enum('infant_crib_seperate_room','infant_crib_parent_room','parents_bed','infant_crib_in_room_with_sibling','other') default NULL,
`other_sleeping_arrangement` varchar(255) default NULL,
`sleep_position` enum('belly','side','back','not_answered') default NULL,
`night_sleep_hours` varchar(10)default NULL,
`night_sleep_mins` varchar(10) default NULL,
`night_sleep_status` enum('dnk','refusal','not_answered') default NULL,
`day_sleep_hours` varchar(10) default NULL,
`day_sleep_mins` varchar(10) default NULL,
`day_sleep_status` enum('dnk','refusal','not_answered') default NULL,
`night_wakes_average_count` varchar(255) default NULL,
`night_wakes_average_count_status` enum('not_answered') default NULL,
`night_wakefullness_hours` varchar(10) default NULL,
`night_wakefullness_mins` varchar(10) default NULL,
`night_wakefullness_status` enum('dnk','refusal','not_answered') default NULL,
`time_to_put_to_sleep_hours` varchar(10) default NULL,
`time_to_put_to_sleep_mins`varchar(10) default NULL,
`time_to_put_to_sleep_status` enum('dnk','refusal','not_answered') default NULL,
`sleep_opts` enum('while_feeding','being_rocked','bed_alone','bed_near_parent','not_answered') default NULL,
`when_fall_asleep_hours` varchar(10) default NULL,
`when_fall_asleep_mins` varchar(10) default NULL,
`when_fall_asleep_status` enum('dnk','refusal','not_answered') default NULL,
`is_sleep_problem` enum('belly','side','back','not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Meta
INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('BISQ_survey', 'Brief Infant Sleep Questionnaire (BISQ - Survey Version)', '1','1');