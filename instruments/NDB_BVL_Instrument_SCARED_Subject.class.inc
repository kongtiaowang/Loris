<?php
/**
 * This file contains the NDB_BVL_Instrument_SCARED_Subject class
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
 * Creates the form elements for the SCARED (Screen for Subject Anxiety Related Disorders) - Subject - Survey
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_SCARED_Subject extends NDB_BVL_Instrument
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
                        "sch_score",
                        "total_score",
                       );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCARED_Subject', "SCARED (Screen for Subject Anxiety Related Disorders) - Subject - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Subject','SCARED_Subject_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Subject','SCARED_Subject_page2', "Page 2", 2);
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
        $this->form     = new LorisForm('SCARED_Subject_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined Subject classes)

        // set the object properties
        $this->testName = "SCARED_Subject"; // test_names.Test_name
        $this->table    = 'SCARED_Subject'; // name of database table corresponding to instrument

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
        if (preg_match("/SCARED_Subject(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("SCARED (Screen for Anxiety Related Disorders) - Child - Subject - Survey");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->addHeader("This survey is for the PRIMARY subject in the research study.");

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
                   "sch"   => "Significant School Avoidance Symptoms (SCH)",
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
        $this->addHeader("SCARED (Screen for Anxiety Related Disorders) - Child - Subject - Survey");
        

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Directions:</strong><br><br>
            Below is a list of sentences that describe how people feel. Read each phrase and decide if it is
            \"Not True or Hardly Ever True\" or \"Somewhat True or Sometimes True\" or \"Very True or Often True\" for you.
            Then, for each sentence, select the response that seems to describe you <b><i>for the last 3 months</i></b>."
        );

        $page1_questions = array(
                            "q1_frightened_hard_to_breathe"                  => "1. When I feel frightened, it is hard to breathe.",
                            "q2_headaches_at_school"                         => "2. I get headaches when I am at school.",
                            "q3_dont_like_to_be_with_people_dont_know_well"  => "3. I don’t like to be with people I don’t know well.",
                            "q4_scared_if_sleep_away_from_home"              => "4. I get scared if I sleep away from home.",
                            "q5_worry_about_people_liking_me"                => "5. I worry about other people liking me.",
                            "q6_frightened_feel_like_passing_out"            => "6. When I get frightened, I feel like passing out.",
                            "q7_am_nervous"                                  => "7. I am nervous.",
                            "q8_follow_mother_or_father_wherever_they_go"    => "8. I follow my mother or father wherever they go.",
                            "q9_people_tell_look_nervous"                    => "9. People tell me that I look nervous.",
                            "q10_nervous_with_people_dont_know_well"         => "10. I feel nervous with people I don’t know well.",
                            "q11_stomachaches_at_school"                     => "11. I get stomachaches at school.",
                            "q12_frightened_feel_like_going_crazy"           => "12. When I get frightened, I feel like I am going crazy.",
                            "q13_worry_about_sleeping_alone"                 => "13. I worry about sleeping alone.",
                            "q14_worry_about_being_as_good_as_other_kids"    => "14. I worry about being as good as other kids.",
                            "q15_frightened_feel_like_things_are_not_real"   => "15. When I get frightened, I feel like things are not real.",
                            "q16_nightmares_something_bad_happening_parents" => "16. I have nightmares about something bad happening to my parents.",
                            "q17_worry_about_going_to_school"                => "17. I worry about going to school.",
                            "q18_frightened_heart_beats_fast"                => "18. When I get frightened, my heart beats fast.",
                            "q19_get_shaky"                                  => "19. I get shaky.",
                            "q20_nightmares_something_bad_happening_me"      => "20. I have nightmares about something bad happening to me.",
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
        $this->addHeader("SCARED (Screen for Anxiety Related Disorders) - Child - Subject - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Directions:</strong><br><br>
            Below is a list of sentences that describe how people feel. Read each phrase and decide if it is
            \"Not True or Hardly Ever True\" or \"Somewhat True or Sometimes True\" or \"Very True or Often True\" for you.
            Then, for each sentence, select the response that seems to describe you <b><i>for the last 3 months</i></b>."
        );

        $page2_questions = array(
                            "q21_worry_about_things_working_out"                        => "21. I worry about things working out for me.",
                            "q22_frightened_sweat_a_lot"                                => "22. When I get frightened, I sweat a lot.",
                            "q23_am_a_worrier"                                          => "23. I am a worrier.",
                            "q24_frightened_for_no_reason"                              => "24. I get really frightened for no reason at all.",
                            "q25_afraid_to_be_alone_in_house"                           => "25. I am afraid to be alone in the house.",
                            "q26_hard_to_talk_with_people_dont_know_well"               => "26. It is hard for me to talk with people I don’t know well.",
                            "q27_frightened_feel_like_choking"                          => "27. When I get frightened, I feel like I am choking.",
                            "q28_people_tell_worry_too_much"                            => "28. People tell me that I worry too much.",
                            "q29_dont_like_to_be_away_from_family"                      => "29. I don’t like to be away from my family.",
                            "q30_afraid_of_anxiety_or_panic_attacks"                    => "30. I am afraid of having anxiety (or panic) attacks.",
                            "q31_worry_something_bad_might_happen_parents"              => "31. I worry that something bad might happen to my parents.",
                            "q32_shy_with_people_dont_know_well"                        => "32. I feel shy with people I don’t know well.",
                            "q33_worry_about_the_future"                                => "33. I worry about what is going to happen in the future.",
                            "q34_frightened_feel_like_throwing_up"                      => "34. When I get frightened, I feel like throwing up.",
                            "q35_worry_about_how_well_do_things"                        => "35. I worry about how well I do things.",
                            "q36_scared_to_go_to_school"                                => "36. I am scared to go to school.",
                            "q37_worry_about_things_already_happened"                   => "37. I worry about things that have already happened.",
                            "q38_frightened_feel_dizzy"                                 => "38. When I get frightened, I feel dizzy.",
                            "q39_nervous_with_children_or_adults_do_something_watch_me" => "39. I feel nervous when I am with other children or adults and I have to do something while they watch me (for example: read aloud, speak, play a game, play a sport).",
                            "q40_nervous_going_to_any_place_with_people_dont_know_well" => "40. I feel nervous when I am going to parties, dances, or any place where there will be people that I don’t know well.",
                            "q41_am_shy"                                                => "41. I am shy.",
                           );

        foreach ($page2_questions as $field => $label) {
            $this->addSelect($field, $label, self::OPTIONS);
        }
    }


    function sumScaleScores($question_array, $record)
    {
        $sum = 0;

        foreach ($question_array as $q) {
            $sum += $record[$q];
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
                   "sch_score"   => 0,
                   "total_score" => 0,
                  );

        $scores["pa_so_score"] = $this->sumScaleScores(self::PA_SO, $record);
        $scores["ga_score"]    = $this->sumScaleScores(self::GA, $record);
        $scores["sep_score"]   = $this->sumScaleScores(self::SEP, $record);
        $scores["soc_score"]   = $this->sumScaleScores(self::SOC, $record);
        $scores["sch_score"]   = $this->sumScaleScores(self::SCH, $record);

        $scores["total_score"] = $scores["pa_so_score"] + $scores["ga_score"] + $scores["sep_score"] + $scores["soc_score"] + $scores["sch_score"];

        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    CONST OPTIONS = [
                     null => "",
                     "0"  => "0 - Not True or Hardly Ever True",
                     "1"  => "1 - Somewhat True or Sometimes True",
                     "2"  => "2 - Very True or Often True",
                    ];

    // 1, 6, 9, 12, 15, 18, 19, 22, 24, 27, 30, 34, 38
    CONST PA_SO = [
                   "q1_frightened_hard_to_breathe",
                   "q6_frightened_feel_like_passing_out",
                   "q9_people_tell_look_nervous",
                   "q12_frightened_feel_like_going_crazy",
                   "q15_frightened_feel_like_things_are_not_real",
                   "q18_frightened_heart_beats_fast",
                   "q19_get_shaky",
                   "q22_frightened_sweat_a_lot",
                   "q24_frightened_for_no_reason",
                   "q27_frightened_feel_like_choking",
                   "q30_afraid_of_anxiety_or_panic_attacks",
                   "q34_frightened_feel_like_throwing_up",
                   "q38_frightened_feel_dizzy",
                  ];

    // 5, 7, 14, 21, 23, 28, 33, 35, 37
    CONST GA = [
                "q5_worry_about_people_liking_me",
                "q7_am_nervous",
                "q14_worry_about_being_as_good_as_other_kids",
                "q21_worry_about_things_working_out",
                "q23_am_a_worrier",
                "q28_people_tell_worry_too_much",
                "q33_worry_about_the_future",
                "q35_worry_about_how_well_do_things",
                "q37_worry_about_things_already_happened",

               ];

    // 4, 8, 13, 16, 20, 25, 29, 31
    CONST SEP = [
                 "q4_scared_if_sleep_away_from_home",
                 "q8_follow_mother_or_father_wherever_they_go",
                 "q13_worry_about_sleeping_alone",
                 "q16_nightmares_something_bad_happening_parents",
                 "q20_nightmares_something_bad_happening_me",
                 "q25_afraid_to_be_alone_in_house",
                 "q29_dont_like_to_be_away_from_family",
                 "q31_worry_something_bad_might_happen_parents",

                ];

    // 3, 10, 26, 32, 39, 40, 41
    CONST SOC = [
                 "q3_dont_like_to_be_with_people_dont_know_well",
                 "q10_nervous_with_people_dont_know_well",
                 "q26_hard_to_talk_with_people_dont_know_well",
                 "q32_shy_with_people_dont_know_well",
                 "q39_nervous_with_children_or_adults_do_something_watch_me",
                 "q40_nervous_going_to_any_place_with_people_dont_know_well",
                 "q41_am_shy",
                ];

    // 2, 11, 17, 36
    CONST SCH = [
                 "q2_headaches_at_school",
                 "q11_stomachaches_at_school",
                 "q17_worry_about_going_to_school",
                 "q36_scared_to_go_to_school",
                ];
}
