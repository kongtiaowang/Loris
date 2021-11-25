alter table `tanner_boys_survey` ADD COLUMN  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete' AFTER `Date_taken`;
