CREATE TABLE `Infant_social_motivation_survey` (
`CommentID` varchar(255) NOT NULL default '',
`UserID` varchar(255),
`Examiner` varchar(255),
`Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
`Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date,
`Candidate_Age` varchar(255),
`Window_Difference` varchar(255),
`filling_out_form` enum('mother','father','step_mother','step_father','other'),
`other_filling_out_form` varchar(255),
`q1` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q2` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q3` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q4` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q5` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q6` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q7` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q8` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q9` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q10` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q11` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q12` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q13` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q14` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q15` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q16` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q17` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q18` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q19` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q20` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q21` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q22` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q23` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q24` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q25` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q26` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q27` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q28` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q29` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q30` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q31` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q32` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q33` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q34` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q35` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q36` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q37` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q38` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q39` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q40` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q41` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q42` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q43` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q44` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q45` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q46` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q47` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q48` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
`q49` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered'),
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Meta
INSERT INTO test_names(Test_name, Full_name, Sub_Group, IsDirectEntry) VALUES('Infant_social_motivation_survey', "Infant Social Motivation Questionnaire - Survey", 13,1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Infant_social_motivation_survey','Infant_social_motivation_survey_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Infant_social_motivation_survey','Infant_social_motivation_survey_page2', "Page 2", 2);
