-- As we need Date of Administration to be populated in survey instruments, we need to add this common colums to the tables---
ALTER TABLE `peer_socialcontact` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `peer_socialcontact` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;

ALTER TABLE `sibling_socialcontact` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `sibling_socialcontact` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;

ALTER TABLE `pspq_1` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `pspq_1` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;

ALTER TABLE `pspq_2` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `pspq_2` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;

ALTER TABLE `SRS2_2` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `SRS2_1` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;

ALTER TABLE `SRS2_InformantReport` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `SRS2_InformantReport` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;

ALTER TABLE `SRS2_SelfReport` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `SRS2_SelfReport` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;
