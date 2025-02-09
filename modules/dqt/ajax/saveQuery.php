<?php declare(strict_types=1);

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

ini_set("max_input_vars", '4000');
$user =& User::singleton();
if (!$user->hasPermission('dataquery_view')) {
    header("HTTP/1.1 403 Forbidden");
    exit(0);
}
require_once __DIR__ . '/../../../vendor/autoload.php';
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize(__DIR__ . "/../../../project/config.xml");

$user        = User::singleton();
$config      = \NDB_Config::singleton();
$couchConfig = $config->getSetting('CouchDB');
$cdb         = \NDB_Factory::singleton()->couchDB(
    $couchConfig['dbName'],
    $couchConfig['hostname'],
    intval($couchConfig['port']),
    $couchConfig['admin'],
    $couchConfig['adminpass']
);
$qid         = $user->getUserName() . "_" . $_REQUEST['QueryName'];
$qid         = rawurlencode($qid);

if ($_REQUEST['SharedQuery'] === "true") {
    $qid = "global:" . $qid;
}

if ($_REQUEST['OverwriteQuery'] === "false") {
    $results = $cdb->getDoc(
        $qid
    );

    if (!empty($results)) {
        error_log($_REQUEST['SharedQuery']);
        header("HTTP/1.1 409 Conflict");
        exit(0);
    }
}

$baseDocument = [
    '_id'        => $qid,
    'Meta'       => [
        'DocType' => 'SavedQuery',
        'user'    => $user->getUserName(),
    ],
    'Fields'     => [],
    'Conditions' => [],
];
if (isset($_REQUEST['QueryName'])) {
    $baseDocument['Meta']['name'] = $_REQUEST['QueryName'];
}
if ($_REQUEST['SharedQuery'] === "true") {
    $baseDocument['Meta']['user'] = 'global';
    $baseDocument['Meta']['name'] = $user->getUserName() .
                                    ': ' .
                                    $_REQUEST['QueryName'];
}
$fields = json_decode(strval($_REQUEST['Fields']));
$cond   = $_REQUEST['Filters'];
$baseDocument['Conditions'] = $cond;
$baseDocument['Fields']     = $fields;

$query = [];
if ($_REQUEST['OverwriteQuery'] === "true") {
    unset($baseDocument['_id']);
    $cdb->replaceDoc($qid, $baseDocument);
    $query['id'] = $qid;
    print json_encode($query);
} else {
    $response = $cdb->postDoc($baseDocument);
    print json_encode($response);
}

