ALTER TABLE `BISQ_survey` MODIFY COLUMN `birth_order` enum('oldest','middle','youngest','not_answered','step_father') DEFAULT NULL;

ALTER TABLE BISQ_survey MODIFY COLUMN night_sleep_status enum('', 'dnk','refusal','not_answered') default NULL;
ALTER TABLE BISQ_survey MODIFY COLUMN day_sleep_status enum('', 'dnk','refusal','not_answered') default NULL;
ALTER TABLE BISQ_survey MODIFY COLUMN night_wakefullness_status enum('', 'dnk','refusal','not_answered') default NULL;
ALTER TABLE BISQ_survey MODIFY COLUMN time_to_put_to_sleep_status enum('', 'dnk','refusal','not_answered') default NULL;
ALTER TABLE BISQ_survey MODIFY COLUMN when_fall_asleep_status enum('', 'dnk','refusal','not_answered') default NULL;
