-- Correct neuro_screen instead of neuroscreen
UPDATE test_battery set Test_name='neuro_screen' where Test_name='neuroscreen' and Visit_label='VSA';
-- Add PSS to V12 battery for DS candidates
INSERT INTO `test_battery`(`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`)
VALUES ('parental_stress_scale',0,0,'Y','Visit',11,'V12');