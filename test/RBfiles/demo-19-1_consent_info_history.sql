-- MySQL dump 10.16  Distrib 10.1.32-MariaDB, for Linux (x86_64)
--
-- Host: 192.168.122.1    Database: Demo
-- ------------------------------------------------------
-- Server version	5.1.73

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Dumping data for table `consent_info_history`
--

LOCK TABLES `consent_info_history` WRITE;
/*!40000 ALTER TABLE `consent_info_history` DISABLE KEYS */;
TRUNCATE TABLE `consent_info_history`; INSERT INTO `consent_info_history` (`ID`, `CandID`, `entry_staff`, `data_entry_date`, `study_consent`, `study_consent_date`, `study_consent_withdrawal`, `raisin_consent`, `raisin_consent_date`, `raisin_consent_withdrawal`, `bread_consent`, `bread_consent_date`, `bread_consent_withdrawal`) VALUES (1,400484,'admin','2016-06-21 20:27:16',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(2,400484,'admin','2016-06-21 20:29:11',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(3,400484,'admin','2016-06-21 20:29:43','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(4,400439,'admin','2016-06-21 20:30:38','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(5,300256,'admin','2016-06-21 20:30:52','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(6,300126,'admin','2016-06-21 20:31:02','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(7,300256,'admin','2016-06-21 20:31:30','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(8,300126,'admin','2016-06-21 20:31:46','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(9,400484,'admin','2016-06-21 20:32:14','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(10,300126,'admin','2016-06-21 20:32:47','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(11,400439,'admin','2016-06-21 20:33:48','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(12,400439,'admin','2016-06-21 20:34:21','not_answered','1001-01-01','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(16,300001,'admin','2016-08-06 22:57:26',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(17,300147,'admin','2016-08-15 19:58:12',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(18,300322,'admin','2016-08-15 19:58:41',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(19,400287,'admin','2016-08-15 19:59:02',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(20,587630,'admin','2016-09-02 17:57:55','yes','2015-12-31','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(21,587630,'admin','2016-09-02 17:58:24','yes','2015-12-31','1001-01-01',NULL,NULL,NULL,NULL,NULL,NULL),(22,587630,'admin','2016-09-09 22:36:30','no',NULL,'2015-12-31',NULL,NULL,NULL,NULL,NULL,NULL),(41,300001,'admin','2016-09-24 06:13:39','no',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(42,300001,'admin','2016-09-24 06:14:04','no',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(43,300001,'admin','2016-09-24 06:16:54','no',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(44,300001,'admin','2016-09-24 06:17:32','no',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(45,300001,'admin','2016-09-24 06:17:45',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(46,300001,'admin','2016-09-24 06:17:46','no',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(47,300001,'admin','2016-09-24 06:19:17','yes','2015-12-31',NULL,NULL,NULL,NULL,NULL,NULL,NULL),(48,300005,'admin','2016-10-08 01:02:40','yes','2015-10-30',NULL,NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `consent_info_history` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed