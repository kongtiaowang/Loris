-- -------------------------------------------------------------------------------
-- 
-- Adds instrument asd_peds to the test battery of all V24 and V24-CVD visits for 
-- DS-Infant and Control DS-Infant.
--
-- Fixes https://redmine.cbrain.mcgill.ca/issues/19261
--
-- -------------------------------------------------------------------------------
INSERT INTO test_battery (Test_name , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('asd_peds', 0         , 0         , 'Y'   , 'Visit', 20          , 'V24'      , NULL    );
INSERT INTO test_battery (Test_name , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('asd_peds', 0         , 0         , 'Y'   , 'Visit', 23          , 'V24'      , NULL    );
INSERT INTO test_battery (Test_name , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('asd_peds', 0         , 0         , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL    );
INSERT INTO test_battery (Test_name , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('asd_peds', 0         , 0         , 'Y'   , 'Visit', 23          , 'V24-CVD'  , NULL    );

