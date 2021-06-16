
-- change gender field

ALTER TABLE caars_SelfReport_scale CHANGE gender respondent_gender enum('male','female') default NULL;
