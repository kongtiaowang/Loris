CREATE TABLE `mri_parameter_ep` (
  `CommentID` varchar(255) NOT NULL default '',
  `UserID` varchar(255) default NULL,
  `Examiner` varchar(255) default NULL,
  `Testdate` timestamp NOT NULL default CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
  `Date_taken` date default NULL,
  `Candidate_Age` varchar(255) default NULL,
  `Window_Difference` varchar(255) default NULL,
  `t1_pass_msg` varchar(255) default NULL,
  `t2_pass_msg` varchar(255) default NULL,
  `bold_pass_msg` varchar(255) default NULL,
  `dti_pass_msg` varchar(255) default NULL,
  `ap_p0` varchar(255) default NULL,
  `ap_n0` varchar(255) default NULL,
  `ap_p1` varchar(255) default NULL,
  `ap_n1` varchar(255) default NULL,
  `study` varchar(255) default NULL,
  `time_enter` varchar(255) default NULL,
  `time_enter_status` enum('not_answered') default NULL,
  `start0` varchar(255) default NULL,
  `end0` varchar(255) default NULL,
  `start1` varchar(255) default NULL,
  `end1` varchar(255) default NULL,
  `start2` varchar(255) default NULL,
  `end2` varchar(255) default NULL,
  `start3` varchar(255) default NULL,
  `end3` varchar(255) default NULL,
  `t1_0` enum('0','1') default NULL,
  `t2_0` enum('0','1') default NULL,
  `anterior0` varchar(255) default NULL,
  `superior0` varchar(255) default NULL,
  `ant_d_sup0` varchar(255) default NULL,
  `s_pass0` enum('0','1') default NULL,
  `t1_1` enum('0','1') default NULL,
  `t2_1` enum('0','1') default NULL,
  `anterior1` varchar(255) default NULL,
  `superior1` varchar(255) default NULL,
  `ant_d_sup1` varchar(255) default NULL,
  `s_pass1` enum('0','1') default NULL,
  `t1_2` enum('0','1') default NULL,
  `t2_2` enum('0','1') default NULL,
  `anterior2` varchar(255) default NULL,
  `superior2` varchar(255) default NULL,
  `ant_d_sup2` varchar(255) default NULL,
  `s_pass2` enum('0','1') default NULL,
  `t1_3` enum('0','1') default NULL,
  `t2_3` enum('0','1') default NULL,
  `anterior3` varchar(255) default NULL,
  `superior3` varchar(255) default NULL,
  `ant_d_sup3` varchar(255) default NULL,
  `s_pass3` enum('0','1') default NULL,
  `t1_4` enum('0','1') default NULL,
  `t2_4` enum('0','1') default NULL,
  `anterior4` varchar(255) default NULL,
  `superior4` varchar(255) default NULL,
  `ant_d_sup4` varchar(255) default NULL,
  `s_pass4` enum('0','1') default NULL,
  `t1_5` enum('0','1') default NULL,
  `t2_5` enum('0','1') default NULL,
  `anterior5` varchar(255) default NULL,
  `superior5` varchar(255) default NULL,
  `ant_d_sup5` varchar(255) default NULL,
  `s_pass5` enum('0','1') default NULL,
  `t1_pass` enum('0','1') default NULL,
  `t2_pass` enum('0','1') default NULL,
  `b1_run0` enum('0','1') default NULL,
  `b2_run1` enum('0','1') default NULL,
  `b3_run2` enum('0','1') default NULL,
  `blast1_run3` enum('0','1') default NULL,
  `bp1_run0` enum('0','1') default NULL,
  `bp1_firmm_0` enum('0','1') default NULL,
  `bp1_02_0` varchar(255) default NULL,
  `bp1_pass_0` enum('0','1') default NULL,
  `bp2_run1` enum('0','1') default NULL,
  `bp2_firmm_1` enum('0','1') default NULL,
  `bp2_02_1` varchar(255) default NULL,
  `bp2_pass_1` enum('0','1') default NULL,
  `bp3_run2` enum('0','1') default NULL,
  `bp3_firmm_2` enum('0','1') default NULL,
  `bp3_02_2` varchar(255) default NULL,
  `bp3_pass_2` enum('0','1') default NULL,
  `bold_pass` enum('0','1') default NULL,
  `101b0run0` varchar(255) default NULL,
  `101b0fail0` varchar(255) default NULL,
  `101b0pass0` enum('0','1') default NULL,
  `dti1run1` enum('0','1') default NULL,
  `dti1fail1` varchar(255) default NULL,
  `dti1pass1` enum('0','1') default NULL,
  `dti2run2` enum('0','1') default NULL,
  `dti2fail2` varchar(255) default NULL,
  `dti2pass2` enum('0','1') default NULL,
  `105b0run3` enum('0','1') default NULL,
  `105b0fail3` varchar(255) default NULL,
  `105b0pass3` enum('0','1') default NULL,
  `dti3run4` enum('0','1') default NULL,
  `dti3fail4` varchar(255) default NULL,
  `dti3pass4` enum('0','1') default NULL,
  `dti4run5` enum('0','1') default NULL,
  `dti4fail5` varchar(255) default NULL,
  `dti4pass5` enum('0','1') default NULL,
  `dti_pass` enum('0','1') default NULL,
  `b4_run0` enum('0','1') default NULL,
  `blast2_run1` enum('0','1') default NULL,
  `bp4_run0` enum('0','1','none') default NULL,
  `bp4_firmm_0` enum('0','1') default NULL,
  `bp4_02_0` varchar(255) default NULL,
  `bp4_pass_0` enum('0','1') default NULL,
  `session_number` varchar(255) default NULL,
  `record_orientation_1` enum('','supine','leftlat','rightlat') default NULL,
  `record_orientation_2` enum('','supine','leftlat','rightlat') default NULL,
  `record_orientation_3` enum('','supine','leftlat','rightlat') default NULL,
  `record_orientation_4` enum('','supine','leftlat','rightlat') default NULL,
  `record_vitamine_1` enum('','left','right') default NULL,
  `record_vitamine_2` enum('','left','right') default NULL,
  `record_vitamine_3` enum('','left','right') default NULL,
  `record_vitamine_4` enum('','left','right') default NULL,
  `boldplus_attempts` varchar(255) default NULL,
  `captured_cycle` varchar(255) default NULL,
  `acquisition_window` varchar(255) default NULL,
  `101b0try0` varchar(255) default NULL,
  `page0_comment` text,
  `page1_comment` text,
  `page2_comment` text,
  `page3_comment` text,
  `page4_comment` text,
  `page5_comment` text,
  `page6_comment` text,
  `csf_run` enum('0','1','') default NULL,
  `csf_pass` enum('0','1','') default NULL,
  `csf_attempts` text,
  `pulse` enum('finger','toe') default NULL,
  `hr_range` text,
  `dti1try1` varchar(255) default NULL,
  `dti2try2` varchar(255) default NULL,
  `105b0try3` varchar(255) default NULL,
  `dti3try4` varchar(255) default NULL,
  `dti4try5` varchar(255) default NULL,
  `bold_attempts` varchar(255) default NULL,
  `s_0` enum('','t1','t2') default NULL,
  `s_1` enum('','t1','t2') default NULL,
  `s_2` enum('','t1','t2') default NULL,
  `s_3` enum('','t1','t2') default NULL,
  `s_4` enum('','t1','t2') default NULL,
  `s_5` enum('','t1','t2') default NULL,
  `t1w_pass` varchar(255) default NULL,
  `t2w_pass` varchar(255) default NULL,
  `face_mask` varchar(255) default NULL,
  `face_shield` varchar(255) default NULL,
  `other_comment` text,
  `overall_success` enum('','full_protocol_acquired','only_core_acquired','partial_core_acquired','none_core_acquired') default NULL,
  `if_partial_or_none` enum('','subject_woke_up','ran_out_of_time','subject_did_not_sleep','none_core_acquired','family_canceled','family_declined_2nd_attempt') default NULL,
  `height` varchar(255) default NULL,
  `height_status` varchar(255) default NULL,
  `weight` varchar(255) default NULL,
  `weight_status` varchar(255) default NULL,
  `head_circumference` varchar(255) default NULL,
  `head_circumference_status` varchar(255) default NULL,
  `mr_tech` varchar(255) default NULL,
  `mr_tech_status` varchar(255) default NULL,
  `behavioral_specialist` varchar(255) default NULL,
  `behavioral_specialist_status` varchar(255) default NULL,
  `Medications` enum('0','1','') default NULL,
  `record_scan_done_1` enum('0','1','') default NULL,
  `record_scan_done_2` enum('0','1','') default NULL,
  `record_scan_done_3` enum('0','1','') default NULL,
  `record_scan_done_4` enum('0','1','') default NULL,
  `record_scan_date_1` date default NULL,
  `record_scan_date_2` date default NULL,
  `record_scan_date_3` date default NULL,
  `record_scan_date_4` date default NULL,
  `record_time_enter_mri_room_1` time default NULL,
  `record_scan_start_time_1` time default NULL,
  `record_scan_end_time_1` time default NULL,
  `record_time_enter_mri_room_2` time default NULL,
  `record_scan_start_time_2` time default NULL,
  `record_scan_end_time_2` time default NULL,
  `record_time_enter_mri_room_3` time default NULL,
  `record_scan_start_time_3` time default NULL,
  `record_scan_end_time_3` time default NULL,
  `record_time_enter_mri_room_4` time default NULL,
  `record_scan_start_time_4` time default NULL,
  `record_scan_end_time_4` time default NULL,
  `record_medications_other` text,
  `structural_session_0` enum('1','2','3','4') default NULL,
  `structural_session_1` enum('1','2','3','4') default NULL,
  `structural_session_2` enum('1','2','3','4') default NULL,
  `structural_session_3` enum('1','2','3','4') default NULL,
  `structural_session_4` enum('1','2','3','4') default NULL,
  `structural_session_5` enum('1','2','3','4') default NULL,
  `bold_session_0` enum('1','2','3','4') default NULL,
  `bold_session_1` enum('1','2','3','4') default NULL,
  `bold_session_2` enum('1','2','3','4') default NULL,
  `dti_session_0` enum('1','2','3','4') default NULL,
  `dti_session_1` enum('1','2','3','4') default NULL,
  `dti_session_2` enum('1','2','3','4') default NULL,
  `dti_session_3` enum('1','2','3','4') default NULL,
  `dti_session_4` enum('1','2','3','4') default NULL,
  `dti_session_5` enum('1','2','3','4') default NULL,
  `bold_plus_session_0` enum('1','2','3','4') default NULL,
  `firm_not_used` varchar(255) default NULL,
  `firm_not_used_plus` varchar(255) default NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB default CHARSET=utf8;