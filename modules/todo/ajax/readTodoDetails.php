<?php
// include Database connection file
    $db  =& Database::singleton();

// check request
if(isset($_POST['id']) && isset($_POST['id']) != "")
{
    // get User ID
    $todoID = $_POST['id'];
    $todo = $db->pselectRow("SELECT * 
                FROM todos 
                WHERE todoID=:todoID",
                array('todoID' => $todoID)
                );
    // display JSON data
     echo json_encode($todo);
}

