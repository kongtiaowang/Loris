<?php
/**
 * This script helps to remove the conflict exceptions from the conflict resolver whenever identified
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
set_include_path(get_include_path().":".__DIR__."/../libraries:".":".__DIR__."/../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";
require_once "../../php/libraries/NDB_Client.class.inc";
require_once "../../php/libraries/NDB_Config.class.inc";
require_once "../../php/libraries/ConflictDetector.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();
$confirm =false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}
$config = NDB_Config::singleton();
$db     = Database::singleton();

echo "Warning: All not_answered and blanks conflicts for all the instruments from the conflict resolver will be removed.\n";

$conflict_instruments = $db->pselect(
    "SELECT DISTINCT cu.TableName tb FROM conflicts_unresolved cu WHERE ((cu.Value1 IS NULL and cu.Value2='not_answered') 
     OR (cu.Value1='not_answered' and cu.Value2 IS NULL))",
    array()
);
if ($confirm === false) {
echo "\n.....INSTRUMENTS WITH BLANK AND NOT_ANSWERED CONFLICTS......\n";
foreach ($conflict_instruments as $test) {
    $conflict_instruments_count = $db->pselectOne(
        "SELECT COUNT(*) FROM conflicts_unresolved cu WHERE ((cu.Value1 IS NULL and cu.Value2='not_answered') 
         OR (cu.Value1='not_answered' and cu.Value2 IS NULL)) AND cu.TableName=:testname",
        array('testname' => $test['tb'])
    );
    echo $test['tb']." (".$conflict_instruments_count.") ENTRIES\n";

}
 echo "\nRun this tool again with the argument 'confirm' to ".
        "delete the above entries\n\n";
}

if($confirm)
{
    foreach ($conflict_instruments as $test) {
        echo " Preparing to delete entries for ".$test['tb'];
        echo "\n";
        echo "Processing...";
        echo "\n";
        $testname=$test['tb'];
        $db->run("DELETE cu FROM conflicts_unresolved cu WHERE cu.TableName='$testname' and (cu.Value1 IS NULL and cu.Value2='not_answered')");
        $db->run("DELETE cu FROM conflicts_unresolved cu WHERE cu.TableName= '$testname'and (cu.Value1='not_answered' and cu.Value2 IS NULL)");
        echo "Done\n";
    }

    echo "All blank vs not_answered conflicts are removed\n";

}