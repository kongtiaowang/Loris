-- Redmine 16837
UPDATE participant_accounts SET Email ='lorideleon@live.com' where SessionID ='6005'and Test_name='ABC2';
-- Redmine 16782
UPDATE candidate SET Active ='N' where PSCID ='PHI3000';

UPDATE test_names tn
SET tn.Sub_group = (SELECT ID FROM test_subgroups where Subgroup_name='Miscellaneous (Data no more collected)')
WHERE tn.test_name IN ('das_schoolage','ADULT_SELF_REPORT','ABCL','SRS2_InformantReport','SRS2_SelfReport')