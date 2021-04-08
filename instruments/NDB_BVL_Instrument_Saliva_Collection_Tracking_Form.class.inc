<?php




class NDB_BVL_Instrument_Saliva_Collection_Tracking_Form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

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
    }

    function _main(){
               //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
        'language' => 'en',
        'format'   => 'YMd',
        'minYear'  => $config->getSetting('startYear'),
        'maxYear'  => $config->getSetting('endYear'),
        'addEmptyOption' => true,
        'emptyOptionValue' => null
        );

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

        // display test name
        $this->form->addElement('header', 'instrument_title', "Saliva Collection Tracking Form");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();


        $this->form->addElement('header', null, 'Subject');


        $options =
            array(
                ''      => '',
                'yes'   => "Yes",
                'no' => "No",
            );

               $this->form->addElement('static','sq_1',"1. Does the subject need saliva collected?");
               $this->form->addElement('select','sq1',$this->indent.'a:',$options);
                $this->form->addRule('sq1', 'This question is required', 'required');

               
               
               $this->form->addElement('static','sq_2',"2. [If no, question 1] Section Ends");

               $this->form->addElement('static','sq_3',"3. [If yes, question 1] Does the subject need to consent?");

               $this->form->addElement('select','sq3',$this->indent.'a:',$options);

               $this->XINRegisterRule('sq3', array("sq1{@}=={@}yes"), 'Required if yes, question 1');

                $this->form->addElement('static','sq_4',"4. [If no, question 3] Why does this subject not give consent?");


               $this->form->addElement('select','sq4',$this->indent.'a:', array('' => '','refused'=>"refused",'not_asked' => "not asked"));

                $this->form->addElement('static','sq_4b',$this->indent."b: Section ends after question 4");

            
               $this->XINRegisterRule('sq4', array("sq3{@}=={@}no"), 'Required if no, question 3');

                $this->form->addElement('static','sq_5',"5. [If yes, question 3] Date of Consent?");


               $this->form->addElement('date','sq5', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('sq5', array("sq3{@}=={@}yes"), 'Required if no, question 3');

             $this->form->addElement('static','sq_6',"6. [If yes, question 3] How will saliva be collected?");


               $this->form->addElement('select','sq6',$this->indent.'a:',  array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));
               
               $this->XINRegisterRule('sq6', array("sq3{@}=={@}yes"), 'Required if no, question 3');

                $this->form->addElement('static','sq_7',"7. [If at visit, question 6] Collection Date?");


               $this->form->addElement('date','sq7','a:', $this->dateOptions);

               $this->XINRegisterRule('sq7', array("sq6{@}=={@}At_Visit"), 'Required if at visit, question 6');



               $this->form->addElement('static','sq_8','8. [If at visit, question 6] Date mailed to UNC?');

               $this->form->addElement('date','sq8_1',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule('sq8_1', array("sq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement('text','sq8_2',$this->indent.'b: Tracking number');

                $this->XINRegisterRule('sq8_2', array("sq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement("advcheckbox", "sq8_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));

                $this->form->addElement('static','sq_9',"9. [If via mail, question 6] How will the family receive the kits?");

               $this->form->addElement("select", "sq9_1", $this->indent."a:",  array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

                $this->XINRegisterRule('sq9_1', array("sq6{@}=={@}Via_Mail"), 'Required if via mail, question 6');

               $this->form->addElement("advcheckbox", "sq9_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));

                $this->form->addElement('static','sq_10',"10. [If via mail, question 9]");
                
                 $this->form->addElement('text','sq10',$this->indent.'a: tracking number');

                $this->XINRegisterRule('sq10', array("sq6{@}=={@}Via_Mail"), 'Required if via mail, question 9');
                
                $this->form->addElement('static','sq_11',"11. [If yes, question 1] Did UNC staff deliver saliva tube to processing lab at UNC?");

               $this->form->addElement('select','sq11_1', $this->indent.'a:',$options);
                
                 $this->XINRegisterRule('sq11_1', array("sq1{@}=={@}yes"), 'Required if yes, question 1');

               $this->form->addElement('select', 'sq11_2', $this->indent.'b: Who delivered the tube?', $examiners);

                $this->XINRegisterRule('sq11_2', array("sq1{@}=={@}yes"), 'Required if yes, question 1');

                 $this->form->addElement('static','sq_12',"12.  What is the expiration date on the collection tube?");


               $this->form->addElement('date','sq12',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule("sq12", array("sq12{@}=={@}NEVER_REQUIRED"));


               $this->form->addElement("textarea", "sq13", "13. Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("sq13", array("sq13{@}=={@}NEVER_REQUIRED"));

    }

function _page1(){
        //Defines the call back function for HTML Quickform to use when validating the form.
      //  $this->form->addFormRule(array(&$this,'XINValidate'));
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
        'language' => 'en',
        'format'   => 'YMd',
        'minYear'  => $config->getSetting('startYear'),
        'maxYear'  => $config->getSetting('endYear'),
        'addEmptyOption' => true,
        'emptyOptionValue' => null
        );

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



            $this->form->addElement('header', null, 'Proband');


        $options =
            array(
                ''      => '',
                'yes'   => "Yes",
                'no' => "No",
            );

               $this->form->addElement('static','pq_1',"1. Does the proband need saliva collected?");
               $this->form->addElement('select','pq1',$this->indent.'a:',$options);
                $this->form->addRule('pq1', 'This question is required', 'required');

               
               
               $this->form->addElement('static','pq_2',"2. [If no, question 1] Section Ends");

               $this->form->addElement('static','pq_3',"3. [If yes, question 1] Does the proband need to consent?");

               $this->form->addElement('select','pq3',$this->indent.'a:',$options);

               $this->XINRegisterRule('pq3', array("pq1{@}=={@}yes"), 'Required if yes, question 1');



                $this->form->addElement('static','pq_4',"4. [If no, question 3] Why does this proband not give consent?");

               $this->form->addElement('select','pq4',$this->indent.'a:', array('' => '','refused'=>"refused",'not_asked' => "not asked"));

               $this->XINRegisterRule('pq4', array("pq3{@}=={@}no"), 'Required if no, question 3');

                $this->form->addElement('static','pq_4b',$this->indent."b: Section ends after question 4");
            


                $this->form->addElement('static','pq_5',"5. [If yes, question 3] Date of Consent?");

               $this->form->addElement('date','pq5', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('pq5', array("pq3{@}=={@}yes"), 'Required if yes, question 3');



             $this->form->addElement('static','pq_6',"6. Will the proband complete an additional collection tube?");

               $this->form->addElement('select','pq6',$this->indent.'a:', $options);



               
              $this->form->addElement('static','pq_7',"7. [yes, question 3] How will saliva be collected?");

               $this->form->addElement('select','pq7','a:', array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

                $this->XINRegisterRule('pq7', array("pq3{@}=={@}yes"), 'Required if yes, question 3');



                $this->form->addElement('static','pq_8',"8. [If at visit, question 7] Collection Date?");

               $this->form->addElement('date','pq8','a:', $this->dateOptions);

               $this->XINRegisterRule('pq8', array("pq7{@}=={@}At_Visit"), 'Required if at visit, question 7');



               $this->form->addElement('static','pq_9','9. [If at visit, question 7] Date mailed to UNC?');

               $this->form->addElement('date','pq9_1',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule('pq9_1', array("pq7{@}=={@}At_Visit"), 'Required if at visit, question 7');

               $this->form->addElement('text','pq9_2',$this->indent.'b: Tracking number');

                $this->XINRegisterRule('pq9_2', array("pq7{@}=={@}At_Visit"), 'Required if at visit, question 7');

               $this->form->addElement("advcheckbox", "pq9_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));



                $this->form->addElement('static','pq_10',"10. [If via mail, question 7] How will the family receive the kits?");

               $this->form->addElement("select", "pq10_1", $this->indent."a:",  array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

                $this->XINRegisterRule('pq10_1', array("pq7{@}=={@}Via_Mail"), 'Required if via mail, question 7');

               $this->form->addElement("advcheckbox", "pq10_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));



                $this->form->addElement('static','pq_11',"11. [If via mail, question 10]");
                
                 $this->form->addElement('text','pq11',$this->indent.'a: Display reminder to document tracking number internally');

                $this->XINRegisterRule('pq10', array("pq10_1{@}=={@}Via_Mail"), 'Required if via mail, question 9');
                


                $this->form->addElement('static','pq_12',"12. [If yes, question 1] Did UNC staff deliver saliva tube to processing lab at UNC?");

               $this->form->addElement('select','pq12_1', $this->indent.'a:',$options);
                
                 $this->XINRegisterRule('pq12_1', array("pq1{@}=={@}yes"), 'Required if yes, question 1');

               $this->form->addElement('select', 'pq12_2', $this->indent.'b: Who delivered the tube?', $examiners);

                $this->XINRegisterRule('pq12_2', array("pq1{@}=={@}yes"), 'Required if yes, question 1');



                 $this->form->addElement('static','pq_13',"13.  What is the expiration date on the collection tube?");


               $this->form->addElement('date','pq13',$this->indent.'a:', $this->dateOptions);
               $this->XINRegisterRule("pq13", array("pq13{@}=={@}NEVER_REQUIRED"));



               $this->form->addElement("textarea", "pq14", "14. Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("pq14", array("pq14{@}=={@}NEVER_REQUIRED"));
}

function _page2(){
    //Defines the call back function for HTML Quickform to use when validating the form.
    //    $this->form->addFormRule(array(&$this,'XINValidate'));
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
        'language' => 'en',
        'format'   => 'YMd',
        'minYear'  => $config->getSetting('startYear'),
        'maxYear'  => $config->getSetting('endYear'),
        'addEmptyOption' => true,
        'emptyOptionValue' => null
        );

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



            $this->form->addElement('header', null, 'Mother');


        $options =
            array(
                ''      => '',
                'yes'   => "Yes",
                'no' => "No",
            );

               $this->form->addElement('static','mq_1',"1. Does the mother need saliva collected?");
               $this->form->addElement('select','mq1',$this->indent.'a:',$options);
                $this->form->addRule('mq1', 'This question is required', 'required');

               
               
               $this->form->addElement('static','mq_2',"2. [If no, question 1] Section Ends");


               $this->form->addElement('static','mq_3',"3. [If yes, question 1] Does the mother need to consent?");

               $this->form->addElement('select','mq3',$this->indent.'a:',$options);

               $this->XINRegisterRule('mq3', array("mq1{@}=={@}yes"), 'Required if yes, question 1');



                $this->form->addElement('static','mq_4',"4. [If no, question 3] Why does this mother not give consent?");

               $this->form->addElement('select','mq4',$this->indent.'a:', array('' => '','refused'=>"refused",'not_asked' => "not asked"));

                $this->form->addElement('static','mq_4b',$this->indent."b: Section ends after question 4");
            
               $this->XINRegisterRule('mq4', array("mq3{@}=={@}no"), 'Required if no, question 3');




                $this->form->addElement('static','mq_5',"5. [If yes, question 3] Date of Consent?");

               $this->form->addElement('date','mq5', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('mq5', array("mq3{@}=={@}yes"), 'Required if yes, question 3');


               
              $this->form->addElement('static','mq_6',"6. [yes, question 3] How will saliva be collected?");

               $this->form->addElement('select','mq6','a:', array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

               $this->XINRegisterRule('mq6', array("mq3{@}=={@}yes"), 'Required if yes, question 3');



                $this->form->addElement('static','mq_7',"7. [If at visit, question 6] Collection Date?");

               $this->form->addElement('date','mq7','a:', $this->dateOptions);

               $this->XINRegisterRule('mq7', array("mq6{@}=={@}At_Visit"), 'Required if at visit, question 7');




               $this->form->addElement('static','mq_8','8. [If at visit, question 6] Date mailed to UNC?');

               $this->form->addElement('date','mq8_1',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule('mq8_1', array("mq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement('text','mq8_2',$this->indent.'b: Tracking number');

                $this->XINRegisterRule('mq8_2', array("mq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement("advcheckbox", "mq8_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));





                $this->form->addElement('static','mq_9',"9. [If via mail, question 6] How will the family receive the kits?");

               $this->form->addElement("select", "mq9_1", $this->indent."a:",  array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

                $this->XINRegisterRule('mq9_1', array("mq6{@}=={@}Via_Mail"), 'Required if via mail, question 6');

               $this->form->addElement("advcheckbox", "mq9_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));



                $this->form->addElement('static','mq_10',"10. [If via mail, question 9]");
                
                 $this->form->addElement('text','mq10',$this->indent.'a: Display reminder to document tracking number internally');

                $this->XINRegisterRule('mq10', array("mq9_1{@}=={@}Via_Mail"), 'Required if via mail, question 9');

                
                $this->form->addElement('static','mq_11',"11. [If yes, question 1] Did UNC staff deliver saliva tube to processing lab at UNC?");

               $this->form->addElement('select','mq11_1', $this->indent.'a:',$options);
                
                 $this->XINRegisterRule('mq11_1', array("mq1{@}=={@}yes"), 'Required if yes, question 1');

               $this->form->addElement('select', 'mq11_2', $this->indent.'b: Who delivered the tube?', $examiners);

                $this->XINRegisterRule('mq11_2', array("mq1{@}=={@}yes"), 'Required if yes, question 1');



                 $this->form->addElement('static','mq_12',"12.  What is the expiration date on the collection tube?");

               $this->form->addElement('date','mq12',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule("mq12", array("mq12{@}=={@}NEVER_REQUIRED"));



               $this->form->addElement("textarea", "mq13", "13. Comments:", array('cols'=>25, 'rows'=>4));

                $this->XINRegisterRule("mq13", array("mq13{@}=={@}NEVER_REQUIRED"));
}

function _page3(){     
     //Defines the call back function for HTML Quickform to use when validating the form.
    //    $this->form->addFormRule(array(&$this,'XINValidate'));
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
        'language' => 'en',
        'format'   => 'YMd',
        'minYear'  => $config->getSetting('startYear'),
        'maxYear'  => $config->getSetting('endYear'),
        'addEmptyOption' => true,
        'emptyOptionValue' => null
        );

        $examiners = $this->_getExaminerNames();

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));



            $this->form->addElement('header', null, 'Father');


        $options =
            array(
                ''      => '',
                'yes'   => "Yes",
                'no' => "No",
            );

               $this->form->addElement('static','fq_1',"1. Does the father need saliva collected?");
               $this->form->addElement('select','fq1',$this->indent.'a:',$options);
                $this->form->addRule('fq1', 'This question is required', 'required');

               
               
               $this->form->addElement('static','fq_2',"2. [If no, question 1] Section Ends");


               $this->form->addElement('static','fq_3',"3. [If yes, question 1] Does the father need to consent?");

               $this->form->addElement('select','fq3',$this->indent.'a:',$options);

               $this->XINRegisterRule('fq3', array("fq1{@}=={@}yes"), 'Required if yes, question 1');



                $this->form->addElement('static','fq_4',"4. [If no, question 3] Why does this father not give consent?");

               $this->form->addElement('select','fq4',$this->indent.'a:', array('' => '','refused'=>"refused",'not_asked' => "not asked"));

                $this->form->addElement('static','fq_4b',$this->indent."b: Section ends after question 4");
            
               $this->XINRegisterRule('fq4', array("fq3{@}=={@}no"), 'Required if no, question 3');




                $this->form->addElement('static','fq_5',"5. [If yes, question 3] Date of Consent?");

               $this->form->addElement('date','fq5', $this->indent.'a:', $this->dateOptions);
               
               $this->XINRegisterRule('fq5', array("fq3{@}=={@}yes"), 'Required if yes, question 3');


               
              $this->form->addElement('static','fq_6',"6. [yes, question 3] How will saliva be collected?");

               $this->form->addElement('select','fq6','a:', array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

               $this->XINRegisterRule('fq6', array("fq3{@}=={@}yes"), 'Required if yes, question 3');



                $this->form->addElement('static','fq_7',"7. [If at visit, question 6] Collection Date?");

               $this->form->addElement('date','fq7','a:', $this->dateOptions);

               $this->XINRegisterRule('fq7', array("fq6{@}=={@}At_Visit"), 'Required if at visit, question 7');




               $this->form->addElement('static','fq_8','8. [If at visit, question 6] Date mailed to UNC?');

               $this->form->addElement('date','fq8_1',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule('fq8_1', array("fq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement('text','fq8_2',$this->indent.'b: Tracking number');

                $this->XINRegisterRule('fq8_2', array("fq6{@}=={@}At_Visit"), 'Required if at visit, question 6');

               $this->form->addElement("advcheckbox", "fq8_3", $this->indent."c: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));





                $this->form->addElement('static','fq_9',"9. [If via mail, question 6] How will the family receive the kits?");

               $this->form->addElement("select", "fq9_1", $this->indent."a:",  array('' => '','At_Visit'=>"At Visit",'Via_Mail' => "Via Mail"));

                $this->XINRegisterRule('fq9_1', array("fq6{@}=={@}Via_Mail"), 'Required if via mail, question 6');

               $this->form->addElement("advcheckbox", "fq9_2", $this->indent."b: Triggers email to UNC saying a kit should be expected", null, null, array("false", "true"));



                $this->form->addElement('static','fq_10',"10. [If via mail, question 9]");
                
                 $this->form->addElement('text','fq10',$this->indent.'a: Display reminder to document tracking number internally');

                $this->XINRegisterRule('fq10', array("fq9_1{@}=={@}Via_Mail"), 'Required if via mail, question 9');

                
                $this->form->addElement('static','fq_11',"11. [If yes, question 1] Did UNC staff deliver saliva tube to processing lab at UNC?");

               $this->form->addElement('select','fq11_1', $this->indent.'a:',$options);
                
                 $this->XINRegisterRule('fq11_1', array("fq1{@}=={@}yes"), 'Required if yes, question 1');

               $this->form->addElement('select', 'fq11_2', $this->indent.'b: Who delivered the tube?', $examiners);

                $this->XINRegisterRule('fq11_2', array("fq1{@}=={@}yes"), 'Required if yes, question 1');



                 $this->form->addElement('static','fq_12',"12.  What is the expiration date on the collection tube?");

               $this->form->addElement('date','fq12',$this->indent.'a:', $this->dateOptions);

               $this->XINRegisterRule("fq12", array("fq12{@}=={@}NEVER_REQUIRED"));



               $this->form->addElement("textarea", "fq13", "13. Comments:", array('cols'=>25, 'rows'=>4));

                $this->XINRegisterRule("fq13", array("fq13{@}=={@}NEVER_REQUIRED"));




               $this->form->addElement('header', null, 'Additional Siblings and Family ID');

               $this->form->addElement('select','aq1','1. Does the subject need saliva collected?',array('' => '','yes'=>"Yes",'no' => "No","investigate"=>"Need to Investigate"));

               $this->form->addRule('aq1', 'This question is required', 'required');

               $this->form->addElement('text','aq2','Tracking number:');

               $this->form->addRule('aq2', 'The tracking number is required', 'required');
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


        // deprecated // $this->form->registerRule('checkdate', 'callback', '_checkDate');
        // not needed // $this->form->addRule('Date_taken', 'Date of Administration is invalid', 'checkdate');

        $this->form->addRule('Examiner', 'Examiner is required', 'required');

    }
}
?>
