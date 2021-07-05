DROP TABLE IF EXISTS BRQ_survey;


CREATE TABLE `BRQ_survey` (
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
`consistency_total_derived_score` varchar(255) default NULL,
`reactivity_total_derived_score` varchar(255) default NULL,
`adaptive_activities_total_derived_score` varchar(255) default NULL,
`maladaptive_activities_total_derived_score` varchar(255) default NULL,
`q1_perform_the_same_activities_in_the_hour_before_bed` enum('1','2','3','4','5') default NULL,
`q2_perform_activities_in_the_same_order_before_going_to_bed` enum('1','2','3','4','5') default NULL,
`q3_sleep_in_the_same_place` enum('1','2','3','4','5') default NULL,
`q4_go_to_bed_at_the_same_time` enum('1','2','3','4','5') default NULL,
`q5_get_put_to_bed_by_the_same_person` enum('1','2','3','4','5') default NULL,
`q6_perform_the_same_activities_in_the_hour_before_bed` enum('1','2','3','4','5') default NULL,
`q7_perform_activities_in_the_same_order_before_going_to_bed` enum('1','2','3','4','5') default NULL,
`q8_sleep_in_the_same_place` enum('1','2','3','4','5') default NULL,
`q9_go_to_bed_at_the_same_time` enum('1','2','3','4','5') default NULL,
`q10_get_put_to_bed_by_the_same_person` enum('1','2','3','4','5') default NULL,
`q11_perform_the_same_activities_in_the_hour_before_bed` enum('1','2','3','4','5') default NULL,
`q12_perform_activities_in_the_same_order_before_going_to_bed` enum('1','2','3','4','5') default NULL,
`q13_sleep_in_the_same_place` enum('1','2','3','4','5') default NULL,
`q14_go_to_bed_at_the_same_time` enum('1','2','3','4','5') default NULL,
`q15_get_put_to_bed_by_the_same_person` enum('1','2','3','4','5') default NULL,
`q16_read_listen_to_a_story` enum('1','2','3','4','5') default NULL,
`q17_play_with_games_or_toys` enum('1','2','3','4','5') default NULL,
`q18_have_active_play` enum('1','2','3','4','5') default NULL,
`q19_watch_tv` enum('1','2','3','4','5') default NULL,
`q20_play_video_games` enum('1','2','3','4','5') default NULL,
`q21_listen_to_music` enum('1','2','3','4','5') default NULL,
`q22_have_a_snack_or_drink` enum('1','2','3','4','5') default NULL,
`q23_take_a_shower_bath` enum('1','2','3','4','5') default NULL,
`q24_brush_teeth` enum('1','2','3','4','5') default NULL,
`q25_use_the_toilet` enum('1','2','3','4','5') default NULL,
`q26_hug_kiss_caregiver` enum('1','2','3','4','5') default NULL,
`q27_say_goodnight_to_family_member` enum('1','2','3','4','5') default NULL,
`q28_get_tucked_in` enum('1','2','3','4','5') default NULL,
`q29_put_on_pajamas` enum('1','2','3','4','5') default NULL,
`q30_say_prayers` enum('1','2','3','4','5') default NULL,
`q31_cuddle_with_caregiver` enum('1','2','3','4','5') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
