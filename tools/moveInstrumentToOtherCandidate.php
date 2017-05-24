<?php
/**
*  Move instrument data from one candidate to another
*
*  PHP Version 7
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

$confirm = false;
if (!empty($argv[4]) && $argv[4] == 'confirm') {
    $confirm = true;
}

// $instrument = "ibq_r";
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
              Exiting\n";
            exit;
        }
    }
} else {
    print "Create new Session and/or CommentID since none exist.\n";
    exit;
}


foreach ($fresults as $f) {
    print "from-{$instrument}-{$f['sID']}-" .
    "{$f['sVisit_label']}-{$f['fCommentID']}\n";

    foreach ($tresults as $t) {
        if ((substr($f['fCommentID'], 0, 3) == 'DDE'
            and substr($t['fCommentID'], 0, 3) == 'DDE')
            or (substr($f['fCommentID'], 0, 3) !== 'DDE'
            and substr($t['fCommentID'], 0, 3) !== 'DDE')
        ) {
            print "\tto-{$instrument}-{$t['sID']}-" .
            "{$t['sVisit_label']}-{$t['fCommentID']}\n";

            // delete incomplete data 'To'
            print "\t\tDeleting 'To' instrument {$instrument} " .
            "for this CommentID {$t['fCommentID']}\n";
            if ($confirm) {
                $DB->delete($instrument, array('CommentID' => $t['fCommentID']));
            }
            // update instrument data from 'From' CommentID to 'To'
            print "\t\tUpdate the 'From' instrument CommentID " .
            "from {$f['fCommentID']} to {$t['fCommentID']}\n";
            if ($confirm) {
                    $DB->update(
                        $instrument,
                        array('CommentID' => $t['fCommentID']),
                        array('CommentID' => $f['fCommentID'])
                    );
            }

            // delete incomplete flag data 'To'
            print "\t\tDeleting 'To' flag entry for this " .
            "CommentID {$t['fCommentID']}\n";
            if ($confirm) {
                 $DB->delete('flag', array('CommentID' => $t['fCommentID']));
            }
            // update flag data with the from 'From' CommentID and sID to the To
            print "\t\tUpdate the 'From' flag CommentID and sID from " .
            "{$f['fCommentID']} to {$t['fCommentID']} and {$f['sID']} to ".
            "{$t['sID']}\n";
            if ($confirm) {
                $DB->update(
                    'flag',
                    array(
                     'CommentID' => $t['fCommentID'],
                     'SessionID' => $t['sID'],
                    ),
                    array('CommentID' => $f['fCommentID'])
                );
            }
        }
    }
}

if (!$confirm) {
    print "\nRun this tool again with the argument 'confirm' to " .
        "move the instrument data.\n";
} else {
    print "\nThe move is complete.\n";
}
