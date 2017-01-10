<?php
    if(isset($_POST['first_name']) && isset($_POST['last_name']) && isset($_POST['email']))
    {
        // get values 
        $first_name = $_POST['first_name'];
        $last_name = $_POST['last_name'];
        $email = $_POST['email'];
 
      //  $query = "INSERT INTO todo(first_name, last_name, email) VALUES('$first_name', '$last_name', '$email')";
      //  if (!$result = mysqli_query($con, $query)) {
      //      exit(mysqli_error($con));
      //  }
        echo "1 Record Added!";
    }
?>
