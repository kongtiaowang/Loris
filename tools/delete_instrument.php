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
if (!empty($argv[4]) && $argv[4] == 'confirm') {
    $confirm = true;
}
// set default arguments
$instrument     = $argv[1];
$visit_label     = $argv[2];
//give all for arg3 if you want to delete from all subprojects
$subProjectID    =$argv[3];
$config = NDB_Config::singleton();
$db = Database::singleton();

echo "Warning: All instances of $instrument for $visit_label under $subProjectID subprojectid for existing candidates will be DELETED(from instrument table and flag).\n";

if($argv[3]=="all")
{
    $subprojectid_query="";
}
else{
    $subprojectid_query ="and SubprojectID='$subProjectID'";
}
$list_instruments = $db->pselect(
    "SELECT * FROM test_battery WHERE Test_name='$instrument' and Visit_label='$visit_label' $subprojectid_query",
    array()
);

if($argv[3]=="all")
{
    $subprojectid_text=" all subprojects";
    $tb_subproject_val="";
    $param_val="";
    $array=array('testname' => $instrument, 'vl' => $visit_label);

}
else{
    $subprojectid_text ="SubprojectID-$subProjectID";
    $tb_subproject_val="and tb.SubprojectID='$subProjectID'";
    $param_val="and session.SubprojectID=:sid";
    $array=array('testname' => $instrument, 'vl' => $visit_label,'sid' => $subProjectID );
}

if ($confirm === false) {
        echo $instrument. " (Instrument)" ."- " . $visit_label. " (Visit Label)".$subprojectid_text." \n";
        $count = $db->pselectOne("SELECT count(*)
                                FROM  $instrument tn
                                JOIN flag On (tn.CommentID=flag.CommentID) 
                                JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                and session.Visit_label=:vl $param_val", $array
        );
        echo "No of associated CommentIDs to be removed from flag and $instrument  are " . $count. "\n";
        echo "----------------------------------------------------------------------------------------------------\n";

    echo "\nRun this tool again with the argument 'confirm' to " .
        "delete all the identified entries\n\n";
}

if ($confirm) {
    if(!empty($list_instruments)) {
        foreach ($list_instruments as $mds) {
            echo " Making entry of $instrument under $visit_label for $subprojectid_text from test battery table as NOT ACTIVE";
            echo "\n";
            $db->run("UPDATE test_battery tb SET tb.Active='N' WHERE tb.Test_name='$instrument' and tb.Visit_label='$visit_label' $tb_subproject_val");
        }
    }
        echo "Deleting associated CommentIDs from $instrument table and flag table\n";
        $del_commentid = $db->pselect("SELECT flag.CommentID as cmid
                                      FROM $instrument tn 
                                      JOIN flag On (tn.CommentID=flag.CommentID) 
                                      JOIN session On(session.ID=flag.SessionID) and flag.Test_name=:testname
                                      and session.Visit_label=:vl $param_val",$array
        );
        foreach ($del_commentid as $dlcmt) {
            $commentID = $dlcmt['cmid'];
            $db->run("DELETE flg FROM flag flg WHERE flg.CommentID='$commentID'");
            $db->run("DELETE testname FROM $instrument testname WHERE testname.CommentID='$commentID'");
            echo ".....";
        }
        echo "DONE\n";
        echo "----------------------------------------------------------------------------------------------------\n";
    echo "ALL THE $instrument under $visit_label for $subprojectid_text IS REMOVED\n";

}