CREATE TABLE `mri_scan_type_groups` (
    `MriScanTypeGroupID` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
    `Name`               VARCHAR(255) UNIQUE NOT NULL,
    `Description`        VARCHAR(255) UNIQUE NOT NULL,
    PRIMARY KEY  (`MriScanTypeGroupID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO mri_scan_type_groups (Name, Description) VALUES ('All_T1w', 'T1w');
INSERT INTO mri_scan_type_groups (Name, Description) VALUES ('All_T2w', 'T2w');

-- ----------------------------------------------------------

CREATE TABLE `mri_scan_type_groups_rel` (
    `MriScanTypeID` int(11) UNSIGNED NOT NULL,
    `MriScanTypeGroupID` int(11) UNSIGNED NOT NULL,
    CONSTRAINT `FK_mri_scan_type_groups_rel1` FOREIGN KEY (`MriScanTypeID`)      REFERENCES `mri_scan_type`        (`ID`),
    CONSTRAINT `FK_mri_scan_type_groups_rel2` FOREIGN KEY (`MriScanTypeGroupID`) REFERENCES `mri_scan_type_groups` (`MriScanTypeGroupID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO mri_scan_type_groups_rel 
SELECT mst.ID, mstg.MriScanTypeGroupID FROM mri_scan_type mst JOIN mri_scan_type_groups mstg ON (mstg.Name='All_T1w')  WHERE Scan_type LIKE 't1w%';

INSERT INTO mri_scan_type_groups_rel 
SELECT mst.ID, mstg.MriScanTypeGroupID FROM mri_scan_type mst JOIN mri_scan_type_groups mstg ON (mstg.Name='All_T2w')  WHERE Scan_type LIKE 't2w%';


-- ----------------------------------------------------------

CREATE TABLE `mri_scan_type_qc_value` (
    `MriScanTypeID` int(11) UNSIGNED NOT NULL,
    `Value`         int(11) UNSIGNED NOT NULL,
    CONSTRAINT `FK_mri_scan_type_qc_value` FOREIGN KEY (`MriScanTypeID`) REFERENCES `mri_scan_type` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO mri_scan_type_qc_value (MriScanTypeID, Value)
SELECT ID, 100 FROM mri_scan_type WHERE Scan_type NOT LIKE '%SA' AND Scan_type NOT LIKE '%EP';

INSERT INTO mri_scan_type_qc_value (MriScanTypeID, Value)
SELECT ID, 50 FROM mri_scan_type WHERE Scan_type LIKE '%SA' OR Scan_type LIKE '%EP';

-- ----------------------------------------------------------

CREATE TABLE `mri_group_qc_pass_threshold` (
    `MriScanTypeGroupID` int(11) UNSIGNED NOT NULL,
    `Threshold`          int(11) UNSIGNED NOT NULL,
    CONSTRAINT `FK_mri_group_qc_threshold1` FOREIGN KEY (`MriScanTypeGroupID`) REFERENCES `mri_scan_type_groups` (`MriScanTypeGroupID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO mri_group_qc_pass_threshold (MriScanTypeGroupID, Threshold)
SELECT MriScanTypeGroupID, 100 FROM mri_scan_type_groups WHERE Name IN ('All_T1w', 'All_T2w');


DELETE FROM ConfigSettings WHERE Name='tblScanTypes';
