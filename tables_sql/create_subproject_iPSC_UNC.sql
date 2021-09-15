-- create a new subproject 

INSERT INTO `subproject` (`title`) VALUES ('Proband iPSC UNC');
INSERT INTO `project_rel` (`ProjectID`,`SubprojectID`) VALUES ((SELECT `ProjectID` FROM `Project` WHERE Name='IBIS1' LIMIT 1),(SELECT `SubprojectID` FROM `subproject` WHERE title='Proband iPSC UNC' LIMIT 1));
INSERT INTO `project_rel` (`ProjectID`,`SubprojectID`) VALUES ((SELECT `ProjectID` FROM `Project` WHERE Name='IBIS2' LIMIT 1),(SELECT `SubprojectID` FROM `subproject` WHERE title='Proband iPSC UNC' LIMIT 1));

