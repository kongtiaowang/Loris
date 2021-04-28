-- -------------------------------------------------------
-- 
-- Converts the SIHI survey into a non-survey instrument.
-- Populates the test battery so that the SIHI is admnistered
-- at VSA-Sleep (all subprojects).
--
-- -------------------------------------------------------


RENAME TABLE SIHI_survey TO SIHI;

UPDATE instrument_subtests SET test_name = 'SIHI', subtest_name = REPLACE(subtest_name, '_survey', '') WHERE test_name = 'SIHI_survey';

UPDATE test_names SET IsDirectEntry = 0, test_name = 'SIHI', full_name='SIHI (Sleep Intervention History Interview)' WHERE test_name = 'SIHI_survey';

UPDATE flag SET test_name = 'SIHI' WHERE test_name = 'SIHI_survey';

DELETE FROM participant_accounts WHERE test_name = 'SIHI_survey';

DELETE FROM survey_test_battery WHERE test_name = 'SIHI_survey';

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('SIHI'   , '0'       , '0'       , 'Y'   , 'Visit', 1           , 'VSA-Sleep', NULL    ),
                         ('SIHI'   , '0'       , '0'       , 'Y'   , 'Visit', 2           , 'VSA-Sleep', NULL    ),
                         ('SIHI'   , '0'       , '0'       , 'Y'   , 'Visit', 3           , 'VSA-Sleep', NULL    ),
                         ('SIHI'   , '0'       , '0'       , 'Y'   , 'Visit', 9           , 'VSA-Sleep', NULL    ),
                         ('SIHI'   , '0'       , '0'       , 'Y'   , 'Visit', 10          , 'VSA-Sleep', NULL    ),
                         ('SIHI'   , '0'       , '0'       , 'Y'   , 'Visit', 21          , 'VSA-Sleep', NULL    );


