-- Adding missing questions to DSMV_checklist
ALTER TABLE vrRSB_survey ADD COLUMN q0_hear_video enum('0','1') default NULL ;
ALTER TABLE vrRSB_survey ADD COLUMN q49_status varchar (100) default NULL ;
ALTER TABLE vrRSB_survey ADD COLUMN q50_status varchar (100) default NULL ;
UPDATE test_names SET Full_name='vrRSB (Video Referenced Ratings of Reciprocal Social Behavior) - Survey'
where test_name='vrRSB_survey';
