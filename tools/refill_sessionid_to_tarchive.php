<?php
/**
 *  Back populate the session Id missed in tarchive table for old scans
 *
 *  PHP Version 7
 *
 *  @category Tools
 *  @package  Tools
 *  @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
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

$confirm =false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}

echo "All NULL SessionIDs (for old scans) in tarchive table will be refilled with the corresponding SessionID from the patient name available.\n";

// The visit label and candid can be extracted from the patient name except for the phantom scans.
// The phantom patient name is as stored as visit label in session table.So more easy to get session id if available

$results = $db->pselect(
                    "SELECT 
                    tr.PatientName,
                    CASE
                    when(PatientName LIKE 'SEA%' OR PatientName LIKE 'PHI%' OR PatientName LIKE 'STL%' OR PatientName LIKE 'DCC%' OR PatientName LIKE 'UNC%') 
                    THEN SUBSTR(tr.PatientName,9,6)
                    END as cand,
                    CASE 
                    WHEN (PatientName LIKE 'SEA%'  OR PatientName LIKE 'PHI%' OR PatientName LIKE 'STL%' OR PatientName LIKE 'DCC%' OR  PatientName LIKE 'UNC%')
                    THEN SUBSTR(tr.PatientName,16,3)
                    END as vt
                    FROM tarchive tr where tr.SessionID IS NULL and tr.PatientName!=:notEmpty",
                    array('notEmpty' => '')
);
print "Obtaining the SessionIDs from the available data\n";
foreach ($results as $r) {

    if($r['cand'] == null && $r['vt'] == null)
    {
        $session_id= $db->pselectOne(
            "SELECT s.ID
             FROM session s where s.Visit_label=:vtl",
             array('vtl' => $r['PatientName'])
        );
        if(empty($session_id))
        {
            print "{$r['PatientName']} SESSION NOT FOUND \n";
        }
        else {

            print "{$r['PatientName']} PHANTOM SCAN- SessionID ({$session_id})\n";
        }
    }
    else{
        $session_id= $db->pselectOne(
            "SELECT s.ID
             FROM session s where s.Visit_label=:vtl and s.CandID=:cid",
             array(
                'vtl' => $r['vt'],
                'cid' => $r['cand'],
            )
        );
        if(empty($session_id))
        {
            print "{$r['PatientName']} SESSION NOT FOUND \n";
        }
        else {
            print "{$r['PatientName']}- {$r['cand']}- {$r['vt']}- SessionID ({$session_id})\n";
        }
    }


    if (empty($session_id)) {
        if ($confirm) {
           print " Session ID not found for the Patient {$r['PatientName']}. So cannot be inserted\n" ;
        }
    } else {
        if ($confirm) {

            $db->update(
                'tarchive',
                array(
                    'SessionID'      => $session_id,
                ),
                array(
                    'PatientName'     => $r['PatientName'],

                )
            );
        }
    }
}

if (!$confirm) {
    print "\nRun this tool again with the argument 'confirm' to " .
        "insert the obtained SessionID to the the tarchive table.\n";
} else {
    print "\nFinished. Hope no more null SessionIDs in tarchive table as we move forward.\n";
}
