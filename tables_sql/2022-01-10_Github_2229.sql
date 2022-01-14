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

-- Deletes candidates with RegistrationProjectID = 7 (TEST IBISSA)
DELETE FROM candidate WHERE ID IN (
    1742,
    1736,
    2251,
    1741
);

-- Deletes rel between IBISSA Project and IBISSA HR and IBISSA LR subprojects
DELETE FROM project_subproject_rel WHERE ID = 14;
DELETE FROM project_subproject_rel WHERE ID = 15;

-- Deletes IBISSA and TEST IBISSA Projects
DELETE FROM Project WHERE ID = 6;
DELETE FROM Project WHERE ID = 7;