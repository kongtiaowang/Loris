<?php
/**
 * This file contains the NDB_BVL_Instrument_SRS2_Preschool_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the SRS2 Preschool Instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_SRS2_Preschool_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityRequired = false;

    var $scoreLabels = array(
                        "total_raw_score",
                        "total_t_score",
                        "awr_raw_score",
                        "awr_t_score",
                        "cog_raw_score",
                        "cog_t_score",
                        "com_raw_score",
                        "com_t_score",
                        "mot_raw_score",
                        "mot_t_score",
                        "rrb_raw_score",
                        "rrb_t_score",
                        "dsm_sci_raw_score",
                        "dsm_sci_t_score",
                        "dsm_rrb_raw_score",
                        "dsm_rrb_t_score",

                        "score_range",
                       );

    /**
     * Abstract function setup($commentID, $page);
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
        $this->formType ="XIN";
        $this->form     = new LorisForm('SRS2_Preschool_survey_form');
        $this->page     = $page;            //Page label

        //Set the object properties
        $this->testName = "SRS2_Preschool_survey";           //test_names.Test_name
        $this->table    = 'SRS2_Preschool_survey';
        //Data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        $this->_requiredElements = array(
                                    'q1_more_fidgety_in_social_situations',
                                    'q16_avoid_or_unusual_eye_contact',
                                    'q33_socially_awkward_even_when_polite',
                                    'q52_knows_when_too_loud_too_much_noise',
                                   );

        //Setup the form
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
        if (preg_match("/SRS2_Preschool_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                <i>*Please fill this form out with regard to your older child who has autism.</i>
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
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   'total'   => "Total",
                   'awr'     => "Awr",
                   'cog'     => "Cog",
                   'com'     => "Com",
                   'mot'     => "Mot",
                   'rrb'     => "RRB",
                   'dsm_sci' => "DSM-5 SCI",
                   'dsm_rrb' => "DSM-5 RRB",
                  );

        $columnHeaders = array(
                          "raw_score" => "Raw Score",
                          "t_score"   => "T Score",
                         );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }

        $this->form->addElement('static', null, "");

        $this->form->addGroup($group, "score_range_header_group", "Score Range", $this->_GUIDelimiter, false);
        unset($group);

        $group[] = $this->form->createElement('static', "score_range", null, null);
        $this->form->addGroup($group, "score_range_score_group", "Score Range", $this->_GUIDelimiter, false);
        unset($group);
    }

    /**
     * Generates the first page of the form
     *
     * @return void
     */
    function _page1()
    {
        $this->form->addElement('header', 'instrument_title', "SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                <i>*Please fill this form out with regard to your older child who has autism.</i>
                <br><br>
                For each question, please select the option that best describes this child's behavior <b>over the past 6 months</b>.
                <br><br>
                $this->indent 1 = Not True<br>
                $this->indent 2 = Sometimes True<br>
                $this->indent 3 = Often True<br>
                $this->indent 4 = Almost Always True<br>
            </h3>"
        );

        $gender_options = array(
                           null   => "",
                           "boy"  => "Boy",
                           "girl" => "Girl",
                          );

        $this->addSelect("child_gender", "Child's Sex", $gender_options);

        $this->addBasicText("child_age", "CHILD'S AGE <br><h5><i>(Please enter a numeric value between 0-100.)</i></h5>");

        $options = array(
                    null                   => '',
                    '1_not_true'           => "1 = Not True",
                    '2_sometimes_true'     => "2 = Sometimes True",
                    '3_often_true'         => "3 = Often True",
                    '4_almost_always_true' => "4 = Almost Always True",
                   );

        $page1_questions = array(
                            "q1_more_fidgety_in_social_situations"       => "1. Seems much more fidgety in social situations than when alone",
                            "q2_expressions_dont_match_what_saying"      => "2. Expressions on his or her face don't match what he or she is saying",
                            "q3_self_confident_when_interacting"         => "3. Seems self-confident when interacting with others",
                            "q4_under_stress_autopilot"                  => "4. When under stress, child seems to go on \"autopilot\" (for example, shows rigid or inflexible patterns of behavior that seem odd)",
                            "q5_doesnt_recognize_others_take_advantage"  => "5. Doesn't recognize when others are trying to take advantage of him or her",
                            "q6_rather_be_alone_than_with_others"        => "6. Would rather be alone than with others",
                            "q7_aware_others_thinking_or_feeling"        => "7. Is aware of what others are thinking or feeling",
                            "q8_behave_in_ways_strange_bizarre"          => "8. Behaves in ways that seem strange or bizarre",
                            "q9_clings_to_adults_too_dependent"          => "9. Clings to adults, seems too dependent on them",
                            "q10_unable_to_pick_up_on_meaning"           => "10. Unable to pick up on any of the meaning of conversations of older children or adults",
                            "q11_has_good_self_confidence"               => "11. Has good self-confidence",
                            "q12_able_to_communicate_feelings_to_others" => "12. Is able to communicate his or her feelings to others in words or gestures",
                            "q13_slow_awkward_turn_taking_interactions"  => "13. Is slow or awkward in turn-taking interactions with peers",
                            "q14_not_well_coordinated"                   => "14. Is not well coordinated in physical activities",
                            "q15_understand_tone_and_facial_expressions" => "15. Is able to understand the meaning of other people's tone of voice and facial expressions",
                           );

        foreach ($page1_questions as $field => $label) {
            $this->addSelect($field, $label, $options);
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Generates the second page of the form
     *
     * @return void
     */
    function _page2()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - Survey");

        $options = array(
                    null                   => '',
                    '1_not_true'           => "1 = Not True",
                    '2_sometimes_true'     => "2 = Sometimes True",
                    '3_often_true'         => "3 = Often True",
                    '4_almost_always_true' => "4 = Almost Always True",
                   );

        $page2_questions = array(
                            "q16_avoid_or_unusual_eye_contact"               => "16. Avoids eye contact or has unusual eye contact",
                            "q17_recognize_when_something_is_unfair"         => "17. Recognizes when something is unfair",
                            "q18_does_not_attempt_interact_with_children"    => "18. When on the playground or in a group with other young children, child does not attempt to interact with other children",
                            "q19_frustrated_trying_to_get_ideas_across"      => "19. Gets frustrated trying to get ideas across in conversations",
                            "q20_has_strange_way_of_playing_with_toy"        => "20. Has a strange way of playing with a toy",
                            "q21_able_to_imitate_others_actions"             => "21. Is able to imitate others' actions",
                            "q22_plays_appropriately_with_children"          => "22. Plays appropriately with children his or her age",
                            "q23_does_not_join_group_activities_unless_told" => "23. Does not join group activities unless told to do so",
                            "q24_difficulty_with_changes_in_routine"         => "24. Has more difficulty than other children with changes in his or her routine",
                            "q25_doesnt_mind_being_out_of_step"              => "25. Doesn't seem to mind being out of step with or \"not on the same wavelength\" as others",
                            "q26_offers_comfort_to_others_when_sad"          => "26. Offers comfort to others when they are sad",
                            "q27_avoids_starting_social_interactions"        => "27. Avoids starting social interactions with peers or adults",
                            "q28_thinks_or_talks_about_same_thing"           => "28. Thinks or talks about the same thing over and over",
                            "q29_regarded_by_other_children_as_odd_weird"    => "29. Is regarded by other children as odd or weird",
                            "q30_becomes_upset_in_situation_lots_going_on"   => "30. Becomes upset in a situation with lots of things going on",
                            "q31_cant_get_mind_off_something_once_starts"    => "31. Can't get his or her mind off something once he or she starts thinking about it",
                            "q32_wants_to_be_changed_when_soiled_or_wet"     => "32. Wants to be changed when diaper or underwear is soiled or wet",
                           );

        foreach ($page2_questions as $field => $label) {
            $this->addSelect($field, $label, $options);
        }
    }

    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - Survey");

        $options = array(
                    null                   => '',
                    '1_not_true'           => "1 = Not True",
                    '2_sometimes_true'     => "2 = Sometimes True",
                    '3_often_true'         => "3 = Often True",
                    '4_almost_always_true' => "4 = Almost Always True",
                   );

        $page3_questions = array(
                            "q33_socially_awkward_even_when_polite"                => "33. Is socially awkward, even when he or she is trying to be polite",
                            "q34_avoids_people_emotionally_close"                  => "34. Avoids people who want to be emotionally close to him or her",
                            "q35_trouble_keeping_up_with_normal_interaction"       => "35. Has trouble keeping up with the flow of a normal interaction with other children",
                            "q36_has_difficulty_relating_to_adults"                => "36. Has difficulty relating to adults",
                            "q37_has_difficulty_relating_to_peers"                 => "37. Has difficulty relating to peers",
                            "q38_responds_appropriately_to_mood_changes"           => "38. Responds appropriately to mood changes in others (for example when a friend's or playmate's mood changes from happy to sad)",
                            "q39_has_restricted_range_of_interests"                => "39. Has a restricted (or unusually narrow) range of interests",
                            "q40_is_imaginative_good_at_pretending"                => "40. Is imaginative, good at pretending (without losing touch with reality)",
                            "q41_wanders_aimlessly_from_activity_to_another"       => "41. Wanders aimlessly from one activity to another",
                            "q42_seems_overly_sensitive"                           => "42. Seems overly sensitive to sounds, textures, or smells",
                            "q43_separates_easily_from_caregivers"                 => "43. Separates easily from caregivers",
                            "q44_doesnt_understand_how_events_are_related"         => "44. Doesn't understand how events are related to one another the way other children his or her age do",
                            "q45_focuses_attention_where_others_looking_listening" => "45. Focuses his or her attention to where others are looking or listening",
                            "q46_has_overly_serious_facial_expressions"            => "46. Has overly serious facial expressions",
                            "q47_is_too_silly_laughs_inappropriately"              => "47. Is too silly or laughs inappropriately",
                            "q48_has_sense_of_humor_understands_jokes"             => "48. Has a sense of humor, understands jokes",
                            "q49_does_extremely_well_at_a_few_tasks"               => "49. Does extremely well at a few tasks, but does not do as well at most other tasks",
                            "q50_has_repetitive_odd_behaviors"                     => "50. Has repetitive, odd behaviors such as hand flapping or rocking",
                            "q51_responds_to_clear_direct_questions"               => "51. Responds to clear, direct questions in ways that don't seem to make any sense",
                           );

        foreach ($page3_questions as $field => $label) {
            $this->addSelect($field, $label, $options);
        }
    }

    /**
     * Generates the fourth page of the form
     *
     * @return void
     */
    function _page4()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 Pre-School (Social Responsiveness Scale - Pre-School) - Survey");

        $options = array(
                    null                   => '',
                    '1_not_true'           => "1 = Not True",
                    '2_sometimes_true'     => "2 = Sometimes True",
                    '3_often_true'         => "3 = Often True",
                    '4_almost_always_true' => "4 = Almost Always True",
                   );

        $page4_questions = array(
                            "q52_knows_when_too_loud_too_much_noise"       => "52. Knows when he or she is talking too loud or making too much noise",
                            "q53_talks_with_unusual_tone_of_voice"         => "53. Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture)",
                            "q54_seems_to_react_to_people_as_objects"      => "54. Seems to react to people as if they are objects",
                            "q55_knows_when_too_close_invading_space"      => "55. Knows when he or she is too close to someone or is invading someone's space",
                            "q56_walks_between_two_people_talking"         => "56. Walks in between two people who are talking",
                            "q57_other_children_do_not_play_with"          => "57. Other children do not like to play with him or her",
                            "q58_concentrates_too_much_on_parts_of_things" => "58. Concentrates too much on parts of things rather than seeing the whole picture. For example, spins the wheels of a toy car but doesn't play with it as a car, or plays with doll's hair but not the whole doll",
                            "q59_is_overly_suspicious"                     => "59. Is overly suspicious",
                            "q60_is_emotionally_distant"                   => "60. Is emotionally distant, doesn't show his or her feelings",
                            "q61_is_inflexible"                            => "61. Is inflexible, has a hard time changing his or her mind ",
                            "q62_gives_unusual_illogical_reasons"          => "62. Gives unusual or illogical reasons for doing things",
                            "q63_touches_others_in_unusual_way"            => "63. Touches others in an unusual way (for example, he or she may touch someone just to make contact and then walk away without saying anything)",
                            "q64_is_too_tense_in_social_settings"          => "64. Is too tense in social settings",
                            "q65_stares_or_gazes_off_into_space"           => "65. Stares or gazes off into space",
                           );

        foreach ($page4_questions as $field => $label) {
            $this->addSelect($field, $label, $options);
        }
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

        $this->validate_child_age($values, "child_age", $errors);

        return $errors;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $scores['score_validity'] = null;

        // null scores
        $this->_nullScores($this->scoreLabels);

        // get the saved scores
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());

        // SCORE GRIDS:
        $score_grid_q1  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q2  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q3  = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q4  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q5  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q6  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q7  = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q8  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q9  = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q10 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q11 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q12 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q13 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q14 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q15 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q16 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q17 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q18 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q19 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q20 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q21 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q22 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q23 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q24 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q25 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q26 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q27 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q28 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q29 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q30 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q31 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q32 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q33 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q34 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q35 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q36 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q37 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q38 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q39 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q40 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q41 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q42 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q43 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q44 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q45 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q46 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q47 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q48 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q49 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q50 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q51 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q52 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q53 =array(
                          '1_not_true'           => 0,
                          '2_sometimes_true'     => 1,
                          '3_often_true'         => 2,
                          '4_almost_always_true' => 3,
                         );
        $score_grid_q54 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q55 = array(
                           '1_not_true'           => 3,
                           '2_sometimes_true'     => 2,
                           '3_often_true'         => 1,
                           '4_almost_always_true' => 0,
                          );
        $score_grid_q56 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q57 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q58 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q59 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q60 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q61 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q62 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q63 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q64 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );
        $score_grid_q65 = array(
                           '1_not_true'           => 0,
                           '2_sometimes_true'     => 1,
                           '3_often_true'         => 2,
                           '4_almost_always_true' => 3,
                          );

        $awr_array = array(
                      $score_grid_q2[$record['q2_expressions_dont_match_what_saying']],
                      $score_grid_q7[$record['q7_aware_others_thinking_or_feeling']],
                      $score_grid_q25[$record['q25_doesnt_mind_being_out_of_step']],
                      $score_grid_q32[$record['q32_wants_to_be_changed_when_soiled_or_wet']],
                      $score_grid_q45[$record['q45_focuses_attention_where_others_looking_listening']],
                      $score_grid_q52[$record['q52_knows_when_too_loud_too_much_noise']],
                      $score_grid_q54[$record['q54_seems_to_react_to_people_as_objects']],
                      $score_grid_q56[$record['q56_walks_between_two_people_talking']],
                     );

        $cog_array = array(
                      $score_grid_q5[$record['q5_doesnt_recognize_others_take_advantage']],
                      $score_grid_q10[$record['q10_unable_to_pick_up_on_meaning']],
                      $score_grid_q15[$record['q15_understand_tone_and_facial_expressions']],
                      $score_grid_q17[$record['q17_recognize_when_something_is_unfair']],
                      $score_grid_q30[$record['q30_becomes_upset_in_situation_lots_going_on']],
                      $score_grid_q40[$record['q40_is_imaginative_good_at_pretending']],
                      $score_grid_q42[$record['q42_seems_overly_sensitive']],
                      $score_grid_q44[$record['q44_doesnt_understand_how_events_are_related']],
                      $score_grid_q48[$record['q48_has_sense_of_humor_understands_jokes']],
                      $score_grid_q58[$record['q58_concentrates_too_much_on_parts_of_things']],
                      $score_grid_q59[$record['q59_is_overly_suspicious']],
                      $score_grid_q62[$record['q62_gives_unusual_illogical_reasons']],
                     );

        $com_array = array(
                      $score_grid_q12[$record['q12_able_to_communicate_feelings_to_others']],
                      $score_grid_q13[$record['q13_slow_awkward_turn_taking_interactions']],
                      $score_grid_q16[$record['q16_avoid_or_unusual_eye_contact']],
                      $score_grid_q18[$record['q18_does_not_attempt_interact_with_children']],
                      $score_grid_q19[$record['q19_frustrated_trying_to_get_ideas_across']],
                      $score_grid_q21[$record['q21_able_to_imitate_others_actions']],
                      $score_grid_q22[$record['q22_plays_appropriately_with_children']],
                      $score_grid_q26[$record['q26_offers_comfort_to_others_when_sad']],
                      $score_grid_q33[$record['q33_socially_awkward_even_when_polite']],
                      $score_grid_q35[$record['q35_trouble_keeping_up_with_normal_interaction']],
                      $score_grid_q36[$record['q36_has_difficulty_relating_to_adults']],
                      $score_grid_q37[$record['q37_has_difficulty_relating_to_peers']],
                      $score_grid_q38[$record['q38_responds_appropriately_to_mood_changes']],
                      $score_grid_q41[$record['q41_wanders_aimlessly_from_activity_to_another']],
                      $score_grid_q46[$record['q46_has_overly_serious_facial_expressions']],
                      $score_grid_q47[$record['q47_is_too_silly_laughs_inappropriately']],
                      $score_grid_q51[$record['q51_responds_to_clear_direct_questions']],
                      $score_grid_q53[$record['q53_talks_with_unusual_tone_of_voice']],
                      $score_grid_q55[$record['q55_knows_when_too_close_invading_space']],
                      $score_grid_q57[$record['q57_other_children_do_not_play_with']],
                      $score_grid_q60[$record['q60_is_emotionally_distant']],
                      $score_grid_q61[$record['q61_is_inflexible']],
                     );

        $mot_array = array(
                      $score_grid_q1[$record['q1_more_fidgety_in_social_situations']],
                      $score_grid_q3[$record['q3_self_confident_when_interacting']],
                      $score_grid_q6[$record['q6_rather_be_alone_than_with_others']],
                      $score_grid_q9[$record['q9_clings_to_adults_too_dependent']],
                      $score_grid_q11[$record['q11_has_good_self_confidence']],
                      $score_grid_q23[$record['q23_does_not_join_group_activities_unless_told']],
                      $score_grid_q27[$record['q27_avoids_starting_social_interactions']],
                      $score_grid_q34[$record['q34_avoids_people_emotionally_close']],
                      $score_grid_q43[$record['q43_separates_easily_from_caregivers']],
                      $score_grid_q64[$record['q64_is_too_tense_in_social_settings']],
                      $score_grid_q65[$record['q65_stares_or_gazes_off_into_space']],
                     );

        $rrb_array = array(
                      $score_grid_q4[$record['q4_under_stress_autopilot']],
                      $score_grid_q8[$record['q8_behave_in_ways_strange_bizarre']],
                      $score_grid_q14[$record['q14_not_well_coordinated']],
                      $score_grid_q20[$record['q20_has_strange_way_of_playing_with_toy']],
                      $score_grid_q24[$record['q24_difficulty_with_changes_in_routine']],
                      $score_grid_q28[$record['q28_thinks_or_talks_about_same_thing']],
                      $score_grid_q29[$record['q29_regarded_by_other_children_as_odd_weird']],
                      $score_grid_q31[$record['q31_cant_get_mind_off_something_once_starts']],
                      $score_grid_q39[$record['q39_has_restricted_range_of_interests']],
                      $score_grid_q49[$record['q49_does_extremely_well_at_a_few_tasks']],
                      $score_grid_q50[$record['q50_has_repetitive_odd_behaviors']],
                      $score_grid_q63[$record['q63_touches_others_in_unusual_way']],
                     );

        $scores = array();

        $scores['awr_raw_score'] = $this->calculateRawScore($awr_array);
        $scores['cog_raw_score'] = $this->calculateRawScore($cog_array);
        $scores['com_raw_score'] = $this->calculateRawScore($com_array);
        $scores['mot_raw_score'] = $this->calculateRawScore($mot_array);
        $scores['rrb_raw_score'] = $this->calculateRawScore($rrb_array);

        $scores['dsm_sci_raw_score'] = $scores['awr_raw_score'] + $scores['cog_raw_score'] + $scores['com_raw_score'] + $scores['mot_raw_score'];
        $scores['dsm_rrb_raw_score'] = $scores['rrb_raw_score'];

        $scores['total_raw_score'] = $scores['dsm_sci_raw_score'] + $scores['rrb_raw_score'];

        $scales = array(
                   "total"   => "Total",
                   "awr"     => "Awr",
                   "cog"     => "Cog",
                   "com"     => "Com",
                   "mot"     => "Mot",
                   "rrb"     => "RRB",
                   "dsm_sci" => "DSM_SCI",
                   "dsm_rrb" => "DSM_RRB",
                  );

        foreach ($scales as $key => $value) {
            $field_raw_score = $key . "_raw_score";

            if ($key == "total" && $scores[$field_raw_score] > 145) {
                $raw_score_adjusted = 145;
            } else if ($key == "awr" && $scores[$field_raw_score] > 22) {
                $raw_score_adjusted = 22;
            } else if ($key == "cog" && $scores[$field_raw_score] > 32) {
                $raw_score_adjusted = 32;
            } else if ($key == "com" && $scores[$field_raw_score] > 51) {
                $raw_score_adjusted = 51;
            } else if ($key == "mot" && $scores[$field_raw_score] > 27) {
                $raw_score_adjusted = 27;
            } else if ($key == "rrb" && $scores[$field_raw_score] > 25) {
                $raw_score_adjusted = 25;
            } else if ($key == "dsm_sci" && $scores[$field_raw_score] > 123) {
                $raw_score_adjusted = 123;
            } else if ($key == "dsm_rrb" && $scores[$field_raw_score] > 25) {
                $raw_score_adjusted = 25;
            } else {
                $raw_score_adjusted = $scores[$field_raw_score];
            }

            $query = "
                        SELECT
                            T_Score
                        from
                            SRS2_Preschool_lookup
                        WHERE
                            Raw_Score = :raw_score
                        AND
                            Scale = :scale
                    ";

            $where = array(
                      'raw_score' => $raw_score_adjusted,
                      'scale'     => $value,
                     );

            $query_result = $db->pselectRow($query, $where);

            $field_t_score          = $key . "_t_score";
            $scores[$field_t_score] = $query_result['T_Score'];
        }

        if ($scores['total_t_score'] >= 76) {
            $scores['score_range'] = "Severe";
        } else if (in_array($scores['total_t_score'], range(66, 75))) {
            $scores['score_range'] = "Moderate";
        } else if (in_array($scores['total_t_score'], range(60, 65))) {
            $scores['score_range'] = "Mild";
        } else if ($scores['total_t_score'] <= 59) {
            $scores['score_range'] = "Normal";
        } else {
            $scores['score_range'] = "NA";
        }

        foreach ($scales as $key => $value) {
            if ($scores[$key . '_t_score'] == 90) {
                $scores[$key . '_t_score'] = "Greater than or equal to 90";
            }

            // only executes for the Awr scale
            if ($scores[$key . '_t_score'] == 30) {
                $scores[$key . '_t_score'] = "Less than or equal to 30";
            }
        }

        $result = $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
    }

    function calculateRawScore($scale_array)
    {
        $raw_score = 0;

        foreach ($scale_array as $val) {
            switch ($val) {
            case 0:
                // do nothing
                break;
            case 1:
                $raw_score += 1;
                break;
            case 2:
                $raw_score += 2;
                break;
            case 3:
                $raw_score += 3;
                break;
            }
        }

        return $raw_score;
    }
}
?>
