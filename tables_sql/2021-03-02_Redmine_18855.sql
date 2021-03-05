-- Redmine 18855
-- Change subproject to Control DS-Infant for:
-- STL6023 (471859) at V06-CVD

UPDATE
    session
SET
    SubprojectID='23'
WHERE
    CandID = '471859' AND
    Visit_label = 'V06-CVD' AND
    SubprojectID='20'
;