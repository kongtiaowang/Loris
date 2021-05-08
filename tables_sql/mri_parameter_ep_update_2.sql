alter table `mri_parameter_ep` MODIFY COLUMN `face_mask` varchar(255)  default NULL;

alter table `mri_parameter_ep` MODIFY COLUMN `face_shield` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_medications_other` text default NULL;
