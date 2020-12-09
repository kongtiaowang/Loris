<?php
/**
 * This script re-uploads the file that was (were) already uploaded for the given
 * candidate(s) for instrument WIAT_III_SA.
 *
 * NOTE: this script must be run AFTER running this patch:
 * /var/www/loris/project/tables_sql/2020-12-03_RefactorWIAT_III_SA.sql
 *
 * "Usage: php reupload_wiat_iii_sa.php CandID [[CandID] ...]"
 * "Example: php  reupload_wiat_iii_sa.php 123456 333333
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Loris
 * @author   Nicolas Brossard
 * @license  Loris license
 * @link     https://www.github.com/aces/IBIS
 */
require_once __DIR__ . '/../../../tools/generic_includes.php';
require_once 'Database.class.inc';
require_once 'NDB_Config.class.inc';
require_once __DIR__ . '/../../instruments/NDB_BVL_Instrument_WIAT_III_SA.class.inc';

// Must have at least one argument
if ($argc <= 1) {
    exit("Usage: $argv[0] Candid [[CandID] ...]\n");
}

//-------------------------------------//
// Build the set of candidate IDs. The //
// duplicates will be eliminated.      //
//-------------------------------------//
$candIDs = [];
for ($i=1; $i<$argc; $i++) {
    if (!preg_match("/^[0-9]{6}$/", $argv[$i])) {
        exit ("Invalid candidate ID $argv[$i]\n");
    }
    $candIDs[$argv[$i]] = 1;
}

//-------------------------------------//
// Get the information associated      //
// to all the WIAT_III_SA for all the  //
// candidate IDs passed as argument.   //
//-------------------------------------//
$DB = \Database::singleton();
$query = "SELECT c.PSCID, s.CandID, s.Visit_label, w.CommentID, w.File_name, w.Data_dir, w.UserID "
       . "FROM WIAT_III_SA w "
       . "JOIN flag f USING(CommentID) "
       . "JOIN session s ON (s.ID=f.sessionID) "
       . "JOIN candidate c ON (c.CandID = s.CandID) "
       . "WHERE f.test_name = 'WIAT_III_SA' "
       . "AND f.CommentID NOT LIKE 'DDE%' "
       . "AND FIND_IN_SET(s.CandID, :CandIDList)";
$rows = $DB->pselect(
    $query,
    [ "CandIDList" =>  implode(',', array_keys($candIDs))]
);

$wiat = [];
foreach ($rows as $r) {
    $wiat[$r["CandID"]] = [
        "COMMENTID"   => $r["CommentID"],
        "FILE_NAME"   => $r["File_name"],
        "VISIT_LABEL" => $r["Visit_label"],
        "PSCID"       => $r["PSCID"],
        "CANDID"      => $r["CandID"],
        "USERID"      => $r["UserID"],
        "DATA_DIR"    => $r["Data_dir"]
    ];
}

//-----------------------------------//
// Check that all candidates have    //
// an uploaded file                  //
//-----------------------------------//
foreach (array_keys($candIDs) as $candID) {
    if (!isset($wiat[$candID])) {
        exit("No instrument WIAT_III_SA for candidate $candID\n");
    }
    if (is_null($wiat[$candID]["FILE_NAME"]) || $wiat[$candID]["FILE_NAME"] == '') {
        exit("No file was uploaded in instrument WIAT_III_SA for candidate $candID\n");
    }
}

$config             = NDB_Config::singleton();
$uploadDir          = $config->getSetting("UploadDir") ?? ".";
$wiatFilesUploadDir = "$uploadDir/WIAT_III_SA/";

foreach ($wiat as  $candID => $instrumentData) {
    $form = NDB_BVL_Instrument::factory("WIAT_III_SA", $instrumentData['COMMENTID']);

    //----------------------------------------//
    // Build the argument array needed by     //
    // the WIAT instrument for that candidate //
    //----------------------------------------//
    $args = [
        "PSCID"        => $instrumentData["PSCID"],
        "visitLabel"   => $instrumentData["VISIT_LABEL"],
        "username"     => $instrumentData["USERID"],
        "CommentID"    => $instrumentData["COMMENTID"],
    ];

    //--------------------------------------------------------//
    // Build a "mock" FileUpload object that will return the  //
    // values for the WIAT instrument                         //
    //--------------------------------------------------------//
    $file = new class($instrumentData, $wiatFilesUploadDir) {
        public $fileInfo;
        private $instrumentData;

        function __construct($instrumentData, $wiatFilesUploadDir) {
            $this->fileInfo = [
                "name"     => "WIAT_III_SA_{$instrumentData['PSCID']}_{$instrumentData['VISIT_LABEL']}.txt",
                "tmp_name" => "$wiatFilesUploadDir/{$instrumentData['CANDID']}/{$instrumentData['FILE_NAME']}"
            ];
            $this->instrumentData = $instrumentData;
        }

        function getDestinationFileName() {
            return $this->instrumentData["FILE_NAME"];
        }

        function getDestinationDirectory() {
            return $this->instrumentData["DATA_DIR"];
        }
    };

    //-----------------------------------//
    // Validate the file: exit on error  //
    //-----------------------------------//
    try {
        $error = $form->isValid($file, $args);
        if ($error !== TRUE) {
            print "{$instrumentData["FILE_NAME"]} is invalid and will not be re-uploaded: {$error[0]}\n";
        } else {
            //-------------------------------------------------//
            // Import the file in the database: exit on error  //
            //-------------------------------------------------//
            $form->importFile($file, $args);
            print "Successfully reuploaded file {$instrumentData['FILE_NAME']}\n";
        }
    } catch (Exception $e) {
        printf "{$instrumentData["FILE_NAME"]} could not be re-uploaded: " . $e->getMessage();
    }
}
?>
