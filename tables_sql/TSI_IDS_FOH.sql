CREATE TABLE `TSI_IDS_FOH` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`not_finish0` varchar(255) default NULL,
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`date_of_most_recent_visit` date default NULL,
`not_finish1` varchar(10) default NULL,
`subject_dob` date default NULL,
`subject_expected_due_date` date default NULL,
`subject_premature` enum('yes','no') default NULL,
`subject_how_many_weeks_gestation` varchar(255) default NULL,
`city_of_birth` varchar(128) default NULL,
`subject_gender` enum('male','female') default NULL,
`subject_adopted` enum('yes','no') default NULL,
`subject_multiple` enum('yes','no') default NULL,
`subject_birth_weight_lbs` varchar(128) default NULL,
`subject_birth_weight_oz` varchar(128) default NULL,
`current_weight_lbs` varchar(128) default NULL,
`current_height_ft` varchar(128) default NULL,
`current_height_in` varchar(128) default NULL,
`current_age_mon` varchar(128) default NULL,
`current_age_year` varchar(128) default NULL,
`v06_optimal_window_lower` date default NULL,
`v06_optimal_window_upper` date default NULL,
`v06_permitted_window_lower` date default NULL,
`v06_permitted_window_upper` date default NULL,
`v12_optimal_window_lower` date default NULL,
`v12_optimal_window_upper` date default NULL,
`v12_permitted_window_lower` date default NULL,
`v12_permitted_window_upper` date default NULL,
`v24_optimal_window_lower` date default NULL,
`v24_optimal_window_upper` date default NULL,
`v24_permitted_window_lower` date default NULL,
`v24_permitted_window_upper` date default NULL,
`mother_dob_date` date default NULL,
`mother_dob_date_status` enum('not_answered') default NULL,
`mother_occupation` varchar(128) default NULL,
`mother_occupation_status` enum('not_answered') default NULL,
`mother_education` enum('some_high_school','high_school','some_college_2yr_degree','college_degree','some_grad_school','grad_degree','not_answered') default NULL,
`preferred_method_contact_mother` enum('0','1') default NULL,
`best_call_number_mother` varchar(128) default NULL,
`best_call_number_mother_status` enum('not_answered') default NULL,
`best_time_call_mother` varchar(128) default NULL,
`best_time_call_mother_status` enum('not_answered') default NULL,
`okay_leave_message_mother` enum('yes','no') default NULL,
`father_dob_date` date default NULL,
`father_dob_date_status` enum('not_answered') default NULL,
`father_occupation` varchar(128) default NULL,
`father_occupation_status` enum('not_answered') default NULL,
`father_education` enum('some_high_school','high_school','some_college_2yr_degree','college_degree','some_grad_school','grad_degree','not_answered') default NULL,
`preferred_method_contact_father` enum('1','2') default NULL,
`best_call_number_father` varchar(128) default NULL,
`best_call_number_father_status` enum('not_answered') default NULL,
`best_time_call_father` varchar(128) default NULL,
`best_time_call_father_status` enum('not_answered') default NULL,
`okay_leave_message_father` enum('yes','no') default NULL,
`are_parents_divorced_or_separated` enum('yes','no') default NULL,
`are_bio_parents_living_in_same_home` enum('yes','no') default NULL,
`if_not_in_same_home_childs_primary_address_with` enum('mother','father') default NULL,
`child_primary_address` enum('both_parents','mother','father','other') default NULL,
`address_specify` varchar(128) default NULL,
`child_primary_address2` enum('mother','father','other') default NULL,
`address_specify2` varchar(128) default NULL,
`relationship_to_family` varchar(128) default NULL,
`additional_info_about_childs_home` text default NULL,
`additional_info_about_childs_home_status` enum('not_answered') default NULL,
`household_ses_mother_or_combined` enum('less_than_25K','25K-35K','35K-50K','50K-75K','75K-100K','100K-150K','150K-200K','over_200K','not_answered') default NULL,
`household_ses_father_if_2_households` enum('less_than_25K','25K-35K','35K-50K','50K-75K','75K-100K','100K-150K','150K-200K','over_200K','not_answered') default NULL,
`subject_race` varchar(128) default NULL,
`sibling_race` varchar(128) default NULL,
`bio_mother_race` varchar(128) default NULL,
`bio_father_race` varchar(128) default NULL,
`subject_ethnicity` enum('hispanic','non_hispanic','not_answered') default NULL,
`sibling_ethnicity` enum('hispanic','non_hispanic','not_answered') default NULL,
`bio_mother_ethnicity` enum('hispanic','non_hispanic','not_answered') default NULL,
`bio_father_ethnicity` enum('hispanic','non_hispanic','not_answered') default NULL,
`is_english_primary_language_spoken_in_home` enum('yes','no') default NULL,
`not_finish2` varchar(10) default NULL,
`diagnose_1` varchar(129) default NULL,
`who_1` varchar(128) default NULL,
`date_1` date default NULL,
`diagnose_2` varchar(128) default NULL,
`who_2` varchar(128) default NULL,
`date_2` date default NULL,
`diagnose_3` varchar(128) default NULL,
`who_3` varchar(128) default NULL,
`date_3` date default NULL,
`diagnose_4` varchar(128) default NULL,
`who_4` varchar(128) default NULL,
`date_4` date default NULL,
`sibling_1_dob` date default NULL,
`sibling_1_gender` enum('male','female') default NULL,
`sibling_1_diagnoses` varchar(128) default NULL,
`sibling_1_type` enum('half','full','step','adopted') default NULL,
`sibling_1_live_in_home` enum('yes','no') default NULL,
`sibling_2_dob` date default NULL,
`sibling_2_gender` enum('male','female') default NULL,
`sibling_2_diagnoses` varchar(128) default NULL,
`sibling_2_type` enum('half','full','step','adopted') default NULL,
`sibling_2_live_in_home` enum('yes','no') default NULL,
`sibling_3_dob` date default NULL,
`sibling_3_gender` enum('male','female') default NULL,
`sibling_3_diagnoses` varchar(128) default NULL,
`sibling_3_type` enum('half','full','step','adopted') default NULL,
`sibling_3_live_in_home` enum('yes','no') default NULL,
`sibling_4_dob` date default NULL,
`sibling_4_gender` enum('male','female') default NULL,
`sibling_4_diagnoses` varchar(128) default NULL,
`sibling_4_type` enum('half','full','step','adopted') default NULL,
`sibling_4_live_in_home` enum('yes','no') default NULL,
`sibling_5_dob` date default NULL,
`sibling_5_gender` enum('male','female') default NULL,
`sibling_5_diagnoses` varchar(128) default NULL,
`sibling_5_type` enum('half','full','step','adopted') default NULL,
`sibling_5_live_in_home` enum('yes','no') default NULL,
`sibling_6_dob` date default NULL,
`sibling_6_gender` enum('male','female') default NULL,
`sibling_6_diagnoses` varchar(128) default NULL,
`sibling_6_type` enum('half','full','step','adopted') default NULL,
`sibling_6_live_in_home` enum('yes','no') default NULL,
`sibling_7_dob` date default NULL,
`sibling_7_gender` enum('male','female') default NULL,
`sibling_7_diagnoses` varchar(128) default NULL,
`sibling_7_type` enum('half','full','step','adopted') default NULL,
`sibling_7_live_in_home` enum('yes','no') default NULL,
`sibling_8_dob` date default NULL,
`sibling_8_gender` enum('male','female') default NULL,
`sibling_8_diagnoses` varchar(128) default NULL,
`sibling_8_type` enum('half','full','step','adopted') default NULL,
`sibling_8_live_in_home` enum('yes','no') default NULL,
`enrolled_in_other_studies_or_registries` enum('yes','no') default NULL,
`enrolled_in_other_studies_or_registries_list` varchar(128) default NULL,
`not_finish3` varchar(10) default NULL,
`q1_has_subject_had_any_genetic_testing_done` enum('yes','no') default NULL,
`q1a_subject_had_testing_done_when_where` varchar(128) default NULL,
`q2_diagnosed_suspected_genetic_conditions` enum('yes','no') default NULL,
`q2a_diagnosed_suspected_genetic_conditions_list` varchar(128) default NULL,
`q3_seizures_or_other_neurological_disorder` enum('yes','no') default NULL,
`q3a_seizures_or_other_neurological_disorder_how_often` varchar(128) default NULL,
`q3b_are_the_seizures_under_control` varchar(128) default NULL,
`q3c_medication_for_seizures` varchar(128) default NULL,
`q3d_last_time_medication_dosage_was_changed` varchar(128) default NULL,
`q4_history_of_head_injury_in_subject` varchar(128) default NULL,
`q4a_if_yes_explain` varchar(128) default NULL,
`q5_significant_hearing_vision_problems_in_subject` enum('yes','no') default NULL,
`q5a_significant_hearing_vision_problems_in_subject_lists` varchar(255) default NULL,
`q6_does_subject_currently_take_any_medications` enum('yes','no') default NULL,
`q6a_does_subject_currently_take_any_medications_list` varchar(255) default NULL,
`q7_has_your_child_ever_had_an_iq_test` enum('yes','no') default NULL,
`q7a_has_your_child_ever_had_an_iq_test_when_where` varchar(128) default NULL,
`q7b_results_and_test_if_known` varchar(128) default NULL,
`q7c_test` varchar(128) default NULL,
`q8_any_specific_neurological_problems_in_subject` enum('yes','no') default NULL,
`q8a_if_yes_list` varchar(128) default NULL,
`q9_congenital_heart_problems_or_abnormalities_in_subject` enum('yes','no') default NULL,
`q9a_exclusionary_conditions` varchar(128) default NULL,
`q9b_other` varchar(128) default NULL,
`q10_any_problems_with_sleep_apnea_or_breathing` enum('yes','no') default NULL,
`q10a_list` varchar(128) default NULL,
`q11_any_gastrointestinal_condition_in_subject` enum('yes','no') default NULL,
`q11a_list` varchar(128) default NULL,
`q12_did_mother_have_gestational_diabetes_while_pregnant` enum('yes','no','not_answered') default NULL,
`q12a_did_gestational_diabetes_require_insulin` enum('yes','no') default NULL,
`q12b_have_diabetes` enum('yes','no') default NULL,
`q13_are_you_breastfeeding_child` enum('weaned','current','never') default NULL,
`q13a_how_long_did_you_breastfeed_for` varchar(128) default NULL,
`q14_exposure_to_medication_alcohol_drugs` enum('yes','no') default NULL,
`q14a_sub_devfactors_1` varchar(128) default NULL,
`q14a_sub_devfactors_q14_1_1st_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_1_2nd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_1_3rd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_1_breastfeeding` enum('yes','no') default NULL,
`q14a_sub_devfactors_2` varchar(128) default NULL,
`q14a_sub_devfactors_q14_2_1st_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_2_2nd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_2_3rd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_2_breastfeeding` enum('yes','no') default NULL,
`q14a_sub_devfactors_3` varchar(128) default NULL,
`q14a_sub_devfactors_q14_3_1st_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_3_2nd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_3_3rd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_3_breastfeeding` enum('yes','no') default NULL,
`q14a_sub_devfactors_4` varchar(128) default NULL,
`q14a_sub_devfactors_q14_4_1st_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_4_2nd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_4_3rd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_4_breastfeeding` enum('yes','no') default NULL,
`q14a_sub_devfactors_5` varchar(128) default NULL,
`q14a_sub_devfactors_q14_5_1st_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_5_2nd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_5_3rd_trimester` enum('yes','no') default NULL,
`q14a_sub_devfactors_q14_5_breastfeeding` enum('yes','no') default NULL,
`q15_complications_during_pregnancy_delivery` enum('yes','no') default NULL,
`q15a_exclusionary_conditions` varchar(128) default NULL,
`q15b_other` varchar(128) default NULL,
`q16_method_of_delivery` varchar(128) default NULL,
`q16a_other` varchar(128) default NULL,
`q17_has_subject_taken_medications_since_birth` enum('yes','no') default NULL,
`q17a_list` varchar(128) default NULL,
`q18_has_subject_ever_had_any_serious_medical` enum('yes','no') default NULL,
`q18a_list` varchar(128) default NULL,
`q19_has_subject_ever_been_hospitalized` enum('yes','no') default NULL,
`q19a_list` varchar(128) default NULL,
`q20_has_subject_had_any_surgery` enum('yes','no') default NULL,
`q20a_list` varchar(128) default NULL,
`q21_has_subject_seen_doctor_for_something` enum('yes','no') default NULL,
`q21a_list` varchar(128) default NULL,
`q22_has_subject_ever_had_anesthesia` enum('yes','no') default NULL,
`not_finish4` varchar(128) default NULL,
`re_confirm_sibling_subject_dob` varchar(128) default NULL,
`q1_has_sibling_had_any_genetic_testing_done` enum('yes','no') default NULL,
`q1a_has_sibling_had_any_genetic_when_where` varchar(128) default NULL,
`q2_diagnosed_suspected_genetic_conditions_syndromes` enum('yes','no') default NULL,
`q2a_diagnosed_suspected_genetic_list` varchar(128) default NULL,
`q3a_how_often` varchar(128) default NULL,
`q4_significant_vision_problems_in_sibling` enum('yes','no') default NULL,
`q4a_significant_vision_problems_in_sibling_list` varchar(128) default NULL,
`q5_does_sibling_currently_take_any_medications` enum('yes','no') default NULL,
`q5a_does_sibling_currently_take_any_medications_list` varchar(128) default NULL,
`q6_has_siblin_ever_had_an_iq_test` enum('yes','no') default NULL,
`q6a_has_siblin_ever_had_an_iq_test_when_where` varchar(128) default NULL,
`q6b_results_and_test_if_known` varchar(128) default NULL,
`q6c_test` varchar(128) default NULL,
`household_ses_mother` enum("combined","mother") default NULL,
`household_ses_father` enum("na","father") default NULL,
`sibling_1_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_2_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_3_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_4_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_5_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_6_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_7_foh_sibling_subject` enum("yes","no") default NULL,
`sibling_8_foh_sibling_subject` enum("yes","no") default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;