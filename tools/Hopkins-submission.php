<?php
/**
* Will create a Hopkins submisson from mysql data into an excel workbook
*
* PHP Version 5.5.9
*
*  @category Main
*  @package  Hopkins-submission
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
* Converst the column number into the excel column name in letters
*
* @param int $num The column number
*
* @return string $letter The excel column name in letters
**/
function getNameFromNumber($num)
{
    $numeric = $num % 26;
    $letter  = chr(65 + $numeric);
    $num2    = intval($num / 26);
    if ($num2 > 0) {
        return getNameFromNumber($num2 - 1) . $letter;
    } else {
        return $letter;
    }
}

/**
* Add a sheet to the excel workbook with name specified
*
* @param string $query The SQL query to run
* @param string $name  Name of the excel tab
*
* @return null
**/
function addSheet($query, $name)
{
    global $DB, $ExcelApplication;

    print "adding tab " . $name . "\n";
    $result = $DB->pselect($query, array());

    $ExcelWorkSheet = new PHPExcel_Worksheet($ExcelApplication, $name);
    $ExcelApplication->addSheet($ExcelWorkSheet, -1);

    // Add Column names
    $ExcelWorkSheet->fromArray(array_keys($result[0]), ' ', 'A1');
    // Add Data
    $ExcelWorkSheet->fromArray($result, ' ', 'A2');

    // Bold Cyan Column headers
    $numCol = count($result[0]) - 1;
    $header = 'a1:' . getNameFromNumber($numCol) . '1';
    $ExcelWorkSheet->getStyle($header)->getFill()->setFillType(
        \PHPExcel_Style_Fill::FILL_SOLID
    )->getStartColor()->setARGB('00e0ffff');

    $hor_cen = \PHPExcel_Style_Alignment::HORIZONTAL_CENTER;
    $style   = array(
                'font'      => array('bold' => true),
                'alignment' => array('horizontal' => $hor_cen),
               );
    $ExcelWorkSheet->getStyle($header)->applyFromArray($style);

    // Redimension columns to max size of data
    for ($col = 0; $col <= $numCol; $col++) {
        $ExcelWorkSheet->getColumnDimension(
            getNameFromNumber($col)
        )->setAutoSize(true);
    }
}

// Main
if (empty($argv[1])) {
    print "Usage: php Hopkins-submission.php Jan2017\n";
} else {

    // Create a new PHPExcel Object
    $ExcelApplication = new PHPExcel();
    // Removing builtin sheet make it easier to use same function to add sheets later
    $ExcelApplication->removeSheetByIndex(0);

    $client = new NDB_Client();
    $client->makeCommandLine();
    $client->initialize('../config.xml');

    $DB = Database::singleton();

    $TQ = array(
           "Hopkins" =>
                "SELECT DISTINCT c.HopID,
                c.Gender,
                t.candidate_race,
                t.mother_age_yrs * 12 as mother_age_mths,
                t.mother_education,
                t.father_age_yrs * 12 as father_age_mths,
                t.father_education
                FROM candidate c
                JOIN session s ON (s.CandID=c.CandID)
                LEFT JOIN flag ft ON (ft.SessionID=s.ID and ft.Test_name='tsi')
                JOIN tsi t ON (t.CommentID=ft.CommentID
                    and t.CommentID not like 'DDE_%')
                JOIN participant_status ps ON (ps.CandID=c.CandID)
                WHERE ps.study_consent='yes' AND s.CenterID!=1 AND c.Active='Y'
                AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00')='0000-00-00')
                AND ((ft.administration <> 'None' AND ft.administration is not null) 
                    OR t.data_entry_completion_status='Complete')
                AND t.Candidate_Age >= 0
                ORDER BY c.HopID;");

    foreach ($TQ as $name => $query) {
        addSheet($query, $name);
    }

    // Writing the excel file out
    $writer = PHPExcel_IOFactory::createWriter($ExcelApplication, 'Excel2007');
    $writer->save('Hopkins-submission-' . $argv[1] . '.xlsx');

    print "-- were done.\n\n";
}
