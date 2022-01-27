<?php
class NDB_BVL_Instrument_med_records_SA extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;




    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "med_records_SA";           // test_names.Test_name
        $this->table = 'med_records_SA';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;



        // setup the form
        $this->_setupForm();
    }


    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/med_records_SA(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {
        // display test name
        $this->form->addElement('header', 'instrument_title', "Medical Records Form -School Age");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addNumericElement('child_birth_length','Child Birth Length (cm)');
        $this->addNumericElement('child_birth_weight','Child Birth Weight (oz)');
        $this->addNumericElement('head_circum','Head Circumference (cm)');
        $this->form->addElement("static", null, "GESTATIONAL AGE");
        $this->addNumericElement("gest_age_weeks", $this->indent . "Weeks:");
        $this->addNumericElement("gest_age_months", $this->indent . "Days:");
        $this->form->addElement("static", null, "APGAR SCORES");
        $this->addNumericElement("apgar_1_minute", $this->indent . "at 1 minute:");
        $this->addNumericElement("apgar_5_minute", $this->indent . "at 5 minutes:");
	$this->form->addElement('select', "mode_of_delivery", "Mode of Delivery",
        array(
           null                   => "", 
           "vaginal"              => "Vaginal", 
           "vaginal_with_forceps" => "Vaginal with forceps",
	   "vaginal_with_vacuum"  => "Vaginal with vacuum",
           "c_section"            => "C-section",
           "nr"                   => "NR")
       );

    }
}
?>
