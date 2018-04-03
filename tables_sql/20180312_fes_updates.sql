-- add fes to V24,V36,V37plus in test battery for IBIS2
-- Currently fes is populated only if above visit labels are first visits; so update is only needed
UPDATE test_battery
SET firstVisit=NULL
WHERE Test_name='FamilyEnvironmentScales'
AND SubprojectID in(9,10)
AND Visit_label IN('V24','V36','V37Plus')
AND firstVisit='Y';


-- add  fes to V36 in test battery table for IBIS1
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('FamilyEnvironmentScales',0,0,'Y','Visit',1,'V36') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('FamilyEnvironmentScales',0,0,'Y','Visit',2,'V36') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('FamilyEnvironmentScales',0,0,'Y','Visit',3,'V36') ;
