CREATE TABLE `FXS_Genetic_Testing` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Date_taken` date default NULL,
`Candidate_Age` varchar(255) default NULL,
`Window_Difference` varchar(255) default NULL,
`respondent` enum('mother','father','step_mother','step_father','other') default NULL,
`respondent_specify` varchar(255) default NULL,
`no_of_siblings` varchar(255) default NULL,
`mother_date_of_birth` date default NULL,
`mother_genetic_testing` enum('yes','no','unknown') default NULL,
`mother_result` varchar(255) default NULL,
`father_date_of_birth` date default NULL,
`father_genetic_testing` enum('yes','no','unknown') default NULL,
`father_result` varchar(255) default NULL,
`sibling_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling_sex` enum('male','female') default NULL,
`sibling_date_of_birth` date default NULL,
`sibling_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling_result` varchar(255) default NULL,
`sibling1_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling1_sex` enum('male','female') default NULL,
`sibling1_date_of_birth` date default NULL,
`sibling1_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling1_result` varchar(255) default NULL,
`sibling2_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling2_sex` enum('male','female') default NULL,
`sibling2_date_of_birth` date default NULL,
`sibling2_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling2_result` varchar(255) default NULL,
`sibling3_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling3_sex` enum('male','female') default NULL,
`sibling3_date_of_birth` date default NULL,
`sibling3_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling3_result` varchar(255) default NULL,
`sibling4_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling4_sex` enum('male','female') default NULL,
`sibling4_date_of_birth` date default NULL,
`sibling4_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling4_result` varchar(255) default NULL,
`sibling5_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling5_sex` enum('male','female') default NULL,
`sibling5_date_of_birth` date default NULL,
`sibling5_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling5_result` varchar(255) default NULL,
`sibling6_relationship_to_fxs` enum('full_sibling','maternal_half','paternal_half') default NULL,
`sibling6_sex` enum('male','female') default NULL,
`sibling6_date_of_birth` date default NULL,
`sibling6_genetic_testing` enum('yes','no','unknown') default NULL,
`sibling6_result` varchar(255) default NULL,
`grand_mother_date_of_birth` date default NULL,
`grand_mother_genetic_testing` enum('yes','no','unknown') default NULL,
`grand_mother_result` varchar(255) default NULL,
`grand_father_date_of_birth` date default NULL,
`grand_father_genetic_testing` enum('yes','no','unknown') default NULL,
`grand_father_result` varchar(255) default NULL,
`aunt1_date_of_birth` date default NULL,
`aunt1_genetic_testing` enum('yes','no','unknown') default NULL,
`aunt1_result` varchar(255) default NULL,
`aunt2_date_of_birth` date default NULL,
`aunt2_genetic_testing` enum('yes','no','unknown') default NULL,
`aunt2_result` varchar(255) default NULL,
`aunt3_date_of_birth` date default NULL,
`aunt3_genetic_testing` enum('yes','no','unknown') default NULL,
`aunt3_result` varchar(255) default NULL,
`uncle1_date_of_birth` date default NULL,
`uncle1_genetic_testing` enum('yes','no','unknown') default NULL,
`uncle1_result` varchar(255) default NULL,
`uncle2_date_of_birth` date default NULL,
`uncle2_genetic_testing` enum('yes','no','unknown') default NULL,
`uncle2_result` varchar(255) default NULL,
`uncle3_date_of_birth` date default NULL,
`uncle3_genetic_testing` enum('yes','no','unknown') default NULL,
`uncle3_result` varchar(255) default NULL,
`moms_family_member1` varchar(255) default NULL,
`moms_relationship_to_fxs1` varchar(255) default NULL,
`moms_sex1` enum('male','female') default NULL,
`moms_date_of_birth1` date default NULL,
`moms_genetic_testing1` enum('yes','no','unknown') default NULL,
`moms_result1` varchar(255) default NULL,
`moms_family_member2` varchar(255) default NULL,
`moms_relationship_to_fxs2` varchar(255) default NULL,
`moms_sex2` enum('male','female') default NULL,
`moms_date_of_birth2` date default NULL,
`moms_genetic_testing2` enum('yes','no','unknown') default NULL,
`moms_result2` varchar(255) default NULL,
`moms_family_member3` varchar(255) default NULL,
`moms_relationship_to_fxs3` varchar(255) default NULL,
`moms_sex3` enum('male','female') default NULL,
`moms_date_of_birth3` date default NULL,
`moms_genetic_testing3` enum('yes','no','unknown') default NULL,
`moms_result3` varchar(255) default NULL,
`moms_family_member4` varchar(255) default NULL,
`moms_relationship_to_fxs4` varchar(255) default NULL,
`moms_sex4` enum('male','female') default NULL,
`moms_date_of_birth4` date default NULL,
`moms_genetic_testing4` enum('yes','no','unknown') default NULL,
`moms_result4` varchar(255) default NULL,
`mother_section2_date_of_birth` date default NULL,
`mother_section2_genetic_testing` enum('yes','no','unknown') default NULL,
`mother_section2_result` varchar(255) default NULL,
`grandmother_section2_date_of_birth` date default NULL,
`grandmother_section2_genetic_testing` enum('yes','no','unknown') default NULL,
`grandmother_section2_result` varchar(255) default NULL,
`moms_sister_date_of_birth1` date default NULL,
`moms_sister_genetic_testing1` enum('yes','no','unknown') default NULL,
`moms_sister_result1` varchar(255) default NULL,
`moms_sister_date_of_birth2` date default NULL,
`moms_sister_genetic_testing2` enum('yes','no','unknown') default NULL,
`moms_sister_result2` varchar(255) default NULL,
`moms_sister_date_of_birth3` date default NULL,
`moms_sister_genetic_testing3` enum('yes','no','unknown') default NULL,
`moms_sister_result3` varchar(255) default NULL,
`moms_sister_date_of_birth4` date default NULL,
`moms_sister_genetic_testing4` enum('yes','no','unknown') default NULL,
`moms_sister_result4` varchar(255) default NULL,
`moms_sister_date_of_birth5` date default NULL,
`moms_sister_genetic_testing5` enum('yes','no','unknown') default NULL,
`moms_sister_result5` varchar(255) default NULL,
`grandfather_section2_date_of_birth` date default NULL,
`grandfather_section2_genetic_testing` enum('yes','no','unknown') default NULL,
`grandfather_section2_result` varchar(255) default NULL,
`moms_brother_date_of_birth1` date default NULL,
`moms_brother_genetic_testing1` enum('yes','no','unknown') default NULL,
`moms_brother_result1` varchar(255) default NULL,
`moms_brother_date_of_birth2` date default NULL,
`moms_brother_genetic_testing2` enum('yes','no','unknown') default NULL,
`moms_brother_result2` varchar(255) default NULL,
`moms_brother_date_of_birth3` date default NULL,
`moms_brother_genetic_testing3` enum('yes','no','unknown') default NULL,
`moms_brother_result3` varchar(255) default NULL,
`moms_brother_date_of_birth4` date default NULL,
`moms_brother_genetic_testing4` enum('yes','no','unknown') default NULL,
`moms_brother_result4` varchar(255) default NULL,
`moms_brother_date_of_birth5` date default NULL,
`moms_brother_genetic_testing5` enum('yes','no','unknown') default NULL,
`moms_brother_result5` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;