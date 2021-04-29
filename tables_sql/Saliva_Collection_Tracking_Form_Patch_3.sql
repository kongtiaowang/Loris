INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES
 ('Saliva_Collection_Tracking_Form','Saliva_Collection_Tracking_Form_page5', "Other", 5);


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq4_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq4_2`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq5_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq7_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq7_2`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq7_3`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN  `sq4` date default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `sq5` varchar(255) default NULL;
alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq6` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `sq7` varchar(255) default NULL;
alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq8` varchar(255) default NULL;
alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq9` date default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `sq10` text default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq8_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq8_2`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq9_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq11_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq11_2`;


alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq5` varchar(255) NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq6` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq7` date default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `pq8` varchar(255) default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `pq9` date default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq10` varchar(255) default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `pq11` varchar(255) default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq12` varchar(255) default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq13` date default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `pq14` text default NULL;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq4_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq4_2`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq5_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq7_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq7_2`;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `mq4` date default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `mq5` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `mq6` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `mq7` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `mq8` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `mq9` date default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `mq10` text default NULL;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq4_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq4_2`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq5_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq7_1`;
alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq7_2`;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `fq4` date default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `fq5` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `fq6` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `fq7` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `fq8` varchar(255) default NULL;
ALTER TABLE `Saliva_Collection_Tracking_Form` MODIFY COLUMN `fq9` date default NULL;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `aq3` varchar(255) default NULL;

