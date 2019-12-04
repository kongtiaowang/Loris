ALTER TABLE SRS2_InformantReport_Dad_On_Mom ADD COLUMN `informant_rel_to_child` enum('biological_mother','biological_father','','other') DEFAULT NULL;
ALTER TABLE SRS2_InformantReport_Mom_On_Dad ADD COLUMN `informant_rel_to_child` enum('biological_mother','biological_father','','other') DEFAULT NULL;
ALTER TABLE SRS2_InformantReport_Dad_On_Mom ADD COLUMN `informant_rel_to_child_other` TEXT DEFAULT NULL;
ALTER TABLE SRS2_InformantReport_Mom_On_Dad ADD COLUMN `informant_rel_to_child_other` TEXT DEFAULT NULL;