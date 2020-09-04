-- Redmine 18178
Alter table scq_subject_survey
add column `relationship_to_child` enum('mother','father','step_mother','step_father','other') DEFAULT NULL,
add column `other_relationship_to_child` varchar(255) DEFAULT NULL;

-- Redmine 18202

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_checklist', '0', '0', 'Y', 'Visit', 1, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_checklist', '0', '0', 'Y', 'Visit', 2, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_checklist', '0', '0', 'Y', 'Visit', 3, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_checklist', '0', '0', 'Y', 'Visit', 9, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMIV_checklist', '0', '0', 'Y', 'Visit', 10, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist', '0', '0', 'Y', 'Visit', 1, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist', '0', '0', 'Y', 'Visit', 2, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist', '0', '0', 'Y', 'Visit', 3, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist', '0', '0', 'Y', 'Visit', 9, 'VSA-CVD', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
VALUES ('DSMV_checklist', '0', '0', 'Y', 'Visit', 10, 'VSA-CVD', NULL);


-- Redmine 18216
-- Brief2
DELETE FROM
    BRIEF2_Parent
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='BRIEF2_Parent' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- CBCL
DELETE FROM
    CBCL_6_To_18
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='CBCL_6_To_18' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );

-- ccc2
DELETE FROM
   CCC2
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='CCC2' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );

-- ucd
DELETE FROM
  UCD_Charge_GI_History
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='UCD_Charge_GI_History' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- conners
DELETE FROM conners_parent
WHERE
    CommentID IN (
         SELECT CommentID
        FROM
            flag
        WHERE
            Test_name='conners_parent' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- cshq
DELETE FROM
  CSHQ
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='CSHQ' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- masc2
DELETE FROM
  MASC2_Parent
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='MASC2_Parent' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- srs2
DELETE FROM
 SRS2_SchoolAge_Parent
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SRS2_SchoolAge_Parent' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- seizure
DELETE FROM
 Seizure_Questionnaire
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='Seizure_Questionnaire' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );
-- ssis
DELETE FROM
 SSIS_Parent
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SSIS_Parent' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );


DELETE FROM
    participant_accounts
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name IN ('BRIEF2_Parent',
'CBCL_6_To_18',
'CCC2',
'UCD_Charge_GI_History',
'conners_parent',
'CSHQ',
'MASC2_Parent',
'SRS2_SchoolAge_Parent',
'Seizure_Questionnaire',
'SSIS_Parent') AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=703739
            )
    );

DELETE FROM
    flag
WHERE
    Test_name
     IN ('BRIEF2_Parent',
'CBCL_6_To_18',
'CCC2',
'UCD_Charge_GI_History',
'conners_parent',
'CSHQ',
'MASC2_Parent',
'SRS2_SchoolAge_Parent',
'Seizure_Questionnaire',
'SSIS_Parent') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='VSA-CVD' AND
            CandID=703739
    );