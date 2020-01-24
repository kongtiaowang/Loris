<?php
/*
 * This file contains the NDB_BVL_Instrument_Shipley2_Data_Labels
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
 * Creates the form elements for the Shipley2_Data_Labels instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_Shipley2_Data_Labels extends NDB_BVL_Instrument
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
        $this->testName = "Shipley2_Data_Labels";           // test_names.Test_name
        $this->table = 'Shipley2_Data_Labels';             // name of table containing

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
            "/Shipley2_Data_Labels(_page[0-9]+)/",
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
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR><i>Shipley2 Data Labels (Raw Data) instrument parses the data and updates the data 
 all around. (Similar to DTIPrep Instrument already in use)<br>
 <b>ie; if you have multiple candidate data in your file</b>; it will check across all the candidates and updates 
 the data for all the valid candidates found in the file.
  <br>This will save your time of going to each candidate and uploading the file.</i><br>
");
        $this->form->addElement('static', null, '<br>');
        $this->form->addFile('Shipley2_Data_Labels', 'Upload the Shipley2 Data Labels File
<br><h6><i>(Filename should be Shipley2_Data_Labels.csv)</i></h6>', array());
        $this->form->addElement('static', 'Uploaded_Shipley2_Data_Labels', "Uploaded  Shipley2 Data Labels File");
        $this->form->addElement('hidden', 'hidden_val', "Hidden Val");
        $this->XINRegisterRule("hidden_val", array("{hidden_val}{@}=={@}NEVER_REQUIRED"));

        $this->XINRegisterRule("Shipley2_Data_Labels",array("hidden_val{@}=={@}NEVER_REQUIRED"));



    }

    function _page1()
    {

        $fields = array("No","Participant", "Survey_Identifier","Relationship", "Specify_other_relationship","Complete1","Survey_Timestamp","TALK","COUCH","REMEMBER",
            'PARDON','HIDEOUS','MASSIVE','PROBABLE','IMPOSTOR','FASCINATE','EVIDENT','NARRATE','HAUL','HILARITY',
            'IGNORANT','CAPTION','INDICATE','SOLEMN','FORTIFY','MERIT','RENOWN',
            'FACILITATE','AMULET','STERILE','CORDIAL','SQUANDER','SERRATED','PLAGIARIZE','ORIFICE',
            'PRISTINE','INNOCUOUS','JOCOSE','RUE','INEXORABLE','DIVEST','MOLLIFY',
            'QUERULOUS','ABET','DESUETUDE','PEREGRINATE','QUOTIDIAN',"1_2_3_4_5_FILL","whiteblack_shortlong_downFILL","AB_BC_CD_DFILL","10_1_9_2_8_FILL","A_Z_B_Y_C_X_D_FILL",
            "oh_ho_rat_tar_mood_FILL","escape_scape_cape_FILL","mist_is_wasp_as_pint_in_toneFILL","NE_SE_SE_NW_E_W_N_FILL","12321_23432_34543_456_FILL",
            "knit_in_spud_up_both_to_stay_FILL","57326_73265_32657_26573_FILL"	,
            "Scotland_landscape_scapegoat_FILL_ee","3_7_5_11_2_FILL",
            "tam_tan_rib_rid_rat_raw_hip_FILL",	"G_V_J_T_M_R_FILL",
            "surgeon_1234567_snore_17635_rogue_FILL",
            "4_11_7_20_3_FILL",	"two_w_four_r_one_o_three_FILL"	,"thicken_10_founder_4_nectarine_FILL",
            "3124_82_73_154_46_13_FILL",	"KW_MS_PP_TN_FILL",
            "pole_post_FILL","9_6_12_7_3_FILL","trauma_tuna_flight_fit_wife_a_FILL_glossy_gravity");

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
        if(isset($values['Shipley2_Data_Labels']) && !empty($values['Shipley2_Data_Labels']['name'])) {
            require_once "File_Upload.class.inc";
            $file=new File_Upload;

            //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
            $file->registerForm($this->form);


            //Tell File_Upload what file handlers to use.
            $file->setFileHandler("Shipley2_Data_Labels", $this);

            //Set the target directory that you want files moved into once they are validated and processed.
            $config = NDB_Config::singleton();
            $dir = $config->getSetting("UploadDir");
            if(empty($dir)) {
                $dir = ".";
            };
            $file->setBaseUploadDirectory($dir . "/Shipley2_Data_Labels/");

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
        if(!empty($file->errorLog)){
            while(list($fileType,$fileErrors)=each($file->errorLog)){
                foreach($fileErrors AS $error){
                    echo "Upload Error: $fileType: $error";
                }
            }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'],
            $values['Shipley2_Data_Labels'], $values['valid'],$values['ids_updated'], $values['hidden_val']);
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

        $correct_filename = $this->testName.".csv";
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
        $main_values = array(
            'Data_dir_assessment' => $file->getDestinationDirectory(),
            'UserID' => $args['username'],
            'File_type' => 'Shipley2',
        );
       // print_r($main_values);
       // exit;
        if(strpos($file->fileInfo['name'], 'Data_Labels') !== false) {
            /** @var Database $db */
            $db =& Database::singleton();
            ///Setting trackchanges to false because getting error messages
            $db->_trackChanges = false;
            ////////////////////////////////////////////////////////////////
            //uploading values to NIHToolBox_Assessment_Scores

            $main_values['Uploaded_Shipley2_Data_Labels'] = $file->getDestinationFilename();
            $fields = array("Participant", "Survey_Identifier","Relationship", "Specify_other_relationship","Complete1","Survey_Timestamp","TALK","COUCH","REMEMBER",
                'PARDON','HIDEOUS','MASSIVE','PROBABLE','IMPOSTOR','FASCINATE','EVIDENT','NARRATE','HAUL','HILARITY',
                'IGNORANT','CAPTION','INDICATE','SOLEMN','FORTIFY','MERIT','RENOWN',
                'FACILITATE','AMULET','STERILE','CORDIAL','SQUANDER','SERRATED','PLAGIARIZE','ORIFICE',
                'PRISTINE','INNOCUOUS','JOCOSE','RUE','INEXORABLE','DIVEST','MOLLIFY',
                'QUERULOUS','ABET','DESUETUDE','PEREGRINATE','QUOTIDIAN',"1_2_3_4_5_FILL","whiteblack_shortlong_downFILL","AB_BC_CD_DFILL","10_1_9_2_8_FILL","A_Z_B_Y_C_X_D_FILL",
                "oh_ho_rat_tar_mood_FILL","escape_scape_cape_FILL","mist_is_wasp_as_pint_in_toneFILL","NE_SE_SE_NW_E_W_N_FILL","12321_23432_34543_456_FILL",
                "knit_in_spud_up_both_to_stay_FILL","57326_73265_32657_26573_FILL"	,
                "Scotland_landscape_scapegoat_FILL_ee","3_7_5_11_2_FILL",
                "tam_tan_rib_rid_rat_raw_hip_FILL",	"G_V_J_T_M_R_FILL",
                "surgeon_1234567_snore_17635_rogue_FILL",
                "4_11_7_20_3_FILL",	"two_w_four_r_one_o_three_FILL"	,"thicken_10_founder_4_nectarine_FILL",
                "3124_82_73_154_46_13_FILL","KW_MS_PP_TN_FILL",
                "pole_post_FILL","9_6_12_7_3_FILL","trauma_tuna_flight_fit_wife_a_FILL_glossy_gravity");

            $result = array();
            $file = fopen($file->fileInfo['tmp_name'], "r");
            $ex_header=fgetcsv($file, 0, ",");
            $avail_headers=array_intersect($ex_header,$fields);
            $avail_header_keys=array_keys($avail_headers);
            while (!feof($file)) {
                $data = fgetcsv($file, 0, ",");
                $outputData = array($data[2]);
                for($f=0;$f<=72;$f++)
                {
                    if(in_array($f,$avail_header_keys)){
                        array_push($outputData, $data[$f]);
                    }
                }
                fputcsv($file, $outputData);
                $key = array_shift($outputData);
                if (!isset($result[$key])) {
                    $result[$key] = array();
                }
                $result[$key][] = $outputData;
            }
          //  print_r($result);
//Now, to print it out, this is all I have to do
            $valid=0;
            $ids_updated='';
            foreach ($result as $pscid => $entries) {
                $upload_values=array();
                //echo $pscid . "\n";
                //loop through all unique pscid found and update the date all around

                //2 sessions per candidate allowed as per the current files given
                $count=count($entries);
                if($count>2)
                {
                    $count=2;
                }
                foreach ($entries as $i => $entry) {
                    $m=$i+1;
                    $f = 0;
                    foreach ($avail_headers as &$value) {
                        if($m<=$count) {

                            $upload_values["{$value}_{$m}"] = $entry[$f];
                        }


                        $f++;
                    }
                }

                $timepoint =& TimePoint::singleton($this->getSessionID());
               // $vl=$timepoint->getVisitLabel(),
                $final_upload_values=array_merge($main_values,$upload_values);
                $commentid = $db->pselectOne(
                    "select f.CommentID from flag as f
                  join `session` as s on f.SessionID=s.ID
                  join `candidate` as c on s.CandID=c.CandID
                  WHERE s.Visit_label=:vl and c.PSCID=:pscid
                  and f.Test_name=:tesna and f.CommentID not like 'DDE_%'",
                    array(
                        'vl'   => $timepoint->getVisitLabel(),
                        'pscid' => $pscid,
                        'tesna' => $this->testName,
                    )
                );
                if(!empty($commentid)) {
                    $valid++;
                    //print_r($upload_values);
                    $result = $db->update($this->testName, $final_upload_values, array('CommentID' => $commentid));
                    $ids_updated .= $pscid.",";
                }
            }
            if($valid==0)
            {
                echo "No matching PSCID found in the csv file to update the data under given visit label. \n
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
}
