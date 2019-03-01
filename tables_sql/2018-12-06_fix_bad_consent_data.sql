-- Fix existing bad data related with consents as part of consent normalization
-- Fix Issue happened during running the 20.0 Consent Normalization Script
-- Blanks are replaced with expected NULLs' for mail tooth kit consent here on confirming the associated dates are also NULL
UPDATE participant_status SET mail_toothkit_consent=NULL where mail_toothkit_consent='' and mail_toothkit_consent_date IS NULL and mail_toothkit_consent_withdrawal IS NULL;
-- Update all study consent date to current date if it has an 'yes' consent
UPDATE participant_status SET study_consent_date=DATE(NOW()) where study_consent='yes' and study_consent_date IS NULL;
-- Update all ndar consent with an yes status for those have a consent date
UPDATE participant_status SET ndar_consent='yes' where ndar_consent IS NULL AND ndar_consent_date IS NOT NULL;


