-- Delete BISQ Survey for UNC7005 (625518) V6-CVD
DELETE FROM
    BISQ_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='BISQ_survey' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V6-CVD' AND
                    CandID=625518
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
            Test_name='BISQ_survey' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V6-CVD' AND
                    CandID=625518
            )
    );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('BISQ_survey') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V6-CVD' AND
            CandID=625518
    );