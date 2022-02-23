-- -------------------------------------------------------------------------------------
--
-- Automatic insertion of Radiological Review Form data submitted by BoB MCInstry
-- via an Excel sheet for a couple of SEA candidates at VSA.
--
-- -------------------------------------------------------------------------------------


UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='SEA0007'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_1_comment='min PVS',
    subtest_4_6_check='yes',
    subtest_4_6_circleOne='mild'
WHERE c.PSCID='SEA0014'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_comment='single dil PVS',
    subtest_1_2_check='yes',
    subtest_1_2_comment='5.2mm R cerebellar WM hyperinten',
    subtest_1_3_comment='srd ck old, f/u?'
WHERE c.PSCID='SEA0029'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_1_comment='3mm cyst adj R frint horn'
WHERE c.PSCID='SEA0032'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='SEA0050'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_4_6_check='yes',
    subtest_4_6_circleOne='mild'
WHERE c.PSCID='SEA0069'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0072'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_comment='poss PF arach cyst',
    subtest_1_2_check='yes',
    subtest_4_1_check='yes'
WHERE c.PSCID='sea0079'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_comment='mild for both',
    subtest_1_2_check='yes',
    subtest_2_3_check='yes',
    subtest_4_5_check='yes'
WHERE c.PSCID='sea0092'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_2_check='yes',
    subtest_1_2_comment='frontal DVA; BG PVS',
    subtest_4_4_check='yes',
    subtest_4_5_check='yes',
    subtest_4_6_check='yes',
    subtest_4_6_circleOne='moderate'
WHERE c.PSCID='sea0106'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0108'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_2_comment='DCC 920912 mislabel 235inPACS'
WHERE c.PSCID='sea0122'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0136'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_2_check='yes',
    subtest_2_3_check='yes'
WHERE c.PSCID='sea0143'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_2_comment='? mild PVS and SA spaces'
WHERE c.PSCID='sea0153'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_2_comment='prob front DVA1',
    subtest_1_3_comment='front horn big than average'
WHERE c.PSCID='sea0158'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0160'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0186'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0197'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_2_check='yes',
    subtest_1_2_comment='prob PF arach cyst; sm CSP',
    subtest_4_1_check='yes'
WHERE c.PSCID='sea0214'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0221'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_2_comment='1 dil PVS'
WHERE c.PSCID='sea0225'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes'
WHERE c.PSCID='sea0233'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_check='yes',
    subtest_1_2_comment='# little PVS'
WHERE c.PSCID='sea0235'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_2_check='yes',
    subtest_4_5_check='yes'
WHERE c.PSCID='sea0238'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_2_check='yes',
    subtest_1_2_comment='poss sm PF arach cyst',
    subtest_4_1_check='yes'
WHERE c.PSCID='sea0247'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_2_check='yes',
    subtest_1_2_comment='min dil PVS',
    subtest_4_5_check='yes'
WHERE c.PSCID='sea0258'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

UPDATE Radiology_Review_VSA rrv
JOIN flag f ON(f.CommentID=rrv.CommentID AND rrv.CommentID NOT LIKE 'DDE%')
JOIN session s ON (s.ID=f.sessionID)
JOIN candidate c ON (c.CandID=s.CandID)
SET subtest_1_1_comment='BG PVS',
    subtest_1_2_check='yes',
    subtest_4_5_check='yes'
WHERE c.PSCID='sea102'
AND s.visit_label = 'VSA';

-- -------------------------------------------------------------------------------------------------

