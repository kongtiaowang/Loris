-- Update tanner boys survey to add Data_entry_completion_status column, setting value based on
-- flags data entry column
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
