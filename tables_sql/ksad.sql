DROP TABLE IF EXISTS `ksad`;
CREATE TABLE `ksad` (
  `CommentID` VARCHAR(255) NOT NULL DEFAULT '',
  `UserID` VARCHAR(255) DEFAULT NULL,
  `Examiner` VARCHAR(255) DEFAULT NULL,
  `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` ENUM('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `Date_taken` date DEFAULT NULL,
  `Candidate_Age` VARCHAR(255) DEFAULT NULL,
  `Window_Difference` VARCHAR(255) DEFAULT NULL,
  `ResponsesFileName` VARCHAR(255) DEFAULT NULL,
  `RatingsFileName`   VARCHAR(255) DEFAULT NULL,
  `DepressiveDisorders`        INT(10) DEFAULT NULL,
  `BipolarDisorders`           INT(10) DEFAULT NULL,
  `Psychosis`                  INT(10) DEFAULT NULL,
  `PanicDisorder`              INT(10) DEFAULT NULL,
  `Agoraphobia`                INT(10) DEFAULT NULL,
  `SeparationAnxiety`          INT(10) DEFAULT NULL,
  `SocialAnxietyDisorder`      INT(10) DEFAULT NULL,
  `SpecificPhobia`             INT(10) DEFAULT NULL,
  `GeneralizedAnxietyDisorder` INT(10) DEFAULT NULL,
  `OCDObsessions`              INT(10) DEFAULT NULL,
  `OCDCompulsions`             INT(10) DEFAULT NULL,
  `OCDTotal`                   INT(10) DEFAULT NULL,
  `Enuresis`                   INT(10) DEFAULT NULL,
  `Encopresis`                 INT(10) DEFAULT NULL,
  `EatingDisorders`            INT(10) DEFAULT NULL,
  `ADHD`                       INT(10) DEFAULT NULL,
  `ODD`                        INT(10) DEFAULT NULL,
  `ConductDisorder`            INT(10) DEFAULT NULL,
  `TicDisorder`                INT(10) DEFAULT NULL,
  `AutismDisorder`             INT(10) DEFAULT NULL,
  `AlcoholuserDisorder`        INT(10) DEFAULT NULL,
  `DrugUseDisorder`            INT(10) DEFAULT NULL,
  `PTSD`                       INT(10) DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `ksad_responses`;
CREATE TABLE `ksad_responses` (
  `CommentID`  VARCHAR(255)     NOT NULL DEFAULT '',
  `QuestionID` INT(10) UNSIGNED NOT NULL,
  `Value`      VARCHAR(255)     DEFAULT NULL,
  `Comment`    VARCHAR(255)     DEFAULT NULL,
  PRIMARY KEY (`CommentID`, `QuestionID`),
  CONSTRAINT `ksad_fk_1` FOREIGN KEY (`QuestionID`) REFERENCES `ksad_questionnaire` (`QuestionID`),
  CONSTRAINT `ksad_fk_2` FOREIGN KEY (`CommentID`)  REFERENCES `ksad` (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO `test_names` (`Test_name`, `Full_name`, `Sub_group`) VALUES ('ksad', 'KSAD', '1');

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ksad', '0', '0', 'Y', 'Visit', 1, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ksad', '0', '0', 'Y', 'Visit', 2, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ksad', '0', '0', 'Y', 'Visit', 3, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ksad', '0', '0', 'Y', 'Visit', 9, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ksad', '0', '0', 'Y', 'Visit', 10, 'VSA', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('ksad', '0', '0', 'Y', 'Visit', 21, 'VSA', NULL);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ksad','ksad_page1', 'Responses'       , 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ksad','ksad_page2', 'Symptoms Ratings', 2);
