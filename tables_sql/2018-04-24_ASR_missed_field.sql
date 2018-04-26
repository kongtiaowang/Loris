-- Adding missed field in ASR instrument
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN q_40_description varchar (255) default NULL AFTER question_40;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN q_40_description_status enum ('not_answered') default NULL AFTER q_40_description;

ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_a enum('not_true','sometimes','very_true') default NULL AFTER question_55;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_b enum('not_true','sometimes','very_true') default NULL AFTER question_56_a;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_c enum('not_true','sometimes','very_true') default NULL AFTER question_56_b;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_d enum('not_true','sometimes','very_true') default NULL AFTER question_56_c;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN q_56_d_description varchar(255) default NULL AFTER question_56_d;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN q_56_d_description_status enum('not_answered') default NULL AFTER q_56_description;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_e enum('not_true','sometimes','very_true') default NULL AFTER question_56_d;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_f enum('not_true','sometimes','very_true') default NULL AFTER question_56_e;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_g enum('not_true','sometimes','very_true') default NULL AFTER question_56_f;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_h enum('not_true','sometimes','very_true') default NULL AFTER question_56_g;
ALTER TABLE ADULT_SELF_REPORT ADD COLUMN question_56_i enum('not_true','sometimes','very_true') default NULL AFTER question_56_h;
