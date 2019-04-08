-- ----------------------------------------------------------------
--
-- This patch allows the imaging uploader to handle archives that 
-- contain scans for the new Inter-scanner Reliability project
--
-- ----------------------------------------------------------------

-- ---------------------------
--
-- Table imaging_upload_type
-- 
-- ---------------------------
CREATE TABLE `imaging_upload_type` (
     `ID`   INT(10) unsigned NOT NULL auto_increment,
     `Type` varchar(255)     NOT NULL,
     PRIMARY KEY  (`ID`),
     UNIQUE KEY `Type` (`Type`)
)  ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- -----------------------------------------
-- 
-- All the possible imaging upload types
-- 
-- -----------------------------------------
INSERT INTO `imaging_upload_type` VALUES (1, 'Subject');
INSERT INTO `imaging_upload_type` VALUES (2, 'Living Phantom');
INSERT INTO `imaging_upload_type` VALUES (3, 'Lego Phantom');
INSERT INTO `imaging_upload_type` VALUES (4, 'Inter-scanner Reliability');

-- -------------------------------------------------------------
--
-- Addition of column ImagingUploadTypeID to table mri_upload
-- 
-- -------------------------------------------------------------
ALTER TABLE `mri_upload` ADD COLUMN `ImagingUploadTypeID` int(10) unsigned NOT NULL;

-- ----------------------------------------------------------------------
-- 
-- These statements will set the value of column ImagingUploadTypeID for
-- the current IBIS records in mri_upload. Note that we have to delete 
-- some records that were introduced in mri_upload and that clearly did
-- not belong there...
-- 
-- ----------------------------------------------------------------------
DELETE FROM mri_upload WHERE IsPhantom = 'Y' AND UploadLocation NOT LIKE '%lego%' AND UploadLocation NOT LIKE '%living%' AND UploadID IN (309,311,518);
UPDATE mri_upload SET ImagingUploadTypeID = (SELECT ID FROM imaging_upload_type WHERE Type = 'Subject')        WHERE IsPhantom = 'N';
UPDATE mri_upload SET ImagingUploadTypeID = (SELECT ID FROM imaging_upload_type WHERE Type = 'Lego Phantom')   WHERE IsPhantom = 'Y' AND UploadLocation LIKE '%lego%';
UPDATE mri_upload SET ImagingUploadTypeID = (SELECT ID FROM imaging_upload_type WHERE Type = 'Living Phantom') WHERE IsPhantom = 'Y' AND UploadLocation LIKE '%living%';

-- -----------------------------------------
-- Link mri_upload and imaging_upload_type
-- -----------------------------------------
ALTER TABLE `mri_upload` ADD CONSTRAINT `FK_imaging_upload_type_id` FOREIGN KEY (`ImagingUploadTypeID`) REFERENCES `imaging_upload_type` (`ID`);

-- ----------------------------------------------------
--
-- Create project 'Inter-scanner Reliability' and its
-- associated subproject
--
-- ----------------------------------------------------
INSERT INTO Project (Name) VALUES ('Inter-scanner Reliability');
INSERT INTO subproject (title) VALUES ('Inter-scanner Reliability');
INSERT INTO project_rel VALUES (
    (SELECT ProjectID FROM Project WHERE Name='Inter-scanner Reliability'),
    (SELECT SubprojectID FROM subproject WHERE title='Inter-scanner Reliability')
);
