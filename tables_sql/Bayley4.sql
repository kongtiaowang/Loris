CREATE TABLE `Bayley4` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `UserID` varchar(255) DEFAULT NULL,
  `Examiner` varchar(255) DEFAULT NULL,
  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `Date_taken` date DEFAULT NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` varchar(255) DEFAULT NULL,
  `ID` varchar(20) default NULL,

 `Name` varchar(50) default NULL,
 `Gender` varchar(20) default NULL,
 `Birth_Date` varchar(20) default NULL,

 `Test_Date` varchar(50) default NULL,
 `Examiner_Name` varchar(50) default NULL,
 `Relationship` varchar(30) default NULL,
 `Test_age` varchar(50) default NULL,



 `Cognitive_CG_RAW_Score` varchar(10)  default NULL, 
 `Cognitive_CG_Scaled_Score` varchar(10)  default NULL,
 `Cognitive_CG_Age_Equivalent` varchar(10)  default NULL,
 `Cognitive_CG_Growth_Scale_Value` varchar(10)  default NULL,


 `Receptive_Communication_RC_RAW_Score` varchar(10)  default NULL,
 `Receptive_Communication_RC_Scaled_Score` varchar(10)  default NULL,
 `Receptive_Communication_RC_Age_Equivalent` varchar(10)  default NULL,  
 `Receptive_Communication_RC_Growth_Scale_Value` varchar(10)  default NULL, 

 `Expressive_Communication_EC_RAW_Score` varchar(10)  default NULL,
 `Expressive_Communication_EC_Scaled_Score` varchar(10)  default NULL,
 `Expressive_Communication_EC_Age_Equivalent` varchar(10)  default NULL,
 `Expressive_Communication_EC_Growth_Scale_Value` varchar(10)  default NULL, 


 `Fine_Motor_FM_RAW_Score` varchar(10)  default NULL,
 `Fine_Motor_FM_Scaled_Score` varchar(10)  default NULL,
 `Fine_Motor_FM_Age_Equivalent` varchar(10)  default NULL,
 `Fine_Motor_FM_Growth_Scale_Value` varchar(10)  default NULL, 

 `Gross_Motor_GM_RAW_Score` varchar(10)  default NULL,
 `Gross_Motor_GM_Scaled_Score` varchar(10)  default NULL,
 `Gross_Motor_GM_Age_Equivalent` varchar(10)  default NULL,
 `Gross_Motor_GM_Growth_Scale_Value` varchar(10)  default NULL,

 `COG_Sum_of_scaled_scores` varchar(10)  default NULL,
 `COG_Scaled_Score` varchar(10)  default NULL,
 `COG_Standard_score` varchar(10)  default NULL,
 `COG_Percentile_rank` varchar(10)  default NULL,
 `COG_Confidence_interval` varchar(100)  default NULL,
 `COG_Descriptive_classification` varchar(100)  default NULL,

 `LANG_Sum_of_scaled_scores` varchar(10)  default NULL,
 `LANG_Scaled_Score` varchar(10)  default NULL,
 `LANG_Standard_score` varchar(10)  default NULL,
 `LANG_Percentile_rank` varchar(10)  default NULL,
 `LANG_Confidence_interval` varchar(100)  default NULL,
 `LANG_Descriptive_classification` varchar(100)  default NULL,

 `MOT_Sum_of_scaled_scores` varchar(10)  default NULL,
 `MOT_Scaled_Score` varchar(10)  default NULL,
 `MOT_Standard_score` varchar(10)  default NULL,
 `MOT_Percentile_rank` varchar(10)  default NULL,
 `MOT_Confidence_interval` varchar(100)  default NULL,
 `MOT_Descriptive_classification` varchar(100)  default NULL,

 `RC_EC_Score_1` varchar(10)  default NULL,
 `RC_EC_Score_2` varchar(10)  default NULL,
 `RC_EC_Difference` varchar(10)  default NULL,
 `RC_EC_Critical_value` varchar(10)  default NULL,
 `RC_EC_Significant_difference` varchar(10)  default NULL,
 `RC_EC_Base_rate` varchar(20)  default NULL,

 `FM_GM_Score_1` varchar(10)  default NULL,
 `FM_GM_Score_2` varchar(10)  default NULL,
 `FM_GM_Difference` varchar(10)  default NULL,
 `FM_GM_Critical_value` varchar(10)  default NULL,
 `FM_GM_Significant_difference` varchar(10)  default NULL,
 `FM_GM_Base_rate` varchar(20)  default NULL,


 `CL_Score_Score_1` varchar(10)  default NULL,
 `CL_Score_Score_2` varchar(10)  default NULL,
 `CL_Score_Difference` varchar(10)  default NULL,
 `CL_Score_Critical_value` varchar(10)  default NULL,
 `CL_Score_Significant_difference` varchar(10)  default NULL,
 `CL_Score_Base_rate` varchar(20)  default NULL,

 `CM_Score_Score_1` varchar(10)  default NULL,
 `CM_Score_Score_2` varchar(10)  default NULL,
 `CM_Score_Difference` varchar(10)  default NULL,
 `CM_Score_Critical_value` varchar(10)  default NULL,
 `CM_Score_Significant_difference` varchar(10)  default NULL,
 `CM_Score_Base_rate` varchar(20)  default NULL,

 `LM_Score_Score_1` varchar(10)  default NULL,
 `LM_Score_Score_2` varchar(10)  default NULL,
 `LM_Score_Difference` varchar(10)  default NULL,
 `LM_Score_Critical_value` varchar(10)  default NULL,
 `LM_Score_Significant_difference` varchar(10)  default NULL,
 `LM_Score_Base_rate` varchar(20)  default NULL,
 `bayley4_file` varchar(200)  default NULL,
  `other_comments` text  default NULL,
`File_name` text default NULL,
`File_type` text default NULL,
`Status` text default NULL,
`Data_dir` text default NULL,


  PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
