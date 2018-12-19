CREATE TABLE `NIHToolBox_Registration_Data` (
`CommentID` varchar(100) NOT NULL default '',

                            `UserID` TEXT default NULL,

                            `Examiner` TEXT default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` TEXT default NULL,
`Window_Difference` TEXT default NULL,
`Uploaded_registration_data` TEXT default NULL,
`DeviceID` TEXT default NULL,
`Name` TEXT default NULL,
`Age` TEXT default NULL,
`Education` TEXT default NULL,
`Mothers_Education` TEXT default NULL,
`Fathers_Education` TEXT default NULL,
`Guardians_Education` TEXT default NULL,
`Starting_Level_Override` TEXT default NULL,
`Gender` TEXT default NULL,
`Handedness` TEXT default NULL,
`Race` TEXT default NULL,
`Ethnicity` TEXT default NULL,
`Assessment_Name` TEXT default NULL,
`Data_dir_assessment` TEXT default NULL,
  `File_type` varchar(25) DEFAULT NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;





-- META
INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('NIHToolBox_Registration_Data', 'NIH ToolBox Registration Data', '1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('NIHToolBox_Registration_Data', 'NIHToolBox_Registration_Data_page1', "Page 1", 1);
