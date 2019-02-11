-- Change weight, height, and head circumference back to open text fields and add select
-- fields for corresponding units
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN weight
weight text DEFAULT NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN weight_units enum ("pounds", "kilograms") DEFAULT NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN height
height text DEFAULT NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN height_units enum ("inches", "centimeters") DEFAULT NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN head_circumference
head_circumference text DEFAULT NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN head_circumference_units enum ("inches", "centimeters") DEFAULT NULL;

-- Add session date
ALTER TABLE mri_parameter_form_sa ADD COLUMN scan_date_1 date default NULL AFTER scan_done_1;
ALTER TABLE mri_parameter_form_sa ADD COLUMN scan_date_2 date default NULL AFTER scan_done_2;
ALTER TABLE mri_parameter_form_sa ADD COLUMN scan_date_3 date default NULL AFTER scan_done_3;
ALTER TABLE mri_parameter_form_sa ADD COLUMN scan_date_4 date default NULL AFTER scan_done_4;
ALTER TABLE mri_parameter_form_sa ADD COLUMN scan_date_5 date default NULL AFTER scan_done_5;


-- Add more T1w & T2w SNR sample sessions
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run3_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run3_passfail enum('Pass','Fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run3_repeat_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run3_repeat_passfail enum('Pass','Fail') default NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN t2w_anterior
t2w_run1_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN t2w_passfail
t2w_run1_passfail enum('Pass','Fail') default NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN t2w_repeat_anterior
t2w_run1_repeat_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN t2w_repeat_passfail
t2w_run1_repeat_passfail enum('Pass','Fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run2_anterior varchar(255) default NULL AFTER t2w_run1_passfail;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run2_passfail enum('Pass','Fail') default NULL AFTER t2w_run2_anterior;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run2_repeat_anterior varchar(255) default NULL AFTER t2w_run1_repeat_passfail;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run2_repeat_passfail enum('Pass','Fail') default NULL AFTER t2w_run2_repeat_anterior;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run3_anterior varchar(255) default NULL AFTER t2w_run2_passfail;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run3_passfail enum('Pass','Fail') default NULL AFTER t2w_run3_anterior;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run3_repeat_anterior varchar(255) default NULL AFTER t2w_run2_repeat_passfail;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run3_repeat_passfail enum('Pass','Fail') default NULL AFTER t2w_run3_repeat_anterior;


-- Change DTI checkboxes to select fields & update existing "yes" responses to "complete"
UPDATE mri_parameter_form_sa SET dti3_shell='complete' WHERE dti3_shell='yes' AND !isnull (dti3_shell);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN dti3_shell
dti3_shell enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET 6b0='complete' WHERE 6b0='yes' AND !isnull (6b0);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN 6b0
6b0 enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET dti2_shell='complete' WHERE dti2_shell='yes' AND !isnull (dti2_shell);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN dti2_shell
dti2_shell enum ('complete','partial','none') default NULL;
ALTER TABLE mri_parameter_form_sa
UPDATE mri_parameter_form_sa SET 6b0_2='complete' WHERE 6b0_2='yes' AND !isnull (6b0_2);
CHANGE COLUMN 6b0_2
6b0_2 enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET dti1_shell='complete' WHERE dti1_shell='yes' AND !isnull (dti1_shell);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN dti1_shell
dti1_shell enum ('complete','partial','none') default NULL;

-- Change BOLD checkboxes to select fields
UPDATE mri_parameter_form_sa SET bold_run1='complete' WHERE bold_run1='yes' AND !isnull (bold_run1);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN bold_run1
bold_run1 enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET bold_run2='complete' WHERE bold_run2='yes' AND !isnull (bold_run2);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN bold_run2
bold_run2 enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET bold_run3='complete' WHERE bold_run3='yes' AND !isnull (bold_run3);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN bold_run3
bold_run3 enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET bold_run4='complete' WHERE bold_run4='yes' AND !isnull (bold_run4);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN bold_run4
bold_run4 enum ('complete','partial','none') default NULL;


UPDATE mri_parameter_form_sa SET FieldMap_APinv_BOLD='complete' WHERE FieldMap_APinv_BOLD='yes' AND !isnull (FieldMap_APinv_BOLD);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN FieldMap_APinv_BOLD
FieldMap_APinv_BOLD enum ('complete','partial','none') default NULL;
UPDATE mri_parameter_form_sa SET FieldMap_AP_BOLD='complete' WHERE FieldMap_AP_BOLD='yes' AND !isnull (FieldMap_APinv_BOLD);
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN FieldMap_AP_BOLD
FieldMap_AP_BOLD enum ('complete','partial','none') default NULL;

