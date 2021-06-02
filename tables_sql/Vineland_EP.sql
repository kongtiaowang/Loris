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
CREATE TABLE Vineland_EP LIKE Vineland_SA;

INSERT INTO test_names (Test_name, Full_name, Sub_group, TestExpert, IsDirectEntry)
    SELECT 'Vineland_EP', 'Vineland 3 - EP (Vineland Adaptive Behavior Scales-3rd Edition - EP)', tn.Sub_group, tn.TestExpert, tn.IsDirectEntry
    FROM test_names tn
    WHERE tn.test_name = 'Vineland_SA';

-- ---------------------------------------------------------
-- No inserts in intrument_subtests, just like Vineland_SA
-- ---------------------------------------------------------

-- ------------------------------------------------------------------
-- Add the Vineland_EP instrument to all the sub-projects and visits (except for V9 & V9-CVD)
-- ------------------------------------------------------------------

--Add for sub-project 1

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 1, 'V24-CVD', NULL);


--Add for sub-project 2
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 2, 'V24-CVD', NULL);


--Add for sub-project 3

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 3, 'V24-CVD', NULL);

--Add for sub-project 4

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 4, 'V24-CVD', NULL);

--Add for sub-project 5

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 5, 'V24-CVD', NULL);

--Add for sub-project 6

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 6, 'V24-CVD', NULL);

--Add for sub-project 7

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 7, 'V24-CVD', NULL);

--Add for sub-project 9

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 9, 'V24-CVD', NULL);

--Add for sub-project 10

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 10, 'V24-CVD', NULL);

--Add for sub-project 11

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 11, 'V24-CVD', NULL);

--Add for sub-project 12

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 12, 'V24-CVD', NULL);

--Add for sub-project 13

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 13, 'V24-CVD', NULL);

--Add for sub-project 17

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 17, 'V24-CVD', NULL);

--Add for sub-project 18

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 18, 'V24-CVD', NULL);

--Add for sub-project 20

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 20, 'V24-CVD', NULL);

--Add for sub-project 21

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 21, 'V24-CVD', NULL);

--Add for sub-project 22

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 22, 'V24-CVD', NULL);

--Add for sub-project 23

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V06', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V06-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V12', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V18', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V18-CVD', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V24', NULL);
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('Vineland_EP', '0', '0', 'Y', 'Visit', 23, 'V24-CVD', NULL);

