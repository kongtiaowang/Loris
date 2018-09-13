-- Fixing Unknown_Columns in field list for SRS2_SchoolAge
ALTER TABLE SRS2_SchoolAge ADD COLUMN Candidate_Age varchar (100);
ALTER TABLE SRS2_SchoolAge ADD COLUMN Window_Difference varchar (100);
-- Fixing Unknown_Columns in field list for CBCL
ALTER TABLE CBCL_6_To_18 ADD COLUMN Candidate_Age varchar (100);
ALTER TABLE CBCL_6_To_18 ADD COLUMN Window_Difference varchar (100);
-- Fixing Unknown_Columns in field list for SSIS
ALTER TABLE SSIS_Parent ADD COLUMN Candidate_Age varchar (100);
ALTER TABLE SSIS_Parent ADD COLUMN Window_Difference varchar (100);
ALTER TABLE SSIS_Teacher ADD COLUMN Candidate_Age varchar (100);
ALTER TABLE SSIS_Teacher ADD COLUMN Window_Difference varchar (100);



