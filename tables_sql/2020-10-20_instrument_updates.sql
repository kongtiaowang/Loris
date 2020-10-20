-- Redmine 18399
-- SRS2_InformantReport_Mom_On_Dad
DELETE FROM
    SRS2_InformantReport_Mom_On_Dad
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SRS2_InformantReport_Mom_On_Dad' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                    CandID=967417
            )
    );
-- pspq_InformantReport_mom_on_dad
DELETE FROM
    pspq_InformantReport_mom_on_dad
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='pspq_InformantReport_mom_on_dad' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                    CandID=967417
            )
    );

-- SRS2_InformantReport_Dad_On_Mom
DELETE FROM
   SRS2_InformantReport_Dad_On_Mom
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SRS2_InformantReport_Dad_On_Mom' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                    CandID=967417
            )
    );

-- pspq_InformantReport_dad_on_mom
DELETE FROM
  pspq_InformantReport_dad_on_mom
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='pspq_InformantReport_dad_on_mom' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                    CandID=967417
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
            Test_name IN ('pspq_InformantReport_dad_on_mom',
'pspq_InformantReport_mom_on_dad',
'SRS2_InformantReport_Mom_On_Dad',
'SRS2_InformantReport_Dad_On_Mom') AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                    CandID=967417
            )
    );

DELETE FROM
    flag
WHERE
    Test_name
     IN ('pspq_InformantReport_dad_on_mom',
'pspq_InformantReport_mom_on_dad',
'SRS2_InformantReport_Mom_On_Dad',
'SRS2_InformantReport_Dad_On_Mom')  AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=967417
    );