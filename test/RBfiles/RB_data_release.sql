TRUNCATE TABLE `data_release`;
LOCK TABLES `data_release` WRITE;
INSERT INTO `data_release` (`id`, `file_name`, `version`, `upload_date`) VALUES (1,'46-054.gif','','2018-05-07');
INSERT INTO `data_release` (`id`, `file_name`, `version`, `upload_date`) VALUES (2,'CBSR_patient_export_2017-08-05_12_32_52.csv','oct_10','2018-11-26');
INSERT INTO `data_release` (`id`, `file_name`, `version`, `upload_date`) VALUES (3,'Screening_PD.sql','1.55','2018-11-26');
UNLOCK TABLES;
