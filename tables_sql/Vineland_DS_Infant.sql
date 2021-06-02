-- ------------------------------------------------------------------------------------
--
-- SQL for the Vineland_DS_Infant instrument.
--                
-- This new instrument is to be administered for DS-Infant at visits V6 and V6-CVD
--
-- ------------------------------------------------------------------------------------

-- ---------------------------------------------
-- Table structure identical to Vineland_SA
-- --------------------------------------------
CREATE TABLE Vineland_DS_Infant LIKE Vineland_SA;

INSERT INTO test_names (Test_name, Full_name, Sub_group, TestExpert, IsDirectEntry)
    SELECT 'Vineland_DS_Infant', 'Vineland 3 - DS-Infant (Vineland Adaptive Behavior Scales-3rd Edition - DS-Infant)', tn.Sub_group, tn.TestExpert, tn.IsDirectEntry
    FROM test_names tn
    WHERE tn.test_name = 'Vineland_SA';

-- ---------------------------------------------------------
-- No inserts in intrument_subtests, just like Vineland_SA
-- ---------------------------------------------------------
-- ------------------------------------------------------------------
-- Add the Vineland_DS_Infant instrument to all the sub-projects and visits (except for V9 & V9-CVD)
-- ------------------------------------------------------------------


--Add for sub-project 20

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 20, 'V24-CVD', NULL);


--Add for sub-project 23

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_DS_Infant', '0', '0', 'Y', 'Visit', 23, 'V24-CVD', NULL);
