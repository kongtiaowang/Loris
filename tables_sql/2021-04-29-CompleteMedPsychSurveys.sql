-- ----------------------------------------------------------------------------------------
--
-- Fixes the Med_Psych_History_Abbreviated_surveys for which the
-- Data_entry_completion_status is incorrectly set to 'Incomplete'.
--
-- This patch will set the Data_entry_completion_status to 'Complete'
-- for the questionnaires with non NULL fields q1_a_what_was_the_outcome_of_pregnancy_1
-- and q3_disorder_a_presence
-- 
-- ----------------------------------------------------------------------------------------

UPDATE Med_Psych_History_Abbreviated_survey
SET Data_entry_completion_status='Complete'
WHERE q1_a_what_was_the_outcome_of_pregnancy_1 IS NOT NULL
AND   q3_disorder_a_presence                   IS NOT NULL;
