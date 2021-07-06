UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.UserID = (
    SELECT Vineland_SA.UserID
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Examiner = (
    SELECT Vineland_SA.Examiner
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Testdate = (
    SELECT Vineland_SA.Testdate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Data_entry_completion_status = (
    SELECT Vineland_SA.Data_entry_completion_status
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Date_taken = (
    SELECT Vineland_SA.Date_taken
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Candidate_Age = (
    SELECT Vineland_SA.Candidate_Age
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Window_Difference = (
    SELECT Vineland_SA.Window_Difference
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.File_name = (
    SELECT Vineland_SA.File_name
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.File_type = (
    SELECT Vineland_SA.File_type
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Status = (
    SELECT Vineland_SA.Status
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.Data_dir = (
    SELECT Vineland_SA.Data_dir
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.adapt_behave_comp_STD_SCORE = (
    SELECT Vineland_SA.adapt_behave_comp_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.adapt_behave_comp_90_CI = (
    SELECT Vineland_SA.adapt_behave_comp_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.adapt_behave_comp_PERCENTILE = (
    SELECT Vineland_SA.adapt_behave_comp_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.adapt_behave_comp_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.adapt_behave_comp_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.adapt_behave_comp_strength_weakness = (
    SELECT Vineland_SA.adapt_behave_comp_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.adapt_behave_comp_base_rate = (
    SELECT Vineland_SA.adapt_behave_comp_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.communication_STD_SCORE = (
    SELECT Vineland_SA.communication_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.communication_90_CI = (
    SELECT Vineland_SA.communication_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.communication_PERCENTILE = (
    SELECT Vineland_SA.communication_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.communication_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.communication_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.communication_strength_weakness = (
    SELECT Vineland_SA.communication_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.communication_base_rate = (
    SELECT Vineland_SA.communication_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.daily_living_skills_STD_SCORE = (
    SELECT Vineland_SA.daily_living_skills_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.daily_living_skills_90_CI = (
    SELECT Vineland_SA.daily_living_skills_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.daily_living_skills_PERCENTILE = (
    SELECT Vineland_SA.daily_living_skills_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.daily_living_skills_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.daily_living_skills_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.daily_living_skills_strength_weakness = (
    SELECT Vineland_SA.daily_living_skills_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.daily_living_skills_base_rate = (
    SELECT Vineland_SA.daily_living_skills_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.socialization_STD_SCORE = (
    SELECT Vineland_SA.socialization_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.socialization_90_CI = (
    SELECT Vineland_SA.socialization_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.socialization_PERCENTILE = (
    SELECT Vineland_SA.socialization_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.socialization_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.socialization_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.socialization_strength_weakness = (
    SELECT Vineland_SA.socialization_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.socialization_base_rate = (
    SELECT Vineland_SA.socialization_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.motor_skills_STD_SCORE = (
    SELECT Vineland_SA.motor_skills_STD_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.motor_skills_90_CI = (
    SELECT Vineland_SA.motor_skills_90_CI
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.motor_skills_PERCENTILE = (
    SELECT Vineland_SA.motor_skills_PERCENTILE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.motor_skills_SS_Minus_Mean_SS = (
    SELECT Vineland_SA.motor_skills_SS_Minus_Mean_SS
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.motor_skills_strength_weakness = (
    SELECT Vineland_SA.motor_skills_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.motor_skills_base_rate = (
    SELECT Vineland_SA.motor_skills_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_RAW_SCORE = (
    SELECT Vineland_SA.recDS_Infanttive_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_v_Scale_Score = (
    SELECT Vineland_SA.recDS_Infanttive_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_age_equiv = (
    SELECT Vineland_SA.recDS_Infanttive_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_growth_scale_value = (
    SELECT Vineland_SA.recDS_Infanttive_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_percent_estimated = (
    SELECT Vineland_SA.recDS_Infanttive_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_vs_minus_mean_vs = (
    SELECT Vineland_SA.recDS_Infanttive_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_strength_weakness = (
    SELECT Vineland_SA.recDS_Infanttive_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.recDS_Infanttive_base_rate = (
    SELECT Vineland_SA.recDS_Infanttive_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_RAW_SCORE = (
    SELECT Vineland_SA.expressive_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_v_Scale_Score = (
    SELECT Vineland_SA.expressive_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_age_equiv = (
    SELECT Vineland_SA.expressive_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_growth_scale_value = (
    SELECT Vineland_SA.expressive_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_percent_estimated = (
    SELECT Vineland_SA.expressive_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_vs_minus_mean_vs = (
    SELECT Vineland_SA.expressive_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_strength_weakness = (
    SELECT Vineland_SA.expressive_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.expressive_base_rate = (
    SELECT Vineland_SA.expressive_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_RAW_SCORE = (
    SELECT Vineland_SA.written_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_v_Scale_Score = (
    SELECT Vineland_SA.written_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_age_equiv = (
    SELECT Vineland_SA.written_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_growth_scale_value = (
    SELECT Vineland_SA.written_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_percent_estimated = (
    SELECT Vineland_SA.written_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_vs_minus_mean_vs = (
    SELECT Vineland_SA.written_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_strength_weakness = (
    SELECT Vineland_SA.written_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.written_base_rate = (
    SELECT Vineland_SA.written_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_RAW_SCORE = (
    SELECT Vineland_SA.personal_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_v_Scale_Score = (
    SELECT Vineland_SA.personal_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_age_equiv = (
    SELECT Vineland_SA.personal_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_growth_scale_value = (
    SELECT Vineland_SA.personal_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_percent_estimated = (
    SELECT Vineland_SA.personal_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_vs_minus_mean_vs = (
    SELECT Vineland_SA.personal_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_strength_weakness = (
    SELECT Vineland_SA.personal_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.personal_base_rate = (
    SELECT Vineland_SA.personal_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_RAW_SCORE = (
    SELECT Vineland_SA.domestic_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_v_Scale_Score = (
    SELECT Vineland_SA.domestic_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_age_equiv = (
    SELECT Vineland_SA.domestic_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_growth_scale_value = (
    SELECT Vineland_SA.domestic_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_percent_estimated = (
    SELECT Vineland_SA.domestic_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_vs_minus_mean_vs = (
    SELECT Vineland_SA.domestic_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_strength_weakness = (
    SELECT Vineland_SA.domestic_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.domestic_base_rate = (
    SELECT Vineland_SA.domestic_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;


UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_RAW_SCORE = (
    SELECT Vineland_SA.community_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_v_Scale_Score = (
    SELECT Vineland_SA.community_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_age_equiv = (
    SELECT Vineland_SA.community_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_growth_scale_value = (
    SELECT Vineland_SA.community_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_percent_estimated = (
    SELECT Vineland_SA.community_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_vs_minus_mean_vs = (
    SELECT Vineland_SA.community_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_strength_weakness = (
    SELECT Vineland_SA.community_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.community_base_rate = (
    SELECT Vineland_SA.community_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_RAW_SCORE = (
    SELECT Vineland_SA.inter_pers_rel_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_v_Scale_Score = (
    SELECT Vineland_SA.inter_pers_rel_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_age_equiv = (
    SELECT Vineland_SA.inter_pers_rel_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_growth_scale_value = (
    SELECT Vineland_SA.inter_pers_rel_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_percent_estimated = (
    SELECT Vineland_SA.inter_pers_rel_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_vs_minus_mean_vs = (
    SELECT Vineland_SA.inter_pers_rel_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_strength_weakness = (
    SELECT Vineland_SA.inter_pers_rel_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.inter_pers_rel_base_rate = (
    SELECT Vineland_SA.inter_pers_rel_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_RAW_SCORE = (
    SELECT Vineland_SA.play_leisure_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_v_Scale_Score = (
    SELECT Vineland_SA.play_leisure_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_age_equiv = (
    SELECT Vineland_SA.play_leisure_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_growth_scale_value = (
    SELECT Vineland_SA.play_leisure_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_percent_estimated = (
    SELECT Vineland_SA.play_leisure_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_vs_minus_mean_vs = (
    SELECT Vineland_SA.play_leisure_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_strength_weakness = (
    SELECT Vineland_SA.play_leisure_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.play_leisure_base_rate = (
    SELECT Vineland_SA.play_leisure_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_RAW_SCORE = (
    SELECT Vineland_SA.copy_skills_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_v_Scale_Score = (
    SELECT Vineland_SA.copy_skills_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_age_equiv = (
    SELECT Vineland_SA.copy_skills_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_growth_scale_value = (
    SELECT Vineland_SA.copy_skills_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_percent_estimated = (
    SELECT Vineland_SA.copy_skills_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_vs_minus_mean_vs = (
    SELECT Vineland_SA.copy_skills_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_strength_weakness = (
    SELECT Vineland_SA.copy_skills_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.copy_skills_base_rate = (
    SELECT Vineland_SA.copy_skills_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_RAW_SCORE = (
    SELECT Vineland_SA.gross_motor_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_v_Scale_Score = (
    SELECT Vineland_SA.gross_motor_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_age_equiv = (
    SELECT Vineland_SA.gross_motor_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_growth_scale_value = (
    SELECT Vineland_SA.gross_motor_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_percent_estimated = (
    SELECT Vineland_SA.gross_motor_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_vs_minus_mean_vs = (
    SELECT Vineland_SA.gross_motor_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_strength_weakness = (
    SELECT Vineland_SA.gross_motor_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.gross_motor_base_rate = (
    SELECT Vineland_SA.gross_motor_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_RAW_SCORE = (
    SELECT Vineland_SA.fine_motor_RAW_SCORE
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_v_Scale_Score = (
    SELECT Vineland_SA.fine_motor_v_Scale_Score
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_age_equiv = (
    SELECT Vineland_SA.fine_motor_age_equiv
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_growth_scale_value = (
    SELECT Vineland_SA.fine_motor_growth_scale_value
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_percent_estimated = (
    SELECT Vineland_SA.fine_motor_percent_estimated
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_vs_minus_mean_vs = (
    SELECT Vineland_SA.fine_motor_vs_minus_mean_vs
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_strength_weakness = (
    SELECT Vineland_SA.fine_motor_strength_weakness
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.fine_motor_base_rate = (
    SELECT Vineland_SA.fine_motor_base_rate
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL;

UPDATE Vineland_DS_Infant 
SET Vineland_DS_Infant.other_comments = (
    SELECT Vineland_SA.other_comments
    FROM Vineland_SA
    WHERE Vineland_SA.CommentID = Vineland_DS_Infant.CommentID 
) WHERE Vineland_DS_Infant.File_name IS NULL; 
