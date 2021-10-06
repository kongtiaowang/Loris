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

-- Update Saliva Collection Tracking Form to be a none survey based instrument.
UPDATE test_names SET IsDirectEntry = 0 WHERE Test_name = 'Saliva_Collection_Tracking_Form';


-- -----------------------------------------------------------------------
--
--           Configure the MRI protocol groups for IBIS
--
-- -----------------------------------------------------------------------

-- --------------------------------------------
-- Three MRI protocols for IBIS:
-- a) IBIS 1&2 MRI Protocol
-- b) IBIS VSA MRI protocol
-- c) IBIS EP & Infant DS MRI protocol
-- --------------------------------------------
UPDATE mri_protocol_group SET Name='IBIS 1&2 MRI Protocol' WHERE MriProtocolGroupID=1;
INSERT INTO mri_protocol_group VALUES (2, 'IBIS VSA MRI protocol');
INSERT INTO mri_protocol_group VALUES (3, 'IBIS EP & Infant DS MRI protocol');


-- --------------------------------------------------------------------
-- Fill column MriProtocolGroupID for each line of table mri_protocol
-- according to the scan type value found on that line
-- --------------------------------------------------------------------
UPDATE mri_protocol mp
JOIN mri_scan_type mst ON (mp.Scan_type=mst.id)
JOIN mri_protocol_group mpg ON (mpg.Name = 'IBIS VSA MRI protocol')
SET mp.MriProtocolGroupID = mpg.MriProtocolGroupID
WHERE mst.Scan_type LIKE '%SA';


UPDATE mri_protocol mp
JOIN mri_scan_type mst ON (mp.Scan_type=mst.id)
JOIN mri_protocol_group mpg ON (mpg.Name = 'IBIS EP & Infant DS MRI protocol')
SET mp.MriProtocolGroupID = mpg.MriProtocolGroupID
WHERE mst.Scan_type LIKE '%EP';


-- ------------------------------------------
-- Activate all lines of table mri_protocol
-- ------------------------------------------
UPDATE mri_protocol SET active='Y';

-- -------------------------------------------------------------------------------------------
-- All instruments listed in table test_names shold have column UserID. This patch adds that
-- column to the instrument tables that do not already have it
-- -------------------------------------------------------------------------------------------

ALTER TABLE acesubjectmedical_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE apsi_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE rbs_ec_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE tanner_boys_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE tanner_girls_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;


-- ---------------------------------------------------------------
-- Removes all duplicate entries in table CBCL_1_to_5_yrs_lookup
-- ---------------------------------------------------------------

DELETE FROM CBCL_1_to_5_yrs_lookup WHERE Raw=62 AND Type='Total';
INSERT INTO CBCL_1_to_5_yrs_lookup VALUES(62,64,'Total',NULL,'Clinical Range');

DELETE FROM CBCL_1_to_5_yrs_lookup WHERE Raw=63 AND Type='Total';
INSERT INTO CBCL_1_to_5_yrs_lookup VALUES(63,65,'Total',NULL,'Clinical Range');

DELETE FROM CBCL_1_to_5_yrs_lookup WHERE Raw=128 AND Type='Total';
INSERT INTO CBCL_1_to_5_yrs_lookup VALUES(128,88,'Total',NULL,'Clinical Range');
