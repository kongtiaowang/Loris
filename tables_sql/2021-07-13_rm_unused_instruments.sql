-- --------------------------------------------------------------------------------
-- 
-- Instruments caars_SelfReport_scale, SCAARED_Adult, and SCARED_Child were
-- created but never used. This SQL patch deletes the records associated with
-- these instruments from tables flag, participant_acounts and survey_test_battery
-- 
-- --------------------------------------------------------------------------------

DELETE FROM flag                WHERE test_name IN ('caars_SelfReport_scale', 'SCAARED_Adult', 'SCARED_Child');
DELETE FROM participant_acounts WHERE test_name IN ('caars_SelfReport_scale', 'SCAARED_Adult', 'SCARED_Child');
DELETE FROM survey_test_battery WHERE test_name IN ('caars_SelfReport_scale', 'SCAARED_Adult', 'SCARED_Child');
