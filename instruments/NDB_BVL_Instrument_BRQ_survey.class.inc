<?php
/**
 * This file contains the NDB_BVL_Instrument_BRQ_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the BRQ_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BRQ_survey extends NDB_BVL_Instrument
{
    use instrument_validator;

    const OPTIONS = array(
                     "1_almost_never"  => "Almost never",
                     "2_occasionally"  => "Occasionally",
                     "3_half_the_time" => "Half the time",
                     "4_often"         => "Often",
                     "5_nearly_always" => "Nearly Always",
                    );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('BRQ_survey', "BRQ (Bedtime Routine Questionnaire) - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BRQ_survey','BRQ_survey_page4', "Page 4", 4);
     */

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('BRQ_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BRQ_survey";           // test_names.Test_name
        $this->table    = 'BRQ_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "q1_perform_the_same_activities_in_the_hour_before_bed",
                                    "q6_q11_perform_the_same_activities_in_the_hour_before_bed",
                                    "q11_perform_the_same_activities_in_the_hour_before_bed",
                                    "q16_read_listen_to_a_story",
                                   );

        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/BRQ_survey(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
    * Generates the main page of the form.
    *
    * @return void
    * @access private
    */
    function _main()
    {
        // display test name
        $this->addHeader("BRQ (Bedtime Routine Questionnaire) - Survey");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->form->addElement(
            'select',
            'respondent',
            'What is your relationship to the child',
            array(
             ''            => '',
             'mother'      => 'Mother',
             'father'      => 'Father',
             'step_mother' => 'Step Mother',
             'step_father' => 'Step Father',
             'other'       => 'Other',
            )
        );

        $this->form->addElement('text', 'respondent_specify', 'If other, specify:');

        $this->XINRegisterRule('respondent_specify', array('respondent{@}=={@}other'), 'Required if other');

        $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("BRQ (Bedtime Routine Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            Bedtime routines are a set sequence of events that occur regularly in the same order and with the same caretaker before a child goes to bed.
            For each item, please rate how often your child engages in each aspect of a bedtime routine or the intensity of your child’s reaction by selecting a rating of your child’s behavior <b><u>in the past month</u></b>."
        );

        $page1_questions = array(
                            "q1_perform_the_same_activities_in_the_hour_before_bed"       => "1. ...perform the <b><u>same activities</u></b> in the hour before going to bed (for example, bathe, brush teeth, read/listen to story, listen to music)?",
                            "q2_perform_activities_in_the_same_order_before_going_to_bed" => "2. ...perform activities <b><u>in the same order</u></b> before going to bed (for example, bathe, brush teeth, read/listen to story, go to bed)?",
                            "q3_sleep_in_the_same_place"                                  => "3. ...sleep <b><u>in the same place</u></b> (for example, in his/her bed, in parent’s bed, on couch)?",
                            "q4_go_to_bed_at_the_same_time"                               => "4. ...go to bed <b><u>at the same time</u></b> (within 10 minutes)?",
                            "q5_get_put_to_bed_by_the_same_person"                        => "5. ...get put to bed <b><u>by the same person</u></b>?",
                           );

        $this->form->addElement(
            'static',
            null,
            "During <b>weeknights</b> (Sunday through Thursday nights only) for the past <b>month</b>, how often did your child..."
        );

        foreach ($page1_questions as $field => $label) {
            $this->addSelect($field, $label, self::OPTIONS);
        }
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("BRQ (Bedtime Routine Questionnaire) - Survey");

        $page2_questions = array(
                            "q6_perform_the_same_activities_in_the_hour_before_bed"       => "6. ...perform <b><u>the same activities</u></b> in the hour before going to bed?",
                            "q7_perform_activities_in_the_same_order_before_going_to_bed" => "7. ...perform events <b><u>in the same order</u></b> before going to bed (for example, bathe, brush teeth, read/listen to story, go to bed)?",
                            "q8_sleep_in_the_same_place"                                  => "8. ...sleep <b><u>in the same place</u></b> (for example, in his/her bed, in parent’s bed, on couch)?",
                            "q9_go_to_bed_at_the_same_time"                               => "9. ...go to bed <b><u>at the same time</u></b> (within 10 minutes)?",
                            "q10_get_put_to_bed_by_the_same_person"                       => "10. ...get put to bed <b><u>by the same person</u></b>?",
                           );

        $this->form->addElement(
            'static',
            null,
            "During <b>weekends</b> (Friday and Saturday nights) for the past <b>month</b>, how often did your child..."
        );

        foreach ($page2_questions as $field => $label) {
            $this->addSelect($field, $label, self::OPTIONS);
        }
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("BRQ (Bedtime Routine Questionnaire) - Survey");

        $page3_questions = array(
                            "q11_perform_the_same_activities_in_the_hour_before_bed"       => "11. ...perform the <b><u>same activities</u></b> in the hour before going to bed (for example, bathe, brush teeth, read/listen to story, listen to music)?",
                            "q12_perform_activities_in_the_same_order_before_going_to_bed" => "12. ...perform activities <b><u>in the same order</u></b> before going to bed (for example, bathe, brush teeth, read/listen to story, go to bed)?",
                            "q13_sleep_in_the_same_place"                                  => "13. ...sleep <b><u>in the same place</u></b> (for example, in his/her bed, in parent’s bed, on couch)?",
                            "q14_go_to_bed_at_the_same_time"                               => "14. ...go to bed <b><u>at the same time</u></b> (within 10 minutes)?",
                            "q15_get_put_to_bed_by_the_same_person"                        => "15. ...get put to bed <b><u>by the same person</u></b>?",
                           );

        $page3_options = array(
                          "1_not_at_all"  => "Not at all",
                          "2_a_little"    => "A little",
                          "3_moderately"  => "Moderately",
                          "4_quite_a_bit" => "Quite a bit",
                          "5_extremely"   => "Extremely",
                         );

        $this->form->addElement(
            'static',
            null,
            "How upset does your child get if he or she <b><u>does NOT</u></b>..."
        );

        foreach ($page3_questions as $field => $label) {
            $this->addSelect($field, $label, $page3_options);
        }
    }

    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("BRQ (Bedtime Routine Questionnaire) - Survey");

        $page4_questions = array(
                            "q16_read_listen_to_a_story"         => "16. ...read/listen to a story?",
                            "q17_play_with_games_or_toys"        => "17. ...play with games or toys?",
                            "q18_have_active_play"               => "18. ...have active play (such as roughhouse or run around)?",
                            "q19_watch_tv"                       => "19. ...watch TV?",
                            "q20_play_video_games"               => "20. ...play video games?",
                            "q21_listen_to_music"                => "21. ...listen to music?",
                            "q22_have_a_snack_or_drink"          => "22. ...have a snack or drink?",
                            "q23_take_a_shower_bath"             => "23. ...take a shower/bath?",
                            "q24_brush_teeth"                    => "24. ...brush teeth?",
                            "q25_use_the_toilet"                 => "25. ...use the toilet?",
                            "q26_hug_kiss_caregiver"             => "26. ...hug/kiss caregiver?",
                            "q27_say_goodnight_to_family_member" => "27. ...say goodnight to family members?",
                            "q28_get_tucked_in"                  => "28. ...get tucked in?",
                            "q29_put_on_pajamas"                 => "29. ...put on pajamas?",
                            "q30_say_prayers"                    => "30. ...say prayers?",
                            "q31_cuddle_with_caregiver"          => "31. ...cuddle with caregiver?",
                           );

        $this->form->addElement(
            'static',
            null,
            "In the past <b>month</b>, in the hour <b><i>before</i></b> going to bed, how often did your child..."
        );

        foreach ($page4_questions as $field => $label) {
            $this->addSelect($field, $label, self::OPTIONS);
        }
    }

    function validate_main_page($values)
    {
         $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

         return $errors;
    }
}
?>