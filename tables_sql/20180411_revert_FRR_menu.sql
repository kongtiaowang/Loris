-- Revert back the FRR Menu and Permissions deleted from LORIS Core(as of 19.) for IBIS.
INSERT INTO LorisMenu (Label, Link, Parent, OrderNumber) VALUES
('Radiological Reviews', 'final_radiological_review/', (SELECT ID FROM LorisMenu as L WHERE Label='Imaging'), 1);
-- Radiological Reviews
INSERT INTO LorisMenuPermissions (MenuID, PermID)
    SELECT m.ID, p.PermID FROM permissions p CROSS JOIN LorisMenu m WHERE p.code='edit_final_radiological_review' AND m.Label='Radiological Reviews';
INSERT INTO LorisMenuPermissions (MenuID, PermID)
    SELECT m.ID, p.PermID FROM permissions p CROSS JOIN LorisMenu m WHERE p.code='view_final_radiological_review' AND m.Label='Radiological Reviews';
