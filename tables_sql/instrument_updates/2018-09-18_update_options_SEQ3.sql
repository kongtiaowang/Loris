-- Adding new columns for SEQ3 as the old one contain different response options
ALTER TABLE SEQ3 ADD COLUMN 100_how_childs_sensory_avoidances_changed_1 enum('much_less_avoidant','somewhat_less_avoidant','unchanged','somewhat_more_avoidant','much_more_avoidant') default NULL ;
ALTER TABLE SEQ3 ADD COLUMN 103_how_have_sensory_fascinations_changed_1 enum('much_less_intense','somewhat_less_avoidant','unchanged','somewhat_more_intense','much_more_intense') default NULL ;

