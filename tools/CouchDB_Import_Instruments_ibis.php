<?php
require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'generic_includes.php';
require_once 'CouchDB.class.inc';
require_once 'Database.class.inc';
require_once 'Utility.class.inc';
class CouchDBInstrumentImporter
{
    var $SQLDB; // reference to the database handler, store here instead
                // of using Database::singleton in case it's a mock.
    var $CouchDB; // reference to the CouchDB database handler

    function __construct()
    {
        $factory       = \NDB_Factory::singleton();
        $config        = \NDB_Config::singleton();
        $couchConfig   = $config->getSetting('CouchDB');
        $this->SQLDB   = $factory->Database();
        $this->CouchDB = $factory->couchDB(
            $couchConfig['dbName'],
            $couchConfig['hostname'],
            intval($couchConfig['port']),
            $couchConfig['admin'],
            $couchConfig['adminpass']
        );
    }

    function UpdateDataDicts($Instruments)
    {
        foreach ($Instruments as $instrument => $name) {
            $Dict   = array(
                       'Administration'  => array(
                                             'Type'        => "enum('None'," .
                                               " 'Partial', 'All')",
                                             'Description' => "Administration " .
                                               "for $name",
                                            ),
                       'Data_entry'      => array(
                                             'Type'        => "enum('In Progress'," .
                                               " 'Complete')",
                                             'Description' => "Data entry status " .
                                               "for $name",
                                            ),
                       'Validity'        => array(
                                             'Type'        => "enum('Questionable'" .
                                               ", 'Invalid', 'Valid')",
                                             'Description' => "Validity of data " .
                                               "for $name",
                                            ),
                       'Conflicts_Exist' => array(
                                             'Type'        => "enum('Yes', 'No')",
                                             'Description' => 'Conflicts exist for' .
                                               ' instrument data entry',
                                            ),
                       'DDE_Complete'    => array(
                                             'Type'        => "enum('Yes', 'No')",
                                             'Description' => 'Double Data Entry ' .
                                               'was completed for instrument',
                                            ),
                      );
            $Fields = $this->SQLDB->pselect(
                "SELECT * from parameter_type WHERE SourceFrom=:inst " .
                  "AND Queryable=1",
                array('inst' => $instrument)
            );
            foreach ($Fields as $field) {
                if (isset($field['SourceField'])) {
                    $fname        = $field['SourceField'];
                    $Dict[$fname] = array();
                    $Dict[$fname]['Type']        = $field['Type'];
                    $Dict[$fname]['Description'] = $field['Description'];
                }
            }

            unset($Dict['city_of_birth']);
            unset($Dict['city_of_birth_status']);

            $Dict['mother_age_at_administration'] = array(
                'Type' => "varchar(255)",
                'Description' => "Mother's age at administration"
            );
            $Dict['father_age_at_administration'] = array(
                'Type' => "varchar(255)",
                'Description' => "Father's age at administration"
            );

            // Determine if any survey's have been created for the instrument via the survey accounts module.
            $survey_count = $this->SQLDB->pselectOne("
                SELECT count(*) FROM participant_accounts WHERE Test_name=:test_name
            ", array("test_name" => $instrument));

            if ($survey_count > 0) {
                // Surveys, exist add new variable to specify whether the instrument was submitted,
                // via the survey module or direct entry.
                $Dict['Data_Entry_Type'] = array(
                    'Type' => "enum('Submitted', 'Direct Data Entered', 'In Progress')",
                    'Description' => "whether the survey was submitted online (via the Parent Portal or using direct url) vs Direct Data Entered"
                );
                $Dict['emailed'] = array(
                    'Type' => "enum('Created - Not emailed via LORIS', 'Sent - emailed via LORIS', 'Survey not Created')",
                    'Description' => "whether the survey was emailed or not"
                );
            }

            $this->CouchDB->replaceDoc(
                "DataDictionary:$instrument",
                array(
                 'Meta'           => array('DataDict' => true),
                 'DataDictionary' => array($instrument => $Dict),
                )
            );
        }
    }

    function generateDocumentSQL(string $tablename) : string
    {
        //Script Overriden as per Redmine 18848
        // Query Adjusted to exclude some data from DQT
        $select = "SELECT
                        c.PSCID,
                        c.CandID,
                        s.Visit_label,
                        f.Administration,
                        f.Data_entry,
                        f.Validity,
                        f.CommentID,
                        CASE WHEN EXISTS (SELECT 'x' FROM conflicts_unresolved cu WHERE f.CommentID=cu.CommentId1 OR f.CommentID=cu.CommentId2) THEN 'Y' ELSE 'N' END AS Conflicts_Exist,
                        CASE ddef.Data_entry='Complete' WHEN 1 THEN 'Y' WHEN NULL THEN 'Y' ELSE 'N' END AS DDE_Complete ";
        $from = "FROM
                        flag f
                        JOIN session s ON (s.ID=f.SessionID)
                        JOIN candidate c ON (c.CandID=s.CandID)
                        LEFT JOIN flag ddef ON (ddef.CommentID=CONCAT('DDE_', f.CommentID))
                        LEFT JOIN participant_status ps ON ( ps.Candid = c.Candid )";

        $where = "WHERE
                        f.CommentID NOT LIKE 'DDE%'
                        AND f.Test_name=:inst
                        AND s.Active='Y' AND c.Active='Y'
                        AND c.RegistrationCenterID NOT IN (1,8,9,10)
                        AND (ps.participant_status NOT IN (2,3,4,15) OR ps.participant_status IS NULL)
                        AND c.RegistrationProjectID NOT IN (5,6)";

        if ($tablename === "") {
            // the data is in the flag table, add the data column to the query and
            // do not join the table.
            $extraSelect = ", f.Data ";

            return $select . $extraSelect . $from . $where;
        }

        // add the SQL table to the query
        $extraSelect = ", i.* ";
        $extraJoin = "JOIN " . $this->SQLDB->escape($tablename) . " i ON (i.CommentID=f.CommentID) ";
        return $select . $extraSelect . $from . $extraJoin . $where;
    }

    /**
     * Calculate the parents age at administration based on inputs at the
     * Telephone Screening Interview administered for the candidate.
     *
     * @param string $candid     the candidate id
     * @param string $date_taken the date the current instrument was administered
     * @return string[] the mother and fathers age
     * @throws LorisException
     */
    function getParentAgeAtAdministration($candid, $date_taken) {
        $tsis = $this->SQLDB->pselect("
                SELECT f.Test_name, f.CommentID
                    FROM session s
                    JOIN flag f on (s.ID=f.SessionID)
                    WHERE s.Visit_label = (
                            SELECT s2.Visit_label
                                FROM session s2
                                WHERE s2.candID=:candID
                                    AND s2.Date_visit IS NOT NULL
                                ORDER BY s2.Date_visit ASC
                                LIMIT 1
                        )
		                AND f.Test_name IN ('tsi', 'tsi_ds', 'TSI_DS_Infant', 'TSI_EP')
		                AND f.CommentID NOT LIKE 'DDE_%'
                        AND s.CandID=:candID
            ", array('candID' => $candid));
        $ages = array(
            'mother' => 'Unknown',
            'father' => 'Unknown'
        );

        if (is_null($date_taken)) {
            return $ages;
        }

        foreach ($tsis as $tsi) {
            $result = array();
            switch ($tsi['Test_name']) {
                case "tsi":
                    $result = $this->SQLDB->pselectRow("
                            SELECT mother_dob_date AS mother_dob,
                                   father_dob_date AS father_dob
                                FROM tsi
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
                case "tsi_ds":
                    $result = $this->SQLDB->pselectRow("
                            SELECT mother_dob_date AS mother_dob,
                                   father_dob_date AS father_dob
                                FROM tsi_ds
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
                case "TSI_DS_Infant":
                    $result = $this->SQLDB->pselectRow("
                            SELECT mother_dob,
                                   father_dob
                                FROM TSI_DS_Infant
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
                case "TSI_EP":
                    $result = $this->SQLDB->pselectRow("
                            SELECT mother_dob,
                                   father_dob
                                FROM TSI_EP
                                WHERE CommentID=:commentID
                        ", array('commentID' => $tsi['CommentID']));
                    break;
            }

            if (!empty($result)) {
                if (!is_null($result['mother_dob'])) {
                    $age = Utility::calculateAge($result['mother_dob'], $date_taken);
                    $ages['mother'] = round($age['year'] + round($age['mon']/12,2) +
                        round($age['day']/365, 2), 2);
                }
                if (!is_null($result['father_dob'])) {
                    $age = Utility::calculateAge($result['father_dob'], $date_taken);
                    $ages['father'] = round($age['year'] + round($age['mon']/12,2) +
                        round($age['day']/365, 2), 2);
                }
            }
        }

        return $ages;
    }

    function UpdateCandidateDocs($Instruments)
    {
        $results = array(
                    'new'       => 0,
                    'modified'  => 0,
                    'unchanged' => 0,
                   );
        foreach ($Instruments as $instrument => $name) {
            // Since the testname does not always match the table name in the database
            // we need to instantiate the object to get the table name
            // we need to check if it is a JSONData instrument or SQL data
            $instrumentObj = \NDB_BVL_Instrument::factory(
                $instrument,
                '',
                ''
            );
            $JSONData = $instrumentObj->usesJSONData();
            $tableName = "";
            if ($JSONData === false) {
                $tableName = $instrumentObj->table;
            }

            $this->CouchDB->beginBulkTransaction();
            $preparedStatement = $this->SQLDB->prepare($this->generateDocumentSQL($tableName));
            $preparedStatement->execute(array('inst' => $instrument));
            while ($row = $preparedStatement->fetch(PDO::FETCH_ASSOC)) {
                $CommentID = $row['CommentID'];

                if ($JSONData) {
                    //Transform JSON object into an array and add treat it the same as SQL
                    $instrumentData = json_decode($row['Data'], true) ?? array();
                    unset($row['Data']);
                    $docdata = $row + $instrumentData;
                } else {
                    $docdata   = $row;
                }

                unset($docdata['CommentID']);
                unset($docdata['PSCID']);
                unset($docdata['CandID']);
                unset($docdata['Visit_label']);
                unset($docdata['Testdate']);
                unset($docdata['city_of_birth']);
                unset($docdata['city_of_birth_status']);

                if (isset($docdata['Examiner']) && is_numeric($docdata['Examiner'])) {
                    $docdata['Examiner'] = $this->SQLDB->pselectOne("SELECT full_name FROM examiners WHERE examinerID=:eid", array("eid" => $docdata['Examiner']));
                }

                $ages = $this->getParentAgeAtAdministration($row['CandID'], $docdata['Date_taken']);
                $docdata['mother_age_at_administration'] = $ages['mother'];
                $docdata['father_age_at_administration'] = $ages['father'];

                // Check if instrument has any surveys.
                $survey_count = $this->SQLDB->pselectOne("
                    SELECT count(*) FROM participant_accounts WHERE Test_name=:test_name
                ", array("test_name" => $instrument));

                if ($survey_count > 0) {
                    // Instrument is survey based and complete. Fetch survey's status.
                    $survey_completion = $this->SQLDB->pselectOne("
                            SELECT Status FROM participant_accounts WHERE CommentID=:CommentID
                        ", array("CommentID" => $CommentID));
                    if ($docdata['Data_entry'] === "Complete") {
                        // Survey status is complete then survey was submitted via the survey module,
                        // else the survey was submitted via direct entry.
                        $docdata['Data_Entry_Type']
                            = $survey_completion === "Complete" ? "Submitted" : "Direct Data Entered";
                    } else {
                        // Instrument is still in progess.
                        $docdata['Data_Entry_Type'] = "In Progress";
                    }

                    // Check if the survey was emailed or not.
                    if (is_null($survey_completion)) {
                        // Survey doesn't exists in survey table, mark as not created.
                        $docdata['emailed'] = "Survey not Created";
                    } else if ($survey_completion === "Created") {
                        // Survey still in created state, never emailed.
                        $docdata['emailed'] = "Created - Not emailed via LORIS";
                    } else {
                        $docdata['emailed'] = "Sent - emailed via LORIS";
                    }
                }

                $doc     = array(
                            'Meta' => array(
                                       'DocType'    => $instrument,
                                       'identifier' => array(
                                                        $row['PSCID'],
                                                        $row['Visit_label'],
                                                       ),
                                      ),
                            'data' => $docdata,
                           );
                $success = $this->CouchDB->replaceDoc($CommentID, $doc);
                print "$row[PSCID] $row[Visit_label] $instrument: $success\n";

                $results[$success] += 1;

                // Count every 200 //
                if (($results[$success] % 200) === 0) {
                    $this->CouchDB->commitBulkTransaction();
                    $this->CouchDB->beginBulkTransaction();
                }
            }

            $result = $this->CouchDB->commitBulkTransaction();
        }
        return $results;
    }

    function GetInstruments()
    {
        return \Utility::getAllInstruments();
    }

    function createRunLog($results)
    {
        $now = date("c");
        $id  = $this->CouchDB->createDoc(
            array(
             'Meta'    => array('DocType' => 'RunLog'),
             'RunInfo' => array(
                           'Script'        => 'Instrument Importer',
                           'Time'          => "$now",
                           'DocsCreated'   => $results['new'],
                           'DocsModified'  => $results['modified'],
                           'DocsUnchanged' => $results['unchanged'],
                          ),
            )
        );
        print "Created run log with id $id\n";
    }
    function run()
    {
        $tests = $this->GetInstruments();
        $this->UpdateDataDicts($tests);
        $results = $this->UpdateCandidateDocs($tests);
        $this->CreateRunLog($results);
    }
}
// Don't run if we're doing the unit tests, the unit test will call run..
if (!class_exists('UnitTestCase')) {
    $Runner = new CouchDBInstrumentImporter();
    $Runner->run();
}
?>
