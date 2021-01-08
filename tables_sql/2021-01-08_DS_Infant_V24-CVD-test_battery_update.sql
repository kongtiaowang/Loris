-- --------------------------------------------------------------------------------------------
-- 
-- SQL patch that adds the following instruments to the V24-CVD visit of DS-Infant candidates:
--
-- * ADOS2 Modules
-- * HPDT (Hand Preference Demonstration Task)
-- * DSM-IV
--
-- --------------------------------------------------------------------------------------------


INSERT INTO test_battery (Test_name      , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID, firstVisit, instr_order)
                  VALUES ('ados2_module1', 0         , 0         , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL    , NULL      , 15         );
INSERT INTO test_battery (Test_name      , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID, firstVisit, instr_order)
                  VALUES ('ados2_module2', 0         , 0         , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL    , NULL      , 16         );
INSERT INTO test_battery (Test_name      , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID, firstVisit, instr_order)
                  VALUES ('ados2_module3', 0         , 0         , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL    , NULL      , 17         );

INSERT INTO test_battery (Test_name       , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID, firstVisit, instr_order)
                  VALUES ('HandPreference', 0         , 0         , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL    , NULL      , 60         );

INSERT INTO test_battery (Test_name      , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID, firstVisit, instr_order)
                  VALUES ('DSMIV_SA'     , 0         , 0         , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL    , NULL      , 45         );

