--
-- Updates the image_storage_regex used to match the T1wRaw and T2wRaw for the IBIS SA protocol. 
-- Without this update, if the lines associated to the a raw scan were before those associated to the 
-- norm scan, then a norm would erroneously be identified as a raw scan (since the regex for the 
-- raw scan is a substring of the regex for the norm scan).
--
-- Fix for Redmine ticket #16331
-- 

UPDATE mri_protocol SET image_storage_regex = 'p4 M/ND(?!/NORM)'
WHERE Scan_type IN (SELECT ID FROM mri_scan_type WHERE Scan_type IN ('T1wRawSA', 'T2RawSA'));
