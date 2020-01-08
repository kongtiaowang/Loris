<?php
/**
 * Created by PhpStorm.
 * User: smathew
 * Date: 18/05/17
 * Time: 2:44 PM
 */

require_once __DIR__ . '/../../vendor/autoload.php';
require_once __DIR__ . '/../../tools/generic_includes.php';
require_once "../../php/libraries/NDB_Client.class.inc";
require_once "../../php/libraries/NDB_Config.class.inc";
require_once "../../php/libraries/ConflictDetector.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();
$confirm = false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}
$config = NDB_Config::singleton();
$db = Database::singleton();

echo "Warning: All instruments in the test battery table will be be ordered alphabetically \n";


$list_instruments = $db->pselect(
    "SELECT DISTINCT tn.Full_name, tn.test_name from test_names tn join test_battery tb on (tn.Test_name=tb.Test_name) order by tn.Full_name",
    array()
);

$i=0;
        foreach ($list_instruments as $li) {
            $i++;
            $instrument = $li['test_name'];
            echo "UPDATE test_battery SET instr_order='$i' where test_name='$instrument'";
            echo "\n";
            if($confirm==true) {
                $db->run("UPDATE test_battery SET instr_order='$i' where test_name='$instrument'");
            }
        }
if($confirm==true) {
    echo "DONE...UPDATED\n";
    echo "----------------------------------------------------------------------------------------------------\n";
    echo "All the instruments are sorted alphabetically in the test battery table";
}
else{
    echo "\nRun this tool again with the argument 'confirm' to " .
        "update the above in database\n";
}