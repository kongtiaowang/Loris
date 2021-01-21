CREATE TABLE `IBIS_SA_SLEEP_Consent_Form` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Date_taken` date DEFAULT NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`IBIS_SA_SLEEP_Consent` enum('yes','no') default NULL,
`data_collection` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('IBIS_SA_SLEEP_Consent_Form', "IBIS SA-SLEEP - Consent Form", 6, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('IBIS_SA_SLEEP_Consent_Form', 'IBIS_SA_SLEEP_Consent_Form_page2', "Page2", 1);


INSERT INTO `consent`(`Name`,`Label`) VALUES ('IBIS_SA_SLEEP_Consent', 'IBIS SA-SLEEP - Consent');

INSERT INTO `survey_test_battery` (`Test_name`, `Active`, `Visit_label`) VALUES ('IBIS_SA_SLEEP_Consent_Form', 'Y', 'VSA-Sleep');
