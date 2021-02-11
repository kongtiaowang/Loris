<?php

/**
 *This file contains the NDB_BVL_Instrument_SSIS_Teacher class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Mie Beers <mie.beers@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_SSIS_Teacher instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Mie Beers <mie.beers@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_SSIS_Teacher extends NDB_BVL_Instrument
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

                        "academic_competence_num_missing",
                        "academic_competence_adjustment_value",
                        "academic_competence_sum",
                        "academic_competence_raw_score",
                        "academic_competence_standard_score",
                        "academic_competence_percentile",
                        "academic_competence_ci_68",
                        "academic_competence_ci_95",

                        "f_index",
                        "f_index_interpretation",
                       );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('SSIS_Teacher', "SSIS Teacher: Social Skills Improvement System", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SSIS_Teacher','SSIS_Teacher_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SSIS_Teacher','SSIS_Teacher_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SSIS_Teacher','SSIS_Teacher_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SSIS_Teacher','SSIS_Teacher_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SSIS_Teacher','SSIS_Teacher_page5', "Page 5", 5);
     */

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
        $this->form     = new LorisForm('SSIS_Teacher_form');
        $this->page     = $page;            // page label

        // Set the object properties
        $this->testName = "SSIS_Teacher";    // test_names.Test_name
        $this->table    = "SSIS_Teacher";

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
        if (preg_match("/SSIS_Teacher(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->form->addElement('header', 'instrument_title', "SSIS Teacher: Social Skills Improvement System");

        // Add date of administration field
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

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
                   "academic_competence"       => "<b>Academic Competence</b>",
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
                if ($field == "social_skills" || $field == "problem_behaviors" || $field == "academic_competence") {
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
                       ''             => null,
                       'male'         => 'Male',
                       'female'       => 'Female',
                       'not_answered' => 'Not Answered',
                      );
        $frequency  = array(
                       ''                => null,
                       'N_never'         => 'Never (N)',
                       'S_sometimes'     => 'Seldom (S)',
                       'O_often'         => 'Often (O)',
                       'A_almost_always' => 'Almost Always (A)',
                       'not_answered'    => 'Not Answered',
                      );
        $importance = array(
                       ''                => null,
                       'n_not_important' => 'not important (n)',
                       'i_important'     => 'important (i)',
                       'c_critical'      => 'critical (c)',
                       'not_answered'    => 'Not Answered',
                      );

        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Teacher: Social Skills Improvement System");
        $this->form->addElement('static', 'lorisSubHeader', "<h5><i>*Please select or indicate NA/Not Answered for the questions<br> you really don't know/don't want to answer.</i></h5>");

        // Add field for child's age
        $this->addBasicText("student_age", "Student's Age <h5><i>(Please indicate the student's age in years, or write NA if you don't know.)</i></h5>");

        // Add field for child's grade
        $this->addBasicText("student_grade", "Student's Grade in School <h5><i>(Please enter a numeric value between 1-12, K, or write NA if you don't know.)</i></h5>");

        // Add select for sex of child
        $this->addSelect('student_sex', "Student's sex", $child_sex);

        // Add optional field for any other data relating to the child
        $this->addBasicText("student_other_data", "Other data about this student");
        $this->XINRegisterRule('student_other_data', array("student_other_data{@}=={@}NEVER_REQUIRED"));

        // Add field for teacher's position at the school
        $this->addBasicText("position", "Your Position");

        // Add field for length of time that the teacher has known the child for
        $this->addBasicText("time_known_child", "How long have you known this student?");

        // Add field for type of class
        $this->addBasicText("class", "What type of class do you teach?");

        // Instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>Please read each item and think about this student's behavior during the past two months. Then, decide <b>how often</b> this student displays the behavior. For each of the Social Skills items, please also rate <b>how important</b> you think the behavior is for success in your classroom.");

        // Indicate the name of the section
        $this->form->addElement('header', 'social_skills_section', "Social Skills");

        // First group of questions
        $this->form->addElement('static', null);
        $questions = array(
                      "q1_asks_for_help"                        => "1. Asks for help from adults.",
                      "q2_follows_directions"                   => "2. Follows your directions.",
                      "q3_comforts_others"                      => "3. Tries to comfort others.",
                      "q4_please"                               => '4. Says "please."',
                      "q5_questions_unfair_rules"               => "5. Questions rules that may be unfair.",
                      "q6_well_behaved"                         => "6. Is well-behaved when unsupervised.",
                      "q7_completes_tasks"                      => "7. Completes tasks without bothering others.",
                      "q8_forgives"                             => "8. Forgives others.",
                      "q9_makes_friends"                        => "9. Makes friends easily.",
                      "q10_responds_well_conversation_activity" => "10. Responds well when others start a conversation or activity.",
                      "q11_stands_up_for_themself"              => "11. Stands up for herself/himself when treated unfairly.",
                      "q12_participates_in_class"               => "12. Participates appropriately in class.",
                      "q13_feels_bad_others_sad"                => "13. Feels bad when others are sad.",
                      "q14_appropriate_tone"                    => "14. Speaks in appropriate tone of voice.",
                      "q15_says_problem"                        => "15. Says when there is a problem.",
                      "q16_responsibility_for_actions"          => "16. Takes responsibility for her/his own actions.",
                      "q17_attention_to_instructions"           => "17. Pays attention to your instructions.",
                      "q18_kind_to_others"                      => "18. Shows kindness to others when they are upset.",
                      "q19_interacts_well_others"               => "19. Interacts well with other children.",
                      "q20_takes_turns_conversation"            => "20. Takes turns in conversations.",
                     );

        // Display questions with two columns, one for a frequency rating and one for an importance rating
        $this->_displayHeaders("questions");

        $i = 0;

        foreach ($questions as $question => $label) {
            $i++;
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
                "page1_table{$i}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Frequency is Required.", // message
                "page1_table{$i}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_importance",
                array($question . "_importance{@}=={@}"), // rule
                "Importance is Required.", // message
                "page1_table{$i}" // group [if field is a part of a group]
            );
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
        $this->form->addElement('header', 'instrument_title', "SSIS Teacher: Social Skills Improvement System");

        // Define variables for select options
        $frequency = array(
                      ''                => null,
                      'N_never'         => 'Never (N)',
                      'S_sometimes'     => 'Seldom (S)',
                      'O_often'         => 'Often (O)',
                      'A_almost_always' => 'Almost Always (A)',
                      'not_answered'    => 'Not Answered',
                     );

        $importance = array(
                       ''                => null,
                       'n_not_important' => 'not important (n)',
                       'i_important'     => 'important (i)',
                       'c_critical'      => 'critical (c)',
                       'not_answered'    => 'Not Answered',
                      );

        // Second group of questions
        $questions = array(
                      "q21_calm_when_teased"                => "21. Stays calm when teased.",
                      "q22_responsible_with_others"         => "22. Acts responsibly when with others.",
                      "q23_joins_activities"                => "23. Joins activities that have already started.",
                      "q24_thank_you"                       => '24. Says "thank you."',
                      "q25_expresses_feelings"              => "25. Expresses feelings when wronged.",
                      "q26_takes_care_of_others_things"     => "26. Takes care when using other people's things.",
                      "q27_ignores_distracting_classmates"  => "27. Ignores classmates when they are distracting.",
                      "q28_nice_when_others_feel_bad"       => "28. Is nice to others when they are feeling bad.",
                      "q29_invites_others_activities"       => "29. Invites others to join in activities.",
                      "q30_eye_contact_talking"             => "30. Makes eye contact when talking.",
                      "q31_criticism_without_getting_upset" => "31. Takes criticism without getting upset.",
                      "q32_respects_others_property"        => "32. Respects the property of others.",
                      "q33_participates_games"              => "33. Participates in games or group activities.",
                      "q34_appropriate_language_upset"      => "34. Uses appropriate language when upset.",
                      "q35_stands_up_for_others"            => "35. Stands up for others who are treated unfairly.",
                      "q36_resolves_disagreements_calmly"   => "36. Resolves disagreements with you calmly.",
                      "q37_follows_rules"                   => "37. Follows classroom rules.",
                      "q38_shows_concern"                   => "38. Shows concern for others.",
                      "q39_starts_conversations_peers"      => "39. Starts conversations with peers.",
                      "q40_gestures_appropriately"          => "40. Uses gestures or body appropriately with others.",
                      "q41_responds_when_pushed"            => "41. Responds appropriately when pushed or hit.",
                      "q42_responsibility_group_activity"   => "42. Takes responsibility for part of a group activity.",
                      "q43_introduces_themself"             => "43. Introduces herself/himself to others.",
                      "q44_compromise_conflict"             => "44. Makes a compromise during a conflict.",
                      "q45_nice_without_bragging"           => "45. Says nice things about herself/himself without bragging.",
                      "q46_calm_disagreement"               => "46. Stays calm when disagreeing with others.",
                     );

        // Display questions with two columns, one for a frequency rating and one for an importance rating
        $this->_displayHeaders("questions");

        $i = 0;

        foreach ($questions as $question => $label) {
            $i++;
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
                "page2_table{$i}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                $question . "_frequency",
                array($question . "_frequency{@}=={@}"), // rule
                "Frequency is Required.", // message
                "page2_table{$i}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                $question . "_importance",
                array($question . "_importance{@}=={@}"), // rule
                "Importance is Required.", // message
                "page2_table{$i}" // group [if field is a part of a group]
            );
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
        $this->form->addElement('header', 'instrument_title', "SSIS Teacher: Social Skills Improvement System");

        // Indicate the name of the section
        $this->form->addElement('header', 'problem_behaviors_section', "Problem Behaviors");

        // Define variable for select options
        $frequency = array(
                      ''                => null,
                      'N_never'         => 'Never (N)',
                      'S_sometimes'     => 'Seldom (S)',
                      'O_often'         => 'Often (O)',
                      'A_almost_always' => 'Almost Always (A)',
                      'not_answered'    => 'Not Answered',
                     );

        // Third group of questions
        $questions = array(
                      "q47_acts_without_thinking"       => "47. Acts without thinking.",
                      "q48_preoccupied_object_parts"    => "48. Is preoccupied with object parts.",
                      "q49_bullies"                     => "49. Bullies others.",
                      "q50_upset_when_routines_change"  => "50. Becomes upset when routines change.",
                      "q51_difficulty_waiting_turn"     => "51. Has difficulty waiting for turn.",
                      "q52_makes_others_scared"         => "52. Does things to make others feel scared.",
                      "q53_fidgets_moves"               => "53. Fidgets or moves around too much.",
                      "q54_stereotyped_motor_behaviors" => "54. Has stereotyped motor behaviors.",
                      "q55_forces_against_will"         => "55. Forces others to act against their will.",
                      "q56_withdraws_from_other"        => "56. Withdraws from others.",
                      "q57_temper_tantrums"             => "57. Has temper tantrums.",
                      "q58_keeps_others_out"            => "58. Keeps others out of social circles.",
                      "q59_breaks_group_activities"     => "59. Breaks into or stops group activities.",
                      "q60_repeats_same_thing"          => "60. Repeats the same thing over and over.",
                      "q61_aggressive_people_objects"   => "61. Is aggressive toward people or objects.",
                      "q62_gets_embarrassed"            => "62. Gets embarrassed easily.",
                     );

        // Implement response selection for each question
        foreach ($questions as $field => $label) {
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
        $this->form->addElement('header', 'instrument_title', "SSIS Teacher: Social Skills Improvement System");

        // Define variable for select options
        $frequency = array(
                      ''                => null,
                      'N_never'         => 'Never (N)',
                      'S_sometimes'     => 'Seldom (S)',
                      'O_often'         => 'Often (O)',
                      'A_almost_always' => 'Almost Always (A)',
                      'not_answered'    => 'Not Answered',
                     );

        // Fourth group of questions
        $questions = array(
                      "q63_cheats_games"           => "63. Cheats in games or activities.",
                      "q64_acts_lonely"            => "64. Acts lonely.",
                      "q65_inattentive"            => "65. Is inattentive.",
                      "q66_nonfunctional_routines" => "66. Has nonfunctional routines or rituals.",
                      "q67_fights_others"          => "67. Fights with others.",
                      "q68_says_bad_about_self"    => "68. Says bad things about self.",
                      "q69_disobeys_rules"         => "69. Disobeys rules or requests.",
                      "q70_low_energy_lethargic"   => "70. Has low energy or is lethargic.",
                      "q71_sleeping_problems"      => "71. Gets Distracted Easily.",
                      "q72_odd_gestures"           => "72. Uses odd physical gestures in interactions.",
                      "q73_talks_back"             => "73. Talks back to adults.",
                      "q74_sad_depressed"          => "74. Acts sad or depressed.",
                      "q75_lies"                   => "75. Lies or does not tell the truth.",
                      "q76_anxious_with_others"    => "76. Acts anxious with others.",
                     );

        // Implement response selection for each question
        foreach ($questions as $field => $label) {
            $this->addSelect($field, $label, $frequency);
        }
    }

    /**
     * Generates the fifth page of the form
     *
     * @return void
     */
    function _page5()
    {
        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Teacher: Social Skills Improvement System");

        // Indicate the name of the section
        $this->form->addElement('header', 'academic_competence_section', "Academic Competence <h5>(for students from kindergarten through Grade 12)</h5>");

        // Instructions
        $this->form->addElement('static', 'lorisSubHeader', 'Please assess this student\'s academic or learning behaviours in your classroom. Compare this student with other students in the same classroom.<br> Mark all items using a scale of 1 to 5. Mark "1" if this student is in the lowest 10% of the class. Mark "5" if this student is in the highest 10% of the class.');

        // Define variable for select options
        $rating = array(
                   ''                   => null,
                   '1_lowest_10%'       => '1. Lowest 10%',
                   '2_next_lowest_20%'  => '2. Next Lowest 20%',
                   '3_middle_40%'       => '3. Middle 40%',
                   '4_next_highest_20%' => '4. Next Highest 20%',
                   '5_highest_10%'      => '5. Highest 10%',
                   'not_answered'       => 'Not Answered',

                  );

        // Fifth group of questions
        $questions = array(
                      "q77_overall_performance"    => "77. Compared with other students in my classroom, the overall academic performance of this student is:",
                      "q78_reading_other_students" => "78. In reading, how does this student compare with other students?",
                      "q79_math_other_students"    => "79. In mathematics, how does this student compare with other students?",
                      "q80_reading_grade_level"    => "80. In terms of grade-level expectations, this student's skills in reading are:",
                      "q81_math_grade_level"       => "81. In terms of grade-level expectations, this student's skills in mathematics are:",
                      "q82_motivation"             => "82. This student's overall motivation to succeed academically is:",
                      "q83_intellect"              => "83. Compared with other students in my classroom, this student's intellectual functioning is:",
                     );

        // Implement response selection for each question
        foreach ($questions as $field => $label) {
            $this->addSelect($field, $label, $rating);
        }
    }

    /**
     * Validates the text fields on page 1 using the instrument validator class
     */
    function validate_page1($values)
    {
        $errors = [];

        $this->validate_age($values, "student_age", $errors);
        $this->validate_grade($values, "student_grade", $errors);

        return $errors;
    }

    function step1_count_missing($question_array, $record)
    {
        $count = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "not_answered") {
                $count++;
            }
        }

        return $count;
    }

    function step1_calculate_adjustment_value($adjustment_factor, $missing_count)
    {
        return $adjustment_factor * $missing_count;
    }

    function step2_calculate_item_sum($question_array, $record)
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

    function step2_calculate_ac_sum($question_array, $record)
    {
        $count = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "5_highest_10%") {
                $count += 4;
            } elseif ($record[$q] == "4_next_highest_20%") {
                $count += 3;
            } elseif ($record[$q] == "3_middle_40%") {
                $count += 2;
            } elseif ($record[$q] == "2_next_lowest_20%") {
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
                      SSIS_Teacher_lookup
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

        if (array_key_exists('standard_score', $record)) {
            $standard = $record['standard_score'];
        }
        if (array_key_exists('percentile', $record)) {
            $percentile = $record['percentile'];
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
                      form = 'Teacher' AND
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
                      form = 'Teacher' AND
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

        if (array_key_exists('confidence_interval_value', $record)) {
            $ci_68 = $record['confidence_interval_value'];
        }

        $query_95 = "SELECT
                      *
                  FROM
                      SSIS_CI_lookup
                  WHERE
                      form = 'Teacher' AND
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

        if (array_key_exists('confidence_interval_value', $record)) {
            $ci_95 = $record['confidence_interval_value'];
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

        // initialize score array
        $scores = array();

        if ($age_years < 5 || $age_years > 18) {
            $scores['score_validity'] = "Age not valid for scoring";
            return;
        }

        // foreach scale/subscale there are 4 fields:
        // _num_missing = # of questions answered with "Not Answered"
        // _adjustment_value = # of questions answered with "Not Answered" * adjustment factor
        // _sum = sum of item scores (N = 0, S = 1, O = 2, A = 3, etc.)
        // _raw_score
        // _behavior_level
        foreach (self::SCALES_AND_SUBSCALES as $s) {
            $scores[$s . "_num_missing"]      = -999;
            $scores[$s . "_adjustment_value"] = -999;
            $scores[$s . "_sum"]       = -999;
            $scores[$s . "_raw_score"] = -999;
            //$scores[$s . "_behavior_level"] = -999;
        }

        $scores["f_index"] = -999;
        $scores["f_index_interpretation"] = -999;

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
         * - Problem Behaviors (Questions: 47-76)
         *      - Externalizing
         *      - Bullying
         *      - Hyperactivity/Inattention
         *      - Internalizing
         * - Autism Spectrum (Questions: 10, 19, 20, 29, 30, 38-40, 48, 50, 54, 56, 60, 66, 72)
         *      - Part A
         *      - Part B
         * - Academic Competence (Questions: 77-83)
         */

        /********************************************************************
         * STEP 1: Determining Adjustment Values for Missing Item Responses *
         ********************************************************************
         *
         * Count # of _frequency questions answered with "Not Answered"
         */

        $adjustment_factors = array(
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
                               "academic_competence"       => 2,
                              );

        $max_missing = array(
                        "social_skills"       => 4,
                        "problem_behaviors"   => 3,
                        "academic_competence" => 1,
                       );

        $scores["social_skills_num_missing"]       = $this->step1_count_missing(self::SOCIAL_SKILLS, $record);
        $scores["problem_behaviors_num_missing"]   = $this->step1_count_missing(self::PROBLEM_BEHAVIORS, $record);
        $scores["academic_competence_num_missing"] = $this->step1_count_missing(self::ACADEMIC_COMPETENCE, $record);

        // If the adjustment values for any of the scales exceeds the maximum,
        // do not continue to score that scale and its subscales
        if ($scores["social_skills_num_missing"] <= $max_missing["social_skills"]) {
            $scores["social_skills_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["social_skills"], $scores["social_skills_num_missing"]);

            $scores["communication_num_missing"]  = $this->step1_count_missing(self::COMMUNICATION, $record);
            $scores["cooperation_num_missing"]    = $this->step1_count_missing(self::COOPERATION, $record);
            $scores["assertion_num_missing"]      = $this->step1_count_missing(self::ASSERTION, $record);
            $scores["responsibility_num_missing"] = $this->step1_count_missing(self::RESPONSIBILITY, $record);
            $scores["empathy_num_missing"]        = $this->step1_count_missing(self::EMPATHY, $record);
            $scores["engagement_num_missing"]     = $this->step1_count_missing(self::ENGAGEMENT, $record);
            $scores["self_control_num_missing"]   = $this->step1_count_missing(self::SELF_CONTROL, $record);

            $scores["communication_adjustment_value"]  = $this->step1_calculate_adjustment_value($adjustment_factors["communication"], $scores["communication_num_missing"]);
            $scores["cooperation_adjustment_value"]    = $this->step1_calculate_adjustment_value($adjustment_factors["cooperation"], $scores["cooperation_num_missing"]);
            $scores["assertion_adjustment_value"]      = $this->step1_calculate_adjustment_value($adjustment_factors["assertion"], $scores["assertion_num_missing"]);
            $scores["responsibility_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["responsibility"], $scores["responsibility_num_missing"]);
            $scores["empathy_adjustment_value"]        = $this->step1_calculate_adjustment_value($adjustment_factors["empathy"], $scores["empathy_num_missing"]);
            $scores["engagement_adjustment_value"]     = $this->step1_calculate_adjustment_value($adjustment_factors["engagement"], $scores["engagement_num_missing"]);
            $scores["self_control_adjustment_value"]   = $this->step1_calculate_adjustment_value($adjustment_factors["self_control"], $scores["self_control_num_missing"]);
        } else {
            $scores["social_skills_adjustment_value"] = "Number of items missing exceeds maximum (" . $max_missing["social_skills"] . ")";
        }

        if ($scores["problem_behaviors_num_missing"] <= $max_missing["problem_behaviors"]) {
            $scores["problem_behaviors_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["problem_behaviors"], $scores["problem_behaviors_num_missing"]);

            $scores["externalizing_num_missing"] = $this->step1_count_missing(self::EXTERNALIZING, $record);
            $scores["bullying_num_missing"]      = $this->step1_count_missing(self::BULLYING, $record);
            $scores["hyperactivity_inattention_num_missing"] = $this->step1_count_missing(self::HYPERACTIVITY_INATTENTION, $record);
            $scores["internalizing_num_missing"]     = $this->step1_count_missing(self::INTERNALIZING, $record);
            $scores["autism_spectrum_A_num_missing"] = $this->step1_count_missing(self::AUTISM_SPECTRUM_A, $record);
            $scores["autism_spectrum_B_num_missing"] = $this->step1_count_missing(self::AUTISM_SPECTRUM_B, $record);

            $scores["externalizing_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["externalizing"], $scores["externalizing_num_missing"]);
            $scores["bullying_adjustment_value"]      = $this->step1_calculate_adjustment_value($adjustment_factors["bullying"], $scores["bullying_num_missing"]);
            $scores["hyperactivity_inattention_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["hyperactivity_inattention"], $scores["hyperactivity_inattention_num_missing"]);
            $scores["internalizing_adjustment_value"]     = $this->step1_calculate_adjustment_value($adjustment_factors["internalizing"], $scores["internalizing_num_missing"]);
            $scores["autism_spectrum_A_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["autism_spectrum_A"], $scores["autism_spectrum_A_num_missing"]);
            $scores["autism_spectrum_B_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["autism_spectrum_B"], $scores["autism_spectrum_B_num_missing"]);
        } else {
            $scores["problem_behaviors_adjustment_value"] = "Number of items missing exceeds maximum (" . $max_missing["problem_behaviors"] . ")";
        }

        if ($scores["academic_competence_num_missing"] <= $max_missing["academic_competence"]) {
            $scores["academic_competence_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["academic_competence"], $scores["academic_competence_num_missing"]);
        } else {
            $scores["academic_competence_adjustment_value"] = "Number of items missing exceeds maximum (" . $max_missing["academic_competence"] . ")";
        }

        // No max for Autism A or B
        $scores["autism_spectrum_A_num_missing"]      = $this->step1_count_missing(self::AUTISM_SPECTRUM_A, $record);
        $scores["autism_spectrum_A_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["autism_spectrum_A"], $scores["autism_spectrum_A_num_missing"]);

        $scores["autism_spectrum_B_num_missing"]      = $this->step1_count_missing(self::AUTISM_SPECTRUM_B, $record);
        $scores["autism_spectrum_B_adjustment_value"] = $this->step1_calculate_adjustment_value($adjustment_factors["autism_spectrum_B"], $scores["autism_spectrum_B_num_missing"]);

        /***************************************************
         * STEP 2: Computing Scale and Subscale Raw Scores *
         ***************************************************
         *
         * Sum ...
         */

        $scores["communication_sum"]  = $this->step2_calculate_item_sum(self::COMMUNICATION, $record);
        $scores["cooperation_sum"]    = $this->step2_calculate_item_sum(self::COOPERATION, $record);
        $scores["assertion_sum"]      = $this->step2_calculate_item_sum(self::ASSERTION, $record);
        $scores["responsibility_sum"] = $this->step2_calculate_item_sum(self::RESPONSIBILITY, $record);
        $scores["empathy_sum"]        = $this->step2_calculate_item_sum(self::EMPATHY, $record);
        $scores["engagement_sum"]     = $this->step2_calculate_item_sum(self::ENGAGEMENT, $record);
        $scores["self_control_sum"]   = $this->step2_calculate_item_sum(self::SELF_CONTROL, $record);

        $scores["social_skills_sum"] = $scores["communication_sum"] +
                                       $scores["cooperation_sum"] +
                                       $scores["assertion_sum"] +
                                       $scores["responsibility_sum"] +
                                       $scores["empathy_sum"] +
                                       $scores["engagement_sum"] +
                                       $scores["self_control_sum"];

        $scores["externalizing_sum"] = $this->step2_calculate_item_sum(self::EXTERNALIZING, $record);
        $scores["bullying_sum"]      = $this->step2_calculate_item_sum(self::BULLYING, $record);
        $scores["hyperactivity_inattention_sum"] = $this->step2_calculate_item_sum(self::HYPERACTIVITY_INATTENTION, $record);
        $scores["internalizing_sum"] = $this->step2_calculate_item_sum(self::INTERNALIZING, $record);

        $scores["problem_behaviors_sum"] = $scores["externalizing_sum"] +
                                           $scores["bullying_sum"] +
                                           $scores["hyperactivity_inattention_sum"] +
                                           $scores["internalizing_sum"];

        $scores["autism_spectrum_A_sum"] = $this->step2_calculate_item_sum(self::AUTISM_SPECTRUM_A, $record);
        $scores["autism_spectrum_B_sum"] = $this->step2_calculate_item_sum(self::AUTISM_SPECTRUM_B, $record);

        $scores["academic_competence_sum"] = $this->step2_calculate_ac_sum(self::ACADEMIC_COMPETENCE, $record);

        /***********************************
         * STEP 3: Calculating the F Index *
         ***********************************
         *
         * Count the number of circled unshaded rating value(s)
         */

        $unshaded_ratings = array(
                             "q1_asks_for_help_frequency"          => "N_never",
                             "q12_participates_in_class_frequency" => "N_never",
                             "q19_interacts_well_others_frequency" => "N_never",
                             "q33_participates_games_frequency"    => "N_never",
                             "q37_follows_rules_frequency"         => "N_never",
                             "q48_preoccupied_object_parts"        => "A_almost_always",
                             "q49_bullies"                         => "A_almost_always",
                             "q54_stereotyped_motor_behaviors"     => "A_almost_always",
                             "q57_temper_tantrums"                 => "A_almost_always",
                             "q58_keeps_others_out"                => "A_almost_always",
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
         * Add each subscale sum to its adjustment value => Raw Score
         */

        // Add each subscale sum to its adjustment value
        foreach (self::SUBSCALES as $key => $value) {
            $scores[$key . "_raw_score"] = $scores[$key . "_sum"] + $scores[$key . "_adjustment_value"];
        }

        // Add Social Skills subscale raw scores to get Social Skills raw score
        $scores["social_skills_raw_score"] = $scores["communication_raw_score"] +
                                             $scores["cooperation_raw_score"] +
                                             $scores["assertion_raw_score"] +
                                             $scores["responsibility_raw_score"] +
                                             $scores["empathy_raw_score"] +
                                             $scores["engagement_raw_score"] +
                                             $scores["self_control_raw_score"];

        $scores["problem_behaviors_raw_score"] = $scores["problem_behaviors_sum"] + $scores["problem_behaviors_adjustment_value"];

        $scores["academic_competence_raw_score"] = $scores["academic_competence_sum"] + $scores["academic_competence_adjustment_value"];

        $scales = array(
                   "social_skills"       => "Social Skills",
                   "problem_behaviors"   => "Problem Behaviors",
                   "academic_competence" => "Academic Competence",
                  );

        if ($age_years >= 5 && $age_years <= 12) {
            $age_range = "5-12";
        } elseif ($age_years >= 13 && $age_years <= 18) {
            $age_range = "13-18";
        }

        foreach ($scales as $key => $value) {
            $tmp = $this->getStandardAndPercentile($age_range, $sex, $value, $scores[$key . "_raw_score"], $db);
            $scores[$key . "_standard_score"] = $tmp[0];
            $scores[$key . "_percentile"]     = $tmp[1];
        }

        foreach (self::SUBSCALES as $key => $value) {
            $scores[$key . "_behavior_level"] = $this->getBehaviorLevel($age_range, $sex, $value, $scores[$key . "_raw_score"], $db);
        }

        // CI
        //  function getCI(string $age_range, string $sex, string $scale, $db)
        foreach ($scales as $key => $value) {
            $tmp = $this->getCI($age_range, $sex, $value, $db);
            $scores[$key . "_ci_68"] = $tmp[0];
            $scores[$key . "_ci_95"] = $tmp[1];
        }

        // Save scores
        $result = $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    private const SCALES_AND_SUBSCALES = [
                                          "social_skills",
                                          "communication",
                                          "cooperation",
                                          "assertion",
                                          "responsibility",
                                          "empathy",
                                          "engagement",
                                          "self_control",
                                          "problem_behaviors",
                                          "externalizing",
                                          "bullying",
                                          "hyperactivity_inattention",
                                          "internalizing",
                                          "autism_spectrum_A",
                                          "autism_spectrum_B",
                                          "academic_competence",
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

    // Scale: Social Skills
    // Questions: 1-46
    private const SOCIAL_SKILLS = [
                                   "q1_asks_for_help_frequency",
                                   "q2_follows_directions_frequency",
                                   "q3_comforts_others_frequency",
                                   "q4_please_frequency",
                                   "q5_questions_unfair_rules_frequency",
                                   "q6_well_behaved_frequency",
                                   "q7_completes_tasks_frequency",
                                   "q8_forgives_frequency",
                                   "q9_makes_friends_frequency",
                                   "q10_responds_well_conversation_activity_frequency",
                                   "q11_stands_up_for_themself_frequency",
                                   "q12_participates_in_class_frequency",
                                   "q13_feels_bad_others_sad_frequency",
                                   "q14_appropriate_tone_frequency",
                                   "q15_says_problem_frequency",
                                   "q16_responsibility_for_actions_frequency",
                                   "q17_attention_to_instructions_frequency",
                                   "q18_kind_to_others_frequency",
                                   "q19_interacts_well_others_frequency",
                                   "q20_takes_turns_conversation_frequency",
                                   "q21_calm_when_teased_frequency",
                                   "q22_responsible_with_others_frequency",
                                   "q23_joins_activities_frequency",
                                   "q24_thank_you_frequency",
                                   "q25_expresses_feelings_frequency",
                                   "q26_takes_care_of_others_things_frequency",
                                   "q27_ignores_distracting_classmates_frequency",
                                   "q28_nice_when_others_feel_bad_frequency",
                                   "q29_invites_others_activities_frequency",
                                   "q30_eye_contact_talking_frequency",
                                   "q31_criticism_without_getting_upset_frequency",
                                   "q32_respects_others_property_frequency",
                                   "q33_participates_games_frequency",
                                   "q34_appropriate_language_upset_frequency",
                                   "q35_stands_up_for_others_frequency",
                                   "q36_resolves_disagreements_calmly_frequency",
                                   "q37_follows_rules_frequency",
                                   "q38_shows_concern_frequency",
                                   "q39_starts_conversations_peers_frequency",
                                   "q40_gestures_appropriately_frequency",
                                   "q41_responds_when_pushed_frequency",
                                   "q42_responsibility_group_activity_frequency",
                                   "q43_introduces_themself_frequency",
                                   "q44_compromise_conflict_frequency",
                                   "q45_nice_without_bragging_frequency",
                                   "q46_calm_disagreement_frequency",
                                  ];

    // Subscale: Communication
    // Questions: 4, 10, 14, 20, 24, 30, 40
    private const COMMUNICATION = [
                                   "q4_please_frequency",
                                   "q10_responds_well_conversation_activity_frequency",
                                   "q14_appropriate_tone_frequency",
                                   "q20_takes_turns_conversation_frequency",
                                   "q24_thank_you_frequency",
                                   "q30_eye_contact_talking_frequency",
                                   "q40_gestures_appropriately_frequency",
                                  ];

    // Subscale: Cooperation
    // Questions: 2, 7, 12, 17, 27, 37
    private const COOPERATION = [
                                 "q2_follows_directions_frequency",
                                 "q7_completes_tasks_frequency",
                                 "q12_participates_in_class_frequency",
                                 "q17_attention_to_instructions_frequency",
                                 "q27_ignores_distracting_classmates_frequency",
                                 "q37_follows_rules_frequency",
                                ];

    // Subscale: Assertion
    // Questions: 1, 5, 11, 15, 25, 35, 45
    private const ASSERTION = [
                               "q1_asks_for_help_frequency",
                               "q5_questions_unfair_rules_frequency",
                               "q11_stands_up_for_themself_frequency",
                               "q15_says_problem_frequency",
                               "q25_expresses_feelings_frequency",
                               "q35_stands_up_for_others_frequency",
                               "q45_nice_without_bragging_frequency",
                              ];

    // Subscale: Responsibility
    // Questions: 6, 16, 22, 26, 32, 42
    private const RESPONSIBILITY = [
                                    "q6_well_behaved_frequency",
                                    "q16_responsibility_for_actions_frequency",
                                    "q22_responsible_with_others_frequency",
                                    "q26_takes_care_of_others_things_frequency",
                                    "q32_respects_others_property_frequency",
                                    "q42_responsibility_group_activity_frequency",
                                   ];

    // Subscale: Empathy
    // Questions: 3, 8, 13, 18, 28, 38
    private const EMPATHY = [
                             "q3_comforts_others_frequency",
                             "q8_forgives_frequency",
                             "q13_feels_bad_others_sad_frequency",
                             "q18_kind_to_others_frequency",
                             "q28_nice_when_others_feel_bad_frequency",
                             "q38_shows_concern_frequency",
                            ];

    // Subscale: Engagement
    // Questions: 9, 19, 23, 29, 33, 39, 43
    private const ENGAGEMENT = [
                                "q9_makes_friends_frequency",
                                "q19_interacts_well_others_frequency",
                                "q23_joins_activities_frequency",
                                "q29_invites_others_activities_frequency",
                                "q33_participates_games_frequency",
                                "q39_starts_conversations_peers_frequency",
                                "q43_introduces_themself_frequency",
                               ];

    // Subscale: Self Control
    // Questions: 21, 31, 34, 36, 41, 44, 46
    private const SELF_CONTROL = [
                                  "q21_calm_when_teased_frequency",
                                  "q31_criticism_without_getting_upset_frequency",
                                  "q34_appropriate_language_upset_frequency",
                                  "q36_resolves_disagreements_calmly_frequency",
                                  "q41_responds_when_pushed_frequency",
                                  "q44_compromise_conflict_frequency",
                                  "q46_calm_disagreement_frequency",
                                 ];

    // Scale: Problem Behaviors
    // Questions: 47-76
    private const PROBLEM_BEHAVIORS = [
                                       "q47_acts_without_thinking",
                                       "q48_preoccupied_object_parts",
                                       "q49_bullies",
                                       "q50_upset_when_routines_change",
                                       "q51_difficulty_waiting_turn",
                                       "q52_makes_others_scared",
                                       "q53_fidgets_moves",
                                       "q54_stereotyped_motor_behaviors",
                                       "q55_forces_against_will",
                                       "q56_withdraws_from_other",
                                       "q57_temper_tantrums",
                                       "q58_keeps_others_out",
                                       "q59_breaks_group_activities",
                                       "q60_repeats_same_thing",
                                       "q61_aggressive_people_objects",
                                       "q62_gets_embarrassed",
                                       "q63_cheats_games",
                                       "q64_acts_lonely",
                                       "q65_inattentive",
                                       "q66_nonfunctional_routines",
                                       "q67_fights_others",
                                       "q68_says_bad_about_self",
                                       "q69_disobeys_rules",
                                       "q70_low_energy_lethargic",
                                       "q71_sleeping_problems",
                                       "q72_odd_gestures",
                                       "q73_talks_back",
                                       "q74_sad_depressed",
                                       "q75_lies",
                                       "q76_anxious_with_others",
                                      ];

    // Subcale: Externalizing
    // Questions: 47, 49, 51, 53, 55, 57, 61, 63, 67, 69, 73, 75
    private const EXTERNALIZING = [
                                   "q47_acts_without_thinking",
                                   "q49_bullies",
                                   "q51_difficulty_waiting_turn",
                                   "q53_fidgets_moves",
                                   "q55_forces_against_will",
                                   "q57_temper_tantrums",
                                   "q61_aggressive_people_objects",
                                   "q63_cheats_games",
                                   "q67_fights_others",
                                   "q69_disobeys_rules",
                                   "q73_talks_back",
                                   "q75_lies",
                                  ];

    // Subscale: Bullying
    // Questions: 49, 52, 55, 58, 61
    private const BULLYING = [
                              "q49_bullies",
                              "q52_makes_others_scared",
                              "q55_forces_against_will",
                              "q58_keeps_others_out",
                              "q61_aggressive_people_objects",
                             ];

    // Subscale: Hyperactivity/Inattention
    // Questions: 47, 51, 53, 57, 59, 65, 71
    private const HYPERACTIVITY_INATTENTION = [
                                               "q47_acts_without_thinking",
                                               "q51_difficulty_waiting_turn",
                                               "q53_fidgets_moves",
                                               "q57_temper_tantrums",
                                               "q59_breaks_group_activities",
                                               "q65_inattentive",
                                               "q71_sleeping_problems",
                                              ];

    // Subscale: Internalizing
    // Questions: 56, 62, 64, 68, 70, 74, 76
    private const INTERNALIZING = [
                                   "q56_withdraws_from_other",
                                   "q62_gets_embarrassed",
                                   "q64_acts_lonely",
                                   "q68_says_bad_about_self",
                                   "q70_low_energy_lethargic",
                                   "q74_sad_depressed",
                                   "q76_anxious_with_others",
                                  ];

    // Subscale: Autism Spectrum A
    // Questions: 10, 19, 20, 29, 30, 38, 39, 40
    private const AUTISM_SPECTRUM_A = [
                                       "q10_responds_well_conversation_activity_frequency",
                                       "q19_interacts_well_others_frequency",
                                       "q20_takes_turns_conversation_frequency",
                                       "q29_invites_others_activities_frequency",
                                       "q30_eye_contact_talking_frequency",
                                       "q38_shows_concern_frequency",
                                       "q39_starts_conversations_peers_frequency",
                                       "q40_gestures_appropriately_frequency",
                                      ];

    // Subscale: Autism Spectrum B
    // Questions: 48, 50, 54, 56, 60, 66, 72
    private const AUTISM_SPECTRUM_B = [
                                       "q48_preoccupied_object_parts",
                                       "q50_upset_when_routines_change",
                                       "q54_stereotyped_motor_behaviors",
                                       "q56_withdraws_from_other",
                                       "q60_repeats_same_thing",
                                       "q66_nonfunctional_routines",
                                       "q72_odd_gestures",
                                      ];

    // Scale: Academic Competence
    // Questions: 77-83
    private const ACADEMIC_COMPETENCE = [
                                         "q77_overall_performance",
                                         "q78_reading_other_students",
                                         "q79_math_other_students",
                                         "q80_reading_grade_level",
                                         "q81_math_grade_level",
                                         "q82_motivation",
                                         "q83_intellect",
                                        ];
}