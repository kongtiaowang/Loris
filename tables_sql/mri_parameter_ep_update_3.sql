alter table `mri_parameter_ep` ADD COLUMN `structural_session_0` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `structural_session_1` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `structural_session_2` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `structural_session_3` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `structural_session_4` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `structural_session_5` enum('1','2','3','4')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `bold_session_0` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `bold_session_1` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `bold_session_2` enum('1','2','3','4')  default NULL;


alter table `mri_parameter_ep` ADD COLUMN `dti_session_0` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `dti_session_1` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `dti_session_2` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `dti_session_3` enum('1','2','3','4')  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `dti_session_4` enum('1','2','3','4')  default NULL;


alter table `mri_parameter_ep` ADD COLUMN `bold_plus_session_0` enum('1','2','3','4')  default NULL;

alter table `mri_parameter_ep` MODIFY COLUMN `pulse` enum('finger','toe')  default NULL;

