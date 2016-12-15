<?php
/**
 * This script allows recreation of conflicts
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Rathi Sekaran <sekaranrathi@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

set_include_path(get_include_path().":".__DIR__."/../libraries:".":".__DIR__."/../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";
require_once "../../php/libraries/NDB_Client.class.inc";
require_once "../../php/libraries/NDB_Config.class.inc";
require_once "../../php/libraries/ConflictDetector.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();

$config = NDB_Config::singleton();
$db     = Database::singleton();

echo "Warning: All conflicts for instruments with Administration=None will be removed.\n";

/**
 * HELP SCREEN
 * display and stop processing if action=help
 */
if (empty($argv[1]) || $argv[1] == 'help') {
    fwrite(STDERR, "Usage: \n\n");
    $case1 ="recreate_conflicts.php all         : To recreate".
        "conflicts for all instruments\n";
    $case2 = "recreate_conflicts.php <test_name> : To recreate".
        "conflict for a given instrument \n";

    fwrite(
        STDERR,
        $case1
    );
    fwrite(
        STDERR,
        $case2
    );
    return;
}

/**
 * Get cmd-line arguments
 */
// get $action argument
$action         = $argv[1];

if ($action=='all') {
    $allInstruments = Utility::getAllInstruments();
    $ddeInstruments = $config->getSetting('DoubleDataEntryInstruments');
} else {
    $allInstruments = array($action => $action);
    $ddeInstruments = array($action => $action);
}
// clear the unresolved conflicts for all the instruments
foreach ($allInstruments as $instrument=>$Full_name) {
    $clear_conflicts = $db->pselect(
        "SELECT CommentID, Test_name,
                                            CONCAT('DDE_', CommentID)
                                            AS DDECommentID
                                     FROM flag
                                     JOIN session s ON (s.ID=flag.SessionID)
                                     JOIN candidate c ON (c.CandID=s.CandID)
                                     WHERE Test_name=:testname AND CommentID
                                           NOT LIKE 'DDE%' AND s.Active='Y'
                                           AND c.Active='Y'",
        array('testname' => $instrument)
    );
    echo "\nClearing conflicts for $Full_name.\n";
    foreach ($clear_conflicts as $conflict) {
        echo".";
        ConflictDetector::clearConflictsForInstance($conflict['CommentID']);
    }
}
echo "\nRecording unresolved conflicts.\n";
foreach ($ddeInstruments as $test) {
    $instruments = $db->pselect(
        "SELECT CommentID, Test_name, CONCAT('DDE_',
                                        CommentID) AS DDECommentID
                                 FROM flag sde
                                 JOIN session s ON (s.ID=sde.SessionID)
                                 JOIN candidate c ON (c.CandID=s.CandID)
                                 WHERE sde.Test_name=:testname AND sde.CommentID
                                       NOT LIKE 'DDE%' AND sde.Data_entry='Complete'
                                       AND s.Active='Y' AND c.Active='Y'
                                       AND EXISTS (SELECT 'x' FROM flag dde WHERE
                                           dde.CommentID=CONCAT('DDE_',sde.CommentID)
                                       AND Data_entry='Complete')",
        array('testname' => $test)
    );

    foreach ($instruments as $instrument) {
        echo ".";
        // If the instrument requires double data entry, check that DDE is also done
        if (in_array($instrument['Test_name'], $ddeInstruments)) {
            print "Recreating conflicts for " . $instrument['Test_name'] .
                ':'. $instrument['CommentID'] . "\n";
            $diff = ConflictDetector::detectConflictsForCommentIds(
                $instrument['Test_name'],
                $instrument['CommentID'],
                $instrument['DDECommentID']
            );
            ConflictDetector::recordUnresolvedConflicts($diff);
        }
    }
}

echo "\nRemoving conflicts where Administration=None.\n";
// Remove conflicts where the instrument's Administration is set to 'none'
$db->run("DELETE cu FROM conflicts_unresolved cu LEFT JOIN flag f ON (cu.CommentId1=f.CommentID) WHERE f.Administration='None'");
$db->run("DELETE cu FROM conflicts_unresolved cu LEFT JOIN flag f ON (cu.CommentId2=f.CommentID) WHERE f.Administration='None'");

echo "\nFinished.\n";

?>