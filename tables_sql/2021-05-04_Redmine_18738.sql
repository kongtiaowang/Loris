ALTER TABLE pspq_SelfReport_dad ADD `aloof_score` varchar(255) default NULL AFTER `respondent_gender`;
ALTER TABLE pspq_SelfReport_dad ADD `prs_score` varchar(255) default NULL AFTER `aloof_score`;
ALTER TABLE pspq_SelfReport_dad ADD `rigid_score` varchar(255) default NULL AFTER `prs_score`;
ALTER TABLE pspq_SelfReport_dad ADD `total_score` varchar(255) default NULL AFTER `rigid_score`;

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_SelfReport_dad', 'pspq_SelfReport_dad_page1', 'Page 1', 1);
UPDATE instrument_subtests SET Description = 'Page 2', Order_number = 2 WHERE Test_name = 'pspq_SelfReport_dad' AND Subtest_name = 'pspq_SelfReport_dad_page2';
UPDATE instrument_subtests SET Description = 'Page 3', Order_number = 3 WHERE Test_name = 'pspq_SelfReport_dad' AND Subtest_name = 'pspq_SelfReport_dad_page3';

ALTER TABLE pspq_SelfReport_mom ADD `aloof_score` varchar(255) default NULL AFTER `respondent_gender`;
ALTER TABLE pspq_SelfReport_mom ADD `prs_score` varchar(255) default NULL AFTER `aloof_score`;
ALTER TABLE pspq_SelfReport_mom ADD `rigid_score` varchar(255) default NULL AFTER `prs_score`;
ALTER TABLE pspq_SelfReport_mom ADD `total_score` varchar(255) default NULL AFTER `rigid_score`;

INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_SelfReport_mom', 'pspq_SelfReport_mom_page1', 'Page 1', 1);
UPDATE instrument_subtests SET Description = 'Page 2', Order_number = 2 WHERE Test_name = 'pspq_SelfReport_mom' AND Subtest_name = 'pspq_SelfReport_mom_page2';
UPDATE instrument_subtests SET Description = 'Page 3', Order_number = 3 WHERE Test_name = 'pspq_SelfReport_mom' AND Subtest_name = 'pspq_SelfReport_mom_page3';

ALTER TABLE pspq_InformantReport_mom_on_dad ADD `aloof_score` varchar(255) default NULL AFTER `respondent_gender`;
ALTER TABLE pspq_InformantReport_mom_on_dad ADD `prs_score` varchar(255) default NULL AFTER `aloof_score`;
ALTER TABLE pspq_InformantReport_mom_on_dad ADD `rigid_score` varchar(255) default NULL AFTER `prs_score`;
ALTER TABLE pspq_InformantReport_mom_on_dad ADD `total_score` varchar(255) default NULL AFTER `rigid_score`;

UPDATE test_names SET Full_name = "PSPQ Mom's Report on Dad (Send to Mom)" WHERE Test_name = 'pspq_InformantReport_mom_on_dad';
UPDATE instrument_subtests SET Description = 'Page 1', Subtest_name = 'pspq_InformantReport_mom_on_dad_page1' WHERE Test_name = 'pspq_InformantReport_mom_on_dad' AND Order_number = 1;
UPDATE instrument_subtests SET Description = 'Page 2', Subtest_name = 'pspq_InformantReport_mom_on_dad_page2' WHERE Test_name = 'pspq_InformantReport_mom_on_dad' AND Order_number = 2;
UPDATE instrument_subtests SET Description = 'Page 3', Subtest_name = 'pspq_InformantReport_mom_on_dad_page3' WHERE Test_name = 'pspq_InformantReport_mom_on_dad' AND Order_number = 3;