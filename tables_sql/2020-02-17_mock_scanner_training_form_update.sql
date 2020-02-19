-- ----------------------------------------
-- Each session now has its own page 
-- ----------------------------------------
DELETE FROM instrument_subtests WHERE test_name='mock_scanner_training_form';
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mock_scanner_training_form','mock_scanner_training_form_page1', "Page 1", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mock_scanner_training_form','mock_scanner_training_form_page2', "Page 2", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mock_scanner_training_form','mock_scanner_training_form_page3', "Page 3", 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mock_scanner_training_form','mock_scanner_training_form_page4', "Page 4", 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mock_scanner_training_form','mock_scanner_training_form_page5', "Page 5", 5);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mock_scanner_training_form','mock_scanner_training_form_page6', "Page 6", 6);



-- -----------------------------------------------------------
-- The max. nb. of sessions i snow 6, so all fields
-- related to sessions 7 & 8 are going away
-- As of 18Feb2020, there is no info in these columns anyway
-- -----------------------------------------------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN session_date_7_date;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_date_7_date_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN total_session_duration_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN total_session_duration_7_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_specialist_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_specialist_7_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN total_session_staffs_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN scan_attempt_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN scan_acquired_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN training_home_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN training_home_yes_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN training_home_yes_7_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN medication_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN medication_yes_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN medication_yes_7_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_social_story;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_mri_video;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_vsb;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_vt;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_vc;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_sb;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_spin_office_chair;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_fsv;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_wb;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_mod_sibling;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_motion_sensor;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_pref_video;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_increase_sound;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_verb_reminders;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_verbal_praise;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_edibale_treats;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_space_facade;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7_other_facade;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_comments_7;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_comments_7_status;

ALTER TABLE mock_scanner_training_form DROP COLUMN session_date_8_date;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_date_8_date_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN total_session_duration_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN total_session_duration_8_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_specialist_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_specialist_8_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN total_session_staffs_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN scan_attempt_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN scan_acquired_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN training_home_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN training_home_yes_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN training_home_yes_8_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN medication_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN medication_yes_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN medication_yes_8_status;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_social_story;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_mri_video;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_vsb;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_vt;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_vc;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_sb;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_spin_office_chair;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_fsv;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_wb;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_mod_sibling;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_motion_sensor;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_pref_video;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_increase_sound;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_verb_reminders;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_verbal_praise;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_edibale_treats;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_space_facade;
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8_other_facade;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_comments_8;
ALTER TABLE mock_scanner_training_form DROP COLUMN session_comments_8_status;


ALTER TABLE mock_scanner_training_form MODIFY COLUMN total_mock_sessions enum('1','2','3','4','5','6') DEFAULT NULL;

-- ----------------------------------------------
-- Choice 'NA' is removed. It's replaced by NULL
-- ----------------------------------------------
UPDATE mock_scanner_training_form SET scan_acquired_1 = NULL WHERE scan_attempt_1 != 'Yes' AND scan_acquired_1 = 'NA';
UPDATE mock_scanner_training_form SET scan_acquired_2 = NULL WHERE scan_attempt_2 != 'Yes' AND scan_acquired_2 = 'NA';
UPDATE mock_scanner_training_form SET scan_acquired_3 = NULL WHERE scan_attempt_3 != 'Yes' AND scan_acquired_3 = 'NA';
UPDATE mock_scanner_training_form SET scan_acquired_4 = NULL WHERE scan_attempt_4 != 'Yes' AND scan_acquired_4 = 'NA';
UPDATE mock_scanner_training_form SET scan_acquired_5 = NULL WHERE scan_attempt_5 != 'Yes' AND scan_acquired_5 = 'NA';
UPDATE mock_scanner_training_form SET scan_acquired_6 = NULL WHERE scan_attempt_6 != 'Yes' AND scan_acquired_6 = 'NA';

-- =========================
--
-- AT HOME TRAINING TOOLS
--
-- ========================

-- The values of these fields will have to manually be entered for
-- existing records based on the value of training_home_yes_1, which  
-- will have to be deleted afterwards
-- ----------------------------------------------------------------------
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_training_protocol_1    enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER training_home_yes_1_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_story_board_1          enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_training_protocol_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_social_story_1         enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_story_board_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_site_video_1           enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_social_story_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_generic_video_1        enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_site_video_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_body_awareness_video_1 enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_generic_video_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_1                varchar(255)         DEFAULT NULL AFTER tool_body_awareness_video_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_1_status         enum('not_answered') DEFAULT NULL AFTER tool_other_1;

-- ----------------------------------------------------------------------
-- The values of these fields will have to manually be entered for
-- existing records based on the value of training_home_yes_2, which  
-- will have to be deleted afterwards
-- ----------------------------------------------------------------------
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_training_protocol_2    enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER training_home_yes_2_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_story_board_2          enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_training_protocol_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_social_story_2         enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_story_board_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_site_video_2           enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_social_story_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_generic_video_2        enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_site_video_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_body_awareness_video_2 enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_generic_video_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_2                varchar(255)         DEFAULT NULL AFTER tool_body_awareness_video_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_2_status         enum('not_answered') DEFAULT NULL AFTER tool_other_2;

-- ----------------------------------------------------------------------
-- The values of these fields will have to manually be entered for
-- existing records based on the value of training_home_yes_3, which  
-- will have to be deleted afterwards
-- ----------------------------------------------------------------------
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_training_protocol_3    enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER training_home_yes_3_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_story_board_3          enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_training_protocol_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_social_story_3         enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_story_board_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_site_video_3           enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_social_story_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_generic_video_3        enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_site_video_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_body_awareness_video_3 enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_generic_video_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_3                varchar(255)         DEFAULT NULL AFTER tool_body_awareness_video_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_3_status         enum('not_answered') DEFAULT NULL AFTER tool_other_3;

-- ----------------------------------------------------------------------
-- The values of these fields will have to manually be entered for
-- existing records based on the value of training_home_yes_4, which  
-- will have to be deleted afterwards
-- ----------------------------------------------------------------------
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_training_protocol_4    enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER training_home_yes_4_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_story_board_4          enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_training_protocol_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_social_story_4         enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_story_board_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_site_video_4           enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_social_story_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_generic_video_4        enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_site_video_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_body_awareness_video_4 enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_generic_video_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_4                varchar(255)         DEFAULT NULL AFTER tool_body_awareness_video_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_4_status         enum('not_answered') DEFAULT NULL AFTER tool_other_4;

-- ----------------------------------------------------------------------
-- The values of these fields will have to manually be entered for
-- existing records based on the value of training_home_yes_5, which  
-- will have to be deleted afterwards
-- ----------------------------------------------------------------------
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_training_protocol_5    enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER training_home_yes_5_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_story_board_5          enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_training_protocol_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_social_story_5         enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_story_board_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_site_video_5           enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_social_story_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_generic_video_5        enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_site_video_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_body_awareness_video_5 enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_generic_video_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_5                varchar(255)         DEFAULT NULL AFTER tool_body_awareness_video_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_5_status         enum('not_answered') DEFAULT NULL AFTER tool_other_5;

-- ----------------------------------------------------------------------
-- The values of these fields will have to manually be entered for
-- existing records based on the value of training_home_yes_6, which  
-- will have to be deleted afterwards
-- ----------------------------------------------------------------------
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_training_protocol_6    enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER training_home_yes_6_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_story_board_6          enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_training_protocol_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_social_story_6         enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_story_board_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_site_video_6           enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_social_story_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_generic_video_6        enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_site_video_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_body_awareness_video_6 enum('Yes', 'No', 'dont_know')    DEFAULT NULL AFTER tool_generic_video_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_6                varchar(255)         DEFAULT NULL AFTER tool_body_awareness_video_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN tool_other_6_status         enum('not_answered') DEFAULT NULL AFTER tool_other_6;

UPDATE mock_scanner_training_form SET tool_generic_video_1 = bx_strategies_1_mri_video;
UPDATE mock_scanner_training_form SET tool_generic_video_2 = bx_strategies_2_mri_video;
UPDATE mock_scanner_training_form SET tool_generic_video_3 = bx_strategies_3_mri_video;
UPDATE mock_scanner_training_form SET tool_generic_video_4 = bx_strategies_4_mri_video;
UPDATE mock_scanner_training_form SET tool_generic_video_5 = bx_strategies_5_mri_video;
UPDATE mock_scanner_training_form SET tool_generic_video_6 = bx_strategies_6_mri_video;

-- ==================
--
-- REINFORCERS
--
-- ==================
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_preferred_treat_1  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER tool_other_1_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_preferred_treat_2  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER tool_other_2_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_preferred_treat_3  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER tool_other_3_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_preferred_treat_4  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER tool_other_4_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_preferred_treat_5  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER tool_other_5_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_preferred_treat_6  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER tool_other_6_status;

ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_generic_treat_1  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_preferred_treat_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_generic_treat_2  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_preferred_treat_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_generic_treat_3  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_preferred_treat_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_generic_treat_4  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_preferred_treat_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_generic_treat_5  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_preferred_treat_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_generic_treat_6  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_preferred_treat_6;

ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_prize_1  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_generic_treat_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_prize_2  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_generic_treat_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_prize_3  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_generic_treat_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_prize_4  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_generic_treat_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_prize_5  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_generic_treat_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_prize_6  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_generic_treat_6;

ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_social_reinforcer_1  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_prize_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_social_reinforcer_2  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_prize_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_social_reinforcer_3  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_prize_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_social_reinforcer_4  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_prize_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_social_reinforcer_5  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_prize_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_social_reinforcer_6  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_prize_6;

ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_delayed_reinforcer_1  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_social_reinforcer_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_delayed_reinforcer_2  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_social_reinforcer_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_delayed_reinforcer_3  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_social_reinforcer_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_delayed_reinforcer_4  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_social_reinforcer_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_delayed_reinforcer_5  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_social_reinforcer_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN reinforcer_delayed_reinforcer_6  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER reinforcer_social_reinforcer_6;


-- Yes, there is a typo
UPDATE mock_scanner_training_form SET reinforcer_generic_treat_1 = bx_strategies_1_edibale_treats;
UPDATE mock_scanner_training_form SET reinforcer_generic_treat_2 = bx_strategies_2_edibale_treats;
UPDATE mock_scanner_training_form SET reinforcer_generic_treat_3 = bx_strategies_3_edibale_treats;
UPDATE mock_scanner_training_form SET reinforcer_generic_treat_4 = bx_strategies_4_edibale_treats;
UPDATE mock_scanner_training_form SET reinforcer_generic_treat_5 = bx_strategies_5_edibale_treats;
UPDATE mock_scanner_training_form SET reinforcer_generic_treat_6 = bx_strategies_6_edibale_treats;

-- ==================
--
-- BX STRATEGIES
--
-- ==================


ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_listen_music  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_listen_music  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_listen_music  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_listen_music  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_listen_music  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_listen_music  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_increase_sound;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_body_awareness_video  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_listen_music;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_body_awareness_video  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_listen_music;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_body_awareness_video  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_listen_music;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_body_awareness_video  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_listen_music;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_body_awareness_video  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_listen_music;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_body_awareness_video  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_listen_music;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_competition  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_body_awareness_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_competition  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_body_awareness_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_competition  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_body_awareness_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_competition  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_body_awareness_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_competition  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_body_awareness_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_competition  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_body_awareness_video;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_face_camera  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_competition;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_face_camera  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_competition;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_face_camera  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_competition;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_face_camera  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_competition;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_face_camera  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_competition;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_face_camera  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_competition;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_generic_power_card  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_generic_power_card  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_generic_power_card  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_generic_power_card  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_generic_power_card  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_generic_power_card  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_fsv;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_token_board  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_generic_power_card;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_token_board  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_generic_power_card;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_token_board  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_generic_power_card;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_token_board  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_generic_power_card;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_token_board  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_generic_power_card;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_token_board  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_generic_power_card;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_power_cards_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_token_board;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_power_cards_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_token_board;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_power_cards_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_token_board;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_power_cards_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_token_board;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_power_cards_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_token_board;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_power_cards_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_token_board;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_shaping  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_power_cards_pref;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_shaping  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_power_cards_pref;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_shaping  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_power_cards_pref;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_shaping  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_power_cards_pref;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_shaping  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_power_cards_pref;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_shaping  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_power_cards_pref;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_dance_game  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_dance_game  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_dance_game  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_dance_game  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_dance_game  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_dance_game  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_social_story;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_token_board_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_dance_game;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_token_board_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_dance_game;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_token_board_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_dance_game;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_token_board_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_dance_game;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_token_board_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_dance_game;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_token_board_pref  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_dance_game;

ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_simon_says  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_simon_says  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_simon_says  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_simon_says  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_simon_says  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_simon_says  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_vt;

-- ==============
--
-- FACADES
--
-- ==============


ALTER TABLE mock_scanner_training_form ADD COLUMN facade_type_1 enum('none', 'space', 'other') DEFAULT NULL AFTER bx_strategies_1_simon_says;
ALTER TABLE mock_scanner_training_form ADD COLUMN facade_type_2 enum('none', 'space', 'other') DEFAULT NULL AFTER bx_strategies_2_simon_says;
ALTER TABLE mock_scanner_training_form ADD COLUMN facade_type_3 enum('none', 'space', 'other') DEFAULT NULL AFTER bx_strategies_3_simon_says;
ALTER TABLE mock_scanner_training_form ADD COLUMN facade_type_4 enum('none', 'space', 'other') DEFAULT NULL AFTER bx_strategies_4_simon_says;
ALTER TABLE mock_scanner_training_form ADD COLUMN facade_type_5 enum('none', 'space', 'other') DEFAULT NULL AFTER bx_strategies_5_simon_says;
ALTER TABLE mock_scanner_training_form ADD COLUMN facade_type_6 enum('none', 'space', 'other') DEFAULT NULL AFTER bx_strategies_6_simon_says;

ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_1 text DEFAULT NULL AFTER facade_type_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_2 text DEFAULT NULL AFTER facade_type_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_3 text DEFAULT NULL AFTER facade_type_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_4 text DEFAULT NULL AFTER facade_type_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_5 text DEFAULT NULL AFTER facade_type_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_6 text DEFAULT NULL AFTER facade_type_6;

ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_1_status enum('not_answered') DEFAULT NULL AFTER other_facade_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_2_status enum('not_answered') DEFAULT NULL AFTER other_facade_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_3_status enum('not_answered') DEFAULT NULL AFTER other_facade_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_4_status enum('not_answered') DEFAULT NULL AFTER other_facade_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_5_status enum('not_answered') DEFAULT NULL AFTER other_facade_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN other_facade_6_status enum('not_answered') DEFAULT NULL AFTER other_facade_6;

UPDATE mock_scanner_training_form SET facade_type_1 = 'none' WHERE bx_strategies_1_space_facade = 'No' AND bx_strategies_1_other_facade = 'No';
UPDATE mock_scanner_training_form SET facade_type_2 = 'none' WHERE bx_strategies_2_space_facade = 'No' AND bx_strategies_2_other_facade = 'No';
UPDATE mock_scanner_training_form SET facade_type_3 = 'none' WHERE bx_strategies_3_space_facade = 'No' AND bx_strategies_3_other_facade = 'No';
UPDATE mock_scanner_training_form SET facade_type_4 = 'none' WHERE bx_strategies_4_space_facade = 'No' AND bx_strategies_4_other_facade = 'No';
UPDATE mock_scanner_training_form SET facade_type_5 = 'none' WHERE bx_strategies_5_space_facade = 'No' AND bx_strategies_5_other_facade = 'No';
UPDATE mock_scanner_training_form SET facade_type_6 = 'none' WHERE bx_strategies_6_space_facade = 'No' AND bx_strategies_6_other_facade = 'No';

UPDATE mock_scanner_training_form SET facade_type_1 = 'space' WHERE bx_strategies_1_space_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_2 = 'space' WHERE bx_strategies_2_space_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_3 = 'space' WHERE bx_strategies_3_space_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_4 = 'space' WHERE bx_strategies_4_space_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_5 = 'space' WHERE bx_strategies_5_space_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_6 = 'space' WHERE bx_strategies_6_space_facade = 'Yes';

UPDATE mock_scanner_training_form SET facade_type_1 = 'other' WHERE bx_strategies_1_other_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_2 = 'other' WHERE bx_strategies_2_other_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_3 = 'other' WHERE bx_strategies_3_other_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_4 = 'other' WHERE bx_strategies_4_other_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_5 = 'other' WHERE bx_strategies_5_other_facade = 'Yes';
UPDATE mock_scanner_training_form SET facade_type_6 = 'other' WHERE bx_strategies_6_other_facade = 'Yes';

-- Old columns bx_strategies_$i_space_facade and bx_strategies_$i_other_facade can now be deleted

-- We can't fill the other_facade_$i for old records since we do not have that information....

