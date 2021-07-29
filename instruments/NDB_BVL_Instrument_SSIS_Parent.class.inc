<?php

/**
 *This file contains the NDB_BVL_Instrument_SSIS_Parent class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Mie Beers <mie.beers@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_SSIS_Parent instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Mie Beers <mie.beers@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_SSIS_Parent extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

     var $scoreLabels = array(
                         "social_skills_num_missing",
                         "social_skills_adjustment_value",
                         "social_skills_sum",
                         "social_skills_raw_score",
                         "social_skills_standard_score",
                         "social_skills_percentile",
                         "social_skills_ci_68",
                         "social_skills_ci_95",

                         "communication_num_missing",
                         "communication_adjustment_value",
                         "communication_sum",
                         "communication_raw_score",
                         "communication_behavior_level",

                         "cooperation_num_missing",
                         "cooperation_adjustment_value",
                         "cooperation_sum",
                         "cooperation_raw_score",
                         "cooperation_behavior_level",

                         "assertion_num_missing",
                         "assertion_adjustment_value",
                         "assertion_sum",
                         "assertion_raw_score",
                         "assertion_behavior_level",

                         "responsibility_num_missing",
                         "responsibility_adjustment_value",
                         "responsibility_sum",
                         "responsibility_raw_score",
                         "responsibility_behavior_level",

                         "empathy_num_missing",
                         "empathy_adjustment_value",
                         "empathy_sum",
                         "empathy_raw_score",
                         "empathy_behavior_level",

                         "engagement_num_missing",
                         "engagement_adjustment_value",
                         "engagement_sum",
                         "engagement_raw_score",
                         "engagement_behavior_level",

                         "self_control_num_missing",
                         "self_control_adjustment_value",
                         "self_control_sum",
                         "self_control_raw_score",
                         "self_control_behavior_level",

                         "problem_behaviors_num_missing",
                         "problem_behaviors_adjustment_value",
                         "problem_behaviors_sum",
                         "problem_behaviors_raw_score",
                         "problem_behaviors_standard_score",
                         "problem_behaviors_percentile",
                         "problem_behaviors_ci_68",
                         "problem_behaviors_ci_95",

                         "externalizing_num_missing",
                         "externalizing_adjustment_value",
                         "externalizing_sum",
                         "externalizing_raw_score",
                         "externalizing_behavior_level",

                         "bullying_num_missing",
                         "bullying_adjustment_value",
                         "bullying_sum",
                         "bullying_raw_score",
                         "bullying_behavior_level",

                         "hyperactivity_inattention_num_missing",
                         "hyperactivity_inattention_adjustment_value",
                         "hyperactivity_inattention_sum",
                         "hyperactivity_inattention_raw_score",
                         "hyperactivity_inattention_behavior_level",

                         "internalizing_num_missing",
                         "internalizing_adjustment_value",
                         "internalizing_sum",
                         "internalizing_raw_score",
                         "internalizing_behavior_level",

                         "autism_spectrum_A_num_missing",
                         "autism_spectrum_A_adjustment_value",
                         "autism_spectrum_A_sum",
                         "autism_spectrum_A_raw_score",
                         "autism_spectrum_A_behavior_level",

                         "autism_spectrum_B_num_missing",
                         "autism_spectrum_B_adjustment_value",
                         "autism_spectrum_B_sum",
                         "autism_spectrum_B_raw_score",
                         "autism_spectrum_B_behavior_level",

                         "f_index",
                         "f_index_interpretation",
                        );

    /**
     * Abstract function setup(?string $commentID = NULL, ?string $page = NULL): void;
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
        $this->form     = new LorisForm('SSIS_Parent_form');
        $this->page     = $page;            // page label

        // Set the object properties
        $this->testName = "SSIS_Parent";    // test_names.Test_name
        $this->table    = "SSIS_Parent";

        // Data keyed by commentID
        $this->commentID = $commentID;

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

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/SSIS_Parent(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        // Defines the call back function for HTML Quickform to use when validating the form.
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
        // Display test name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

        // Add date of administration field
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
                 null          => "",
                 "mother"      => "Mother",
                 "father"      => "Father",
                 "step_mother" => "Step Mother",
                 "step_father" => "Step Father",
                 "other"       => "Other",
                );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );

        // SCORING TABLE

        $this->form->addElement('header', null, "Score Summary");

        $group[] = $this->form->createElement('static', "num_missing", null, null);
        $group[] = $this->form->createElement('static', "adjustment_value", null, null);
        $group[] = $this->form->createElement('static', "sum", null, null);
        $group[] = $this->form->createElement('static', "raw_score", null, null);
        $group[] = $this->form->createElement('static', "standard_score", null, null);
        $group[] = $this->form->createElement('static', "percentile", null, null);
        $group[] = $this->form->createElement('static', "behavior_level", null, null);
        $group[] = $this->form->createElement('static', "ci_68", null, null);
        $group[] = $this->form->createElement('static', "ci_95", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   "social_skills"             => "<b>Social Skills</b>",
                   "communication"             => "Communication",
                   "cooperation"               => "Cooperation",
                   "assertion"                 => "Assertion",
                   "responsibility"            => "Responsibility",
                   "empathy"                   => "Empathy",
                   "engagement"                => "Engagement",
                   "self_control"              => "Self Control",
                   "problem_behaviors"         => "<b>Problem Behaviors</b>",
                   "externalizing"             => "Externalizing",
                   "bullying"                  => "Bullying",
                   "hyperactivity_inattention" => "Hyperactivity/Inattention",
                   "internalizing"             => "Internalizing",
                   "autism_spectrum_A"         => "<b>Autism Spectrum Part A</b>",
                   "autism_spectrum_B"         => "<b>Autism Spectrum Part B</b>",
                  );

        $columnHeaders = array(
                          "num_missing"      => "Number Missing",
                          "adjustment_value" => "Adjustment Value",
                          "sum"              => "Sum",
                          "raw_score"        => "Raw Score",
                          "standard_score"   => "Standard Score",
                          "percentile"       => "Percentile",
                          "behavior_level"   => "Behavior Level",
                          "ci_68"            => "68% CI",
                          "ci_95"            => "95% CI",
                         );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                if ($field == "social_skills" || $field == "problem_behaviors") {
                    if ($scoreField != "behavior_level") {
                        $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                    } else {
                        $group[] = $this->form->createElement('static', null, null, null);
                    }
                } else {
                    if ($scoreField != "standard_score" && $scoreField != "percentile" && $scoreField != "ci_68" && $scoreField != "ci_95") {
                        $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                    } else {
                        $group[] = $this->form->createElement('static', null, null, null);
                    }
                }
            }

            $this->form->addGroup($group, "{$field}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }

        $this->form->addElement('header', null, "F Index Summary");

        $group[] = $this->form->createElement('static', "value", null, null);

        $this->form->addGroup($group, 'f_index_header_group', "Field", $this->_GUIDelimiter, false);
        unset($group);

        $fIndexFields = array(
                         "f_index"                => "F Index",
                         "f_index_interpretation" => "Interpretation",
                        );

        $columnHeaders = array("value" => "Value");

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($fIndexFields as $field => $label) {
            $group[] = $this->form->createElement('static', "{$field}", null, null);
            $this->form->addGroup($group, "{$field}_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }
    }

    /**
     * Allows for the setup of 2 columns of subquestions for each question
     * Used in Social Skills section
     *
     * @return void
     */
    function _displayHeaders($category)
    {
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Frequency</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Problem</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $this->form->addGroup(
            $group,
            $category . "_group",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    /**
     * Generates the first page of the form
     *
     * @return void
     */
    function _page1()
    {
        // Commonly used level of indentation
        $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

        // Define variables for select options
        $respondent = array(
                       ''         => null,
                       'mother'   => '(Biological) Mother',
                       'father'   => '(Biological) Father',
                       'guardian' => 'Guardian',
                       'other'    => 'Other',
                      );
        $child_sex  = array(
                       ''       => null,
                       'male'   => 'Male',
                       'female' => 'Female',
                      );
        $adult_sex  = array(
                       ''       => null,
                       'male'   => 'Male',
                       'female' => 'Female',
                       'other'  => 'Other',
                      );
        $frequency  = array(
                       ''                => null,
                       'N_never'         => 'Never (N)',
                       'S_sometimes'     => 'Seldom (S)',
                       'O_often'         => 'Often (O)',
                       'A_almost_always' => 'Almost Always (A)',
                      );
        $importance = array(
                       ''                => null,
                       'n_not_important' => 'not important (n)',
                       'i_important'     => 'important (i)',
                       'c_critical'      => 'critical (c)',
                      );

        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

        // Add field for child's age
        $this->addBasicText("child_age", "Child's Age <h5><i>(Please indicate your child's age in years.)</i></h5>");

        // Add field for child's grade
        $this->addBasicText("child_grade", "Child's Grade in School <h5><i>(Please enter a numeric value between 1-12, K, or write NA if you don't know.)</i></h5>");

        // Add select for sex of child
        $this->addSelect('child_sex', "Child's sex at birth", $child_sex);

        // Add optional field for any other data relating to the child
        $this->addBasicText("child_other_data", "Other data about your child");
        $this->XINRegisterRule('child_other_data', array("child_other_data{@}=={@}NEVER_REQUIRED"));

        // Add select for sex of parent
        $this->addSelect('respondent_sex', "Your sex", $adult_sex);

        // Add field for respondent's relationship to child, including mandatory text field for "other" selection
        $this->addSelect('respondent', "Your relationship to child", $respondent);
        $group[] = $this->createText('respondent_other', $indent."If other please specify");
        $this->addGroup($group, "respondent_other_group", $indent."If other please specify", null, false);
        unset($group);
        $rules_array = array("respondent{@}=={@}other");
        $this->XINRegisterRule('respondent_other', $rules_array, "Please specify relationship", 'respondent_other_group');

        // Instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>Please read each item and think about your child's behavior during the past two months. Then, decide <b>how often</b> your child displays the behavior. For each of the Social Skills items, please also rate <b>how important</b> you think the behavior is for your child's development.");

        // Indicate the name of the section
        $this->form->addElement('header', 'instrument_title1', "Social Skills");

        // First group of questions
        $this->form->addElement('static', null);
        $questions = array(
                      "q1_expresses_feelings"           => "1. Expresses feelings when wronged.",
                      "q2_household_rules"              => "2. Follows household rules.",
                      "q3_understand_your_feelings"     => "3. Tries to understand how you feel.",
                      "q4_thank_you"                    => '4. Says "thank you."',
                      "q5_asks_for_help"                => "5. Asks for help from adults.",
                      "q6_borrowing_with_care"          => "6. Takes care when using other people's things.",
                      "q7_attention_to_instructions"    => "7. Pays attention to your instructions.",
                      "q8_makes_others_feel_better"     => "8. Tries to make others feel better.",
                      "q9_joins_activities"             => "9. Joins activities that have already started.",
                      "q10_takes_turns_conversation"    => "10. Takes turns in conversations.",
                      "q11_shares_problem"              => "11. Says when there is a problem.",
                      "q12_works_well_family"           => "12. Works well with family members.",
                      "q13_forgives"                    => "13. Forgives others.",
                      "q14_appropriate_tone"            => "14. Speaks in appropriate tone of voice.",
                      "q15_stands_up_for_others"        => "15. Stands up for others who are treated unfairly.",
                      "q16_well_behaved"                => "16. Is well-behaved when unsupervised.",
                      "q17_follows_directions"          => "17. Follows your directions.",
                      "q18_understand_others_feelings"  => "18. Tries to understand how others feel.",
                      "q19_starts_conversations"        => "19. Starts conversations with peers.",
                      "q20_uses_gestures_appropriately" => "20. Uses gestures or body appropriately with others.",
                     );

        // Display questions with two columns, one for a frequency rating and one for an importance rating
        $this->_displayHeaders("questions");
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $frequency
            );
            $group[] = $this->createSelect(
                $question . "_importance",
                "",
                $importance
            );
            $this->form->addGroup(
                $group,
                $question . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }

        // Validate text fields using instrument validator class
        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Generates the second page of the form
     *
     * @return void
     */
    function _page2()
    {
        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

        // Define variables for select options
        $frequency = array(
                      ''                => null,
                      'N_never'         => 'Never (N)',
                      'S_sometimes'     => 'Seldom (S)',
                      'O_often'         => 'Often (O)',
                      'A_almost_always' => 'Almost Always (A)',
                     );

        $importance = array(
                       ''                => null,
                       'n_not_important' => 'not important (n)',
                       'i_important'     => 'important (i)',
                       'c_critical'      => 'critical (c)',
                      );

        // Second group of questions
        $questions = array(
                      "q21_resolves_disagreements"      => "21. Resolves disagreements with you calmly.",
                      "q22_respects_property"           => "22. Respects the property of others.",
                      "q23_makes_friends"               => "23. Makes friends easily.",
                      "q24_says_please"                 => '24. Says "please."',
                      "q25_questions_unfair_rules"      => "25. Questions rules that may be unfair.",
                      "q26_takes_responsibility"        => "26. Takes responsibility for her/his own actions.",
                      "q27_completes_tasks"             => "27. Completes tasks without bothering others.",
                      "q28_comforts_others"             => "28. Tries to comfort others.",
                      "q29_interacts_with_children"     => "29. Interacts well with other children.",
                      "q30_start_conversation_activity" => "30. Responds well when others start a conversation or activity.",
                      "q31_calm_teased"                 => "31. Stays calm when teased.",
                      "q32_does_what_promised"          => "32. Does what she/he promised.",
                      "q33_introduces_to_others"        => "33. Introduces herself/himself to others.",
                      "q34_takes_criticism"             => "34. Takes criticism without getting upset.",
                      "q35_nice_without_bragging"       => "35. Says nice things about herself/himself without bragging.",
                      "q36_compromise_conflict"         => "36. Makes a compromise during a conflict.",
                      "q37_follows_game_rules"          => "37. Follows rules when playing games with others.",
                      "q38_shows_concern"               => "38. Shows concern for others.",
                      "q39_invites_others"              => "39. Invites others to join in activities.",
                      "q40_makes_eye_contact"           => "40. Makes eye contact when talking.",
                      "q41_tolerates_annoying_peers"    => "41. Tolerates peers when they are annoying.",
                      "q42_responsibility_for_mistakes" => "42. Takes responsibility for her/his own mistakes.",
                      "q43_conversations_with_adults"   => "43. Starts conversations with adults.",
                      "q44_responds_when_pushes"        => "44. Responds appropriately when pushed or hit.",
                      "q45_stands_up_for_self"          => "45. Stands up for herself/himself when treated unfairly.",
                      "q46_calm_disagreement"           => "46. Stays calm when disagreeing with others.",
                     );

        // Display questions with two columns, one for a frequency rating and one for an importance rating
        $this->_displayHeaders("questions");
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $frequency
            );
            $group[] = $this->createSelect(
                $question . "_importance",
                "",
                $importance
            );
            $this->form->addGroup(
                $group,
                $question . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3()
    {
        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

        // Indicate the name of the section
        $this->form->addElement('header', 'instrument_title2', "Problem Behaviors");

        // Define variable for select options
        $frequency = array(
                      ''                => null,
                      'N_never'         => 'Never (N)',
                      'S_sometimes'     => 'Seldom (S)',
                      'O_often'         => 'Often (O)',
                      'A_almost_always' => 'Almost Always (A)',
                     );

        // Third group of questions
        $questions = array(
                      "q47_difficulty_waiting_turn"     => "47. Has difficulty waiting for turn.",
                      "q48_repeats_same_thing"          => "48. Repeats the same thing over and over.",
                      "q49_forces_against_will"         => "49. Forces others to act against their will.",
                      "q50_stereotyped_motor_behaviors" => "50. Has stereotyped motor behaviors.",
                      "q51_fidgets_moves"               => "51. Fidgets or moves around too much.",
                      "q52_excludes_social_circles"     => "52. Keeps others out of social circles.",
                      "q53_inattentive"                 => "53. Is inattentive.",
                      "q54_acts_without_thinking"       => "54. Acts without thinking.",
                      "q55_upset_when_routines_change"  => "55. Becomes upset when routines change.",
                      "q56_aggressive_people_objects"   => "56. Is aggressive toward people or objects.",
                      "q57_withdraws_from_others"       => "57. Withdraws from others.",
                      "q58_temper_tantrums"             => "58. Has temper tantrums.",
                      "q59_makes_others_scared"         => "59. Does things to make others feel scared.",
                      "q60_breaks_group_activities"     => "60. Breaks into or stops group activities.",
                      "q61_low_energy_lethargic"        => "61. Has low energy or is lethargic.",
                      "q62_odd_gestures"                => "62. Uses odd physical gestures in interactions.",
                     );

        // Implement response selection for each question
        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $frequency);
        }
    }

    /**
     * Generates the fourth page of the form
     *
     * @return void
     */
    function _page4()
    {
        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

        // Define variable for select options
        $frequency = array(
                      ''                => null,
                      'N_never'         => 'Never (N)',
                      'S_sometimes'     => 'Seldom (S)',
                      'O_often'         => 'Often (O)',
                      'A_almost_always' => 'Almost Always (A)',
                     );

        // Fourth group of questions
        $questions = array(
                      "q63_bullies"                  => "63. Bullies others.",
                      "q64_anxious_with_others"      => "64. Acts anxious with others.",
                      "q65_talks_back"               => "65. Talks back to adults.",
                      "q66_nobody_likes_them"        => "66. Says nobody likes her/him.",
                      "q67_easily_distracted"        => "67. Gets distracted easily.",
                      "q68_sad_depressed"            => "68. Acts sad or depressed.",
                      "q69_preoccupied_object_parts" => "69. Is preoccupied with object parts.",
                      "q70_disobeys_rules"           => "70. Disobeys rules or requests.",
                      "q71_sleeping_problems"        => "71. Has sleeping problems.",
                      "q72_lies"                     => "72. Lies or does not tell the truth.",
                      "q73_gets_embarrassed"         => "73. Gets embarrassed easily.",
                      "q74_says_bad_about_self"      => "74. Says bad things about self.",
                      "q75_nonfunctional_routines"   => "75. Has nonfunctional routines or rituals.",
                      "q76_cheats_games"             => "76. Cheats in games or activities.",
                      "q77_acts_lonely"              => "77. Acts lonely.",
                      "q78_fights_others"            => "78. Fights with others.",
                      "q79_eating_problems"          => "79. Has eating problems.",
                     );

        // Implement response selection for each question
        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $frequency);
        }
    }

    /**
     * Validates the text fields on page 1 using the instrument validator class
     */
    function validate_page1($values)
    {
        $errors = [];
        $this->validate_child_age($values, "child_age", $errors);
        $this->validate_grade($values, "child_grade", $errors);
        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_other"], $errors);
        }

        return $errors;
    }

    function countNotAnswered($question_array, $record)
    {
        $count = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "not_answered") {
                $count++;
            }
        }

        return $count;
    }

    function calculateAdjustmentValue($adjustment_factor, $missing_count)
    {
        return $adjustment_factor * $missing_count;
    }

    function calculateItemSum($question_array, $record)
    {
        $count = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "A_almost_always") {
                $count += 3;
            } elseif ($record[$q] == "O_often") {
                $count += 2;
            } elseif ($record[$q] == "S_sometimes") {
                $count += 1;
            } else {
                // do nothing
            }
        }

        return $count;
    }

    function getStandardAndPercentile(string $age_range, string $sex, string $scale, int $raw_score, $db)
    {
        $standard   = null;
        $percentile = null;

        $query = "SELECT
                      *
                  FROM
                      SSIS_Parent_lookup
                  WHERE
                      age_range = :age_range AND
                      sex = :sex AND
                      scale = :scale AND
                      raw_score = :raw_score";

        $record = $db->pselectRow(
            $query,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "scale"     => $scale,
             "raw_score" => $raw_score,
            )
        );

        if (!is_null($record)) {
            if (array_key_exists('standard_score', $record)) {
                $standard = $record['standard_score'];
            }
            if (array_key_exists('percentile', $record)) {
                $percentile = $record['percentile'];
            }
        }

        return [
                $standard,
                $percentile,
               ];
    }

    function getBehaviorLevel(string $age_range, string $sex, string $subscale, int $subscale_raw_score, $db)
    {
        $behavior_level = "";

        $query = "SELECT
                      *
                  FROM
                      SSIS_Behavior_lookup
                  WHERE
                      form = 'Parent' AND
                      age_range = :age_range AND
                      sex = :sex AND
                      subscale = :subscale";

        $record = $db->pselect(
            $query,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "subscale"  => $subscale,
            )
        );

        foreach ($record as $r) {
            if (is_null($r["raw_score_min"]) && is_null($r["raw_score_max"])) {
                continue;
            } else {
                if ($subscale_raw_score >= $r["raw_score_min"] && $subscale_raw_score <= $r["raw_score_max"]) {
                    $behavior_level = $r["behavior_level"];
                }
            }
        }

        return $behavior_level;
    }

    function getCI(string $age_range, string $sex, string $scale, $db)
    {
        $ci_68 = null;
        $ci_95 = null;

        $query_68 = "SELECT
                      *
                  FROM
                      SSIS_CI_lookup
                  WHERE
                      form = 'Parent' AND
                      age_range = :age_range AND
                      sex = :sex AND
                      scale = :scale AND
                      confidence_level = '68%'";

        $record = $db->pselectRow(
            $query_68,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "scale"     => $scale,
            )
        );

        if (!is_null($record)) {
            if (array_key_exists('confidence_interval_value', $record)) {
                $ci_68 = $record['confidence_interval_value'];
            }
        }

        $query_95 = "SELECT
                      *
                  FROM
                      SSIS_CI_lookup
                  WHERE
                      form = 'Parent' AND
                      age_range = :age_range AND
                      sex = :sex AND
                      scale = :scale AND
                      confidence_level = '95%'";

        $record = $db->pselectRow(
            $query_95,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "scale"     => $scale,
            )
        );

        if (!is_null($record)) {
            if (array_key_exists('confidence_interval_value', $record)) {
                $ci_95 = $record['confidence_interval_value'];
            }
        }

        return [
                $ci_68,
                $ci_95,
               ];
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // Null scores
        $this->_nullScores($this->scoreLabels);

        // Get saved data
        $db     = Database::singleton();
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" => $this->getCommentID()));

        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob       = $timepoint->getEffectiveDateOfBirth();
        $age       = Utility::calculateAge($dob, $record["Date_taken"]);
        $age_years = $age['year'];

        $query = "SELECT
                      Sex
                  FROM
                      candidate as c,
                      session as s,
                      flag as f,
                      $this->table as t
                  WHERE
                      t.CommentID = '$this->commentID' AND
                      f.CommentID=t.CommentID AND
                      s.ID=f.SessionID AND
                      s.CandID=c.CandID";

        $record_sex = $db->pselectRow($query, array());
        $sex        = $record_sex['Sex'];

        /*
         * Scales and subscales:
         *
         * - Social Skills (Questions: 1-46)
         *      - Communication
         *      - Cooperation
         *      - Assertion
         *      - Responsibility
         *      - Empathy
         *      - Engagement
         *      - Self-Control
         * - Problem Behaviors (Questions: 47-79)
         *      - Externalizing
         *      - Bullying
         *      - Hyperactivity/Inattention
         *      - Internalizing
         * - Autism Spectrum (Questions: 10, 19, 20, 29, 30, 38-40, 48, 50, 55, 57, 62, 69, 75)
         *      - Part A
         *      - Part B
         */

        // Initialize score array
        $scores = array();

        /*
         * The 2 Scales (Social Skills, Problem Behaviors) have the following fields:
         *
         * _num_missing      = # of questions answered with "Not Answered"
         * _adjustment_value = # of questions answered with "Not Answered" * adjustment factor
         *  _sum             = sum of item scores (N = 0, S = 1, O = 2, A = 3, etc.)
         * _raw_score        = sum + adjustment value
         * _standard_score   = retrieved from SSIS_Parent_lookup
         * _percentile       = retrieved from SSIS_Parent_lookup
         * _ci_68            = retrieved from SSIS_CI_lookup
         * _ci_95            = retrieved from SSIS_CI_lookup
         */
        foreach (self::SCALES as $key => $value) {
            $scores[$key . "_num_missing"]      = null;
            $scores[$key . "_adjustment_value"] = null;
            $scores[$key . "_sum"]            = null;
            $scores[$key . "_raw_score"]      = null;
            $scores[$key . "_standard_score"] = null;
            $scores[$key . "_percentile"]     = null;
            $scores[$key . "_ci_68"]          = null;
            $scores[$key . "_ci_95"]          = null;
        }

        /*
         * The Subscales have the following fields:
         *
         * _num_missing      = # of questions answered with "Not Answered"
         * _adjustment_value = # of questions answered with "Not Answered" * adjustment factor
         *  _sum             = sum of item scores (N = 0, S = 1, O = 2, A = 3, etc.)
         * _raw_score        = sum + adjustment value
         * _behavior_level   = retrieved from SSIS_Behavior_lookup
         */
        foreach (self::SUBSCALES as $key => $value) {
            $scores[$key . "_num_missing"]      = null;
            $scores[$key . "_adjustment_value"] = null;
            $scores[$key . "_sum"]            = null;
            $scores[$key . "_raw_score"]      = null;
            $scores[$key . "_behavior_level"] = null;
        }

        $scores["f_index"] = null;
        $scores["f_index_interpretation"] = null;

        /********************************************************************
         * STEP 1: Determining Adjustment Values for Missing Item Responses *
         ********************************************************************
         *
         * Count # of questions answered with "Not Answered" for each scale & subscale
         * Calculate the adjustment value for each scale & subscale
         */

        foreach (self::SUBSCALE_ARRAYS as $key => $value) {
             $scores[$key . "_num_missing"]      = $this->countNotAnswered($value, $record);
             $scores[$key . "_adjustment_value"] = $this->calculateAdjustmentValue(self::ADJUSTMENT_FACTORS[$key], $scores[$key . "_num_missing"]);;
        }

        // If the adjustment values for any of the scales exceeds the maximum,
        // do not continue to score that scale and its subscales
        foreach (self::SCALE_ARRAYS as $key => $value) {
             $scores[$key . "_num_missing"] = $this->countNotAnswered($value, $record);

            if ($scores[$key . "_num_missing"] <= self::MAX_MISSING[$key]) {
                $scores[$key . "_adjustment_value"] = $this->calculateAdjustmentValue(self::ADJUSTMENT_FACTORS[$key], $scores[$key . "_num_missing"]);
            } else {
                $scores[$key . "_adjustment_value"] = "Number of items missing exceeds maximum (" . self::MAX_MISSING[$key] . ")";
            }
        }

        /***************************************************
         * STEP 2: Computing Scale and Subscale Raw Scores *
         ***************************************************
         *
         * Sum the responses for each scale and subscale
         *   N = 0
         *   S = 1
         *   O = 2
         *   A = 3
         */

        foreach (self::SUBSCALE_ARRAYS as $key => $value) {
            $scores[$key . "_sum"] = $this->calculateItemSum($value, $record);
        }

        $scores["social_skills_sum"] = $scores["communication_sum"] +
                                       $scores["cooperation_sum"] +
                                       $scores["assertion_sum"] +
                                       $scores["responsibility_sum"] +
                                       $scores["empathy_sum"] +
                                       $scores["engagement_sum"] +
                                       $scores["self_control_sum"];

        $scores["problem_behaviors_sum"] = $scores["externalizing_sum"] +
                                           $scores["bullying_sum"] +
                                           $scores["hyperactivity_inattention_sum"] +
                                           $scores["internalizing_sum"];

        //$scores["academic_competence_sum"] = $this->calculateACSum(self::ACADEMIC_COMPETENCE, $record);

        /***********************************
         * STEP 3: Calculating the F Index *
         ***********************************
         *
         * Count the number of circled unshaded rating value(s) to get the F-Index and its interpretation
         */

        $unshaded_ratings = array(
                             "q2_household_rules_frequency"          => "N_never",
                             "q12_works_well_family_frequency"       => "N_never",
                             "q17_follows_directions_frequency"      => "N_never",
                             "q24_says_please_frequency"             => "N_never",
                             "q29_interacts_with_children_frequency" => "N_never",
                             "q49_forces_against_will"               => "A_almost_always",
                             "q52_excludes_social_circles"           => "A_almost_always",
                             "q56_aggressive_people_objects"         => "A_almost_always",
                             "q57_withdraws_from_others"             => "A_almost_always",
                             "q59_makes_others_scared"               => "A_almost_always",
                            );

        $f_index_count = 0;

        foreach ($unshaded_ratings as $key => $value) {
            if ($record[$key] == $value) {
                $f_index_count++;
            }
        }

        $scores["f_index"] = $f_index_count;

        if ($f_index_count == 0 || $f_index_count == 1) {
            $scores["f_index_interpretation"] = "Acceptable";
        } elseif ($f_index_count == 2 || $f_index_count == 3) {
            $scores["f_index_interpretation"] = "Caution";
        } else {
            $scores["f_index_interpretation"] = "Extreme Caution";
        }

        /****************************************
         * STEP 4: Completing the Summary Table *
         ****************************************
         *
         * Add each subscale sum to its adjustment value to get the Raw Score
         * If the Candidate's age is valid, get the Standard and Percentile scores, Behavior levels, and Confidence Interval Value
         */

        // Add each subscale sum to its adjustment value
        foreach (self::SUBSCALES as $key => $value) {
            $scores[$key . "_raw_score"] = $scores[$key . "_sum"] + $scores[$key . "_adjustment_value"];
        }

        if (strpos($scores["social_skills_adjustment_value"], "Number of items missing exceeds maximum") !== false) {
            $scores["social_skills_raw_score"] = null;
        } else {
            // Add Social Skills subscale raw scores to get Social Skills raw score
            $scores["social_skills_raw_score"] = $scores["communication_raw_score"] +
                                             $scores["cooperation_raw_score"] +
                                             $scores["assertion_raw_score"] +
                                             $scores["responsibility_raw_score"] +
                                             $scores["empathy_raw_score"] +
                                             $scores["engagement_raw_score"] +
                                             $scores["self_control_raw_score"];
        }

        if (strpos($scores["problem_behaviors_adjustment_value"], "Number of items missing exceeds maximum") !== false) {
            $scores["problem_behaviors_raw_score"] = null;
        } else {
            $scores["problem_behaviors_raw_score"] = $scores["problem_behaviors_sum"] + $scores["problem_behaviors_adjustment_value"];
        }

        /*
        if (strpos($scores["academic_competence_adjustment_value"], "Number of items missing exceeds maximum") !== false) {
            $scores["academic_competence_raw_score"] = null;
        } else {
            $scores["academic_competence_raw_score"] = $scores["academic_competence_sum"] + $scores["academic_competence_adjustment_value"];
        }*/

        if ($age_years >= 5 && $age_years <= 12) {
            $age_range = "5-12";
        } elseif ($age_years >= 13 && $age_years <= 18) {
            $age_range = "13-18";
        } else {
            $age_range = "invalid";
        }

        if ($age_range != "invalid") {
            foreach (self::SCALES as $key => $value) {
                if (!is_null($scores[$key . "_raw_score"])) {
                    $tmp = $this->getStandardAndPercentile($age_range, $sex, $value, $scores[$key . "_raw_score"], $db);
                    $scores[$key . "_standard_score"] = $tmp[0];
                    $scores[$key . "_percentile"]     = $tmp[1];
                } else {
                    $scores[$key . "_standard_score"] = null;
                    $scores[$key . "_percentile"]     = null;
                }

                $tmp = $this->getCI($age_range, $sex, $value, $db);
                $scores[$key . "_ci_68"] = $tmp[0];
                $scores[$key . "_ci_95"] = $tmp[1];
            }

            foreach (self::SUBSCALES as $key => $value) {
                $scores[$key . "_behavior_level"] = $this->getBehaviorLevel($age_range, $sex, $value, $scores[$key . "_raw_score"], $db);
            }
        } else {
            foreach (self::SCALES as $key => $value) {
                $scores[$key . "_standard_score"] = "Age not valid for scoring (Candidate must be between 5-18 years old)";
                $scores[$key . "_percentile"]     = "Age not valid for scoring (Candidate must be between 5-18 years old)";
                $scores[$key . "_ci_68"]          = "Age not valid for scoring (Candidate must be between 5-18 years old)";
                $scores[$key . "_ci_95"]          = "Age not valid for scoring (Candidate must be between 5-18 years old)";
            }
            foreach (self::SUBSCALES as $key => $value) {
                $scores[$key . "_behavior_level"] = "Age not valid for scoring";
            }
        }

        // Save scores
        $result = $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    private const ADJUSTMENT_FACTORS = [
                                        "social_skills"             => 2,
                                        "communication"             => 2,
                                        "cooperation"               => 2,
                                        "assertion"                 => 2,
                                        "responsibility"            => 2,
                                        "empathy"                   => 2,
                                        "engagement"                => 2,
                                        "self_control"              => 2,
                                        "problem_behaviors"         => 1,
                                        "externalizing"             => 1,
                                        "bullying"                  => 1,
                                        "hyperactivity_inattention" => 1,
                                        "internalizing"             => 1,
                                        "autism_spectrum_A"         => 2,
                                        "autism_spectrum_B"         => 1,
                                       ];

    private const MAX_MISSING = [
                                 "social_skills"     => 4,
                                 "problem_behaviors" => 3,
                                ];

    // Scale: Social Skills
    // Questions: 1-46
    private const SOCIAL_SKILLS = [
                                   "q1_expresses_feelings_frequency",
                                   "q2_household_rules_frequency",
                                   "q3_understand_your_feelings_frequency",
                                   "q4_thank_you_frequency",
                                   "q5_asks_for_help_frequency",
                                   "q6_borrowing_with_care_frequency",
                                   "q7_attention_to_instructions_frequency",
                                   "q8_makes_others_feel_better_frequency",
                                   "q9_joins_activities_frequency",
                                   "q10_takes_turns_conversation_frequency",
                                   "q11_shares_problem_frequency",
                                   "q12_works_well_family_frequency",
                                   "q13_forgives_frequency",
                                   "q14_appropriate_tone_frequency",
                                   "q15_stands_up_for_others_frequency",
                                   "q16_well_behaved_frequency",
                                   "q17_follows_directions_frequency",
                                   "q18_understand_others_feelings_frequency",
                                   "q19_starts_conversations_frequency",
                                   "q20_uses_gestures_appropriately_frequency",
                                   "q21_resolves_disagreements_frequency",
                                   "q22_respects_property_frequency",
                                   "q23_makes_friends_frequency",
                                   "q24_says_please_frequency",
                                   "q25_questions_unfair_rules_frequency",
                                   "q26_takes_responsibility_frequency",
                                   "q27_completes_tasks_frequency",
                                   "q28_comforts_others_frequency",
                                   "q29_interacts_with_children_frequency",
                                   "q30_start_conversation_activity_frequency",
                                   "q31_calm_teased_frequency",
                                   "q32_does_what_promised_frequency",
                                   "q33_introduces_to_others_frequency",
                                   "q34_takes_criticism_frequency",
                                   "q35_nice_without_bragging_frequency",
                                   "q36_compromise_conflict_frequency",
                                   "q37_follows_game_rules_frequency",
                                   "q38_shows_concern_frequency",
                                   "q39_invites_others_frequency",
                                   "q40_makes_eye_contact_frequency",
                                   "q41_tolerates_annoying_peers_frequency",
                                   "q42_responsibility_for_mistakes_frequency",
                                   "q43_conversations_with_adults_frequency",
                                   "q44_responds_when_pushes_frequency",
                                   "q45_stands_up_for_self_frequency",
                                   "q46_calm_disagreement_frequency",
                                  ];

    // Subscale: Communication
    // Questions: 4, 10, 14, 20, 24, 30, 40
    private const COMMUNICATION = [
                                   "q4_thank_you_frequency",
                                   "q10_takes_turns_conversation_frequency",
                                   "q14_appropriate_tone_frequency",
                                   "q20_uses_gestures_appropriately_frequency",
                                   "q24_says_please_frequency",
                                   "q30_start_conversation_activity_frequency",
                                   "q40_makes_eye_contact_frequency",
                                  ];

    // Subscale: Cooperation
    // Questions: 2, 7, 12, 17, 27, 37
    private const COOPERATION = [
                                 "q2_household_rules_frequency",
                                 "q7_attention_to_instructions_frequency",
                                 "q12_works_well_family_frequency",
                                 "q17_follows_directions_frequency",
                                 "q27_completes_tasks_frequency",
                                 "q37_follows_game_rules_frequency",
                                ];

    // Subscale: Assertion
    // Questions: 1, 5, 11, 15, 25, 35, 45
    private const ASSERTION = [
                               "q1_expresses_feelings_frequency",
                               "q5_asks_for_help_frequency",
                               "q11_shares_problem_frequency",
                               "q15_stands_up_for_others_frequency",
                               "q25_questions_unfair_rules_frequency",
                               "q35_nice_without_bragging_frequency",
                               "q45_stands_up_for_self_frequency",
                              ];

    // Subscale: Responsibility
    // Questions: 6, 16, 22, 26, 32, 42
    private const RESPONSIBILITY = [
                                    "q6_borrowing_with_care_frequency",
                                    "q16_well_behaved_frequency",
                                    "q22_respects_property_frequency",
                                    "q26_takes_responsibility_frequency",
                                    "q32_does_what_promised_frequency",
                                    "q42_responsibility_for_mistakes_frequency",
                                   ];

    // Subscale: Empathy
    // Questions: 3, 8, 13, 18, 28, 38
    private const EMPATHY = [
                             "q3_understand_your_feelings_frequency",
                             "q8_makes_others_feel_better_frequency",
                             "q13_forgives_frequency",
                             "q18_understand_others_feelings_frequency",
                             "q28_comforts_others_frequency",
                             "q38_shows_concern_frequency",
                            ];

    // Subscale: Engagement
    // Questions: 9, 19, 23, 29, 33, 39, 43
    // TO DO
    private const ENGAGEMENT = [
                                "q9_joins_activities_frequency",
                                "q19_starts_conversations_frequency",
                                "q23_makes_friends_frequency",
                                "q29_interacts_with_children_frequency",
                                "q33_introduces_to_others_frequency",
                                "q39_invites_others_frequency",
                                "q43_conversations_with_adults_frequency",
                               ];

    // Subscale: Self Control
    // Questions: 21, 31, 34, 36, 41, 44, 46
    private const SELF_CONTROL = [
                                  "q21_resolves_disagreements_frequency",
                                  "q31_calm_teased_frequency",
                                  "q34_takes_criticism_frequency",
                                  "q36_compromise_conflict_frequency",
                                  "q41_tolerates_annoying_peers_frequency",
                                  "q44_responds_when_pushes_frequency",
                                  "q46_calm_disagreement_frequency",
                                 ];

    // Scale: Problem Behaviors
    // Questions: 47-76
    private const PROBLEM_BEHAVIORS = [
                                       "q47_difficulty_waiting_turn",
                                       "q48_repeats_same_thing",
                                       "q49_forces_against_will",
                                       "q50_stereotyped_motor_behaviors",
                                       "q51_fidgets_moves",
                                       "q52_excludes_social_circles",
                                       "q53_inattentive",
                                       "q54_acts_without_thinking",
                                       "q55_upset_when_routines_change",
                                       "q56_aggressive_people_objects",
                                       "q57_withdraws_from_others",
                                       "q58_temper_tantrums",
                                       "q59_makes_others_scared",
                                       "q60_breaks_group_activities",
                                       "q61_low_energy_lethargic",
                                       "q62_odd_gestures",
                                       "q63_bullies",
                                       "q64_anxious_with_others",
                                       "q65_talks_back",
                                       "q66_nobody_likes_them",
                                       "q67_easily_distracted",
                                       "q68_sad_depressed",
                                       "q69_preoccupied_object_parts",
                                       "q70_disobeys_rules",
                                       "q71_sleeping_problems",
                                       "q72_lies",
                                       "q73_gets_embarrassed",
                                       "q74_says_bad_about_self",
                                       "q75_nonfunctional_routines",
                                       "q76_cheats_games",
                                      ];

    // Subcale: Externalizing
    // Questions: 47, 49, 51, 54, 56, 58, 63, 65, 70, 72, 76, 78
    private const EXTERNALIZING = [
                                   "q47_difficulty_waiting_turn",
                                   "q49_forces_against_will",
                                   "q51_fidgets_moves",
                                   "q54_acts_without_thinking",
                                   "q56_aggressive_people_objects",
                                   "q58_temper_tantrums",
                                   "q63_bullies",
                                   "q65_talks_back",
                                   "q70_disobeys_rules",
                                   "q72_lies",
                                   "q76_cheats_games",
                                   "q78_fights_others",
                                  ];

    // Subscale: Bullying
    // Questions: 49, 52, 56, 59, 63
    private const BULLYING = [
                              "q49_forces_against_will",
                              "q52_excludes_social_circles",
                              "q56_aggressive_people_objects",
                              "q59_makes_others_scared",
                              "q63_bullies",
                             ];

    // Subscale: Hyperactivity/Inattention
    // Questions: 47, 51, 53, 54, 58, 60, 67
    private const HYPERACTIVITY_INATTENTION = [
                                               "q47_difficulty_waiting_turn",
                                               "q51_fidgets_moves",
                                               "q53_inattentive",
                                               "q54_acts_without_thinking",
                                               "q58_temper_tantrums",
                                               "q60_breaks_group_activities",
                                               "q67_easily_distracted",
                                              ];

    // Subscale: Internalizing
    // Questions: 57, 61, 64, 66, 68, 71, 73, 74, 77, 79
    private const INTERNALIZING = [
                                   "q57_withdraws_from_others",
                                   "q61_low_energy_lethargic",
                                   "q64_anxious_with_others",
                                   "q66_nobody_likes_them",
                                   "q68_sad_depressed",
                                   "q71_sleeping_problems",
                                   "q73_gets_embarrassed",
                                   "q74_says_bad_about_self",
                                   "q77_acts_lonely",
                                   "q79_eating_problems",
                                  ];

    // Subscale: Autism Spectrum A
    // Questions: 10, 19, 20, 29, 30, 38, 39, 40
    private const AUTISM_SPECTRUM_A = [
                                       "q10_takes_turns_conversation_frequency",
                                       "q19_starts_conversations_frequency",
                                       "q20_uses_gestures_appropriately_frequency",
                                       "q29_interacts_with_children_frequency",
                                       "q30_start_conversation_activity_frequency",
                                       "q38_shows_concern_frequency",
                                       "q39_invites_others_frequency",
                                       "q40_makes_eye_contact_frequency",
                                      ];

    // Subscale: Autism Spectrum B
    // Questions: 48, 50, 55, 57, 62, 69, 75
    private const AUTISM_SPECTRUM_B = [
                                       "q48_repeats_same_thing",
                                       "q50_stereotyped_motor_behaviors",
                                       "q55_upset_when_routines_change",
                                       "q57_withdraws_from_others",
                                       "q62_odd_gestures",
                                       "q69_preoccupied_object_parts",
                                       "q75_nonfunctional_routines",
                                      ];

    private const SCALES = [
                            "social_skills"     => "Social Skills",
                            "problem_behaviors" => "Problem Behaviors",
                           ];

    private const SCALE_ARRAYS = [
                                  "social_skills"     => self::SOCIAL_SKILLS,
                                  "problem_behaviors" => self::PROBLEM_BEHAVIORS,
                                 ];

    private const SUBSCALES = [
                               "communication"             => "Communication",
                               "cooperation"               => "Cooperation",
                               "assertion"                 => "Assertion",
                               "responsibility"            => "Responsibility",
                               "empathy"                   => "Empathy",
                               "engagement"                => "Engagement",
                               "self_control"              => "Self-Control",
                               "externalizing"             => "Externalizing",
                               "bullying"                  => "Bullying",
                               "hyperactivity_inattention" => "Hyperactivity/Inattention",
                               "internalizing"             => "Internalizing",
                               "autism_spectrum_A"         => "Autism Spectrum",
                               "autism_spectrum_B"         => "Autism Spectrum",
                              ];

    private const SUBSCALE_ARRAYS = [
                                     "communication"             => self::COMMUNICATION,
                                     "cooperation"               => self::COOPERATION,
                                     "assertion"                 => self::ASSERTION,
                                     "responsibility"            => self::RESPONSIBILITY,
                                     "empathy"                   => self::EMPATHY,
                                     "engagement"                => self::ENGAGEMENT,
                                     "self_control"              => self::SELF_CONTROL,
                                     "externalizing"             => self::EXTERNALIZING,
                                     "bullying"                  => self::BULLYING,
                                     "hyperactivity_inattention" => self::HYPERACTIVITY_INATTENTION,
                                     "internalizing"             => self::INTERNALIZING,
                                     "autism_spectrum_A"         => self::AUTISM_SPECTRUM_A,
                                     "autism_spectrum_B"         => self::AUTISM_SPECTRUM_B,
                                    ];
}
