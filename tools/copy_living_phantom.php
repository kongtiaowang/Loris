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
set_include_path(get_include_path().":/var/www/loris/project/libraries:/var/www/loris/php/libraries:");

require_once '/var/www/loris/vendor/autoload.php';
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
$client->initialize('/var/www/loris/project/config.xml');

$db = Database::singleton();

$files = $db->pselect("SELECT c.CandID, c.PSCID, c.IBISID, c.CandidateGUID,
    c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label,
    s.Current_stage, f.File, fqc.QCStatus, c.Gender
    FROM files f
    LEFT JOIN files_qcstatus fqc USING (FileID)
    LEFT JOIN session s ON (s.ID=f.SessionID)
    LEFT JOIN candidate c on (c.CandID=s.CandID)
    LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
    WHERE f.File like \"%living_phantom%\"
    and (f.AcquisitionProtocolID=44 or f.AcquisitionProtocolID=45)
    ORDER BY c.PSCID", array());

$base_dir = "/data/not_backed_up/"; // was "/home/gluneau/pinch/"
$target_dir = "Phantom_MINCS";  // WHERE f.File not like \"%DTI65%\" // (1, 2, 3, 4, 5, 7, 9, 10) <-- default
// $target_dir = "DTI65_Minc";  // WHERE f.File like \"%DTI65%\"  //  (1, 2, 3, 4, 5, 7, 9, 10)
// $target_dir = "DTI_SubP_4_5";  // WHERE s.SubprojectID IN (4, 5)
//$target_dir = "swarfield/dti";  // (3, 10)
// and from_unixtime(f.InsertTime) > '2014-01-01 01:01:01'

foreach($files as $row) {
    //$file = explode("/", $row["File"]);
    //     copy("/data/ibis/data/" . $row["File"], "/home/gluneau/pinch/clement/" .  $file[5]);

    $file = str_replace("assembly/","", $row["File"]);
    $subfile = substr($file, 0, strrpos($file, '/', -2) + 1 );
    createPath($base_dir . $target_dir . "/" . $subfile);

    if (file_exists($base_dir . $target_dir ."/" .  $file)) {
        print "s:";
    } else {
        copy("/data/ibis/data/" . $row["File"], $base_dir . $target_dir ."/" .  $file);
        print "n:";
    }

    print "/data/ibis/data/" . $row["File"] . "\n";
}
