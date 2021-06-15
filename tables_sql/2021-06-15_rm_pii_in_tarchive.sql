-- -------------------------------------------------------------------------
-- 
-- Remove the Personally Identifiable Information (PII) from table tarchive
-- The only place where PII was found was in column PatientName
--
-- -------------------------------------------------------------------------

-- ---------------------------------------------------------------------------------
-- A patient name of the form PSCID_CandID_VLabel could not be detemrine for these:
-- setting patient name to UNKNOWN
-- ---------------------------------------------------------------------------------
UPDATE tarchive SET PatientName='UNKNOWN' WHERE TarchiveID IN (229,238,248,249,304,467,470,473,478,497);

-- ---------------------------------------------------------------------------------
-- The patient name for these was determined by looking at the session to which all
-- files associated to the archive are tied
-- ---------------------------------------------------------------------------------
UPDATE tarchive SET PatientName='SEA1048_132594_V06' WHERE TarchiveID=487;
UPDATE tarchive SET PatientName='PHI0168_814671_V12' WHERE TarchiveID=4000189;
UPDATE tarchive SET PatientName='PHI0084_395301_V24' WHERE TarchiveID=4000203;
UPDATE tarchive SET PatientName='PHI0153_550077_V12' WHERE TarchiveID=4000204;
UPDATE tarchive SET PatientName='PHI0193_671814_V12' WHERE TarchiveID=4000205;
UPDATE tarchive SET PatientName='PHI0241_572121_V12' WHERE TarchiveID=4000272;
UPDATE tarchive SET PatientName='PHI0248_621892_V24' WHERE TarchiveID=4000333;
UPDATE tarchive SET PatientName='PHI1005_974562_V06' WHERE TarchiveID=4000334;

