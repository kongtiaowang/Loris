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

$air_pollution_data = $db->pselect("select s.CenterID, s.CandID, s.Visit_label, ap.Date_taken,
  ap.proband_name, ap.proband_birthdate, ap.living1yb4m1, ap.address_line1m1, ap.address_line2m1, ap.citym1, ap.statem1, ap.zip_codem1, ap.from1b41, ap.to1b41, ap.livinghere3bd1, ap.living1yb4m2, ap.address_line1m2, ap.address_line2m2, ap.citym2, ap.statem2, ap.zip_codem2, ap.from1b42, ap.to1b42, ap.living1yb4m3, ap.address_line1m3, ap.address_line2m3, ap.citym3, ap.statem3, ap.zip_codem3, ap.from1b43, ap.to1b43, ap.living1yb4m4, ap.address_line1m4, ap.address_line2m4, ap.citym4, ap.statem4, ap.zip_codem4, ap.from1b44, ap.to1b44, ap.living1yb4m5, ap.address_line1m5, ap.address_line2m5, ap.citym5, ap.statem5, ap.zip_codem5, ap.from1b45, ap.to1b45, ap.livingatb1, ap.address_line1b1, ap.address_line2b1, ap.cityb1, ap.stateb1, ap.zip_codeb1, ap.fromatb1, ap.toatb1, ap.livingatb2, ap.address_line1b2, ap.address_line2b2, ap.cityb2, ap.stateb2, ap.zip_codeb2, ap.fromatb2, ap.toatb2, ap.livingatb3, ap.address_line1b3, ap.address_line2b3, ap.cityb3, ap.stateb3, ap.zip_codeb3, ap.fromatb3, ap.toatb3, ap.livingatb4, ap.address_line1b4, ap.address_line2b4, ap.cityb4, ap.stateb4, ap.zip_codeb4, ap.fromatb4, ap.toatb4, ap.livingatb5, ap.address_line1b5, ap.address_line2b5, ap.cityb5, ap.stateb5, ap.zip_codeb5, ap.fromatb5, ap.toatb5, ap.livingatb6, ap.address_line1b6, ap.address_line2b6, ap.cityb6, ap.stateb6, ap.zip_codeb6, ap.fromatb6, ap.toatb6, ap.additional_comments
  from air_pollution AS ap
  left join flag as f using (CommentID)
  left join session as s on s.ID=f.SessionID
  where ap.CommentID not like 'DDE_%'
  and ap.Data_entry_completion_status = 'Complete'
  and ap.consent = 'yes'
  and ap.Date_taken <> ''", array());

$air_pollution_headers = array(
  'CenterID', 'CandID', 'Visit_label', 'Date_taken',
  'proband_name', 'proband_birthdate', 'living1yb4m1', 'address_line1m1', 'address_line2m1', 'citym1', 'statem1', 'zip_codem1', 'from1b41', 'to1b41', 'livinghere3bd1', 'living1yb4m2', 'address_line1m2', 'address_line2m2', 'citym2', 'statem2', 'zip_codem2', 'from1b42', 'to1b42', 'living1yb4m3', 'address_line1m3', 'address_line2m3', 'citym3', 'statem3', 'zip_codem3', 'from1b43', 'to1b43', 'living1yb4m4', 'address_line1m4', 'address_line2m4', 'citym4', 'statem4', 'zip_codem4', 'from1b44', 'to1b44', 'living1yb4m5', 'address_line1m5', 'address_line2m5', 'citym5', 'statem5', 'zip_codem5', 'from1b45', 'to1b45', 'livingatb1', 'address_line1b1', 'address_line2b1', 'cityb1', 'stateb1', 'zip_codeb1', 'fromatb1', 'toatb1', 'livingatb2', 'address_line1b2', 'address_line2b2', 'cityb2', 'stateb2', 'zip_codeb2', 'fromatb2', 'toatb2', 'livingatb3', 'address_line1b3', 'address_line2b3', 'cityb3', 'stateb3', 'zip_codeb3', 'fromatb3', 'toatb3', 'livingatb4', 'address_line1b4', 'address_line2b4', 'cityb4', 'stateb4', 'zip_codeb4', 'fromatb4', 'toatb4', 'livingatb5', 'address_line1b5', 'address_line2b5', 'cityb5', 'stateb5', 'zip_codeb5', 'fromatb5', 'toatb5', 'livingatb6', 'address_line1b6', 'address_line2b6', 'cityb6', 'stateb6', 'zip_codeb6', 'fromatb6', 'toatb6', 'additional_comments'
);


// Adds headers and data into csv file
fputcsv($fp, $air_pollution_headers, $delimiter = ",", $enclosure = "'");

foreach ($air_pollution_data as $value) {
  fputcsv($fp, array_map('htmlspecialchars_decode', $value), $delimiter = ",", $enclosure = "'");
}

echo "File writing for AIR POLLUTION SUBMISSION complete.\n\n";

fclose($fp);

