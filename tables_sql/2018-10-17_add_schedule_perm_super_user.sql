-- Inserting schedule permissions to super user id so that he/she can give permissions to others.
INSERT INTO user_perm_rel (userID, permID) VALUES
('1000036', (SELECT permID FROM permissions WHERE code='schedule_module'));
