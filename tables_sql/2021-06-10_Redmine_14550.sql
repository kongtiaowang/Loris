-- Redmine 14550
-- Add scoring columns to SSIS_Teacher

ALTER TABLE SSIS_Teacher ADD `social_skills_num_missing` varchar(128) default NULL AFTER `Date_taken`;
ALTER TABLE SSIS_Teacher ADD `social_skills_adjustment_value` varchar(128) default NULL AFTER `social_skills_num_missing`;
ALTER TABLE SSIS_Teacher ADD `social_skills_sum` varchar(128) default NULL AFTER `social_skills_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `social_skills_raw_score` varchar(128) default NULL AFTER `social_skills_sum`;
ALTER TABLE SSIS_Teacher ADD `social_skills_standard_score` varchar(128) default NULL AFTER `social_skills_raw_score`;
ALTER TABLE SSIS_Teacher ADD `social_skills_percentile` varchar(128) default NULL AFTER `social_skills_standard_score`;
ALTER TABLE SSIS_Teacher ADD `social_skills_ci_68` varchar(128) default NULL AFTER `social_skills_percentile`;
ALTER TABLE SSIS_Teacher ADD `social_skills_ci_95` varchar(128) default NULL AFTER `social_skills_ci_68`;
ALTER TABLE SSIS_Teacher ADD `communication_num_missing` varchar(128) default NULL AFTER `social_skills_ci_95`;
ALTER TABLE SSIS_Teacher ADD `communication_adjustment_value` varchar(128) default NULL AFTER `communication_num_missing`;
ALTER TABLE SSIS_Teacher ADD `communication_sum` varchar(128) default NULL AFTER `communication_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `communication_raw_score` varchar(128) default NULL AFTER `communication_sum`;
ALTER TABLE SSIS_Teacher ADD `communication_behavior_level` varchar(128) default NULL AFTER `communication_raw_score`;
ALTER TABLE SSIS_Teacher ADD `cooperation_num_missing` varchar(128) default NULL AFTER `communication_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `cooperation_adjustment_value` varchar(128) default NULL AFTER `cooperation_num_missing`;
ALTER TABLE SSIS_Teacher ADD `cooperation_sum` varchar(128) default NULL AFTER `cooperation_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `cooperation_raw_score` varchar(128) default NULL AFTER `cooperation_sum`;
ALTER TABLE SSIS_Teacher ADD `cooperation_behavior_level` varchar(128) default NULL AFTER `cooperation_raw_score`;
ALTER TABLE SSIS_Teacher ADD `assertion_num_missing` varchar(128) default NULL AFTER `cooperation_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `assertion_adjustment_value` varchar(128) default NULL AFTER `assertion_num_missing`;
ALTER TABLE SSIS_Teacher ADD `assertion_sum` varchar(128) default NULL AFTER `assertion_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `assertion_raw_score` varchar(128) default NULL AFTER `assertion_sum`;
ALTER TABLE SSIS_Teacher ADD `assertion_behavior_level` varchar(128) default NULL AFTER `assertion_raw_score`;
ALTER TABLE SSIS_Teacher ADD `responsibility_num_missing` varchar(128) default NULL AFTER `assertion_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `responsibility_adjustment_value` varchar(128) default NULL AFTER `responsibility_num_missing`;
ALTER TABLE SSIS_Teacher ADD `responsibility_sum` varchar(128) default NULL AFTER `responsibility_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `responsibility_raw_score` varchar(128) default NULL AFTER `responsibility_sum`;
ALTER TABLE SSIS_Teacher ADD `responsibility_behavior_level` varchar(128) default NULL AFTER `responsibility_raw_score`;
ALTER TABLE SSIS_Teacher ADD `empathy_num_missing` varchar(128) default NULL AFTER `responsibility_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `empathy_adjustment_value` varchar(128) default NULL AFTER `empathy_num_missing`;
ALTER TABLE SSIS_Teacher ADD `empathy_sum` varchar(128) default NULL AFTER `empathy_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `empathy_raw_score` varchar(128) default NULL AFTER `empathy_sum`;
ALTER TABLE SSIS_Teacher ADD `empathy_behavior_level` varchar(128) default NULL AFTER `empathy_raw_score`;
ALTER TABLE SSIS_Teacher ADD `engagement_num_missing` varchar(128) default NULL AFTER `empathy_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `engagement_adjustment_value` varchar(128) default NULL AFTER `engagement_num_missing`;
ALTER TABLE SSIS_Teacher ADD `engagement_sum` varchar(128) default NULL AFTER `engagement_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `engagement_raw_score` varchar(128) default NULL AFTER `engagement_sum`;
ALTER TABLE SSIS_Teacher ADD `engagement_behavior_level` varchar(128) default NULL AFTER `engagement_raw_score`;
ALTER TABLE SSIS_Teacher ADD `self_control_num_missing` varchar(128) default NULL AFTER `engagement_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `self_control_adjustment_value` varchar(128) default NULL AFTER `self_control_num_missing`;
ALTER TABLE SSIS_Teacher ADD `self_control_sum` varchar(128) default NULL AFTER `self_control_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `self_control_raw_score` varchar(128) default NULL AFTER `self_control_sum`;
ALTER TABLE SSIS_Teacher ADD `self_control_behavior_level` varchar(128) default NULL AFTER `self_control_raw_score`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_num_missing` varchar(128) default NULL AFTER `self_control_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_adjustment_value` varchar(128) default NULL AFTER `problem_behaviors_num_missing`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_sum` varchar(128) default NULL AFTER `problem_behaviors_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_raw_score` varchar(128) default NULL AFTER `problem_behaviors_sum`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_standard_score` varchar(128) default NULL AFTER `problem_behaviors_raw_score`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_percentile` varchar(128) default NULL AFTER `problem_behaviors_standard_score`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_ci_68` varchar(128) default NULL AFTER `problem_behaviors_percentile`;
ALTER TABLE SSIS_Teacher ADD `problem_behaviors_ci_95` varchar(128) default NULL AFTER `problem_behaviors_ci_68`;
ALTER TABLE SSIS_Teacher ADD `externalizing_num_missing` varchar(128) default NULL AFTER `problem_behaviors_ci_95`;
ALTER TABLE SSIS_Teacher ADD `externalizing_adjustment_value` varchar(128) default NULL AFTER `externalizing_num_missing`;
ALTER TABLE SSIS_Teacher ADD `externalizing_sum` varchar(128) default NULL AFTER `externalizing_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `externalizing_raw_score` varchar(128) default NULL AFTER `externalizing_sum`;
ALTER TABLE SSIS_Teacher ADD `externalizing_behavior_level` varchar(128) default NULL AFTER `externalizing_raw_score`;
ALTER TABLE SSIS_Teacher ADD `bullying_num_missing` varchar(128) default NULL AFTER `externalizing_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `bullying_adjustment_value` varchar(128) default NULL AFTER `bullying_num_missing`;
ALTER TABLE SSIS_Teacher ADD `bullying_sum` varchar(128) default NULL AFTER `bullying_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `bullying_raw_score` varchar(128) default NULL AFTER `bullying_sum`;
ALTER TABLE SSIS_Teacher ADD `bullying_behavior_level` varchar(128) default NULL AFTER `bullying_raw_score`;
ALTER TABLE SSIS_Teacher ADD `hyperactivity_inattention_num_missing` varchar(128) default NULL AFTER `bullying_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `hyperactivity_inattention_adjustment_value` varchar(128) default NULL AFTER `hyperactivity_inattention_num_missing`;
ALTER TABLE SSIS_Teacher ADD `hyperactivity_inattention_sum` varchar(128) default NULL AFTER `hyperactivity_inattention_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `hyperactivity_inattention_raw_score` varchar(128) default NULL AFTER `hyperactivity_inattention_sum`;
ALTER TABLE SSIS_Teacher ADD `hyperactivity_inattention_behavior_level` varchar(128) default NULL AFTER `hyperactivity_inattention_raw_score`;
ALTER TABLE SSIS_Teacher ADD `internalizing_num_missing` varchar(128) default NULL AFTER `hyperactivity_inattention_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `internalizing_adjustment_value` varchar(128) default NULL AFTER `internalizing_num_missing`;
ALTER TABLE SSIS_Teacher ADD `internalizing_sum` varchar(128) default NULL AFTER `internalizing_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `internalizing_raw_score` varchar(128) default NULL AFTER `internalizing_sum`;
ALTER TABLE SSIS_Teacher ADD `internalizing_behavior_level` varchar(128) default NULL AFTER `internalizing_raw_score`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_A_num_missing` varchar(128) default NULL AFTER `internalizing_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_A_adjustment_value` varchar(128) default NULL AFTER `autism_spectrum_A_num_missing`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_A_sum` varchar(128) default NULL AFTER `autism_spectrum_A_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_A_raw_score` varchar(128) default NULL AFTER `autism_spectrum_A_sum`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_A_behavior_level` varchar(128) default NULL AFTER `autism_spectrum_A_raw_score`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_B_num_missing` varchar(128) default NULL AFTER `autism_spectrum_A_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_B_adjustment_value` varchar(128) default NULL AFTER `autism_spectrum_B_num_missing`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_B_sum` varchar(128) default NULL AFTER `autism_spectrum_B_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_B_raw_score` varchar(128) default NULL AFTER `autism_spectrum_B_sum`;
ALTER TABLE SSIS_Teacher ADD `autism_spectrum_B_behavior_level` varchar(128) default NULL AFTER `autism_spectrum_B_raw_score`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_num_missing` varchar(128) default NULL AFTER `autism_spectrum_B_behavior_level`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_adjustment_value` varchar(128) default NULL AFTER `academic_competence_num_missing`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_sum` varchar(128) default NULL AFTER `academic_competence_adjustment_value`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_raw_score` varchar(128) default NULL AFTER `academic_competence_sum`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_standard_score` varchar(128) default NULL AFTER `academic_competence_raw_score`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_percentile` varchar(128) default NULL AFTER `academic_competence_standard_score`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_ci_68` varchar(128) default NULL AFTER `academic_competence_percentile`;
ALTER TABLE SSIS_Teacher ADD `academic_competence_ci_95` varchar(128) default NULL AFTER `academic_competence_ci_68`;
ALTER TABLE SSIS_Teacher ADD `f_index` varchar(128) default NULL AFTER `academic_competence_ci_95`;
ALTER TABLE SSIS_Teacher ADD `f_index_interpretation` varchar(128) default NULL AFTER `f_index`;