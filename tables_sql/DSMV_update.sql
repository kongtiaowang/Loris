ALTER TABLE DSMV_checklist MODIFY COLUMN `qa1_deficit_communication_social` enum('yes','no','not_answered') default NULL;
ALTER TABLE DSMV_checklist MODIFY COLUMN `qa2_change_communication` enum('yes','no','not_answered') default NULL;
ALTER TABLE DSMV_checklist MODIFY COLUMN `qa3_deficit_followrules` enum('yes','no','not_answered') default NULL;
ALTER TABLE DSMV_checklist MODIFY COLUMN `qb_limit_communication` enum('yes','no','not_answered') default NULL;
ALTER TABLE DSMV_checklist MODIFY COLUMN `qc_onset_earlychildhood` enum('yes','no','not_answered') default NULL;
ALTER TABLE DSMV_checklist MODIFY COLUMN `meet_dsm_scd` enum('yes','no','not_answered') default NULL;
ALTER TABLE DSMV_checklist MODIFY COLUMN `dsm_scd_confidence` enum('3_very_confident','2_somewhat_confident','1_not_confident','not_answered') default NULL;