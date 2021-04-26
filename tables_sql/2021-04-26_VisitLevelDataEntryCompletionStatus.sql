-- ------------------------------------------------------------------
--
-- Sets field Data_Entry_Completion_Status to 'Complete'
-- for all non-DDE records that have a non NULL q1_visit
-- column in the following tables:
--
-- Visit_Level_Information_Status_SA
-- Visit_Level_Information_Status_DS
-- Visit_Level_Information_Status_EP
--
-- Partially fixes https://redmine.cbrain.mcgill.ca/issues/18843.
--
-- ------------------------------------------------------------------

UPDATE Visit_Level_Information_Status_SA
SET Data_Entry_Completion_Status = 'Complete'
WHERE CommentID NOT LIKE 'DDE%'
AND q1_visit IS NOT NULL;

UPDATE Visit_Level_Information_Status_DS
SET Data_Entry_Completion_Status = 'Complete'
WHERE CommentID NOT LIKE 'DDE%'
AND q1_visit IS NOT NULL;

UPDATE Visit_Level_Information_Status_EP
SET Data_Entry_Completion_Status = 'Complete'
WHERE CommentID NOT LIKE 'DDE%'
AND q1_visit IS NOT NULL;


