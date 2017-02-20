<?php

/**
 * This script, given a SeriesUID, will detect how many scans share the same
 * SeriesUID and prompt for which one you'd like to keep, deleting all the
 * others.
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
require_once "generic_includes.php";

//define the command line parameters
if (count($argv)!=2) {
    echo "Usage: php $argv[0]  [SeriesUID]\n";
    die();
} else {
    $SeriesUID= $argv[1];
}

$files = $DB->pselect(
    "SELECT f.FileID, c.PSCID, s.Visit_label, fqc.QCStatus 
    FROM files f LEFT JOIN files_qcstatus fqc USING (FileID) 
        LEFT JOIN session s ON (s.ID=f.SessionID) 
        LEFT JOIN candidate c ON (c.CandID=s.CandID) 
    WHERE f.SeriesUID=:SID",
    array('SID' => $SeriesUID)
);

/**
 * Callback function to extract the FileID from an array using array_map
 *
 * @param array $row A row from a database query involving FileID
 *
 * @return The fileID 
 */
function extractFID($row)
{
    return $row['FileID'];
}
$fileIDs = array_map('extractFID', $files);

if (count($files) === 0) {
    print "File does not appear to be in database.\n";
    die();
}

if (count($files) === 1) {
    print "No duplicates found, only one scan with SeriesUID.\n";
    die();
}

$i = 1;
print "\tFileID\tPSCID\tVisit_label\tQCStatus\n";

foreach ($files as $file) {
    print "$i:\t$file[FileID]\t$file[PSCID]\t$file[Visit_label]\t$file[QCStatus]\n";
    $i += 1;
}

print "\nEnter FileID you would like to delete (one at a time) or Ctrl-D"
   . " to finish.\n";

$SelectedID = $DB->pselectOne("SELECT ParameterTypeID FROM parameter_type WHERE Name='Selected'", array());
function getSelected($FileID) {
    global $DB, $SelectedID;
    $val = $DB->pselectOne("SELECT pf.Value FROM parameter_file pf WHERE pf.FileID=:FID AND pt.ParameterTypeID=:SID", array('FID' => $FileID, 'SID' => $SelectedID));

    if(empty($val)) {
        return '';
    }

    return $val;
} 
function getCaveat($FileID) {
    global $DB;
    $val = $DB->pselectOne("SELECT Caveat FROM files WHERE FileID=:FID", array('FID' => $FileID));

    if(empty($val)) {
        return false;
    }

    return $val;
}

while (!feof(STDIN)) {
    print "\nFileID: ";
    $FileID = trim(fgets(STDIN));


    if (!is_numeric($FileID)) {
        print "Invalid FileID.\n";
        continue;
    }

    if (!in_array($FileID, $fileIDs)) {
        print "FileID $FileID is not for this SeriesUID.\n";
        continue;
    }

    
    print "\nDELETING FileID $FileID\n";
    $selected = getSelected($FileID);
    $caveat   = getCaveat($FileID);
    $DB->delete("files", array('FileID' => $FileID));
    $DB->delete("parameter_file", array('FileID' => $FileID));
    
    print "Selected status: $selected\n";

    $moveQC = '';
    do {
        print "Move QC (Y/N)? ";
        $moveQC = trim(fgets(STDIN));
    } while ($moveQC !== 'Y' && $moveQC !== 'N');

    if ($moveQC === 'Y') {
        $fileIDs = array_values(array_diff($fileIDs, array($FileID)));

        $nextFileID = $fileIDs[0];
        print "Updating QCStatus for $SeriesUID to point to remaining files. " .
            "Mapping to FileID $nextFileID.\n";

        $DB->update(
            "files_qcstatus",
            array('FileID' => $nextFileID),
            array('SeriesUID' => $SeriesUID)
        );

        $DB->update('files', array('Caveat' => $caveat), array('FileID' => $nextFileID));

        $DB->delete("parameter_file", array('ParameterTypeID' => $SelectedID, 'FileID' => $nextFileID));
        $DB->insert("parameter_file", array('ParameterTypeID' => $SelectedID, 'FileID' => $nextFileID, 'Value' => $selected));

        
    }

}
?>
