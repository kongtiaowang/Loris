ALTER TABLE SRS ADD COLUMN `mannerisms_score` varchar(255) default NULL AFTER `srs_score`;
ALTER TABLE SRS ADD COLUMN `motivation_score` varchar(255) default NULL AFTER `srs_score`;
ALTER TABLE SRS ADD COLUMN `communication_score` varchar(255) default NULL AFTER `srs_score`;
ALTER TABLE SRS ADD COLUMN `cognition_score` varchar(255) default NULL AFTER `srs_score`;
ALTER TABLE SRS ADD COLUMN `awareness_score` varchar(255) default NULL AFTER `srs_score`;
