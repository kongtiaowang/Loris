-- -------------------------------------------------------------------------------------------
-- All instruments listed in table test_names shold have column UserID. This patch adds that
-- column to the instrument tables that do not already have it
-- -------------------------------------------------------------------------------------------

ALTER TABLE acesubjectmedical_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE apsi_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE rbs_ec_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE tanner_boys_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;
ALTER TABLE tanner_girls_survey ADD COLUMN UserID VARCHAR(255) DEFAULT NULL AFTER CommentID;

