-- Redmine 18965
UPDATE participant_accounts
SET status = 'Sent'
WHERE sessionid = (
    SELECT id
    FROM session
    WHERE candid=815769
    AND visit_label='V06-CVD'
)
AND test_name = 'pspq_InformantReport_mom_on_dad';

-- Redmine 18952
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('CBCL_6_To_18','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('MASC2_Parent','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('MASC2_Self_Report','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('QRS','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('rbs_r','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('SRS2_SchoolAge_Parent','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('tanner_boys_survey','VSA-Sleep');
INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('tanner_girls_survey','VSA-Sleep');