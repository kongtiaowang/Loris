CREATE TABLE `Seizure_Questionnaire` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`person_completing_form` varchar(255) default NULL,
`relationship_to_child` varchar(255) default NULL,
`p1_1` enum('yes','no','possible','dont_know') default NULL,
`p1_2` enum('yes','no','possible','dont_know') default NULL,
`p1_3a` enum('yes','no','possible','dont_know') default NULL,
`p1_3a_notes` varchar(255) default NULL,
`p1_3b` enum('yes','no','possible','dont_know') default NULL,
`p1_3b_notes` varchar(255) default NULL,
`p1_3c` enum('yes','no','possible','dont_know') default NULL,
`p1_3c_notes` varchar(255) default NULL,
`p1_3d` enum('yes','no','possible','dont_know') default NULL,
`p1_3d_notes` varchar(255) default NULL,
`p1_3e` enum('yes','no','possible','dont_know') default NULL,
`p1_3e_notes` varchar(255) default NULL,
`p1_3f` enum('yes','no','possible','dont_know') default NULL,
`p1_3f_notes` varchar(255) default NULL,
`p1_3g` enum('yes','no','possible','dont_know') default NULL,
`p1_3g_notes` varchar(255) default NULL,
`p1_3h` enum('yes','no','possible','dont_know') default NULL,
`p1_3h_notes` varchar(255) default NULL,
`p2_1_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p2_1_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p2_1_last_over_30min` enum('no','yes') default NULL,
`p2_1_duration` varchar(255) default NULL,
`p2_2_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p2_2_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p2_2_last_over_30min` enum('no','yes') default NULL,
`p2_2_duration` varchar(255) default NULL,
`p3_3_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p3_3_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p3_3_last_over_30min` enum('no','yes') default NULL,
`p3_3_duration` varchar(255) default NULL,
`p3_4_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p3_4_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p3_4_last_over_30min` enum('no','yes') default NULL,
`p3_4_duration` varchar(255) default NULL,
`p3_5_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p3_5_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p3_5_last_over_30min` enum('no','yes') default NULL,
`p3_5_duration` varchar(255) default NULL,
`p3_6_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p3_6_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p3_6_last_over_30min` enum('no','yes') default NULL,
`p3_6_duration` varchar(255) default NULL,
`p3_7_frequency` enum('never_occurred','less_than_once_per_year','more_than_once_a_year','1_or_more_each_month','1_or_more_each_week','daily') default NULL,
`p3_7_period` enum('never_occurred','less_than_a_month','one_to_six_months','more_than_six_months') default NULL,
`p3_7_last_over_30min` enum('no','yes') default NULL,
`p3_7_duration` varchar(255) default NULL,
`medication_1` varchar(255) default NULL,
`medication_1_efficacy` enum('stopped_seizures_completely','partial_reduction','no_improvement','adverse_reaction') default NULL,
`medication_2` varchar(255) default NULL,
`medication_2_efficacy` enum('stopped_seizures_completely','partial_reduction','no_improvement','adverse_reaction') default NULL,
`medication_3` varchar(255) default NULL,
`medication_3_efficacy` enum('stopped_seizures_completely','partial_reduction','no_improvement','adverse_reaction') default NULL,
`medication_4` varchar(255) default NULL,
`medication_4_efficacy` enum('stopped_seizures_completely','partial_reduction','no_improvement','adverse_reaction') default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;