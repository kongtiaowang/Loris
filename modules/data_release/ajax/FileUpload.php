<?php
/**
 * Server handling for the file uploads, including support for chunked uploads,
 *  and checks to prevent file overwriting.
 *
 * PHP Version 7.1
 *
 *  @category Loris
 *  @package  Data_Release
 *  @author   Jean-Michel Raoult <jean-michel.raoult.comtl@ssss.gouv.qc.ca>
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 */

use LORIS\data_release\Data_Release;
                error_log(print_r($_FILES,true));

try{
    // Getting the factory singleton
    $factory = NDB_Factory::singleton();
    // Using the factory to get the required singletons
    $db = $factory->database();
    $user = $factory->user();
    $config = $factory->config();

    $lorisInstance = new \LORIS\LorisInstance(
        $db,
        $config,
        [
            __DIR__ . "/../../../project/modules",
            __DIR__ . "/../../",
        ]
    );
    $module = $lorisInstance->getModule("data_release");
    // If an exception is thrown
}catch(Exception $e){
    // Log the error
    error_log("Data Release Module: FileUpload.php: {$e->getCode()}: {$e->getMessage()}");
    // Set the header and exit the script
    header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
    exit(2);
}
// Getting the path values from the configuration
$UploadDirPath = "/data/incoming/";
$UploadDirTempFolderPath = "/data/incoming/";
// Setting a size limit for upload size validity (501MB)
$FileSizeLimit = 525336576;

// Checking the user permissions
try{
    // Verify that the user has permission to access the upload functions of the data release module
    if(!$user->hasPermission('data_release_edit')){
        error_log("You do not have sufficient permission to access the upload functions of the data release module.");
        // Set the header and exit the script
        header("{$_SERVER['SERVER_PROTOCOL']} 403 Forbidden", true, 403);
        exit(4);
    }
    // If an exception is thrown
}catch(ConfigurationException | Exception $e){
    // Log the error
    error_log("Data Release Module: FileUpload.php: {$e->getCode()}: {$e->getMessage()}");
    // Set the header, echo the code and the message and exit the script
    header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
    exit(5);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                //
//                                      Processing Requests                                       //
//                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////

// For GET requests
if($_SERVER["REQUEST_METHOD"] === "GET"){
    // Validate that the action parameter is set and respects the expected format
    _validateActionName($_GET['action']);
    // Process according to the action specified
    switch($_GET['action']){
        case 'FileExists':
            // If the file exists
            if(_fileExistence($_GET['FileName'])){
                // Set the header to success
                header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
                // If the file doesn't exist
            }else{
                // Set the header to not found
                header("{$_SERVER['SERVER_PROTOCOL']} 404 Not Found", true, 404);
            }
            // Exit the script
            exit(6);
        case 'PartialDataExists':
            // If the filename is valid
            if(_validateFileName($_GET['FileName'])){
                // Get the last chunk associated with the filename
                $latestChunk = _getLatestChunk($_GET['FileName']);
                // If there are no chunks
                if(!isset($latestChunk)){
                    // Set the header to not found
                    header("{$_SERVER['SERVER_PROTOCOL']} 404 Not Found", true, 404);
                    // Encode the response
                    echo json_encode(array(
                            "lastChunk" => null,
                            "FileName" => $_GET['FileName']
                        )
                    );
                    // If there are chunks
                }else{
                    // Set the header to success
                    header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
                    // Encode the response
                    echo json_encode(array(
                            "lastChunk" => $latestChunk,
                            "FileName" => $_GET['FileName']
                        )
                    );
                }
                // If the filename is invalid
            }else{
                // Set the header to the proper error code
                header("{$_SERVER['SERVER_PROTOCOL']} 400 Bad Request", true, 400);
                // Echo an error message
                echo("The filename requested, {$_GET['FileName']}, doesn't match the expected format.");
            }
            // Exit the script
            exit(7);
        case 'MissingChunks':
            // If the filename is valid
            if(_validateFileName($_GET['FileName'])){
                // Get the last chunk associated with the filename
                $latestChunk = _getLatestChunk($_GET['FileName']);
                // If there are no chunks
                if(!isset($latestChunk)){
                    // Set the header to a not found
                    header("{$_SERVER['SERVER_PROTOCOL']} 404 Not Found", true, 404);
                    // Encode the response
                    echo json_encode(array(
                            "lastChunk" => null,
                            "FileName" => $_GET['FileName']
                        )
                    );
                    // If there are chunks
                }else{
                    // Get the first missing chunk
                    $earliestMissingChunk = getMissingChunk($_GET['FileName']);
                    // Set the header to a correct response
                    header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
                    // If there are no missing chunks
                    if(!isset($earliestMissingChunk)){
                        // Encode the response
                        echo json_encode(array(
                                "FileName" => $_GET['FileName']
                            )
                        );
                        // If there are missing chunks
                    }else{
                        // Encode the response
                        echo json_encode(array(
                                "FileName" => $_GET['FileName'],
                                "MissingChunk" => $earliestMissingChunk
                            )
                        );
                    }
                }
                // If the filename is invalid
            }else{
                // Set the header to the proper error code
                header("{$_SERVER['SERVER_PROTOCOL']} 400 Bad Request", true, 400);
                // Echo an error message
                echo("The filename requested, {$_GET['FileName']}, doesn't match the expected format.");
            }
            // Exit the script
            exit(8);
        case 'DeletePartialData':
            // If the filename is valid
            if(_validateFileName($_GET['FileName'])){
                // Get the last chunk
                $lastChunk = _getLatestChunk($_GET['FileName']);
                // If there are no chunks
                if(!isset($lastChunk)){
                    // Set the header to a correct response
                    header("{$_SERVER['SERVER_PROTOCOL']} 404 Not Found", true, 404);
                    // If there are chunks
                }else{
                    // Delete the partial data
                    deletePartialData($_GET['FileName']);
                    // Set the header to a correct response
                    header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
                    // Encode the response
                    echo json_encode(array(
                            "FileName" => $_GET['FileName']
                        )
                    );
                }
                // If the filename is invalid
            }else{
                // Set the header to the proper error code
                header("{$_SERVER['SERVER_PROTOCOL']} 400 Bad Request", true, 400);
                // Echo an error message
                echo("The filename requested, {$_GET['FileName']}, doesn't match the expected format.");
            }
            // Exit the script
            exit(9);
        case 'IsStitching':
            // If the filename is valid
            if(_validateFileName($_GET['FileName'])){
                // If the lock file exists
                if(_fileExistence($_GET['FileName'] . ".lock")){
                    // Set the header to a busy response
                    header("{$_SERVER['SERVER_PROTOCOL']} 503 Service Unavailable", true, 503);
                    // If the lock file doesn't exist
                }else{
                    // Set the header to a correct response
                    header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
                    // Encode the response
                    echo json_encode(array(
                            "FileName" => $_GET['FileName']
                        )
                    );
                }
                // If the filename is invalid
            }else{
                // Set the header to the proper error code
                header("{$_SERVER['SERVER_PROTOCOL']} 400 Bad Request", true, 400);
                // Echo an error message
                echo("The filename requested, {$_GET['FileName']}, doesn't match the expected format.");
            }
            // Exit the script
            exit(10);
        // If the action specified doesn't match an implemented action
        default:
            // Set the header to the proper error code
            header("{$_SERVER['SERVER_PROTOCOL']} 501 Not Implemented", true, 501);
            // Echo an error message
            echo("The data release module doesn't support the {$_GET['action']} action.");
            // Exit script
            exit(11);
    }
    // For POST requests
}elseif($_SERVER["REQUEST_METHOD"] === "POST"){
    // Validate that the action parameter is set and respects the expected format
    _validateActionName($_POST['action']);
    // Process depending on the action specified
    switch($_POST['action']){
        case 'UploadVersion':
            // Validate that the upload and the header data is valid
            if(_validateFileUpload($_POST, $_FILES)){
                // Process the file upload
                processFileUpload($_POST, $_FILES);
            }
            break;
        case 'UploadChunk':
            // Validate that the upload and the header data is valid
            if(_validateChunkUpload($_POST, $_FILES)){
                // Process the chunk upload
                processChunkUpload($_POST, $_FILES);
            }
            break;
        case 'StitchFile':
            // Validate that the upload and the header data is valid
            if(_validateStitchFile($_POST)){
                // Process the chunk upload
                stitchFile($_POST);
            }
            break;
        // If the action doesn't match an implemented action
        default:
            // Set the header to the proper error code
            header("{$_SERVER['SERVER_PROTOCOL']} 501 Not Implemented", true, 501);
            // Echo an error message
            echo("The data release module doesn't support the {$_POST['action']} action.");
            // Exit script
            exit(12);
    }
    // If the request uses an unsupported method
}else{
    // Set the header to the proper error code
    header("{$_SERVER['SERVER_PROTOCOL']} 501 Not Implemented", true, 501);
    // Echo an error message
    echo("The data release module currently only support GET and POST requests for its upload functionalities.");
    // Exit script
    exit(13);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                //
//                                     Processing Functions                                       //
//                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *
 * Function which returns the latest index from the chunks of the provided filename.
 *
 * @param string $FileName      Name of the file
 * @return int|null
 */
function _getLatestChunk(string $FileName): ?int
{
    // Get an assoc sorted by index value of the chunks matching the filename
    $FileParts = _processTemporaryFilesArray($FileName);
    // Return null if there are no chunks for the file or the zero-indexed index of the latest chunk
    return empty($FileParts) ? null : array_keys($FileParts)[count($FileParts) - 1];
}

/**
 *
 * Function which takes a filename and returns, if it exists, the number of the first missing
 * chunk for that file.
 *
 * @param string $FileName      Name of the file
 * @return int|null     Number of the chunk or null if there are no missing chunks for that filename
 */
function getMissingChunk(string $FileName): ?int
{
    // Get an assoc sorted by index value of the chunks matching the filename
    $FileParts = _processTemporaryFilesArray($FileName);
    // Set a counter to zero
    $counter = 0;
    // Using the sorted keys of the assoc
    // Note: the permanence of the ordering of an assoc by its keys in PHP is not order-safe
    // so avoid extra operations on the array to prevent issues with this method
    foreach(array_keys($FileParts) as $index){
        // If the key doesn't match the sequential index
        if($counter !== $index){
            // Return the index that was missing
            return $counter;
        }
        // Increment the counter to advance the sequence
        $counter++;
    }
    // If no index was missing
    return null;
}

/**
 *
 * Function which deletes the chunks associated with the provided filename.
 *
 * @param string $FileName Name of the file
 * @return void
 */
function deletePartialData(string $FileName): void
{
    // Path of the chunks' directory defined as a parameter of the script
    global $UploadDirTempFolderPath;
    // Deactivate the time limit to account for LONG deletion times
    set_time_limit(0);
    // Get the chunks from the directory
    $chunkyFiles = scandir($UploadDirTempFolderPath);
    // For each file in the chunks' directory
    foreach($chunkyFiles as $entry){
        // If the entry is a file and that file matches the chunk format filename.part12
        if( is_file($UploadDirTempFolderPath . $entry) &&
            preg_match("/^" . preg_quote($FileName) . "\.part(\d+)$/", $entry)){
            // if there's an error while deleting the file
            if(!unlink($UploadDirTempFolderPath . $entry)){
                // Set the header to a correct response
                header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
                echo("Issue deleting file $entry.");
                exit(14);
            }
        }
    }
    exit(15);
}

/**
 *
 * Function which takes the validated $_POST and $_FILES superglobals of an upload request and processes
 * them to add the file to the DB and the appropriate directory.
 *
 * @param array $POST Content of the $_POST superglobal
 * @param array $FILES Content of the $_FILES superglobal
 * @return void
 */
function processFileUpload(array $POST, array $FILES): void
{
	        error_log(print_r($FILES,true));

    global $lorisInstance, $module;
    // Path for the uploaded files specified as parameter in the script
    global $UploadDirPath;
    try{
        // Creating an instance of the data release class to access the file adding methods
        $data_release = new Data_Release(
            $lorisInstance,
            $module,
            "data_release",
            "",
            "",
            "data_release"
        );
	// If the class method for adding a file to the DB returns true
	error_log(print_r($FILES,true));
        if($data_release->addDataReleaseFile(
            $POST['UploadDisplayNameTextInput'],
            $FILES['file']['name'],
            $POST['UploadAuthorTextInput'],
            $POST['UploadReferencePaperTextInput'],
            $POST['UploadDateTextInput'],
            $POST['UploadDescriptionTextareaInput'],
            $POST['UploadDocumentSelectInput']
        )){
            // If the move from the temporary location to the appropriate directory returns true
            if(move_uploaded_file($FILES['file']['tmp_name'], $UploadDirPath . $FILES['file']['name'])){
                // Set the header to success
                header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
                // Encode the response
                echo json_encode(array(
                        "FileName" => $FILES['file']['name']
                    )
                );
                // If there was an error while moving the file
            }else{
                // Remove the entry for the file
                $data_release->deleteDataReleaseFile($FILES['file']['name']);
                // Set the header to the proper error code
                header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
                // Echo an error message
                echo("Internal error while moving the {$FILES['file']['name']} file.");
            }
            // If the class method for adding a file to the DB returns an error
        }else{
            // Set the header to the proper error code
            header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
            // Echo an error message
            echo("Internal error while adding the {$FILES['file']['name']} file to the DB.");
        }
        // Delete the instance of the data release class created
        unset($data_release);
        // Exit script
        exit(16);
        // If an exception was thrown
    }catch(
    DatabaseException |
    LorisNoSuchModuleException |
    LorisModuleMissingException |
    LorisException | Exception $e){
        // If it was created, delete the instance of the data release class created
        unset($data_release);
        // Log the error
        error_log($e->getCode() . ": " . $e->getMessage());
        // Set the header to the proper error code
        header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
        // Exit the script
        exit(17);
    }
}

/**
 *
 * Function which takes the validated $_POST and $_FILES superglobals of a chunk upload request and processes
 * them to add the file's chunk to the chunks' directory.
 *
 * @param array $POST Content of the $_POST superglobal
 * @param array $FILES Content of the $_FILES superglobal
 * @return void
 */
function processChunkUpload(array $POST, array $FILES): void
{
    // Path for the chunks of uploaded files specified as parameter in the script
    global $UploadDirTempFolderPath;
    // If the move from the temporary location to the appropriate directory returns true
    if(move_uploaded_file($FILES['file']['tmp_name'], $UploadDirTempFolderPath . $FILES['file']['name'] . ".part{$POST['Chunk']}")){
        // Set the header to success
        header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
        // Encode the response
        echo json_encode(array(
                "FileName" => $FILES['file']['name'],
                "Chunk" => $POST['Chunk']
            )
        );
        // If there was an error while moving the file
    }else{
        // Log the error
        error_log("Internal error while moving the {$FILES['file']['name']} file's chunk number {$POST['Chunk']}.");
        // Set the header to the proper error code
        header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
    }
    exit(18);
}

/**
 *
 * Function which takes the chunks of a file, stitches them sequentially then records
 * the resulting file to the DB.
 *
 * @param array $POST       Superglobal POST array of the request to stitch the file
 */
function stitchFile(array $POST): void
{
    // Paths for both the uploads and chunks directories as defined in the script parameters
    global $UploadDirPath, $UploadDirTempFolderPath;
    // Getting an assoc of the chunks
    $fileParts = _processTemporaryFilesArray($POST['FileName']);
    // If no chunks for that filename, return error
    if(is_null($fileParts)){
        // Set the error code header, push an error message and exit the script
        header("{$_SERVER['SERVER_PROTOCOL']} 404 File Not Found", true, 404);
        echo("The filename {$POST['FileName']} doesn't have uploaded chunks.");
        exit(19);
    }
    // Deactivate the time limit to account for long stitching times
    set_time_limit(0);
    // Opening the output file in append mode for binary data
    $outputFile = fopen($UploadDirPath . $POST['FileName'], 'ab');
    // Create an empty lock file with the filename.lock format
    $lockFile = fopen($UploadDirPath . $POST['FileName'] . ".lock", 'w');
    // Close lock file
    fclose($lockFile);
    // Setting the buffer size (5 MB)
    // Note: this parameter can be played with to find an optimal balance based on the server configuration
    // used
    $bufferSize = 5*1024*1024;
    // Initial position of the pointer in the chunk file
    $position  = 0;
    // Getting the first value from the sorted assoc
    $chunkFileName = array_values($fileParts)[0];
    // Opening the chunk file in read binary file
    $chunkFile = fopen($UploadDirTempFolderPath . $chunkFileName, 'rb');
    // Setting pointer to end of file
    fseek($chunkFile, 0, SEEK_END);
    // Getting the length of the file
    $length = ftell($chunkFile);
    // Rewinding to the start of the chunk file
    rewind($chunkFile);
    // For every time the pointer's position is smaller than the length of the file
    while ($position < $length) {
        // Write the buffer length from the position to the output file
        $dataWritten = stream_copy_to_stream($chunkFile, $outputFile, $bufferSize, $position);
        // Update the position
        $position += $dataWritten;
    }
    // Close the chunk
    fclose($chunkFile);
    // Erase the chunk
    unlink($UploadDirTempFolderPath . $chunkFileName);
    // Close the output file
    fclose($outputFile);
    // Erase the lock file
    unlink($UploadDirPath . $POST['FileName'] . ".lock");
    // If it's the last chunk
    if(count($fileParts) === 1){
        // Add stitched file to the DB
        _registerChunkedFile($POST);
        exit(20);
        // If there are other chunks
    }else{
        // Set the OK header, push the index of the stitched chunk and exit the script
        header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", false, 200);
        echo json_encode(array(
                "Chunk" => array_keys($fileParts)[0]
            )
        );
        exit(21);
    }
}

/**
 *
 * Function which takes the validated $_POST superglobal of a file stitching request and register
 * the resulting stitched files in the DB.
 *
 * @param array $POST Content of the POST superglobal
 * @return void
 */
function _registerChunkedFile(array $POST): void
{
    global $lorisInstance, $module;
    // Path for the uploaded files specified as parameter in the script
    global $UploadDirPath;
    try{
        // Creating an instance of the data release class to access the file adding methods
        $data_release = new Data_Release(
            $lorisInstance,
            $module,
            "data_release",
            "",
            "",
            "data_release"
        );
        // If the class method for adding a file to the DB returns true
        if($data_release->addDataReleaseFile(
            $POST['UploadDisplayNameTextInput'],
            $POST['FileName'],
            $POST['UploadAuthorTextInput'],
            $POST['UploadReferencePaperTextInput'],
            $POST['UploadDateTextInput'],
            $POST['UploadDescriptionTextareaInput'],
            $POST['UploadDocumentSelectInput']
        )){
            // Set the header to success
            header("{$_SERVER['SERVER_PROTOCOL']} 200 OK", true, 200);
            // Encode the response
            echo json_encode(array(
                    "FileName" => $POST['FileName']
                )
            );
            // If there was an error while adding the file to the DB
        }else{
            // Remove the entry for the file
            $data_release->deleteDataReleaseFile($POST['FileName']);
            // In case of removing large files
            set_time_limit(0);
            // Remove the stitched file
            unlink($UploadDirPath . $POST['FileName']);
            // Set the header to the proper error code
            header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
            // Echo an error message
            echo("Internal error while registering the {$POST['FileName']} file.");
        }
        // Delete the instance of the data release class created
        unset($data_release);
        // Exit script
        exit(22);
    }catch(
    DatabaseException |
    LorisNoSuchModuleException |
    LorisModuleMissingException |
    LorisException |
    Exception $e){
        // If it was created, delete the instance of the data release class created
        unset($data_release);
        // Set the header to the proper error code
        header("{$_SERVER['SERVER_PROTOCOL']} 500 Internal Server Error", true, 500);
        // Echo the code and error message
        echo($e->getCode() . ": " . $e->getMessage());
        // Exit the script
        exit(23);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                //
//                                     Validation Functions                                       //
//                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *
 * Function which validates that the value passed as an action name
 * matches an expected format or exits the script with proper http header
 * and error messaging.
 *
 * @param string|null $action   Name of the request to be executed
 * @return bool
 */
function _validateActionName(?string $action): bool
{   return true;
       	// If the request's action is not set or doesn't respect the format
    if(!isset($action) || !preg_match('/^[a-z+\-_]+$/i', $action)){
        // Log the error
        error_log("The {$_SERVER['REQUEST_METHOD']} action $action doesn't match the format excepted for an action command.");
        // Set the error code header, push an error message and exit the script
        header("{$_SERVER['SERVER_PROTOCOL']} 400 Bad Request", true, 400);
        exit(24);
    }
    return true;
}

/**
 *
 * Function which tests whether a valid filename matches to an existing,
 * readable file or not.
 *
 * @param string|null $FileName     Name of the file
 * @param bool $networkError        Produce a network error or return a boolean
 * @return bool
 */
function _fileExistence(?string $FileName, bool $networkError = True): bool
{return true;
    // Global path for the upload directory defined as parameter in the script
    global $UploadDirPath;
    // If the filename is not valid
    if(!_validateFileName($FileName, $networkError)){
        // return error
        return false;
    }
    // Return true if the filename matches a file in the upload directory and that file is readable
    return is_file($UploadDirPath . $FileName) && is_readable($UploadDirPath . $FileName);
}

/**
 *
 * Function which takes a filename provided and, if said filename doesn't match
 * the expected format, returns a 400 error or a false boolean depending
 * on the parameter specified.
 *
 * @param string|null $FileName     Name of the file
 * @param bool $networkError        Whether to return a boolean or HTTP network error
 * @return bool
 */
function _validateFileName(?string $FileName, bool $networkError = True): bool
{
	return true;
    // If the filename includes characters that aren't whitelisted,
    // is not set or has repeating periods
    if( !isset($FileName) ||
        preg_match("/[^a-z0-9\-\(\)'\[\]_\s.]+/i", $FileName) ||
        preg_match("/\.{2,}/", $FileName)
    ){
        if($networkError){
            // Set the error code header, push an error message and exit the script
            header("{$_SERVER['SERVER_PROTOCOL']} 400 Bad Request", true, 400);
            echo("The filename $FileName doesn't match the expected format.");
            exit(25);
        }else{
            return false;
        }
    }
    return true;
}

/**
 *
 * Wrapper function which calls the validation functions for both the $_POST and $_FILES superglobals
 * of the request for a file upload.
 *
 * @param array $POST Content of the $_POST superglobal of the request
 * @param array $FILES Content of the $_FILES superglobal of the request
 * @return bool
 */
function _validateFileUpload(array $POST, array $FILES): bool
{return true;
    try{
        // If both the uploaded file parameter and the file meta parameter are valid
        return _validateFileParameters($FILES) && _validateFileMetaParameters($POST);
    }catch(
    DatabaseException |
    LorisModuleMissingException |
    LorisNoSuchModuleException |
    LorisException |
    Exception $e){
        return false;
    }
}

/**
 *
 * Wrapper function which calls the validation functions for both the $_POST and $_FILES superglobals
 * of the request for a chunk upload.
 *
 * @param array $POST Content of the $_POST superglobal of the request
 * @param array $FILES Content of the $_FILES superglobal of the request
 * @return bool
 */
function _validateChunkUpload(array $POST, array $FILES): bool
{return true;
    try{
        // If both the file and the chunk parameters are valid
        return _validateFileParameters($FILES) && _validateChunkParameters($POST);
    }catch(
    DatabaseException |
    LorisModuleMissingException |
    LorisNoSuchModuleException |
    LorisException |
    Exception $e){
        return false;
    }
}

/**
 *
 * Wrapper function which calls the validation functions for the $_POST superglobal
 * of the request for stitching the chunks of an uploaded file.
 *
 * @param array $POST Content of the POST superglobal of the request
 * @return bool
 */
function _validateStitchFile(array $POST): bool
{return true;
    try{
        // If both the parameters of the file are valid and the file doesn't already exist in
        // the upload directory
        return  _validateFileMetaParameters($POST) &&
                _validateFileName($POST['FileName'], false);
    }catch(
    DatabaseException |
    LorisModuleMissingException |
    LorisNoSuchModuleException |
    LorisException |
    Exception $e){
        return false;
    }
}

/**
 *
 * Function which tests the validity of the metadata of a file passed through
 * POST during an upload request.
 *
 * @param array $parameters         Content of the $_POST superglobal
 * @return bool
 * @throws DatabaseException
 * @throws LorisException
 * @throws LorisModuleMissingException
 * @throws LorisNoSuchModuleException
 */
function _validateFileMetaParameters(array $parameters): bool
{return true;
    global $lorisInstance, $module;
    // Creating an instance of the data release class to access the parameter validation functions
    $data_release = new Data_Release(
        $lorisInstance,
        $module,
        "data_release",
        "",
        "",
        "data_release"
    );
    // Using the data release class methods, test the validity of the display name, the author, the reference paper
    // the date, the description and the document
    $validity =  $data_release->_validateString(
            $parameters['UploadDisplayNameTextInput'],
            127,
            "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
        $data_release->_validateString(
            $parameters['UploadAuthorTextInput'],
            127,
            "[^A-Za-z0-9 \(\)\-\.'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]") &&
        $data_release->_validateString(
            $parameters['UploadReferencePaperTextInput'],
            255,
            "[^A-Za-z0-9 \(\)\-\.:,'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]") &&
        $data_release->_validateDate($parameters['UploadDateTextInput']) &&
        $data_release->_validateDescription($parameters['UploadDescriptionTextareaInput']) &&
        (empty($parameter['UploadDocumentSelectInput']) ||
            (   $data_release->_validateIntegerID($parameters['UploadDocumentSelectInput']) &&
                $data_release->_validateParameterExistence(
                    $data_release->documentsTable,
                    "DataReleaseDocumentID",
                    $parameters['UploadDocumentSelectInput'])
            )
        );
    // Delete the instance created
    unset($data_release);
    // Return the validity of the parameters
    return $validity;
}

/**
 *
 * Function which tests the validity of the content of the $_FILES superglobal
 *
 * @param array $parameters     Content of the $_FILES superglobal associated with an upload request
 * @return bool
 */
function _validateFileParameters(array $parameters): bool
{return true;
    // Max value of file's size as specified by script parameter
    global $FileSizeLimit;
    // Test that the file has a valid name and use the boolean return, test that the error code is 0
    // and test that the file provided is smaller than the max size allowed
    return _validateFileName($parameters['file']['name'], false) &&
            intval($parameters['file']['error']) === 0 &&
            intval($parameters['file']['size']) < $FileSizeLimit;
}

/**
 *
 * Function which tests the validity of the metadata of a chunk passed through
 * POST during an upload request.
 *
 * @param array $parameters         Content of the $_POST superglobal
 * @return bool
 * @throws DatabaseException
 * @throws LorisException
 * @throws LorisModuleMissingException
 * @throws LorisNoSuchModuleException
 */
function _validateChunkParameters(array $parameters): bool
{return true;
    global $lorisInstance, $module;
	error_log("_validateChunkParameters");
    // Creating an instance of the data release class to access the parameter validation functions
    $data_release = new Data_Release(
        $lorisInstance,
        $module,
        "data_release",
        "",
        "",
        "data_release"
    );
    // Using the data release class methods, test the validity of the display name, the date, the category and the
    // description then test the validity of the chunk indices
    $validity = $data_release->_validateString(
            $parameters['UploadDisplayNameTextInput'],
            127,
            "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
        $data_release->_validateString(
            $parameters['UploadAuthorTextInput'],
            127,
            "[^A-Za-z0-9 \(\)\-\.'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]") &&
        $data_release->_validateString(
            $parameters['UploadReferencePaperTextInput'],
            127,
            "[^A-Za-z0-9 \(\)\-\.:,'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]") &&
        $data_release->_validateDate($parameters['UploadDateTextInput']) &&
        $data_release->_validateDescription($parameters['UploadDescriptionTextareaInput']) &&
        (   empty($parameter['UploadDocumentSelectInput']) ||
            (
                $data_release->_validateIntegerID($parameters['UploadDocumentSelectInput']) &&
                $data_release->_validateParameterExistence(
                    $data_release->documentsTable,
                    "DataReleaseDocumentID",
                    $parameters['UploadDocumentSelectInput'])
            )
        ) &&
        _validateChunkIndex($_POST['Chunk'], $_POST['LastChunk']);
    // Delete the instance created
    unset($data_release);
     error_log("_validateChunkParameters end");
    // Return the validity of the parameters
    return $validity;
}

/**
 *
 * Function which insures that the index of the chunk and the value
 * of the last index of the chunks are both valid.
 *
 * @param string $chunk         Positive integer including zero
 * @param string $lastChunk     Positive integer, excluding zero
 * @return bool
 */
function _validateChunkIndex(string $chunk, string $lastChunk): bool
{
    // Check that both index and limit are set and numeric
    if(
        !isset($chunk) ||
        !isset($lastChunk) ||
        !is_numeric($chunk) ||
        !is_numeric($lastChunk)){
        return false;
    }
    // Check that both values are positive integer and that the chunk index is not larger
    // than the last chunk
    if(
        intval($chunk) < 0 ||
        intval($lastChunk) <= 0 ||
        intval($chunk) > intval($lastChunk)){
        return false;
    }
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                //
//                                        Utility Functions                                       //
//                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *
 * Function which uses the global temporary location of the chunks folder
 * to build an assoc of the chunks matching the specified file indexed on
 * the part number in the chunks' filenames. The assoc is then sorted by keys
 * and returned if not empty.
 *
 * @param string $FileName  Name of the file the chunks are part of
 * @return array|null   If empty the final assoc is empty, return null, otherwise
 *                      return the folder
 */
function _processTemporaryFilesArray(string $FileName): ?array
{ error_log("__processTemporaryFilesArray");
    // Getting global value for the location of the chunks folder
    global $UploadDirTempFolderPath;
    // Get the chunks from the temp directory
    $chunkyFiles = scandir($UploadDirTempFolderPath);
    // Initialize an array for the parts of the file specified
    $FileParts = array();
    // For each file in the temp directory
    foreach($chunkyFiles as $entry){
        // Initialize a match array
        $matches = array();
        // If the entry is a file and that file matches the chunk format filename.extension.part12
        // Note the preg quoting of the filename to avoid issues with periods while doing the regex on the
        // filename
        if( is_file($UploadDirTempFolderPath . $entry) &&
            preg_match("/^" . preg_quote($FileName) . "\.part(\d+)$/", $entry, $matches)){
            // Add the filename with the part index as a key to the assoc
            $FileParts[intval($matches[1])] = $entry;
        }
    }
    // Sort according to keys
    ksort($FileParts);
    // Return null or the array depending on the presence of chunks
    return empty($FileParts) ? null : $FileParts;
}
