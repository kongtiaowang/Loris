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
