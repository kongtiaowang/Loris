<?php
/**
 * This script removes comment conflicts from conflict resolver. Redmine 15501)
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
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}
$config = NDB_Config::singleton();
$db     = Database::singleton();

echo "Warning: All comment conflicts will be removed as it is not considered as an actual conflict \n";

if ($confirm === false) {

    $conflict_instruments_count = $db->pselectOne(
        "SELECT COUNT(*) FROM conflicts_unresolved cu WHERE cu.FieldName like '%comments%'",
        array()
    );
    echo $instrument."(".$conflict_instruments_count.") ENTRIES\n";

    echo "\nRun this tool again with the argument 'confirm' to ".
        "delete the comment conflict entries\n\n";
}

if($confirm)
{
        $db->run("DELETE cu FROM conflicts_unresolved cu WHERE cu.FieldName like '%comments%'");
        echo "Done\n";
    }


