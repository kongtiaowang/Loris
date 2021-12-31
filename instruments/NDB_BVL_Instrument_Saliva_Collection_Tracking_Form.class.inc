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

           //    $this->form->addElement('static','sq_1',"1. Does the subject need saliva collected?");
               
               $this->form->addElement('select','sq1','1. Does the subject need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('sq1', 'This question is required', 'required');

               $this->addLabel("<i>If 'No' is selected for Question 1, please skip all other questions.</i>");

               $this->form->addElement('select','sq2','2. How will saliva be collected?',self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('sq2', array("sq1{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

	       $this->form->addElement('select','sq3a','3. Which type of kit will the Subject use?', self::KIT_TYPE);

               $this->form->addGroup($group, 'subject_header1', "At Visit", $this->_GUIDelimiter, FALSE);
               unset($group);
               $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


               $this->form->addElement('date','sq3','4. Collection Date?', $this->dateOptions);
 
               $this->XINRegisterRule('sq3', array("sq2{@}=={@}At_Visit"), "Required if 'At Visit', for Question 2");




               $this->form->addElement('date','sq4', "5. Date mailed to UNC", $this->dateOptions);
               
               $this->XINRegisterRule('sq4', array("sq2{@}=={@}At_Visit"), "Required if 'At Visit', for Question 2");

               $this->form->addElement('text','sq5','6. Tracking number:');

               $this->XINRegisterRule('sq5', array("sq2{@}=={@}At_Visit"), "Required if 'At Visit', for Question 2");

 

              $group[] = $this->form->createElement('static', "", null, null);
              $this->form->addGroup($group, 'mail_header_group_', "Via Mail", $this->_GUIDelimiter, FALSE);
               unset($group);
               $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");

            

               $this->form->addElement('select','sq6','7. How will the family receive the kits?', self::VISIT_MAIL);
               
               $this->XINRegisterRule('sq6', array("sq2{@}=={@}Via_Mail"), "Required if 'Via Mail', for Question 2");


               $this->XINRegisterRule('sq6', array("sq2{@}=={@}Via_Mail"), "Required if 'Via Mail', for Question 2");

	       $this->form->addElement('text','sq8','8. Tracking number for return label to UNC');

               $this->form->addFormRule(array(&$this, 'validate_page1'));


}

function _page2(){

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



               $this->form->addElement('header', null, 'Proband');

               $this->form->addElement('select','pq1','1. Does the proband need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('pq1', 'This question is required', 'required');

               $this->addLabel("<i>If 'No' is selected for Question 1, please skip all other questions.</i>");

              
              $this->form->addElement('select','pq2','2.  Does the proband need to sign an assent or consent form?',self::YES_NO_DONT_KNOW);

               $this->XINRegisterRule('pq2', array("pq1{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

	       $this->form->addElement('select','pq3a','3. Which type of kit will the Subject use?', self::KIT_TYPE);

               $this->form->addElement('select','pq3',"4. Does this proband give consent?", array(''=>'','yes'=>'Yes','refused'=>'Refused','not_asked'=>'Not Asked'));
    
               $this->form->addElement('select','pq6','5. How will saliva be collected?', self::VISIT_MAIL_OPTIONS);

                $this->XINRegisterRule('pq6', array("pq2{@}=={@}yes"), "Required if 'yes' was selected for Question 2");


            $this->form->addGroup($group, 'proband_header1', "At Visit", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


               $this->form->addElement('date','pq7','6. Collection Date?', $this->dateOptions);

               $this->XINRegisterRule('pq7', array("pq6{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 6");

             $this->form->addElement('text','pq8','7. Tracking number:');

               $this->XINRegisterRule('pq8', array("pq6{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 6");

             //  $this->form->addElement('date','pq9','8. Date mailed to UNC?', $this->dateOptions);

	       $group[] = $this->form->createElement("date","pq9",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","pq9_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
            );
            $this->XINRegisterRule("pq9",array("pq9_status{@}=={@}"),"A Date, Not yet planned, storing at site is required.","pq9_group");
	    $this->addGroup($group,"pq9_group","8. Date mailed to UNC?",$this->_GUIDelimiter,false);
	    unset($group);

               $this->XINRegisterRule('pq9_group', array("pq6{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 6");



            $this->form->addGroup($group, 'proband_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");


                $this->form->addElement("select", "pq10", "8. How will the family receive the kits?",  self::VISIT_MAIL);

                $this->XINRegisterRule('pq10', array("pq6{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 6");


                $this->form->addElement('text', 'pq_tracking_no', '9. Tracking number for return label to UNC');


                $this->XINRegisterRule('pq_tracking_no', array("pq6{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 6");
                

               $this->form->addFormRule(array(&$this, 'validate_page2'));


}

function _page3(){

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

            $this->form->addElement('header', null, 'Mother');

               $this->form->addElement('select','mq1','1. Does the mother need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('mq1', 'This question is required', 'required');              
               
               $this->form->addElement('static','mq_2',"2. How will saliva be collected?");

               $this->form->addElement('select','mq2','', self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('mq2', array("mq1{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

              $this->form->addGroup($group, 'mother_header1', "At Visit", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


               $this->form->addElement('date','mq3','3. Collection Date?', $this->dateOptions);

              $this->XINRegisterRule('mq3', array("mq2{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

             //  $this->form->addElement('date','mq4', "4. Date mailed to UNC?", $this->dateOptions);

	      $group[] = $this->form->createElement("date","mq4",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","mq4_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
            );
            $this->XINRegisterRule("mq4",array("mq4_status{@}=={@}"),"A Date, Not yet planned, storing at site is required.","mq4_group");
            $this->addGroup($group,"mq4_group","4. Date mailed to UNC?",$this->_GUIDelimiter,false);
	    unset($group);

               $this->XINRegisterRule('mq4_group', array("mq2{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

               $this->form->addElement('text','mq5','5. Tracking number');

               $this->XINRegisterRule('mq5', array("mq2{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");



              $this->form->addGroup($group, 'mother_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");


               $this->form->addElement('select','mq6','6. How will the family receive the kits?', self::VISIT_MAIL);
               
              $this->XINRegisterRule('mq6', array("mq2{@}=={@}Via_Mail"), "Required if 'Via Mail', Question 2");

              $this->form->addElement('text', 'mq_tracking_no', '7. Tracking number for return label to UNC');


              $this->XINRegisterRule('mq_tracking_no', array("mq2{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 2");


                $this->form->addFormRule(array(&$this, 'validate_page3'));


}

function _page4(){     

         $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

            $this->form->addElement('header', null, 'Father');

               $this->form->addElement('select','fq1','1. Does the father need saliva collected?',self::YES_NO_DONT_KNOW);
               $this->form->addRule('fq1', 'This question is required', 'required');              

               $this->form->addElement('static','fq_2',"2. How will saliva be collected?");

               $this->form->addElement('select','fq2','', self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('fq2', array("fq1{@}=={@}yes"), "Required if 'Yes' was selected for Question 1.");

              $this->form->addGroup($group, 'mother_header1', "At Visit", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");

               $this->form->addElement('date','fq3','3. Collection Date?', $this->dateOptions);

              $this->XINRegisterRule('fq3', array("fq2{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

            //   $this->form->addElement('date','fq4', "4. Date mailed to UNC?", $this->dateOptions);

	      $group[] = $this->form->createElement("date","fq4",null,$this->dateOptions);
               $group[] = $this->form->createElement("select","fq4_status",null,
               array(
                 null           => "",
                 'not_answered' => "Not yet planned, storing at site",
                )
            );
            $this->XINRegisterRule("fq4",array("fq4_status{@}=={@}"),"A Date, Not yet planned, storing at site is required.","fq4_group");
            $this->addGroup($group,"fq4_group","4. Date mailed to UNC?",$this->_GUIDelimiter,false);
	    unset($group);

               $this->XINRegisterRule('fq4_group', array("fq2{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");

               $this->form->addElement('text','fq5','5. Tracking number');

               $this->XINRegisterRule('fq5', array("fq2{@}=={@}At_Visit"), "Required if 'At Visit' was selected for Question 2");



              $this->form->addGroup($group, 'mother_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");


              $this->form->addElement('select','fq6','6. How will the family receive the kits?', self::VISIT_MAIL);
               
              $this->XINRegisterRule('fq6', array("fq2{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 2");

              $this->form->addElement('text', 'fq_tracking_no', '7. Tracking number for return label to UNC');


              $this->XINRegisterRule('fq_tracking_no', array("fq2{@}=={@}Via_Mail"), "Required if 'Via Mail' was selected for Question 2");


              $this->form->addFormRule(array(&$this, 'validate_page4'));

}

function _page5(){
               $this->form->addElement('header', null, 'Additional Siblings and Family ID');

               $this->form->addElement('select','aq1','1.Did UNC staff deliver saliva tube to processing lab at UNC?',array('' => '','yes'=>"Yes",'no' => "No","investigate"=>"Need to Investigate","na"=>"NA - Shipped directly to lab at UNC"));
                $this->XINRegisterRule("aq1", array("aq1{@}=={@}NEVER_REQUIRED"));

	       $this->form->addElement('date','other_date_delivered', $this->indent . "Date delivered", $this->dateOptions);

	       $this->form->addElement('text','other_staff_delivered', $this->indent . 'UNC staff member that delivered tubes.');

               $this->form->addElement('select','aq2',"2. Does this subject have a family ID? [Family ID can be found in the 'Family Information' tab of the 'Candidate Info' in the candidate's page.] ",self::YES_NO_DONT_KNOW);

               $this->form->addRule('aq2', 'This question is required', 'required');

               $this->form->addElement('text','aq3','3.  What is Family ID?');
                $this->XINRegisterRule('aq3', array("aq2{@}=={@}yes"), "Required if 'Yes' was selected for Question 2.");


               $this->form->addFormRule(array(&$this, 'validate_tracking_number'));
               $this->form->addFormRule(array(&$this, 'validate_page4'));

}

    // This function is overridden here to send the email notifications if blood draw date is set.
    function _save(array $values): void
    {
      $db =& Database::singleton();
      $timepoint =& TimePoint::singleton($this->getSessionID());
      $candidate =& Candidate::singleton($timepoint->getCandID());
      $PSCID = $candidate->getPSCID();
      $msg_data['PSCID'] = $PSCID;

      
            //subject
           // - If 'At visit' was selected for question 2, email should include 'Date mailed to UNC' and 'Tracking Number'.
           // - If 'Via Mail' was selected for question 2, email should include a reminder to "Document 'Tracking number' internally.".
            $notification_reciever_email = 'Heidi.Bryant@cidd.unc.edu';
      if ($values['sq1'] == 'yes') {
          if ($values["sq2"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['sq4'];
                  $msg_data['tracking_number'] = $value['sq5'];
                Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          } 
          if ($values["sq2"] == "Via_Mail"){
                  $msg_data['tracking_number'] = $value['sq5'];
                Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
            
          } 
       }
      //proband
      if ($values['pq1'] == 'yes') {
          if ($values["pq6"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['pq9'];
                  $msg_data['tracking_number'] = $value['pq8'];
                // Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          } 
          if ($values["pq6"] == "Via_Mail"){
                $msg_data['tracking_number'] = $value['pq_tracking_no'];
                // Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
            
          } 
       }
      //mother
      if ($values['mq1'] == 'yes') {
          if ($values["mq2"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['mq4']; 
                  $msg_data['tracking_number'] = $value['mq5'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          } 
          if ($values["mq2"] == "Via_Mail"){
                  $msg_data['tracking_number'] = $value['mq_tracking_no'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
            
          } 
       }
      //father
      if ($values['fq1'] == 'yes') {
          if ($values["fq2"] == "At_Visit"){
                  $msg_data['mail_date'] = $value['fq4']; 
                  $msg_data['tracking_number'] = $value['fq5'];
                  Email::send($notification_reciever_email, 'Saliva_Collection_Tracking_Form_Email_Notifications.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
          } 
          if ($values["fq2"] == "Via_Mail"){
                  $msg_data['tracking_number'] = $value['fq_tracking_no'];
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
        $this->validate_positive_numeric($values, "aq3", $errors);
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
          if ($values["sq2"] == "At_Visit") 
          {
              if ($values["sq6"] != null)
              {
                $errors["sq6"] = $err_msg;
              }

          } 

          if ($values["sq2"] == "Via_Mail") 
          {
              if ($values["sq3"] != null)
              {
                $errors["sq3"] = $err_msg;
              }
              if ($values["sq4"] != null)
              {
                $errors["sq4"] = $err_msg;
              }
              if ($values["sq5"] != null)
              {
                $errors["sq5"] = $err_msg;
              }

          }
  
        return $errors;
    }
    function validate_page2($values)
    {
      $err_msg = "Not required, please leave the field blank";
          $errors = array();
          if ($values["pq6"] == "At_Visit") 
          {
              if ($values["pq10"] != null)
              {
                $errors["pq10"] = $err_msg;
              }
              if ($values["pq_tracking_no"] != null)
              {
                $errors["pq_tracking_no"] = $err_msg;
              }
          } 

          if ($values["pq6"] == "Via_Mail") 
          {
              if ($values["pq7"] != null)
              {
                $errors["pq7"] = $err_msg;
              }            
              if ($values["pq8"] != null)
              {
                $errors["pq8"] = $err_msg;
              }
              if ($values["pq9"] != null)
              {
                $errors["pq9"] = $err_msg;
              }

          }
        return $errors;
    }


    function validate_page3($values)
    {
      $err_msg = "Not required, please leave the field blank";
          $errors = array();
          if ($values["mq2"] == "At_Visit") 
          {
              if ($values["mq6"] != null)
              {
                $errors["mq6"] = $err_msg;
              }
              if ($values["mq_tracking_no"] != null)
              {
                $errors["mq_tracking_no"] = $err_msg;
              }

          } 

          if ($values["mq2"] == "Via_Mail") 
          {
              if ($values["mq3"] != null)
              {
                $errors["mq3"] = $err_msg;
              }
              if ($values["mq5"] != null)
              {
                $errors["mq5"] = $err_msg;
              }
              if ($values["mq4"] != null)
              {
                $errors["mq4"] = $err_msg;
              }

          }
        return $errors;
    }

    function validate_page4($values)
    {
      $err_msg = "Not required, please leave the field blank";
          $errors = array();
          if ($values["fq2"] == "At_Visit") 
          {
              if ($values["fq6"] != null)
              {
                $errors["fq6"] = $err_msg;
              }
              if ($values["fq_tracking_no"] != null)
              {
                $errors["fq_tracking_no"] = $err_msg;
              }

          } 

          if ($values["fq2"] == "Via_Mail") 
          {
              if ($values["fq3"] != null)
              {
                $errors["fq3"] = $err_msg;
              }
              if ($values["fq5"] != null)
              {
                $errors["fq5"] = $err_msg;
              }
              if ($values["fq4"] != null)
              {
                $errors["fq4"] = $err_msg;
              }

          }
        return $errors;
    }
    
}
