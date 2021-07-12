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

    var $scoreLabels = array(
        "mornings_evenings_total_derived_score",
      );

    const MORNINGNESS_EVENINGNESS = [
        "q1_is_it_easy_to_get_up_in_the_morning",
        "q2_how_alert_are_you_in_first_half_hour_youre_up",
        "q3_imagine_school_canceled_when_would_you_get_out_of_bed",
        "q4_parents_decided_to_let_you_set_own_bedtime_what_time",
        "q5_have_to_take_two_hour_test_can_take_it_when_best_what_time",
        "q6_gym_class_is_set_7_00_am_how_do_you_think_you_will_do",
        "q7_when_does_your_body_tell_you_its_time_for_bed",
        "q8_had_to_get_up_at_6_00_am_what_would_it_be_like",
        "q9_when_you_wake_up_how_long_to_be_totally_with_it",
        "q10_when_do_you_have_most_energy_to_do_favorite_things",
    ];

    const getResponseValue = [
        "no_way"                     => 1,
        "sort_of"                    => 2,
        "pretty_easy"                => 3,
        "cinch"                      => 4,
        "out_of_it"                  => 1,
        "a_little_dazed"             => 2,
        "okay"                       => 3,
        "ready_to_take_on_the_world" => 4,
        "5_00_and_6_30_am"           => 5,
        "6_30_and_7_45_am"           => 4,
        "7_45_and_9_45_am"           => 3,
        "9_45_and_11_00_am"          => 2,
        "11_00_am_and_noon"          => 1,
        "8_00_and_9_00_pm"           => 5,
        "9_00_and_10_15_pm"          => 4,
        "10_15_pm_and_12_30_am"      => 3,
        "12_30_and_1_45_am"          => 2,
        "1_45_and_3_00_am"           => 1,
        "8_00_to_10_00_am"           => 4,
        "11_00_am_to_1_00_pm"        => 3,
        "3_00_to_5_00_pm"            => 2,
        "7_00_to_9_00_pm"            => 1,
        "my_best"                    => 4,
        "okay"                       => 3,
        "worse_than_usual"           => 2,
        "awful"                      => 1,
        "8_00_and_9_00_pm"           => 5,
        "9_00_and_10_15_pm"          => 4,
        "10_15_pm_and_12_30_am"      => 3,
        "12_30_and_1_45_am"          => 2,
        "1_45_and_3_00_am"           => 1,
        "awful"                      => 1,
        "not_so_great"               => 2,
        "okay"                       => 3,
        "fine"                       => 4,
        "0_to_10_minutes"            => 4,
        "11_to_20_minutes"           => 3,
        "21_to_40_minutes"           => 2,
        "more_than_40_minutes"       => 1,
        "morning_tired_in_evening"   => 4,
        "morning_more_than_evening"  => 3,
        "evening_more_than_morning"  => 2,
        "evening_tired_in_morning"   => 1,
    ];

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
	
	// SCORING TABLE

        $this->form->addElement('header', 'score', "Score Summary");

        $group[] = $this->form->createElement('static', "score", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   "mornings_evenings_total_derived"     => "The Morningness/Eveningness Points:",
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
        $this->addHeader("MEQC (Morningness Eveningness Questionnaire for Children) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            Please have your child participating in the IBIS Sleep Study complete the following questions on their own to the best of their ability."
        );

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">1. Is it easy for you to get up in the morning?</h3>");
        $group[] = $this->createSelect(
            "q1_is_it_easy_to_get_up_in_the_morning",
            "",
            array(
             null          => "",
             "no_way"      => "No way!",
             "sort_of"     => "Sort of",
             "pretty_easy" => "Pretty easy",
             "cinch"       => "It's a cinch",
            )
        );
        $this->form->addGroup(
            $group,
            "page1_q1",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">2. How alert are you in the first half hour you're up?</h3>");
        $group[] = $this->createSelect(
            "q2_how_alert_are_you_in_first_half_hour_youre_up",
            "",
            array(
             null                         => "",
             "out_of_it"                  => "Out of it",
             "a_little_dazed"             => "A little dazed",
             "okay"                       => "Okay",
             "ready_to_take_on_the_world" => "Ready to take on the world",
            )
        );
        $this->form->addGroup(
            $group,
            "page1_q2",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">3. Imagine: School is canceled! You can get up whenever you want to. When would you get out of bed? Between...</h3>");
        $group[] = $this->createSelect(
            "q3_imagine_school_canceled_when_would_you_get_out_of_bed",
            "",
            array(
             null                => "",
             "5_00_and_6_30_am"  => "5:00 and 6:30 am",
             "6_30_and_7_45_am"  => "6:30 and 7:45 am",
             "7_45_and_9_45_am"  => "7:45 and 9:45 am",
             "9_45_and_11_00_am" => "9:45 and 11:00 am",
             "11_00_am_and_noon" => "11:00 am and noon",
            )
        );
        $this->form->addGroup(
            $group,
            "page1_q3",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">4. Guess what? Your parents have decided to let you set your own bedtime. What time would you pick? Between...</h3>");
        $group[] = $this->createSelect(
            "q4_parents_decided_to_let_you_set_own_bedtime_what_time",
            "",
            array(
             null                    => "",
             "8_00_and_9_00_pm"      => "8:00 and 9:00 pm",
             "9_00_and_10_15_pm"     => "9:00 and 10:15 pm",
             "10_15_pm_and_12_30_am" => "10:15 pm and 12:30 am",
             "12_30_and_1_45_am"     => "12:30 and 1:45 am",
             "1_45_and_3_00_am"      => "1:45 and 3:00 am",
            )
        );
        $this->form->addGroup(
            $group,
            "page1_q4",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">5. The bad news: You have to take a two-hour test. The good news: You can take it when you think you'll do your best. What time is that?</h3>");
        $group[] = $this->createSelect(
            "q5_have_to_take_two_hour_test_can_take_it_when_best_what_time",
            "",
            array(
             null                  => "",
             "8_00_to_10_00_am"    => "8:00 to 10:00 am",
             "11_00_am_to_1_00_pm" => "11:00 am to 1:00 pm",
             "3_00_to_5_00_pm"     => "3:00 to 5:00 pm",
             "7_00_to_9_00_pm"     => "7:00 to 9:00 pm",
            )
        );
        $this->form->addGroup(
            $group,
            "page1_q5",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">6. Gym class is set for 7:00 in the morning. How do you think you'll do?</h3>");
        $group[] = $this->createSelect(
            "q6_gym_class_is_set_7_00_am_how_do_you_think_you_will_do",
            "",
            array(
             null               => "",
             "my_best"          => "My best!",
             "okay"             => "Okay",
             "worse_than_usual" => "Worse than usual",
             "awful"            => "Awful",
            )
        );
        $this->form->addGroup(
            $group,
            "page1_q6",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _page2()
    {
        $this->addHeader("MEQC (Morningness Eveningness Questionnaire for Children) - Survey");

        /*$this->addSelect(
            "q7_when_does_your_body_tell_you_its_time_for_bed",
            "7. When does your body start to tell you it's time for bed (even if you ignore it)? Between ...",
            array(
             "8_00_and_9_00_pm"      => "8:00 and 9:00 pm",
             "9_00_and_10_15_pm"     => "9:00 and 10:15 pm",
             "10_15_pm_and_12_30_am" => "10:15 pm and 12:30 am",
             "12_30_and_1_45_am"     => "12:30 and 1:45 am",
             "1_45_and_3_00_am"      => "1:45 and 3:00 am",
            )
        );*/

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">7. When does your body start to tell you it's time for bed (even if you ignore it)? Between ...</h3>");
        $group[] = $this->createSelect(
            "q7_when_does_your_body_tell_you_its_time_for_bed",
            "",
            array(
             null                    => "",
             "8_00_and_9_00_pm"      => "8:00 and 9:00 pm",
             "9_00_and_10_15_pm"     => "9:00 and 10:15 pm",
             "10_15_pm_and_12_30_am" => "10:15 pm and 12:30 am",
             "12_30_and_1_45_am"     => "12:30 and 1:45 am",
             "1_45_and_3_00_am"      => "1:45 and 3:00 am",
            )
        );
        $this->form->addGroup(
            $group,
            "page2_q7",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        /*
        $this->addSelect(
            "q8_had_to_get_up_at_6_00_am_what_would_it_be_like",
            "8. Say you had to get up at 6:00 am every morning. What would it be like?",
            array(
             "awful"        => "Awful",
             "not_so_great" => "Not so great",
             "okay"         => "Okay (if I have to)",
             "fine"         => "Fine, no problem",
            )
        );*/

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">8. Say you had to get up at 6:00 am every morning. What would it be like?</h3>");
        $group[] = $this->createSelect(
            "q8_had_to_get_up_at_6_00_am_what_would_it_be_like",
            "",
            array(
             null           => "",
             "awful"        => "Awful",
             "not_so_great" => "Not so great",
             "okay"         => "Okay (if I have to)",
             "fine"         => "Fine, no problem",
            )
        );
        $this->form->addGroup(
            $group,
            "page2_q8",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        /*
        $this->addSelect(
            "q9_when_you_wake_up_how_long_to_be_totally_with_it",
            "9. When you wake up in the morning how long does it take for you to be totally \"with it?\"",
            array(
             "0_to_10_minutes"      => "0 to 10 minutes",
             "11_to_20_minutes"     => "11 to 20 minutes",
             "21_to_40_minutes"     => "21 to 40 minutes",
             "more_than_40_minutes" => "More than 40 minutes",
            )
        );*/

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">9. When you wake up in the morning how long does it take for you to be totally \"with it?\"</h3>");
        $group[] = $this->createSelect(
            "q9_when_you_wake_up_how_long_to_be_totally_with_it",
            "",
            array(
             null                   => "",
             "0_to_10_minutes"      => "0 to 10 minutes",
             "11_to_20_minutes"     => "11 to 20 minutes",
             "21_to_40_minutes"     => "21 to 40 minutes",
             "more_than_40_minutes" => "More than 40 minutes",
            )
        );
        $this->form->addGroup(
            $group,
            "page2_q9",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        /*
        $this->addSelect(
            "q10_when_do_you_have_most_energy_to_do_favorite_things",
            "10. When do you have the most energy to do your favorite things?",
            array(
             "morning_tired_in_evening"  => "Morning! I'm tired in the evening",
             "morning_more_than_evening" => "Morning more than evening",
             "evening_more_than_morning" => "Evening more than morning",
             "evening_tired_in_morning"  => "Evening! I'm tired in the morning",
            )
        );*/

        $group[] = $this->createLabel("<h3 style=\"text-align:left\">10. When do you have the most energy to do your favorite things?</h3>");
        $group[] = $this->createSelect(
            "q10_when_do_you_have_most_energy_to_do_favorite_things",
            "",
            array(
             null                        => "",
             "morning_tired_in_evening"  => "Morning! I'm tired in the evening",
             "morning_more_than_evening" => "Morning more than evening",
             "evening_more_than_morning" => "Evening more than morning",
             "evening_tired_in_morning"  => "Evening! I'm tired in the morning",
            )
        );
        $this->form->addGroup(
            $group,
            "page2_q10",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
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

    // to sum up values for the responses 
    function sumScaleScores($question_array, $record)
    {
        $sum = 0;

        foreach ($question_array as $q) {
            $sum += $this->getNumericalValue($record[$q]);
        }
        return $sum;
    }

    // to assign values to the responses 
    function getNumericalValue($record){

        return self::getResponseValue[$record];

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

	$scores["mornings_evenings_total_derived_score"] = $this->sumScaleScores(self::MORNINGNESS_EVENINGNESS, $record);

	$db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));

    }

}
