-- Adding missing clock question to CSHQ
ALTER TABLE CSHQ ADD COLUMN wakes_up_with_alarm_clock enum('1','0','n/a') default NULL;
-- Adding missed enum values for SSIS teacher
ALTER TABLE SSIS_Teacher MODIFY COLUMN q77_overall_performance ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
ALTER TABLE SSIS_Teacher MODIFY COLUMN q78_reading_other_students ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
ALTER TABLE SSIS_Teacher MODIFY COLUMN q79_math_other_students ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
ALTER TABLE SSIS_Teacher MODIFY COLUMN q80_reading_grade_level ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
ALTER TABLE SSIS_Teacher MODIFY COLUMN q81_math_grade_level ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
ALTER TABLE SSIS_Teacher MODIFY COLUMN q82_motivation ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
ALTER TABLE SSIS_Teacher MODIFY COLUMN q83_intellect ENUM('N_never','S_sometimes','O_often','A_almost_always', 'not_answered',
'1_lowest_10%','2_next_lowest_20%','3_middle_40%','4_next_highest_20%','5_highest_10%') default NULL ;
