CREATE TABLE `Infant_social_motivation` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`filling_out_form` enum('mother','father','step_mother','step_father','other') default NULL,
`other_filling_out_form` varchar(255) default NULL,
`q1` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q2` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q3` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q4` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q5` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q6` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q7` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q8` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q9` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q10` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q11` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q12` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q13` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q14` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q15` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q16` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q17` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q18` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q19` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q20` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q21` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q22` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q23` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q24` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q25` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q26` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q27` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q28` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q29` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q30` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q31` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q32` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q33` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q34` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q35` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q36` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q37` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q38` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q39` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q40` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q41` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q42` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q43` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q44` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q45` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q46` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q47` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q48` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q49` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
`q50` enum('not_true','sometimes_true','often_true','almost_always_true','not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Meta Files
INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('Infant_social_motivation', "Infant Social Motivation Questionnaire", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Infant_social_motivation','Infant_social_motivation_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Infant_social_motivation','Infant_social_motivation_page2', "Page 2", 2);


-- Infant_social_motivation to IBIS EP HR, IBIS EP LR, DS Infant at  V12, V06
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Infant_social_motivation', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Infant_social_motivation', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Infant_social_motivation', '0', '0', 'Y', 'Visit', 19, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Infant_social_motivation', '0', '0', 'Y', 'Visit', 19, 'V06', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Infant_social_motivation', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Infant_social_motivation', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);