INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('pspq_SelfReport_dad', 'PSPQ Dad Self Report (Send to Dad)', '13','1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_SelfReport_dad', 'pspq_SelfReport_dad_page2', 'PSPQ Self Report Dad Page 2', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_SelfReport_dad', 'pspq_SelfReport_dad_page3', 'PSPQ Self Report Dad Page 3', 2);


INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('pspq_SelfReport_mom', 'PSPQ Mom Self Report (Send to Mom)', '13','1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_SelfReport_mom', 'pspq_SelfReport_mom_page2', 'PSPQ Self Report Mom Page 2', 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_SelfReport_mom', 'pspq_SelfReport_mom_page3', 'PSPQ Self Report Mom Page 3', 2);

INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('pspq_InformantReport_dad_on_mom', "PSPQ Dad's Report on Mom (Send to Dad)", '13','1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_InformantReport_dad_on_mom', 'pspq_InformantReport_dad_on_mom_page2', "PSPQ Dad's Report on Mom Page 2", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_InformantReport_dad_on_mom', 'pspq_InformantReport_dad_on_mom_page3', "PSPQ Dad's Report on Mom Page 3", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_InformantReport_dad_on_mom', 'pspq_InformantReport_dad_on_mom_page4', "PSPQ Dad's Report on Mom Page 4", 3);

INSERT INTO test_names (Test_name, Full_name, Sub_group,IsDirectEntry) VALUES ('pspq_InformantReport_mom_on_dad', "PSPQ Mom's Report on Dad(Send to Mom)", '13','1');
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_InformantReport_mom_on_dad', 'pspq_InformantReport_mom_on_dad_page2', "PSPQ Mom's Report on Dad Page 2", 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_InformantReport_mom_on_dad', 'pspq_InformantReport_mom_on_dad_page3', "PSPQ Mom's Report on Dad Page 3", 2);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_InformantReport_mom_on_dad', 'pspq_InformantReport_mom_on_dad_page4', "PSPQ Mom's Report on Dad Page 4", 3);

UPDATE test_names SET IsDirectEntry=0 where Test_name IN ('pspq_1','pspq_2');