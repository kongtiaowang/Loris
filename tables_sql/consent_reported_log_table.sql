CREATE TABLE `reported_consent_log` (
  `PSCID` varchar(255) NOT NULL,
  `consent_name` varchar(255) NOT NULL,
  `reported` varchar(255) NOT NULL,
  CONSTRAINT `PK_reported_consent_log` PRIMARY KEY (`PSCID`,`consent_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;