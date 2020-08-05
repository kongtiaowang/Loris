<?php


class NDB_BVL_Instrument_head_measurements extends NDB_BVL_Instrument
{
    public function getFullName(): string
    {
        return '';
    }

    function getSubtestList(): array {
        return [];
    }

/*
INSERT INTO test_names VALUES ('', 'head_measurements', 'Measurements Data Sheet', '0', '1');
INSERT INTO test_battery VALUES ('', 'head_measurements', '1050', '1140', 'Y', 'Visit', '3');
*/
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
        
        // data keyed by commentID
        $this->commentID = $commentID;
        
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");
            
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner');

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
        if(preg_match("/head_measurements (_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
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
        $this->form->addElement('header', 'instrument_title', "Measurements Data Sheet");
        
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        
        $this->form->addElement('header', null, 'Head Measurements');
        $this->form->addElement('select', 'head_circumference_unit', 'Unit for head circumference', array('cm' => 'centimeters', "inches" => "inches", "not_answered" => "Not Answered"));
        $this->addNumericElement('head_circumference1', "Circumference 1:");
        $this->addNumericElement('head_circumference2', "Circumference 2:");

        $this->form->addElement('header', null, 'Length');
        $this->form->addElement('select', 'head_length_unit', 'Unit for length', array('cm' => 'centimeters', "inches" => "inches", "not_answered" => "Not Answered"));
        $this->addNumericElement('length1', "Length 1:");
        $this->addNumericElement('length2', "Length 2:");
        $this->form->addElement('select', 'measurement_method', $this->indent . "Child was measured:", array(""=>NULL, "lying_down"=>"Lying down", "standing_up"=>"Standing up", "not_answered"=>"Not Answered"));

        $this->form->addElement('header', null, 'Weight');
        $this->form->addElement('select', 'weight_unit', 'Unit for weight', array('kg' => 'kilograms', "lbs" => "pounds", "not_answered" => "Not Answered"));
        $this->addNumericElement('weight1', "Weight 1:");
        $this->addNumericElement('weight2', "Weight 2:");
        
    }
   
}
?>
