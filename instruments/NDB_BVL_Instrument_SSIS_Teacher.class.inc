<?php

/**
 *This file contains the NDB_BVL_Instrument_SSIS_Teacher class
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
        $this->form->addElement('static', 'lorisSubHeader1', "<h5><i>*Please select or indicate NA/Not Answered for the questions<br> you really don't know/don't want to answer.</i></h5>");

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
        $i =0;
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
        $i =0;
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
                      "q56_withdraws_from_other"        => "56. Withdraws from others. .",
                      "q57_temper_tantrums"             => "57. Has temper tantrums.",
                      "q58_keeps_others_out"            => "58. Keeps others out of social circles.",
                      "q59_breaks_group_activities"     => "59. Breaks into or stops group activities.",
                      "q60_repeats_same_thing"          => "60. Repeats the same thing over and over.",
                      "q61_aggressive_people_objects"   => "61. Is aggressive toward people or objects.",
                      "q62_gets_embarrassed"            => "62. Gets embarrassed easily.",
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
        foreach ($questions as $field=>$label) {
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
        foreach ($questions as $field=>$label) {
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
}