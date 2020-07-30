-- script to check data to make sure that there is no user data
/*
SELECT Data_entry_completion_status, count(Data_entry_completion_status) FROM EEG 
WHERE commentid IN (SELECT f.commentid FROM flag f, session s WHERE f.sessionid = s.id AND f.Test_name = 'EEG'
and s.Visit_label = 'VSA') GROUP BY Data_entry_completion_status;
*/

-- DELETE EEG FROM instruments together with flag data
DELETE FROM EEG WHERE commentid IN (SELECT f.commentid FROM flag f, session s 
WHERE f.sessionid = s.id AND f.Test_name = 'EEG' and s.Visit_label = 'VSA');

DELETE FROM flag WHERE Test_name = 'EEG' and sessionid IN (SELECT id FROM session WHERE Visit_label = 'VSA');
