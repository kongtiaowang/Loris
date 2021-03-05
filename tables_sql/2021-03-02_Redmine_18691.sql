-- Redmine 18691
-- Change subproject to 6 month recruit for:
-- UNC0223 (416539) at all time points

UPDATE
    session
SET
    SubprojectID='1'
WHERE
    CandID = '416539' AND
    SubprojectID='7'
;