ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN first_name;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN middle_name;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN last_name;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN pupil_age_status;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN date_today;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN grade_in_school_status;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN name_address_of_school;
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN form_filled_by; 
ALTER TABLE Teachers_Report_Form_6_To_18 DROP COLUMN teacher_gender;

ALTER TABLE CBCL_6_To_18 DROP COLUMN child_age_status;
ALTER TABLE CBCL_6_To_18 DROP COLUMN grade_in_school_status;
ALTER TABLE CBCL_6_To_18 DROP COLUMN in_school;
ALTER TABLE CBCL_6_To_18 MODIFY COLUMN parent_gender enum('male','female','other') default NULL;