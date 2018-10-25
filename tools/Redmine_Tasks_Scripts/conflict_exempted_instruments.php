<?php
/**
 * This script removes conflicts from certain instruments in certain demanded cases(derived instrument,cannot be reconciled etc)
 * Redmine 15516, 15500
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
set_include_path(get_include_path().":../../libraries:../../../php/libraries:");
require_once __DIR__ . "/../../../vendor/autoload.php";
require_once "Database.class.inc";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../../config.xml');
$db        =& Database::singleton();
$confirm =false;
if (!empty($argv[2]) && $argv[2] == 'confirm') {
    $confirm = true;
}
$instrument =$argv[1];
$config = NDB_Config::singleton();
$db     = Database::singleton();

echo "Warning: All conflicts from the given instrument will be removed.\n";

if ($confirm === false) {

    $conflict_instruments_count = $db->pselectOne(
        "SELECT COUNT(*) FROM conflicts_unresolved cu WHERE cu.TableName=:testname",
        array('testname' => $instrument)
    );
    echo $instrument."(".$conflict_instruments_count.") ENTRIES\n";

    echo "\nRun this tool again with the argument 'confirm' to ".
        "delete the above entries\n\n";
}

if($confirm)
{
        $db->run("DELETE cu FROM conflicts_unresolved cu WHERE cu.TableName='$instrument'");
        echo "Done\n";
    }


