<?php

/**
 * A script that generates a data dump for IBIS in a .tar.gz archive.
 * This dump will contain a CSV file for each the following:
 * - Data for all instruments, except air_pollution
 * - Data for figs_year3_relatives
 * - Final radiology review data
 * - parameter_candidate info for parameter 'candidate_plan'
 *
 * When validity is enabled for a given instrument, the CSV file will
 * contain validity information (from table flag) for that instrument.
 * When DDE is enabled for an instrument, the CSV file will contain
 * the current conflicts for that instrument.
 *
 * Only a specific set of candidates is considered (see $SITES).
 */
require_once __DIR__ . '/../../vendor/autoload.php';
require_once __DIR__ . '/../../tools/generic_includes.php';
require_once 'Archive/Tar.php';
require_once 'Utility.class.inc';

// These columns will not be written to the CSV files
$COLUMNS_TO_DELETE = array(
    "CommentID",
    "UserID",
    "Examiner",
    "Testdate",
    "Data_entry_completion_status"
);

// Consider only candidates that belong to these sites
$SITES = "'SEA', 'PHI', 'STL', 'UNC'";

// Basename for the final tar file
$dumpBaseName   = sprintf("IBISdataDump%s", date('dMy'));
$config         = NDB_Config::singleton();
$paths          = $config->getSetting('paths');

// Directory where all CSV files are written
$csvDir         = "{$paths['base']}/tools/$dumpBaseName/";
// Directory in which to write the final tar file
$tarDir         = "{$paths['base']}/modules/data_release/user_uploads/csv";

//------------------------------------------------//
// Create working directory, if needed.           //
// -----------------------------------------------//
if(!file_exists($csvDir)) {
    if(!mkdir($csvDir)) {
        die("Failed to create directory $csvDir\n");
    }
}
//------------------------------------------------//
// Delete content of temporary working directory  //
// if it already exists                           //
// -----------------------------------------------//
else
{
    $d = dir($csvDir);
    while($entry = $d->read()) {
        if ($entry!= "." && $entry!= "..") {
            unlink("$csvDir/$entry");
        }
    }
    $d->close();
}

//--------------------------------------------
// Get list of all test_names (instruments)
//--------------------------------------------
$query = "
   SELECT * 
   FROM test_names
   ORDER BY Test_name
";
$instruments = $DB->pselect($query, array());

$defaultSelect   = "SELECT c.PSCID, c.CandID, prj.Name AS Project,"
                 . " sub.title as Subproject, s.Visit_label, s.Submitted, s.Current_stage, s.Screening, s.Visit,"
                 . " f.Administration, f.Data_entry";

$defaultJoin = "JOIN flag f ON (f.commentid=i.commentid) "
             . "JOIN session s ON (s.id=f.sessionid) "
             . "JOIN candidate c ON (c.candid=s.candid) "
             . "JOIN psc p ON (p.centerid=c.RegistrationCenterID) "
             . "JOIN Project prj ON (prj.projectid=c.projectid) "
             . "JOIN subproject sub ON (sub.subprojectid=s.subprojectid)";

$defaultWhere = "WHERE c.Entity_type = 'Human' "
              . "AND c.Active='Y' "
              . "AND s.Active='Y' "
              . "AND p.Name IN ($SITES) "
              . "AND i.commentid not like 'DDE%'";

foreach ($instruments as $instrument) {
    $testName = $instrument['Test_name'];
    if($testName == 'air_pollution') {
        echo "\033[31mWarning! Instrument $testName contains encoded data: skipped.\033[39m\n";
        continue;
    }
    if(!$DB->tableExists($testName)){
        print("Table '$testName' not found in database. Skipped.\n");
        continue;
    }

    $select = $defaultSelect;
    $join   = $defaultJoin;
    if (!$instrument['IsDirectEntry']) {
        print "Instrument $testName is not direct entry: using examiners\n";
        $select .= ", e.full_name AS Examiner_name";
        $join   .= " LEFT OUTER JOIN examiners e ON (i.Examiner=e.examinerID)";
    }

    switch($testName) {
        //-------------------------------------------//
        // For prefrontal_task, the validity         //
        // is in a column of the instrument itself   //
        //-------------------------------------------//
        case 'prefrontal_task':
            $select .= ", 'See validity_of_data field' AS Validity";
            break;

        //------------------------------------------------//
        // For radiology_review, also add the associated  //
        // info from table final_radiological_review      //
        //------------------------------------------------//
        case 'radiology_review':
            $select .= ", f.Validity, 'Site review:'"
                    .  ", 'Final Review:', COALESCE(fr.Review_Done, 0) AS Review_Done"
                    .  ", fr.Final_Review_Results, fr.Final_Exclusionary, fr.SAS, fr.PVS"
                    .  ", fr.Final_Incidental_Findings, fre.full_name AS Final_Examiner_Name"
                    .  ", fr.Final_Review_Results2, fre2.full_name AS Final_Examiner2_Name"
                    .  ", fr.Final_Exclusionary2, COALESCE(fr.Review_Done2, 0) AS Review_Done2"
                    .  ", fr.SAS2, fr.PVS2, fr.Final_Incidental_Findings2, fr.Finalized";

            $join   .= "LEFT JOIN final_radiological_review fr ON (fr.CommentID=i.CommentID) "
                    .  "LEFT JOIN examiners fre ON (fr.Final_Examiner=fre.examinerID) "
                    .  "LEFT JOIN examiners fre2 ON (fre2.examinerID=fr.Final_Examiner2)";
            break;
        default:
            $select     = "$defaultSelect";
            $classFile  = "{$paths['base']}/project/instruments/NDB_BVL_Instrument_$testName.class.inc";
            if (is_file($classFile)) {
                require_once "$classFile";
                $className = "NDB_BVL_Instrument_$testName";

                // Stolen from NDB_BVL_Instrument.class.inc:
                // The module directory we use for instruments is arbitrary,
                // since it isn't a real module, but it's required for the page
                // constructor.
                $testClass = new $className (
                    new Module($testName, "{$paths['base']}/project"), '', '', '', ''
                );

                // If validity is enabled for that instrument, fetch
                // the validity status from table flag for that instrument
                if($testClass->ValidityEnabled == true) {
                    $select .= ', f.Validity';
                }

                // If DDE is set for that instrument, report DDE completion status
                // and whether conflicts exist
                $ddeInstruments = $config->getSetting('DoubleDataEntryInstruments');
                if(in_array($testName, $ddeInstruments)) {
                    $select       .= ", CASE ddef.Data_entry='Complete' "
                                  .  "    WHEN 1 THEN 'Y' "
                                  .  "    WHEN NULL THEN 'Y' "
                                  .  "    ELSE 'N' "
                                  .  "    END AS DDE_Complete";

                    $select       .= ", CASE WHEN EXISTS ("
                                  .  "    SELECT 'x' "
                                  .  "    FROM conflicts_unresolved cu "
                                  .  "    WHERE i.CommentID=cu.CommentId1 "
                                  .  "    OR i.CommentID=cu.CommentId2"
                                  .  "  ) THEN 'Y' ELSE 'N' "
                                  .  "  END AS conflicts_exist";

                    $join         .= "LEFT JOIN flag ddef "
                                  .  "ON (ddef.CommentID=CONCAT('DDE_', i.CommentID))";
                }
            }
    }   # switch

    $select .= ", i.*";
    $query = "$select FROM $testName i $join $defaultWhere ORDER BY s.Visit_label, c.PSCID ";
    $data = $DB->pselect($query, array());
    writeCSV($testName, $data, $csvDir);
} //end foreach instrument

//---------------------------------------------------------//
// Create CSV file for figs_year3_relatives table          //
//---------------------------------------------------------//
$query = "SELECT c.PSCID, c.CandID, sub.title AS Subproject, s.Visit_label, i.* "
       . "FROM figs_year3_relatives i "
       . "$defaultJoin "
       . "$defaultWhere "
       . "ORDER BY s.Visit_label, c.PSCID";
$data = $DB->pselect($query, array());
if(empty($data)) {
    die(sprintf("Cannot retrieve figs_year3_relatives table data: %s\n", $data->getMessage()));
}
writeCSV('figs_year3_relatives', $data, $csvDir);

//-----------------------------------------------------------------//
// Fetch value of 'candidate_plan' from table parameter_candidate  //
// for all candidates of interest                                  //
//-----------------------------------------------------------------//
$query = "SELECT c.PSCID, c.CandID, c.Sex, c.DoB, p.name AS Project, pc_with_plan.Value as Plan, c.EDC "
       . "FROM candidate c "
       . "LEFT JOIN ( "
       . "   SELECT pc.candid, pc.value "
       . "   FROM parameter_candidate pc "
       . "   JOIN parameter_type pt ON (pc.parametertypeid=pt.parametertypeid) "
       . "   WHERE pt.name='candidate_plan' "
       . ") pc_with_plan ON (pc_with_plan.candid=c.candid) "
       . "JOIN Project p ON (c.projectid=p.projectid) "
       . "JOIN psc ON (psc.centerid=c.RegistrationCenterID) "
       . "WHERE c.Entity_type = 'Human' "
       . "AND c.Active='Y' "
       . "AND psc.Name IN ($SITES) "
       . "AND EXISTS( "
       . "  SELECT 1 "
       . "  FROM session s "
       . "  WHERE s.candid=c.candid "
       . "  AND s.active='Y' "
       . ") "
       . "ORDER BY c.PSCID";

$data = $DB->pselect($query, array());
if (empty($data)) {
    die(sprintf("Couldn't get 'candidate_plan' from parameter_candidate: %s\n", $data->getMessage()));
}
writeCSV('candidate_info', $data, $csvDir);

//--------------------------------------------//
// Data Dictionary construction               //
// This relies on the quickform_parser and    //
// data_dictionary_builder having being       //
// recently run                               //
//--------------------------------------------//
$query = "
    SELECT Name, Type, Description, SourceField, SourceFrom
    FROM parameter_type
    WHERE SourceField IS NOT NULL
    ORDER BY SourceFrom
";
$data = $DB->pselect($query, array());
if (empty($data)) {
    die(sprintf("Could not generate IBIS data dictionary: %s\n", $data->getMessage()));
}
writeCSV('IBISDataDictionary', $data, $csvDir);

//----------------------------------------//
// Create a tar file of all the CSV files //
// generated so far                       //
//----------------------------------------//
$tarFileName = "$dumpBaseName.csv.tgz";
$tar = new Archive_Tar("$tarDir/$tarFileName", 'gz');
if(!$tar->add($csvDir)) {
    die("Failed to archive contents of '$csvDir' in '$tarDir/$tarFileName'\n");
}

echo "Wrote file $tarDir/$tarFileName\n";

//----------------------------------------------------------------------------------------//
//                                        Functions                                       //
//----------------------------------------------------------------------------------------//

/**
 * Takes the data retrieved from the database for a given test name (instrument)
 * and writes it to a CSV file.
 * 
 * @param string $testName Name of the test (or instrument).
 * @param array  $data 	   A 2D array of the test data.
 * @param string $csvDir   Directory in which to write the CSV file.
 */
function writeCSV($testName, $data, $csvDir) {
    // Print warning and return if empty result set
    if (count($data) == 0) {
        echo "\033[31mWarning! $testName contains no data: skipped.\033[39m\n";
        return;
    }

    // Remove unwanted columns
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] = array_diff_key($data[$i], array_flip($GLOBALS['COLUMNS_TO_DELETE']));
    }

    $fp = fopen("$csvDir/$testName.csv", "w");

    // Write the column headers
    $headers = array_keys($data[0]);
    fputcsv($fp, $headers);

    // Write data for each row
    foreach ($data as $row) {
        // When IBIS PR#1496 is merged and script instrument_double_escape_fix.php is run, the
        // following line should be replaced by the commented line under it
        $row = preg_replace("/&amp;(amp;)*/", '&', $row);
        // $row = preg_replace("/&amp;/"       , '&', $row);
        $row = preg_replace("/&gt;/"        , '>', $row);
        $row = preg_replace("/&lt;/"        , '<', $row);
        $row = preg_replace("/&quot;/"      , '"', $row);

        fputcsv($fp, $row);
    }
    fclose($fp);
    echo "Wrote $csvDir/$testName.csv\n";
}

?>
