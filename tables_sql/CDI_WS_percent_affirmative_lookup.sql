DROP TABLE IF EXISTS CDI_WS_percent_affirmative_lookup;

CREATE TABLE `CDI_WS_percent_affirmative_lookup` (
                 	`age_months` int(3) NOT NULL,
                 	`sex` enum("male","female", "both_sexes") NOT NULL,
			`subscale` varchar(255) NOT NULL,
		  	`percentage_affirmative` int(3) NOT NULL
		  	) TYPE=MyISAM;


INSERT INTO CDI_WS_percent_affirmative_lookup VALUES
('16', 'both_sexes', 'word_endings_plural', '11'),
('17', 'both_sexes', 'word_endings_plural', '16'),
('18', 'both_sexes', 'word_endings_plural', '27'),
('19', 'both_sexes', 'word_endings_plural', '45'),
('20', 'both_sexes', 'word_endings_plural', '42'),
('21', 'both_sexes', 'word_endings_plural', '42'),
('22', 'both_sexes', 'word_endings_plural', '59'),
('23', 'both_sexes', 'word_endings_plural', '69'),
('24', 'both_sexes', 'word_endings_plural', '63'),
('25', 'both_sexes', 'word_endings_plural', '69'),
('26', 'both_sexes', 'word_endings_plural', '78'),
('27', 'both_sexes', 'word_endings_plural', '76'),
('28', 'both_sexes', 'word_endings_plural', '86'),
('29', 'both_sexes', 'word_endings_plural', '83'),
('30', 'both_sexes', 'word_endings_plural', '93'),
('16', 'both_sexes', 'word_endings_possessive', '8'),
('17', 'both_sexes', 'word_endings_possessive', '19'),
('18', 'both_sexes', 'word_endings_possessive', '21'),
('19', 'both_sexes', 'word_endings_possessive', '31'),
('20', 'both_sexes', 'word_endings_possessive', '47'),
('21', 'both_sexes', 'word_endings_possessive', '48'),
('22', 'both_sexes', 'word_endings_possessive', '64'),
('23', 'both_sexes', 'word_endings_possessive', '75'),
('24', 'both_sexes', 'word_endings_possessive', '70'),
('25', 'both_sexes', 'word_endings_possessive', '74'),
('26', 'both_sexes', 'word_endings_possessive', '79'),
('27', 'both_sexes', 'word_endings_possessive', '84'),
('28', 'both_sexes', 'word_endings_possessive', '86'),
('29', 'both_sexes', 'word_endings_possessive', '86'),
('30', 'both_sexes', 'word_endings_possessive', '91'),
('16', 'both_sexes', 'word_endings_past', '0'),
('17', 'both_sexes', 'word_endings_past', '4'),
('18', 'both_sexes', 'word_endings_past', '2'),
('19', 'both_sexes', 'word_endings_past', '9'),
('20', 'both_sexes', 'word_endings_past', '11'),
('21', 'both_sexes', 'word_endings_past', '13'),
('22', 'both_sexes', 'word_endings_past', '21'),
('23', 'both_sexes', 'word_endings_past', '34'),
('24', 'both_sexes', 'word_endings_past', '35'),
('25', 'both_sexes', 'word_endings_past', '36'),
('26', 'both_sexes', 'word_endings_past', '48'),
('27', 'both_sexes', 'word_endings_past', '50'),
('28', 'both_sexes', 'word_endings_past', '58'),
('29', 'both_sexes', 'word_endings_past', '64'),
('30', 'both_sexes', 'word_endings_past', '74'),
('16', 'both_sexes', 'word_endings_progressive', '4'),
('17', 'both_sexes', 'word_endings_progressive', '5'),
('18', 'both_sexes', 'word_endings_progressive', '14'),
('19', 'both_sexes', 'word_endings_progressive', '18'),
('20', 'both_sexes', 'word_endings_progressive', '27'),
('21', 'both_sexes', 'word_endings_progressive', '27'),
('22', 'both_sexes', 'word_endings_progressive', '48'),
('23', 'both_sexes', 'word_endings_progressive', '61'),
('24', 'both_sexes', 'word_endings_progressive', '56'),
('25', 'both_sexes', 'word_endings_progressive', '65'),
('26', 'both_sexes', 'word_endings_progressive', '64'),
('27', 'both_sexes', 'word_endings_progressive', '69'),
('28', 'both_sexes', 'word_endings_progressive', '82'),
('29', 'both_sexes', 'word_endings_progressive', '80'),
('30', 'both_sexes', 'word_endings_progressive', '94'),
('16', 'both_sexes', 'how_use_absent_comp', '91'),
('17', 'both_sexes', 'how_use_absent_comp', '94'),
('18', 'both_sexes', 'how_use_absent_comp', '91'),
('19', 'both_sexes', 'how_use_absent_comp', '91'),
('20', 'both_sexes', 'how_use_absent_comp', '96'),
('21', 'both_sexes', 'how_use_absent_comp', '94'),
('22', 'both_sexes', 'how_use_absent_comp', '99'),
('23', 'both_sexes', 'how_use_absent_comp', '95'),
('24', 'both_sexes', 'how_use_absent_comp', '98'),
('25', 'both_sexes', 'how_use_absent_comp', '95'),
('26', 'both_sexes', 'how_use_absent_comp', '98'),
('27', 'both_sexes', 'how_use_absent_comp', '96'),
('28', 'both_sexes', 'how_use_absent_comp', '96'),
('29', 'both_sexes', 'how_use_absent_comp', '99'),
('30', 'both_sexes', 'how_use_absent_comp', '99'),
('16', 'both_sexes', 'how_use_absent_owner', '60'),
('17', 'both_sexes', 'how_use_absent_owner', '67'),
('18', 'both_sexes', 'how_use_absent_owner', '75'),
('19', 'both_sexes', 'how_use_absent_owner', '82'),
('20', 'both_sexes', 'how_use_absent_owner', '83'),
('21', 'both_sexes', 'how_use_absent_owner', '83'),
('22', 'both_sexes', 'how_use_absent_owner', '91'),
('23', 'both_sexes', 'how_use_absent_owner', '93'),
('24', 'both_sexes', 'how_use_absent_owner', '95'),
('25', 'both_sexes', 'how_use_absent_owner', '94'),
('26', 'both_sexes', 'how_use_absent_owner', '97'),
('27', 'both_sexes', 'how_use_absent_owner', '93'),
('28', 'both_sexes', 'how_use_absent_owner', '95'),
('29', 'both_sexes', 'how_use_absent_owner', '98'),
('30', 'both_sexes', 'how_use_absent_owner', '99'),
('16', 'both_sexes', 'how_use_absent_production', '61'),
('17', 'both_sexes', 'how_use_absent_production', '65'),
('18', 'both_sexes', 'how_use_absent_production', '73'),
('19', 'both_sexes', 'how_use_absent_production', '80'),
('20', 'both_sexes', 'how_use_absent_production', '80'),
('21', 'both_sexes', 'how_use_absent_production', '81'),
('22', 'both_sexes', 'how_use_absent_production', '87'),
('23', 'both_sexes', 'how_use_absent_production', '91'),
('24', 'both_sexes', 'how_use_absent_production', '89'),
('25', 'both_sexes', 'how_use_absent_production', '91'),
('26', 'both_sexes', 'how_use_absent_production', '93'),
('27', 'both_sexes', 'how_use_absent_production', '89'),
('28', 'both_sexes', 'how_use_absent_production', '91'),
('29', 'both_sexes', 'how_use_absent_production', '98'),
('30', 'both_sexes', 'how_use_absent_production', '96'),
('16', 'both_sexes', 'how_use_absent_future', '19'),
('17', 'both_sexes', 'how_use_absent_future', '35'),
('18', 'both_sexes', 'how_use_absent_future', '44'),
('19', 'both_sexes', 'how_use_absent_future', '54'),
('20', 'both_sexes', 'how_use_absent_future', '61'),
('21', 'both_sexes', 'how_use_absent_future', '56'),
('22', 'both_sexes', 'how_use_absent_future', '70'),
('23', 'both_sexes', 'how_use_absent_future', '74'),
('24', 'both_sexes', 'how_use_absent_future', '79'),
('25', 'both_sexes', 'how_use_absent_future', '79'),
('26', 'both_sexes', 'how_use_absent_future', '85'),
('27', 'both_sexes', 'how_use_absent_future', '82'),
('28', 'both_sexes', 'how_use_absent_future', '83'),
('29', 'both_sexes', 'how_use_absent_future', '86'),
('30', 'both_sexes', 'how_use_absent_future', '94'),
('16', 'both_sexes', 'how_use_absent_past', '18'),
('17', 'both_sexes', 'how_use_absent_past', '27'),
('18', 'both_sexes', 'how_use_absent_past', '38'),
('19', 'both_sexes', 'how_use_absent_past', '47'),
('20', 'both_sexes', 'how_use_absent_past', '57'),
('21', 'both_sexes', 'how_use_absent_past', '57'),
('22', 'both_sexes', 'how_use_absent_past', '69'),
('23', 'both_sexes', 'how_use_absent_past', '78'),
('24', 'both_sexes', 'how_use_absent_past', '80'),
('25', 'both_sexes', 'how_use_absent_past', '76'),
('26', 'both_sexes', 'how_use_absent_past', '82'),
('27', 'both_sexes', 'how_use_absent_past', '87'),
('28', 'both_sexes', 'how_use_absent_past', '86'),
('29', 'both_sexes', 'how_use_absent_past', '89'),
('30', 'both_sexes', 'how_use_absent_past', '94');