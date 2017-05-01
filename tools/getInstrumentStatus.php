<?php
/**
*  Show all instrument not started by project and site
*
*  PHP Version 5
*
*  @category Tools
*  @package  Tools
*  @author   Gregory Luneau <gregory.luneau@mcgill.ca>
*  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
*  @version  GIT: <git_id>
*  @link     https://www.github.com/aces/IBIS/
**/
set_include_path(get_include_path().":../libraries:../../php/libraries:");

require_once '../../vendor/autoload.php';

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db = Database::singleton();

/* $argv[1] is ProjectID
 * 1 IBIS1
 * 2 IBIS2
 * 3 Fragile X
 * 4 EARLI
 * 5 Down's Syndrome
 */

/* $argv[2] is CenterID
 * 2 SEA
 * 3 PHI
 * 4 STL
 * 5 UNC
 */

/* SELECT DISTINCT Data_entry FROM flag
 * NULL
 * In Progress
 * Complete
 */

if (isset($argv[1]) && isset($argv[2])) {
    $confirm = true;
} else {
    $confirm = false;
}


if (empty($argv[1])) {
    $ProjectID = "";
} else {
    $ProjectID = "AND c.ProjectID={$argv[1]} ";

    if (empty($argv[2])) {
        $CenterID = "";
    } else {
        $CenterID = "AND c.CenterID={$argv[2]} ";
    }
}


$instruments = $db->pselect(
    "SELECT * FROM test_names AS t 
                             ORDER BY t.Test_name",
    array()
);
// CSV Headers
print "PSCID-VisitLabel";
foreach ($instruments as $ins) {
    print ", {$ins['Test_name']}";
}

print "\n";

$result = $db->pselect(
    "SELECT *, c.PSCID as CPSCID FROM candidate AS c 
                        JOIN session AS s USING (CandID)
                        WHERE c.Entity_type='Human' {$ProjectID} {$CenterID} 
                        ORDER BY c.PSCID, s.Visit_label",
    array()
);


foreach ($result as $row) {
    print "{$row['CPSCID']}-{$row['Visit_label']}";

    foreach ($instruments as $ins) {
        $status = $db->pselectRow(
            "SELECT * FROM flag AS f 
                               WHERE f.SessionID=:sid AND f.Test_name=:tnm",
            array(
             'sid' => $row['ID'],
             'tnm' => $ins['Test_name'],
            )
        );

        if (empty($status)) {
            // You're here because there is no flag entry
            // for this instrument and that session
            print ", ";

        } else {
            if ($status['Data_entry'] == "") {
                print ", NS";

            } else {
                // You could print the "In Progress" or "Complete" status here
                // print ", {$status['Data_entry']}";
            }
        }
    } // foreach instrument
    print "\n";

} // foreach candidate/visit


