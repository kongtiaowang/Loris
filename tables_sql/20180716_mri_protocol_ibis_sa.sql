-- ----------------------------------------------------------------------------------------------
-- SQL patch that will allow the new MRI protocol for IBIS SA to be used
-- 
-- This patch adds columns to the mri_protocol table to support new types of constraints.
-- One of new column is 'Active' and specifies whether the current line is taken into 
-- account when the mri protocol table is read. This column also allows both the IBIS 1&2 
-- and the IBIS SA protocols to coexist in the same table (i.e. you set 'Active' = 'Y' only for 
-- those lines which you want the pipeline to consider).
-- ----------------------------------------------------------------------------------------------



-- ---------------------------------------------------------------------------
-- New scan types for IBIS SA
-- ---------------------------------------------------------------------------
INSERT INTO mri_scan_type (`Scan_type`) VALUES('spin_echo_fieldmap_ap_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('spin_echo_fieldmap_pa_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('t1w_raw_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('t1w_norm_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('t2w_raw_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('t2w_norm_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('dti_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('bold_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('fa_sa');
INSERT INTO mri_scan_type (`Scan_type`) VALUES('col_fa_sa');

-- ------------------------------------------------------------------------
-- New columns to add in the mri_protocol table
-- ------------------------------------------------------------------------
ALTER TABLE mri_protocol ADD COLUMN protocol_name            VARCHAR(255)  DEFAULT NULL          AFTER series_description_regex;
ALTER TABLE mri_protocol ADD COLUMN phase_encoding_direction VARCHAR(255)  DEFAULT NULL          AFTER protocol_name;
ALTER TABLE mri_protocol ADD COLUMN image_storage_regex      VARCHAR(255)  DEFAULT NULL          AFTER phase_encoding_direction;
ALTER TABLE mri_protocol ADD COLUMN number_of_files          VARCHAR(255)  DEFAULT NULL          AFTER image_storage_regex;
ALTER TABLE mri_protocol ADD COLUMN active                   enum('Y','N') DEFAULT 'Y'  NOT NULL AFTER number_of_files;

-- -----------------------------------------------------------------------------------------
-- This will inactivate all the lines in the mri_protocol, namely those that describe
-- the IBIS 1&2 protocol. All the lines that will be created afterwards are associated
-- to the IBIS SA protocol and will have 'Active' set to 'Y'.
-- -----------------------------------------------------------------------------------------
UPDATE mri_protocol SET active='N';

-- --------------------------------------------------------------------------------
-- New IBIS SA protocol: spin_echo_fieldmap_ap_sa
-- --------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , 2.4          , 2.4          , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , 2.4          , 2.4          , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , 2.4          , -2.4         , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , -2.4         , 2.4          , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , -2.4         , -2.4         , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , -2.4         , -2.4         , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , 2.4          , -2.4         , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_ap_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_AP'          , 2.4          , 2.4          , -2.4         );
       
-- ---------------------------------------------------------------------------------
-- New IBIS SA protocol: spin_echo_fieldmap_pa_sa
-- ---------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , 2.4          , 2.4          , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , 2.4          , 2.4          , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , 2.4          , -2.4         , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , -2.4         , 2.4          , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , -2.4         , -2.4         , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , -2.4         , -2.4         , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , 2.4          , -2.4         , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                              , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `protocol_name`                , `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='spin_echo_fieldmap_pa_sa'), 6000      ,  55       , 2.4                    , 'COL'                     , 'SpinEchoFieldMap_APinv'       , 2.4          , 2.4          , -2.4         );
 

-- -----------------------------------------------------------------------------------
-- New IBIS SA protocol: t1w_raw_sa
-- -----------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , 1            , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , -1           , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , 1            , -1           , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , -1           , -1           , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , 1            , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , -1           , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , 1            , -1           , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_raw_sa') , 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , -1           , -1           , '4 M/ND'             , '176-9999999');

-- ----------------------------------------------------------------------------------
-- New IBIS SA protocol: t1w_norm_sa
-- ----------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , 1            , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , -1           , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , 1            , -1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , 1            , -1           , -1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , 1            , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , -1           , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , 1            , -1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TI_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t1w_norm_sa'), 2500      , 1000      , 2.03      , 1                      , 'ROW'                     , -1           , -1           , -1           , '4 M/ND/NORM'        , '176-9999999');

-- -----------------------------------------------------------------------------------
-- New IBIS SA protocol: t2w_raw_sa
-- -----------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , 1            , 1            , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , 1            , -1           , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , 1            , 1            , -1            , '4 M/ND'            , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , 1            , -1           , -1            , '4 M/ND'            , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , -1           , 1            , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , -1           , -1           , 1            , '4 M/ND'             , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , -1           , 1            , -1            , '4 M/ND'            , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_raw_sa') , 3200      , 564       , 1                      , 'ROW'                     , -1           , -1           , -1            , '4 M/ND'            , '176-9999999');

-- -----------------------------------------------------------------------------------
-- New IBIS SA protocol: t2w_norm_sa
-- -----------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , 1            , 1            , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , 1            , -1            , 1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , 1            , 1            , -1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , 1            , -1           , -1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , -1           , 1            , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , -1           , -1           , 1            , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , -1           , 1            , -1           , '4 M/ND/NORM'        , '176-9999999');
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`, `image_storage_regex`, `number_of_files`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='t2w_norm_sa'), 3200      , 564       , 1                      , 'ROW'                     , -1           , -1           , -1           , '4 M/ND/NORM'        , '176-9999999');


-- ----------------------------------------------------------------------------------
-- New IBIS SA protocol: dti_sa
-- ----------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='dti_sa')     , 4100      , 84        , 1.7                    , 'COL'                     , 1.7          , 1.7          , 1.7          );

-- ----------------------------------------------------------------------------------
-- New IBIS SA protocol: bold_sa
-- ----------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , 2.4          , 2.4          , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , 2.4          , -2.4         , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , 2.4          , -2.4         , -2.4        );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , 2.4          , 2.4          , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , -2.4         , 2.4          , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , -2.4         , -2.4         , 2.4          );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , -2.4         , -2.4         , -2.4         );
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `TR_range`, `TE_range`, `slice_thickness_range`, `phase_encoding_direction`, `xstep_range`, `ystep_range`, `zstep_range`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='bold_sa')    , 800       , 30        , 2.4                    , 'COL'                     , -2.4         , 2.4          , -2.4         );

-- ---------------------------------------------------------------------------------
-- New IBIS SA protocol: col_fa_sa
-- ---------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `series_description_regex`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='col_fa_sa')  , '_ColFA'                  );

-- ---------------------------------------------------------------------------------
-- New IBIS SA protocol: fa_sa
-- ---------------------------------------------------------------------------------
INSERT INTO mri_protocol (`Center_name`, `ScannerID`, `Scan_type`                                                 , `series_description_regex`)
       VALUES            ('ZZZZ'       , 0          , (SELECT ID FROM mri_scan_type WHERE Scan_type='fa_sa')      , '_FA'                     );
