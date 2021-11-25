alter table `tanner_girls_survey` ADD COLUMN  `Data_entry_completion_status1` enum('Incomplete','Complete') NOT NULL default 'Incomplete' AFTER `Date_taken`;

