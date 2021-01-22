ALTER TABLE `TSI_EP` ADD COLUMN `mother_dob_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` ADD COLUMN `father_dob_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` ADD COLUMN `father_occupation_status` enum('not_answered') DEFAULT NULL;
ALTER TABLE `TSI_EP` ADD COLUMN `mother_occupation_status` enum('not_answered') DEFAULT NULL;