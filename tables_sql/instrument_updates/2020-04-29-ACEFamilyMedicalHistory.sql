ALTER TABLE ACEFamilyMedicalHistory ADD `Date_taken` date AFTER Data_entry_completion_status;
ALTER TABLE ACEFamilyMedicalHistory ADD `Candidate_Age` varchar(20) AFTER Date_taken;
ALTER TABLE ACEFamilyMedicalHistory ADD `Window_Difference` varchar(20) AFTER Candidate_Age;
