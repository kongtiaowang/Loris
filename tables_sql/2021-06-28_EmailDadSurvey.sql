-- -----------------------------------------------------------------------
-- 
-- Updates the email address associated to specific dad surveys for 
-- candidate SEA0029
--
-- Fixes https://redmine.cbrain.mcgill.ca/issues/19304.
--
-- -----------------------------------------------------------------------

UPDATE participant_accounts pa
JOIN session s ON (s.id=pa.sessionid)
JOIN candidate c USING(candid)
SET email='jeengh@yahoo.com'
WHERE c.pscid='SEA0029'
AND test_name IN (
    'ADULT_SELF_REPORT_DAD',
    'ABCL_DAD_ON_MOM',
    'pspq_SelfReport_dad',
    'pspq_InformantReport_dad_on_mom',
    'SRS2_SelfReport_Dad',
    'SRS2_InformantReport_Dad_On_Mom'
);
