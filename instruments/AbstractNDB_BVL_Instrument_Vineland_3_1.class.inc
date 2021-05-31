<?php
/*
 * This file contains the AbstractNDB_BVL_Instrument_Vineland_3
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the abstract Vineland_3 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Nicolas Brossard
 * @link     https://www.github.com/aces/IBIS/
 */


abstract class AbstractNDB_BVL_Instrument_Vineland_3_1 extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /**
     * Gets the test name.
     *
     * return string test name.
     */
    abstract function getTestName() : string;

    /**
     * Gets the name of the database table where the instrument data
     * is saved.
     *
     * return string table name.
     */
    abstract function getTableName() : string;

    /**
     * Gets the instrument short name.
     *
     * return string instrument short name.
     */
    abstract function getInstrumentShortName() : string;

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
        $this->testName = $this->getTestName();
        $this->table    = $this->getTableName();

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

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement(
            'file',
            "{$this->testName}_file",
            sprintf(
                "Upload the %s file<br><h6><i>(Ex: %s_PSCID_V12.txt)</i></h6>",
                $this->getInstrumentShortName(),
                $this->testName
            )
        );

        $this->form->addElement('static', "File_name", "Uploaded File");


        $this->form->addElement('header', null, "ABC and Domain Score Summary ");


        //scoring column headers
        $group[] = $this->form->createElement('static', "STD_SCORE", null, null);
        $group[] = $this->form->createElement('static', "90_CI", null, null);
        $group[] = $this->form->createElement('static', "PERCENTILE", null, null);
        $group[] = $this->form->createElement('static', "SS_Minus_Mean_SS", null, null);
        $group[] = $this->form->createElement('static', "strength_weakness", null, null);
        $group[] = $this->form->createElement('static', "base_rate", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>ABC</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains = array("adapt_behave_comp" => "Adaptive Behaviour Composite",1 => "Domains","communication" => "Communication",
            "daily_living_skills" => "Daily Living Skills", "socialization" => "Socialization", "motor_skills" => "Motor Skills"
        );
        $columnHeaders = array("STD_SCORE" => "Standard Score (SS)", "90_CI" => "90 % Confidence Interval",
             "PERCENTILE" => "Percentile Rank","SS_Minus_Mean_SS" => "SS Minus Mean SS",
             "strength_weakness" => "Strength OR weakness",  "base_rate" => "Base Rate",
        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                if (is_int($field)) {
                    $group[] = $this->form->createElement('static', null, null, null);
                }
                else {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            if (is_int($field)) {
                // echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group", "<strong>$label</strong>", $this->_GUIDelimiter, FALSE);
            }
            else {
                // echo "$label.hdfdello\n";
                $this->form->addGroup($group, "{$label}_group", $label, $this->_GUIDelimiter, FALSE);
            }
            unset($group);


        }


    $this->form->addElement('header', null, "Subdomain Score Summary");
        $group[] = $this->form->createElement('static', "RAW_SCORE", null, null);
        $group[] = $this->form->createElement('static', "v_Scale_Score", null, null);
        $group[] = $this->form->createElement('static', "age_equiv", null, null);
        $group[] = $this->form->createElement('static', "growth_scale_value", null, null);
        $group[] = $this->form->createElement('static', "percent_estimated", null, null);
        $group[] = $this->form->createElement('static', "vs_minus_mean_vs", null, null);
        $group[] = $this->form->createElement('static', "strength_weakness", null, null);
        $group[] = $this->form->createElement('static', "base_rate", null, null);
        $group[] = $this->form->createElement('static', "QD", null, null);
        $this->form->addGroup($group, 'score_header_group1', "<strong>Subdomains</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains1 = array(1 => "Communication Domains ","receptive" => "Receptive","expressive" => "Expressive","written" => "Written",
            2 => "Daily Living Skills Domain","personal" => "Personal","domestic" => "Domestic","community" => "Community",
            3 => "Socialization Domain","inter_pers_rel" => "Interpersonal Relationships","play_leisure" => "Play and Leisure","copy_skills" => "Coping Skills",
            4 => "Motor Skills Domain","gross_motor" => "Gross Motor","fine_motor" => "Fine Motor",

        );
        $columnHeaders1 = array("RAW_SCORE" => "Raw Score", "v_Scale_Score" => "v Scale Score",
           "age_equiv" => "Age Equivalent","growth_scale_value" => "Growth Scale Value",
            "percent_estimated" => "Percent Estimated", "vs_minus_mean_vs" => "vs Minus Mean vs", "strength_weakness" => "Strength or Weakness",
            "base_rate" => "Base Rate",
        );

        foreach ($columnHeaders1 as $field => $label) {
            $columnHeaders1[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders1);

        foreach ($domains1 as $field => $label) {
            foreach ($columnHeaders1 as $scoreField => $scoreLabel) {
                if (is_int($field)) {
                    $group[] = $this->form->createElement('static', null, null, null);
                }
                else {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            if (is_int($field)) {
               // echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group", "<strong>$label</strong>", $this->_GUIDelimiter, FALSE);
            }
            else {
               // echo "$label.hdfdello\n";
                $this->form->addGroup($group, "{$label}_group", $label, $this->_GUIDelimiter, FALSE);
            }
            unset($group);


        }




       if($this->getFieldValue("File_name")!=false){
            $this->XINRegisterRule("{$this->testName}_file", array("{$this->testName}_file{@}=={@}NEVER_REQUIRED"));
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
        $file->setFileHandler("{$this->testName}_file", $this);

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("UploadDir");
        if(empty($dir)) {
            $dir = ".";
        };
        $file->setBaseUploadDirectory($dir . "/{$this->testName}/");

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
        if ($values["{$this->testName}_file"]['name'] != false) {
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
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values["{$this->testName}_file"]);
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
        $correct_filename = ($this->testName.'_'. $args['PSCID'].'_'.$args['visitLabel']. ".txt");
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


       //Implement if needed.
       /* if(!empty($args['values']['Date_taken']) && !empty($values['Date of Report']) && ($args['values']['Date_taken'] != $values['Date of Report'])){
            $errors['Date of Administration']="Date of administration in the file ({$values['Date of Report']}) does not match the date of administration entered ({$args['values']['Date_taken']})." ;
            return $errors;
        }*/

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
            'File_type' =>$this->testName,
            'File_name' =>$file->getDestinationFilename(),
            'Data_dir'  =>$file->getDestinationDirectory()
        );


        //Cycle through the lines and extract the data
        $lines =preg_split("/\\r\\n|\\r|\\n/", $contents);
        //print_r($lines);
        //exit;

        $domains = array("adapt_behave_comp" =>"Adaptive Behavior Composite" ,"communication" => "Communication",
            "daily_living_skills" => "Daily Living Skills", "socialization" => "Socialization", "motor_skills" => "Motor Skills"
        );

        foreach ($domains as $key => $val) {
           // echo $val;
            $array_key=array_search($val,$lines);
            $val_count=$array_key+6;
            $count=0;
            ${$key."_DOMAIN"}= array("{$key}_STD_SCORE","{$key}_90_CI","{$key}_PERCENTILE","{$key}_SS_Minus_Mean_SS","{$key}_strength_weakness","{$key}_base_rate");
            if($array_key!=NULL) {
                for ($i = $array_key + 1; $i <= $val_count; $i++) {
                    $values[${$key.'_DOMAIN'}[$count]] = $lines[$i];
                    $count++;
                }


            }
            else{
                foreach(${$key.'_DOMAIN'} as $val)
                {
                    $values[$val]='--';
                }
            }
        }

        $domains1 = array("receptive" => "Receptive","expressive" => "Expressive","written" => "Written",
            "personal" => "Personal","domestic" => "Domestic","community" => "Community",
            "inter_pers_rel" => "Interpersonal Relationships","play_leisure" => "Play and Leisure","copy_skills" => "Coping Skills",
            "gross_motor" => "Gross Motor","fine_motor" => "Fine Motor",
        );

        foreach ($domains1 as $key => $val) {
            $array_key=array_search($val,$lines);
            $val_count=$array_key+8;
            $count=0;
            ${$key."_DOMAIN"}= array("{$key}_RAW_SCORE","{$key}_v_Scale_Score","{$key}_age_equiv","{$key}_growth_scale_value","{$key}_percent_estimated","{$key}_vs_minus_mean_vs",
                "{$key}_strength_weakness","{$key}_base_rate",);
            if($array_key!=NULL) {
                for ($i = $array_key + 1; $i <= $val_count; $i++) {
                    $values[${$key.'_DOMAIN'}[$count]] = $lines[$i];
                    $count++;
                }


            }
            else{
                foreach(${$key.'_DOMAIN'} as $val)
                {
                    $values[$val]='--';
                }
            }
        }




        $db=& Database::singleton();

///Setting trackchanges to false because getting error messages
        $db->_trackChanges = false;
////////////////////////////////////////////////////////////////

        $values= str_replace(">", "Greater than ", $values);

        $values= str_replace("<", "Less than ", $values);

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
