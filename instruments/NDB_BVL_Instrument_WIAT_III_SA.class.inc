<?php
/*
 * This file contains the NDB_BVL_Instrument_mock_scanner_training_form
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
 * Creates the form elements for the WIAT_III_SA instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_WIAT_III_SA extends NDB_BVL_Instrument
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
        $this->testName = "WIAT_III_SA";           // test_names.Test_name
        $this->table = 'WIAT_III_SA';             // name of table containing

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
            "/WIAT_III_SA(_page[0-9]+)/",
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
        $this->form->addElement('file', 'wiatIII_file', 'Upload the WIAT_III file 
       <br><h6><i>(Ex: WIAT_III_SA_PSCID_VSA.txt)</i></h6>');

        $this->form->addElement('static', "File_name", "Uploaded File");


        $this->form->addElement('header', null, "Subtest Score Summary");


        //scoring column headers
        $group[] = $this->form->createElement('static', "RAW", null, null);
        $group[] = $this->form->createElement('static', "STD_SCORE", null, null);
        $group[] = $this->form->createElement('static', "CI", null, null);
        $group[] = $this->form->createElement('static', "PER_RANK", null, null);
        $group[] = $this->form->createElement('static', "NCE", null, null);
        $group[] = $this->form->createElement('static', "STANINE", null, null);
        $group[] = $this->form->createElement('static', "GRADE_EQUIV", null, null);
        $group[] = $this->form->createElement('static', "AGE_EQUIV", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Domain/Subdomain</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains = array("RC" => "Reading Comprehension", "MPS" => "Math Problem Solving", "WR" => "Word Reading", "PD" => "Pseudoword Decoding",
            "NO" => "Numerical Operations");
        $columnHeaders = array("RAW" => "Raw Score", "STD_SCORE" => "Standard Score",
            "CI" => "95% Confidence Interval", "PER_RANK" => "Percentile Rank",
            "NCE" => "Normal Curve Equiv", "STANINE" => "Stanine", "GRADE_EQUIV" => "Grade Equivalent", "AGE_EQUIV" => "Age Equivalent"
        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_group", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }
        if($this->getFieldValue("File_name")===false){
            $this->form->addRule("wiatIII_file", "WIAT III file is required.", 'required', null, 'server');
        } else {
            $this->XINRegisterRule("wiatIII_file", array("wiatIII_file{@}==={@}NEVER_REQUIRED"));
        }
        // handedness questions
        $this->form->addElement('static', null, "<br /><br />");
        $this->form->addElement("textarea", "other_comments", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));
    }
    function _saveValues($values)
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
        $file->setFileHandler("wiatIII_file", $this);

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("UploadDir");
        if(empty($dir)) {
            $dir = ".";
        };
        $file->setBaseUploadDirectory($dir . "/wiatIII/");

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
        if ($values['wiatIII_file']['name'] != false) {
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
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['wiatIII_file']);
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
        $correct_filename = strtolower($this->testName .'_'. $args['candID'] .'_'. $args['PSCID'] .'_'. $args['visitLabel'] . ".txt");
        if(strtolower($file->fileInfo['name']) != $correct_filename){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
        }

        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        $lines=explode("\n",$contents);



        $visit = $args['visitLabel'];



        $input = 'Student Name:IBIS-SA';
        $result = array_filter($lines, function ($item) use ($input) {
            if (stripos($item, $input) !== false) {
                return true;
            }
            return false;
        });

        if(empty($result))
        {
            $errors[]="Unable To Read the PSCID from the txt file. Please make sure you have a Student Name:IBIS-SA PSCID entry in your file" ;
            return $errors;
        }
        else{
            foreach ($result as $key => $value) {
                $student_string=$value;
            }
        }
        $student_string_array=explode(" ", $student_string);
        $pscid=$student_string_array[2];
        $actual_pscid=$args['PSCID'];
        if($actual_pscid!=$pscid)
        {
            $errors[]="PSCID in the file given (".$pscid.") doesn't match with the actual PSCID (".$actual_pscid.")";
            return $errors;
        }

        $test_date_key = array_search('Date of Report:', $lines);
        $values['Date of Report'] =$lines[$test_date_key+1];

        $values['Date of Report'] = $this->formatDate($values['Date of Report']);


        if(!empty($args['values']['Date_taken']) && !empty($values['Date of Report']) && ($args['values']['Date_taken'] != $values['Date of Report'])){
            $errors['Date of Administration']="Date of administration in the file ({$values['Date of Report']}) does not match the date of administration entered ({$args['values']['Date_taken']})." ;
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
    function importFile(&$file, $args){
        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        $values=array(
            'UserID'    =>$args['username'],
            'Status'    =>'assembly',
            'File_type' =>'WIAT_III_SA',
            'File_name' =>$file->getDestinationFilename(),
            'Data_dir'  =>$file->getDestinationDirectory()
        );


        //Cycle through the lines and extract the data
        $lines=explode("\n",$contents);
        $RC_DOMAIN=array("RC_RAW","RC_STD_SCORE","RC_CI","RC_PER_RANK","RC_NCE","RC_STANINE","RC_GRADE_EQUIV","RC_AGE_EQUIV");
        $MPS_DOMAIN=array("MPS_RAW","MPS_STD_SCORE","MPS_CI","MPS_PER_RANK","MPS_NCE","MPS_STANINE","MPS_GRADE_EQUIV","MPS_AGE_EQUIV");
        $WR_DOMAIN=array("WR_RAW","WR_STD_SCORE","WR_CI","WR_PER_RANK","WR_NCE","WR_STANINE","WR_GRADE_EQUIV","WR_AGE_EQUIV");
        $PD_DOMAIN=array("PD_RAW","PD_STD_SCORE","PD_CI","PD_PER_RANK","PD_NCE","PD_STANINE","PD_GRADE_EQUIV","PD_AGE_EQUIV");
        $NO_DOMAIN=array("NO_RAW","NO_STD_SCORE","NO_CI","NO_PER_RANK","NO_NCE","NO_STANINE","NO_GRADE_EQUIV","NO_AGE_EQUIV");

            $group[] = $this->form->createElement('static', "CI", null, null);
        $group[] = $this->form->createElement('static', "PER_RANK", null, null);
        $group[] = $this->form->createElement('static', "NCE", null, null);
        $group[] = $this->form->createElement('static', "STANINE", null, null);
        $group[] = $this->form->createElement('static', "GRADE_EQUIV", null, null);
        $group[] = $this->form->createElement('static', "AGE_EQUIV", null, null);
        $RC_array_key = array_search('Reading Comprehension', $lines);
        $MPS_array_key = array_search('Math Problem Solving', $lines);
        $WR_array_key = array_search('Word Reading', $lines);
        $PD_array_key = array_search('Pseudoword Decoding', $lines);
        $NO_array_key = array_search('Numerical Operations', $lines);
        $RC_count=$RC_array_key+8;
        $MPS_count=$MPS_array_key+8;
        $WR_count=$WR_array_key+8;
        $PD_count=$PD_array_key+8;
        $NO_count=$NO_array_key+8;
        $count=0;
        for($i=$RC_array_key+1; $i<=$RC_count; $i++)
        {
            $values[$RC_DOMAIN[$count]]=$lines[$i];
            $count++;
        }
        $count=0;
        for($i=$MPS_array_key+1; $i<=$MPS_count; $i++)
        {

            $values[$MPS_DOMAIN[$count]]=$lines[$i];
            $count++;
        }
        $count=0;
        for($i=$WR_array_key+1; $i<=$WR_count; $i++)
        {
            $values[$WR_DOMAIN[$count]]=$lines[$i];
            $count++;
        }
        $count=0;
        for($i=$PD_array_key+1; $i<=$PD_count; $i++)
        {
            $values[$PD_DOMAIN[$count]]=$lines[$i];
            $count++;
        }
        $count=0;
        for($i=$NO_array_key+1; $i<=$NO_count; $i++)
        {
            $values[$NO_DOMAIN[$count]]=$lines[$i];
            $count++;
        }

        $test_date_key = array_search('Date of Report:', $lines);
        $values['Date of Report'] =$lines[$test_date_key+1];

        $values['Date of Report'] = $this->formatDate($values['Date of Report']);

        unset($values['Date of Report']);

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
