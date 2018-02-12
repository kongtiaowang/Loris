-- Some instruments need to updated as survey instruments for IBIS3
UPDATE `test_names` SET `IsDirectEntry`=1 WHERE `Test_name`='CBCL';
UPDATE `test_names` SET `IsDirectEntry`=1 WHERE `Test_name`='rbs_r';
UPDATE `test_names` SET `IsDirectEntry`=1 WHERE `Test_name`='ADULT_SELF_REPORT';

-- ASR instrument should populate across all subprojects for VSA in IBIS3
-- Update already inserted  with ASR to Active 'N' to avoid confusions
UPDATE `test_battery` SET `Active` ='N' WHERE `Test_name`='ADULT_SELF_REPORT';
-- fresh and correct test battery inserts for ASR
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ADULT_SELF_REPORT', '0', '0', 'Y', 'Visit', '12', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ADULT_SELF_REPORT', '0', '0', 'Y', 'Visit', '13', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ADULT_SELF_REPORT', '0', '0', 'Y', 'Visit', '14', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ADULT_SELF_REPORT', '0', '0', 'Y', 'Visit', '15', 'VSA', NULL);
