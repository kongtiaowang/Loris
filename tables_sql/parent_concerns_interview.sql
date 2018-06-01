DROP TABLE IF EXISTS `parent_concerns_interview` ;
CREATE TABLE `parent_concerns_interview` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`q1_understanding` text default NULL,
`q1a_understanding_research` varchar(255) default NULL,
`q2_familiar_risk` text default NULL,
`q3_risk_effect` text default NULL,
`q4_worry` enum('yes','no','not_answered') default NULL,
`q4yes_worry` text default NULL,
`q4no_worry` text default NULL,
`q5_worry_affect_family` text default NULL,
`q6_initial_thoughts_v1` text default NULL,
`q7_past_visit_info` text default NULL,
`q8_initial_thoughts_v2` text default NULL,
`examiner_concern_rating` enum('1_no','2_little','3_high','4_very_high') default NULL,
`examiner_understanding_rating` enum('1_no','2_little','3_high','4_very_high') default NULL,
`examiner_coping_rating` enum('1_no','2_little','3_high','4_very_high') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

