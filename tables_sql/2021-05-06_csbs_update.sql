-- ----------------------------------------------------------
--
-- Modifications done to the CSBS based on the SME comments.
-- 
-- See https://redmine.cbrain.mcgill.ca/issues/18817. 
--
-- ----------------------------------------------------------

ALTER TABLE csbs DROP COLUMN q_1_alertness;
ALTER TABLE csbs DROP COLUMN q_2_emotional_reaction;
ALTER TABLE csbs DROP COLUMN q_3_level_of_interest;
ALTER TABLE csbs DROP COLUMN q_4_comfort_level;
ALTER TABLE csbs DROP COLUMN q_5_level_of_activity;
ALTER TABLE csbs DROP COLUMN q_6_level_of_communication;
ALTER TABLE csbs DROP COLUMN q_7_play_behaviour;
