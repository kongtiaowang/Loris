TRUNCATE TABLE `ExternalLinkTypes`;
LOCK TABLES `ExternalLinkTypes` WRITE;
INSERT INTO `ExternalLinkTypes` (`LinkTypeID`, `LinkType`) VALUES (4,'FooterLink');
INSERT INTO `ExternalLinkTypes` (`LinkTypeID`, `LinkType`) VALUES (5,'StudyLinks');
INSERT INTO `ExternalLinkTypes` (`LinkTypeID`, `LinkType`) VALUES (6,'dashboard');
UNLOCK TABLES;
