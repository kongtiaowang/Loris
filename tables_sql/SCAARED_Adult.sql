CREATE TABLE `SCAARED_Adult` (
    `CommentID` varchar(255) NOT NULL default '',
    `UserID` varchar(255) default NULL,
    `Examiner` varchar(255) default NULL,
    `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
    `Date_taken` date default NULL,
    `Candidate_Age` varchar(255) default NULL,
    `Window_Difference` varchar(255) default NULL,
    `respondent` enum('child','mother','father','step_mother','step_father','other') default NULL,
    `other_specify` varchar(255) default NULL,
    `pa_so_score` varchar(255) default NULL,
    `ga_score` varchar(255) default NULL,
    `sep_score` varchar(255) default NULL,
    `soc_score` varchar(255) default NULL,
    `total_score` varchar(255) default NULL,
    `q1_nervous_hard_to_breathe` enum('0','1','2') default NULL,
    `q2_headaches_public_places` enum('0','1','2') default NULL,
    `q3_dont_like_to_be_with_people_dont_know_well` enum('0','1','2') default NULL,
    `q4_nervous_if_sleep_away_from_home` enum('0','1','2') default NULL,
    `q5_worry_about_people_liking_me` enum('0','1','2') default NULL,
    `q6_anxious_feel_like_passing_out` enum('0','1','2') default NULL,
    `q7_am_nervous` enum('0','1','2') default NULL,
    `q8_hard_to_stop_worrying` enum('0','1','2') default NULL,
    `q9_people_tell_look_nervous` enum('0','1','2') default NULL,
    `q10_nervous_with_people_dont_know_well` enum('0','1','2') default NULL,
    `q11_stomachaches_public_places` enum('0','1','2') default NULL,
    `q12_anxious_feel_like_going_crazy` enum('0','1','2') default NULL,
    `q13_worry_about_sleeping_alone` enum('0','1','2') default NULL,
    `q14_worry_about_being_as_good_as_other_people` enum('0','1','2') default NULL,
    `q15_anxious_feel_like_things_are_not_real` enum('0','1','2') default NULL,
    `q16_nightmares_something_bad_happening_family` enum('0','1','2') default NULL,
    `q17_worry_about_going_to_public_places` enum('0','1','2') default NULL,
    `q18_anxious_heart_beats_fast` enum('0','1','2') default NULL,
    `q19_get_shaky` enum('0','1','2') default NULL,
    `q20_nightmares_something_bad_happening_me` enum('0','1','2') default NULL,
    `q21_worry_about_things_working_out` enum('0','1','2') default NULL,
    `q22_anxious_sweat_a_lot` enum('0','1','2') default NULL,
    `q23_am_a_worrier` enum('0','1','2') default NULL,
    `q24_worry_trouble_sleeping` enum('0','1','2') default NULL,
    `q25_frightened_for_no_reason` enum('0','1','2') default NULL,
    `q26_afraid_to_be_alone_in_house` enum('0','1','2') default NULL,
    `q27_hard_to_talk_with_people_dont_know_well` enum('0','1','2') default NULL,
    `q28_anxious_feel_like_choking` enum('0','1','2') default NULL,
    `q29_people_tell_worry_too_much` enum('0','1','2') default NULL,
    `q30_dont_like_to_be_away_from_family` enum('0','1','2') default NULL,
    `q31_worry_feel_restless` enum('0','1','2') default NULL,
    `q32_afraid_of_anxiety_or_panic_attacks` enum('0','1','2') default NULL,
    `q33_worry_something_bad_might_happen_family` enum('0','1','2') default NULL,
    `q34_shy_with_people_dont_know_well` enum('0','1','2') default NULL,
    `q35_worry_about_the_future` enum('0','1','2') default NULL,
    `q36_anxious_feel_like_throwing_up` enum('0','1','2') default NULL,
    `q37_worry_about_how_well_do_things` enum('0','1','2') default NULL,
    `q38_afraid_to_go_outside_crowded_places_myself` enum('0','1','2') default NULL,
    `q39_worry_about_things_already_happened` enum('0','1','2') default NULL,
    `q40_anxious_feel_dizzy` enum('0','1','2') default NULL,
    `q41_nervous_with_people_do_something_watch_me` enum('0','1','2') default NULL,
    `q42_nervous_go_to_any_place_with_people_dont_know_well` enum('0','1','2') default NULL,
    `q43_am_shy` enum('0','1','2') default NULL,
    `q44_worry_feel_irritable` enum('0','1','2') default NULL,
    PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;