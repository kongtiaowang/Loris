ALTER TABLE pspq_InformantReport_dad_on_mom ADD COLUMN Date_taken DATE DEFAULT NULL AFTER Data_entry_completion_status;
ALTER TABLE pspq_InformantReport_mom_on_dad ADD COLUMN Date_taken DATE DEFAULT NULL AFTER Data_entry_completion_status;
ALTER TABLE pspq_SelfReport_dad ADD COLUMN Date_taken DATE DEFAULT NULL AFTER Data_entry_completion_status;
ALTER TABLE pspq_SelfReport_mom ADD COLUMN Date_taken DATE DEFAULT NULL AFTER Data_entry_completion_status;

ALTER TABLE pspq_InformantReport_dad_on_mom ADD COLUMN Candidate_Age varchar(20) DEFAULT NULL AFTER Date_taken;
ALTER TABLE pspq_InformantReport_mom_on_dad ADD COLUMN Candidate_Age varchar(20) DEFAULT NULL AFTER Date_taken;
ALTER TABLE pspq_SelfReport_dad ADD COLUMN Candidate_Age varchar(20) DEFAULT NULL AFTER Date_taken;
ALTER TABLE pspq_SelfReport_mom ADD COLUMN Candidate_Age varchar(20) DEFAULT NULL AFTER Date_taken;

ALTER TABLE pspq_InformantReport_dad_on_mom ADD COLUMN Window_Difference varchar(20) DEFAULT NULL AFTER Candidate_Age;
ALTER TABLE pspq_InformantReport_mom_on_dad ADD COLUMN Window_Difference varchar(20) DEFAULT NULL AFTER Candidate_Age;
ALTER TABLE pspq_SelfReport_dad ADD COLUMN Window_Difference varchar(20) DEFAULT NULL AFTER Candidate_Age;
ALTER TABLE pspq_SelfReport_mom ADD COLUMN Window_Difference varchar(20) DEFAULT NULL AFTER Candidate_Age;
