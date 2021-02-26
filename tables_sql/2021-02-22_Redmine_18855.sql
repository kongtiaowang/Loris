-- Redmine 18855
-- Change subproject to Control DS-Infant for:
-- STL6006 (605027) at V06
-- STL6023 (471859) at V6-CVD

UPDATE
    session
SET
    SubprojectID='23'
WHERE
    CandID = '605027' AND
    Visit_label = 'V06' AND
    SubprojectID='20'
;

UPDATE
    session
SET
    SubprojectID='23'
WHERE
    CandID = '471859' AND
    Visit_label = 'V6-CVD' AND
    SubprojectID='20'
;