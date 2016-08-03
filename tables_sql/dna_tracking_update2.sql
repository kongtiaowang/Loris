ALTER TABLE dna_tracking ADD COLUMN `Window_Difference` varchar(255) default NULL AFTER `Data_entry_completion_status`;
ALTER TABLE dna_tracking ADD COLUMN `Candidate_Age` varchar(255) default NULL AFTER `Data_entry_completion_status`;
ALTER TABLE dna_tracking ADD COLUMN `Date_taken` date default NULL AFTER `Data_entry_completion_status`;
