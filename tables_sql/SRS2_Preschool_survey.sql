CREATE TABLE `SRS2_Preschool_survey` (
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
`total_raw_score` varchar(255) default NULL,
`total_t_score` varchar(255) default NULL,
`awr_raw_score` varchar(255) default NULL,
`awr_t_score` varchar(255) default NULL,
`cog_raw_score` varchar(255) default NULL,
`cog_t_score` varchar(255) default NULL,
`com_raw_score` varchar(255) default NULL,
`com_t_score` varchar(255) default NULL,
`mot_raw_score` varchar(255) default NULL,
`mot_t_score` varchar(255) default NULL,
`rrb_raw_score` varchar(255) default NULL,
`rrb_t_score` varchar(255) default NULL,
`dsm_sci_raw_score` varchar(255) default NULL,
`dsm_sci_t_score` varchar(255) default NULL,
`dsm_rrb_raw_score` varchar(255) default NULL,
`dsm_rrb_t_score` varchar(255) default NULL,
`score_range` varchar(255) default NULL,
`child_gender` enum('boy','girl') default NULL,
`child_age` varchar(255) default NULL,
`q1_more_fidgety_in_social_situations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q2_expressions_dont_match_what_saying` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q3_self_confident_when_interacting` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q4_under_stress_autopilot` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q5_doesnt_recognize_others_take_advantage` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q6_rather_be_alone_than_with_others` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q7_aware_others_thinking_or_feeling` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q8_behave_in_ways_strange_bizarre` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q9_clings_to_adults_too_dependent` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q10_unable_to_pick_up_on_meaning` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q11_has_good_self_confidence` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q12_able_to_communicate_feelings_to_others` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q13_slow_awkward_turn_taking_interactions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q14_not_well_coordinated` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q15_understand_tone_and_facial_expressions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q16_avoid_or_unusual_eye_contact` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q17_recognize_when_something_is_unfair` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q18_does_not_attempt_interact_with_children` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q19_frustrated_trying_to_get_ideas_across` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q20_has_strange_way_of_playing_with_toy` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q21_able_to_imitate_others_actions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q22_plays_appropriately_with_children` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q23_does_not_join_group_activities_unless_told` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q24_difficulty_with_changes_in_routine` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q25_doesnt_mind_being_out_of_step` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q26_offers_comfort_to_others_when_sad` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q27_avoids_starting_social_interactions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q28_thinks_or_talks_about_same_thing` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q29_regarded_by_other_children_as_odd_weird` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q30_becomes_upset_in_situation_lots_going_on` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q31_cant_get_mind_off_something_once_starts` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q32_wants_to_be_changed_when_soiled_or_wet` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q33_socially_awkward_even_when_polite` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q34_avoids_people_emotionally_close` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q35_trouble_keeping_up_with_normal_interaction` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q36_has_difficulty_relating_to_adults` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q37_has_difficulty_relating_to_peers` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q38_responds_appropriately_to_mood_changes` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q39_has_restricted_range_of_interests` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q40_is_imaginative_good_at_pretending` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q41_wanders_aimlessly_from_activity_to_another` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q42_seems_overly_sensitive` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q43_separates_easily_from_caregivers` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q44_doesnt_understand_how_events_are_related` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q45_focuses_attention_where_others_looking_listening` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q46_has_overly_serious_facial_expressions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q47_is_too_silly_laughs_inappropriately` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q48_has_sense_of_humor_understands_jokes` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q49_does_extremely_well_at_a_few_tasks` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q50_has_repetitive_odd_behaviors` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q51_responds_to_clear_direct_questions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q52_knows_when_too_loud_too_much_noise` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q53_talks_with_unusual_tone_of_voice` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q54_seems_to_react_to_people_as_objects` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q55_knows_when_too_close_invading_space` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q56_walks_between_two_people_talking` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q57_other_children_do_not_play_with` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q58_concentrates_too_much_on_parts_of_things` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q59_is_overly_suspicious` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q60_is_emotionally_distant` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q61_is_inflexible` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q62_gives_unusual_illogical_reasons` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q63_touches_others_in_unusual_way` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q64_is_too_tense_in_social_settings` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
`q65_stares_or_gazes_off_into_space` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;