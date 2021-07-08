UPDATE test_names SET Full_name="SCARED (Screen for Anxiety Related Disorders) - Child - Sibling - Survey" WHERE Test_name = "SCARED_Sibling";
UPDATE test_names SET Full_name="SCARED (Screen for Anxiety Related Disorders) - Child - Subject - Survey" WHERE Test_name = "SCARED_Subject";

ALTER TABLE SCARED_Parent_Sibling ADD COLUMN Candidate_Age varchar(255) default NULL AFTER Date_taken;
ALTER TABLE SCARED_Parent_Sibling ADD COLUMN Window_Difference varchar(255) default NULL AFTER Candidate_Age;
ALTER TABLE SCARED_Parent_Subject ADD COLUMN Candidate_Age varchar(255) default NULL AFTER Date_taken;
ALTER TABLE SCARED_Parent_Subject ADD COLUMN Window_Difference varchar(255) default NULL AFTER Candidate_Age;
ALTER TABLE SCARED_Sibling ADD COLUMN Candidate_Age varchar(255) default NULL AFTER Date_taken;
ALTER TABLE SCARED_Sibling ADD COLUMN Window_Difference varchar(255) default NULL AFTER Candidate_Age;

