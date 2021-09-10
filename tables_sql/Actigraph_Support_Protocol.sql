CREATE TABLE `Actigraph_Support_Protocol` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`section1_probe` enum('level1','level2','level3','level4','level5','not_answered') default NULL,
`q1_my_child_tolerates_wearing_watches` enum('1','2','3','4','5') default NULL,
`q2_my_child_has_difficulty_with_extra` enum('1','2','3','4','5') default NULL,
`q3_my_child_has_difficulty_with_tags` enum('1','2','3','4','5') default NULL,
`q4_my_child_struggles_with_change` enum('1','2','3','4','5') default NULL,
`q5_my_child_tolerates_change_better` enum('1','2','3','4','5') default NULL,
`q6_my_child_tolerates_when_i_can_tell` enum('1','2','3','4','5') default NULL,
`q7_my_child_tolerates_learns_new_skills` enum('1','2','3','4','5') default NULL,
`q8_my_child_responds_well_to_reinforcement` enum('1','2','3','4','5') default NULL,
`q9_my_child_needs_reminders_about_what` enum('1','2','3','4','5') default NULL,
`q10_my_child_responds_well_to_visual_reminders` enum('1','2','3','4','5') default NULL,
`q11_my_child_responds_well_to_social_stories` enum('1','2','3','4','5') default NULL,
`visual_supports` varchar(255) default NULL,
`weekly_countdown_schedule_token_system` varchar(255) default NULL,
`social_story` varchar(255) default NULL,
`visual_of_keeping_actigraph_on` varchar(255) default NULL,
`verbal_prompts_priming` varchar(255) default NULL,
`scripts_about_wearing_the_actigraph` varchar(255) default NULL,
`verbal_reminders` varchar(255) default NULL,
`reinforcement` varchar(255) default NULL,
`sample_shaping_protocol` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
