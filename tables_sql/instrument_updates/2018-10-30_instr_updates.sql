-- seq needs to be in battery other than VSA
UPDATE test_battery SET Active='Y' WHERE  Test_name ='seq' and Visit_label!='VSA';
-- Remove SRS2 1 & 2 as mom and dad versions are created
UPDATE test_names SET IsDirectEntry='0' WHERE  Test_name ='SRS2_1';
UPDATE test_names SET IsDirectEntry='0' WHERE  Test_name ='SRS2_2';
-- Inserting publication module permissions to super user id so that he/she can give permissions to others.
INSERT INTO user_perm_rel (userID, permID) VALUES('1000036', (SELECT permID FROM permissions WHERE code='publication_approve'));
INSERT INTO user_perm_rel (userID, permID) VALUES('1000036', (SELECT permID FROM permissions WHERE code='publication_propose'));
INSERT INTO user_perm_rel (userID, permID) VALUES('1000036', (SELECT permID FROM permissions WHERE code='publication_view'));
