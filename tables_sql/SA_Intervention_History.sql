CREATE TABLE `SA_Intervention_History` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(100) default NULL,

                            `Examiner` varchar(100) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(100) default NULL,
`Window_Difference` varchar(100) default NULL,
`relationship_to_child` enum('mother','father','step_mother','step_father','other') default NULL,
`relationship_to_child_other` varchar(100) default NULL,
`interviewer_initials` varchar(100) default NULL,
`birth_to_three_services` enum('yes','no','dont_know') default NULL,
`birth_to_three_services_minutes` enum('30','60','90','120','180') default NULL,
`birth_to_three_services_times_per_week` enum('1','2','3','4','5','6','7') default NULL,
`birth_to_three_services_years` enum('0','1','2','3','4','5','6','7','8','9','10') default NULL,
`birth_to_three_services_months` enum('30','60','90','120','180') default NULL,
`day_care` enum('yes','no','dont_know') default NULL,
`day_care_age` enum('0','1','2','3','4','5','6','7','8','9','10') default NULL,
`day_care_years` enum('0','1','2','3','4','5','6','7','8','9','10') default NULL,
`day_care_months` enum('1','2','3','4','5','6','7','8','9','10','11') default NULL,
`day_care_hours_per_week` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40') default NULL,
`nursery_school_preschool` enum('yes','no','dont_know') default NULL,
`nursery_school_preschool_age` enum('0','1','2','3','4','5','6','7','8','9','10') default NULL,
`nursery_school_preschool_years` enum('0','1','2','3','4','5') default NULL,
`nursery_school_preschool_months` enum('0','1','2','3','4','5','6','7','8','9','10','11','12') default NULL,
`support_in_school` enum('yes','no') default NULL,
`support_outside_school` enum('yes','no') default NULL,
`age_10_11_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_10_11_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_10_11_min_1` enum('0','1','2','3') default NULL,
`age_10_11_location_1` varchar(100) default NULL,
`age_10_11_description_1` varchar(100) default NULL,
`age_10_11_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_10_11_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_10_11_min_2` enum('0','1','2','3') default NULL,
`age_10_11_location_2` varchar(100) default NULL,
`age_10_11_description_2` varchar(100) default NULL,
`age_10_11_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_10_11_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_10_11_min_3` enum('0','1','2','3') default NULL,
`age_10_11_location_3` varchar(100) default NULL,
`age_10_11_description_3` varchar(100) default NULL,
`age_10_11_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_10_11_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_10_11_min_4` enum('0','1','2','3') default NULL,
`age_10_11_location_4` varchar(100) default NULL,
`age_10_11_description_4` varchar(100) default NULL,
`age_10_11_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_10_11_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_10_11_min_5` enum('0','1','2','3') default NULL,
`age_10_11_location_5` varchar(100) default NULL,
`age_10_11_description_5` varchar(100) default NULL,
`age_10_11_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_10_11_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_10_11_min_6` enum('0','1','2','3') default NULL,
`age_10_11_location_6` varchar(100) default NULL,
`age_10_11_description_6` varchar(100) default NULL,
`age_9_10_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_9_10_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_9_10_min_1` enum('0','1','2','3') default NULL,
`age_9_10_location_1` varchar(100) default NULL,
`age_9_10_description_1` varchar(100) default NULL,
`age_9_10_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_9_10_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_9_10_min_2` enum('0','1','2','3') default NULL,
`age_9_10_location_2` varchar(100) default NULL,
`age_9_10_description_2` varchar(100) default NULL,
`age_9_10_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_9_10_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_9_10_min_3` enum('0','1','2','3') default NULL,
`age_9_10_location_3` varchar(100) default NULL,
`age_9_10_description_3` varchar(100) default NULL,
`age_9_10_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_9_10_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_9_10_min_4` enum('0','1','2','3') default NULL,
`age_9_10_location_4` varchar(100) default NULL,
`age_9_10_description_4` varchar(100) default NULL,
`age_9_10_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_9_10_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_9_10_min_5` enum('0','1','2','3') default NULL,
`age_9_10_location_5` varchar(100) default NULL,
`age_9_10_description_5` varchar(100) default NULL,
`age_9_10_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_9_10_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_9_10_min_6` enum('0','1','2','3') default NULL,
`age_9_10_location_6` varchar(100) default NULL,
`age_9_10_description_6` varchar(100) default NULL,
`age_8_9_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_8_9_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_8_9_min_1` enum('0','1','2','3') default NULL,
`age_8_9_location_1` varchar(100) default NULL,
`age_8_9_description_1` varchar(100) default NULL,
`age_8_9_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_8_9_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_8_9_min_2` enum('0','1','2','3') default NULL,
`age_8_9_location_2` varchar(100) default NULL,
`age_8_9_description_2` varchar(100) default NULL,
`age_8_9_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_8_9_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_8_9_min_3` enum('0','1','2','3') default NULL,
`age_8_9_location_3` varchar(100) default NULL,
`age_8_9_description_3` varchar(100) default NULL,
`age_8_9_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_8_9_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_8_9_min_4` enum('0','1','2','3') default NULL,
`age_8_9_location_4` varchar(100) default NULL,
`age_8_9_description_4` varchar(100) default NULL,
`age_8_9_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_8_9_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_8_9_min_5` enum('0','1','2','3') default NULL,
`age_8_9_location_5` varchar(100) default NULL,
`age_8_9_description_5` varchar(100) default NULL,
`age_8_9_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_8_9_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_8_9_min_6` enum('0','1','2','3') default NULL,
`age_8_9_location_6` varchar(100) default NULL,
`age_8_9_description_6` varchar(100) default NULL,
`age_7_8_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_7_8_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_7_8_min_1` enum('0','1','2','3') default NULL,
`age_7_8_location_1` varchar(100) default NULL,
`age_7_8_description_1` varchar(100) default NULL,
`age_7_8_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_7_8_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_7_8_min_2` enum('0','1','2','3') default NULL,
`age_7_8_location_2` varchar(100) default NULL,
`age_7_8_description_2` varchar(100) default NULL,
`age_7_8_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_7_8_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_7_8_min_3` enum('0','1','2','3') default NULL,
`age_7_8_location_3` varchar(100) default NULL,
`age_7_8_description_3` varchar(100) default NULL,
`age_7_8_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_7_8_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_7_8_min_4` enum('0','1','2','3') default NULL,
`age_7_8_location_4` varchar(100) default NULL,
`age_7_8_description_4` varchar(100) default NULL,
`age_7_8_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_7_8_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_7_8_min_5` enum('0','1','2','3') default NULL,
`age_7_8_location_5` varchar(100) default NULL,
`age_7_8_description_5` varchar(100) default NULL,
`age_7_8_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_7_8_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_7_8_min_6` enum('0','1','2','3') default NULL,
`age_7_8_location_6` varchar(100) default NULL,
`age_7_8_description_6` varchar(100) default NULL,
`age_6_7_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_6_7_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_6_7_min_1` enum('0','1','2','3') default NULL,
`age_6_7_location_1` varchar(100) default NULL,
`age_6_7_description_1` varchar(100) default NULL,
`age_6_7_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_6_7_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_6_7_min_2` enum('0','1','2','3') default NULL,
`age_6_7_location_2` varchar(100) default NULL,
`age_6_7_description_2` varchar(100) default NULL,
`age_6_7_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_6_7_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_6_7_min_3` enum('0','1','2','3') default NULL,
`age_6_7_location_3` varchar(100) default NULL,
`age_6_7_description_3` varchar(100) default NULL,
`age_6_7_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_6_7_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_6_7_min_4` enum('0','1','2','3') default NULL,
`age_6_7_location_4` varchar(100) default NULL,
`age_6_7_description_4` varchar(100) default NULL,
`age_6_7_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_6_7_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_6_7_min_5` enum('0','1','2','3') default NULL,
`age_6_7_location_5` varchar(100) default NULL,
`age_6_7_description_5` varchar(100) default NULL,
`age_6_7_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_6_7_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_6_7_min_6` enum('0','1','2','3') default NULL,
`age_6_7_location_6` varchar(100) default NULL,
`age_6_7_description_6` varchar(100) default NULL,
`age_5_6_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_5_6_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_5_6_min_1` enum('0','1','2','3') default NULL,
`age_5_6_location_1` varchar(100) default NULL,
`age_5_6_description_1` varchar(100) default NULL,
`age_5_6_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_5_6_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_5_6_min_2` enum('0','1','2','3') default NULL,
`age_5_6_location_2` varchar(100) default NULL,
`age_5_6_description_2` varchar(100) default NULL,
`age_5_6_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_5_6_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_5_6_min_3` enum('0','1','2','3') default NULL,
`age_5_6_location_3` varchar(100) default NULL,
`age_5_6_description_3` varchar(100) default NULL,
`age_5_6_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_5_6_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_5_6_min_4` enum('0','1','2','3') default NULL,
`age_5_6_location_4` varchar(100) default NULL,
`age_5_6_description_4` varchar(100) default NULL,
`age_5_6_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_5_6_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_5_6_min_5` enum('0','1','2','3') default NULL,
`age_5_6_location_5` varchar(100) default NULL,
`age_5_6_description_5` varchar(100) default NULL,
`age_5_6_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_5_6_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_5_6_min_6` enum('0','1','2','3') default NULL,
`age_5_6_location_6` varchar(100) default NULL,
`age_5_6_description_6` varchar(100) default NULL,
`age_4_5_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_4_5_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_4_5_min_1` enum('0','1','2','3') default NULL,
`age_4_5_location_1` varchar(100) default NULL,
`age_4_5_description_1` varchar(100) default NULL,
`age_4_5_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_4_5_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_4_5_min_2` enum('0','1','2','3') default NULL,
`age_4_5_location_2` varchar(100) default NULL,
`age_4_5_description_2` varchar(100) default NULL,
`age_4_5_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_4_5_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_4_5_min_3` enum('0','1','2','3') default NULL,
`age_4_5_location_3` varchar(100) default NULL,
`age_4_5_description_3` varchar(100) default NULL,
`age_4_5_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_4_5_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_4_5_min_4` enum('0','1','2','3') default NULL,
`age_4_5_location_4` varchar(100) default NULL,
`age_4_5_description_4` varchar(100) default NULL,
`age_4_5_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_4_5_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_4_5_min_5` enum('0','1','2','3') default NULL,
`age_4_5_location_5` varchar(100) default NULL,
`age_4_5_description_5` varchar(100) default NULL,
`age_4_5_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_4_5_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_4_5_min_6` enum('0','1','2','3') default NULL,
`age_4_5_location_6` varchar(100) default NULL,
`age_4_5_description_6` varchar(100) default NULL,
`age_3_4_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_3_4_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_3_4_min_1` enum('0','1','2','3') default NULL,
`age_3_4_location_1` varchar(100) default NULL,
`age_3_4_description_1` varchar(100) default NULL,
`age_3_4_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_3_4_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_3_4_min_2` enum('0','1','2','3') default NULL,
`age_3_4_location_2` varchar(100) default NULL,
`age_3_4_description_2` varchar(100) default NULL,
`age_3_4_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_3_4_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_3_4_min_3` enum('0','1','2','3') default NULL,
`age_3_4_location_3` varchar(100) default NULL,
`age_3_4_description_3` varchar(100) default NULL,
`age_3_4_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_3_4_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_3_4_min_4` enum('0','1','2','3') default NULL,
`age_3_4_location_4` varchar(100) default NULL,
`age_3_4_description_4` varchar(100) default NULL,
`age_3_4_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_3_4_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_3_4_min_5` enum('0','1','2','3') default NULL,
`age_3_4_location_5` varchar(100) default NULL,
`age_3_4_description_5` varchar(100) default NULL,
`age_3_4_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_3_4_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_3_4_min_6` enum('0','1','2','3') default NULL,
`age_3_4_location_6` varchar(100) default NULL,
`age_3_4_description_6` varchar(100) default NULL,
`age_2_3_type_of_intervention_1` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_2_3_hours_1` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_2_3_min_1` enum('0','1','2','3') default NULL,
`age_2_3_location_1` varchar(100) default NULL,
`age_2_3_description_1` varchar(100) default NULL,
`age_2_3_type_of_intervention_2` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_2_3_hours_2` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_2_3_min_2` enum('0','1','2','3') default NULL,
`age_2_3_location_2` varchar(100) default NULL,
`age_2_3_description_2` varchar(100) default NULL,
`age_2_3_type_of_intervention_3` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_2_3_hours_3` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_2_3_min_3` enum('0','1','2','3') default NULL,
`age_2_3_location_3` varchar(100) default NULL,
`age_2_3_description_3` varchar(100) default NULL,
`age_2_3_type_of_intervention_4` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_2_3_hours_4` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_2_3_min_4` enum('0','1','2','3') default NULL,
`age_2_3_location_4` varchar(100) default NULL,
`age_2_3_description_4` varchar(100) default NULL,
`age_2_3_type_of_intervention_5` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_2_3_hours_5` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_2_3_min_5` enum('0','1','2','3') default NULL,
`age_2_3_location_5` varchar(100) default NULL,
`age_2_3_description_5` varchar(100) default NULL,
`age_2_3_type_of_intervention_6` enum('1','2','3','4','5','6','7','8','9','10','11','12', '13') default NULL,
`age_2_3_hours_6` enum('0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31','32','33','34','35','36','37','38','39','40','41','42','43','44','45','46','47','48','49','50') default NULL,
`age_2_3_min_6` enum('0','1','2','3') default NULL,
`age_2_3_location_6` varchar(100) default NULL,
`age_2_3_description_6` varchar(100) default NULL,
`q15_additional_info` text default NULL,
`q15_additional_info_status` enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)

) ENGINE=InnoDB DEFAULT CHARSET=utf8;

