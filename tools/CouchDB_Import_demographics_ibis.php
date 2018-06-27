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
        'Visit_label' => array(
            'Description' => 'Visit of Candidate',
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
        'Gender' => array(
            'Description' => 'Candidate\'s gender',
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
        'NDAR_consent' => array(
            'Description' => 'NDAR Consent',
            'Type' => "enum('yes','no','not_answered')",
        ),
        'NDAR_consent_date' => array(
            'Description' => 'NDAR Consent Date',
            'Type' => "varchar(255)",
        ),
        'NDAR_consent_withdrawal' => array(
            'Description' => 'NDAR Consent Withdrawal Date',
            'Type' => "varchar(255)",
        ),
        'Study_consent' => array(
            'Description' => 'Study Consent',
            'Type' => "enum('yes','no','not_answered')",
        ),
        'Study_consent_date' => array(
            'Description' => 'Study Consent Date',
            'Type' => "varchar(255)",
        ),
        'Study_consent_withdrawal' => array(
            'Description' => 'Study Consent Withdrawal Date',
            'Type' => "varchar(255)",
        ),
        'Air_pollution_consent' => array(
            'Description' => 'Air Pollution Consent',
            'Type' => "enum('yes','no','not_answered')",
        ),
        'Air_pollution_consent_date' => array(
            'Description' => 'Air Pollution Consent Date',
            'Type' => "varchar(255)",
        ),
        'Air_pollution_consent_withdrawal' => array(
            'Description' => 'Air Pollution Consent Withdrawal Date',
            'Type' => "varchar(255)",
        ),
        'Mail_tooth_kit_consent' => array(
            'Description' => 'Mail Tooth Kit Consent',
            'Type' => "enum('yes','no','not_answered')",
        ),
        'Mail_tooth_kit_consent_date' => array(
            'Description' => 'Mail Tooth Kit Consent Date',
            'Type' => "varchar(255)",
        ),
        'Mail_tooth_kit_consent_withdrawal' => array(
            'Description' => 'Mail Tooth Kit Consent Withdrawal Date',
            'Type' => "varchar(255)",
        ),
        'ASD_DX' => array(
            'Description' => 'Combines questions 4a(autistic disorder) and 4b(PDD) on the DSMIV_checklist',
            'Type' => 'varchar(255)'
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
                                 s.visit_label                                               AS Visit_label,
                                 s.subprojectid                                              AS SubprojectID,
                                 CASE 
                                   WHEN s.subprojectid = 1 THEN 'HR' 
                                   WHEN s.subprojectid = 2 THEN 'HR' 
                                   WHEN s.subprojectid = 3 THEN 'LR' 
                                   WHEN s.subprojectid = 9 THEN 'HR' 
                                   WHEN s.subprojectid = 10 THEN 'LR' 
                                 END                                                         AS Risk, 
                                 CASE 
                                   WHEN (dsm.q4_criteria_autistic_disorder = 'no' && q4_criteria_PDD ='no') THEN 'No' 
                                   WHEN (dsm.q4_criteria_autistic_disorder = 'yes' || q4_criteria_PDD ='yes') THEN 'Yes'  
                                 END                                                         AS ASD_DX, 
                                 p.alias                                                     AS Site, 
                                 c.Gender, 
                                 s.Current_stage, 
                                 CASE 
                                   WHEN s.visit = 'Failure' THEN 'Failure' 
                                   WHEN s.screening = 'Failure' THEN 'Failure' 
                                   WHEN s.visit = 'Withdrawal' THEN 'Withdrawal' 
                                   WHEN s.screening = 'Withdrawal' THEN 'Withdrawal' 
                                   ELSE 'Neither' 
                                 END                                                         AS Failure, 
                                 c.ProjectID, 
                                 c.flagged_caveatemptor                                      AS CEF, 
                                 c.flagged_caveatemptor                                      AS CEF, 
                                 c_o.description                                             AS CEF_reason, 
                                 c.flagged_other                                             AS CEF_comment, 
                                 c.flagged_date                                              AS CEF_date, 
                                 pc_comment.value                                            AS Comment, 
                                 COALESCE(pso.description, 'Active')                         AS Status, 
                                 ps.participant_suboptions                                   AS Status_reason, 
                                 ps.reason_specify                                           AS Status_comments, 
                                 ps.ndar_consent                                             AS NDAR_consent, 
                                 ps.ndar_consent_date                                        AS NDAR_consent_date,
                                 ps.ndar_consent_withdrawal                                  AS NDAR_consent_withdrawal, 
                                 ps.study_consent                                            AS Study_consent, 
                                 ps.study_consent_date                                       AS Study_consent_date,
                                 ps.study_consent_withdrawal                                 AS Study_consent_withdrawal, 
                                 ps.air_consent                                              AS Air_pollution_consent, 
                                 ps.air_consent_date                                         AS Air_pollution_consent_date,
                                 ps.air_consent_withdrawal                                   AS Air_pollution_consent_withdrawal, 
                                 ps.mail_toothkit_consent                                    AS Mail_tooth_kit_consent,
                                 ps.mail_toothkit_consent_date                               AS Mail_tooth_kit_consent_date,
                                 ps.mail_toothkit_consent_withdrawal                         AS Mail_tooth_kit_consent_withdrawal";
        $tablesToJoin = " FROM   session s 
                                 JOIN candidate c using (candid) 
                                 LEFT JOIN psc p 
                                        ON ( p.centerid = s.centerid ) 
                                 LEFT JOIN caveat_options c_o 
                                        ON ( c_o.id = c.flagged_reason ) 
                                 LEFT JOIN parameter_candidate AS pc_comment 
                                        ON ( pc_comment.candid = c.candid ) 
                                           AND pc_comment.parametertypeid = (SELECT parametertypeid 
                                                                             FROM   parameter_type 
                                                                             WHERE  NAME = 'candidate_comment') 
                                 LEFT JOIN participant_status ps 
                                        ON ( ps.candid = c.candid )
                                 LEFT JOIN flag f 
                                        ON ( f.SessionID = s.ID)
                                           AND f.Test_name ='DSMIV_checklist' AND f.CommentID  NOT LIKE 'DDE%'
                                 LEFT JOIN DSMIV_checklist dsm
                                       ON ( dsm.CommentID = f.CommentID )
                                 LEFT JOIN participant_status_options pso 
              ON ( pso.id = ps.participant_status )";

        // If proband fields are being used, add proband information into the query
        if ($config->getSetting("useProband") === "true") {
            $probandFields = ", c.ProbandGender as Gender_proband, ROUND(DATEDIFF(c.DoB, c.ProbandDoB) / (365/12)) AS Age_difference";
            $fieldsInQuery .= $probandFields;
        }
        // If expected date of confinement is being used, add EDC information into the query
        if ($config->getSetting("useEDC") === "true") {
            $EDCFields = ", c.EDC as EDC";
            $fieldsInQuery .= $EDCFields;
        }
        $concatQuery = $fieldsInQuery . $tablesToJoin . " WHERE s.Active='Y' AND c.Active='Y' AND c.Entity_type != 'Scanner'";
        return $concatQuery;
    }

    function _updateDataDict() {
        $config = \NDB_Config::singleton();
        // If proband fields are being used, update the data dictionary
        if ($config->getSetting("useProband") === "true") {
            $this->Dictionary["Gender_proband"] = array(
                'Description' => 'Proband\'s gender',
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
        if ($config->getSetting("useProjects") === "true") {
            $projects = \Utility::getProjectList();
            $projectsEnum = "enum('";
            $projectsEnum .= implode("', '", $projects);
            $projectsEnum .= "')";
            $this->Dictionary["Project"] = array(
                'Description' => 'Project for which the candidate belongs',
                'Type' => $projectsEnum
            );
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

    function run() {
        $config = $this->CouchDB->replaceDoc('Config:BaseConfig', $this->Config);
        print "Updating Config:BaseConfig: $config";

        // Run query
        $demographics = $this->SQLDB->pselect($this->_generateQuery(), array());

        $this->CouchDB->beginBulkTransaction();
        $config_setting = \NDB_Config::singleton();
        foreach($demographics as $demographics) {
            $id = 'Demographics_Session_' . $demographics['PSCID'] . '_' . $demographics['Visit_label'];
            $demographics['Cohort'] = $this->_getSubproject($demographics['SubprojectID']);
            unset($demographics['SubprojectID']);
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
