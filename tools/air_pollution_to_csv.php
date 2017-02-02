#!/usr/bin/php
<?php
/**
 * User: Gregory Luneau
 * Date: 31-01-2016
 *
 * CSV to submit encrypted data to get air pollution data
 *
 */

set_include_path(get_include_path().":../../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db =& Database::singleton();
$config = NDB_Config::singleton();

$date = date("m_d_Y");
$output_file = "air_pollution_$date.csv";
$fp = fopen($output_file, 'w');
echo "AIR POLLUTION SUBMISSION SCRIPT - $date\n\n";
echo "Data can be found in $output_file.\n\n";


$air_pollution_data = array();

$air_pollution_data = $db->pselect("select s.CenterID, s.CandID, s.Visit_label, ap.Date_taken, ap.proband_name,
  ap.address_line1m1, ap.address_line2m1, ap.citym1, ap.statem1, ap.zip_codem1, ap.additional_comments
  from air_pollution AS ap
  left join flag as f using (CommentID)
  left join session as s on s.ID=f.SessionID
  where ap.CommentID not like 'DDE_%'
  and ap.Data_entry_completion_status = 'Complete'
  and ap.consent = 'yes'", array());

$air_pollution_headers = array(
  'CenterID',
  'CandID',
  'Visit_label',
  'Date_taken',
  'proband_name',
  'address_line1m1',
  'address_line2m1',
  'citym1',
  'statem1',
  'zip_codem1',
  'additional_comments'
);


// Adds headers and project statistics into csv file
fputcsv($fp, $air_pollution_headers, $delimiter = ",", $enclosure = "'");

foreach ($air_pollution_data as $value) {
  fputcsv($fp, array_map('htmlspecialchars_decode', $value), $delimiter = ",", $enclosure = "'");
}

echo "File writing for AIR POLLUTION SUBMISSION complete.\n\n";

fclose($fp);

