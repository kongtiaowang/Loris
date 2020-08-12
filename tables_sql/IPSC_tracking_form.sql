CREATE TABLE `IPSC_tracking_form` (
    `CommentID` varchar(255) NOT NULL default '',
    `UserID` varchar(255) default NULL,
    `Examiner` varchar(255) default NULL,
    `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
    `Date_taken` date default NULL,
    `Candidate_Age` varchar(255) default NULL,
    `Window_Difference` varchar(255) default NULL,
    `recruiter_asked_blood_draw` enum('not_yet_called','yes','no') default NULL,
    `IPSC_consent_date` date default NULL,
    `blood_draw_location` enum('site','take_home_kit_sent') default NULL,
    `fedex_tracking_number` text default NULL,
    `blood_draw_date` date default NULL,
    `ipsc_notes` text default NULL,
    PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Meta Files
INSERT INTO test_names(Test_name, Full_name, Sub_Group) VALUES('IPSC_tracking_form', 'IPSC Tracking Form', 6);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 12, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('IPSC_tracking_form', '0', '0', 'Y', 'Visit', 13, 'VSA', NULL);