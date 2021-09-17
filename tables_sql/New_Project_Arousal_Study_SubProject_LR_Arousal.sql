INSERT INTO `Project` (`Name`) VALUES ('Arousal Study');
INSERT INTO `subproject` (`title`) VALUES ('LR Arousal');
INSERT INTO `project_rel` (`ProjectID`,`SubprojectID`) VALUES ((SELECT `ProjectID` FROM `Project` WHERE Name='Arousal Study' LIMIT 1),(SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1));

