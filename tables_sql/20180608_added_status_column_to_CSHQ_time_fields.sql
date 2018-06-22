ALTER TABLE `CSHQ` ADD COLUMN `bed_time_status` enum('', 'not_answered') default NULL;
ALTER TABLE `CSHQ` MODIFY COLUMN `morning_waking_time_status` enum('', 'not_answered') default NULL;
