<?php
// check request
if(isset($_POST))
{

     $db   =& Database::singleton();
     $todoID = $_POST['id'];
     $content = $_POST['content'];

     $query = "UPDATE todos SET content='".$content."' WHERE todoID=".$todoID.";";
     $db->run($query);

}
