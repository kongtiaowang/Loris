-- ====================================================================
-- 
-- Anonymizes all parameters containing PII in table parameter_file
-- The names of the parameter types to anomymize are:
--   patient:full_name
--   patient_name
--   patient:identification
--   dicom_0x0010:el_0x1000
--   dicom_0x0010:el_0x1001
--   dicom_0x0010:el_0x1005
--   dicom_0x0010:el_0x1040
--   dicom_0x0010:el_0x1060
--   dicom_0x0010:el_0x21f0
--   dicom_0x0010:el_0x2154
--
-- ====================================================================

-- -----------------------------------------------------------------------------
-- 
-- Patient identification (patient:identification)  were legit as of 2021Jun21
--
-- -----------------------------------------------------------------------------

-- ----------------------------------------------------------------------
--
-- Real patient name ('patient:full_name' and patient_name) found for 
-- these two files: replace with <pscid>_<candid>_<vlabel>
--
-- ----------------------------------------------------------------------

UPDATE parameter_file pf
JOIN files f
  ON (f.FileID=pf.FileID)
JOIN session s
  ON (s.ID=f.sessionID)
JOIN candidate c
  ON (c.CandID=s.CandID)
SET Value = CONCAT_WS('_', c.PSCID, c.CandID, s.Visit_label)
WHERE pf.FileID IN (57168, 57169)
AND pf.ParameterTypeID IN (
    SELECT ParameterTypeID
    FROM parameter_type
    WHERE Name ='patient:full_name'
    OR Name = 'patient_name'
);

-- -------------------------------------------------------------------------
-- 
-- Other patient IDs (dicom_0x0010:el_0x1000)  were legit as of 2021Jun21
--
-- -------------------------------------------------------------------------

-- ---------------------------------------------------------
--
-- Other patient Names (dicom_0x0010:el_0x1001) found:
-- replacing with <pscid>_<candid>_<vlabel>
--
-- ---------------------------------------------------------
UPDATE parameter_file pf
JOIN files f
  ON (f.FileID=pf.FileID)
JOIN session s
  ON (s.ID=f.sessionID)
JOIN candidate c
  ON (c.CandID=s.CandID)
SET Value = CONCAT_WS('_', c.PSCID, c.CandID, s.Visit_label)
WHERE pf.ParameterTypeID = (
    SELECT ParameterTypeID
    FROM parameter_type
    WHERE Name='dicom_0x0010:el_0x1001'
);

-- ------------------------------------------------------------------------
-- 
-- Patient birth name(dicom_0x0010:el_0x1005) were legit as of 2021Jun21
--
-- ------------------------------------------------------------------------

-- --------------------------------------------------------
-- 
-- PII were found for these:
--     * Real patient address (dicom_0x0010:el_0x1040)
--     * Patient mother's birth name (dicom_0x0010:el_0x1060)
--     * Patient religious preferences (dicom_0x0010:el_0x21f0)
--     * Patient telephone number (dicom_0x0010:el_0x2154)
-- Replacing all with 'IBIS'
--
-- --------------------------------------------------------
UPDATE parameter_file
SET Value = 'IBIS'
WHERE ParameterTypeID IN (
    SELECT ParameterTypeID
    FROM parameter_type
    WHERE Name IN (
        'dicom_0x0010:el_0x1040',
        'dicom_0x0010:el_0x1060',
        'dicom_0x0010:el_0x21f0',
        'dicom_0x0010:el_0x2154'
    )
);
