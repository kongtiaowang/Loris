ALTER TABLE MASC2_Parent ADD COLUMN masc2_total_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN SP_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN GAD_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN SA_total_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN HR_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN PF_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN OC_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN PS_total_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN Panic_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN TR_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN HA_score varchar(50) default NULL;



ALTER TABLE MASC2_Parent ADD COLUMN masc2_total_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN SP_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN GAD_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN SA_total_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN HR_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN PF_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN OC_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN PS_total_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN Panic_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN TR_T_score varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN HA_T_score varchar(50) default NULL;


ALTER TABLE MASC2_Parent ADD COLUMN masc2_total_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN SP_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN GAD_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN SA_total_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN HR_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN PF_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN OC_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN PS_total_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN Panic_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN TR_classification varchar(50) default NULL;
ALTER TABLE MASC2_Parent ADD COLUMN HA_classification varchar(50) default NULL;

ALTER TABLE MASC2_Parent ADD COLUMN score_validity TEXT default NULL;

ALTER TABLE MASC2_Parent ADD COLUMN anxiety_probability_score TEXT default NULL;
