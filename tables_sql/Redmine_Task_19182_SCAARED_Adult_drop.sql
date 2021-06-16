
-- Drop SCAARED_Adult version

DELETE FROM test_names WHERE Test_name = "SCAARED_Adult";
DELETE FROM instrument_subtests WHERE Test_name = "SCAARED_Adult";
DELETE FROM survey_test_battery WHERE Test_name = "SCAARED_Adult";
DROP TABLE SCAARED_Adult;
