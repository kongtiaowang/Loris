-- Drop all the duplicate rows. As an added benefit, future INSERTs that are duplicates will error out.

ALTER IGNORE TABLE test_battery
ADD UNIQUE INDEX idx_name (SubprojectID, Test_name, Visit_label);