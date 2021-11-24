-- -------------------------------------------------------------------------------
-- Sets the order_number for test FamilyEnvironmentScales to have the pages of
-- this instrument displayed in the correctt order
-- -------------------------------------------------------------------------------

UPDATE instrument_subtests SET order_number=1 WHERE Subtest_name='FamilyEnvironmentScales_page1';
UPDATE instrument_subtests SET order_number=2 WHERE Subtest_name='FamilyEnvironmentScales_page2';
UPDATE instrument_subtests SET order_number=3 WHERE Subtest_name='FamilyEnvironmentScales_page3';

-- ---------------------------------------------------------------
-- Remove all DB reference to old test FES
-- ---------------------------------------------------------------

DELETE FROM test_names WHERE test_name='FES';
DELETE FROM instrument_subtests WHERE test_name='FES';
DROP TABLE FES;

