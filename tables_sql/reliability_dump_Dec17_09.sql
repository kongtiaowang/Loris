-- MySQL dump 10.11
--
-- Host: zaphod.bic.mni.mcgill.ca    Database: nihaceProd
-- ------------------------------------------------------
-- Server version	5.0.32-Debian_7etch5-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `reliability`
--

DROP TABLE IF EXISTS `reliability`;
CREATE TABLE `reliability` (
  `ID` int(11) NOT NULL auto_increment,
  `CommentID` varchar(255) default NULL,
  `reliability_center_id` int(11) NOT NULL default '1',
  `Instrument` varchar(255) default NULL,
  `Reliability_score` decimal(4,2) default NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reliability`
--

LOCK TABLES `reliability` WRITE;
/*!40000 ALTER TABLE `reliability` DISABLE KEYS */;
INSERT INTO `reliability` VALUES (1,'116434dcc1234c65161202252026',1,'csbs',NULL),(2,'230082dcc000186161239211217',1,'csbs',NULL),(3,'235548dcc0009484161239212277',1,'csbs',NULL),(4,'282976dcc0001S42161213627225',1,'csbs',NULL),(5,'475963dcc000390161239211126',1,'csbs',NULL),(6,'524539dcc0008483161239212212',1,'csbs',NULL),(7,'553014dcc0010485161239212347',1,'csbs',NULL),(8,'568246dcc0005122161239211086',1,'csbs',NULL),(9,'116434dcc1234c65161202252026',1,'adi_r',NULL),(10,'116434dcc1234c65161202252026',1,'ados_module1',NULL),(11,'116434dcc1234c65161202252026',1,'ados_module2',NULL),(12,'230082dcc000186161239211217',1,'ados_module2',NULL),(13,'230082dcc000186161239211217',1,'ados_module1',NULL),(14,'230082dcc000186161239211217',1,'adi_r',NULL),(15,'235548dcc0009484161239212277',1,'adi_r',NULL),(16,'235548dcc0009484161239212277',1,'ados_module1',NULL),(17,'235548dcc0009484161239212277',1,'ados_module2',NULL),(18,'282976dcc0001S42161213627225',1,'ados_module2',NULL),(19,'282976dcc0001S42161213627225',1,'ados_module1',NULL),(20,'282976dcc0001S42161213627225',1,'adi_r',NULL),(21,'475963dcc000390161239211126',1,'adi_r',NULL),(22,'475963dcc000390161239211126',1,'ados_module1',NULL),(23,'475963dcc000390161239211126',1,'ados_module2',NULL),(24,'524539dcc0008483161239212212',1,'ados_module1',NULL),(25,'524539dcc0008483161239212212',1,'ados_module2',NULL),(26,'524539dcc0008483161239212212',1,'adi_r',NULL),(27,'553014dcc0010485161239212347',1,'adi_r',NULL),(28,'553014dcc0010485161239212347',1,'ados_module2',NULL),(29,'553014dcc0010485161239212347',1,'ados_module1',NULL),(30,'486150dcc431126161189210811',1,'ados_module1',NULL),(31,'486150dcc431126161189210811',1,'ados_module2',NULL),(32,'486150dcc431126161189210811',1,'csbs',NULL),(33,'486150dcc431126161189210811',1,'adi_r',NULL),(34,'568246dcc0005122161239211086',1,'ados_module1',NULL),(35,'568246dcc0005122161239211086',1,'ados_module2',NULL),(37,'568246dcc0005122161239211086',1,'adi_r',NULL),(38,'590008dcc000264161239211044',1,'ados_module1',NULL),(39,'590008dcc000264161239211044',1,'ados_module2',NULL),(40,'590008dcc000264161239211044',1,'csbs',NULL),(41,'590008dcc000264161239211044',1,'adi_r',NULL),(42,'600761dcc000085161239211020',1,'ados_module1',NULL),(43,'600761dcc000085161239211020',1,'ados_module2',NULL),(44,'600761dcc000085161239211020',1,'csbs',NULL),(45,'600761dcc000085161239211020',1,'adi_r',NULL),(46,'733764dcc0006378161239210981',1,'ados_module1',NULL),(47,'733764dcc0006378161239210981',1,'ados_module2',NULL),(48,'733764dcc0006378161239210981',1,'csbs',NULL),(49,'733764dcc0006378161239210981',1,'adi_r',NULL),(50,'914533dcc000491161239210490',1,'ados_module1',NULL),(51,'914533dcc000491161239210490',1,'ados_module2',NULL),(52,'914533dcc000491161239210490',1,'csbs',NULL),(53,'914533dcc000491161239210490',1,'adi_r',NULL),(54,'965327dcc0007482161239212144',1,'ados_module1',NULL),(55,'965327dcc0007482161239212144',1,'ados_module2',NULL),(56,'965327dcc0007482161239212144',1,'csbs',NULL),(57,'965327dcc0007482161239212144',1,'adi_r',NULL),(86,'898532dcc0011539121242838132',1,'ados_module1',NULL),(87,'898532dcc0011539121242838132',1,'ados_module2',NULL),(88,'898532dcc0011539121242838132',1,'adi_r',NULL),(89,'898532dcc0011539121242838132',1,'csbs',NULL),(90,'439163dcc0012540121242838182',1,'ados_module1',NULL),(91,'439163dcc0012540121242838182',1,'ados_module2',NULL),(92,'439163dcc0012540121242838182',1,'adi_r',NULL),(93,'439163dcc0012540121242838182',1,'csbs',NULL),(94,'737931dcc0013543121242937645',1,'ados_module1',NULL),(95,'746377dcc0014544121242937698',1,'ados_module1',NULL),(96,'330452dcc0015545121242937751',1,'ados_module1',NULL),(97,'332479dcc0016546121242937833',1,'ados_module1',NULL),(98,'356076dcc0017547121242937875',1,'ados_module1',NULL),(99,'737931dcc0013543121242937645',1,'ados_module2',NULL),(100,'746377dcc0014544121242937698',1,'ados_module2',NULL),(101,'330452dcc0015545121242937751',1,'ados_module2',NULL),(102,'332479dcc0016546121242937833',1,'ados_module2',NULL),(103,'356076dcc0017547121242937875',1,'ados_module2',NULL),(104,'737931dcc0013543121242937645',1,'adi_r',NULL),(105,'746377dcc0014544121242937698',1,'adi_r',NULL),(106,'330452dcc0015545121242937751',1,'adi_r',NULL),(107,'332479dcc0016546121242937833',1,'adi_r',NULL),(108,'356076dcc0017547121242937875',1,'adi_r',NULL),(109,'737931dcc0013543121242937645',1,'csbs',NULL),(110,'746377dcc0014544121242937698',1,'csbs',NULL),(111,'330452dcc0015545121242937751',1,'csbs',NULL),(112,'332479dcc0016546121242937833',1,'csbs',NULL),(113,'356076dcc0017547121242937875',1,'csbs',NULL),(114,'341688dcc0019609181245335920',1,'adir_r',NULL),(115,'341688dcc0019609181245335920',1,'ados_module2',NULL),(116,'341688dcc0019609181245335920',1,'ados_module1',NULL),(117,'341688dcc0019609181245335920',1,'csbs',NULL),(118,'710696dcc0018609181245335920',1,'adir_r',NULL),(119,'710696dcc0018609181245335920',1,'ados_modeule1',NULL),(120,'710696dcc0018609181245335920',1,'ados_module1',NULL),(121,'710696dcc0018609181245335920',1,'ados_module2',NULL),(122,'710696dcc0018609181245335920',1,'csbs',NULL),(123,'623980dcc0020609181245335920',1,'adir_r',NULL),(124,'623980dcc0020609181245335920',1,'ados_module1',NULL),(125,'623980dcc0020609181245335920',1,'ados_module2',NULL),(126,'623980dcc0020609181245335920',1,'csbs',NULL),(127,'690789dcc0021609181245335920',1,'adir_r',NULL),(128,'690789dcc0021609181245335920',1,'ados_module1',NULL),(129,'690789dcc0021609181245335920',1,'ados_module2',NULL),(130,'690789dcc0021609181245335920',1,'csbs',NULL),(131,'742494dcc0022609181245335920',1,'adir_r',NULL),(132,'742494dcc0022609181245335920',1,'ados_module1',NULL),(133,'742494dcc0022609181245335920',1,'ados_module2',NULL),(134,'742494dcc0022609181245335920',1,'csbs',NULL),(135,'123999dcc0023609181245335920',1,'adir_r',NULL),(136,'123999dcc0023609181245335920',1,'ados_module1',NULL),(137,'123999dcc0023609181245335920',1,'ados_module2',NULL),(138,'123999dcc0023609181245335920',1,'csbs',NULL),(139,'311440dcc0024609181245335920',1,'ados_module1',NULL),(140,'311440dcc0024609181245335920',1,'ados_module2',NULL),(141,'311440dcc0024609181245335920',1,'csbs',NULL),(142,'311440dcc0024609181245335920',1,'adi_r',NULL),(143,'535086dcc0025609181245335920',1,'adi_r',NULL),(144,'535086dcc0025609181245335920',1,'ados_module1',NULL),(145,'535086dcc0025609181245335920',1,'ados_module2',NULL),(146,'535086dcc0025609181245335920',1,'csbs',NULL),(147,'299084dcc0026609181245335920',1,'csbs',NULL),(148,'299084dcc0026609181245335920',1,'ados_module1',NULL),(149,'299084dcc0026609181245335920',1,'ados_module2',NULL),(150,'299084dcc0026609181245335920',1,'adir_r',NULL),(151,'623980dcc0020668121249046134',1,'adir_r',NULL),(152,'623980dcc0020668121249046134',1,'ados_module1',NULL),(153,'623980dcc0020668121249046134',1,'ados_module2',NULL),(154,'623980dcc0020668121249046134',1,'csbs',NULL),(155,'690789dcc0021669121249047601',1,'csbs',NULL),(156,'690789dcc0021669121249047601',1,'ados_module2',NULL),(157,'690789dcc0021669121249047601',1,'ados_module1',NULL),(158,'690789dcc0021669121249047601',1,'adi_r',NULL),(159,'742494dcc0022670121249047633',1,'ados_module1',NULL),(160,'742494dcc0022670121249047633',1,'ados_module2',NULL),(161,'742494dcc0022670121249047633',1,'csbs',NULL),(162,'742494dcc0022670121249047633',1,'adi_r',NULL),(163,'123999dcc0023671121249048020',1,'adi_r',NULL),(164,'123999dcc0023671121249048020',1,'ados_module1',NULL),(165,'123999dcc0023671121249048020',1,'ados_module2',NULL),(166,'123999dcc0023671121249048020',1,'adi_r',NULL),(167,'311440dcc0024672121249048068',1,'adi_r',NULL),(168,'311440dcc0024672121249048068',1,'ados_module2',NULL),(169,'311440dcc0024672121249048068',1,'ados_module1',NULL),(170,'311440dcc0024672121249048068',1,'adi_r',NULL),(171,'311440dcc0024672121249048068',1,'csbs',NULL),(172,'535086dcc0025673121249048102',1,'csbs',NULL),(173,'535086dcc0025673121249048102',1,'adi_r',NULL),(174,'535086dcc0025673121249048102',1,'ados_module1',NULL),(175,'535086dcc0025673121249048102',1,'ados_module2',NULL),(176,'299084dcc0026674121249048129',1,'ados_module2',NULL),(177,'299084dcc0026674121249048129',1,'ados_module1',NULL),(178,'299084dcc0026674121249048129',1,'csbs',NULL),(179,'299084dcc0026674121249048129',1,'adi_r',NULL),(180,'710696dcc0018549131250194722',1,'csbs',NULL),(181,'710696dcc0018549131250194722',1,'adi_r',NULL),(182,'710696dcc0018549131250194722',1,'ados_module1',NULL),(183,'710696dcc0018549131250194722',1,'ados_module2',NULL),(413,'269738SEA0032139121215629944',2,'adi_r_proband',NULL),(414,'337032SEA000757121218508185',2,'adi_r_proband',NULL),(415,'580367SEA001049121205951333',2,'adi_r_proband',NULL),(416,'619518SEA0065321121228494529',2,'adi_r_proband',NULL),(417,'690303SEA001353121205951480',2,'adi_r_proband',NULL),(418,'804916SEA000950121221174988',2,'adi_r_proband',NULL),(419,'911974SEA000656121213627225',2,'adi_r_proband',NULL),(420,'271626SEA0037335151229633012',2,'aosi',NULL),(421,'336576SEA0107718151252624110',2,'aosi',NULL),(422,'460612SEA0069730151253035025',2,'aosi',NULL),(423,'596154SEA0070740151252708923',2,'aosi',NULL),(424,'659752SEA0004179151237918279',2,'aosi',NULL),(425,'722947SEA0083398151254250581',2,'aosi',NULL),(426,'833557SEA0110752151253229359',2,'aosi',NULL),(427,'898932SEA0029359151231174693',2,'aosi',NULL),(428,'201597PHI0056255121225133729',3,'adi_r_proband',NULL),(429,'350868PHI0093405121233768020',3,'adi_r_proband',NULL),(430,'408510PHI0080323221228507314',3,'adi_r_proband',NULL),(431,'506851PHI0085355121230049486',3,'adi_r_proband',NULL),(432,'567669PHI0072286121226599061',3,'adi_r_proband',NULL),(433,'678266PHI0008129221215104440',3,'adi_r_proband',NULL),(434,'809318PHI0014145121215804420',3,'adi_r_proband',NULL),(435,'868281PHI0091399121233601751',3,'adi_r_proband',NULL),(436,'957420PHI0050248121224795111',3,'adi_r_proband',NULL),(437,'230955PHI0052257251237918280',3,'aosi',NULL),(438,'389101PHI0000401151233690664',3,'aosi',NULL),(439,'490022PHI0077337251239912784',3,'aosi',NULL),(440,'570888PHI0106528151242141068',3,'aosi',NULL),(441,'695831PHI0002569151244555590',3,'aosi',NULL),(442,'838659PHI0009134151225923601',3,'aosi',NULL),(443,'929204PHI0010489151239824642',3,'aosi',NULL),(444,'131292STL0095480121239055432',4,'adi_r_proband',NULL),(445,'189601STL0070299121227547563',4,'adi_r_proband',NULL),(446,'231287STL0061244221224705992',4,'adi_r_proband',NULL),(447,'327609STL0043274121225824897',4,'adi_r_proband',NULL),(448,'377996STL0037302221227562019',4,'adi_r_proband',NULL),(449,'456823STL0064273121225824845',4,'adi_r_proband',NULL),(450,'501347STL0063312121227723476',4,'adi_r_proband',NULL),(451,'580472STL0053308221227637227',4,'adi_r_proband',NULL),(452,'693153STL0009142121216917495',4,'adi_r_proband',NULL),(453,'762212STL0151724221252161133',4,'adi_r_proband',NULL),(454,'846507STL0114691221253116873',4,'adi_r_proband',NULL),(455,'882244STL0088429121236617539',4,'adi_r_proband',NULL),(456,'950726STL0086477121238806514',4,'adi_r_proband',NULL),(457,'982351STL0036412221234553246',4,'adi_r_proband',NULL),(458,'347302STL0093464151238445997',4,'aosi',NULL),(459,'509054STL0042520251241637158',4,'aosi',NULL),(460,'731685STL0101624251246385956',4,'aosi',NULL),(461,'967950STL0077324151247175367',4,'aosi',NULL),(462,'842255STL0035309261254250579',4,'csbs',NULL),(463,'222376UNC000280121225222308',5,'adi_r_proband',NULL),(464,'389321UNC0048390121233014123',5,'adi_r_proband',NULL),(465,'471178UNC0025716121252001435',5,'adi_r_proband',NULL),(466,'568175UNC0084684221253642976',5,'adi_r_proband',NULL),(467,'675680UNC0099760121253891199',5,'adi_r_proband',NULL),(468,'822011UNC0043622121246298468',5,'adi_r_proband',NULL),(469,'910593UNC0076558221244733003',5,'adi_r_proband',NULL),(470,'996243UNC0019173121224793695',5,'adi_r_proband',NULL),(471,'171701UNC0008427151242926015',5,'aosi',NULL),(472,'324373UNC0079562151246055325',5,'aosi',NULL),(473,'420719UNC0078560151248031759',5,'aosi',NULL),(474,'515353UNC0059650151253715504',5,'aosi',NULL),(475,'641585UNC0020445151243351965',5,'aosi',NULL),(476,'792210UNC0013431151242926319',5,'aosi',NULL),(477,'856858UNC0045389151246896628',5,'aosi',NULL),(478,'957019UNC0029262151246293158',5,'aosi',NULL),(479,'323623SEA001463151207592933',2,'aosi','89.47'),(480,'714779SEA002267151208815576',2,'aosi','94.74'),(481,'726000SEA001659151216170816',2,'aosi','84.21'),(482,'108001SEA003482151220634661',2,'aosi','78.95'),(483,'613004SEA0036187151225142428',2,'aosi','89.47'),(484,'898932SEA002977121208815789',2,'adi_r_proband',NULL),(485,'223443STL0118721121255377506',4,'adi_r_proband',NULL),(486,'368672PHI0018151121216676439',3,'adi_r_proband',NULL),(487,'335470UNC0063496121240253432',5,'adi_r_proband',NULL),(488,'320613SEA001252221201047640',3,'adi_r_proband',NULL),(489,'550654SEA0068409121234369213',4,'adi_r_proband',NULL),(490,'641247SEA0005195121229377427',5,'adi_r_proband',NULL),(491,'745524SEA0064372121232132319',3,'adi_r_proband',NULL),(492,'969473SEA0048115121216072245',4,'adi_r_proband',NULL),(493,'269738SEA0032139151220040461',6,'aosi',NULL),(494,'323623SEA001463151207592933',6,'aosi',NULL),(495,'458894SEA0043109351215458082',6,'aosi',NULL),(496,'581471SEA0078641351248212200',6,'aosi',NULL),(497,'646579SEA000851351205876353',6,'aosi',NULL),(498,'714779SEA0022330151229023962',6,'aosi','26.32'),(499,'804916SEA000950151207592400',6,'aosi',NULL),(500,'873371SEA000244351213627225',6,'aosi',NULL),(501,'275891PHI0027203221222184837',2,'adi_r_proband',NULL),(502,'408510PHI0080323221228507314',4,'adi_r_proband',NULL),(503,'519756PHI0129707121251730939',5,'adi_r_proband',NULL),(504,'630096PHI0040237221224617272',2,'adi_r_proband',NULL),(505,'811160PHI0068314221227819280',4,'adi_r_proband',NULL),(506,'927676PHI0016149221216643807',5,'adi_r_proband',NULL),(507,'230955PHI0052257251237918280',6,'aosi',NULL),(508,'389101PHI0000117151215526615',6,'aosi',NULL),(509,'463809PHI0024491151239824710',6,'aosi',NULL),(510,'567669PHI0072768151254336754',6,'aosi',NULL),(511,'695831PHI0002133151226430911',6,'aosi',NULL),(512,'812952PHI0015146251221483409',6,'aosi',NULL),(513,'929204PHI0010135151221747293',6,'aosi',NULL),(514,'141335STL0010224121229705049',2,'adi_r_proband',NULL),(515,'221751STL0113722121253554520',3,'adi_r_proband',NULL),(516,'347302STL0093464121238445997',5,'adi_r_proband',NULL),(517,'435125STL0125742221252944198',2,'adi_r_proband',NULL),(518,'509054STL0042520221241637158',3,'adi_r_proband',NULL),(519,'662153STL0059343121229536775',5,'adi_r_proband',NULL),(520,'762212STL0151724221252161133',2,'adi_r_proband',NULL),(521,'859030STL0030326121228849099',3,'adi_r_proband',NULL),(522,'942002STL0080513121243544186',5,'adi_r_proband',NULL),(523,'995261STL0058316221228239203',2,'adi_r_proband',NULL),(524,'347302STL0093464151238445997',6,'aosi',NULL),(525,'501347STL0063312151232743121',6,'aosi',NULL),(526,'662153STL0059779151255361115',6,'aosi',NULL),(527,'957622STL0103696251251130431',6,'aosi',NULL),(528,'762212STL0151724261252161133',2,'csbs',NULL),(529,'302575UNC0040387121233011108',2,'adi_r_proband',NULL),(530,'429591UNC0092688121257195267',3,'adi_r_proband',NULL),(531,'568175UNC0084684221253642976',4,'adi_r_proband',NULL),(532,'713824UNC0046446121243546453',2,'adi_r_proband',NULL),(533,'856858UNC0045389121233013668',3,'adi_r_proband',NULL),(534,'996243UNC0019173121224793695',4,'adi_r_proband',NULL),(535,'171701UNC0008427151242926015',6,'aosi',NULL),(536,'324373UNC0079562151246055325',6,'aosi',NULL),(537,'420719UNC0078560151248031759',6,'aosi',NULL),(538,'515353UNC0059517151243546601',6,'aosi',NULL),(539,'618551UNC0052593151246627762',6,'aosi',NULL),(540,'778775UNC0041588151244825501',6,'aosi',NULL),(541,'856858UNC0045389151246896628',6,'aosi',NULL),(542,'950194UNC0022519151243957664',6,'aosi',NULL),(543,'220416PHI0096582151244661551',3,'aosi',NULL),(544,'220416PHI0096582151244661551',6,'aosi',NULL),(545,'171701UNC0008427151242926015',5,'aosi',NULL),(546,'323421UNC0072606151246299137',6,'aosi',NULL),(547,'167672UNC0021502151243545626',5,'aosi',NULL),(548,'167672UNC0021502151243545626',6,'aosi',NULL),(549,'201597PHI0056753151253281727',3,'aosi',NULL),(550,'201597PHI0056753151253281727',6,'aosi',NULL);
/*!40000 ALTER TABLE `reliability` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-12-17 17:37:21