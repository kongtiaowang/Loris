<?php
namespace LORIS\imaging_uploader;
use LORIS\server_processes_manager as SP;


class Imaging_Files_Upload extends \DefaultFilesUploadHandler
{
	public function __construct(\LorisForm $lorisForm, int $dirPermissions, string $moveDirPath=null, string $dirGroup=null)
    {
		parent::__construct($lorisForm,  $dirPermissions, $moveDirPath, $dirGroup);
	}
	
	public function isValid() : bool
	{
        if(!parent::isValid()) {
			return false;
	    }
	    
	    $values = $this->getLorisForm()->getSubmitValues();
	    
        ///////////////////////////////////////////////////////////////////////
        /////////Validate the advanced Options only if it's not a Phantom//////
        ///////////////////////////////////////////////////////////////////////
        if($values['IsPhantom'] == 'N') {
            $candid      = trim($values['candID']);
            $pscid       = trim($values['pSCID']);
            $visit_label = trim($values['visitLabel']);
            $clientFileName = $this->getFiles()['mri_file']['name'];
            
            ///////////////////////////////////////////////////////////////////////
            ///////////    Make sure the file name matches the format   ///////////
            ///////////         $pscid_$candid_$visit_label             ///////////
            ///////////              OR starts with                     ///////////
            ///////////         $pscid_$candid_$visit_label_            ///////////
            ///////////////////////////////////////////////////////////////////////
            $pcv  = "{$pscid}_{$candid}_{$visit_label}";
            $pcvu = "{$pcv}_";
            if ((!preg_match("/{$pcv}\.(zip|tgz|tar.gz)/", $clientFileName))
                && (!preg_match("/^{$pcvu}.*(\.(zip|tgz|tar.gz))/", $clientFileName))
            ) {
                $this->addError(
                    'mri_file',
                    "File name must match $pcv or begin with " 
                        . "'$pcvu' and have extension .tgz, tar.gz or .zip"
                );
                error_log("--------- wrong extension, returning false");
                return false;
            }
            
            $tmpServerFileName = $this->getFiles()['mri_file']['tmp_name'];
            if (preg_match('/zip/', mime_content_type($tmpServerFileName), $matches)) {
				$this->addError(
				    'mri_file',
				    "File $clientFileName is not of type .tgz, .tar.gz or .zip."
				);
				return false;
		    }
	    }
	    
	    return true;
	}
	
	public function onFileMoveEvent(string $oldPath, string $newPath=null, string $errorMsg=null)
	{
		if(is_null($errorMsg)) {
            $db          = \Database::singleton();
            $values      = $this->getLorisForm()->getSubmitValues();
            
            $patientName = '';
            $sessionId   = '';
            ///////////////////////////////////////////////////////////////////////
            /////Get the pscid, candid and visit_label/////////////////////////////
            ///////////////////////////////////////////////////////////////////////
            if ($values['IsPhantom'] == 'N') {
                if ((!empty($values['candID']))
                    && (!empty($values['pSCID']))
                    &&(!empty($values['visitLabel']))
                ) {
                    $patientName = implode(
                        '_', array($values['pSCID'], $values['candID'], $values['visitLabel'])
                    );
                    $sessionId   = $db->pselectOne(
                        "SELECT ID 
                         FROM  session 
                         WHERE CandID = :cid AND Visit_label =:vlabel",
                        array(
                         'cid'    => $values['candID'],
                         'vlabel' => $values['visitLabel'],
                        )
                    );
                }
            }
            
            $user     = \User::singleton();
            $userName = $user->getUsername();
            
            $values = array(
                'UploadedBy'     => $userName,
                'UploadDate'     => date('Y-m-d H:i:s'),
                'UploadLocation' => $newPath,
                'SessionID'      => $sessionId,
                'PatientName'    => $patientName,
                'IsPhantom'      => $values['IsPhantom'],
            );

            $mriUploadId = null;
            if(isset($values['overwrite']) && $values['overwrite']) {
                // Only overwrite file if it failed MRI pipeline. Need to use
                // wildcard for files that were uploaded to a random temp path.
                $fileName    = $file->fileInfo['name'];
                $mriUploadId = $db->pselectOne(
                    "SELECT 
                       IF (InsertionComplete=0 AND (ISNULL(Inserting) OR Inserting=0), 
                           UploadID, 
                           NULL) as UploadID 
                     FROM mri_upload 
                     WHERE UploadLocation LIKE :ul",
                    array('ul' => "%$fileName")
                );
                
                if (!empty($mriUploadId)) {
                    $db->update('mri_upload', $values, array('UploadID' => $mriUploadId));
                }
            }
            
            if(!$mriUploadId) {
		        $db->insert('mri_upload', $values);
                $mriUploadId = $db->getLastInsertId();
			}
			
			$config = \NDB_Config::singleton();
            $ImagingUploaderAutoLaunch = $config->getSetting(
                'ImagingUploaderAutoLaunch'
            );

            if ($ImagingUploaderAutoLaunch) {
                // Instanciate the server process module to autoload
                // its namespace classes
                $spmModule = \Module::factory('server_processes_manager');

                // Perform the real upload on the server
                $serverProcessLauncher = new SP\ServerProcessLauncher();
                $serverProcessLauncher->mriUpload($mriUploadId, $newPath);
            }   
		}
	}
	
	public function processingDone()
	{
		error_log("===== processing done");
        // Cleanup
//        if(isset($this->movedFiles[$fileName])) {
//		    $uploadedFile = new SplFileObject($_FILES[$fileName]);
//			error_log("----- Code for cleanup of directory " . $uploadedFile->getPath() . " commented out");
//	if(!\Utility::deleteDirectory($uploadedFile->getPath())) {
//					error_log("Directory " . $uploadedFile->getPath() . " could not be deleted");
//				}
//            }
//
	}
}

?>
