ALTER TABLE `feedback_mri_comments_ibis` ADD `dwi_qc` enum('1', '2', '3') AFTER t2_comment;
ALTER TABLE `feedback_mri_comments_ibis` ADD `dwi_exclusion_reason` enum('1', '2', '3') AFTER dwi_qc;
ALTER TABLE `feedback_mri_comments_ibis` DROP COLUMN dwi_red_artifact;
ALTER TABLE `feedback_mri_comments_ibis` DROP COLUMN dwi_green_artifact;
ALTER TABLE `feedback_mri_comments_ibis` DROP COLUMN dwi_blue_artifact;
