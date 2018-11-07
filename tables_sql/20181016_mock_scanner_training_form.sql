-- -------------------------------------------------------------------------------
-- Update for the mock_scanner_training_form table
--
-- 1. Converts previous  bx_strategies_* to radio buttons (one for each choice)
-- 2. Adds two new radio buttons: 'space facade' and 'other facade'
--
-- -------------------------------------------------------------------------------

-- ------------------
-- Strategy #1
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_1;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_1_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_1_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_1_space_facade;


-- ------------------
-- Strategy #2
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_2;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_2_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_2_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_2_space_facade;

-- ------------------
-- Strategy #3
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_3;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_3_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_3_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_3_space_facade;

-- ------------------
-- Strategy #4
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_4;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_4_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_4_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_4_space_facade;

-- ------------------
-- Strategy #5
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_5;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_5_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_5_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_5_space_facade;

-- ------------------
-- Strategy #6
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_6;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_6_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_6_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_6_space_facade;

-- ------------------
-- Strategy #7
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_7;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_7_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_7_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_7_space_facade;

-- ------------------
-- Strategy #8
-- ------------------
ALTER TABLE mock_scanner_training_form DROP COLUMN bx_strategies_8;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_social_story       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER medication_yes_8_status;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_mri_video          enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_social_story;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_vsb                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_mri_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_vt                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_vsb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_vc                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_vt;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_sb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_vc;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_spin_office_chair  enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_sb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_fsv                enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_spin_office_chair;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_wb                 enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_fsv;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_mod_sibling        enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_wb;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_motion_sensor      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_mod_sibling;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_pref_video         enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_motion_sensor;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_increase_sound     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_pref_video;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_verb_reminders     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_increase_sound;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_verbal_praise      enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_verb_reminders;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_edibale_treats     enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_verbal_praise;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_space_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_edibale_treats;
ALTER TABLE mock_scanner_training_form ADD COLUMN bx_strategies_8_other_facade       enum('Yes', 'No', 'dont_know') DEFAULT NULL AFTER bx_strategies_8_space_facade;
