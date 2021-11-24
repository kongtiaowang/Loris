DELETE survey_test_battery, test_names from test_names inner join survey_test_battery
ON survey_test_battery.Test_name=test_names.Test_name WHERE survey_test_battery.Visit_label
IN('LR-Arousal-V1', 'All') AND survey_test_battery.Test_name='SRS2_SchoolAge_Parent_proband';

DELETE survey_test_battery, test_names from test_names inner join survey_test_battery
ON survey_test_battery.Test_name=test_names.Test_name WHERE survey_test_battery.Visit_label
IN('LR-Arousal-V1', 'All') AND survey_test_battery.Test_name='rbs_r_proband';
