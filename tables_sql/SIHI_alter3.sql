ALTER TABLE SIHI ADD COLUMN what_year_was_your_child_born varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN where_were_you_living_at_the_time varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN where_did_your_child_sleep varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN any_significant_family_events varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN i_q2_please_describe_concern varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN ii_q2_please_describe_concern varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN iii_q2_please_describe_concern varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN iv_q2_please_describe_concern varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN v_q2_please_describe_concern varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN i_q5_if_yes_select_other varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN ii_q5_if_yes_select_other varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN iii_q5_if_yes_select_other varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN iv_q5_if_yes_select_other varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN v_q5_if_yes_select_other varchar(100) default NULL;
ALTER TABLE SIHI ADD COLUMN i_q5_additional_comment varchar(250) default NULL;
ALTER TABLE SIHI ADD COLUMN ii_q5_additional_comment varchar(250) default NULL;
ALTER TABLE SIHI ADD COLUMN iii_q5_additional_comment varchar(250) default NULL;
ALTER TABLE SIHI ADD COLUMN iv_q5_additional_comment varchar(250) default NULL;
ALTER TABLE SIHI ADD COLUMN v_q5_additional_comment varchar(250) default NULL;