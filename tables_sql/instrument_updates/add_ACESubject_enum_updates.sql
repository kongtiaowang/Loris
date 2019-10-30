ALTER TABLE ACESubjectMedicalHistory MODIFY COLUMN preg_complic enum('yes', 'no', 'nk', 'not_answered','')  default NULL ;
ALTER TABLE ACESubjectMedicalHistory MODIFY COLUMN preg_dxdrug enum('yes', 'no', 'nk', 'not_answered','')  default NULL ;

