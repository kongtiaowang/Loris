-- Add dropdown for total number of runs/attempts for T1w & T2w scans.

ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL AFTER t1w_acquired;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL AFTER t2w_acquired;
