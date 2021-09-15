ALTER TABLE BRQ_survey ADD COLUMN consistency_total_derived_score varchar(255) default NULL;
ALTER TABLE BRQ_survey ADD COLUMN reactivity_total_derived_score varchar(255) default NULL;
ALTER TABLE BRQ_survey ADD COLUMN adaptive_activities_total_derived_score varchar(255) default NULL;
ALTER TABLE BRQ_survey ADD COLUMN maladaptive_activities_total_derived_score varchar(255) default NULL;
