CREATE TABLE `instrument_completion_time` (
  `ID` int(10) NOT NULL AUTO_INCREMENT,
  `TestNameID` int(6) NOT NULL,
  `completion_time` VARCHAR(10) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
