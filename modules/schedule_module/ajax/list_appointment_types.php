<?php
/**
 * This file is used by the Schedule Module to list all valid appointment types
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

// Select all existing appt types
$appointment_types = $DB->pselect(
    "
        SELECT 
        	*
        FROM 
        	appointment_type
    ",
    array()
);

echo json_encode($appointment_types);
?>