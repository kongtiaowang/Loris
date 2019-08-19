UPDATE test_battery  SET Active ='N' where Visit_label IS NULL and SubprojectID IS NULL;
-- Redmine 16837
UPDATE participant_accounts SET Email ='lorideleon@live.com' where SessionID ='6005'and Test_name='ABC2';
-- Redmine 16782
UPDATE candidate SET Active ='N' where PSCID ='PHI3000';