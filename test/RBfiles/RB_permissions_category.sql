TRUNCATE TABLE `permissions_category`;
LOCK TABLES `permissions_category` WRITE;
INSERT INTO `permissions_category` (`ID`, `Description`) VALUES (1,'Roles');
INSERT INTO `permissions_category` (`ID`, `Description`) VALUES (2,'Permission');
UNLOCK TABLES;
