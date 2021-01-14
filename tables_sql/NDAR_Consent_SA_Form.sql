CREATE TABLE `NDAR_Consent_SA_Form` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Date_taken` date DEFAULT NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`NDAR_consent_SA` enum('yes','no') default NULL,
`data_collection` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('NDAR_Consent_SA_Form', "NDAR Consent Form - SA", 6, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('NDAR_Consent_SA_Form', 'NDAR_Consent_SA_Form_page2', "Page2", 1);


INSERT INTO `consent`(`Name`,`Label`) VALUES ('NDAR_consent_SA', 'NDAR Consent SA');

INSERT INTO `survey_test_battery` (`Test_name`, `Active`, `Visit_label`) VALUES ('NDAR_Consent_SA_Form', 'Y', 'VSA');
INSERT INTO `survey_test_battery` (`Test_name`, `Active`, `Visit_label`) VALUES ('NDAR_Consent_SA_Form', 'Y', 'VSA-CVD');
