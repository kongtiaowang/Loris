-- Add scoring column to Tanner Boys table;
ALTER TABLE TANNER_Boys
    ADD tanner_score_boys decimal(3,2);

-- Add scoring column to Tanner Girls table;
ALTER TABLE TANNER_Girls
    ADD tanner_score_girls decimal(3,2);

-- Add scoring, candidate age and window difference to Tanner Boys Survey table;
ALTER TABLE tanner_boys_survey
    ADD tanner_score_boys decimal(3,2),
    ADD Candidate_Age varchar(255),
    ADD Window_Difference varchar(255);

-- Add scoring, candidate age and window difference to Tanner Boys Survey table;
ALTER TABLE tanner_girls_survey
    ADD tanner_score_girls decimal(3,2),
    ADD Candidate_Age varchar(255),
    ADD Window_Difference varchar(255);

-- Add two new columns to parameter type table to be imported into the DQT.
INSERT INTO `parameter_type` (`Name`, `Type`, `Description`, `SourceField`, `SourceFrom`) VALUES
    ('TANNER_Boys_tanner_score_boys', 'varchar(255)', 'Tanner Stage of Physical Development (Boys)', 'tanner_score_boys', 'TANNER_Boys'),
    ('TANNER_Girls_tanner_score_girls', 'varchar(255)', 'Tanner Stage of Physical Development (Girls)', 'tanner_score_girls', 'TANNER_Girls'),
    ('tanner_boys_survey_Candidate_Age', 'varchar(255)', 'Candidate Age (Months)', 'Candidate_Age', 'tanner_boys_survey'),
    ('tanner_boys_survey_Window_Difference', 'varchar(255)', 'Window Difference (+/- Days)', 'Window_Difference', 'tanner_boys_survey'),
    ('tanner_girls_survey_Candidate_Age', 'varchar(255)', 'Candidate Age (Months)', 'Candidate_Age', 'tanner_girls_survey'),
    ('tanner_girls_survey_Window_Difference', 'varchar(255)', 'Window Difference (+/- Days)', 'Window_Difference', 'tanner_girls_survey');
