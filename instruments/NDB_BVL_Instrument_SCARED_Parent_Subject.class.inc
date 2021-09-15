<?php
/**
 * This file contains the NDB_BVL_Instrument_SCARED_Parent_Subject class
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
 * Creates the form elements for the SCARED (Screen for Child Anxiety Related Disorders) - Parent - Subject - Survey
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_SCARED_Parent_Subject extends NDB_BVL_Instrument
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
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SCARED_Parent', "SCARED (Screen for Child Anxiety Related Disorders) - Parent - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Parent','SCARED_Parent_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SCARED_Parent','SCARED_Parent_page2', "Page 2", 2);
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
        $this->form     = new LorisForm('SCARED_Parent_Subject_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "SCARED_Parent_Subject"; // test_names.Test_name
        $this->table    = 'SCARED_Parent_Subject'; // name of database table corresponding to instrument

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
        if (preg_match("/SCARED_Parent_Subject(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("SCARED (Screen for Child Anxiety Related Disorders) - Parent - Subject - Survey");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->addHeader("Please fill out this survey about your child who is the PRIMARY subject in the research study.");

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
        $this->addHeader("SCARED (Screen for Child Anxiety Related Disorders) - Parent - Subject - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Directions:</strong><br><br>
            Below is a list of sentences that describe how people feel. Read each phrase and decide if it is
            \"Not True or Hardly Ever True\" or \"Somewhat True or Sometimes True\" or \"Very True or Often True\" for your child.
            Then, for each statement, select the response that seems to describe your child <b><i>for the last 3 months</i></b>.
            Please respond to all statements as well as you can, even if some do not seem to concern your child."
        );

        $page1_questions = array(
                            "q1_frightened_hard_to_breathe"                     => "1. When my child feels frightened, it is hard for him/her to breathe.",
                            "q2_headaches_at_school"                            => "2. My child gets headaches when he/she is at school.",
                            "q3_doesnt_like_to_be_with_people_doesnt_know_well" => "3. My child doesn’t like to be with people he/she doesn't know well.",
                            "q4_scared_if_sleeps_away_from_home"                => "4. My child gets scared if he/she sleeps away from home.",
                            "q5_worries_about_people_liking_him_or_her"         => "5. My child worries about other people liking him/her.",
                            "q6_frightened_feels_like_passing_out"              => "6. When my child gets frightened, he/she feels like passing out.",
                            "q7_is_nervous"                                     => "7. My child is nervous.",
                            "q8_follows_me_wherever_i_go"                       => "8. My child follows me wherever I go.",
                            "q9_people_tell_looks_nervous"                      => "9. People tell me that my child looks nervous.",
                            "q10_nervous_with_people_doesnt_know_well"          => "10. My child feels nervous with people he/she doesn’t know well.",
                            "q11_stomachaches_at_school"                        => "11. My child gets stomachaches at school.",
                            "q12_frightened_feels_like_going_crazy"             => "12. When my child gets frightened, he/she feels like he/she is going crazy.",
                            "q13_worries_about_sleeping_alone"                  => "13. My child worries about sleeping alone.",
                            "q14_worries_about_being_as_good_as_other_kids"     => "14. My child worries about being as good as other kids.",
                            "q15_frightened_feels_like_things_are_not_real"     => "15. When my child gets frightened, he/she feels like things are not real.",
                            "q16_nightmares_something_bad_happening_parents"    => "16. My child has nightmares about something bad happening to his/her parents.",
                            "q17_worries_about_going_to_school"                 => "17. My child worries about going to school.",
                            "q18_frightened_heart_beats_fast"                   => "18. When my child gets frightened, his/her heart beats fast.",
                            "q19_gets_shaky"                                    => "19. He/she gets shaky.",
                            "q20_nightmares_something_bad_happening_him_or_her" => "20. My child has nightmares about something bad happening to him/her.",
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
        $this->addHeader("SCARED (Screen for Child Anxiety Related Disorders) - Parent - Subject - Survey");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Directions:</strong><br><br>
            Below is a list of sentences that describe how people feel. Read each phrase and decide if it is
            \"Not True or Hardly Ever True\" or \"Somewhat True or Sometimes True\" or \"Very True or Often True\" for your child.
            Then, for each statement, select the response that seems to describe your child <b><i>for the last 3 months</i></b>.
            Please respond to all statements as well as you can, even if some do not seem to concern your child."
        );

        $page2_questions = array(
                            "q21_worries_about_things_working_out"                        => "21. My child worries about things working out for him/her.",
                            "q22_frightened_sweats_a_lot"                                 => "22. When my child gets frightened, he/she sweats a lot.",
                            "q23_is_a_worrier"                                            => "23. My child is a worrier.",
                            "q24_frightened_for_no_reason"                                => "24. My child gets really frightened for no reason at all.",
                            "q25_afraid_to_be_alone_in_house"                             => "25. My child is afraid to be alone in the house.",
                            "q26_hard_to_talk_with_people_doesnt_know_well"               => "26. It is hard for my child to talk with people he/she doesn't know well.",
                            "q27_frightened_feels_like_choking"                           => "27. When my child gets frightened, he/she feels like he/she is choking.",
                            "q28_people_tell_worries_too_much"                            => "28. People tell me that my child worries too much.",
                            "q29_doesnt_like_to_be_away_from_family"                      => "29. My child doesn't like to be away from his/her family.",
                            "q30_afraid_of_anxiety_or_panic_attacks"                      => "30. My child is afraid of having anxiety (or panic) attacks.",
                            "q31_worries_something_bad_might_happen_parents"              => "31. My child worries that something bad might happen to his/her parents.",
                            "q32_shy_with_people_doesnt_know_well"                        => "32. My child feels shy with people he/she doesn't know well.",
                            "q33_worries_about_the_future"                                => "33. My child worries about what is going to happen in the future.",
                            "q34_frightened_feels_like_throwing_up"                       => "34. When my child gets frightened, he/she feels like throwing up.",
                            "q35_worries_about_how_well_does_things"                      => "35. My child worries about how well he/she does things.",
                            "q36_scared_to_go_to_school"                                  => "36. My child is scared to go to school.",
                            "q37_worries_about_things_already_happened"                   => "37. My child worries about things that have already happened.",
                            "q38_frightened_feels_dizzy"                                  => "38. When my child gets frightened, he/she feels dizzy.",
                            "q39_nervous_with_children_or_adults_do_something_watch"      => "39. My child feels nervous when he/she is with other children or adults and he/she has to do something while they watch him/her (for example: read aloud, speak, play a game, play a sport).",
                            "q40_nervous_going_to_any_place_with_people_doesnt_know_well" => "40. My child feels nervous when he/she is going to parties, dances, or any place where there will be people that he/she doesn't know well.",
                            "q41_is_shy"                                                  => "41. My child is shy.",
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
                   "q6_frightened_feels_like_passing_out",
                   "q9_people_tell_looks_nervous",
                   "q12_frightened_feels_like_going_crazy",
                   "q15_frightened_feels_like_things_are_not_real",
                   "q18_frightened_heart_beats_fast",
                   "q19_gets_shaky",
                   "q22_frightened_sweats_a_lot",
                   "q24_frightened_for_no_reason",
                   "q27_frightened_feels_like_choking",
                   "q30_afraid_of_anxiety_or_panic_attacks",
                   "q34_frightened_feels_like_throwing_up",
                   "q38_frightened_feels_dizzy",
                  ];

    // 5, 7, 14, 21, 23, 28, 33, 35, 37
    CONST GA = [
                "q5_worries_about_people_liking_him_or_her",
                "q7_is_nervous",
                "q14_worries_about_being_as_good_as_other_kids",
                "q21_worries_about_things_working_out",
                "q23_is_a_worrier",
                "q28_people_tell_worries_too_much",
                "q33_worries_about_the_future",
                "q35_worries_about_how_well_does_things",
                "q37_worries_about_things_already_happened",
               ];

    // 4, 8, 13, 16, 20, 25, 29, 31
    CONST SEP = [
                 "q4_scared_if_sleeps_away_from_home",
                 "q8_follows_me_wherever_i_go",
                 "q13_worries_about_sleeping_alone",
                 "q16_nightmares_something_bad_happening_parents",
                 "q20_nightmares_something_bad_happening_him_or_her",
                 "q25_afraid_to_be_alone_in_house",
                 "q29_doesnt_like_to_be_away_from_family",
                 "q31_worries_something_bad_might_happen_parents",
                ];

    // 3, 10, 26, 32, 39, 40, 41
    CONST SOC = [
                 "q3_doesnt_like_to_be_with_people_doesnt_know_well",
                 "q10_nervous_with_people_doesnt_know_well",
                 "q26_hard_to_talk_with_people_doesnt_know_well",
                 "q32_shy_with_people_doesnt_know_well",
                 "q39_nervous_with_children_or_adults_do_something_watch",
                 "q40_nervous_going_to_any_place_with_people_doesnt_know_well",
                 "q41_is_shy",
                ];

    // 2, 11, 17, 36
    CONST SCH = [
                 "q2_headaches_at_school",
                 "q11_stomachaches_at_school",
                 "q17_worries_about_going_to_school",
                 "q36_scared_to_go_to_school",
                ];
}
