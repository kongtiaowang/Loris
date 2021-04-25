update instrument_subtests  SET Description = "Subject" where Subtest_name="Saliva_Collection_Tracking_Form_page1";

update instrument_subtests  SET Description = "Proband" where Subtest_name="Saliva_Collection_Tracking_Form_page2";

update instrument_subtests  SET Description = "Mother" where Subtest_name="Saliva_Collection_Tracking_Form_page3";

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Saliva_Collection_Tracking_Form','Saliva_Collection_Tracking_Form_page4', "Father", 4);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 7, 'VSA', NULL);

INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('Saliva_Collection_Tracking_Form', '0', '0', 'Y', 'Visit', 7, 'VSA-CVD', NULL);


alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq1` enum('yes','no','0')  default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq2` enum('At_Visit','Via_Mail') default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq3` date default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq4`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq4_1` date default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq4_2` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq4_3` enum('true','false') default 'false';

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq5`;

ALTER TABLE `Saliva_Collection_Tracking_Form` ADD COLUMN `sq5_1` enum('At_Visit','Via_Mail') default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq5_2` varchar(255) NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `sq6` varchar(255) NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq7`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq7_1` enum('yes','no') default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq7_2` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq7_3` text default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq8` date default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq8_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq8_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq8_3`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `sq9` text default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq9_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq9_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq10`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq11_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq11_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq12`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `sq13`;




alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq1` enum('yes','no','0')  default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq2` enum('yes','no','0') default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq3` enum('refused','not_asked') default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq4` date default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq5` enum('yes','no') default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq6` enum('At_Visit','Via_Mail') default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq7` date default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq8`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq8_1` date default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq8_2` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq8_3` enum('true','false') default 'false';

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq9_1` enum('At_Visit','Via_Mail')  default NULL;

alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq9_2` enum('true','false') default 'false';

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq9_3`;




alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq10_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq10_2`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq10` varchar(255) default NULL;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq11`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq11_1` enum('yes','no') default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq11_2` varchar(255) default NULL;



alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq12_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq12_2`;


alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `pq12` date default NULL;


alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `pq13` text default NULL;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `pq14`;













alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `mq1` enum('yes','no','0')  default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq2`  enum('At_Visit','Via_Mail')   default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq3`;


alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq3` date default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq4`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq4_1` date default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq4_2` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq4_3` enum('true','false') default 'false';


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq5`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq5_1`  enum('At_Visit','Via_Mail')   default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq5_2` enum('true','false') default 'false';


alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `mq6` varchar(255)  default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq7`;



alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq7_1` enum('yes','no') NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq7_2` varchar(255) default NULL;



alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq8` date default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `mq9` text default NULL;




alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq8_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq8_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq8_3`;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq9_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq9_2`;



alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq10`;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq11_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq11_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq13`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `mq12`;





alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `fq1` enum('yes','no','0')  default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq2`  enum('At_Visit','Via_Mail')   default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq3`;


alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq3` date default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq4`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq4_1` date default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq4_2` varchar(255) default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq4_3` enum('true','false') default 'false';


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq5`;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq5_1`  enum('At_Visit','Via_Mail')   default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq5_2` enum('true','false') default 'false';


alter table `Saliva_Collection_Tracking_Form` MODIFY COLUMN `fq6` varchar(255)  default NULL;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq7`;



alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq7_1` enum('yes','no') NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq7_2` varchar(255) default NULL;



alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq8` date default NULL;

alter table `Saliva_Collection_Tracking_Form` ADD COLUMN `fq9` text default NULL;





alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq8_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq8_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq8_3`;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq9_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq9_2`;



alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq10`;


alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq11_1`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq11_2`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq13`;

alter table `Saliva_Collection_Tracking_Form` DROP COLUMN `fq12`;
