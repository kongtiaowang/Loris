TRUNCATE TABLE `genomic_analysis_modality_enum`;
LOCK TABLES `genomic_analysis_modality_enum` WRITE;
INSERT INTO `genomic_analysis_modality_enum` (`analysis_modality`) VALUES ('Methylation beta-values');
INSERT INTO `genomic_analysis_modality_enum` (`analysis_modality`) VALUES ('Other');
UNLOCK TABLES;
