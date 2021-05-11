<?php
/**
 * This file contains the NDB_BVL_Instrument_SCAARED_Adult class
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
 * Creates the form elements for the SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Survey
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_SCAARED_Adult extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
                        "pa_so_score",
                        "ga_score",
                        "sep_score",
                        "soc_score",
                        "total_score",
                       );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCAARED_Adult', "SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCAARED_Adult','SCAARED_Adult_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCAARED_Adult','SCAARED_Adult_page2', "Page 2", 2);
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
        $this->form     = new LorisForm('SCAARED_Adult_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "SCAARED_Adult"; // test_names.Test_name
        $this->table    = 'SCAARED_Adult'; // name of database table corresponding to instrument

        // data keyed by commentID
        $this->commentID   = $commentID;
        $config            =& NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
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
        if (preg_match("/SCAARED_Adult(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Survey");

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

        $this->form->addElement('text', 'other_specify', $this->indent . 'If other, specify:');

        $this->XINRegisterRule('other_specify', array('respondent{@}=={@}other'), 'Required if other');

        $this->form->addFormRule(array(&$this, 'validate_main_page'));

        // SCORING TABLE

        $this->form->addElement('header', 'score', "Score Summary");

        $group[] = $this->form->createElement('static', "score", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   "pa_so" => "Panic Disorder or Significant Somatic Symptoms (PA/SO)",
                   "ga"    => "Generalized Anxiety Disorder (GA)",
                   "sep"   => "Separation Anxiety Disorder (SEP)",
                   "soc"   => "Social Phobis Disorder (SOC)",
                   "total" => "Total ",
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
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Instructions:</strong><br><br>
            Below is a list of sentences that describe how people feel. Read each phrase and decide if it is
            \"Not True or Hardly Ever True\" or \"Somewhat True or Sometimes True\" or \"Very True or Often True\" for you.
            Then, for each sentence, select the response that seems to describe you now or <b><i>within the past 3 months</i></b>."
        );

        $page1_questions = array(
                            "q1_nervous_hard_to_breathe"                    => "1. When I feel nervous, it is hard for me to breathe.",
                            "q2_headaches_public_places"                    => "2. I get headaches when I am at school, at work or in public places.",
                            "q3_dont_like_to_be_with_people_dont_know_well" => "3. I don’t like to be with people I don’t know well.",
                            "q4_nervous_if_sleep_away_from_home"            => "4. I get nervous if I sleep away from home.",
                            "q5_worry_about_people_liking_me"               => "5. I worry about people liking me.",
                            "q6_anxious_feel_like_passing_out"              => "6. When I get anxious, I feel like passing out.",
                            "q7_am_nervous"                                 => "7. I am nervous.",
                            "q8_hard_to_stop_worrying"                      => "8. It is hard for me to stop worrying.",
                            "q9_people_tell_look_nervous"                   => "9. People tell me that I look nervous.",
                            "q10_nervous_with_people_dont_know_well"        => "10. I feel nervous with people I don’t know well.",
                            "q11_stomachaches_public_places"                => "11. I get stomachaches at school, at work, or in public places.",
                            "q12_anxious_feel_like_going_crazy"             => "12. When I get anxious, I feel like I'm going crazy.",
                            "q13_worry_about_sleeping_alone"                => "13. I worry about sleeping alone.",
                            "q14_worry_about_being_as_good_as_other_people" => "14. I worry about being as good as other people.",
                            "q15_anxious_feel_like_things_are_not_real"     => "15. When I get anxious, I feel like things are not real.",
                            "q16_nightmares_something_bad_happening_family" => "16. I have nightmares about something bad happening to my family.",
                            "q17_worry_about_going_to_public_places"        => "17. I worry about going to work or school, or to public places.",
                            "q18_anxious_heart_beats_fast"                  => "18. When I get anxious, my heart beats fast.",
                            "q19_get_shaky"                                 => "19. I get shaky.",
                            "q20_nightmares_something_bad_happening_me"     => "20. I have nightmares about something bad happening to me.",
                           );

        foreach ($page1_questions as $field => $label) {
            $this->addSelect($field, $label, self::OPTIONS);
        }
    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("SCAARED (Screen for Adult Anxiety Related Disorders) - Adult - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Instructions:</strong><br><br>
            Below is a list of sentences that describe how people feel. Read each phrase and decide if it is
            \"Not True or Hardly Ever True\" or \"Somewhat True or Sometimes True\" or \"Very True or Often True\" for you.
            Then, for each sentence, select the response that seems to describe you now or <b><i>within the past 3 months</i></b>."
        );

        $page2_questions = array(
                            "q21_worry_about_things_working_out"                     => "21. I worry about things working out for me.",
                            "q22_anxious_sweat_a_lot"                                => "22. When I get anxious, I sweat a lot.",
                            "q23_am_a_worrier"                                       => "23. I am a worrier.",
                            "q24_worry_trouble_sleeping"                             => "24. When I worry a lot, I have trouble sleeping.",
                            "q25_frightened_for_no_reason"                           => "25. I get really frightened for no reason at all.",
                            "q26_afraid_to_be_alone_in_house"                        => "26. I am afraid to be alone in the house.",
                            "q27_hard_to_talk_with_people_dont_know_well"            => "27. It is hard for me to talk with people I don't know well.",
                            "q28_anxious_feel_like_choking"                          => "28. When I get anxious, I feel like I'm choking.",
                            "q29_people_tell_worry_too_much"                         => "29. People tell me that I worry too much.",
                            "q30_dont_like_to_be_away_from_family"                   => "30. I don't like to be away from my family.",
                            "q31_worry_feel_restless"                                => "31. When I worry a lot, I feel restless.",
                            "q32_afraid_of_anxiety_or_panic_attacks"                 => "32. I am afraid of having anxiety (or panic) attacks.",
                            "q33_worry_something_bad_might_happen_family"            => "33. I worry that something bad might happen to my family.",
                            "q34_shy_with_people_dont_know_well"                     => "34. I feel shy with people I don't know well.",
                            "q35_worry_about_the_future"                             => "35. I worry about what is going to happen in the future.",
                            "q36_anxious_feel_like_throwing_up"                      => "36. When I get anxious, I feel like throwing up.",
                            "q37_worry_about_how_well_do_things"                     => "37. I worry about how well I do things.",
                            "q38_afraid_to_go_outside_crowded_places_myself"         => "38. I am afraid to go outside or to crowded places by myself.",
                            "q39_worry_about_things_already_happened"                => "39. I worry about things that have already happened.",
                            "q40_anxious_feel_dizzy"                                 => "40. When I get anxious, I feel dizzy.",
                            "q41_nervous_with_people_do_something_watch_me"          => "41. I feel nervous when I am with other people and I have to do something while they watch me (for example: speak, play a sport.)",
                            "q42_nervous_go_to_any_place_with_people_dont_know_well" => "42. I feel nervous when I go to parties, dances, or any place where there will be people that I don't know well.",
                            "q43_am_shy"                                             => "43. I am shy.",
                            "q44_worry_feel_irritable"                               => "44. When I worry a lot, I feel irritable.",
                           );

        foreach ($page2_questions as $field => $label) {
            $this->addSelect($field, $label, self::OPTIONS);
        }
    }

    function validate_main_page($values)
    {
        $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["other_specify"], $errors);
        }

        return $errors;
    }

    function sumScaleScores($question_array, $record)
    {
        $sum = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "2") {
                $sum += 2;
            } elseif ($record[$q] == "1") {
                $sum += 1;
            } else {
                // do nothing
            }
        }

        return $sum;
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

        $scores = array(
                   "pa_so_score" => 0,
                   "ga_score"    => 0,
                   "sep_score"   => 0,
                   "soc_score"   => 0,
                   "total_score" => 0,
                  );

        $scores["pa_so_score"] = $this->sumScaleScores(self::PA_SO, $record);
        $scores["ga_score"]    = $this->sumScaleScores(self::GA, $record);
        $scores["sep_score"]   = $this->sumScaleScores(self::SEP, $record);
        $scores["soc_score"]   = $this->sumScaleScores(self::SOC, $record);

        $scores["total_score"] = $scores["pa_so_score"] + $scores["ga_score"] + $scores["sep_score"] + $scores["soc_score"];

        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    CONST OPTIONS = [
                     null => "",
                     "0"  => "0 - Not True or Hardly Ever True",
                     "1"  => "1 - Somewhat True or Sometimes True",
                     "2"  => "2 - Very True or Often True",
                    ];

    // 1, 2, 6, 9, 11, 12, 15, 17, 18, 19, 22, 25, 28, 32, 36, 38, 40
    CONST PA_SO = [
                   "q1_nervous_hard_to_breathe",
                   "q2_headaches_public_places",
                   "q6_anxious_feel_like_passing_out",
                   "q9_people_tell_look_nervous",
                   "q11_stomachaches_public_places",
                   "q12_anxious_feel_like_going_crazy",
                   "q15_anxious_feel_like_things_are_not_real",
                   "q17_worry_about_going_to_public_places",
                   "q18_anxious_heart_beats_fast",
                   "q19_get_shaky",
                   "q22_anxious_sweat_a_lot",
                   "q25_frightened_for_no_reason",
                   "q28_anxious_feel_like_choking",
                   "q32_afraid_of_anxiety_or_panic_attacks",
                   "q36_anxious_feel_like_throwing_up",
                   "q38_afraid_to_go_outside_crowded_places_myself",
                   "q40_anxious_feel_dizzy",
                  ];

    // 5, 7, 8, 14, 21, 23, 24, 29, 31, 35, 37, 39, 44
    CONST GA = [
                "q5_worry_about_people_liking_me",
                "q7_am_nervous",
                "q8_hard_to_stop_worrying",
                "q14_worry_about_being_as_good_as_other_people",
                "q21_worry_about_things_working_out",
                "q23_am_a_worrier",
                "q24_worry_trouble_sleeping",
                "q29_people_tell_worry_too_much",
                "q31_worry_feel_restless",
                "q35_worry_about_the_future",
                "q37_worry_about_how_well_do_things",
                "q39_worry_about_things_already_happened",
                "q44_worry_feel_irritable",
               ];

    // 4, 13, 16, 20, 26, 30, 33
    CONST SEP = [
                 "q4_nervous_if_sleep_away_from_home",
                 "q13_worry_about_sleeping_alone",
                 "q16_nightmares_something_bad_happening_family",
                 "q20_nightmares_something_bad_happening_me",
                 "q26_afraid_to_be_alone_in_house",
                 "q30_dont_like_to_be_away_from_family",
                 "q33_worry_something_bad_might_happen_family",
                ];

    // 3, 10, 27, 34, 41, 42, 43
    CONST SOC = [
                 "q3_dont_like_to_be_with_people_dont_know_well",
                 "q10_nervous_with_people_dont_know_well",
                 "q27_hard_to_talk_with_people_dont_know_well",
                 "q34_shy_with_people_dont_know_well",
                 "q41_nervous_with_people_do_something_watch_me",
                 "q42_nervous_go_to_any_place_with_people_dont_know_well",
                 "q43_am_shy",
                ];
}