DROP TABLE IF EXISTS BRIEF2_Parent_lookup;

CREATE TABLE `BRIEF2_Parent_lookup` (
                 	`age_years` varchar(50) DEFAULT NULL,
                 	`sex` enum('Male','Female') DEFAULT NULL,
                 	`scale` varchar(100) DEFAULT NULL,
			            `scale_raw_score` varchar(10) DEFAULT NULL,
		  	          `scale_T_score` varchar(10) DEFAULT NULL,
		  	          `scale_percentile` varchar(10) DEFAULT NULL,
		  	          `scale_CI` varchar(10)DEFAULT NULL
		  	)ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT
	INTO
		`bot2_scale_score_lookup`
	VALUES(
		'4.0-4.3',
		'both_sexes',
		'subtest_1',
		'35',
		'36-41'
	);


