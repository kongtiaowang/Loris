ALTER TABLE candidate ADD COLUMN ParentID VARCHAR(15) NULL, ADD UNIQUE INDEX `UK_candidate_ParentID` (`ParentID` ASC);
INSERT INTO modules (Name, Active) VALUES ('parent_portal', 'Y');