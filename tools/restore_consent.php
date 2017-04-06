<?php
/**
*
*  @category Main
*  @package  
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

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db = Database::singleton();


if (isset($argv[1]) && $argv[1] === "confirm") {
  $confirm = true;
} else {
  $confirm = false;
}

restore_consent($db, 'study_consent', $confirm);
restore_consent($db, 'ndar_consent', $confirm);

function restore_consent($db, $col, $confirm)
{
  $candidates = $db->pselect("select * from participant_status as ps 
  where ps.{$col} = '' or ps.{$col} is NULL
  ORDER BY ps.CandID", array());

  $count = count($candidates);
  $found = 0;
  $notfound = 0;

  foreach($candidates as $candidate) {

    $cih = $db->pselectRow("select * from consent_info_history as cih 
    where (cih.{$col}='yes' OR cih.{$col}='no') AND cih.CandID=:pcid ORDER BY cih.ID DESC", 
    array('pcid' => $candidate['CandID']));

    if (!empty($cih)) {

      print "UPDATE participant_status AS ps SET ps.{$col}='{$cih[$col]}', ps.{$col}_date='{$cih[$col . '_date']}' WHERE ps.ID={$candidate['ID']};\n";
      if ($confirm) {
        $db->update('participant_status', array($col => $cih[$col], $col . '_date' => $cih[$col . '_date']), array('ID' => $candidate['ID']));
      }
      $found++;
    } else {
      // print "nothing in consent_info_history for candidate: {$candidate['CandID']} on ID: {$candidate['ID']} in {$col}\n";
      
      // $h = $db->pselect("select * from history as h where h.tbl='participant_status' AND h.col='{$col}' AND h.primaryCols='ID'
      // AND h.primaryVals=:phvals ORDER BY h.id DESC", 
      // array('phvals' => $candidate['ID']));
      // print_r($h);
      
      $notfound++;
    }  
  }


  print "\nfound for {$col}:     {$found}\n";
  print "not found for {$col}: {$notfound}\n";
  print "total # for {$col}:   {$count}\n";
}

