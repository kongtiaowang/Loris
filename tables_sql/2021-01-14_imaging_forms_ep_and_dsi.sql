-- ################################################################################################
--
-- Update of the imaging forms used for cohorts DS-Infant and EP:
--
-- 1. Creation of new instrument radiology_review_infant.
--    Data for this new instrument goes into the same table as Radiology_Review_VSA.
-- 2. Creation of new instrument mock_scanner_training_form_infant.
--    Data for this new instrument goes into the same table as Mock_Scanner_Training_Version_2.
-- 3. Update of test_battery for instruments radiology_review_infant, mock_scanner_training_form_infant,
--    mri_parameter_ep and mri_screening_questionnaire.
--
-- ###############################################################################################


-- ==========================
--
-- radiology_review_infant
--
-- ==========================

-- ---------------------------------------------------------------------------------------
--
-- Create new instrument radiology_review_infant. It is identical to Radiology_Review_VSA
-- but with a different name
--
-- ---------------------------------------------------------------------------------------
INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry)
       SELECT 'radiology_review_infant', 'Radiology Review Form / EP & DS-Infant', Sub_Group, IsDirectEntry
       FROM test_names
       WHERE test_name = 'Radiology_Review_VSA';

-- --------------------------------------------------------------------------------------------
--
-- Instrument radiology_review_infant has the same instrument subtests as Radiology_Review_VSA
--
-- --------------------------------------------------------------------------------------------
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number)
    SELECT 'radiology_review_infant', Subtest_name, Description, Order_number
    FROM instrument_subtests
    WHERE Test_name = 'Radiology_Review_VSA';

-- ------------------------------------------------------
--
-- Administer radiology_review_infant at all visits for
-- cohorts  'IBIS EP High Risk' (18), 'DS Infant' (20) and
-- 'Control DS Infant'.
-- This instrument will replace the actual Radiology_Review_VSA
-- for candidates of these cohorts.
--
-- ------------------------------------------------------
UPDATE test_battery SET Active='Y', Test_name = 'radiology_review_infant' WHERE Test_name = 'Radiology_Review_VSA' AND SubprojectID IN (18,20,23);

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           18, 'V06-CVD'  ,        100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           18, 'V12-CVD'  ,        100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           18, 'V24-CVD'  ,        100);

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           20, 'V06-CVD'  ,        100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           20, 'V12-CVD'  ,        100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           20, 'V24-CVD'  ,        100);

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           23, 'V06-CVD'  ,        100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           23, 'V12-CVD'  ,        100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('radiology_review_infant', 0         ,          0, 'Visit',           23, 'V24-CVD'  ,        100);




-- ===================================
--
-- mock_scanner_training_form_infant
--
-- ===================================


-- ---------------------------------------------------------------------------------------
--
-- Create new instrument mock_scanner_training_form_infant. It is identical to
-- Mock_Scanner_Training_Version_2 but with a different name.
--
-- ---------------------------------------------------------------------------------------
INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry)
       SELECT 'mock_scanner_training_form_infant', 'Mock Scanner Training Form / EP & DS-Infant', Sub_Group, IsDirectEntry
       FROM test_names
       WHERE test_name = 'Mock_Scanner_Training_Version_2';

-- ------------------------------------------------------------------------------------
--
-- Instrument mock_scanner_training_form_infant has the same instrument subtests
-- Mock_Scanner_Training_Version_2
--
-- ------------------------------------------------------------------------------------
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number)
    SELECT 'mock_scanner_training_form_infant', Subtest_name, Description, Order_number
    FROM instrument_subtests
    WHERE Test_name = 'Mock_Scanner_Training_Version_2';

-- ---------------------------------------------------------------
--
-- Administer mock_scanner_training_form_infant at all visits for
-- cohorts 'IBIS EP High Risk' (18), 'DS Infant' (20) and
-- 'Control DS Infant'
--
-- ---------------------------------------------------------------
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           18, 'V06-CVD'  ,        100);
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           18, 'V12-CVD'  ,        100);
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           18, 'V24-CVD'  ,        100);

INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           20, 'V06-CVD'  ,        100);
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           20, 'V12-CVD'  ,        100);
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           20, 'V24-CVD'  ,        100);

INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           23, 'V06-CVD'  ,        100);
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           23, 'V12-CVD'  ,        100);
INSERT INTO test_battery (Test_name                          , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('mock_scanner_training_form_infant', 0         ,          0, 'Visit',           23, 'V24-CVD'  ,        100);


-- =====================
--
-- mri_parameter_ep
--
-- =====================


-- -------------------------------------------------------------
--
-- 1. Add mri_parameter_ep to the V24-CVD visit of 'IBIS EP High Risk'
--     candidates
-- 2. Add mri_parameter_ep to the V06-CVD, V12-CVD and V24-CVD visits
--    of 'DS-Infant' and 'Control DS Infant' candidates
-- -------------------------------------------------------------
INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 18          , 'V24-CVD'  , NULL);

INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 20          , 'V06-CVD'  , NULL);
INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 20          , 'V12-CVD'  , NULL);
INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL);

INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 23          , 'V06-CVD'  , NULL);
INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 23          , 'V12-CVD'  , NULL);
INSERT INTO test_battery (Test_name         , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_parameter_ep', '0'       , '0'       , 'Y'   , 'Visit', 23          , 'V24-CVD'  , NULL);


-- ==============================
--
-- mri_screening_questionnaire
--
-- =============================


-- -------------------------------------------------------------
--
-- 1. Add mri_screening_questionnaire to the V24-CVD visit of
--    'IBIS EP High Risk' candidates.
-- 2. Add mri_screening_questionnaire to the V06-CVD, V12-CVD
--    and V24-CVD visits of 'DS-Infant' and 'Control DS Infant'
--    candidates
--
-- -------------------------------------------------------------
INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 18          , 'V24-CVD'  , NULL);

INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 20          , 'V06-CVD'  , NULL);
INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 20          , 'V12-CVD'  , NULL);
INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 20          , 'V24-CVD'  , NULL);

INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 23          , 'V06-CVD'  , NULL);
INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 23          , 'V12-CVD'  , NULL);
INSERT INTO test_battery (Test_name                    , AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
                  VALUES ('mri_screening_questionnaire', '0'       , '0'       , 'Y'   , 'Visit', 23          , 'V24-CVD'  , NULL);

