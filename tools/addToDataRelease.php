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

// Main
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../config.xml');

$db = Database::singleton();

// $argv[1] is filename
// $argv[2] is userid list, comma seperated with no spaces
// and $argv[3] is the optional date
if (isset($argv[1]) && isset($argv[2])) {
  $confirm = true;
} else {
  $confirm = false;
}

$file_name = trim($argv[1]);
$users = explode(",", $argv[2]);

if (empty($argv[3])) {
  $upload_date = date("Y-m-d");
} else {
  $upload_date = trim($argv[3]);
}

if ($confirm)
{
  // INSERT INTO data_release (id, file_name, version, upload_date) VALUES(0, '', '', '');
  $db->insert('data_release', array('file_name' => $file_name, 'version' => '1', 'upload_date' => $upload_date));
  $lastID = $db->lastInsertID;

  // INSERT INTO data_release_permissions (userid, data_release_id) VALUES(0, 0);
  foreach ($users as $user) {
    $db->insert('data_release_permissions', array('userid' => $user, 'data_release_id' => $lastID));
  }

}

