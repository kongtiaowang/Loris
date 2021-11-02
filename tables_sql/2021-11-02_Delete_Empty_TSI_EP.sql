-- Delete empty/outdated TSI_EP:
-- 948165, V12-CVD
-- 363358, V12-CVD
-- 334015, V12
-- 569867, V12
-- 576743, V12
-- 750651, V12
-- 929406, V12 
-- 574980, V12
-- 967417, V12-CVD
-- 621139, V06-CVD
-- 432844, V12
-- 750713, V12
-- 328191, V12
-- 514844, V12
-- 982712, V12
-- 605027, V12
-- 336515, V12
-- 174254, V12
-- 434782, V12
-- 392381, V06-CVD
-- 280547, V12
-- 911161, V12
-- 449868, V12-CVD
-- 957759, V12-CVD
-- 577380, V12-CVD
-- 569369, V06-CVD
-- 311724, V06-CVD
-- 311724, V12-CVD
-- 535264, V06-CVD

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                            CandID=948165
                )
        );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=948165
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                            CandID=363358
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=363358
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=334015
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=334015
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=569867
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=569867
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=576743
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=576743
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=750651
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=750651
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12 ' AND
                            CandID=929406
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12 ' AND
            CandID=929406
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=574980
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=574980
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
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
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=967417
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06-CVD' AND
                            CandID=621139
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06-CVD' AND
            CandID=621139
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=432844
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=432844
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=750713
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=750713
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
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
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=328191
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=514844
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=514844
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=982712
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=982712
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=605027
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=605027
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=336515
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=336515
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=174254
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=174254
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=434782
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=434782
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06-CVD' AND
                            CandID=392381
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06-CVD' AND
            CandID=392381
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=280547
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=280547
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12' AND
                            CandID=911161
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12' AND
            CandID=911161
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                            CandID=449868
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=449868
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                            CandID=957759
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=957759
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                            CandID=577380
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=577380
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06-CVD' AND
                            CandID=569369
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06-CVD' AND
            CandID=569369
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06-CVD' AND
                            CandID=311724
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06-CVD' AND
            CandID=311724
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V12-CVD' AND
                            CandID=311724
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V12-CVD' AND
            CandID=311724
    );

DELETE FROM
    TSI_EP
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='TSI_EP' AND
            SessionID = (
                SELECT
                    ID
                FROM
                    session
                WHERE
                    Visit_label='V06-CVD' AND
                            CandID=535264
                )
         );

DELETE FROM
    flag
WHERE
    Test_name
IN
    ('TSI_EP') AND
    SessionId = (
        SELECT
            ID
        FROM
            session
        WHERE
            Visit_label='V06-CVD' AND
            CandID=535264
    );