-- ----------------------------------------------------------------------------
--  Modifications to the EEG questionnaire according to Redmine ticket #17618:
-- ----------------------------------------------------------------------------

UPDATE instrument_subtests SET Description = 'PARADIGM 1: Resting' WHERE Test_name = 'EEG' AND Subtest_name = 'EEG_page1' AND Description = 'EEG Net';
UPDATE instrument_subtests SET Description = 'PARADIGM 2: Visual' WHERE Test_name = 'EEG' AND Subtest_name = 'EEG_page2' AND Description = 'Paradigm 1: Resting Bubbles';
UPDATE instrument_subtests SET Description = 'PARADIGM 3: Resting' WHERE Test_name = 'EEG' AND Subtest_name = 'EEG_page3' AND Description = 'Paradigm 2: VEP';
UPDATE instrument_subtests SET Description = 'PARADIGM 4: Auditory' WHERE Test_name = 'EEG' AND Subtest_name = 'EEG_page4' AND Description = 'Paradigm 3: AEP';
UPDATE instrument_subtests SET Description = 'PARADIGM 5: Resting' WHERE Test_name = 'EEG' AND Subtest_name = 'EEG_page5' AND Description = 'Paradigm 4: Social/Non-social';
UPDATE instrument_subtests SET Description = 'General Session Notes' WHERE Test_name = 'EEG' AND Subtest_name = 'EEG_page6' AND Description = 'Overall EEG Session Information';

-- --------------------------
-- Old column not yet removed
-- --------------------------
ALTER TABLE EEG DROP COLUMN note_1_2_status;
ALTER TABLE EEG DROP COLUMN file_paradigm3;
ALTER TABLE EEG DROP COLUMN second_file_paradigm3;

ALTER TABLE EEG DROP COLUMN caregiver_role;
ALTER TABLE EEG DROP COLUMN caregiver_role_status;

ALTER TABLE EEG DROP COLUMN netting_notes;
ALTER TABLE EEG DROP COLUMN netting_notes_status;
ALTER TABLE EEG DROP COLUMN Photo_of_Net_Placement_Taken;
ALTER TABLE EEG DROP COLUMN photo_file;

-- ---------------------------
-- New columns, the execution order matters since I want to keep the #3, but change the name to #2. 
-- ---------------------------
ALTER TABLE EEG CHANGE COLUMN note_1_3 note_1_2 text;

ALTER TABLE EEG CHANGE COLUMN note_1_3_status note_1_2_status enum('not_answered');
ALTER TABLE EEG DROP COLUMN trials_completed_1;
ALTER TABLE EEG DROP COLUMN trials_completed_1_status;
ALTER TABLE EEG ADD `paradigm_completed_1` enum('y','n','p') AFTER note_1_2_status;

ALTER TABLE EEG DROP COLUMN note_2_2;
ALTER TABLE EEG DROP COLUMN note_2_2_status;
ALTER TABLE EEG CHANGE COLUMN note_2_3 note_2_2 text;
ALTER TABLE EEG CHANGE COLUMN note_2_3_status note_2_2_status enum('not_answered');

ALTER TABLE EEG DROP COLUMN quality_2;
ALTER TABLE EEG DROP COLUMN trials_completed_2;
ALTER TABLE EEG DROP COLUMN trials_completed_2_status;

ALTER TABLE EEG ADD `paradigm_completed_2` enum('y','n','p') AFTER note_2_2_status;


ALTER TABLE EEG DROP COLUMN note_3_2;
ALTER TABLE EEG DROP COLUMN note_3_2_status;
ALTER TABLE EEG CHANGE COLUMN note_3_3 note_3_2 text;
ALTER TABLE EEG CHANGE COLUMN note_3_3_status note_3_2_status enum('not_answered');

ALTER TABLE EEG DROP COLUMN quality_3;
ALTER TABLE EEG DROP COLUMN trials_completed_3;
ALTER TABLE EEG DROP COLUMN trials_completed_3_status;

ALTER TABLE EEG ADD `paradigm_completed_3` enum('y','n','p') AFTER note_3_2_status;

ALTER TABLE EEG DROP COLUMN note_4_2;
ALTER TABLE EEG DROP COLUMN note_4_2_status;
ALTER TABLE EEG CHANGE COLUMN note_4_3 note_4_2 text;
ALTER TABLE EEG CHANGE COLUMN note_4_3_status note_4_2_status enum('not_answered');

ALTER TABLE EEG DROP COLUMN quality_4;
ALTER TABLE EEG DROP COLUMN trials_completed_4;
ALTER TABLE EEG DROP COLUMN trials_completed_4_status;

ALTER TABLE EEG ADD `paradigm_completed_4` enum('y','n','p') AFTER note_4_2_status;

ALTER TABLE EEG ADD `mood_5` enum('1','2','3','4','5') AFTER note_5_2_status;
ALTER TABLE EEG ADD `paradigm_completed_5` enum('y','n','p') AFTER mood_5;


ALTER TABLE EEG ADD `note_6_1` text AFTER paradigm_completed_5;
ALTER TABLE EEG ADD `note_6_1_status` enum('not_answered') AFTER note_6_1;
ALTER TABLE EEG ADD `standard_paradigm_order` enum('y','n') AFTER note_6_1_status;
ALTER TABLE EEG ADD `note_6_2` text AFTER standard_paradigm_order;
ALTER TABLE EEG ADD `note_6_2_status` enum('not_answered') AFTER note_6_2;

