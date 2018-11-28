-- Updating test name display
UPDATE `test_names` SET `Full_name`='SRS-2 School Age (Send to Teacher)' WHERE `Test_name`='SRS2_SchoolAge';
UPDATE `test_names` SET `Full_name`='PSPQ (Send to Mom)' WHERE `Test_name`='pspq_1';
UPDATE `test_names` SET `Full_name`='PSPQ (Send to Dad)' WHERE `Test_name`='pspq_2';
-- Instruments to get excluded from Surveys
UPDATE `test_names` SET `isDirectEntry`='0' WHERE `Test_name`='SRS2_SelfReport';
UPDATE `test_names` SET `isDirectEntry`='0' WHERE `Test_name`='SRS2_InformantReport';
UPDATE `test_names` SET `isDirectEntry`='0' WHERE `Test_name`='ADULT_SELF_REPORT';
UPDATE `test_names` SET `isDirectEntry`='0' WHERE `Test_name`='ABCL';