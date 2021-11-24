<?php
/**
 * This file contains the NDB_BVL_Instrument_CCTQ_survey class
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
 * Creates the form elements for the CCTQ_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_CCTQ_survey extends NDB_BVL_Instrument_survey
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityRequired = false;

    const YES_NO_OPTIONS = array(
                            null  => "",
                            "yes" => "Yes",
                            "no"  => "No",
                           );

    var $scoreLabels = array(
                            "midsleep_point_total_derived_score",
                            "mornings_evenings_total_derived_score",
                            "chronotype_total_derived_score",
		    );
    
    const SCHEDULEDDAYS = [
                            "q7_child_is_ready_to_fall_asleep_lights_turned_out_at",
                            "q1_child_wakes_up_at",
                          ];

    const FREEDAYS = [
                        "q15_child_is_ready_to_fall_asleep_lights_turned_out_at",
                        "q9_child_normally_wakes_up_at",
                     ];

    const MORNINGNESS_EVENINGNESS = [
                     "q17_if_child_has_to_be_awakened_how_difficult_do_you_find_it",
                     "q18_how_alert_is_child_the_first_half_hour_after_having_awakened",
                     "q19_what_time_would_your_child_get_up_if_they_could_decide",
                     "q20_what_time_would_your_child_go_to_bed_if_they_could_decide",
                     "q21_which_time_intervals_would_you_choose_for_the_test",
                     "q22_class_at_7_am_to_8_am_how_do_you_think_child_will_perform",
                     "q23_what_time_in_evening_does_child_seem_tired_and_need_sleep",
                     "q24_if_child_has_to_get_up_at_6_am_what_would_it_be_like",
                     "q25_if_child_has_to_go_to_bed_at_7_30_pm_what_would_it_be_like",
                     "q26_when_child_wakes_in_the_morning_how_long_to_be_fully_awake",
    ];

    const CHRONOTYPE = [
        "q27_my_child_is",
    ];

    const RESPONSE_VALUES = [
        "very_difficult"                                         => 5,
        "fairly_difficult"                                       => 4,
        "moderate_difficult"                                     => 3,
        "slightly_difficult"                                     => 2,
        "not_at_all_difficult_my_child_never_has_to_be_awakened" => 1,
        "not_at_all_alert"                                       => 5,
        "slightly_alert"                                         => 4,
        "moderately_alert"                                       => 3,
        "fairly_alert"                                           => 2,
        "very_alert"                                             => 1,
        "prior_to_6_30_am"                                       => 1,
        "6_30_to_7_14_am"                                        => 2,
        "7_15am_to_9_29_am"                                      => 3,
        "9_30_to_10_14_am"                                       => 4,
        "after_10_15_am"                                         => 5,
        "prior_to_6_59_pm"                                       => 1,
        "7_00_to_7_39_pm"                                        => 2,
        "8_00_to_9_59_pm"                                        => 3,
        "10_00_to_10_59_pm"                                      => 4,
        "after_11_00_pm"                                         => 5,
        "7_00_to_11_00_am"                                       => 1,
        "11_00_am_to_3_00_pm"                                    => 2,
        "3_00_to_8_00_pm"                                        => 3,
        "would_be_in_very_good_form"                             => 1,
        "would_be_in_good_form"                                  => 2,
        "would_be_in_reasonable_form"                            => 3,
        "would_find_it_difficult"                                => 4,
        "would_find_it_very_difficult"                           => 5,
        "prior_to_6_29_pm"                                       => 1,
        "6_30_to_7_14_pm"                                        => 2,
        "7_15_to_9_29_pm"                                        => 3,
        "9_30_to_10_14_pm"                                       => 4,
        "after_10_15_pm"                                         => 5,
        "rather_difficult"                                       => 4,
        "a_little_difficult_but_not_a_great_problem"             => 2,
        "not_at_all_difficult"                                   => 1,
        "0_minutes_immediately"                                  => 1,
        "1_to_4_minutes"                                         => 2,
        "5_to_10_minutes"                                        => 3,
        "11_to_20_minutes"                                       => 4,
        "more_than_21_minutes"                                   => 5,
        "definitely_a_morning_type"                              => 1,
        "rather_more_a_morning_type_than_an_evening_type"        => 2,
        "neither_a_morning_type_nor_an_evening_type"             => 3,
        "rather_more_an_evening_type_than_a_morning_type"        => 4,
        "definitely_an_evening_type"                             => 5,
    ];

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('CCTQ_survey', "CCTQ (Children's ChronoType Questionnaire) - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CCTQ_survey','CCTQ_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CCTQ_survey','CCTQ_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CCTQ_survey','CCTQ_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CCTQ_survey','CCTQ_survey_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CCTQ_survey','CCTQ_survey_page5', "Page 5", 5);
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
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('CCTQ_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "CCTQ_survey";           // test_names.Test_name
        $this->table    = 'CCTQ_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
	$this->commentID = $commentID;
	$config            = NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
	$this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "did_you_have_to_read_the_survey_questions_to_your_child",
                                    "q1_child_wakes_up_at",
                                    "q9_child_normally_wakes_up_at",
                                    "q17_if_child_has_to_be_awakened_how_difficult_do_you_find_it",
                                    "q27_my_child_is",
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
        if (preg_match("/CCTQ_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("CCTQ (Children's ChronoType Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            Please answer the following questions regarding the child paricipating in the IBIS sleep study."
	);

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
   	
        // SCORING TABLE

         $this->form->addElement('header', 'score', "Score Summary");

         $group[] = $this->form->createElement('static', "score", null, null);
 
         $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
         unset($group);
 
         $scales = array(
                    "midsleep_point_total_derived"        => "Midsleep Point on free days (MCF):",
                    "mornings_evenings_total_derived"     => "The Morningness/Eveningness (M/E):",
                    "chronotype_total_derived"            => "Chronotype (CT):",
                   );
 
         $columnHeaders = array("score" => "Score");
 
         foreach ($columnHeaders as $field => $label) {
             $columnHeaders[$field] .= "   ";
         }
         $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);
 
         foreach ($scales as $field => $label) {
             foreach ($columnHeaders as $scoreField => $scoreLabel) {
                 $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
             }
             $this->form->addGroup($group, "{$field}_score_group", $label, $this->_GUIDelimiter, false);
             unset($group);
         }
   
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("CCTQ (Children's ChronoType Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            Please answer the following questions in reference to the MEQ-C survey your child recently completed."
        );

        $how_much_support_options = array(
		                     null          => "",
		                     "none"        => "None",
                                     "a_little"    => "A little",
                                     "quite_a_bit" => "Quite a bit",
                                     "completely"  => "Completely",
                                    );

        $how_well_understood_options = array(
	                                null                   => "",
	                        	"did_not_understand"   => "Did not understand",
                                        "somewhat_understood"  => "Somewhat understood",
                                        "understood"           => "Understood",
                                        "very_much_understood" => "Very much understood",
                                       );

        $how_accurate_options = array(
	                         null                  => "",
	                         "not_at_all_accurate" => "Not at all accurate",
                                 "somewhat_accurate"   => "Somewhat accurate",
                                 "usually_accurate"    => "Usually accurate",
                                 "very_much_accurate"  => "Very much accurate",
                                );

	$this->addSelect("did_your_child_complete_the_meqc", "Did your child complete the MEQC?", self::YES_NO_OPTIONS);

	$this->form->addElement('static',null, "<h4>If 'No', the next four questions are not required and can be skipped. </h4>");

        $this->addSelect("did_you_have_to_read_the_survey_questions_to_your_child", "Did you have to read the survey questions to your child?", self::YES_NO_OPTIONS);
        $this->XINRegisterRule("did_you_have_to_read_the_survey_questions_to_your_child", array("did_your_child_complete_the_meqc{@}=={@}yes"), 'Required if yes.');

        $this->addSelect("how_much_did_you_support_your_child_in_completing_the_survey", "How much did you support your child in completing the survey?", $how_much_support_options);
        $this->XINRegisterRule("how_much_did_you_support_your_child_in_completing_the_survey", array("did_your_child_complete_the_meqc{@}=={@}yes"), 'Required if yes.');

        $this->addSelect("how_well_do_you_think_you_child_understood_the_survey_questions", "How well do you think your child understood the survey questions?", $how_well_understood_options);
        $this->XINRegisterRule("how_well_do_you_think_you_child_understood_the_survey_questions", array("did_your_child_complete_the_meqc{@}=={@}yes"), 'Required if yes.');


	$this->addSelect("how_accurate_were_your_childs_response_on_the_survey", "In your opinion, how accurate were your child's response on the survey?", $how_accurate_options);
	$this->XINRegisterRule("how_accurate_were_your_childs_response_on_the_survey", array("did_your_child_complete_the_meqc{@}=={@}yes"), 'Required if yes.');
  $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("CCTQ (Children's ChronoType Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            The following questions ask about sleep/wake patterns during \"scheduled days\" in contrast to \"free days.\"
            Think about your child's behavior during recent weeks when answering these questions.
            For questions with changing conditions (e.g., child goes to daycare at 7:00 am 1 day/week and 9:00 am 3 days/week),
            fill in or select the most frequent common answer.
            <br><br>
            Scheduled Days
            <br>
            Child's sleep-wake pattern is directly influenced by individual or family activites (e.g. school, day care, work, athletics, etc.)"
        );

        $q2_options = array(
                       "by_their_self"                => "By their self",
                       "with_help_from_family_member" => "With help from a family memeber",
                       "with_an_alarm_clock"          => "With an alarm clock",
                      );

        $q5_options = array(
                       ""  => "",
                       "1" => "1 day/week",
                       "2" => "2 days/week",
                       "3" => "3 days/week",
                       "4" => "4 days/week",
                       "5" => "5 days/week",
                       "6" => "6 days/week",
                       "7" => "7 days/week",
                      );

        $this->form->addElement(
            'static',
            null,
            "<b><u>On Scheduled Days ...</u></b>"
        );

        $this->addHourMinElement('q1_child_wakes_up_at', "1. ... child wakes up at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addSelect("q2_child_regularly_wakes_up", "2. ... child regularly wakes up", $q2_options);

        $this->addHourMinElement('q3_child_gets_up_out_of_bed_at', "3. ... child gets up (out of bed) at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addHourMinElement('q4_child_is_fully_awake_by', "4. ... child is fully awake by", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addSelect("q5_child_takes_regular_naps", "5. ... child takes regular naps", self::YES_NO_OPTIONS);

        $this->addSelect("q5_if_yes_how_many_days_per_week_do_they_nap", $this->indent . "If yes, how many days/week do they nap?", $q5_options);

        $this->XINRegisterRule('q5_if_yes_how_many_days_per_week_do_they_nap', array('q5_child_takes_regular_naps{@}=={@}yes'), 'Required if yes');

        $this->form->addElement('text', 'q5_if_yes_how_many_minutes_do_they_sleep_each_nap', $this->indent . 'If yes, how many minutes do they sleep each nap?');

        $this->XINRegisterRule('q5_if_yes_how_many_minutes_do_they_sleep_each_nap', array('q5_child_takes_regular_naps{@}=={@}yes'), 'Required if yes');

        $this->form->addElement('text', 'q5_if_no_why_do_they_not_nap', $this->indent . 'If no, why do they not nap?');

        $this->XINRegisterRule('q5_if_no_why_do_they_not_nap', array('q5_child_takes_regular_naps{@}=={@}no'), 'Required if no');

        $this->form->addElement(
            'static',
            null,
            "<b><u>On nights before Scheduled Days ...</u></b>"
        );

        $this->addHourMinElement('q6_child_goes_to_bed_body_in_bed_at', "6. ... child goes to bed (body in bed) at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addHourMinElement('q7_child_is_ready_to_fall_asleep_lights_turned_out_at', "7. ... child is ready to fall asleep (lights turned out) at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->form->addElement('text', 'q8_how_many_minutes_does_it_take_child_to_fall_asleep_lights_out', '8. ... how many minutes does it take child to fall asleep (after lights turned out)?');

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("CCTQ (Children's ChronoType Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "Free Days
            <br>
            Child's sleep/wake pattern is \"free\" from the influence of individual or family activities (e.g., school, day care, work, athletics etc.)"
        );

        $q13_options = array(
                        "1" => "1 day/week",
                        "2" => "2 days/week",
                        "3" => "3 days/week",
                        "4" => "4 days/week",
                        "5" => "5 days/week",
                        "6" => "6 days/week",
                        "7" => "7 days/week",
                       );

        $this->form->addElement(
            'static',
            null,
            "<b><u>On Free Days ...</u></b>"
        );

        $this->addHourMinElement('q9_child_normally_wakes_up_at', "9. ... my child normally wakes up at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addSelect("q10_child_wakes_up_at_normal_time_but_goes_back_to_sleep", "10. ... my child wakes up at their normal time on scheduled days, but then goes back to sleep after waking", self::YES_NO_OPTIONS);

        $this->form->addElement('text', 'q10_if_yes_how_many_minutes_does_child_go_back_to_sleep_for', $this->indent . 'If yes, how many minutes does child go back to sleep for after waking?');

        $this->XINRegisterRule('q10_if_yes_how_many_minutes_does_child_go_back_to_sleep_for', array('q10_child_wakes_up_at_normal_time_but_goes_back_to_sleep{@}=={@}yes'), 'Required if yes');

        $this->addHourMinElement('q11_child_gets_up_out_of_bed_at', "11. ... my child gets up (out of bed) by", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addHourMinElement('q12_child_is_fully_awake_by', "12. ... my child is fully awake by", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addSelect("q13_child_takes_regular_naps", "13. ... my child takes regular naps", self::YES_NO_OPTIONS);

        $this->addSelect("q13_if_yes_how_many_days_per_week_do_they_nap", $this->indent . 'If yes, how many days/week do they nap?', $q13_options);

        $this->XINRegisterRule('q13_if_yes_how_many_days_per_week_do_they_nap', array('q13_child_takes_regular_naps{@}=={@}yes'), 'Required if yes');

        $this->form->addElement('text', 'q13_if_yes_how_many_minutes_do_they_sleep_each_nap', $this->indent . 'If yes, how many minutes do they sleep each nap?');

        $this->XINRegisterRule('q13_if_yes_how_many_minutes_do_they_sleep_each_nap', array('q13_child_takes_regular_naps{@}=={@}yes'), 'Required if yes');

        $this->form->addElement('text', 'q13_if_no_why_do_they_not_nap', $this->indent . 'If no, why do they not nap?');

        $this->XINRegisterRule('q13_if_no_why_do_they_not_nap', array('q13_child_takes_regular_naps{@}=={@}no'), 'Required if no');

        $this->form->addElement(
            'static',
            null,
            "<b><u>On nights before Free Days ...</u></b>"
        );

        $this->addHourMinElement('q14_child_goes_to_bed_body_in_bed_at', "14. ... my child goes to bed (body in bed) at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->addHourMinElement('q15_child_is_ready_to_fall_asleep_lights_turned_out_at', "15. ... my child is ready to fall asleep (lights turned out) at", [], "No time entered. Fields may appear to be filled. Please clear and re-enter with the appropriate time.", false);

        $this->form->addElement('text', 'q16_how_many_minutes_does_it_take_child_fall_asleep_lights_out', '16. ... how many minutes does it take child to fall asleep (after lights turned out)?');

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("CCTQ (Children's ChronoType Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions</h3><br>
            For each of the following questions, please select the answer that best describes your child.
            Make your judgments based on how the behavior of your child was in recent weeks.
            There are no \"right\" or \"wrong\" answers."
        );

        $q17_options = array(
                        null                                                     => "",
                        "very_difficult"                                         => "Very difficult",
                        "fairly_difficult"                                       => "Fairly difficult",
                        "moderate_difficult"                                     => "Moderately difficult",
                        "slightly_difficult"                                     => "Slightly difficult",
                        "not_at_all_difficult_my_child_never_has_to_be_awakened" => "Not at all difficult/my child never has to be awakened",
                       );

        $q18_options = array(
                        null               => "",
                        "not_at_all_alert" => "Not at all alert",
                        "slightly_alert"   => "Slightly alert",
                        "moderately_alert" => "Moderately alert",
                        "fairly_alert"     => "Fairly alert",
                        "very_alert"       => "Very alert",
                       );

        $q19_options = array(
                        null                => "",
                        "prior_to_6_30_am"  => "Prior to 6:30 am",
                        "6_30_to_7_14_am"   => "6:30 - 7:14 am",
                        "7_15am_to_9_29_am" => "7:15 - 9:29 am",
                        "9_30_to_10_14_am"  => "9:30 - 10:14 am",
                        "after_10_15_am"    => "After 10:15 am",
                       );

        $q20_options = array(
                        null                => "",
                        "prior_to_6_59_pm"  => "Prior to 6:59 pm",
                        "7_00_to_7_39_pm"   => "7:00 - 7:39 pm",
                        "8_00_to_9_59_pm"   => "8:00 - 9:59 pm",
                        "10_00_to_10_59_pm" => "10:00 - 10:59 pm",
                        "after_11_00_pm"    => "After 11:00 pm",
                       );

        $q21_options = array(
                        null                  => "",
                        "7_00_to_11_00_am"    => "7:00 - 11:00 am",
                        "11_00_am_to_3_00_pm" => "11:00 am - 3:00 pm",
                        "3_00_to_8_00_pm"     => "3:00 - 8:00 pm",
                       );

        $q22_options = array(
                        null                           => "",
                        "would_be_in_very_good_form"   => "Would be in very good form",
                        "would_be_in_good_form"        => "Would be in good form",
                        "would_be_in_reasonable_form"  => "Would be in reasonable form",
                        "would_find_it_difficult"      => "Would find it difficult",
                        "would_find_it_very_difficult" => "Would find it very difficult",
                       );

        $q23_options = array(
                        null               => "",
                        "prior_to_6_29_pm" => "Prior to 6:29 pm",
                        "6_30_to_7_14_pm"  => "6:30 - 7:14 pm",
                        "7_15_to_9_29_pm"  => "7:15 - 9:29 pm",
                        "9_30_to_10_14_pm" => "9:30 - 10:14 pm",
                        "after_10_15_pm"   => "After 10:15 pm",
                       );

        $q24_q25_options = array(
                            null                                         => "",
                            "very_difficult"                             => "Very difficult",
                            "rather_difficult"                           => "Rather difficult",
                            "moderate_difficult"                         => "Moderately difficult",
                            "a_little_difficult_but_not_a_great_problem" => "A little difficult, but not a great problem",
                            "not_at_all_difficult"                       => "Not at all difficult",
                           );

        $q26_options = array(
                        null                    => "",
                        "0_minutes_immediately" => "0 minutes (i.e., immediately)",
                        "1_to_4_minutes"        => "1 to 4 minutes",
                        "5_to_10_minutes"       => "5 to 10 minutes",
                        "11_to_20_minutes"      => "11 to 20 minutes",
                        "more_than_21_minutes"  => "More than 21 minutes",
                       );

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">17. If your child has to be awakened, how difficult do you find it to wake your child up in the morning?</h3>");
        $group[] = $this->createSelect(
            "q17_if_child_has_to_be_awakened_how_difficult_do_you_find_it",
            "",
            $q17_options
        );
        $this->form->addGroup(
            $group,
            "page4_q17",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">18. How alert is your child during the first half hour after having awakened in the morning?</h3>");
        $group[] = $this->createSelect(
            "q18_how_alert_is_child_the_first_half_hour_after_having_awakened",
            "",
            $q18_options
        );
        $this->form->addGroup(
            $group,
            "page4_q18",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">19. Considering your child's own \"feeling best\" rhythm, what time would your child get up if they could decide by their self and if they were entirely free to plan their day (e.b., vacation)?</h3>");
        $group[] = $this->createSelect(
            "q19_what_time_would_your_child_get_up_if_they_could_decide",
            "",
            $q19_options
        );
        $this->form->addGroup(
            $group,
            "page4_q19",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">20. Considering your child's \"feeling best\" rhythm, at what time would your child go to bed if they could decide by their self and if they were entirely free to plan the next day (e.g., weekend)?</h3>");
        $group[] = $this->createSelect(
            "q20_what_time_would_your_child_go_to_bed_if_they_could_decide",
            "",
            $q20_options
        );
        $this->form->addGroup(
            $group,
            "page4_q20",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel(
            "<h3 style=\"text-align:left\">21. Let's assume your child has to be at peak performance for a test that will be mentally exhausting for 2 hours.
            Considering your child's \"feeling best\" rhythm and that you are entirely free to plan your child's day,
            which ONE of the three time intervals would you choose for the test?</h3>"
        );
        $group[] = $this->createSelect(
            "q21_which_time_intervals_would_you_choose_for_the_test",
            "",
            $q21_options
        );
        $this->form->addGroup(
            $group,
            "page4_q21",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel(
            "<h3 style=\"text-align:left\">22. Let's assume that you have decided to enroll your child in an athletic activity (e.g., swimming).
            The only class available meets twice a week at 7 am - 8 am. How do you think your child will perform?</h3>"
        );
        $group[] = $this->createSelect(
            "q22_class_at_7_am_to_8_am_how_do_you_think_child_will_perform",
            "",
            $q22_options
        );
        $this->form->addGroup(
            $group,
            "page4_q22",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel(
            "<h3 style=\"text-align:left\">23. At what time in the evening does your child seem tired and in need of sleep?</h3>"
        );
        $group[] = $this->createSelect(
            "q23_what_time_in_evening_does_child_seem_tired_and_need_sleep",
            "",
            $q23_options
        );
        $this->form->addGroup(
            $group,
            "page4_q23",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel(
            "<h3 style=\"text-align:left\">24. If your child had to get up every day at 6 am, what do you think it would be like for them?</h3>"
        );
        $group[] = $this->createSelect(
            "q24_if_child_has_to_get_up_at_6_am_what_would_it_be_like",
            "",
            $q24_q25_options
        );
        $this->form->addGroup(
            $group,
            "page4_q24",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel(
            "<h3 style=\"text-align:left\">25. If your child always had to go to bed at 7:30 pm, what do you think it would be like for them?</h3>"
        );
        $group[] = $this->createSelect(
            "q25_if_child_has_to_go_to_bed_at_7_30_pm_what_would_it_be_like",
            "",
            $q24_q25_options
        );
        $this->form->addGroup(
            $group,
            "page4_q25",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel(
            "<h3 style=\"text-align:left\">26. When your child wakes up in the morning, how long does it take to be fully awake?</h3>"
        );
        $group[] = $this->createSelect(
            "q26_when_child_wakes_in_the_morning_how_long_to_be_fully_awake",
            "",
            $q26_options
        );
        $this->form->addGroup(
            $group,
            "page4_q26",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("CCTQ (Children's ChronoType Questionnaire) - Survey");

        $this->form->addElement(
            'static',
            null,
            "After answering the previous questions, you may have a feeling which \"Chronotype\" or \"Time-of-Day type\" your child is.
            <br><br>
            For example, if your child would like to sleep quite a bit longer on \"Free Days\" compared to \"Scheduled Days\" or if it is difficult
            for your child to get out of bed on Monday mornings, then he/she is more likely to be an Evening Type person (a \"Night Owl\").
            If your child, however, regularly wakes up and feels perky once they get out of bed, and your child prefers to go to bed rather early than late,
            then they are more likely a Morning Type person (a \"Morning Lark\").
            <br><br>
            Please categorize your child using one of the following choices."
        );

        $q27_options = array(
                        "definitely_a_morning_type"                       => "Definitely a \"morning\" type",
                        "rather_more_a_morning_type_than_an_evening_type" => "Rather more a \"morning\" type than an \"evening\" type",
                        "neither_a_morning_type_nor_an_evening_type"      => "Neither a \"morning\" type nor an \"evening\" type",
                        "rather_more_an_evening_type_than_a_morning_type" => "Rather more an \"evening\" type than a \"morning\" type",
                        "definitely_an_evening_type"                      => "Definitely an \"evening\" type",
                       );

        $this->addSelect("q27_my_child_is", "27. My child is...", $q27_options);

        $this->addBasicText("comments", "Comments (please add any other information or questions regarding your child's sleep):");

        $this->XINRegisterRule(
            "comments",
            array("comments{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
    }

    function validate_main_page($values)
    {
         $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

         return $errors;
    }
    function validate_page1($values)
    {
        $errors = [];
        if ($values["did_you_have_to_read_the_survey_questions_to_your_child"] == "no") {
            $this->validate_empty_subquestions($values, ["how_much_did_you_support_your_child_in_completing_the_survey"], $errors);
            $this->validate_empty_subquestions($values, ["how_well_do_you_think_you_child_understood_the_survey_questions"], $errors);
            $this->validate_empty_subquestions($values, ["how_accurate_were_your_childs_response_on_the_survey"], $errors);
        }

        return $errors;
    }
    function validate_page2($values)
    {
        $errors = [];

        if ($values["q5_child_takes_regular_naps"] == "yes") {
            $this->validate_empty_subquestions($values, ["q5_if_no_why_do_they_not_nap"], $errors);
        }

        if ($values["q5_child_takes_regular_naps"] == "no") {
            $this->validate_empty_subquestions($values, ["q5_if_yes_how_many_days_per_week_do_they_nap"], $errors);
            $this->validate_empty_subquestions($values, ["q5_if_yes_how_many_minutes_do_they_sleep_each_nap"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["q10_child_wakes_up_at_normal_time_but_goes_back_to_sleep"] == "no") {
            $this->validate_empty_subquestions($values, ["q10_if_yes_how_many_minutes_does_child_go_back_to_sleep_for"], $errors);
        }

        if ($values["q13_child_takes_regular_naps"] == "yes") {
            $this->validate_empty_subquestions($values, ["q13_if_no_why_do_they_not_nap"], $errors);
        }

        if ($values["q13_child_takes_regular_naps"] == "no") {
            $this->validate_empty_subquestions($values, ["q13_if_yes_how_many_days_per_week_do_they_nap"], $errors);
            $this->validate_empty_subquestions($values, ["q13_if_yes_how_many_minutes_do_they_sleep_each_nap"], $errors);
        }

        return $errors;
    }

    /**
 * To get the time difference between bed time and wake up time.
 *
 * @param $times is an array containing both time responses, $record1 array contains db reponse, $record2 is a string for additional time to fall asleep,
 * @return float value for the time difference
 */
    function calculateTimeDiff($times,$record1, $record2){

        $lights_turned_out = $record1[$times[0]];
        $child_wakes_up_at = $record1[$times[1]];
        $lights_turned_out = explode(':',$lights_turned_out);
        $child_wakes_up_at = explode(':',$child_wakes_up_at);
        $hours_sleep = $lights_turned_out[0];
        $hours_wake = $child_wakes_up_at[0];
        $mins_sleep = $lights_turned_out[1] + $record2;
        $mins_wake = $child_wakes_up_at[1];
        $hours = $hours_wake - $hours_sleep;
        $mins = 0;
        if($hours <= 0 ){
            $hours = 24 + $hours;
        }
        if($mins_wake >= $mins_sleep){
            $mins = $mins_wake - $mins_sleep;
        }else{
            $mins = ($mins_wake + 60 ) - $mins_sleep;
            $hours--;
        }
        $hours = $hours + ($mins/60);
        return $hours;
    }

 /**
 * To sum up values assigned to the responses.
 *
 * @param $question_array is an array containing responses with assigned values, $record array contains db reponse 
 * @return integer value sum
 */ 
    function sumScaleScores($question_array, $record)
    {
        $sum = 0;

        foreach ($question_array as $q) {
            $sum += $this->getNumericalValue($record[$q]);
        }
        return $sum;
    }

 /**
 * To assign values to the responses stored in the table.
 *
 * @param string $record is the response   
 * @return value assigned to the response in the array declared as constant
 */ 
    function getNumericalValue($record){

        return self::RESPONSE_VALUES[$record];

        }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // Null scores
        $this->_nullScores($this->scoreLabels);

        // Get the saved scores
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());

        $sleep_period_on_scheduled_days = $this->calculateTimeDiff(self::SCHEDULEDDAYS,$record,$record["q8_how_many_minutes_does_it_take_child_to_fall_asleep_lights_out"]) ?? 0;
        $sleep_period_on_free_days = $this->calculateTimeDiff(self::FREEDAYS,$record,$record["q16_how_many_minutes_does_it_take_child_fall_asleep_lights_out"]) ?? 0;

        $scores["midsleep_point_total_derived_score"] = round((  (5 * $sleep_period_on_scheduled_days)
                                                        + (2 * $sleep_period_on_free_days)
                                                       )/7,2);

        $scores["mornings_evenings_total_derived_score"] = $this->sumScaleScores(self::MORNINGNESS_EVENINGNESS, $record);
        $scores["chronotype_total_derived_score"] = $this->sumScaleScores(self::CHRONOTYPE,$record);

	$db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

}

