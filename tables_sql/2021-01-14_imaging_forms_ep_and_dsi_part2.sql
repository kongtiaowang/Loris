-- ===============================================================
--
-- Creates a table for instrument radiology_review_infant.
-- Creates a table for instrument mock_scanner_training_form_infant.
--
-- ===============================================================




-- #####################################
--
--     radiology_review_infant
--
-- #####################################

CREATE TABLE radiology_review_infant           LIKE Radiology_Review_VSA;

DELETE FROM Radiology_Review_VSA
WHERE CommentID IN (
    SELECT f.Commentid
    FROM flag f
    JOIN session s ON (f.sessionid=s.id)
    WHERE s.visit_label IN ('V06-CVD', 'V12-CVD', 'V24-CVD')
    AND s.subprojectid IN (18,20,23)
    AND f.test_name = 'Radiology_Review_VSA'
);

-- #####################################
--
-- mock_scanner_training_form_infant
--
-- #####################################

CREATE TABLE mock_scanner_training_form_infant LIKE Mock_Scanner_Training_Version_2;

DELETE FROM Mock_Scanner_Training_Version_2
WHERE CommentID IN (
    SELECT f.Commentid
    FROM flag f
    JOIN session s ON (f.sessionid=s.id)
    WHERE s.visit_label IN ('V06-CVD', 'V12-CVD', 'V24-CVD')
    AND s.subprojectid IN (18,20,23)
    AND f.test_name = 'Mock_Scanner_Training_Version_2'
);
