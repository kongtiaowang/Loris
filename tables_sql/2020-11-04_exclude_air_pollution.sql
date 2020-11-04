-- ------------------------------------------------------------------
--
-- Adds instrument air_pollution to the list of excluded instruments 
--
-- ------------------------------------------------------------------

INSERT INTO Config (ConfigID, Value) SELECT ID, "air_pollution" FROM ConfigSettings WHERE Name="excluded_instruments";
