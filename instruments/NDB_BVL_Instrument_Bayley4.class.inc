<?php
/*
 * This file contains the NDB_BVL_Instrument_Bayley4
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Shen Wang
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the PVT instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Shen Wang
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_Bayley4 extends NDB_BVL_Instrument
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
        $this->testName = "Bayley4";           // test_names.Test_name
        $this->table = 'Bayley4';              // name of table containing

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
            "/Bayley4(_page[0-9]+)/",
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
        $this->form->addElement('header', null, "Bayley Scales of Infant and Toddler Development™, Fourth Edition (Bayley™-4)");

        $this->form->addElement('static', "title", "Cognitive, Language, and Motor Scales Score Report
         Nancy Bayley, PhD, Glen P. Aylward, PhD, ABPP
        ");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement('file', 'bayley4_file', 'Upload the Bayley4 doc file<br><h6><i>(Filename should be Bayley4_CandID_PSCID_VisitLabel.doc)</i></h6>');

        $this->form->addElement('static', "File_name", "Uploaded File");
        $this->form->addElement('header', null, "Examinee Information");

     $this->form->addElement('static','ID','ID:');
     $this->form->addElement('static','Name','Name:');
     $this->form->addElement('static','Gender','Gender:');
     $this->form->addElement('static','Birth_Date','Birth Date:');
     $this->form->addElement('static','Test_Date','Test Date:');
     $this->form->addElement('static','Examiner_Name','Examiner Name:');
     $this->form->addElement('static','Relationship','Relationship to Child:');
     $this->form->addElement('static','Test_age','Test Age:');




     // table 1

         $this->form->addElement('header', null, "Standard Score Summary");
         $this->form->addElement('static', 'title1', "Subtest Scaled Score Summary");

        $group[] = $this->form->createElement('static', "RAW_Score", null, null);
        $group[] = $this->form->createElement('static', "Scaled_Score", null, null);
        $group[] = $this->form->createElement('static', "Age_Equivalent", null, null);
        $group[] = $this->form->createElement('static', "Growth_Scale_Value", null, null);
        $this->form->addGroup($group, 'score_header_group1', "<strong>Scale Subtest</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains1 = array(1 => "Cognitive","Cognitive_CG" => "Cognitive (CG)",
            2 => "Language","Receptive_Communication_RC" => "Receptive Communication (RC)",
            "Expressive_Communication_EC" => "Expressive Communication (EC)",
            3 => "Motor","Fine_Motor_FM" => "Fine Motor (FM)",
            "Gross_Motor_GM" => "Gross Motor (GM)"
        );
        $columnHeaders1 = array("RAW_Score" => "Raw Score", "Scaled_Score" => "Scaled score",
           "Age_Equivalent" => "Age equivalent",
            "Growth_Scale_Value" => "Growth scale value"
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
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group", "<strong>$label</strong>", $this->_GUIDelimiter, FALSE);
            }
            else {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group", $label, $this->_GUIDelimiter, FALSE);
            }
            unset($group);


        }
     //table 2    todo : table2
         $this->form->addElement('static', 'title2', "Standard Score Summary");
        $group[] = $this->form->createElement('static', "Sum_of_scaled_scores", null, null);
        $group[] = $this->form->createElement('static', "Standard_score", null, null);
        $group[] = $this->form->createElement('static', "Percentile_rank", null, null);
        $group[] = $this->form->createElement('static', "Confidence_interval", null, null);
        $group[] = $this->form->createElement('static', "Descriptive_classification", null, null);
        $this->form->addGroup($group, 'score_header_group2', "<strong>Scale Subtest</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains2 = array(1 => "Cognitive, Language, and Motor","COG" => "Cognitive (COG)",
            "LANG" => "Language (LANG)",
            "MOT" => "Motor (MOT)",            
        );
        $columnHeaders2 = array(
            "Sum_of_scaled_scores" => "Sum of scaled scores",
            "Standard_score" => "Standard score",
            "Percentile_rank" => "Percentile rank",
            "Confidence_interval" => "95% Confidence interval",
            "Descriptive_classification" => "Descriptive classification",           
        );

        foreach ($columnHeaders2 as $field => $label) {
            $columnHeaders2[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders2);
        foreach ($domains2 as $field => $label) {
            foreach ($columnHeaders2 as $scoreField => $scoreLabel) {
                if (is_int($field)) {
                    $group[] = $this->form->createElement('static', null, null, null);
                }
                else {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            if (is_int($field)) {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group2", "<strong>$label</strong>", $this->_GUIDelimiter, FALSE);
            }
            else {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group2", $label, $this->_GUIDelimiter, FALSE);
            }
            unset($group);
        }        

// table 3

        $this->form->addElement('header', null, "SUPPLEMENTAL ANALYSIS");

        $this->form->addElement('static', "title3_1", "Subtest Discrepancy Comparisons");
        $this->form->addElement('static', 'title3_2', "Cognitive, Language, and Motor");

        $group[] = $this->form->createElement('static', "Score_1", null, null);
        $group[] = $this->form->createElement('static', "Score_2", null, null);
        $group[] = $this->form->createElement('static', "Difference", null, null);
        $group[] = $this->form->createElement('static', "Critical_value", null, null);
        $group[] = $this->form->createElement('static', "Significant_difference", null, null);
        $group[] = $this->form->createElement('static', "Base_rate", null, null);
        $this->form->addGroup($group, 'score_header_group3', "<strong>Scale score</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains3 = array(
            "RC_EC" => "Receptive Communication - Expressive Communication",
            "FM_GM" => "Fine Motor - Gross Motor",          
        );
        $columnHeaders3 = array(
            "Score_1" => "Score 1",
            "Score_2" => "Score 2",
            "Difference" => "Difference",
            "Critical_value" => "Critical value",
            "Significant_difference" => "Significant difference*",
            "Base_rate" => "Base rate",           
        );

        foreach ($columnHeaders3 as $field => $label) {
            $columnHeaders3[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders3);
        foreach ($domains3 as $field => $label) {
            foreach ($columnHeaders3 as $scoreField => $scoreLabel) {
                if (is_int($field)) {
                    $group[] = $this->form->createElement('static', null, null, null);
                }
                else {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            if (is_int($field)) {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group3", "<strong>$label</strong>", $this->_GUIDelimiter, FALSE);
            }
            else {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group3", $label, $this->_GUIDelimiter, FALSE);
            }
            unset($group);
        }    

//table 4

        $this->form->addElement('static', "title4_1", "Standard Score Discrepancy Comparisons");
        $this->form->addElement('static', 'title4_2', "Cognitive, Language, and Motor");

        $group[] = $this->form->createElement('static', "Score_1", null, null);
        $group[] = $this->form->createElement('static', "Score_2", null, null);
        $group[] = $this->form->createElement('static', "Difference", null, null);
        $group[] = $this->form->createElement('static', "Critical_value", null, null);
        $group[] = $this->form->createElement('static', "Significant_difference", null, null);
        $group[] = $this->form->createElement('static', "Base_rate", null, null);
        $this->form->addGroup($group, 'score_header_group4', "<strong>Scale score</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains4 = array(
            "CL" => "Cognitive - Language",
            "CM" => "Cognitive - Motor",
            "LM" => "Language - Motor"          
        );
        $columnHeaders4 = array(
            "Score_Score_1" => "Score 1",
            "Score_Score_2" => "Score 2",
            "Score_Difference" => "Difference",
            "Score_Critical_value" => "Critical value",
            "Score_Significant_difference" => "Significant difference*",
            "Score_Base_rate" => "Base rate",           
        );

        foreach ($columnHeaders4 as $field => $label) {
            $columnHeaders4[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders4);
        foreach ($domains4 as $field => $label) {
            foreach ($columnHeaders4 as $scoreField => $scoreLabel) {
                if (is_int($field)) {
                    $group[] = $this->form->createElement('static', null, null, null);
                }
                else {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            if (is_int($field)) {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group4", "<strong>$label</strong>", $this->_GUIDelimiter, FALSE);
            }
            else {
            //    echo "$label.hello\n";
                $this->form->addGroup($group, "{$label}_group4", $label, $this->_GUIDelimiter, FALSE);
            }
            unset($group);
        }    

// table 4 end //        

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
        $file->setFileHandler("bayley4_file", $this);

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("UploadDir");
        if(empty($dir)) {
            $dir = ".";
        };
        $file->setBaseUploadDirectory($dir . "/Bayley4/");
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
        if ($values['bayley4_file']['name'] != false) {
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
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['bayley4_file']);
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

        $string = file_get_contents($file->fileInfo['tmp_name']);
        $textArr =  $this->getStringBetween($string,'Examinee Information','End of Report');

        $id = $this->getStringBetween($textArr,'ID:','Test Date:');

        // Since we are parsing Word documents, there can be
        // non-word characters before of after the patient ID: get rid
        // of those
        $id = preg_replace('/^\W+/', '', $id);
        $id = preg_replace('/\W+$/', '', $id);

        if (strpos($id, $args['candID']) !== false || strpos($id, $args['PSCID']) !== false ) {
            $errors[]="Incorrect candidate ID or PSCID found in file.";
            return $errors;
        }


        $correct_filename = ($this->testName.'_'.$args['candID'].'_'. $args['PSCID'].".doc");
        if($file->fileInfo['name'] != $correct_filename){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
        }

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



        $values=array(
            'UserID'    =>$args['username'],
            'Status'    =>'assembly',
            'File_type' =>'Bayley4',
            'File_name' =>$file->getDestinationFilename(),
            'Data_dir'  =>$file->getDestinationDirectory()
        );

            $string = file_get_contents($file->fileInfo['tmp_name']);
            $textArr =  $this->getStringBetween($string,'Examinee Information','End of Report');

            $id = $this->getStringBetween($textArr,'ID:','Test');
            $values['ID'] = $id;

            $name = $this->getStringBetween($textArr,'Name:','Examiner');
            $values['Name'] = $name;

            $gender = $this->getStringBetween($textArr,'Gender:','Caregiver');
            $values['Gender'] = $gender;

            $birth_day = $this->getStringBetween($textArr,'Birth Date:','Relationship');
            $values['Birth_Date'] = $birth_day;

            $date = $this->getStringBetween($textArr,'Test Date:','Name');
            $values['Test_Date'] = $date;

            $Examiner_Name = $this->getStringBetween($textArr,'Examiner Name:','Gender');
            $values['Examiner_Name'] = $Examiner_Name;

            $Relationship = $this->getStringBetween($textArr,'Relationship to Child:','Test Age');
            $values['Relationship'] = $Relationship;

            $test_age = $this->getStringBetween($textArr,'Test Age (Months:Days):','Adjusted Test Age');
            $values['Test_Age'] = $test_age;

            //table 1 cg data
            $cg = trim($this->getStringBetween($textArr,'Cognitive (CG)','Language'));
            $cgArr = array_filter(explode('', $cg));
            $values['Cognitive_CG_RAW_Score'] = $cgArr[1];
            $values['Cognitive_CG_Scaled_Score'] = $cgArr[2];
            $values['Cognitive_CG_Age_Equivalent'] = $cgArr[3];
            $values['Cognitive_CG_Growth_Scale_Value'] = $cgArr[4];

            //table 1 RC data
            $rc = trim($this->getStringBetween($textArr,'Receptive Communication (RC)','Expressive Communication (EC)'));
            $rcArr = array_filter(explode('', $rc));
            $values['Receptive_Communication_RC_RAW_Score'] = $rcArr[1];
            $values['Receptive_Communication_RC_Scaled_Score'] = $rcArr[2];
            $values['Receptive_Communication_RC_Age_Equivalent'] = $rcArr[3];
            $values['Receptive_Communication_RC_Growth_Scale_Value'] = $rcArr[4]; 

            //table 1 EC data
            $ec = trim($this->getStringBetween($textArr,'Expressive Communication (EC)','Motor'));
            $ecArr = array_filter(explode('', $ec));
            $values['Expressive_Communication_EC_RAW_Score'] = $ecArr[1];
            $values['Expressive_Communication_EC_Scaled_Score'] = $ecArr[2];
            $values['Expressive_Communication_EC_Age_Equivalent'] = $ecArr[3];
            $values['Expressive_Communication_EC_Growth_Scale_Value'] = $ecArr[4];     

            //table 1 FM data
            $fm = trim($this->getStringBetween($textArr,'Fine Motor (FM)','Gross Motor (GM)'));
            $fmArr = array_filter(explode('', $fm));
            $values['Fine_Motor_FM_RAW_Score'] = $fmArr[1];
            $values['Fine_Motor_FM_Scaled_Score'] = $fmArr[2];
            $values['Fine_Motor_FM_Age_Equivalent'] = $fmArr[3];
            $values['Fine_Motor_FM_Growth_Scale_Value'] = $fmArr[4];  

            //table 1 GM data
            $gm = trim($this->getStringBetween($textArr,'Gross Motor (GM)','Standard Score Summary'));
            $gmArr = array_filter(explode('', $gm));
            $values['Gross_Motor_GM_RAW_Score'] = $gmArr[1];
            $values['Gross_Motor_GM_Scaled_Score'] = $gmArr[2];
            $values['Gross_Motor_GM_Age_Equivalent'] = $gmArr[3];
            $values['Gross_Motor_GM_Growth_Scale_Value'] = $gmArr[4]; 

            //table 2 cog data
            $cog = trim($this->getStringBetween($textArr,'Cognitive (COG)','Language (LANG)'));
            $cogArr = array_filter(explode('', $cog));

            $values['COG_Sum_of_scaled_scores'] = $cogArr[1];
            $values['COG_Standard_score'] = $cogArr[2];
            $values['COG_Percentile_rank'] = $cogArr[3];
            $values['COG_Confidence_interval'] = $cogArr[4]; 
            $values['COG_Descriptive_classification'] = $cogArr[5]; 


             //table 2 lang data
            $lang = trim($this->getStringBetween($textArr,'(LANG)','Motor'));
            $langArr = array_filter(explode('', $lang));

            $values['LANG_Sum_of_scaled_scores'] = $langArr[1];
            $values['LANG_Standard_score'] = $langArr[2];
            $values['LANG_Percentile_rank'] = $langArr[3];
            $values['LANG_Confidence_interval'] = $langArr[4]; 
            $values['LANG_Descriptive_classification'] = $langArr[5]; 



             //table 2 mot data
            $mot = trim($this->getStringBetween($textArr,'Motor (MOT)','SUPPLEMENTAL ANALYSIS'));
            $motArr = array_filter(explode('', $mot));

            $values['MOT_Sum_of_scaled_scores'] = $motArr[1];
            $values['MOT_Standard_score'] = $motArr[2];
            $values['MOT_Percentile_rank'] = $motArr[3];
            $values['MOT_Confidence_interval'] = $motArr[4]; 
            $values['MOT_Descriptive_classification'] = $motArr[5]; 


             //table 3 sdc data
            $sdc = trim($this->getStringBetween($textArr,'Receptive Communication -','Fine Motor - Gross Motor'));
            $sdcArr = array_filter(explode('', $sdc));

            $values['RC_EC_Score_1'] = $sdcArr[1];
            $values['RC_EC_Score_2'] = $sdcArr[2];
            $values['RC_EC_Difference'] = $sdcArr[3];
            $values['RC_EC_Critical_value'] = $sdcArr[4]; 
            $values['RC_EC_Significant_difference'] = $sdcArr[5];
            $sdcArr[6] = str_replace(">", "greater than ", $sdcArr[6]);
            $sdcArr[6] = str_replace("<", "less than ",  $sdcArr[6]); 
            $values['RC_EC_Base_rate'] = $sdcArr[6]; 

             //table 3 sdc fm data

            $ssdc = trim($this->getStringBetween($textArr,'Fine Motor - Gross Motor','Significance level'));
            $ssdcArr = array_filter(explode('', $ssdc));

            $values['FM_GM_Score_1'] = $ssdcArr[1];
            $values['FM_GM_Score_2'] = $ssdcArr[2];
            $values['FM_GM_Difference'] = $ssdcArr[3];
            $values['FM_GM_Critical_value'] = $ssdcArr[4]; 
            $values['FM_GM_Significant_difference'] = $ssdcArr[5]; 
            $ssdcArr[6] = str_replace(">", "greater than ", $ssdcArr[6]);
            $ssdcArr[6] = str_replace("<", "less than ",  $ssdcArr[6]);
            $values['FM_GM_Base_rate'] = $ssdcArr[6]; 


             //table 4 ssdc data

            $ssdc = trim($this->getStringBetween($textArr,'Cognitive - Language','Cognitive - Motor'));
            $ssdcArr = array_filter(explode('', $ssdc));

            $values['CL_Score_Score_1'] = $ssdcArr[1];
            $values['CL_Score_Score_2'] = $ssdcArr[2];
            $values['CL_Score_Difference'] = $ssdcArr[3];
            $values['CL_Score_Critical_value'] = $ssdcArr[4]; 
            $values['CL_Score_Significant_difference'] =    $ssdcArr[5];
            $ssdcArr[6] = str_replace(">", "greater than ", $ssdcArr[6]);
            $ssdcArr[6] = str_replace("<", "less than ", $ssdcArr[6]); 
            $values['CL_Score_Base_rate'] = $ssdcArr[6]; 

             //table 4 ssdc data row 2

            $ssdc = trim($this->getStringBetween($textArr,'Cognitive - Motor','Language - Motor'));
            $ssdcArr = array_filter(explode('', $ssdc));

            $values['CM_Score_Score_1'] = $ssdcArr[1];
            $values['CM_Score_Score_2'] = $ssdcArr[2];
            $values['CM_Score_Difference'] = $ssdcArr[3];
            $values['CM_Score_Critical_value'] = $ssdcArr[4]; 
            $values['CM_Score_Significant_difference'] =    $ssdcArr[5];
            $ssdcArr[6] = str_replace(">", "greater than ", $ssdcArr[6]);
            $ssdcArr[6] = str_replace("<", "less than ", $ssdcArr[6]); 
            $values['CM_Score_Base_rate'] = $ssdcArr[6]; 

             //table 4 ssdc data row 3

            $ssdc = trim($this->getStringBetween($textArr,'Language - Motor','Significance level'));
            $ssdcArr = array_filter(explode('', $ssdc));

            $values['LM_Score_Score_1'] = $ssdcArr[1];
            $values['LM_Score_Score_2'] = $ssdcArr[2];
            $values['LM_Score_Difference'] = $ssdcArr[3];
            $values['LM_Score_Critical_value'] = $ssdcArr[4]; 
            $values['LM_Score_Significant_difference'] = $ssdcArr[5]; 
            $values['LM_Score_Base_rate'] = $ssdcArr[6]; 

        $db=& Database::singleton();

///Setting trackchanges to false because getting error messages
        $db->_trackChanges = false;
////////////////////////////////////////////////////////////////

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
        $output=$args['candID']."/";
        return $output;
    }

    function getStringBetween($str,$from,$to)
    {
    $sub = substr($str, strpos($str,$from)+strlen($from),strlen($str));
    return substr($sub,0,strpos($sub,$to));
    }


}

