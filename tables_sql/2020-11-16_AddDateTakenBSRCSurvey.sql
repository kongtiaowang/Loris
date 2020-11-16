-- --------------------------------------------------------
-- Adds the Date_taken column to the BSRC_survey table
-- --------------------------------------------------------

ALTER TABLE BSRC_survey ADD COLUMN Date_taken date DEFAULT NULL AFTER Data_entry_completion_status;
