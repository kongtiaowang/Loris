-- --------------------------------------------------------------------
--
-- Corrects the invalid subtest names for test radiology_review_infant
--
-- --------------------------------------------------------------------


UPDATE instrument_subtests SET Subtest_name = REPLACE(Subtest_name,'Radiology_Review_VSA', 'radiology_review_infant') WHERE test_name='radiology_review_infant';
