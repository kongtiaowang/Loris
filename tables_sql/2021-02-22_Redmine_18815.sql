-- Delete APSI Survey for STL6002 (328191) V12
DELETE FROM
    apsi_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='apsi_survey' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                    CandID=328191
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
            Test_name='apsi_survey' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                    CandID=328191
            )
    );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('apsi_survey') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=328191
    );