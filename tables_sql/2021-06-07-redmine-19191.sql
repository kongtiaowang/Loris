INSERT INTO LorisMenu (Parent, Label, Link, OrderNumber) VALUES
    (3, 'Bobdule', 'bobdule/', 6);

INSERT INTO LorisMenuPermissions (MenuID, PermID)
    SELECT
        (SELECT ID FROM LorisMenu WHERE LorisMenu.Label='Bobdule') AS MenuID,
        (SELECT permID FROM permissions WHERE permissions.code='edit_final_radiological_review') AS PermID;

DELETE FROM user_perm_rel
    WHERE permID IN (SELECT permID FROM permissions WHERE permissions.code='edit_final_radiological_review')
    AND userID NOT IN (SELECT ID FROM users WHERE UserID IN ('mckinstryb@wustl.edu', 'nicolabrossard.mni@gmail.com', 'jstirling91@gmail.com', 'leigh.ibis@gmail.com'));
