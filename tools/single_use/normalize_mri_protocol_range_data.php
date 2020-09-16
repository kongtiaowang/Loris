<?php
/**
 * This script is the part of the second step for normalizing the mri_protocol table
 * and mri_protocol_checks table.
 * It populates the new min & max columns for each field that can contain ranges. 
 *   - If the script is run with the option "tosql", the SQL statements to remove the
 *     old "%_range" columns will be written in file
 *     $LORIS/project/tables_sql/DELETE_mri_protocol_range_columns.sql
 *   - If the script is run without the option "tosql", the SQL statements to
 *     remove the old "%_range" columns will be printed in the terminal.
 *
 * NOTE: this script must be run AFTER running this patch:
 * /var/www/loris/SQL/New_patches/2018-02-27_normalize_mri_protocol_sql.
 *
 * "Usage: php normalize_mri_protocol_range_data.php [tosql]";
 * "Example: php normalize_mri_protocol_range_data.php tosql";
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Loris
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris
 */
require_once __DIR__ . '/../../../tools/generic_includes.php';
require_once 'Database.class.inc';
require_once 'Utility.class.inc';

// Regex pattern for a positivie or negative float number, with or without a fractional part
$FLOAT_PATTERN = '-?[0-9]+(?:\.[0-9]+)?';

// set default arguments
$printToSQL = false;
// SQL output
$output     = "";

// check if the 'tosql' option is passed
if (!empty($argv[1]) && $argv[1] == "tosql") {
  $printToSQL = true;
}

function split_ranges($table_name, $printToSQL, $output) {
    global $FLOAT_PATTERN;

    $DB = \Database::singleton();

// get all "ID" values from the mri_protocol table
    $mp_idx = $DB->pselect("SELECT ID FROM $table_name", array());
    $idx = array();
    foreach($mp_idx as $num => $value) {
        array_push($idx, $value["ID"]);
    }

// get all column names like "%_range" from mri_protocol table
    $mp_columns = $DB->pselect("SELECT column_name FROM information_schema.columns WHERE table_name=:table_name", array('table_name' => $table_name));
    $mp_range_columns = array();
    foreach($mp_columns as $id => $value) {
        if (ucfirst(substr($value['column_name'], -5)) == 'Range') {
            array_push($mp_range_columns, $value["column_name"]);
        }
    }
    // IBIS specific: even though this column name does not end with the string
    // 'Range' it *can* contain a range, so it is added to the array
    if ($table_name == 'mri_protocol') {
        array_push($mp_range_columns, "number_of_files");
    }

    foreach($idx as $id) {
        $mp_data = $DB->pselect("SELECT * FROM $table_name mp WHERE mp.ID=:id", array('id' => $id));
        $data_to_insert = array();
        foreach($mp_range_columns as $range_col) {
            $to_replace = substr($range_col,0, 5) == "Valid" ? 'Range' : '_range';
            $rangeString = $mp_data[0][$range_col];
            if ($rangeString == "") {
                continue;
            } 

            $col_name   = str_replace($to_replace, '', $range_col);
            $col_min    = $table_name == 'mri_protocol' 
                ? $col_name . "_min" : $col_name . "Min";
            $col_max    = $table_name == 'mri_protocol' 
                ? $col_name . "_max" : $col_name . "Max";

            // If rangeString consists of a single positive or negative number, then min=max
            if (preg_match("/^$FLOAT_PATTERN$/", $rangeString)) {
                $data_to_insert[$col_min] = $rangeString;
                $data_to_insert[$col_max] = $rangeString;
            // If rangeString consists of positive or negative numbers separated by a dash
            } else if (preg_match("/^($FLOAT_PATTERN)-($FLOAT_PATTERN)$/", $rangeString, $matches)) {
                $data_to_insert[$col_min] = $matches[1];
                $data_to_insert[$col_max] = $matches[2];
            // Invalid range
            } else {
                echo "Invalid range for column $range_col: $rangeString. Aborting.\n";
                exit(1);
            }
        }
        $not_null = 0;
        foreach ($data_to_insert as $data) {
            if ($data != null) {
                $not_null += 1;
            }
        }
        // only update non-null range cols
        if ($not_null > 0) {
            $DB->update($table_name, $data_to_insert, array('ID' => $id));
        }
    }

    echo("$table_name: Data insertion for new min & max columns is complete.\n");

    foreach($mp_range_columns as $range_column) {
        $output .= "ALTER TABLE $table_name DROP $range_column;\n";
    }

    if ($printToSQL) {
        _exportSQL($output);
    } else {
        echo("Please execute the following SQL statements to delete the original range columns.\n\n");
        echo("$output\n");
    }
}

$tables_to_normalize = array("mri_protocol", "mri_protocol_checks");
foreach ($tables_to_normalize as $table) {
    split_ranges($table, $printToSQL, $output);
}
$filename = __DIR__ . "/../../tables_sql/DELETE_mri_protocol_range_columns.sql";
if ($printToSQL) {
    echo("Please run the SQL patch found in: " . $filename . "\n");
}

function _exportSQL ($output) {
    //export file
    $filename = __DIR__ . "/../../tables_sql/DELETE_mri_protocol_range_columns.sql";
    $fp       = fopen($filename, "a");
    fwrite($fp, $output);
    fclose($fp);
}

