CREATE TABLE `tanner_boys_survey` (
`CommentID` varchar(255) NOT NULL default '',
`Date_taken` date,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`q1_height_growth` enum('a','b','c','d'),
`q2_body_hair_growth` enum('a','b','c','d'),
`q3_skin_changes` enum('a','b','c','d'),
`q4_voice_deepening` enum('a','b','c','d'),
`q5_grow_hair_on_face` enum('a','b','c','d'),
`tanner_score_boys` decimal(3,2),
`tanner_pubertal_stage_boys` enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal'),
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
