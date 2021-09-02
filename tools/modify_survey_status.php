<?php
require_once __DIR__."/../../tools/generic_includes.php";

/**
 * Script that is to be run when wanting to modify a survey from completed state to in progress.
 */
class ModifySurveyStatus
{
    var $SQLDB;

    function __construct()
    {
        $factory       = \NDB_Factory::singleton();
        $config        = \NDB_Config::singleton();
        $this->SQLDB   = $factory->Database();
    }

    /**
     * Print help text to the console.
     */
    function showHelp()
    {
        echo "*** Modify a completed survey's status to in progress to allow for parents to reinsert data ***\n\n";

        echo "Usage: php modify_survey_status.php testName pscid visit_label [confirm]\n\n";
        echo "Use the confirm flag to confirm updating.\n";
        echo "Remove the confirm flag to preform a dry run to see what data will be updated.\n\n";

        die();
    }

    /**
     * Query the flag table to get the insturment status and commentID. Script will exit if insturment
     * not found.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     * @return string[]
     */
    function getInstrumentStatus($test_name, $pscid, $visit_label) {
        $instrumentStatus = $this->SQLDB->pselectRow("
            SELECT f.CommentID, f.Data_entry, f.Administration
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

        if (is_null($instrumentStatus)) {
            print "Instrument $test_name not found for candidate $pscid's visit $visit_label. Please verify input.\n";
            die();
        }

        return $instrumentStatus;
    }

    /**
     * Get the survey status and key. Script will exit if survey not found.
     *
     * @param string $commentID the comment id
     * @return string[]
     */
    function getSurveyInfo($commentID) {
        $surveyInfo = $this->SQLDB->pselectRow("
            SELECT Status, OneTimePassword
                FROM participant_accounts
                WHERE CommentID = :CommentID
        ", array("CommentID" => $commentID));

        if (is_null($surveyInfo)) {
            print "Survey not found, please verify input.\n";
            die();
        }

        if ($surveyInfo['Status'] !== "Complete") {
            print "Survey not in completed state, unable to update.\n";
            die();
        }

        return $surveyInfo;
    }

    /**
     * Run the script printing whether the survey or instrument status need to be updated.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     */
    function dryRun($test_name, $pscid, $visit_label) {
        $instrumentStatus = $this->getInstrumentStatus($test_name, $pscid, $visit_label);

        $commentID  = $instrumentStatus['CommentID'];
        $surveyInfo = $this->getSurveyInfo($commentID);

        print "Completed survey with key " . $surveyInfo['OneTimePassword']
            . " found. Run with confirm to update survey to in progress.\n";

        if ($instrumentStatus['Data_entry'] === "Complete") {
            print "Instrument status set to complete. Run with confirm to set to in progress.\n";
        }
    }

    /**
     * Run the script updating the survey or instrument status accordingly.
     *
     * @param string $test_name   the instrument name
     * @param string $pscid       the candidate pscid
     * @param string $visit_label the visit label
     */
    function run($test_name, $pscid, $visit_label) {
        $instrumentStatus = $this->getInstrumentStatus($test_name, $pscid, $visit_label);

        $commentID  = $instrumentStatus['CommentID'];
        $surveyInfo = $this->getSurveyInfo($commentID);

        print "Updating survey status.\n";
        $this->SQLDB->update(
            "participant_accounts",
            array("Status" => "In Progress"),
            array("CommentID" => $commentID)
        );

        if ($instrumentStatus['Data_entry'] === "Complete") {
            print "Updating instrument status.\n";
            $this->SQLDB->update(
                "flag",
                array(
                    "Data_entry"     => "In Progress",
                    "Administration" => "None"
                ),
                array("CommentID" => $commentID)
            );
        }
    }
}

if(!class_exists('UnitTestCase')) {
    $Runner = new ModifySurveyStatus();

    if (count($argv) < 4 || count($argv) > 5 || $argv[1] == 'help') {
        $Runner->showHelp();
    }

    if (count($argv) === 5 && $argv[4] === 'confirm') {
        $Runner->run($argv[1], $argv[2], $argv[3]);
    } else {
        $Runner->dryRun($argv[1], $argv[2], $argv[3]);
    }
}
