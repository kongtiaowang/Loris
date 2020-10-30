-- Redmine 18278
ALTER TABLE `TSI_EP` MODIFY COLUMN `when_diagnosed_with_autism` varchar(128) default NULL;
ALTER TABLE `TSI_EP` ADD pro_devfactors_q5a_head_injury enum('yes','no') default NULL AFTER pro_devfactors_q5_other;