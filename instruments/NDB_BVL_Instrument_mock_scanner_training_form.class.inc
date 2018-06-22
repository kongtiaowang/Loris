<?php
/*
 * This file contains the NDB_BVL_Instrument_mock_scanner_training_form
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
 * Creates the form elements for the mock_scanner_training_form instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_mock_scanner_training_form extends NDB_BVL_Instrument
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
    function setup($commentID, $page){

        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "mock_scanner_training_form";           // test_names.Test_name
        $this->table = 'mock_scanner_training_form';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken", "session_date_1","session_date_2","session_date_3","session_date_4","session_date_5","session_date_6",
            "session_date_7","session_date_8","total_session_duration_1","total_session_duration_2","total_session_duration_3","total_session_duration_4",
            "total_session_duration_5","total_session_duration_6","total_session_duration_7","total_session_duration_8","mock_time",
            );


        $this->_selectMultipleElements = array("bx_strategies_1","bx_strategies_2","bx_strategies_3","bx_strategies_4","bx_strategies_5","bx_strategies_6",
            "bx_strategies_7","bx_strategies_8");


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
            "/mock_scanner_training_form(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'mock_scanner_Rules'));
    }


    function _main()
    {

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->form->addElement('header', null, 'Session Details');
        $this->form->addElement('select',"total_mock_sessions", "*Total No. of mock sessions:",array("" => NULL,1 => 1, 2 => 2, 3 => 3,4 => 4, 5 => 5, 6 => 6,7 => 7, 8 => 8));
        $this->addHourMinElement("mock_time", "*Approximate total mock time: (hours:minutes)");
        $this->form->addElement('header', null, 'Instructions');
        $this->form->addElement('static','lorisSubHeader',"<b><i>Please fill the sessions based on 'Total No.of mock sessions' you selected above. 
<br>If you select 2 as Total No. of mock sessions, you need to complete Session 1 & Session 2 and you can skip the other sessions.</b></i> ");
        for ($i = 1; $i < 9; $i++) {

            $this->form->addElement('header', null, 'Session No.' . $i);
            $this->addDateElement('session_date_'.$i, '*Date of Session');
            $this->addHourMinElement("total_session_duration_$i", "*Total Duration of Session (hours:minutes)");
            $this->addTextElement("session_specialist_$i", "Bx Specialist:");
            $this->form->addElement('select', 'total_session_staffs_' . $i, "Total Number of IBIS Staff present:", array("" => NULL, 1 => 1, 2 => 2, 3 => 3));
            $this->form->addElement('select', 'scan_attempt_' . $i, "*Has a scan been attempted yet?", array("" => NULL, "Yes" => "Yes", "No" => "No", 'not_answered' => 'Not Answered'));
            $this->form->addElement('select', 'scan_acquired_' . $i, "*Any Acquired?", array("" => NULL, "Complete" => "Complete","Partial" => "Partial", "None" => "None", 'NA' => 'NA'));
            $this->form->addElement('select', 'training_home_' . $i, "*Did the subject do training at home?", array("" => NULL, "Yes" => "Yes", "No" => "No", 'not_answered' => 'Not Answered'));
            $this->addTextAreaElement('training_home_yes_' . $i, 'If Yes, specify:');
            $this->form->addElement('select', 'medication_' . $i, "*Did the subject take any medications today?", array("" => NULL, "Yes" => "Yes", "No" => "No", 'not_answered' => 'Not Answered'));
            $this->addTextAreaElement('medication_yes_' . $i, 'If Yes, specify:');
            $training_options= array(""=>null,"social_story"=>"(1) Social Story","mri_video"=>"(2) MRI Video","vsb"=>"(3) Visual
Story Board","vt"=>"(4) Visual Timer","vc"=>"(5) Verbal Countdown","sb"=>"(6) Sensory Bin","spin_office_chair"=>"(7) Spin in Office Chair",
                "fsv"=>"(8) First/Then Statements Or Visual","wb"=>"(9) Weighted Blanket","mod_sibling"=>"(10) Model on Sibling, Parent,Stuffed Animal",
                "motion_sensor"=>"(11) Motion Sensor/Video Pause","pref_video"=>"(12) Preferred Video/Movie","increase_sound"=>"(13) Increase Scanner Sound Slowly",
                "verb_reminders"=>"(14) Verbal Reminders","verbal_praise"=>"(15) Verbal Praise","edibale_treats"=>"(16) Edible Treats");
            $this->addSelect('bx_strategies_'.$i,"*Select Bx Training Strategies Used?<BR>Cmd+Click or Ctrl+Click to select multiple options", $training_options, array("multiple"));
            $this->addTextAreaElement('session_comments_' . $i, 'Comments:');

        }


    }
    function mock_scanner_Rules($values) {
        $errors = array();
        if (array_key_exists('total_mock_sessions', $values) && empty($values['total_mock_sessions'])) {
            $errors['total_mock_sessions'] = "Required";
        }
        if (array_key_exists('mock_time', $values) ) {
            if(empty($values['mock_time']) && empty($values['mock_time_status'])) {
                $errors['mock_time_group'] = "Required";
            }
        }
       if(!empty($values['total_mock_sessions']))
       {
           for($i=1;$i<=$values['total_mock_sessions'];$i++)
           {
               if(empty($values['session_date_'.$i.'_date']) && empty($values['session_date_'.$i.'_date_status']))
               {
                   $errors['session_date_'.$i.'_date_group'] = "Required";
               }
               if(empty($values['total_session_duration_'.$i]) && empty($values['total_session_duration_'.$i.'_status']))
               {
                   $errors['total_session_duration_'.$i.'_group'] = "Required";
               }
               if(empty($values['scan_attempt_'.$i]))
               {
                   $errors['scan_attempt_'.$i] = "Required";
               }
               if(empty($values['scan_acquired_'.$i])) {
                   $errors['scan_acquired_'.$i] = "Required";
               }
               if(empty($values['training_home_'.$i]))
                   {
                       $errors['training_home_'.$i] = "Required";
                   }
               if(empty($values['medication_' . $i]))
               {
                   $errors['medication_'.$i] = "Required";
               }
               if(empty($values['bx_strategies_'.$i]))
               {
                   $errors['bx_strategies_'.$i] = "Required";
               }

               if($values['training_home_'.$i]=="Yes" && empty($values['training_home_yes_'.$i]) && empty($values['training_home_yes_'.$i.'_status']))
               {
                   $errors['training_home_yes_'.$i.'_group'] = "Required";
               }
               if($values['medication_'.$i]=="Yes" && empty($values['medication_yes_'.$i]) && empty($values['medication_yes_'.$i.'_status']))
               {
                   $errors['medication_yes_'.$i.'_group'] = "Required";
               }
           }
       }
        return $errors;
    }



}
?>
