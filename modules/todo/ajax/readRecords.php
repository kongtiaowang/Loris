<?php
    $user =& User::singleton();
    $db   =& Database::singleton(); 
    $userID = $user->getData('UserID');
   

    $todoList = $DB->pselect("SELECT * 
                FROM todos 
                WHERE UserID=:UserID",
                array('UserID' => $userID)
                );
        
	$data = '<table class="table table-bordered table-striped">
						<tr>
							<th>content</th>
                                                        <th>function</th>
						</tr>';
               foreach($todoList as $todo){
    		$data .= '<tr>
		
				<td>'.$todo['content'].'</td>
                                <td>
					<button onclick="DeleteUser('.$todo['todoID'].')" class="btn btn-danger">Delete</button>
				</td>
    	               	</tr>';
                }
    $data .= '</table>';

    echo $data;
  
?>
