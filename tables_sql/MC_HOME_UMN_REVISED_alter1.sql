ALTER TABLE MC_HOME_UMN_REVISED CHANGE `routine_and_responsibility` `responsivity` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `emotional_need` `encouragement_of_maturity` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `learning_behavior` `emotional_climate` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `recreational_activity` `learning_materials_and_opportunities` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `place_or_travel` `enrichment` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `family_friend` `family_companionship` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `house` `family_integration` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED CHANGE `parent_child_interaction` `physical_environment` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED DROP COLUMN `parent_visitor_interaction`;

UPDATE instrument_subtests SET Description = "RESPONSIVITY"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 1;
UPDATE instrument_subtests SET Description = "ENCOURAGEMENT OF MATURITY"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 2;
UPDATE instrument_subtests SET Description = "EMOTIONAL CLIMATE"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 3;
UPDATE instrument_subtests SET Description = "LEARNING MATERIALS AND OPPORTUNITIES"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 4;
UPDATE instrument_subtests SET Description = "ENRICHMENT"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 5;
UPDATE instrument_subtests SET Description = "FAMILY COMPANIONSHIP"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 6;
UPDATE instrument_subtests SET Description = "FAMILY INTEGRATION"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 7;
UPDATE instrument_subtests SET Description = "PYSICAL ENVIRONMENT"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 8;
DELETE FROM instrument_subtests WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 9;
