UPDATE participant_status as ps SET ps.study_consent_withdrawal = NULL WHERE ps.study_consent_withdrawal = '0000-00-00';
UPDATE participant_status as ps SET ps.ndar_consent_withdrawal = NULL WHERE ps.ndar_consent_withdrawal = '0000-00-00';
UPDATE consent_info_history SET study_consent_withdrawal = NULL WHERE study_consent_withdrawal = '0000-00-00';
UPDATE consent_info_history SET ndar_consent_withdrawal = NULL WHERE ndar_consent_withdrawal = '0000-00-00';

