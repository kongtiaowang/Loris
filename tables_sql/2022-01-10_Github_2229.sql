-- Github 2229
-- Remove IBISSA and TEST IBISSA Projects

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='856269')
WHERE
    CandID='856269' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='247315')
WHERE
    CandID='247315' AND
    ProjectID = 6;

-- Deletes session where ProjectID = 7 (TEST IBISSA)
DELETE FROM session WHERE ProjectID = 7;

