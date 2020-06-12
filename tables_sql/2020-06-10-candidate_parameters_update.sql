-- Redmine 17902
-- Add new participant_status Active-Flagged
INSERT INTO `participant_status_options` (`ID`, `Description`, `Required`) VALUES ('13', 'Active - Flagged', '0');
-- Any child Caveat Emptor Flag = True should be categorized as "Active-Flagged" - Done
UPDATE participant_status ps join candidate c ON (c.CandID=ps.CandID) SET ps.participant_status=13 where c.flagged_caveatemptor='True';