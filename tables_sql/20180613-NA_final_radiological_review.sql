-- --------------------------------------------------------------------------------------------------
-- This patch changes the values of the enums for the fields listed below so that the value
-- 'not_answered' is replaced by '' (empty string)
-- The patch assumes that the 'not_answered' value is the last one to appear in each enum list and
-- that none of these fields actually have value 'not_answered' in the database.
-- --------------------------------------------------------------------------------------------------

ALTER TABLE final_radiological_review CHANGE `Review_Done`           `Review_Done`           ENUM('yes','no','')                        DEFAULT NULL;
ALTER TABLE final_radiological_review CHANGE `Final_Review_Results`  `Final_Review_Results`  ENUM('normal','abnormal','atypical','')    DEFAULT NULL;
ALTER TABLE final_radiological_review CHANGE `Final_Exclusionary`    `Final_Exclusionary`    ENUM('exclusionary','non_exclusionary','') DEFAULT NULL;
ALTER TABLE final_radiological_review CHANGE `Final_Review_Results2` `Final_Review_Results2` ENUM('normal','abnormal','atypical','')    DEFAULT NULL;
ALTER TABLE final_radiological_review CHANGE `Final_Exclusionary2`   `Final_Exclusionary2`   ENUM('exclusionary','non_exclusionary','') DEFAULT NULL;
ALTER TABLE final_radiological_review CHANGE `Review_Done2`          `Review_Done2`          ENUM('yes','no','')                        DEFAULT NULL;
ALTER TABLE final_radiological_review CHANGE `Finalized`             `Finalized`             ENUM('yes','no','')                        DEFAULT NULL;
