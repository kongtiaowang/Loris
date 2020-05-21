-- Redmine 17858
ALTER TABLE pspq_2 MODIFY COLUMN q4_hard_avoid_sidetrack ENUM('','1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_2 MODIFY COLUMN q25_connecting_people ENUM('','1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;
ALTER TABLE pspq_2 MODIFY COLUMN q29_longpauses_conversations ENUM('','1_very_rarely','2_rarely','3_occasionally','4_somewhat_often','5_often','6_very_often','na') default NULL;


-- Redmine 17895
UPDATE participant_accounts SET Email='decarver@gmail.com' where Email='kellymcarver@gmail.com'
and CommentID IN ('490324SEA0186609631311569532113', '490324SEA0186609631331569532158','490324SEA0186609631391569532221','490324SEA0186609631371569532236')
and Test_name IN ('ABCL_DAD_ON_MOM', 'ADULT_SELF_REPORT_DAD','SRS2_SelfReport_Dad','SRS2_InformantReport_Dad_On_Mom');