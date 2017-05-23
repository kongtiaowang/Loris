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

//$instrument = "ibq_r";
// $instrument = "aosi";
$fromcid = $argv[1];
$tocid = $argv[2];
$instrument = $argv[3];


$fresults = $db->pselect(
    "select s.ID as sID, s.Visit_label as sVisit_label, f.CommentID as fCommentID, 
      i.Data_entry_completion_status 
      from candidate as c
      join session as s on s.CandID=c.CandID
      join flag as f on f.SessionID=s.ID
      join {$instrument} as i on i.CommentID =f.CommentID 
      where c.PSCID = :cpscid",
    array("cpscid" => $fromcid)
);

$tresults = $db->pselect(
    "select s.ID as sID, s.Visit_label as sVisit_label, f.CommentID as fCommentID, 
      i.Data_entry_completion_status 
      from candidate as c
      join session as s on s.CandID=c.CandID
      join flag as f on f.SessionID=s.ID
      join {$instrument} as i on i.CommentID =f.CommentID 
      where c.PSCID = :cpscid",
    array("cpscid" => $tocid)
);

// To candidate instrument created?
if (!empty($tresults)) {
    foreach ($tresults as $row) {
        if ($row['Data_entry_completion_status'] != 'Incomplete') {
            print "The 'To' candadate has data that in not marked Incomplete!  Exiting";
            exit;
        }
    }
} else {
    print "create new CommentID since none exist";
    exit;
}


foreach ($fresults as $row) {
    print "{$instrument}-{$row['sID']}-{$row['sVisit_label']}-{$row['fCommentID']}";


    print "\n";

} // foreach candidate/visit


