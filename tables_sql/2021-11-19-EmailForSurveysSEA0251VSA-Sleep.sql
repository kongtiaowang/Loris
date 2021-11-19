-- ----------------------------------------------------------------------------------
--
-- Changes the email address assigned to the following surveys:
--
-- Candidate: SEA0251
-- Visit: VSA-Sleep
-- New email address: tressaabe11@hotmail.com
-- 
-- BRQ (Bedtime Routine Questionnaire) - Survey
-- CBCL (Child Behavior Checklist) 6 to 18 years - Survey
-- CCTQ (Children's ChronoType Questionnaire) - Survey
-- CSHQ (Children's Sleep Habits Questionnaire) - Survey
-- MASC2 - Parent (Multidimensional Anxiety Scale for Children - Parent) - Survey
-- MEQC (Morningness Eveningness Questionnaire for Children) - Survey
-- TANNER Staging Questionnaire (Girls) - Survey
--
--
-- Fixes #2090
--
-- ----------------------------------------------------------------------------------


UPDATE
  participant_accounts pa
  JOIN session s ON (s.id = pa.sessionid)
  JOIN candidate c ON (c.candid = s.candid)
SET
  email = 'tressaabe11@hotmail.com'
WHERE
  c.pscid = 'SEA0251'
  AND s.visit_label = 'VSA-Sleep'
  AND pa.test_name IN (
    'BRQ_survey',
    'CBCL_6_To_18',
    'CCTQ_survey',
    'CSHQ',
    'MASC2_Parent',
    'MEQC_survey',
    'tanner_girls_survey'
  );

