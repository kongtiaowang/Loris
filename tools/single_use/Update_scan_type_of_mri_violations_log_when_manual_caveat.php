<?php
/**
 * This script is written for a one time use only to update the scan_type
 * previously not inserted into the mri_violations_log table when manually
 * setting the caveat MRI QC flag to true in the imaging browser.
 *
 * This script updates the scan_type field mri_violations_log based on the
 * SeriesUID for each caveat flag reported manually when QCing images.
 *
 * affected table:
 * - mri_violations_log
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Loris
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  Loris license
 * @link     https://github.com/aces/Loris
 */
require_once __DIR__ . '/../generic_includes.php';

// select all SeriesUID missing data from mri_violations_log
$db = $lorisInstance->getDatabaseConnection();
$seriesUIDs_list = selectManualCaveat($db);
// loop through all SeriesUID to update the MriScanTypeID field in
// mri_violations_log
foreach ($seriesUIDs_list as $seriesUID) {
    updateScanType($seriesUID['SeriesUID'], $db);
}

/**
 * Selects all SeriesUIDs for which MriScanTypeID is set to NULL and Headers set
 * to "Manual Caveat Set by%" in the mri_violations_log.
 *
 * @return array of seriesUID without MriScanTypeID set in mri_violations_log
 * @throws DatabaseException
 */
function selectManualCaveat($db)
{
    $query = "SELECT DISTINCT(SeriesUID) 
              FROM mri_violations_log 
              WHERE HEADER LIKE \"Manual Caveat Set by%\" 
              AND MriScanTypeID IS NULL";

    $result = $db->pselect($query, []);

    return $result;
}

/**
 * Select the scan type associated to the SeriesUID in the files table and
 * updates the mri_violations_log table with found scan type if only one scan
 * type was found for the SeriesUID. Otherwise, prints proper message for the
 * user.
 *
 * @param string $seriesUID SeriesUID
 *
 * @return nothing
 * @throws DatabaseException
 */
function updateScanType($seriesUID, $db)
{
    // select scan type for the SeriesUID given as an argument
    $scan_type_list = $db->pselectCol(
        "SELECT MriScanTypeID FROM files WHERE SeriesUID=:seriesUID",
        ['seriesUID' => $seriesUID]
    );

    // update mri_violations_log if only one scan type found
    if (count($scan_type_list) == 1) {
        $scan_type = $scan_type_list[0];
        print "Updating scan type to $scan_type for SeriesUID $seriesUID \n";
        $db->update(
            'mri_violations_log',
            ['MriScanTypeID'=>$scan_type],
            ['SeriesUID'=>$seriesUID]
        );
    } elseif (count($scan_type_list) == 0) {
        print "Could not find any scan type for SeriesUID $seriesUID \n";
    } else {
        print "Found more than one scan type for SeriesUID $seriesUID\n";
    }
}


