
-- UPDATE the form name

UPDATE test_names SET Full_name="SCARED (Screen for Adult Anxiety Related Disorders) - Adult Dad - Survey" WHERE Test_name = "SCAARED_Dad";
UPDATE test_names SET Full_name="SCARED (Screen for Adult Anxiety Related Disorders) - Adult - Mom - Survey" WHERE Test_name = "SCAARED_Mom";
UPDATE test_names SET Full_name="SCARED (Screen for Child Anxiety Related Disorders) - Child - Sibling - Survey" WHERE Test_name = "SCARED_Sibling";
UPDATE test_names SET Full_name="SCARED (Screen for Child Anxiety Related Disorders) - Child - Subject - Survey" WHERE Test_name = "SCARED_Subject";

-- Drop SCARED Child old version

DELETE FROM test_names WHERE Test_name="SCARED_Child";
DELETE FROM instrument_subtests WHERE Test_name="SCARED_Child";
DELETE FROM test_battery WHERE Test_name="SCARED_Child";



