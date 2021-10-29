ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `routine_and_responsibility` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `emotional_need` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `learning_behavior` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `recreational_activity` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `place_or_travel` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `family_friend` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `house` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `parent_child_interaction` varchar(10) default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN `parent_visitor_interaction` varchar(10) default NULL;

UPDATE instrument_subtests SET Description = "ROUTINES AND RESPONSIBILITY"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 1;
UPDATE instrument_subtests SET Description = "EMOTIONAL NEEDS"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 2;
UPDATE instrument_subtests SET Description = "LEARNING BEHAVIOR"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 3;
UPDATE instrument_subtests SET Description = "RECREATIONAL ACTIVITIES"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 4;
UPDATE instrument_subtests SET Description = "PLACES/TRAVEL"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 5;
UPDATE instrument_subtests SET Description = "FAMILY AND FRIENDS"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 6;
UPDATE instrument_subtests SET Description = "HOUSE"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 7;
UPDATE instrument_subtests SET Description = "PARENT-CHILD INTERACTIONS"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 8;
UPDATE instrument_subtests SET Description = "PARENT-VISITOR INTERACTIONS"
WHERE Test_name = "MC_HOME_UMN_REVISED" AND Order_number = 9;
