-- Github 2229
-- Remove IBISSA and TEST IBISSA Projects

START TRANSACTION;

DELETE FROM candidate_consent_rel WHERE CandidateID IN (603080, 897213, 143683, 852976);

DELETE FROM candidate WHERE CandID IN (
    603080,
    897213,
    143683,
    852976
);

DELETE FROM project_subproject_rel WHERE ProjectSubprojectRelID = 14;
DELETE FROM project_subproject_rel WHERE ProjectSubprojectRelID = 15;

DELETE FROM Project WHERE ProjectID = 6;
DELETE FROM Project WHERE ProjectID = 7;

COMMIT;