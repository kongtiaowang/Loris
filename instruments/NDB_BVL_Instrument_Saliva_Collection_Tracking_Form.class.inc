<?php


class NDB_BVL_Instrument_Saliva_Collection_Tracking_Form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled = false;
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
                                'Via_Mail' => "Via Mail"
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

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

        // display test name


    }

function _page1(){

        $this->form->addElement('header', null, 'Subject');

               $this->form->addElement('static','sq_1',"1. Does the subject need saliva collected?");
               $this->form->addElement('select','sq1','',self::YES_NO_DONT_KNOW);
               $this->form->addRule('sq1', 'This question is required', 'required');

               $this->addLabel("<i>If choose No , please skip all other questions.</i>");

               $this->form->addElement('static','sq_2',"2. How will saliva be collected?");
// tod sql
               $this->form->addElement('select','sq2','',self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('sq2', array("sq1{@}=={@}yes"), 'Required if yes, question 1');



            $this->form->addGroup($group, 'subject_header1', "At Visit", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");





               $this->form->addElement('static','sq_3',"3. Collection Date?");

               $this->form->addElement('date','sq3',$this->indent.'a:', $this->dateOptions);
 
               $this->XINRegisterRule('sq3', array("sq2{@}=={@}At_Visit"), 'Required if At Visit, question 2');


                $this->form->addElement('static','sq_4',"4. Date of Consent?");


               $this->form->addElement('date','sq4_1', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('sq4_1', array("sq2{@}=={@}At_Visit"), 'Required if At Visit, question 2');

               $this->form->addElement('text','sq4_2',$this->indent.'b: Tracking number');

               $this->XINRegisterRule('sq4_2', array("sq2{@}=={@}At_Visit"), 'Required if At Visit, question 2');

               $this->form->addElement("advcheckbox", "sq4_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));

                $this->XINRegisterRule("sq4_3", array("sq4_3{@}=={@}NEVER_REQUIRED"));


 

              $group[] = $this->form->createElement('static', "", null, null);
              $this->form->addGroup($group, 'mail_header_group_', "By Mail", $this->_GUIDelimiter, FALSE);
               unset($group);
               $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");

            



              $this->form->addElement('static','sq_5',"5. How will the family receive the kits?");


               $this->form->addElement('select','sq5_1',$this->indent.'a:', self::VISIT_MAIL_OPTIONS);
               
               $this->XINRegisterRule('sq5_1', array("sq2{@}=={@}Via_Mail"), 'Required if at visit, question 2');


               $this->form->addElement("advcheckbox", "sq5_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));


               $this->form->addElement('static','sq_6',"6. Display reminder to document tracking number internally");
               $this->form->addElement('text','sq6','');

               $this->XINRegisterRule('sq6', array("sq2{@}=={@}Via_Mail"), 'Required if at visit, question 2');



               $this->form->addElement('static','sq_7','7. Did UNC staff deliver saliva tube to processing lab at UNC?');

               $this->form->addElement('select','sq7_1',$this->indent.'a:', self::YES_NO_OPTIONS);

               $this->XINRegisterRule('sq7_1', array("sq2{@}=={@}Via_Mail"), 'Required if Via_Mail, question 2');

               $this->form->addElement('text','sq7_2',$this->indent.'b: Who delivered the tube? ');

                $this->XINRegisterRule('sq7_2', array("sq2{@}=={@}Via_Mail"), 'Required if Via_Mail, question 2');
                
                

                $this->form->addElement('static','sq_8',"8. What is the expiration date on the collection tube?");

                $this->form->addElement("date", "sq8", $this->indent."a:", $this->dateOptions);

                $this->XINRegisterRule('sq8', array("sq2{@}=={@}Via_Mail"), 'Required if Via_Mail, question 2');


                $group[] = $this->form->createElement('static', "subject_comments", null, null);
                $this->form->addGroup($group, 'subject_comments_header_group', "Comment", $this->_GUIDelimiter, FALSE);
                unset($group);

                $this->form->addElement("textarea", "sq9", "9. Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("sq9", array("sq9{@}=={@}NEVER_REQUIRED"));

}

function _page2(){

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



            $this->form->addElement('header', null, 'Proband');



               $this->form->addElement('static','pq_1',"1. Does the proband need saliva collected?");
               $this->form->addElement('select','pq1','',self::YES_NO_DONT_KNOW);
               $this->form->addRule('pq1', 'This question is required', 'required');

               $this->addLabel("<i>If choose No , please skip all other questions.</i>");

               
               

              $this->form->addElement('static','pq_2',"2.  Does the proband need to sign an assent or consent form?");

              $this->form->addElement('select','pq2','',self::YES_NO_DONT_KNOW);

               $this->XINRegisterRule('pq2', array("pq1{@}=={@}yes"), 'Required if yes, question 1');







                $this->form->addElement('static','pq_3',"3. Why does this proband not give consent?");

               $this->form->addElement('select','pq3',$this->indent.'a:', array('' => '','refused'=>"refused",'not_asked' => "not asked"));

               $this->XINRegisterRule('pq3', array("pq2{@}=={@}no"), 'Required if no, question 2');

                $this->form->addElement('static','pq_3b',$this->indent."b: Section ends after question 3");
            


                $this->form->addElement('static','pq_4',"4. Date of Consent?");

               $this->form->addElement('date','pq4', '', $this->dateOptions);
               
               $this->XINRegisterRule('pq4', array("pq2{@}=={@}yes"), 'Required if yes, question 2');



             $this->form->addElement('static','pq_5',"5. Will the proband complete an additional collection tube?");

               $this->form->addElement('select','pq5','', self::YES_NO_OPTIONS);

               
              $this->form->addElement('static','pq_6',"6. How will saliva be collected?");

               $this->form->addElement('select','pq6','', self::VISIT_MAIL_OPTIONS);

                $this->XINRegisterRule('pq6', array("pq2{@}=={@}yes"), 'Required if yes, question 2');


            $this->form->addGroup($group, 'proband_header1', "At Visit", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");


                $this->form->addElement('static','pq_7',"7.Collection Date?");

               $this->form->addElement('date','pq7','', $this->dateOptions);

               $this->XINRegisterRule('pq7', array("pq6{@}=={@}At_Visit"), 'Required if at visit, question 6');





               $this->form->addElement('static','pq_8','8. Date mailed to UNC?');

               $this->form->addElement('date','pq8_1',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule('pq8_1', array("pq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement('text','pq8_2',$this->indent.'b: Tracking number');

                $this->XINRegisterRule('pq8_2', array("pq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement("advcheckbox", "pq8_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));




            $this->form->addGroup($group, 'proband_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
            unset($group);
            $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");




                $this->form->addElement('static','pq_9',"9. How will the family receive the kits?");

               $this->form->addElement("select", "pq9_1", $this->indent."a:",  self::VISIT_MAIL_OPTIONS);

                $this->XINRegisterRule('pq9_1', array("pq6{@}=={@}Via_Mail"), 'Required if via mail, question 6');

               $this->form->addElement("advcheckbox", "pq9_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));



                $this->form->addElement('static','pq_10',"10. Display reminder to document tracking number internally");
                
                 $this->form->addElement('text','pq10','');

                $this->XINRegisterRule('pq10', array("pq9_1{@}=={@}Via_Mail"), 'Required if via mail, question 9');
                


                $this->form->addElement('static','pq_11',"11. Did UNC staff deliver saliva tube to processing lab at UNC?");

               $this->form->addElement('select','pq11_1', $this->indent.'a:',self::YES_NO_OPTIONS);
                
                 $this->XINRegisterRule('pq11_1', array("pq1{@}=={@}yes"), 'Required if yes, question 1');

               $this->form->addElement('text', 'pq11_2', $this->indent.'b: Who delivered the tube?');

                $this->XINRegisterRule('pq11_2', array("pq1{@}=={@}yes"), 'Required if yes, question 1');



                 $this->form->addElement('static','pq_12',"12.  What is the expiration date on the collection tube?");


               $this->form->addElement('date','pq12','', $this->dateOptions);
               $this->XINRegisterRule("pq12", array("pq12{@}=={@}NEVER_REQUIRED"));



               $this->form->addElement("textarea", "pq13", "13. Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("pq13", array("pq13{@}=={@}NEVER_REQUIRED"));

}

function _page3(){

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



            $this->form->addElement('header', null, 'Mother');



               $this->form->addElement('static','mq_1',"1. Does the subject need saliva collected?");
               $this->form->addElement('select','mq1','',self::YES_NO_DONT_KNOW);
               $this->form->addRule('mq1', 'This question is required', 'required');

               
               
               $this->form->addElement('static','mq_2',"2. How will saliva be collected?");

               $this->form->addElement('select','mq2','', self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('mq2', array("mq1{@}=={@}yes"), 'Required if yes, question 1');


              $this->form->addGroup($group, 'mother_header1', "At Visit", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");



               $this->form->addElement('static','mq_3',"3. Collection Date?");

               $this->form->addElement('date','mq3','', $this->dateOptions);

              $this->XINRegisterRule('mq3', array("mq2{@}=={@}At_Visit"), 'Required if at visit, question 2');



               $this->form->addElement('static','mq_4','Date mailed to UNC?');

               $this->form->addElement('date','mq4_1', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('mq4_1', array("mq2{@}=={@}At_Visit"), 'Required if at visit, question 2');

               $this->form->addElement('text','mq4_2',$this->indent.'b: Tracking number');

               $this->XINRegisterRule('mq4_2', array("mq2{@}=={@}At_Visit"), 'Required if at visit, question 2');

               $this->form->addElement("advcheckbox", "mq4_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));

                $this->XINRegisterRule("mq4_3", array("mq4_3{@}=={@}NEVER_REQUIRED"));



              $this->form->addGroup($group, 'mother_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");




             $this->form->addElement('static','mq_5',"5. How will the family receive the kits?");


               $this->form->addElement('select','mq5_1',$this->indent.'a:', self::VISIT_MAIL_OPTIONS);
               
               $this->XINRegisterRule('mq5_1', array("mq2{@}=={@}Via_Mail"), 'Required if via mail, question 3');

             //  NOTIFICATION: Triggers email to UNC saying a kit should be expected

               $this->form->addElement("advcheckbox", "mq5_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));


               $this->form->addElement('static','mq_6',"6. Display reminder to document tracking number internally");
               $this->form->addElement('text','mq6','');

               $this->XINRegisterRule('mq6', array("mq2{@}=={@}Via_Mail"), 'Required if via mail, question 3');

               $this->form->addElement('static','mq_7','7. Did UNC staff deliver saliva tube to processing lab at UNC?');

               $this->form->addElement('select','mq7_1',$this->indent.'a:', self::YES_NO_OPTIONS);

               $this->XINRegisterRule('mq7_1', array("mq1{@}=={@}yes"), 'Required if Yes, question 1');

               $this->form->addElement('text','mq7_2',$this->indent.'b: Who delivered the tube? ');

                $this->XINRegisterRule('mq7_2', array("mq1{@}=={@}yes"), 'Required if Yes, question 1');



                $this->form->addElement('static','mq_8',"8. What is the expiration date on the collection tube?");

                $this->form->addElement("date", "mq8", '', $this->dateOptions);

                $this->form->addElement("textarea", "mq9", "9. Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("mq9", array("mq9{@}=={@}NEVER_REQUIRED"));

}

function _page4(){     

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



            $this->form->addElement('header', null, 'Father');


               $this->form->addElement('static','fq_1',"1. Does the subject need saliva collected?");
               $this->form->addElement('select','fq1','',self::YES_NO_DONT_KNOW);
               $this->form->addRule('fq1', 'This question is required', 'required');

               
               
               $this->form->addElement('static','fq_2',"2. How will saliva be collected?");

               $this->form->addElement('select','fq2','', self::VISIT_MAIL_OPTIONS);

               $this->XINRegisterRule('fq2', array("fq1{@}=={@}yes"), 'Required if yes, question 1');


              $this->form->addGroup($group, 'mother_header1', "At Visit", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'At Visit' the questions below are required</i>");



               $this->form->addElement('static','fq_3',"3. Collection Date?");

               $this->form->addElement('date','fq3','', $this->dateOptions);

              $this->XINRegisterRule('fq3', array("fq2{@}=={@}At_Visit"), 'Required if at visit, question 2');



               $this->form->addElement('static','fq_4','Date mailed to UNC?');

               $this->form->addElement('date','fq4_1', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('fq4_1', array("fq2{@}=={@}At_Visit"), 'Required if at visit, question 2');

               $this->form->addElement('text','fq4_2',$this->indent.'b: Tracking number');

               $this->XINRegisterRule('fq4_2', array("fq2{@}=={@}At_Visit"), 'Required if at visit, question 2');

               $this->form->addElement("advcheckbox", "fq4_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));

                $this->XINRegisterRule("fq4_3", array("fq4_3{@}=={@}NEVER_REQUIRED"));



              $this->form->addGroup($group, 'mother_header2', "Via Mail", $this->_GUIDelimiter, FALSE);
              unset($group);
              $this->addLabel("<i>If Saliva collection is 'Via Mail' the questions below are required</i>");




             $this->form->addElement('static','fq_5',"5. How will the family receive the kits?");


               $this->form->addElement('select','fq5_1',$this->indent.'a:', self::VISIT_MAIL_OPTIONS);
               
               $this->XINRegisterRule('fq5_1', array("fq2{@}=={@}Via_Mail"), 'Required if via mail, question 3');

             //  NOTIFICATION: Triggers email to UNC saying a kit should be expected

               $this->form->addElement("advcheckbox", "fq5_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));


               $this->form->addElement('static','fq_6',"6. Display reminder to document tracking number internally");
               $this->form->addElement('text','fq6','');

               $this->XINRegisterRule('fq6', array("fq2{@}=={@}Via_Mail"), 'Required if via mail, question 3');

               $this->form->addElement('static','fq_7','7. Did UNC staff deliver saliva tube to processing lab at UNC?');

               $this->form->addElement('select','fq7_1',$this->indent.'a:', self::YES_NO_OPTIONS);

               $this->XINRegisterRule('fq7_1', array("fq1{@}=={@}yes"), 'Required if Yes, question 1');

               $this->form->addElement('text','fq7_2',$this->indent.'b: Who delivered the tube? ');

                $this->XINRegisterRule('fq7_2', array("fq1{@}=={@}yes"), 'Required if Yes, question 1');



                $this->form->addElement('static','fq_8',"8. What is the expiration date on the collection tube?");

                $this->form->addElement("date", "fq8", '', $this->dateOptions);

                $this->form->addElement("textarea", "fq9", "9. Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("fq9", array("fq9{@}=={@}NEVER_REQUIRED"));




               $this->form->addElement('header', null, 'Additional Siblings and Family ID');

               $this->form->addElement('select','aq1','1. Does the subject need saliva collected?',array('' => '','yes'=>"Yes",'no' => "No","investigate"=>"Need to Investigate"));

               $this->form->addRule('aq1', 'This question is required', 'required');


               $this->form->addElement('text','aq2','2. Tracking number:');

               $this->form->addRule('aq2', 'The tracking number is required', 'required');

               $this->form->addFormRule(array(&$this, 'validate_tracking_number'));


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

        $this->form->addElement('date', 'Date_taken', 'Date of Administration', $this->dateOptions);

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
        $this->validate_positive_numeric($values, "aq2", $errors);
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

    
}


