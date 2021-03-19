-- Redmine 18886
ALTER TABLE Visit_Level_Information_SA DROP COLUMN q3_subject_scan;
ALTER TABLE Visit_Level_Information_SA DROP COLUMN q3_i_if_no_scan_scheduled;
ALTER TABLE Visit_Level_Information_SA MODIFY COLUMN `mock_scan_method_of_collection` enum('in_person') default NULL;
ALTER TABLE Visit_Level_Information_SA MODIFY COLUMN `mri_scan_method_of_collection` enum('in_person') default NULL;