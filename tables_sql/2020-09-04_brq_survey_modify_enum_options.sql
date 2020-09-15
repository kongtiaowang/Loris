ALTER TABLE BRQ_survey MODIFY COLUMN q11_perform_the_same_activities_in_the_hour_before_bed enum('1_almost_never','2_occasionally','3_half_the_time','4_often','5_nearly_always', '1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q12_perform_activities_in_the_same_order_before_going_to_bed enum('1_almost_never','2_occasionally','3_half_the_time','4_often','5_nearly_always', '1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q13_sleep_in_the_same_place enum('1_almost_never','2_occasionally','3_half_the_time','4_often','5_nearly_always', '1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q14_go_to_bed_at_the_same_time enum('1_almost_never','2_occasionally','3_half_the_time','4_often','5_nearly_always', '1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q15_get_put_to_bed_by_the_same_person enum('1_almost_never','2_occasionally','3_half_the_time','4_often','5_nearly_always', '1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;

UPDATE BRQ_survey SET q11_perform_the_same_activities_in_the_hour_before_bed = CASE
    WHEN q11_perform_the_same_activities_in_the_hour_before_bed = '1_almost_never' THEN '1_not_at_all'
    WHEN q11_perform_the_same_activities_in_the_hour_before_bed = '2_occasionally' THEN '2_a_little'
    WHEN q11_perform_the_same_activities_in_the_hour_before_bed = '3_half_the_time' THEN '3_moderately'
    WHEN q11_perform_the_same_activities_in_the_hour_before_bed = '4_often' THEN '4_quite_a_bit'
    WHEN q11_perform_the_same_activities_in_the_hour_before_bed = '5_nearly_always' THEN '5_extremely'
    END
WHERE q11_perform_the_same_activities_in_the_hour_before_bed in ('1_almost_never', '2_occasionally', '3_half_the_time', '4_often', '5_nearly_always');

UPDATE BRQ_survey SET q12_perform_activities_in_the_same_order_before_going_to_bed = CASE
    WHEN q12_perform_activities_in_the_same_order_before_going_to_bed = '1_almost_never' THEN '1_not_at_all'
    WHEN q12_perform_activities_in_the_same_order_before_going_to_bed = '2_occasionally' THEN '2_a_little'
    WHEN q12_perform_activities_in_the_same_order_before_going_to_bed = '3_half_the_time' THEN '3_moderately'
    WHEN q12_perform_activities_in_the_same_order_before_going_to_bed = '4_often' THEN '4_quite_a_bit'
    WHEN q12_perform_activities_in_the_same_order_before_going_to_bed = '5_nearly_always' THEN '5_extremely'
    END
WHERE q12_perform_activities_in_the_same_order_before_going_to_bed in ('1_almost_never', '2_occasionally', '3_half_the_time', '4_often', '5_nearly_always');

UPDATE BRQ_survey SET q13_sleep_in_the_same_place = CASE
    WHEN q13_sleep_in_the_same_place = '1_almost_never' THEN '1_not_at_all'
    WHEN q13_sleep_in_the_same_place = '2_occasionally' THEN '2_a_little'
    WHEN q13_sleep_in_the_same_place = '3_half_the_time' THEN '3_moderately'
    WHEN q13_sleep_in_the_same_place = '4_often' THEN '4_quite_a_bit'
    WHEN q13_sleep_in_the_same_place = '5_nearly_always' THEN '5_extremely'
    END
WHERE q13_sleep_in_the_same_place in ('1_almost_never', '2_occasionally', '3_half_the_time', '4_often', '5_nearly_always');

UPDATE BRQ_survey SET q14_go_to_bed_at_the_same_time = CASE
    WHEN q14_go_to_bed_at_the_same_time = '1_almost_never' THEN '1_not_at_all'
    WHEN q14_go_to_bed_at_the_same_time = '2_occasionally' THEN '2_a_little'
    WHEN q14_go_to_bed_at_the_same_time = '3_half_the_time' THEN '3_moderately'
    WHEN q14_go_to_bed_at_the_same_time = '4_often' THEN '4_quite_a_bit'
    WHEN q14_go_to_bed_at_the_same_time = '5_nearly_always' THEN '5_extremely'
    END
WHERE q14_go_to_bed_at_the_same_time in ('1_almost_never', '2_occasionally', '3_half_the_time', '4_often', '5_nearly_always');

UPDATE BRQ_survey SET q15_get_put_to_bed_by_the_same_person = CASE
    WHEN q15_get_put_to_bed_by_the_same_person = '1_almost_never' THEN '1_not_at_all'
    WHEN q15_get_put_to_bed_by_the_same_person = '2_occasionally' THEN '2_a_little'
    WHEN q15_get_put_to_bed_by_the_same_person = '3_half_the_time' THEN '3_moderately'
    WHEN q15_get_put_to_bed_by_the_same_person = '4_often' THEN '4_quite_a_bit'
    WHEN q15_get_put_to_bed_by_the_same_person = '5_nearly_always' THEN '5_extremely'
    END
WHERE q15_get_put_to_bed_by_the_same_person in ('1_almost_never', '2_occasionally', '3_half_the_time', '4_often', '5_nearly_always');

ALTER TABLE BRQ_survey MODIFY COLUMN q11_perform_the_same_activities_in_the_hour_before_bed enum('1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q12_perform_activities_in_the_same_order_before_going_to_bed enum('1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q13_sleep_in_the_same_place enum('1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q14_go_to_bed_at_the_same_time enum('1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;
ALTER TABLE BRQ_survey MODIFY COLUMN q15_get_put_to_bed_by_the_same_person enum('1_not_at_all','2_a_little','3_moderately','4_quite_a_bit','5_extremely') default NULL;

ALTER TABLE `BRQ_survey` CHANGE `q6_q11_perform_the_same_activities_in_the_hour_before_bed` `q6_perform_the_same_activities_in_the_hour_before_bed` enum('1_almost_never','2_occasionally','3_half_the_time','4_often','5_nearly_always') default NULL;