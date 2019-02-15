TRUNCATE TABLE `data_release_permissions`;
LOCK TABLES `data_release_permissions` WRITE;
INSERT INTO `data_release_permissions` (`userid`, `data_release_id`) VALUES (1,1);
INSERT INTO `data_release_permissions` (`userid`, `data_release_id`) VALUES (1,2);
INSERT INTO `data_release_permissions` (`userid`, `data_release_id`) VALUES (1,3);
UNLOCK TABLES;
