CREATE TABLE `ibq_r_survey` (
`CommentID` varchar(255) NOT NULL default '',
`UserID` varchar(255) DEFAULT NULL,
`Examiner` varchar(255) DEFAULT NULL,
`Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
`Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
`Date_taken` date,
`Candidate_Age` varchar(50),
`Window_Difference` varchar(50),
`activity_level` varchar(255),
`distress_to_limitations` varchar(255),
`fear` varchar(255),
`duration_of_orienting` varchar(255),
`smiling_and_laughter` varchar(255),
`high_pleasure` varchar(255),
`low_pleasure` varchar(255),
`soothability` varchar(255),
`falling_reactivity` varchar(255),
`cuddliness` varchar(255),
`perceptual_sensitivity` varchar(255),
`sadness` varchar(255),
`approach` varchar(255),
`vocal_reactivity` varchar(255),
`q_1` enum('1','2','3','4','5','6','7','n/a'),
`q_2` enum('1','2','3','4','5','6','7','n/a'),
`q_3` enum('1','2','3','4','5','6','7','n/a'),
`q_4` enum('1','2','3','4','5','6','7','n/a'),
`q_5` enum('1','2','3','4','5','6','7','n/a'),
`q_6` enum('1','2','3','4','5','6','7','n/a'),
`q_7` enum('1','2','3','4','5','6','7','n/a'),
`q_8` enum('1','2','3','4','5','6','7','n/a'),
`q_9` enum('1','2','3','4','5','6','7','n/a'),
`q_10` enum('1','2','3','4','5','6','7','n/a'),
`q_11` enum('1','2','3','4','5','6','7','n/a'),
`q_12` enum('1','2','3','4','5','6','7','n/a'),
`q_13` enum('1','2','3','4','5','6','7','n/a'),
`q_14` enum('1','2','3','4','5','6','7','n/a'),
`q_15` enum('1','2','3','4','5','6','7','n/a'),
`q_16` enum('1','2','3','4','5','6','7','n/a'),
`q_17` enum('1','2','3','4','5','6','7','n/a'),
`q_18` enum('1','2','3','4','5','6','7','n/a'),
`q_19` enum('1','2','3','4','5','6','7','n/a'),
`q_20` enum('1','2','3','4','5','6','7','n/a'),
`q_21` enum('1','2','3','4','5','6','7','n/a'),
`q_22` enum('1','2','3','4','5','6','7','n/a'),
`q_23` enum('1','2','3','4','5','6','7','n/a'),
`q_24` enum('1','2','3','4','5','6','7','n/a'),
`q_25` enum('1','2','3','4','5','6','7','n/a'),
`q_26` enum('1','2','3','4','5','6','7','n/a'),
`q_27` enum('1','2','3','4','5','6','7','n/a'),
`q_28` enum('1','2','3','4','5','6','7','n/a'),
`q_29` enum('1','2','3','4','5','6','7','n/a'),
`q_30` enum('1','2','3','4','5','6','7','n/a'),
`q_31` enum('1','2','3','4','5','6','7','n/a'),
`q_32` enum('1','2','3','4','5','6','7','n/a'),
`q_33` enum('1','2','3','4','5','6','7','n/a'),
`q_34` enum('1','2','3','4','5','6','7','n/a'),
`q_35` enum('1','2','3','4','5','6','7','n/a'),
`q_36` enum('1','2','3','4','5','6','7','n/a'),
`q_37` enum('1','2','3','4','5','6','7','n/a'),
`q_38` enum('1','2','3','4','5','6','7','n/a'),
`q_39` enum('1','2','3','4','5','6','7','n/a'),
`q_40` enum('1','2','3','4','5','6','7','n/a'),
`q_41` enum('1','2','3','4','5','6','7','n/a'),
`q_42` enum('1','2','3','4','5','6','7','n/a'),
`q_43` enum('1','2','3','4','5','6','7','n/a'),
`q_44` enum('1','2','3','4','5','6','7','n/a'),
`q_45` enum('1','2','3','4','5','6','7','n/a'),
`q_46` enum('1','2','3','4','5','6','7','n/a'),
`q_47` enum('1','2','3','4','5','6','7','n/a'),
`q_48` enum('1','2','3','4','5','6','7','n/a'),
`q_49` enum('1','2','3','4','5','6','7','n/a'),
`q_50` enum('1','2','3','4','5','6','7','n/a'),
`q_51` enum('1','2','3','4','5','6','7','n/a'),
`q_52` enum('1','2','3','4','5','6','7','n/a'),
`q_53` enum('1','2','3','4','5','6','7','n/a'),
`q_54` enum('1','2','3','4','5','6','7','n/a'),
`q_55` enum('1','2','3','4','5','6','7','n/a'),
`q_56` enum('1','2','3','4','5','6','7','n/a'),
`q_57` enum('1','2','3','4','5','6','7','n/a'),
`q_58` enum('1','2','3','4','5','6','7','n/a'),
`q_59` enum('1','2','3','4','5','6','7','n/a'),
`q_60` enum('1','2','3','4','5','6','7','n/a'),
`q_61` enum('1','2','3','4','5','6','7','n/a'),
`q_62` enum('1','2','3','4','5','6','7','n/a'),
`q_63` enum('1','2','3','4','5','6','7','n/a'),
`q_64` enum('1','2','3','4','5','6','7','n/a'),
`q_65` enum('1','2','3','4','5','6','7','n/a'),
`q_66` enum('1','2','3','4','5','6','7','n/a'),
`q_67` enum('1','2','3','4','5','6','7','n/a'),
`q_68` enum('1','2','3','4','5','6','7','n/a'),
`q_69` enum('1','2','3','4','5','6','7','n/a'),
`q_70` enum('1','2','3','4','5','6','7','n/a'),
`q_71` enum('1','2','3','4','5','6','7','n/a'),
`q_72` enum('1','2','3','4','5','6','7','n/a'),
`q_73` enum('1','2','3','4','5','6','7','n/a'),
`q_74` enum('1','2','3','4','5','6','7','n/a'),
`q_75` enum('1','2','3','4','5','6','7','n/a'),
`q_76` enum('1','2','3','4','5','6','7','n/a'),
`q_77` enum('1','2','3','4','5','6','7','n/a'),
`q_78` enum('1','2','3','4','5','6','7','n/a'),
`q_79` enum('1','2','3','4','5','6','7','n/a'),
`q_80` enum('1','2','3','4','5','6','7','n/a'),
`q_81` enum('1','2','3','4','5','6','7','n/a'),
`q_82` enum('1','2','3','4','5','6','7','n/a'),
`q_83` enum('1','2','3','4','5','6','7','n/a'),
`q_84` enum('1','2','3','4','5','6','7','n/a'),
`q_85` enum('1','2','3','4','5','6','7','n/a'),
`q_86` enum('1','2','3','4','5','6','7','n/a'),
`q_87` enum('1','2','3','4','5','6','7','n/a'),
`q_88` enum('1','2','3','4','5','6','7','n/a'),
`q_89` enum('1','2','3','4','5','6','7','n/a'),
`q_90` enum('1','2','3','4','5','6','7','n/a'),
`q_91` enum('1','2','3','4','5','6','7','n/a'),
`q_92` enum('1','2','3','4','5','6','7','n/a'),
`q_93` enum('1','2','3','4','5','6','7','n/a'),
`q_94` enum('1','2','3','4','5','6','7','n/a'),
`q_95` enum('1','2','3','4','5','6','7','n/a'),
`q_96` enum('1','2','3','4','5','6','7','n/a'),
`q_97` enum('1','2','3','4','5','6','7','n/a'),
`q_98` enum('1','2','3','4','5','6','7','n/a'),
`q_99` enum('1','2','3','4','5','6','7','n/a'),
`q_100` enum('1','2','3','4','5','6','7','n/a'),
`q_101` enum('1','2','3','4','5','6','7','n/a'),
`q_102` enum('1','2','3','4','5','6','7','n/a'),
`q_103` enum('1','2','3','4','5','6','7','n/a'),
`q_104` enum('1','2','3','4','5','6','7','n/a'),
`q_105` enum('1','2','3','4','5','6','7','n/a'),
`q_106` enum('1','2','3','4','5','6','7','n/a'),
`q_107` enum('1','2','3','4','5','6','7','n/a'),
`q_108` enum('1','2','3','4','5','6','7','n/a'),
`q_109` enum('1','2','3','4','5','6','7','n/a'),
`q_110` enum('1','2','3','4','5','6','7','n/a'),
`q_111` enum('1','2','3','4','5','6','7','n/a'),
`q_112` enum('1','2','3','4','5','6','7','n/a'),
`q_113` enum('1','2','3','4','5','6','7','n/a'),
`q_114` enum('1','2','3','4','5','6','7','n/a'),
`q_115` enum('1','2','3','4','5','6','7','n/a'),
`q_116` enum('1','2','3','4','5','6','7','n/a'),
`q_117` enum('1','2','3','4','5','6','7','n/a'),
`q_118` enum('1','2','3','4','5','6','7','n/a'),
`q_119` enum('1','2','3','4','5','6','7','n/a'),
`q_120` enum('1','2','3','4','5','6','7','n/a'),
`q_121` enum('1','2','3','4','5','6','7','n/a'),
`q_122` enum('1','2','3','4','5','6','7','n/a'),
`q_123` enum('1','2','3','4','5','6','7','n/a'),
`q_124` enum('1','2','3','4','5','6','7','n/a'),
`q_125` enum('1','2','3','4','5','6','7','n/a'),
`q_126` enum('1','2','3','4','5','6','7','n/a'),
`q_127` enum('1','2','3','4','5','6','7','n/a'),
`q_128` enum('1','2','3','4','5','6','7','n/a'),
`q_129` enum('1','2','3','4','5','6','7','n/a'),
`q_130` enum('1','2','3','4','5','6','7','n/a'),
`q_131` enum('1','2','3','4','5','6','7','n/a'),
`q_132` enum('1','2','3','4','5','6','7','n/a'),
`q_133` enum('1','2','3','4','5','6','7','n/a'),
`q_134` enum('1','2','3','4','5','6','7','n/a'),
`q_135` enum('1','2','3','4','5','6','7','n/a'),
`q_136` enum('1','2','3','4','5','6','7','n/a'),
`q_137` enum('1','2','3','4','5','6','7','n/a'),
`q_138` enum('1','2','3','4','5','6','7','n/a'),
`q_139` enum('1','2','3','4','5','6','7','n/a'),
`q_140` enum('1','2','3','4','5','6','7','n/a'),
`q_141` enum('1','2','3','4','5','6','7','n/a'),
`q_142` enum('1','2','3','4','5','6','7','n/a'),
`q_143` enum('1','2','3','4','5','6','7','n/a'),
`q_144` enum('1','2','3','4','5','6','7','n/a'),
`q_145` enum('1','2','3','4','5','6','7','n/a'),
`q_146` enum('1','2','3','4','5','6','7','n/a'),
`q_147` enum('1','2','3','4','5','6','7','n/a'),
`q_148` enum('1','2','3','4','5','6','7','n/a'),
`q_149` enum('1','2','3','4','5','6','7','n/a'),
`q_150` enum('1','2','3','4','5','6','7','n/a'),
`q_151` enum('1','2','3','4','5','6','7','n/a'),
`q_152` enum('1','2','3','4','5','6','7','n/a'),
`q_153` enum('1','2','3','4','5','6','7','n/a'),
`q_154` enum('1','2','3','4','5','6','7','n/a'),
`q_155` enum('1','2','3','4','5','6','7','n/a'),
`q_156` enum('1','2','3','4','5','6','7','n/a'),
`q_157` enum('1','2','3','4','5','6','7','n/a'),
`q_158` enum('1','2','3','4','5','6','7','n/a'),
`q_159` enum('1','2','3','4','5','6','7','n/a'),
`q_160` enum('1','2','3','4','5','6','7','n/a'),
`q_161` enum('1','2','3','4','5','6','7','n/a'),
`q_162` enum('1','2','3','4','5','6','7','n/a'),
`q_163` enum('1','2','3','4','5','6','7','n/a'),
`q_164` enum('1','2','3','4','5','6','7','n/a'),
`q_165` enum('1','2','3','4','5','6','7','n/a'),
`q_166` enum('1','2','3','4','5','6','7','n/a'),
`q_167` enum('1','2','3','4','5','6','7','n/a'),
`q_168` enum('1','2','3','4','5','6','7','n/a'),
`q_169` enum('1','2','3','4','5','6','7','n/a'),
`q_170` enum('1','2','3','4','5','6','7','n/a'),
`q_171` enum('1','2','3','4','5','6','7','n/a'),
`q_172` enum('1','2','3','4','5','6','7','n/a'),
`q_173` enum('1','2','3','4','5','6','7','n/a'),
`q_174` enum('1','2','3','4','5','6','7','n/a'),
`q_175` enum('1','2','3','4','5','6','7','n/a'),
`q_176` enum('1','2','3','4','5','6','7','n/a'),
`q_177` enum('1','2','3','4','5','6','7','n/a'),
`q_178` enum('1','2','3','4','5','6','7','n/a'),
`q_179` enum('1','2','3','4','5','6','7','n/a'),
`q_180` enum('1','2','3','4','5','6','7','n/a'),
`q_181` enum('1','2','3','4','5','6','7','n/a'),
`q_182` enum('1','2','3','4','5','6','7','n/a'),
`q_183` enum('1','2','3','4','5','6','7','n/a'),
`q_184` enum('1','2','3','4','5','6','7','n/a'),
`q_185` enum('1','2','3','4','5','6','7','n/a'),
`q_186` enum('1','2','3','4','5','6','7','n/a'),
`q_187` enum('1','2','3','4','5','6','7','n/a'),
`q_188` enum('1','2','3','4','5','6','7','n/a'),
`q_189` enum('1','2','3','4','5','6','7','n/a'),
`q_190` enum('1','2','3','4','5','6','7','n/a'),
`q_191` enum('1','2','3','4','5','6','7','n/a'),
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;