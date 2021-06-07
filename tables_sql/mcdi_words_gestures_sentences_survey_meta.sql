-- Meta
INSERT INTO test_names(Test_name, Full_name, Sub_Group, IsDirectEntry) VALUES ('mcdi_words_gestures_sentences_survey', 'MCDI - Words, Gestures & Sentences Survey', 13, 1);

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page1', 'Part I: A1-3', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page2', 'Part I: A4-5', 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page3', 'Part I: A6-8', 3);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page4', 'Part I: A9-11', 4);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page5', 'Part I: A12-14', 5);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page6', 'Part I: A15-18', 6);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page7', 'Part I: A19-22, B', 7);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page8', 'Part II', 8);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('mcdi_words_gestures_sentences_survey', 'mcdi_words_gestures_sentences_survey_page9', 'Part III', 9);



-- Insert IBIS EP and DS-Infant for V12, V18, V24
-- EP
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 18, 'V12');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 18, 'V18');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 18, 'V24');

-- DS-Infant

INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 20, 'V12');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 20, 'V18');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 20, 'V24');

INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 23, 'V12');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 23, 'V18');
INSERT INTO survey_test_battery (Test_name, Active, SubprojectID, Visit_label) VALUES ('mcdi_words_gestures_sentences_survey', DEFAULT, 23, 'V24');


