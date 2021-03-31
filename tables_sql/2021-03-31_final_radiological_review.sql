-- ===============================================================
--
-- Creates a table for instrument final_radiological_review
--
-- ===============================================================


-- #####################################
--
--    final_radiological_review
--
-- #####################################

CREATE TABLE final_radiological_review_VSA LIKE Radiology_Review_VSA;

-- ---------------------------------------------------------------------------------------
--
-- Create new instrument final_radiological_review. It is identical to Radiology_Review_VSA
-- but with a different name
--
-- ---------------------------------------------------------------------------------------
INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry)
       SELECT 'final_radiological_review_VSA', 'Final Study Radiological Review', Sub_Group, IsDirectEntry
       FROM test_names
       WHERE test_name = 'Radiology_Review_VSA';

-- --------------------------------------------------------------------------------------------
--
-- Instrument final_radiological_review has the same instrument subtests as Radiology_Review_VSA
--
-- --------------------------------------------------------------------------------------------
INSERT INTO instrument_subtests (Test_name                      , Subtest_name                         , Description, Order_number)
                          VALUES('final_radiological_review_VSA', 'final_radiological_review_VSA_page1', 'Page1'    , 1           );
INSERT INTO instrument_subtests (Test_name                      , Subtest_name                         , Description, Order_number)
                          VALUES('final_radiological_review_VSA', 'final_radiological_review_VSA_page2', 'Page2'    , 2           );
INSERT INTO instrument_subtests (Test_name                      , Subtest_name                         , Description, Order_number)
                          VALUES('final_radiological_review_VSA', 'final_radiological_review_VSA_page3', 'Page3'    , 3           );

-- ----------------------------------------------------------
--
-- Administration of final_radiological_review_VSA goes like this:
--
-- ----------------------------------------------------------

-- -------------------------
--
-- Project: IBIS 1 and 2
-- Subproject: ALL
-- Visit: VSA and VSA CVD
--
-- -------------------------

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            1, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            2, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            3, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            7, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            9, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           10, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           11, 'VSA'      ,         100);

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            1, 'VSA-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            2, 'VSA-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            3, 'VSA-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            7, 'VSA-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',            9, 'VSA-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           10, 'VSA-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           11, 'VSA-CVD'  ,         100);


-- ---------------------------
--
-- Project: Down Syndrome SA
-- Subproject: ALL
-- Visit: VSA AND VSA CVD
-- 
-- ---------------------------
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           21, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           21, 'VSA-CVD'  ,         100);


-- --------------------------------
--
-- Project: Down syndrome Infant
-- Subproject: ALL
-- Visit: ALL
--
-- --------------------------------

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           20, 'V06'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           20, 'V12'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           20, 'V24'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           20, 'V06-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           20, 'V12-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           20, 'V24-CVD'  ,         100);

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'V06'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'V12'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'V24'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'VSA'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'V06-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'V12-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           23, 'V24-CVD'  ,         100);

-- ----------------------------------------
-- 
-- Project: IBIS EP
-- Subproject: ALL
-- Visit: ALL
--
-- Note that for subproject 18 we have
-- visit V09 and V9-CVD (not a typo...)
--
-- ----------------------------------------

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V06'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V09'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V12'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V18'      ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V24'      ,         100);

INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V06-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V9-CVD'   ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V12-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V18-CVD'  ,         100);
INSERT INTO test_battery (Test_name                , AgeMinDays, AgeMaxDays, Stage  , SubprojectID, Visit_label, instr_order)
                   VALUES('final_radiological_review_VSA' , 0         ,          0, 'Visit',           18, 'V24-CVD'  ,         100);

