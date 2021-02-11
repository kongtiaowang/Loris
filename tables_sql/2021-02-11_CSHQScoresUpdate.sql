-- --------------------------------------------------------------------------------
--  
-- Make all score fields in instrument CSHQ have names of the form 'score_*'
--
-- --------------------------------------------------------------------------------
ALTER TABLE CSHQ CHANGE COLUMN `bedtime_resistance`         `score_bedtime_resistance`         VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `sleep_onset_delay`          `score_sleep_onset_delay`          VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `sleep_duration`             `score_sleep_duration`             VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `sleep_anxiety`              `score_sleep_anxiety`              VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `night_wakings`              `score_night_wakings`              VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `parasomnias`                `score_parasomnias`                VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `sleep_disordered_breathing` `score_sleep_disordered_breathing` VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `daytime_sleepiness`         `score_daytime_sleepiness`         VARCHAR(255) DEFAULT NULL;
ALTER TABLE CSHQ CHANGE COLUMN `total_score`                `score_total`                      VARCHAR(255) DEFAULT NULL;
