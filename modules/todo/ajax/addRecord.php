<?php
    if(isset($_POST['content']))
    {
        // get values 
        $content = $_POST['content'];
 
         $db   =& Database::singleton();
         $user =& User::singleton();
         $todoValues['content'] = $content; 
         $todoValues['UserID'] = $user->getData('UserID');
                   
         $db->insert('todos', $todoValues);        
    
         echo $todoValues['UserID'] ;
    }
?>
