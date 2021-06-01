CREATE TABLE `TANNER_Boys` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`q1_height_growth` enum('a','b','c','d') default NULL,
`q2_body_hair_growth` enum('a','b','c','d') default NULL,
`q3_skin_changes` enum('a','b','c','d') default NULL,
`q4_voice_deepening` enum('a','b','c','d') default NULL,
`q5_grow_hair_on_face` enum('a','b','c','d') default NULL,
`tanner_score_boys` decimal(3,2) default NULL,
`tanner_pubertal_stage_boys` enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal') default NULL
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
