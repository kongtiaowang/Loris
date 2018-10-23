---Add subproject to project IBIS EP

INSERT INTO subproject (title) VALUES ("IBIS EP High Risk");
INSERT INTO subproject (title) VALUES ("IBIS EP Low Risk");
INSERT INTO project_rel (ProjectID, SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS EP'),(SELECT SubprojectID FROM subproject WHERE title='IBIS EP High Risk'));
INSERT INTO project_rel (ProjectID, SubprojectID) VALUES ((SELECT ProjectID from Project WHERE Name='IBIS EP'),(SELECT SubprojectID FROM subproject WHERE title='IBIS EP Low Risk'));

