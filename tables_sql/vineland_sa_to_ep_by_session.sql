UPDATE  flag f
JOIN Vineland_EP ep ON (ep.CommentID=f.CommentID AND f.CommentID NOT LIKE 'DDE%' AND f.test_name='Vineland_EP') 
JOIN session s   ON(s.ID=f.sessionID) 
JOIN flag f2 on (s.ID=f2.sessionID AND f2.CommentID NOT LIKE 'DDE%' AND f2.test_name='Vineland_SA')
JOIN Vineland_SA ON (f2.CommentID=Vineland_SA.CommentID)
SET 
f.Data_entry=f2.Data_entry,
f.Administration=f2.Administration
Where 
    ep.File_name IS NULL;


UPDATE Vineland_EP ep 
JOIN flag f ON (ep.CommentID=f.CommentID AND f.CommentID NOT LIKE 'DDE%' AND f.test_name='Vineland_EP') 
JOIN session s   ON(s.ID=f.sessionID) 
JOIN flag f2 on (s.ID=f2.sessionID AND f2.CommentID NOT LIKE 'DDE%' AND f2.test_name='Vineland_SA')
JOIN Vineland_SA ON (f2.CommentID=Vineland_SA.CommentID)
SET 

ep.UserID=Vineland_SA.UserID,
ep.Examiner=Vineland_SA.Examiner,
ep.Testdate=Vineland_SA.Testdate,
ep.Data_entry_completion_status=Vineland_SA.Data_entry_completion_status,
ep.Date_taken=Vineland_SA.Date_taken,
ep.Candidate_Age=Vineland_SA.Candidate_Age,
ep.Window_Difference=Vineland_SA.Window_Difference,
ep.File_name=Vineland_SA.File_name,
ep.File_type=Vineland_SA.File_type,
ep.Status=Vineland_SA.Status,
ep.Data_dir=Vineland_SA.Data_dir,
ep.adapt_behave_comp_STD_SCORE=Vineland_SA.adapt_behave_comp_STD_SCORE,
ep.adapt_behave_comp_90_CI=Vineland_SA.adapt_behave_comp_90_CI,
ep.adapt_behave_comp_PERCENTILE=Vineland_SA.adapt_behave_comp_PERCENTILE,
ep.adapt_behave_comp_SS_Minus_Mean_SS=Vineland_SA.adapt_behave_comp_SS_Minus_Mean_SS,
ep.adapt_behave_comp_strength_weakness=Vineland_SA.adapt_behave_comp_strength_weakness,
ep.adapt_behave_comp_base_rate=Vineland_SA.adapt_behave_comp_base_rate,
ep.communication_STD_SCORE=Vineland_SA.communication_STD_SCORE,
ep.communication_90_CI=Vineland_SA.communication_90_CI,
ep.communication_PERCENTILE=Vineland_SA.communication_PERCENTILE,
ep.communication_SS_Minus_Mean_SS=Vineland_SA.communication_SS_Minus_Mean_SS,
ep.communication_strength_weakness=Vineland_SA.communication_strength_weakness,
ep.communication_base_rate=Vineland_SA.communication_base_rate,
ep.daily_living_skills_STD_SCORE=Vineland_SA.daily_living_skills_STD_SCORE,
ep.daily_living_skills_90_CI=Vineland_SA.daily_living_skills_90_CI,
ep.daily_living_skills_PERCENTILE=Vineland_SA.daily_living_skills_PERCENTILE,
ep.daily_living_skills_SS_Minus_Mean_SS=Vineland_SA.daily_living_skills_SS_Minus_Mean_SS,
ep.daily_living_skills_strength_weakness=Vineland_SA.daily_living_skills_strength_weakness,
ep.daily_living_skills_base_rate=Vineland_SA.daily_living_skills_base_rate,
ep.socialization_STD_SCORE=Vineland_SA.socialization_STD_SCORE,
ep.socialization_90_CI=Vineland_SA.socialization_90_CI,
ep.socialization_PERCENTILE=Vineland_SA.socialization_PERCENTILE,
ep.socialization_SS_Minus_Mean_SS=Vineland_SA.socialization_SS_Minus_Mean_SS,
ep.socialization_strength_weakness=Vineland_SA.socialization_strength_weakness,
ep.socialization_base_rate=Vineland_SA.socialization_base_rate,
ep.motor_skills_STD_SCORE=Vineland_SA.motor_skills_STD_SCORE,
ep.motor_skills_90_CI=Vineland_SA.motor_skills_90_CI,
ep.motor_skills_PERCENTILE=Vineland_SA.motor_skills_PERCENTILE,
ep.motor_skills_SS_Minus_Mean_SS=Vineland_SA.motor_skills_SS_Minus_Mean_SS,
ep.motor_skills_strength_weakness=Vineland_SA.motor_skills_strength_weakness,
ep.motor_skills_base_rate=Vineland_SA.motor_skills_base_rate,
ep.receptive_RAW_SCORE=Vineland_SA.receptive_RAW_SCORE,
ep.receptive_v_Scale_Score=Vineland_SA.receptive_v_Scale_Score,
ep.receptive_age_equiv=Vineland_SA.receptive_age_equiv,
ep.receptive_growth_scale_value=Vineland_SA.receptive_growth_scale_value,
ep.receptive_percent_estimated=Vineland_SA.receptive_percent_estimated,
ep.receptive_vs_minus_mean_vs=Vineland_SA.receptive_vs_minus_mean_vs,
ep.receptive_strength_weakness=Vineland_SA.receptive_strength_weakness,
ep.receptive_base_rate=Vineland_SA.receptive_base_rate,
ep.expressive_RAW_SCORE=Vineland_SA.expressive_RAW_SCORE,
ep.expressive_v_Scale_Score=Vineland_SA.expressive_v_Scale_Score,
ep.expressive_age_equiv=Vineland_SA.expressive_age_equiv,
ep.expressive_growth_scale_value=Vineland_SA.expressive_growth_scale_value,
ep.expressive_percent_estimated=Vineland_SA.expressive_percent_estimated,
ep.expressive_vs_minus_mean_vs=Vineland_SA.expressive_vs_minus_mean_vs,
ep.expressive_strength_weakness=Vineland_SA.expressive_strength_weakness,
ep.expressive_base_rate=Vineland_SA.expressive_base_rate,
ep.written_RAW_SCORE=Vineland_SA.written_RAW_SCORE,
ep.written_v_Scale_Score=Vineland_SA.written_v_Scale_Score,
ep.written_age_equiv=Vineland_SA.written_age_equiv,
ep.written_growth_scale_value=Vineland_SA.written_growth_scale_value,
ep.written_percent_estimated=Vineland_SA.written_percent_estimated,
ep.written_vs_minus_mean_vs=Vineland_SA.written_vs_minus_mean_vs,
ep.written_strength_weakness=Vineland_SA.written_strength_weakness,
ep.written_base_rate=Vineland_SA.written_base_rate,
ep.personal_RAW_SCORE=Vineland_SA.personal_RAW_SCORE,
ep.personal_v_Scale_Score=Vineland_SA.personal_v_Scale_Score,
ep.personal_age_equiv=Vineland_SA.personal_age_equiv,
ep.personal_growth_scale_value=Vineland_SA.personal_growth_scale_value,
ep.personal_percent_estimated=Vineland_SA.personal_percent_estimated,
ep.personal_vs_minus_mean_vs=Vineland_SA.personal_vs_minus_mean_vs,
ep.personal_strength_weakness=Vineland_SA.personal_strength_weakness,
ep.personal_base_rate=Vineland_SA.personal_base_rate,
ep.domestic_RAW_SCORE=Vineland_SA.domestic_RAW_SCORE,
ep.domestic_v_Scale_Score=Vineland_SA.domestic_v_Scale_Score,
ep.domestic_age_equiv=Vineland_SA.domestic_age_equiv,
ep.domestic_growth_scale_value=Vineland_SA.domestic_growth_scale_value,
ep.domestic_percent_estimated=Vineland_SA.domestic_percent_estimated,
ep.domestic_vs_minus_mean_vs=Vineland_SA.domestic_vs_minus_mean_vs,
ep.domestic_strength_weakness=Vineland_SA.domestic_strength_weakness,
ep.domestic_base_rate=Vineland_SA.domestic_base_rate,
ep.community_RAW_SCORE=Vineland_SA.community_RAW_SCORE,
ep.community_v_Scale_Score=Vineland_SA.community_v_Scale_Score,
ep.community_age_equiv=Vineland_SA.community_age_equiv,
ep.community_growth_scale_value=Vineland_SA.community_growth_scale_value,
ep.community_percent_estimated=Vineland_SA.community_percent_estimated,
ep.community_vs_minus_mean_vs=Vineland_SA.community_vs_minus_mean_vs,
ep.community_strength_weakness=Vineland_SA.community_strength_weakness,
ep.community_base_rate=Vineland_SA.community_base_rate,
ep.inter_pers_rel_RAW_SCORE=Vineland_SA.inter_pers_rel_RAW_SCORE,
ep.inter_pers_rel_v_Scale_Score=Vineland_SA.inter_pers_rel_v_Scale_Score,
ep.inter_pers_rel_age_equiv=Vineland_SA.inter_pers_rel_age_equiv,
ep.inter_pers_rel_growth_scale_value=Vineland_SA.inter_pers_rel_growth_scale_value,
ep.inter_pers_rel_percent_estimated=Vineland_SA.inter_pers_rel_percent_estimated,
ep.inter_pers_rel_vs_minus_mean_vs=Vineland_SA.inter_pers_rel_vs_minus_mean_vs,
ep.inter_pers_rel_strength_weakness=Vineland_SA.inter_pers_rel_strength_weakness,
ep.inter_pers_rel_base_rate=Vineland_SA.inter_pers_rel_base_rate,
ep.play_leisure_RAW_SCORE=Vineland_SA.play_leisure_RAW_SCORE,
ep.play_leisure_v_Scale_Score=Vineland_SA.play_leisure_v_Scale_Score,
ep.play_leisure_age_equiv=Vineland_SA.play_leisure_age_equiv,
ep.play_leisure_growth_scale_value=Vineland_SA.play_leisure_growth_scale_value,
ep.play_leisure_percent_estimated=Vineland_SA.play_leisure_percent_estimated,
ep.play_leisure_vs_minus_mean_vs=Vineland_SA.play_leisure_vs_minus_mean_vs,
ep.play_leisure_strength_weakness=Vineland_SA.play_leisure_strength_weakness,
ep.play_leisure_base_rate=Vineland_SA.play_leisure_base_rate,
ep.copy_skills_RAW_SCORE=Vineland_SA.copy_skills_RAW_SCORE,
ep.copy_skills_v_Scale_Score=Vineland_SA.copy_skills_v_Scale_Score,
ep.copy_skills_age_equiv=Vineland_SA.copy_skills_age_equiv,
ep.copy_skills_growth_scale_value=Vineland_SA.copy_skills_growth_scale_value,
ep.copy_skills_percent_estimated=Vineland_SA.copy_skills_percent_estimated,
ep.copy_skills_vs_minus_mean_vs=Vineland_SA.copy_skills_vs_minus_mean_vs,
ep.copy_skills_strength_weakness=Vineland_SA.copy_skills_strength_weakness,
ep.copy_skills_base_rate=Vineland_SA.copy_skills_base_rate,
ep.gross_motor_RAW_SCORE=Vineland_SA.gross_motor_RAW_SCORE,
ep.gross_motor_v_Scale_Score=Vineland_SA.gross_motor_v_Scale_Score,
ep.gross_motor_age_equiv=Vineland_SA.gross_motor_age_equiv,
ep.gross_motor_growth_scale_value=Vineland_SA.gross_motor_growth_scale_value,
ep.gross_motor_percent_estimated=Vineland_SA.gross_motor_percent_estimated,
ep.gross_motor_vs_minus_mean_vs=Vineland_SA.gross_motor_vs_minus_mean_vs,
ep.gross_motor_strength_weakness=Vineland_SA.gross_motor_strength_weakness,
ep.gross_motor_base_rate=Vineland_SA.gross_motor_base_rate,
ep.fine_motor_RAW_SCORE=Vineland_SA.fine_motor_RAW_SCORE,
ep.fine_motor_v_Scale_Score=Vineland_SA.fine_motor_v_Scale_Score,
ep.fine_motor_age_equiv=Vineland_SA.fine_motor_age_equiv,
ep.fine_motor_growth_scale_value=Vineland_SA.fine_motor_growth_scale_value,
ep.fine_motor_percent_estimated=Vineland_SA.fine_motor_percent_estimated,
ep.fine_motor_vs_minus_mean_vs=Vineland_SA.fine_motor_vs_minus_mean_vs,
ep.fine_motor_strength_weakness=Vineland_SA.fine_motor_strength_weakness,
ep.fine_motor_base_rate=Vineland_SA.fine_motor_base_rate,
ep.other_comments=Vineland_SA.other_comments
WHERE 
    ep.File_name IS NULL;
