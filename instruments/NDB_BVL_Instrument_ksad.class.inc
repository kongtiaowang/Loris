<?php
/*
 * This file contains the NDB_BVL_Instrument_ksad
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard <nicolas.brossard2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the KSAD instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard <nicolas.brossard2@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_ksad extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    // Max number of error messages to show when parsing an uploaded file
    const MAX_UPLOAD_ERRORS_SHOWN = 10;

    // All the rating labels expected to be found in the ratings file
    const RATINGS = array(
        'Depressive Disorders',
        'Bipolar Disorders',
        'Psychosis',
        'Panic Disorder',
        'Agoraphobia',
        'Separation Anxiety',
        'Social Anxiety Disorder',
        'Specific Phobia',
        'Generalized Anxiety Disorder',
        'OCD Obsessions',
        'OCD Compulsions',
        'OCD Total',
        'Enuresis',
        'Encopresis',
        'Eating Disorders',
        'ADHD',
        'ODD',
        'Conduct Disorder',
        'Tic Disorder',
        'Autism Disorder',
        'Alcohol user Disorder',
        'Drug Use Disorder',
        'PTSD'
    );

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     *
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        // Set the object properties
        $this->formType  = 'XIN';
        $this->form      = new LorisForm('test_form');
        $this->page      = $page;
        $this->testName  = 'ksad';          
        $this->table     = 'ksad';        
        $this->commentID = $commentID;

        // Setup the form
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
        // Determine page to display
        if (preg_match(
            "/ksad(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            // We need to update the local defaults otherwise the 
            // responses/ratings will not be displayed on the
            // page
            $this->_updateLocalDefaults();
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function _main()
    {
        $this->addHeader("KSAD");

       
        // Automatically adds examiner & date of administration
        $this->_addMetadataFields();

    }

    /**
     * Override sthe method defined in the base class so as not to add a 'Save Data'
     * button at the bottom of the responses and ratings pages.
     *
     * @param array  $elements   The group of elements to add to the page
     * @param string $name       The name to give this group
     * @param string $label      A label to attach to the group
     * @param string $separator  The separator to use between group elements
     * @param string $appendName unused
     *
     * @return void
     */
    function addGroup($elements, $name, $label, $separator, $appendName=null)
    {
        // If the element added is the 'Save Data' button that all forms have
        // at the bottom of their page
        if (count($elements) == 1 && $elements[0]['type'] == 'submit' 
            && isset($elements[0]['value']) && $elements[0]['value'] == 'Save Data'
        ) {
            // If the page displayed is either the responses or ratings file, don't
            // add the button: we already have the 'Upload File' button
            if ($this->page == 'ksad_page1' || $this->page == 'ksad_page2') {
                return;
            }
        }

        // Revert to normal behaviour in other cases
        parent::addGroup($elements, $name, $label, $separator, $appendName);
    }

    /**
     * Displays page#1 (User Responses).
     */
    function _page1()
    {
        $this->addHeader("KSAD - User Responses");

        $timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());
        $pscid  = $candidate->getPSCID();
        $candID = $candidate->getCandID();
        $vlabel = $timepoint->getVisitLabel();

        //------------------------//
        // Display instructions   //
        //------------------------//
        $this->form->addElement('static', null, 'Instructions:');

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<i>The KSAD instrument will parse the candidate responses file "
                . "and  fill out the 'Responses' section below<br>"
                . "The uploaded file has to be in CSV format and itsbase name has to be "
                . "<strong>ksad_responses_{$pscid}_{$candID}_{$vlabel}</i><br><br>"  
        );

        //----------------------------------------//
        // Adds control needed to upload the file //
        //----------------------------------------//
        $this->form->addElement('file'  , 'ksad_responses_file', 'Upload the KSAD candidate responses file:');
        $this->form->addElement('static', 'ResponsesFileName'  , 'Uploaded responses file:');

        //--------------------------------//
        // Create the upload file button  //
        //--------------------------------//
        $buttons[] = $this->form->createElement(
            'submit',
            'fire_away',
            'Upload File',
            array('class' => 'button')
        );
        $this->addGroup($buttons, null, null, "&nbsp;");

        if ($this->getFieldValue('ResponsesFileName') != false) {
            $this->XINRegisterRule('ksad_responses_file', array("ksad_responses_file{@}=={@}NEVER_REQUIRED"));
        }

        $this->form->addElement('static', null, '<br><br>');

        //-------------------------------------------//
        // Display questionnaire header              //
        //-------------------------------------------//       
        $group    = array();
        $group[]  = $this->form->createElement('static', null, null, 'Question');
        $group[]  = $this->form->createElement('static', null, null, 'Answer');
        $group[]  = $this->form->createElement('static', null, null, 'Comment');
        $this->form->addGroup($group, 'header_group', '<strong>#</strong>', $this->_GUIDelimiter, FALSE);
        unset($group);

        //--------------------------------------------------------//
        // Display responses in loaded file (if any)              //
        // Note that since there are no fields "Value$questionID" //
        // and "Comment$questionID", local defaults have to       //
        // be set for these fields                                //
        //--------------------------------------------------------//       
        $db = Database::singleton();
        $questionnaireRows = $db->pselect(
            'SELECT QuestionID, SequenceID, QuestionText FROM ksad_questionnaire',
            []
        );

        foreach ($questionnaireRows as $q) {
            $group    = array();
            $group[]  = $this->form->createElement('static', null, null, $q['QuestionText']);
            $questionID = $q['QuestionID'];
            $group[]  = $this->form->createElement('static', "Value$questionID", null);
            $group[]  = $this->form->createElement('static', "Comment$questionID", null);
            $this->form->addGroup($group, "group$questionID", $q['SequenceID'], $this->_GUIDelimiter, FALSE);
            unset($group);            
        }        
    }

    /**
     * Displays page#2, the symptoms ratings page.
     */
    function _page2()
    {
        $this->addHeader("KSAD - Symptoms Ratings");

        $timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());
        $pscid  = $candidate->getPSCID();
        $candID = $candidate->getCandID();
        $vlabel = $timepoint->getVisitLabel();

        //------------------------//
        // Display instructions   //
        //------------------------//
        $this->form->addElement('static', null, 'Instructions:');

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<i>The KSAD instrument will parse the symptoms ratings file you choose to upload "
                . "and  fill out the ratings section below.<br>"
                . "The uploaded file base name has to be <strong>ksad_ratings_{$pscid}_{$candID}_{$vlabel}</i><br><br>"
        );

        //----------------------------------------//
        // Add controls needed to upload the file //
        //----------------------------------------//
        $this->form->addElement('file'  , 'ksad_ratings_file'  , 'Upload the KSAD symptoms ratings file:');
        $this->form->addElement('static', 'RatingsFileName'    , 'Uploaded ratings file:');

        //--------------------------------//
        // Create the upload file button  //
        //--------------------------------//
        $buttons[] = $this->form->createElement(
            'submit',
            'fire_away',
            'Upload File',
            array('class' => 'button')
        );
        $this->addGroup($buttons, null, null, "&nbsp;");

        if ($this->getFieldValue('RatingsFileName') != false) {
            $this->XINRegisterRule('ksad_ratings_file', array("ksad_ratings_file{@}=={@}NEVER_REQUIRED"));
        }

        $this->form->addElement('static', null, '<br><br>');

        //-------------------------------------------//
        // Display questionnaire header              //
        //-------------------------------------------//
        $this->addScoreColumn('Symptom', 'Symptom');

        //------------------------------------------//
        // Display ratings in loaded file (if any)  //
        //------------------------------------------//
        foreach (self::RATINGS as $r) {
            $ratingFieldName = str_replace(' ', '', $r);
            $this->addScoreColumn($ratingFieldName, $r);
        }
    }

    /**
     * Invoked when a file is uploaded or when the top page is saved.
     *
     * @param $values array array of submitted values.
     */
    function _saveValues($values)
    {
        if ($this->page == 'ksad_page1') {
            //--------------------------------------------------//
            // If a response file has been uploaded, process it //
            //--------------------------------------------------//
            if ($values['ksad_responses_file']['name'] != false) {
                require_once "File_Upload.class.inc";
                $responsesFileUpload = new File_Upload;
                $uploadedFile = $this->_processUpload(
                    $responsesFileUpload,
                    'ksad_responses_file',
                    'isResponsesFileValid',
                    'importResponsesFile',
                    $values
                );
                if (!$uploadedFile) {
                    return null;
                }
                
                $values['ResponsesFileName'] = $uploadedFile;
                $this->_updateLocalDefaults();
                unset($values['ksad_responses_file']);
            }
        } elseif ($this->page == 'ksad_page2') {
            //--------------------------------------------------//
            // If a ratings file has been uploaded, process it  //
            //--------------------------------------------------//
            if ($values['ksad_ratings_file']['name'] != false) {
                require_once "File_Upload.class.inc";
                $ratingsFileUpload = new File_Upload;
                $uploadedFile = $this->_processUpload(
                    $ratingsFileUpload,
                    'ksad_ratings_file',
                    'isRatingsFileValid',
                    'importRatingsFile',
                    $values
                );
                if (!$uploadedFile) {
                    return null;
                }

                $values['RatingsFileName'] = $uploadedFile;
                $this->_updateLocalDefaults();
                unset($values['ksad_ratings_file']);
            }
        } 

        parent::_saveValues($values);
    }

    /**
     * Updates $this->LocalDefaults in order to display the pages properly.
     */
    function _updateLocalDefaults()
    {
        // This is needed for page1
        $db = Database::singleton();
        $questionnaireRows = $db->pselect(
            'SELECT QuestionID, SequenceID, QuestionText FROM ksad_questionnaire',
            []
        );

        $responseRows     = $db->pselect(
            'SELECT QuestionID, Value, Comment FROM ksad_responses WHERE CommentID=:commentID',
            array('commentID' => $this->getCommentID())
        );
  
        $responses = array();
        foreach ($responseRows as $r) {
            $questionID = $r['QuestionID'];
            $this->localDefaults["Value$questionID"]   = $r['Value'];
            $this->localDefaults["Comment$questionID"] = $r['Comment'];
        }

        // This is needed for page2
        $this->localDefaults['Symptom'] = 'Rating';
    }

    /**
     * Processes an uploaded file.
     *
     * @param $fileUpload FileUpload the object used to handle the upload.
     * @param $fileFieldName string name of the file field associated with the upload.
     * @param $verifyFunctionName string name of the function used to validate the file.
     * @param $importFunctionName string name of the function used to extract the information from the file.
     * @param $values array all the values submitted using the form.
     *
     * @return string the name of the processed file or null if an error occured.
     */
    function _processUpload($fileUpload, $fileFieldName, $verifyFunctionName, $importFunctionName, $values)
    {
        //-------------------------------------------//
        // Configure the FileUpload object properly  //
        //-------------------------------------------//
        $fileUpload->setOverwriteMode('overwrite');

        //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
        $fileUpload->registerForm($this->form);

        //Tell File_Upload what file handlers to use.
        $fileUpload->setFileHandler(
            $fileFieldName,
            $this,
            array(
              'verify' => $verifyFunctionName,
              'import' => $importFunctionName,
            )
        );

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir    = $config->getSetting('UploadDir') ?? '.';
        $fileUpload->setBaseUploadDirectory("$dir/ksad/");

        //set the the IDs to the handler functions.
        $user =& User::singleton();
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());

        $fileUpload->setHandlerArgs(
           array(
             'CommentID'  => $this->getCommentID(),
             'candID'     => $candidate->getCandID(),
             'PSCID'      => $candidate->getPSCID(),
             'visitLabel' => $timepoint->getVisitLabel(),
             'username'   => $user->getUsername(),
             'values'     => $values
           )
       );

       //------------------------------------------//
       // Process the uploaded file. This includes //
       // validation, relocation to the ksad       //
       // upload directory and storage of all the  //
       // information contained in the file in the //
       // database                                 //
       //------------------------------------------//
       $fileUpload->processFiles();

       //--------------------------------------//
       // Check if the uploaded file is valid  //
       // If not, display the first 10 errors  //
       // found. This error message block will //
       // be displayed at the top of the page  //
       //--------------------------------------//
       $errors = $fileUpload->getErrors();
       if (isset($errors[$fileFieldName]) && !empty($errors[$fileFieldName])) {
           $errorMessages[] = $this->htmlErrorMessage('<strong>Processing of the uploaded file failed:</strong>');
           for($i=0; $i < count($errors[$fileFieldName]) && $i < self::MAX_UPLOAD_ERRORS_SHOWN; $i++) {
               $errorMessages[] = $this->htmlErrorMessage($errors[$fileFieldName][$i]);
           }
           if(count($errors[$fileFieldName]) > self::MAX_UPLOAD_ERRORS_SHOWN) {
               $nbErrorsNotShown = count($errors[$fileFieldName]) - self::MAX_UPLOAD_ERRORS_SHOWN;
               $errorMessages[] = $this->htmlErrorMessage("... ( $nbErrorsNotShown more error(s) ) ...");
           }
           $this->form->addElement('static', 'mainError');
           $this->form->setElementError('mainError', implode("\n", $errorMessages));

           return null;
       }

       return $fileUpload->getDestinationDirectory() . $fileUpload->getDestinationFilename();
    }

    /**
     * Formats a text message using a red text color.
     *
     * @param $msg string message to format.
     *
     * @return string formatted message.
     */
    function htmlErrorMessage($msg) 
    {
        return "<p><font color='red'>$msg</font></p>";
    }

    /**
     * Checks the validity of the responses file.
     *
     * @param string $file The full filename including directory.
     *
     * @return array The errors found or null if no errors were found.
     */
    function isResponsesFileValid(&$file, $args){
        //------------------------------------//
        // Validate the uploaded file name    //
        //------------------------------------//
        $correctFilename = "ksad_responses_{$args['PSCID']}_{$args['candID']}_{$args['visitLabel']}.csv";
        if ($file->fileInfo['name'] != $correctFilename) {
            $errors[] = "Incorrect name {$file->fileInfo['name']} for the response file: it should be $correctFilename";
            return $errors;
        }

        //---------------------------------------------------//
        // Load the ID of each question in the questionnaire //
        // in hash array $sequenceID                         //
        //---------------------------------------------------//
        $db = Database::singleton();
        $rows = $db->pselect(
            'SELECT SequenceID FROM ksad_questionnaire',
            []
        );
        $sequenceID = [];
        foreach ($rows as $r) {
            $sequenceID[$r['SequenceID']] = 1;
        }

        //-------------------------------------------------------//
        // Parse uploaded file. Ensure each question ID is valid //
        // and each line has at least 5 fields                   //
        //-------------------------------------------------------//
        $errors = [];
        $handle = fopen($file->fileInfo['tmp_name'], 'r');
        if ($handle === FALSE) {
            return ["Cannot read file {fileInfo['tmp_name']}"];
        }

        while ($fields = fgetcsv($handle)) {
            if (count($fields) == 5 && $fields[0] == 'QuestionID') {
                continue;
            }

            if (count($fields) < 5 || !isset($sequenceID[strtoupper($fields[1])])) {
                $errors[] = sprintf(
                    "Invalid line found in file {$file->fileInfo['name']}: %s",
                    implode(',', $fields)
                );
            }
        }

        return empty($errors) ? null : $errors;
    }

    /**
     * Checks the validity of the ratings file.
     *
     * @param string $file The full filename including directory.
     *
     * @return array the list of errors found or null if none were found.
     */
    function isRatingsFileValid(&$file, $args){
        //------------------------------------//
        // Validate the uploaded file name    //
        //------------------------------------//
        $correctFilename = "ksad_ratings_{$args['PSCID']}_{$args['candID']}_{$args['visitLabel']}.csv";
        if ($file->fileInfo['name'] != $correctFilename) {
            $errors[] = "Incorrect name {$file->fileInfo['name']} for the ratings file: it should be $correctFilename";
            return $errors;
        }

        //--------------------------------------------------------//
        // Parse uploaded file. Ensure each rating label is valid //
        // and each line has at least 2 fields                    //
        //--------------------------------------------------------//
        $handle = fopen($file->fileInfo['tmp_name'], 'r');
        if ($handle === FALSE) {
            return ["Cannot read file {fileInfo['tmp_name']}"];
        }

        $errors        = [];
        $ratingsInFile = [];
        while ($fields = fgetcsv($handle)) {
            if (count($fields) && $fields[0] == 'ModuleName') {
                continue; 
            }

            if (count($fields) < 2 ||  !in_array($fields[0], self::RATINGS)) {
                $errors[] = sprintf(
                    "Invalid line found in file {$file->fileInfo['name']}: %s",
                    implode(',', $fields)
                );
            } elseif(isset($ratingsInFile[$fields[0]])) {
                $errors[] = sprintf(
                    "Duplicate rating $fields[0] found in file {$file->fileInfo['name']}: %s",
                    implode(',', $fields)
                );
            } else {
                $ratingsInFile[$fields[0]] = 1;
            }
        }

        if (count($ratingsInFile) != count(self::RATINGS)) {
            foreach (self::RATINGS as $r) {
                if (!isset($ratingsInFile[$r])) {
                    $errors[] = "No rating for symptom $r found in {$file->fileInfo['name']}";
                }
            }
        }

        return empty($errors) ? null : $errors;
    }

    /**
     * Parses a valid responses file and stores the information it contains
     * in the database.
     *
     * @param object      $file A reference to the file object (passed automatically by callFileHandler).
     * @param assoc_array $args The arguments passed to the function.
     *
     * @return array the list of errors that occured during processing or null if
     *               everything worked perfectly.
     */
    function importResponsesFile(&$file, $args){
        //---------------------------------------------------//
        // Load the ID of each question in the questionnaire //
        // in hash array $sequenceID                         //
        //---------------------------------------------------//
        $db = Database::singleton();
        $rows = $db->pselect(
            'SELECT QuestionID, SequenceID FROM ksad_questionnaire',
            []
        );
        $sequenceID = [];
        foreach ($rows as $r) {
            $sequenceID[strtoupper($r['SequenceID'])] = $r['QuestionID'];
        }

        $handle = fopen($file->fileInfo['tmp_name'], 'r');
        if ($handle === FALSE) {
            return ["Cannot read file {fileInfo['tmp_name']}"];
        }

        $db =& Database::singleton();
        while ($fields = fgetcsv($handle)) {
            if (count($fields) == 5 && $fields[0] == 'QuestionID') {
                continue;
            }
            $newValues[] = sprintf(
                "(%s, %s, %s, %s)",
                $db->quote($this->getCommentID()),
                $db->quote($sequenceID[strtoupper($fields[1])]),
                $db->quote($fields[3]),
                $db->quote($fields[4])
            );
        }

        $query = "INSERT INTO ksad_responses (CommentID, QuestionID, Value, Comment) VALUES "
               . implode(',', $newValues)
               . " ON DUPLICATE KEY UPDATE Value=VALUES(Value), Comment=VALUES(Comment)";
        $result = $db->run($query);

        return true;
    }

    /**
     * Parses a valid ratings file and stores the information it contains
     * in the database.
     *
     * @param object      $file A reference to the file object (passed automatically by callFileHandler).
     * @param assoc_array $args The arguments passed to the function.
     *
     * @return array the list of errors that occured during processing or null if
     *               everything worked perfectly.
     */
    function importRatingsFile(&$file, $args){
        $handle = fopen($file->fileInfo['tmp_name'], 'r');
        if ($handle === FALSE) {
            return ["Cannot read file {fileInfo['tmp_name']}"];
        }

        while ($fields = fgetcsv($handle)) {
            if (count($fields) && $fields[0] == 'ModuleName') {
                continue;
            }
      
            $ratingFieldName              = str_replace(' ', '', $fields[0]);
            $newRatings[$ratingFieldName] = $fields[1];
        }

        $db =& Database::singleton();
        if (!empty($newRatings)) {
            $db->update('ksad', $newRatings, ['CommentID' => $this->getCommentID()]);
        }
  
        return true;
    }

    /**
     * Formats a date in YYYY-MM-DD format.
     *
     * @param $date array the date pieces.
     *
     * @return string the formatted date.
     *
    function formatDate($date){
        if(empty($date)){
            return null;
        }
        $dateBits = explode('/', $date);
        return sprintf("%04d-%02d-%02d", $dateBits[2], $dateBits[0], $dateBits[1]);
    }

    /**
     * Retrieves info about where the file should be stored.
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
