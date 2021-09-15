INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='Proband iPSC UNC' LIMIT 1), 'VSA-PR-IPSC', NULL);
