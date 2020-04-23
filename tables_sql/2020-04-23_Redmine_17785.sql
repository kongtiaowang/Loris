-- Inactive SEQ from testbattery
UPDATE test_battery set Active='N' where Test_name='SEQ3';

-- Delete SEQ3 for SEA7005(624363); Made sure no data collected for this candidate
DELETE FROM SEQ3
WHERE CommentID IN (
    SELECT CommentID FROM flag
    WHERE test_name='SEQ3'
    AND SessionID = (SELECT id FROM session WHERE visit_label='V12' AND candid=624363)
);

DELETE FROM flag
WHERE test_name IN ('SEQ3')
AND sessionid = (SELECT id FROM session WHERE visit_label='V12' AND candid=624363);




