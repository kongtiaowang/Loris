-- ----------------------------------------------------------------------------
--  Modifications to the EEG questionnaire according to Redmine ticket #17524:
-- ----------------------------------------------------------------------------

ALTER TABLE EEG DROP COLUMN file_paradigm1;
ALTER TABLE EEG DROP COLUMN second_file_paradigm1;
ALTER TABLE EEG DROP COLUMN file_paradigm2;
ALTER TABLE EEG DROP COLUMN second_file_paradigm2;
ALTER TABLE EEG DROP COLUMN file_paradigm4;
ALTER TABLE EEG DROP COLUMN second_file_paradigm4;

ALTER TABLE EEG DROP COLUMN note_1_2;
ALTER TABLE EEG DROP COLUMN quality_1;
ALTER TABLE EEG DROP COLUMN overall_5;
ALTER TABLE EEG DROP COLUMN experimental_order_5;


