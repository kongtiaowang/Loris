-- Delete SCQ-Proband Survey for SEA0067 (703739) VSA-CVD
DELETE FROM
    scq_proband_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='scq_proband_survey' AND
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
IN
    ('scq_proband_survey') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='VSA-CVD' AND
            CandID=703739
    );