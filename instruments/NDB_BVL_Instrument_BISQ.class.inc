<?php
/*
 * This file contains the NDB_BVL_Instrument_BISQ
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the BISQ instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BISQ extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

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
        $this->form = new LorisForm('BISQ_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "BISQ";           // test_names.Test_name
        $this->table = 'BISQ';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array("sleep_opts");
        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');
        // setup the form
        $this->_setupForm();
    }

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        $this->_main();

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
        $this->addHeader("Brief Infant Sleep Questionnaire (BISQ)");
        $this->_addMetadataFields();
        $opts = array(
            null => "",
            "mother" => "Mother",
            "father" => "Father",
            "step_mother" => "Step Mother",
            "step_father" => "Step Father",
            "other" => "Other",
        );
        $this->addSelect("responder", "Role of the Responder:", $opts);
        $this->addBasicText("other_responder", $this->indent . "If Other, please specify:");
        $this->XINRegisterRule(
            "other_responder",
            array("responder{@}=={@}other"),
            "Required",
            "other_responder"
        );
        $opts1 = array(
            null => "",
            "oldest" => "Oldest",
            "middle" => "Middle",
            "youngest" => "Youngest",
            "step_father" => "Not Answered",

        );
        $this->addSelect("birth_order", "Birth order of the child:", $opts1);
        $where_opts = array(
            null => "",
            "infant_crib_seperate_room" => "Infant crib in a separate room",
            "infant_crib_parent_room" => "Infant crib in parents’ room",
            "parents_bed" => "In parents’ bed",
            "infant_crib_in_room_with_sibling" => "Infant crib in room with sibling",
            "other" => "Other",
        );
        $this->addSelect("sleeping_arrangement", "Sleeping arrangement:", $where_opts);
        $this->addBasicText("other_sleeping_arrangement", $this->indent . "If Other, please specify:");
        $this->XINRegisterRule(
            "other_sleeping_arrangement",
            array("sleeping_arrangement{@}=={@}other"),
            "Required",
            "other_sleeping_arrangement"
        );
        $pos_opts = array(
            null => "",
            "belly" => "On his/her belly ",
            "side" => "On his/her side",
            "back" => "On his/her back",
            "not_answered" => "Not Answered",
        );
        $this->addSelect("sleep_position", "In what position does your child sleep most of the time?", $pos_opts);
        $this->addHourMinElement("night_sleep", "How much time does your child spend in sleep during the NIGHT (between 7 in the evening and 7 in the morning)? ");
        $this->addHourMinElement("day_sleep", "How much time does your child spend in sleep during the DAY (between 7 in the morning and 7 in the evening)?");
        $this->addTextElement("night_wakes_average_count","Average number of night wakings per night:");
        $this->addHourMinElement("night_wakefullness", "How much time during the night does your child spend in wakefulness (from 10 in the evening to 6 in the morning)? ");
        $this->addHourMinElement("time_to_put_to_sleep", "How long does it take to put your baby to sleep in the evening? ");
        $sleep_opts = array(
            null => "",
            "while_feeding" => "While feeding ",
            "being_rocked" => "Being rocked",
            "bed_alone" => "In bed alone",
            "bed_near_parent" => "In bed near parent",
            "not_answered" => "Not Answered",
        );
        $this->addSelect("sleep_opts", " How does your baby fall asleep?", $sleep_opts,["multiple"]);
        $this->addHourMinElement("when_fall_asleep", "When does your baby usually fall asleep for the night: ");
        $sleep_prob_opts = array(
         null => "",
         "belly" => " A very serious problem ",
         "side" => "A small problem",
         "back" => "Not a problem at all",
         "not_answered" => "Not Answered"
        );
        $this->addSelect("is_sleep_problem", " Do you consider your child’s sleep as a problem?", $sleep_prob_opts);

    }
}
