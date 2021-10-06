-- ---------------------------------------------------------------
-- Removes all duplicate entries in table CBCL_1_to_5_yrs_lookup
-- ---------------------------------------------------------------

DELETE FROM CBCL_1_to_5_yrs_lookup WHERE Raw=62 AND Type='Total';
INSERT INTO CBCL_1_to_5_yrs_lookup VALUES(62,64,'Total',NULL,'Clinical Range');

DELETE FROM CBCL_1_to_5_yrs_lookup WHERE Raw=63 AND Type='Total';
INSERT INTO CBCL_1_to_5_yrs_lookup VALUES(63,65,'Total',NULL,'Clinical Range');

DELETE FROM CBCL_1_to_5_yrs_lookup WHERE Raw=128 AND Type='Total';
INSERT INTO CBCL_1_to_5_yrs_lookup VALUES(128,88,'Total',NULL,'Clinical Range');



