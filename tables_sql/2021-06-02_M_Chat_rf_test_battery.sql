-- ------------------------------------------------------------------
--
-- Removes the inactive m_char_rf entry in table test_battery
-- This entry causes a bug that would make the m_chat_rf instrument
-- appears twice on the visit page for all candidates.
--
-- See https://redmine.cbrain.mcgill.ca/issues/19172
--
-- ------------------------------------------------------------------


DELETE FROM test_battery WHERE test_name='m_chat_rf' AND Active='N';

