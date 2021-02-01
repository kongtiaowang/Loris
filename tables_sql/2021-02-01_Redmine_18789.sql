ALTER TABLE `MEQC_survey` MODIFY COLUMN `respondent` enum('child','mother','father','step_mother','step_father','other') default NULL;
ALTER TABLE `MEQC_survey` CHANGE `respondent_specify` `other_specify` varchar(255) default NULL;
ALTER TABLE `MEQC_survey` ADD `respondent_explain` varchar(255) default NULL AFTER `respondent`;