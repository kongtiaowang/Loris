alter table `mri_parameter_ep` Modify COLUMN `record_orientation_1` enum('','supine','leftlat','rightlat')  default NULL;
alter table `mri_parameter_ep` Modify COLUMN `record_orientation_2` enum('','supine','leftlat','rightlat')  default NULL;
alter table `mri_parameter_ep` Modify COLUMN `record_orientation_3` enum('','supine','leftlat','rightlat')  default NULL;
alter table `mri_parameter_ep` Modify COLUMN `record_orientation_4` enum('','supine','leftlat','rightlat')  default NULL;

alter table `mri_parameter_ep` Modify COLUMN `record_vitamine_1` enum('','left','right') default NULL;
alter table `mri_parameter_ep` Modify COLUMN `record_vitamine_2` enum('','left','right') default NULL;
alter table `mri_parameter_ep` Modify COLUMN `record_vitamine_3` enum('','left','right') default NULL;
alter table `mri_parameter_ep` Modify COLUMN `record_vitamine_4` enum('','left','right') default NULL;


alter table `mri_parameter_ep` MODIFY COLUMN `face_mask` varchar(255)  default NULL;
alter table `mri_parameter_ep` MODIFY COLUMN `face_shield` varchar(255)  default NULL;
alter table `mri_parameter_ep` ADD COLUMN `record_medications_other` text default NULL;
