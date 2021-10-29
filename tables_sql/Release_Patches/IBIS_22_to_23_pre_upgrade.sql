-- 0000-00-00 00:00:00 is not valid, need to port to valid timestamp
UPDATE mri_violations_log SET TimeRun='1970-01-01 00:00:01' WHERE CAST(TimeRun AS CHAR(20)) = '0000-00-00 00:00:00';
