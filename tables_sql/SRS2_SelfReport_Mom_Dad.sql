-- SRS2 Self Report MOm
CREATE TABLE `SRS2_SelfReport_Mom` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `UserID` varchar(255) DEFAULT NULL,
  `Examiner` varchar(255) DEFAULT NULL,
  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `respondent_age` varchar(255) DEFAULT NULL,
  `respondent_gender` enum('male','female','other') DEFAULT NULL,
  `q1_uncomfortable_socialsituations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q2_wrong_facialexpressions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q3_self_confident` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q4_rigid_inflexible` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q5_others_take_advantage` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q6_rather_be_alone` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q7_aware_others_feeling` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q8_behave_strange_bizarre` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q9_overly_dependent` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q10_takethings_literally` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q11_have_selfconfidence` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q12_communicate_toothers` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q13_awkward_turn_takingtalk` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q14_notwell_coordinated` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q15_changefacialexp_understandmeaning` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q16_avoideyecontact` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q17_recognize_unfair` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q18_difficulty_makingfriends` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q19_frustrated_conveyingideas` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q20_unusual_interests` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q21_imitate_actionsexpressions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q22_interact_appropriately` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q23_joingroups_activities` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q24_diff_changeroutine` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q25_diff_wavelength` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q26_offer_comfort` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q27_avoid_socialinteractions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q28_think_overandover` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q29_odd_weird` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q30_upset_situations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q31_cant_getmind_off` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q32_good_personal_hygiene` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q33_socially_awkward` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q34_avoid_emotionallyclose` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q35_trouble_keepingup` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q36_difficulty_relating_family` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q37_difficulty_relating_adults` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q38_respond_moodchange` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q39_interested_toofew_topics` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q40_imaginative` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q41_wander_aimlessly` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q42_overly_sensitive` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q43_enjoy_smalltalk` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q44_trouble_chains_causation` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q45_pay_attention` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q46_serious_facialexp` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q47_laugh_inappropriate` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q48_goodsense_humor` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q49_wellat_intellectualtasks` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q50_repetitive_behavior` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q51_diff_directqstn` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q52_overly_loud` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q53_monotone_voice` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q54_thinkpeople_as_objects` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q55_invade_personalspace` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q56_walk_btwn_people` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q57_isolate_myself` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q58_concentration_parts` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q59_suspicious_ofpeople` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q60_emotionally_distant` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q61_inflexible` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q62_reason_unusual` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q63_greeting_unusual` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q64_tense_socialsituations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q65_staring_gazing` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` int(11) DEFAULT NULL,
  `Date_taken` date DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
-- SRS2 Self Report Dad
CREATE TABLE `SRS2_SelfReport_Dad` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `UserID` varchar(255) DEFAULT NULL,
  `Examiner` varchar(255) DEFAULT NULL,
  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `respondent_age` varchar(255) DEFAULT NULL,
  `respondent_gender` enum('male','female','other') DEFAULT NULL,
  `q1_uncomfortable_socialsituations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q2_wrong_facialexpressions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q3_self_confident` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q4_rigid_inflexible` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q5_others_take_advantage` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q6_rather_be_alone` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q7_aware_others_feeling` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q8_behave_strange_bizarre` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q9_overly_dependent` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q10_takethings_literally` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q11_have_selfconfidence` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q12_communicate_toothers` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q13_awkward_turn_takingtalk` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q14_notwell_coordinated` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q15_changefacialexp_understandmeaning` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q16_avoideyecontact` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q17_recognize_unfair` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q18_difficulty_makingfriends` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q19_frustrated_conveyingideas` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q20_unusual_interests` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q21_imitate_actionsexpressions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q22_interact_appropriately` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q23_joingroups_activities` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q24_diff_changeroutine` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q25_diff_wavelength` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q26_offer_comfort` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q27_avoid_socialinteractions` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q28_think_overandover` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q29_odd_weird` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q30_upset_situations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q31_cant_getmind_off` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q32_good_personal_hygiene` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q33_socially_awkward` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q34_avoid_emotionallyclose` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q35_trouble_keepingup` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q36_difficulty_relating_family` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q37_difficulty_relating_adults` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q38_respond_moodchange` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q39_interested_toofew_topics` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q40_imaginative` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q41_wander_aimlessly` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q42_overly_sensitive` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q43_enjoy_smalltalk` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q44_trouble_chains_causation` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q45_pay_attention` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q46_serious_facialexp` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q47_laugh_inappropriate` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q48_goodsense_humor` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q49_wellat_intellectualtasks` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q50_repetitive_behavior` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q51_diff_directqstn` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q52_overly_loud` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q53_monotone_voice` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q54_thinkpeople_as_objects` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q55_invade_personalspace` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q56_walk_btwn_people` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q57_isolate_myself` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q58_concentration_parts` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q59_suspicious_ofpeople` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q60_emotionally_distant` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q61_inflexible` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q62_reason_unusual` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q63_greeting_unusual` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q64_tense_socialsituations` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `q65_staring_gazing` enum('1_not_true','2_sometimes_true','3_often_true','4_almost_always_true','refused_dontknow') DEFAULT NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` int(11) DEFAULT NULL,
  `Date_taken` date DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- SRS2_SelfReport_Mom_Meta
INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('SRS2_SelfReport_Mom', 'SRS2 Mom Self Report (Send to Mom)', '1','1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_SelfReport_Mom', 'SRS2_SelfReport_Mom_page2', 'SRS2 Self Report Mom Page 2', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_SelfReport_Mom', 'SRS2_SelfReport_Mom_page3', 'SRS2 Self Report Mom Page 3', 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_SelfReport_Mom', 'SRS2_SelfReport_Mom_page4', 'SRS2 Self Report Mom Page 4', 3);

-- SRS2_SelfReport_Dad_Meta
INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('SRS2_SelfReport_Dad', 'SRS2 Dad Self Report (Send to Dad)', '1','1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_SelfReport_Dad', 'SRS2_SelfReport_Dad_page2', 'SRS2 Self Report Dad Page 2', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_SelfReport_Dad', 'SRS2_SelfReport_Dad_page3', 'SRS2 Self Report Dad Page 3', 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SRS2_SelfReport_Dad', 'SRS2_SelfReport_Dad_page4', 'SRS2 Self Report Dad Page 4', 3);
