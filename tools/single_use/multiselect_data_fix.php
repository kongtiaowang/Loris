<?php
require_once __DIR__."/../../../tools/generic_includes.php";

class InstrumentMultiselectFixer
{
    var $SQLDB;

    function __construct()
    {
        $factory     = \NDB_Factory::singleton();
        $this->SQLDB = $factory->Database();
    }

    /**
     * Print help text to the console.
     */
    function showHelp()
    {
        echo "*** Fix all multiselect data inserted post 23.0 upgrade ***\n\n";

        echo "Usage: php multiselect_data_fix.php testName|all [confirm]\n\n";
        echo "Use testname when wanting to run on a single instrument.\n";
        echo "Otherwise use all to run on all instruments.\n";
        echo "Use the confirm flag to update the missing data.\n";
        echo "Remove the confirm flag to preform a dry run to see what data will be updated.\n\n";

        die();
    }

    /**
     * Checks if the specified instrument exists. If not it'll print an error and exit the script.
     *
     * @param string $testName the instrument name to verify
     */
    function testNameExists($testName) {
        $rowExists = $this->SQLDB->pselectOne("
            SELECT *
                FROM test_names
                WHERE Test_name=:table
        ", array("table" => $testName));
        if (!(bool)$rowExists) {
            print "ERROR: Provided test name doesn't exist in DB, please enter valid test name.\n";
            die();
        }
    }

    /**
     * Query instrument table to fetch all multiselect columns which have a stored
     * value of Array.
     *
     * @param string $testName the instrument to query
     *
     * @return array|string[][] all rows with stored value of array
     * @throws NotFound
     */
    function getMissingData($testName) {
        $instrumentObj = \NDB_BVL_Instrument::factory(
            $testName,
            '',
            ''
        );

        $multiSelects = $instrumentObj->getSelectMultipleElements();
        if (empty($multiSelects)) {
            return array();
        }

        $list  = "i.".implode(",i.", $multiSelects);
        $query = "SELECT f.CommentID,
                f.Data,
                s.Visit_label,
                c.CandID,
                c.PSCID,
                f.Testdate,
                f.UserID,
                psc.Name,
                pso.Description,
                ps.reason_specify,
                $list
            FROM $testName i
                JOIN flag f ON (f.CommentID = i.CommentID)
                JOIN session s ON (s.ID = f.SessionID)
                JOIN candidate c ON (c.CandID = s.CandID)
                JOIN psc ON (psc.CenterID = c.RegistrationCenterID)
                LEFT JOIN participant_status ps ON (c.CandID = ps.CandID)
                LEFT JOIN participant_status_options pso ON (ps.participant_status = pso.ID)
            WHERE 'Array' IN ($list)";

        return $this->SQLDB->pselect($query, array());
    }

    /**
     * Compare data stored in instrument table and flag Data column, updating
     * instrument table when confirm flag is set to true.
     *
     * @param string  $testName    the instrument
     * @param array   $missingData the missing instrument data
     * @param boolean $confirm     the confirm flag
     * @return array information on what fields are fixable and which are not
     */
    function fixMissingData($testName, $missingData, $confirm = false) {
        $diff = array();
        $fixable = 0;
        $metaCols = array(
            "CommentID",
            "Data",
            "Visit_label",
            "CandID",
            "PSCID",
            "Testdate",
            "UserID",
            "Name",
            "Description",
            "reason_specify"
        );
        foreach ($missingData as $row) {
            $jsonData = (array) json_decode($row['Data']);
            $values   = array();
            $unknown  = array();
            $nullVal  = array();
            $knownVal = array();
            foreach ($row as $key => $value) {
                if (in_array($key, $metaCols)) {
                    continue;
                }

                if (array_key_exists($key, $jsonData)) {
                    $values[$key] = implode("{@}", $jsonData[$key]);
                } else if (is_null($value)) {
                    $nullVal[$key] = $key;
                } else if ($value !== 'Array') {
                    $knownVal[$key] = $value;
                } else {
                    $unknown[$key] = $value;
                }
            }

            if (!empty($values)) {
                $fixable++;
            }

            if ($confirm && empty($values)) {
                $this->SQLDB->update($testName, $values, array('CommentID'=>$row['CommentID']));
            }
            $diff[$row['CommentID']] = array(
                "dccid"    => $row['CandID'],
                "pscid"    => $row['PSCID'],
                "visit"    => $row['Visit_label'],
                "site"     => $row['Name'],
                "status"   => $row['Description'],
                "comments" => $row['reason_specify'],
                "date"     => $row['Testdate'],
                "user"     => $row['UserID'],
                "known"    => $values,
                "nullVal"  => $nullVal,
                "unknown"  => $unknown,
                "setVal"   => $knownVal
            );
        }

        return array(
            "data"    => $diff,
            "fixable" => $fixable,
            "total"   => count($missingData)
        );
    }

    /**
     * Update instruments to look for missing data based for multiselect fields.
     *
     * @param array $instruments list of instruments to update missing data
     * @throws NotFound
     */
    function run($instruments) {
        $report = array();
        foreach ($instruments as $testName => $fullName) {
            $missingData = $this->getMissingData($testName);
            if (empty($missingData)) {
                continue;
            }

            $report[$testName] = $this->fixMissingData($testName, $missingData, true);
        }

        $fileName = 'missing_data_report_'.date('m-d-Y_hia').'.json';
        $fp = fopen($fileName, 'w');
        fwrite($fp, json_encode($report));
        fclose($fp);
    }

    /**
     * Dry run to look for missing data based for multiselect fields in instruments.
     *
     * @param array $instruments list of instruments to update missing data
     * @throws NotFound
     */
    function dryRun($instruments) {
        $report = array();
        foreach ($instruments as $testName => $fullName) {
            $missingData = $this->getMissingData($testName);
            if (empty($missingData)) {
                continue;
            }

            $report[$testName] = $this->fixMissingData($testName, $missingData);
        }

        $fileName = 'missing_data_report_'.date('m-d-Y_hia').'.json';
        $fp = fopen($fileName, 'w');
        fwrite($fp, json_encode($report));
        fclose($fp);
    }
}

if(!class_exists('UnitTestCase')) {
    $Runner = new InstrumentMultiselectFixer();

    if (count($argv) < 2 || count($argv) > 3 || $argv[1] == 'help') {
        $Runner->showHelp();
    }

    $instruments = array();
    if ($argv[1] === 'all') {
        $instruments = \Utility::getAllInstruments();
    } else {
        $Runner->testNameExists($argv[1]);
        $instruments = array($argv[1] => $argv[1]);
    }

    if (count($argv) === 3 && $argv[2] === 'confirm') {
        $Runner->run($instruments);
    } else {
        $Runner->dryRun($instruments);
    }
}
