-- Adding missing questions to BISQ_Survey
ALTER TABLE BISQ_survey ADD COLUMN night_sleep_hours varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN night_sleep_mins varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN day_sleep_hours varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN day_sleep_mins varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN night_wakefullness_hours varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN night_wakefullness_mins varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN time_to_put_to_sleep_hours varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN time_to_put_to_sleep_mins varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN when_fall_asleep_hours varchar(15) default NULL ;
ALTER TABLE BISQ_survey ADD COLUMN when_fall_asleep_mins varchar(15) default NULL ;
