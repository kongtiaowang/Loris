<?php
/*
 * This file contains the NDB_BVL_Instrument_DAS_SA
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
 * Creates the form elements for the DAS_SA instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_DAS_SA extends NDB_BVL_Instrument
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
        $this->testName = "DAS_SA";           // test_names.Test_name
        $this->table = 'DAS_SA';              // name of table containing

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
            "/DAS_SA(_page[0-9]+)/",
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
        $this->form->addElement('file', 'das_sa_file', 'Upload the DAS SA file 
       <br><h6><i>(Ex: DAS_SA_PSCID_VSA.txt)</i></h6>');

        $this->form->addElement('static', "File_name", "Uploaded File");


        $this->form->addElement('header', null, "Core Cluster and Composite Scores and Indexes ");


        //scoring column headers
        $group[] = $this->form->createElement('static', "T_SCORE", null, null);
        $group[] = $this->form->createElement('static', "STD_SCORE", null, null);
        $group[] = $this->form->createElement('static', "PERCENTILE", null, null);
        $group[] = $this->form->createElement('static', "CI", null, null);
        $group[] = $this->form->createElement('static', "QD", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Cluster/Composite</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains = array("verbal" => "Verbal","non_verb_reasoning" => "Non Verbal Reasoning","spatial" => "Spatial",
            "GCA" => "GCA", "SNC" => "SNC"
        );
        $columnHeaders = array("T_Score" => "Sum of T- Scores", "STD_SCORE" => "Standard Score",
             "PERCENTILE" => "Percentile Rank","CI" => "95% Confidence Interval",
             "QD" => "Qualitative Description"
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


    $this->form->addElement('header', null, "Cluster Subtest Scores Summary");
        $group[] = $this->form->createElement('static', "RAW", null, null);
        $group[] = $this->form->createElement('static', "ITEM_SET", null, null);
        $group[] = $this->form->createElement('static', "ABILITY_SCORE", null, null);
        $group[] = $this->form->createElement('static', "T_SCORE", null, null);
        $group[] = $this->form->createElement('static', "PERCENTILE", null, null);
        $group[] = $this->form->createElement('static', "AGE_EQUIV", null, null);
        $this->form->addGroup($group, 'score_header_group1', "<strong>Subtest</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains1 = array(1 => "Verbal Ability Cluster Subtest Scores Summary ","verbal_similarities" => "Verbal Similarities",
            "word_defn" => "Word Definitions",
            2 => "Nonverbal Reasoning Ability Cluster Subtest Scores","matrices" => "Matrices",
            "seq_qr" => "Sequential and Quantitative Reasoning",
            3 => "Spatial Ability Cluster Subtest Scores Summary","rd" => "Recall of Designs",
            "PC" => "Pattern Construction"
        );
        $columnHeaders1 = array("RAW" => "Raw Score", "ITEM_SET" => "Item Set",
           "ABILITY_SCORE" => "Ability Score",
            "T_SCORE" => "T_SCORE", "PERCENTILE" => "Percentile", "AGE_EQUIV" => "Age Equivalence"
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




       if($this->getFieldValue("File_name")===false){
            $this->form->addRule("das_sa_file", "DAS SA file is required.", 'required', null, 'server');
        } else {
            $this->XINRegisterRule("das_sa_file", array("das_sa_file{@}==={@}NEVER_REQUIRED"));
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
        $file->setFileHandler("das_sa_file", $this);

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("UploadDir");
        if(empty($dir)) {
            $dir = ".";
        };
        $file->setBaseUploadDirectory($dir . "/DAS_SA/");

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
        if ($values['das_sa_file']['name'] != false) {
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
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['das_sa_file']);
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

        $test_date_key = array_search('Date of Report', $lines);
        $values['Date of Report'] =$lines[$test_date_key+1];

        $values['Date of Report'] = $this->formatDate($values['Date of Report']);

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
            'File_type' =>'DAS_SA',
            'File_name' =>$file->getDestinationFilename(),
            'Data_dir'  =>$file->getDestinationDirectory()
        );


        //Cycle through the lines and extract the data
        $lines =preg_split("/\\r\\n|\\r|\\n/", $contents);
        $lines =  str_replace(">","greater than ",$lines);
        $lines =  str_replace("<","less than ",$lines);

        $group[] = $this->form->createElement('static', "T_SCORE", null, null);
        $group[] = $this->form->createElement('static', "STD_SCORE", null, null);
        $group[] = $this->form->createElement('static', "PERCENTILE", null, null);
        $group[] = $this->form->createElement('static', "CI", null, null);
        $group[] = $this->form->createElement('static', "QD", null, null);
        $domains = array("verbal" => "Verbal","non_verb_reasoning" => "Nonverbal Reasoning","spatial" => "Spatial",
            "GCA" => "GCA", "SNC" => "SNC"
        );
        foreach ($domains as $key => $val) {
            $array_key=array_search($val,$lines);
            $val_count=$array_key+5;
            $count=0;
            ${$key."_DOMAIN"}= array("{$key}_T_SCORE","{$key}_STD_SCORE","{$key}_PERCENTILE","{$key}_CI","{$key}_QD");
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
        $domains1 = array("verbal_similarities" => "Verbal Similarities",
            "word_defn" => "Word Definitions",
            "matrices" => "Matrices",
            "seq_qr" => "Sequential and Quantitative Reasoning",
            "rd" => "Recall of Designs",
            "pc" => "Pattern Construction"
        );
        foreach ($domains1 as $key => $val) {
            $array_key=array_search($val,$lines);
            $val_count=$array_key+6;
            $count=0;
            ${$key."_DOMAIN"}= array("{$key}_RAW","{$key}_ITEM_SET","{$key}_ABILITY_SCORE","{$key}_T_SCORE","{$key}_PERCENTILE","{$key}_AGE_EQUIV");
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
