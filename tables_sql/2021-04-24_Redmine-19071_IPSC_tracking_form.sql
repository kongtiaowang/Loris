ALTER TABLE `IPSC_tracking_form`
    CHANGE `was_the_blood_draw_successful` `was_the_blood_draw_successful` enum('yes','no','no_blood_draw_scheduled','blood_draw_not_occurred') DEFAULT NULL,
    ADD COLUMN `ask_about_interview` enum('not_yet','yes') default NULL AFTER `blood_draw_date`,
    ADD COLUMN `family_participate` enum('yes','no','na') default NULL AFTER `ask_about_interview`;