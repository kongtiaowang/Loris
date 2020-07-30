ALTER TABLE CSHQ ADD COLUMN bed_time_hours varchar(10) AFTER bed_time;
ALTER TABLE CSHQ ADD COLUMN bed_time_mins varchar(10) AFTER bed_time_hours;
ALTER TABLE CSHQ MODIFY COLUMN bed_time_status enum('', 'dnk','refusal','not_answered');
ALTER TABLE CSHQ ADD COLUMN sleep_behavior_duration_hours varchar(10) AFTER sleep_behavior_duration;
ALTER TABLE CSHQ ADD COLUMN sleep_behavior_duration_mins varchar(10) AFTER sleep_behavior_duration_hours;
ALTER TABLE CSHQ ADD COLUMN morning_waking_time_hours varchar(10) AFTER morning_waking_time;
ALTER TABLE CSHQ ADD COLUMN morning_waking_time_mins varchar(10) AFTER morning_waking_time_hours;
ALTER TABLE CSHQ MODIFY COLUMN `sleep_behavior_duration_status` enum('', 'dnk','refusal','not_answered');
ALTER TABLE CSHQ MODIFY COLUMN `morning_waking_time_status` enum('', 'dnk','refusal','not_answered');