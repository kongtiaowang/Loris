-- Adding Relationship to Survey Instruments
-- 1) Add relationship to child question to UCD Charge GI
ALTER TABLE UCD_Charge_GI_History ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE UCD_Charge_GI_History ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 2) Add relationship to child question to Conners 3 Parent
ALTER TABLE conners_parent ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE conners_parent ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 3)Add relationship to child question to CBCL_6_to_18
ALTER TABLE CBCL_6_To_18 ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Date_taken;
ALTER TABLE CBCL_6_To_18 ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 4) Add relationship to child question to SSIS parent
ALTER TABLE SSIS_Parent ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Date_taken;
ALTER TABLE SSIS_Parent ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 5) Add relationship to child question to SRS2_School Age
ALTER TABLE SRS2_SchoolAge ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Date_taken;
ALTER TABLE SRS2_SchoolAge ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 6) Add relationship to child question to scq_proband_survey
ALTER TABLE scq_proband_survey ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Date_taken;
ALTER TABLE scq_proband_survey ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 7) Add relationship to child question to ABC2
ALTER TABLE ABC2 ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE ABC2 ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 8) Add relationship to child question to QRS
ALTER TABLE QRS ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE QRS ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 9) Add relationship to child question to CSHQ
ALTER TABLE CSHQ ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE CSHQ ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 10) Add relationship to child question to ABCL
ALTER TABLE ABCL ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE ABCL ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 11) Add relationship to MASC2 Parent
ALTER TABLE MASC2_Parent ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE MASC2_Parent ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;
-- 12) Add relationship to MASC2 Self
ALTER TABLE MASC2_Self_Report ADD COLUMN relationship_to_child enum('mother','father','step_mother','step_father','other') default NULL AFTER Window_Difference;
ALTER TABLE MASC2_Self_Report ADD COLUMN other_relationship_to_child varchar (255) default NULL AFTER relationship_to_child;

-- Modifying/Updating Some Instruments to include the new enum values
-- 13) Modifying Seizure Questionnaire
ALTER TABLE `Seizure_Questionnaire` MODIFY COLUMN `relationship_to_child` enum('mother','father','step_mother','step_father','other') default NULL;
ALTER TABLE `Seizure_Questionnaire` ADD COLUMN `relationship_to_child_other` varchar(255) AFTER relationship_to_child;
-- 14) Modifying rbs_r
ALTER TABLE `rbs_r` MODIFY COLUMN `respondent` enum('mother','father','step_mother','step_father','other') default NULL;
-- 15) Modifying Sibling Social Contact
ALTER TABLE `sibling_socialcontact` MODIFY COLUMN `respondent` enum('mother','father','step_mother','step_father','other') default NULL;
-- 16) SRS2 Informant(not removing spouse as some entries already have spouse as value; but removing the option from frontend
ALTER TABLE `SRS2_InformantReport` MODIFY COLUMN `informant` enum('mother','father','step_mother','step_father','spouse','other') default NULL;
-- 17) m_chat_rf(not removing other_relative as some entries already have other relative as value; but removing the option from frontend
ALTER TABLE `m_chat_rf` MODIFY COLUMN `relationship_to_child` enum('mother','father','step_mother','step_father','other_relative','other') default NULL;
-- 18) SEQ3 Add step mother, step father options
ALTER TABLE `SEQ3` MODIFY COLUMN `person_completing_form` enum('mother','father','step_mother','step_father','both','teacher','other') default NULL;
-- 19) CCC2 Add step mother, step father options
ALTER TABLE `CCC2` MODIFY COLUMN `responder_relationship` enum('parent','step_mother','step_father','caregiver','teacher','other') default NULL;
