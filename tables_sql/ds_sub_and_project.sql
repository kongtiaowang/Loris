INSERT INTO `Project` (`Name`, `recruitmentTarget`) VALUES ("Down's Syndrome", 15);
INSERT INTO `subproject` (`title`, `useEDC`, `WindowDifference`) VALUES ("DS", 0, "optimal");
INSERT INTO project_rel (ProjectID, SubprojectID) VALUES ((SELECT ProjectID FROM Project WHERE Name="Down's Syndrome"), (SELECT SubprojectID FROM subproject WHERE title='DS'));
