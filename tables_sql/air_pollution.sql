CREATE TABLE `air_pollution` (
  `CommentID` varchar(255) NOT NULL default '',
  `UserID` varchar(255) default NULL,
  `Examiner` varchar(255) default NULL,
  `Testdate` timestamp NOT NULL,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
  `consent` enum('yes','no','not_answered') DEFAULT NULL,
  `consent_date` date DEFAULT NULL,
  `code` varchar(255) default NULL,
  `name` text default NULL,
  `Date_taken` date default NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` int(11) DEFAULT NULL,
  `address_line1` text default NULL,
  `address_line2` text default NULL,
  `city` text default NULL,
  `state` text default NULL,
  `zip_code` text default NULL,
  `additional_comments` text default NULL,
  `additional_comments_status` enum('not_answered') default NULL,
  PRIMARY KEY  (`CommentID`)
);
INSERT INTO `test_names` (Test_name, Full_name, Sub_group, isDirectEntry) VALUES ('air_pollution', 'Air Pollution', 6, true);
INSERT INTO `instrument_subtests` (`Test_name`, `Subtest_name`, `Description`, `Order_number`) VALUES ('air_pollution', 'air_pollution_page2', 'Page2', '0');
ALTER TABLE `participant_status` ADD COLUMN `air_consent` enum('yes','no','not_answered') DEFAULT NULL;
ALTER TABLE `participant_status` ADD COLUMN `air_consent_date` date DEFAULT NULL;
ALTER TABLE `participant_status` ADD COLUMN `air_consent_withdrawal` date DEFAULT NULL;
ALTER TABLE `consent_info_history` ADD COLUMN `air_consent` enum('yes','no','not_answered') DEFAULT NULL;
ALTER TABLE `consent_info_history` ADD COLUMN `air_consent_date` date DEFAULT NULL;
ALTER TABLE `consent_info_history` ADD COLUMN `air_consent_withdrawal` date DEFAULT NULL;

