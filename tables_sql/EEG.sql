CREATE TABLE `EEG` (
`CommentID`                            varchar(255) NOT NULL default '',
`UserID`                               varchar(255) default NULL,
`Examiner`                             varchar(255) default NULL,
`Testdate`                             timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
`Data_entry_completion_status`         enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`Candidate_Age`                        VARCHAR(255) DEFAULT NULL,
`Window_Difference`                    VARCHAR(255) DEFAULT NULL,

-- ----------------------------
-- Columns for section Top   --
-- ----------------------------
`Date_taken`                           date default NULL,
`start_time`                           varchar(255) default NULL,
`start_time_status`                    enum('not_answered') default NULL,
`experimenter_initials`                varchar(255) default NULL,
`experimenter_initials_status`         enum('not_answered') default NULL,
`behavioral_assistant_initials`        varchar(255) default NULL,
`behavioral_assistant_initials_status` enum('not_answered') default NULL,
`caregiver_present`                    enum('y','n') default NULL,
`caregiver_role`                       varchar(255) default NULL,
`caregiver_role_status`                enum('not_answered') default NULL,
`file_top`                             varchar(255) default NULL,
`second_file_top`                      varchar(255) default NULL,
`ofc`                                  float default NULL,
`ofc_status`                           enum('not_answered') default NULL,
`net_serial_number`                    varchar(255) default NULL,
`net_serial_number_status`             enum('not_answered') default NULL,
`additional_notes`                     text default NULL,
`additional_notes_status`              enum('not_answered') default NULL,

-- --------------------------------
-- Columns for section EEG Net   --
-- --------------------------------
`impedance_before_netting`             enum('y','n') default NULL,
`bad_channels_before_netting`          text default NULL,
`bad_channels_before_netting_status`   enum('not_answered') default NULL,
`impedance_after_netting`              enum('y','n') default NULL,
`bad_channels_after_netting`           text default NULL,
`bad_channels_after_netting_status`    enum('not_answered') default NULL,
`net_quality_rating`                   enum('1','2','3','not_answered') default NULL,
`netting_notes`                        text default NULL,
`netting_notes_status`                 enum('not_answered') default NULL,
`Photo_of_Net_Placement_Taken`         enum('y','n') default NULL,
`photo_file`                           varchar(255) default NULL,

-- ----------------------------------------------------
-- Columns for section Paradigm 1: Resting Bubbles   --
-- ----------------------------------------------------
`file_paradigm1`                       varchar(255) default NULL,
`second_file_paradigm1`                varchar(255) default NULL,
`note_1_1`                             text default NULL,
`note_1_1_status`                      enum('not_answered') default NULL,
`note_1_2`                             text default NULL,
`note_1_2_status`                      enum('not_answered') default NULL,
`note_1_3`                             text default NULL,
`note_1_3_status`                      enum('not_answered') default NULL,
`mood_1`                               enum('1','2','3','4','5') default NULL,
`quality_1`                            enum('1','2','3') default NULL,
`trials_completed_1`                   varchar(255) default NULL,
`trials_completed_1_status`            enum('not_answered') default NULL,

-- ----------------------------------------
-- Columns for section Paradigm 2: VEP   --
-- ----------------------------------------
`file_paradigm2`                       varchar(255) default NULL,
`second_file_paradigm2`                varchar(255) default NULL,
`note_2_1`                             text default NULL,
`note_2_1_status`                      enum('not_answered') default NULL,
`note_2_2`                             text default NULL,
`note_2_2_status`                      enum('not_answered') default NULL,
`note_2_3`                             text default NULL,
`note_2_3_status`                      enum('not_answered') default NULL,
`mood_2`                               enum('1','2','3','4','5') default NULL,
`quality_2`                            enum('1','2','3') default NULL,
`trials_completed_2`                   varchar(255) default NULL,
`trials_completed_2_status`            enum('not_answered') default NULL,

-- ----------------------------------------
-- Columns for section Paradigm 3: AEP   --
-- ----------------------------------------
`file_paradigm3`                       varchar(255) default NULL,
`second_file_paradigm3`                varchar(255) default NULL,
`note_3_1`                             text default NULL,
`note_3_1_status`                      enum('not_answered') default NULL,
`note_3_2`                             text default NULL,
`note_3_2_status`                      enum('not_answered') default NULL,
`note_3_3`                             text default NULL,
`note_3_3_status`                      enum('not_answered') default NULL,
`mood_3`                               enum('1','2','3','4','5') default NULL,
`quality_3`                            enum('1','2','3') default NULL,
`trials_completed_3`                   varchar(255) default NULL,
`trials_completed_3_status`            enum('not_answered') default NULL,

-- ------------------------------------------------------
-- Columns for section Paradigm 4: Social/Non-Social   --
-- ------------------------------------------------------
`file_paradigm4`                       varchar(255) default NULL,
`second_file_paradigm4`                varchar(255) default NULL,
`note_4_1`                             text default NULL,
`note_4_1_status`                      enum('not_answered') default NULL,
`note_4_2`                             text default NULL,
`note_4_2_status`                      enum('not_answered') default NULL,
`note_4_3`                             text default NULL,
`note_4_3_status`                      enum('not_answered') default NULL,
`mood_4`                               enum('1','2','3','4','5') default NULL,
`quality_4`                            enum('1','2','3') default NULL,
`trials_completed_4`                   varchar(255) default NULL,
`trials_completed_4_status`            enum('not_answered') default NULL,

-- --------------------------------------------------------
-- Columns for section Overall EEG Session Information   --
-- --------------------------------------------------------
`note_5_1`                             text default NULL,
`note_5_1_status`                      enum('not_answered') default NULL,
`end_time`                             varchar(255) default NULL,
`end_time_status`                      enum('not_answered') default NULL,
`overall_5`                            enum('f','m') default NULL,
`experimental_order_5`                 enum('f','m') default NULL,
`note_5_2`                             text default NULL,
`note_5_2_status`                      enum('not_answered') default NULL,
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
