CREATE TABLE `tanner_girls_survey` (
`CommentID` varchar(255) NOT NULL default '',
`Date_taken` date,
`q1_height_growth` enum('a','b','c','d'),
`q2_body_hair_growth` enum('a','b','c','d'),
`q3_skin_changes` enum('a','b','c','d'),
`q4_breast_growth` enum('a','b','c','d'),
`q5_begun_to_menstruate` enum('n','y'),
`q5a_month` varchar(255),
`q5a_year` varchar(255),
`q5b_first_day_of_last_menstrual_period` date,
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
