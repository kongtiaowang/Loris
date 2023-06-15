<?php
/**
 * Mri_upload class file
 *
 * PHP version 5
 *
 * @category Behavioural
 * @package  Main
 * @author   Zia Mohaddes  <zia.mohades@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/mohadesz/Loris-Trunk
 */
namespace LORIS\imaging_uploader;
use LORIS\server_processes_manager as SP;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

/**
 * Post method handles updating a file.
 * Delete method handles deleting a file.
 * Get method handles getting a file.
 * Put method handles editing a file.
 * This class contains functions providing upload and edit functionality for
 * files in the document_repository.
 *
 * @license http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 */
class Upload_Process extends \NDB_Page
{
    var $mri_upload_id;
    var $AjaxModule      = true;
    public $skipTemplate = true;
    var $show_queries    = true;
    var $temp_path       = null;	

    /**
     * Same as the permissions for the main menu filter page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true only if the user has access to this page.
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('imaging_uploader');
	    
    }

    /**
     * Handle how to operate all the files.
     * PUT method updates a file's info.
     * DELETE method deletes a file.
     * POST method uploads a file.
     * GET method gets a file.
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     */
    public function handle(ServerRequestInterface $request): ResponseInterface
    {
        switch ($request->getMethod()) {
	case "POST":
		    $postData = $request->getParsedBody();
		    $file  = $_FILES['mriFile'];
		    $postData['mriFile']=$file;
		return $this->uploadFile($request,$postData);
        default:
            return (new \LORIS\Http\Response\JSON\MethodNotAllowed(
                ["POST"]
            ));
        }
    }
    /**
     * Handles the document editing process
     *
     * @param ServerRequestInterface $req The incoming PSR7 request
     *
     * @return ResponseInterface
     */
    function uploadFile($request,$values)
    {
	$this->valid($values);
        $instance = $request->getAttribute('loris');
        $db       = $instance->getDatabaseConnection();
        $config   = $instance->getConfiguration();
        $user     = $request->getAttribute('user');
        $name     = $user->getUsername();
	$overwrite = $values['overwrite'] ?? false;
	$updateFile  = $overwrite;
        error_log("999999999999999999999");
        // Initialize FilesUploadHandler
        $path = \Utility::pathJoin(
            $config->getSetting("MRIUploadIncomingPath"),
            $name
        );
        if (!is_dir($path)) {
            mkdir($path, 0770);
        }
	error_log($path);
	$targetdir = new \SplFileInfo($path);
	        error_log($targetdir);

        try {
            $uploader = (new \LORIS\FilesUploadHandler($targetdir))
                ->withPermittedMIMETypes(
			'application/zip',
			'application/tar+gzip',
			'application/x-gzip',
                );
        } catch (\ConfigurationException $e) {
            return new \LORIS\Http\Response\JSON\InternalServerError(
                $e->getMessage()
            );
	}
  error_log("88888");

$uploader=$uploader->withOverwrite($overwrite);
        $response = $uploader->handle($request);
        if (!in_array($response->getStatusCode(), [200, 201], true)) {
            // Something went wrong. Return early to skip further processing.
            return $response;
	}
        $user_name = $values['user_id'] ?? null;
        if (($user_name==null) || (!(isset($user_name)))) {
            $user      = \User::singleton();
            $user_name = $user->getUsername();
	}
	        error_log("77777");

        ///////////////////////////////////////////////////////////////////////
        ////////////////////Insert values into mri_upload//////////////////////
        ///////////////////////////////////////////////////////////////////////
        $date = date('Y-m-d H:i:s');

        ///////////////////////////////////////////////////////////////////////
        /////Get the pscid, candid and visit_label/////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        if ($values['IsPhantom']=='N') {
            if ((!empty($values['candID']))
                && (!empty($values['pSCID']))
                &&(!empty($values['visitLabel']))
            ) {
                ///////////////////////////////////////////////////////////////////
                ////////////////////Use the arguments//////////////////////////////
                ///////////////////////////////////////////////////////////////////
                $visit_label = $values['visitLabel'];
                $candid      = $values['candID'];
                $pscid       = $values['pSCID'];
                $pname       = $pscid. "_" . $candid . "_" . $visit_label;
                $sessionid   = $db->pselectOne(
                    "SELECT ID FROM  session WHERE CandID = :cid
                     AND Visit_label =:vlabel",
                    [
                        'cid'    => $candid,
                        'vlabel' => $visit_label,
                    ]
                );
            }
	}
	   error_log("66666666");
        ///////////////////////////////////////////////////////////////
        ///if the DestinationDirectory/getDestinationFilename//////////
        //is not empty, then remove the uploaded directory in the /tmp/
        ////Otherwise keep uploaded directory in the /tmp and insert///
        ////into the mri_upload table//////////////////////////////////
        ///////////////////////////////////////////////////////////////
        $values = [
            'UploadedBy'               => $user_name,
            'UploadDate'               => $date,
            'UploadLocation'           => $targetdir."/".$values['mriFile']['name'],
            'SessionID'                => $sessionid ?? null,
            'PatientName'              => $pname ?? '',
            'IsPhantom'                => $values['IsPhantom'],
            'TarchiveID'               => null,
            'Inserting'                => null,
            'InsertionComplete'        => 0,
            'IsCandidateInfoValidated' => null,
            'IsTarchiveValidated'      => 0,
            'number_of_mincInserted'   => null,
            'number_of_mincCreated'    => null,
	];
        if ($updateFile) {
            // Only overwrite file if it failed MRI pipeline. Need to use
            // wildcard for files that were uploaded to a random temp path.
            $fileName = $targetdir."/".$values['mriFile']['name'];
            $id       = $db->pselectOne(
                "SELECT
                IF (InsertionComplete=0 AND
                (ISNULL(Inserting) OR Inserting=0), UploadID, NULL) as UploadID
                FROM mri_upload WHERE UploadLocation LIKE :ul",
                ['ul' => "%$fileName"]
	    );

            if (!empty($id)) {
                $db->update('mri_upload', $values, ['UploadID' => $id]);
                $this->mri_upload_id = $id;
                return true;
            }
	} else {
        $db->insert('mri_upload', $values);
	$this->mri_upload_id = $db->getLastInsertId();
            $db->update(
                'notification_spool',
                ['Active' => 'N'],
                ['ProcessID' => $this->mri_upload_id]
            );

            // Save file succeeded. All that's left to do is launch the MRI
            // pipeline if the auto-launch switch is on
            $config = \NDB_Config::singleton();
            $ImagingUploaderAutoLaunch = $config->getSetting(
                'ImagingUploaderAutoLaunch'
            );
            if ($ImagingUploaderAutoLaunch == '1'
                || $ImagingUploaderAutoLaunch == 'true'
            ) {
                try {
                    // Perform the real upload on the server
                    $serverProcessLauncher = new SP\ServerProcessLauncher();
                    $serverProcessLauncher->mriUpload(
                        $this->mri_upload_id,
                        $this->uploaded_file_path
                    );
                    $db->update(
                        'mri_upload',
                        ['Inserting' => 1],
                        ['UploadID' => $this->mri_upload_id]
                    );
                } catch (\Exception $e) {
                    $notificationTypeID = $db->pselectOne(
                        "SELECT NotificationTypeID
                         FROM notification_types
                         WHERE Type = :type",
                        ['type' => 'mri upload handler emergency']
                    );
                    $values = [
                        'NotificationTypeID' => $notificationTypeID,
                        'Message'            => 'MRI pipeline could not be '
                                              . 'started: ' . $e->getMessage() . "\n"
                                              . 'This indicates an incorrect or non-'
                                              . "existent MRI pipeline setup\n",
                        'Origin'             => 'Launch of the MRI pipeline',
                        'ProcessID'          => $this->mri_upload_id,
                        'Error'              => 'Y',
                        'Verbose'            => 'N',
                    ];
                    $db->insert('notification_spool', $values);
                    $db->update(
                        'mri_upload',
                        ['Inserting' => 0],
                        ['UploadID' => $this->mri_upload_id]
		    );
		}            error_log("333333");

	 return (new \LORIS\Http\Response())
            ->withStatus(200)
            ->withHeader("Content-Type", "text/plain")
            ->withBody(
                new \LORIS\Http\StringStream(
                    "Error")
            );
                }
            }
         return (new \LORIS\Http\Response())
            ->withStatus(200)
            ->withHeader("Content-Type", "text/plain")
            ->withBody(
                new \LORIS\Http\StringStream(
                    "Done")
            );
        }


    function valid($values)
    {
	           $errors = [
            'IsPhantom'  => [],
            'candID'     => [],
            'pSCID'      => [],
            'visitLabel' => [],
            'mriFile'    => [],
        ];
	                error_log("valid");
        //make sure the file-name is  valid
        $temp_file = $values['mriFile']['tmp_name'];
        $db        = $this->loris->getDatabaseConnection();
        // creates associative array to store error messages for each form element
        // creates empty string variable to store error message for wrong file name
        $file_name_error = "";
        $config          = \NDB_Config::singleton();
        $file_name       = $values['mriFile']['name'];

        ///////////////////////////////////////////////////////////////////////
        ////////////// Checks to see if the file is of type////////////////////
        //////////////.gz, .zip or .tgz////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        if (!$this->isCompressed($temp_file)) {
            array_push(
                $errors["mriFile"],
                "The file $file_name is not of type".
                " .tgz, .tar.gz or .zip."
            );
        }

        ///////////////////////////////////////////////////////////////////////
        /////////Validate the advanced Options only if it's not a Phantom//////
        ///////////////////////////////////////////////////////////////////////
        if ($values['IsPhantom']=='N') {
            $candid      = trim($values['candID']);
            $pscid       = trim($values['pSCID']);
            $visit_label = trim($values['visitLabel']);
            ////////////////////////////////////////////////////////////////
            //////     checks if candid exists                        //////
            //////     checks if pscid is valid for candid            //////
            //////     checks if visit_label is valid for candid      //////
            //////     checks if candidate is active                  //////
            //////     checks if session is active                    //////
            //////     stores error messages in associative array     //////
            ////////////////////////////////////////////////////////////////
            if ((!empty($candid)) && (!empty($pscid)) && (!empty($visit_label))) {
                $candidate = $db->pselectRow(
                    "SELECT c.candid AS candid,
                     c2.candid AS candid_with_pscid,
                     s.visit_label,
                     c2.active AS candidate_active,
                     s.active AS session_active
                     FROM candidate c
                     LEFT JOIN candidate c2
                     ON (c.candid=c2.candid AND c2.pscid = :pid)
                     LEFT JOIN session s
                     ON (s.candid=c.candid and s.visit_label = :vlabel)
                     WHERE c.candid = :cid",
                    [
                        ':cid'    => $candid,
                        ':pid'    => $pscid,
                        ':vlabel' => $visit_label,
                    ]
                );
                if (is_null($candidate) || $candidate["candid"] !== $candid) {
                    array_push(
                        $errors["candID"],
                        "The CandID " . $candid .
                        " does not exist in the database."
                    );
                } else {
                    if (!$candidate['candid_with_pscid']) {
                        array_push(
                            $errors["pSCID"],
                            "Invalid PSCID " . $pscid .
                             " for CandID " . $candid .
                             ". Check that you entered the correct" .
                             " PSCID and CandID."
                        );
                    }
                    if (!$candidate['visit_label']) {
                            array_push(
                                $errors["visitLabel"],
                                "Invalid Visit Label " . $visit_label .
                                " for CandID " . $candid .
                                ". Check that you entered the correct" .
                                " Visit Label and CandID."
                            );
                    }
                    if ($candidate['candidate_active'] == 'N') {
                        array_push(
                            $errors["pSCID"],
                            "The candidate associated with CandID " .
                            $candid . " and PSCID " .
                            $pscid . " is not active in the database."
                        );
                    }
                    if ($candidate['session_active'] == 'N') {
                        array_push(
                            $errors["visitLabel"],
                            "The session associated with CandID " .
                            $candid . " and Visit Label " .
                            $visit_label . " is not active in".
                            " the database."
                        );
                    }
                }
            }
            ///////////////////////////////////////////////////////////////////////
            ///////////    Make sure the file name matches the format   ///////////
            ///////////         $pscid_$candid_$visit_label             ///////////
            ///////////              OR starts with                     ///////////
            ///////////         $pscid_$candid_$visit_label_            ///////////
            ///////////    Stores error message in string variable      ///////////
            ///////////////////////////////////////////////////////////////////////
            $pcv  = $pscid . "_" . $candid . "_" . $visit_label;
            $pcvu = $pcv . "_";
            if ((!preg_match("/^{$pcv}\.(zip|tgz|tar.gz)/", $file_name))
                && (!preg_match("/^{$pcvu}.*(\.(zip|tgz|tar.gz))/", $file_name))
            ) {
                     $file_name_error
                         = "File name and fields entered in CandID, PSCID," .
                     " Visit Label must match. Verify that the information" .
                     " entered in all the fields above is correct or rename" .
                     " the file so that the file name matches " . $pcv .
                     " or begins with " . "\"". $pcvu . "\"" .
                     ", and has the extension .tgz, tar.gz or .zip";
            }
        }

        ///////////////////////////////////////////////////////////////////////
        //////// Make sure there's no existing identical entry ////////////////
        //////// for "new" scans //////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        $updateFile = isset($values['overwrite'])
		? (boolean) $values['overwrite'] : false;
 if (!$updateFile){
        $id         = $db->pselectOne(
            "SELECT
                IF (InsertionComplete=0 AND
                (ISNULL(Inserting) OR Inserting=0), UploadID, NULL) as UploadID
                FROM mri_upload WHERE UploadLocation LIKE :ul",
            ['ul' => "%$file_name"]
	);
 }
        $uploadPath = $config->getSetting('MRIUploadIncomingPath') . $file_name;

        if (!$updateFile && !empty($id) && file_exists($uploadPath)) {
            array_push(
                $errors['mriFile'],
                "This file has already been uploaded."
            );
        }
        // Loops through associative array of error messages
        // If there are error messages, array is passed to front end
        // If there are no error messages but the file name is wrong,
        // file name error is added to array and array is passed to front end
        // This way, file name error is thrown after other fields are validated
        $associative_array_errors = false;
        foreach ($errors as $error) {
            if (count($error) != 0) {
                $associative_array_errors = true;
            }
        }
        if ($associative_array_errors) {
	
	            http_response_code(400);
            header('Content-Type: application/json; charset=UTF-8');
		    exit(json_encode(['errors' => $errors]));
	} else if (strlen($file_name_error) != 0) {
            array_push($errors["mriFile"], $file_name_error);
            http_response_code(400);
            header('Content-Type: application/json; charset=UTF-8');
            exit(json_encode(['errors' => $errors]));       
	}
        ///////////////////////////////////////////////////////////////////////
        /////////copy the temporary file to a temporary directory//////////////
        //////////with a correct extension/////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        $temp_dir      = $this->tempdir();
        $new_temp_file = $temp_dir. "/". $values['mriFile']['name'];
        if (!copy($temp_file, $new_temp_file)) {
            $msg = "An internal server error prevented this file from being "
                 . "uploaded. Please contact the system administrator: "
                 . "failed to copy $temp_file to $new_temp_file";
	    array_push($errors["mriFile"], $msg);
	                http_response_code(400);
            header('Content-Type: application/json; charset=UTF-8');
            exit(json_encode(['errors' => $errors]));
        }
            error_log("------");

	$this->setTempPath($new_temp_file);
	return true;
    }    
    /**
     * Creates a temporary directory
     *
     * @return String
     */
    function tempdir()
    {
        $tempfile =tempnam(
            sys_get_temp_dir(),
            ''
        );
        if (file_exists($tempfile)) {
            unlink($tempfile);
        }
        mkdir($tempfile);
        if (is_dir($tempfile)) {
            return $tempfile;
        }
    }
    /**
     * The SetTempDir sets the tempdir
     *
     * @param string $tempFilePath The path to the temp file
     *
     * @return NULL
     */
    function setTempPath($tempFilePath)
    {
        $this->temp_path = $tempFilePath;
    }
    /**
     * The getTempPath gets the temp_path
     *
     * @return String returns temp_path
     */
    function getTempPath()
    {
        return $this->temp_path;
    }
    /**
     * The getTargetDirectory retrieves info about where the file should be stored.
     *
     * The returned directory is added to the baseUploadDirectory property.
     * It should have a trailing slash.
     *
     * @param string $file The full filename including directory.
     * @param Array  $args The list of arguments
     *
     * @return string  $success if operation succeeded
     */
    function getTargetDirectory($file, $args)
    {
        return sprintf(
            "%s/",
            $args['user_id'] ?? \User::singleton()->getUsername()
        );
    }
    /**
     * The function isCompressed returns true if the file is
     * compressed (gzip or zip) or false otherwise
     *
     * @param string $file The full filename including directory
     *
     * @return bool Whether the file is compressed
     */
    function isCompressed($file)
    {
        return strpos(mime_content_type($file), 'zip') !== false;
    }
    /**
     * The function removes the uploaded file from the /tmp directory
     * only if the file is moved from the /tmp directory to the
     * MRI-Upload Directory
     *
     * @return bool  $success if operation succeeded
     */
    function removeTempDir()
    {
        $tempFolderPath = dirname($this->getTempPath());
        $success        = false;
        if (($tempFolderPath) && (is_dir($tempFolderPath))) {
            $success = $this->removeDir($tempFolderPath);
        }
        return $success;
    }
    /**
     * The function removes the directory and all its contents
     *
     * @param string $folder The full folder path
     *
     * @return bool  $success if operation succeeded
     */
    function removeDir($folder)
    {
        $d = dir($folder);
        while ($entry = $d->read()) {
            if ($entry!= "." && $entry!= "..") {
                unlink($folder . "/" . $entry);
            }
        }
        return rmdir($folder);
    }    
}
