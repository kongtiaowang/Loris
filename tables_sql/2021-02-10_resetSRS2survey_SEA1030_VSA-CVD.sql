-- -----------------------------------------------------------------------------
--
-- Resets the SRS2_SchoolAge_Parent_proband survey for SEA0130 (560969)
-- at VSA-CVDto allow the parent to fill it again (it is currently incorrectly
-- filled with information on the wrong child and marked as 'Complete'.
-- 
-- -----------------------------------------------------------------------------

UPDATE participant_accounts
SET status = 'Sent'
WHERE sessionid = (
    SELECT id
    FROM session
    WHERE candid=560969
    AND visit_label='VSA-CVD'
)
AND test_name = 'SRS2_SchoolAge_Parent_proband';
