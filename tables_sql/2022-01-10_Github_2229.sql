-- Github 2229
-- Remove IBISSA and TEST IBISSA Projects

-- Deletes session where ProjectID = 7 (TEST IBISSA)
DELETE FROM session WHERE SessionID = 5788;

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