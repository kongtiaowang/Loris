CREATE TABLE `FOH_FXS_Saliva_Collection_Tracking` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`SubjectConsent` enum('yes','no','unknown','not_answered') default NULL,
`SiblingConsent` enum('yes','no','unknown','not_answered') default NULL,
`MotherConsent` enum('yes','no','unknown','not_answered') default NULL,
`FatherConsent` enum('yes','no','unknown','not_answered') default NULL,
`dateprepared_date` date default NULL,
`dateprepared_date_status` enum('not_answered') default NULL,
`Preparer` varchar(255) default NULL,
`Preparer_status` enum('not_answered') default NULL,
`SubjectKitType` enum('drool','swab','unknown','not_answered') default NULL,
`SiblingKitType` enum('drool','swab','unknown','not_answered') default NULL,
`SubjectID` varchar(255) default NULL,
`SubjectID_status` enum('not_answered') default NULL,
`SiblingID` varchar(255) default NULL,
`SiblingID_status` enum('not_answered') default NULL,
`MotherID` varchar(255) default NULL,
`MotherID_status` enum('not_answered') default NULL,
`FatherID` varchar(255) default NULL,
`FatherID_status` enum('not_answered') default NULL,
`datesent_date` date default NULL,
`datesent_date_status` enum('not_answered') default NULL,
`Sender` varchar(255) default NULL,
`Sender_status` enum('not_answered') default NULL,
`Tracking` varchar(255) default NULL,
`Tracking_status` enum('not_answered') default NULL,
`Tracking2` varchar(255) default NULL,
`Tracking2_status` enum('not_answered') default NULL,
`TrackingtoUNC` varchar(255) default NULL,
`TrackingtoUNC_status` enum('not_answered') default NULL,
`TrackingtoUNC2` varchar(255) default NULL,
`TrackingtoUNC2_status` enum('not_answered') default NULL,
`datesentback_date` date default NULL,
`datesentback_date_status` enum('not_answered') default NULL,
`datesentback2_date` date default NULL,
`datesentback2_date_status` enum('not_answered') default NULL,
`daterecieved_date` date default NULL,
`daterecieved_date_status` enum('not_answered') default NULL,
`daterecieved2_date` date default NULL,
`daterecieved2_date_status` enum('not_answered') default NULL,
`Notes` text default NULL,
`Notes_status` enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('FOH_FXS_Saliva_Collection_Tracking', 'FOH FXS Saliva Collection Tracking', '1');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_FXS_Saliva_Collection_Tracking', '0', '0', 'Y', 'Visit', '4', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_FXS_Saliva_Collection_Tracking', '0', '0', 'Y', 'Visit', '5', 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_FXS_Saliva_Collection_Tracking', '0', '0', 'Y', 'Visit', '4', 'VSA-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('FOH_FXS_Saliva_Collection_Tracking', '0', '0', 'Y', 'Visit', '5', 'VSA-CVD', NULL);
