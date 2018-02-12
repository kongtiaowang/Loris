<?php
/**
 * This script adds the timepoint to the specified candidate.
 *
 * Add timepoint rows for a given candidate
 * echo "Usage: php add_timepoint.php add_timepoint CandID PSCID SubprojectID CenterID VisitLabel";
 * echo "Example: php add_timepoint.php add_timepoint 965327 dcc0007 1 1 V24";

 *
 * PHP Version 7
 *
 * @category Tools
 * @package  Tools
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @version  GIT: <git_id>
 * @link     https://www.github.com/aces/IBIS/
 */

set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once '../../vendor/autoload.php';
$actions = array('add_timepoint');
//define the command line parameters
if (count($argv) < 6 || $argv[1] == 'help' || !in_array($argv[1], $actions)) {
    showHelp();
}

// set default arguments
$action    = $argv[1];
$CandID     = $argv[2];
$PSCID     = $argv[3];
$subprojectID = $argv[4];
$centerID = $argv[5];
$visitLabel = $argv[6];

// get the rest of the arguments
switch ($action) {
    case 'add_timepoint':
        if (empty($argv[6])) {
            echo "Missing Visit Label parameter\n\n";
            showHelp();
        }
        break;
    default:
        showHelp();
        break;
}

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');
$DB =& Database::singleton();
/*
 * Perform validations on arguments
 */
$candExists = $DB->pselectOne(
    "SELECT COUNT(*) 
      FROM candidate 
      WHERE CandID = :cid AND PSCID = :pid AND Active ='Y'",
    array(
        'cid' => $CandID,
        'pid' => $PSCID,
    )
);
if ($candExists == 0) {
    echo "\nThe candidate with CandID : $CandID  and PSCID : $PSCID either does ".
        "not exist in the database or is set to Active='N' state.\n\n";
    die();
}
if ($visitLabel != null) {
    $vLExists = $DB->pselectOne(
        "SELECT COUNT(*) FROM session WHERE CandID=:cid AND Visit_label=:visitLabel AND SubprojectID=:subprojectID AND Active ='Y'",
        array(
            'cid' => $CandID,
            'visitLabel' => $visitLabel,
            'subprojectID' => $subprojectID
        )
    );
    if ($vLExists > 0) {
        echo "Visit Label $visitLabel for candidate $CandID already exists for the ".
             "specified subproject in the database or is set to Active='N' state.\n\n";
        die();
    }
}

/*
 * The switch to execute actions
 */
switch ($action) {
    case 'add_timepoint':
        addTimepoint($CandID, $PSCID, $visitLabel, $subprojectID, $centerID, $DB);
        break;
}
/*
 * Prints the usage and example help text and stop program
 */
function showHelp()
{
    echo "*** Add Timepoint ***\n\n";
    echo "Usage: php add_timepoint.php add_timepoint CandID PSCID SubprojectID CenterID VisitLabel\n";
    echo "Example: php add_timepoint.php add_timepoint 965327 dcc0007 1 1 V24\n\n";
    die();
}

function addTimepoint($CandID, $PSCID, $visitLabel, $subprojectID, $centerID, $DB) {
    $num_visits = $DB->pselectOne(
        "SELECT COUNT(*) FROM session WHERE CandID=:cid",
        array(
            'cid' => $CandID,
        )
    );
    $DB->insert(
        'session',
        array(
            'CandID' => $CandID,
            'Visit_label' => $visitLabel,
            'SubprojectID' => $subprojectID,
            'CenterID' => $centerID,
            'VisitNo' => $num_visits + 1,
            'Submitted' => 'N',
            'Current_Stage' => 'Not Started'
        )
    );
}
