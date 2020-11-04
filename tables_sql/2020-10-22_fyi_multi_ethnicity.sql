-- ####################################################################
-- #                                                                  #
-- #   Converts the mother's and father's ethnicity radio buttons to  #
-- #   a serie of checkboxes (one for each possible choice)           #
-- #                                                                  #
-- ####################################################################


-- +++++++++++++++++++++++++++++++++
-- +              Mother           +
-- +++++++++++++++++++++++++++++++++

-- -----------------------------------------------------------------------------
-- Add a column for every possdible value that field 'mother_ethnicity' can have
-- -----------------------------------------------------------------------------
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_white                            VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity;
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_black_african_american           VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity_white;
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_hispanic_latino                  VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity_black_african_american;
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_asian                            VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity_hispanic_latino;
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_american_indian_alaskan_native   VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity_asian;
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_native_hawaiian_pacific_islander VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity_american_indian_alaskan_native;
ALTER TABLE fyi_survey ADD COLUMN mother_ethnicity_not_answered                     VARCHAR(255) DEFAULT NULL AFTER mother_ethnicity_native_hawaiian_pacific_islander;

-- -----------------------------------------------------------------------------------
-- Populate each mother_ethnicity_* column according to what is in 'mother_ethnicity'
-- -----------------------------------------------------------------------------------
UPDATE fyi_survey SET mother_ethnicity_white                            = 'used' WHERE mother_ethnicity LIKE '%white%';
UPDATE fyi_survey SET mother_ethnicity_black_african_american           = 'used' WHERE mother_ethnicity LIKE '%black\_african\_american%';
UPDATE fyi_survey SET mother_ethnicity_hispanic_latino                  = 'used' WHERE mother_ethnicity LIKE '%hispanic\_latino%';
UPDATE fyi_survey SET mother_ethnicity_asian                            = 'used' WHERE mother_ethnicity LIKE '%asian%';
UPDATE fyi_survey SET mother_ethnicity_american_indian_alaskan_native   = 'used' WHERE mother_ethnicity LIKE '%american\_indian\_alaskan\_native%';
UPDATE fyi_survey SET mother_ethnicity_native_hawaiian_pacific_islander = 'used' WHERE mother_ethnicity LIKE '%native\_hawaiian\_pacific\_islander%';
UPDATE fyi_survey SET mother_ethnicity_not_answered                     = 'used' WHERE mother_ethnicity LIKE '%not\_answered%';

-- --------------------------------------------------------
--  Get rid of the (now obsolete) mother_ethnicity column
-- --------------------------------------------------------
ALTER TABLE fyi_survey DROP COLUMN mother_ethnicity;




-- ++++++++++++++++++++++++++++++++++
-- +              Father            +
-- ++++++++++++++++++++++++++++++++++

-- -----------------------------------------------------------------------------
-- Add a column for every possdible value that field 'father_ethnicity' can have
-- -----------------------------------------------------------------------------
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_white                            VARCHAR(255) DEFAULT NULL AFTER father_ethnicity;
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_black_african_american           VARCHAR(255) DEFAULT NULL AFTER father_ethnicity_white;
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_hispanic_latino                  VARCHAR(255) DEFAULT NULL AFTER father_ethnicity_black_african_american;
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_asian                            VARCHAR(255) DEFAULT NULL AFTER father_ethnicity_hispanic_latino;
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_american_indian_alaskan_native   VARCHAR(255) DEFAULT NULL AFTER father_ethnicity_asian;
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_native_hawaiian_pacific_islander VARCHAR(255) DEFAULT NULL AFTER father_ethnicity_american_indian_alaskan_native;
ALTER TABLE fyi_survey ADD COLUMN father_ethnicity_not_answered                     VARCHAR(255) DEFAULT NULL AFTER father_ethnicity_native_hawaiian_pacific_islander;

-- -----------------------------------------------------------------------------------
-- Populate each father_ethnicity_* column according to what is in 'father_ethnicity'
-- -----------------------------------------------------------------------------------
UPDATE fyi_survey SET father_ethnicity_white                            = 'used' WHERE father_ethnicity LIKE '%white%';
UPDATE fyi_survey SET father_ethnicity_black_african_american           = 'used' WHERE father_ethnicity LIKE '%black\_african\_american%';
UPDATE fyi_survey SET father_ethnicity_hispanic_latino                  = 'used' WHERE father_ethnicity LIKE '%hispanic\_latino%';
UPDATE fyi_survey SET father_ethnicity_asian                            = 'used' WHERE father_ethnicity LIKE '%asian%';
UPDATE fyi_survey SET father_ethnicity_american_indian_alaskan_native   = 'used' WHERE father_ethnicity LIKE '%american\_indian\_alaskan\_native%';
UPDATE fyi_survey SET father_ethnicity_native_hawaiian_pacific_islander = 'used' WHERE father_ethnicity LIKE '%native\_hawaiian\_pacific\_islander%';
UPDATE fyi_survey SET father_ethnicity_not_answered                     = 'used' WHERE father_ethnicity LIKE '%not\_answered%';

-- --------------------------------------------------------
--  Get rid of the (now obsolete) father_ethnicity column
-- --------------------------------------------------------
ALTER TABLE fyi_survey DROP COLUMN father_ethnicity;



