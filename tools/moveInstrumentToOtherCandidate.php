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
// php moveInstrumentToOtherCandidate.php UNC0236_55555_V06 UNC0235_444444_V06 aosi
list($frpid, $frcid, $frvl) = explode("_", $argv[1]);
list($topid, $tocid, $tovl) = explode("_", $argv[2]);
$instrument = $argv[3];


$fresults = $db->pselect(
    "select s.ID as sID, s.Visit_label as sVisit_label, f.CommentID as fCommentID, 
      i.Data_entry_completion_status 
      from candidate as c
      join session as s on s.CandID=c.CandID
      join flag as f on f.SessionID=s.ID
      join {$instrument} as i on i.CommentID =f.CommentID 
      where c.PSCID = :cpscid AND s.Visit_label = :svlbl",
    array(
     "cpscid" => $frpid,
     "svlbl"  => $frvl,
    )
);

$tresults = $db->pselect(
    "select s.ID as sID, s.Visit_label as sVisit_label, f.CommentID as fCommentID, 
      i.Data_entry_completion_status 
      from candidate as c
      join session as s on s.CandID=c.CandID
      join flag as f on f.SessionID=s.ID
      join {$instrument} as i on i.CommentID =f.CommentID 
      where c.PSCID = :cpscid AND s.Visit_label = :svlbl",
    array(
     "cpscid" => $topid,
     "svlbl"  => $tovl,
    )
);

// 'To' candidate instrument created?
if (!empty($tresults)) {
    foreach ($tresults as $row) {
        if ($row['Data_entry_completion_status'] != 'Incomplete') {
            print "The 'To' candadate has data that in not marked Incomplete!  
              Exiting";
            exit;
        }


    }
} else {
    print "create new CommentID since none exist";
    exit;
}



foreach ($fresults as $f) {
    print "{$instrument}-{$f['sID']}-{$f['sVisit_label']}-{$f['fCommentID']}\n";

    foreach ($tresults as $t) {
        if ((substr($f['fCommentID'], 0, 3) == 'DDE'
            and substr($t['fCommentID'], 0, 3) == 'DDE')
            or (substr($f['fCommentID'], 0, 3) !== 'DDE'
            and substr($t['fCommentID'], 0, 3) !== 'DDE')
        ) {
            print "\t{$instrument}-{$t['sID']}-
            {$t['sVisit_label']}-{$t['fCommentID']}\n";

            // delete incomplete data 'To'
            $DB->delete($instrument, array('CommentID' => $t['fCommentID']));
            // update instrument data from 'From' CommentID to 'To'
            $DB->update(
                $instrument,
                array('CommentID' => $t['fCommentID']),
                array('CommentID' => $f['fCommentID'])
            );

            // delete incomplete flag data 'To'
            $DB->delete('flag', array('CommentID' => $t['fCommentID']));
            // update flag data with the from 'From' CommentID and sID to the To
            $DB->update(
                'flag',
                array(
                 'CommentID' => $t['fCommentID'],
                 'SessionID' => $t['SessionID'],
                ),
                array('CommentID' => $f['fCommentID'])
            );
        }
    }

    print "\n";

} // foreach candidate/visit


