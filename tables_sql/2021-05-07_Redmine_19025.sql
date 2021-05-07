-- Redmine 19025
ALTER TABLE Seizure_Questionnaire CHANGE p1_1 p1_q1 enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_2 p1_q2 enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3a p1_q3a enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3b p1_q3b enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3c p1_q3c enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3d p1_q3d enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3e p1_q3e enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3f p1_q3f enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3g p1_q3g enum('yes','no','possible','dont_know') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3h p1_q3h enum('yes','no','possible','dont_know') default NULL;

ALTER TABLE Seizure_Questionnaire CHANGE p1_3a_notes p1_q3a_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3b_notes p1_q3b_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3c_notes p1_q3c_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3d_notes p1_q3d_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3e_notes p1_q3e_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3f_notes p1_q3f_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3g_notes p1_q3g_notes varchar(255) default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p1_3h_notes p1_q3h_notes varchar(255) default NULL;

ALTER TABLE Seizure_Questionnaire CHANGE p2_1_frequency p2_q1a_tonic_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p2_2_frequency p2_q2a_partial_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_3_frequency p2_q3a_infantile_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_4_frequency p2_q4a_generalized_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_5_frequency p2_q5a_atonic_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_6_frequency p2_q6a_absence_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_7_frequency p2_q7a_myoclonic_frequency enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL;

ALTER TABLE Seizure_Questionnaire CHANGE p2_1_period p2_q1b_tonic_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p2_2_period p2_q2b_partial_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_3_period p2_q3b_infantile_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_4_period p2_q4b_generalized_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_5_period p2_q5b_atonic_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_6_period p2_q6b_absence_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_7_period p2_q7b_myoclonic_period enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL;

ALTER TABLE Seizure_Questionnaire CHANGE p2_1_last_over_30min p2_q1_last_over_30min enum('no','yes') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p2_2_last_over_30min p2_q2_last_over_30min enum('no','yes') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_3_last_over_30min p2_q3_last_over_30min enum('no','yes') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_4_last_over_30min p2_q4_last_over_30min enum('no','yes') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_5_last_over_30min p2_q5_last_over_30min enum('no','yes') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_6_last_over_30min p2_q6_last_over_30min enum('no','yes') default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_7_last_over_30min p2_q7_last_over_30min enum('no','yes') default NULL;

ALTER TABLE Seizure_Questionnaire CHANGE p2_1_duration p2_q1c_tonic_duration text default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p2_2_duration p2_q2c_partial_duration text default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_3_duration p2_q3c_infantile_duration text default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_4_duration p2_q4c_generalized_duration text default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_5_duration p2_q5c_atonic_duration text default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_6_duration p2_q6c_absence_duration text default NULL;
ALTER TABLE Seizure_Questionnaire CHANGE p3_7_duration p2_q7c_myoclonic_duration text default NULL;