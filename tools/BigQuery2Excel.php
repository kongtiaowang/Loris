<?php
/**
* Will create a BSRC submisson from mysql data into an excel workbook
* 
* PHP Version 5.5.9
* 
*  @category Main
*  @package  BSRC-submission
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
* 
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
* 
**/
function addSheet($query, $name)
{
    global $DB, $ExcelApplication;

    print "adding tab " . $name . "\n";
    $DB->select($query, $result);

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
    print "Usage: php BSRC-submission.php Dec2015\n";
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
           "a2m3"                      => "SELECT DISTINCT c.PSCID, c.IBISId, v.*, m.*, d.*, a.*, a1m1.*
FROM candidate c
JOIN session s ON (s.CandID=c.CandID)
LEFT JOIN flag fv ON (fv.SessionID=s.ID and fv.Test_name='vineland_subject')
  JOIN vineland_subject v ON (v.CommentID=fv.CommentID and v.CommentID not like 'DDE_%')
LEFT JOIN flag fm ON (fm.SessionID=s.ID and fm.Test_name='mullen')
  JOIN mullen m ON (m.CommentID=fm.CommentID and m.CommentID not like 'DDE_%')
LEFT JOIN flag fd ON (fd.SessionID=s.ID and fd.Test_name='DSMIV_checklist')
  JOIN DSMIV_checklist d ON (d.CommentID=fd.CommentID and d.CommentID not like 'DDE_%')
LEFT JOIN flag fa1m1 ON (fa1m1.SessionID=s.ID and fa1m1.Test_name='ados2_module3')
  JOIN ados2_module3 a1m1 ON (a1m1.CommentID=fa1m1.CommentID and a1m1.CommentID not like 'DDE_%')
JOIN participant_status ps ON (ps.CandID=c.CandID)
JOIN ADOS_DERIVED a on (a.CandID=c.CandID)
WHERE ps.study_consent='yes' AND s.CenterID!=1 AND c.Active='Y'
AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00')='0000-00-00')
AND (s.SubprojectID=1 OR s.SubprojectID=2 OR s.SubprojectID=3)
AND (
   ((fv.administration <> 'None' AND fv.administration is not null) OR v.data_entry_completion_status='Complete')
OR ((fm.administration <> 'None' AND fm.administration is not null) OR m.data_entry_completion_status='Complete')
OR ((fd.administration <> 'None' AND fd.administration is not null) OR d.data_entry_completion_status='Complete')
OR ((fa1m1.administration <> 'None' AND fa1m1.administration is not null) OR a1m1.data_entry_completion_status='Complete')
)
AND (s.Visit_label = 'V24' or s.Visit_label = 'V36')
order by c.PSCID;",
          );

    foreach ($TQ as $name => $query) {
        addSheet($query, $name);
    }

    // Writing the excel file out
    $writer = PHPExcel_IOFactory::createWriter($ExcelApplication, 'Excel2007');
    $writer->save('BigQuery-' . $argv[1] . '.xlsx');

    print "-- were done.\n\n";
}
