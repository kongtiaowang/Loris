INSERT INTO `Project` (`Name`, `Alias`) VALUES ("IDDRC-UNC", "IDDR");
INSERT INTO `subproject` (`title`) VALUES ("Angelman-IDDRC");
INSERT INTO `subproject` (`title`) VALUES ("FXS-IDDRC");
INSERT INTO project_subproject_rel (ProjectID, SubprojectID) VALUES ((SELECT ProjectID FROM Project WHERE Name="IDDRC-UNC"), (SELECT SubprojectID FROM subproject WHERE title="Angelman-IDDRC"));
INSERT INTO project_subproject_rel (ProjectID, SubprojectID) VALUES ((SELECT ProjectID FROM Project WHERE Name="IDDRC-UNC"), (SELECT SubprojectID FROM subproject WHERE title="FXS-IDDRC"));