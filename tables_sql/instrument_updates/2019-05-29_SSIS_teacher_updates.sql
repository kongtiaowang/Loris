-- Fixing the wrong enum values added to student_sex
ALTER TABLE SSIS_Teacher MODIFY COLUMN student_sex ENUM('male','female', 'not_answered') default NULL ;