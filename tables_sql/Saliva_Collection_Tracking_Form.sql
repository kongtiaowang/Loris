CREATE TABLE `Saliva_Collection_Tracking_Form` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `UserID` varchar(255) DEFAULT NULL,
  `Examiner` varchar(255) DEFAULT NULL,
  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `Date_taken` date DEFAULT NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` varchar(255) DEFAULT NULL,
  `Date_Kits` date DEFAULT NULL,
  `aq1` enum('yes','no','investigate') DEFAULT NULL,
  `aq2` varchar(255) DEFAULT NULL,
  `sq1` enum('yes','no','0') DEFAULT NULL,
  `sq2` varchar(100) default NULL,
  `sq3` date DEFAULT NULL,
  `sq4_1` date DEFAULT NULL,
  `sq4_2` varchar(255) DEFAULT NULL,
  `sq5_1` enum('At_Visit','Via_Mail') DEFAULT NULL,
  `sq6` varchar(255) DEFAULT NULL,
  `sq7_1` enum('yes','no') DEFAULT NULL,
  `sq7_2` varchar(255) DEFAULT NULL,
  `sq7_3` text,
  `sq9` text,
  `pq1` enum('yes','no','0') DEFAULT NULL,
  `pq2` enum('yes','no','0') DEFAULT NULL,
  `pq3` enum('refused','not_asked') DEFAULT NULL,
  `pq4` date DEFAULT NULL,
  `pq5` enum('yes','no') DEFAULT NULL,
  `pq6` enum('At_Visit','Via_Mail') DEFAULT NULL,
  `pq7` date DEFAULT NULL,
  `pq8_1` date DEFAULT NULL,
  `pq8_2` varchar(255) DEFAULT NULL,
  `pq9_1` enum('At_Visit','Via_Mail') DEFAULT NULL,
  `pq10` varchar(255) DEFAULT NULL,
  `pq11_1` enum('yes','no') DEFAULT NULL,
  `pq11_2` varchar(255) DEFAULT NULL,
  `pq12` date DEFAULT NULL,
  `pq13` text,
  `mq1` enum('yes','no','0') DEFAULT NULL,
  `mq2` varchar(100) default NULL,
  `mq3` date DEFAULT NULL,
  `mq4_1` date DEFAULT NULL,
  `mq4_2` varchar(255) DEFAULT NULL,
  `mq6` varchar(255) DEFAULT NULL,
  `mq5_1` enum('At_Visit','Via_Mail') DEFAULT NULL,
  `mq7_1` enum('yes','no') DEFAULT NULL,
  `mq7_2` varchar(255) DEFAULT NULL,
  `mq8` date DEFAULT NULL,
  `mq9` text,
  `fq1` enum('yes','no','0') DEFAULT NULL,
  `fq2` varchar(100) default NULL,
  `fq3` date DEFAULT NULL,
  `fq4_1` date DEFAULT NULL,
  `fq4_2` varchar(255) DEFAULT NULL,
  `fq5_1` enum('At_Visit','Via_Mail') DEFAULT NULL,
  `fq6` varchar(255) DEFAULT NULL,
  `fq7_1` enum('yes','no') DEFAULT NULL,
  `fq7_2` varchar(255) DEFAULT NULL,
  `fq8` date DEFAULT NULL,
  `sq3a` varchar(100) default NULL,
  `sq8` varchar(255) default NULL,
  `pq3a` varchar(100) default NULL,
  `pq9_status` varchar(100) default NULL,
  `mq4_status` varchar(100) default NULL,
  `fq4_status` varchar(100) default NULL,
  `other_date_delivered` varchar(100) default NULL,
  `other_staff_delivered` varchar(100) default NULL,
  `sq4` date default NULL,
  `sq4_status` varchar(100) default NULL,
  `fq9` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;