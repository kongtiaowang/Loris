<?php
/*
 * This file contains the NDB_BVL_Instrument NIHToolBox_Assessment_Data
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
 * Creates the form elements for the NIHToolBox_Assessment_Data instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_NIHToolBox_Assessment_Data extends NDB_BVL_Instrument
{
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
    function setup($commentID, $page)
    {

        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "NIHToolBox_Assessment_Data";           // test_names.Test_name
        $this->table = 'NIHToolBox_Assessment_Data';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;
        $db =& Database::singleton();
        try {
            $record = $db->pselectRow("SELECT * FROM " . $this->table . " WHERE CommentID=:cid",
                array('cid' => $this->getCommentID()));
        } catch (DatabaseException $ex) {
            print "Query has failed to select";
            $record = array();
        }

        try {
            $record2 = $db->pselectRow("SELECT * FROM NIHToolBox_Assessment_Data2  WHERE CommentID=:cid",
                array('cid' => $this->getCommentID()));
        } catch (DatabaseException $ex) {
            print "Query has failed to select";
            $record2 = array();
        }

        $fields = array("DeviceID", "Assessment_Name", "InstOrdr", "InstSctn", "ItmOrdr", "Inst", "Locale", "ItemID", "Response", "Score", "Theta",
            "TScore", "SE", "DataType", "Position", "ResponseTime", "DateCreated", "InstStarted", "InstEnded", "AppVersion", "iPad_Version", "Firmware_Version");

        if (!empty($record)) {

            //$this->localDefaults['Uploaded_file'] = $record['Uploaded_file'];
            for ($i = 1; $i <= 30; $i++) {
                foreach ($fields as $field) {
                    $key = $field . "_" . $i;
                    $this->localDefaults[$key] = $record[$key];
                }
            }
        }
        if (!empty($record2)) {
            for ($i = 31; $i <= 62; $i++) {
                foreach ($fields as $field) {
                    $key = $field . "_" . $i;
                    $this->localDefaults[$key] = $record2[$key];
                }
            }
        }
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
            "/NIHToolBox_Assessment_Data(_page[0-9]+)/",
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
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR><i>The NIHToolBox Assessment Data instrument parses the data and updates the data 
 all around. (Similar to DTIPrep Instrument already in use)<br>
 <b>ie; if you have multiple candidate data in your file</b>; it will check across all the candidates and updates 
 the data for all the valid candidates found in the file.
  <br>This will save your time of going to each candidate and uploading the file.</i><br>
");
        $this->form->addElement('static', null, '<br>');
        $this->form->addFile('NIHToolBox_Assessment_Data', 'Upload the Assessment Data File
<br><h6><i>(Filename should be NIHToolBox_Assessment_Data.csv)</i></h6>', array());
        $this->form->addElement('static', 'Uploaded_assessment_data', "Uploaded Assessment Data File");
        $this->form->addElement('hidden', 'hidden_val', "Hidden Val");
        $this->XINRegisterRule("hidden_val", array("{hidden_val}{@}=={@}NEVER_REQUIRED"));
        $this->XINRegisterRule("NIHToolBox_Assessment_Data",array("hidden_val{@}=={@}NEVER_REQUIRED"));


    }

    function _page1()
    {

        $fields = array("No", "DeviceID", "Assessment_Name", "InstOrdr", "InstSctn", "ItmOrdr", "Inst", "Locale", "ItemID", "Response", "Score", "Theta",
            "TScore", "SE", "DataType", "Position", "ResponseTime", "DateCreated", "InstStarted", "InstEnded", "AppVersion", "iPad_Version", "Firmware_Version"
        );
        foreach ($fields as $field) {
            $group[] = &$this->form->createElement("static", null, null, $field);
            $group[] = &$this->form->createElement("static", null, null, null);
        }
        $this->form->addGroup($group, 'header_group', "", $this->_GUIDelimiter, FALSE);
        unset($group);


        for ($i = 1; $i <= 62; $i++) {
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

    function _saveValues($values)
    {
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());

        if(isset($values['Date_taken'])) {
            $this->_saveCandidateAge($values);
        }

        //Set the prefix to prepend to the filenames
        //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

        //set the the IDs to the handler functions.
            if(isset($values['NIHToolBox_Assessment_Data']) && !empty($values['NIHToolBox_Assessment_Data']['name'])) {
                require_once "File_Upload.class.inc";
                $file=new File_Upload;

                //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
                $file->registerForm($this->form);


                //Tell File_Upload what file handlers to use.
                $file->setFileHandler("NIHToolBox_Assessment_Data", $this);

                //Set the target directory that you want files moved into once they are validated and processed.
                $config = NDB_Config::singleton();
                $dir = $config->getSetting("UploadDir");
                if(empty($dir)) {
                    $dir = ".";
                };
                $file->setBaseUploadDirectory($dir . "/NIHToolBox_Assessment_Data/");

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
                $file->processFiles();
            }
        //echo error messages
        if(!empty($file->errorLog)){
            while(list($fileType,$fileErrors)=each($file->errorLog)){
                foreach($fileErrors AS $error){
                    echo "Upload Error: $fileType: $error";
                }
            }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'],
            $values['NIHToolBox_Assessment_Data'],$values['hidden_val']);
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


        $correct_filename = $this->testName.".csv";
        if($file->fileInfo['name'] != $correct_filename){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
        }
        return true;
    }

    /**
     * importFile imports the wiatIII file into the database.
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

        $sesionID=$this->getSessionID();
        $main_values = array(
             'Data_dir_assessment' => $file->getDestinationDirectory(),
             'UserID' => $args['username'],
             'File_type' => 'NIHToolBox',
             'Examiner'  =>$this->getExaminerID('NIH ToolBox Not Applicable'),
             'Date_taken'=>$this->getDateAdmin($sesionID),
             'Data_entry_completion_status' =>'Complete'
        );

        if(strpos($file->fileInfo['name'], 'Data') !== false) {
            $upload_values2=array();

            /** @var Database $db */
            $db =& Database::singleton();
            ///Setting trackchanges to false because getting error messages
            $db->_trackChanges = false;
            ////////////////////////////////////////////////////////////////
           //uploading values to NIHToolBox_Assessment_Data

            $main_values['Uploaded_assessment_data'] = $file->getDestinationFilename();

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
//Now, to print it out, this is all I have to do
            $valid=0;
            $ids_updated='';
            foreach ($result as $pscid => $entries) {
                $upload_values=array();
                $upload_values2=array();
              // echo $pscid . "\n";
                $fields = array("DeviceID", "Assessment_Name", "InstOrdr", "InstSctn", "ItmOrdr", "Inst", "Locale", "ItemID", "Response", "Score", "Theta",
                    "TScore", "SE", "DataType", "Position", "ResponseTime", "DateCreated", "InstStarted", "InstEnded", "AppVersion", "iPad_Version", "Firmware_Version");
                $count=count($entries);
                if($count>62)
                {
                    $count=62;
                }

                foreach ($entries as $i => $entry) {
                    $i++;
                           if($i<=62) {
                                    $f = 0;
                                    foreach ($fields as &$value) {
                                        if ($i > 30 && $i <= $count) {
                                            $upload_values2["{$value}_{$i}"] = $entry[$f];
                                        } else {
                                            $upload_values["{$value}_{$i}"] = $entry[$f];
                                        }
                                        $f++;
                                    }

                           }
                }

                $commentid = $db->pselectOne(
                    "select f.CommentID from flag as f
                  join `session` as s on f.SessionID=s.ID
                  join `candidate` as c on s.CandID=c.CandID
                  WHERE s.Visit_label='VSA' and c.PSCID=:pscid
                  and f.Test_name=:tesna and f.CommentID not like 'DDE_%'",
                    array(
                        'pscid' => $pscid,
                        'tesna' => $this->testName,
                    )
                );
                $final_upload_values=array_merge($main_values,$upload_values);
                if(!empty($commentid)) {
                    $result = $db->update($this->testName, $final_upload_values, array('CommentID' => $commentid));
                    $result2= $db->update('flag', array('Data_entry' => 'Complete', 'Administration'    =>'All'),
                            array('CommentID' => $commentid));
                    $valid++;
                    $ids_updated .= $pscid.",";

                    if (!empty($upload_values2)) {
                        $check = $db->pselectOne("SELECT 1 FROM NIHToolBox_Assessment_Data2 WHERE CommentID=:cid", array('cid' => $commentid));
                        if ($check != 1) {
                            $upload_values2['CommentID'] = $commentid;
                            $ok = $db->insert("NIHToolBox_Assessment_Data2", $upload_values2);
                        } else {
                            $ok = $db->update("NIHToolBox_Assessment_Data2", $upload_values2, array('CommentID' => $commentid));
                        }
                    }
                }
            }
            if($valid==0)
            {
                echo "No matching PSCID found in the csv file to update the data under VSA visit label. \n
                Please check your file and try again.";
                return false;
            }
            else {
                echo "UPLOAD SUCCESSFUL!!!! \n";
                echo $valid . " Entries Updated.\n";
                echo $ids_updated . "got updated";
                return true;
            }
        }
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

    function getDateAdmin($sessionID)
    {
        $db =& Database::singleton();
        $NIH_Asses_Score_CommentID=$db->pselectOne("select CommentID from flag where 
test_name='NIHToolBox_Assessment_Scores' and CommentID not like '%DDE%'and sessionID=:sid", array('sid'=>$sessionID));

        $query      = "SELECT Date_taken from NIHToolBox_Assessment_Scores where CommentID=:CID";
        $fieldValue = $db->pselectOne($query, array('CID' => $NIH_Asses_Score_CommentID));

        if (!empty($fieldValue)) {
            return $fieldValue;
        }
        return NULL;
    }
}
