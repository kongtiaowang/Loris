-- Delete all surveys for SEA7006 V12 (SessionID = 6118) that are not started

-- There are 11 surveys in participant_accounts with SessionID = 6118 and Status = Created:
-- apsi_survey
-- BISQ_survey
-- fyi_survey
-- ibq_r_survey
-- macarthur_words_gestures_survey
-- pspq_SelfReport_mom
-- rbs_ec_survey
-- SEQ3
-- Infant_social_motivation_survey
-- SRS2_Preschool_survey
-- SRS2_SelfReport_Mom

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
            SessionID = '6118'
    );

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
            SessionID = '6118'
    );

DELETE FROM
    fyi_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='fyi_survey' AND
            SessionID = '6118'
    );

DELETE FROM
    ibq_r_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='ibq_r_survey' AND
            SessionID = '6118'
    );

DELETE FROM
    macarthur_words_gestures_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='macarthur_words_gestures_survey' AND
            SessionID = '6118'
    );

DELETE FROM
    pspq_SelfReport_mom
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='pspq_SelfReport_mom' AND
            SessionID = '6118'
    );

DELETE FROM
    rbs_ec_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='rbs_ec_survey' AND
            SessionID = '6118'
    );

DELETE FROM
    SEQ3
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SEQ3' AND
            SessionID = '6118'
    );

DELETE FROM
    Infant_social_motivation_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='Infant_social_motivation_survey' AND
            SessionID = '6118'
    );

DELETE FROM
    SRS2_Preschool_survey
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SRS2_Preschool_survey' AND
            SessionID = '6118'
    );

DELETE FROM
    SRS2_SelfReport_Mom
WHERE
    CommentID IN (
        SELECT
            CommentID
        FROM
            flag
        WHERE
            Test_name='SRS2_SelfReport_Mom' AND
            SessionID = '6118'
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
            (
                Test_name='apsi_survey' OR
                Test_name='BISQ_survey' OR
                Test_name='fyi_survey' OR
                Test_name='ibq_r_survey' OR
                Test_name='macarthur_words_gestures_survey' OR
                Test_name='pspq_SelfReport_mom' OR
                Test_name='rbs_ec_survey' OR
                Test_name='SEQ3' OR
                Test_name='Infant_social_motivation_survey' OR
                Test_name='SRS2_Preschool_survey' OR
                Test_name='SRS2_SelfReport_Mom'
            ) AND
            SessionID = '6118'
    );

DELETE FROM
    flag
WHERE
    Test_name
IN
    (
        'apsi_survey',
        'BISQ_survey',
        'fyi_survey',
        'ibq_r_survey',
        'macarthur_words_gestures_survey',
        'pspq_SelfReport_mom',
        'rbs_ec_survey',
        'SEQ3',
        'Infant_social_motivation_survey',
        'SRS2_Preschool_survey',
        'SRS2_SelfReport_Mom'
    ) AND
    SessionId = '6118';