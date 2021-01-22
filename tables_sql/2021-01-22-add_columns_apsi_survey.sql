ALTER TABLE `apsi_survey` ADD COLUMN `Candidate_Age` VARCHAR(255) DEFAULT NULL;
ALTER TABLE `apsi_survey` ADD COLUMN `Window_Difference` INT(11) DEFAULT NULL;
ALTER TABLE `apsi_survey` ADD COLUMN`Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP;
ALTER TABLE `apsi_survey`ADD COLUMN`Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete';

UPDATE apsi_survey aps INNER JOIN flag f ON (f.CommentID = aps.CommentID) SET aps.Data_entry_completion_status = 'Incomplete'
WHERE f.Data_entry = 'In Progress' and f.test_name='apsi_survey';
UPDATE apsi_survey aps INNER JOIN flag f ON (f.CommentID = aps.CommentID) SET aps.Data_entry_completion_status = 'Complete'
WHERE f.Data_entry = 'Complete' and f.test_name='apsi_survey';