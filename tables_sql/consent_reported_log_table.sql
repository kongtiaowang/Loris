CREATE TABLE `reported_consent_log` (
  `PSCID` varchar(255) NOT NULL,
  `consent_name` varchar(255) NOT NULL,
  `reported` varchar(255) NOT NULL,
  `DateAdded` date DEFAULT NULL,
  CONSTRAINT `PK_reported_consent_log` PRIMARY KEY (`PSCID`,`consent_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO  `reported_consent_log` values ('SEA7010','ELSI Consent','1','2020-01-14');
INSERT INTO  `reported_consent_log` values ('SEA7006','ELSI Consent','1','2020-01-21');
INSERT INTO  `reported_consent_log` values ('SEA7005','ELSI Consent','1','2020-01-21');

