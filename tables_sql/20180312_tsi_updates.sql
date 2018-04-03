-- add tsi across all IBIS1 & FRX cohorts for V06
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi',0,0,'Y','Visit',1,'V06') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi',0,0,'Y','Visit',2,'V06') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi',0,0,'Y','Visit',3,'V06') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi',0,0,'Y','Visit',4,'V06') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi',0,0,'Y','Visit',5,'V06') ;
-- add tsi across all IBIS1 & FRX cohorts for V12; if V12 is the first visit
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `firstVisit`)
VALUES ('tsi',0,0,'Y','Visit',1,'V12','Y') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `firstVisit`)
VALUES ('tsi',0,0,'Y','Visit',2,'V12','Y') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `firstVisit`)
VALUES ('tsi',0,0,'Y','Visit',3,'V12', 'Y') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `firstVisit`)
VALUES ('tsi',0,0,'Y','Visit',4,'V12', 'Y') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `firstVisit`)
VALUES ('tsi',0,0,'Y','Visit',5,'V12', 'Y') ;
-- add tsi_ followup across all IBIS1 & FRX cohorts for V12
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',1,'V12') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',2,'V12') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',3,'V12') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',4,'V12') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',5,'V12') ;
-- Remove/make inactive tsi across all IBIS2 & DS cohorts for V03 as it is already in Screening(do not want to end up with more than 1 TSI/candidate)
UPDATE test_battery SET Active='N' WHERE Test_name='tsi' AND SubprojectID in(9,10,11) AND Visit_label IN('V03');
-- add tsi_followup across all IBIS2 & DS cohorts for V03
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',9,'V03') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',10,'V03') ;
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('tsi_followup',0,0,'Y','Visit',11,'V03') ;







