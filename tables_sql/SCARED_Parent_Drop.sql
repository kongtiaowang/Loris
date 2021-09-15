
-- Drop SCARED_Parent version

DELETE FROM test_names WHERE Test_name = "SCARED_Parent";
DELETE FROM instrument_subtests WHERE Test_name = "SCARED_Parent";
DELETE FROM survey_test_battery WHERE Test_name = "SCARED_Parent";
DROP TABLE SCARED_Parent;
