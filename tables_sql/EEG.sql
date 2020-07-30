CREATE TABLE `EEG` (
`CommentID`                            varchar(255) NOT NULL default '',
`UserID`                               varchar(255),
`Examiner`                             varchar(255),
`Testdate`                             timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
`Data_entry_completion_status`         enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Candidate_Age`                        VARCHAR(255),
`Window_Difference`                    VARCHAR(255),

-- ----------------------------
-- Columns for section Top   --
-- ----------------------------
`Date_taken`                           date,
`start_time`                           varchar(255),
`start_time_status`                    enum('not_answered'),
`experimenter_initials`                varchar(255),
`experimenter_initials_status`         enum('not_answered'),
`behavioral_assistant_initials`        varchar(255),
`behavioral_assistant_initials_status` enum('not_answered'),
`caregiver_present`                    enum('y','n'),
`file_top`                             varchar(255),
`second_file_top`                      varchar(255),
`ofc`                                  float,
`ofc_status`                           enum('not_answered'),
`net_serial_number`                    varchar(255),
`net_serial_number_status`             enum('not_answered'),
`additional_notes`                     text,
`additional_notes_status`              enum('not_answered'),

-- --------------------------------
-- Columns for section EEG Net   --
-- --------------------------------
`impedance_before_netting`             enum('y','n'),
`bad_channels_before_netting`          text,
`bad_channels_before_netting_status`   enum('not_answered'),
`impedance_after_netting`              enum('y','n'),
`bad_channels_after_netting`           text,
`bad_channels_after_netting_status`    enum('not_answered'),
`net_quality_rating`                   enum('1','2','3','not_answered'),

-- ----------------------------------------------------
-- Columns for section Paradigm 1: Resting Bubbles   --
-- ----------------------------------------------------
`note_1_1`                             text,
`note_1_1_status`                      enum('not_answered'),
`note_1_2`                             text,
`note_1_2_status`                      enum('not_answered'),
`mood_1`                               enum('1','2','3','4','5'),
`paradigm_completed_1`                 enum('y','n','p'),

-- ----------------------------------------
-- Columns for section Paradigm 2: Visual   --
-- ----------------------------------------
`note_2_1`                             text,
`note_2_1_status`                      enum('not_answered'),
`note_2_2`                             text,
`note_2_2_status`                      enum('not_answered'),
`mood_2`                               enum('1','2','3','4','5'),
`paradigm_completed_2`                 enum('y','n','p'),

-- ----------------------------------------
-- Columns for section Paradigm 3: Resting   --
-- ----------------------------------------
`note_3_1`                             text,
`note_3_1_status`                      enum('not_answered'),
`note_3_2`                             text,
`note_3_2_status`                      enum('not_answered'),
`mood_3`                               enum('1','2','3','4','5'),
`paradigm_completed_3`                 enum('y','n','p'),

-- ------------------------------------------------------
-- Columns for section Paradigm 4: Auditory   --
-- ------------------------------------------------------
`note_4_1`                             text,
`note_4_1_status`                      enum('not_answered'),
`note_4_2`                             text,
`note_4_2_status`                      enum('not_answered'),
`mood_4`                               enum('1','2','3','4','5'),
`paradigm_completed_4`                 enum('y','n','p'),

-- --------------------------------------------------------
-- Columns for section Paradigm 5: Resting     --
-- --------------------------------------------------------
`note_5_1`                             text,
`note_5_1_status`                      enum('not_answered'),
`note_5_2`                             text,
`note_5_2_status`                      enum('not_answered'),
`mood_5`                               enum('1','2','3','4','5'),
`paradigm_completed_5`                 enum('y','n','p'),

-- --------------------------------------------------------
-- Columns for section Overall EEG Session Information   --
-- --------------------------------------------------------
`note_6_1` text,
`note_6_1_status` enum('not_answered'),
`end_time` varchar(255),
`end_time_status` enum('not_answered'),
`standard_paradigm_order` enum('y','n'),
`note_6_2` text,
`note_6_2_status` enum('not_answered'),

PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
