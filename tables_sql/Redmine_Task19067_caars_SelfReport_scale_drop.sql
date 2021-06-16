
-- Drop caars_SelfReport_scale version

DELETE FROM test_names WHERE Test_name = "caars_SelfReport_scale";
DELETE FROM instrument_subtests WHERE Test_name = "caars_SelfReport_scale";
DELETE FROM survey_test_battery WHERE Test_name = "caars_SelfReport_scale";
DROP TABLE caars_SelfReport_scale;
