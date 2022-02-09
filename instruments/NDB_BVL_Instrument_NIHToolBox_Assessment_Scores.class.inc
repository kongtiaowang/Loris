<?php
/*
 * This file contains the NDB_BVL_Instrument_NIHToolBox_Assessment_Scores
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NIHToolBox_Assessment_Scores instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_NIHToolBox_Assessment_Scores extends NDB_BVL_Instrument
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
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "NIHToolBox_Assessment_Scores";           // test_names.Test_name
        $this->table = 'NIHToolBox_Assessment_Scores';             // name of table containing

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
            "/NIHToolBox_Assessment_Scores(_page[0-9]+)/",
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

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR><i>The NIHToolBox Assessment Scores instrument parses the data and updates the data 
 all around. (Similar to DTIPrep Instrument already in use)<br>
 <b>ie; if you have multiple candidate data in your file</b>; it will check across all the candidates and updates 
 the data for all the valid candidates found in the file.
  <br>This will save your time of going to each candidate and uploading the file.</i><br>
");
        $this->form->addElement('static', null, '<br>');
        $this->form->addElement('file','NIHToolBox_Assessment_Scores', 'Upload the NIH ToolBox Assessment Scores File
<br><h6><i>(Filename should be PSCID_DCCID_VisitLabel_NIHToolBox_Assessment_Scores.csv)</i></h6>');
        $this->form->addElement('static', 'Uploaded_Assessment_Scores', "Uploaded  NIH ToolBox Assessment Scores File");
        $this->form->addElement('hidden', 'hidden_val', "Hidden Val");
        $this->XINRegisterRule("hidden_val", array("{hidden_val}{@}=={@}NEVER_REQUIRED"));
        $this->XINRegisterRule("NIHToolBox_Assessment_Scores",array("hidden_val{@}=={@}NEVER_REQUIRED"));



    }

    function _page1()
    {

        $fields = array("No","DeviceID"	,"AssessmentName" ,	"Inst",	"RawScore",	"Theta", "TScore",	"SE","ItmCnt" ,"DateFinished" ,
            "Column1" ,"Column2","Column3", "Column4","Column5",
            "Language","ComputedScore","Uncorrected_Standard_Score","Age_Corrected_Standard Score","National_Percentile",
            "Fully_Corrected_T_score", "InstrumentBreakoff","InstrumentStatus2","InstrumentRCReason","InstrumentRCReasonOther", "App_Version",
            "iPad_Version","Firmware_Version"

        );
        foreach ($fields as $field) {
            $group[] = &$this->form->createElement("static", null, null, $field);
            $group[] = &$this->form->createElement("static", null, null, null);
        }
        $this->form->addGroup($group, 'header_group', "", $this->_GUIDelimiter, FALSE);
        unset($group);


        for ($i = 1; $i <= 2; $i++) {
            foreach ($fields as $field) {
                if ($field === "No") {
                    $group[] = $this->form->createElement('static', null, null, $i);
                    $group[] = $this->form->createElement("static", null, null, null);
                } else {
                    $group[] = $this->form->createElement('static', $field . "_" . $i);
                    $group[] = $this->form->createElement("static", null, null, null);
                }
            }
            $this->form->addGroup($group, $i . '_group', "", $this->_GUIDelimiter, FALSE);
            unset($group);

        }

    }

    function _saveValues(array $values): void
    {


        $timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());

        if(isset($values['Date_taken'])) {
            $this->_saveCandidateAge($values);
        }


        //set the the IDs to the handler functions.
            require_once "File_Upload.class.inc";
            $file=new File_Upload;

            //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
            $file->registerForm($this->form);


            //Tell File_Upload what file handlers to use.
            $file->setFileHandler("NIHToolBox_Assessment_Scores", $this);

            //Set the target directory that you want files moved into once they are validated and processed.
            $config = NDB_Config::singleton();
            $dir = $config->getSetting("mediaPath");
            $file->setBaseUploadDirectory($dir);

	    // move previously uploaded file not in media module
                $prev_dir = $config->getSetting("UploadDir");
                if(empty($prev_dir)) {
                    $prev_dir = ".";
                };
                //previously file directory and naming convention
                $prev_filename = $prev_dir . "/NIHToolBox_Assessment_Scores/NIHToolBox_Assessment_Scores.csv";
                if (file_exists($prev_filename)) {
                        move_uploaded_file($prev_filename, $dir);
                        echo "move previously uploaded file " . $prev_filename . " to media";
		}

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
	   if ($values['NIHToolBox_Assessment_Scores']['name'] != false) {
		   $file->processFiles();
	   }
        
        if(!empty($file->errorLog)){
            while(list($fileType,$fileErrors)=each($file->errorLog)){
                foreach($fileErrors AS $error){
                    echo "Upload Error: $fileType: $error";
                }
            }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'],
            $values['NIHToolBox_Assessment_Scores'], $values['valid'],$values['ids_updated'],$values['hidden_val']);
        $this->_save($values);
        //

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

        $correct_filename = $correct_filename = ($args['PSCID'].'_'.$args['candID'].'_'.$args['visitLabel'].'_'.$this->testName.".csv");
        if($file->fileInfo['name'] != $correct_filename){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
        }
        return true;
    }

    /**
     * importFile imports the NIHToolBoxRegistrationData into the database.
     *
     * @param     object       $file    A reference to the file object (passed automatically by callFileHandler)
     * @param     assoc_array  $args    The arguments passed to the function they must be:
     *   -
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function importFile(&$file, $args)
    {
	$timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());
        $user      =& User::singleton();

        // Compute the directory where all media files are stored
        $config    = NDB_Config::singleton();
	$mediaPath = $config->getSetting('mediaPath');

        $main_values = array(
            'Data_dir_assessment' => $file->getDestinationDirectory(),
            'UserID' => $args['username'],
            'File_type' => 'NIHToolBox',
            'Examiner'  =>$this->getExaminerID('NIH ToolBox Not Applicable'),
            'Data_entry_completion_status' =>'Complete'
    );

        $values = array();
        $values["Uploaded_Assessment_Scores"] = $file->fileInfo['name'];
	parent::_saveValues($values);

            /** @var Database $db */
            $db =& Database::singleton();
            ///Setting trackchanges to false because getting error messages
            $db->_trackChanges = false;
            ////////////////////////////////////////////////////////////////
            //uploading values to NIHToolBox_Assessment_Scores

            $result = array();
            $file = fopen($file->fileInfo['tmp_name'], "r");
            while (!feof($file)) {
                $data = fgetcsv($file, 0, ",");
                $key = array_shift($data);
                if (!isset($result[$key])) {
                    $result[$key] = array();
                }
                $result[$key][] = $data;
            }
           // print_r($result);
//Now, to print it out, this is all I have to do
            $valid=0;
            $ids_updated='';
            foreach ($result as $pscid => $entries) {
                $upload_values=array();
                //echo $pscid . "\n";
                //loop through all unique pscid found and update the date all around
                $fields = array("DeviceID"	,"AssessmentName" ,	"Inst",	"RawScore",	"Theta", "TScore",	"SE","ItmCnt" ,"DateFinished" ,
                    "Column1" ,"Column2","Column3", "Column4","Column5",
                    "Language","ComputedScore","Uncorrected_Standard_Score","Age_Corrected_Standard_Score","National_Percentile",
                    "Fully_Corrected_T_score", "InstrumentBreakoff","InstrumentStatus2","InstrumentRCReason","InstrumentRCReasonOther", "App_Version",
                    "iPad_Version","Firmware_Version"

                );
                //2 sessions per candidate allowed as per the current files given
                $count=count($entries);
                if($count>2)
                {
                    $count=2;
                }
                foreach ($entries as $i => $entry) {
                    $m=$i+1;
                    if($m<=$count) {
                        $f = 0;
                        foreach ($fields as &$value) {
                            if ($m <= $count) {

                                $upload_values["{$value}_{$m}"] = $entry[$f];
                            }


                            $f++;
                        }
                    }
                }
                $upload_values['Date_taken']=date("Y-m-d", strtotime($upload_values['DateFinished_1']));
                if (DateTime::createFromFormat('Y-m-d', $upload_values['Date_taken']) == FALSE) {
                    echo "Cannot Find Valid DateFinished(10th column) in csv file to consider as Date of Administration";
                }

                $final_upload_values=array_merge($main_values,$upload_values);
                $commentid = $db->pselectOne(
                    "select f.CommentID from flag as f
                  join `session` as s on f.SessionID=s.ID
                  join `candidate` as c on s.CandID=c.CandID
                  WHERE s.Visit_label IN ('VSA','VSA-CVD')  and c.PSCID=:pscid
                  and f.Test_name=:tesna and f.CommentID not like 'DDE_%'",
                    array(
                        'pscid' => $pscid,
                        'tesna' => $this->testName,
                    )
                );
                $NIH_Assess_Data_commentid = $db->pselectOne(
                    "select f.CommentID from flag as f
                  join `session` as s on f.SessionID=s.ID
                  join `candidate` as c on s.CandID=c.CandID
                  WHERE s.Visit_label IN ('VSA','VSA-CVD') and c.PSCID=:pscid
                  and f.Test_name=:tesna and f.CommentID not like 'DDE_%'",
                    array(
                        'pscid' => $pscid,
                        'tesna' => 'NIHToolBox_Assessment_Data',
                    )
                );
                $NIH_Reg_Data_commentid = $db->pselectOne(
                    "select f.CommentID from flag as f
                  join `session` as s on f.SessionID=s.ID
                  join `candidate` as c on s.CandID=c.CandID
                  WHERE s.Visit_label IN ('VSA','VSA-CVD') and c.PSCID=:pscid
                  and f.Test_name=:tesna and f.CommentID not like 'DDE_%'",
                    array(
                        'pscid' => $pscid,
                        'tesna' => 'NIHToolBox_Registration_Data',
                    )
                );

                //Date taken is updated for all the NIHforms where the DateFinished from NIHToolBox AssessmentScores

              if(!empty($NIH_Assess_Data_commentid))
              {
                  $db->update('NIHToolBox_Assessment_Data', array('Date_taken' => $upload_values['Date_taken']), array('CommentID' => $NIH_Assess_Data_commentid));
              }

                if(!empty($NIH_Reg_Data_commentid))
                {
                    $db->update('NIHToolBox_Registration_Data', array('Date_taken' => $upload_values['Date_taken']), array('CommentID' => $NIH_Reg_Data_commentid));
                }

                if(!empty($commentid)) {
                    $valid++;
                    $result = $db->update($this->testName, $final_upload_values, array('CommentID' => $commentid));
                    $result2= $db->update('flag', array('Data_entry' => 'Complete', 'Administration'    =>'All'),
                        array('CommentID' => $commentid));
                    $ids_updated .= $pscid.",";
                }
            }
            if($valid==0)
            {
                echo "No matching PSCID found in the csv file to update the data under VSA visit label. \n
                Please check your file and try again.";
                return false;
            }

	                    //-------------------------------------------------------------------//
        // Check if there is a file in the media module with the same name   //
        // as the uploaded file.                                             //
        //-------------------------------------------------------------------//

        $row          = $db->pselectRow(
                "SELECT e.Date_Taken, m.ID FROM {$this->table} e LEFT JOIN media m ON (e.Uploaded_Assessment_Scores=m.file_name) WHERE e.CommentID=:CommentID",
                array("CommentID" => $this->getCommentID())
        );
        $dateTaken = $row['Date_Taken'];
        $mediaID   = $row['ID'];

        $query = [
                      'session_id'  => $timepoint->getSessionID(),
                      'instrument'  => $this->table,
                      'date_taken'  => $dateTaken,
                      'comments'    => $comments,
                      'file_name'   => $values["Uploaded_Assessment_Scores"],
                      'file_type'   => 'NIHToolBox_Assessment_Scores',
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

        // Update the table
    $result = $db->update($this->testName, $values, array('CommentID'=>$args['CommentID']));

                echo "UPLOAD SUCCESSFUL!!!! \n";
                echo $valid . " Entries Updated.\n";
                echo $ids_updated . "got updated";
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

    function getExaminerID($fullName)
    {
        $DB         = \Database::singleton();
        $examinerID = $DB->pselectOne(
            "SELECT examinerID
             FROM examiners
             WHERE full_name=:fullName",
            array('fullName' => $fullName)
        );

        //returned as a string
        return $examinerID;
    }

}
