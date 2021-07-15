CREATE TABLE `scq_fxs_subject_survey` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`relationship_to_child` enum('mother','father','step_mother','step_father','other') default NULL,
`other_relationship_to_child` varchar(255) default NULL,
`score` varchar(255) default NULL,
`scq_diagnosis` varchar(255) default NULL,
`q1_talk_short_phrases` enum('yes','no') default NULL,
`q2_to_and_fro` enum('yes','no') default NULL,
`q3_odd_phrases` enum('yes','no') default NULL,
`q4_socially_inappropriate` enum('yes','no') default NULL,
`q5_pronouns_mixed` enum('yes','no') default NULL,
`q6_words_invented` enum('yes','no') default NULL,
`q7_said_same_thing` enum('yes','no') default NULL,
`q8_particular_way` enum('yes','no') default NULL,
`q9_facial_expressions` enum('yes','no') default NULL,
`q10_hand_like_tool` enum('yes','no') default NULL,
`q11_interests_that_preoccupy` enum('yes','no') default NULL,
`q12_interested_in_parts` enum('yes','no') default NULL,
`q13_intense_interests` enum('yes','no') default NULL,
`q14_sight_feel_sound` enum('yes','no') default NULL,
`q15_mannerisms` enum('yes','no') default NULL,
`q16_complicated_movements` enum('yes','no') default NULL,
`q17_deliberate_injury` enum('yes','no') default NULL,
`q18_carry_objects` enum('yes','no') default NULL,
`q19_particular_friends` enum('yes','no') default NULL,
`q20_talk_friendly` enum('yes','no') default NULL,
`q21_spontaneously_copy` enum('yes','no') default NULL,
`q22_spontaneously_point` enum('yes','no') default NULL,
`q23_gestures` enum('yes','no') default NULL,
`q24_nod_yes` enum('yes','no') default NULL,
`q25_shake_no` enum('yes','no') default NULL,
`q26_look_directly` enum('yes','no') default NULL,
`q27_smile_back` enum('yes','no') default NULL,
`q28_show_things` enum('yes','no') default NULL,
`q29_offer_share` enum('yes','no') default NULL,
`q30_join_enjoyment` enum('yes','no') default NULL,
`q31_comfort` enum('yes','no') default NULL,
`q32_wanted_something` enum('yes','no') default NULL,
`q33_facial_expressions` enum('yes','no') default NULL,
`q34_spontaneously_join` enum('yes','no') default NULL,
`q35_play_pretend` enum('yes','no') default NULL,
`q36_seem_interested` enum('yes','no') default NULL,
`q37_respond_positively` enum('yes','no') default NULL,
`q38_came_into_room` enum('yes','no') default NULL,
`q39_play_imaginative` enum('yes','no') default NULL,
`q40_play_cooperatively` enum('yes','no') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('scq_fxs_subject_survey', "SCQ (Social Communication Questionnaire) - FXS Subject - Survey", 9, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('scq_fxs_subject_survey','scq_fxs_subject_survey_page1', "Page 1", 1);


INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('scq_fxs_subject_survey', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('scq_fxs_subject_survey', DEFAULT, 5, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('scq_fxs_subject_survey', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('scq_fxs_subject_survey', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('scq_fxs_subject_survey', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('scq_fxs_subject_survey', DEFAULT, 7, 'VSA-CVD');
