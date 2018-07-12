-- changing the wrong column name associated with child'd birth date in CCC2
ALTER TABLE `CCC2` CHANGE COLUMN `user_birthdate_date` `user_birthdate` DATE NULL DEFAULT NULL ;