<?php

// Dumps the database instruments and some accompanying information into Excel formatted files.
// For some large tables, this script requires *a lot* of memory.  Modify the `cli` php.ini for > 256M

// Operation:
// Passes the results from one or more SQL queries to the writeExcel function.

// Future improvements:
// The SQL to pull the instrument data rely on some nastry text matching (ie. where c.PSCID not like '1%').  Ideally, this junk could be purged directly from the DB, and the SQL made more plain.

require_once "generic_includes.php";
require_once 'Spreadsheet/Excel/Writer.php';
require_once "Archive/Tar.php";
require_once "Utility.class.inc";
//Configuration variables for this script, possibly installation dependent.
//$dataDir = "dataDump" . date("dMy");
$dumpName       = "dataDump" . date("dMy"); // label for dump
$config         = NDB_Config::singleton();
$paths          = $config->getSetting('paths'); print_r($paths);
$dataDir        = $paths['base'] . "tools/$dumpName/"; //temporary working directory
$destinationDir = $paths['base'] . "htdocs/dataDumps"; //temporary working directory

$factory        = NDB_Factory::singleton();
$DB             = $factory->database();

/*
* Prepare output/tmp directories, if needed.
*/
//Create
if(!file_exists($dataDir)) {
	mkdir($dataDir);
}
//Create
if(!file_exists($destinationDir)) {
        mkdir($destinationDir);
}

//Delete all previous files.
$d = dir($dataDir);
while($entry = $d->read()) {
	if ($entry!= "." && $entry!= "..") {
		unlink($dataDir . "/" . $entry);
	}
}
$d->close();

//Substites words for number in ProjectID data field
function MapProjectID(&$results){
    $projects = Utility::getProjectList();
    for($i = 0; $i < count($results); $i++){
       if(!empty($results[$i])) {
           $results[$i]["ProjectID"] = $projects[$results[$i]["ProjectID"]];
       }
    }
    return $results;
}

//Substitute words for numbers in Subproject data field
function MapSubprojectID(&$results) {
    global $config;
    $subprojectLookup = array();
    // Look it up from the config file, because it's not stored
    // in the database
    //$study = $config->getSetting('study');
    //foreach($study["subprojects"]["subproject"] as $subproject) {
	//    $subprojectLookup[$subproject["id"]] =  $subproject["title"];
    //}
    
    // new way of getting subprojects
    global $DB;
    $subprojects = $DB->pselect("SELECT * FROM subproject", array());
    foreach ($subprojects as $row) {
       $subprojectLookup[$row['SubprojectID']] = $row['title'];
    }
    
    print_r($subprojectLookup);
    //print_r($results[1]);
    //1exit;
    
    for ($i = 0; $i < count($results); $i++) {
       if(!empty($results[$i]) && !empty($subprojectLookup[$results[$i]["SubprojectID"]])) {
	    $results[$i]["SubprojectID"] = 
                $subprojectLookup[$results[$i]["SubprojectID"]];
       }
    }
    return $results;
}

/*
* Start with all the instrument tables
*/
//Get the names of all instrument tables
$query = "select * from test_names order by Test_name";
//$query = "select * from test_names where Test_name like 'a%' order by Test_name";  //for rapid testing
$DB->select($query, $instruments);

print_r($instruments);
// exit;
// $instruments = array();


foreach ($instruments as $instrument) {
	//Query to pull the data from the DB
	$Test_name = $instrument['Test_name'];
    if($Test_name == 'prefrontal_task') {

	    $query = "select c.PSCID, c.CandID, s.SubprojectID, s.Visit_label, s.Submitted, s.Current_stage, s.Screening, s.Visit, f.Administration, e.full_name as Examiner_name, f.Data_entry, 'See validity_of_data field' as Validity, i.* from candidate c, session s, flag f, participant_status ps, $Test_name i left outer join examiners e on i.Examiner = e.examinerID where c.PSCID not like 'dcc%' and c.PSCID not like '0%' and c.PSCID not like '1%' and c.PSCID not like '2%' and c.PSCID != 'scanner' and i.CommentID not like 'DDE%' and c.CandID = s.CandID and s.ID = f.sessionID and f.CommentID = i.CommentID AND c.Active='Y' AND s.Active='Y' AND c.CenterID IN (2, 3, 4, 5) AND ps.CandID=c.CandID order by s.Visit_label, c.PSCID";

    } else if ($Test_name == 'radiology_review') {
        $query = "select c.PSCID, c.CandID, s.SubprojectID, s.Visit_label, s.Submitted, s.Current_stage, s.Screening, s.Visit, f.Administration, e.full_name as Examiner_name, f.Data_entry, f.Validity, 'Site review:', i.*, 'Final Review:', COALESCE(fr.Review_Done, 0) as Review_Done, fr.Final_Review_Results, fr.Final_Exclusionary, fr.Final_Incidental_Findings, fre.full_name as Final_Examiner_Name, fr.Final_Review_Results2, fre2.full_name as Final_Examiner2_Name, fr.Final_Exclusionary2, COALESCE(fr.Review_Done2, 0) as Review_Done2, fr.Final_Incidental_Findings2, fr.Finalized from candidate c, session s, flag f,participant_status ps, $Test_name i left join final_radiological_review fr ON (fr.CommentID=i.CommentID) left outer join examiners e on (i.Examiner = e.examinerID) left join examiners fre ON (fr.Final_Examiner=fre.examinerID) left join examiners fre2 ON (fre2.examinerID=fr.Final_Examiner2) where c.PSCID not like 'dcc%' and c.PSCID not like '0%' and c.PSCID not like '1%' and c.PSCID not like '2%' and c.PSCID != 'scanner' and i.CommentID not like 'DDE%' and c.CandID = s.CandID and s.ID = f.sessionID and f.CommentID = i.CommentID AND c.Active='Y' AND s.Active='Y' AND ps.CandID=c.CandID order by s.Visit_label, c.PSCID";
    } else {
        if (is_file("../project/instruments/NDB_BVL_Instrument_$Test_name.class.inc") || is_file("../project/instruments/$Test_name.linst")) {
            $instrument =& NDB_BVL_Instrument::factory($Test_name, '', false);
            $extra_fields ='';
            if($instrument->ValidityEnabled == true) {
                $extra_fields = 'f.Validity, ';
            }
            $ddeInstruments = $config->getSetting("DoubleDataEntryInstruments");
            print_r($ddeInstruments);
            if(in_array($Test_name, $ddeInstruments)) {
                $extra_fields .= "CASE ddef.Data_entry='Complete' WHEN 1 then 'Y' 
                                                                 WHEN  NULL then 'Y' 
                                                                 ELSE 'N' 
                                    END AS DDE_Complete, 
                                 CASE WHEN EXISTS (SELECT 'x' FROM conflicts_unresolved cu WHERE i.CommentID=cu.CommentId1 OR i.CommentID=cu.CommentId2) THEN 'Y' ELSE 'N' END AS conflicts_exist, ";
            }
	        $query = "select c.PSCID, c.CandID, s.SubprojectID, s.Visit_label, s.Submitted, s.Current_stage, s.Screening, s.Visit, f.Administration, e.full_name as Examiner_name, f.Data_entry, $extra_fields i.* from candidate c, session s, flag f,participant_status ps, $Test_name i left outer join examiners e on i.Examiner = e.examinerID left join flag ddef ON (ddef.CommentID=CONCAT('DDE_', i.CommentID)) WHERE c.PSCID not like 'dcc%' and c.PSCID not like '0%' and c.PSCID not like '1%' and c.PSCID not like '2%' and c.PSCID != 'scanner' and i.CommentID not like 'DDE%' and c.CandID = s.CandID and s.ID = f.sessionID and f.CommentID = i.CommentID AND c.Active='Y' AND  s.Active='Y' AND c.CenterID IN (2, 3, 4, 5) AND ps.CandID=c.CandID order by s.Visit_label, c.PSCID";

        } else {
            $query = "select c.PSCID, c.CandID, s.SubprojectID, s.Visit_label, s.Submitted, s.Current_stage, s.Screening, s.Visit, f.Administration, e.full_name as Examiner_name, f.Data_entry, f.Validity, i.* from candidate c, session s, flag f,participant_status ps, $Test_name i left outer join examiners e on i.Examiner = e.examinerID where c.PSCID not like 'dcc%' and c.PSCID not like '0%' and c.PSCID not like '1%' and c.PSCID not like '2%' and c.PSCID != 'scanner' and i.CommentID not like 'DDE%' and c.CandID = s.CandID and s.ID = f.sessionID and f.CommentID = i.CommentID AND c.Active='Y' AND s.Active='Y' AND  c.CenterID IN (2, 3, 4, 5) AND ps.CandID=c.CandID order by s.Visit_label, c.PSCID";
        }
    }
	$DB->select($query, $instrument_table);

    MapSubprojectID($instrument_table);
    if ($Test_name == 'tsi') {
        foreach ($instrument_table as &$row) {
            unset($row['father_dob_date']);
            unset($row['father_dob_date_status']);
            unset($row['mother_dob_date']);
            unset($row['mother_dob_date_status']);
        }
    }
	writeExcel($Test_name, $instrument_table, $dataDir);

} //end foreach instrument

/*
* Special figs_year3_relatives query
*/
//check if figs table exists

$query = "SHOW TABLES LIKE 'figs_year3_relatives'";
$DB->select($query,$result);
if (count($result) > 0) {
	$Test_name = "figs_year3_relatives";
	$query = "select c.PSCID, c.CandID, s.SubprojectID, s.Visit_label, fyr.* from candidate c, session s, flag f, participant_status ps,figs_year3_relatives fyr where c.PSCID not like 'dcc%' and fyr.CommentID not like 'DDE%' and c.CandID = s.CandID and s.ID = f.sessionID and f.CommentID = fyr.CommentID AND c.Active='Y' AND s.Active='Y' AND ps.CandID=c.CandID order by s.Visit_label, c.PSCID";
	$DB->select($query, $instrument_table);
	if(PEAR::isError($instrument_table)) {
		print "Cannot figs_year3_relatives data ".$instrument_table->getMessage()."<br>\n";
		die();
	}
	MapSubprojectID($instrument_table);
	writeExcel($Test_name, $instrument_table, $dataDir);
}

/*
* Candidate Information query
*/
$Test_name = "candidate_info";
//this query is a but clunky, but it gets rid of all the crap that would otherwise appear.
$query = "SELECT DISTINCT c.PSCID, c.CandID, c.Gender, c.DoB, ROUND(DATEDIFF(NOW(),c.DoB)/(365/12)) as Candidate_Age, s.SubprojectID, c.ProjectID, pc.Value as Plan, c.EDC, pc1.Value as Comments, c.flagged_caveatemptor as Caveat_Emptor, c.flagged_info as Caveat_Emptor_reason, c.flagged_other as Caveat_Emptor_detail, c.ProbandGender, c.ProbandDoB,ROUND(DATEDIFF(c.DoB, c.ProbandDoB) / (365/12)) AS Age_difference,ps.ndar_consent from candidate c LEFT JOIN session s ON (c.CandID = s.CandID) LEFT JOIN parameter_candidate pc ON (c.CandID = pc.CandID AND pc.ParameterTypeID=73754) LEFT JOIN parameter_candidate pc1 ON (c.CandID = pc1.CandID AND pc1.ParameterTypeID=7296) LEFT JOIN participant_status ps ON (ps.CandID=c.CandID) WHERE c.CenterID IN (2,3,4,5) AND c.Active='Y'  AND s.Active='Y' ORDER BY c.PSCID";
$DB->select($query, $results);

foreach($results as &$result) {
    $result['FamilyID']= '';
    for ($i = 1; $i<=3; $i++) {
        $result['Sibling'.$i] = "";
        $result['Relationship_type_Sibling'.$i] = "";
    }
    $familyID     = $DB->pselectOne("SELECT FamilyID FROM family
                                     WHERE CandID=:cid",
                                     array('cid'=>$result['CandID']));

    if (!empty($familyID)) {
        $result['FamilyID']=$familyID;
        $familyFields = $DB->pselect("SELECT candID as Sibling_ID,
                Relationship_type as Relationship_to_sibling
                FROM family
                WHERE FamilyID=:fid AND CandID<>:cid",
                array('fid'=>$familyID, 'cid'=>$result['CandID']));
        $num_siblings = 1;
        if (!empty($familyFields)) {
            foreach($familyFields as $row) {
                //adding each sibling id and relationship to the file
                $result['Sibling'.$num_siblings]                     = $row['Sibling_ID'];
                $result['Relationship_type_Sibling'.$num_siblings]   = $row['Relationship_to_sibling'];
                $num_siblings                                       += 1;
            }
        }
    }
}
MapProjectID($results);
MapSubprojectID($results);
writeExcel($Test_name, $results, $dataDir);

/*Demographics information query*/
$Test_name = "demographics";
$fieldsInQuery = "SELECT c.CandID, c.PSCID, s.Visit_label, s.SubprojectID, p.Alias as Site, c.Gender,ROUND(DATEDIFF(NOW(),c.DoB)/(365/12)) as Candidate_age, s.Current_stage, CASE WHEN s.Visit='Failure' THEN 'Failure' WHEN s.Screening='Failure' THEN 'Failure' WHEN s.Visit='Withdrawal' THEN 'Withdrawal' WHEN s.Screening='Withdrawal' THEN 'Withdrawal' ELSE 'Neither' END as Failure, c.ProjectID, c.flagged_caveatemptor as CEF, c.flagged_caveatemptor as CEF, c_o.Description as CEF_reason, c.flagged_other as CEF_comment, pc_comment.Value as Comment, pso.Description as Status, ps.participant_suboptions as Status_reason, ps.reason_specify as Status_comments";
        $tablesToJoin = " FROM session s JOIN candidate c USING (CandID) LEFT JOIN psc p ON (p.CenterID=s.CenterID) LEFT JOIN caveat_options c_o ON (c_o.ID=c.flagged_reason) LEFT JOIN parameter_candidate AS pc_comment ON (pc_comment.CandID=c.CandID) AND pc_comment.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE Name='candidate_comment') LEFT JOIN participant_status ps ON (ps.CandID=c.CandID) LEFT JOIN participant_status_options pso ON (pso.ID=ps.participant_status)";
        // If proband fields are being used, add proband information into the query
        if ($config->getSetting("useProband") === "true") {
            $probandFields = ", c.ProbandGender as Gender_proband, ROUND(DATEDIFF(c.DoB, c.ProbandDoB) / (365/12)) AS Age_difference";
            $fieldsInQuery .= $probandFields;
        }
        // If expected date of confinement is being used, add EDC information into the query
        if ($config->getSetting("useEDC") === "true") {
            $EDCFields = ", c.EDC as EDC";
            $fieldsInQuery .= $EDCFields;
        }
        $concatQuery = $fieldsInQuery . $tablesToJoin . " WHERE s.Active='Y' AND c.Active='Y' AND c.PSCID <> 'scanner'";
$DB->select($concatQuery, $results);

MapProjectID($results);
MapSubprojectID($results);
writeExcel($Test_name, $results, $dataDir);

/*MRI Data*/
$Test_name = "mri_data";
$ScanTypes = $DB->pselect("SELECT DISTINCT pf.ParameterTypeID, pf.Value as ScanType from parameter_type pt JOIN parameter_file pf USING (ParameterTypeID) WHERE pt.Name='selected' AND COALESCE(pf.Value, '') <> ''", array());
$Query = "SELECT c.PSCID, s.Visit_label, s.ID as SessionID, fmric.Comment
                  as QCComment";
        foreach ($ScanTypes as $Scan) {
            $Query .= ", (SELECT f.File FROM files f LEFT JOIN files_qcstatus fqc 
                      USING(FileID)
                      LEFT JOIN parameter_file p
                      ON (p.FileID=f.FileID 
                      AND p.ParameterTypeID=$Scan[ParameterTypeID])
                      WHERE f.SessionID=s.ID AND p.Value='$Scan[ScanType]' LIMIT 1) 
                            as `Selected_$Scan[ScanType]`, (SELECT fqc.QCStatus 
                      FROM files f LEFT JOIN files_qcstatus fqc USING(FileID)
                      LEFT JOIN parameter_file p ON (p.FileID=f.FileID 
                      AND p.ParameterTypeID=$Scan[ParameterTypeID]) 
                      WHERE f.SessionID=s.ID AND p.Value='$Scan[ScanType]' LIMIT 1)
                             as `$Scan[ScanType]_QCStatus`";
        }
        $Query .= " FROM session s JOIN candidate c USING (CandID) 
                    LEFT JOIN feedback_mri_comments fmric 
                    ON (fmric.CommentTypeID=7 AND fmric.SessionID=s.ID)
                    LEFT JOIN participant_status ps ON (ps.CandID=c.CandID) 
                    LEFT JOIN participant_status_options pso ON (pso.ID=ps.participant_status)
                    WHERE c.PSCID <> 'scanner' AND c.PSCID NOT LIKE '%9999' 
                    AND c.Active='Y' AND s.Active='Y' AND c.CenterID <> 1";
$DB->select($Query, $results);

MapProjectID($results);
MapSubprojectID($results);
writeExcel($Test_name, $results, $dataDir);

/*
* Data Dictionary construction
* This relies on the quickform_parser and data_dictionary_builder having being recently run
*/
$Test_name = "DataDictionary";
$query = "select Name, Type, Description, SourceField, SourceFrom from parameter_type where SourceField is not null order by SourceFrom";
$DB->select($query, $dictionary);

writeExcel($Test_name, $dictionary, $dataDir);

// Clean up
// tar and gzip the product
$tarFile = $dumpName . ".tgz"; // produced dump file name and extension
$tar = new Archive_Tar($tarFile, "gz");
$tar->add("./$dumpName/")
or die ("Could not add files!");

// mv (or as php calls it, 'rename') to a web-accessible pickup directory
rename("./$tarFile", "$destinationDir/$tarFile"); //change, if not a subdirectory

// rm left-over junk, from all that excel file generation.
delTree($dataDir);

// Announce completion
echo "$tarFile ready in $destinationDir\n";




/**
 * Takes a 2D array and saves it as a nicely formatted Excel spreadsheet.
 * Metadata columns are preserved, multiple worksheets are used, when appropriate and headers are maintained.
 *
 * @param string	$Test_name	File name to be used.
 * @param unknown_type $instrument_table 	A 2D array of the data to be presented in Excel format
 * @param unknown_type $dataDir The  output directory.
 */
function writeExcel ($Test_name, $instrument_table, $dataDir) {
	//Modifiable parameters
	//    $metaCols = array("PSCID", "CandID", "Visit_label", "Examiner_name", "Data_entry_completion_status", "Date_taken"); //metadata columns
	$junkCols = array("CommentID", "UserID", "Examiner", "Testdate", "Data_entry_completion_status"); //columns to be removed
        
    $filename = "$dataDir/$Test_name.csv";
    $fd = fopen($filename, 'w+');
    if($fd === FALSE) {
        exit(-1);
    }
	//ensure non-empty result set
	if (count($instrument_table) ==0) { //empty result set
		echo "Empty: $Test_name  [Contains no data]\n";
		return; // move on to the next instrument //nothing to save
	}

	//remove any undesired columns that came in from the DB query.
	for ($i = 0; $i < count($instrument_table); $i++) {
		if (is_array($instrument_table[$i])) {
			$instrument_table[$i] = array_diff_key($instrument_table[$i], array_flip($junkCols));
		}
	}

	$headers = array_keys($instrument_table[0]);
        fputcsv($fd, $headers);	

	// add data to worksheet
	foreach ($instrument_table as $row) {
             fputcsv($fd, $row);	
	}

    fclose($fd);
} //end function writeExcel

/**
 * PHP equivalent of `rm -rf`
 * This function stolen from PHP manual
 * @param string dir Directory to be recursively deleted, ending with a slash
 *
 */
function delTree($dir) {
	$files = glob( $dir . '*', GLOB_MARK );
	foreach( $files as $file ){
		if( substr( $file, -1 ) == '/' ) {
			delTree( $file );
		} else {
			unlink( $file );
		}
	}
	if (is_dir($dir)) rmdir( $dir );
}

?>
