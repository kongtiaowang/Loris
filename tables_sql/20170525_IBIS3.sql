ALTER TABLE `session` DROP COLUMN PSCID ;
CREATE TABLE candidate_project_rel (
	ID INT(11) unsigned NOT NULL AUTO_INCREMENT,
	CandID INT(6) unsigned NOT NULL,
	ProjectID INT(2) unsigned NOT NULL,
	StartDate DATE NOT NULL,
	PRIMARY KEY  (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO project_rel (ProjectID,SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS3'),(SELECT SubprojectID FROM subproject WHERE title='ASD+ HR')) ;
INSERT INTO project_rel (ProjectID,SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS3'),(SELECT SubprojectID FROM subproject WHERE title='ASD- HR')) ;
INSERT INTO project_rel (ProjectID,SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS3'),(SELECT SubprojectID FROM subproject WHERE title='ASD+ LR')) ;
INSERT INTO project_rel (ProjectID,SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS3'),(SELECT SubprojectID FROM subproject WHERE title='ASD- LR')) ;
INSERT INTO project_rel (ProjectID,SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS3'),(SELECT SubprojectID FROM subproject WHERE title='ND')) ;
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label) VALUES 
('seq', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('seq', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('seq', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('seq', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('seq', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('CBCL', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('CBCL', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('CBCL', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('CBCL', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('CBCL', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('ados2_module1', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('ados2_module1', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('ados2_module1', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('ados2_module1', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('ados2_module1', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('ados2_module2', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('ados2_module2', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('ados2_module2', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('ados2_module2', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('ados2_module2', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('ados2_module3', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('ados2_module3', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('ados2_module3', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('ados2_module3', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('ados2_module3', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('adi_r_subject', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('adi_r_subject', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('adi_r_subject', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('adi_r_subject', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('adi_r_subject', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('med_records_recruit', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('med_records_recruit', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('med_records_recruit', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('med_records_recruit', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('med_records_recruit', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('vineland_subject', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('vineland_subject', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('vineland_subject', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('vineland_subject', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('vineland_subject', 0, 0, 'Y', 'Visit', 16, 'VSA'),
('das_schoolage', 0, 0, 'Y', 'Visit', 12, 'VSA'),
('das_schoolage', 0, 0, 'Y', 'Visit', 13, 'VSA'),
('das_schoolage', 0, 0, 'Y', 'Visit', 14, 'VSA'),
('das_schoolage', 0, 0, 'Y', 'Visit', 15, 'VSA'),
('das_schoolage', 0, 0, 'Y', 'Visit', 16, 'VSA');
