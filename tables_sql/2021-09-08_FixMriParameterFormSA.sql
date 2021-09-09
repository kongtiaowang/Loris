-- -------------------------------------------------------------------------------------------------------
--
-- Corrects the MRI parameter form SA for which:
-- 1. Data was entered in the DWI section when it should have been entered in the DWICmrr section
-- 2. Data was entered in the DWICmrr section when it should have been entered in the DWI section
-- Bascially we are transfering values from one section to another.
--
-- We determine which section the data should have gone into by examining parameter 'protocol_name' of all
-- DTI files associated to the scanning session:
-- * if there was at least one protocol with a name that matches 'DWIcmrr%' and no protocol whose names
--   don't match 'DWIcmrr%', then data goes in the DWIcmrr section
-- * if there is no protocol with a name that matches 'DWIcmrr%' and at least one protocol whose name
--   doesn't match 'DWIcmrr%', then data goes in the DWI section
--
-- ------------------------------------------------------------------------------------------------------


UPDATE mri_parameter_form_sa mpf
       JOIN flag f
         ON ( f.commentid = mpf.commentid )
       JOIN session s
         ON ( s.id = f.sessionid )
SET    mpf.cmrr1_dti_sequences_acquired  = COALESCE(mpf.cmrr1_dti_sequences_acquired , mpf.siemens_dti_sequences_acquired),
       mpf.cmrr1_dti3_shell              = COALESCE(mpf.cmrr1_dti3_shell             , mpf.siemens_dti3_shell),
       mpf.cmrr1_dti3_shell_attempts     = COALESCE(mpf.cmrr1_dti3_shell_attempts    , mpf.siemens_dti3_shell_attempts),
       mpf.cmrr1_dti3_shell_num_attempts = IF(mpf.cmrr1_dti3_shell_num_attempts = 0, mpf.siemens_dti3_shell_num_attempts, mpf.cmrr1_dti3_shell_num_attempts),
       mpf.cmrr1_dti3_shell_facemask     = COALESCE(mpf.cmrr1_dti3_shell_facemask    , mpf.siemens_dti3_shell_facemask),
       mpf.cmrr1_6b0                     = COALESCE(mpf.cmrr1_6b0                    , mpf.siemens_6b0),
       mpf.cmrr1_6b0_attempts            = COALESCE(mpf.cmrr1_6b0_attempts           , mpf.siemens_6b0_attempts),
       mpf.cmrr1_6b0_num_attempts        = IF(mpf.cmrr1_6b0_num_attempts = 0, mpf.siemens_6b0_num_attempts, mpf.cmrr1_6b0_num_attempts),
       mpf.cmrr1_6b0_facemask            = COALESCE(mpf.cmrr1_6b0_facemask           , mpf.siemens_6b0_facemask),
       mpf.cmrr1_dti2_shell              = COALESCE(mpf.cmrr1_dti2_shell             , mpf.siemens_dti2_shell),
       mpf.cmrr1_dti2_shell_attempts     = COALESCE(mpf.cmrr1_dti2_shell_attempts    , mpf.siemens_dti2_shell_attempts),
       mpf.cmrr1_dti2_shell_num_attempts = IF(mpf.cmrr1_dti2_shell_num_attempts = 0, mpf.siemens_dti2_shell_num_attempts, mpf.cmrr1_dti2_shell_num_attempts),
       mpf.cmrr1_dti2_shell_facemask     = COALESCE(mpf.cmrr1_dti2_shell_facemask    , mpf.siemens_dti2_shell_facemask),
       mpf.cmrr1_6b02                    = COALESCE(mpf.cmrr1_6b02                   , mpf.siemens_6b02),
       mpf.cmrr1_6b02_attempts           = COALESCE(mpf.cmrr1_6b02_attempts          , mpf.siemens_6b02_attempts),
       mpf.cmrr1_6b02_num_attempts       = IF(mpf.cmrr1_6b02_num_attempts = 0, mpf.siemens_6b02_num_attempts, mpf.cmrr1_6b02_num_attempts),
       mpf.cmrr1_6b02_facemask           = COALESCE(mpf.cmrr1_6b02_facemask          , mpf.siemens_6b02_facemask),
       mpf.cmrr1_dti1_shell              = COALESCE(mpf.cmrr1_dti1_shell             , mpf.siemens_dti1_shell),
       mpf.cmrr1_dti1_shell_attempts     = COALESCE(mpf.cmrr1_dti1_shell_attempts    , mpf.siemens_dti1_shell_attempts),
       mpf.cmrr1_dti1_shell_num_attempts = IF(mpf.cmrr1_dti1_shell_num_attempts = 0, mpf.siemens_dti1_shell_num_attempts, mpf.cmrr1_dti1_shell_num_attempts),
       mpf.cmrr1_dti1_shell_facemask     = COALESCE(mpf.cmrr1_dti1_shell_facemask    , mpf.siemens_dti1_shell_facemask),
       mpf.cmrr1_dti_comments            = COALESCE(mpf.cmrr1_dti_comments           , mpf.siemens_dti_comments),

       mpf.cmrr2_dti_sequences_acquired_2  = COALESCE(mpf.cmrr2_dti_sequences_acquired_2 , mpf.siemens2_dti_sequences_acquired_2),
       mpf.cmrr2_dti3_shell_2              = COALESCE(mpf.cmrr2_dti3_shell_2             , mpf.siemens2_dti3_shell_2),
       mpf.cmrr2_dti3_shell_attempts_2     = COALESCE(mpf.cmrr2_dti3_shell_attempts_2    , mpf.siemens2_dti3_shell_attempts_2),
       mpf.cmrr2_dti3_shell_num_attempts_2 = IF(mpf.cmrr2_dti3_shell_num_attempts_2 = 0, mpf.siemens2_dti3_shell_num_attempts_2, mpf.cmrr2_dti3_shell_num_attempts_2),
       mpf.cmrr2_dti3_shell_2_facemask_2   = COALESCE(mpf.cmrr2_dti3_shell_2_facemask_2  , mpf.siemens2_dti3_shell_2_facemask_2),
       mpf.cmrr2_6b0_2                     = COALESCE(mpf.cmrr2_6b0_2                    , mpf.siemens2_6b0_2),
       mpf.cmrr2_6b0_attempts_2            = COALESCE(mpf.cmrr2_6b0_attempts_2           , mpf.siemens2_6b0_attempts_2),
       mpf.cmrr2_6b0_num_attempts_2        = IF(mpf.cmrr2_6b0_num_attempts_2 = 0, mpf.siemens2_6b0_num_attempts_2, mpf.cmrr2_6b0_num_attempts_2),
       mpf.cmrr2_6b0_2_facemask_2          = COALESCE(mpf.cmrr2_6b0_2_facemask_2         , mpf.siemens2_6b0_2_facemask_2),
       mpf.cmrr2_dti2_shell_2              = COALESCE(mpf.cmrr2_dti2_shell_2             , mpf.siemens2_dti2_shell_2),
       mpf.cmrr2_dti2_shell_attempts_2     = COALESCE(mpf.cmrr2_dti2_shell_attempts_2    , mpf.siemens2_dti2_shell_attempts_2),
       mpf.cmrr2_dti2_shell_num_attempts_2 = IF(mpf.cmrr2_dti2_shell_num_attempts_2 = 0, mpf.siemens2_dti2_shell_num_attempts_2, mpf.cmrr2_dti2_shell_num_attempts_2),
       mpf.cmrr2_dti2_shell_2_facemask_2   = COALESCE(mpf.cmrr2_dti2_shell_2_facemask_2  , mpf.siemens2_dti2_shell_2_facemask_2),
       mpf.cmrr2_6b02_2                    = COALESCE(mpf.cmrr2_6b02_2                   , mpf.siemens2_6b02_2),
       mpf.cmrr2_6b02_attempts_2           = COALESCE(mpf.cmrr2_6b02_attempts_2          , mpf.siemens2_6b02_attempts_2),
       mpf.cmrr2_6b02_num_attempts_2       = IF(mpf.cmrr2_6b02_num_attempts_2 = 0, mpf.siemens2_6b02_num_attempts_2, mpf.cmrr2_6b02_num_attempts_2),
       mpf.cmrr2_6b02_2_facemask_2         = COALESCE(mpf.cmrr2_6b02_2_facemask_2        , mpf.siemens2_6b02_2_facemask_2),
       mpf.cmrr2_dti1_shell_2              = COALESCE(mpf.cmrr2_dti1_shell_2             , mpf.siemens2_dti1_shell_2),
       mpf.cmrr2_dti1_shell_attempts_2     = COALESCE(mpf.cmrr2_dti1_shell_attempts_2    , mpf.siemens2_dti1_shell_attempts_2),
       mpf.cmrr2_dti1_shell_num_attempts_2 = IF(mpf.cmrr2_dti1_shell_num_attempts_2 = 0, mpf.siemens2_dti1_shell_num_attempts_2, mpf.cmrr2_dti1_shell_num_attempts_2),
       mpf.cmrr2_dti1_shell_2_facemask_2   = COALESCE(mpf.cmrr2_dti1_shell_2_facemask_2  , mpf.siemens2_dti1_shell_2_facemask_2),
       mpf.cmrr2_dti_comments_2            = COALESCE(mpf.cmrr2_dti_comments_2           , mpf.siemens2_dti_comments_2),

       mpf.cmrr3_dti_sequences_acquired_3  = COALESCE(mpf.cmrr3_dti_sequences_acquired_3 , mpf.siemens3_dti_sequences_acquired_3),
       mpf.cmrr3_dti3_shell_3              = COALESCE(mpf.cmrr3_dti3_shell_3             , mpf.siemens3_dti3_shell_3),
       mpf.cmrr3_dti3_shell_attempts_3     = COALESCE(mpf.cmrr3_dti3_shell_attempts_3    , mpf.siemens3_dti3_shell_attempts_3),
       mpf.cmrr3_dti3_shell_num_attempts_3 = IF(mpf.cmrr3_dti3_shell_num_attempts_3 = 0, mpf.siemens3_dti3_shell_num_attempts_3, mpf.cmrr3_dti3_shell_num_attempts_3),
       mpf.cmrr3_dti3_shell_3_facemask_3   = COALESCE(mpf.cmrr3_dti3_shell_3_facemask_3  , mpf.siemens3_dti3_shell_3_facemask_3),
       mpf.cmrr3_6b0_3                     = COALESCE(mpf.cmrr3_6b0_3                    , mpf.siemens3_6b0_3),
       mpf.cmrr3_6b0_attempts_3            = COALESCE(mpf.cmrr3_6b0_attempts_3           , mpf.siemens3_6b0_attempts_3),
       mpf.cmrr3_6b0_num_attempts_3        = IF(mpf.cmrr3_6b0_num_attempts_3 = 0, mpf.siemens3_6b0_num_attempts_3, mpf.cmrr3_6b0_num_attempts_3),
       mpf.cmrr3_6b0_3_facemask_3          = COALESCE(mpf.cmrr3_6b0_3_facemask_3         , mpf.siemens3_6b0_3_facemask_3),
       mpf.cmrr3_dti2_shell_3              = COALESCE(mpf.cmrr3_dti2_shell_3             , mpf.siemens3_dti2_shell_3),
       mpf.cmrr3_dti2_shell_attempts_3     = COALESCE(mpf.cmrr3_dti2_shell_attempts_3    , mpf.siemens3_dti2_shell_attempts_3),
       mpf.cmrr3_dti2_shell_num_attempts_3 = IF(mpf.cmrr3_dti2_shell_num_attempts_3 = 0, mpf.siemens3_dti2_shell_num_attempts_3, mpf.cmrr3_dti2_shell_num_attempts_3),
       mpf.cmrr3_dti2_shell_3_facemask_3   = COALESCE(mpf.cmrr3_dti2_shell_3_facemask_3  , mpf.siemens3_dti2_shell_3_facemask_3),
       mpf.cmrr3_6b02_3                    = COALESCE(mpf.cmrr3_6b02_3                   , mpf.siemens3_6b02_3),
       mpf.cmrr3_6b02_attempts_3           = COALESCE(mpf.cmrr3_6b02_attempts_3          , mpf.siemens3_6b02_attempts_3),
       mpf.cmrr3_6b02_num_attempts_3       = IF(mpf.cmrr3_6b02_num_attempts_3 = 0, mpf.siemens3_6b02_num_attempts_3, mpf.cmrr3_6b02_num_attempts_3),
       mpf.cmrr3_6b02_3_facemask_3         = COALESCE(mpf.cmrr3_6b02_3_facemask_3        , mpf.siemens3_6b02_3_facemask_3),
       mpf.cmrr3_dti1_shell_3              = COALESCE(mpf.cmrr3_dti1_shell_3             , mpf.siemens3_dti1_shell_3),
       mpf.cmrr3_dti1_shell_attempts_3     = COALESCE(mpf.cmrr3_dti1_shell_attempts_3    , mpf.siemens3_dti1_shell_attempts_3),
       mpf.cmrr3_dti1_shell_num_attempts_3 = IF(mpf.cmrr3_dti1_shell_num_attempts_3 = 0, mpf.siemens3_dti1_shell_num_attempts_3, mpf.cmrr3_dti1_shell_num_attempts_3),
       mpf.cmrr3_dti1_shell_3_facemask_3   = COALESCE(mpf.cmrr3_dti1_shell_3_facemask_3  , mpf.siemens3_dti1_shell_3_facemask_3),
       mpf.cmrr3_dti_comments_3            = COALESCE(mpf.cmrr3_dti_comments_3           , mpf.siemens3_dti_comments_3),

       mpf.cmrr4_dti_sequences_acquired_4  = COALESCE(mpf.cmrr4_dti_sequences_acquired_4 , mpf.siemens4_dti_sequences_acquired_4),
       mpf.cmrr4_dti3_shell_4              = COALESCE(mpf.cmrr4_dti3_shell_4             , mpf.siemens4_dti3_shell_4),
       mpf.cmrr4_dti3_shell_attempts_4     = COALESCE(mpf.cmrr4_dti3_shell_attempts_4    , mpf.siemens4_dti3_shell_attempts_4),
       mpf.cmrr4_dti3_shell_num_attempts_4 = IF(mpf.cmrr4_dti3_shell_num_attempts_4 = 0, mpf.siemens4_dti3_shell_num_attempts_4, mpf.cmrr4_dti3_shell_num_attempts_4),
       mpf.cmrr4_dti3_shell_4_facemask_4   = COALESCE(mpf.cmrr4_dti3_shell_4_facemask_4  , mpf.siemens4_dti3_shell_4_facemask_4),
       mpf.cmrr4_6b0_4                     = COALESCE(mpf.cmrr4_6b0_4                    , mpf.siemens4_6b0_4),
       mpf.cmrr4_6b0_attempts_4            = COALESCE(mpf.cmrr4_6b0_attempts_4           , mpf.siemens4_6b0_attempts_4),
       mpf.cmrr4_6b0_num_attempts_4        = IF(mpf.cmrr4_6b0_num_attempts_4 = 0, mpf.siemens4_6b0_num_attempts_4, mpf.cmrr4_6b0_num_attempts_4),
       mpf.cmrr4_6b0_4_facemask_4          = COALESCE(mpf.cmrr4_6b0_4_facemask_4         , mpf.siemens4_6b0_4_facemask_4),
       mpf.cmrr4_dti2_shell_4              = COALESCE(mpf.cmrr4_dti2_shell_4             , mpf.siemens4_dti2_shell_4),
       mpf.cmrr4_dti2_shell_attempts_4     = COALESCE(mpf.cmrr4_dti2_shell_attempts_4    , mpf.siemens4_dti2_shell_attempts_4),
       mpf.cmrr4_dti2_shell_num_attempts_4 = IF(mpf.cmrr4_dti2_shell_num_attempts_4 = 0, mpf.siemens4_dti2_shell_num_attempts_4, mpf.cmrr4_dti2_shell_num_attempts_4),
       mpf.cmrr4_dti2_shell_4_facemask_4   = COALESCE(mpf.cmrr4_dti2_shell_4_facemask_4  , mpf.siemens4_dti2_shell_4_facemask_4),
       mpf.cmrr4_6b02_4                    = COALESCE(mpf.cmrr4_6b02_4                   , mpf.siemens4_6b02_4),
       mpf.cmrr4_6b02_attempts_4           = COALESCE(mpf.cmrr4_6b02_attempts_4          , mpf.siemens4_6b02_attempts_4),
       mpf.cmrr4_6b02_num_attempts_4       = IF(mpf.cmrr4_6b02_num_attempts_4 = 0, mpf.siemens4_6b02_num_attempts_4, mpf.cmrr4_6b02_num_attempts_4),
       mpf.cmrr4_6b02_4_facemask_4         = COALESCE(mpf.cmrr4_6b02_4_facemask_4        , mpf.siemens4_6b02_4_facemask_4),
       mpf.cmrr4_dti1_shell_4              = COALESCE(mpf.cmrr4_dti1_shell_4             , mpf.siemens4_dti1_shell_4),
       mpf.cmrr4_dti1_shell_attempts_4     = COALESCE(mpf.cmrr4_dti1_shell_attempts_4    , mpf.siemens4_dti1_shell_attempts_4),
       mpf.cmrr4_dti1_shell_num_attempts_4 = IF(mpf.cmrr4_dti1_shell_num_attempts_4 = 0, mpf.siemens4_dti1_shell_num_attempts_4, mpf.cmrr4_dti1_shell_num_attempts_4),
       mpf.cmrr4_dti1_shell_4_facemask_4   = COALESCE(mpf.cmrr4_dti1_shell_4_facemask_4  , mpf.siemens4_dti1_shell_4_facemask_4),
       mpf.cmrr4_dti_comments_4            = COALESCE(mpf.cmrr4_dti_comments_4           , mpf.siemens4_dti_comments_4)

WHERE  EXISTS(SELECT 1
              FROM   files f
                     JOIN mri_scan_type mst
                       ON ( mst.id = f.acquisitionprotocolid )
                     JOIN parameter_file pf
                       ON ( pf.fileid = f.fileid )
                     JOIN parameter_type pt
                       ON( pt.parametertypeid = pf.parametertypeid )
              WHERE  f.sessionid = s.id
                     AND pt.NAME = 'protocol_name'
                     AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                     AND pf.value LIKE 'DWIcmrr%')
       AND NOT EXISTS(SELECT 1
                      FROM   files f
                             JOIN mri_scan_type mst
                               ON ( mst.id = f.acquisitionprotocolid )
                             JOIN parameter_file pf
                               ON ( pf.fileid = f.fileid )
                             JOIN parameter_type pt
                               ON( pt.parametertypeid = pf.parametertypeid )
                      WHERE  f.sessionid = s.id
                             AND pt.NAME = 'protocol_name'
                             AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                             AND pf.value NOT LIKE 'DWIcmrr%')
       AND s.visit_label IN ( 'VSA', 'VSA-CVD' )
       AND f.data_entry IS NOT NULL;


-- -----------------------------------------------------------------------------------------------

UPDATE mri_parameter_form_sa mpf
       JOIN flag f
         ON ( f.commentid = mpf.commentid )
       JOIN session s
         ON ( s.id = f.sessionid )
SET  mpf.siemens_dti_sequences_acquired     = DEFAULT,
     mpf.siemens_dti3_shell                 = DEFAULT,
     mpf.siemens_dti3_shell_attempts        = DEFAULT,
     mpf.siemens_dti3_shell_num_attempts    = 0,
     mpf.siemens_dti3_shell_facemask        = DEFAULT,
     mpf.siemens_6b0                        = DEFAULT,
     mpf.siemens_6b0_attempts               = DEFAULT,
     mpf.siemens_6b0_num_attempts           = 0,
     mpf.siemens_6b0_facemask               = DEFAULT,
     mpf.siemens_dti2_shell                 = DEFAULT,
     mpf.siemens_dti2_shell_attempts        = DEFAULT,
     mpf.siemens_dti2_shell_num_attempts    = 0,
     mpf.siemens_dti2_shell_facemask        = DEFAULT,
     mpf.siemens_6b02                       = DEFAULT,
     mpf.siemens_6b02_attempts              = DEFAULT,
     mpf.siemens_6b02_num_attempts          = 0,
     mpf.siemens_6b02_facemask              = DEFAULT,
     mpf.siemens_dti1_shell                 = DEFAULT,
     mpf.siemens_dti1_shell_attempts        = DEFAULT,
     mpf.siemens_dti1_shell_num_attempts    = 0,
     mpf.siemens_dti1_shell_facemask        = DEFAULT,
     mpf.siemens_dti_comments               = DEFAULT,

     mpf.siemens2_dti_sequences_acquired_2  = DEFAULT,
     mpf.siemens2_dti3_shell_2              = DEFAULT,
     mpf.siemens2_dti3_shell_attempts_2     = DEFAULT,
     mpf.siemens2_dti3_shell_num_attempts_2 = 0,
     mpf.siemens2_dti3_shell_2_facemask_2   = DEFAULT,
     mpf.siemens2_6b0_2                     = DEFAULT,
     mpf.siemens2_6b0_attempts_2            = DEFAULT,
     mpf.siemens2_6b0_num_attempts_2        = 0,
     mpf.siemens2_6b0_2_facemask_2          = DEFAULT,
     mpf.siemens2_dti2_shell_2              = DEFAULT,
     mpf.siemens2_dti2_shell_attempts_2     = DEFAULT,
     mpf.siemens2_dti2_shell_num_attempts_2 = 0,
     mpf.siemens2_dti2_shell_2_facemask_2   = DEFAULT,
     mpf.siemens2_6b02_2                    = DEFAULT,
     mpf.siemens2_6b02_attempts_2           = DEFAULT,
     mpf.siemens2_6b02_num_attempts_2       = 0,
     mpf.siemens2_6b02_2_facemask_2         = DEFAULT,
     mpf.siemens2_dti1_shell_2              = DEFAULT,
     mpf.siemens2_dti1_shell_attempts_2     = DEFAULT,
     mpf.siemens2_dti1_shell_num_attempts_2 = 0,
     mpf.siemens2_dti1_shell_2_facemask_2   = DEFAULT,
     mpf.siemens2_dti_comments_2            = DEFAULT,

     mpf.siemens3_dti_sequences_acquired_3  = DEFAULT,
     mpf.siemens3_dti3_shell_3              = DEFAULT,
     mpf.siemens3_dti3_shell_attempts_3     = DEFAULT,
     mpf.siemens3_dti3_shell_num_attempts_3 = 0,
     mpf.siemens3_dti3_shell_3_facemask_3   = DEFAULT,
     mpf.siemens3_6b0_3                     = DEFAULT,
     mpf.siemens3_6b0_attempts_3            = DEFAULT,
     mpf.siemens3_6b0_num_attempts_3        = 0,
     mpf.siemens3_6b0_3_facemask_3          = DEFAULT,
     mpf.siemens3_dti2_shell_3              = DEFAULT,
     mpf.siemens3_dti2_shell_attempts_3     = DEFAULT,
     mpf.siemens3_dti2_shell_num_attempts_3 = 0,
     mpf.siemens3_dti2_shell_3_facemask_3   = DEFAULT,
     mpf.siemens3_6b02_3                    = DEFAULT,
     mpf.siemens3_6b02_attempts_3           = DEFAULT,
     mpf.siemens3_6b02_num_attempts_3       = 0,
     mpf.siemens3_6b02_3_facemask_3         = DEFAULT,
     mpf.siemens3_dti1_shell_3              = DEFAULT,
     mpf.siemens3_dti1_shell_attempts_3     = DEFAULT,
     mpf.siemens3_dti1_shell_num_attempts_3 = 0,
     mpf.siemens3_dti1_shell_3_facemask_3   = DEFAULT,
     mpf.siemens3_dti_comments_3            = DEFAULT,

     mpf.siemens4_dti_sequences_acquired_4  = DEFAULT,
     mpf.siemens4_dti3_shell_4              = DEFAULT,
     mpf.siemens4_dti3_shell_attempts_4     = DEFAULT,
     mpf.siemens4_dti3_shell_num_attempts_4 = 0,
     mpf.siemens4_dti3_shell_4_facemask_4   = DEFAULT,
     mpf.siemens4_6b0_4                     = DEFAULT,
     mpf.siemens4_6b0_attempts_4            = DEFAULT,
     mpf.siemens4_6b0_num_attempts_4        = 0,
     mpf.siemens4_6b0_4_facemask_4          = DEFAULT,
     mpf.siemens4_dti2_shell_4              = DEFAULT,
     mpf.siemens4_dti2_shell_attempts_4     = DEFAULT,
     mpf.siemens4_dti2_shell_num_attempts_4 = 0,
     mpf.siemens4_dti2_shell_4_facemask_4   = DEFAULT,
     mpf.siemens4_6b02_4                    = DEFAULT,
     mpf.siemens4_6b02_attempts_4           = DEFAULT,
     mpf.siemens4_6b02_num_attempts_4       = 0,
     mpf.siemens4_6b02_4_facemask_4         = DEFAULT,
     mpf.siemens4_dti1_shell_4              = DEFAULT,
     mpf.siemens4_dti1_shell_attempts_4     = DEFAULT,
     mpf.siemens4_dti1_shell_num_attempts_4 = 0,
     mpf.siemens4_dti1_shell_4_facemask_4   = DEFAULT,
     mpf.siemens4_dti_comments_4            = DEFAULT
WHERE  EXISTS(SELECT 1
              FROM   files f
                     JOIN mri_scan_type mst
                       ON ( mst.id = f.acquisitionprotocolid )
                     JOIN parameter_file pf
                       ON ( pf.fileid = f.fileid )
                     JOIN parameter_type pt
                       ON( pt.parametertypeid = pf.parametertypeid )
              WHERE  f.sessionid = s.id
                     AND pt.NAME = 'protocol_name'
                     AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                     AND pf.value LIKE 'DWIcmrr%')
       AND NOT EXISTS(SELECT 1
                      FROM   files f
                             JOIN mri_scan_type mst
                               ON ( mst.id = f.acquisitionprotocolid )
                             JOIN parameter_file pf
                               ON ( pf.fileid = f.fileid )
                             JOIN parameter_type pt
                               ON( pt.parametertypeid = pf.parametertypeid )
                      WHERE  f.sessionid = s.id
                             AND pt.NAME = 'protocol_name'
                             AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                             AND pf.value NOT LIKE 'DWIcmrr%')
       AND s.visit_label IN ( 'VSA', 'VSA-CVD' )
       AND f.data_entry IS NOT NULL;

-- -----------------------------------------------------------------------------------------------


UPDATE mri_parameter_form_sa mpf
       JOIN flag f
         ON ( f.commentid = mpf.commentid )
       JOIN session s
         ON ( s.id = f.sessionid )
SET    mpf.siemens_dti_sequences_acquired  = COALESCE(mpf.siemens_dti_sequences_acquired , mpf.cmrr1_dti_sequences_acquired),
       mpf.siemens_dti3_shell              = COALESCE(mpf.siemens_dti3_shell             , mpf.cmrr1_dti3_shell),
       mpf.siemens_dti3_shell_attempts     = COALESCE(mpf.siemens_dti3_shell_attempts    , mpf.cmrr1_dti3_shell_attempts),
       mpf.siemens_dti3_shell_num_attempts = IF(mpf.siemens_dti3_shell_num_attempts = 0, mpf.cmrr1_dti3_shell_num_attempts, mpf.siemens_dti3_shell_num_attempts),
       mpf.siemens_dti3_shell_facemask     = COALESCE(mpf.siemens_dti3_shell_facemask    , mpf.cmrr1_dti3_shell_facemask),
       mpf.siemens_6b0                     = COALESCE(mpf.siemens_6b0                    , mpf.cmrr1_6b0),
       mpf.siemens_6b0_attempts            = COALESCE(mpf.siemens_6b0_attempts           , mpf.cmrr1_6b0_attempts),
       mpf.siemens_6b0_num_attempts        = IF(mpf.siemens_6b0_num_attempts = 0, mpf.cmrr1_6b0_num_attempts, mpf.siemens_6b0_num_attempts),
       mpf.siemens_6b0_facemask            = COALESCE(mpf.siemens_6b0_facemask           , mpf.cmrr1_6b0_facemask),
       mpf.siemens_dti2_shell              = COALESCE(mpf.siemens_dti2_shell             , mpf.cmrr1_dti2_shell),
       mpf.siemens_dti2_shell_attempts     = COALESCE(mpf.siemens_dti2_shell_attempts    , mpf.cmrr1_dti2_shell_attempts),
       mpf.siemens_dti2_shell_num_attempts = IF(mpf.siemens_dti2_shell_num_attempts = 0, mpf.cmrr1_dti2_shell_num_attempts, mpf.siemens_dti2_shell_num_attempts),
       mpf.siemens_dti2_shell_facemask     = COALESCE(mpf.siemens_dti2_shell_facemask    , mpf.cmrr1_dti2_shell_facemask),
       mpf.siemens_6b02                    = COALESCE(mpf.siemens_6b02                   , mpf.cmrr1_6b02),
       mpf.siemens_6b02_attempts           = COALESCE(mpf.siemens_6b02_attempts          , mpf.cmrr1_6b02_attempts),
       mpf.siemens_6b02_num_attempts       = IF(mpf.siemens_6b02_num_attempts = 0, mpf.cmrr1_6b02_num_attempts, mpf.siemens_6b02_num_attempts),
       mpf.siemens_6b02_facemask           = COALESCE(mpf.siemens_6b02_facemask          , mpf.cmrr1_6b02_facemask),
       mpf.siemens_dti1_shell              = COALESCE(mpf.siemens_dti1_shell             , mpf.cmrr1_dti1_shell),
       mpf.siemens_dti1_shell_attempts     = COALESCE(mpf.siemens_dti1_shell_attempts    , mpf.cmrr1_dti1_shell_attempts),
       mpf.siemens_dti1_shell_num_attempts = IF(mpf.siemens_dti1_shell_num_attempts = 0, mpf.cmrr1_dti1_shell_num_attempts, mpf.siemens_dti1_shell_num_attempts),
       mpf.siemens_dti1_shell_facemask     = COALESCE(mpf.siemens_dti1_shell_facemask    , mpf.cmrr1_dti1_shell_facemask),
       mpf.siemens_dti_comments            = COALESCE(mpf.siemens_dti_comments           , mpf.cmrr1_dti_comments),

       mpf.siemens2_dti_sequences_acquired_2  = COALESCE(mpf.siemens2_dti_sequences_acquired_2 , mpf.cmrr2_dti_sequences_acquired_2),
       mpf.siemens2_dti3_shell_2              = COALESCE(mpf.siemens2_dti3_shell_2             , mpf.cmrr2_dti3_shell_2),
       mpf.siemens2_dti3_shell_attempts_2     = COALESCE(mpf.siemens2_dti3_shell_attempts_2    , mpf.cmrr2_dti3_shell_attempts_2),
       mpf.siemens2_dti3_shell_num_attempts_2 = IF(mpf.siemens2_dti3_shell_num_attempts_2 = 0, mpf.siemens2_dti3_shell_num_attempts_2, mpf.siemens2_dti3_shell_num_attempts_2),
       mpf.siemens2_dti3_shell_2_facemask_2   = COALESCE(mpf.siemens2_dti3_shell_2_facemask_2  , mpf.cmrr2_dti3_shell_2_facemask_2),
       mpf.siemens2_6b0_2                     = COALESCE(mpf.siemens2_6b0_2                    , mpf.cmrr2_6b0_2),
       mpf.siemens2_6b0_attempts_2            = COALESCE(mpf.siemens2_6b0_attempts_2           , mpf.cmrr2_6b0_attempts_2),
       mpf.siemens2_6b0_num_attempts_2        = IF(mpf.siemens2_6b0_num_attempts_2 = 0, mpf.cmrr2_6b0_num_attempts_2, mpf.siemens2_6b0_num_attempts_2),
       mpf.siemens2_6b0_2_facemask_2          = COALESCE(mpf.siemens2_6b0_2_facemask_2         , mpf.cmrr2_6b0_2_facemask_2),
       mpf.siemens2_dti2_shell_2              = COALESCE(mpf.siemens2_dti2_shell_2             , mpf.cmrr2_dti2_shell_2),
       mpf.siemens2_dti2_shell_attempts_2     = COALESCE(mpf.siemens2_dti2_shell_attempts_2    , mpf.cmrr2_dti2_shell_attempts_2),
       mpf.siemens2_dti2_shell_num_attempts_2 = IF(mpf.siemens2_dti2_shell_num_attempts_2 = 0, mpf.cmrr2_dti2_shell_num_attempts_2, mpf.siemens2_dti2_shell_num_attempts_2),
       mpf.siemens2_dti2_shell_2_facemask_2   = COALESCE(mpf.siemens2_dti2_shell_2_facemask_2  , mpf.cmrr2_dti2_shell_2_facemask_2),
       mpf.siemens2_6b02_2                    = COALESCE(mpf.siemens2_6b02_2                   , mpf.cmrr2_6b02_2),
       mpf.siemens2_6b02_attempts_2           = COALESCE(mpf.siemens2_6b02_attempts_2          , mpf.cmrr2_6b02_attempts_2),
       mpf.siemens2_6b02_num_attempts_2       = IF(mpf.siemens2_6b02_num_attempts_2 = 0, mpf.cmrr2_6b02_num_attempts_2, mpf.siemens2_6b02_num_attempts_2),
       mpf.siemens2_6b02_2_facemask_2         = COALESCE(mpf.siemens2_6b02_2_facemask_2        , mpf.cmrr2_6b02_2_facemask_2),
       mpf.siemens2_dti1_shell_2              = COALESCE(mpf.siemens2_dti1_shell_2             , mpf.cmrr2_dti1_shell_2),
       mpf.siemens2_dti1_shell_attempts_2     = COALESCE(mpf.siemens2_dti1_shell_attempts_2    , mpf.cmrr2_dti1_shell_attempts_2),
       mpf.siemens2_dti1_shell_num_attempts_2 = IF(mpf.siemens2_dti1_shell_num_attempts_2 = 0, mpf.cmrr2_dti1_shell_num_attempts_2, mpf.siemens2_dti1_shell_num_attempts_2),
       mpf.siemens2_dti1_shell_2_facemask_2   = COALESCE(mpf.siemens2_dti1_shell_2_facemask_2  , mpf.cmrr2_dti1_shell_2_facemask_2),
       mpf.siemens2_dti_comments_2            = COALESCE(mpf.siemens2_dti_comments_2           , mpf.cmrr2_dti_comments_2),

       mpf.siemens3_dti_sequences_acquired_3  = COALESCE(mpf.siemens3_dti_sequences_acquired_3 , mpf.cmrr3_dti_sequences_acquired_3),
       mpf.siemens3_dti3_shell_3              = COALESCE(mpf.siemens3_dti3_shell_3             , mpf.cmrr3_dti3_shell_3),
       mpf.siemens3_dti3_shell_attempts_3     = COALESCE(mpf.siemens3_dti3_shell_attempts_3    , mpf.cmrr3_dti3_shell_attempts_3),
       mpf.siemens3_dti3_shell_num_attempts_3 = IF(mpf.siemens3_dti3_shell_num_attempts_3 = 0, mpf.cmrr3_dti3_shell_num_attempts_3, mpf.siemens3_dti3_shell_num_attempts_3),
       mpf.siemens3_dti3_shell_3_facemask_3   = COALESCE(mpf.siemens3_dti3_shell_3_facemask_3  , mpf.cmrr3_dti3_shell_3_facemask_3),
       mpf.siemens3_6b0_3                     = COALESCE(mpf.siemens3_6b0_3                    , mpf.cmrr3_6b0_3),
       mpf.siemens3_6b0_attempts_3            = COALESCE(mpf.siemens3_6b0_attempts_3           , mpf.cmrr3_6b0_attempts_3),
       mpf.siemens3_6b0_num_attempts_3        = IF(mpf.siemens3_6b0_num_attempts_3 = 0, mpf.cmrr3_6b0_num_attempts_3, mpf.siemens3_6b0_num_attempts_3),
       mpf.siemens3_6b0_3_facemask_3          = COALESCE(mpf.siemens3_6b0_3_facemask_3         , mpf.cmrr3_6b0_3_facemask_3),
       mpf.siemens3_dti2_shell_3              = COALESCE(mpf.siemens3_dti2_shell_3             , mpf.cmrr3_dti2_shell_3),
       mpf.siemens3_dti2_shell_attempts_3     = COALESCE(mpf.siemens3_dti2_shell_attempts_3    , mpf.cmrr3_dti2_shell_attempts_3),
       mpf.siemens3_dti2_shell_num_attempts_3 = IF(mpf.siemens3_dti2_shell_num_attempts_3 = 0, mpf.cmrr3_dti2_shell_num_attempts_3, mpf.siemens3_dti2_shell_num_attempts_3),
       mpf.siemens3_dti2_shell_3_facemask_3   = COALESCE(mpf.siemens3_dti2_shell_3_facemask_3  , mpf.cmrr3_dti2_shell_3_facemask_3),
       mpf.siemens3_6b02_3                    = COALESCE(mpf.siemens3_6b02_3                   , mpf.cmrr3_6b02_3),
       mpf.siemens3_6b02_attempts_3           = COALESCE(mpf.siemens3_6b02_attempts_3          , mpf.cmrr3_6b02_attempts_3),
       mpf.siemens3_6b02_num_attempts_3       = IF(mpf.siemens3_6b02_num_attempts_3 = 0, mpf.cmrr3_6b02_num_attempts_3, mpf.siemens3_6b02_num_attempts_3),
       mpf.siemens3_6b02_3_facemask_3         = COALESCE(mpf.siemens3_6b02_3_facemask_3        , mpf.cmrr3_6b02_3_facemask_3),
       mpf.siemens3_dti1_shell_3              = COALESCE(mpf.siemens3_dti1_shell_3             , mpf.cmrr3_dti1_shell_3),
       mpf.siemens3_dti1_shell_attempts_3     = COALESCE(mpf.siemens3_dti1_shell_attempts_3    , mpf.cmrr3_dti1_shell_attempts_3),
       mpf.siemens3_dti1_shell_num_attempts_3 = IF(mpf.siemens3_dti1_shell_num_attempts_3 = 0, mpf.cmrr3_dti1_shell_num_attempts_3, mpf.siemens3_dti1_shell_num_attempts_3),
       mpf.siemens3_dti1_shell_3_facemask_3   = COALESCE(mpf.siemens3_dti1_shell_3_facemask_3  , mpf.cmrr3_dti1_shell_3_facemask_3),
       mpf.siemens3_dti_comments_3            = COALESCE(mpf.siemens3_dti_comments_3           , mpf.cmrr3_dti_comments_3),

       mpf.siemens4_dti_sequences_acquired_4  = COALESCE(mpf.siemens4_dti_sequences_acquired_4 , mpf.cmrr4_dti_sequences_acquired_4),
       mpf.siemens4_dti3_shell_4              = COALESCE(mpf.siemens4_dti3_shell_4             , mpf.cmrr4_dti3_shell_4),
       mpf.siemens4_dti3_shell_attempts_4     = COALESCE(mpf.siemens4_dti3_shell_attempts_4    , mpf.cmrr4_dti3_shell_attempts_4),
       mpf.siemens4_dti3_shell_num_attempts_4 = IF(mpf.siemens4_dti3_shell_num_attempts_4 = 0, mpf.cmrr4_dti3_shell_num_attempts_4, mpf.siemens4_dti3_shell_num_attempts_4),
       mpf.siemens4_dti3_shell_4_facemask_4   = COALESCE(mpf.siemens4_dti3_shell_4_facemask_4  , mpf.cmrr4_dti3_shell_4_facemask_4),
       mpf.siemens4_6b0_4                     = COALESCE(mpf.siemens4_6b0_4                    , mpf.cmrr4_6b0_4),
       mpf.siemens4_6b0_attempts_4            = COALESCE(mpf.siemens4_6b0_attempts_4           , mpf.cmrr4_6b0_attempts_4),
       mpf.siemens4_6b0_num_attempts_4        = IF(mpf.siemens4_6b0_num_attempts_4 = 0, mpf.cmrr4_6b0_num_attempts_4, mpf.siemens4_6b0_num_attempts_4),
       mpf.siemens4_6b0_4_facemask_4          = COALESCE(mpf.siemens4_6b0_4_facemask_4         , mpf.cmrr4_6b0_4_facemask_4),
       mpf.siemens4_dti2_shell_4              = COALESCE(mpf.siemens4_dti2_shell_4             , mpf.cmrr4_dti2_shell_4),
       mpf.siemens4_dti2_shell_attempts_4     = COALESCE(mpf.siemens4_dti2_shell_attempts_4    , mpf.cmrr4_dti2_shell_attempts_4),
       mpf.siemens4_dti2_shell_num_attempts_4 = IF(mpf.siemens4_dti2_shell_num_attempts_4 = 0, mpf.cmrr4_dti2_shell_num_attempts_4, mpf.siemens4_dti2_shell_num_attempts_4),
       mpf.siemens4_dti2_shell_4_facemask_4   = COALESCE(mpf.siemens4_dti2_shell_4_facemask_4  , mpf.cmrr4_dti2_shell_4_facemask_4),
       mpf.siemens4_6b02_4                    = COALESCE(mpf.siemens4_6b02_4                   , mpf.cmrr4_6b02_4),
       mpf.siemens4_6b02_attempts_4           = COALESCE(mpf.siemens4_6b02_attempts_4          , mpf.cmrr4_6b02_attempts_4),
       mpf.siemens4_6b02_num_attempts_4       = IF(mpf.siemens4_6b02_num_attempts_4 = 0, mpf.cmrr4_6b02_num_attempts_4, mpf.siemens4_6b02_num_attempts_4),
       mpf.siemens4_6b02_4_facemask_4         = COALESCE(mpf.siemens4_6b02_4_facemask_4        , mpf.cmrr4_6b02_4_facemask_4),
       mpf.siemens4_dti1_shell_4              = COALESCE(mpf.siemens4_dti1_shell_4             , mpf.cmrr4_dti1_shell_4),
       mpf.siemens4_dti1_shell_attempts_4     = COALESCE(mpf.siemens4_dti1_shell_attempts_4    , mpf.cmrr4_dti1_shell_attempts_4),
       mpf.siemens4_dti1_shell_num_attempts_4 = IF(mpf.siemens4_dti1_shell_num_attempts_4 = 0, mpf.cmrr4_dti1_shell_num_attempts_4, mpf.siemens4_dti1_shell_num_attempts_4),
       mpf.siemens4_dti1_shell_4_facemask_4   = COALESCE(mpf.siemens4_dti1_shell_4_facemask_4  , mpf.cmrr4_dti1_shell_4_facemask_4),
       mpf.siemens4_dti_comments_4            = COALESCE(mpf.siemens4_dti_comments_4           , mpf.cmrr4_dti_comments_4)

WHERE  NOT EXISTS(SELECT 1
                  FROM   files f
                         JOIN mri_scan_type mst
                           ON ( mst.id = f.acquisitionprotocolid )
                         JOIN parameter_file pf
                           ON ( pf.fileid = f.fileid )
                         JOIN parameter_type pt
                           ON( pt.parametertypeid = pf.parametertypeid )
                  WHERE  f.sessionid = s.id
                         AND pt.NAME = 'protocol_name'
                         AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                         AND pf.value LIKE 'DWIcmrr%')
       AND EXISTS(SELECT 1
                  FROM   files f
                         JOIN mri_scan_type mst
                           ON ( mst.id = f.acquisitionprotocolid )
                         JOIN parameter_file pf
                           ON ( pf.fileid = f.fileid )
                         JOIN parameter_type pt
                           ON( pt.parametertypeid = pf.parametertypeid )
                  WHERE  f.sessionid = s.id
                         AND pt.NAME = 'protocol_name'
                         AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                         AND pf.value NOT LIKE 'DWIcmrr%')
       AND s.visit_label IN ( 'VSA', 'VSA-CVD' )
       AND f.data_entry IS NOT NULL;


-- -----------------------------------------------------------------------------------------

UPDATE mri_parameter_form_sa mpf
       JOIN flag f
         ON ( f.commentid = mpf.commentid )
       JOIN session s
         ON ( s.id = f.sessionid )
SET    mpf.cmrr1_dti_sequences_acquired  = DEFAULT,
       mpf.cmrr1_dti3_shell              = DEFAULT,
       mpf.cmrr1_dti3_shell_attempts     = DEFAULT,
       mpf.cmrr1_dti3_shell_num_attempts = 0,
       mpf.cmrr1_dti3_shell_facemask     = DEFAULT,
       mpf.cmrr1_6b0                     = DEFAULT,
       mpf.cmrr1_6b0_attempts            = DEFAULT,
       mpf.cmrr1_6b0_num_attempts        = 0,
       mpf.cmrr1_6b0_facemask            = DEFAULT,
       mpf.cmrr1_dti2_shell              = DEFAULT,
       mpf.cmrr1_dti2_shell_attempts     = DEFAULT,
       mpf.cmrr1_dti2_shell_num_attempts = 0,
       mpf.cmrr1_dti2_shell_facemask     = DEFAULT,
       mpf.cmrr1_6b02                    = DEFAULT,
       mpf.cmrr1_6b02_attempts           = DEFAULT,
       mpf.cmrr1_6b02_num_attempts       = 0,
       mpf.cmrr1_6b02_facemask           = DEFAULT,
       mpf.cmrr1_dti1_shell              = DEFAULT,
       mpf.cmrr1_dti1_shell_attempts     = DEFAULT,
       mpf.cmrr1_dti1_shell_num_attempts = 0,
       mpf.cmrr1_dti1_shell_facemask     = DEFAULT,
       mpf.cmrr1_dti_comments            = DEFAULT,
       mpf.cmrr2_dti_sequences_acquired_2  = DEFAULT,
       mpf.cmrr2_dti3_shell_2              = DEFAULT,
       mpf.cmrr2_dti3_shell_attempts_2     = DEFAULT,
       mpf.cmrr2_dti3_shell_num_attempts_2 = 0,
       mpf.cmrr2_dti3_shell_2_facemask_2   = DEFAULT,
       mpf.cmrr2_6b0_2                     = DEFAULT,
       mpf.cmrr2_6b0_attempts_2            = DEFAULT,
       mpf.cmrr2_6b0_num_attempts_2        = 0,
       mpf.cmrr2_6b0_2_facemask_2          = DEFAULT,
       mpf.cmrr2_dti2_shell_2              = DEFAULT,
       mpf.cmrr2_dti2_shell_attempts_2     = DEFAULT,
       mpf.cmrr2_dti2_shell_num_attempts_2 = 0,
       mpf.cmrr2_dti2_shell_2_facemask_2   = DEFAULT,
       mpf.cmrr2_6b02_2                    = DEFAULT,
       mpf.cmrr2_6b02_attempts_2           = DEFAULT,
       mpf.cmrr2_6b02_num_attempts_2       = 0,
       mpf.cmrr2_6b02_2_facemask_2         = DEFAULT,
       mpf.cmrr2_dti1_shell_2              = DEFAULT,
       mpf.cmrr2_dti1_shell_attempts_2     = DEFAULT,
       mpf.cmrr2_dti1_shell_num_attempts_2 = 0,
       mpf.cmrr2_dti1_shell_2_facemask_2   = DEFAULT,
       mpf.cmrr2_dti_comments_2            = DEFAULT,
       mpf.cmrr3_dti_sequences_acquired_3  = DEFAULT,
       mpf.cmrr3_dti3_shell_3              = DEFAULT,
       mpf.cmrr3_dti3_shell_attempts_3     = DEFAULT,
       mpf.cmrr3_dti3_shell_num_attempts_3 = 0,
       mpf.cmrr3_dti3_shell_3_facemask_3   = DEFAULT,
       mpf.cmrr3_6b0_3                     = DEFAULT,
       mpf.cmrr3_6b0_attempts_3            = DEFAULT,
       mpf.cmrr3_6b0_num_attempts_3        = 0,
       mpf.cmrr3_6b0_3_facemask_3          = DEFAULT,
       mpf.cmrr3_dti2_shell_3              = DEFAULT,
       mpf.cmrr3_dti2_shell_attempts_3     = DEFAULT,
       mpf.cmrr3_dti2_shell_num_attempts_3 = 0,
       mpf.cmrr3_dti2_shell_3_facemask_3   = DEFAULT,
       mpf.cmrr3_6b02_3                    = DEFAULT,
       mpf.cmrr3_6b02_attempts_3           = DEFAULT,
       mpf.cmrr3_6b02_num_attempts_3       = 0,
       mpf.cmrr3_6b02_3_facemask_3         = DEFAULT,
       mpf.cmrr3_dti1_shell_3              = DEFAULT,
       mpf.cmrr3_dti1_shell_attempts_3     = DEFAULT,
       mpf.cmrr3_dti1_shell_num_attempts_3 = 0,
       mpf.cmrr3_dti1_shell_3_facemask_3   = DEFAULT,
       mpf.cmrr3_dti_comments_3            = DEFAULT,
       mpf.cmrr4_dti_sequences_acquired_4  = DEFAULT,
       mpf.cmrr4_dti3_shell_4              = DEFAULT,
       mpf.cmrr4_dti3_shell_attempts_4     = DEFAULT,
       mpf.cmrr4_dti3_shell_num_attempts_4 = 0,
       mpf.cmrr4_dti3_shell_4_facemask_4   = DEFAULT,
       mpf.cmrr4_6b0_4                     = DEFAULT,
       mpf.cmrr4_6b0_attempts_4            = DEFAULT,
       mpf.cmrr4_6b0_num_attempts_4        = 0,
       mpf.cmrr4_6b0_4_facemask_4          = DEFAULT,
       mpf.cmrr4_dti2_shell_4              = DEFAULT,
       mpf.cmrr4_dti2_shell_attempts_4     = DEFAULT,
       mpf.cmrr4_dti2_shell_num_attempts_4 = 0,
       mpf.cmrr4_dti2_shell_4_facemask_4   = DEFAULT,
       mpf.cmrr4_6b02_4                    = DEFAULT,
       mpf.cmrr4_6b02_attempts_4           = DEFAULT,
       mpf.cmrr4_6b02_num_attempts_4       = 0,
       mpf.cmrr4_6b02_4_facemask_4         = DEFAULT,
       mpf.cmrr4_dti1_shell_4              = DEFAULT,
       mpf.cmrr4_dti1_shell_attempts_4     = DEFAULT,
       mpf.cmrr4_dti1_shell_num_attempts_4 = 0,
       mpf.cmrr4_dti1_shell_4_facemask_4   = DEFAULT,
       mpf.cmrr4_dti_comments_4            = DEFAULT

WHERE  NOT EXISTS(SELECT 1
                  FROM   files f
                         JOIN mri_scan_type mst
                           ON ( mst.id = f.acquisitionprotocolid )
                         JOIN parameter_file pf
                           ON ( pf.fileid = f.fileid )
                         JOIN parameter_type pt
                           ON( pt.parametertypeid = pf.parametertypeid )
                  WHERE  f.sessionid = s.id
                         AND pt.NAME = 'protocol_name'
                         AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                         AND pf.value LIKE 'DWIcmrr%')
       AND EXISTS(SELECT 1
                  FROM   files f
                         JOIN mri_scan_type mst
                           ON ( mst.id = f.acquisitionprotocolid )
                         JOIN parameter_file pf
                           ON ( pf.fileid = f.fileid )
                         JOIN parameter_type pt
                           ON( pt.parametertypeid = pf.parametertypeid )
                  WHERE  f.sessionid = s.id
                         AND pt.NAME = 'protocol_name'
                         AND mst.scan_type IN ( 'DtiSA', 'DtiCmrrSA' )
                         AND pf.value NOT LIKE 'DWIcmrr%')
       AND s.visit_label IN ( 'VSA', 'VSA-CVD' )
       AND f.data_entry IS NOT NULL;

