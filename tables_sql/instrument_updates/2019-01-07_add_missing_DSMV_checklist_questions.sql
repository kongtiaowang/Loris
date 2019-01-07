-- Adding missing questions to DSMV_checklist
ALTER TABLE DSMV_checklist ADD COLUMN qd_medical_condition enum('yes','no','not_applicable') default NULL ;
ALTER TABLE DSMV_checklist ADD COLUMN met_criteria_adi_r enum('yes','no','not_applicable') default NULL ;
ALTER TABLE DSMV_checklist ADD COLUMN met_criteria_ados2 enum('yes','no','not_applicable') default NULL ;
ALTER TABLE DSMV_checklist ADD COLUMN discussed_adir_ados2_scores enum('yes','no','not_applicable') default NULL ;
