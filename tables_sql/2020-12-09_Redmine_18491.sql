ALTER TABLE mcdi_words_gestures_sentences_survey ADD `words_produced_number` int(5) default NULL AFTER `other_relationship_to_child`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `words_produced_percentile` varchar(255) default NULL AFTER `words_produced_number`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `early_gestures_number` int(5) default NULL AFTER `words_produced_percentile`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `early_gestures_percentile` varchar(255) default NULL AFTER `early_gestures_number`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `later_gestures_number` int(5) default NULL AFTER `early_gestures_percentile`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `later_gestures_percentile` varchar(255) default NULL AFTER `later_gestures_number`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `total_gestures_number` int(5) default NULL AFTER `later_gestures_percentile`;
ALTER TABLE mcdi_words_gestures_sentences_survey ADD `total_gestures_percentile` varchar(255) default NULL AFTER `total_gestures_number`;