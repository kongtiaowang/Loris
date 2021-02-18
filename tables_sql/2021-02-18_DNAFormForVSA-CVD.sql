-- ----------------------------------------------------------------------------
--
-- Adds instrument DNA_parameter_form for visit VSA-CVD for all cohorts 
-- of IBIS1 & IBIS2.
--
-- ----------------------------------------------------------------------------

INSERT INTO test_battery (Test_name           , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('DNA_parameter_form', '0'       , '0'       , 'Y'   , 'Visit', '1'        , 'VSA-CVD'      , NULL);
INSERT INTO test_battery (Test_name           , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('DNA_parameter_form', '0'       , '0'       , 'Y'   , 'Visit', '2'        , 'VSA-CVD'      , NULL);
INSERT INTO test_battery (Test_name           , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('DNA_parameter_form', '0'       , '0'       , 'Y'   , 'Visit', '3'        , 'VSA-CVD'      , NULL);
INSERT INTO test_battery (Test_name           , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('DNA_parameter_form', '0'       , '0'       , 'Y'   , 'Visit', '9'        , 'VSA-CVD'      , NULL);
INSERT INTO test_battery (Test_name           , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('DNA_parameter_form', '0'       , '0'       , 'Y'   , 'Visit', '10'       , 'VSA-CVD'      , NULL);
