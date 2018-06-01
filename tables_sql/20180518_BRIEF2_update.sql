ALTER TABLE BRIEF2_Parent DROP COLUMN childs_name;
ALTER TABLE BRIEF2_Parent MODIFY COLUMN childs_gender enum('male','female') default NULL;
ALTER TABLE BRIEF2_Parent DROP COLUMN childs_age_status;
ALTER TABLE BRIEF2_Parent DROP COLUMN childs_grade_status;
ALTER TABLE BRIEF2_Parent DROP COLUMN rater_name;
ALTER TABLE BRIEF2_Parent DROP COLUMN date_today;

ALTER TABLE BRIEF2_Teacher DROP COLUMN date_today;
ALTER TABLE BRIEF2_Teacher DROP COLUMN student_name;
ALTER TABLE BRIEF2_Teacher DROP COLUMN student_age_status;
ALTER TABLE BRIEF2_Teacher DROP COLUMN student_grade_status;
ALTER TABLE BRIEF2_Teacher DROP COLUMN rater_name;