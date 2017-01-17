<?php
// check request

if(isset($_POST['id']) && isset($_POST['id']) != "")
{
    // get values 
         $id = $_POST['id'];
         $db =& Database::singleton();
         $db->delete("todos", array("todoID" => $id));

         echo $id ;
}



?>
