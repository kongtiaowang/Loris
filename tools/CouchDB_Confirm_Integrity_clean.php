<?php
/**
 * This script deletes cancelled or incorrect data from the DQT by comparing
 * everything in CouchDB against what's currently valid in MySQL.
 *
 * Note that if there is a duplicate Visit_label for a PSCID the script can
 * not determine which is Active on the CouchDB end and assumes that the identifier
 * is invalid, so this should be run *before* the import scripts because it will
 * delete both (and then the import script will reimport the correct one if run
 * in that order.)
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'generic_includes.php';
require_once 'CouchDB.class.inc';
require_once 'Database.class.inc';

/**
 * This class compares what's in a CouchDB Loris DQT instance against the
 * MySQL database of that Loris instance and deletes anything from CouchDB
 * that is not in MySQL.
 *
 * @category Main
 * @package  Loris
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
class CouchDBIntegrityChecker
{
    var $SQLDB; // reference to the database handler, store here instead
                // of using Database::singleton in case it's a mock.
    var $CouchDB; // reference to the CouchDB database handler

    var $ddeInstruments;

    // Keep track of instrument's validityEnabled flag as to not need
    // to load the instrument for each dqt session.
    var $validityEnabled = array();

    var $debugUnknown = array();
    var $debugDeleted = array();


    /**
     * Initialize references to SQL database and CouchDB wrapper
     *
     * @return None
     */
    function __construct()
    {
        $factory       = \NDB_Factory::singleton();
        $config        = \NDB_Config::singleton();
        $couchConfig   = $config->getSetting('CouchDB');
        $this->SQLDB   = $factory->Database();
        $this->CouchDB = $factory->couchDB(
            $couchConfig['dbClean'],
            $couchConfig['hostname'],
            intval($couchConfig['port']),
            $couchConfig['admin'],
            $couchConfig['adminpass']
        );
        $this->ddeInstruments = \Utility::getAllDDEInstruments();
    }

    /**
     * Verify the candidates participant status is valid and session is active. Returns true
     * if the candidate is valid, deleting document and returning false.
     *
     * @param string $pscid the candidates pscid
     * @param string $vl    the candidates visit label
     * @param string $id    the couchDB doc id
     * @return bool
     */
    function verifyStatus($pscid, $vl, $id) {
        $sqlDB = $this->SQLDB->pselectRow(
            "SELECT c.PSCID, c.Active as cActive, s.Visit_label
                 FROM candidate c
                 LEFT JOIN session s
                   ON (
                         c.CandID=s.CandID
                     AND s.Visit_label=:VL
                     AND s.Active='Y'
                     AND s.Current_stage NOT IN ('Recycling Bin')
                   )
                 LEFT JOIN participant_status ps ON ( ps.Candid = c.Candid )
                 WHERE c.PSCID=:PID
                 AND c.RegistrationCenterID NOT IN (1,8,9,10)
                 AND (ps.participant_status NOT IN (2,3,4,15) OR ps.participant_status IS NULL)
                 AND c.RegistrationProjectID NOT IN (5,6)",
            array(
                "PID" => $pscid,
                "VL" => $vl
            )
        );

        // Candidate not in LORIS DB anymore: delete doc
        if (empty($sqlDB)) {
            print "Candidate $pscid does not exist: deleting doc {$id}.\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
            // Candidate is in LORIS DB but is inactive now: delete doc
        } else if ($sqlDB['cActive'] == 'N') {
            print "PSCID $pscid is inactive: deleting doc {$id}.\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
            // Visit has been either deleted or inactivated: delete doc
        } else if (empty($sqlDB['Visit_label'])) {
            print "No active visit $vl found for $pscid: deleting doc {$id}.\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
            // Case mismatch for PSCID: delete doc
        }  else if ($sqlDB['PSCID'] !== $pscid) {
            print "PSCID $pscid case sensitivity mismatch: deleting doc {$id}\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
            // Case mismatch for visit label: delete doc
        } else if ($sqlDB['Visit_label'] !== $vl) {
            print "Visit Label case sensitivity mismatch: deleting doc {$id}\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
            // All good: keep the doc
        } else {
//            print "Nothing wrong with {$id}!\n";
            return true;
        }

        return false;
    }

    /**
     * Verify that the ADOS module being used for the candidate is DDE, deleting doc if not.
     *
     * @param string $pscid the candidates pscid
     * @param string $vl    the candidates visit label
     * @param string $id    the couchDB doc id
     */
    function verifyADOS($pscid, $vl, $id) {
        $module = $this->SQLDB->pselectOne("
            SELECT f.Test_name
            FROM flag f
                JOIN session s ON (s.ID = f.SessionID)
                JOIN candidate c ON (c.CandID = s.CandID)
            WHERE c.PSCID = :PID
                AND s.Visit_label = :VL
                AND Test_name LIKE 'ados%'
                AND EXISTS (
                     SELECT 'x'
                     FROM flag ff
                     WHERE ff.CommentID = CONCAT('DDE_', f.CommentID)
                         AND ff.Data_entry = 'Complete'
                ) AND NOT EXISTS (
                     SELECT 'x'
                     FROM conflicts_unresolved cu
                     WHERE f.CommentID=cu.CommentId1 OR f.CommentID=cu.CommentId2
                ) AND f.Administration = 'All'
                LIMIT 1;
        ", array("PID" => $pscid, "VL" => $vl));

        if (strpos($module, 'ados') === false) {
            print "Ados Module doesn't meet clean specification: deleting doc {$id}\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
        }
    }

    /**
     * Verifies if the candidate's instrument is DDE and valid when applicable.
     *
     * @param string $id    the couchDB doc id
     * @throws NotFound
     */
    function verifyInstrument($id) {
        // Using the doc id, ie. CommentID, find out the instrument.
        $testName = $this->SQLDB->pselectOne("
            SELECT Test_name FROM flag WHERE CommentID = :commentID
        ", array("commentID" => $id));

        // If the commentID is not found, track the id to email list of unknown ids.
        if (empty($testName)) {
            $this->debugUnknown[] = $id;
            return;
        }

        // Keep track of instrument validity flags as to not load the same instrument twice.
        // If we don't know the flag, load the instrument and store for future use.
        if (!key_exists($testName, $this->validityEnabled)) {
            $instrumentObj = \NDB_BVL_Instrument::factory(
                $testName,
                '',
                ''
            );
            $this->validityEnabled[$testName] = $instrumentObj->ValidityEnabled;
        }

        $query = "
            SELECT f.Test_name
            FROM flag f
                LEFT JOIN flag ddef ON (ddef.CommentID=CONCAT('DDE_', f.CommentID))
            WHERE f.CommentID = :id
                AND f.Test_name=:inst
                AND f.Administration = 'All'
                AND f.Data_entry = 'Complete'
        ";

        // Check if the instrument is set for DDE and/or validity flag, if so add required clauses.
        if (key_exists($testName, $this->ddeInstruments)) {
            $query = $query . "
                AND ddef.Data_entry = 'Complete'
                AND NOT EXISTS (
                        SELECT 'x'
                        FROM conflicts_unresolved cu
                        WHERE f.CommentID=cu.CommentId1 OR f.CommentID=cu.CommentId2
                    )
            ";

            if ($this->validityEnabled[$testName]) {
                $query = $query . "
                    AND f.Validity <> 'Invalid'";
            }
        } else if ($this->validityEnabled[$testName]) {
            $query = $query . "
                AND f.Validity = 'Valid'";
        }

        $table = $this->SQLDB->pselectOne($query, array("id" => $id, "inst" => $testName));

        // If the query didn't return the expected table, delete the document as
        // it doesn't meet the clean requirements.
        if ($testName !== $table) {
            print "Instrument doesn't meet clean specification: deleting doc {$id}\n";
            $this->debugDeleted[] = $id;
            $this->CouchDB->deleteDoc($id);
        }
    }

    /**
     * Runs the script
     *
     * @return none
     */
    function run()
    {

        $sessions = $this->CouchDB->queryView(
            "DQG-2.0",
            "sessions",
            array("reduce" => "false")
        );
        print "Sessions:\n";

        foreach ($sessions as $row) {
            $doc_id = $row['id'];
            $pscid  = $row['key'][0];
            $vl     = $row['key'][1];

            $validStatus = $this->verifyStatus($pscid, $vl, $doc_id);

            if ($validStatus) {
                if (strpos($doc_id, "Demographics_Session") !== false) {
                    // Skip for now
                } else if (strpos($doc_id, "ADOS_Derived") !== false) {
                    $this->verifyADOS($pscid, $vl, $doc_id);
                } else if (strpos($doc_id, "Language_Common_Variables") !== false) {
                    // Skip for now
                } else {
                    // Instrument Based.
                    $this->verifyInstrument($doc_id);
                }
            }
        }

        // For tracking purposes, email list of deleted documents and unknown ones
        // so that if need changes can be made to import scripts to fix issues.
        if (!empty($this->debugDeleted) || !empty($this->debugUnknown)) {
            $today_date=date("Y-m-d");
            $msq_data = array(
                'today_date'  => $today_date,
                'deleted' => $this->debugDeleted,
                'unknown' => $this->debugUnknown
            );

            Email::send("jordan.stirling@mcin.ca", "dqt_clean.tpl", $msq_data, "", "IBIS Team <noreply@ibis.loris.ca>", "", "", "text/html");
        }
    }
}

// Don't run if we're doing the unit tests, the unit test will call run..
if (!class_exists('UnitTestCase')) {
    $Runner = new CouchDBIntegrityChecker();
    $Runner->run();
}
?>
