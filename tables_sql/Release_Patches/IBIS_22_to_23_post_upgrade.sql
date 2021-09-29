INSERT INTO permissions (code,description,categoryID) VALUES ('server_processes_manager','View and manage server processes','2');
INSERT INTO modules (Name, Active) VALUES ('reliability', 'Y');
INSERT INTO modules (Name, Active) VALUES ('environment_residential_history', 'Y');
INSERT INTO modules (Name, Active) VALUES ('schedule_module', 'Y');
INSERT INTO modules (Name, Active) VALUES ('videos', 'Y');
INSERT INTO modules (Name, Active) VALUES ('final_radiological_review', 'Y');
INSERT INTO modules (Name, Active) VALUES ('bobdule', 'Y');
INSERT INTO modules (Name, Active) VALUES ('quality_control', 'Y');
INSERT INTO modules (Name, Active) VALUES ('dqt', 'Y');
UPDATE modules SET Active='N' WHERE Name='imaging_qc';

-- Issue Tracker Path
UPDATE Config
    SET Value='/export-01/nihace/www/modules/issue_tracker'
    WHERE ConfigID=(
        SELECT ID FROM ConfigSettings WHERE Name='IssueTrackerDataPath'
    );

-- Modify publication column name
ALTER TABLE publication_upload
    CHANGE COLUMN URL Filename VARCHAR(255);

-- Set Test_names sent as survey to direct entry
UPDATE test_names t
    SET IsDirectEntry = 1
    WHERE t.IsDirectEntry=0
        AND EXISTS (SELECT * FROM participant_accounts p WHERE t.Test_name = p.Test_name);
