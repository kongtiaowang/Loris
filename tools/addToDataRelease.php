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
//require_once "NDB_Client.class.inc";
//require_once "Utility.class.inc";
//require_once "Candidate.class.inc";

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db = Database::singleton();

// $argv[1] is filename and $argv[2] is userid list
if (isset($argv[1]) && isset($argv[2])) {
  $confirm = true;
} else {
  $confirm = false;
}

if ($confirm)
{
  // INSERT INTO data_release (id, file_name, version, upload_date) VALUES(0, '', '', '');
  $db->insert('data_release', array($col => $cih[$col], $col . '_date' => $cih[$col . '_date']));

  // INSERT INTO data_release_permissions (userid, data_release_id) VALUES(0, 0);

}

