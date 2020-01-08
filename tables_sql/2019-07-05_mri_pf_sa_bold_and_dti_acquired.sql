-- -------------------------------------------------------------------------------------------
--
-- Remaps enum values for column dti_sequences_acquired of table mri_parameter_form_sa
--
-- The enum values change from ('complete','partial','No') to ('complete','partial','none')
-- All existing 'No' are set to 'none' for this column.
--
-- -------------------------------------------------------------------------------------------
ALTER TABLE mri_parameter_form_sa CHANGE dti_sequences_acquired dti_sequences_acquired ENUM('complete','partial','No', 'none') DEFAULT NULL;
UPDATE mri_parameter_form_sa SET dti_sequences_acquired='none' WHERE dti_sequences_acquired='No';
ALTER TABLE mri_parameter_form_sa CHANGE dti_sequences_acquired dti_sequences_acquired ENUM('complete','partial','none') DEFAULT NULL;


-- -------------------------------------------------------------------------------------------
--
-- Remaps enum values for column bold_sequences_acquired of table mri_parameter_form_sa
--
-- The enum values change from ('complete','partial','No') to ('complete','partial','none')
-- All existing 'No' are set to 'none' for this column.
--
-- -------------------------------------------------------------------------------------------
ALTER TABLE mri_parameter_form_sa CHANGE bold_sequences_acquired bold_sequences_acquired ENUM('complete','partial','No', 'none') DEFAULT NULL;
UPDATE mri_parameter_form_sa SET bold_sequences_acquired='none' WHERE bold_sequences_acquired='No';
ALTER TABLE mri_parameter_form_sa CHANGE bold_sequences_acquired bold_sequences_acquired ENUM('complete','partial','none') DEFAULT NULL;
