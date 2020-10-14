-- Redmine 18175

ALTER TABLE `IPSC_tracking_form` MODIFY COLUMN `recruiter_asked_blood_draw` enum('not_yet_called','yes','no','not_yet_asked') default NULL;

UPDATE `IPSC_tracking_form` SET `recruiter_asked_blood_draw` = CASE
    WHEN `recruiter_asked_blood_draw` = 'not_yet_called' THEN 'not_yet_asked'
    WHEN `recruiter_asked_blood_draw` = 'no' THEN 'not_yet_asked'
    WHEN `recruiter_asked_blood_draw` = 'yes' THEN 'yes'
    END
WHERE `recruiter_asked_blood_draw` in ('not_yet_called','yes','no', 'not_yet_asked');

ALTER TABLE `IPSC_tracking_form` MODIFY COLUMN `recruiter_asked_blood_draw` enum('yes','not_yet_asked') default NULL;

ALTER TABLE `IPSC_tracking_form` ADD `did_family_agree_to_project` enum('yes','no') default NULL AFTER `recruiter_asked_blood_draw`;
ALTER TABLE `IPSC_tracking_form` ADD `was_the_blood_draw_successful` enum('yes','no') default NULL AFTER `fedex_tracking_number`;