ALTER TABLE ADULT_SELF_REPORT_DAD ADD COLUMN respondent enum("yes","no") default NULL;

ALTER TABLE ADULT_SELF_REPORT_MOM ADD COLUMN respondent enum("yes","no") default NULL;

ALTER TABLE SRS2_InformantReport_Dad_On_Mom ADD COLUMN respondent enum("yes","no") default NULL;

ALTER TABLE SRS2_InformantReport_Mom_On_Dad ADD COLUMN respondent enum("yes","no") default NULL;

ALTER TABLE SRS2_SchoolAge ADD COLUMN respondent enum("yes","no") default NULL;

ALTER TABLE SRS2_SelfReport_Dad ADD COLUMN respondent enum("yes","no") default NULL;

ALTER TABLE SRS2_SelfReport_Mom ADD COLUMN respondent enum("yes","no") default NULL;

-- Modify tables to map old value to new value

ALTER TABLE caars_SelfReport_dad CHANGE COLUMN respondent respondent enum('mother','father','step_mother','step_father','other','yes','no') default NULL;
UPDATE caars_SelfReport_dad SET respondent = "no" WHERE respondent <> "father";
UPDATE caars_SelfReport_dad SET respondent = "yes" WHERE respondent = "father";
ALTER TABLE caars_SelfReport_dad CHANGE COLUMN respondent respondent enum("yes","no") default NULL;

ALTER TABLE caars_SelfReport_mom CHANGE COLUMN respondent respondent enum('mother','father','step_mother','step_father','other','yes','no') default NULL;
UPDATE caars_SelfReport_mom SET respondent = "no" WHERE respondent <> "mother";
UPDATE caars_SelfReport_mom SET respondent = "yes" WHERE respondent = "mother";
ALTER TABLE caars_SelfReport_mom CHANGE COLUMN respondent respondent enum("yes","no") default NULL;

ALTER TABLE pspq_SelfReport_dad CHANGE COLUMN respondent respondent enum('mother','father','stepmother','stepfather','other','yes','no') default NULL;
UPDATE pspq_SelfReport_dad SET respondent = "no" WHERE respondent <> "father";
UPDATE pspq_SelfReport_dad SET respondent = "yes" WHERE respondent = "father";
ALTER TABLE pspq_SelfReport_dad CHANGE COLUMN respondent respondent enum("yes","no") default NULL;

ALTER TABLE pspq_SelfReport_mom CHANGE COLUMN respondent respondent enum('mother','father','stepmother','stepfather','other','yes','no') default NULL;
UPDATE pspq_SelfReport_mom SET respondent = "no" WHERE respondent <> "mother";
UPDATE pspq_SelfReport_mom SET respondent = "yes" WHERE respondent = "mother";
ALTER TABLE pspq_SelfReport_mom CHANGE COLUMN respondent respondent enum("yes","no") default NULL;

