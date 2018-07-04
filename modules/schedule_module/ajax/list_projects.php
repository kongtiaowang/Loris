<?php
/**
 * This is used by the Schedule Module to list all valid projects
 *
 * PHP Version 5
 *
 * @category Schedule
 * @package  Loris
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris
 */
$DB = Database::singleton();

// Select all existing projects
$projects = $DB->pselect(
    "
        SELECT 
        	ProjectID, Name 
        FROM 
        	Project
    ",
    array()
);

echo json_encode($projects);
?>