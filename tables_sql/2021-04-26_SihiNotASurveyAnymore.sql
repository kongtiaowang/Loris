-- -------------------------------------------------------
-- 
-- Converts the SIHI survey into a non-survey instrument.
-- Populates the test battery so that the SIHI is admnistered
-- at VSA-Sleep (all subprojects).
--
-- -------------------------------------------------------


RENAME TABLE SIHI_survey TO SIHI;

UPDATE instrument_subtests SET test_name = 'SIHI', subtest_name = REPLACE(subtest_name, '_survey', '') WHERE test_name = 'SIHI_survey';

INSERT INTO test_names (Test_name, Full_name, Sub_group, IsDirectEntry) VALUES ('SIHI', 'SIHI (Sleep Intervention History Interview)', 1, 0);

UPDATE media                      SET instrument = 'SIHI' WHERE instrument = 'SIHI_survey';
UPDATE participant_emails         SET Test_name  = 'SIHI' WHERE Test_name  = 'SIHI_survey';
UPDATE publication_test_names_rel SET TestNameID = 'SIHI' WHERE TestNameID = 'SIHI_survey';

DELETE FROM test_names WHERE test_name = 'SIHI_survey';

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


