CREATE TABLE `fyi_survey` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`mother_ethnicity` varchar(255) default NULL,
`mother_highest_grade` enum('not_answered','j_high','some_hs','high_school','some_college','college_degree','some_grad_level','grad_degree') default NULL,
`father_ethnicity` varchar(255) default NULL,
`father_highest_grade` enum('not_answered','j_high','some_hs','high_school','some_college','college_degree','some_grad_level','grad_degree') default NULL,
`person_filling_out` enum('mother','father','both','other','not_answered') default NULL,
`person_filling_out_specify` varchar(255) default NULL,
`person_filling_out_specify_status` enum('not_answered') default NULL,
`risk_score` varchar(255) default NULL,
`percentile` varchar(255) default NULL,
`soc_com_risk` varchar(255) default NULL,
`sen_reg_risk` varchar(255) default NULL,
`orientrec` varchar(255) default NULL,
`affeng` varchar(255) default NULL,
`imitate` varchar(255) default NULL,
`express` varchar(255) default NULL,
`senproc` varchar(255) default NULL,
`regpat` varchar(255) default NULL,
`react` varchar(255) default NULL,
`repplay` varchar(255) default NULL,
`q_1` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_2` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_3` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_4` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_5` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_6` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_7` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_8` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_9` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_10` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_11` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_12` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_13` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_14` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_15` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_16` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_17` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_18` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_19` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_20` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_21` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_22` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_23` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_24` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_25` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_26` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_27` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_28` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_29` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_30` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_31` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_32` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_33` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_34` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_35` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_36` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_37` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_38` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_39` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_40` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_41` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_42` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_43` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_44` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_45` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_46` enum('never','seldom','sometimes','often','not_answered') default NULL,
`q_47` enum('a_same_way','b_new_way','c_often_explores','not_answered') default NULL,
`q_48` enum('a_one_or_two','b_small_number','c_large_number','not_answered') default NULL,
`q_49` enum('a_joins_in_immediately','b_usually_joins_in','c_joins_in_only_with_a_lot','d_doesn_t_seem_interested','not_answered') default NULL,
`q_50` enum('a_show_different_toy','b_move_shake_make_noise','c_take_favourite','not_answered') default NULL,
`q_51` enum('a_doesn_t_notice','b_reacts_a_little','c_sensitive_or_cries','not_answered') default NULL,
`q_52` enum('a_say_name','b_say_name_several','c_say_name_loudly','d_doesn_t_do','not_answered') default NULL,
`q_53` enum('a_smiling_laughing','b_touch_tickle','c_swing_bounce','d_doesn_t_do','not_answered') default NULL,
`q_54` enum('a_12_or_more','b_10_11','c_8_9','d_7_or_fewer','not_answered') default NULL,
`q_55` enum('a_0','b_1_2','c_3_or_more','not_answered') default NULL,
`q_56` enum('a_walks_independently','b_walks_with_hands','c_pulls_up_to_stand','d_does_not_pull','not_answered') default NULL,
`q_57` enum('a_never_gets_upset','b_upset_calmed_1_3','c_upset_calmed_4_6','d_upset_calmed_6_or_more','not_answered') default NULL,
`q_58` enum('a_doesn_t_notice_sound','b_looks_but_doesn_t_make','c_looks_and_makes','d_plays_making','not_answered') default NULL,
`q_59` enum('a_almost_never','b_sometimes','c_often','d_almost_always','not_answered') default NULL,
`q_60` enum('a_almost_always','b_sometimes','c_rarely','d_almost_never','not_answered') default NULL,
`sounds_p` varchar(255) default NULL,
`sounds_b` varchar(255) default NULL,
`sounds_t` varchar(255) default NULL,
`sounds_d` varchar(255) default NULL,
`sounds_k` varchar(255) default NULL,
`sounds_g` varchar(255) default NULL,
`sounds_m` varchar(255) default NULL,
`sounds_n` varchar(255) default NULL,
`sounds_w` varchar(255) default NULL,
`sounds_y` varchar(255) default NULL,
`sounds_h` varchar(255) default NULL,
`sounds_s` varchar(255) default NULL,
`q_62` text default NULL,
`q_62_status` enum('not_answered') default NULL,
`q_63` text default NULL,
`q_63_status` enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Meta
INSERT INTO test_names(Test_name, Full_name, Sub_Group, IsDirectEntry) VALUES('fyi_survey', 'First Year Inventory - Survey Version', '13', '1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number)  VALUES('fyi_survey', 'fyi_survey_page1', '#1-#46', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number)  VALUES('fyi_survey', 'fyi_survey_page2', '#47-#63', 2);