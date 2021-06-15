-- -------------------------------------------------------------------------
-- 
-- Remove the Personally Identifiable Information (PII) from the database
-- The only place where PII was found was in column PatientName for tables
-- tarchive, tarchive_bkp, MRICandidateErrors and mri_violations_log.
--
-- -------------------------------------------------------------------------

-- =============================
--            Tarchive
-- =============================
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


-- ===============================
--            Tarchive_bkp
-- ===============================

UPDATE tarchive_bkp SET PatientName='UNKNOWN' WHERE TarchiveID IN (229,238,248,249,304,467,470,473,478,497);

UPDATE tarchive_bkp SET PatientName='SEA1048_132594_V06' WHERE TarchiveID=487;
UPDATE tarchive_bkp SET PatientName='PHI0168_814671_V12' WHERE TarchiveID=4000189;
UPDATE tarchive_bkp SET PatientName='PHI0084_395301_V24' WHERE TarchiveID=4000203;
UPDATE tarchive_bkp SET PatientName='PHI0153_550077_V12' WHERE TarchiveID=4000204;
UPDATE tarchive_bkp SET PatientName='PHI0193_671814_V12' WHERE TarchiveID=4000205;
UPDATE tarchive_bkp SET PatientName='PHI0241_572121_V12' WHERE TarchiveID=4000272;
UPDATE tarchive_bkp SET PatientName='PHI0248_621892_V24' WHERE TarchiveID=4000333;
UPDATE tarchive_bkp SET PatientName='PHI1005_974562_V06' WHERE TarchiveID=4000334;

UPDATE tarchive_bkp SET PatientName='SEA1022_235125_V12' WHERE TarchiveID=474;
UPDATE tarchive_bkp SET PatientName='SEA1045_597653_V03' WHERE TarchiveID=482;

-- =====================================
--            MRICandidateErrors
-- =====================================

UPDATE MRICandidateErrors m
JOIN tarchive t USING(TarchiveID)
SET m.PatientName=t.PatientName
WHERE m.PatientName NOT REGEXP '^(lego|living)'
AND m.PatientName NOT REGEXP '^(phi|unc|sea|stl|dcc)';

-- =====================================
--           mri_violations_log
-- =====================================

UPDATE mri_violations_log m
JOIN tarchive t USING(TarchiveID)
SET m.PatientName=t.PatientName
WHERE m.PatientName NOT REGEXP '^(lego|living)'
AND m.PatientName NOT REGEXP '^(phi|unc|sea|stl|dcc)';




