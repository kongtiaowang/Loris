UPDATE test_names SET IsDirectEntry = 0 WHERE Test_name = 'm_chat_rf';
UPDATE test_names SET Full_name = 'M-CHAT [Revised with Follow-up]' WHERE Test_name = 'm_chat_rf';

INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page1', 'Page 1', '1');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page2', 'Page 2', '2');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page3', 'Page 3', '3');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page4', 'Page 4', '4');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page5', 'Page 5', '5');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page6', 'Page 6', '6');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page7', 'Page 7', '7');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page8', 'Page 8', '8');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page9', 'Page 9', '9');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page10', 'Page 10', '10');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page11', 'Page 11', '11');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page12', 'Page 12', '12');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page13', 'Page 13', '13');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page14', 'Page 14', '14');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page15', 'Page 15', '15');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page16', 'Page 16', '16');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page17', 'Page 17', '17');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page18', 'Page 18', '18');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page19', 'Page 19', '19');
INSERT INTO `instrument_subtests` (`ID`, `Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES (NULL, 'm_chat_rf', 'm_chat_rf_page20', 'Page 20', '20');

-- IBIS EP High Risk
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V09', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V9-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V24-CVD', NULL);

-- DS Infant
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V09', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V9-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V24-CVD', NULL);

-- Control DS Infant
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V09', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V9-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V24-CVD', NULL);

ALTER TABLE m_chat_rf ADD `q1_pass_or_fail` varchar(255) default NULL AFTER `relationship_to_child_other`;
ALTER TABLE m_chat_rf ADD `q2_pass_or_fail` varchar(255) default NULL AFTER `q1_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q3_pass_or_fail` varchar(255) default NULL AFTER `q2_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q4_pass_or_fail` varchar(255) default NULL AFTER `q3_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q5_pass_or_fail` varchar(255) default NULL AFTER `q4_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q6_pass_or_fail` varchar(255) default NULL AFTER `q5_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q7_pass_or_fail` varchar(255) default NULL AFTER `q6_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q8_pass_or_fail` varchar(255) default NULL AFTER `q7_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q9_pass_or_fail` varchar(255) default NULL AFTER `q8_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q10_pass_or_fail` varchar(255) default NULL AFTER `q9_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q11_pass_or_fail` varchar(255) default NULL AFTER `q10_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q12_pass_or_fail` varchar(255) default NULL AFTER `q11_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q13_pass_or_fail` varchar(255) default NULL AFTER `q12_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q14_pass_or_fail` varchar(255) default NULL AFTER `q13_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q15_pass_or_fail` varchar(255) default NULL AFTER `q14_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q16_pass_or_fail` varchar(255) default NULL AFTER `q15_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q17_pass_or_fail` varchar(255) default NULL AFTER `q16_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q18_pass_or_fail` varchar(255) default NULL AFTER `q17_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q19_pass_or_fail` varchar(255) default NULL AFTER `q18_pass_or_fail`;
ALTER TABLE m_chat_rf ADD `q20_pass_or_fail` varchar(255) default NULL AFTER `q19_pass_or_fail`;

ALTER TABLE m_chat_rf ADD `q1_look_at_object` enum('yes','no') default NULL AFTER `q1_point_across_room`;
ALTER TABLE m_chat_rf ADD `q1_point_at_object` enum('yes','no') default NULL AFTER `q1_look_at_object`;
ALTER TABLE m_chat_rf ADD `q1_look_and_comment_on_object` enum('yes','no') default NULL AFTER `q1_point_at_object`;
ALTER TABLE m_chat_rf ADD `q1_look_if_you_point_and_say_look` enum('yes','no') default NULL AFTER `q1_look_and_comment_on_object`;
ALTER TABLE m_chat_rf ADD `q1_ignores_you` enum('yes','no') default NULL AFTER `q1_look_if_you_point_and_say_look`;
ALTER TABLE m_chat_rf ADD `q1_look_around_room_randomly` enum('yes','no') default NULL AFTER `q1_ignores_you`;
ALTER TABLE m_chat_rf ADD `q1_look_at_your_finger` enum('yes','no') default NULL AFTER `q1_look_around_room_randomly`;
ALTER TABLE m_chat_rf ADD `q1_yes_to_both_pass_and_fail` enum('pass','fail') default NULL AFTER `q1_look_at_your_finger`;

ALTER TABLE m_chat_rf ADD `q2_often_ignore_sounds` enum('yes','no') default NULL AFTER `q2_deaf`;
ALTER TABLE m_chat_rf ADD `q2_often_ignore_people` enum('yes','no') default NULL AFTER `q2_often_ignore_sounds`;
ALTER TABLE m_chat_rf ADD `q2_hearing_tested` enum('yes','no') default NULL AFTER `q2_often_ignore_people`;
ALTER TABLE m_chat_rf ADD `q2_results_of_hearing_test` enum('normal_range','below_normal','inconclusive_or_not_definitive') default NULL AFTER `q2_hearing_tested`;

ALTER TABLE m_chat_rf ADD `q3_pretend_to_drink_from_toy_cup` enum('yes','no') default NULL AFTER `q3_play_pretend`;
ALTER TABLE m_chat_rf ADD `q3_pretend_to_eat_from_toy_spoon_or_fork` enum('yes','no') default NULL AFTER `q3_pretend_to_drink_from_toy_cup`;
ALTER TABLE m_chat_rf ADD `q3_pretend_to_talk_on_phone` enum('yes','no') default NULL AFTER `q3_pretend_to_eat_from_toy_spoon_or_fork`;
ALTER TABLE m_chat_rf ADD `q3_pretened_to_feed_doll_or_stuffed_animal` enum('yes','no') default NULL AFTER `q3_pretend_to_talk_on_phone`;
ALTER TABLE m_chat_rf ADD `q3_push_car_along_pretend_road` enum('yes','no') default NULL AFTER `q3_pretened_to_feed_doll_or_stuffed_animal`;
ALTER TABLE m_chat_rf ADD `q3_pretend_to_be_robot_airplane_ballerina_or_other` enum('yes','no') default NULL AFTER `q3_push_car_along_pretend_road`;
ALTER TABLE m_chat_rf ADD `q3_put_toy_pot_on_pretend_stove` enum('yes','no') default NULL AFTER `q3_pretend_to_be_robot_airplane_ballerina_or_other`;
ALTER TABLE m_chat_rf ADD `q3_stir_imaginary_food` enum('yes','no') default NULL AFTER `q3_put_toy_pot_on_pretend_stove`;
ALTER TABLE m_chat_rf ADD `q3_put_action_figure_or_doll_into_car_or_truck` enum('yes','no') default NULL AFTER `q3_stir_imaginary_food`;
ALTER TABLE m_chat_rf ADD `q3_pretend_to_vacuum_sweep_mow` enum('yes','no') default NULL AFTER `q3_put_action_figure_or_doll_into_car_or_truck`;
ALTER TABLE m_chat_rf ADD `q3_other` enum('yes','no') default NULL AFTER `q3_pretend_to_vacuum_sweep_mow`;
ALTER TABLE m_chat_rf ADD `q3_if_other_describe` varchar(255) default NULL AFTER `q3_other`;

ALTER TABLE m_chat_rf ADD `q4_stairs` enum('yes','no') default NULL AFTER `q4_like_climbing`;
ALTER TABLE m_chat_rf ADD `q4_chairs` enum('yes','no') default NULL AFTER `q4_stairs`;
ALTER TABLE m_chat_rf ADD `q4_furniture` enum('yes','no') default NULL AFTER `q4_chairs`;
ALTER TABLE m_chat_rf ADD `q4_playground_equipment` enum('yes','no') default NULL AFTER `q4_furniture`;

ALTER TABLE m_chat_rf ADD `q5_look_at_hands` enum('yes','no') default NULL AFTER `q5_unusual_finger_movements_near_eyes`;
ALTER TABLE m_chat_rf ADD `q5_move_fingers_when_playing_peek_a_boo` enum('yes','no') default NULL AFTER `q5_look_at_hands`;
ALTER TABLE m_chat_rf ADD `q5_ignores_you` enum('yes','no') default NULL AFTER `q5_move_fingers_when_playing_peek_a_boo`;
ALTER TABLE m_chat_rf ADD `q5_look_around_room_randomly` enum('yes','no') default NULL AFTER `q5_ignores_you`;
ALTER TABLE m_chat_rf ADD `q5_look_at_your_finger` enum('yes','no') default NULL AFTER `q5_look_around_room_randomly`;
ALTER TABLE m_chat_rf ADD `q5_flap_hands_near_face` enum('yes','no') default NULL AFTER `q5_look_at_your_finger`;
ALTER TABLE m_chat_rf ADD `q5_other` enum('yes','no') default NULL AFTER `q5_flap_hands_near_face`;
ALTER TABLE m_chat_rf ADD `q5_if_other_describe` varchar(255) default NULL AFTER `q5_other`;
ALTER TABLE m_chat_rf ADD `q5_happen_more_than_twice_a_week` enum('yes','no') default NULL AFTER `q5_if_other_describe`;

ALTER TABLE m_chat_rf ADD `q6_reach_for_object_with_whole_hand` enum('yes','no') default NULL AFTER `q6_point_one_finger_for_help`;
ALTER TABLE m_chat_rf ADD `q6_lead_you_to_object` enum('yes','no') default NULL AFTER `q6_reach_for_object_with_whole_hand`;
ALTER TABLE m_chat_rf ADD `q6_try_to_get_object_for_self` enum('yes','no') default NULL AFTER `q6_lead_you_to_object`;
ALTER TABLE m_chat_rf ADD `q6_ask_using_words_or_sounds` enum('yes','no') default NULL AFTER `q6_try_to_get_object_for_self`;
ALTER TABLE m_chat_rf ADD `q6_show_me_point` enum('yes','no') default NULL AFTER `q6_ask_using_words_or_sounds`;

ALTER TABLE m_chat_rf ADD `q7_airplane_in_sky` enum('yes','no') default NULL AFTER `q7_point_one_finger_show`;
ALTER TABLE m_chat_rf ADD `q7_truck_on_road` enum('yes','no') default NULL AFTER `q7_airplane_in_sky`;
ALTER TABLE m_chat_rf ADD `q7_bug_on_ground` enum('yes','no') default NULL AFTER `q7_truck_on_road`;
ALTER TABLE m_chat_rf ADD `q7_animal_in_yard` enum('yes','no') default NULL AFTER `q7_bug_on_ground`;
ALTER TABLE m_chat_rf ADD `q7_child_draw_attention` enum('yes','no') default NULL AFTER `q7_animal_in_yard`;
ALTER TABLE m_chat_rf ADD `q7_if_yes_show_interest_not_help` enum('yes','no') default NULL AFTER `q7_child_draw_attention`;

ALTER TABLE m_chat_rf ADD `q8_interested_in_children_not_brother_or_sister` enum('yes','no') default NULL AFTER `q8_interested_other_children`;
ALTER TABLE m_chat_rf ADD `q8_respond_to_other_children` enum('yes','no') default NULL AFTER `q8_interested_in_children_not_brother_or_sister`;
ALTER TABLE m_chat_rf ADD `q8_play_with_another_child` enum('yes','no') default NULL AFTER `q8_respond_to_other_children`;
ALTER TABLE m_chat_rf ADD `q8_talk_to_another_child` enum('yes','no') default NULL AFTER `q8_play_with_another_child`;
ALTER TABLE m_chat_rf ADD `q8_babble_or_make_vocal_noises` enum('yes','no') default NULL AFTER `q8_talk_to_another_child`;
ALTER TABLE m_chat_rf ADD `q8_watch_another_child` enum('yes','no') default NULL AFTER `q8_babble_or_make_vocal_noises`;
ALTER TABLE m_chat_rf ADD `q8_smile_at_another_child` enum('yes','no') default NULL AFTER `q8_watch_another_child`;
ALTER TABLE m_chat_rf ADD `q8_act_shy_at_first_then_smile` enum('yes','no') default NULL AFTER `q8_smile_at_another_child`;
ALTER TABLE m_chat_rf ADD `q8_get_excited_about_another_child` enum('yes','no') default NULL AFTER `q8_act_shy_at_first_then_smile`;
ALTER TABLE m_chat_rf ADD `q8_respond_to_other_children_more_than_half_the_time` enum('yes','no') default NULL AFTER `q8_get_excited_about_another_child`;

ALTER TABLE m_chat_rf ADD `q9_picture_or_toy_to_show_you` enum('yes','no') default NULL AFTER `q9_show_things`;
ALTER TABLE m_chat_rf ADD `q9_drawing_done` enum('yes','no') default NULL AFTER `q9_picture_or_toy_to_show_you`;
ALTER TABLE m_chat_rf ADD `q9_flower_has_picked` enum('yes','no') default NULL AFTER `q9_drawing_done`;
ALTER TABLE m_chat_rf ADD `q9_bug_found_in_grass` enum('yes','no') default NULL AFTER `q9_flower_has_picked`;
ALTER TABLE m_chat_rf ADD `q9_few_blocks_put_together` enum('yes','no') default NULL AFTER `q9_bug_found_in_grass`;
ALTER TABLE m_chat_rf ADD `q9_other` enum('yes','no') default NULL AFTER `q9_few_blocks_put_together`;
ALTER TABLE m_chat_rf ADD `q9_if_other_describe` varchar(255) default NULL AFTER `q9_other`;
ALTER TABLE m_chat_rf ADD `q9_sometimes_just_to_show_you_not_get_help` enum('yes','no') default NULL AFTER `q9_if_other_describe`;

ALTER TABLE m_chat_rf ADD `q10_look_up` enum('yes','no') default NULL AFTER `q10_respond_by_name`;
ALTER TABLE m_chat_rf ADD `q10_talk_or_babble` enum('yes','no') default NULL AFTER `q10_look_up`;
ALTER TABLE m_chat_rf ADD `q10_stop_what_doing` enum('yes','no') default NULL AFTER `q10_talk_or_babble`;
ALTER TABLE m_chat_rf ADD `q10_make_no_response` enum('yes','no') default NULL AFTER `q10_stop_what_doing`;
ALTER TABLE m_chat_rf ADD `q10_seem_to_hear_but_ignores_parent` enum('yes','no') default NULL AFTER `q10_make_no_response`;
ALTER TABLE m_chat_rf ADD `q10_respond_only_if_parent_is_in_front_of_face` enum('yes','no') default NULL AFTER `q10_seem_to_hear_but_ignores_parent`;
ALTER TABLE m_chat_rf ADD `q10_respond_only_if_touched` enum('yes','no') default NULL AFTER `q10_respond_only_if_parent_is_in_front_of_face`;
ALTER TABLE m_chat_rf ADD `q10_yes_to_both_pass_and_fail` enum('pass','fail') default NULL AFTER `q10_respond_only_if_touched`;

ALTER TABLE m_chat_rf ADD `q11_smile_when_you_smile` enum('yes','no') default NULL AFTER `q11_smile_back`;
ALTER TABLE m_chat_rf ADD `q11_smile_when_enter_room` enum('yes','no') default NULL AFTER `q11_smile_when_you_smile`;
ALTER TABLE m_chat_rf ADD `q11_smile_when_return_from_being_away` enum('yes','no') default NULL AFTER `q11_smile_when_enter_room`;
ALTER TABLE m_chat_rf ADD `q11_always_smile` enum('yes','no') default NULL AFTER `q11_smile_when_return_from_being_away`;
ALTER TABLE m_chat_rf ADD `q11_smile_at_favorite_toy_or_activity` enum('yes','no') default NULL AFTER `q11_always_smile`;
ALTER TABLE m_chat_rf ADD `q11_smile_randomly_or_nothing` enum('yes','no') default NULL AFTER `q11_smile_at_favorite_toy_or_activity`;
ALTER TABLE m_chat_rf ADD `q11_yes_to_both_pass_and_fail` enum('pass','fail') default NULL AFTER `q11_smile_randomly_or_nothing`;

ALTER TABLE m_chat_rf ADD `q12_washing_machine` enum('yes','no') default NULL AFTER `q12_upset_by_everyday_noises`;
ALTER TABLE m_chat_rf ADD `q12_babies_crying` enum('yes','no') default NULL AFTER `q12_washing_machine`;
ALTER TABLE m_chat_rf ADD `q12_vacuum_cleaner` enum('yes','no') default NULL AFTER `q12_babies_crying`;
ALTER TABLE m_chat_rf ADD `q12_hairdryer` enum('yes','no') default NULL AFTER `q12_vacuum_cleaner`;
ALTER TABLE m_chat_rf ADD `q12_traffic` enum('yes','no') default NULL AFTER `q12_hairdryer`;
ALTER TABLE m_chat_rf ADD `q12_babies_squealing_or_screeching` enum('yes','no') default NULL AFTER `q12_traffic`;
ALTER TABLE m_chat_rf ADD `q12_loud_music` enum('yes','no') default NULL AFTER `q12_babies_squealing_or_screeching`;
ALTER TABLE m_chat_rf ADD `q12_telephone_doorbell_ringing` enum('yes','no') default NULL AFTER `q12_loud_music`;
ALTER TABLE m_chat_rf ADD `q12_noisy_places` enum('yes','no') default NULL AFTER `q12_telephone_doorbell_ringing`;
ALTER TABLE m_chat_rf ADD `q12_other` enum('yes','no') default NULL AFTER `q12_noisy_places`;
ALTER TABLE m_chat_rf ADD `q12_if_other_describe` varchar(255) default NULL AFTER `q12_other`;
ALTER TABLE m_chat_rf ADD `q12_calmly_cover_ears` enum('yes','no') default NULL AFTER `q12_if_other_describe`;
ALTER TABLE m_chat_rf ADD `q12_does_not_like_noise` enum('yes','no') default NULL AFTER `q12_calmly_cover_ears`;
ALTER TABLE m_chat_rf ADD `q12_scream` enum('yes','no') default NULL AFTER `q12_does_not_like_noise`;
ALTER TABLE m_chat_rf ADD `q12_cry` enum('yes','no') default NULL AFTER `q12_scream`;
ALTER TABLE m_chat_rf ADD `q12_cover_ears_while_upset` enum('yes','no') default NULL AFTER `q12_cry`;
ALTER TABLE m_chat_rf ADD `q12_yes_to_both_pass_and_fail` enum('pass','fail') default NULL AFTER `q12_cover_ears_while_upset`;

ALTER TABLE m_chat_rf ADD `q13_walk_without_holding_anything` enum('yes','no') default NULL AFTER `q13_walk`;

ALTER TABLE m_chat_rf ADD `q14_needs_something` enum('yes','no') default NULL AFTER `q14_look_in_eye`;
ALTER TABLE m_chat_rf ADD `q14_playing_with` enum('yes','no') default NULL AFTER `q14_needs_something`;
ALTER TABLE m_chat_rf ADD `q14_during_feeding` enum('yes','no') default NULL AFTER `q14_playing_with`;
ALTER TABLE m_chat_rf ADD `q14_during_diaper_changes` enum('yes','no') default NULL AFTER `q14_during_feeding`;
ALTER TABLE m_chat_rf ADD `q14_when_reading_a_story` enum('yes','no') default NULL AFTER `q14_during_diaper_changes`;
ALTER TABLE m_chat_rf ADD `q14_when_talking` enum('yes','no') default NULL AFTER `q14_when_reading_a_story`;
ALTER TABLE m_chat_rf ADD `q14_look_you_in_eye_every_day` enum('yes','no') default NULL AFTER `q14_when_talking`;
ALTER TABLE m_chat_rf ADD `q14_look_you_in_eye_5_times` enum('yes','no') default NULL AFTER `q14_look_you_in_eye_every_day`;

ALTER TABLE m_chat_rf ADD `q15_stick_out_tongue` enum('yes','no') default NULL AFTER `q15_copy_you`;
ALTER TABLE m_chat_rf ADD `q15_make_funny_sound` enum('yes','no') default NULL AFTER `q15_stick_out_tongue`;
ALTER TABLE m_chat_rf ADD `q15_wave_good_bye` enum('yes','no') default NULL AFTER `q15_make_funny_sound`;
ALTER TABLE m_chat_rf ADD `q15_clap_hands` enum('yes','no') default NULL AFTER `q15_wave_good_bye`;
ALTER TABLE m_chat_rf ADD `q15_put_fingers_to_lips_signal_shhh` enum('yes','no') default NULL AFTER `q15_clap_hands`;
ALTER TABLE m_chat_rf ADD `q15_blow_kiss` enum('yes','no') default NULL AFTER `q15_put_fingers_to_lips_signal_shhh`;
ALTER TABLE m_chat_rf ADD `q15_other` enum('yes','no') default NULL AFTER `q15_blow_kiss`;
ALTER TABLE m_chat_rf ADD `q15_if_other_describe` varchar(255) default NULL AFTER `q15_other`;

ALTER TABLE m_chat_rf ADD `q16_look_toward_thing_looking_at` enum('yes','no') default NULL AFTER `q16_look_around`;
ALTER TABLE m_chat_rf ADD `q16_point_toward_thing_looking_at` enum('yes','no') default NULL AFTER `q16_look_toward_thing_looking_at`;
ALTER TABLE m_chat_rf ADD `q16_look_around_see_what_looking_at` enum('yes','no') default NULL AFTER `q16_point_toward_thing_looking_at`;
ALTER TABLE m_chat_rf ADD `q16_ignore_you` enum('yes','no') default NULL AFTER `q16_look_around_see_what_looking_at`;
ALTER TABLE m_chat_rf ADD `q16_look_at_your_face` enum('yes','no') default NULL AFTER `q16_ignore_you`;
ALTER TABLE m_chat_rf ADD `q16_yes_to_both_pass_and_fail` enum('pass','fail') default NULL AFTER `q16_look_at_your_face`;

ALTER TABLE m_chat_rf ADD `q17_say_look_or_watch_me` enum('yes','no') default NULL AFTER `q17_try_watch`;
ALTER TABLE m_chat_rf ADD `q17_babble_or_make_noise` enum('yes','no') default NULL AFTER `q17_say_look_or_watch_me`;
ALTER TABLE m_chat_rf ADD `q17_look_to_get_praise_or_comment` enum('yes','no') default NULL AFTER `q17_babble_or_make_noise`;
ALTER TABLE m_chat_rf ADD `q17_keep_looking_to_see_if_looking` enum('yes','no') default NULL AFTER `q17_look_to_get_praise_or_comment`;
ALTER TABLE m_chat_rf ADD `q17_other` enum('yes','no') default NULL AFTER `q17_keep_looking_to_see_if_looking`;
ALTER TABLE m_chat_rf ADD `q17_if_other_describe` varchar(255) default NULL AFTER `q17_other`;

ALTER TABLE m_chat_rf ADD `q18_follow_a_command` enum('yes','no') default NULL AFTER `q18_understand_tell_something`;
ALTER TABLE m_chat_rf ADD `q18_dinnertime_food_sit_at_table` enum('yes','no') default NULL AFTER `q18_follow_a_command`;
ALTER TABLE m_chat_rf ADD `q18_1_show_me_your_shoe` enum('yes','no') default NULL AFTER `q18_dinnertime_food_sit_at_table`;
ALTER TABLE m_chat_rf ADD `q18_2_bring_me_the_blanket` enum('yes','no') default NULL AFTER `q18_1_show_me_your_shoe`;
ALTER TABLE m_chat_rf ADD `q18_3_put_the_book_on_the_chair` enum('yes','no') default NULL AFTER `q18_2_bring_me_the_blanket`;

ALTER TABLE m_chat_rf ADD `q19_hears_noise_look_before_responding` enum('yes','no') default NULL AFTER `q19_look_at_face`;
ALTER TABLE m_chat_rf ADD `q19_look_at_you_when_someone_approaches` enum('yes','no') default NULL AFTER `q19_hears_noise_look_before_responding`;
ALTER TABLE m_chat_rf ADD `q19_look_at_you_when_faced_unfamiliar_or_scary` enum('yes','no') default NULL AFTER `q19_look_at_you_when_someone_approaches`;

ALTER TABLE m_chat_rf ADD `q20_enjoy_being_bounced_or_swung` enum('yes','no') default NULL AFTER `q20_movement_activities`;
ALTER TABLE m_chat_rf ADD `q20_laugh_or_smile` enum('yes','no') default NULL AFTER `q20_enjoy_being_bounced_or_swung`;
ALTER TABLE m_chat_rf ADD `q20_talk_or_babble` enum('yes','no') default NULL AFTER `q20_laugh_or_smile`;
ALTER TABLE m_chat_rf ADD `q20_request_more_by_holding_out_arm` enum('yes','no') default NULL AFTER `q20_talk_or_babble`;
ALTER TABLE m_chat_rf ADD `q20_other` enum('yes','no') default NULL AFTER `q20_request_more_by_holding_out_arm`;
ALTER TABLE m_chat_rf ADD `q20_if_other_describe` varchar(255) default NULL AFTER `q20_other`;

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('m_chat_rf', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);

DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label='V09';
DELETE FROM test_battery WHERE Test_name='m_chat_rf' AND Visit_label='V12';
