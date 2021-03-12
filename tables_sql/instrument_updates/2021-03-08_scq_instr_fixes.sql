ALTER TABLE scq_subject_survey ADD COLUMN Candidate_Age varchar(20) DEFAULT NULL AFTER Date_taken;
ALTER TABLE scq_subject_survey ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;
ALTER TABLE scq_proband_survey ADD COLUMN Candidate_Age varchar(20) DEFAULT NULL AFTER Date_taken;
ALTER TABLE scq_proband_survey ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;