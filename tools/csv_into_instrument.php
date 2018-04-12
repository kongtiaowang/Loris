<?php
require_once "generic_includes.php";




$csv = explode("\n", file_get_contents('/data/Minimental.csv'));

foreach ($csv as $key => $line)
{
        $csv[$key] = str_getcsv($line);
        print_r($line);
}

?>
