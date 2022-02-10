ALTER TABLE TSI_SA ADD `candidate_race` varchar(128) default NULL;
ALTER TABLE TSI_SA ADD `bio_mother_race` varchar(128) default NULL;
ALTER TABLE TSI_SA ADD `bio_father_race` varchar(128) default NULL;
ALTER TABLE TSI_SA ADD `candidate_ethnicity` enum('hispanic','non_hispanic') default NULL;
ALTER TABLE TSI_SA ADD `bio_mother_ethnicity` enum('hispanic','non_hispanic') default NULL;
ALTER TABLE TSI_SA ADD `bio_father_ethnicity` enum('hispanic','non_hispanic') default NULL;
