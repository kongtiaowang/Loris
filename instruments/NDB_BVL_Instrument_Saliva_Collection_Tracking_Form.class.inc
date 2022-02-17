<?php


class NDB_BVL_Instrument_Saliva_Collection_Tracking_Form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityRequired = false;

    const YES_NO_OPTIONS = array(
                               ""           => "",
                               "yes"          => "Yes",
                               "no"           => "No",
                              );

    const YES_NO_DONT_KNOW = array(
                               ""           => "",
                               "yes"          => "Yes",
                               "no"           => "No",
                               "0"             => "I don't know"
                              );

    const VISIT_MAIL_OPTIONS = array(
                                 ""           => "",
                                'At_Visit'=>"At Visit",
                                'Via_Mail' => "Via Mail",
                                'refused' => "Refused"
                           );

    const VISIT_MAIL= array(
                                 ""           => "",
                                'At_Visit'=>"At Visit",
                                'Via_Mail' => "Via Mail"
                           );

    const KIT_TYPE = array(
	    			null         =>  "",
				"drool"      =>  "Drool",
				"swab"       =>  "Swab",
				"unknown"    =>  "Unknown",
				"not_answered" => "Not Answered",
    			);
    /**
    * sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
                                        // string - used by
                                        // user-defined child classes)

        // set the object properties
        $this->testName = "Saliva_Collection_Tracking_Form";           // test_names.Test_name
        $this->table = 'Saliva_Collection_Tracking_Form';             // name of table containing


        // data keyed by commentID
        $this->commentID = $commentID;

        //$this->_requiredElements = array('Date_taken', 'Examiner');

        $this->dateTimeFields=array("Date_taken");

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
        if(preg_match("/Saliva_Collection_Tracking_Form(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));

    }

    function _main(){
        $this->form->addElement('header', 'instrument_title', "Saliva Collection Tracking Form");
        $this->addLabel('This form is to be completed when the saliva collection tubes are being prepared for a family. All tubes should be labeled using this structure: “PSCID_DCCID_CA_Timepoint” where CA is IN=subject, PR=proband, MO=mother, FA=father. ');

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

        // display test name

    }

function _page1(){

        $this->form->addElement('header', null, 'Subject');

               $this->form->addElement('select','subject_need_collection','1. Does the subject need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('subject_need_collection', 'This question is required', 'required');

               $this->addLabel("<i>If 'No' is selected for Question 1, please skip all other questions.</i>");

               $this->form->addElement('select','subject_how_collected','2. How will saliva be collected?',self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('subject_how_collected', array("subject_need_collection{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

	       $this->form->addElement('select','subject_kit_used','3. Which type of kit will the Subject use?', self::KIT_TYPE);

               $this->form->addGroup($group, 'subject_header1', "At Visit", $this->_GUIDelimiter, FALSE);
               unset($group);
               $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


               $this->form->addElement('date','subject_visit_collection_date','4. Collection Date?', $this->dateOptions);

               $this->XINRegisterRule('subject_visit_collection_date', array("subject_how_collected{@}=={@}At_Visit"), "Required if 'At Visit', for Question 2");


	       $group[] = $this->form->createElement("date","subject_visit_mailed_to_UNC",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","subject_visit_mailed_to_UNC_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
              );
              $this->XINRegisterRule("subject_visit_mailed_to_UNC",array("subject_visit_mailed_to_UNC_status{@}=={@}"),"You must either enter a date or specify that the sample is stored at the site","sq4_group");
              $this->addGroup($group,"sq4_group","5. Date mailed to UNC?",$this->_GUIDelimiter,false);
	      unset($group);

               $this->XINRegisterRule('sq4_group', array("subject_how_collected{@}=={@}At_Visit"), "Required if 'At Visit', for Question 2");

               $this->form->addElement('text','subject_visit_tracking_number','6. Tracking number for shipment to UNC:');

               $this->XINRegisterRule('subject_visit_tracking_number', array("subject_how_collected{@}=={@}At_Visit"), "Required if 'At Visit', for Question 2");



              $group[] = $this->form->createElement('static', "", null, null);
              $this->form->addGroup($group, 'mail_header_group_', "Via Mail", $this->_GUIDelimiter, FALSE);
               unset($group);
               $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");



               $this->form->addElement('select','subject_mail_receive','7. How will the family receive the kits?', self::VISIT_MAIL);

               $this->XINRegisterRule('subject_mail_receive', array("subject_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail', for Question 2");


               $this->XINRegisterRule('subject_mail_receive', array("subject_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail', for Question 2");

	       $this->form->addElement('text','subject_mail_tracking_number','8. Tracking number for shipment to UNC:');

               $this->form->addFormRule(array(&$this, 'validate_page1'));


}

function _page2(){

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



               $this->form->addElement('header', null, 'Proband');

               $this->form->addElement('select','proband_need_collection','1. Does the proband need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('proband_need_collection', 'This question is required', 'required');

               $this->addLabel("<i>If 'No' is selected for Question 1, please skip all other questions.</i>");


              $this->form->addElement('select','proband_need_signed_consent','2.  Does the proband need to sign an assent or consent form?',self::YES_NO_DONT_KNOW);

               $this->XINRegisterRule('proband_need_signed_consent', array("proband_need_collection{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

	       $this->form->addElement('select','proband_kit_used','3. Which type of kit will the Proband use?', self::KIT_TYPE);

               $this->form->addElement('select','proband_consent',"4. Does this proband give consent?", array(''=>'','yes'=>'Yes','refused'=>'Refused','not_asked'=>'Not Asked'));

               $this->form->addElement('select','proband_how_collected','5. How will saliva be collected?', self::VISIT_MAIL_OPTIONS);

              $this->XINRegisterRule('proband_how_collected', array("proband_need_signed_consent{@}=={@}yes"), "Required if 'yes' was selected for Question 2");


            $this->form->addGroup($group, 'proband_header1', "At Visit", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


               $this->form->addElement('date','proband_visit_collection_date','6. Collection Date?', $this->dateOptions);

               $this->XINRegisterRule('proband_visit_collection_date', array("proband_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 6");

             $this->form->addElement('text','proband_visit_tracking_number','7. Tracking number for shipment to UNC:');

               $this->XINRegisterRule('proband_visit_tracking_number', array("proband_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 6");

	       $group[] = $this->form->createElement("date","proband_visit_mailed_to_UNC",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","proband_visit_mailed_to_UNC_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
            );
            $this->XINRegisterRule("proband_visit_mailed_to_UNC",array("proband_visit_mailed_to_UNC_status{@}=={@}"),"You must either enter a date or specify that the sample is stored at the site","pq9_group");
	    $this->addGroup($group,"pq9_group","8. Date mailed to UNC?",$this->_GUIDelimiter,false);
	    unset($group);

               $this->XINRegisterRule('pq9_group', array("proband_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 6");



            $this->form->addGroup($group, 'proband_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");


                $this->form->addElement("select", "proband_mail_receive", "8. How will the family receive the kits?",  self::VISIT_MAIL);

                $this->XINRegisterRule('proband_mail_receive', array("proband_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 6");


                $this->form->addElement('text', 'proband_mail_tracking_number', '9. Tracking number for shipment to UNC:');


                $this->XINRegisterRule('proband_mail_tracking_number', array("proband_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 6");


               $this->form->addFormRule(array(&$this, 'validate_page2'));


}

function _page3(){

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
               $this->form->addFormRule(array(&$this,'XINValidate'));

               $this->form->addElement('header', null, 'Mother');

               $this->form->addElement('select','mother_need_collection','1. Does the mother need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('mother_need_collection', 'This question is required', 'required');

               $this->form->addElement('static','mq_2',"2. How will saliva be collected?");

               $this->form->addElement('select','mother_how_collected','', self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('mother_how_collected', array("mother_need_collection{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

              $this->form->addGroup($group, 'mother_header1', "At Visit", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


               $this->form->addElement('date','mother_visit_collection_date','3. Collection Date?', $this->dateOptions);

              $this->XINRegisterRule('mother_visit_collection_date', array("mother_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

	      $group[] = $this->form->createElement("date","mother_visit_mailed_to_UNC",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","mother_visit_mailed_to_UNC_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
            );
            $this->XINRegisterRule("mother_visit_mailed_to_UNC",array("mother_visit_mailed_to_UNC_status{@}=={@}"),"You must either enter a date or specify that the sample is stored at the site","mq4_group");
            $this->addGroup($group,"mq4_group","4. Date mailed to UNC?",$this->_GUIDelimiter,false);
	    unset($group);

               $this->XINRegisterRule('mq4_group', array("mother_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

               $this->form->addElement('text','mother_visit_tracking_number','5. Tracking number for shipment to UNC');

               $this->XINRegisterRule('mother_visit_tracking_number', array("mother_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");



              $this->form->addGroup($group, 'mother_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");


               $this->form->addElement('select','mother_mail_receive','6. How will the family receive the kits?', self::VISIT_MAIL);

              $this->XINRegisterRule('mother_mail_receive', array("mother_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail', Question 2");

              $this->form->addElement('text', 'mother_mail_tracking_number', '7. Tracking number for shipment to UNC:');


              $this->XINRegisterRule('mother_mail_tracking_number', array("mother_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 2");


                $this->form->addFormRule(array(&$this, 'validate_page3'));


}

function _page4(){

         $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

            $this->form->addElement('header', null, 'Father');

               $this->form->addElement('select','father_need_collection','1. Does the father need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('father_need_collection', 'This question is required', 'required');

               $this->form->addElement('static','fq_2',"2. How will saliva be collected?");

               $this->form->addElement('select','father_how_collected','', self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('father_how_collected', array("father_need_collection{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

              $this->form->addGroup($group, 'mother_header1', "At Visit", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");

               $this->form->addElement('date','father_visit_collection_date','3. Collection Date?', $this->dateOptions);

              $this->XINRegisterRule('father_visit_collection_date', array("father_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

	      $group[] = $this->form->createElement("date","father_visit_mailed_to_UNC",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","father_visit_mailed_to_UNC_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
            );
            $this->XINRegisterRule("father_visit_mailed_to_UNC",array("father_visit_mailed_to_UNC_status{@}=={@}"),"You must either enter a date or specify that the sample is stored at the site","fq4_group");
            $this->addGroup($group,"fq4_group","4. Date mailed to UNC?",$this->_GUIDelimiter,false);
	    unset($group);

               $this->XINRegisterRule('fq4_group', array("father_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

               $this->form->addElement('text','father_visit_tracking_number','5. Tracking number for shipment to UNC');

               $this->XINRegisterRule('father_visit_tracking_number', array("father_how_collected{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");



              $this->form->addGroup($group, 'mother_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");


              $this->form->addElement('select','father_mail_receive','6. How will the family receive the kits?', self::VISIT_MAIL);

              $this->XINRegisterRule('father_mail_receive', array("father_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 2");

              $this->form->addElement('text', 'father_mail_tracking_number', '7. Tracking number for shipment to UNC:');


              $this->XINRegisterRule('father_mail_tracking_number', array("father_how_collected{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 2");


              $this->form->addFormRule(array(&$this, 'validate_page4'));

}

function _page5(){
               $this->form->addElement('header', null, 'Additional Siblings and Family ID');

               $this->form->addElement('select','delivered_to_lab','1.Did UNC staff deliver saliva tube to processing lab at UNC?',array('' => '','yes'=>"Yes",'no' => "No","investigate"=>"Need to Investigate","na"=>"NA - Shipped directly to lab at UNC"));
                $this->XINRegisterRule("delivered_to_lab", array("aq1{@}=={@}NEVER_REQUIRED"));

	       $this->form->addElement('date','delivered_to_lab_date', $this->indent . "Date delivered", $this->dateOptions);

	       $this->form->addElement('text','delivered_to_lab_by', $this->indent . 'UNC staff member that delivered tubes.');

               $this->form->addElement('select','have_family_id',"2. Does this subject have a family ID? [Family ID can be found in the 'Family Information' tab of the 'Candidate Info' in the candidate's page.] ",self::YES_NO_DONT_KNOW);

               $this->form->addRule('have_family_id', 'This question is required', 'required');

               $this->form->addElement('text','family_id','3.  What is Family ID?');
                $this->XINRegisterRule('family_id', array("have_family_id{@}=={@}yes"), "Required if 'Yes' was selected for Question 2.");


               $this->form->addFormRule(array(&$this, 'validate_tracking_number'));
               $this->form->addFormRule(array(&$this, 'validate_page4'));

}

    // This function is overridden here to send the email notifications if blood draw date is set.
    function _save(array $values): void
    {
      $db =& Database::singleton();
      $PSCID = $this->getPSCID();
      $msg_data['PSCID'] = $PSCID;


            //subject
           // - If 'At visit' was selected for question 2, email should include 'Date mailed to UNC' and 'Tracking Number'.
           // - If 'Via Mail' was selected for question 2, email should include a reminder to "Document 'Tracking number' internally.".
            $notification_reciever_email = 'Heidi.Bryant@cidd.unc.edu';
      if ($values['subject_need_collection'] == 'yes') {
          if ($values["subject_how_collected"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['subject_visit_mailed_to_UNC'];
                  $msg_data['tracking_number'] = $value['subject_visit_tracking_number'];
                Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          }
          if ($values["subject_how_collected"] == "Via_Mail"){
                  $msg_data['tracking_number'] = $value['subject_visit_tracking_number'];
                Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");

          }
       }
      //proband
      if ($values['proband_need_collection'] == 'yes') {
          if ($values["proband_how_collected"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['proband_visit_mailed_to_UNC'];
                  $msg_data['tracking_number'] = $value['proband_visit_tracking_number'];
                // Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          }
          if ($values["proband_how_collected"] == "Via_Mail"){
                $msg_data['tracking_number'] = $value['proband_mail_tracking_number'];
                // Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");

          }
       }
      //mother
      if ($values['mother_need_collection'] == 'yes') {
          if ($values["mother_how_collected"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['mother_visit_mailed_to_UNC'];
                  $msg_data['tracking_number'] = $value['mother_visit_tracking_number'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          }
          if ($values["mother_how_collected"] == "Via_Mail"){
                  $msg_data['tracking_number'] = $value['mother_mail_tracking_number'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");

          }
       }
      //father
      if ($values['father_need_collection'] == 'yes') {
          if ($values["father_how_collected"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['father_visit_mailed_to_UNC'];
                  $msg_data['tracking_number'] = $value['father_visit_tracking_number'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          }
          if ($values["father_how_collected"] == "Via_Mail"){
                  $msg_data['tracking_number'] = $value['father_mail_tracking_number'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");

          }
       }
       parent::_save($values);
    }


  /**
    * adds metadata fields (such as Examiner and Date_taken) to the
    * current form
    *
    * @return void
    * @access private
    */
    function _addMetadataFields(): void
    {
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
        'language' => 'en',
        'format'   => 'YMd',
        'minYear'  => $config->getSetting('startYear'),
        'maxYear'  => $config->getSetting('endYear'),
        'addEmptyOption' => true,
        'emptyOptionValue' => null
        );

        $this->form->addElement('date', 'Date_taken', 'Date of Administration (Use Date of visit)', $this->dateOptions);

        $examiners = $this->_getExaminerNames();

        $this->form->addRule('Date_taken', 'Date of Administration is required', 'required');



        $this->form->addElement('date', 'Date_Kits', 'Date kits prepared', $this->dateOptions);
        $this->form->addRule('Date_Kits', 'Date kits prepared is required', 'required');

        $this->form->addElement('select', 'Examiner', 'Examiner', $examiners);


        $this->form->addRule('Examiner', 'Examiner is required', 'required');

    }


    function validate_tracking_number($values)
    {
        $errors = [];
        $this->validate_positive_numeric($values, "family_id", $errors);
        return $errors;

    }


    function validate_positive_numeric($values, $question, &$errors)
    {
        if (isset($values[$question])) {
            $user_input = $values[$question];
            if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                $errors[$question] = "Specify a number as tracking number.";
            }
        }
    }

    function validate_page1($values)
    {
      $err_msg = "Not required, please leave the field blank";
             $errors = array();
          if ($values["subject_how_collected"] == "At_Visit")
          {
              if ($values["subject_mail_receive"] != null)
              {
                $errors["subject_mail_receive"] = $err_msg;
              }

          }

          if ($values["subject_how_collected"] == "Via_Mail")
          {
              if ($values["subject_visit_collection_date"] != null)
              {
                $errors["subject_visit_collection_date"] = $err_msg;
              }
              if ($values["subject_visit_mailed_to_UNC"] != null)
              {
                $errors["subject_visit_mailed_to_UNC"] = $err_msg;
              }
              if ($values["subject_visit_tracking_number"] != null)
              {
                $errors["subject_visit_tracking_number"] = $err_msg;
              }

          }

        return $errors;
    }
    function validate_page2($values)
    {
      $err_msg = "Not required, please leave the field blank";
          $errors = array();
          if ($values["proband_how_collected"] == "At_Visit")
          {
              if ($values["proband_mail_receive"] != null)
              {
                $errors["proband_mail_receive"] = $err_msg;
              }
              if ($values["proband_mail_tracking_number"] != null)
              {
                $errors["proband_mail_tracking_number"] = $err_msg;
              }
          }

          if ($values["proband_how_collected"] == "Via_Mail")
          {
              if ($values["proband_visit_collection_date"] != null)
              {
                $errors["proband_visit_collection_date"] = $err_msg;
              }
              if ($values["proband_visit_tracking_number"] != null)
              {
                $errors["proband_visit_tracking_number"] = $err_msg;
              }
              if ($values["proband_visit_mailed_to_UNC"] != null)
              {
                $errors["proband_visit_mailed_to_UNC"] = $err_msg;
              }

          }
        return $errors;
    }


    function validate_page3($values)
    {
      $err_msg = "Not required, please leave the field blank";
          $errors = array();
          if ($values["mother_how_collected"] == "At_Visit")
          {
              if ($values["mother_mail_receive"] != null)
              {
                $errors["mother_mail_receive"] = $err_msg;
              }
              if ($values["mother_mail_tracking_number"] != null)
              {
                $errors["mother_mail_tracking_number"] = $err_msg;
              }

          }

          if ($values["mother_how_collected"] == "Via_Mail")
          {
              if ($values["mother_visit_collection_date"] != null)
              {
                $errors["mother_visit_collection_date"] = $err_msg;
              }
              if ($values["mother_visit_tracking_number"] != null)
              {
                $errors["mother_visit_tracking_number"] = $err_msg;
              }
              if ($values["mother_visit_mailed_to_UNC"] != null)
              {
                $errors["mother_visit_mailed_to_UNC"] = $err_msg;
              }

          }
        return $errors;
    }

    function validate_page4($values)
    {
      $err_msg = "Not required, please leave the field blank";
          $errors = array();
          if ($values["father_how_collected"] == "At_Visit")
          {
              if ($values["father_mail_receive"] != null)
              {
                $errors["father_mail_receive"] = $err_msg;
              }
              if ($values["father_mail_tracking_number"] != null)
              {
                $errors["father_mail_tracking_number"] = $err_msg;
              }

          }

          if ($values["father_how_collected"] == "Via_Mail")
          {
              if ($values["father_visit_collection_date"] != null)
              {
                $errors["father_visit_collection_date"] = $err_msg;
              }
              if ($values["father_visit_tracking_number"] != null)
              {
                $errors["father_visit_tracking_number"] = $err_msg;
              }
              if ($values["father_visit_mailed_to_UNC"] != null)
              {
                $errors["father_visit_mailed_to_UNC"] = $err_msg;
              }

          }
        return $errors;
    }

}
