alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `top_use_date_visit` date default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq3` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `aq1` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq_tracking_no` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq_tracking_no` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq_tracking_no` varchar(255) default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `fq10` text default NULL;
