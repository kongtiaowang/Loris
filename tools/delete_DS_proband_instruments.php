<?php
/**
 * Created by PhpStorm.
 * User: smathew
 * Date: 18/05/17
 * Time: 2:44 PM
 */

set_include_path(get_include_path() . ":" . __DIR__ . "/../libraries:" . ":" . __DIR__ . "/../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";
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

echo "Warning: All accidentally created Down Syndrome proband instruments from test_battery table will be deleted.\n";
echo "Warning: All accidentally created Down Syndrome proband instruments(CommentIDs) from corresponding instrument and flag table will be deleted\n";

$proband_instruments = $db->pselect(
    "SELECT * FROM test_battery where Test_name LIKE '%proband%' and SubprojectID=11",
    array()
);
$proband_instruments_count = $db->pselectOne(
    "SELECT count(*) FROM test_battery where Test_name LIKE '%proband%' and SubprojectID=11",
    array()
);
if($proband_instruments_count==0)
{
    echo " No proband instruments were found or added to test battery table for Down Syndrome project. You are good!" ;
    echo "\n";
    exit;
}

if ($confirm === false) {

    echo "\n.....All accidentally created  proband instruments for DS subproject in test_battery table......\n";
    echo "\n";
    foreach ($proband_instruments as $pbs) {

        echo $pbs['Test_name'] . "(proband instrument) - " . $pbs['Visit_label']. " (Visit Label) - " . $pbs['SubprojectID'] . "(SubprojectID)\n";
        $testname=$pbs['Test_name'];
        $count = $db->pselectOne("SELECT count(*)
                                FROM  $testname tn
                                JOIN flag On (tn.CommentID=flag.CommentID) 
                                JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                and session.Visit_label=:vl and session.SubprojectID=:sid",
                                array('testname' => $pbs['Test_name'], 'vl' => $pbs['Visit_label'], 'sid' => $pbs['SubprojectID'],)
        );
        echo "No of associated CommentIDs to be removed from flag and " . $pbs['Test_name'] . " for the above test battery entry are " . $count. "\n";
        echo "----------------------------------------------------------------------------------------------------\n";

    }
    echo "\nRun this tool again with the argument 'confirm' to " .
        "delete all the identified entries\n\n";
}

if ($confirm) {
    foreach ($proband_instruments as $pbs) {
        echo " Preparing to delete entries from test_battery table";
        echo "\n";
        echo "Deleting " . $pbs['Test_name']. " from test battery";
        echo "\n";
        $testname = $pbs['Test_name'];
        $db->run("DELETE tb FROM test_battery tb WHERE tb.Test_name LIKE '%proband%' and tb.SubprojectID=11");
        echo "Deleting associated CommentIDs from ".$pbs['Test_name']. " table and flag table\n";
        $del_commentid = $db->pselect("SELECT flag.CommentID as cmid
                                      FROM $testname tn 
                                      JOIN flag On (tn.CommentID=flag.CommentID) 
                                      JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                      and session.Visit_label=:vl and session.SubprojectID=:sid",
                                       array('testname' => $pbs['Test_name'], 'vl' => $pbs['Visit_label'], 'sid' => $pbs['SubprojectID'],)
        );
        $testname = $pbs['Test_name'];
        foreach ($del_commentid as $dlcmt) {
            $commentID = $dlcmt['cmid'];
            $db->run("DELETE flg FROM flag flg WHERE flg.CommentID='$commentID'");
            $db->run("DELETE testname FROM $testname testname WHERE testname.CommentID='$commentID'");
            echo ".....";
        }
        echo "DONE\n";
        echo "----------------------------------------------------------------------------------------------------\n";
    }
    echo "ALL THE PROBAND INSTRUMENT DETAILS FROM DOWN SYNDROME PROJECT IS REMOVED\n";

}