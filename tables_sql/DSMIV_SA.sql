CREATE TABLE `DSMIV_SA` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`q1a` enum('yes','no') default NULL,
`q1b` enum('yes','no') default NULL,
`q1c` enum('yes','no') default NULL,
`q1d` enum('yes','no') default NULL,
`q2a` enum('yes','no') default NULL,
`q2b` enum('yes','no') default NULL,
`q2c` enum('yes','no') default NULL,
`q2d` enum('yes','no') default NULL,
`q3a` enum('yes','no') default NULL,
`q3b` enum('yes','no') default NULL,
`q3c` enum('yes','no') default NULL,
`q3d` enum('yes','no') default NULL,
`meets_dsmiv_criteria_autistic_disorder` enum('yes','no') default NULL,
`meets_dsmiv_criteria_pervasive_developmental_disorder` enum('no_na','yes') default NULL,
`nonasd` varchar(255) default NULL,
`nonasd_comments` varchar(255) default NULL,
`confidence_rating` enum('3','2','1') default NULL,
`comments` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
