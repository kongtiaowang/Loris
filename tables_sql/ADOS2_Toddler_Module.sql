CREATE TABLE `ADOS2_Toddler_Module`
(
    `CommentID`                                          varchar(255)                   NOT NULL       DEFAULT '',
    `UserID`                                             varchar(255)                                  DEFAULT NULL,
    `Examiner`                                           varchar(255)                                  DEFAULT NULL,
    `Testdate`                                           timestamp                      NOT NULL       DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `Data_entry_completion_status`                       enum ('Incomplete','Complete') NOT NULL       DEFAULT 'Incomplete',
    `Date_taken`                                         date                                          DEFAULT NULL,
    `Candidate_Age`                                      varchar(255)                                  DEFAULT NULL,
    `Window_Difference`                                  int(11)                                       DEFAULT NULL,
    `social_affect_total`                                varchar(255)                                  DEFAULT NULL,
    `restricted_repetitive_behavior_total`               varchar(255)                                  DEFAULT NULL,
    `social_affect_restricted_repetitive_behavior_total` varchar(255)                                  DEFAULT NULL,
    `ADOS_classification`                                varchar(255)                                  DEFAULT NULL,
    `a1`                                                 enum ('0','1','2','3','4','not_answered')     DEFAULT NULL,
    `a1a`                                                enum ('0','1','2','3','8','not_answered')     DEFAULT NULL,
    `a2`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `a3`                                                 enum ('0','1','2','8','not_answered')         DEFAULT NULL,
    `a4`                                                 enum ('0','1','2','3','8','not_answered')     DEFAULT NULL,
    `a5`                                                 enum ('0','1','2','3','8','not_answered')     DEFAULT NULL,
    `a6`                                                 enum ('0','1','2','8','not_answered')         DEFAULT NULL,
    `a7`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `a8`                                                 enum ('0','1','2','8','not_answered')         DEFAULT NULL,
    `a9`                                                 enum ('0','1','2','8','not_answered')         DEFAULT NULL,
    `b1`                                                 enum ('0','2','not_answered')                 DEFAULT NULL,
    `b2`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b3`                                                 enum ('0','1','2','not_answered')             DEFAULT NULL,
    `b4`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b5`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b6`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b7`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b8`                                                 enum ('0','1','2','not_answered')             DEFAULT NULL,
    `b9`                                                 enum ('0','1','2','not_answered')             DEFAULT NULL,
    `b10`                                                enum ('0','1','2','not_answered')             DEFAULT NULL,
    `b11`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b12`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b13`                                               enum ('0','1','2','3','7','not_answered')     DEFAULT NULL,
    `b14`                                               enum ('0','1','2','3','7','8','not_answered') DEFAULT NULL,
    `b15`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b16a`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b16b`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b17`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `b18`                                                enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `c1`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `c2`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `c3`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `d1`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `d1_specify`                                         text,
    `d1_specify_status`                                  enum ('not_answered')                         DEFAULT NULL,
    `d2`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `d2_specify`                                         text,
    `d2_specify_status`                                  enum ('not_answered')                         DEFAULT NULL,
    `d3`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `d3_specify`                                         text,
    `d3_specify_status`                                  enum ('not_answered')                         DEFAULT NULL,
    `d4`                                                 enum ('0','1','2','not_answered')             DEFAULT NULL,
    `d5`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `d5_specify`                                         text,
    `d5_specify_status`                                  enum ('not_answered')                         DEFAULT NULL,
    `e1`                                                 enum ('0','1','2','3','7','not_answered')     DEFAULT NULL,
    `e2`                                                 enum ('0','1','2','3','not_answered')         DEFAULT NULL,
    `e3`                                                 enum ('0','1','2','not_answered')             DEFAULT NULL,
    `e4`                                                 enum ('0','1','2','not_answered')             DEFAULT NULL,
    `a2_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `a3_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `a8_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `b1_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `b3_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `b4_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `b5_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `b9_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `b10_weighted`                                       varchar(255)                                  DEFAULT NULL,
    `b11_weighted`                                       varchar(255)                                  DEFAULT NULL,
    `b12_weighted`                                       varchar(255)                                  DEFAULT NULL,
    `d1_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `d2_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `d4_weighted`                                        varchar(255)                                  DEFAULT NULL,
    `social_affect_gotham_weighted`                      varchar(255)                                  DEFAULT NULL,
    `restricted_repetitive_gotham_weighted`              varchar(255)                                  DEFAULT NULL,
    `gotham_weighted_score`                              varchar(255)                                  DEFAULT NULL,
    `severity_score_lookup`                              varchar(255)                                  DEFAULT NULL,
    PRIMARY KEY (`CommentID`)
) ENGINE = MyISAM
  DEFAULT CHARSET = latin1;

INSERT INTO test_names (Test_name, Full_name, Sub_group, IsDirectEntry)
VALUES ('ADOS2_Toddler_Module', 'ADOS-2 - Toddler Module', 1, 0);

# INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number)
# VALUES ('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page1', 'Observation 1-5', 1);
# INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number)
# VALUES ('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page2', 'Observation 6-11', 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page1', 'Sections A-B', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page2', 'Sections C-E', 2);


INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 18, "V24");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 19, "V24");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 20, "V24");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 23, "V24");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 18, "V24-CVD");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 19, "V24-CVD");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 20, "V24-CVD");
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label)
VALUES ("ADOS2_Toddler_Module", "660", "780", "Y", "Visit", 23, "V24-CVD");
