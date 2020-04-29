<?php
class NDB_BVL_Instrument_EEG extends NDB_BVL_Instrument
{
  use instrument_validator;

  static $cssStyle = "style='color:white; background-color: black;border: 10px solid black;margin-left:0;'";
  static $cssStyle2 = "style='background-color: gray;border: 10px solid gray;height:100%;width:100%;float:left;'";

  // All the form fields that contain the name of a file uploaded on the server
  // Each field $x has an associated field $x_chooser (a file chooser user to choose
  //   a file on the local system).
  static $FILE_FIELDS = array(
      'file_top'              => [ 'required' => 0, 'page' => ''         , 'name' => 'File Name'],
      'second_file_top'       => [ 'required' => 0, 'page' => ''         , 'name' => 'Secondary File']
  );

  private const YES_NO = array(
      null => '',
      'y'  => 'Yes',
      'n'  => 'No'
  );

  private const PARADIGM_COMPLETENESS = [
      null => '',
      'y' => 'Yes',
      'n' => 'No',
      'p' => 'Partial'
  ];

  var $ValidityRequired = true;

  var $_requiredElements = array('file_top');


  /**
   * sets up basic data, such as the LorisForm object, and so on.
   *
   * @param string $commentID  the CommentID identifying the data to load
   * @param string $page       if a multipage form, the page to show
   * @return void
   * @access public
   */
   function setup($commentID = NULL, $page = NULL) {
       parent::setup($commentID, $page);

       $this->formType="XIN";
       $this->form = new LorisForm('test_form');

       // set the object properties
       $this->testName = "EEG";          // test_names.Test_name
       $this->table = 'EEG';             // name of database table corresponding to instrument
       //The array of dates/timestamps to convert to database dates/timestamps
       //Any LorisForm date elements must be listed here
       $this->dateTimeFields=array("Date_taken");
       $config             = NDB_Config::singleton();
       $this->dateOptions  = array(
           'language'         => 'en',
           'format'           => 'YMd',
           'minYear'          => $config->getSetting('startYear'),
           'maxYear'          => $config->getSetting('endYear'),
           'addEmptyOption'   => true,
           'emptyOptionValue' => null,
       );

       // setup the form
       $this->_setupForm();
   }

   /**
    * method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm(){
        if(preg_match("/EEG(_page[0-9]+)/",$this->page,$matches)){
           call_user_func(array($this, $matches[1]));
        } else {
           $this->_main();
        }

        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'eeg_rules'));
    }

    /**
     * Sets the default values for the form fields.
     *
     * @param array $defaults The current default values.
     * @return array the updated default values.
     */
    function _setDefaultsArray($defaults) {
        $defaults = parent::_setDefaultsArray($defaults);

        $defaults['subjectID']    = $this->getPSCID();
        $defaults['ageAtSession'] = 'Unknown';

        $dateOfAdministration = $this->getDateOfAdministration();
        if ($dateOfAdministration) {
            $age = $this->getCandidateAge($dateOfAdministration);
            if(is_array($age)) {
                if($age['year']) {
                    $defaults['ageAtSession'] = sprintf(
                        "%d year(s), %d month(s), %d day(s)", $age['year'], $age['mon'], $age['day']
                    );
                } elseif($age['mon']) {
                    $defaults['ageAtSession'] = sprintf("%d month(s), %d day(s)", $age['mon'], $age['day']);
                } else {
                    $defaults['ageAtSession'] = "{$age['day']} day(s)";
                }
            }
        }

        $gender = 'Unknown';
        $session = $this->getSessionID();
        if (!empty($session)) {
            $timepoint = \TimePoint::singleton($session);
            $candidate = \Candidate::singleton($timepoint->getCandID());
            $gender    = $candidate->getCandidateGender() ?? 'Unknown';
        }
        $defaults['gender'] = $gender;

        foreach (array_keys(self::$FILE_FIELDS) as $f) {
            $defaults[$f] = $defaults[$f] ?? '<None>';
        }

        return $defaults;
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main(){
        // display test name
        $this->form->addElement('header', null, "<div ".self::$cssStyle.">IBIS-EP EEG Project: EEG Session Log</div>");
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." style='text-align:center'>Subject and Session Information</div>");

        $this->addScoreColumn('subjectID'      , "Subject ID:");
        $this->addScoreColumn('gender'         , "Subject's gender:");
        $this->addBasicDate('Date_taken'       , "Session Date:", $this->dateOptions);
        $this->addScoreColumn('ageAtSession', "Age at session:");

        $this->addTextElement("start_time", "Start time (24h format, HH:MM, e.g. 13:00):");

        $this->addTextElement("experimenter_initials", "Experimenter Initials:");
        $this->addTextElement("behavioral_assistant_initials", "Behavioral Assistant Initials:");
        $this->addSelect('caregiver_present', 'Caregiver Present?', self::YES_NO);

        $this->addScoreColumn('file_top', "File Name:");
        $this->form->addElement('file', "file_top_chooser", '');
        $this->XINRegisterRule("file_top_chooser", array("second_file_top_chooser{@}==={@}NEVER_REQUIRED"));

        $this->addScoreColumn('second_file_top', 'Secondary File (optional):');
        $this->form->addElement('file', "second_file_top_chooser", '');
        $this->XINRegisterRule("second_file_top_chooser", array("second_file_top_chooser{@}==={@}NEVER_REQUIRED"));

        $this->addTextElement("ofc", "Head Measurement (OFC): (CM)");
        $this->addTextElement("net_serial_number", "Net Serial Number:");
        $this->addTextAreaElement("additional_notes", "Additional Pre-Session Notes:");

        // EEG Net Information
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." style='text-align:center'>EEG Net Information</div>");
        $this->addSelect("impedance_before_netting", "Impedances measured before netting?", self::YES_NO);
        $this->addTextAreaElement("bad_channels_before_netting", "Bad channels before netting:");
        $this->addSelect('impedance_after_netting', 'Impedances measured after netting?', self::YES_NO);
        $this->addTextAreaElement("bad_channels_after_netting", "Bad channels after netting:");
        $this->addSelect('net_quality_rating', 'Net Quality Rating:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","not_answered"=>"Not Answered"));
    }

    /**
     * Generates the 'Resting Bubbles' section.
     */
    function _page1(){
        // PARADIGM 1: Resting (Bubbles)
        $this->form->addElement("header", null, "<div ".self::$cssStyle2." >PARADIGM 1: Resting (Bubbles)</div>");

        $this->addTextAreaElement('note_1_1', 'Artifact/Net Movement Notes:');
        $this->addTextAreaElement('note_1_2', 'General Notes (soothing devices used, child behavior, breaks taken, etc.):');
        $this->addSelect('mood_1', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->addSelect('paradigm_completed_1', 'Paradigm Completed?', self::PARADIGM_COMPLETENESS);
    }

    /**
     * Generates the 'VEP' section.
     */
    function _page2(){
        // PARADIGM 2: Visual (Checkerboard)
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >PARADIGM 2: Visual (Checkerboard)</div>");

        $this->addTextAreaElement("note_2_1", "Artifact/Net Movement Notes:");
        $this->addTextAreaElement("note_2_2", "General Notes (soothing devices used, child behavior, breaks taken, etc.):");
        $this->addSelect('mood_2', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->addSelect('paradigm_completed_2', 'Paradigm Completed?', self::PARADIGM_COMPLETENESS);
    }

    /**
     * Generates the 'AEP' section.
     */
    function _page3(){
        // PARADIGM 3: Resting (Bubbles)
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >PARADIGM 3: Resting (Bubbles)</div>");

        $this->addTextAreaElement("note_3_1", "Artifact/Net Movement Notes:");
        $this->addTextAreaElement("note_3_2", "General Notes (soothing devices used, child behavior, breaks taken, etc.):");
        $this->addSelect('mood_3', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->addSelect('paradigm_completed_3', 'Paradigm Completed?', self::PARADIGM_COMPLETENESS);
    }

    /**
     * Generates the 'Social/Non-social' section.
     */
    function _page4(){
        // PARADIGM 4: Auditory (Bubbles with Tone)
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >PARADIGM 4: Auditory (Bubbles with Tone)</div>");

        $this->addTextAreaElement("note_4_1", "Artifact/Net Movement Notes:");
        $this->addTextAreaElement("note_4_2", "General Notes (soothing devices used, child behavior, breaks taken, etc.):");
        $this->addSelect('mood_4', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->addSelect('paradigm_completed_4', 'Paradigm Completed?', self::PARADIGM_COMPLETENESS);
    }

    /**
     * Generates the 'Resting Bubbles' section.
     */
    function _page5(){
        // PARADIGM 5:Resting (Bubbles)
        $this->form->addElement("header", null, "<div ".self::$cssStyle2." >PARADIGM 5: Resting (Bubbles)</div>");

        $this->addTextAreaElement("note_5_1", "Artifact/Net Movement Notes:");
        $this->addTextAreaElement("note_5_2", "General Notes (soothing devices used, child behavior, breaks taken, etc.):");
        $this->addSelect('mood_5', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        //$this->addTextElement("trials_completed_5", "Trials Completed:");
        $this->addSelect('paradigm_completed_5', 'Paradigm Completed?', self::PARADIGM_COMPLETENESS);
    }

    /**
     * Generates the 'General EEG session' section.
     */
    function _page6(){
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >General Session Notes</div>");
        $this->addTextAreaElement("note_6_1", "General Notes:");
        $this->addTextElement("end_time", "End time (24h format, HH:MM, e.g. 13:00):");

        $this->addSelect('standard_paradigm_order', 'Standard Paradigm Order Used?', self::YES_NO);

        $this->addTextAreaElement("note_6_2", "Order Deviations Notes:");
    }

    /**
     * Saves the form values and upload the specified files (if any).
     *
     * @param array $values Values entered in the form.
     */
    function _saveValues($values) {

        //----------------------------------------------------------//
        // *_chooser fields are always posted but do not exist in   //
        // the DB. Save their values in $files and unset these      //
        // otherwise parent::_saveValues will crash                 //
        //----------------------------------------------------------//
        foreach (self::$FILE_FIELDS as $k => $v) {
            if ($v['page'] == $this->page) {
                $files["{$k}_chooser"] = $values["{$k}_chooser"];
                unset($values["${k}_chooser"]);
            }
        }

        parent::_saveValues($values);

        //--------------------------//
        // Process all file fields  //
        //--------------------------//
        foreach (self::$FILE_FIELDS as $k => $v) {
            //---------------------------------------------//
            // If the associated file chooser was used and //
            // the chooser is on the current page          //
            //---------------------------------------------//
            if ($v['page'] != $this->page || $files["{$k}_chooser"]["name"] == '') {
                continue;
            }

            //-------------------------------------------------------------------//
            // Check that there is no file in the media module with              //
            // the same name as the file. If there is a file with the sam        //
            // but the file was uploaded through the EEG form for field $k, then //
            // that's OK (counts as an update)                                   //
            //-------------------------------------------------------------------//
            $db        =& Database::singleton();
            $row = $db->pselectRow(
                "SELECT e.Date_Taken, m.ID FROM {$this->table} e LEFT JOIN media m ON (e.{$k}=m.file_name) WHERE e.CommentID=:CommentID",
                array("CommentID"=>$this->getCommentID())
            );
            $eegDateTaken = $row['Date_Taken'];
            $mediaID      = $row['ID'];

            // Build insert query
            $config    = NDB_Config::singleton();
            $mediaPath = $config->getSetting('mediaPath');
            $user      =& User::singleton();

            $query = [
              'session_id'    => $values["sessionID"],
              'instrument'    => $values["test_name"],
              'date_taken'    => $eegDateTaken,
              'file_name'     => $files["{$k}_chooser"]["name"],
              'file_type'     => $_FILES["{$k}_chooser"]["type"],
              'data_dir'      => $mediaPath,
              'uploaded_by'   => $user->getData('UserID'),
            ];

            //-----------------------------------------------------------//
            // Try to move the file from the tmp upload directory to the //
            // media module upload directory                             //
            //-----------------------------------------------------------//
            if (move_uploaded_file($files["{$k}_chooser"]["tmp_name"], $mediaPath . $files["{$k}_chooser"]['name'])) {
                try {
                    // File alread exists in media module: update
                    if(!is_null($mediaID)) {
                        $db->update('media', $query, array('ID' => $mediaID));
                    // File does not exist in media module: insert new
                    } else {
                        $db->insert('media', $query);
                    }

                    // Notifiy listeners that a file was added/edited in the media module
                    $uploadNotifier = new NDB_Notifier("media", "upload");
                    $uploadNotifier->notify(array("file" => $files["{$k}_chooser"]["name"]));

                    // Update field $k in the EEG table for the current record
                    // Note that this was not done by parent::_saveValues since $k
                    // was defined as a "score" (i.e not submitted by the POST)
                    $db->update(
                        $this->table,
                        array($k          => $files["{$k}_chooser"]["name"]),
                        array('CommentID' => $this->getCommentID())
                    );
                } catch (DatabaseException $e) {
                    print_r($e);
                }
            } // if move_upload
        } // foreach
    }

    /**
     * Perfoms addtional validation on top of those done in 'XINvalidate'.
     *
     * @param array $values Values entered in the form.
     * @return array Errors found.
     */
    function eeg_rules($values) {
        $errors = array();

        //------------------------------------//
        // Validate start time, if specified  //
        //------------------------------------//
        if(isset($values['start_time_status']) && $values['start_time_status'] == '' && isset($values['start_time'])) {
            if(!preg_match('/^([0-9]?[0-9]):([0-5][0-9])$/', $values['start_time'], $matches)) {
                $errors['start_time_group'] = 'You must enter a time in 24H format, using the colon as the hour/minute separator (e.g. 08:15 or 20:30)';
            } elseif($matches[1] > 23 || $matches[2] > 59) {
                $errors['start_time_group'] = 'You must enter a time in 24H format, using the colon as the hour/minute separator (e.g. 08:15 or 20:30)';
            }
        }

        //----------------------------------//
        // Validate end time, if specified  //
        //----------------------------------//
        if(isset($values['end_time_status']) && $values['end_time_status'] == '' && isset($values['end_time'])) {
            if(!preg_match('/^([0-9]?[0-9]):([0-5][0-9])$/', $values['end_time'], $matches)) {
                $errors['end_time_group'] = 'You must enter a time in 24H format, using the colon as the hour/minute separator (e.g. 08:15 or 20:30)';
            } elseif($matches[1] > 23 || $matches[2] > 59) {
                $errors['end_time_group'] = 'You must enter a time in 24H format, using the colon as the hour/minute separator (e.g. 08:15 or 20:30)';
            }
        }

        //---------------//
        // Validate OFC  //
        //---------------//
        $this->validate_positive_numeric($values, 'ofc', $errors, 'ofc_group');

        //--------------------------------------------------------------------//
        // Validate that there are no duplicates in the set of files chosen   //
        // with the file choosers on the current page                        //
        //--------------------------------------------------------------------//
        $chosen = array();
        foreach (self::$FILE_FIELDS as $k => $v) {
            //---------------------------------------------//
            // If the associated file chooser was used and //
            // the chooser is on the current page          //
            //---------------------------------------------//
            if ($v['page'] == $this->page) {
                if ($values["{$k}_chooser"]['name'] != '') {
                    $fname = $values["{$k}_chooser"]['name'];
                    if (isset($chosen[$fname])) {
                        $errors["{$k}_chooser"] = "A file with name $fname is already selected in section '{$chosen[$fname]}'. Please choose another file";
                    } else {
                        $chosen[$fname] = $v['name'];
                    }
                }
            }
        }

        //-----------------------------//
        // Validate all required files //
        //-----------------------------//
        foreach (self::$FILE_FIELDS as $k => $v) {
            if (isset($errors["{$k}_chooser"])) {
                continue;
            }

            //---------------------------------------------//
            // If the associated file chooser was used and //
            // the chooser is on the current page          //
            //---------------------------------------------//
            if ($v['page'] != $this->page) {
                continue;
            }

            $db        =& Database::singleton();
            // Check that a file for $k already exists in the DB
            $fileAlreadyUploaded = $db->pselectOne(
                "SELECT $k FROM {$this->table} WHERE CommentID=:CommentID",
                array('CommentID' => $this->getCommentID())
            );

            // File chooser for $k was not used but there's already a file in the DB
            // for $k: all good
            if ($fileAlreadyUploaded && $values["{$k}_chooser"]['name'] == '') {
                continue;
            }

            // File chooser was used to specify the same file as the one in the DB
            // for $k: that's an update and that's OK
            if(!is_null($fileAlreadyUploaded) && $values["{$k}_chooser"]['name'] == $fileAlreadyUploaded) {
                continue;
            }

            // File chooser for $k was not used and no file in the DB for $k: error
            if ($values["{$k}_chooser"]['name'] == '' && $v['required']) {
                $errors["{$k}_chooser"] = 'You must select a file to upload';
            //----------------------------------------------//
            // The file chooser associated to $k was used   //
            // (i.e a file for $k is supplied)              //
            //----------------------------------------------//
            } else {
                //-----------------------------------------------------------------//
                // Check that there is not already a file with the same name       //
                // in the media module.                                            //
                //-----------------------------------------------------------------//
                $query = "SELECT 1 FROM media WHERE file_name=:fileName";
                $fileAlreadyExists = $db->pselectOne(
                    $query,
                    array('fileName'  => $values["{$k}_chooser"]['name'])
                );

                if($fileAlreadyExists) {
                    $errors["{$k}_chooser"] = "A file with name {$values["{$k}_chooser"]['name']} "
                                            . "has already been uploaded in the database. Please choose another one";
                }
            } // else
        } // foreach

        return $errors;
    }
}
