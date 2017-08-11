<?php
ini_set('default_charset', 'utf-8');
require_once "Database.class.inc";
require_once 'NDB_Config.class.inc';
require_once 'NDB_Client.class.inc';

$user =& User::singleton();
if (!$user->hasPermission('data_team_helper')) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}

$config =& NDB_Config::singleton();
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();
header("content-type:application/json");

require_once "Utility.class.inc";


if ($_REQUEST['project_id']!= '') {
    $subprojects = Utility::getSubprojectsForProject($_REQUEST['project_id']);
    print json_encode($subprojects);
    exit();

}


