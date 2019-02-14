TRUNCATE TABLE `candidate_consent_rel`;
LOCK TABLES `candidate_consent_rel` WRITE;
INSERT INTO `candidate_consent_rel` (`CandidateID`, `ConsentID`, `Status`, `DateGiven`, `DateWithdrawn`) VALUES (587630,1,'yes','2018-11-06',NULL);
UNLOCK TABLES;
