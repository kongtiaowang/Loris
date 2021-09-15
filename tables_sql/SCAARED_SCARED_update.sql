
-- UPDATE TABLE NAME

UPDATE test_names SET Full_name="SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Dad - Survey" WHERE Test_name = "SCAARED_Dad";
UPDATE test_names SET Full_name="SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Mom - Survey" WHERE Test_name = "SCAARED_Mom";
UPDATE test_names SET Full_name="SCAARED (Screen for Anxiety Related Disorders) - Child - Sibling - Survey" WHERE Test_name = "SCARED_Sibling";
UPDATE test_names SET Full_name="SCAARED (Screen for Anxiety Related Disorders) - Child - Subject - Survey" WHERE Test_name = "SCARED_Subject";


-- Alter table SCARED_Subject for Child

ALTER TABLE SCARED_Subject CHANGE q39_nervous_with_Subjectren_or_adults_do_something_watch_me q39_nervous_with_children_or_adults_do_something_watch_me enum('0','1','2') default NULL;


