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

echo "Warning: Entry of MedRecords New recruit  V03 for DS subproject from Test battery table will be removed.\n";
echo "Warning: All instances of MedRecords New recruit in V03 for existing and future candidates in DS project will be DELETED(from instrument table and flag).\n";

$med_ds_instruments = $db->pselect(
    "SELECT * FROM test_battery WHERE Test_name='med_records_recruit' and Visit_label='V03' and  SubprojectID=11",
    array()
);

if ($confirm === false) {

    foreach ($med_ds_instruments as $mds) {

        echo $mds['Test_name'] ."- " . $mds['Visit_label']. " (Visit Label) - " . $mds['SubprojectID'] . "(SubprojectID)\n";
        $testname=$mds['Test_name'];
        $count = $db->pselectOne("SELECT count(*)
                                FROM  $testname tn
                                JOIN flag On (tn.CommentID=flag.CommentID) 
                                JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                and session.Visit_label=:vl and session.SubprojectID=:sid",
            array('testname' => $mds['Test_name'], 'vl' => $mds['Visit_label'], 'sid' => $mds['SubprojectID'],)
        );
        echo "No of associated CommentIDs to be removed from flag and " . $mds['Test_name'] . " for the above test battery entry are " . $count. "\n";
        echo "----------------------------------------------------------------------------------------------------\n";

    }
    echo "\nRun this tool again with the argument 'confirm' to " .
        "delete all the identified entries\n\n";
}

if ($confirm) {
    foreach ($med_ds_instruments as $mds) {
        echo " Preparing to delete entry of MedRecords New recruit in V03 from test battery table";
        echo "\n";
        echo "Deleting " . $mds['Test_name']. " from test battery";
        echo "\n";
        $testname = $mds['Test_name'];
        $db->run("DELETE tb FROM test_battery tb WHERE tb.Test_name='med_records_recruit' and tb.Visit_label='V03' and tb.SubprojectID=11");
        echo "Deleting associated CommentIDs from ".$mds['Test_name']. " table and flag table\n";
        $del_commentid = $db->pselect("SELECT flag.CommentID as cmid
                                      FROM $testname tn 
                                      JOIN flag On (tn.CommentID=flag.CommentID) 
                                      JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                      and session.Visit_label=:vl and session.SubprojectID=:sid",
            array('testname' => $mds['Test_name'], 'vl' => $mds['Visit_label'], 'sid' => $mds['SubprojectID'],)
        );
        $testname = $mds['Test_name'];
        foreach ($del_commentid as $dlcmt) {
            $commentID = $dlcmt['cmid'];
            $db->run("DELETE flg FROM flag flg WHERE flg.CommentID='$commentID'");
            $db->run("DELETE testname FROM $testname testname WHERE testname.CommentID='$commentID'");
            echo ".....";
        }
        echo "DONE\n";
        echo "----------------------------------------------------------------------------------------------------\n";
    }
    echo "ALL THE MED_RECORDS NEW RECRUIT V03 DETAILS FROM DOWN SYNDROME PROJECT IS REMOVED\n";

}