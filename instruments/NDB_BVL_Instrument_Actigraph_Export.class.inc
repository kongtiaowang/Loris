<?php
/*
 * This file contains the NDB_BVL_Instrument_Actigraph_Export
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
 * Creates the form elements for the Actigraph_Export instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Moshood Kolawole <moshood.kolawole@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_Actigraph_Export extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

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
        $this->form = new LorisForm('Actigraph_Export');
        $this->page = $page;

        // set the object properties
        $this->testName = "Actigraph_Export";            // test_names.Test_name
        $this->table = 'Actigraph_Export';              // name of table containing

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
        //determine page to display
        if (preg_match(
            "/Actigraph_Export(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }


    function _main()
    {

	$this->form->addElement('header', null, "Actigraph Export Summary Parser");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement('file', 'actigraph_export_file', 'Upload the Actigraph Export Summary Parser file 
       <br><h6><i>(Ex: PSCID_DCCID_visitlabel_Actigraph_Export.csv)</i></h6>');
       
        $this->form->addElement('static', "File_name", "Uploaded File");


        $this->form->addElement('header', null, "Actigraph Export Summary Parser");

        $this->form->addElement('static', null, null);

	$this->form->addElement('header', null, "Subject Properties");

	$group[] = $this->form->createElement('static',null, 'Value', null);
	$this->form->addGroup($group, "items_group",'Items', $this->_GUIDelimiter, false);
	unset($group);

	 $fields = array(
            "initials"               =>  "Initials:",
            "full_name"              =>  "Full name:",
            "street_address"         =>  "Street Address:",
            "city_state_zip"         =>  "City State Zip Country:",
            "phone"                  =>  "Phone:",
            "gender"                 =>  "Gender:",
            "date_of_birth"          => "Date of Birth:",
            "age_at_file_creation"   => "Age(at time of export file creation):",
            "age_at_data_collection" => "Age(at start of data collection):",
        );

        foreach($fields as $field => $label){
            $group[] = $this->form->createElement('static', "$field", null, null);
            $this->form->addGroup($group, "{$field}_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }

       if($this->getFieldValue("File_name")===false){
            $this->form->addRule("actigraph_export_file", "ACTIGRAPH EXPORT file is required.", 'required', null, 'server');
        } else {
            $this->XINRegisterRule("actigraph_export_file", array("actigraph_export_file{@}=={@}NEVER_REQUIRED"));
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
        $file->setFileHandler("actigraph_export_file", $this);

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("UploadDir");
        if(empty($dir)) {
            $dir = ".";
        };
        $file->setBaseUploadDirectory($dir . "/Actigraph_Export/");

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
        if ($values['actigraph_export_file']['name'] != false) {
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
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['actigraph_export_file']);
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
        $correct_filename = ($args['PSCID'].'_'.$args['candID'].'_'.$args['visitLabel']."_Actigraph_Export.csv");
        if($file->fileInfo['name'] != $correct_filename){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
        }

        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        $lines =preg_split("/\\r\\n|\\r|\\n/", $contents);
        $visit = $args['visitLabel'];
        $actual_pscid=$args['PSCID'];


        $input = $actual_pscid; //from the user
        $matches = array();
        foreach ($lines as $c){
            if (strpos($c, $input) === 0){
                //if $c starts with $input, add to matches list
                $matches[] = $c;
            } else if (strcmp($input, $c) < 0){
                //$input comes after $c in alpha order
                //since $colors is sorted, we know that we won't find any more matches
                break;
            }
        }
        $found =0;
        foreach($lines as $key => $value) {
            if (preg_match('/' . $actual_pscid . '/i', $value)) {
                $found = 1;
                break;
            }
        }
        if($found==0){
            $errors[]="No matching PSCID found in the file. Please check and try again";
            return $errors;

        }

        $test_date_key = array_search('Date of Birth:', $lines);
        $values['Date of Birth'] =$lines[$test_date_key+1];

        $values['Date of Birth'] = $this->formatDate($values['Date of Birth']);

        return true;
    }

    /**
     * importFile imports the das sa file into the database.
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

        $values=array(
            'UserID'    =>$args['username'],
            'Status'    =>'assembly',
            'File_type' =>'Actigraph_Export',
            'File_name' =>$file->getDestinationFilename(),
            'Data_dir'  =>$file->getDestinationDirectory()
        );


        //Cycle through the lines and extract the data
        $lines =preg_split("/\\r\\n|\\r|\\n/", $contents);
        
        $fields = array(
            "initials"               =>  "Initials:",
            "full_name"              =>  "Full name:",
            "street_address"         =>  "Street Address:",
            "city_state_zip"         =>  "City State Zip Country:",
            "phone"                  =>  "Phone:",
            "gender"                 =>  "Gender:",
            "date_of_birth"          => "Date of Birth:",
            "age_at_file_creation"   => "Age(at time of export file creation):",
            "age_at_data_collection" => "Age(at start of data collection):",
    );

	foreach ($fields as $key => $val) {
		$array_key=array_search($val,$lines);
		$val_count=$array_key+1;
		if($array_key != null) {
                            $values[$key] = $lines[$val_count];
		}
            else{
                    $values[$key]='--';
            }
        }

        $db=& Database::singleton();

///Setting trackchanges to false because getting error messages
        $db->_trackChanges = false;
////////////////////////////////////////////////////////////////

        $result = $db->update($this->testName, $values, array('CommentID'=>$args['CommentID']));
        return true;
    }

    function formatDate($date){
        if(empty($date)){
            return null;
        }
        $dateBits = explode('/', $date);
        return sprintf("%04d-%02d-%02d", $dateBits[2], $dateBits[0], $dateBits[1]);
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
        $output=$args['candID']."/";
        return $output;
    }
}
