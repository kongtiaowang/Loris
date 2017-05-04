DELETE FROM test_battery WHERE ID=611 ;
DELETE FROM test_battery WHERE ID=622 ;
DELETE FROM test_battery WHERE ID=942 ;
DELETE FROM test_battery WHERE ID=953 ;
ALTER TABLE test_battery ADD UNIQUE `unique_test` (`Test_name`,`AgeMinDays`, `AgeMaxDays`, `Active`, `Stage`, `SubprojectID`, `Visit_label`, `CenterID`, `firstVisit`, `instr_order`);

