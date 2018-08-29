<?php
/**
  * Document_repository module
  *
  * PHP Version 5
  *
  * @category Test
  * @package  Loris
  * @author   Loris Team <loris.info@mcin.ca>
  * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
  * @link     https://github.com/aces/Loris
  */
$user =& User::singleton();
if (!$user->hasPermission('document_repository_view')
    && !$user->hasPermission('document_repository_delete')
) {
    header("HTTP/1.1 403 Forbidden");
    exit;
}

set_include_path(get_include_path().":../../project/libraries:../../php/libraries:");
require_once "NDB_Client.class.inc";
$client = new NDB_Client();
$client->initialize("../../project/config.xml");
$DB =& Database::singleton();
if (isset($_GET['categoryID'])){
   $categoryID = $_GET['categoryID'];
}

$result = $DB->pselect(
    "SELECT * FROM document_repository WHERE File_category=:categoryID",
    array('categoryID'=>$categoryID)
);

echo json_encode($result);

?>
