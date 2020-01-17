-- Protocol names were checked for strict string equality. Now the protocol name is
-- checked against a regex. This SQL statement build the regex equivalent to a strict string
-- equality for every non NULL protocol name check.
UPDATE mri_protocol SET protocol_name = CONCAT('^', protocol_name, '$') WHERE protocol_name IS NOT NULL;

-- Insert new scan type DtiCmrrSA and associated protocol checks
INSERT INTO mri_scan_type (Scan_type) VALUES ('DtiCmrrSA');

INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                               , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `protocol_name`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='DtiCmrrSA'), 4100      , 84        , 1.7                    , 'COL'                     , 1.7          , 1.7          , 1.7          , '^DWIcmrr'     );

-- This is so that a DWIcmrr is not mistakingly tagged as a DtiSA if the protocol checks for DtiSA occur before
-- those for DtiCmrrSA
UPDATE mri_protocol SET protocol_name = '^(?!DWIcmrr)' WHERE Scan_type = (SELECT ID FROM mri_scan_type WHERE Scan_type='DtiSA');
