-- Add derived scoring column to Tanner Boys table;
ALTER TABLE TANNER_Boys
    ADD tanner_pubertal_stage_boys enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal');

-- Add derived scoring column to Tanner Girls table;
ALTER TABLE TANNER_Girls
    ADD tanner_pubertal_stage_girls enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal');

-- Add derived scoring, candidate age and window difference to Tanner Boys Survey table;
ALTER TABLE tanner_boys_survey
    ADD tanner_pubertal_stage_boys enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal');

-- Add derived scoring, candidate age and window difference to Tanner Boys Survey table;
ALTER TABLE tanner_girls_survey
    ADD tanner_pubertal_stage_girls enum('pre_pubertal', 'early_pubertal', 'mid_pubertal', 'late_pubertal', 'post_pubertal');

-- Add new columns to parameter type table to be imported into the DQT.
INSERT INTO `parameter_type` (`Name`, `Type`, `Description`, `SourceField`, `SourceFrom`) VALUES
    ('TANNER_Boys_tanner_pubertal_stage_boys', 'varchar(255)', 'Tanner Stage of Physical Development (Boys)', 'tanner_pubertal_stage_boys', 'TANNER_Boys'),
    ('TANNER_Girls_tanner_pubertal_stage_girls', 'varchar(255)', 'Tanner Stage of Physical Development (Girls)', 'tanner_pubertal_stage_girls', 'TANNER_Girls'),
    ('tanner_boys_survey_tanner_score_boys', 'varchar(255)', 'Tanner Stage of Physical Development Raw Score (Boys)', 'tanner_score_boys', 'tanner_boys_survey'),
    ('tanner_girls_survey_tanner_score_girls', 'varchar(255)', 'Tanner Stage of Physical Development Raw Score (Girls)', 'tanner_score_girls', 'tanner_girls_survey'),
    ('tanner_boys_survey_tanner_pubertal_stage_boys', 'varchar(255)', 'Tanner Stage of Physical Development (Boys)', 'tanner_pubertal_stage_boys', 'tanner_boys_survey'),
    ('tanner_girls_survey_tanner_pubertal_stage_girls', 'varchar(255)', 'Tanner Stage of Physical Development (Girls)', 'tanner_pubertal_stage_girls', 'tanner_girls_survey');

-- Update the raw score descriptions in the parameter types table.
UPDATE `parameter_type` SET `Description` = 'Tanner Stage of Physical Development Raw Score (Boys)' WHERE `Name` = 'TANNER_Boys_tanner_score_boys';
UPDATE `parameter_type` SET `Description` = 'Tanner Stage of Physical Development Raw Score (Girls)' WHERE `Name` = 'TANNER_Girls_tanner_score_girls';
