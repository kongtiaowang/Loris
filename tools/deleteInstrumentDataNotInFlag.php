<?php
/**
 *  Delete Instrument data from the instrument table where it is already deleted from flag.Unsyc data should be removed to keep in balance.
 *
 *  PHP Version 7
 *
 *  @category Tools
 *  @package  Tools
 *  @author   Sruthy Mathew
 *  @link     https://www.github.com/aces/IBIS/
 **/
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');
$db = Database::singleton();

$confirm = false;
if (!empty($argv[2]) && $argv[2] == 'confirm') {
    $confirm = true;
}

// php deleteInstrumentDataNotInFlag.php edi/edi2

$instrument = $argv[1];
if (empty($argv[1]) || $argv[1] == 'help') {
    fwrite(STDERR, "Usage: \n\n");
    fwrite(STDERR, "deleteInstrumentDataNotInFlag.php <instrument_name>\n");
    return;
}
$results = $db->pselect(
    "SELECT instr.CommentID as cmid
FROM {$instrument} instr
WHERE instr.CommentID NOT IN
    (SELECT CommentID 
     FROM flag where Test_name=:test_name)",
    array(
        "test_name" => $instrument,
    )
);

if (!empty($results)) {
    $results_count = $db->pselectOne(
        "SELECT COUNT(*)
FROM {$instrument} instr
WHERE CommentID NOT IN
    (SELECT CommentID 
     FROM flag where Test_name=:test_name)",
        array(
            "test_name" => $instrument,
        )
    );
    echo $results_count." Unsync CommentIds found in this instrument table which is not in flag table\n";
    foreach ($results as $row) {

            print "{$row['cmid']}\n";

        if ($confirm) {
            print "\n Deleting this CommentID {$row['cmid']}\n";
            $DB->delete($instrument, array('CommentID' => $row['cmid']));
        }

    }
} else {
    print "No such mismatching CommentIds found. The instrument table  and flag table seems to be in sync. Exiting\n";
    exit;
}

if (!$confirm) {
    print "\nRun this tool again with the argument 'confirm' to " .
        "move the instrument data.\n";
} else {
    print "\nThe move is complete.\n";
}
