ALTER TABLE `TSI_EP` ADD COLUMN `mother_dob_date_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` ADD COLUMN `father_dob_date_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` ADD COLUMN `father_occupation_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` ADD COLUMN `mother_occupation_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` CHANGE COLUMN mother_dob mother_dob_date DATE default NULL;
ALTER TABLE `TSI_EP` CHANGE COLUMN father_dob father_dob_date DATE default NULL;