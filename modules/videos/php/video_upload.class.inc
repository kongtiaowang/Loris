<?php
namespace LORIS\videos;
/**
 * The forms for the new profile menu
 * @package main
 */

function hash_it($array, $item){
    $new_array = array();
    foreach($array as $key => $value){
        $new_array[$array[$key][$item]]=$array[$key][$item];
    }
    return $new_array;
}


class video_upload extends \NDB_Form
{



    function _hasAccess()
    {
        error_log("_hasAccess");
        // create user object
        $user =& \User::singleton();

        if ($user->hasPermission('earli_videos')) {
            return true;
        }
        if ($user->hasStudySite()) {
            return $user->hasPermission('data_entry');
        }
        return false;
    }

    function _isEARLIUser() {
        error_log("_isEARLIUser");
        $user =& \User::singleton();
        return $user->hasPermission('earli_videos') && !$user->hasPermission('data_entry');
    }

    function _process($values)
    {
        error_log("_process");
        if($values['hide_video'] || $values['hide_video_confirm']) {
            // Validate should have already checked this, but double check
            if($values['hide_video'] && $values['hide_video_confirm']) {
                $DB =& \Database::singleton();
                $DB->update("videos", array('hide_video' => true), array('record_id' => $this->identifier));
                $this->tpl_data['message'] = true;
            }
        }
        // set up the arguments to Candidate::createNew

        //------------------------------------------------------------

        elseif($this->_saveFile($values)){
            $this->tpl_data['success'] = true;

            // freeze it, just in case
            $this->form->freeze();
        }

    }

    function setup()
    {
        parent::setup();
        error_log("video_upload");
        // create user object
        $user =& \User::singleton();

        $siteIDs = $user->getData('CenterIDs');
        $site_string="";
        foreach ($siteIDs as $val) {
            $site =& \Site::singleton($val);
            if ($site->isStudySite()) {
                $siteList[$site->getCenterName()] = $site->getCenterName();
                if ($site_string) $site_string .= '|';
                $site_string.=$siteList[$site->getCenterName()];
            }
        }
        $config =& \NDB_Config::singleton();
        $db =& \Database::singleton();

        $instruments = $db->pselect("SELECT test_name FROM test_names ORDER BY test_name", array());


        $instruments = hash_it($instruments, "test_name");
        unset($instruments['EARLI_interview_PART_1']);
        unset($instruments['EARLI_interview_PART_2']);
        unset($instruments['EARLI_interview_PART_3']);
        unset($instruments['EARLI_interview_PART_4']);
        unset($instruments['EARLI_interview_revised']);
        if($this->_isEARLIUser()) {
            $instruments = array ('aosi' => 'AOSI'); // add others here
        }
        if($user->hasPermission('earli_videos')) {
            $instruments = array_merge($instruments, array('EARLI' => 'EARLI Questionaire'));
        }

        $candidates = $db->pselect("SELECT PSCID FROM candidate WHERE PSCID REGEXP '$site_string' ORDER BY PSCID");
        $candidates2 = $db->pselect("SELECT PSCID FROM candidate WHERE PSCID NOT REGEXP '$site_string' ORDER BY PSCID");
        if ($user->hasPermission('access_all_profiles')) {
            $candidates = hash_it($candidates + $candidates2, "PSCID");
        }
        else{
            $candidates = hash_it($candidates, "PSCID");
        }

        $this->addSelect("Instrument", "Instrument", $instruments);
        if($this->_isEARLIUser()) {
            $this->addBasicText("PSCID", "PSCID");
        } else {
            $this->addSelect("PSCID", "PSCID", $candidates);
        }
        $visit_list = \Utility::getVisitList();
        $this->addSelect("visitLabel", "Visit Label", $visit_list);
        $dateOptions = array(
            'language' => 'en',
            'format'   => 'YMd',
            'minYear'  => $config->getSetting('startYear'),
            'maxYear'  => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null
        );

        $this->addBasicDate('Date_taken', 'Date of Administration', $dateOptions);
        //$this->form->addElement("select", "For_site", "Site This File is Being Uploaded For", array(null, "DCC", "SEA", "PHI", "STL", "UNC", "UofA"));
        $this->addSelect("For_site", "Site This File is Being Uploaded For", \Utility::getSiteList(false));
        $this->addSelect("multipart", "Is this upload split into multiple parts?", array("Yes" => "Yes", "No" => "No"));
        $this->addSelect("EARLI", "Is this an EARLI collaboration video?", array('' => '', "1" => "Yes", "0" => "No"));
        $this->addBasicTextArea("comments", "Comments (optional)", array('rows' => 5, 'cols' => 50));
        if($this->identifier){
            $this->form->addElement('static', 'File_name', 'File name');
        }else{
            $this->form->addElement('file', 'video_file', 'File to Upload');
            $this->form->addRule('video_file', 'No file selected.', 'required');
        }

        $this->form->addRule('PSCID', 'PSCID required.', 'required');
        $this->form->addRule('Instrument', 'Instrument is required.', 'required');
        $this->form->addRule('visitLabel', 'Visit Label is required.', 'required');

        $this->addCheckbox("hide_video", "Delete video",array('value' => '1'));
        $this->addCheckbox("hide_video_confirm", "Delete video (Confirmation)",array('value' => '1'));


        $uploaded_by = $db->pselectOne("SELECT uploaded_by FROM videos WHERE record_id=:identifier", array(':identifier' => $this->identifier));
        if($uploaded_by == $user->getUsername()) {
            $this->tpl_data['has_delete_permission'] = true;
        }

        $this->form->addFormRule(array(&$this, '_validate'));
    }

    function _validate($values)
    {
        error_log("_validate");
        error_log(print_r($values, true));
        error_log(print_r($_REQUEST, true));

        $errors = array();
        if($values['hide_video'] || $values['hide_video_confirm']) {
            if(empty($values['hide_video']) || empty($values['hide_video_confirm'])) {
                $errors['hide_video'] = "Must check BOTH boxes to delete";
            }
        }
        if($values['EARLI'] == '' || !isset($values['EARLI'])) {
            $errors['EARLI'] = "EARLI collaboration video flag required.";
        }


        // if (empty($values['gender'])) {
        //         $errors['gender'] = 'Gender is required';
        //     }
        error_log(print_r($errors, true));
        return $errors;
    }

    /**
     * getTargetDirectory retrieves info about where the file should be stored.
     *
     * The returned directory is ADDED to the baseUploadDirectory property.  It should have a trailing slash.
     *
     * @param     string  $file    The full filename including directory.
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function getTargetDirectory(&$file, $args){
        error_log("getTargetDirectory");
        $output="{$args["user_id"]}/";
        return $output;
    }

    // methods available to all children
    /**
     * Save the file to the DataBase
     *
     * @param array $values      the array of values from the form
     * @return true on success, false othewise
     * @access private
     */
    function _saveFile($values)
    {
        error_log(print_r($values, true));

        if(isset($values['Date_taken'])) {
            $Date_taken = $values['Date_taken'];
            $values['Date_taken'] = sprintf("%04d-%02d-%02d", $Date_taken['Y'], $Date_taken['M'], $Date_taken['d']);
        }

        if(!empty($this->identifier)){
            $db=& \Database::singleton();
            $result = $db->update('videos', $values, array('record_id'=>$this->identifier));
            return true;
        }else{
            error_log("in _saveFile else");


            $file=new \File_Upload;
            //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
            $file->registerForm($this->form);

            //Tell File_Upload what file handlers to use.
            // Removed &$this because Call-time pass-by-reference has been removed from PHP.
            $file->setFileHandler("video_file", $this);
            $file->overwriteMode="overwrite";

            //Set the target directory that you want files moved into once they are validated and processed.
            $file->setBaseUploadDirectory("../../../../../../../var/www/loris/project/modules/temp_videos/videos");

            //Set the prefix to prepend to the filenames
            //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

            $user =& \User::singleton();

            //set the the IDs to the handler functions.
            $file->setHandlerArgs(array("user_id" => $user->getUsername(), "values"=>$values));

            //If the form is validated, call File_Upload::processFiles() which loops through the files and 
            //processes them (including verify, move, and import steps)
            $file->processFiles();

            //echo error messages
            if(!empty($file->errorLog)){
               while(list($fileType,$fileErrors)=each($file->errorLog)){
                   foreach($fileErrors AS $error){
                        echo "Upload Error. $fileType: $error";
                   }
               }
               return false;
            }
            return true;
        }

    }

    function _getDefaults()
    {
        // Default to "No" for multipart, so that the behaviour doesn't
        // change
        $defaults = array('multipart' => 'No', 'EARLI' => 'No');
        error_log("getDefaults");
        if (!empty($this->identifier)) {
            $db=& \Database::singleton();

            $row = $db->pselectRow("SELECT * FROM videos WHERE record_id =:rid", array('rid' => $this->identifier));

            // get the user defaults
            $defaults = $row;
        }

        error_log(print_r($defaults, true));
        return $defaults;
    }

    function isValid(&$file, $args){
        $errors = array();

        error_log("isValid");
        $correct_filename = $args['values']['PSCID'] .'_'. $args['values']['visitLabel'] .'_'. $args['values']['Instrument'];

        $Stmt = "SELECT count(*) as Total FROM videos WHERE Instrument =:instrum AND PSCID =:pid AND visitLabel =:visit";

        $db=& \Database::singleton();
        $CountFiles = $db->pselectRow($Stmt, array('instrum' => $args['values']['Instrument'], 'pid' => $args['values']['PSCID'], 'visit' => $args['values']['visitLabel']));
        if($CountFiles['Total'] > 1 && $_REQUEST['multipart'] != 'Yes') {
            $errors[]="Incorrect value for split file selected.";
        }

        if(!preg_match("/^{$correct_filename}/i", $file->fileInfo['name']) ){
            $errors[]="Incorrect Filename: Filename begin with: " . $correct_filename;
        }

        if(count($errors) > 0)
            return $errors;

        return true;
    }

    function importFile(&$file, $args){
        $filename = $file->getDestinationFileName();
        $values=array(
            'File_type' =>'video_file',
            'File_name' =>$filename,
            'Data_dir'  =>$file->getDestinationDirectory(),
            'File_size' => $file->fileInfo['size'],
            'Instrument'=>$args['values']['Instrument'],
            'PSCID'=>$args['values']['PSCID'],
            'uploaded_by' => $args['user_id'],
            'For_site' => $args['values']['For_site'],
            'visitLabel' => $args['values']['visitLabel'],
            'Date_taken' => $args['values']['Date_taken'],
            'comments' => $args['values']['comments'],
            'EARLI' => $args['values']['EARLI']
        );

        error_log("importFile");
        error_log(print_r($values, true));

        $db=& \Database::singleton();

        // SQL to run to check if the file's already
        $Stmt = "SELECT * FROM videos WHERE Instrument =:instrum AND PSCID =:pid AND visitLabel =:visit";

        $params = array('instrum' => $values['Instrument'], 'pid' => $values['PSCID'], 'visit' => $values['visitLabel']);

        if($_REQUEST['multipart'] == 'Yes') {
            $Stmt .= " AND File_name=:fn";
            $params = array_merge($params, array('fn' => $filename));
        }
        $row = $db->pselectRow($Stmt, $params);

        if (empty($row)) {

            // insert the event
            $result = $db->insert('videos', $values);

        } else {
            // update the event
            $WhereCriteria = array('PSCID'=>$args['values']['PSCID'],
                'Instrument'=>$args['values']['Instrument'],
                'visitLabel' => $args['values']['visitLabel']);

            // Using this if statement makes duplicates appear if a
            // multipart file was already uploaded, and they forget
            // to change the dropdown for the second upload. So for
            // now the filename is always part of the criteria.
            if($_REQUEST['multipart'] == 'Yes') {
                $WhereCriteria['File_name'] = $filename;
            }

            $values['hide_video'] = false;
            $result = $db->update('videos', $values, $WhereCriteria);
        }

        //$result = $db->update('videos', $values, array('PSCID'=>$args['values']['PSCID'], 'Instrument'=>$args['values']['Instrument'], 'visitLabel' => $args['values']['visitLabel']));
        return true;
    }
}
?>
