<?php
/**
 * Created by PhpStorm.
 * User: smathew
 * Date: 18/05/17
 * Time: 2:44 PM
 */

set_include_path(get_include_path() . ":" . __DIR__ . "/../libraries:" . ":" . __DIR__ . "/../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";
$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize();
$confirm = false;
if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}
$db = Database::singleton();

echo "Warning: Entry of some Instruments(BOT2,MRI_PF,TSI) for VSA visit from Test battery table will be removed to avoid future population.\n";
echo "Warning: All Incomplete(Data Not Collected) instances of Instruments(BOT2,MRI_PF,TSI,Med Records Recruit) in VSA for existing candidates in will be DELETED(from instrument table and flag).\n";

$to_be_deletedinstruments = array('BOT2','mri_parameter_form','tsi','med_records_recruit');

if ($confirm === false) {

    foreach ($to_be_deletedinstruments  as $key => $value) {

        $testname=$value;
        $visit='VSA';
        echo $testname."\n";
        $count = $db->pselectOne("SELECT count(*)
                                FROM  $testname tn
                                JOIN flag On (tn.CommentID=flag.CommentID) 
                                JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                and session.Visit_label=:vl and tn.Data_entry_completion_status='Incomplete' and tn.Date_taken IS NULL",
            array('testname' => $testname, 'vl' => $visit)
        );
        echo "No of associated CommentIDs to be removed from flag and " . $testname . " are " . $count. "\n";
        echo "----------------------------------------------------------------------------------------------------\n";

    }
    echo "\nRun this tool again with the argument 'confirm' to " .
        "delete all the identified entries\n\n";
}

if ($confirm) {
    foreach ($to_be_deletedinstruments as $key => $value) {

        $testname = $value;
        $visit='VSA';
        echo "Deleting associated CommentIDs from ".$testname. " table and flag table\n";
        $del_commentid = $db->pselect("SELECT tn.CommentID as cmid
                                      FROM  $testname tn
                                JOIN flag On (tn.CommentID=flag.CommentID) 
                                JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                and session.Visit_label=:vl and tn.Data_entry_completion_status='Incomplete' and tn.Date_taken IS NULL",
            array('testname' => $testname, 'vl' => $visit)
        );
        foreach ($del_commentid as $dlcmt) {
            $commentID = $dlcmt['cmid'];
            echo $commentID."\n";
            $db->run("DELETE flg FROM flag flg WHERE flg.CommentID='$commentID'");
            $db->run("DELETE testname FROM $testname testname WHERE testname.CommentID='$commentID'");
        }
        echo "DONE\n";
        echo "----------------------------------------------------------------------------------------------------\n";
    }
    echo "All Incomplete(Data Not Collected) instances of Instruments(BOT2,MRI_PF,TSI, Med Records Recruit) in VSA for existing candidates are DELETED";

}