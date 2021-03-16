ALTER TABLE CCC2 ADD COLUMN A_speech_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN B_syntax_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN C_semantics_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN D_coherence_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN E_initiation_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN F_scripted_language_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN G_context_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN H_nonverbal_communication_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN I_social_relations_total_raw_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN J_interests_total_raw_score varchar(50) default NULL;


ALTER TABLE CCC2 ADD COLUMN A_speech_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN B_syntax_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN C_semantics_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN D_coherence_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN E_initiation_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN F_scripted_language_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN G_context_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN H_nonverbal_communication_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN I_social_relations_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN J_interests_scaled_score varchar(50) default NULL;


ALTER TABLE CCC2 ADD COLUMN A_speech_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN B_syntax_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN C_semantics_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN D_coherence_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN E_initiation_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN F_scripted_language_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN G_context_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN H_nonverbal_communication_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN I_social_relations_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN J_interests_percentile varchar(50) default NULL;

ALTER TABLE CCC2 ADD COLUMN SIDI_scaled_score varchar(50) default NULL;


ALTER TABLE CCC2 ADD COLUMN GCC_scaled_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN GCC_composite_score varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN GCC_percentile varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN GCC_90_percentage_CI varchar(50) default NULL;
ALTER TABLE CCC2 ADD COLUMN GCC_95_percentage_CI varchar(50) default NULL;
