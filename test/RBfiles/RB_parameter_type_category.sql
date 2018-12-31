TRUNCATE TABLE `parameter_type_category`;
LOCK TABLES `parameter_type_category` WRITE;
INSERT INTO `parameter_type_category` (`ParameterTypeCategoryID`, `Name`, `Type`) VALUES (3,'MRI Variables','Metavars');
INSERT INTO `parameter_type_category` (`ParameterTypeCategoryID`, `Name`, `Type`) VALUES (4,'Identifiers','Metavars');
INSERT INTO `parameter_type_category` (`ParameterTypeCategoryID`, `Name`, `Type`) VALUES (5,'AOSI','Instrument');
UNLOCK TABLES;
