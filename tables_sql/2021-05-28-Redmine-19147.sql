CREATE TABLE `IPSC_tracking_form_PD` (
                                         `CommentID` varchar(255) NOT NULL default '',
                                         `UserID` varchar(255) default NULL,
                                         `Examiner` varchar(255) default NULL,
                                         `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
                                         `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
                                         `Date_taken` date default NULL,
                                         `Candidate_Age` varchar(255) default NULL,
                                         `Window_Difference` varchar(255) default NULL,
                                         `dccid` varchar(255) default NULL,
                                         `pscid` varchar(255) default NULL,
                                         `recruiter_asked_blood_draw` enum('yes','not_yet_asked') default NULL,
                                         `did_family_agree_to_project` enum('yes','no') default NULL,
                                         `IPSC_consent_date` date default NULL,
                                         `blood_draw_location` enum('site','take_home_kit_sent') default NULL,
                                         `fedex_tracking_number` text default NULL,
                                         `was_the_blood_draw_successful` enum('yes','no','no_blood_draw_scheduled','blood_draw_not_occurred') default NULL,
                                         `blood_draw_date` date default NULL,
                                         `ask_about_interview` enum('not_yet','yes') default NULL,
                                         `family_participate` enum('yes','no','na') default NULL,
                                         `ipsc_notes` text default NULL,
                                         PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
REPLACE INTO test_names (Test_name, Full_name, Sub_group) VALUES ('IPSC_tracking_form_PD', 'IPSC Tracking Form Proband', 1);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '1', 'VSA-PR-IPSC', NULL),
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '2', 'VSA-PR-IPSC', NULL),
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '3', 'VSA-PR-IPSC', NULL),
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '7', 'VSA-PR-IPSC', NULL),
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '9', 'VSA-PR-IPSC', NULL),
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '10', 'VSA-PR-IPSC', NULL),
('IPSC_tracking_form_PD', '0', '0', 'Y', 'Visit', '11', 'VSA-PR-IPSC', NULL);

INSERT INTO `Visit_Windows` (`Visit_label`, `WindowMinDays`, `WindowMaxDays`, `OptimumMinDays`, `OptimumMaxDays`, `WindowMidpointDays`, `ID`) VALUES
('VSA-PR-IPSC', NULL, NULL, NULL, NULL, NULL, DEFAULT);
