ALTER TABLE `participant_status` ADD COLUMN `mail_toothkit_consent` ENUM('yes','no','not_answered') DEFAULT NULL;
ALTER TABLE `participant_status` ADD COLUMN `mail_toothkit_consent_date` DATE DEFAULT NULL;
ALTER TABLE `participant_status` ADD COLUMN `mail_toothkit_consent_withdrawal` DATE DEFAULT NULL;
-- Ignore the very next line if it is already created on production --
ALTER TABLE `consent_info_history` ADD COLUMN `mail_toothkit_consent` ENUM('yes','no','not_answered') DEFAULT NULL;
ALTER TABLE `consent_info_history` ADD COLUMN `mail_toothkit_consent_date` DATE DEFAULT NULL;
ALTER TABLE `consent_info_history` ADD COLUMN `mail_toothkit_consent_withdrawal` DATE DEFAULT NULL;