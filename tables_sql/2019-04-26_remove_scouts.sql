
-- ------------------------------------------------------------------------------------
-- 
-- The scout scans are cluttering the mri_protocol_violated_scans table. This patch
-- eliminates them. There is an associated shell script that should be run on pinch
-- after this patch is run to also eliminate from the file system the files associated
-- to the records deleted by this patch.
--
-- ------------------------------------------------------------------------------------

DELETE FROM mri_protocol_violated_scans WHERE series_description LIKE '%scout%';
