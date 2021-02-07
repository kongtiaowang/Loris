ALTER TABLE `APSI` DROP COLUMN `speech_loss_occurred_before_eye_loss`, DROP COLUMN `speech_loss_occurred_after_eye_loss`, DROP COLUMN `speech_loss_occurred_close_to_eye_loss`;
ALTER TABLE `APSI` ADD COLUMN `speech_loss_happened_when` TEXT default NULL AFTER `other_skills_lost`;
