<?php
/**
*
* Need to mount pinch first: gluneau@nihace:~$ ./mount_pinch.sh
*
* PHP Version 5.5.9
*
*  @category Main
*  @package  copy-dti
*  @author   Gregory Luneau <gregory.luneau@mcgill.ca>
*  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
*  @version  GIT: <git_id>
*  @link     https://www.github.com/aces/IBIS/
**/
set_include_path(get_include_path().":../libraries:../../php/libraries:");

require_once '../../vendor/autoload.php';
require_once "NDB_Client.class.inc";
require_once "Utility.class.inc";
require_once "Candidate.class.inc";

/**
*
* @param int $num The column number
*
* @return string $letter The excel column name in letters
*
**/
function createPath($path) {
    if (is_dir($path)) return true;
    $prev_path = substr($path, 0, strrpos($path, '/', -2) + 1 );
    $return = createPath($prev_path);
    return ($return && is_writable($prev_path)) ? mkdir($path) : false;
}

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db = Database::singleton();

$files = $db->pselect("SELECT c.CandID, c.PSCID, c.IBISID, c.CandidateGUID,
    c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label,
    s.Current_stage, f.File, fqc.QCStatus, c.Sex
    FROM files f
    LEFT JOIN files_qcstatus fqc USING (FileID)
    LEFT JOIN session s ON (s.ID=f.SessionID)
    LEFT JOIN candidate c on (c.CandID=s.CandID)
    LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
    WHERE s.SubprojectID IN (1, 2, 3, 4, 5, 7, 9, 10)
    AND (ps.study_consent != 'no' OR ps.study_consent is null)
    AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00')
    AND f.File like \"%t1%\"
    AND fqc.QCStatus = \"Pass\"
    ORDER BY c.PSCID", array());

//$target_dir = "DTI_Minc";  // WHERE f.File not like \"%DTI65%\" // (1, 2, 3, 4, 5, 7, 9, 10) <-- default
$target_dir = "T1_Minc_Pass";  // WHERE f.File like \"%DTI65%\"  //  (1, 2, 3, 4, 5, 7, 9, 10)
// $target_dir = "DTI_SubP_4_5";  // WHERE s.SubprojectID IN (4, 5)
//$target_dir = "swarfield/dti";  // (3, 10)

foreach($files as $row) {
    //$file = explode("/", $row["File"]);
    //     copy("/data/ibis/data/" . $row["File"], "/home/gluneau/pinch/clement/" .  $file[5]);

    $file = str_replace("assembly/","", $row["File"]);
    createPath("/home/gluneau/pinch/". $target_dir ."/" . substr($file, 0, strrpos($file, '/', -2) + 1 ));

    if (file_exists("/home/gluneau/pinch/". $target_dir ."/" .  $file)) {
        print "s:";
    } else {
        copy("/data/ibis/data/" . $row["File"], "/home/gluneau/pinch/". $target_dir ."/" .  $file);
        print "n:";
    }

    print "/data/ibis/data/" . $row["File"] . "\n";
}
