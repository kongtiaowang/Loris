-- ------------------------------------------------------
-- Adds the ADI-R Proband form to the V12 visit for
-- subproject IDS 18 and 19
-- ------------------------------------------------------

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_proband', '0', '0', 'Y', 'Visit', 18 , 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_proband', '0', '0', 'Y', 'Visit', 19 , 'V12', NULL);

-- ------------------------------------------------------
-- Adds the ADI-R Proband form to the V12-CVD visit for
-- subproject IDS 18 and 19
-- ------------------------------------------------------

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_proband', '0', '0', 'Y', 'Visit', 18 , 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('adi_r_proband', '0', '0', 'Y', 'Visit', 19 , 'V12-CVD', NULL);

