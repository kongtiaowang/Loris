-- Update q2 options in IEP Extraction Form to include 'na'

ALTER TABLE IEP_Extraction_Form MODIFY COLUMN q2_specify_pull_out_services enum('social_skills','mathematics','reading', 'na') default NULL;
