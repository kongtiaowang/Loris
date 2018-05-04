-- Update Connors to Conners table names
RENAME TABLE connors_parent TO conners_parent;
RENAME TABLE connors_teacher TO conners_teacher;
SET FOREIGN_KEY_CHECKS=0;
-- Update 'connors_teacher' to 'conners_teacher' in the flag table
UPDATE flag
    SET Test_name = "conners_teacher"
    WHERE Test_name = "connors_teacher";
-- Update 'connors_parent' to 'conners_parent' in the flag table
UPDATE flag
    SET Test_name = "conners_parent"
    WHERE Test_name = "connors_parent";
-- Update Connors to Conners in test_names
UPDATE test_names SET Test_name="conners_parent" WHERE Test_name="connors_parent";
UPDATE test_names SET Test_name="conners_teacher" WHERE Test_name="connors_teacher";
-- Update Connors to Conners in test_battery
UPDATE test_battery SET Test_name="conners_parent" WHERE Test_name="connors_parent";
UPDATE test_battery SET Test_name="conners_teacher" WHERE Test_name="connors_teacher";
-- Update Connors to Conners in instrument_subtests
UPDATE instrument_subtests
  SET Test_name="conners_parent", Subtest_name="conners_parent_page1"
  WHERE Test_name="connors_parent";
UPDATE instrument_subtests
  SET Test_name="conners_teacher", Subtest_name="conners_teacher_page1"
  WHERE Test_name="connors_teacher";
SET FOREIGN_KEY_CHECKS=1;