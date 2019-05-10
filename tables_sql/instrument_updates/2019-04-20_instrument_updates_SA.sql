-- Add describe to CBCL_6_18
ALTER TABLE CBCL_6_To_18 ADD COLUMN `q77_describe` varchar (100) default NULL;
-- Remove BOT2 from VSA battery
UPDATE `test_battery` SET `Active`='N' WHERE `test_name`='BOT2' and Visit_label='VSA';
