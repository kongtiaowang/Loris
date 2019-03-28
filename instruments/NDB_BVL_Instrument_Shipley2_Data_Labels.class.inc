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


class NDB_BVL_Instrument_Shipley2_Data_Labels extends NDB_BVL_Instrument
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
        $this->testName = "Shipley2_Data_Labels";           // test_names.Test_name
        $this->table = 'Shipley2_Data_Labels';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;
        $db =& Database::singleton();
    /*    try {
            $record = $db->pselectRow("SELECT * FROM " . $this->table . " WHERE CommentID=:cid",
                array('cid' => $this->getCommentID()));
        } catch (DatabaseException $ex) {
            print "Query has failed to select";
            $record = array();
        }

        try {
            $record2 = $db->pselectRow("SELECT * FROM Shipley2_Data_Labels2  WHERE CommentID=:cid",
                array('cid' => $this->getCommentID()));
        } catch (DatabaseException $ex) {
            print "Query has failed to select";
            $record2 = array();
        }
*/


        $fields = array("Participant", "Survey_Identifier","Relationship", "Specify_other_relationship","Complete1","Survey_Timestamp","TALK","COUCH","REMEMBER",
            'PARDON','HIDEOUS','MASSIVE','PROBABLE','IMPOSTOR','FASCINATE','EVIDENT','NARRATE','HAUL','HILARITY',
            'IGNORANT','CAPTION','INDICATE','SOLEMN','FORTIFY','MERIT','RENOWN',
            'FACILITATE','AMULET','STERILE','CORDIAL','SQUANDER','SERRATED','PLAGIARIZE','ORIFICE',
            'PRISTINE','INNOCUOUS','JOCOSE','RUE','INEXORABLE','DIVEST','MOLLIFY',
            'QUERULOUS','ABET','DESUETUDE','PEREGRINATE','QUOTIDIAN',"1_2_3_4_5_?","whiteblack_shortlong _down?","AB_BC_CD_D?","10_1_9_2_8_?","A_Z_B_Y_C_X_D_?",
            "oh_ho_rat_tar_mood_?","escape_scape_cape_?","mist_is__wasp_as__pint_in__tone?","NE_SE__SE_NW__E_W__N_?","12321_23432_34543_456_?",
            "knit_in__spud_up__both_to__stay_?","57326_73265_32657_26573_?"	,
            "Scotland_landscape_scapegoat_?ee","3_7_5_11_2_?",
            "tam_tan__rib_rid__rat_raw__hip_?",	"G_V_J_T_M_R_?",
            "surgeon_1234567__snore_17635__rogue_?",
            "4_11__7__20_3_?",	"two_w__four_r__one_o__three_?"	,"thicken_10__founder_4__nectarine_?",
            "3124_82__73_154__46_13_?",	"KW_MS_PP_TN_?",
            "pole_post_mail__carton_box_fight__film_picture_depict__money_?_alter",	"9_6__12_7__3_?",	"trauma_tuna__flight_fit__wife_a?__glossy_gravity"
        );
        if (!empty($record)) {

            //$this->localDefaults['Uploaded_file'] = $record['Uploaded_file'];
            for ($i = 1; $i <= 1; $i++) {
                foreach ($fields as $field) {
                    $key = $field . "_" . $i;
                    $this->localDefaults[$key] = $record[$key];
                }
            }
        }
        if (!empty($record2)) {
            for ($i = 2; $i <= 2; $i++) {
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
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR><i>The Sgipley2 Data Labels instrument parses the data and updates the data 
 all around. (Similar to DTIPrep Instrument already in use)<br>
 <b>ie; if you have multiple candidate data in your file</b>; it will check across all the candidates and updates 
 the data for all the valid candidates found in the file.
  <br>This will save your time of going to each candidate and uploading the file.</i><br>
");
        $this->form->addElement('static', null, '<br>');
        $this->form->addFile('Shipley2_Data_Labels', 'Upload the Assessment Data File
<br><h6><i>(Filename should be Shipley2_DATA_LABELS.csv)</i></h6>', array());
        $this->form->addElement('static', 'Uploaded_Shipley2_Data_Labels', "Uploaded Shipley2 Data Labels");


    }

    function _page1()
    {

        $fields = array("No","Participant", "Survey_Identifier","Relationship", "Specify_other_relationship","Complete1","Survey_Timestamp","TALK","COUCH","REMEMBER",
         'PARDON','HIDEOUS','MASSIVE','PROBABLE','IMPOSTOR','FASCINATE','EVIDENT','NARRATE','HAUL','HILARITY',
            'IGNORANT','CAPTION','INDICATE','SOLEMN','FORTIFY','MERIT','RENOWN',
            'FACILITATE','AMULET','STERILE','CORDIAL','SQUANDER','SERRATED','PLAGIARIZE','ORIFICE',
            'PRISTINE','INNOCUOUS','JOCOSE','RUE','INEXORABLE','DIVEST','MOLLIFY',
            'QUERULOUS','ABET','DESUETUDE','PEREGRINATE','QUOTIDIAN',"1_2_3_4_5_?","whiteblack_shortlong _down?","AB_BC_CD_D?","10_1_9_2_8_?","A_Z_B_Y_C_X_D_?",
            "oh_ho_rat_tar_mood_?","escape_scape_cape_?","mist_is__wasp_as__pint_in__tone?","NE_SE__SE_NW__E_W__N_?","12321_23432_34543_456_?",
        "knit_in__spud_up__both_to__stay_?","57326_73265_32657_26573_?"	,
        "Scotland_landscape_scapegoat_?ee","3_7_5_11_2_?",
        	"tam_tan__rib_rid__rat_raw__hip_?",	"G_V_J_T_M_R_?",
        "surgeon_1234567__snore_17635__rogue_?",
        "4_11__7__20_3_?",	"two_w__four_r__one_o__three_?"	,"thicken_10__founder_4__nectarine_?",
        "3124_82__73_154__46_13_?",	"KW_MS_PP_TN_?",
        "pole_post_mail__carton_box_fight__film_picture_depict__money_?_alter",	"9_6__12_7__3_?",	"trauma_tuna__flight_fit__wife_a?__glossy_gravity"
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
        //echo error messages
        if(!empty($file->errorLog)){
            while(list($fileType,$fileErrors)=each($file->errorLog)){
                foreach($fileErrors AS $error){
                    echo "Upload Error: $fileType: $error";
                }
            }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'],
            $values['Shipley2_Data_Labels']);
        $this->_save($values);

    }
    /**
     * isValid checks the validity of the file.
     *
     * @param     string  $file    The full filename including directory.
     *
     * @return    bool    $successif operation succeeded
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
     * @return    bool    $successif operation succeeded
     * @access    public
     */
    function importFile(&$file, $args)
    {

        $main_values = array(
             'Data_dir_assessment' => $file->getDestinationDirectory(),
             'UserID' => $args['username'],
             'File_type' => 'Shipley2',
        );

        if(strpos($file->fileInfo['name'], 'Data') !== false) {
            $upload_values2=array();

            /** @var Database $db */
            $db =& Database::singleton();
            ///Setting trackchanges to false because getting error messages
            $db->_trackChanges = false;
            ////////////////////////////////////////////////////////////////
           //uploading values to Shipley 2 Data Labels

            $main_values['Uploaded_Shipley2_Data_Labels'] = $file->getDestinationFilename();

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
                $fields = array( "No","Participant", "Survey_Identifier","Relationship", "Specify_other_relationship","Complete1","Survey_Timestamp","TALK","COUCH","REMEMBER",
                    'PARDON','HIDEOUS','MASSIVE','PROBABLE','IMPOSTOR','FASCINATE','EVIDENT','NARRATE','HAUL','HILARITY',
                    'IGNORANT','CAPTION','INDICATE','SOLEMN','FORTIFY','MERIT','RENOWN',
                    'FACILITATE','AMULET','STERILE','CORDIAL','SQUANDER','SERRATED','PLAGIARIZE','ORIFICE',
                    'PRISTINE','INNOCUOUS','JOCOSE','RUE','INEXORABLE','DIVEST','MOLLIFY',
                    'QUERULOUS','ABET','DESUETUDE','PEREGRINATE','QUOTIDIAN',"1_2_3_4_5_?","whiteblack_shortlong _down?","AB_BC_CD_D?","10_1_9_2_8_?","A_Z_B_Y_C_X_D_?",
                    "oh_ho_rat_tar_mood_?","escape_scape_cape_?","mist_is__wasp_as__pint_in__tone?","NE_SE__SE_NW__E_W__N_?","12321_23432_34543_456_?",
                    "knit_in__spud_up__both_to__stay_?","57326_73265_32657_26573_?"	,
                    "Scotland_landscape_scapegoat_?ee","3_7_5_11_2_?",
                    "tam_tan__rib_rid__rat_raw__hip_?",	"G_V_J_T_M_R_?",
                    "surgeon_1234567__snore_17635__rogue_?",
                    "4_11__7__20_3_?",	"two_w__four_r__one_o__three_?"	,"thicken_10__founder_4__nectarine_?",
                    "3124_82__73_154__46_13_?",	"KW_MS_PP_TN_?",
                    "pole_post_mail__carton_box_fight__film_picture_depict__money_?_alter",	"9_6__12_7__3_?",	"trauma_tuna__flight_fit__wife_a?__glossy_gravity"
                );
                $count=count($entries);
                if($count>2)
                {
                    $count=2;
                }
                foreach ($entries as $i => $entry) {
                    $i++;

                    $f = 0;
                    foreach ($fields as &$value) {
                        if ($i > 1 && $i<=$count) {
                            $upload_values2["{$value}_{$i}"] = $entry[$f];
                        } else {
                            $upload_values["{$value}_{$i}"] = $entry[$f];
                        }
                        $f++;
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
                    $valid++;
                    $ids_updated .= $pscid.",";

                    if (!empty($upload_values2)) {
                        $check = $db->pselectOne("SELECT 1 FROM Shipley2_Data_Labels2 WHERE CommentID=:cid", array('cid' => $commentid));
                        if ($check != 1) {
                            $upload_values2['CommentID'] = $commentid;
                            $ok = $db->insert("Shipley2_Data_Labels2", $upload_values2);
                        } else {
                            $ok = $db->update("Shipley2_Data_Labels2", $upload_values2, array('CommentID' => $commentid));
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
     * @return    bool    $successif operation succeeded
     * @access    public
     */
    function getTargetDirectory(&$file, $args){
        $output=$args['candID']."/";
        return $output;
    }
}
