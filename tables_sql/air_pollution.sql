CREATE TABLE `air_pollution` (
`CommentID` varchar(255) NOT NULL default '',

                          `UserID` varchar(255) default NULL,

                          `Examiner` varchar(255) default NULL,

                          `Testdate` timestamp NOT NULL,

                          `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`code` varchar(255) default NULL,
`name` varchar(255) default NULL,
`Date_taken` date default NULL,
`address_line1` varchar(255) default NULL,
`address_line2` varchar(255) default NULL,
`city` varchar(255) default NULL,
`state` varchar(255) default NULL,
`zip_code` varchar(255) default NULL,
`additional_comments` text default NULL,
`additional_comments_status` enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

              );
