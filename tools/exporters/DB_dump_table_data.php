<?php
/**
 * This script generates data-only dumps for all tables in the currently active database.
 * Each table in the database gets dumped into a single file in the following location :
 *  BASE_PATH_TO_LORIS/test/RBfiles/RB_TABLE_NAME.sql
 *
 * This script was primarily written to simplify contributions to the raisinbread dataset.
 * Each file contains data TRUNCATION, table LOCKING, and individual INSERTS for each
 * row. This is done by design to allow for an easier review of the changes through
 * a VCS system.
 *
 *
 *
 * note: this script currently depends on the existence of a mysql configuration file
 * allowing to dump data using only the database name. The functionality to input
 * credentials interactively should be added.
 *
 * PHP Version
 *
 * @category Main
 * @package  Loris
 * @author   Rida Abou-Haidar <rida.abou-haidar@mcin.ca>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
require_once __DIR__ . '/../generic_includes.php';

$config = NDB_Config::singleton();
$databaseInfo = $config->getSetting('database');

// Get all tables in the database
$tableNames = $DB->pselectCol("
                      SELECT TABLE_NAME 
                      FROM INFORMATION_SCHEMA.TABLES
                      WHERE TABLE_SCHEMA =:dbn",
    array("dbn"=>$databaseInfo['database'])
);

// Loop through all tables to generate insert statements for each.
foreach ($tableNames as $tableName) {
    $filename = __DIR__ . "/../../test/RBfiles/RB_$tableName.sql";
    exec('mysqldump '.$databaseInfo['database'].' '.
        '--complete-insert '.
        '--no-create-db '.
        '--no-create-info '.
        '--skip-opt '.
        '--compact '.
        '--add-locks '.
        '--verbose '.
        $tableName.
        ' | sed -E \'s/LOCK TABLES (`[^`]+`)/TRUNCATE TABLE \1;\nLOCK TABLES \1/g\''.
        ' > '.$filename
    );
}