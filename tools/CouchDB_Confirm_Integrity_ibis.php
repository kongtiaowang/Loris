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
            $couchConfig['dbName'],
            $couchConfig['hostname'],
            intval($couchConfig['port']),
            $couchConfig['admin'],
            $couchConfig['adminpass']
        );
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
        $activeExists = $this->SQLDB->prepare(
            "SELECT count(*) AS count FROM 
        candidate c LEFT JOIN session s USING (CandID) WHERE s.Active='Y' 
        AND c.Active='Y' AND c.PSCID=:PID and s.Visit_label=:VL"
        );
        foreach ($sessions as $row) {
            $pscid = $row['key'][0];
            $vl    = $row['key'][1];
            //IBIS Override Query Start here (IBIS database has so many Inactive Sessions and
            //it makes the LORIS default pselectRow fails
            $sqlDB = $this->SQLDB->pselectRow(
                "SELECT c.PSCID, c.Active as cActive, s.Visit_label
                 FROM candidate c
                 LEFT JOIN session s
                 ON (c.CandID=s.CandID AND s.Visit_label=:VL AND s.Active='Y')
                 LEFT JOIN participant_status ps ON ( ps.Candid = c.Candid )
                 WHERE c.PSCID=:PID
                 AND c.RegistrationCenterID NOT IN (1,8,9,10)
                 AND (ps.participant_status NOT IN (2,3,4) OR ps.participant_status IS NULL)
                 AND c.ProjectID NOT IN (5,6)",
                array(
                    "PID" => $pscid,
                    "VL" => $vl
                )
            );
            ////IBIS Override Query Ends Here

            // Candidate not in LORIS DB anymore: delete doc
            if (empty($sqlDB)) {
                print "Candidate $pscid does not exist: deleting doc {$row['id']}.\n";
                $this->CouchDB->deleteDoc($row['id']);
            // Candidate is in LORIS DB but is inactive now: delete doc
            } else if ($sqlDB['cActive'] == 'N') {
                print "PSCID $pscid is inactive: deleting doc {$row['id']}.\n";
                $this->CouchDB->deleteDoc($row['id']);
            // Visit has been either deleted or inactivated: delete doc
            } else if (empty($sqlDB['Visit_label'])) {
                print "No active visit $vl found for $pscid: deleting doc {$row['id']}.\n";
                $this->CouchDB->deleteDoc($row['id']);
            // Case mismatch for PSCID: delete doc
            }  else if ($sqlDB['PSCID'] !== $pscid) {
                print "PSCID $pscid case sensitivity mismatch: deleting doc {$row['id']}\n";
                $this->CouchDB->deleteDoc($row['id']);
            // Case mismatch for visit label: delete doc
            } else if ($sqlDB['Visit_label'] !== $vl) {
                print "Visit Label case sensitivity mismatch: deleting doc {$row['id']}\n";
                $this->CouchDB->deleteDoc($row['id']);
            // All good: keep the doc
            } else {
                print "Nothing wrong with {$row['id']}!\n";
            }
        }
    }
}

// Don't run if we're doing the unit tests, the unit test will call run..
if (!class_exists('UnitTestCase')) {
    $Runner = new CouchDBIntegrityChecker();
    $Runner->run();
}
?>
