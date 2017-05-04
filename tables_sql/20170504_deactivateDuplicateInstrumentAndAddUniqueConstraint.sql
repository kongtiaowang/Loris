UPDATE test_battery SET Active='N' WHERE ID=611 ;
UPDATE test_battery SET Active='N' WHERE ID=622 ;
UPDATE test_battery SET Active='N' WHERE ID=942 ;
UPDATE test_battery SET Active='N' WHERE ID=953 ;
ALTER TABLE test_battery ADD UNIQUE `unique_test` (`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `CenterID`, `firstVisit`, `instr_order`);

