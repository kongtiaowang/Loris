<?php
require_once __DIR__."/../../tools/generic_includes.php";

/**
 * Script that'll delete an instrument from a candidate's timepoint. This script will delete the
 * required data from the flag and instrument table as well as from the DQT. It has two modes of
 * running. The first is as a dry run which will print which data will be deleted. The second will
 * delete the data.
 */
class CandidateInstrumentDeleter
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

    /**
     * Print help text to the console.
     */
    function showHelp()
    {
        echo "*** Delete Instrument From Candidate Timepoint ***\n\n";

        echo "Usage: php delete_candidate_instrument.php testName pscid vist_label [confirm]\n\n";
        echo "Use the confirm flag to confirm deletion.\n";
        echo "Remove the confirm flag to preform a dry run to see what data will be deleted.\n\n";

        die();
    }

    /**
     * Checks if the specified instrument exists. If not it'll print an error and exit the script.
     *
     * @param string $test_name the instrument name to verify
     */
    function testNameExists($test_name) {
        $rowExists = $this->SQLDB->pselectOne("
            SELECT *
                FROM test_names
                WHERE Test_name=:table
        ", array("table" => $test_name));
        if (!(bool)$rowExists) {
            print "ERROR: Provided test name doesn't exist in DB, please enter valid test name.\n";
            die();
        }
    }

    /**
     * Gets the commentID and whether or not data exists for the commentID in the insturment table.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     * @return string[]|null commentID and if the data exists in the instrument table
     */
    function getSessionInfo($test_name, $pscid, $visit_label) {

        // Verify that the instrument exists in the DB, exit if not.
        $this->testNameExists($test_name);

        // Some instrument data is stored in the flag table, check if the instrument table exists.
        $existStmt = "";
        if ($this->SQLDB->tableExists($test_name)) {
            // If so add subquery to verify if data exists in the table.
            $existStmt = "EXISTS (
                       SELECT *
                           FROM " . $this->SQLDB->escape($test_name) . " i
                           WHERE i.CommentID = f.CommentID
                   ) AS data_exists,";
        }
        $sessionInfo = $this->SQLDB->pselectRow("
            SELECT $existStmt f.CommentID
                FROM session s
                    JOIN candidate c ON (s.CandID = c.CandID)
                    JOIN flag f ON (s.ID = f.SessionID)
                WHERE c.PSCID = :pscid
                    AND s.Visit_label = :visit_label
                    AND f.Test_name = :test_name
                    AND f.CommentID NOT LIKE 'DDE_%'
        ", array(
            "test_name"   => $test_name,
            "pscid"       => $pscid,
            "visit_label" => $visit_label
        ));

        if ($existStmt === "") {
            // Instrument doesn't have a table, set data exists to false.
            $sessionInfo['data_exists'] = false;
        }

        return $sessionInfo;
    }

    /**
     * Check if a document exists in the DQT with the specified commentID.
     *
     * @param string $commentID the commentID to verify
     * @return bool true if the document exists, false otherwise
     * @throws LorisException
     */
    function DQTDataExists($commentID) {
        return $this->CouchDB->getDoc($commentID) !== array();
    }

    /**
     * Instrument doesn't exist in the DB, verify if it exists in the DQT using the instruments view.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     * @return string the document id if it exists, empty string otherwise
     * @throws LorisException
     */
    function DQTViewExists($test_name, $pscid, $visit_label) {
        $data = $this->CouchDB->queryView(
            "DQG-2.0",
            "instruments",
            array(
                "reduce" => "false",
                "key"    => "[\"$test_name\", \"$pscid\", \"$visit_label\"]",
            )
        );
        if (count($data) === 1) {
            return $data[0]['id'];
        }

        return '';
    }

    /**
     * Run the script, deleting data as its found.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     * @throws DatabaseException
     * @throws LorisException
     */
    function run($test_name, $pscid, $visit_label) {
        $sessionInfo = $this->getSessionInfo($test_name, $pscid, $visit_label);

        // Check if data exists in the DB.
        if (is_null($sessionInfo)) {
            // Data doesn't exist in DB. Check if it exists in the DQT.
            $docID = $this->DQTViewExists($test_name, $pscid, $visit_label);
            if ($docID !== "") {
                // Data exists, delete it.
                print "Deleting data from the DQT\n";
                $this->CouchDB->deleteDoc($docID);
            }
        } else {
            // Data exists in the DB, delete instrument for candidate's timepoint.
            print "Deleting instrument from candidate visit.\n";
            $this->SQLDB->delete("flag", array("CommentID" => $sessionInfo['CommentID']));

            // Check if data exists in the instrument table.
            if ($sessionInfo['data_exists']) {
                // Data exists, delete it.
                print "Deleting instrument data for candidate.\n";
                $this->SQLDB->delete($test_name, array("CommentID" => $sessionInfo['CommentID']));
            }

            // Check if data exists in the DQT.
            $dqtDataExists = $this->DQTDataExists($sessionInfo['CommentID']);
            if ($dqtDataExists) {
                // Data exists, delete it.
                print "Deleting data from the DQT\n";
                $this->CouchDB->deleteDoc($sessionInfo['CommentID']);
            }
        }
    }

    /**
     * Run the script, printing out which data will be deleted if run with confirm flag.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     * @throws LorisException
     */
    function dryRun($test_name, $pscid, $visit_label) {
        $sessionInfo = $this->getSessionInfo($test_name, $pscid, $visit_label);

        // Check if data exists in the DB.
        if (is_null($sessionInfo)) {
            // Data doesn't exist in DB. Check if it exists in the DQT.
            $docID = $this->DQTViewExists($test_name, $pscid, $visit_label);
            if ($docID !== "") {
                // Data exists, print message that data exists in DQT.
                print "Candidate data exists in the DQT, run with confirm to delete\n";
            } else {
                // No data exists in DB and DQT. Print message that nothing was found.
                print "Nothing found for given parameters.\n";
            }
        } else {
            // Data exists in the DB. Print message that data exists in DB.
            print "Instument, $test_name, exists at $visit_label for candidate $pscid.\n";
            print "\tRun with confirm to delete instrument at timepoint.\n";

            // Check if data exists in the DQT.
            $dqtDataExists = $this->DQTDataExists($sessionInfo['CommentID']);
            if ($dqtDataExists) {
                // Data exists. Print message that data exists in DQT.
                print "Candidate data exists in the DQT, run with confirm to delete\n";
            }
        }
    }
}

if(!class_exists('UnitTestCase')) {
    $Runner = new CandidateInstrumentDeleter();

    if (count($argv) < 4 || count($argv) > 5 || $argv[1] == 'help') {
        $Runner->showHelp();
    }

    if (count($argv) === 5 && $argv[4] === 'confirm') {
        $Runner->run($argv[1], $argv[2], $argv[3]);
    } else {
        $Runner->dryRun($argv[1], $argv[2], $argv[3]);
    }
}
