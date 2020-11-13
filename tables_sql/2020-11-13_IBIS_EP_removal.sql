-- Remove IBIS EP low Risk
DELETE FROM subproject where title='IBIS EP Low Risk';
DELETE FROM project_rel where subprojectId=19;
DELETE FROM test_battery where SubprojectID=19 and Active='N';