<?php
/*
 * This file contains the NDB_BVL_Instrument_mQST_form
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the mQST_form instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_mQST extends NDB_BVL_Instrument
{
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
    function setup($commentID = NULL, $page= NULL){

        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "mQST";           // test_names.Test_name
        $this->table = 'mQST';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;


        // setup the form
        $this->_setupForm();
    }

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/mQST(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }


    function _main()
    {
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();



        $this->form->addElement('header', null, '<u>mQST Tracking Sheet</u>');
        $this->form->addElement('select',"protocol_reqr", "(1)Select One (Protocol Acquirement):",
            array("" => NULL,'complete_protocol'=>'Complete protocol acquired', 'partial_completed'=>'Only partial protocol completed',
                'no_protocol_completed' => 'No protocol completed','not_answered' => 'Not Answered'));
        $this->form->addElement('select',"video_reqr", "(2)Select One (Video Acquirement):",
            array("" => NULL,'2_angle_completed' => '2 angles of video were successfully acquired', '1_angle_completed' => '1 angle of video was successfully acquired',
                'no_video' => 'No video was acquired','not_answered' => 'Not Answered'));
        for ($i = 0; $i <=6; $i++) {
            $header_array = array("(0) Sham: Closed Purple Von Frey Fiber -1 trial for 5s", "(1) Purple Von Frey Fiber (2.0g) – 1 trial, 5 applications",
                "(2) Red Pin Prick – 1 trial, count for 5s", "(3) Cold Stimulus [l7] : 1 trial for 5s seconds", "(4) Pressure Assay: 1 trial of 4lbs for 5sec",
                "(5) Red Von Frey Fiber (60g): 1 trial, 30 applications", "(6) Heat Thermode at 50C : 1 trial for 5s seconds");

            $this->form->addElement('header', null, $header_array[$i]);
            $this->form->addElement('static', null, '<u>Trial['.$i.']</u>');
            $this->form->addElement('select', 'attempted_' . $i, "Attempted:", array("" => NULL, 'Y' => 'Yes', 'N' => 'No', 'not_answered' => 'Not Answered'));
            $this->form->addElement('select', 'terminated_' . $i, "Terminated:", array("" => NULL, 'Y' => 'Yes', 'N' => 'No', 'not_answered' => 'Not Answered'));
            $this->addTextAreaElement('participant_response_' . $i, 'Participant’s response to task:');
            $this->form->addElement('static', null, '<br>');
        }
        $this->form->addElement('select', 'parent_presence', "Was parent in the room [l8] ?:", array("" => NULL, 'Y' => 'Yes', 'N' => 'No', 'not_answered' => 'Not Answered'));
            $this->addTextAreaElement('general_comments', 'General Comments/Notes:');



    }


}
?>
