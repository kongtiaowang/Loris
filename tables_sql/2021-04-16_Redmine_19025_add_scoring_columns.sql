-- Redmine 19025: Add scoring columns
ALTER TABLE Seizure_Questionnaire ADD COLUMN seizure_screening_total_score varchar(255) default NULL AFTER relationship_to_child_other;
ALTER TABLE Seizure_Questionnaire ADD COLUMN subscale1_seizure_frequency_score varchar(255) default NULL AFTER seizure_screening_total_score;
ALTER TABLE Seizure_Questionnaire ADD COLUMN subscale2_time_period_score varchar(255) default NULL AFTER subscale1_seizure_frequency_score;
ALTER TABLE Seizure_Questionnaire ADD COLUMN subscale3_num_of_seizure_types_score varchar(255) default NULL AFTER subscale2_time_period_score;
ALTER TABLE Seizure_Questionnaire ADD COLUMN subscale4_epilepticus_score varchar(255) default NULL AFTER subscale3_num_of_seizure_types_score;
ALTER TABLE Seizure_Questionnaire ADD COLUMN total_severity_score varchar(255) default NULL AFTER subscale4_epilepticus_score;