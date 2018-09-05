-- Fixing wiatIII instrument subtests; There is an unwanted space in front of subtest name currently which caused to fail the subtest to load
UPDATE `instrument_subtests` SET `Subtest_name`='wiatIII_part_1_page3' WHERE `Test_name`='wiatIII_part_1' and `Description` ='Reading Comprehension';
-- Remove old TSI from VSA battery as new SA form is getting added
UPDATE test_battery SET Active='N' WHERE  Test_name ='tsi' and Visit_label='VSA';



