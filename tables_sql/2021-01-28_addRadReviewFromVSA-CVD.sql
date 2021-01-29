-- ----------------------------------------------------------------------------
--  
-- Add form Radiology_Review_VSA to all VSA-CVD visits (all sub-projects)
-- 
-- ----------------------------------------------------------------------------
INSERT INTO test_battery (Test_name             , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('Radiology_Review_VSA', '0'       , '0'       , 'Y'   , 'Visit', 1           , 'VSA-CVD'  , NULL    ),
                         ('Radiology_Review_VSA', '0'       , '0'       , 'Y'   , 'Visit', 2           , 'VSA-CVD'  , NULL    ),
                         ('Radiology_Review_VSA', '0'       , '0'       , 'Y'   , 'Visit', 3           , 'VSA-CVD'  , NULL    ),
                         ('Radiology_Review_VSA', '0'       , '0'       , 'Y'   , 'Visit', 9           , 'VSA-CVD'  , NULL    ),
                         ('Radiology_Review_VSA', '0'       , '0'       , 'Y'   , 'Visit', 10          , 'VSA-CVD'  , NULL    ),
                         ('Radiology_Review_VSA', '0'       , '0'       , 'Y'   , 'Visit', 21          , 'VSA-CVD'  , NULL    );
