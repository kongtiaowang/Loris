ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run1_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run2_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run3_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run4_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run5_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run6_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run1_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run2_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run3_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run4_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run5_superior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run6_superior varchar(255) default NULL;


ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t1w_run1_repeat_anterior t1w_run4_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t1w_run1_repeat_passfail t1w_run4_passfail varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t1w_run2_repeat_anterior t1w_run5_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t1w_run2_repeat_passfail t1w_run5_passfail varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t1w_run3_repeat_anterior t1w_run6_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t1w_run3_repeat_passfail t1w_run6_passfail varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t2w_run1_repeat_anterior t2w_run4_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t2w_run1_repeat_passfail t2w_run4_passfail varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t2w_run2_repeat_anterior t2w_run5_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t2w_run2_repeat_passfail t2w_run5_passfail varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t2w_run3_repeat_anterior t2w_run6_anterior varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN t2w_run3_repeat_passfail t2w_run6_passfail varchar(255) default NULL;


ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run1_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run2_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run3_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run4_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run5_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t1w_run6_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run1_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run2_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run3_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run4_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run5_snr float(3) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN t2w_run6_snr float(3) default NULL;




