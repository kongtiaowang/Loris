alter table `mri_parameter_ep` ADD COLUMN `page0_comment` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `page1_comment` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `page2_comment` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `page3_comment` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `page4_comment` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `page5_comment` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `page6_comment` text  default NULL;


alter table `mri_parameter_ep` ADD COLUMN `csf_run` enum('0','1','')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `csf_pass` enum('0','1','')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `csf_attempts` text  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `pulse` enum('right_finger','left_finger','right_toe','left_toe')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `hr_range` text  default NULL;


alter table `mri_parameter_ep` ADD COLUMN `101b0run0` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `dti1try1` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `dti2try2` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `105b0try3` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `dti3try4` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `dti4try5` varchar(255)  default NULL;



alter table `mri_parameter_ep` ADD COLUMN `bold_attempts` varchar(255)  default NULL;



alter table `mri_parameter_ep` ADD COLUMN `s_0` enum('','t1','t2')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `s_1` enum('','t1','t2')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `s_2` enum('','t1','t2')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `s_3` enum('','t1','t2')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `s_4` enum('','t1','t2')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `s_5` enum('','t1','t2')  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `t1w_pass` varchar(255)  default NULL;

alter table `mri_parameter_ep` ADD COLUMN `t2w_pass` varchar(255)  default NULL;


alter table `mri_parameter_ep` ADD COLUMN `face_mask` enum('','By_Specialist','MR_Tech','Parent_or_Guardian')   default NULL;

alter table `mri_parameter_ep` ADD COLUMN `face_shield` enum('','By_Specialist','MR_Tech','Parent_or_Guardian')   default NULL;

alter table `mri_parameter_ep` ADD COLUMN `other_comment` text   default NULL;

alter table `mri_parameter_ep` ADD COLUMN `overall_success` enum('','full_protocol_acquired','only_core_acquired','partial_core_acquired','none_core_acquired') default NULL;

alter table `mri_parameter_ep` ADD COLUMN `if_partial_or_none` enum('','subject_woke_up','ran_out_of_time','subject_did_not_sleep','none_core_acquired','family_canceled','family_declined_2nd_attempt') default NULL;

alter table `mri_parameter_ep` ADD COLUMN `height` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `height_status` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `weight` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `weight_status` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `head_circumference` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `head_circumference_status` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `mr_tech` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `mr_tech_status` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `behavioral_specialist` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `behavioral_specialist_status` varchar(255) default NULL;

alter table `mri_parameter_ep` ADD COLUMN `Medications` enum('0','1','') default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_done_1` enum('0','1','') default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_scan_done_2` enum('0','1','') default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_scan_done_3` enum('0','1','') default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_scan_done_4` enum('0','1','') default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_date_1` date default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_scan_date_2` date default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_scan_date_3` date default NULL;

alter table `mri_parameter_ep` ADD COLUMN `record_scan_date_4` date default NULL;




alter table `mri_parameter_ep` ADD COLUMN `record_time_enter_mri_room_1` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_start_time_1` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_end_time_1` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_time_enter_mri_room_2` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_start_time_2` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_end_time_2` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_time_enter_mri_room_3` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_start_time_3` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_end_time_3` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_time_enter_mri_room_4` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_start_time_4` time default NULL;


alter table `mri_parameter_ep` ADD COLUMN `record_scan_end_time_4` time default NULL;



alter table `mri_parameter_ep` modify COLUMN `bp4_run0` enum('0','1','none')  default NULL;
