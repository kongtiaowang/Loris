ALTER TABLE macarthur_words_gestures ADD COLUMN phrases_understood_number integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN phrases_understood_percentile integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN words_produced_number integer(3) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN words_produced_percentile integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN words_understood_number integer(3) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN words_understood_percentile integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN early_gestures_number integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN early_gestures_percentile integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN later_gestures_number integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN later_gestures_percentile integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN total_gestures_number integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN total_gestures_percentile integer(2) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN I_C_1_score varchar(255) NULL;
ALTER TABLE macarthur_words_gestures ADD COLUMN I_C_2_score varchar(255) NULL;