<?php
require_once 'generic_includes.php';
require_once 'CouchDB.class.inc';
require_once 'Database.class.inc';
class CouchDBDemographicsImporter {
    var $SQLDB; // reference to the database handler, store here instead
                // of using Database::singleton in case it's a mock.
    var $CouchDB; // reference to the CouchDB database handler

    // this is just in an instance variable to make
    // the code a little more readable.
    var $Dictionary = array(
        'DoB' => array(
            'Description' => 'Date of Birth',
            'Type' => 'varchar(255)'
        ),
        'Proband_DoB' => array(
            'Description' => 'Proband Date of Birth',
            'Type' => 'varchar(255)'
        ),
        'CandID' => array(
            'Description' => 'DCC Candidate Identifier',
            'Type' => 'varchar(255)'
        ),
        'PSCID' => array(
            'Description' => 'Project Candidate Identifier',
            'Type' => 'varchar(255)'
        ),
        'NDAR_ID' => array(
            'Description' => 'NDAR Candidate Identifier',
            'Type' => 'varchar(255)'
        ),
        'age_today' => array(
            'Description' => 'Candidate age today',
            'Type' => 'varchar(255)'
        ),
        'candidate_ethnicity' => array(
            'Description' => 'Candidate Ethnicity',
            'Type' => 'varchar(255)'
        ),
        'candidate_race' => array(
            'Description' => 'Candidate Race',
            'Type' => 'varchar(255)'
        ),
        'Visit_label' => array(
            'Description' => 'Visit of Candidate',
            'Type' => 'varchar(255)'
        ),
        'Visit_date' => array(
            'Description' => 'Date of Stage',
            'Type' => 'varchar(255)'
        ),
        'Cohort' => array(
            'Description' => 'Cohort of this session',
            'Type' => 'varchar(255)'
        ),
        'Risk' => array(
            'Description' => 'Risk group of candidate',
            'Type' => 'varchar(255)'
        ),
        'Sex' => array(
            'Description' => 'Candidate\'s sex',
            'Type' => "enum('Male', 'Female')"
        ),
        'Site' => array(
            'Description' => 'Site that this visit took place at',
            'Type' => "varchar(3)",
        ),
        'Current_stage' => array(
            'Description' => 'Current stage of visit',
            'Type' => "enum('Not Started','Screening','Visit','Approval','Subject','Recycling Bin')"
        ),
        'Failure' =>  array(
            'Description' => 'Whether Recycling Bin Candidate was failure or withdrawal',
            'Type' => "enum('Failure','Withdrawal','Neither')",
        ),
        'CEF' => array(
            'Description' => 'Caveat Emptor flag',
            'Type' => "enum('true','false')",
        ),
        'CEF_reason' => array(
            'Description' => 'Reason for Caveat Emptor flag',
            'Type' => "varchar(255)",
        ),
        'CEF_comment' => array(
            'Description' => 'Comment on Caveat Emptor flag',
            'Type' => "varchar(255)",
        ),
        'CEF_date' => array(
            'Description' => 'Caveat Emptor flag set date',
            'Type' => "varchar(255)",
        ),
        'Comment' => array(
            'Description' => 'Candidate comment',
            'Type' => "varchar(255)",
        ),
        'Status' => array(
            'Description' => 'Participant status',
            'Type' => "varchar(255)",
        ),
        'Status_reason' => array(
            'Description' => 'Reason for status - only filled out if status is inactive or incomplete',
            'Type' => "int(10)",
        ),
        'Status_comments' => array(
            'Description' => 'Participant status comments',
            'Type' => "text",
        ),
        'ASD_Ever_DSMIV' => array(
            'Description' => 'This variable shows whether a candidate was ASD+ at any timepoint based on the DSMIV (YES on Q4A or Q4B)',
            'Type' => 'varchar(255)',
        ),
        'ASD_Latest_DSMIV' => array(
            'Description' => 'This variable shows whether the candidate was ASD+ or ASD- at their last visit the DSMIV was administered',
            'Type' => 'varchar(255)',
        ),
        'ASD_DX' => array(
            'Description' => 'YES ==> If 4a/4b on DSMIV_checklist(V24) is yes at V24.
                              NO ==>  If 4a/4b on DSMIV_checklist(V24) is no at V24.',
            'Type' => 'varchar(255)',
        ),
        'DX_Subgroups' => array(
            'Description' => 'YES ==> If 4a/4b on DSMIV_checklist(V24) is yes at V24.
                              NO ==> If 4a/4b on DSMIV_checklist(V24) is no and not atypical at V24.
                              ATYPICAL ==> If 2 or more major sub-scales less than 35 (t score) on Mullen(V24) OR
                              1 or more major sub-scale less than 30 (tscore) on Mullen(V24) OR Greater than or Equal to 3 CSS on ADOS(V24).',
            'Type' => 'varchar(255)',
        ),
        'Age_at_visit_start' => array(
            'Description' => 'Candidate age in months when visit started',
            'Type' => 'varchar(255)',
        ),
        'Scan_done' => array(
            'Description' => 'Scan done for the visit',
            'Type' => 'varchar(255)',
        ),
        'session_feedback' => array(
            'Description' => 'Behavioural feedback at the session level',
            'Type' => "varchar(255)",
        ),
        'vsa_priority_data_status' => array(
            'Description' => 'NOT IBIS 1 OR IBIS 2 ==> Not an IBIS 1 or an IBIS 2 candidate.
                              NOT A PRIORITY TO BRING BACK AT VSA ==> If participant status is Excluded, Ineligible, Refused, Not enrolled or study consent is NO
                                          OR none of the other conditions (below) are met.
                              SCAN AND DSMV DONE AT VSA ==> If a scan was done at VSA and there is also DSMV data.
                              SCAN DONE AT VSA ==> If a scan was done at VSA but there is no DSMV data.
                              DSMV DONE AT VSA ==> If there is DSMV data at VSA but no scan.
                              PRIORITY TO BRING BACK AT VSA ==> If candidate has an ASD+ diagnosis at V24
                                          OR 2 scans before VSA along with data for either the Mullen or DSMIV.
                              1+ MULLEN IN V3..V12; NO T1 QC Pass IN V3..V12 ==> If there is at least one completed Mullen
                                          instrument but no T1 that passed QC between visits V3 and V12.
                              1+ MULLEN IN V3..V12; 1+ T1 QC Pass IN V3..V12 ==> If there is at least one completed Mullen
                                          instrument AND at least a T1 that passed QC between visits V3 and V12.',
            'Type' => 'varchar(255)',
        ),
        'GWAS_saliva_samples_tracking' => array(
            'Description' => 'NOT IBIS 1 OR IBIS 2 ==> Not an IBIS 1 or an IBIS 2 candidate.
                              NOT A PRIORITY TO BRING BACK AT VSA ==> If participant status is Excluded, Ineligible, Refused, Not enrolled or study consent is NO
                              NOT A PRIORITY TO BRING BACK AT VSA => If no scan at VSA, no DSMV data, no ASD+ diagnosis at V24, less
                              than 2 scans before VSA and no data for both the Mullen or DSMIV.
                              Otherwise, the value will be a string telling who to collect saliva samples for at VSA
                              (e.g. "COLLECT SALIVA SAMPLES FOR MOTHER AND FATHER")',
            'Type' => 'varchar(255)',
        )

    );

    var $Config = array(
        'Meta' => array(
            'DocType' => 'ServerConfig'
        ),
        'Config' => array(
            'GroupString'  => 'How to arrange data: ',
            'GroupOptions' =>
                array('Cross-sectional', 'Longitudinal')
        )
    );

    function __construct() {
        $factory       = \NDB_Factory::singleton();
        $config        = \NDB_Config::singleton();
        $couchConfig   = $config->getSetting('CouchDB');
        $this->SQLDB   = $factory->Database();
        $this->CouchDB = $factory->couchDB(
            $couchConfig['dbName'],
            $couchConfig['hostname'],
            $couchConfig['port'],
            $couchConfig['admin'],
            $couchConfig['adminpass']
        );
    }

    function _getSubproject($id) {
        $config = \NDB_Config::singleton();
        $subprojs = $config->getSubprojectSettings($id);
        if($subprojs['id'] == $id) {
            return $subprojs['title'];
        }
    }

    function _getProject($id) {
        $config = \NDB_Config::singleton();
        $projs = $config->getProjectSettings($id);
        if($projs['id'] == $id) {
            return $projs['Name'];
        }
    }

    function _generateQuery() {
        $config = \NDB_Config::singleton();
        $fieldsInQuery = "SELECT c.DoB,
                                 c.ProbandDoB                                                AS Proband_DoB,
                                 c.candid                                                    AS CandID,
                                 c.pscid                                                     AS PSCID,
                                 pc_ndarid.Value                                             AS NDAR_ID,
                                 s.visit_label                                               AS Visit_label,
                                 s.Date_visit                                                AS Visit_date,
                                 s.subprojectid                                              AS SubprojectID,
                                 CASE
                                   WHEN s.subprojectid = 1 THEN 'HR'
                                   WHEN s.subprojectid = 2 THEN 'HR'
                                   WHEN s.subprojectid = 3 THEN 'LR'
                                   WHEN s.subprojectid = 9 THEN 'HR'
                                   WHEN s.subprojectid = 10 THEN 'LR'
                                 END                                                         AS Risk,
                                 CASE
                                   WHEN (dsm.q4_criteria_autistic_disorder = 'no' && dsm.q4_criteria_PDD ='no') THEN 'NO (DSM_IV questions 4a/4b is No at V24)'
                                   WHEN (dsm.q4_criteria_autistic_disorder = 'yes' || dsm.q4_criteria_PDD ='yes') THEN 'YES (DSM_IV questions 4a/4b is Yes)'
                                 END                                                         AS ASD_DX,
                                  CASE
                                   WHEN (dsm.q4_criteria_autistic_disorder = 'yes' || dsm.q4_criteria_PDD ='yes') THEN 'YES (DSM_IV questions 4a/4b is Yes)'
                                 END                                                         AS DX_Subgroups,
                                 p.alias                                                     AS Site,
                                 c.Sex,
                                 s.Current_stage,
                                 ROUND(DATEDIFF(s.Date_visit, c.DoB) / (365/12))             AS Age_at_visit_start,
                                 ROUND(DATEDIFF(NOW(), c.DoB) / (365/12))                    AS age_today,
                                 s.Scan_done                                                 AS Scan_done,
                                 CASE
                                   WHEN s.visit = 'Failure' THEN 'Failure'
                                   WHEN s.screening = 'Failure' THEN 'Failure'
                                   WHEN s.visit = 'Withdrawal' THEN 'Withdrawal'
                                   WHEN s.screening = 'Withdrawal' THEN 'Withdrawal'
                                   ELSE 'Neither'
                                 END                                                         AS Failure,
                                 c.RegistrationProjectID                                     AS ProjectID,
                                 c.flagged_caveatemptor                                      AS CEF,
                                 c.flagged_caveatemptor                                      AS CEF,
                                 c_o.description                                             AS CEF_reason,
                                 c.flagged_other                                             AS CEF_comment,
                                 c.flagged_date                                              AS CEF_date,
                                 pc_comment.value                                            AS Comment,
                                 COALESCE(pso.description, 'Active')                         AS Status,
                                 ps.participant_suboptions                                   AS Status_reason,
                                 ps.reason_specify                                           AS Status_comments,
                                 CASE
                                   WHEN c.RegistrationProjectID NOT IN (1,2) THEN 'NOT IBIS 1 OR IBIS 2'
                                   WHEN COALESCE(pso.description,'Active') NOT IN ('Active', 'Inactive', 'Active - Flagged', 'Complete') OR cc1.Status = 'no' THEN 'NOT A PRIORITY TO BRING BACK AT VSA'
                                   WHEN scanned_at_vsa.count >= 1 AND fvsadsm.commentid IS NOT NULL THEN 'SCAN AND DSMV DONE AT VSA'
                                   WHEN scanned_at_vsa.count >= 1 THEN 'SCAN DONE AT VSA'
                                   WHEN fvsadsm.commentid IS NOT NULL THEN 'DSMV DONE AT VSA'
                                   WHEN (dsm24.q4_criteria_autistic_disorder = 'yes' || dsm24.q4_criteria_PDD ='yes') THEN 'PRIORITY TO BRING BACK AT VSA'
                                   WHEN nb_scans_before_vsa.count >= 2 AND (f24dsm.commentid IS NOT NULL OR f24mullen.commentid IS NOT NULL) THEN 'PRIORITY TO BRING BACK AT VSA'
                                   WHEN nb_mullen_v3_v12.count >= 1 AND nb_t1_pass_v3_v12.count IS NULL THEN '1+ MULLEN IN V3..V12; NO T1 QC Pass IN V3..V12'
                                   WHEN nb_mullen_v3_v12.count >= 1 AND nb_t1_pass_v3_v12.count >= 1 THEN '1+ MULLEN IN V3..V12; 1+ T1 QC Pass IN V3..V12'
                                   ELSE 'NOT A PRIORITY TO BRING BACK AT VSA'
                                 END                                                         AS vsa_priority_data_status,
                                 CASE
                                   WHEN c.RegistrationProjectID NOT IN (1,2) THEN 'NOT IBIS 1 OR IBIS 2'
                                   WHEN COALESCE(pso.description,'Active') NOT IN ('Active', 'Inactive', 'Active - Flagged', 'Complete') OR cc1.Status = 'no' THEN 'NOT A PRIORITY TO BRING BACK AT VSA'
                                   WHEN COALESCE(scanned_at_vsa.count,0) < 1 AND fvsadsm.commentid IS NULL
                                        AND NOT(dsm24.q4_criteria_autistic_disorder <=> 'yes') AND NOT(dsm24.q4_criteria_PDD <=> 'yes')
                                        AND (COALESCE(nb_scans_before_vsa.count,0) < 2 OR (f24dsm.commentid IS NULL AND f24mullen.commentid IS NULL)) THEN 'NOT A PRIORITY TO BRING BACK AT VSA'
                                   WHEN gwas24.candid IS NULL THEN 'NOT A PRIORITY TO BRING BACK AT VSA'
                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.proband_qc = 'yes' AND gwas24.mother_qc = 'yes' AND gwas24.father_qc = 'yes' THEN 'ALL SALIVA FROM THIS FAMILY PASSED QC'

                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.proband_qc = 'yes' AND gwas24.mother_qc = 'yes' THEN 'COLLECT SALIVA FROM FATHER'
                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.proband_qc = 'yes' AND gwas24.father_qc = 'yes' THEN 'COLLECT SALIVA FROM MOTHER'
                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.mother_qc  = 'yes' AND gwas24.father_qc = 'yes' THEN 'COLLECT SALIVA FROM PROBAND'
                                   WHEN gwas24.proband_qc = 'yes' AND gwas24.mother_qc  = 'yes' AND gwas24.father_qc = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT'

                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.proband_qc = 'yes' THEN 'COLLECT SALIVA FROM MOTHER AND FATHER'
                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.mother_qc  = 'yes' THEN 'COLLECT SALIVA FROM PROBAND AND FATHER'
                                   WHEN gwas24.subject_qc = 'yes' AND gwas24.father_qc  = 'yes' THEN 'COLLECT SALIVA FROM PROBAND AND MOTHER'
                                   WHEN gwas24.proband_qc = 'yes' AND gwas24.mother_qc  = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT AND FATHER'
                                   WHEN gwas24.proband_qc = 'yes' AND gwas24.father_qc  = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT AND MOTHER'
                                   WHEN gwas24.mother_qc  = 'yes' AND gwas24.father_qc  = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT AND PROBAND'

                                   WHEN gwas24.subject_qc = 'yes' THEN 'COLLECT SALIVA FROM PROBAND, MOTHER AND FATHER'
                                   WHEN gwas24.proband_qc = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT, MOTHER AND FATHER'
                                   WHEN gwas24.mother_qc  = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT, PROBAND AND FATHER'
                                   WHEN gwas24.father_qc  = 'yes' THEN 'COLLECT SALIVA FROM SUBJECT, PROBAND AND MOTHER'

                                   ELSE 'COLLECT SALIVA FROM SUBJECT, PROBAND, MOTHER AND FATHER'
                                 END                                                         AS GWAS_saliva_samples_tracking
                          ";
        $tablesToJoin = " FROM   session s
                                 JOIN candidate c using (candid)
                                 LEFT JOIN (
                                     SELECT candid, COUNT(*) as count FROM session
                                     WHERE session.visit_label IN ('V3', 'V03', 'V06', 'V09', 'V12', 'V15', 'V18', 'V24', 'V36')
                                     AND EXISTS(
                                       SELECT 1
                                       FROM files
                                       WHERE files.filetype='mnc'
                                       AND files.sessionid=session.id
                                     )
                                     GROUP BY candid
                                 ) nb_scans_before_vsa ON (nb_scans_before_vsa.candid=c.candid)
                                 LEFT JOIN (
                                     SELECT candid, COUNT(*) as count FROM session
                                     WHERE session.visit_label IN ('VSA','VSA-CVD')
                                     AND EXISTS(
                                       SELECT 1
                                       FROM files
                                       WHERE files.filetype='mnc'
                                       AND files.sessionid=session.id
                                     )
                                     GROUP BY candid
                                 ) scanned_at_vsa ON (scanned_at_vsa.candid=c.candid)
                                 LEFT JOIN psc p
                                        ON ( p.centerid = s.centerid )
                                 LEFT JOIN caveat_options c_o
                                        ON ( c_o.id = c.flagged_reason )
                                 LEFT JOIN parameter_candidate AS pc_comment
                                        ON ( pc_comment.candid = c.candid )
                                           AND pc_comment.parametertypeid = (SELECT parametertypeid
                                                                             FROM   parameter_type
                                                                             WHERE  NAME = 'candidate_comment')
                                 LEFT JOIN parameter_candidate AS pc_ndarid
                                        ON ( pc_ndarid.candid = c.candid )
                                           AND pc_ndarid.parametertypeid = (SELECT parametertypeid
                                                                             FROM   parameter_type
                                                                             WHERE  NAME = 'CandidateGUID')
                                 LEFT JOIN participant_status ps
                                        ON ( ps.candid = c.candid )
                                 LEFT JOIN flag f
                                        ON ( f.SessionID = s.ID)
                                           AND f.Test_name ='DSMIV_checklist' AND f.CommentID  NOT LIKE 'DDE%'
                                 LEFT JOIN DSMIV_checklist dsm
                                       ON ( dsm.CommentID = f.CommentID )
                                 LEFT JOIN (
                                       SELECT candidate.candid as candid, flag.commentid as commentid
                                       FROM flag
                                       JOIN session   ON session.id       = flag.sessionid
                                       JOIN candidate ON candidate.candid = session.candid
                                       WHERE flag.test_name = 'DSMIV_checklist'
                                       AND flag.CommentID NOT LIKE 'DDE%'
                                       AND flag.data_entry = 'Complete'
                                       AND flag.administration = 'All'
                                       AND session.visit_label='V24'
                                 ) f24dsm ON (f24dsm.candid=c.candid)
                                 LEFT JOIN (
                                      SELECT CommentID, q4_criteria_autistic_disorder, q4_criteria_PDD
                                      FROM DSMIV_checklist
                                 ) dsm24 ON (dsm24.commentid=f24dsm.commentid)
                                 LEFT JOIN (
                                       SELECT candidate.candid as candid, flag.commentid as commentid
                                       FROM flag
                                       JOIN session   ON session.id      = flag.sessionid
                                       JOIN candidate ON candidate.candid = session.candid
                                       WHERE flag.test_name = 'mullen'
                                       AND flag.CommentID NOT LIKE 'DDE%'
                                       AND flag.data_entry = 'Complete'
                                       AND flag.administration = 'All'
                                       AND session.visit_label='V24'
                                 ) f24mullen ON (f24mullen.candid = c.candid)
                                 LEFT JOIN (
                                       SELECT candidate.candid as candid, flag.commentid as commentid
                                       FROM flag
                                       JOIN session   ON session.id       = flag.sessionid
                                       JOIN candidate ON candidate.candid = session.candid
                                       WHERE flag.test_name = 'DSMV_checklist'
                                       AND flag.CommentID NOT LIKE 'DDE%'
                                       AND flag.data_entry = 'Complete'
                                       AND flag.administration = 'All'
                                       AND session.visit_label IN ('VSA', 'VSA-CVD')
                                 ) fvsadsm ON (fvsadsm.candid=c.candid)
                                 LEFT JOIN (
                                      SELECT candidate.candid, COUNT(*) AS count
                                      FROM flag
                                      JOIN session   ON session.ID        = flag.sessionID
                                      JOIN candidate ON candidate.CandID = session.CandID
                                      WHERE flag.test_name = 'mullen'
                                      AND flag.Data_entry = 'Complete'
                                      AND flag.Administration = 'All'
                                      AND session.visit_label IN ('V3', 'V03', 'V06', 'V09', 'V09JA', 'V09LENA', 'V12')
                                      AND session.active = 'Y'
                                      GROUP BY candidate.candid
                                 ) nb_mullen_v3_v12 ON (nb_mullen_v3_v12.candid=c.candid)
                                 LEFT JOIN (
                                      SELECT candidate.candid, COUNT(*) as count
                                      FROM files
                                      JOIN mri_scan_type  ON files.AcquisitionProtocolID = mri_scan_type.ID
                                      JOIN files_qcstatus ON files_qcstatus.FileID       = files.FileID
                                      JOIN session        ON files.sessionid             = session.id
                                      JOIN candidate      ON candidate.CandID            = session.CandID
                                      WHERE session.visit_label IN ('V3', 'V03', 'V06', 'V09', 'V09JA', 'V09LENA', 'V12')
                                      AND session.active = 'Y'
                                      AND mri_scan_type.Scan_type = 't1w'
                                      AND files_qcstatus.QCStatus = 'Pass'
                                      GROUP BY candidate.candid
                                 ) nb_t1_pass_v3_v12 ON (nb_t1_pass_v3_v12.candid=c.candid)
                                 LEFT JOIN participant_status_options pso
                                       ON ( pso.id = ps.participant_status )
                                 LEFT JOIN (
                                      SELECT session.candid as candid, gwas.subject_qc, gwas.proband_qc, gwas.mother_qc, gwas.father_qc
                                      FROM gwas
                                      JOIN flag ON(flag.commentid=gwas.commentid AND flag.commentid NOT LIKE 'DDE%')
                                      JOIN session ON(session.id=flag.sessionid AND session.visit_label='V24')
                                 ) gwas24 ON(gwas24.candid=s.candid) ";

        // If proband fields are being used, add proband information into the query
        if ($config->getSetting("useProband") === "true") {
            $probandFields = ", c.ProbandSex as Sex_proband, ROUND(DATEDIFF(c.DoB, c.ProbandDoB) / (365/12)) AS Age_difference";
            $fieldsInQuery .= $probandFields;
        }
        // If expected date of confinement is being used, add EDC information into the query
        if ($config->getSetting("useEDC") === "true") {
            $EDCFields = ", c.EDC as EDC";
            $fieldsInQuery .= $EDCFields;
        }
        $projects = \Utility::getProjectList();
        $projectsEnum = "enum('";
        $projectsEnum .= implode("', '", $projects);
        $projectsEnum .= "')";
        $this->Dictionary["Project"] = array(
            'Description' => 'Project for which the candidate belongs',
            'Type' => $projectsEnum
        );
        // If consent is being used, add consent information into query
        if ($config->getSetting("useConsent") === "true") {
            $consents = \Utility::getConsentList();
            foreach ($consents as $consentID => $consent) {
                $consentName = $consent['Name'];
                $cField = $this->SQLDB->escape("cc$consentID");
                $consentFields = ",
                               $cField.Status AS " . $consentName . ",
                               $cField.DateGiven AS " . $consentName . "_date,
                               $cField.DateWithdrawn AS " . $consentName . "_withdrawal";
                $fieldsInQuery .= $consentFields;
                $tablesToJoin  .= "
                                LEFT JOIN candidate_consent_rel $cField ON ($cField.CandidateID=c.CandID)
                                AND $cField.ConsentID=(SELECT ConsentID FROM consent WHERE Name='" . $consentName . "') ";
            }
        }

        $concatQuery = $fieldsInQuery . $tablesToJoin . " WHERE s.Active='Y' AND c.Active='Y'
        AND c.Entity_type != 'Scanner'
        AND s.Current_stage NOT IN ('Recycling Bin', 'Not Started')
        AND c.RegistrationCenterID NOT IN (1,8,9,10)
        AND (ps.participant_status NOT IN (2,3,4,15) OR ps.participant_status IS NULL)
        AND c.RegistrationProjectID NOT IN (5,6)";

        return $concatQuery;
    }

    function _updateDataDict() {
        $config = \NDB_Config::singleton();
        // If proband fields are being used, update the data dictionary
        if ($config->getSetting("useProband") === "true") {
            $this->Dictionary["Sex_proband"] = array(
                'Description' => 'Proband\'s sex',
                'Type' => "enum('Male','Female')"
            );
            $this->Dictionary["Age_difference"] = array(
                'Description' => 'Age difference between the candidate and the proband',
                'Type' => "int"
            );
        }
        // If expected date of confinement is being used, update the data dictionary
        if ($config->getSetting("useEDC") === "true") {
            $this->Dictionary["EDC"] = array(
                'Description' => 'Expected Date of Confinement (Due Date)',
                'Type' => "varchar(255)"
            );
        }
        // If consent is being used, update the data dictionary
        if ($config->getSetting("useConsent") === "true") {
            $consents = \Utility::getConsentList();
            foreach($consents as $consent) {
                $consentName  = $consent['Name'];
                $consentLabel = $consent['Label'];
                $this->Dictionary[$consentName] = array(
                    'Description' => $consentLabel,
                    'Type' => "enum('yes','no')"
                );
                $this->Dictionary[$consentName . "_date"] = array(
                    'Description' => $consentLabel . ' Date',
                    'Type' => "date"
                );
                $this->Dictionary[$consentName . "_withdrawal"] = array(
                    'Description' => $consentLabel . ' Withdrawal Date',
                    'Type' => "date"
                );
            }
        }
        /*
        // Add any candidate parameter fields to the data dictionary
        $parameterCandidateFields = $this->SQLDB->pselect("SELECT * from parameter_type WHERE SourceFrom='parameter_candidate' AND Queryable=1",
            array());
        foreach($parameterCandidateFields as $field) {
            if(isset($field['Name'])) {
                $fname = $field['Name'];
                $Dict[$fname] = array();
                $Dict[$fname]['Description'] = $field['Description'];
                $Dict[$fname]['Type'] = $field['Type'];
            }
        }
        */
    }
    /**
     * Gets the ADOS module that was Administered at a particular
     * SessionID
     *
     * @param int $SessionID The Session
     *
     * @return string Test_name of ADOS module. null if not found
     */
    function getADOSModule($SessionID)
    {
        $rows = $this->SQLDB->pselect(
            "SELECT Test_name, Administration FROM flag " .
            "WHERE SessionID=:SID AND Test_name LIKE 'ados%'" .
            " AND CommentID NOT LIKE 'DDE%'",
            array('SID' => $SessionID)
        );
        foreach ($rows as $row) {
            if ($row['Administration'] === 'All') {
                return $row['Test_name'];
            }
        }

        return null;
    }

    function getSessionID($candID,$visit)
    {
        $row = $this->SQLDB->pselectRow(
            "SELECT s.ID FROM session s
             join candidate c on (c.CandID=s.CandID)
            WHERE s.Visit_label=:vl AND c.CandID=:cid
            and s.Active='Y'",
            array('cid' => $candID, 'vl' =>$visit)
        );

        return $row['ID'];
    }

    function getSessionFeedback($SessionID)
    {
        $row = $this->SQLDB->pselectRow(
            "select s.candID,s.Visit_label, GROUP_CONCAT(fbe.Comment SEPARATOR '---->') as session_feedback_comments
from session s
LEFT JOIN feedback_bvl_thread fbt ON (fbt.SessionID=s.ID)
LEFT JOIN feedback_bvl_entry fbe ON (fbe.FeedbackID=fbt.FeedbackID)
WHERE s.ID=:SID
group by s.CandID,s.Visit_label",
            array('SID' => $SessionID)
        );
         return $row['session_feedback_comments'];

    }

    /**
     * Get the Candidate Race and Ethnicity from the Telephone Screening Interview administered at
     * the first candidate visit.
     *
     * @param $candid
     * @return array
     */
    function getTSIInfo($candid) {

        // Get the TSI version administered at the first visit.
        $first_visit = $this->SQLDB->pselect("
                SELECT f.Test_name, f.CommentID
                    FROM session s
                    JOIN flag f on (s.ID=f.SessionID)
                    WHERE f.Administration IN ('Partial','All')
		                AND f.Test_name IN ('tsi', 'tsi_ds', 'TSI_DS_Infant', 'TSI_EP')
		                AND f.CommentID NOT LIKE 'DDE_%'
                        AND s.CandID=:candID
            ", array('candID' => $candid));

        $candidate_ethnicity = null;
        $candidate_race = null;

        // Since there can be multiple versions of the TSI instrument at a visit, iterate through
        // the ones present to determine which one was administered.
        foreach ($first_visit as $tsi) {
            $result = array();
            switch ($tsi['Test_name']) {
                case "tsi":
                    $result = $this->SQLDB->pselectRow("
                            SELECT child_ethnicity AS candidate_ethnicity,
                                   candidate_race
                                FROM tsi
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
                case "tsi_ds":
                    $result = $this->SQLDB->pselectRow("
                            SELECT child_ethnicity AS candidate_ethnicity,
                                   candidate_race
                                FROM tsi_ds
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
                case "TSI_DS_Infant":
                    $result = $this->SQLDB->pselectRow("
                            SELECT candidate_ethnicity,
                                   candidate_race
                                FROM TSI_DS_Infant
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
                case "TSI_EP":
                    $result = $this->SQLDB->pselectRow("
                            SELECT candidate_ethnicity,
                                   candidate_race
                                FROM TSI_EP
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
            }

            // Check if some results were found, if so stop looping through versions.
            if (!empty($result) && (!is_null($result['candidate_ethnicity']) || !is_null($result['candidate_race']))) {
                $candidate_ethnicity = $result['candidate_ethnicity'];
                $candidate_race = $result['candidate_race'];
                break;
            }
        }

        return array(
            'candidate_ethnicity' => $candidate_ethnicity,
            'candidate_race' => $candidate_race
        );
    }

    /**
     * Get the all visits where the candidate was identified as ASD+ as well as what their latest
     * visit's diagnosis was.
     *
     * @param $candid
     * @return array
     */
    function getASDInfo($candID)
    {
        $dsmiv = $this->SQLDB->pselect("
            SELECT
                s.Visit_label,
                f.Test_name,
                dc.q4_criteria_autistic_disorder AS DSMIV_checklist_q4a,
                dc.q4_criteria_PDD AS DSMIV_checklist_q4b,
                dc.Date_taken AS DSMIV_checklist_Date_taken,
                ds.meets_dsmiv_criteria_autistic_disorder AS DSMIV_SA_q4a,
                ds.meets_dsmiv_criteria_pervasive_developmental_disorder AS DSMIV_SA_q4b,
                ds.Date_taken AS DSMIV_SA_Date_taken
            FROM session s
                JOIN flag f ON (f.SessionID=s.ID)
                LEFT JOIN DSMIV_checklist dc ON (f.CommentID=dc.CommentID)
                LEFT JOIN DSMIV_SA ds ON (f.CommentID=ds.CommentID)
            WHERE s.CandID=:candID
                AND f.Test_name IN ('DSMIV_checklist', 'DSMIV_SA')
                AND f.CommentID NOT LIKE 'DDE_%'
                AND f.Administration = 'All'
        ", array('candID' => $candID));

        $asd_plus     = array();
        $found_values = false;
        $most_recent  = array(
            'date'  => "1970-01-01",
            'value' => "",
        );
        foreach ($dsmiv as $visit) {
            $q4a  = $visit['Test_name'] . '_q4a';
            $q4b  = $visit['Test_name'] . '_q4b';
            $date = $visit['Test_name'] . '_Date_taken';
            if ($visit[$q4a] === 'yes' || $visit[$q4b] === 'yes') {
                array_push($asd_plus, $visit['Visit_label']);
                if ($visit[$date] > $most_recent['date']) {
                    $most_recent['date']  = $visit[$date];
                    $most_recent['value'] = "ASD+ (" . $visit['Visit_label'] . ")";
                }
            } elseif ($visit[$q4a] === 'no' || $visit[$q4b] === 'no' || $visit[$q4b] === 'no_na') {
                $found_values = true;
                if ($visit[$date] > $most_recent['date']) {
                    $most_recent['date']  = $visit[$date];
                    $most_recent['value'] = "ASD- (" . $visit['Visit_label'] . ")";
                }
            }
        }

        if (count($asd_plus) > 0) {
            return array(
                'all'    => "ASD+ (" . implode(", ", $asd_plus) . ")",
                'latest' => $most_recent['value']
            );
        }

        if ($found_values) {
            return array(
                'all'    => "ASD-",
                'latest' => $most_recent['value']
            );
        }

        return array(
            'all'    => "No DSMIV ever administered",
            'latest' => "No DSMIV ever administered"
        );
    }

    function run() {
        $config = $this->CouchDB->replaceDoc('Config:BaseConfig', $this->Config);
        print "Updating Config:BaseConfig: $config";
        // Run query
        $max_len = $this->SQLDB->run("SET SESSION group_concat_max_len = 100000;", array());

        // Run query
        $demographics = $this->SQLDB->pselect($this->_generateQuery(), array());

//        $this->CouchDB->beginBulkTransaction();
        $config_setting = \NDB_Config::singleton();
        foreach($demographics as $demographics) {
            $id = 'Demographics_Session_' . $demographics['PSCID'] . '_' . $demographics['Visit_label'];
            $demographics['Cohort'] = $this->_getSubproject($demographics['SubprojectID']);
            unset($demographics['SubprojectID']);
            $candid=$demographics['CandID'];
            $visit=$demographics['Visit_label'];
            $sid=$this->getSessionID($candid,$visit);
            $demographics['session_feedback'] = $this->getSessionFeedback($sid);
            if(isset($demographics['ProjectID'])) {
                $demographics['Project'] = $this->_getProject($demographics['ProjectID']);
                unset($demographics['ProjectID']);
            }
            if ($config_setting->getSetting("useFamilyID") === "true") {
                $familyID     = $this->SQLDB->pselectOne("SELECT FamilyID FROM family
                                                          WHERE CandID=:cid",
                                                          array('cid'=>$demographics['CandID']));
                if (!empty($familyID)) {
                   $this->Dictionary["FamilyID"] = array(
                                    'Description' => 'FamilyID of Candidate',
                                    'Type'        => "int(6)",
                                    );
                    $demographics['FamilyID'] = $familyID;
                    $familyFields = $this->SQLDB->pselect("SELECT candID as Family_ID,
                                    Relationship_type as Relationship_to_candidate
                                    FROM family
                                    WHERE FamilyID=:fid AND CandID<>:cid",
                                    array('fid'=>$familyID, 'cid'=>$demographics['CandID']));
                    $num_family = 1;
                    if (!empty($familyFields)) {
                        foreach($familyFields as $row) {
                            //adding each sibling id and relationship to the file
                            $this->Dictionary["Family_CandID".$num_family] = array(
                                    'Description' => 'CandID of Family Member '.$num_family,
                                    'Type'        => "varchar(255)",
                                    );
                            $this->Dictionary["Relationship_type_Family".$num_family] = array(
                                    'Description' => 'Relationship of candidate to Family Member '.$num_family,
                                    'Type'        => "enum('half_sibling','full_sibling','1st_cousin')",
                                    );
                            $demographics['Family_CandID'.$num_family]                      = $row['Family_ID'];
                            $demographics['Relationship_type_Family'.$num_family] = $row['Relationship_to_candidate'];
                            $num_family                                                += 1;
                        }
                    }
                }
            }

            //Finding Atypical value
            $candid=$demographics['CandID'];
            $mullen_complex= "WHEN (mullen.visual_reception_t < 35 && (
            mullen.fine_motor_t < 35 || mullen.receptive_language_t <35 ||
            mullen.expressive_language_t <35)) THEN 'Yes_2'

            WHEN (mullen.fine_motor_t < 35 && (mullen.visual_reception_t < 35 ||
            mullen.receptive_language_t <35 ||
            mullen.expressive_language_t <35)) THEN 'Yes_2'

            WHEN (mullen.receptive_language_t < 35 && (mullen.visual_reception_t < 35 ||
            mullen.fine_motor_t <35 ||
            mullen.expressive_language_t <35)) THEN 'Yes_2'

            WHEN (mullen.expressive_language_t< 35 && (mullen.visual_reception_t < 35 ||
            mullen.fine_motor_t <35 ||
            mullen.receptive_language_t <35)) THEN 'Yes_2'";
            if($demographics['Visit_label']=='V24' && $demographics['DX_Subgroups']!='YES (DSM_IV questions 4a/4b is Yes)')
            {
            $find_atypical = $this->SQLDB->pselect("SELECT CASE
                                                         WHEN (mullen.visual_reception_t < 30 ||
                                                         mullen.fine_motor_t < 30 || mullen.receptive_language_t <30 ||
                                                         mullen.expressive_language_t <30) THEN 'Yes'"
                                                         .$mullen_complex."
                                                         ELSE 'No' END AS mullen_criteria, s.ID,s.Visit_label FROM  session s
                                                         JOIN candidate c using (candid)
                                                         LEFT JOIN flag f  ON ( f.SessionID = s.ID)
                                                         LEFT JOIN mullen mullen ON ( mullen.CommentID = f.CommentID )
                                                         where c.Candid=$candid and f.Test_name IN('mullen') and s.Visit_label IN('V24')
                                                         AND f.CommentID NOT LIKE 'DDE%'", array());

            foreach($find_atypical as $find_atypical_row) {
                $sessionID = $find_atypical_row['ID'];
                $ADOSModule = $this->getADOSModule($sessionID);
                $Fields = array(
                    'c.PSCID',
                    's.Visit_label',
                    'i.Candidate_Age',
                    'i.social_affect_total',
                    'i.severity_score_lookup',
                    'i.a1'
                );
                if ($ADOSModule != NULL) {

                    $selectq = "SELECT " . join(",", $Fields) .
                        " FROM flag f LEFT JOIN " . $ADOSModule . " i USING (CommentID)" .
                        " LEFT JOIN session s ON (s.ID=f.SessionID)" .
                        " LEFT JOIN candidate c USING (CandID) " .
                        "WHERE f.Test_name='$ADOSModule' AND f.SessionID=:SID AND s.Active='Y'" .
                        " AND c.Active='Y' AND f.CommentID NOT LIKE 'DDE%'";
                    $row = $this->SQLDB->pselectRow($selectq,
                        array(
                            'SID' => $sessionID,
                        )
                    );
                    if ($row === array()) {
                       return;
                    }
                    $PSCID = $row['PSCID'];
                    $Visit_label = $row['Visit_label'];
                    $age_months = $row['Candidate_Age'];
                    for ($i = 2; $i <= 14; $i++) {
                        $low = $i * 12;
                        $high = ($i + 1) * 12;
                        if ($age_months >= $low && $age_months < $high) {
                            $ados_age = $i;
                        }
                    }

                    //Leigh says this is SA version; at V24 css is severity score lookup
                    //$ADOS_SA_CSS = NDB_BVL_Instrument_IBIS::ADOS_SA_CSS($ADOSModule, $row['a1'], $row['social_affect_total'], $ados_age);
                    $ADOS_CSS = $row['severity_score_lookup'];
                }

                if ($demographics['ASD_DX'] != NULL) {

                    if ($ADOS_CSS >= 3 && $find_atypical_row['Visit_label'] == 'V24' && $ADOSModule!=NULL) {
                        $atypical = "ATYPICAL (ADOS severity score greater than or equal to 3 at V24) ";
                    } else if ($find_atypical_row['mullen_criteria'] == 'Yes' && $find_atypical_row['Visit_label'] == 'V24') {
                        $atypical = "ATYPICAL (Mullen: 1 or more sub-scale Tscore less than 30 at V24)";
                    } else if ($find_atypical_row['mullen_criteria'] == 'Yes_2' && $find_atypical_row['Visit_label'] == 'V24') {
                        $atypical = "ATYPICAL (Mullen: 2 or more sub-scale Tscore less than 35 at V24)";
                    } else if ($demographics['ASD_DX']=='NO (DSM_IV questions 4a/4b is No at V24)'
                        && $find_atypical_row['Visit_label'] == 'V24') {
                        $atypical = 'NO (DSM_IV questions 4a/4b is no and not atypical) ';
                    } else {
                        $atypical = $demographics['ASD_DX'];
                    }

                    $demographics['DX_Subgroups'] = $atypical;
                }
                else{
                    $demographics['DX_Subgroups'] = $demographics['ASD_DX'];
                }
            }
            }

            //atypical code finished

            // Get the candidate race and ethnicity from the tsi instrument.
            $tsi_info = $this->getTSIInfo($candid);
            $demographics['candidate_ethnicity'] = $tsi_info['candidate_ethnicity'];
            $demographics['candidate_race'] = $tsi_info['candidate_race'];

            // Get ASD info for all visit the candidate was administered a DSMIV,
            // along with most recent visit's value.
            $asd_info = $this->getASDInfo($candid);
            $demographics['ASD_Ever_DSMIV']   = $asd_info['all'];
            $demographics['ASD_Latest_DSMIV'] = $asd_info['latest'];

            $success = $this->CouchDB->replaceDoc($id, array('Meta' => array(
                'DocType' => 'demographics',
                'identifier' => array($demographics['PSCID'], $demographics['Visit_label'])
            ),
                'data' => $demographics
            ));
            print "$id: $success\n";
        }
        $this->_updateDataDict();
        $this->CouchDB->replaceDoc('DataDictionary:Demographics',
                array('Meta' => array('DataDict' => true),
                    'DataDictionary' => array('demographics' => $this->Dictionary)
                    )
                );

        print $this->CouchDB->commitBulkTransaction();

    }
}

// Don't run if we're doing the unit tests; the unit test will call run.
if(!class_exists('UnitTestCase')) {
    $Runner = new CouchDBDemographicsImporter();
    $Runner->run();
}
?>
