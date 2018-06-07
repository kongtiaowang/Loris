ALTER TABLE BRIEF2_Teacher MODIFY COLUMN student_gender enum('male','female') default NULL;
ALTER TABLE BRIEF2_Teacher DROP COLUMN how_long_have_you_known_student_status;
