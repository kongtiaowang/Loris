<?php
/**
 * This file contains the NDB_BVL_Instrument_MEQC_survey
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  MEQC_survey
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

/**
 * Creates the form elements for the MEQC_survey instrument
 *
 * @category Instrument
 * @package  MEQC_survey
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */
class NDB_BVL_Instrument_MEQC_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('MEQC_survey', "MEQC (Morningness Eveningness Questionnaire for Children) - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MEQC_survey','MEQC_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MEQC_survey','MEQC_survey_page2', "Page 2", 2);
     */

    /**
     * Sets up basic data such as the HTML_Quickform object, database references
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('MEQC_survey');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        // Corresponds to the Test_name column in test_names table
        $this->testName = "MEQC_survey";
        // name of database table corresponding to instrument
        $this->table = 'MEQC_survey';
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'q1_is_it_easy_to_get_up_in_the_morning',
                                    'q7_when_does_your_body_tell_you_its_time_for_bed',
                                   );

        // setup the form
        $this->_setupForm();

    }

    /**
     * Builds the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/MEQC_survey(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        // Defines the call back function for HTML Quickform to use in validation
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
        $this->addHeader("MEQC (Morningness Eveningness Questionnaire for Children) - Survey");

        $config      =& NDB_Config::singleton();
        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->form->addElement(
            'select',
            'respondent',
            'Individual completing this Questionnaire:',
            array(
             ''            => '',
             'child'       => 'Child',
             'mother'      => 'Mother',
             'father'      => 'Father',
             'step_mother' => 'Step Mother',
             'step_father' => 'Step Father',
             'other'       => 'Other',
            )
        );

        $this->form->addElement('text', 'respondent_explain', 'If not child, explain:');

        $this->XINRegisterRule('respondent_explain', array('respondent{@}!={@}child'), 'Required if not child');

        $this->form->addElement('text', 'other_specify', 'If other, specify:');

        $this->XINRegisterRule('other_specify', array('respondent{@}=={@}other'), 'Required if other');

        $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    /**
     * Generates the first page of the form.
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("MEQC (Morningness Eveningness Questionnaire for Children) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            Please have your child participating in the IBIS Sleep Study complete the following questions on their own to the best of their ability."
        );

        $this->addSelect(
            "q1_is_it_easy_to_get_up_in_the_morning",
            "1. Is it easy for you to get up in the morning?",
            array(
             "no_way"      => "No way!",
             "sort_of"     => "Sort of",
             "pretty_easy" => "Pretty easy",
             "cinch"       => "It's a cinch",
            )
        );

        $this->addSelect(
            "q2_how_alert_are_you_in_first_half_hour_youre_up",
            "2. How alert are you in the first half hour you're up?",
            array(
             "out_of_it"                  => "Out of it",
             "a_little_dazed"             => "A little dazed",
             "okay"                       => "Okay",
             "ready_to_take_on_the_world" => "Ready to take on the world",
            )
        );

        $this->addSelect(
            "q3_imagine_school_canceled_when_would_you_get_out_of_bed",
            "3. Imagine: School is canceled! You can get up whenever you want to. When would you get out of bed? Between...",
            array(
             "5_00_and_6_30_am"  => "5:00 and 6:30 am",
             "6_30_and_7_45_am"  => "6:30 and 7:45 am",
             "7_45_and_9_45_am"  => "7:45 and 9:45 am",
             "9_45_and_11_00_am" => "9:45 and 11:00 am",
             "11_00_am_and_noon" => "11:00 am and noon",
            )
        );

        $this->addSelect(
            "q4_parents_decided_to_let_you_set_own_bedtime_what_time",
            "4. Guess what? Your parents have decided to let you set your own bedtime. What time would you pick? Between...",
            array(
             "8_00_and_9_00_pm"      => "8:00 and 9:00 pm",
             "9_00_and_10_15_pm"     => "9:00 and 10:15 pm",
             "10_15_pm_and_12_30_am" => "10:15 pm and 12:30 am",
             "12_30_and_1_45_am"     => "12:30 and 1:45 am",
             "1_45_and_3_00_am"      => "1:45 and 3:00 am",
            )
        );

        $this->addSelect(
            "q5_have_to_take_two_hour_test_can_take_it_when_best_what_time",
            "5. The bad news: You have to take a two-hour test. The good news: You can take it when you think you'll do your best. What time is that?",
            array(
             "8_00_to_10_00_am"    => "8:00 to 10:00 am",
             "11_00_am_to_1_00_pm" => "11:00 am to 1:00 pm",
             "3_00_to_5_00_pm"     => "3:00 to 5:00 pm",
             "7_00_to_9_00_pm"     => "7:00 to 9:00 pm",
            )
        );

        $this->addSelect(
            "q6_gym_class_is_set_7_00_am_how_do_you_think_you_will_do",
            "6. Gym class is set for 7:00 in the morning. How do you think you'll do?",
            array(
             "my_best"          => "My best!",
             "okay"             => "Okay",
             "worse_than_usual" => "Worse than usual",
             "awful"            => "Awful",
            )
        );
    }

    function _page2()
    {
        $this->addHeader("MEQC (Morningness Eveningness Questionnaire for Children) - Survey");

        $this->addSelect(
            "q7_when_does_your_body_tell_you_its_time_for_bed",
            "7. When does your body start to tell you it's time for bed (even if you ignore it)? Between ...",
            array(
             "8_00_and_9_00_pm"      => "8:00 and 9:00 pm",
             "9_00_and_10_15_pm"     => "9:00 and 10:15 pm",
             "10_15_pm_and_12_30_am" => "10:15 pm and 12:30 am",
             "12_30_and_1_45_am"     => "12:30 and 1:45 am",
             "1_45_and_3_00_am"      => "1:45 and 3:00 am",
            )
        );

        $this->addSelect(
            "q8_had_to_get_up_at_6_00_am_what_would_it_be_like",
            "8. Say you had to get up at 6:00 am every morning. What would it be like?",
            array(
             "awful"        => "Awful",
             "not_so_great" => "Not so great",
             "okay"         => "Okay (if I have to)",
             "fine"         => "Fine, no problem",
            )
        );

        $this->addSelect(
            "q9_when_you_wake_up_how_long_to_be_totally_with_it",
            "9. When you wake up in the morning how long does it take for you to be totally \"with it?\"",
            array(
             "0_to_10_minutes"      => "0 to 10 minutes",
             "11_to_20_minutes"     => "11 to 20 minutes",
             "21_to_40_minutes"     => "21 to 40 minutes",
             "more_than_40_minutes" => "More than 40 minutes",
            )
        );

        $this->addSelect(
            "q10_when_do_you_have_most_energy_to_do_favorite_things",
            "10. When do you have the most energy to do your favorite things?",
            array(
             "morning_tired_in_evening"  => "Morning! I'm tired in the evening",
             "morning_more_than_evening" => "Morning more than evening",
             "evening_more_than_morning" => "Evening more than morning",
             "evening_tired_in_morning"  => "Evening! I'm tired in the morning",
            )
        );
    }

    function validate_main_page($values)
    {
         $errors = [];

        if ($values["respondent"] == "child") {
            $this->validate_empty_subquestions($values, ["respondent_explain"], $errors);
        }

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["other_specify"], $errors);
        }

         return $errors;
    }
}