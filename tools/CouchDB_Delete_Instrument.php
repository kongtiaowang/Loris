<?php
require_once __DIR__."/../../tools/generic_includes.php";

/**
 * Script to delete an instrument from the DQT. The script has two capabilites, a dry run which will print out
 * the data which will be deleted:
 *     php CouchDB_Delete_Instrument.php testName
 * and a actual run which will delete the data from the DQT and the instrument from the test_names table to ensure
 * that the data isn't reinserted into the DQT:
 *     php CouchDB_Delete_Instrument.php testName confirm
 */
class CouchDBInstrumentDeleter
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
        echo "*** Delete Instrument From DQT ***\n\n";

        echo "Usage: php CouchDB_Delete_Instrument.php testName [confirm]\n\n";
        echo "Use the confirm flag to confirm deletion.\n";
        echo "Remove the confirm flag to preform a dry run to see what data will be deleted.\n\n";

        die();
    }

    /**
     * Checks if the instrument has a data dictionary in couchDB.
     *
     * @param string $test_name the instrument name to verify
     *
     * @return bool true if exisits, false otherwise
     * @throws LorisException
     */
    function DQTDataDictionaryExists($test_name)
    {
        return $this->CouchDB->getDoc("DataDictionary:$test_name") !== array();
    }

    /**
     * Checks if any candidate data exisits in the DQT for the given instrument.
     *
     * @param string $test_name the instrument name to check
     *
     * @return array|string the candidate data if any
     * @throws LorisException
     */
    function getDQTData($test_name)
    {
        return $this->CouchDB->queryView(
            "DQG-2.0",
            "categories",
            array(
                "reduce" => "false",
                "key"    => "\"$test_name\"",
            )
        );
    }

    /**
     * Checks if the instrument exists in the test_name table.
     *
     * @param string $test_name the instrument name to verify
     *
     * @return bool true if it exist, false otherwise
     */
    function testNameExistsInTable($test_name)
    {
        $rowExists = $this->SQLDB->pselectOne("
            SELECT *
                FROM test_names
                WHERE Test_name=:table
        ", array("table" => $test_name));
        return (bool)$rowExists;
    }

    /**
     * Preforms a dry run deleting an instrument from the DQT, printing out any data which would be deleted.
     *
     * @param string $test_name the instrument name to run on
     *
     * @throws LorisException
     */
    function dryRun($test_name)
    {
        echo "RUNNING DRY RUN\n\n";

        // Check if DQT data dictionary exists.
        if ($this->DQTDataDictionaryExists($test_name)) {
            echo "DQT Datadictionary exists, run with confirm to remove\n";
        }

        // Check if data exists in DQT.
        $data = $this->getDQTData($test_name);
        if (count($data) > 0) {
            echo "DQT Data exists, run confirm to delete the following:\n";
            foreach ($data as $value) {
                $id = $value['id'];
                echo "\tFOR DELETION $id\n";
            }
        }

        // Check if testName exists in test_name table
        if ($this->testNameExistsInTable($test_name)) {
            echo "Instrument exists in test_names table. Run confirm to remove.\n";
        }
        echo "\n";
    }

    /**
     * Deletes the DQT data for a given the instrument.
     *
     * @param string $test_name the instrument name to run on
     * @throws DatabaseException
     * @throws LorisException
     */
    function run($test_name) {
        echo "RUNNING WITH CONFIRM\n\n";

        // Check if DQT data dictionary exists.
        if ($this->DQTDataDictionaryExists($test_name)) {
            echo "DQT Datadictionary exists, deleting from DQT\n";
            $this->CouchDB->deleteDoc("DataDictionary:$test_name");
        } else {
            echo "DQT Datadictionary doesn't exist. Skipping deletion\n";
        }

        // Check if data exists in DQT.
        $data = $this->getDQTData($test_name);
        if (count($data) > 0) {
            echo "DQT Data exists. Starting deletion:\n";
            foreach ($data as $value) {
                $id = $value['id'];
                echo "\tDELETING $id\n";
                $this->CouchDB->deleteDoc($id);
            }
        } else {
            echo "DQT Data doesn't exist. Skipping deletion\n";
        }

        // Check if testName exists in test_name table
        if ($this->testNameExistsInTable($test_name)) {
            echo "Instrument exists in test_names table. Removing from table.\n";
            $this->SQLDB->delete(
                'test_names',
                array("Test_name" => $test_name)
            );
        }
        echo "\n";
    }
}

if(!class_exists('UnitTestCase')) {
    $Runner = new CouchDBInstrumentDeleter();

    if (count($argv) < 2 || count($argv) > 3 || $argv[1] == 'help') {
        $Runner->showHelp();
    }

    if (count($argv) === 3 && $argv[2] === 'confirm') {
        $Runner->run($argv[1]);
    } else {
        $Runner->dryRun($argv[1]);
    }
}
