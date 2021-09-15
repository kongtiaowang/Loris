ALTER TABLE pspq_InformantReport_mom_on_dad MODIFY COLUMN `qi4_hard_avoid_sidetrack` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_InformantReport_mom_on_dad MODIFY COLUMN `qi25_connecting_people` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_InformantReport_mom_on_dad MODIFY COLUMN `qi29_longpauses_conversations` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;

ALTER TABLE pspq_InformantReport_dad_on_mom MODIFY COLUMN `qi4_hard_avoid_sidetrack` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_InformantReport_dad_on_mom MODIFY COLUMN `qi25_connecting_people` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_InformantReport_dad_on_mom MODIFY COLUMN `qi29_longpauses_conversations` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;

ALTER TABLE pspq_SelfReport_mom MODIFY COLUMN `q4_hard_avoid_sidetrack` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_SelfReport_mom MODIFY COLUMN `q25_connecting_people` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_SelfReport_mom MODIFY COLUMN `q29_longpauses_conversations` enum('1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;