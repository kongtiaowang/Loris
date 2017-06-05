-- Missing columns
ALTER TABLE bapq_informant ADD `comments` text;
ALTER TABLE bapq_respondent ADD `comments` text;
-- No flag entry exists for those miss-named instruments.
UPDATE test_battery SET Active='N' WHERE Test_name='head_measurement_proband';
UPDATE test_battery SET Active='N' WHERE Test_name='head_measurement_subject';
UPDATE test_battery SET Active='N' WHERE Test_name='neuroscreen';

