DROP TABLE IF EXISTS CCC2_composite_score_lookup;

CREATE TABLE `CCC2_composite_score_lookup` (
			`GCC_total_score` varchar(55) NOT NULL,
			`GCC_composite_score` varchar(55) NOT NULL,
			`GCC_90_percentage_CI` varchar(55) NOT NULL,
			`GCC_95_percentage_CI` varchar(55) NOT NULL,
			`GCC_percentile` varchar(55) NOT NULL
			)ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO CCC2_composite_score_lookup VALUES
('8','40','-','-','-'),
('9','41','-','-','-'),
('10','42','-','-','-'),
('11','43','-','-','-'),
('12','44','-','-','-'),
('13','45','-','-','-'),
('14','46','-','-','-'),
('15','47','-','-','-'),
('16','48','-','-','-'),
('17','49','-','-','-'),
('18','50','-','-','-'),
('19','51','-','-','-'),
('20','52','-','-','-'),
('21','53','-','-','-'),
('22','54','-','-','-'),
('23','55','-','-','-'),
('24','56','-','-','-'),
('25','57','-','-','-'),
('26','58','-','-','-'),
('27','59','-','-','-'),
('28','60','-','-','-'),
('29','60','-','-','-'),
('30','61','-','-','-'),
('31','62','-','-','-'),
('32','63','-','-','-'),
('33','64','-','-','-'),
('34','65','-','-','-'),
('35','66','-','-','-'),
('36','67','-','-','-'),
('37','68','-','-','-'),
('38','69','-','-','-'),
('39','70','-','-','-'),
('40','70','-','-','-'),
('41','71','-','-','-'),
('42','72','-','-','-'),
('43','72','-','-','-'),
('44','73','-','-','-'),
('45','74','-','-','-'),
('46','74','-','-','-'),
('47','75','-','-','-'),
('48','76','-','-','-'),
('49','76','-','-','-'),
('50','77','-','-','-'),
('51','78','-','-','-'),
('52','78','-','-','-'),
('53','79','-','-','-'),
('54','80','-','-','-'),
('55','80','-','-','-'),
('56','81','-','-','-'),
('57','82','-','-','-'),
('58','83','-','-','-'),
('59','83','-','-','-'),
('60','84','-','-','-'),
('61','85','-','-','-'),
('62','85','-','-','-'),
('63','86','-','-','-'),
('64','87','-','-','-'),
('65','88','-','-','-'),
('66','88','-','-','-'),
('67','89','-','-','-'),
('68','90','-','-','-'),
('69','91','-','-','-'),
('70','91','-','-','-'),
('71','92','-','-','-'),
('72','93','-','-','-'),
('73','94','-','-','-'),
('74','95','-','-','-'),
('75','95','-','-','-'),
('76','96','-','-','-'),
('77','97','-','-','-'),
('78','98','-','-','-'),
('79','99','-','-','-'),
('80','100','-','-','-'),
('81','101','-','-','-'),
('82','102','-','-','-'),
('83','103','-','-','-'),
('84','104','-','-','-'),
('85','105','-','-','-'),
('86','106','-','-','-'),
('87','107','-','-','-'),
('88','108','-','-','-'),
('89','109','-','-','-'),
('90','110','-','-','-'),
('91','111','-','-','-'),
('92','112','-','-','-'),
('93','113','-','-','-'),
('94','114','-','-','-'),
('95','115','-','-','-'),
('96','116','-','-','-'),
('97','117','-','-','-'),
('98','118','-','-','-'),
('99','119','-','-','-'),
('100','120','-','-','-'),
('101','121','-','-','-'),
('102','122','-','-','-'),
('103','123','-','-','-'),
('104','124','-','-','-'),
('105','125','-','-','-'),
('106','126','-','-','-'),
('107','127','-','-','-'),
('108','128','-','-','-'),
('109','129','-','-','-'),
('110','130','-','-','-'),
('111','131','-','-','-'),
('112','132','-','-','-'),
('113','133','-','-','-'),
('114','134','-','-','-'),
('115','135','-','-','-'),
('116','136','-','-','-'),
('117','137','-','-','-'),
('118','138','-','-','-'),
('119','139','-','-','-'),
('120','140','-','-','-'),
('121','141','-','-','-'),
('122','142','-','-','-'),
('123','143','-','-','-'),
('124','144','-','-','-'),
('125','145','-','-','-'),
('126','146','-','-','-'),
('127','147','-','-','-'),
('128','148','-','-','-'),
('129','149','-','-','-'),
('130','150','-','-','-'),
('131','151','-','-','-'),
('132','152','-','-','-'),
('133','153','-','-','-'),
('134','154','-','-','-'),
('135','155','-','-','-'),
('136','156','-','-','-'),
('137','157','-','-','-'),
('138','158','-','-','-'),
('139','159','-','-','-'),
('140','160','-','-','-'),
('141','160','-','-','-'),
('142','160','-','-','-'),
('143','160','-','-','-'),
('144','160','-','-','-'),
('145','160','-','-','-'),
('146','160','-','-','-'),
('147','160','-','-','-'),
('148','160','-','-','-'),
('149','160','-','-','-'),
('150','160','-','-','-'),
('151','160','-','-','-'),
('152','160','-','-','-');


UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='38-48', GCC_95_percentage_CI='37-49', GCC_percentile='<0.1' where GCC_composite_score='40';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='39-49', GCC_95_percentage_CI='38-50', GCC_percentile='<0.1' where GCC_composite_score='41';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='40-50', GCC_95_percentage_CI='39-51', GCC_percentile='<0.1' where GCC_composite_score='42';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='41-51', GCC_95_percentage_CI='40-52', GCC_percentile='<0.1' where GCC_composite_score='43';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='42-52', GCC_95_percentage_CI='41-53', GCC_percentile='<0.1' where GCC_composite_score='44';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='43-53', GCC_95_percentage_CI='42-54', GCC_percentile='<0.1' where GCC_composite_score='45';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='43-54', GCC_95_percentage_CI='42-55', GCC_percentile='<0.1' where GCC_composite_score='46';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='44-55', GCC_95_percentage_CI='43-56', GCC_percentile='<0.1' where GCC_composite_score='47';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='45-56', GCC_95_percentage_CI='44-57', GCC_percentile='<0.1' where GCC_composite_score='48';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='46-57', GCC_95_percentage_CI='45-58', GCC_percentile='<0.1' where GCC_composite_score='49';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='47-58', GCC_95_percentage_CI='46-59', GCC_percentile='<0.1' where GCC_composite_score='50';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='48-59', GCC_95_percentage_CI='47-60', GCC_percentile='0.1' where GCC_composite_score='51';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='49-60', GCC_95_percentage_CI='48-61', GCC_percentile='0.1' where GCC_composite_score='52';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='50-61', GCC_95_percentage_CI='49-62', GCC_percentile='0.1' where GCC_composite_score='53';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='51-62', GCC_95_percentage_CI='50-63', GCC_percentile='0.1' where GCC_composite_score='54';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='52-62', GCC_95_percentage_CI='51-63', GCC_percentile='0.1' where GCC_composite_score='55';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='53-63', GCC_95_percentage_CI='52-64', GCC_percentile='0.2' where GCC_composite_score='56';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='54-64', GCC_95_percentage_CI='53-65', GCC_percentile='0.2' where GCC_composite_score='57';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='55-65', GCC_95_percentage_CI='54-66', GCC_percentile='0.3' where GCC_composite_score='58';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='56-66', GCC_95_percentage_CI='55-67', GCC_percentile='0.3' where GCC_composite_score='59';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='57-67', GCC_95_percentage_CI='56-68', GCC_percentile='0.4' where GCC_composite_score='60';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='57-67', GCC_95_percentage_CI='56-68', GCC_percentile='0.4' where GCC_composite_score='60';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='58-68', GCC_95_percentage_CI='57-69', GCC_percentile='0.5' where GCC_composite_score='61';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='59-69', GCC_95_percentage_CI='58-70', GCC_percentile='1' where GCC_composite_score='62';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='60-70', GCC_95_percentage_CI='59-71', GCC_percentile='1' where GCC_composite_score='63';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='61-71', GCC_95_percentage_CI='60-72', GCC_percentile='1' where GCC_composite_score='64';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='62-72', GCC_95_percentage_CI='61-73', GCC_percentile='1' where GCC_composite_score='65';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='62-73', GCC_95_percentage_CI='61-74', GCC_percentile='1' where GCC_composite_score='66';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='63-74', GCC_95_percentage_CI='62-75', GCC_percentile='1' where GCC_composite_score='67';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='64-75', GCC_95_percentage_CI='63-76', GCC_percentile='2' where GCC_composite_score='68';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='65-76', GCC_95_percentage_CI='64-77', GCC_percentile='2' where GCC_composite_score='69';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='66-77', GCC_95_percentage_CI='65-78', GCC_percentile='2' where GCC_composite_score='70';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='66-77', GCC_95_percentage_CI='65-78', GCC_percentile='2' where GCC_composite_score='70';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='67-78', GCC_95_percentage_CI='66-79', GCC_percentile='3' where GCC_composite_score='71';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='68-79', GCC_95_percentage_CI='67-80', GCC_percentile='3' where GCC_composite_score='72';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='69-80', GCC_95_percentage_CI='68-81', GCC_percentile='4' where GCC_composite_score='73';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='70-81', GCC_95_percentage_CI='69-82', GCC_percentile='4' where GCC_composite_score='74';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='71-81', GCC_95_percentage_CI='70-82', GCC_percentile='5' where GCC_composite_score='75';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='72-82', GCC_95_percentage_CI='71-83', GCC_percentile='5' where GCC_composite_score='76';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='73-83', GCC_95_percentage_CI='72-84', GCC_percentile='6' where GCC_composite_score='77';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='74-84', GCC_95_percentage_CI='73-85', GCC_percentile='7' where GCC_composite_score='78';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='75-85', GCC_95_percentage_CI='74-86', GCC_percentile='8' where GCC_composite_score='79';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='76-86', GCC_95_percentage_CI='75-87', GCC_percentile='9' where GCC_composite_score='80';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='77-87', GCC_95_percentage_CI='76-88', GCC_percentile='10' where GCC_composite_score='81';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='78-88', GCC_95_percentage_CI='77-89', GCC_percentile='12' where GCC_composite_score='82';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='79-89', GCC_95_percentage_CI='78-90', GCC_percentile='13' where GCC_composite_score='83';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='80-90', GCC_95_percentage_CI='79-91', GCC_percentile='14' where GCC_composite_score='84';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='81-91', GCC_95_percentage_CI='80-92', GCC_percentile='16' where GCC_composite_score='85';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='81-92', GCC_95_percentage_CI='80-93', GCC_percentile='18' where GCC_composite_score='86';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='82-93', GCC_95_percentage_CI='81-94', GCC_percentile='19' where GCC_composite_score='87';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='83-94', GCC_95_percentage_CI='82-95', GCC_percentile='21' where GCC_composite_score='88';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='84-95', GCC_95_percentage_CI='83-96', GCC_percentile='23' where GCC_composite_score='89';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='85-96', GCC_95_percentage_CI='84-97', GCC_percentile='25' where GCC_composite_score='90';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='86-97', GCC_95_percentage_CI='85-98', GCC_percentile='27' where GCC_composite_score='91';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='87-98', GCC_95_percentage_CI='86-99', GCC_percentile='30' where GCC_composite_score='92';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='88-99', GCC_95_percentage_CI='87-100', GCC_percentile='32' where GCC_composite_score='93';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='89-100', GCC_95_percentage_CI='88-101', GCC_percentile='34' where GCC_composite_score='94';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='90-100', GCC_95_percentage_CI='89-101', GCC_percentile='37' where GCC_composite_score='95';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='91-101', GCC_95_percentage_CI='90-102', GCC_percentile='39' where GCC_composite_score='96';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='92-102', GCC_95_percentage_CI='91-103', GCC_percentile='42' where GCC_composite_score='97';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='93-103', GCC_95_percentage_CI='92-104', GCC_percentile='45' where GCC_composite_score='98';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='94-104', GCC_95_percentage_CI='93-105', GCC_percentile='47' where GCC_composite_score='99';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='95-105', GCC_95_percentage_CI='94-106', GCC_percentile='50' where GCC_composite_score='100';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='96-106', GCC_95_percentage_CI='95-107', GCC_percentile='53' where GCC_composite_score='101';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='97-107', GCC_95_percentage_CI='96-108', GCC_percentile='55' where GCC_composite_score='102';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='98-108', GCC_95_percentage_CI='97-109', GCC_percentile='58' where GCC_composite_score='103';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='99-109', GCC_95_percentage_CI='98-110', GCC_percentile='61' where GCC_composite_score='104';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='100-110', GCC_95_percentage_CI='99-111', GCC_percentile='63' where GCC_composite_score='105';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='100-111', GCC_95_percentage_CI='99-112', GCC_percentile='66' where GCC_composite_score='106';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='101-112', GCC_95_percentage_CI='100-113', GCC_percentile='68' where GCC_composite_score='107';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='102-113', GCC_95_percentage_CI='101-114', GCC_percentile='70' where GCC_composite_score='108';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='103-114', GCC_95_percentage_CI='102-115', GCC_percentile='73' where GCC_composite_score='109';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='104-115', GCC_95_percentage_CI='103-116', GCC_percentile='75' where GCC_composite_score='110';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='105-116', GCC_95_percentage_CI='104-117', GCC_percentile='77' where GCC_composite_score='111';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='106-117', GCC_95_percentage_CI='105-118', GCC_percentile='79' where GCC_composite_score='112';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='107-118', GCC_95_percentage_CI='106-119', GCC_percentile='81' where GCC_composite_score='113';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='108-119', GCC_95_percentage_CI='107-120', GCC_percentile='82' where GCC_composite_score='114';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='109-119', GCC_95_percentage_CI='108-120', GCC_percentile='84' where GCC_composite_score='115';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='110-120', GCC_95_percentage_CI='109-121', GCC_percentile='86' where GCC_composite_score='116';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='111-121', GCC_95_percentage_CI='110-122', GCC_percentile='87' where GCC_composite_score='117';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='112-122', GCC_95_percentage_CI='111-123', GCC_percentile='88' where GCC_composite_score='118';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='113-123', GCC_95_percentage_CI='112-124', GCC_percentile='90' where GCC_composite_score='119';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='114-124', GCC_95_percentage_CI='113-125', GCC_percentile='91' where GCC_composite_score='120';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='115-125', GCC_95_percentage_CI='114-126', GCC_percentile='92' where GCC_composite_score='121';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='116-126', GCC_95_percentage_CI='115-127', GCC_percentile='93' where GCC_composite_score='122';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='117-127', GCC_95_percentage_CI='116-128', GCC_percentile='94' where GCC_composite_score='123';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='118-128', GCC_95_percentage_CI='117-129', GCC_percentile='95' where GCC_composite_score='124';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='119-129', GCC_95_percentage_CI='118-130', GCC_percentile='95' where GCC_composite_score='125';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='119-130', GCC_95_percentage_CI='118-131', GCC_percentile='96' where GCC_composite_score='126';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='120-131', GCC_95_percentage_CI='119-132', GCC_percentile='96' where GCC_composite_score='127';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='121-132', GCC_95_percentage_CI='120-133', GCC_percentile='97' where GCC_composite_score='128';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='122-133', GCC_95_percentage_CI='121-134', GCC_percentile='97' where GCC_composite_score='129';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='123-134', GCC_95_percentage_CI='122-135', GCC_percentile='98' where GCC_composite_score='130';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='124-135', GCC_95_percentage_CI='123-136', GCC_percentile='98' where GCC_composite_score='131';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='125-136', GCC_95_percentage_CI='124-137', GCC_percentile='98' where GCC_composite_score='132';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='126-137', GCC_95_percentage_CI='125-138', GCC_percentile='99' where GCC_composite_score='133';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='127-138', GCC_95_percentage_CI='126-139', GCC_percentile='99' where GCC_composite_score='134';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='128-138', GCC_95_percentage_CI='127-139', GCC_percentile='99' where GCC_composite_score='135';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='129-139', GCC_95_percentage_CI='128-140', GCC_percentile='99' where GCC_composite_score='136';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='130-140', GCC_95_percentage_CI='129-141', GCC_percentile='99' where GCC_composite_score='137';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='131-141', GCC_95_percentage_CI='130-142', GCC_percentile='99' where GCC_composite_score='138';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='132-142', GCC_95_percentage_CI='131-143', GCC_percentile='99.5' where GCC_composite_score='139';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='133-143', GCC_95_percentage_CI='132-144', GCC_percentile='99.6' where GCC_composite_score='140';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='134-144', GCC_95_percentage_CI='133-145', GCC_percentile='99.7' where GCC_composite_score='141';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='135-145', GCC_95_percentage_CI='134-146', GCC_percentile='99.7' where GCC_composite_score='142';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='136-146', GCC_95_percentage_CI='135-147', GCC_percentile='99.8' where GCC_composite_score='143';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='137-147', GCC_95_percentage_CI='136-148', GCC_percentile='99.8' where GCC_composite_score='144';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='138-148', GCC_95_percentage_CI='137-149', GCC_percentile='99.9' where GCC_composite_score='145';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='138-149', GCC_95_percentage_CI='137-150', GCC_percentile='99.9' where GCC_composite_score='146';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='139-150', GCC_95_percentage_CI='138-151', GCC_percentile='99.9' where GCC_composite_score='147';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='140-151', GCC_95_percentage_CI='139-152', GCC_percentile='99.9' where GCC_composite_score='148';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='141-152', GCC_95_percentage_CI='140-153', GCC_percentile='99.9' where GCC_composite_score='149';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='142-153', GCC_95_percentage_CI='141-154', GCC_percentile='>99.9' where GCC_composite_score='150';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='143-154', GCC_95_percentage_CI='142-155', GCC_percentile='>99.9' where GCC_composite_score='151';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='144-155', GCC_95_percentage_CI='143-156', GCC_percentile='>99.9' where GCC_composite_score='152';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='145-156', GCC_95_percentage_CI='144-157', GCC_percentile='>99.9' where GCC_composite_score='153';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='146-157', GCC_95_percentage_CI='145-158', GCC_percentile='>99.9' where GCC_composite_score='154';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='147-157', GCC_95_percentage_CI='146-158', GCC_percentile='>99.9' where GCC_composite_score='155';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='148-158', GCC_95_percentage_CI='147-159', GCC_percentile='>99.9' where GCC_composite_score='156';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='149-159', GCC_95_percentage_CI='148-160', GCC_percentile='>99.9' where GCC_composite_score='157';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='150-160', GCC_95_percentage_CI='149-161', GCC_percentile='>99.9' where GCC_composite_score='158';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='151-161', GCC_95_percentage_CI='150-162', GCC_percentile='>99.9' where GCC_composite_score='159';
UPDATE CCC2_composite_score_lookup SET GCC_90_percentage_CI='152-162', GCC_95_percentage_CI='151-163', GCC_percentile='>99.9' where GCC_composite_score='160';