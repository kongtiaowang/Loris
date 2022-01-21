-- =========================================================================
-- Replaces values of form mri_parameter_ep that were incorrectly saved
-- as 'Array' (multi-select bug).
-- =========================================================================


-- ===========================================================================
--
-- face_mask
--
-- ===========================================================================

-- -----------------------------------------------------------------------------
-- Update for the records whose data value in table flag is of the form:
--  data = {..... , "face_mask":["value1","value2","value3"] , ....}
-- -----------------------------------------------------------------------------
 UPDATE mri_parameter_ep
 JOIN flag USING(commentid)
 SET face_mask =
     REPLACE(                                                  -- Step 5: get result of step 4 and replace ',' with '{@}'
         REPLACE(                                              -- Step 4: get result of step 3 and remove the quotes
             SUBSTRING_INDEX(                                  -- Step 3: get result of step 2 and get whatever's to the right of string [
                 SUBSTRING_INDEX(                              -- Step 2: get result of step 1 and get whatever's to the left of string ]
                     SUBSTRING_INDEX(data,'"face_mask":', -1), -- Step 1: get whatever's to the right of string "face_mask":
                     ']',
                     1
                 ),
                 '[',
                 -1
              ),
              '"',
              ''
          ),
          ",",
          "{@}"
     )
 WHERE face_mask = 'Array'
 AND data LIKE '%"face_mask":[%';

-- -----------------------------------------------------------------------------
-- Update for the records whose data value in table flag is of the form:
--  data = {..... , "face_mask":"value1{@}value2{@}value3" , ....}
-- -----------------------------------------------------------------------------
UPDATE mri_parameter_ep
JOIN flag USING(commentid)
SET face_mask =
     REPLACE(                                            -- Step 3: get result of step 2 and remove the quotes
         SUBSTRING_INDEX(                                -- Step 2: get result of step 1 and get whetever's to the right of string ',' 
             SUBSTRING_INDEX(data,'"face_mask":', -1),   -- Step 1: get whatever's to the right of string "face_mask":
             ',',
             1
         ),
         '"',
         ''
     )
 WHERE face_mask ='Array';


-- ===========================================================================
--
-- face_shield
--
-- ===========================================================================

-- -----------------------------------------------------------------------------
-- Update for the records whose data value in table flag is of the form:
--  data = {..... , "face_shield":["value1","value2","value3"] , ....}
-- -----------------------------------------------------------------------------
 UPDATE mri_parameter_ep
 JOIN flag USING(commentid)
 SET face_shield =
     REPLACE(                                                    -- Step 5: get result of step 4 and replace ',' with '{@}'
         REPLACE(                                                -- Step 4: get result of step 3 and remove the quotes
             SUBSTRING_INDEX(                                    -- Step 3: get result of step 2 and get whatever's to the right of string [
                 SUBSTRING_INDEX(                                -- Step 2: get result of step 1 and get whatever's to the left of string ]
                     SUBSTRING_INDEX(data,'"face_shield":', -1), -- Step 1: get whatever's to the right of string "face_shield":
                     ']',
                     1
                 ),
                 '[',
                 -1
              ),
              '"',
              ''
          ),
          ",",
          "{@}"
     )
 WHERE face_shield = 'Array'
 AND data LIKE '%"face_shield":[%';

-- -----------------------------------------------------------------------------
-- Update for the records whose data value in table flag is of the form:
--  data = {..... , "face_shield":"value1{@}value2{@}value3" , ....}
-- -----------------------------------------------------------------------------
UPDATE mri_parameter_ep
JOIN flag USING(commentid)
SET face_shield =
     REPLACE(                                              -- Step 3: get result of step 2 and remove the quotes
         SUBSTRING_INDEX(                                  -- Step 2: get result of step 1 and get whetever's to the right of string ',' 
             SUBSTRING_INDEX(data,'"face_shield":', -1),   -- Step 1: get whatever's to the right of string "face_shield":
             ',',
             1
         ),
         '"',
         ''
     )
 WHERE face_shield ='Array';


-- ===========================================================================
--
-- study
--
-- ===========================================================================

-- -----------------------------------------------------------------------------
-- Update for the records whose data value in table flag is of the form:
--  data = {..... , "study":["value1","value2","value3"] , ....}
-- -----------------------------------------------------------------------------
 UPDATE mri_parameter_ep
 JOIN flag USING(commentid)
 SET study =
     REPLACE(                                                  -- Step 5: get result of step 4 and replace ',' with '{@}'
         REPLACE(                                              -- Step 4: get result of step 3 and remove the quotes
             SUBSTRING_INDEX(                                  -- Step 3: get result of step 2 and get whatever's to the right of string [
                 SUBSTRING_INDEX(                              -- Step 2: get result of step 1 and get whatever's to the left of string ]
                     SUBSTRING_INDEX(data,'"study":', -1),     -- Step 1: get whatever's to the right of string "study":
                     ']',
                     1
                 ),
                 '[',
                 -1
              ),
              '"',
              ''
          ),
          ",",
          "{@}"
     )
 WHERE study = 'Array'
 AND data LIKE '%"study":[%';

-- -----------------------------------------------------------------------------
-- Update for the records whose data value in table flag is of the form:
--  data = {..... , "study":"value1{@}value2{@}value3" , ....}
-- -----------------------------------------------------------------------------
UPDATE mri_parameter_ep
JOIN flag USING(commentid)
SET study =
     REPLACE(                                            -- Step 3: get result of step 2 and remove the quotes
         SUBSTRING_INDEX(                                -- Step 2: get result of step 1 and get whetever's to the right of string ',' 
             SUBSTRING_INDEX(data,'"study":', -1),       -- Step 1: get whatever's to the right of string "study":
             ',',
             1
         ),
         '"',
         ''
     )
 WHERE study ='Array';


