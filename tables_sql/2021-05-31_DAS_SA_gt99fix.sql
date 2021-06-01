-- -----------------------------------------------------------------
--
-- Updates all the percentile scores of DAS_SA:
-- 
-- Converts '&gt;99.9' to 'Greater than 99.9'
--
-- See https://redmine.cbrain.mcgill.ca/issues/19014
--
-- -----------------------------------------------------------------

UPDATE DAS_SA SET verbal_PERCENTILE               = 'Greater than 99.9' WHERE TRIM(verbal_PERCENTILE)               = '&gt;99.9';
UPDATE DAS_SA SET spatial_PERCENTILE              = 'Greater than 99.9' WHERE TRIM(spatial_PERCENTILE)              = '&gt;99.9';
UPDATE DAS_SA SET non_verb_reasoning_PERCENTILE   = 'Greater than 99.9' WHERE TRIM(non_verb_reasoning_PERCENTILE)   = '&gt;99.9';
UPDATE DAS_SA SET GCA_PERCENTILE                  = 'Greater than 99.9' WHERE TRIM(GCA_PERCENTILE)                  = '&gt;99.9';
UPDATE DAS_SA SET SNC_PERCENTILE                  = 'Greater than 99.9' WHERE TRIM(SNC_PERCENTILE)                  = '&gt;99.9';
UPDATE DAS_SA SET verbal_similarities_PERCENTILE  = 'Greater than 99.9' WHERE TRIM(verbal_similarities_PERCENTILE)  = '&gt;99.9';
UPDATE DAS_SA SET word_defn_PERCENTILE            = 'Greater than 99.9' WHERE TRIM(word_defn_PERCENTILE)            = '&gt;99.9';
UPDATE DAS_SA SET matrices_PERCENTILE             = 'Greater than 99.9' WHERE TRIM(matrices_PERCENTILE)             = '&gt;99.9';
UPDATE DAS_SA SET seq_qr_PERCENTILE               = 'Greater than 99.9' WHERE TRIM(seq_qr_PERCENTILE)               = '&gt;99.9';
UPDATE DAS_SA SET rd_PERCENTILE                   = 'Greater than 99.9' WHERE TRIM(rd_PERCENTILE)                   = '&gt;99.9';
UPDATE DAS_SA SET PC_PERCENTILE                   = 'Greater than 99.9' WHERE TRIM(PC_PERCENTILE)                   = '&gt;99.9';

