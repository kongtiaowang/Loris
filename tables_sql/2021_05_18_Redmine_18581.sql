-- Add dropdown options for
--     Withdrawn - can use data
--     Withdrawn - can not use data
-- in participant status form.
INSERT INTO `participant_status_options` (`ID`, `Description`, `Required`) VALUES
        ('14', 'Withdrawn - can use data', '0'),
        ('15', 'Withdrawn - can not use data', '0');
