/* adi_r_subject */
ALTER TABLE adi_r_subject add q_20_loss_of_skills_sametime enum('0','1') AFTER q_20_loss_of_skills_code;
ALTER TABLE adi_r_subject add q_21_puposive_hand_movements_sametime enum('0','1') AFTER q_21_puposive_hand_movements_code;
ALTER TABLE adi_r_subject add q_22_motor_skills_sametime enum('0','1') AFTER q_22_motor_skills_code;
ALTER TABLE adi_r_subject add q_23_self_help_skills_sametime enum('0','1') AFTER q_23_self_help_skills_code;
ALTER TABLE adi_r_subject add q_24_constructive_play_sametime enum('0','1') AFTER q_24_constructive_play_code;
ALTER TABLE adi_r_subject add q_25_social_engagement_sametime enum('0','1') AFTER q_25_social_engagement_code;

ALTER TABLE adi_r_subject add `q_27_physical_illness_text` varchar(255)  AFTER q_27_physical_illness_code;
ALTER TABLE adi_r_subject add `q_27_physical_illness_text_status` enum('not_answered') AFTER q_27_physical_illness_text;

ALTER TABLE adi_r_subject add `favorite_activities` text AFTER q_59_appropriat_resp_most_abnormal_code;
ALTER TABLE adi_r_subject add `favorite_activities_status` enum('not_answered') AFTER favorite_activities;
ALTER TABLE adi_r_subject add `favorite_toys_objects` text AFTER favorite_activities_status;
ALTER TABLE adi_r_subject add `favorite_toys_objects_status` enum('not_answered') AFTER favorite_toys_objects;

/* adi_r_proband */
ALTER TABLE adi_r_proband add q_20_loss_of_skills_sametime enum('0','1') AFTER q_20_loss_of_skills_code;
ALTER TABLE adi_r_proband add q_21_puposive_hand_movements_sametime enum('0','1') AFTER q_21_puposive_hand_movements_code;
ALTER TABLE adi_r_proband add q_22_motor_skills_sametime enum('0','1') AFTER q_22_motor_skills_code;
ALTER TABLE adi_r_proband add q_23_self_help_skills_sametime enum('0','1') AFTER q_23_self_help_skills_code;
ALTER TABLE adi_r_proband add q_24_constructive_play_sametime enum('0','1') AFTER q_24_constructive_play_code;
ALTER TABLE adi_r_proband add q_25_social_engagement_sametime enum('0','1') AFTER q_25_social_engagement_code;

ALTER TABLE adi_r_proband add `q_27_physical_illness_text` varchar(255)  AFTER q_27_physical_illness_code;
ALTER TABLE adi_r_proband add `q_27_physical_illness_text_status` enum('not_answered') AFTER q_27_physical_illness_text;

ALTER TABLE adi_r_proband add `favorite_activities` text AFTER q_59_appropriat_resp_most_abnormal_code;
ALTER TABLE adi_r_proband add `favorite_activities_status` enum('not_answered') AFTER favorite_activities;
ALTER TABLE adi_r_proband add `favorite_toys_objects` text AFTER favorite_activities_status;
ALTER TABLE adi_r_proband add `favorite_toys_objects_status` enum('not_answered') AFTER favorite_toys_objects;
