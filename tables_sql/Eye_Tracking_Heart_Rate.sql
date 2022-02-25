CREATE TABLE `Eye_Tracking_Heart_Rate` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`start_time` varchar(255) default NULL,
`start_time_status` enum('not_answered') default NULL,
`end_time` varchar(255) default NULL,
`end_time_status` enum('not_answered') default NULL,
`q1_room_temperature` varchar(255) default NULL,
`q1_room_temperature_status` enum('data_not_recorded') default NULL,
`q2_lights` enum('on','off','dim','mix_of_off_and_on','data_not_recorded') default NULL,
`q3_who_is_the_child_sitting_with` varchar(255) default NULL,
`q4_task_version` varchar(255) default NULL,
`q4_task_version_status` enum('not_answered') default NULL,
`q5_issues_with_child_comfort` enum('yes','no','data_not_recorded') default NULL,
`q5_issues_specify` varchar(255) default NULL,
`q6_issues_with_parent_comfort` enum('yes','no','data_not_recorded') default NULL,
`q6_issues_specify` varchar(255) default NULL,
`q7_eye_tracking_alert` enum('yes','no','data_not_recorded') default NULL,
`q7_issues_specify` varchar(255) default NULL,
`q8_cooperation_with_the_heart_monitor` enum('yes','no','data_not_recorded') default NULL,
`q8_issues_specify` varchar(255) default NULL,
`q9_cooperation_with_the_heart_monitor` enum('yes','no','data_not_recorded') default NULL,
`q9_issues_specify` varchar(255) default NULL,
`q10_heart_rate_alert` enum('yes','no','data_not_recorded') default NULL,
`q10_issues_specify` varchar(255) default NULL,
`q11_comments` text default NULL,
`q11_comments_status` enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8; 
	
INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('Eye_Tracking_Heart_Rate', 'Eye Tracking/Heart Rate Data Collection Checklist', '1');
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);
-- IBIS EP High Risk
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V09', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V9-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 18, 'V24-CVD', NULL);
-- DS-Infant
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V09', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V9-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 20, 'V24-CVD', NULL);
-- Control DS-Infant
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V09', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V9-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Eye_Tracking_Heart_Rate', '0', '0', 'Y', 'Visit', 23, 'V24-CVD', NULL);

