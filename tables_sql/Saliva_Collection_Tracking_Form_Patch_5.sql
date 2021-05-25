ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq2` enum('At_Visit','Via_Mail','refused') default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq6` enum('At_Visit','Via_Mail','refused') default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `mq2` enum('At_Visit','Via_Mail','refused') default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `fq2` enum('At_Visit','Via_Mail','refused') default NULL;




alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq7`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq8`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq9`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq10`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq11`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq12`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq13`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq14`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq7`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq8`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq9`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq10`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq7`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq8`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq9`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq10`;
