-- Update tanner boys survey to add Data_entry_completion_status column, setting value based on
-- flags data entry column
ALTER TABLE tanner_boys_survey ADD COLUMN Data_entry_completion_status enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete' AFTER UserID;

UPDATE tanner_boys_survey
SET tanner_boys_survey.Data_entry_completion_status = (
    SELECT
        CASE
            WHEN Data_entry = 'Complete' THEN 'Complete'
            ELSE 'Incomplete'
        END
    FROM flag
    WHERE flag.CommentID = tanner_boys_survey.CommentID
);

-- Update tanner girls survey to add Data_entry_completion_status column, setting value based on
-- flags data entry column
ALTER TABLE tanner_girls_survey ADD COLUMN Data_entry_completion_status enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete' AFTER UserID;

UPDATE tanner_girls_survey
SET tanner_girls_survey.Data_entry_completion_status = (
    SELECT
        CASE
            WHEN Data_entry = 'Complete' THEN 'Complete'
            ELSE 'Incomplete'
            END
    FROM flag
    WHERE flag.CommentID = tanner_girls_survey.CommentID
);
