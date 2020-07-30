CREATE TABLE `tanner_boys_survey` (
`CommentID` varchar(255) NOT NULL default '',
`Date_taken` date,
`q1_height_growth` enum('a','b','c','d'),
`q2_body_hair_growth` enum('a','b','c','d'),
`q3_skin_changes` enum('a','b','c','d'),
`q4_voice_deepening` enum('a','b','c','d'),
`q5_grow_hair_on_face` enum('a','b','c','d'),
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
