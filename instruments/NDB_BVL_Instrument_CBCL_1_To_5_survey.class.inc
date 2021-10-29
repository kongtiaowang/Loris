<?php
/**
 * This file contains the NDB_BVL_Instrument_CBCL_1_To_5_survey class
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
 * Creates the form elements for the CBCL_1_To_5_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_CBCL_1_To_5_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityRequired = false;

    var $scoreLabels = array(
                        "internal_raw_score",
                        "internal_t_score",
                        "internal_score_interpretation",

                        "external_raw_score",
                        "external_t_score",
                        "external_score_interpretation",

                        "total_raw_score",
                        "total_t_score",
                        "total_score_interpretation",

                        "emotional_raw_score",
                        "emotional_t_score",
                        "emotional_score_interpretation",
                        "emotional_percentile",

                        "anxious_raw_score",
                        "anxious_t_score",
                        "anxious_score_interpretation",
                        "anxious_percentile",

                        "somatic_raw_score",
                        "somatic_t_score",
                        "somatic_score_interpretation",
                        "somatic_percentile",

                        "withdrawn_raw_score",
                        "withdrawn_t_score",
                        "withdrawn_score_interpretation",
                        "withdrawn_percentile",

                        "aggressive_raw_score",
                        "aggressive_t_score",
                        "aggressive_score_interpretation",
                        "aggressive_percentile",

                        "sleep_raw_score",
                        "sleep_t_score",
                        "sleep_score_interpretation",
                        "sleep_percentile",

                        "attention_raw_score",
                        "attention_t_score",
                        "attention_score_interpretation",
                        "attention_percentile",

                        "dsm_affective_raw_score",
                        "dsm_affective_t_score",
                        "dsm_affective_score_interpretation",
                        "dsm_affective_percentile",

                        "dsm_anxiety_raw_score",
                        "dsm_anxiety_t_score",
                        "dsm_anxiety_score_interpretation",
                        "dsm_anxiety_percentile",

                        "dsm_mental_raw_score",
                        "dsm_mental_t_score",
                        "dsm_mental_score_interpretation",
                        "dsm_mental_percentile",

                        "dsm_attention_raw_score",
                        "dsm_attention_t_score",
                        "dsm_attention_score_interpretation",
                        "dsm_attention_percentile",

                        "dsm_oppose_raw_score",
                        "dsm_oppose_t_score",
                        "dsm_oppose_score_interpretation",
                        "dsm_oppose_percentile",

                        "other_raw_score",
                       );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('CBCL_1_To_5_survey', "CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CBCL_1_To_5_survey','CBCL_1_To_5_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CBCL_1_To_5_survey','CBCL_1_To_5_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CBCL_1_To_5_survey','CBCL_1_To_5_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('CBCL_1_To_5_survey','CBCL_1_To_5_survey_page4', "Page 4", 4);
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
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('CBCL_1_To_5_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "CBCL_1_To_5_survey";           // test_names.Test_name
        $this->table    = 'CBCL_1_To_5_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();



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
        if (preg_match("/CBCL_1_To_5_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                <i>*Please fill this form out with regard to your child who has enrolled in our study,
                NOT their older sibling with autism.</i>
                <br><br>
                Please fill out this form to reflect <b><i>your</i></b> view of the child's behavior
                even if other people might not agree. <b><i>Be sure to answer all items.</b></i>
            </h3>"
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

        $this->form->addElement('header', null, "Score Summary");

        //scoring column headers
        $group[] = $this->form->createElement('static', "raw_score", null, null);
        $group[] = $this->form->createElement('static', "t_score", null, null);
        $group[] = $this->form->createElement('static', "score_interpretation", null, null);
        $group[] = $this->form->createElement('static', "percentile", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
            'internal'      => "Internal",
            'external'      => "External",
            'total'         => "Total",
            'emotional'     => "EmotReact",
            'anxious'       => 'AnxDep',
            'somatic'       => 'SomatComp',
            'withdrawn'     => 'With',
            'aggressive'    => 'AggrBeh',
            'sleep'         => 'SleepProb',
            'attention'     => 'AttnProb',
            'other'         => 'Other',
            'dsm_affective' => 'dsm_affective',
            'dsm_anxiety'   => 'dsm_anxiety',
            'dsm_mental'    => 'dsm_pdd',
            'dsm_attention' => 'dsm_adhd',
            'dsm_oppose'    => 'dsm_odd',
        );

        $columnHeaders = array(
                          "raw_score"            => "Raw Score",
                          "t_score"              => "T Score",
                          "score_interpretation" => "Score Interpretation",
                          "percentile"           => "Percentile",
                         );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label)  {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                // other has: raw score
                // internal, external, and total have: raw score, t score, score interpretation
                // remaining scales have all 4: raw, t, score interpretation, percentile
                if ($field == "other") {
                    if ($scoreField == "raw_score") {
                        $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                    }
                } else if ($field == "internal" || $field == "external" || $field == "total") {
                    if ($scoreField != "percentile") {
                        $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                    }
                } else {
                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, false);
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
        $this->addHeader("CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                <i>*Please fill this form out with regard to your child who has enrolled in our study,
                NOT their older sibling with autism.</i>
                <br><br>
                For each item that describes your child <b><i>now or within the past 2 months</i></b>,
                please select <b><i>2</i></b> if the item is <b><i>very true or often true</b></i> of the child.
                Select the <b><i>1</i></b> if the item is <b><i>somewhat or sometimes true</b></i> of the child.
                If the item is <b><i>not true</i></b> of the child, select the <b><i>0</i></b>.
                Please answer all items as well as you can, even if some do not seem to apply to the child.<br><br>
                $this->indent 0 = Not True (as far as you know)<br>
                $this->indent 1 = Somewhat or Sometimes True<br>
                $this->indent 2 = Very True or Often True<br>
            </h3>"
        );

        $gender_options = array(
                           null   => "",
                           "boy"  => "Boy",
                           "girl" => "Girl",
                          );

        $this->addSelect("child_gender", "CHILD'S SEX", $gender_options);

        $this->addBasicText("child_age", "CHILD'S AGE <br><h5><i>(Please enter a numeric value between 0-100.)</i></h5>");

        $this->addBasicText("child_ethnic_group_race", "CHILD'S ETHNIC GROUP OR RACE");

        $this->addBasicDate('child_birthdate', "Child's Birthdate (if known)");

        $this->XINRegisterRule(
            "child_birthdate",
            array("child_birthdate{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addLabel(
            "<h3>PARENTS' USUAL TYPE OF WORK, even if not working now
                        <i>(Please be specific -- for example, auto mechanic, high school teacher, homemaker, laborer, lathe operator, shoe salesman, army sergeant.)</i></h3>"
        );

        $this->addBasicText("parent1_type_of_work", "PARENT 1 (or FATHER) TYPE OF WORK");

        $this->XINRegisterRule(
            "parent1_type_of_work",
            array("parent2_type_of_work{@}=={@}"),
            "Required."
        );

        $this->addBasicText("parent2_type_of_work", "PARENT 2 (or MOTHER) TYPE OF WORK");

        $this->XINRegisterRule(
            "parent2_type_of_work",
            array("parent1_type_of_work{@}=={@}"),
            "Required."
        );

        $options = array(
                    null => '',
                    '0'  => "0 = Not True (as far as you know)",
                    '1'  => "1 = Somewhat or Sometimes True",
                    '2'  => "2 = Very True or Often True",
                   );

        $page1_questions = array(
                            "q1_aches_or_pains"                         => "1. Aches or pains (without medical cause; <b><i>do not</i></b> include stomach or headaches)",
                            "q2_acts_too_young_for_age"                 => "2. Acts too young for age",
                            "q3_afraid_to_try_new_things"               => "3. Afraid to try new things ",
                            "q4_avoids_looking_others_in_the_eye"       => "4. Avoids looking others in the eye",
                            "q5_cant_concentrate_cant_pay_attention"    => "5. Can't concentrate, can't pay attention for long",
                            "q6_cant_sit_still_restless_or_hyperactive" => "6. Can't sit still, restless, or hyperactive ",
                            "q7_cant_stand_having_things_out_of_place"  => "7. Can't stand having things out of place",
                            "q8_cant_stand_waiting"                     => "8. Can't stand waiting; wants everything now",
                            "q9_chews_on_things_that_arent_edible"      => "9. Chews on things that aren't edible",
                            "q10_clings_to_adults_or_too_dependent"     => "10. Clings to adults or too dependent ",
                            "q11_constantly_seeks_help"                 => "11. Constantly seeks help",
                            "q12_constipated_doesnt_move_bowels"        => "12. Constipated, doesn't move bowels (when not sick)",
                            "q13_cries_a_lot"                           => "13. Cries a lot",
                            "q14_cruel_to_animals"                      => "14. Cruel to animals",
                            "q15_defiant"                               => "15. Defiant",
                            "q16_demands_must_be_met_immediately"       => "16. Demands must be met immediately ",
                            "q17_destroys_own_things"                   => "17. Destroys his/her own things ",
                            "q18_destroys_things_belonging_to_family"   => "18. Destroys things belonging to his/her family or other children ",
                            "q19_diarrhea_or_loose_bowels"              => "19. Diarrhea or loose bowels (when not sick)",
                            "q20_disobedient"                           => "20. Disobedient ",
                            "q21_disturbed_by_any_change_in_routine"    => "21. Disturbed by any change in routine ",
                            "q22_doesnt_want_to_sleep_alone"            => "22. Doesn't want to sleep alone ",
                            "q23_doesnt_answer_when_people_talk"        => "23. Doesn't answer when people talk to him/her ",
                            "q24_doesnt_eat_well"                       => "24. Doesn't eat well (describe): ",
                            "q25_doesnt_get_along_with_other_children"  => "25. Doesn't get along with other children",
                            "q26_doesnt_know_how_to_have_fun"           => "26. Doesn't know how to have fun; acts like a little adult",
                            "q27_doesnt_feel_guilty_after_misbehaving"  => "27. Doesn't seem to feel guilty after misbehaving",
                            "q28_doesnt_want_to_go_out_of_home"         => "28. Doesn't want to go out of home ",
                            "q29_easily_frustrated"                     => "29. Easily frustrated",
                           );

        foreach ($page1_questions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if (strpos($question, "(describe)") !== false) {
                $str = substr($key, 0, strpos($key, "_")+1)."describe";

                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");

                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey");

        $options = array(
                    null => '',
                    '0'  => "0 = Not True (as far as you know)",
                    '1'  => "1 = Somewhat or Sometimes True",
                    '2'  => "2 = Very True or Often True",
                   );

        $page2_questions = array(
                            "q30_easily_jealous"                          => "30. Easily jealous",
                            "q31_eats_drinks_things_that_are_not_food"    => "31. Eats or drinks things that are not food - <b><i>don't</i></b> include sweets (describe):",
                            "q32_fears_certain_animals_situations_places" => "32. Fears certain animals, situations, or places (describe):",
                            "q33_feelings_are_easily_hurt"                => "33. Feelings are easily hurt",
                            "q34_gets_hurt_a_lot_accident_prone"          => "34. Gets hurt a lot, accident-prone",
                            "q35_gets_in_many_fights"                     => "35. Gets in many fights",
                            "q36_gets_into_everything"                    => "36. Gets into everything ",
                            "q37_gets_upset_separated_from_parents"       => "37. Gets too upset when separated from parents",
                            "q38_has_trouble_getting_to_sleep"            => "38. Has trouble getting to sleep",
                            "q39_headaches"                               => "39. Headaches (without medical cause)",
                            "q40_hits_others"                             => "40. Hits others",
                            "q41_holds_breath"                            => "41. Holds his/her breath",
                            "q42_hurts_animals_or_people_without_meaning" => "42. Hurts animals or people without meaning to",
                            "q43_looks_unhappy_without_good_reason"       => "43. Looks unhappy without good reason",
                            "q44_angry_moods"                             => "44. Angry moods ",
                            "q45_nausea_feels_sick"                       => "45. Nausea, feels sick (without medical cause)",
                            "q46_nervous_movements_or_twitching"          => "46. Nervous movements or twitching (describe):",
                            "q47_nervous_highstrung_or_tense"             => "47. Nervous, highstrung, or tense",
                            "q48_nightmares"                              => "48. Nightmares",
                            "q49_overeating"                              => "49. Overeating",
                            "q50_overtired"                               => "50. Overtired",
                            "q51_shows_panic_for_no_good_reason"          => "51. Shows panic for no good reason ",
                            "q52_painful_bowel_movements"                 => "52. Painful bowel movements (without medical cause)",
                            "q53_physically_attacks_people"               => "53. Physically attacks people",
                            "q54_picks_nose_skin_or_other_parts_of_body"  => "54. Picks nose, skin, or other parts of body (describe):",
                           );

        foreach ($page2_questions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if (strpos($question, "(describe)") !== false) {
                $str = substr($key, 0, strpos($key, "_")+1)."describe";
                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");
                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey");

        $options = array(
                    null => '',
                    '0'  => "0 = Not True (as far as you know)",
                    '1'  => "1 = Somewhat or Sometimes True",
                    '2'  => "2 = Very True or Often True",
                   );

        $page3_questions = array(
                            "q55_plays_with_own_sex_parts_too_much"       => "55. Plays with own sex parts too much",
                            "q56_poorly_coordinated_or_clumsy"            => "56. Poorly coordinated or clumsy",
                            "q57_problems_with_eyes"                      => "57. Problems with eyes (without medical cause) (describe):",
                            "q58_punishment_doesnt_change_behavior"       => "58. Punishment doesn't change his/her behavior",
                            "q59_quickly_shifts_from_activity_to_another" => "59. Quickly shifts from one activity to another",
                            "q60_rashes_or_other_skin_problems"           => "60. Rashes or other skin problems (without medical cause)",
                            "q61_refuses_to_eat"                          => "61. Refuses to eat",
                            "q62_refuses_to_play_active_games"            => "62. Refuses to play active games",
                            "q63_repeatedly_rocks_head_or_body"           => "63. Repeatedly rocks head or body",
                            "q64_resists_going_to_bed_at_night"           => "64. Resists going to bed at night",
                            "q65_resists_toilet_training"                 => "65. Resists toilet training (describe):",
                            "q66_screams_a_lot"                           => "66. Screams a lot",
                            "q67_seems_unresponsive_to_affection"         => "67. Seems unresponsive to affection",
                            "q68_self_conscious_or_easily_embarrassed"    => "68. Self-conscious or easily embarrassed ",
                            "q69_selfish_or_wont_share"                   => "69. Selfish or won't share",
                            "q70_shows_little_affection_toward_people"    => "70. Shows little affection toward people",
                            "q71_shows_little_interest_in_things_around"  => "71. Shows little interest in things around him/her",
                            "q72_shows_too_little_fear_of_getting_hurt"   => "72. Shows too little fear of getting hurt",
                            "q73_too_shy_or_timid"                        => "73. Too shy or timid",
                            "q74_sleeps_less_than_most_kids"              => "74. Sleeps less than most kids during day and/or night (describe):",
                            "q75_smears_plays_with_bowel_movements"       => "75. Smears or plays with bowel movements",
                            "q76_speech_problem"                          => "76. Speech problem (describe):",
                            "q77_stares_into_space_seems_preoccupied"     => "77. Stares into space or seems preoccupied ",
                            "q78_stomachaches_or_cramps"                  => "78. Stomachaches or cramps (without medical cause)",
                           );

        foreach ($page3_questions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if (strpos($question, "(describe)") !== false) {
                $str = substr($key, 0, strpos($key, "_")+1)."describe";
                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");
                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }
    }

    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("CBCL (Child Behavior Checklist) 1.5 to 5 years - Survey");

        $options = array(
                    null => '',
                    '0'  => "0 = Not True (as far as you know)",
                    '1'  => "1 = Somewhat or Sometimes True",
                    '2'  => "2 = Very True or Often True",
                   );

        $page4_questions = array(
                            "q79_rapid_shifts_sadness_excitement"   => "79. Rapid shifts between sadness and excitement",
                            "q80_strange_behavior"                  => "80. Strange behavior (describe):",
                            "q81_stubborn_sullen_or_irritable"      => "81. Stubborn, sullen, or irritable",
                            "q82_sudden_changes_in_mood_feelings"   => "82. Sudden changes in mood or feelings",
                            "q83_sulks_a_lot"                       => "83. Sulks a lot",
                            "q84_talks_or_cries_out_in_sleep"       => "84. Talks or cries out in sleep",
                            "q85_temper_tantrums_or_hot_temper"     => "85. Temper tantrums or hot temper",
                            "q86_too_concerned_with_neatness"       => "86. Too concerned with neatness or cleanliness",
                            "q87_too_fearful_or_anxious"            => "87. Too fearful or anxious",
                            "q88_uncooperative"                     => "88. Uncooperative",
                            "q89_underactive_slow_moving"           => "89. Underactive, slow moving, or lacks energy",
                            "q90_unhappy_sad_or_depressed"          => "90. Unhappy, sad, or depressed",
                            "q91_unusually_loud"                    => "91. Unusually loud",
                            "q92_upset_by_new_people_or_situations" => "92. Upset by new people or situations (describe):",
                            "q93_vomiting_throwing_up"              => "93. Vomiting, throwing up (without medical cause)",
                            "q94_wakes_up_often_at_night"           => "94. Wakes up often at night",
                            "q95_wanders_away"                      => "95. Wanders away",
                            "q96_wants_a_lot_of_attention"          => "96. Wants a lot of attention",
                            "q97_whining"                           => "97. Whining",
                            "q98_withdrawn_doesnt_get_involved"     => "98. Withdrawn, doesn't get involved with others",
                            "q99_worries"                           => "99. Worries",
                           );

        foreach ($page4_questions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if (strpos($question, "(describe)") !== false) {
                $str = substr($key, 0, strpos($key, "_")+1)."describe";
                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");
                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }

        $this->form->addElement(
            'static',
            null,
            "<h3>100. Please write in any problems the child has that were not listed above.</h3>"
        );


        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Problem</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Rating</h4>"
        );
        $this->addGroup(
            $group,
            "page4_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i = 1; $i <= 3; $i++) {

            // $this->addLabel($i . ".");
            $group[] = $this->createLabel($i . ".");

            $group[] =& $this->createText(
                "q100_problem{$i}",
                "100. Problem {$i}"
            );
            $group[] =& $this->createSelect(
                "q100_problem" . $i . "_rating",
                "100. Problem {$i} Rating",
                $options
            );

            /*
            $this->addGroup(
                $group,
                "page4_table",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);*/

            $this->addGroup(
                $group,
                "q100_problem" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

            $this->XINRegisterRule(
                "q100_problem{$i}",
                array("q100_problem{$i}_rating{@}!={@}"),
                "Problem " . $i . " Required if Rating is given.",
                "q100_problem" . $i . "_group"
            );
            $this->XINRegisterRule(
                "q100_problem{$i}_rating",
                array("q100_problem{$i}{@}!={@}"),
                "Problem " . $i . " Rating Required if problem is given.",
                "q100_problem" . $i . "_group"
            );
        }

        $yes_no_options = array(
                           null  => '',
                           'no'  => "No",
                           'yes' => "Yes - Please describe",
                          );

        $this->addSelect("q101_does_child_have_illness_disability", "Does the child have any illness or disability (either physical or mental)?", $yes_no_options);

        $this->addBasicText("q101_if_yes_describe", "If yes, please describe:");

        $this->XINRegisterRule(
            "q101_if_yes_describe",
            array("q101_does_child_have_illness_disability{@}=={@}yes"),
            "This field should be left blank OR response in the related question should be changed."
        );

        $this->addTextAreaElement("q102_what_concerns_you_most_about_child", "What concerns you most about the child?");

        $this->addTextAreaElement("q103_describe_best_things_about_child", "Please describe the best things about the child:");

        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    function validate_main_page($values)
    {
         $errors = [];

        // Ensures "if other" field is blank when user selects a respondent that isn't "other"
        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

         return $errors;
    }

    function validate_page1($values)
    {
        $errors = [];

        // Validate child's age (0-100, no NA option)
        $this->validate_child_age($values, "child_age", $errors);

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        // Ensures "describe" field is blank when user doesn't select "yes"
        if ($values["q101_does_child_have_illness_disability"] != "yes") {
            $this->validate_empty_subquestions($values, ["q101_if_yes_describe"], $errors);
        }

        return $errors;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $scores['score_validity'] = null;

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());

        // q21, q46, q51, q79, q82, q83, q92, q97, q99
        $emotional = array(
                      $record['q21_disturbed_by_any_change_in_routine'],
                      $record['q46_nervous_movements_or_twitching'],
                      $record['q51_shows_panic_for_no_good_reason'],
                      $record['q79_rapid_shifts_sadness_excitement'],
                      $record['q82_sudden_changes_in_mood_feelings'],
                      $record['q83_sulks_a_lot'],
                      $record['q92_upset_by_new_people_or_situations'],
                      $record['q97_whining'],
                      $record['q99_worries'],
                     );

        // 'q10','q33','q37','q43','q47','q68','q87','q90'
        $anxious = array(
                    $record['q10_clings_to_adults_or_too_dependent'],
                    $record['q33_feelings_are_easily_hurt'],
                    $record['q37_gets_upset_separated_from_parents'],
                    $record['q43_looks_unhappy_without_good_reason'],
                    $record['q47_nervous_highstrung_or_tense'],
                    $record['q68_self_conscious_or_easily_embarrassed'],
                    $record['q87_too_fearful_or_anxious'],
                    $record['q90_unhappy_sad_or_depressed'],
                   );

        // 'q1','q7','q12','q19','q24','q39','q45','q52','q78','q86','q93'
        $somatic = array(
                    $record['q1_aches_or_pains'],
                    $record['q7_cant_stand_having_things_out_of_place'],
                    $record['q12_constipated_doesnt_move_bowels'],
                    $record['q19_diarrhea_or_loose_bowels'],
                    $record['q24_doesnt_eat_well'],
                    $record['q39_headaches'],
                    $record['q45_nausea_feels_sick'],
                    $record['q52_painful_bowel_movements'],
                    $record['q78_stomachaches_or_cramps'],
                    $record['q86_too_concerned_with_neatness'],
                    $record['q93_vomiting_throwing_up'],
                   );

        // 'q2','q4','q23','q62','q67','q70','q71','q98'
        $withdrawn = array(
                      $record['q2_acts_too_young_for_age'],
                      $record['q4_avoids_looking_others_in_the_eye'],
                      $record['q23_doesnt_answer_when_people_talk'],
                      $record['q62_refuses_to_play_active_games'],
                      $record['q67_seems_unresponsive_to_affection'],
                      $record['q70_shows_little_affection_toward_people'],
                      $record['q71_shows_little_interest_in_things_around'],
                      $record['q98_withdrawn_doesnt_get_involved'],
                     );

        // 'q22','q38','q48','q64','q74','q84','q94'
        $sleep = array(
                  $record['q22_doesnt_want_to_sleep_alone'],
                  $record['q38_has_trouble_getting_to_sleep'],
                  $record['q48_nightmares'],
                  $record['q64_resists_going_to_bed_at_night'],
                  $record['q74_sleeps_less_than_most_kids'],
                  $record['q84_talks_or_cries_out_in_sleep'],
                  $record['q94_wakes_up_often_at_night'],
                 );

        // 'q5','q6','q56','q59','q95'
        $attention = array(
                      $record['q5_cant_concentrate_cant_pay_attention'],
                      $record['q6_cant_sit_still_restless_or_hyperactive'],
                      $record['q56_poorly_coordinated_or_clumsy'],
                      $record['q59_quickly_shifts_from_activity_to_another'],
                      $record['q95_wanders_away'],
                     );

        // 'q8','q15','q16','q18','q20','q27','q29','q35','q40','q42',
        // 'q44','q53','q58','q66','q69','q81','q85','q88','q96'
        $agressive = array(
                      $record['q8_cant_stand_waiting'],
                      $record['q15_defiant'],
                      $record['q16_demands_must_be_met_immediately'],
                      $record['q18_destroys_things_belonging_to_family'],
                      $record['q20_disobedient'],
                      $record['q27_doesnt_feel_guilty_after_misbehaving'],
                      $record['q29_easily_frustrated'],
                      $record['q35_gets_in_many_fights'],
                      $record['q40_hits_others'],
                      $record['q42_hurts_animals_or_people_without_meaning'],
                      $record['q44_angry_moods'],
                      $record['q53_physically_attacks_people'],
                      $record['q58_punishment_doesnt_change_behavior'],
                      $record['q66_screams_a_lot'],
                      $record['q69_selfish_or_wont_share'],
                      $record['q81_stubborn_sullen_or_irritable'],
                      $record['q85_temper_tantrums_or_hot_temper'],
                      $record['q88_uncooperative'],
                      $record['q96_wants_a_lot_of_attention'],
                     );

        // 'q3','q9','q11','q13','q14','q17','q25','q26','q28','q30',
        // 'q31','q32','q34','q36','q41','q49','q50','q54','q55','q57',
        // 'q60','q61','q63','q65','q72','q73','q75','q76','q77','q80',
        // 'q89','q91'
        $other = array(
                  $record['q3_afraid_to_try_new_things'],
                  $record['q9_chews_on_things_that_arent_edible'],
                  $record['q11_constantly_seeks_help'],
                  $record['q13_cries_a_lot'],
                  $record['q14_cruel_to_animals'],
                  $record['q17_destroys_own_things'],
                  $record['q25_doesnt_get_along_with_other_children'],
                  $record['q26_doesnt_know_how_to_have_fun'],
                  $record['q28_doesnt_want_to_go_out_of_home'],
                  $record['q30_easily_jealous'],
                  $record['q31_eats_drinks_things_that_are_not_food'],
                  $record['q32_fears_certain_animals_situations_places'],
                  $record['q34_gets_hurt_a_lot_accident_prone'],
                  $record['q36_gets_into_everything'],
                  $record['q41_holds_breath'],
                  $record['q49_overeating'],
                  $record['q50_overtired'],
                  $record['q54_picks_nose_skin_or_other_parts_of_body'],
                  $record['q55_plays_with_own_sex_parts_too_much'],
                  $record['q57_problems_with_eyes'],
                  $record['q60_rashes_or_other_skin_problems'],
                  $record['q61_refuses_to_eat'],
                  $record['q63_repeatedly_rocks_head_or_body'],
                  $record['q65_resists_toilet_training'],
                  $record['q72_shows_too_little_fear_of_getting_hurt'],
                  $record['q73_too_shy_or_timid'],
                  $record['q75_smears_plays_with_bowel_movements'],
                  $record['q76_speech_problem'],
                  $record['q77_stares_into_space_seems_preoccupied'],
                  $record['q80_strange_behavior'],
                  $record['q89_underactive_slow_moving'],
                  $record['q91_unusually_loud'],
                 );

        // 'q13','q24','q38','q43','q49','q50','q71','q74','q89','q90'
        $dsm_affective = array(
                          $record['q13_cries_a_lot'],
                          $record['q24_doesnt_eat_well'],
                          $record['q38_has_trouble_getting_to_sleep'],
                          $record['q43_looks_unhappy_without_good_reason'],
                          $record['q49_overeating'],
                          $record['q50_overtired'],
                          $record['q71_shows_little_interest_in_things_around'],
                          $record['q74_sleeps_less_than_most_kids'],
                          $record['q89_underactive_slow_moving'],
                          $record['q90_unhappy_sad_or_depressed'],
                         );

        // q10','q22','q28','q32','q37','q47','q48','q51','q87','q99'
        $dsm_anxiety = array(
                        $record['q10_clings_to_adults_or_too_dependent'],
                        $record['q22_doesnt_want_to_sleep_alone'],
                        $record['q28_doesnt_want_to_go_out_of_home'],
                        $record['q32_fears_certain_animals_situations_places'],
                        $record['q37_gets_upset_separated_from_parents'],
                        $record['q47_nervous_highstrung_or_tense'],
                        $record['q48_nightmares'],
                        $record['q51_shows_panic_for_no_good_reason'],
                        $record['q87_too_fearful_or_anxious'],
                        $record['q99_worries'],
                       );

        // 'q3','q4','q7','q21','q23','q25','q63','q67','q70','q76','q80','q92','q98'
        $dsm_mental = array(
                       $record['q3_afraid_to_try_new_things'],
                       $record['q4_avoids_looking_others_in_the_eye'],
                       $record['q7_cant_stand_having_things_out_of_place'],
                       $record['q21_disturbed_by_any_change_in_routine'],
                       $record['q23_doesnt_answer_when_people_talk'],
                       $record['q25_doesnt_get_along_with_other_children'],
                       $record['q63_repeatedly_rocks_head_or_body'],
                       $record['q67_seems_unresponsive_to_affection'],
                       $record['q70_shows_little_affection_toward_people'],
                       $record['q76_speech_problem'],
                       $record['q80_strange_behavior'],
                       $record['q92_upset_by_new_people_or_situations'],
                       $record['q98_withdrawn_doesnt_get_involved'],
                      );

        // 'q5','q6','q8','q16','q36','q59'
        $dsm_attention = array(
                          $record['q5_cant_concentrate_cant_pay_attention'],
                          $record['q6_cant_sit_still_restless_or_hyperactive'],
                          $record['q8_cant_stand_waiting'],
                          $record['q16_demands_must_be_met_immediately'],
                          $record['q36_gets_into_everything'],
                          $record['q59_quickly_shifts_from_activity_to_another'],
                         );

        // 'q15','q20','q44','q81','q85','q88'
        $dsm_oppose = array(
                       $record['q15_defiant'],
                       $record['q20_disobedient'],
                       $record['q44_angry_moods'],
                       $record['q81_stubborn_sullen_or_irritable'],
                       $record['q85_temper_tantrums_or_hot_temper'],
                       $record['q88_uncooperative'],
                      );

        $scores = array();

        $scores['emotional_raw_score']  = $this->calculateRawScore($emotional);
        $scores['anxious_raw_score']    = $this->calculateRawScore($anxious);
        $scores['somatic_raw_score']    = $this->calculateRawScore($somatic);
        $scores['withdrawn_raw_score']  = $this->calculateRawScore($withdrawn);
        $scores['sleep_raw_score']      = $this->calculateRawScore($sleep);
        $scores['attention_raw_score']  = $this->calculateRawScore($attention);
        $scores['aggressive_raw_score'] = $this->calculateRawScore($aggressive);
        $scores['other_raw_score']      = $this->calculateRawScore($other);
        $scores['dsm_affective_raw_score'] = $this->calculateRawScore($dsm_affective);
        $scores['dsm_anxiety_raw_score']   = $this->calculateRawScore($dsm_anxiety);
        $scores['dsm_mental_raw_score']    = $this->calculateRawScore($dsm_mental);
        $scores['dsm_attention_raw_score'] = $this->calculateRawScore($dsm_attention);
        $scores['dsm_oppose_raw_score']    = $this->calculateRawScore($dsm_oppose);

        // Scoring for Q100:
        // default values
        $q100_max = 0;
        // Q100 RAW SCORE
        //$scores['q100_raw_scores'] = "N/A";

        $q100_1 = $record['q100_problem1_rating'];
        $q100_2 = $record['q100_problem2_rating'];
        $q100_3 = $record['q100_problem3_rating'];

        // OTHER RAW SCORE
        // if at least one of the q100 fields aren't empty, evaluate score
        if (!empty($q100_1) || !empty($q100_2) || !empty($q100_3)) {
            $q100_max = max($q100_1, $q100_2, $q100_3);
            //$scores['q100_raw_score'] = $q100_max;
        }

        $scores['other_raw_score'] += $q100_max;

        $scores['internal_raw_score'] = $scores['emotional_raw_score'] + $scores['anxious_raw_score'] + $scores['somatic_raw_score'] + $scores['withdrawn_raw_score'];
        $scores['external_raw_score'] = $scores['attention_raw_score'] + $scores['aggressive_raw_score'];
        $scores['total_raw_score']    = $scores['internal_raw_score'] + $scores['external_raw_score'] + $scores['sleep_raw_score'] + $scores['other_raw_score'];

        // CBCL_1_to_5_yrs_lookup Table
        // doesn't include 'other'
        $lookup_fields = array(
                          'internal'      => "Internal",
                          'external'      => "External",
                          'total'         => "Total",
                          'emotional'     => "EmotReact",
                          'anxious'       => 'AnxDep',
                          'somatic'       => 'SomatComp',
                          'withdrawn'     => 'With',
                          'aggressive'    => 'AggrBeh',
                          'sleep'         => 'SleepProb',
                          'attention'     => 'AttnProb',
                          'dsm_affective' => 'dsm_affective',
                          'dsm_anxiety'   => 'dsm_anxiety',
                          'dsm_mental'    => 'dsm_pdd',
                          'dsm_attention' => 'dsm_adhd',
                          'dsm_oppose'    => 'dsm_odd',
                         );

        $non_percent = array(
                        'internal',
                        'external',
                        'total',
                       );

        // Get T-Scores, Social Interpretation, Percentile
        foreach ($lookup_fields as $key => $value) {
            $field_raw_score = $key . "_raw_score";

            $query = "
                        SELECT
                            T, Percentile, Score_Interpretation
                        from
                            CBCL_1_to_5_yrs_lookup
                        WHERE
                            Raw = :raw_score
                        AND
                            Type = :scale
                    ";

            $where = array(
                      'raw_score' => $scores[$field_raw_score],
                      'scale'     => $value,
                     );

            $query_result = $db->pselectRow($query, $where);

            // T Score
            $field_t_score          = $key . "_t_score";
            $scores[$field_t_score] = $query_result['T'];

            // Score Interpretation
            $field_score_interpretation          = $key . "_score_interpretation";
            $scores[$field_score_interpretation] = $query_result['Score_Interpretation'];

            // Percentile
            if (!in_array($key, $non_percent)) {
                $field_percentile          = $key . "_percentile";
                $scores[$field_percentile] = $query_result['Percentile'];
            }
        }

        $result = $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
    }

    /**
    * Calculates raw score given a scale
    *
    * @param string $scale such as emotional, anxious, somatic, etc.
    *
    * @return int
    */
    function calculateRawScore($scale)
    {
        $raw_score = 0;

        // $value is the question's answer
        foreach ($scale as $value) {
            switch ($value) {
            case 0:
                break; // do nothing
            case 1:
                $raw_score += 1;
                break;
            case 2:
                $raw_score += 2;
                break;
            }
        }

        return $raw_score;
    }
}
?>
