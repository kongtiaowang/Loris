-- -----------------------------------------------------------------
-- 
-- SQL statements that reenable the Data Team Helper module in IBIS
-- (Visible=NULL => module is visible)
-- 
-- -----------------------------------------------------------------

UPDATE LorisMenu SET Visible=NULL WHERE Label='Data Team Helper';
