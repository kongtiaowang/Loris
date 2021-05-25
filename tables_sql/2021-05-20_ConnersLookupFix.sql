-- ======================================================================
--
-- Updates done on both the Conners parent and teacher lookup tables.
--
-- ======================================================================

-- ====================
--   CONNERS PARENT
-- ====================

UPDATE conners_parent_lookup SET scale_raw_score='' WHERE scale_raw_score='-';

UPDATE conners_parent_lookup SET scale_T_score = '<=40' WHERE scale_T_score = '<40';
UPDATE conners_parent_lookup SET scale_T_score = '>=90' WHERE scale_T_score = '>90';


-- -------------
--     IN     --
-- -------------
UPDATE conners_parent_lookup SET scale_raw_score='13' WHERE age_years=7 AND sex='F' AND scale='IN' and scale_T_score='87';
UPDATE conners_parent_lookup SET scale_raw_score='1'  WHERE age_years=9 AND sex='F' AND scale='IN' and scale_T_score='44';


-- -------------
--     HY     --
-- -------------
UPDATE conners_parent_lookup SET scale_raw_score='1'  WHERE age_years=8 AND sex='F' AND scale='HY' and scale_T_score='44';

-- -------------
--     LP     --
-- -------------
UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=7  AND SEX='F' AND scale='LP' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=8  AND SEX='F' AND scale='LP' AND scale_raw_score='1';

-- -------------
--     AG     --
-- -------------
UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=6  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=7  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=8  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=9  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
INSERT INTO conners_parent_lookup VALUES(10, 'M', 'AG', '0', '45');
UPDATE conners_parent_lookup SET scale_T_score='44' WHERE age_years=11 AND SEX='M' AND scale='AG' AND scale_raw_score='0';

UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=12 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=13 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=14 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='44' WHERE age_years=15 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=16 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=17 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=18 AND SEX='M' AND scale='AG' AND scale_raw_score='0';

UPDATE conners_parent_lookup SET scale_T_score='55' WHERE age_years=6  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='52' WHERE age_years=7  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='52' WHERE age_years=8  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=9  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='53' WHERE age_years=10 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=11 AND SEX='M' AND scale='AG' AND scale_raw_score='1';

UPDATE conners_parent_lookup SET scale_T_score='52' WHERE age_years=12 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=13 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=14 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=15 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=16 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=17 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_parent_lookup SET scale_T_score='51' WHERE age_years=18 AND SEX='M' AND scale='AG' AND scale_raw_score='1';


-- -------------
--     PR     --
-- -------------
UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=6  AND SEX='M' AND scale='PR' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=7  AND SEX='M' AND scale='PR' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='46' WHERE age_years=8  AND SEX='M' AND scale='PR' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=9  AND SEX='M' AND scale='PR' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='45' WHERE age_years=10 AND SEX='M' AND scale='PR' AND scale_raw_score='0';
UPDATE conners_parent_lookup SET scale_T_score='44' WHERE age_years=11 AND SEX='M' AND scale='PR' AND scale_raw_score='0';


-- =========================
--
-- CONNERS TEACHER LOOKUP
--
-- =========================
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=6  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='46' WHERE age_years=7  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=8  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=9  AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=10 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=11 AND SEX='M' AND scale='AG' AND scale_raw_score='0';

UPDATE conners_teacher_lookup SET scale_T_score='46' WHERE age_years=12 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='44' WHERE age_years=13 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=14 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='47' WHERE age_years=15 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='47' WHERE age_years=16 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=17 AND SEX='M' AND scale='AG' AND scale_raw_score='0';
UPDATE conners_teacher_lookup SET scale_T_score='45' WHERE age_years=18 AND SEX='M' AND scale='AG' AND scale_raw_score='0';

UPDATE conners_teacher_lookup SET scale_T_score='50' WHERE age_years=6  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='53' WHERE age_years=7  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='53' WHERE age_years=8  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='52' WHERE age_years=9  AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='51' WHERE age_years=10 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='51' WHERE age_years=11 AND SEX='M' AND scale='AG' AND scale_raw_score='1';

UPDATE conners_teacher_lookup SET scale_T_score='54' WHERE age_years=12 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='50' WHERE age_years=13 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='54' WHERE age_years=14 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='53' WHERE age_years=15 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='53' WHERE age_years=16 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='52' WHERE age_years=17 AND SEX='M' AND scale='AG' AND scale_raw_score='1';
UPDATE conners_teacher_lookup SET scale_T_score='52' WHERE age_years=18 AND SEX='M' AND scale='AG' AND scale_raw_score='1';

