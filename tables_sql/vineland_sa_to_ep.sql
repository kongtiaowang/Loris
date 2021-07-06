UPDATE Vineland_EP 
SET Vineland_EP.UserID = (
    SELECT Vineland_SA.UserID
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Examiner = (
    SELECT Vineland_SA.Examiner
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Testdate = (
    SELECT Vineland_SA.Testdate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Data_entry_completion_status = (
    SELECT Vineland_SA.Data_entry_completion_status
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Date_taken = (
    SELECT Vineland_SA.Date_taken
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Candidate_Age = (
    SELECT Vineland_SA.Candidate_Age
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Window_Difference = (
    SELECT Vineland_SA.Window_Difference
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.File_name = (
    SELECT Vineland_SA.File_name
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.File_type = (
    SELECT Vineland_SA.File_type
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Status = (
    SELECT Vineland_SA.Status
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.Data_dir = (
    SELECT Vineland_SA.Data_dir
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.adapt_behave_comp_STD_SCORE = (
    SELECT Vineland_SA.adapt_behave_comp_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.adapt_behave_comp_90_CI = (
    SELECT Vineland_SA.adapt_behave_comp_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.adapt_behave_comp_PERCENTILE = (
    SELECT Vineland_SA.adapt_behave_comp_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.adapt_behave_comp_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.adapt_behave_comp_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.adapt_behave_comp_strength_weakness = (
    SELECT Vineland_SA.adapt_behave_comp_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.adapt_behave_comp_base_rate = (
    SELECT Vineland_SA.adapt_behave_comp_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.communication_STD_SCORE = (
    SELECT Vineland_SA.communication_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.communication_90_CI = (
    SELECT Vineland_SA.communication_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.communication_PERCENTILE = (
    SELECT Vineland_SA.communication_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.communication_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.communication_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.communication_strength_weakness = (
    SELECT Vineland_SA.communication_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.communication_base_rate = (
    SELECT Vineland_SA.communication_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.daily_living_skills_STD_SCORE = (
    SELECT Vineland_SA.daily_living_skills_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.daily_living_skills_90_CI = (
    SELECT Vineland_SA.daily_living_skills_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.daily_living_skills_PERCENTILE = (
    SELECT Vineland_SA.daily_living_skills_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.daily_living_skills_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.daily_living_skills_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.daily_living_skills_strength_weakness = (
    SELECT Vineland_SA.daily_living_skills_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.daily_living_skills_base_rate = (
    SELECT Vineland_SA.daily_living_skills_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.socialization_STD_SCORE = (
    SELECT Vineland_SA.socialization_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.socialization_90_CI = (
    SELECT Vineland_SA.socialization_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.socialization_PERCENTILE = (
    SELECT Vineland_SA.socialization_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.socialization_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.socialization_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.socialization_strength_weakness = (
    SELECT Vineland_SA.socialization_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.socialization_base_rate = (
    SELECT Vineland_SA.socialization_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.motor_skills_STD_SCORE = (
    SELECT Vineland_SA.motor_skills_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.motor_skills_90_CI = (
    SELECT Vineland_SA.motor_skills_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.motor_skills_PERCENTILE = (
    SELECT Vineland_SA.motor_skills_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.motor_skills_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.motor_skills_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.motor_skills_strength_weakness = (
    SELECT Vineland_SA.motor_skills_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.motor_skills_base_rate = (
    SELECT Vineland_SA.motor_skills_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_RAW_SCORE = (
    SELECT Vineland_SA.receptive_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_v_Scale_Score = (
    SELECT Vineland_SA.receptive_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_age_equiv = (
    SELECT Vineland_SA.receptive_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_growth_scale_value = (
    SELECT Vineland_SA.receptive_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_percent_estimated = (
    SELECT Vineland_SA.receptive_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_vs_minus_mean_vs = (
    SELECT Vineland_SA.receptive_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_strength_weakness = (
    SELECT Vineland_SA.receptive_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.receptive_base_rate = (
    SELECT Vineland_SA.receptive_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_RAW_SCORE = (
    SELECT Vineland_SA.expressive_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_v_Scale_Score = (
    SELECT Vineland_SA.expressive_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_age_equiv = (
    SELECT Vineland_SA.expressive_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_growth_scale_value = (
    SELECT Vineland_SA.expressive_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_percent_estimated = (
    SELECT Vineland_SA.expressive_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_vs_minus_mean_vs = (
    SELECT Vineland_SA.expressive_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_strength_weakness = (
    SELECT Vineland_SA.expressive_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.expressive_base_rate = (
    SELECT Vineland_SA.expressive_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_RAW_SCORE = (
    SELECT Vineland_SA.written_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_v_Scale_Score = (
    SELECT Vineland_SA.written_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_age_equiv = (
    SELECT Vineland_SA.written_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_growth_scale_value = (
    SELECT Vineland_SA.written_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_percent_estimated = (
    SELECT Vineland_SA.written_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_vs_minus_mean_vs = (
    SELECT Vineland_SA.written_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_strength_weakness = (
    SELECT Vineland_SA.written_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.written_base_rate = (
    SELECT Vineland_SA.written_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_RAW_SCORE = (
    SELECT Vineland_SA.personal_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_v_Scale_Score = (
    SELECT Vineland_SA.personal_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_age_equiv = (
    SELECT Vineland_SA.personal_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_growth_scale_value = (
    SELECT Vineland_SA.personal_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_percent_estimated = (
    SELECT Vineland_SA.personal_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_vs_minus_mean_vs = (
    SELECT Vineland_SA.personal_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_strength_weakness = (
    SELECT Vineland_SA.personal_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.personal_base_rate = (
    SELECT Vineland_SA.personal_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_RAW_SCORE = (
    SELECT Vineland_SA.domestic_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_v_Scale_Score = (
    SELECT Vineland_SA.domestic_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_age_equiv = (
    SELECT Vineland_SA.domestic_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_growth_scale_value = (
    SELECT Vineland_SA.domestic_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_percent_estimated = (
    SELECT Vineland_SA.domestic_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_vs_minus_mean_vs = (
    SELECT Vineland_SA.domestic_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_strength_weakness = (
    SELECT Vineland_SA.domestic_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.domestic_base_rate = (
    SELECT Vineland_SA.domestic_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;


UPDATE Vineland_EP 
SET Vineland_EP.community_RAW_SCORE = (
    SELECT Vineland_SA.community_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_v_Scale_Score = (
    SELECT Vineland_SA.community_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_age_equiv = (
    SELECT Vineland_SA.community_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_growth_scale_value = (
    SELECT Vineland_SA.community_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_percent_estimated = (
    SELECT Vineland_SA.community_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_vs_minus_mean_vs = (
    SELECT Vineland_SA.community_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_strength_weakness = (
    SELECT Vineland_SA.community_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.community_base_rate = (
    SELECT Vineland_SA.community_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_RAW_SCORE = (
    SELECT Vineland_SA.inter_pers_rel_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_v_Scale_Score = (
    SELECT Vineland_SA.inter_pers_rel_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_age_equiv = (
    SELECT Vineland_SA.inter_pers_rel_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_growth_scale_value = (
    SELECT Vineland_SA.inter_pers_rel_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_percent_estimated = (
    SELECT Vineland_SA.inter_pers_rel_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_vs_minus_mean_vs = (
    SELECT Vineland_SA.inter_pers_rel_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_strength_weakness = (
    SELECT Vineland_SA.inter_pers_rel_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.inter_pers_rel_base_rate = (
    SELECT Vineland_SA.inter_pers_rel_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_RAW_SCORE = (
    SELECT Vineland_SA.play_leisure_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_v_Scale_Score = (
    SELECT Vineland_SA.play_leisure_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_age_equiv = (
    SELECT Vineland_SA.play_leisure_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_growth_scale_value = (
    SELECT Vineland_SA.play_leisure_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_percent_estimated = (
    SELECT Vineland_SA.play_leisure_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_vs_minus_mean_vs = (
    SELECT Vineland_SA.play_leisure_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_strength_weakness = (
    SELECT Vineland_SA.play_leisure_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.play_leisure_base_rate = (
    SELECT Vineland_SA.play_leisure_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_RAW_SCORE = (
    SELECT Vineland_SA.copy_skills_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_v_Scale_Score = (
    SELECT Vineland_SA.copy_skills_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_age_equiv = (
    SELECT Vineland_SA.copy_skills_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_growth_scale_value = (
    SELECT Vineland_SA.copy_skills_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_percent_estimated = (
    SELECT Vineland_SA.copy_skills_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_vs_minus_mean_vs = (
    SELECT Vineland_SA.copy_skills_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_strength_weakness = (
    SELECT Vineland_SA.copy_skills_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.copy_skills_base_rate = (
    SELECT Vineland_SA.copy_skills_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_RAW_SCORE = (
    SELECT Vineland_SA.gross_motor_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_v_Scale_Score = (
    SELECT Vineland_SA.gross_motor_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_age_equiv = (
    SELECT Vineland_SA.gross_motor_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_growth_scale_value = (
    SELECT Vineland_SA.gross_motor_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_percent_estimated = (
    SELECT Vineland_SA.gross_motor_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_vs_minus_mean_vs = (
    SELECT Vineland_SA.gross_motor_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_strength_weakness = (
    SELECT Vineland_SA.gross_motor_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.gross_motor_base_rate = (
    SELECT Vineland_SA.gross_motor_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_RAW_SCORE = (
    SELECT Vineland_SA.fine_motor_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_v_Scale_Score = (
    SELECT Vineland_SA.fine_motor_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_age_equiv = (
    SELECT Vineland_SA.fine_motor_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_growth_scale_value = (
    SELECT Vineland_SA.fine_motor_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_percent_estimated = (
    SELECT Vineland_SA.fine_motor_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_vs_minus_mean_vs = (
    SELECT Vineland_SA.fine_motor_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_strength_weakness = (
    SELECT Vineland_SA.fine_motor_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.fine_motor_base_rate = (
    SELECT Vineland_SA.fine_motor_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL;

UPDATE Vineland_EP 
SET Vineland_EP.other_comments = (
    SELECT Vineland_SA.other_comments
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_EP.CommentID 
) WHERE Vineland_EP.File_name IS NULL; 
