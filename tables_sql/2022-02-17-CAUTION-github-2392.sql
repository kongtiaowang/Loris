-- We cant store any candidate that hasn't consented to the study
-- according to IRB guidelines. This patch will set DoB and EDC
-- field to NULL for all candidates with study consent set to no
UPDATE candidate
SET DoB = NULL,
    EDC = NULL
WHERE CandID IN (
    SELECT CandidateID
    FROM candidate_consent_rel CandidateID
    WHERE ConsentID = (SELECT ConsentID FROM consent WHERE Name = 'study_consent')
      AND Status='no'
);
