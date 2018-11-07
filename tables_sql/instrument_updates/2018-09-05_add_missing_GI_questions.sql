-- Adding missing questions to GI instrument
ALTER TABLE UCD_Charge_GI_History ADD COLUMN how_often_have_poops enum('2_times_a_week_or_less','3_to_6_times_a_week','once_a_day','2_to_3_times_a_day','more_than_3_times_a_day','dont_know') default NULL ;
ALTER TABLE UCD_Charge_GI_History ADD COLUMN poop_usually_looks_like enum('very_hard','hard','not_too_hard','very_soft_or_mushy','watery','it_depends','dont_know') default NULL ;
ALTER TABLE UCD_Charge_GI_History ADD COLUMN how_long_hard enum('less_than_1_month','1_month','2_months','3_month_or_more','dont_know') default NULL ;
