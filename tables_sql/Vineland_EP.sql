-- ------------------------------------------------------------------------------------
--
-- SQL for the Vineland_3_Proband instrument.
--                
-- This new instrument is to be administered for DS-Infant at visits V6 and V6-CVD
--
-- ------------------------------------------------------------------------------------

-- ---------------------------------------------
-- Table structure identical to Vineland_SA
-- --------------------------------------------
CREATE TABLE Vineland_EP LIKE Vineland_SA;

INSERT INTO test_names (Test_name, Full_name, Sub_group, TestExpert, IsDirectEntry)
    SELECT 'Vineland_EP', 'Vineland Adaptive Behavior Scales, Third Edition (Vineland™-3)', tn.Sub_group, tn.TestExpert, tn.IsDirectEntry
    FROM test_names tn
    WHERE tn.test_name = 'Vineland_SA';

-- ---------------------------------------------------------
-- No inserts in intrument_subtests, just like Vineland_SA
-- ---------------------------------------------------------

-- ---------------------------------------------------------------
-- Add the Vineland_3_Proband instrument to the V6 visit for
-- subproject IDS 20 and 23
-- ---------------------------------------------------------------

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 19, 'V06', NULL);

-- ------------------------------------------------------------------
-- Add the Vineland_3_Proband instrument to the V6-CVD visit for
-- subproject IDS 20 and 23
-- ------------------------------------------------------------------

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V6-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 19, 'V6-CVD', NULL);
