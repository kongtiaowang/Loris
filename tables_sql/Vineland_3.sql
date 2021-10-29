-- ------------------------------------------------------------------------------------
--
-- SQL for the Vineland_EP instrument.
--                
-- This new instrument is to be administered for DS_Infant at visits V6 and V6-CVD
--
-- ------------------------------------------------------------------------------------

-- ---------------------------------------------
-- Table structure identical to Vineland_SA
-- --------------------------------------------
CREATE TABLE Vineland_3 LIKE Vineland_SA;

INSERT INTO test_names (Test_name, Full_name, Sub_group, TestExpert, IsDirectEntry)
    SELECT 'Vineland_3', 'Vineland 3', tn.Sub_group, tn.TestExpert, tn.IsDirectEntry
    FROM test_names tn
    WHERE tn.test_name = 'Vineland_SA';

-- ---------------------------------------------------------
-- No inserts in intrument_subtests, just like Vineland_SA
-- ---------------------------------------------------------

-- ------------------------------------------------------------------
-- Add the Vineland_3 instrument to the sub-project (LR Arousal) and visit (LR-Arousal-V1)
-- ------------------------------------------------------------------


-- Add for sub-project LR Arousal

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('Vineland_3', '0', '0', 'Y', 'Visit', (SELECT `SubprojectID` FROM `subproject` WHERE title='LR Arousal' LIMIT 1), 'LR-Arousal-V1', NULL);

