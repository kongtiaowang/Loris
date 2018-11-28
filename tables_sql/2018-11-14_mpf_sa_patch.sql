-- Drop columns sex & scan_protocol
ALTER TABLE mri_parameter_form_sa DROP COLUMN scan_protocol;
ALTER TABLE mri_parameter_form_sa DROP COLUMN sex;

-- Modify columns that now take enums
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN weight
weight enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50','51','52','53','54','55','56','57','58','59','60','61','62','63','64','65','66','67','68','69','70','71','72','73','74','75','76','77','78','79','80','81','82','83','84','85','86','87','88','89','90','91','92','93','94','95','96','97','98','99','100','101','102','103','104','105','106','107','108','109','110','111','112','113','114','115','116','117','118','119','120','121','122','123','124','125','126','127','128','129','130','131','132','133','134','135','136','137','138','139','140','141','142','143','144','145','146','147','148','149','150','151','152','153','154','155','156','157','158','159','160','161','162','163','164','165','166','167','168','169','170','171','172','173','174','175','176','177','178','179','180','181','182','183','184','185','186','187','188','189','190','191','192','193','194','195','196','197','198','199','200') default NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN height
height enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50','51','52','53','54','55','56','57','58','59','60','61','62','63','64','65','66','67','68','69','70') default NULL;
ALTER TABLE mri_parameter_form_sa
CHANGE COLUMN head_circumference
head_circumference enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25') default NULL;

ALTER TABLE mri_parameter_form_sa DROP COLUMN session_attempts;
ALTER TABLE mri_parameter_form_sa DROP COLUMN time_enter_mri_rm;
ALTER TABLE mri_parameter_form_sa DROP COLUMN time_enter_mri_rm_status;
ALTER TABLE mri_parameter_form_sa DROP COLUMN start_time;
ALTER TABLE mri_parameter_form_sa DROP COLUMN start_time_status;
ALTER TABLE mri_parameter_form_sa DROP COLUMN end_time;
ALTER TABLE mri_parameter_form_sa DROP COLUMN end_time_status;

ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_done_1` enum('yes','no') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `time_enter_mri_room_1` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_start_time_1` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_end_time_1` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `vit_e_right_1` enum('yes','no') default NULL,
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_done_2` enum('yes','no') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `time_enter_mri_room_2` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_start_time_2` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_end_time_2` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `vit_e_right_2` enum('yes','no') default NULL,
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_done_3` enum('yes','no') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `time_enter_mri_room_3` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_start_time_3` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_end_time_3` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `vit_e_right_3` enum('yes','no') default NULL,
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_done_4` enum('yes','no') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `time_enter_mri_room_4` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_start_time_4` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_end_time_4` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `vit_e_right_4` enum('yes','no') default NULL,
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_done_5` enum('yes','no') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `time_enter_mri_room_5` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_start_time_5` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `scan_end_time_5` varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `vit_e_right_5` enum('yes','no') default NULL,
ALTER TABLE mri_parameter_form_sa DROP COLUMN `additional_sessions`;

ALTER TABLE mri_parameter_form_sa DROP COLUMN aahscout;
ALTER TABLE mri_parameter_form_sa DROP COLUMN fieldmap_apinv_structural;
ALTER TABLE mri_parameter_form_sa DROP COLUMN localizers;
ALTER TABLE mri_parameter_form_sa DROP COLUMN fieldmap_ap_structural;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t1w_run1_check;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t1w_run2_check;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t2w_check;

ALTER TABLE mri_parameter_form_sa DROP COLUMN t1w_run1_superior;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t1w_run2_superior;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t2w_superior;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t1w_run1_repeat_superior;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t1w_run2_repeat_superior;
ALTER TABLE mri_parameter_form_sa DROP COLUMN t2w_repeat_superior;

ALTER TABLE mri_parameter_form_sa CHANGE COLUMN dti3_shell_attempts
dti3_shell_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `dti3_shell_num_attempts` enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN 3b0
6b0 varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN 3b0_attempts
6b0_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN 6b0_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN dti2_shell_attempts
dti2_shell_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN `dti2_shell_num_attempts` enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN 3b0_2
6b0_2 varchar(255) default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN 3b0_2_attempts
6b0_2_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN 6b0_2_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN dti1_shell_attempts
dti1_shell_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN dti1_shell_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN bold_run1_attempts
bold_run1_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN bold_run1_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN bold_run2_attempts
bold_run2_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN bold_run2_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN bold_run3_attempts
bold_run3_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN bold_run3_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE mri_parameter_form_sa CHANGE COLUMN bold_run4_attempts
bold_run4_attempts enum('console_pass','console_fail') default NULL;
ALTER TABLE mri_parameter_form_sa ADD COLUMN bold_run4_num_attempts enum('0','1','2','3','4','5','6','7','8','9','10') default NULL;

ALTER TABLE mri_parameter_form_sa DROP COLUMN total_number_scans;
ALTER TABLE mri_parameter_form_sa DROP COLUMN total_scan_time;
ALTER TABLE mri_parameter_form_sa DROP COLUMN total_scan_time_status;
ALTER TABLE mri_parameter_form_sa DROP COLUMN total_attempts_t1w;
ALTER TABLE mri_parameter_form_sa DROP COLUMN total_attempts_t2w;
ALTER TABLE mri_parameter_form_sa DROP COLUMN total_attempts_dti;
ALTER TABLE mri_parameter_form_sa DROP COLUMN total_attempts_bold;
ALTER TABLE mri_parameter_form_sa DROP COLUMN data_sent_to_dcc;
ALTER TABLE mri_parameter_form_sa DROP COLUMN data_entry_done_loris;