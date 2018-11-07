-- Fixing Issues with CDI Words and Sentences
-- Adding missing columns
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `part_2_b_nouns` VARCHAR(50) NULL DEFAULT NULL;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `part_2_e_second_choice_count` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `part_2_e_first_choice_count` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `words_produced` VARCHAR(50) NULL DEFAULT NULL;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `word_forms` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `part_2_b_verbs` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `grammatical_complexity_percentile` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `word_endings_plural_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `word_endings_possessive_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `word_endings_past_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `word_endings_progressive_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `how_use_absent_comp_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `how_use_absent_owner_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `how_use_absent_production_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `how_use_future_percentage` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `how_use_past_percentage` VARCHAR(50) NULL DEFAULT NULL ;
-- 2nd set
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `words_produced_number` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `grammatical_complexity_number` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `word_endings_part_2_number` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `sentence_1_morpheme_count` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `sentence_2_morpheme_count` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `sentence_3_morpheme_count` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `m3l_number` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `m3l_percentile` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN part_2_e_36 enum('two_shoe','two_shoes') default NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN part_2_e_37 enum('daddy_car','daddys_car') default NULL ;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN part_2_c_nouns VARCHAR(50) NULL DEFAULT NULL;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN part_2_c_verbs VARCHAR(50) NULL DEFAULT NULL;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN word_endings_plural VARCHAR(50) NULL DEFAULT NULL;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN word_endings_part2 VARCHAR(50) NULL DEFAULT NULL;
ALTER TABLE `CDI_Words_Sentences` ADD COLUMN `words_forms_number` VARCHAR(50) NULL DEFAULT NULL ;
-- Increasing the varchar limit(currently set to 3 but Not able to score sentence is supposed to score as per scoring algorithm)
ALTER TABLE `CDI_Words_Sentences`
CHANGE COLUMN `part_2_d_1` `part_2_d_1` VARCHAR(100) NULL DEFAULT NULL ,
CHANGE COLUMN `part_2_d_2` `part_2_d_2` VARCHAR(100) NULL DEFAULT NULL ,
CHANGE COLUMN `part_2_d_3` `part_2_d_3` VARCHAR(100) NULL DEFAULT NULL ;

ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `words_produced_percentile` `words_produced_percentile` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `word_endings_plural` `word_endings_plural` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `word_endings_possessive` `word_endings_possessive` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `word_endings_past` `word_endings_past` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `word_endings_progressive` `word_endings_progressive` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `how_use_absent_comp` `how_use_absent_comp` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `how_use_absent_owner` `how_use_absent_owner` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `how_use_absent_production` `how_use_absent_production` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `how_use_future` `how_use_future` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `how_use_past` `how_use_past` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `grammatical_complexity` `grammatical_complexity` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `part1_wpNum` `part1_wpNum` VARCHAR(50) NULL DEFAULT NULL ;
ALTER TABLE `CDI_Words_Sentences` CHANGE COLUMN `word_forms_percentile` `word_forms_percentile` VARCHAR(50) NULL DEFAULT NULL ;



