<?php
/**
 *  Fix the subproject for a candidate timepoint/visit
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


    $candid            = $argv[1];
    $session_id        = $argv[2];
    $new_subproject_id = $argv[3];

$confirm = false;
if (!empty($argv[4]) && $argv[4] == 'confirm') {
    $confirm = true;
}
// php fix_timepoint_subject.php <candid><session_id><subprojectid>
function getSubProjects($subid)
{
    $db = Database::singleton();
    $subproject_name = $db->pselectOne(
        "select sp.title 
         from subproject sp
         where sp.SubprojectID = :spid ",
         array("spid" => $subid)
    );
    return $subproject_name;
}

$old_subid = $db->pselectOne(
    "select s.SubprojectID 
     from session s
     where s.CandID = :cid AND s.ID = :sid",
     array(
     "cid" => $candid,
     "sid" => $session_id,
    )
);
if ($confirm) {
    $db->update(
        'session',
        array('SubprojectID' => $new_subproject_id),
        array('id' => $session_id)
    );
}

if (!$confirm) {
    $old_subid_name =getSubProjects($old_subid);
    $new_subid_name =getSubProjects($new_subproject_id);
    print "\nCandidate $candid with session $session_id now has SubprojectID $old_subid($old_subid_name).\n Run this tool again with the argument 'confirm' to " .
        "update the SubprojectID to $new_subproject_id($new_subid_name) for the above information\n";
} else {
    print "\nThe SubprojectID is updated\n";
}






