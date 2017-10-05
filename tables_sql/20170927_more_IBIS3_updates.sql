-- IBIS3 VSA visit label to incorporate in survey module
INSERT INTO `Visit_Windows` (`Visit_label`) VALUES ('VSA');
-- Update the name of existing IBIS3 subprojects to the confirmed names
UPDATE `subproject` SET `title`='IBIS3 LR' WHERE `SubprojectID`='12';
UPDATE `subproject` SET `title`='IBIS3 HR' WHERE `SubprojectID`='13';
-- Delete the unwanted subprojects from subproject table
DELETE FROM `subproject` WHERE `SubprojectID`='14';
DELETE FROM `subproject` WHERE `SubprojectID`='15';
DELETE FROM `subproject` WHERE `SubprojectID`='16';
-- Delete the unwanted subprojects from project_rel table
DELETE FROM `project_rel`WHERE `SubprojectID`='14';
DELETE FROM `project_rel`WHERE `SubprojectID`='15';
DELETE FROM `project_rel`WHERE `SubprojectID`='16';
-- Active to N in test_battery_table
UPDATE `test_battery` SET `Active` ='N' WHERE `SubprojectID`='14';
UPDATE `test_battery` SET `Active` ='N' WHERE `SubprojectID`='15';
UPDATE `test_battery` SET `Active` ='N' WHERE `SubprojectID`='16';