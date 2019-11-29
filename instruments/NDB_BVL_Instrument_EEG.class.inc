<?php
class NDB_BVL_Instrument_EEG extends NDB_BVL_Instrument
{
  use instrument_validator;
  static $cssStyle = "style='color:white; background-color: black;border: 10px solid black;margin-left:0;'";
  static $cssStyle2 = "style='background-color: gray;border: 10px solid gray;height:100%;width:100%;float:left;'";
    /**
    * sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    function setup($commentID, $page): void{
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;           // page label (number or

        // set the object properties
        $this->testName = "EEG";          // test_names.Test_name
        $this->table = 'EEG';             // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");
        $config             = NDB_Config::singleton();
        $this->dateOptions   = array(
            'language'        => 'en',
            'format'          => 'YMd',
            'minYear'         => $config->getSetting('startYear'),
            'maxYear'         => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
           );
        // setup the form
        $db =& Database::singleton();
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
    }

    /**
    * generates the main page of the form.
    *
    * @return void
    * @access private
    *
    */
    function _main(){
        // display test name
        $this->form->addElement('header', null, "<div ".self::$cssStyle.">IBIS-EP EEG Project: EEG Session Log</div>");
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." style='text-align:center'>Subject and Session Information</div>");

        $config = \NDB_Config::singleton();

        $this->form->addElement('text', "subject_ID", "Subject ID:");
        $this->form->addElement('text', "age", "Age:");
        //Gender:
        $this->form->addElement('select', 'gender', 'Gender:', array(NULL=>"","f"=>"Female","m"=>"Male","not_answered"=>"Not Answered"));

        $this->addBasicDate('Date_taken', 'Session Data:', $this->dateOptions);

        $group[] = $this->form->createElement("static", null, null, "Time");
        $group[] = $this->form->createElement("static", null, null, "AM / PM" );
        $this->form->addGroup($group, "time_start_headers", null, $this->_GUIDelimiter, false);
        unset($group);
        $time = array(NULL=>"") + array_combine(range(1,12), range(1,12)) + array("not_answered"=>"Not Answered");
        $group[] = $this->form->createElement('select', 'start_time', null, $time);
        $group[] = $this->form->createElement('select', 'start_time_AMPM', null, array(NULL=>"", "AM"=>"AM", "PM"=>"PM", "not_answered"=>"Not Answered"));
        $this->form->addGroup($group, "start_time_grp", "<b>Start time:</b>", $this->_GUIDelimiter, false);
        unset($group);


        $this->form->addElement('text', "experimenter_initials", "Experimenter Initials:");
        $this->form->addElement('text', "behavioral_assistant_initials", "Behavioral Assistant Initials:");
        $this->form->addElement('select', 'caregiver_present', 'Caregiver Present?', array(NULL=>"","y"=>"Yes","n"=>"No"));
        $this->form->addElement('text', "caregiver_role", "Caregiver role:");
        $this->form->addElement("text", "filename_1", "File Name:");
        $this->form->addElement("file", "file", "Secondary File (optional):");

        $this->form->addElement('text', "ofc", "Head Measurement (OFC): (CM)");
        $this->form->addFormRule(array($this, 'num_rules'));
        $this->form->addElement('text', "net_serial_number", "Net Serial Number:");
        $this->form->addElement("textarea", "additional_notes", "Additional Pre-Session Notes:", array('cols'=>25, 'rows'=>4));
    }
    function _page1(){
       // EEG Net Information
        $this->form->addElement("header", null, "<div ".self::$cssStyle2.">EEG Net Information</div>");
        $this->form->addElement("select", "impedance_before_netting", "Impedances measured before netting?", array(NULL=>"","y"=>"Yes","n"=>"No")); 
        $this->form->addElement("textarea", "bad_channels_before_netting", "Bad channels before netting:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement('select', 'impedance_after_netting', 'Impedances measured after netting?', array(NULL=>"","y"=>"Yes","n"=>"No"));
        $this->form->addElement("textarea", "bad_channels_after_netting", "Bad channels after netting:", array('cols'=>25, 'rows'=>4));

        $this->form->addElement('select', 'net_quality_rating', 'Net Quality Rating:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","not_answered"=>"Not Answered"));
        $this->form->addElement("textarea", "netting_notes", "Netting Notes:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement('select', 'Photo_of_Net_Placement_Taken', 'Photo of Net Placement Taken?', array(NULL=>"","y"=>"Yes","n"=>"No"));
        $this->form->addElement('text', "photo_file_name", "Photo File Name:");
    }
    function _page2(){
           // PARADIGM 1:Resting Bubbles
        $this->form->addElement("header", null, "<div ".self::$cssStyle2." >PARADIGM 1: Resting Bubbles</div>");
        $this->form->addElement("text", "filename_2", "File Name:");
        $this->form->addElement("file", "file", "Secondary File (optional):");
        $this->form->addElement("textarea", "note_1_1", "Artifact/Net Movement Notes:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_1_2", "Soothing Devices Used:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_1_3", "General Notes (child behavior, breaks taken, adjustments etc.):", array('cols'=>25, 'rows'=>4));
        $this->form->addElement('select', 'mood_1', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->form->addElement('select', 'quality_1', 'Quality Rating:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3"));
        $this->form->addElement('text', "trials_completed_1", "Trials Completed:");
    }
  function _page3(){
           // PARADIGM 2:VEP
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >PARADIGM 2: VEP</div>");
        $this->form->addElement('text', "filename_3", "File Name:");
        $this->form->addElement('file', "file", "Secondary File (optional):");
        $this->form->addElement("textarea", "note_2_1", "Artifact/Net Movement Notes:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_2_2", "Soothing Devices Used:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_2_3", "General Notes (child behavior, breaks taken, adjustments etc.):", array('cols'=>25, 'rows'=>4));
        $this->form->addElement('select', 'mood_2', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->form->addElement('select', 'quality_2', 'Quality Rating:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3"));
        $this->form->addElement('text', "trials_completed_2", "Trials Completed:");

  }
  function _page4(){
// PARADIGM 3:AEP    
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >PARADIGM 3: AEP</div>");
        $this->form->addElement('text', "filename_4", "File Name:");
        $this->form->addElement('file', "file", "Secondary File (optional):");
        $this->form->addElement("textarea", "note_3_1", "Artifact/Net Movement Notes:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_3_2", "Soothing Devices Used:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_3_3", "General Notes (child behavior, breaks taken, adjustments etc.):", array('cols'=>25, 'rows'=>4));
        $this->form->addElement('select', 'mood_3', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->form->addElement('select', 'quality_3', 'Quality Rating:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3"));
        $this->form->addElement('text', "trials_completed_3", "Trials Completed:");

  }
  function _page5(){
// PARADIGM 4: Social/NonSocial
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >PARADIGM 4: Social/NonSocial</div>");
        $this->form->addElement('text', "filename_5", "File Name:");
        $this->form->addElement('file', "file", "Secondary File (optional):");
        $this->form->addElement("textarea", "note_4_1", "Artifact/Net Movement Notes:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_4_2", "Soothing Devices Used:", array('cols'=>25, 'rows'=>4));
        $this->form->addElement("textarea", "note_4_3", "General Notes (child behavior, breaks taken, adjustments etc.):", array('cols'=>25, 'rows'=>4));
        $this->form->addElement('select', 'mood_4', 'Mood:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3","4"=>"4","5"=>"5"));
        $this->form->addElement('select', 'quality_4', 'Quality Rating:', array(NULL=>"","1"=>"1","2"=>"2","3"=>"3"));
        $this->form->addElement('text', "trials_completed_4", "Trials Completed:");
  }
  function _page6(){
        $this->form->addElement('header', null, "<div ".self::$cssStyle2." >Overall EEG Session Information</div>");
        $this->form->addElement("textarea", "note_5_1", "General Notes:", array('cols'=>50, 'rows'=>4));
        $group[] = $this->form->createElement("static", null, null, "Time");
        $group[] = $this->form->createElement("static", null, null, "AM / PM" );
        $this->form->addGroup($group, "end_time_headers", "", $this->_GUIDelimiter, false);
        unset($group);
        $time  = array(NULL=>"") + array_combine(range(1,12), range(1,12)) + array("not_answered"=>"Not Answered");
        $group[] = $this->form->createElement('select', 'end_time', null, array(NULL=>"") + $time);
        $group[] = $this->form->createElement('select', 'end_AMPM', null, array(NULL=>"", "AM"=>"AM", "PM"=>"PM", "not_answered"=>"Not Answered"));
        $this->form->addGroup($group, "end_time_grp", "<b> End Time:</b>", $this->_GUIDelimiter, false);
        unset($group);
        $this->form->addElement('select', 'overall_5', 'Overall Irritablity:', array(""=>"","f"=>"Female","m"=>"Male"));
        $this->form->addElement('select', 'experimental_order_5', 'Experimental Order:', array(""=>"","f"=>"Female","m"=>"Male"));

        $this->form->addElement("textarea", "note_5_2", "Notes on Order Deviations:", array('cols'=>50, 'rows'=>4));
  }

  function _saveValues($values) {
//var_dump($values);
             if (!empty($values["file"]["name"])) {
                $timepoint = TimePoint::singleton($this->getSessionID());
                $candidate = Candidate::singleton($timepoint->getCandID());

                $uploadNotifier = new NDB_Notifier(
                    "media",
                    "upload"
                );
                $db     =& Database::singleton();
                $config = NDB_Config::singleton();
                $user   =& User::singleton();
                $mediaPath = $config->getSetting('mediaPath');

                //  $fileName  = preg_replace('/\s/', '_', $_FILES["file"]["name"]);
                $fileType  = $_FILES["file"]["type"];

                $userID = $user->getData('UserID');
                $eeg_datetaken = $db->pselectOne(
                  "SELECT Date_Taken FROM EEG ",array("CommentID"=>$this->getCommentID()));
                // Build insert query
                $query = [
                    'session_id'    => $values["sessionID"],
                    'instrument'    => $values["test_name"],
                    'date_taken'    => $eeg_datetaken,
                    'file_name'     => $values["file"]["name"],
                    'file_type'     => $fileType,
                    'data_dir'      => $mediaPath,
                    'uploaded_by'   => $userID,
                ];
             if (move_uploaded_file($values["file"]["tmp_name"], $mediaPath . $values["file"]["name"])) {
                try {
                       // Insert or override db record if file_name already exists
                       $db->insertOnDuplicateUpdate('media', $query);
                       $uploadNotifier->notify(array("file" => $values["file"]["name"]));
                    } catch (DatabaseException $e) {
                       print_r($e);
                    }
              }
              } // end if


 }


 /* function _saveValues($values) {
       if(isset($values['Date_taken'])) {
            $date = $values['Date_taken'];
            if(!empty($date['Y']) && !empty($date['M']) && !empty($date['d'])) {
                $values['Date_taken'] = $this->_getDatabaseDate($date); //sprintf("%04d-%02d-%02d", $date['Y'], $date['M'], $date['d']);
                $this->_saveCandidateAge($values);
            }  else {
                unset($values['Date_taken']);
            }
        }
        for ($i=1;$i<6;$i++) {

             if (!empty($values["file_".$i]["name"])) {
                $timepoint = TimePoint::singleton($this->getSessionID());
                $candidate = Candidate::singleton($timepoint->getCandID());

                $uploadNotifier = new NDB_Notifier(
                    "media",
                    "upload"
                );
                $db     =& Database::singleton();
                $config = NDB_Config::singleton();
                $user   =& User::singleton();
                $mediaPath = $config->getSetting('mediaPath');

                //  $fileName  = preg_replace('/\s/', '_', $_FILES["file"]["name"]);
                $fileType  = $_FILES["file_".$i]["type"];

                $userID = $user->getData('UserID');
                $eeg_datetaken = $db->pselectOne(
                  "SELECT Data_Taken FROM EEG ",array("CommentID"=>$this->getCommentID()));
                // Build insert query
                $query = [
                    'session_id'    => $values["sessionID"],
                    'instrument'    => $values["test_name"],
                    'date_taken'    => $eeg_datetaken,
                    'file_name'     => $values["file_".$i]["name"],
                    'file_type'     => $fileType,
                    'data_dir'      => $mediaPath,
                    'uploaded_by'   => $userID,
                ];
             if (move_uploaded_file($values["file_".$i]["tmp_name"], $mediaPath . $values["file_".$i]["name"])) {
                try {
                       // Insert or override db record if file_name already exists
                       $db->insertOnDuplicateUpdate('media', $query);
                       $uploadNotifier->notify(array("file" => $values["file_".$i]["name"]));
                    } catch (DatabaseException $e) {
                       print_r($e);
                    }
              }
              } // end if
        } // end for 

 }*/
  function num_rules($values)
  {
      $errors = array();
         if ($values["ofc"] != "" && (!is_numeric($values["ofc"]) || intval($values["ofc"]) < 0)) {
             $errors["ofc"] = "Specify a positive number";                   
         }
         if ($values["age"] != "" && (!is_numeric($values["age"]) || intval($values["age"]) < 0)) {
             $errors["age"] = "Specify a positive number";
         }
      return $errors;
        
  }
}
 
