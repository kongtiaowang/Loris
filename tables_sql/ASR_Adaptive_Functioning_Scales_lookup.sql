CREATE TABLE `ASR_Adaptive_Functioning_Scales_lookup` (
    `age_range` enum('18-35','18-29','36-59'),
    `sex` enum('female','male'),
    `scale` enum('friends','spouse_partner','family','job','education','mean_adaptive'),
    `score_min` decimal(4,1),
    `score_max` decimal(4,1),
    `t_score` int(3),
     PRIMARY KEY  (`age_range`,`sex`,`scale`,`t_score`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO ASR_Adaptive_Functioning_Scales_lookup VALUES
('18-35','male','friends',12,12,60),
('18-35','male','friends',11,11,57),
('18-35','male','friends',10,10,52),
('18-35','male','friends',9,9,48),
('18-35','male','friends',8,8,44),
('18-35','male','friends',7,7,40),
('18-35','male','friends',6,6,36),
('18-35','male','friends',5,5,34),
('18-35','male','friends',4,4,32),
('18-35','male','friends',3,3,30),
('18-35','male','friends',2,2,27),
('18-35','male','friends',1,1,23),
('18-35','male','friends',0,0,20),
('36-59','male','friends',12,12,60),
('36-59','male','friends',11,11,59),
('36-59','male','friends',10,10,56),
('36-59','male','friends',9,9,51),
('36-59','male','friends',8,8,47),
('36-59','male','friends',7,7,43),
('36-59','male','friends',6,6,39),
('36-59','male','friends',5,5,36),
('36-59','male','friends',4,4,34),
('36-59','male','friends',3,3,31),
('36-59','male','friends',2,2,30),
('36-59','male','friends',1,1,25),
('36-59','male','friends',0,0,20),
('18-35','male','spouse_partner',8,8,60),
('18-35','male','spouse_partner',7,7,56),
('18-35','male','spouse_partner',6,6,50),
('18-35','male','spouse_partner',5,5,46),
('18-35','male','spouse_partner',4,4,43),
('18-35','male','spouse_partner',3,3,42),
('18-35','male','spouse_partner',2,2,39),
('18-35','male','spouse_partner',1,1,36),
('18-35','male','spouse_partner',0,0,34),
('18-35','male','spouse_partner',-1,-1,31),
('18-35','male','spouse_partner',-2,-2,29),
('18-35','male','spouse_partner',-3,-3,28),
('18-35','male','spouse_partner',-4,-4,26),
('18-35','male','spouse_partner',-5,-5,25),
('18-35','male','spouse_partner',-6,-6,23),
('18-35','male','spouse_partner',-7,-7,22),
('18-35','male','spouse_partner',-8,-8,20),
('36-59','male','spouse_partner',8,8,59),
('36-59','male','spouse_partner',7,7,53),
('36-59','male','spouse_partner',6,6,48),
('36-59','male','spouse_partner',5,5,44),
('36-59','male','spouse_partner',4,4,42),
('36-59','male','spouse_partner',3,3,39),
('36-59','male','spouse_partner',2,2,35),
('36-59','male','spouse_partner',1,1,33),
('36-59','male','spouse_partner',0,0,31),
('36-59','male','spouse_partner',-1,-1,30),
('36-59','male','spouse_partner',-2,-2,29),
('36-59','male','spouse_partner',-3,-3,27),
('36-59','male','spouse_partner',-4,-4,26),
('36-59','male','spouse_partner',-5,-5,24),
('36-59','male','spouse_partner',-6,-6,23),
('36-59','male','spouse_partner',-7,-7,21),
('36-59','male','spouse_partner',-8,-8,20),
('18-35','male','family',2,2,57),
('18-35','male','family',1.8,1.8,51),
('18-35','male','family',1.6,1.6,48),
('18-35','male','family',1.4,1.4,44),
('18-35','male','family',1.2,1.2,41),
('18-35','male','family',1,1,38),
('18-35','male','family',0.8,0.8,33),
('18-35','male','family',0.6,0.6,30),
('18-35','male','family',0.4,0.4,27),
('18-35','male','family',0.2,0.2,23),
('18-35','male','family',0,0,20),
('36-59','male','family',2,2,57),
('36-59','male','family',1.8,1.8,51),
('36-59','male','family',1.6,1.6,47),
('36-59','male','family',1.4,1.4,44),
('36-59','male','family',1.2,1.2,42),
('36-59','male','family',1,1,37),
('36-59','male','family',0.8,0.8,31),
('36-59','male','family',0.6,0.6,28),
('36-59','male','family',0.4,0.4,26),
('36-59','male','family',0.2,0.2,23),
('36-59','male','family',0,0,20),
('18-35','male','job',4,4,58),
('18-35','male','job',3,3,52),
('18-35','male','job',2,2,48),
('18-35','male','job',1,1,44),
('18-35','male','job',0,0,41),
('18-35','male','job',-1,-1,38),
('18-35','male','job',-2,-2,36),
('18-35','male','job',-3,-3,34),
('18-35','male','job',-4,-4,33),
('18-35','male','job',-5,-5,30),
('18-35','male','job',-6,-6,29),
('18-35','male','job',-7,-7,27),
('18-35','male','job',-8,-8,26),
('18-35','male','job',-9,-9,24),
('18-35','male','job',-10,-10,23),
('18-35','male','job',-11,-11,21),
('18-35','male','job',-12,-12,20),
('36-59','male','job',4,4,58),
('36-59','male','job',3,3,52),
('36-59','male','job',2,2,47),
('36-59','male','job',1,1,44),
('36-59','male','job',0,0,41),
('36-59','male','job',-1,-1,37),
('36-59','male','job',-2,-2,34),
('36-59','male','job',-3,-3,30),
('36-59','male','job',-4,-4,29),
('36-59','male','job',-5,-5,28),
('36-59','male','job',-6,-6,27),
('36-59','male','job',-7,-7,26),
('36-59','male','job',-8,-8,24),
('36-59','male','job',-9,-9,23),
('36-59','male','job',-10,-10,22),
('36-59','male','job',-11,-11,21),
('36-59','male','job',-12,-12,20),
('18-29','male','education',6,6,60),
('18-29','male','education',5,5,56),
('18-29','male','education',4,4,50),
('18-29','male','education',3,3,45),
('18-29','male','education',2,2,41),
('18-29','male','education',1,1,36),
('18-29','male','education',0,0,30),
('18-29','male','education',-1,-1,28),
('18-29','male','education',-2,-2,25),
('18-29','male','education',-3,-3,23),
('18-29','male','education',-4,-4,20),
('18-35','male','mean_adaptive',56.5,60,60),
('18-35','male','mean_adaptive',55,56,59),
('18-35','male','mean_adaptive',54.5,54.5,58),
('18-35','male','mean_adaptive',54,54,57),
('18-35','male','mean_adaptive',53.5,53.5,56),
('18-35','male','mean_adaptive',52.5,53,55),
('18-35','male','mean_adaptive',52,52,54),
('18-35','male','mean_adaptive',51.5,51.5,53),
('18-35','male','mean_adaptive',51,51,52),
('18-35','male','mean_adaptive',50.5,50.5,51),
('18-35','male','mean_adaptive',50,50,50),
('18-35','male','mean_adaptive',49.5,49.5,49),
('18-35','male','mean_adaptive',49,49,48),
('18-35','male','mean_adaptive',48,48.5,47),
('18-35','male','mean_adaptive',47.5,47.5,46),
('18-35','male','mean_adaptive',47,47,45),
('18-35','male','mean_adaptive',46,46.5,44),
('18-35','male','mean_adaptive',45,45.5,43),
('18-35','male','mean_adaptive',44.5,44.5,42),
('18-35','male','mean_adaptive',44,44,41),
('18-35','male','mean_adaptive',43.5,43.5,40),
('18-35','male','mean_adaptive',43,43,39),
('18-35','male','mean_adaptive',42.5,42.5,38),
('18-35','male','mean_adaptive',42,42,37),
('18-35','male','mean_adaptive',41.5,41.5,36),
('18-35','male','mean_adaptive',41,41,35),
('18-35','male','mean_adaptive',40.5,40.5,34),
('18-35','male','mean_adaptive',39.5,40,33),
('18-35','male','mean_adaptive',38.5,39,32),
('18-35','male','mean_adaptive',37.5,38,31),
('18-35','male','mean_adaptive',37,37,30),
('18-35','male','mean_adaptive',36,36.5,29),
('18-35','male','mean_adaptive',34,35.5,28),
('18-35','male','mean_adaptive',32,33.5,27),
('18-35','male','mean_adaptive',30.5,31.5,26),
('18-35','male','mean_adaptive',28.5,30,25),
('18-35','male','mean_adaptive',26.5,28,24),
('18-35','male','mean_adaptive',25,26,23),
('18-35','male','mean_adaptive',23,24.5,22),
('18-35','male','mean_adaptive',21,22.5,21),
('18-35','male','mean_adaptive',20,20.5,20),
('36-59','male','mean_adaptive',56.5,60,60),
('36-59','male','mean_adaptive',55,56,59),
('36-59','male','mean_adaptive',54.5,54.5,58),
('36-59','male','mean_adaptive',54,54,57),
('36-59','male','mean_adaptive',53.5,53.5,56),
('36-59','male','mean_adaptive',52.5,53,55),
('36-59','male','mean_adaptive',52,52,54),
('36-59','male','mean_adaptive',51.5,51.5,53),
('36-59','male','mean_adaptive',51,51,52),
('36-59','male','mean_adaptive',50,50.5,51),
('36-59','male','mean_adaptive',49.5,49.5,50),
('36-59','male','mean_adaptive',48.5,49,49),
('36-59','male','mean_adaptive',48,48,48),
('36-59','male','mean_adaptive',47.5,47.5,47),
('36-59','male','mean_adaptive',47,47,46),
('36-59','male','mean_adaptive',46.5,46.5,45),
('36-59','male','mean_adaptive',45.5,46,44),
('36-59','male','mean_adaptive',44.5,45,43),
('36-59','male','mean_adaptive',44,44,42),
('36-59','male','mean_adaptive',43.5,43.5,41),
('36-59','male','mean_adaptive',43,43,40),
('36-59','male','mean_adaptive',42.5,42.5,39),
('36-59','male','mean_adaptive',42,42,38),
('36-59','male','mean_adaptive',41,41.5,37),
('36-59','male','mean_adaptive',40,40.5,36),
('36-59','male','mean_adaptive',39.5,39.5,35),
('36-59','male','mean_adaptive',39,39,34),
('36-59','male','mean_adaptive',38.5,38.5,33),
('36-59','male','mean_adaptive',37.5,38,32),
('36-59','male','mean_adaptive',37,37,31),
('36-59','male','mean_adaptive',36.5,36.5,30),
('36-59','male','mean_adaptive',35.5,36,29),
('36-59','male','mean_adaptive',33.5,35,28),
('36-59','male','mean_adaptive',32,33,27),
('36-59','male','mean_adaptive',30,31.5,26),
('36-59','male','mean_adaptive',28,29.5,25),
('36-59','male','mean_adaptive',26.5,27.5,24),
('36-59','male','mean_adaptive',24.5,26,23),
('36-59','male','mean_adaptive',23,24,22),
('36-59','male','mean_adaptive',21,22.5,21),
('36-59','male','mean_adaptive',20,20.5,20);

INSERT INTO ASR_Adaptive_Functioning_Scales_lookup VALUES
('18-35','female','friends',12,12,60),
('18-35','female','friends',11,11,58),
('18-35','female','friends',10,10,53),
('18-35','female','friends',9,9,48),
('18-35','female','friends',8,8,44),
('18-35','female','friends',7,7,41),
('18-35','female','friends',6,6,38),
('18-35','female','friends',5,5,34),
('18-35','female','friends',4,4,32),
('18-35','female','friends',3,3,29),
('18-35','female','friends',2,2,26),
('18-35','female','friends',1,1,23),
('18-35','female','friends',0,0,20),
('36-59','female','friends',12,12,60),
('36-59','female','friends',11,11,58),
('36-59','female','friends',10,10,54),
('36-59','female','friends',9,9,50),
('36-59','female','friends',8,8,46),
('36-59','female','friends',7,7,42),
('36-59','female','friends',6,6,39),
('36-59','female','friends',5,5,36),
('36-59','female','friends',4,4,33),
('36-59','female','friends',3,3,30),
('36-59','female','friends',2,2,27),
('36-59','female','friends',1,1,23),
('36-59','female','friends',0,0,20),
('18-35','female','spouse_partner',8,8,60),
('18-35','female','spouse_partner',7,7,55),
('18-35','female','spouse_partner',6,6,50),
('18-35','female','spouse_partner',5,5,47),
('18-35','female','spouse_partner',4,4,44),
('18-35','female','spouse_partner',3,3,42),
('18-35','female','spouse_partner',2,2,39),
('18-35','female','spouse_partner',1,1,37),
('18-35','female','spouse_partner',0,0,35),
('18-35','female','spouse_partner',-1,-1,33),
('18-35','female','spouse_partner',-2,-2,32),
('18-35','female','spouse_partner',-3,-3,30),
('18-35','female','spouse_partner',-4,-4,28),
('18-35','female','spouse_partner',-5,-5,26),
('18-35','female','spouse_partner',-6,-6,24),
('18-35','female','spouse_partner',-7,-7,22),
('18-35','female','spouse_partner',-8,-8,20),
('36-59','female','spouse_partner',8,8,60),
('36-59','female','spouse_partner',7,7,56),
('36-59','female','spouse_partner',6,6,51),
('36-59','female','spouse_partner',5,5,47),
('36-59','female','spouse_partner',4,4,43),
('36-59','female','spouse_partner',3,3,40),
('36-59','female','spouse_partner',2,2,38),
('36-59','female','spouse_partner',1,1,35),
('36-59','female','spouse_partner',0,0,33),
('36-59','female','spouse_partner',-1,-1,31),
('36-59','female','spouse_partner',-2,-2,29),
('36-59','female','spouse_partner',-3,-3,28),
('36-59','female','spouse_partner',-4,-4,26),
('36-59','female','spouse_partner',-5,-5,25),
('36-59','female','spouse_partner',-6,-6,23),
('36-59','female','spouse_partner',-7,-7,22),
('36-59','female','spouse_partner',-8,-8,20),
('18-35','female','family',2,2,58),
('18-35','female','family',1.8,1.8,52),
('18-35','female','family',1.6,1.6,48),
('18-35','female','family',1.4,1.4,44),
('18-35','female','family',1.2,1.2,41),
('18-35','female','family',1,1,36),
('18-35','female','family',0.8,0.8,30),
('18-35','female','family',0.6,0.6,28),
('18-35','female','family',0.4,0.4,25),
('18-35','female','family',0.2,0.2,23),
('18-35','female','family',0,0,20),
('36-59','female','family',2,2,56),
('36-59','female','family',1.8,1.8,50),
('36-59','female','family',1.6,1.6,46),
('36-59','female','family',1.4,1.4,42),
('36-59','female','family',1.2,1.2,39),
('36-59','female','family',1,1,34),
('36-59','female','family',0.8,0.8,30),
('36-59','female','family',0.6,0.6,28),
('36-59','female','family',0.4,0.4,25),
('36-59','female','family',0.2,0.2,23),
('36-59','female','family',0,0,20),
('18-35','female','job',4,4,56),
('18-35','female','job',3,3,50),
('18-35','female','job',2,2,47),
('18-35','female','job',1,1,44),
('18-35','female','job',0,0,41),
('18-35','female','job',-1,-1,37),
('18-35','female','job',-2,-2,35),
('18-35','female','job',-3,-3,33),
('18-35','female','job',-4,-4,32),
('18-35','female','job',-5,-5,30),
('18-35','female','job',-6,-6,29),
('18-35','female','job',-7,-7,27),
('18-35','female','job',-8,-8,26),
('18-35','female','job',-9,-9,24),
('18-35','female','job',-10,-10,23),
('18-35','female','job',-11,-11,21),
('18-35','female','job',-12,-12,20),
('36-59','female','job',4,4,58),
('36-59','female','job',3,3,52),
('36-59','female','job',2,2,47),
('36-59','female','job',1,1,42),
('36-59','female','job',0,0,37),
('36-59','female','job',-1,-1,33),
('36-59','female','job',-2,-2,30),
('36-59','female','job',-3,-3,29),
('36-59','female','job',-4,-4,28),
('36-59','female','job',-5,-5,27),
('36-59','female','job',-6,-6,26),
('36-59','female','job',-7,-7,25),
('36-59','female','job',-8,-8,24),
('36-59','female','job',-9,-9,23),
('36-59','female','job',-10,-10,22),
('36-59','female','job',-11,-11,21),
('36-59','female','job',-12,-12,20),
('18-29','female','education',6,6,60),
('18-29','female','education',5,5,54),
('18-29','female','education',4,4,48),
('18-29','female','education',3,3,44),
('18-29','female','education',2,2,39),
('18-29','female','education',1,1,34),
('18-29','female','education',0,0,30),
('18-29','female','education',-1,-1,28),
('18-29','female','education',-2,-2,25),
('18-29','female','education',-3,-3,23),
('18-29','female','education',-4,-4,20),
('18-35','female','mean_adaptive',56,60,60),
('18-35','female','mean_adaptive',54.5,55.5,59),
('18-35','female','mean_adaptive',53.5,54,58),
('18-35','female','mean_adaptive',53,53,57),
('18-35','female','mean_adaptive',52,52.5,55),
('18-35','female','mean_adaptive',51.5,51.5,54),
('18-35','female','mean_adaptive',51,51,53),
('18-35','female','mean_adaptive',50.5,50.5,52),
('18-35','female','mean_adaptive',50,50,51),
('18-35','female','mean_adaptive',49.5,49.5,50),
('18-35','female','mean_adaptive',48.5,49,49),
('18-35','female','mean_adaptive',48,48,48),
('18-35','female','mean_adaptive',47.5,47.5,47),
('18-35','female','mean_adaptive',46.5,47,46),
('18-35','female','mean_adaptive',46,46,45),
('18-35','female','mean_adaptive',45.5,45.5,44),
('18-35','female','mean_adaptive',45,45,43),
('18-35','female','mean_adaptive',44.5,44.5,42),
('18-35','female','mean_adaptive',44,44,41),
('18-35','female','mean_adaptive',43,43.5,40),
('18-35','female','mean_adaptive',42.5,42.5,39),
('18-35','female','mean_adaptive',42,42,38),
('18-35','female','mean_adaptive',41,41.5,37),
('18-35','female','mean_adaptive',40.5,40.5,36),
('18-35','female','mean_adaptive',40,40,35),
('18-35','female','mean_adaptive',39,39.5,34),
('18-35','female','mean_adaptive',38.5,38.5,33),
('18-35','female','mean_adaptive',37.5,38,32),
('18-35','female','mean_adaptive',37,37,31),
('18-35','female','mean_adaptive',36.5,36.5,30),
('18-35','female','mean_adaptive',35.5,36,29),
('18-35','female','mean_adaptive',33.5,35,28),
('18-35','female','mean_adaptive',32,33,27),
('18-35','female','mean_adaptive',30,31.5,26),
('18-35','female','mean_adaptive',28,29.5,25),
('18-35','female','mean_adaptive',26.5,27.5,24),
('18-35','female','mean_adaptive',24.5,26,23),
('18-35','female','mean_adaptive',23,24,22),
('18-35','female','mean_adaptive',21,22.5,21),
('18-35','female','mean_adaptive',20,20.5,20),
('36-59','female','mean_adaptive',56.5,60,60),
('36-59','female','mean_adaptive',55,56,59),
('36-59','female','mean_adaptive',54.5,54.5,58),
('36-59','female','mean_adaptive',54,54,57),
('36-59','female','mean_adaptive',53,53.5,56),
('36-59','female','mean_adaptive',52.5,52.5,55),
('36-59','female','mean_adaptive',52,52,54),
('36-59','female','mean_adaptive',51.5,51.5,53),
('36-59','female','mean_adaptive',51,51,52),
('36-59','female','mean_adaptive',50.5,50.5,51),
('36-59','female','mean_adaptive',49.5,49.5,50),
('36-59','female','mean_adaptive',49,49,49),
('36-59','female','mean_adaptive',48,48.5,48),
('36-59','female','mean_adaptive',47.5,47.5,47),
('36-59','female','mean_adaptive',47,47,46),
('36-59','female','mean_adaptive',46.5,46.5,45),
('36-59','female','mean_adaptive',45.5,46,44),
('36-59','female','mean_adaptive',45,45,43),
('36-59','female','mean_adaptive',44.5,44.5,42),
('36-59','female','mean_adaptive',44,44,41),
('36-59','female','mean_adaptive',43,43.5,40),
('36-59','female','mean_adaptive',42.5,42.5,39),
('36-59','female','mean_adaptive',41.5,42,38),
('36-59','female','mean_adaptive',41,41,37),
('36-59','female','mean_adaptive',40.5,40.5,36),
('36-59','female','mean_adaptive',39.5,40,35),
('36-59','female','mean_adaptive',39,39,34),
('36-59','female','mean_adaptive',38,38.5,33),
('36-59','female','mean_adaptive',37.5,37.5,32),
('36-59','female','mean_adaptive',37,37,31),
('36-59','female','mean_adaptive',36.5,36.5,30),
('36-59','female','mean_adaptive',35.5,36,29),
('36-59','female','mean_adaptive',33.5,35,28),
('36-59','female','mean_adaptive',32,33,27),
('36-59','female','mean_adaptive',30,31.5,26),
('36-59','female','mean_adaptive',28,29.5,25),
('36-59','female','mean_adaptive',26.5,27.5,24),
('36-59','female','mean_adaptive',24.5,26,23),
('36-59','female','mean_adaptive',23,24,22),
('36-59','female','mean_adaptive',21,22.5,21),
('36-59','female','mean_adaptive',20,20.5,20);