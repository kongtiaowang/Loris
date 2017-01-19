<?php
    $user =& User::singleton();
    $db   =& Database::singleton();
    $userID = $user->getData('UserID');


    $todoList = $db->pselect("SELECT * 
                FROM todos 
                WHERE UserID=:UserID",
                array('UserID' => $userID)
                );
//button comment out
        $data = '<ul class="todo_list">';
               foreach($todoList as $todo){
                $data .= '<li class="card card-3"> 
                              <a class="aa" href="#">
                            
                                     <h3>'.$todo['content'].'</h3>
                                     <p class="pp">
                                        <p onclick="DeleteTodo('.$todo['todoID'].')" class="btn1 btn-danger1">Delete</p>
                                        <p onclick="GetTodoDetails('.$todo['todoID'].')" class="btn1 btn-info1">Edit</p>
                                     </p>
                              </a>
                        </li>';
                }
    $data .= '</ul>';

    echo $data;

?>

