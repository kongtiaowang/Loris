-- Delete SEQ3 for UNC6001(911161); Made sure no data collected for this candidate
DELETE FROM SEQ3
WHERE CommentID IN (
    SELECT CommentID FROM flag
    WHERE test_name='SEQ3'
    AND SessionID = (SELECT id FROM session WHERE visit_label='V12' AND candid=911161)
);

DELETE FROM flag
WHERE test_name IN ('SEQ3')
AND sessionid = (SELECT id FROM session WHERE visit_label='V12' AND candid=911161);