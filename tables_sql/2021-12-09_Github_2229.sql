-- Github #2229

-- Update sessions where session.Project = IBISSA and candidate.RegistrationProjectID != IBISSA
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

-- Archive candidates the following candidates:
-- STL3000
-- UNC3000
-- UNC3001
-- UNC3002
UPDATE candidate SET Active='N' WHERE PSCID='STL3000';
UPDATE candidate SET Active='N' WHERE PSCID='UNC3000';
UPDATE candidate SET Active='N' WHERE PSCID='UNC3001';
UPDATE candidate SET Active='N' WHERE PSCID='UNC3002';