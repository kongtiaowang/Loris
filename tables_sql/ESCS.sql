CREATE TABLE `ESCS` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`ija_lower_total` varchar(255) default NULL,
`ija_higher_total` varchar(255) default NULL,
`ija_total` varchar(255) default NULL,
`ija_bid_caregiver_total` varchar(255) default NULL,
`ibr_lower_total` varchar(255) default NULL,
`ibr_higher_total` varchar(255) default NULL,
`ibr_total` varchar(255) default NULL,
`ibr_bid_caregiver_total` varchar(255) default NULL,
`rja_follows_pt_sum` varchar(255) default NULL,
`rja_line_regard_pt_correct` varchar(255) default NULL,
`rja_pt_sum` varchar(255) default NULL,
`rbr_without_g_pass_sum` varchar(255) default NULL,
`rbr_without_g_fail_sum` varchar(255) default NULL,
`rbr_with_g_pass_sum` varchar(255) default NULL,
`rbr_with_g_fail_sum` varchar(255) default NULL,
`rbr_correct` varchar(255) default NULL,
`rbr_total` varchar(255) default NULL,
`pt_imitation_sum` varchar(255) default NULL,
`note1` text default NULL,
`note2` text default NULL,
`ija_ec1` enum('0','1') default NULL,
`ija_ec2` enum('0','1') default NULL,
`ija_ec3` enum('0','1') default NULL,
`ija_ec4` enum('0','1') default NULL,
`ija_ec5` enum('0','1') default NULL,
`ija_ec6` enum('0','1') default NULL,
`ija_ec7` enum('0','1') default NULL,
`ija_ec8` enum('0','1') default NULL,
`ija_ec9` enum('0','1') default NULL,
`ija_ec10` enum('0','1') default NULL,
`ija_ec11` enum('0','1') default NULL,
`ija_ec12` enum('0','1') default NULL,
`ija_ec13` enum('0','1') default NULL,
`ija_ec14` enum('0','1') default NULL,
`ija_ec15` enum('0','1') default NULL,
`ija_ec16` enum('0','1') default NULL,
`ija_ec17` enum('0','1') default NULL,
`ija_ec18` enum('0','1') default NULL,
`ija_ec19` enum('0','1') default NULL,
`ija_ec20` enum('0','1') default NULL,
`ija_al1` enum('0','1') default NULL,
`ija_al2` enum('0','1') default NULL,
`ija_al3` enum('0','1') default NULL,
`ija_al4` enum('0','1') default NULL,
`ija_al5` enum('0','1') default NULL,
`ija_al6` enum('0','1') default NULL,
`ija_al7` enum('0','1') default NULL,
`ija_al8` enum('0','1') default NULL,
`ija_al9` enum('0','1') default NULL,
`ija_al10` enum('0','1') default NULL,
`ija_al11` enum('0','1') default NULL,
`ija_al12` enum('0','1') default NULL,
`ija_al13` enum('0','1') default NULL,
`ija_al14` enum('0','1') default NULL,
`ija_al15` enum('0','1') default NULL,
`ija_al16` enum('0','1') default NULL,
`ija_al17` enum('0','1') default NULL,
`ija_al18` enum('0','1') default NULL,
`ija_al19` enum('0','1') default NULL,
`ija_al20` enum('0','1') default NULL,
`ija_pt1` enum('0','1') default NULL,
`ija_pt2` enum('0','1') default NULL,
`ija_pt3` enum('0','1') default NULL,
`ija_pt4` enum('0','1') default NULL,
`ija_pt5` enum('0','1') default NULL,
`ija_pt6` enum('0','1') default NULL,
`ija_pt7` enum('0','1') default NULL,
`ija_pt8` enum('0','1') default NULL,
`ija_pt9` enum('0','1') default NULL,
`ija_pt10` enum('0','1') default NULL,
`ija_pt11` enum('0','1') default NULL,
`ija_pt12` enum('0','1') default NULL,
`ija_pt13` enum('0','1') default NULL,
`ija_pt14` enum('0','1') default NULL,
`ija_pt15` enum('0','1') default NULL,
`ija_pt16` enum('0','1') default NULL,
`ija_pt17` enum('0','1') default NULL,
`ija_pt18` enum('0','1') default NULL,
`ija_pt19` enum('0','1') default NULL,
`ija_pt20` enum('0','1') default NULL,
`ija_pt_ec1` enum('0','1') default NULL,
`ija_pt_ec2` enum('0','1') default NULL,
`ija_pt_ec3` enum('0','1') default NULL,
`ija_pt_ec4` enum('0','1') default NULL,
`ija_pt_ec5` enum('0','1') default NULL,
`ija_pt_ec6` enum('0','1') default NULL,
`ija_pt_ec7` enum('0','1') default NULL,
`ija_pt_ec8` enum('0','1') default NULL,
`ija_pt_ec9` enum('0','1') default NULL,
`ija_pt_ec10` enum('0','1') default NULL,
`ija_pt_ec11` enum('0','1') default NULL,
`ija_pt_ec12` enum('0','1') default NULL,
`ija_pt_ec13` enum('0','1') default NULL,
`ija_pt_ec14` enum('0','1') default NULL,
`ija_pt_ec15` enum('0','1') default NULL,
`ija_pt_ec16` enum('0','1') default NULL,
`ija_pt_ec17` enum('0','1') default NULL,
`ija_pt_ec18` enum('0','1') default NULL,
`ija_pt_ec19` enum('0','1') default NULL,
`ija_pt_ec20` enum('0','1') default NULL,
`ija_sh1` enum('0','1') default NULL,
`ija_sh2` enum('0','1') default NULL,
`ija_sh3` enum('0','1') default NULL,
`ija_sh4` enum('0','1') default NULL,
`ija_sh5` enum('0','1') default NULL,
`ija_sh6` enum('0','1') default NULL,
`ija_sh7` enum('0','1') default NULL,
`ija_sh8` enum('0','1') default NULL,
`ija_sh9` enum('0','1') default NULL,
`ija_sh10` enum('0','1') default NULL,
`ija_sh11` enum('0','1') default NULL,
`ija_sh12` enum('0','1') default NULL,
`ija_sh13` enum('0','1') default NULL,
`ija_sh14` enum('0','1') default NULL,
`ija_sh15` enum('0','1') default NULL,
`ija_sh16` enum('0','1') default NULL,
`ija_sh17` enum('0','1') default NULL,
`ija_sh18` enum('0','1') default NULL,
`ija_sh19` enum('0','1') default NULL,
`ija_sh20` enum('0','1') default NULL,
`ija_care1` enum('0','1') default NULL,
`ija_care2` enum('0','1') default NULL,
`ija_care3` enum('0','1') default NULL,
`ija_care4` enum('0','1') default NULL,
`ija_care5` enum('0','1') default NULL,
`ija_care6` enum('0','1') default NULL,
`ija_care7` enum('0','1') default NULL,
`ija_care8` enum('0','1') default NULL,
`ija_care9` enum('0','1') default NULL,
`ija_care10` enum('0','1') default NULL,
`ija_care11` enum('0','1') default NULL,
`ija_care12` enum('0','1') default NULL,
`ija_care13` enum('0','1') default NULL,
`ija_care14` enum('0','1') default NULL,
`ija_care15` enum('0','1') default NULL,
`ija_care16` enum('0','1') default NULL,
`ija_care17` enum('0','1') default NULL,
`ija_care18` enum('0','1') default NULL,
`ija_care19` enum('0','1') default NULL,
`ija_care20` enum('0','1') default NULL,
`rja_fo1` enum('0','1') default NULL,
`rja_fo2` enum('0','1') default NULL,
`rja_fo3` enum('0','1') default NULL,
`rja_fo4` enum('0','1') default NULL,
`rja_fo5` enum('0','1') default NULL,
`rja_fo6` enum('0','1') default NULL,
`rja_fo7` enum('0','1') default NULL,
`rja_fo8` enum('0','1') default NULL,
`rja_fo9` enum('0','1') default NULL,
`rja_fo10` enum('0','1') default NULL,
`rja_fo11` enum('0','1') default NULL,
`rja_fo12` enum('0','1') default NULL,
`rja_fo13` enum('0','1') default NULL,
`rja_fo14` enum('0','1') default NULL,
`rja_fo15` enum('0','1') default NULL,
`rja_fo16` enum('0','1') default NULL,
`rja_fo17` enum('0','1') default NULL,
`rja_fo18` enum('0','1') default NULL,
`rja_fo19` enum('0','1') default NULL,
`rja_fo20` enum('0','1') default NULL,
`rja_left1` enum('0','1') default NULL,
`rja_back_left1` enum('0','1') default NULL,
`rja_right1` enum('0','1') default NULL,
`rja_back_right1` enum('0','1') default NULL,
`rja_left_d_1` enum('0','1') default NULL,
`rja_back_left_d_1` enum('0','1') default NULL,
`rja_right_d_1` enum('0','1') default NULL,
`rja_back_right_d_1` enum('0','1') default NULL,
`rja_left2` enum('0','1') default NULL,
`rja_back_left2` enum('0','1') default NULL,
`rja_right2` enum('0','1') default NULL,
`rja_back_right2` enum('0','1') default NULL,
`rja_left_d_2` enum('0','1') default NULL,
`rja_back_left_d_2` enum('0','1') default NULL,
`rja_right_d_2` enum('0','1') default NULL,
`rja_back_right_d_2` enum('0','1') default NULL,
`im1` enum('0','1') default NULL,
`im2` enum('0','1') default NULL,
`im3` enum('0','1') default NULL,
`im4` enum('0','1') default NULL,
`im5` enum('0','1') default NULL,
`im6` enum('0','1') default NULL,
`im7` enum('0','1') default NULL,
`im8` enum('0','1') default NULL,
`im9` enum('0','1') default NULL,
`im10` enum('0','1') default NULL,
`im11` enum('0','1') default NULL,
`im12` enum('0','1') default NULL,
`im13` enum('0','1') default NULL,
`im14` enum('0','1') default NULL,
`im15` enum('0','1') default NULL,
`im16` enum('0','1') default NULL,
`im17` enum('0','1') default NULL,
`im18` enum('0','1') default NULL,
`im19` enum('0','1') default NULL,
`im20` enum('0','1') default NULL,
`ibr_ec1` enum('0','1') default NULL,
`ibr_ec2` enum('0','1') default NULL,
`ibr_ec3` enum('0','1') default NULL,
`ibr_ec4` enum('0','1') default NULL,
`ibr_ec5` enum('0','1') default NULL,
`ibr_ec6` enum('0','1') default NULL,
`ibr_ec7` enum('0','1') default NULL,
`ibr_ec8` enum('0','1') default NULL,
`ibr_ec9` enum('0','1') default NULL,
`ibr_ec10` enum('0','1') default NULL,
`ibr_ec11` enum('0','1') default NULL,
`ibr_ec12` enum('0','1') default NULL,
`ibr_ec13` enum('0','1') default NULL,
`ibr_ec14` enum('0','1') default NULL,
`ibr_ec15` enum('0','1') default NULL,
`ibr_ec16` enum('0','1') default NULL,
`ibr_ec17` enum('0','1') default NULL,
`ibr_ec18` enum('0','1') default NULL,
`ibr_ec19` enum('0','1') default NULL,
`ibr_ec20` enum('0','1') default NULL,
`ibr_re1` enum('0','1') default NULL,
`ibr_re2` enum('0','1') default NULL,
`ibr_re3` enum('0','1') default NULL,
`ibr_re4` enum('0','1') default NULL,
`ibr_re5` enum('0','1') default NULL,
`ibr_re6` enum('0','1') default NULL,
`ibr_re7` enum('0','1') default NULL,
`ibr_re8` enum('0','1') default NULL,
`ibr_re9` enum('0','1') default NULL,
`ibr_re10` enum('0','1') default NULL,
`ibr_re11` enum('0','1') default NULL,
`ibr_re12` enum('0','1') default NULL,
`ibr_re13` enum('0','1') default NULL,
`ibr_re14` enum('0','1') default NULL,
`ibr_re15` enum('0','1') default NULL,
`ibr_re16` enum('0','1') default NULL,
`ibr_re17` enum('0','1') default NULL,
`ibr_re18` enum('0','1') default NULL,
`ibr_re19` enum('0','1') default NULL,
`ibr_re20` enum('0','1') default NULL,
`ibr_ap1` enum('0','1') default NULL,
`ibr_ap2` enum('0','1') default NULL,
`ibr_ap3` enum('0','1') default NULL,
`ibr_ap4` enum('0','1') default NULL,
`ibr_ap5` enum('0','1') default NULL,
`ibr_ap6` enum('0','1') default NULL,
`ibr_ap7` enum('0','1') default NULL,
`ibr_ap8` enum('0','1') default NULL,
`ibr_ap9` enum('0','1') default NULL,
`ibr_ap10` enum('0','1') default NULL,
`ibr_ap11` enum('0','1') default NULL,
`ibr_ap12` enum('0','1') default NULL,
`ibr_ap13` enum('0','1') default NULL,
`ibr_ap14` enum('0','1') default NULL,
`ibr_ap15` enum('0','1') default NULL,
`ibr_ap16` enum('0','1') default NULL,
`ibr_ap17` enum('0','1') default NULL,
`ibr_ap18` enum('0','1') default NULL,
`ibr_ap19` enum('0','1') default NULL,
`ibr_ap20` enum('0','1') default NULL,
`ibr_pt1` enum('0','1') default NULL,
`ibr_pt2` enum('0','1') default NULL,
`ibr_pt3` enum('0','1') default NULL,
`ibr_pt4` enum('0','1') default NULL,
`ibr_pt5` enum('0','1') default NULL,
`ibr_pt6` enum('0','1') default NULL,
`ibr_pt7` enum('0','1') default NULL,
`ibr_pt8` enum('0','1') default NULL,
`ibr_pt9` enum('0','1') default NULL,
`ibr_pt10` enum('0','1') default NULL,
`ibr_pt11` enum('0','1') default NULL,
`ibr_pt12` enum('0','1') default NULL,
`ibr_pt13` enum('0','1') default NULL,
`ibr_pt14` enum('0','1') default NULL,
`ibr_pt15` enum('0','1') default NULL,
`ibr_pt16` enum('0','1') default NULL,
`ibr_pt17` enum('0','1') default NULL,
`ibr_pt18` enum('0','1') default NULL,
`ibr_pt19` enum('0','1') default NULL,
`ibr_pt20` enum('0','1') default NULL,
`ibr_pt_ec1` enum('0','1') default NULL,
`ibr_pt_ec2` enum('0','1') default NULL,
`ibr_pt_ec3` enum('0','1') default NULL,
`ibr_pt_ec4` enum('0','1') default NULL,
`ibr_pt_ec5` enum('0','1') default NULL,
`ibr_pt_ec6` enum('0','1') default NULL,
`ibr_pt_ec7` enum('0','1') default NULL,
`ibr_pt_ec8` enum('0','1') default NULL,
`ibr_pt_ec9` enum('0','1') default NULL,
`ibr_pt_ec10` enum('0','1') default NULL,
`ibr_pt_ec11` enum('0','1') default NULL,
`ibr_pt_ec12` enum('0','1') default NULL,
`ibr_pt_ec13` enum('0','1') default NULL,
`ibr_pt_ec14` enum('0','1') default NULL,
`ibr_pt_ec15` enum('0','1') default NULL,
`ibr_pt_ec16` enum('0','1') default NULL,
`ibr_pt_ec17` enum('0','1') default NULL,
`ibr_pt_ec18` enum('0','1') default NULL,
`ibr_pt_ec19` enum('0','1') default NULL,
`ibr_pt_ec20` enum('0','1') default NULL,
`ibr_gv1` enum('0','1') default NULL,
`ibr_gv2` enum('0','1') default NULL,
`ibr_gv3` enum('0','1') default NULL,
`ibr_gv4` enum('0','1') default NULL,
`ibr_gv5` enum('0','1') default NULL,
`ibr_gv6` enum('0','1') default NULL,
`ibr_gv7` enum('0','1') default NULL,
`ibr_gv8` enum('0','1') default NULL,
`ibr_gv9` enum('0','1') default NULL,
`ibr_gv10` enum('0','1') default NULL,
`ibr_gv11` enum('0','1') default NULL,
`ibr_gv12` enum('0','1') default NULL,
`ibr_gv13` enum('0','1') default NULL,
`ibr_gv14` enum('0','1') default NULL,
`ibr_gv15` enum('0','1') default NULL,
`ibr_gv16` enum('0','1') default NULL,
`ibr_gv17` enum('0','1') default NULL,
`ibr_gv18` enum('0','1') default NULL,
`ibr_gv19` enum('0','1') default NULL,
`ibr_gv20` enum('0','1') default NULL,
`ibr_gv_ec1` enum('0','1') default NULL,
`ibr_gv_ec2` enum('0','1') default NULL,
`ibr_gv_ec3` enum('0','1') default NULL,
`ibr_gv_ec4` enum('0','1') default NULL,
`ibr_gv_ec5` enum('0','1') default NULL,
`ibr_gv_ec6` enum('0','1') default NULL,
`ibr_gv_ec7` enum('0','1') default NULL,
`ibr_gv_ec8` enum('0','1') default NULL,
`ibr_gv_ec9` enum('0','1') default NULL,
`ibr_gv_ec10` enum('0','1') default NULL,
`ibr_gv_ec11` enum('0','1') default NULL,
`ibr_gv_ec12` enum('0','1') default NULL,
`ibr_gv_ec13` enum('0','1') default NULL,
`ibr_gv_ec14` enum('0','1') default NULL,
`ibr_gv_ec15` enum('0','1') default NULL,
`ibr_gv_ec16` enum('0','1') default NULL,
`ibr_gv_ec17` enum('0','1') default NULL,
`ibr_gv_ec18` enum('0','1') default NULL,
`ibr_gv_ec19` enum('0','1') default NULL,
`ibr_gv_ec20` enum('0','1') default NULL,
`ibr_care1` enum('0','1') default NULL,
`ibr_care2` enum('0','1') default NULL,
`ibr_care3` enum('0','1') default NULL,
`ibr_care4` enum('0','1') default NULL,
`ibr_care5` enum('0','1') default NULL,
`ibr_care6` enum('0','1') default NULL,
`ibr_care7` enum('0','1') default NULL,
`ibr_care8` enum('0','1') default NULL,
`ibr_care9` enum('0','1') default NULL,
`ibr_care10` enum('0','1') default NULL,
`ibr_care11` enum('0','1') default NULL,
`ibr_care12` enum('0','1') default NULL,
`ibr_care13` enum('0','1') default NULL,
`ibr_care14` enum('0','1') default NULL,
`ibr_care15` enum('0','1') default NULL,
`ibr_care16` enum('0','1') default NULL,
`ibr_care17` enum('0','1') default NULL,
`ibr_care18` enum('0','1') default NULL,
`ibr_care19` enum('0','1') default NULL,
`ibr_care20` enum('0','1') default NULL,
`rbr_wo_g_p1` enum('0','1') default NULL,
`rbr_wo_g_p2` enum('0','1') default NULL,
`rbr_wo_g_p3` enum('0','1') default NULL,
`rbr_wo_g_p4` enum('0','1') default NULL,
`rbr_wo_g_p5` enum('0','1') default NULL,
`rbr_wo_g_p6` enum('0','1') default NULL,
`rbr_wo_g_p7` enum('0','1') default NULL,
`rbr_wo_g_p8` enum('0','1') default NULL,
`rbr_wo_g_p9` enum('0','1') default NULL,
`rbr_wo_g_p10` enum('0','1') default NULL,
`rbr_wo_g_p11` enum('0','1') default NULL,
`rbr_wo_g_p12` enum('0','1') default NULL,
`rbr_wo_g_p13` enum('0','1') default NULL,
`rbr_wo_g_p14` enum('0','1') default NULL,
`rbr_wo_g_p15` enum('0','1') default NULL,
`rbr_wo_g_p16` enum('0','1') default NULL,
`rbr_wo_g_p17` enum('0','1') default NULL,
`rbr_wo_g_p18` enum('0','1') default NULL,
`rbr_wo_g_p19` enum('0','1') default NULL,
`rbr_wo_g_p20` enum('0','1') default NULL,
`rbr_wo_g_f1` enum('0','1') default NULL,
`rbr_wo_g_f2` enum('0','1') default NULL,
`rbr_wo_g_f3` enum('0','1') default NULL,
`rbr_wo_g_f4` enum('0','1') default NULL,
`rbr_wo_g_f5` enum('0','1') default NULL,
`rbr_wo_g_f6` enum('0','1') default NULL,
`rbr_wo_g_f7` enum('0','1') default NULL,
`rbr_wo_g_f8` enum('0','1') default NULL,
`rbr_wo_g_f9` enum('0','1') default NULL,
`rbr_wo_g_f10` enum('0','1') default NULL,
`rbr_wo_g_f11` enum('0','1') default NULL,
`rbr_wo_g_f12` enum('0','1') default NULL,
`rbr_wo_g_f13` enum('0','1') default NULL,
`rbr_wo_g_f14` enum('0','1') default NULL,
`rbr_wo_g_f15` enum('0','1') default NULL,
`rbr_wo_g_f16` enum('0','1') default NULL,
`rbr_wo_g_f17` enum('0','1') default NULL,
`rbr_wo_g_f18` enum('0','1') default NULL,
`rbr_wo_g_f19` enum('0','1') default NULL,
`rbr_wo_g_f20` enum('0','1') default NULL,
`rbr_w_g_p1` enum('0','1') default NULL,
`rbr_w_g_p2` enum('0','1') default NULL,
`rbr_w_g_p3` enum('0','1') default NULL,
`rbr_w_g_p4` enum('0','1') default NULL,
`rbr_w_g_p5` enum('0','1') default NULL,
`rbr_w_g_p6` enum('0','1') default NULL,
`rbr_w_g_p7` enum('0','1') default NULL,
`rbr_w_g_p8` enum('0','1') default NULL,
`rbr_w_g_p9` enum('0','1') default NULL,
`rbr_w_g_p10` enum('0','1') default NULL,
`rbr_w_g_p11` enum('0','1') default NULL,
`rbr_w_g_p12` enum('0','1') default NULL,
`rbr_w_g_p13` enum('0','1') default NULL,
`rbr_w_g_p14` enum('0','1') default NULL,
`rbr_w_g_p15` enum('0','1') default NULL,
`rbr_w_g_p16` enum('0','1') default NULL,
`rbr_w_g_p17` enum('0','1') default NULL,
`rbr_w_g_p18` enum('0','1') default NULL,
`rbr_w_g_p19` enum('0','1') default NULL,
`rbr_w_g_p20` enum('0','1') default NULL,
`rbr_w_g_f1` enum('0','1') default NULL,
`rbr_w_g_f2` enum('0','1') default NULL,
`rbr_w_g_f3` enum('0','1') default NULL,
`rbr_w_g_f4` enum('0','1') default NULL,
`rbr_w_g_f5` enum('0','1') default NULL,
`rbr_w_g_f6` enum('0','1') default NULL,
`rbr_w_g_f7` enum('0','1') default NULL,
`rbr_w_g_f8` enum('0','1') default NULL,
`rbr_w_g_f9` enum('0','1') default NULL,
`rbr_w_g_f10` enum('0','1') default NULL,
`rbr_w_g_f11` enum('0','1') default NULL,
`rbr_w_g_f12` enum('0','1') default NULL,
`rbr_w_g_f13` enum('0','1') default NULL,
`rbr_w_g_f14` enum('0','1') default NULL,
`rbr_w_g_f15` enum('0','1') default NULL,
`rbr_w_g_f16` enum('0','1') default NULL,
`rbr_w_g_f17` enum('0','1') default NULL,
`rbr_w_g_f18` enum('0','1') default NULL,
`rbr_w_g_f19` enum('0','1') default NULL,
`rbr_w_g_f20` enum('0','1') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;