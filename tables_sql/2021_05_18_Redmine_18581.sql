-- Add dropdown options for
--     Withdrawn - can use data
--     Withdrawn - can not use data
-- in participant status form.
INSERT INTO `participant_status_options` (`ID`, `Description`, `Required`) VALUES
        ('14', 'Withdrawn - can use data', '0'),
        ('15', 'Withdrawn - can not use data', '0');

-- Update all candidates' participant status to withdrawn - can not use data where their study consent is no.
UPDATE candidate_consent_rel c
    JOIN participant_status p ON (c.CandidateID=p.CandID)
    SET p.participant_status=15
    WHERE c.ConsentID=1 AND c.Status='no';
