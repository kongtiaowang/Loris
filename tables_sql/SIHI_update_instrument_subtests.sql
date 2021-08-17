-- Update instrument_subtests
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SIHI','SIHI_page6', "Page 6", 6);

-- Update SIHI table
ALTER TABLE SIHI ADD COLUMN `vi_q1_any_concerns_about_childs_nighttime_sleep` enum('yes','no') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q1_if_yes_rate_concern` enum('1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q2_any_concerns_about_childs_daytime_sleep` enum('yes','no') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q2_if_yes_rate_concern` enum('1','2','3','4','5','6','7','8','9','10') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q3_any_external_influences_affected_sleep` text default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q3_any_external_influences_affected_sleep_status` enum('not_answered') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q4_seek_information_to_help_child_sleep_better` enum('yes','no') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q4_if_yes_select_source` varchar(255) default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q4_if_sleep_specialist` enum('short_term','long_term') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q5_did_child_receive_intervention` enum('yes','no') default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q5_if_yes_select` varchar(255) default NULL;
ALTER TABLE SIHI ADD COLUMN `vi_q5_if_medication_select_which_medicine_your_child_used` varchar(255) default NULL;

