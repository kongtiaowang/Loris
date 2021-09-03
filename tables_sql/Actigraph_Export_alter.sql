ALTER TABLE Actigraph_Export ADD COLUMN UserID    varchar(255) DEFAULT NULL AFTER Window_Difference;
ALTER TABLE Actigraph_Export ADD COLUMN Status    varchar(255) DEFAULT NULL AFTER UserID;
ALTER TABLE Actigraph_Export ADD COLUMN File_type varchar(255) DEFAULT NULL AFTER Status;
ALTER TABLE Actigraph_Export ADD COLUMN Data_dir  varchar(255) DEFAULT NULL AFTER File_type;

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 1, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 2, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 3, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 9, 'VSA-Sleep', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Actigraph_Export', '0', '0', 'Y', 'Visit', 10, 'VSA-Sleep', NULL);

-- DELETE Instrument from survey battery

DELETE FROM survey_test_battery WHERE Test_name='Actigraph_Export';
