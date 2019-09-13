<?php
/**
 * Data Querying Module
 *
 * PHP Version 5
 *
 * @category Data_Querying_Module
 * @package  Loris
 * @author   Loris Team <loris-dev@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
$user =& User::singleton();
if (!$user->hasPermission('dataquery_view')) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}
//-----------------//
// BEGIN OVERRIDE  //
//-----------------//
require_once __DIR__ . '/../../../../vendor/autoload.php';
//-----------------//
// END OVERRIDE    //
//-----------------//
$client = new NDB_Client();
$client->makeCommandLine();
//-----------------//
// BEGIN OVERRIDE  //
//-----------------//
$client->initialize(__DIR__ . "/../../../config.xml");
//-----------------//
// END OVERRIDE    //
//-----------------//
header("Content-Type: application/json");

$config      = \NDB_Config::singleton();
$couchConfig = $config->getSetting('CouchDB');
$cdb         = \NDB_Factory::singleton()->couchDB(
    $couchConfig['dbName'],
    $couchConfig['hostname'],
    $couchConfig['port'],
    $couchConfig['admin'],
    $couchConfig['adminpass']
);
$docID       = urlencode($_REQUEST['DocID']);

$results = $cdb->getDoc(
    $docID
);

print json_encode($results);
?>
