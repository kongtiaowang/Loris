-- --------------
-- Redmine #17604 
-- --------------

DELETE FROM test_battery WHERE test_name = 'mullen' AND subprojectid in (SELECT subprojectid FROM subproject WHERE title in ('IBIS EP High Risk', 'IBIS EP Low Risk', 'DS Infant'));
