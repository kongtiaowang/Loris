CREATE TABLE `rbs_r_fxs_subject` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`respondent` enum('mother','father','step_mother','step_father','other') default NULL,
`respondent_specify` varchar(255) default NULL,
`overall_endorsed` varchar(255) default NULL,
`overall_score` varchar(255) default NULL,
`I_stereotyped_endorsed` varchar(255) default NULL,
`I_stereotyped_score` varchar(255) default NULL,
`II_self_injurious_endorsed` varchar(255) default NULL,
`II_self_injurious_score` varchar(255) default NULL,
`III_compulsive_endorsed` varchar(255) default NULL,
`III_compulsive_score` varchar(255) default NULL,
`IV_ritualistic_endorsed` varchar(255) default NULL,
`IV_ritualistic_score` varchar(255) default NULL,
`V_sameness_endorsed` varchar(255) default NULL,
`V_sameness_score` varchar(255) default NULL,
`VI_restricted_endorsed` varchar(255) default NULL,
`VI_restricted_score` varchar(255) default NULL,
`q1_whole_body` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q2_head` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q3_hand_finger` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q4_locomotion` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q5_object_usage` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q6_sensory` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q7_hits_self_body_part` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q8_hits_self_against_surface` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q9_hits_self_with_object` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q10_bites_self` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q11_pulls` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q12_rubs_or_scratches` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q13_inserts_finger_or_object` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q14_skin_picking` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q15_arranging_ordering` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q16_completeness` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q17_washing_cleaning` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q18_checking` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q19_counting` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q20_hoarding_saving` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q21_repeating` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q22_touch_tap` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q23_eating_mealtime` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q24_sleeping_bedtime` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q25_self_care` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q26_travel_transportation` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q27_play_leisure` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q28_communication` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q29_insists_things_remain` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q30_objects_to_visiting` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q31_upset_if_interrupted` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q32_walking_in_a_pattern` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q33_insists_on_sitting_at_same_place` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q34_dislikes_change` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q35_insists_on_particular_door` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q36_likes_same_cd` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q37_resists_changing_activities` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q38_insists_on_same_routine` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q39_insists_that_specific` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q40_fascination_preoccupation` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q41_strongly_attached` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q42_preoccupation_with_parts` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
`q43_fascination_with_movement` enum('0_does_not_occur','1_mild_problems','2_moderate_problem','3_severe_problem','not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('rbs_r_fxs_subject', "RBS-R (Repetitive Behavior Scale Revised) - FXS Subject - Survey", 1, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('rbs_r_fxs_subject','rbs_r_fxs_subject_page1', "Subscales", 1);

INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r_fxs_subject', DEFAULT, 4, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r_fxs_subject', DEFAULT, 5, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r_fxs_subject', DEFAULT, 7, 'VSA');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r_fxs_subject', DEFAULT, 4, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r_fxs_subject', DEFAULT, 5, 'VSA-CVD');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('rbs_r_fxs_subject', DEFAULT, 7, 'VSA-CVD');

