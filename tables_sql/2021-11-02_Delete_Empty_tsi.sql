-- Delete empty/outdated tsi:
-- 877248,V12
-- 713528,V12
-- 624363,V12
-- 873390,V12
-- 477893,V06
-- 477893,V12
-- 946008,V12
-- 799324,V12
-- 718588,V12
-- 545706,V06
-- 545706,V12
-- 210772,V06
-- 381658,V06
-- 917944,V06
-- 136177,V06
-- 134585,V06
-- 872785,V06
-- 872785,V12

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=877248
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=877248
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=713528
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=713528
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=624363
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=624363
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=873390
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=873390
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=477893
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=477893
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=477893
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=477893
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=946008
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=946008
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=799324
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=799324
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=718588
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=718588
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=545706
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=545706
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=545706
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=545706
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=210772
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=210772
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=381658
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=381658
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=917944
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=917944
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=136177
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=136177
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=134585
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=134585
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06' AND
                            CandID=872785
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06' AND
            CandID=872785
    );

DELETE FROM
    tsi
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='tsi' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=872785
                    )
            );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('tsi') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=872785
    );
