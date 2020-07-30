-- Redmine 17629

UPDATE session SET SubprojectID=(SELECT subprojectid FROM subproject WHERE title = 'Control DS Infant') WHERE ID='6065';
