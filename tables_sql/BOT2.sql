CREATE TABLE `BOT2` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`preferred_drawing_hand` enum('right','left') default NULL,
`preferred_throwing_hand_arm` enum('right','left') default NULL,
`preferred_foot_leg` enum('right','left') default NULL,
`examinee_school` text,
`subtest_1_1_raw_score` text,
`subtest_1_1_point_score` text,
`subtest_1_2_raw_score` text,
`subtest_1_2_point_score` text,
`subtest_1_3_raw_score` text,
`subtest_1_3_point_score` text,
`subtest_1_4_raw_score` text,
`subtest_1_4_point_score` text,
`subtest_1_5_raw_score` text,
`subtest_1_5_point_score` text,
`subtest_1_6_raw_score` text,
`subtest_1_6_point_score` text,
`subtest_1_7_raw_score` text,
`subtest_1_7_point_score` text,
`subtest_2_1_basic_shape` enum('0','1') default NULL,
`subtest_2_1_closure` enum('0','1') default NULL,
`subtest_2_1_edges` enum('0','1') default NULL,
`subtest_2_1_overall_size` enum('0','1') default NULL,
`subtest_2_1_raw_score` text,
`subtest_2_1_point_score` text,
`subtest_2_2_basic_shape` enum('0','1') default NULL,
`subtest_2_2_closure` enum('0','1') default NULL,
`subtest_2_2_edges` enum('0','1') default NULL,
`subtest_2_2_orientation` enum('0','1') default NULL,
`subtest_2_2_overall_size` enum('0','1') default NULL,
`subtest_2_2_raw_score` text,
`subtest_2_2_point_score` text,
`subtest_2_3_basic_shape` enum('0','1') default NULL,
`subtest_2_3_closure` enum('0','1') default NULL,
`subtest_2_3_edges` enum('0','1') default NULL,
`subtest_2_3_orientation` enum('0','1') default NULL,
`subtest_2_3_overlap` enum('0','1') default NULL,
`subtest_2_3_overall_size` enum('0','1') default NULL,
`subtest_2_3_raw_score` text,
`subtest_2_3_point_score` text,
`subtest_2_4_basic_shape` enum('0','1') default NULL,
`subtest_2_4_edges` enum('0','1') default NULL,
`subtest_2_4_orientation` enum('0','1') default NULL,
`subtest_2_4_overall_size` enum('0','1') default NULL,
`subtest_2_4_raw_score` text,
`subtest_2_4_point_score` text,
`subtest_2_5_basic_shape` enum('0','1') default NULL,
`subtest_2_5_closure` enum('0','1') default NULL,
`subtest_2_5_edges` enum('0','1') default NULL,
`subtest_2_5_orientation` enum('0','1') default NULL,
`subtest_2_5_overall_size` enum('0','1') default NULL,
`subtest_2_5_raw_score` text,
`subtest_2_5_point_score` text,
`subtest_2_6_basic_shape` enum('0','1') default NULL,
`subtest_2_6_closure` enum('0','1') default NULL,
`subtest_2_6_edges` enum('0','1') default NULL,
`subtest_2_6_orientation` enum('0','1') default NULL,
`subtest_2_6_overall_size` enum('0','1') default NULL,
`subtest_2_6_raw_score` text,
`subtest_2_6_point_score` text,
`subtest_2_7_basic_shape` enum('0','1') default NULL,
`subtest_2_7_closure` enum('0','1') default NULL,
`subtest_2_7_edges` enum('0','1') default NULL,
`subtest_2_7_orientation` enum('0','1') default NULL,
`subtest_2_7_overall_size` enum('0','1') default NULL,
`subtest_2_7_raw_score` text,
`subtest_2_7_point_score` text,
`subtest_2_8_basic_shape` enum('0','1') default NULL,
`subtest_2_8_closure` enum('0','1') default NULL,
`subtest_2_8_edges` enum('0','1') default NULL,
`subtest_2_8_orientation` enum('0','1') default NULL,
`subtest_2_8_overlap` enum('0','1') default NULL,
`subtest_2_8_overall_size` enum('0','1') default NULL,
`subtest_2_8_raw_score` text,
`subtest_2_8_point_score` text,
`subtest_3_1_trial1` text,
`subtest_3_1_point_score` text,
`subtest_3_2_trial1` text,
`subtest_3_2_trial2` text,
`subtest_3_2_point_score` text,
`subtest_3_3_trial1` text,
`subtest_3_3_trial2` text,
`subtest_3_3_point_score` text,
`subtest_3_4_trial1` text,
`subtest_3_4_trial2` text,
`subtest_3_4_point_score` text,
`subtest_3_5_trial1` text,
`subtest_3_5_trial2` text,
`subtest_3_5_point_score` text,
`subtest_4_1_trial1` text,
`subtest_4_1_trial2` text,
`subtest_4_1_point_score` text,
`subtest_4_2_trial1` text,
`subtest_4_2_trial2` text,
`subtest_4_2_point_score` text,
`subtest_4_3_trial1` text,
`subtest_4_3_trial2` text,
`subtest_4_3_point_score` text,
`subtest_4_4_trial1` text,
`subtest_4_4_trial2` text,
`subtest_4_4_point_score` text,
`subtest_4_5_trial1` text,
`subtest_4_5_trial2` text,
`subtest_4_5_point_score` text,
`subtest_4_6_trial1` text,
`subtest_4_6_trial2` text,
`subtest_4_6_point_score` text,
`subtest_4_7_trial1` text,
`subtest_4_7_trial2` text,
`subtest_4_7_point_score` text,
`subtest_5_1_trial1` text,
`subtest_5_1_trial2` text,
`subtest_5_1_point_score` text,
`subtest_5_2_trial1` text,
`subtest_5_2_trial2` text,
`subtest_5_2_point_score` text,
`subtest_5_3_trial1` text,
`subtest_5_3_trial2` text,
`subtest_5_3_point_score` text,
`subtest_5_4_trial1` text,
`subtest_5_4_trial2` text,
`subtest_5_4_point_score` text,
`subtest_5_5_trial1` text,
`subtest_5_5_trial2` text,
`subtest_5_5_point_score` text,
`subtest_5_6_trial1` text,
`subtest_5_6_trial2` text,
`subtest_5_6_point_score` text,
`subtest_5_7_trial1` text,
`subtest_5_7_trial2` text,
`subtest_5_7_point_score` text,
`subtest_5_8_trial1` text,
`subtest_5_8_trial2` text,
`subtest_5_8_point_score` text,
`subtest_5_9_trial1` text,
`subtest_5_9_trial2` text,
`subtest_5_9_point_score` text,
`subtest_6_1_trial1` text,
`subtest_6_1_trial2` text,
`subtest_6_1_point_score` text,
`subtest_6_2_trial1` text,
`subtest_6_2_trial2` text,
`subtest_6_2_point_score` text,
`subtest_6_3_trial1` text,
`subtest_6_3_trial2` text,
`subtest_6_3_point_score` text,
`subtest_6_4_trial1` text,
`subtest_6_4_trial2` text,
`subtest_6_4_point_score` text,
`subtest_6_5_trial1` text,
`subtest_6_5_trial2` text,
`subtest_6_5_point_score` text,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;