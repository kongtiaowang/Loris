--Current column type will break the date entry contents to display/update in database--
ALTER TABLE `aims` CHANGE COLUMN `data_entry_error` `data_entry_error` TEXT NULL DEFAULT NULL  ;

