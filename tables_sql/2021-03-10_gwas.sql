-- ---------------------------------------------------
-- 
-- Updates the database with the GWAS instrument
-- 
-- ---------------------------------------------------
CREATE TABLE `gwas` (
  `CommentID`                    varchar(255) NOT NULL DEFAULT '',
  `UserID`                       varchar(255) DEFAULT NULL,
  `Examiner`                     varchar(255) DEFAULT NULL,
  `Testdate`                     timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `Date_taken`                   date DEFAULT NULL,
  `Candidate_Age`                varchar(255) DEFAULT NULL,
  `Window_Difference`            varchar(255) DEFAULT NULL,

  `subject_qc`                   enum('yes', 'no') DEFAULT NULL,
  `subject_gwasid`               varchar(255) DEFAULT NULL,

  `proband_qc`                   enum('yes', 'no') DEFAULT NULL,
  `proband_gwasid`               varchar(255) DEFAULT NULL,

  `mother_qc`                    enum('yes', 'no') DEFAULT NULL,
  `mother_gwasid`                varchar(255) DEFAULT NULL,

  `father_qc`                    enum('yes', 'no') DEFAULT NULL,
  `father_gwasid`                varchar(255) DEFAULT NULL,
  
  `comment`                      varchar(255) DEFAULT NULL,

  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- -------------------------------------------------------
--
-- GWAS instrument only has a main page and goes into the
-- 'Medical' section on the instrument list page
--
-- ------------------------------------------------------- 
INSERT INTO `test_names` (`Test_name`, `Full_name`                    , `Sub_group`)
                  VALUES ('gwas'     , 'Genome-wide Association Study', '7'        );

-- -----------------------------------------------------------------------------
--
-- GWAS is administered at V24 for all IBIS 1 & 2 candidates (all subprojects)
--
-- -----------------------------------------------------------------------------
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage  , SubprojectID, Visit_label, CenterID)
VALUES
                         ('gwas'   , '0'       , '0'       , 'Y'   , 'Visit', 1           , 'V24'      , NULL),
                         ('gwas'   , '0'       , '0'       , 'Y'   , 'Visit', 2           , 'V24'      , NULL),
                         ('gwas'   , '0'       , '0'       , 'Y'   , 'Visit', 3           , 'V24'      , NULL),
                         ('gwas'   , '0'       , '0'       , 'Y'   , 'Visit', 7           , 'V24'      , NULL),
                         ('gwas'   , '0'       , '0'       , 'Y'   , 'Visit', 9           , 'V24'      , NULL),
                         ('gwas'   , '0'       , '0'       , 'Y'   , 'Visit', 10          , 'V24'      , NULL);

