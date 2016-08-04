UPDATE test_names SET Test_name='csbs_spontaneity', Full_name='CSBS Spontaneity' WHERE Test_name='csbs_sponteneity';

UPDATE instrument_subtests SET Test_name='csbs_spontaneity' WHERE Test_name='csbs_sponteneity';
UPDATE instrument_subtests SET Subtest_name='csbs_spontaneity_page1' WHERE Subtest_name='csbs_sponteneity_page1';
UPDATE instrument_subtests SET Subtest_name='csbs_spontaneity_page2' WHERE Subtest_name='csbs_sponteneity_page2';

UPDATE test_battery SET Test_name='csbs_spontaneity' WHERE Test_name='csbs_sponteneity';

UPDATE flag SET Test_name='csbs_spontaneity' WHERE Test_name='csbs_sponteneity';

RENAME TABLE csbs_sponteneity TO csbs_spontaneity;
