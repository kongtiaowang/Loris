ALTER TABLE BRIEF2_Parent ADD COLUMN relationship_to_child_other varchar(255) default NULL;
ALTER TABLE BRIEF2_Parent MODIFY COLUMN relationship_to_child enum ('mother', 'father', 'step_mother', 'step_father', 'other') default NULL;
