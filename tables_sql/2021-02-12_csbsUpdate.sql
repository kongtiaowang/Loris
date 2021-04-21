-- ---------------------------------------------------
--
-- Updates to the casb questionnaire according to 
-- https://redmine.cbrain.mcgill.ca/issues/18817
--
-- ---------------------------------------------------

-- -----------------------------------------
-- Add a comment field for all activities
-- -----------------------------------------
ALTER TABLE csbs ADD COLUMN wind_up_admin_comment VARCHAR(255) DEFAULT NULL AFTER wind_up_admin;
ALTER TABLE csbs ADD COLUMN balloon_admin_comment VARCHAR(255) DEFAULT NULL AFTER balloon_admin;
ALTER TABLE csbs ADD COLUMN bubbles_admin_comment VARCHAR(255) DEFAULT NULL AFTER bubbles_admin;
ALTER TABLE csbs ADD COLUMN books_admin_comment   VARCHAR(255) DEFAULT NULL AFTER books_admin;
ALTER TABLE csbs ADD COLUMN jar_admin_comment     VARCHAR(255) DEFAULT NULL AFTER jar_admin;
ALTER TABLE csbs ADD COLUMN play_admin_comment    VARCHAR(255) DEFAULT NULL AFTER play_admin;

-- -------------------------------------------------------
-- Add new enum to store whether the gaze point following
-- was administered or not. Set value of this new field
-- to 'yes' for all existing instruments.
-- -------------------------------------------------------
ALTER TABLE csbs ADD COLUMN q_3_gaze_point_following_admin enum('yes', 'no') DEFAULT NULL AFTER q_3_gaze_point_following_5;
UPDATE csbs SET q_3_gaze_point_following_admin='yes' WHERE CommentID NOT LIKE 'DDE%';

-- ----------------------------------------------
-- All standard scores and percentile ranks are
-- now varchars since they can have value 
-- 'Unable to score'
-- ----------------------------------------------
ALTER TABLE csbs MODIFY emotion_eye_gaze_standard     VARCHAR(255);
ALTER TABLE csbs MODIFY emotion_eye_gaze_percentile   VARCHAR(255);

ALTER TABLE csbs MODIFY communication_standard        VARCHAR(255);
ALTER TABLE csbs MODIFY communication_percentile      VARCHAR(255);

ALTER TABLE csbs MODIFY gestures_standard             VARCHAR(255);
ALTER TABLE csbs MODIFY gestures_percentile           VARCHAR(255);

ALTER TABLE csbs MODIFY sounds_standard               VARCHAR(255);
ALTER TABLE csbs MODIFY sounds_percentile             VARCHAR(255);

ALTER TABLE csbs MODIFY words_standard                VARCHAR(255);
ALTER TABLE csbs MODIFY words_percentile              VARCHAR(255);

ALTER TABLE csbs MODIFY understanding_standard        VARCHAR(255);
ALTER TABLE csbs MODIFY understanding_percentile      VARCHAR(255);

ALTER TABLE csbs MODIFY object_use_standard           VARCHAR(255);
ALTER TABLE csbs MODIFY object_use_percentile         VARCHAR(255);

ALTER TABLE csbs MODIFY social_composite_score        VARCHAR(255);
ALTER TABLE csbs MODIFY social_composite_standard     VARCHAR(255);
ALTER TABLE csbs MODIFY social_composite_percentile   VARCHAR(255);

ALTER TABLE csbs MODIFY speech_composite_score        VARCHAR(255);
ALTER TABLE csbs MODIFY speech_composite_standard     VARCHAR(255);
ALTER TABLE csbs MODIFY speech_composite_percentile   VARCHAR(255);

ALTER TABLE csbs MODIFY symbolic_composite_score      VARCHAR(255);
ALTER TABLE csbs MODIFY symbolic_composite_standard   VARCHAR(255);
ALTER TABLE csbs MODIFY symbolic_composite_percentile VARCHAR(255);

ALTER TABLE csbs MODIFY total_weighted_raw_score      VARCHAR(255);
ALTER TABLE csbs MODIFY total_standard                VARCHAR(255);
ALTER TABLE csbs MODIFY total_percentile              VARCHAR(255);

-- ------------------------------------------------------------------
-- Add new option to q_20_stacks_tower enum: probe_not_administered
-- ------------------------------------------------------------------
ALTER TABLE csbs MODIFY q_20_stacks_tower enum('0_refuses','1_tries_but_fails','2_stacks','3_stacks','4_stacks','5_stacks','not_administered', 'probe_not_administered');

