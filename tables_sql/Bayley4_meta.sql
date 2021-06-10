INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('Bayley4', 'Bayley4', '1');


--  DS Infant(across all sub projects & visit labels) And IBIS EP High Risk & IBIS EP (across all sub projects & visit labels)
INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Bayley4', '0', '0', 'Y', 'Visit', 20, 'V06-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 20, 'V12-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 20, 'V24-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 23, 'V06-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 23, 'V12-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 23, 'V24-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 23, 'VSA', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V06-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V12-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V24-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V09', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V9-CVD', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V18', NULL),
           ('Bayley4', '0', '0', 'Y', 'Visit', 18, 'V18-CVD', NULL);   
