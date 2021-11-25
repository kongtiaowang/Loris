CREATE TABLE `tanner_girls_survey` (
`CommentID` varchar(255) NOT NULL default '',
`Date_taken` date,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`q1_height_growth` enum('a','b','c','d'),
`q2_body_hair_growth` enum('a','b','c','d'),
`q3_skin_changes` enum('a','b','c','d'),
`q4_breast_growth` enum('a','b','c','d'),
`q5_begun_to_menstruate` enum('n','y'),
`q5a_month` varchar(255),
`q5a_year` varchar(255),
`q5b_first_day_of_last_menstrual_period` date,
`tanner_score_girls` decimal(3,2),
`tanner_pubertal_stage_girls` enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal') default NULL,
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
