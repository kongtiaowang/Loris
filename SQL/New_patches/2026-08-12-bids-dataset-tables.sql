-- General BIDS dataset and file tables: `bids_dataset` and `bids_file`, plus
-- nullable foreign keys from data-type-specific file tables.
--
-- These tables are also part of the base schema (SQL/0000-00-00-schema.sql,
-- SQL/0000-00-05-ElectrophysiologyTables.sql are kept in sync with this
-- patch), so every statement is guarded to be safe on fresh installs,
-- on upgrades from the last release, and to be safe to re-run, on both
-- MySQL and MariaDB.

CREATE TABLE IF NOT EXISTS `bids_dataset` (
  `ID` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `Path` VARCHAR(255) NOT NULL,
  `InsertTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `UpdateTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `bids_dataset_path_unique` (`Path`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `bids_file` (
  `ID` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `DatasetID` INT(10) UNSIGNED NOT NULL,
  `Path` VARCHAR(255) NOT NULL,
  `SourcePath` VARCHAR(255) NULL,
  `InsertTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Blake2bHash` CHAR(128) NOT NULL,
  `Derivative` TINYINT(1) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `bids_file_dataset_id_path_unique` (`DatasetID`, `Path`),
  KEY `bids_file_dataset_id_fk_idx` (`DatasetID`),
  CONSTRAINT `bids_file_dataset_id_fk`
    FOREIGN KEY (`DatasetID`) REFERENCES `bids_dataset` (`ID`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

SET @col_exists := (
  SELECT COUNT(*)
  FROM information_schema.columns
  WHERE table_schema = DATABASE()
    AND table_name = 'files'
    AND column_name = 'BidsInfoID'
);
SET @stmt := IF(@col_exists = 0,
  'ALTER TABLE `files` ADD COLUMN `BidsInfoID` INT(10) UNSIGNED NULL, ADD KEY `files_bids_info_id_fk_idx` (`BidsInfoID`), ADD CONSTRAINT `files_bids_info_id_fk` FOREIGN KEY (`BidsInfoID`) REFERENCES `bids_file` (`ID`) ON DELETE SET NULL',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

SET @col_exists := (
  SELECT COUNT(*)
  FROM information_schema.columns
  WHERE table_schema = DATABASE()
    AND table_name = 'physiological_file'
    AND column_name = 'BidsInfoID'
);
SET @stmt := IF(@col_exists = 0,
  'ALTER TABLE `physiological_file` ADD COLUMN `BidsInfoID` INT(10) UNSIGNED NULL, ADD KEY `physiological_file_bids_info_id_fk_idx` (`BidsInfoID`), ADD CONSTRAINT `physiological_file_bids_info_id_fk` FOREIGN KEY (`BidsInfoID`) REFERENCES `bids_file` (`ID`) ON DELETE SET NULL',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

SET @col_exists := (
  SELECT COUNT(*)
  FROM information_schema.columns
  WHERE table_schema = DATABASE()
    AND table_name = 'physiological_event_file'
    AND column_name = 'BidsInfoID'
);
SET @stmt := IF(@col_exists = 0,
  'ALTER TABLE `physiological_event_file` ADD COLUMN `BidsInfoID` INT(10) UNSIGNED NULL, ADD KEY `physiological_event_file_bids_info_id_fk_idx` (`BidsInfoID`), ADD CONSTRAINT `physiological_event_file_bids_info_id_fk` FOREIGN KEY (`BidsInfoID`) REFERENCES `bids_file` (`ID`) ON DELETE SET NULL',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

SET @col_exists := (
  SELECT COUNT(*)
  FROM information_schema.columns
  WHERE table_schema = DATABASE()
    AND table_name = 'meg_ctf_head_shape_file'
    AND column_name = 'BidsInfoID'
);
SET @stmt := IF(@col_exists = 0,
  'ALTER TABLE `meg_ctf_head_shape_file` ADD COLUMN `BidsInfoID` INT(10) UNSIGNED NULL, ADD COLUMN `InsertTime` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP, ADD KEY `meg_ctf_head_shape_file_bids_info_id_fk_idx` (`BidsInfoID`), ADD CONSTRAINT `meg_ctf_head_shape_file_bids_info_id_fk` FOREIGN KEY (`BidsInfoID`) REFERENCES `bids_file` (`ID`) ON DELETE SET NULL',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

-- Re-declare the head shape foreign key after the BIDS changes. Dropping and
-- re-adding must be separate statements: MySQL rejects a drop and re-add of
-- the same constraint name within a single ALTER TABLE (ERROR 1826).
SET @fk_exists := (
  SELECT COUNT(*)
  FROM information_schema.key_column_usage
  WHERE table_schema = DATABASE()
    AND table_name = 'physiological_file'
    AND constraint_name = 'physiological_file_head_shape_file_id_fk'
);
SET @stmt := IF(@fk_exists > 0,
  'ALTER TABLE `physiological_file` DROP FOREIGN KEY `physiological_file_head_shape_file_id_fk`',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

SET @fk_exists := (
  SELECT COUNT(*)
  FROM information_schema.key_column_usage
  WHERE table_schema = DATABASE()
    AND table_name = 'physiological_file'
    AND constraint_name = 'physiological_file_head_shape_file_id_fk'
);
SET @stmt := IF(@fk_exists = 0,
  'ALTER TABLE `physiological_file` ADD CONSTRAINT `physiological_file_head_shape_file_id_fk` FOREIGN KEY (`HeadShapeFileID`) REFERENCES `meg_ctf_head_shape_file` (`ID`) ON DELETE SET NULL',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;
