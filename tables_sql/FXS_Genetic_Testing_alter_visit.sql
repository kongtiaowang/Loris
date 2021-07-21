DELETE FROM test_battery WHERE Test_name='FXS_Genetic_Testing' AND SubprojectID=7;

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FXS_Genetic_Testing', '0', '0', 'Y', 'Visit', 20, 'iDS-FOH', NULL);
