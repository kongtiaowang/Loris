-- Fix existing bad data related with consents as part of consent normalization
-- Blanks are replaced with expected NULL here on confirming the dates are also NULL
UPDATE participant_status SET study_consent=NULL where study_consent IN ('','not_answered') and study_consent_date IS NULL and study_withdrawal_date IS NULL;
UPDATE participant_status SET ndar_consent=NULL where ndar_consent IN ('','not_answered') and ndar_consent_date IS NULL and ndar_consent_withdrawal IS NULL;
UPDATE participant_status SET air_consent=NULL where air_consent IN ('','not_answered') and air_consent_date IS NULL and air_consent_withdrawal IS NULL;
UPDATE participant_status SET mail_toothkit_consent=NULL where mail_toothkit_consent IN ('','not_answered') and mail_toothkit_consent IS NULL and mail_toothkit_consent_withdrawal IS NULL;

