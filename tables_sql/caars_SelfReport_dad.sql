CREATE TABLE `caars_SelfReport_dad` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`respondent_age` varchar(255) default NULL,
`respondent_gender` enum('male','female') default NULL,
`respondent` enum('mother','father','step_mother','step_father','other') default NULL,
`respondent_specify` varchar(255) default NULL,
`a_raw_score` varchar(255) default NULL,
`a_raw_percentile` varchar(255) default NULL,
`b_raw_score` varchar(255) default NULL,
`b_raw_percentile` varchar(255) default NULL,
`c_raw_score` varchar(255) default NULL,
`c_raw_percentile` varchar(255) default NULL,
`d_raw_score` varchar(255) default NULL,
`d_raw_percentile` varchar(255) default NULL,
`e_raw_score` varchar(255) default NULL,
`e_raw_percentile` varchar(255) default NULL,
`index_total_score` varchar(255) default NULL,
`index_total_percentile` varchar(255) default NULL,
`index_guide_score` varchar(255) default NULL,
`index_guide_percentile` varchar(255) default NULL,
`q1_interrupt_others_when_talking` enum('0','1','2','3') default NULL,
`q2_am_always_on_the_go_as_if` enum('0','1','2','3') default NULL,
`q3_am_disorganized` enum('0','1','2','3') default NULL,
`q4_hard_for_me_to_stay` enum('0','1','2','3') default NULL,
`q5_hard_for_me_to_keep_track` enum('0','1','2','3') default NULL,
`q6_am_bored_easily` enum('0','1','2','3') default NULL,
`q7_have_a_short_fuse` enum('0','1','2','3') default NULL,
`q8_still_throw_tantrums` enum('0','1','2','3') default NULL,
`q9_avoid_new_challenges` enum('0','1','2','3') default NULL,
`q10_seek_out_fast_paced` enum('0','1','2','3') default NULL,
`q11_feel_restless_inside` enum('0','1','2','3') default NULL,
`q12_things_I_hear_or_see` enum('0','1','2','3') default NULL,
`q13_many_things_set_me` enum('0','1','2','3') default NULL,
`q14_am_an_underachiever` enum('0','1','2','3') default NULL,
`q15_get_down_on_myself` enum('0','1','2','3') default NULL,
`q16_act_okay_on_the_outside` enum('0','1','2','3') default NULL,
`q17_cant_get_things_done` enum('0','1','2','3') default NULL,
`q18_have_trouble_getting` enum('0','1','2','3') default NULL,
`q19_intrude_on_others` enum('0','1','2','3') default NULL,
`q20_my_moods_are_unpredictable` enum('0','1','2','3') default NULL,
`q21_absent_minded_in_daily` enum('0','1','2','3') default NULL,
`q22_sometimes_my_attention` enum('0','1','2','3') default NULL,
`q23_tend_to_squirm_or` enum('0','1','2','3') default NULL,
`q24_cant_keep_my_mind_on` enum('0','1','2','3') default NULL,
`q25_wish_I_had_greater` enum('0','1','2','3') default NULL,
`q26_my_past_failures_make` enum('0','1','2','3') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('caars_SelfReport_dad', "CAARS–Self-Report Scale: Self Report Dad (Send to Dad)", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('caars_SelfReport_dad','caars_SelfReport_dad_page1', "Page 1", 1);

-- Fragile X at VSA and VSA-CVD
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_dad', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_dad', DEFAULT, 5, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_dad', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_dad', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_dad', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('caars_SelfReport_dad', DEFAULT, 7, 'VSA-CVD');
