<?php
/**
 * Allows for the download of files from the data release module after
 * appropriate validation on both the file and the user in question.
 *
 * PHP Version 7.1
 *
 *  @category Loris
 *  @package  Data_Release
 *  @author   Jean-Michel Raoult <jean-michel.raoult.comtl@ssss.gouv.qc.ca>
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 */

// Getting singletons
try{
           $db = \NDB_Factory::singleton()->database();
        $user = \User::singleton();
        $config =& NDB_Config::singleton();

    // If an exception is thrown
}catch(Exception $e){
    // Log the error
    error_log("Data Release Module: GetFile.php: {$e->getCode()}: {$e->getMessage()}");
    // Set the header and exit the script
    header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
    exit(2);
}
           $db = \NDB_Factory::singleton()->database();
        $user = \User::singleton();
        $config =& NDB_Config::singleton();
/* Checking the user's permissions
try{
    // If the user lacks any permission to the data release module
    if (
        !$user->hasPermission("data_release_view") &&
        !$user->hasPermission("data_release_edit")){
        // Log the error, set the appropriate header and terminate script
        error_log("ERROR: Attempting to download data release file without data release permissions.");
        header($_SERVER['SERVER_PROTOCOL'] . " 403 Forbidden", false, 403);
        exit(3);
    }
    // If an exception is thrown
}catch(ConfigurationException | Exception $e){
    // Log the error
    error_log("Data Release Module: GetFile.php: {$e->getCode()}: {$e->getMessage()}");
    // Set the header and exit the script
    header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
    exit(4);
}
 */
// Check if the submitted ID validates the expected regex
if(!preg_match("/^\d{1,6}$/", $_GET["ID"])){
    // Log the error, set the appropriate header and terminate script
    error_log("ERROR: The file ID provided to the data release module doesn't match the expected format");
    header($_SERVER['SERVER_PROTOCOL'] . " 400 Bad Request", false, 400);
    exit(5);
}

// Given that the file ID matches the expected regex, look-up the file to make sure it exists
$fileInDB = $db->pselectRow(
    "SELECT
            dr.DataReleaseID,
            dr.FileName
        FROM data_release dr
        WHERE dr.DataReleaseID = :DataReleaseID",
    array("DataReleaseID" => $_GET["ID"])
);

// If the file doesn't exist in the DB
if(empty($fileInDB)){
    // Log the error, set the appropriate header and terminate script
    error_log("ERROR: The file ID provided to the data release module matches the format but doesn't exist in the DB");
    header($_SERVER['SERVER_PROTOCOL'] . " 404 Not Found", false, 404);
    exit(6);
}

try{
    // Absolute location of the file from the config
	//$AbsolutePath = $config->getSettingFromDB("DataReleaseDirectory") . $fileInDB["FileName"];
	$AbsolutePath = "/data/incoming/". $fileInDB["FileName"];
}catch(ConfigurationException | LorisException | Exception $e){
    // Log the error
    error_log("Data Release Module: GetFile.php: {$e->getCode()}: {$e->getMessage()}");
    // Set the header and exit the script
    header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
    exit(9);
}

// Check if the file exists
if(!file_exists($AbsolutePath)){
    // Log the error
    error_log("ERROR: A file tracked in the DB for the data release module doesn't exist in the appropriate location on the server.");
    // Set the appropriate header and terminate script
    header($_SERVER['SERVER_PROTOCOL'] . " 500 Internal Server Error", false, 500);
    exit(10);
}

// Check if the file is readable
if(!is_readable($AbsolutePath)){
    // Log the error
    error_log("ERROR: A file tracked in the DB for the data release module exists but is not readable in the proper location on the server.");
    // Set the appropriate header and terminate script
    header($_SERVER['SERVER_PROTOCOL'] . " 500 Internal Server Error", false, 500);
    exit(11);
}

// Specify the length of the content
header("Content-Length: " . filesize($AbsolutePath));
// Specify the content's type
header("Content-Type: " . mime_content_type($AbsolutePath));
// Specify the filename of the file response
header("Content-disposition: attachment; filename=\"" . basename($AbsolutePath) . "\"");
// Output the file using the specified header
readfile($AbsolutePath);

// Exit the script with no error
exit(0);
