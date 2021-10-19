<?php
/*
 * This file contains the NDB_BVL_Instrument_Eye_Tracking_Heart_Rate
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   moshood.abiola@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the Eye Tracking/Heart Rate Data Collection Checklist
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   moshood.abiola@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Eye_Tracking_Heart_Rate extends NDB_BVL_Instrument
{
	use LegacyInstrumentTrait;
	use instrument_validator;

    var $lights = array(
                null                 =>  "",
                "on"                 =>  "On",
                "off"                =>  "Off",
                "dim"                =>  "Dim",
                "mix_of_off_and_on"  =>  "Mix of Off and On",
                "data_not_recorded"  =>  "Data Not Recorded"
    );

    var $child_with = array(
                null                  =>  "",
                "mother"              =>  "Mother",
                "father"              =>  "Father",
                "ra"                  =>  "RA",
                "bca"                 =>  "BCA",
                "other"               =>  "Other",
                "data_not_recorded"   => "Data Not Recorded"
    );

    var  $options = array(
                null                 =>  "",
                "yes"                =>  "Yes",
                "no"                 =>  "No",
                "data_not_recorded"  =>  "Data Not Recorded"
    );

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
        $this->form = new LorisForm('Eye_Tracking_Heart_Rate');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "Eye_Tracking_Heart_Rate";           // test_names.Test_name
        $this->table = 'Eye_Tracking_Heart_Rate';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();
        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');
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
        //determine page to display
        if (preg_match(
            "/Eye_Tracking_Heart_Rate(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
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

	$this->addHeader("Eye Tracking/Heart Rate Data Collection Checklist");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        // display test name
        $this->form->addElement("static", null, "<h3><b>Instructions:</b> Keep lights on, no pacifier, 
                                 no milk/toys/water, ensure parents are comfortable in seat, infrared
                                  glasses on parent, heart rate monitor placement (sock over it).</h3>");
    
    $this->addTextElement("start_time", "Start time (24h format, HH:MM, e.g. 13:00):");

    $this->addTextElement("end_time", "End time (24h format, HH:MM, e.g. 13:00):");

    $group[] = $this->createText("q1_room_temperature");
    $group[] = $this->createSelect("q1_room_temperature_status", null ,array(null => "","data_not_recorded"  => "Data Not Recorded"));
    $this->addGroup($group, "room_temperature_group", "1. Room Temperature (Fahrenheit):" , $this->_GUIDelimiter, false );
    unset($group);
    $this->XINRegisterRule("q1_room_temperature", array("q1_room_temperature_status{@}=={@}"),"A Data, or DATA NOT RECORDED is required.", "room_temperature_group");

    $this->addSelect("q2_lights", "2. Lights: ", $this->lights);

    $this->addSelect("q3_who_is_child_with", "3. Who is the Child Sitting With? ", $this->child_with);

    $this->addTextElement("q4_task_version","4. Task Version:");

    $this->addSelect("q5_issues_with_child_comfort", "5. Issues With Child Comfort/Cooperation with eye tracking? ", $this->options);
    $this->form->addElement('text', 'q5_issues_specify', $this->indent . 'If Yes, specify:');
    $this->XINRegisterRule('q5_issues_specify', array('q5_issues_with_child_comfort{@}=={@}yes'), 'Required if yes');

    $this->addSelect("q6_issues_with_parent_comfort", "6. Issues With Parent Comfort/Cooperation with Eye Tracking? ", $this->options);
    $this->form->addElement('text', 'q6_issues_specify', $this->indent .  'If Yes, specify:');
    $this->XINRegisterRule('q6_issues_specify', array('q6_issues_with_parent_comfort{@}=={@}yes'), 'Required if yes');

    $this->addSelect("q7_eye_tracking_alert", "7. Eye Tracking Alert (has anything happened that would potentially invalidate the data gathered): ", $this->options);
    $this->form->addElement('text', 'q7_issues_specify', $this->indent . 'If Yes, specify:');
    $this->XINRegisterRule('q7_issues_specify', array('q7_eye_tracking_alert{@}=={@}yes'), 'Required if yes');

    $this->form->addElement("static", null, "<h3>Heart Rate Monitor</h3>");

    $this->addSelect("q8_cooperation_with_the_heart_monitor", "8. Issues With Child Comfort/Cooperation with the heart monitor? ", $this->options);
    $this->form->addElement('text', 'q8_issues_specify', $this->indent . 'If Yes, specify:');
    $this->XINRegisterRule('q8_issues_specify', array('q8_cooperation_with_the_heart_monitor{@}=={@}yes'), 'Required if yes');

    $this->addSelect("q9_cooperation_with_the_heart_monitor", "9. Issues With Parent Comfort/Cooperation with the heart monitor? ", $this->options);
    $this->form->addElement('text', 'q9_issues_specify', $this->indent . 'If Yes, specify:');
    $this->XINRegisterRule('q9_issues_specify', array('q9_cooperation_with_the_heart_monitor{@}=={@}yes'), 'Required if yes');

    $this->addSelect("q10_heart_rate_alert", "10. Heart Rate Alert (has anything happened that would potentially invalidate the data gathered): ", $this->options);
    $this->form->addElement('text', 'q10_issues_specify', $this->indent . 'If Yes, specify:');
    $this->XINRegisterRule('q10_issues_specify', array('q10_heart_rate_alert{@}=={@}yes'), 'Required if yes');

    $this->addTextAreaElement("q11_comments","Comments:");

    $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    function validate_main_page($values)
    {

	    $errors = [];
            if ($values["q5_issues_with_child_comfort"] != 'yes'){
                $this->validate_empty_subquestions($values, ["q5_issues_specify"], $errors);
            }
            if ($values["q6_issues_with_parent_comfort"] != 'yes'){
                $this->validate_empty_subquestions($values, ["q6_issues_specify"], $errors);
            }
            if ($values["q7_eye_tracking_alert"] != 'yes'){
                $this->validate_empty_subquestions($values, ["q7_issues_specify"], $errors);
            }
            if ($values["q8_cooperation_with_the_heart_monitor"] != 'yes'){
                $this->validate_empty_subquestions($values, ["q8_issues_specify"], $errors);
            }
            if ($values["q9_cooperation_with_the_heart_monitor"] != 'yes'){
                $this->validate_empty_subquestions($values, ["q9_issues_specify"], $errors);
            }
            if ($values["q10_heart_rate_alert"] != 'yes'){
                $this->validate_empty_subquestions($values, ["q10_issues_specify"], $errors);
            }
          
	    return $errors;
    }

}

?>
