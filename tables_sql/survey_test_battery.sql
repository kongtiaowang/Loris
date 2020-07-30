CREATE TABLE `survey_test_battery` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Test_name` varchar(255) NOT NULL DEFAULT '',
  `Active` enum('Y','N') NOT NULL DEFAULT 'Y',
  `SubprojectID` int(11) DEFAULT NULL,
  `Visit_label` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `idx_name` (`SubprojectID`,`Test_name`,`Visit_label`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

INSERT INTO survey_test_battery (
    Test_name,
    Visit_label
)
VALUES
('ADULT_SELF_REPORT_DAD','VSA-CVD'),
('ADULT_SELF_REPORT_MOM','VSA-CVD'),
('ABCL_DAD_ON_MOM','VSA-CVD'),
('ABC2','VSA-CVD'),
('ABCL_MOM_ON_DAD','VSA-CVD'),
('BRIEF2_Parent','VSA-CVD'),
('CBCL_6_To_18','VSA-CVD'),
('CCC2','VSA-CVD'),
('UCD_Charge_GI_History','VSA-CVD'),
('CSHQ','VSA-CVD'),
('conners_parent','VSA-CVD'),
('perinatal_data','VSA-CVD'),
('MASC2_Parent','VSA-CVD'),
('MASC2_Self_Report','VSA-CVD'),
('pspq_SelfReport_dad','VSA-CVD'),
('pspq_SelfReport_mom','VSA-CVD'),
('pspq_InformantReport_dad_on_mom','VSA-CVD'),
('pspq_InformantReport_mom_on_dad','VSA-CVD'),
('QRS_Proband','VSA-CVD'),
('QRS','VSA-CVD'),
('scq_proband_survey','VSA-CVD'),
('Seizure_Questionnaire','VSA-CVD'),
('SEQ3','VSA-CVD'),
('rbs_r_proband','VSA-CVD'),
('rbs_r','VSA-CVD'),
('SRS2_SelfReport_Dad','VSA-CVD'),
('SRS2_SelfReport_Mom','VSA-CVD'),
('SRS2_InformantReport_Dad_On_Mom','VSA-CVD'),
('SRS2_InformantReport_Mom_On_Dad','VSA-CVD'),
('SRS2_SchoolAge_Parent_proband','VSA-CVD'),
('SRS2_SchoolAge_Parent','VSA-CVD'),
('SSIS_Parent','VSA-CVD');