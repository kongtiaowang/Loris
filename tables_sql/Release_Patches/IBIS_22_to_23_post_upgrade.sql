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
