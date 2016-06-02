<?php
/**
 * Returns the queries for IBIS LG Calls
 *
 *  @category Main
 *  @package  LGQuery
 *  @author   Stella Lee
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 *  @version  GIT: <git_id>
 *  @link     https://www.github.com/aces/IBIS/
 */

set_include_path(get_include_path() . ":../libraries:../../php/libraries:../../php/libraries/Classes:");
require_once __DIR__ . "/../../vendor/autoload.php";
require_once "NDB_Client.class.inc";
require_once "Utility.class.inc";
require_once "Database.class.inc";

include 'PHPExcel/IOFactory.php';

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db =& Database::singleton();

// Set date for output file titles
// Month_Dayth_Year
$date = date("F_d") . "_" . date("Y");
$date2 = date("F d, Y");

print "\nStella's Automated IBIS Large Group Call Number Generating Script!!!\n";

echo date('Y/m/d H:i:s'), "\n\n";

$previousDate = readline("What is the date of previous query? (Month Day, Year) ");
$previousHR = readline("What was the previous total TOTAL HR RECRUITS w. Mullens (V03+V06nr)? ");
$previousLR = readline("What was the previous total TOTAL LR RECRUITS w. Mullens (V03+V06nr)? ");

// Create a new PHPExcel Object
$ExcelApplication = new PHPExcel();
// Removing builtin sheet make it easier to use same function to add sheets later
$ExcelApplication->removeSheetByIndex(0);


IBIS2($previousDate, $previousHR, $previousLR);
//bySite();

$fileType = 'Excel2007';
$outputFileName = "IBIS_LG_Call_Status_$date.xlsx";

// Writing the excel file out
$writer = PHPExcel_IOFactory::createWriter($ExcelApplication, $fileType);
$writer->save($outputFileName);

print "Done writing file $outputFileName\n\n";


/*
 *
 * IBIS 2 OVERALL
 *
 */
function IBIS2($previousDate, $previousHR, $previousLR)
{

    global $db, $ExcelApplication, $date2;

    $name = 'Overall';

    $ExcelWorkSheet = new PHPExcel_Worksheet($ExcelApplication, $name);
    $ExcelApplication->addSheet($ExcelWorkSheet, -1);

    $visitLabels = array("V03", "V06 new", "V06", "V09", "V12", "V15", "V24", "V36", "");

    $column = 'A';
    $row = '2';
    // Set Database Date
    $ExcelWorkSheet->setCellValue($column . $row, '');
    $ExcelWorkSheet->setCellValue($column . $row++, 'FROM DB ' . $date2);

    // Populates Headers
    $ExcelWorkSheet->setCellValue($column . $row++, '');
    $ExcelWorkSheet->setCellValue($column . $row++, 'IBIS-2');
    $ExcelWorkSheet->setCellValue($column . $row++, 'Whole Network');
    $ExcelWorkSheet->setCellValue($column . $row++, 'IBIS-2 Recruits');

    // Populates Visit Labels
    for ($i = 0; $i < 2; $i++) {
        foreach ($visitLabels as $visitLabel) {
            $ExcelWorkSheet->setCellValue($column . $row++, $visitLabel);
        }
    }

    // Populates Remaining Headers
    $columnMRI = 'B';
    $columnBx = 'C';
    $row1 = 6;
    $row2 = 15;
    $ExcelWorkSheet->setCellValue($columnMRI . $row1, 'HR MRI');
    $ExcelWorkSheet->setCellValue($columnMRI . $row2, 'LR MRI');
    $ExcelWorkSheet->setCellValue($columnBx . $row1, 'HR Bx');
    $ExcelWorkSheet->setCellValue($columnBx . $row2, 'LR Bx');



    //Mullen - across visits and SubprojectIDs
    $IBIS2Q1a = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID, s.Visit_label
from flag as f, session as s
WHERE f.Test_name='mullen'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND s.Cancelled ='N'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1 AND s.Visit_label <> 'V06'
GROUP BY s.SubprojectID, s.Visit_label",
        array()
    );
    print "...";

    $IBIS2Q1b = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID, CASE
WHEN p.Value LIKE '3m%' THEN 'V06'
WHEN p.Value LIKE '6m%' THEN 'V06 new' END
as Visit_labelString from flag as f, session as s join candidate c on c.CandID=s.CandID
join parameter_candidate p on p.CandID=c.CandID WHERE f.Test_name='mullen'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND s.Cancelled ='N'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID
AND s.CenterID!=1
AND s.Visit_label ='V06'
AND p.ParameterTypeID=73754
GROUP BY s.SubprojectID, Visit_labelString",
        array()
    );
    print "...";


//MRI parameter Form T1=Complete- across visits and SubprojectIDs
    $IBIS2Q2a = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID, s.Visit_label from flag as f, session as s, mri_parameter_form as m
WHERE f.Test_name='mri_parameter_form'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID
AND s.CenterID!=1
AND m.CommentID=f.CommentID
AND m.T1_Scan_done='Complete'
AND s.Visit_label <> 'V06'
GROUP BY s.SubprojectID, s.Visit_label",
        array()
    );
    print "...";

    $IBIS2Q2b = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID,
CASE WHEN p.Value LIKE '3m%' THEN 'V06'
WHEN p.Value LIKE '6m%' THEN 'V06 new' END
as Visit_labelString from flag as f, session as s join candidate c on c.CandID=s.CandID
join parameter_candidate p on p.CandID=c.CandID , mri_parameter_form as m
WHERE f.Test_name='mri_parameter_form'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID
AND s.CenterID!=1
AND m.CommentID=f.CommentID
AND m.T1_Scan_done='Complete'
AND s.Visit_label = 'V06'
AND p.ParameterTypeID=73754
GROUP BY s.SubprojectID, Visit_labelString",
        array()
    );
    print "...\n";

    print_r($IBIS2Q2b);

    /*
     * ENTER NEW TABLE VALUES
     */
// HR MRI
    for ($row = 7; $row <= 9; $row++) {
        foreach ($IBIS2Q2b as $data) {
            if (($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_labelString']) && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
// HR MRI
    for ($row = 7; $row <= 14; $row++) {
        foreach ($IBIS2Q2a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
    print "...";
// LR MRI --> B16 to 22
    for ($row = 16; $row <= 18; $row++) {
        foreach ($IBIS2Q2b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_labelString'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
// LR MRI --> B16 to 22
    for ($row = 16; $row <= 22; $row++) {
        foreach ($IBIS2Q2a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
    print "...";
// HR Bx
    for ($row = 7; $row <= 9; $row++) {
        foreach ($IBIS2Q1b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_labelString'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
// HR Bx
    for ($row = 7; $row <= 14; $row++) {
        foreach ($IBIS2Q1a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
// LR Bx
    for ($row = 16; $row <= 18; $row++) {
        foreach ($IBIS2Q1b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_labelString'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
// LR Bx
    for ($row = 16; $row <= 22; $row++) {
        foreach ($IBIS2Q1a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct (s.CandID))']);
            }
        }
    }
    print "...";
// END ENTER NEW TABLES VALUES


    /*
     * SUMMARY
     */
    $HR_Bx_V03_curr = intval($ExcelWorkSheet->getCell('C7')->getValue());
    $HR_Bx_V06nr_curr = intval($ExcelWorkSheet->getCell('C8')->getValue());
    $LR_Bx_V03_curr = intval($ExcelWorkSheet->getCell('C16')->getValue());
    $LR_Bx_V06nr_curr = intval($ExcelWorkSheet->getCell('C17')->getValue());

    $total_LR_recruits_curr = $LR_Bx_V03_curr + $LR_Bx_V06nr_curr;
    $total_HR_recruits_curr = $HR_Bx_V03_curr + $HR_Bx_V06nr_curr;

    $LR_change = $total_LR_recruits_curr - $previousLR;
    $HR_change = $total_HR_recruits_curr - $previousLR;

    $ExcelWorkSheet
        ->setCellValue('A24', 'Recruitment change since ' . $previousDate . ':    +' . $HR_change . 'HR   +' . $LR_change . 'LR');
    print "...";

// Total HR Recruits
    $ExcelWorkSheet
        ->setCellValue('A25', "TOTAL HR RECRUITS w. Mullens (V03+V06nr)= $total_HR_recruits_curr");
    print "...";

// HR % Proposed
    $HR_target = 200;
    $HR_percent = round($total_HR_recruits_curr / $HR_target * 100, 1);
    $ExcelWorkSheet
        ->setCellValue('B25', "HR % PROPOSED : $HR_percent%");
    print "...";

// Total LR Recruits
    $ExcelWorkSheet
        ->setCellValue('A27', "TOTAL LR RECRUITS w. Mullens (V03+V06nr) = $total_LR_recruits_curr");
    print "...\n";

// LR % Proposed
    $LR_target = 60;
    $LR_percent = round($total_LR_recruits_curr / $LR_target * 100, 1);
    $ExcelWorkSheet
        ->setCellValue('B27', "LR % OF PROPOSED: $LR_percent%");
// END SUMMARY

    print "\nDone IBIS2 Overall.\n\n";
}


/*
 *
 * IBIS1 IBIS2 by Site
 *
 */
/*function bySite()
{
// Sets active sheet index to IBIS1 IBIS2 by Site
    $objPHPExcel->setActiveSheetIndex(1);

    print "IBIS1 IBIS2 By Site - In Progress.\n";

    $ExcelWorkSheet
        ->setCellValue('A1', 'FROM DB ' . $date2);
*/
    /*
     * ENTER NEW TABLE VALUES
     */
/*    print "Entering new values...";



//Mullen - across visits and SubprojectIDs
$IBIS1Q1 = $db->pselect("
SELECT count(distinct (s.CandID)),s.SubprojectID, s.Visit_label from flag as f, session as s
WHERE f.Test_name='mullen'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=1 OR s.SubprojectID=2 OR s.SubprojectID=3)
AND s.Active='Y' AND s.Cancelled ='N'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure'
    AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID
AND s.CenterID!=1
GROUP BY s.SubprojectID, s.Visit_label
ORDER BY s.SubprojectID",
    array()
);
print "...";


//MRI parameter Form T1=Complete- across visits and SubprojectIDs
$IBIS1Q2 = $db->pselect("
select count(distinct (s.CandID)),s.SubprojectID, s.Visit_label from flag as f, session as s, mri_parameter_form as m
WHERE f.Test_name='mri_parameter_form'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=1 OR s.SubprojectID=2 OR s.SubprojectID=3)
AND s.Active='Y' AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1 AND m.CommentID=f.CommentID
AND m.T1_Scan_done='Complete'
GROUP BY s.SubprojectID, s.Visit_label
ORDER BY s.SubprojectID",
    array()
);
print "...";

//MRI parameter Form T1=Complete- across visits and SubprojectIDs by Site
$IBIS1Q3 = $db->pselect("
select count(distinct (s.CandID)), s.CenterID, s.SubprojectID,s.Visit_label from flag as f, session as s, mri_parameter_form as m
WHERE f.Test_name='mri_parameter_form'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=1 OR s.SubprojectID=2 OR s.SubprojectID=3)
AND s.Active='Y' AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1
AND m.CommentID=f.CommentID
AND m.T1_Scan_done='Complete'
GROUP BY s.CenterID, s.SubprojectID, s.Visit_label
ORDER BY s.CenterID, s.Visit_label",
    array()
);
print "...";

//Mullen- across visits and Subprojects IDs by Site
$IBIS1Q4 = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID, s.Visit_label, s.CenterID from flag as f, session as s
WHERE f.Test_name='mullen'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=1 OR s.SubprojectID=2 OR s.SubprojectID=3)
AND s.Active='Y' AND s.Cancelled ='N'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1
GROUP BY s.SubprojectID, s.Visit_label, s.CenterID
ORDER BY s.SubprojectID",
    array()
);
print "...";


 * IBIS2




//MRI parameter Form T1=Complete- across visits and SubprojectIDs by Site
$IBIS2Q3a = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID, s.Visit_label, s.CenterID
from flag as f, session as s, mri_parameter_form as m
WHERE f.Test_name='mri_parameter_form'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1 AND m.CommentID=f.CommentID
AND m.T1_Scan_done='Complete'
AND s.Visit_label <> 'V06'
GROUP BY s.Visit_label, s.SubprojectID, s.CenterID
ORDER BY s.SubprojectID, s.Visit_label",
    array()
);
print "...";

$IBIS2Q3b = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID,
CASE WHEN p.Value LIKE '3m%' THEN 'V06'
WHEN p.Value LIKE '6m%' THEN 'V06 new' END
as Visit_labelString, s.CenterID from flag as f,
session as s join candidate c on c.CandID=s.CandID
join parameter_candidate p on p.CandID=c.CandID , mri_parameter_form as m
WHERE f.Test_name='mri_parameter_form'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1
AND m.CommentID=f.CommentID
AND m.T1_Scan_done='Complete'
AND s.Visit_label = 'V06'
AND p.ParameterTypeID=73754
GROUP BY Visit_labelString, s.SubprojectID, s.CenterID
ORDER BY s.SubprojectID, s.Visit_label",
    array()
);
print "...";

//Mullen- across visits and Subprojects IDs by Site
$IBIS2Q4a = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID, s.Visit_label, s.CenterID from flag as f, session as s
WHERE f.Test_name='mullen'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND s.Cancelled ='N'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID AND s.CenterID!=1
AND s.Visit_label <> 'V06'
GROUP BY s.SubprojectID, s.Visit_label, s.CenterID
ORDER BY s.SubprojectID",
    array()
);
print "...";

$IBIS2Q4b = $db->pselect("select count(distinct (s.CandID)),s.SubprojectID,
CASE WHEN p.Value LIKE '3m%' THEN 'V06' WHEN p.Value LIKE '6m%' THEN 'V06 new' END
as Visit_labelString, s.CenterID from flag as f,
session as s join candidate c on c.CandID=s.CandID join parameter_candidate p on p.CandID=c.CandID
WHERE f.Test_name='mullen'
AND (f.Administration='All' OR f.Administration='Partial')
AND (s.SubprojectID=9 OR s.SubprojectID=10)
AND s.Active='Y'
AND s.Cancelled ='N'
AND f.CommentID NOT LIKE '%DDE%'
AND (COALESCE(s.Screening, '')!='Failure' AND COALESCE(s.Visit, '') !='Failure')
AND s.ID=f.SessionID
AND s.CenterID!=1
AND s.Visit_label = 'V06'
AND p.ParameterTypeID=73754
GROUP BY s.SubprojectID, Visit_labelString, s.CenterID
ORDER BY s.SubprojectID",
    array()
);
print "...\n";



// note V06nr shows up as V06 new in back end

// IBIS1 Bx & MRI
    for ($row = 4; $row <= 8; $row++) {
        foreach ($IBIS1Q1 as $data) { // Bx
            if ($ExcelWorkSheet->getCell($columnBx . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct(s.CandID))']);
            }
        }
        foreach ($IBIS1Q2 as $data) { // MRI
            if ($ExcelWorkSheet->getCell($columnMRI . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct(s.CandID))']);

            }
        }
    }
    for ($row = 10; $row <= 13; $row++) {
        foreach ($IBIS1Q1 as $data) { // Bx
            if ($ExcelWorkSheet->getCell($columnBx . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct(s.CandID))']);
            }
        }
        foreach ($IBIS1Q2 as $data) { // MRI
            if ($ExcelWorkSheet->getCell($columnMRI . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
// IBIS1 By Site
    foreach ($sites as $centerID => $site) {
        for ($row = 4; $row <= 13; $row++) {
            if ($row < 9) {
                foreach ($IBIS1Q4 as $data) { // Bx
                    if ($ExcelWorkSheet->getCell($columns_Bx[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9' && $data['CenterID'] == $centerID) {
                        $ExcelWorkSheet->setCellValue(($columns_Bx[$site] . $row), $data['count(distinct(s.CandID))']);
                    }
                }
                foreach ($IBIS1Q3 as $data) { // MRI
                    if ($ExcelWorkSheet->getCell($columns_MRI[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9' && $data['CenterID'] == $centerID) {
                        $ExcelWorkSheet->setCellValue(($columns_MRI[$site] . $row), $data['count(distinct(s.CandID))']);
                    }
                    if ($row > 9) {
                        foreach ($IBIS1Q4 as $data) { // Bx
                            if ($ExcelWorkSheet->getCell($columns_Bx[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10' && $data['CenterID'] == $centerID) {
                                $ExcelWorkSheet->setCellValue(($columns_Bx[$site] . $row), $data['count(distinct(s.CandID))']);
                            }
                        }
                        foreach ($IBIS1Q3 as $data) { // MRI
                            if ($ExcelWorkSheet->getCell($columns_MRI[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10' && $data['CenterID'] == $centerID) {
                                $ExcelWorkSheet->setCellValue(($columns_MRI[$site] . $row), $data['count(distinct(s.CandID))']);
                            }
                        }
                    }
                }
            }
        }
    }

// IBIS2 By Site
    foreach ($sites as $centerID => $site) {
        for ($row = 19; $row <= 34; $row++) {
            if ($row < 27) {
                if ($row < 22) {
                    foreach ($IBIS2Q4b as $data) { // Bx
                        if ($ExcelWorkSheet->getCell($columns_Bx[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_Bx[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }
                    foreach ($IBIS2Q3b as $data) { // MRI
                        if ($ExcelWorkSheet->getCell($columns_MRI[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_MRI[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }

                } else {
                    foreach ($IBIS2Q4a as $data) { // Bx
                        if ($ExcelWorkSheet->getCell($columns_Bx[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_Bx[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }
                    foreach ($IBIS2Q3a as $data) { // MRI
                        if ($ExcelWorkSheet->getCell($columns_MRI[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_MRI[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }

                }
            } elseif ($row != 27) {
                if ($row < 31) {
                    foreach ($IBIS2Q4b as $data) { // Bx
                        if ($ExcelWorkSheet->getCell($columns_Bx[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_Bx[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }
                    foreach ($IBIS2Q4b as $data) { // Bx --> note V06nr shows up as V06 new in back end
                        if ($ExcelWorkSheet->getCell($columns_Bx[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_Bx[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }
                } else {
                    foreach ($IBIS2Q3a as $data) { // MRI
                        if ($ExcelWorkSheet->getCell($columns_MRI[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_MRI[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }
                    foreach ($IBIS2Q3a as $data) { // MRI
                        if ($ExcelWorkSheet->getCell($columns_MRI[$site] . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10' && $data['CenterID'] == $centerID) {
                            $ExcelWorkSheet->setCellValue(($columns_MRI[$site] . $row), $data['count(distinct(s.CandID))']);
                        }
                    }
                }
            }
        }
    }


// IBIS2 overall
// HR MRI
    for ($row = 19; $row <= 21; $row++) {
        foreach ($IBIS2Q2b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
// HR MRI
    for ($row = 22; $row <= 26; $row++) {
        foreach ($IBIS2Q2a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
    print "...";
// LR MRI --> B16 to 22
    for ($row = 28; $row <= 30; $row++) {
        foreach ($IBIS2Q2b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
// LR MRI --> B16 to 22
    for ($row = 31; $row <= 34; $row++) {
        foreach ($IBIS2Q2a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnMRI . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
    print "...";
// HR Bx
    for ($row = 19; $row <= 21; $row++) {
        foreach ($IBIS2Q1b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
// HR Bx
    for ($row = 22; $row <= 26; $row++) {
        foreach ($IBIS2Q1a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '9') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
// LR Bx
    for ($row = 28; $row <= 30; $row++) {
        foreach ($IBIS2Q1b as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
// LR Bx
    for ($row = 31; $row <= 34; $row++) {
        foreach ($IBIS2Q1a as $data) {
            if ($ExcelWorkSheet->getCell('A' . $row)->getValue() == $data['Visit_label'] && $data['SubprojectID'] == '10') {
                $ExcelWorkSheet->setCellValue(($columnBx . $row), $data['count(distinct(s.CandID))']);
            }
        }
    }
    print "...";


    print "\nDone IBIS1 IBIS2 By Site.\n\n";
}*/




?>
