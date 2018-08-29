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
$result = $DB->pselect(
    "SELECT * FROM document_repository_categories",
    array()
);

$data = array();

foreach ($result as $value) {
       array_push($data,parseCategory($value));
}

    function parseCategory($value)
    {
        $id = $value['id'];
        $depth = 0;
        $DB    = \Database::singleton();
            $categoryName = $value['category_name'];
        do {
            if ($value['parent_id'] != 0) {
                $depth       += 1;
                $parent_id    = $value['parent_id'];
                $query        = "SELECT * FROM document_repository_categories".
                                " where id=$parent_id";
                $value        = $DB->pselectRow($query, array());
                $categoryName = $value['category_name'] . ">" . $categoryName;
            }
        } while ($value['parent_id'] != 0);
//try to return array{{name:"ddd",id:'1'}{}}
//        return $categoryName;
//          return $id;
         return array("name"=>$categoryName,"id"=>$id);
    }
echo json_encode($data);

?>
