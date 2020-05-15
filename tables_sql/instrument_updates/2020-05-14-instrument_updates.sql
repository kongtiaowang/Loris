-- Redmine 17859
UPDATE conners_parent SET q33=NULL,q41=NULL where CommentID='232791SEA007958671991547070720';

-- Redmine 17858
ALTER TABLE conners_parent MODIFY COLUMN q11 ENUM('','0','1','2','3','not_applicable') default NULL;
ALTER TABLE conners_parent MODIFY COLUMN q42 ENUM('','0','1','2','3','not_applicable') default NULL;

ALTER TABLE CSHQ MODIFY COLUMN sleeps_same_amount_each_day_item11_frequency enum('','3','2','1','na') default NULL;

ALTER TABLE QRS MODIFY COLUMN q13 ENUM('','1','2','3','4','na') default NULL;
ALTER TABLE QRS MODIFY COLUMN q59 ENUM('','1','2','3','4','na') default NULL;

ALTER TABLE pspq_SelfReport_dad MODIFY COLUMN q4_hard_avoid_sidetrack ENUM('','1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_SelfReport_dad MODIFY COLUMN q25_connecting_people ENUM('','1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_SelfReport_dad MODIFY COLUMN q29_longpauses_conversations ENUM('','1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;


