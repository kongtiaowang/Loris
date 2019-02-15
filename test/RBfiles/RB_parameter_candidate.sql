TRUNCATE TABLE `parameter_candidate`;
LOCK TABLES `parameter_candidate` WRITE;
INSERT INTO `parameter_candidate` (`ParameterCandidateID`, `CandID`, `ParameterTypeID`, `Value`, `InsertTime`) VALUES (1,587630,2,'comment',1543265913);
INSERT INTO `parameter_candidate` (`ParameterCandidateID`, `CandID`, `ParameterTypeID`, `Value`, `InsertTime`) VALUES (2,587630,3,'plan1',1543265913);
INSERT INTO `parameter_candidate` (`ParameterCandidateID`, `CandID`, `ParameterTypeID`, `Value`, `InsertTime`) VALUES (3,300005,3,'as',1475874024);
INSERT INTO `parameter_candidate` (`ParameterCandidateID`, `CandID`, `ParameterTypeID`, `Value`, `InsertTime`) VALUES (4,300005,4,'plan2',1475874024);
UNLOCK TABLES;
