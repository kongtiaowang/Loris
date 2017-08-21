<?php
/**
 * Get all the subprojects list for the selected project
 *
 * PHP Version 7
 *
 * @category Main
 * @package  statistics_ibis
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
ini_set('default_charset', 'utf-8');
require_once "Database.class.inc";
require_once 'NDB_Client.class.inc';

$user =& User::singleton();
if (!$user->hasPermission('data_entry')) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();
header("content-type:application/json");

require_once "Utility.class.inc";
if ($_REQUEST['project_id']!= '') {
    $subprojects = Utility::getSubprojectsForProject($_REQUEST['project_id']);
    print json_encode($subprojects);
    exit;

}
else{
    echo 0;
    exit;
}


