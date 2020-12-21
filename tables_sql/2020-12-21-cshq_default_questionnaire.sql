ALTER TABLE CSHQ ALTER which_cshq_did_you_administer SET DEFAULT 'b_long_form';
UPDATE CSHQ SET which_cshq_did_you_administer = 'b_long_form' WHERE which_cshq_did_you_administer IS NULL;
