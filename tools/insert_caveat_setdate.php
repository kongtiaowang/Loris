<?php
/**
 * This script inserts caveat set date from history to candidate table
 * @author   Sruthy Mathew
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @version  GIT: <git_id>
 * @link     https://www.github.com/aces/IBIS/
 */

set_include_path(get_include_path() . ":" . __DIR__ . "/../libraries:" . ":" . __DIR__ . "/../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";
require_once "../../php/libraries/NDB_Client.class.inc";
require_once "../../php/libraries/NDB_Config.class.inc";
require_once "../../php/libraries/ConflictDetector.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();
$config = NDB_Config::singleton();
$db = Database::singleton();

echo "*****THIS SCRIPT FETCHES CAVEAT SET DATE FROM HISTORY AND ADD TO CANDIDATE TABLE*****\n";


//The count Where caveat flag is set but no flagged_date found";
$date_missing_count = $db->pselectOne(
    "SELECT COUNT(*)  FROM candidate WHERE flagged_caveatemptor='true' AND flagged_date IS NULL",
    array()
);

echo " FOUND " . $date_missing_count . " ENTRIES. PREPARING TO INSERT DATES FROM HISTORY TABLE.......\n";
$date_missing = $db->pselect(
    "SELECT CandId, PSCID FROM candidate WHERE flagged_caveatemptor='true' and flagged_date IS NULL",
    array()
);
echo "INSERTING FOUND DATES IN HISTORY TO CANDIDATE TABLE";
$count = 0;
foreach ($date_missing as $missing) {
    echo ".";
    //As in history table  primaryVals contains candid and dccid in one column  like (1234,dcc1234)
    $cand_vals = $missing['CandId'] . "," . $missing['PSCID'];
    $date_found_count = $db->pselectOne(
        "SELECT COUNT(*) FROM history WHERE tbl='candidate' AND col='flagged_caveatemptor'AND new ='true'
         AND primaryVals=:cand_vals",
        array('cand_vals' => $cand_vals)
    );
    if ($date_found_count == 1) {
        $count++;
        $date_found = $db->pselect(
            "SELECT changeDate as caveatdate FROM history WHERE tbl='candidate'AND col='flagged_caveatemptor'AND new ='true'
             AND primaryVals=:cand_vals",
            array('cand_vals' => $cand_vals)
        );
        foreach ($date_found as $caveatdate) {
            $vals = array('flagged_date' => $caveatdate['caveatdate']);
            $Where = array('CandID' => $missing['CandId']);
            $result = $db->update('candidate', $vals, $Where);
        }


    }

}

echo $count . " UPDATED.\n";
echo "YOU ARE DONE\n";


?>