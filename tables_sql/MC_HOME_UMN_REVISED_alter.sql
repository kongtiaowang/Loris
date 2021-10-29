ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN ira_completed_for_this_visit enum("no","yes") default NULL;
ALTER TABLE MC_HOME_UMN_REVISED ADD COLUMN ira_percentage varchar(10) default NULL;
