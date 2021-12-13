-- Github #2229

-- Update sessions where session.ProjectID == 6 (IBISSA) and candidate.RegistrationProjectID != 6 (IBISSA)
UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='572121')
WHERE
    CandID='572121' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='391404')
WHERE
    CandID='391404' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='828935')
WHERE
    CandID='828935' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='465514')
WHERE
    CandID='465514' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='699209')
WHERE
    CandID='699209' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='170538')
WHERE
    CandID='170538' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='921629')
WHERE
    CandID='921629' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='185584')
WHERE
    CandID='185584' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='680028')
WHERE
    CandID='680028' AND
    ProjectID = 6;

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
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='191896')
WHERE
    CandID='191896' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='247315')
WHERE
    CandID='247315' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='800599')
WHERE
    CandID='800599' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='525057')
WHERE
    CandID='525057' AND
    ProjectID = 6;

UPDATE
    session
SET
    ProjectID = (SELECT RegistrationProjectID FROM candidate where CandID='122785')
WHERE
    CandID='122785' AND
    ProjectID = 6;

-- Delete DCC sessions with session.ProjectID = 6 (IBISSA) AND candidate.RegistrationProjectID = 6 (IBISSA)
DELETE FROM
	session
WHERE CandID in (
    SELECT cid FROM (
        SELECT
            session.CandID as cid
        FROM
            candidate
        INNER JOIN
            session
        ON
            candidate.CandID = session.CandID
        WHERE
            session.ProjectID = 6 AND
            candidate.PSCID LIKE 'dcc%'

    ) AS c
);

-- Archive candidates the following candidates:
-- STL3000
-- UNC3000
-- UNC3001
-- UNC3002
UPDATE candidate SET Active='N' WHERE PSCID='STL3000';
UPDATE candidate SET Active='N' WHERE PSCID='UNC3000';
UPDATE candidate SET Active='N' WHERE PSCID='UNC3001';
UPDATE candidate SET Active='N' WHERE PSCID='UNC3002';

-- Archive all DCC candidates where RegistrationProjectID = 6 (IBISSA)
UPDATE candidate SET Active='N' WHERE PSCID LIKE 'dcc%' AND RegistrationProjectID = 6;

-- Updates all candidates with RegistrationProjectID = 6 (IBISSA) to RegistrationProjectID = 1 (IBIS1)
UPDATE
    candidate
SET
    RegistrationProjectID = 1
WHERE
    RegistrationProjectID = 6;

-- Update ProjectID for remaining sessions (these sessions belong to archived candidates)
UPDATE session SET ProjectID = 1 WHERE ProjectID = 6;