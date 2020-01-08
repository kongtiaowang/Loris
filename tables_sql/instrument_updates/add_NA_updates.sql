ALTER TABLE MASC2_Parent MODIFY COLUMN q3 enum('0','1','2','3','NA')  default NULL ;
ALTER TABLE MASC2_Self_Report MODIFY COLUMN q3 enum('0','1','2','3','NA')  default NULL ;
ALTER TABLE SEQ3 MODIFY COLUMN 46_bothered_by_tags_or_seams  enum('never','once_in_a_while','sometimes','frequently','always','NA') default NULL;
ALTER TABLE SEQ3 MODIFY COLUMN 74_trouble_distinguishing_different_tastes_or_flavors  enum('never','once_in_a_while','sometimes','frequently','always','NA') default NULL;
ALTER TABLE SEQ3 MODIFY COLUMN 91_confuse_which_sense_something_is_from  enum('never','once_in_a_while','sometimes','frequently','always','NA') default NULL;
