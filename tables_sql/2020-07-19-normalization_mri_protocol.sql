-- ------------------------------------------------------------------------------------------------
-- 
-- This patch normalizes the IBIS specific columns that are not handled by the normalization
-- patch that is part of the standard LORIS distribution (2018-02-27_normalize_mri_protocol.sql)
--
-- IBIS only has one column that is not part of the standard mri_protocol schema and that can 
-- contain a range of numbers: number_of_files
-- ------------------------------------------------------------------------------------------------

ALTER TABLE `mri_protocol` ADD COLUMN `number_of_files_min` DECIMAL(10,0) DEFAULT NULL AFTER `time_max`;
ALTER TABLE `mri_protocol` ADD COLUMN `number_of_files_max` DECIMAL(10,0) DEFAULT NULL AFTER `number_of_files_min`;
