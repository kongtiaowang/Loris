CREATE TABLE `m_chat_rf` (
`CommentID` varchar(255) NOT NULL default '',

                          `UserID` varchar(255) default NULL,

                          `Examiner` varchar(255) default NULL,

                          `Testdate` timestamp NOT NULL,

                          `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`score_raw` varchar(255) default NULL,
`q1_point_across_room` enum('yes','no') default NULL,
`q2_deaf` enum('yes','no') default NULL,
`q3_play_pretend` enum('yes','no') default NULL,
`q4_like_climbing` enum('yes','no') default NULL,
`q5_unusual_finger_movements_near_eyes` enum('yes','no') default NULL,
`q6_point_one_finger_for_help` enum('yes','no') default NULL,
`q7_point_one_finger_show` enum('yes','no') default NULL,
`q8_interested_other_children` enum('yes','no') default NULL,
`q9_show_things` enum('yes','no') default NULL,
`q10_respond_by_name` enum('yes','no') default NULL,
`q11_smile_back` enum('yes','no') default NULL,
`q12_upset_by_everyday_noises` enum('yes','no') default NULL,
`q13_walk` enum('yes','no') default NULL,
`q14_look_in_eye` enum('yes','no') default NULL,
`q15_copy_you` enum('yes','no') default NULL,
`q16_look_around` enum('yes','no') default NULL,
`q17_try_watch` enum('yes','no') default NULL,
`q18_understand_tell_something` enum('yes','no') default NULL,
`q19_look_at_face` enum('yes','no') default NULL,
`q20_movement_activities` enum('yes','no') default NULL,
PRIMARY KEY  (`CommentID`)

              );
