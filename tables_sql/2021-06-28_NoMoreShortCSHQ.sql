-- --------------------------------------------------------------------
--
-- Ensure that if question 'Which version of the CSHQ was administered'
-- was not answered, then the long version of the questionnaire is
-- used
--
-- Fixes https://redmine.cbrain.mcgill.ca/issues/19165. 
--
-- --------------------------------------------------------------------

UPDATE CSHQ SET which_cshq_did_you_administer='b_long_form' WHERE which_cshq_did_you_administer IS NULL;
