<?php
/*
 * This file contains the NDB_BVL_Instrument_PVT
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Moshood Kolawole <moshood.kolawole@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the PVT instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Moshood Kolawole <moshood.kolawole@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_PVT extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
                       "participant","trial","isi","abstime","rt","type","valid_response","false_starts","timeouts","mean_rt","standard_deviation_rt","minimum_rt","maximum_rt"
        );
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "PVT";            // test_names.Test_name
        $this->table = 'PVT';              // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        // setup the form
        $this->_setupForm();
    }

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */

    function _setupForm()
    {   
            $this->_main();

        $this->form->addFormRule(array(&$this, 'XINValidate'));

    }


    function _main()
    {
        $this->form->addElement('header', null, "PVT (Psychomotor Vigilance Task)");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement('file', 'pvt_file', 'Upload the PVT Parser file 
       <br><h6><i>(Ex: PSCID_DCCID_VisitLabel_PVT.csv)</i></h6>');

	$this->form->addElement('static', "File_name", "Uploaded File");

	$this->form->addElement('header', null, "PVT (Psychomotor Vigilance Task)");

	$this->form->addElement('static', null, null);

	$this->form->addElement('header', null, "Subject Headers");

	$group[] = $this->form->createElement('static',null, 'Participant ID', null);
	$group[] = $this->form->createElement('static',null, 'Trial', null);
	$group[] = $this->form->createElement('static',null, 'ISI', null);
	$group[] = $this->form->createElement('static',null, 'Abstime', null);
	$group[] = $this->form->createElement('static',null, 'RT', null);
	$group[] = $this->form->createElement('static',null, 'Type', null);
	$group[] = $this->form->createElement('static',null, 'Valid Responses', null);
	$group[] = $this->form->createElement('static',null, 'False Starts', null);
	$group[] = $this->form->createElement('static',null, 'Timeouts', null);
	$group[] = $this->form->createElement('static',null, 'Mean RT', null);
	$group[] = $this->form->createElement('static',null, 'Standard Deviation RT', null);
	$group[] = $this->form->createElement('static',null, 'Minimum RT', null);
	$group[] = $this->form->createElement('static',null, 'Maximum RT', null);
	$this->form->addGroup($group, "items_group",null, $this->_GUIDelimiter, false);
	unset($group); 

	for($i=0; $i<37; $i++){
	foreach($this->scoreLabels as $field){
            $group[] = $this->form->createElement('static', "{$field}_{$i}", null, null);
	}
	$this->form->addGroup($group, "{$field}_{$i}_group", null, $this->_GUIDelimiter, false);
            unset($group);
	}

       if($this->getFieldValue("File_name")===false){
            $this->form->addRule("pvt_file", "PVT file is required.", 'required', null, 'server');
        } else {
            $this->XINRegisterRule("pvt_file", array("pvt_file{@}=={@}NEVER_REQUIRED"));
	}

        // handedness questions
        $this->form->addElement('static', null, "<br /><br />");
        $this->form->addElement("textarea", "other_comments", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));
    }
    function _saveValues(array $values): void
    {
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());

        if(isset($values['Date_taken'])) {
            $this->_saveCandidateAge($values);
        }

        require_once "File_Upload.class.inc";
        $file=new File_Upload;

        //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
        $file->registerForm($this->form);

        //Tell File_Upload what file handlers to use.
        $file->setFileHandler("pvt_file", $this);

        // The uploaded file will go into the directory where all media files go
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("mediaPath");
        $file->setBaseUploadDirectory($dir);

        //Set the prefix to prepend to the filenames
        //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

        //set the the IDs to the handler functions.
        $user =& User::singleton();
        $file->setHandlerArgs(array("CommentID"=>$this->getCommentID(),
                "candID"=>$candidate->getCandID(),
                "PSCID"=>$candidate->getPSCID(),
                "visitLabel"=>$timepoint->getVisitLabel(),
                "username"=>$user->getUsername(),
                "values"=>$values)


        );

        //If the form is validated, call File_Upload::processFiles() which loops through the files and
        //proccesses them (including verify, move, and import steps)
        if ($values['pvt_file']['name'] != false) {
            $file->processFiles();
        }

        //echo error messages
        if(!empty($file->errorLog)){
            while(list($fileType,$fileErrors)=each($file->errorLog)){
                foreach($fileErrors AS $error){
                    echo "UPLOAD ERROR ($fileType) : $error";
                }
            }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['pvt_file']);
        $this->_save($values);
    }
    /**
     * isValid checks the validity of the file.
     *
     * @param     string  $file    The full filename including directory.
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function isValid(&$file, $args){
        $correct_filename = ($args['PSCID'].'_'.$args['candID'].'_'.$args['visitLabel']."_PVT.csv");

        if($file->fileInfo['name'] != $correct_filename ){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
        }
    
        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        $lines =preg_split("/\\r\\n|\\r|\\n/", $contents);
        $visit = $args['visitLabel'];
        $actual_pscid=$args['PSCID'];


        return true;
    }

    /**
     *
     * @param     object       $file    A reference to the file object (passed automatically by callFileHandler)
     * @param     assoc_array  $args    The arguments passed to the function they must be:
     *   -
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function importFile(&$file, $args){
        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

	$timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());
        $user      =& User::singleton();

        // Compute the directory where all media files are stored
        $config    = NDB_Config::singleton();
        $mediaPath = $config->getSetting('mediaPath');

        $values=array(
            'UserID'    =>$args['username'],
            'Status'    =>'assembly',
            'File_type' =>'PVT',
            'File_name' =>$file->getDestinationFilename(),
            'Data_dir'  =>$mediaPath
        );

	//Cycle through the lines and extract the data
	$lines =preg_split("/\\r\\n|\\r|\\n/", $contents);

   // "participant","trial","isi","abstime","rt","type","valid_response","false_starts","timeouts","mean_rt","standard_deviation_rt","minimum_rt","maximum_rt"
	$size = sizeof($lines);
	$last_line = 0;
	for($i=$size-1; $i>=0;$i--){
            if($lines[$i] != NULL){
		$tokens = explode(',',$lines[$i]);
		$values["participant_0"] = "--"; 
	        $values["trial_0"] = "--";
		$values["isi_0"] = "--";
		$values["abstime_0"] = "--";
		$values["rt_0"] = "--";
		$values["type_0"] = "--";
		$values["valid_response_0"] =  $tokens[6];
		$values["false_starts_0"] =  $tokens[7];
		$values["timeouts_0"] = $tokens[8];
		$values["mean_rt_0"] = $tokens[9];
		$values["standard_deviation_rt_0"] = $tokens[10];
		$values["minimum_rt_0"] = $tokens[11];
		$values["maximum_rt_0"] = $tokens[12];
		$last_line = $i;
		break;
	    }
	}

	for($i=1;$i<$last_line;$i++){
		$tokens = explode(',',$lines[$i]);
                $values["participant_{$i}"] = $tokens[0];
                $values["trial_{$i}"] = $tokens[1];
                $values["isi_{$i}"] = $tokens[2];
                $values["abstime_{$i}"] = $tokens[3];
                $values["rt_{$i}"] = $tokens[4];
                $values["type_{$i}"] = $tokens[5];
                $values["valid_response_{$i}"] =  "--";
                $values["false_starts_{$i}"] = "--";
                $values["timeouts_{$i}"] = "--";
                $values["mean_rt_{$i}"] = "--";
                $values["standard_deviation_rt_{$i}"] = "--";
                $values["minimum_rt_{$i}"] = "--";
                $values["maximum_rt_{$i}"] = "--";
	}
        $db=& Database::singleton();

        //-------------------------------------------------------------------//
        // Check that there is no file in the media module with              //
        // the same name as the file. If there is a file with the sam        //
        // but the file was uploaded through the EEG form for field $k, then //
        // that's OK (counts as an update)                                   //
        //-------------------------------------------------------------------//

        $row          = $db->pselectRow(
                "SELECT e.Date_Taken, m.ID FROM {$this->table} e LEFT JOIN media m ON (e.File_name=m.file_name) WHERE e.CommentID=:CommentID",
                array("CommentID" => $this->getCommentID())
            );
        $dateTaken = $row['Date_Taken'];
        $mediaID   = $row['ID'];

        // Compute the directory where all media files are stored
        $config    = NDB_Config::singleton();
        $mediaPath = $config->getSetting('mediaPath');

        $query = [
                      'session_id'  => $timepoint->getSessionID(),
                      'instrument'  => $this->table,
                      'date_taken'  => $dateTaken,
                      'comments'    => $comments,
                      'file_name'   => $file->getDestinationFilename(),
                      'file_type'   => 'PVT',
                      'data_dir'    => $mediaPath,
                      'uploaded_by' => $user->getData('UserID'),
                     ];

         try {
             // File alread exists in media module: update
             if (!is_null($mediaID)) {
                 $db->update('media', $query, array('ID' => $mediaID));
             // File does not exist in media module: insert new
             } else {
                 $db->insert('media', $query);
             }
         } catch (DatabaseException $e) {
             print_r($e);
         }

         $result = $db->update($this->testName, $values, array('CommentID'=>$args['CommentID']));  
         return true;
    }


    /**
     * getTargetDirectory retrieves info about where the file should be stored.
     *
     * The returned directory is ADDED to the baseUploadDirectory proprety.  It should have a trailing slash.
     *
     * @param     string  $file    The full filename including directory.
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function getTargetDirectory(&$file, $args){
        // Uploaded file goes directly in the media directory (no subdirectory needs to be created)
        return "";
    }
}
