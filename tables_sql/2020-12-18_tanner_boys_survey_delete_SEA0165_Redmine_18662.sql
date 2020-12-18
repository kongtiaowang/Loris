DELETE FROM
    tanner_boys_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tanner_boys_survey' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=237123
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
            Test_name='tanner_boys_survey' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='VSA-CVD' AND
                    CandID=237123
            )
    );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tanner_boys_survey') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='VSA-CVD' AND
            CandID=237123
    ); 