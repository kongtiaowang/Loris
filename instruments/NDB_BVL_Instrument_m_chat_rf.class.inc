<?php
/**
 *
 * @category Instrument
 * @author   Stella Lee <slee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the M-CHAT Revised Follow-Up instrument
 *
 * @category Instrument
 * @author   Stella Lee <slee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_m_chat_rf extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $scoreLabels = array(
        "q1_pass_or_fail",
        "q2_pass_or_fail",
        "q3_pass_or_fail",
        "q4_pass_or_fail",
        "q5_pass_or_fail",
        "q6_pass_or_fail",
        "q7_pass_or_fail",
        "q8_pass_or_fail",
        "q9_pass_or_fail",
        "q10_pass_or_fail",
        "q11_pass_or_fail",
        "q12_pass_or_fail",
        "q13_pass_or_fail",
        "q14_pass_or_fail",
        "q15_pass_or_fail",
        "q16_pass_or_fail",
        "q17_pass_or_fail",
        "q18_pass_or_fail",
        "q19_pass_or_fail",
        "q20_pass_or_fail",
    );

    var $yesNo = array(
                  null  => '',
                  'yes' => 'Yes',
                  'no'  => 'No',
                 );

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'm_chat_rf'; // test_names.Test_name
        $this->table    = 'm_chat_rf'; // name of database table corresponding to instrument

        $this->commentID   = $commentID; // data keyed by commentID
        $config            = NDB_Config::singleton();
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
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match("/m_chat_rf(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // Header
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $this->_addMetadataFields();

        $group[] =&$this->form->createElement("text", 'age', "", null);
        $this->XINRegisterRule("age", array("age{@}=={@}"), "Required.", "age_group");
        $this->form->addGroup($group, "age_group", 'Age', null, false);
        unset($group);
        $this->addGroupRule(
            "age_group",
            array(array(array("Value must be numeric.", 'numeric')))
        );

        $informant = array(
                      ''            => null,
                      'mother'      => 'Mother',
                      'father'      => 'Father',
                      'step_mother' => 'Step Mother',
                      'step_father' => 'Step Father',
                      'other'       => 'Other',
                     );

        $this->addSelect('relationship_to_child', "Relationship to child", $informant);

        $group[] = $this->createText('relationship_to_child_other', $this->indent . "If Other please specify");
        $this->addGroup($group, "relationship_to_child_other_group", $this->indent . $this->indent . "If Other please specify", null, false);
        unset($group);
        $rules_array = array("relationship_to_child{@}=={@}other");
        $this->XINRegisterRule('relationship_to_child_other', $rules_array, "Please specify relationship", 'relationship_to_child_other_group');

        // SCORING TABLE

        $this->form->addElement('header', 'score', "Score Summary");

        $this->form->addGroup($group, 'score_header_group', "<strong>Question</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $columnHeaders = array("pass_or_fail" => "Pass or Fail");

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        for ($i = 1; $i<=20; $i++) {
            foreach ($columnHeaders as $field => $label) {
                $group[] = $this->form->createElement('static', "q{$i}_{$field}", null, null);
            }
            $this->form->addGroup($group, "q{$i}_{$field}_score_group", "q" . $i, $this->_GUIDelimiter, false);
            unset($group);
        }

        $this->addLabel('2009 Diana Robins, Deborah Fein, & Marianne Barton');
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page1_pass_examples = array(
                                "look_at_object"                 => "Look at object?",
                                "point_at_object"                => "Point to object?",
                                "look_and_comment_on_object"     => "Look and comment on object?",
                                "look_if_you_point_and_say_look" => "Look if you point and say \"look!\"?",
                               );

        $page1_fail_examples = array(
                                "ignores_you"               => "Ignores you?",
                                "look_around_room_randomly" => "Look around room randomly?",
                                "look_at_your_finger"       => "Look at your finger?",
                               );

        $this->addLabel(
            '<strong>Instructions:</strong><BR>Please answer these questions about your child.
            Keep in mind how your child <strong>usually</strong> behaves.
            If you have seen your child do the behavior a few times, but he or she does not usually do it, then please answer <strong>no</strong>.
            Please choose <strong>yes or no</strong> for every question. Thank you very much.'
        );

        $this->form->addElement('select', "q1_point_across_room", "1. If you point at something across the room, does your child look at it? <h6>(FOR EXAMPLE, if you point at a toy or an animal, does your child look at the toy or animal?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give an example of how he/she will respond if you point at something (If parent does not give a PASS example below, ask each individually.)");

        $this->form->addElement('static', null, "If No: If you point at something, what does your child typically do?");

        $this->form->addElement('static', null, "<b>1.1. Does he/she... (Always Required)</b><h6><i>(Below are <u>PASS</u> examples)</i></h6>");

        foreach ($page1_pass_examples as $field => $label) {
            $this->form->addElement('select', "q1_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addElement('static', null, "<b>1.2. Does he/she... (Always Required)</b><h6><i>(Below are <u>FAIL</u> examples)</i></h6>");

        foreach ($page1_fail_examples as $field => $label) {
            $this->form->addElement('select', "q1_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addElement('select', "q1_yes_to_both_pass_and_fail", "1.3. If Yes to both <u>PASS</u> and <u>FAIL</u> examples: Which one does he/she do most often?", [null => "", "pass" => "Pass example", "fail" => "Fail example"]);

        $this->XINRegisterRule(
            "q1_yes_to_both_pass_and_fail",
            array("q1_yes_to_both_pass_and_fail{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page2_test_result_options = array(
                                      null                             => "",
                                      "normal_range"                   => "Hearing in normal range",
                                      "below_normal"                   => "Hearing below normal",
                                      "inconclusive_or_not_definitive" => "Results inconclusive or not definitive",
                                     );

        $this->form->addElement('select', "q2_deaf", "2. Have you ever wondered if your child might be deaf?", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: What led you to wonder that?");

        $this->form->addElement('static', null, "<b>2.1. Does he/she... (Required if Yes to #2)</b>");

        $this->form->addElement('select', "q2_often_ignore_sounds", $this->indent . "often ignore sounds?", $this->yesNo);
        $this->XINRegisterRule(
            "q2_often_ignore_sounds",
            array("q2_deaf{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('select', "q2_often_ignore_people", $this->indent . "often ignore people?", $this->yesNo);
        $this->XINRegisterRule(
            "q2_often_ignore_people",
            array("q2_deaf{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('select', "q2_hearing_tested", "2.2. Has your child’s hearing been tested? (Required if Yes to #2)", $this->yesNo);
        $this->XINRegisterRule(
            "q2_hearing_tested",
            array("q2_deaf{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('select', "q2_results_of_hearing_test", $this->indent . "2.3. If Yes to #2.2: What were the results of the hearing test?", $page2_test_result_options);
        $this->XINRegisterRule(
            "q2_results_of_hearing_test",
            array("q2_hearing_tested{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

     /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page3_questions = array(
                            "pretend_to_drink_from_toy_cup"                   => "Pretend to drink from a <b>toy</b> cup?",
                            "pretend_to_eat_from_toy_spoon_or_fork"           => "Pretend to eat from a <b>toy</b> spoon or fork?",
                            "pretend_to_talk_on_phone"                        => "Pretend to talk on the telephone?",
                            "pretened_to_feed_doll_or_stuffed_animal"         => "Pretend to feed a doll or stuffed animal with real or imaginary food?",
                            "push_car_along_pretend_road"                     => "Push a car as if it is going along a pretend road?",
                            "pretend_to_be_robot_airplane_ballerina_or_other" => "Pretend to be a robot, an airplane, a ballerina, or any other favorite character?",
                            "put_toy_pot_on_pretend_stove"                    => "Put a toy pot on a pretend stove?",
                            "stir_imaginary_food"                             => "Stir imaginary food?",
                            "put_action_figure_or_doll_into_car_or_truck"     => "Put an action figure or doll into a car or truck as if it is the driver or passenger?",
                            "pretend_to_vacuum_sweep_mow"                     => "Pretend to vacuum the rug, sweep the floor, or the mow lawn?",
                            "other"                                           => "Other (describe)",
                           );

        $this->form->addElement('select', "q3_play_pretend", "3. Does your child play pretend or make-believe? <h6>(FOR EXAMPLE, pretend to drink from an empty cup, pretend to talk on a phone, or pretend to feed a doll or stuffed animal?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example of his/her pretend play. (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>3.1. Does he/she usually... (Always Required)</b>");

        foreach ($page3_questions as $field => $label) {
            $this->form->addElement('select', "q3_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->addBasicText("q3_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q3_if_other_describe",
            array("q3_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page4_questions = array(
                            "stairs"               => "Stairs?",
                            "chairs"               => "Chairs?",
                            "furniture"            => "Furniture?",
                            "playground_equipment" => "Playground equipment?",
                           );

        $this->form->addElement('select', "q4_like_climbing", "4. Does your child like climbing on things? <h6>(FOR EXAMPLE, furniture, playground Yes No equipment, or stairs?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If yes: Please give me an example of something he/she enjoys climbing on. (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>4.1. Does he/she enjoy climbing on... (Always Required)</b>");

        foreach ($page4_questions as $field => $label) {
            $this->form->addElement('select', "q4_" . $field, $this->indent . $label, $this->yesNo);
        }
    }

    /**
     * Page 5
     *
     * @return void
     */
    function _page5()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page5_pass_examples = array(
                                "look_at_hands"                        => "Look at hands?",
                                "move_fingers_when_playing_peek_a_boo" => "Move fingers when playing peek-a-boo?",
                               );

        $page5_fail_examples = array(
                                "ignores_you"               => "Wiggle his/her fingers near his/her eyes?",
                                "look_around_room_randomly" => "Hold his/her hands up close to his/her eyes?",
                                "look_at_your_finger"       => "Hold his/her hands off to the side of his/her eyes?",
                                "flap_hands_near_face"      => "Flap his/her hands near his/her face?",
                                "other"                     => "Other (describe)",
                               );

        $this->form->addElement('select', "q5_unusual_finger_movements_near_eyes", "5. Does your child make unusual finger movements near his or her eyes? <h6>(FOR EXAMPLE, does your child wiggle his or her fingers close to his or her eyes?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please describe these movements (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>5.1. Does he/she... (Required if Yes to #5)</b><h6><i>(Below are <u>PASS</u> examples)</i></h6>");

        foreach ($page5_pass_examples as $field => $label) {
            $this->form->addElement('select', "q5_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q5_" . $field,
                array("q5_unusual_finger_movements_near_eyes{@}=={@}yes"),
                "Required."
            );
        }

        $this->form->addElement('static', null, "<b>5.2. Does he/she... (Required if Yes to #5)</b><h6><i>(Below are <u>FAIL</u> examples)</i></h6>");

        foreach ($page5_fail_examples as $field => $label) {
            $this->form->addElement('select', "q5_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q5_" . $field,
                array("q5_unusual_finger_movements_near_eyes{@}=={@}yes"),
                "Required."
            );
        }

        $this->addBasicText("q5_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q5_if_other_describe",
            array("q5_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('select', "q5_happen_more_than_twice_a_week", "5.3. If Yes to any FAIL examples: Does this happen more than twice a week?", $this->yesNo);

        $this->XINRegisterRule(
            "q5_happen_more_than_twice_a_week",
            array("q5_happen_more_than_twice_a_week{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page5'));
    }

    /**
     * Page 6
     *
     * @return void
     */
    function _page6()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page6_questions = array(
                            "reach_for_object_with_whole_hand" => "Reach for the object with his/her whole hand?",
                            "lead_you_to_object"               => "Lead you to the object?",
                            "try_to_get_object_for_self"       => "Try to get the object for him/herself?",
                            "ask_using_words_or_sounds"        => "Ask for it using words or sounds?",
                           );

        $this->form->addElement('select', "q6_point_one_finger_for_help", "6. Does your child point with one finger to ask for something or to get help? <h6>(FOR EXAMPLE, pointing to a snack or toy that is out of reach)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If No: If there is something your child wants that is out of reach, such as a snack or toy that is out of reach, how does he/she get it? (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>6.1. Does he/she... (Required if No to #6)</b>");

        foreach ($page6_questions as $field => $label) {
            $this->form->addElement('select', "q6_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q6_" . $field,
                array("q6_point_one_finger_for_help{@}=={@}no"),
                "Required."
            );
        }

        $this->form->addElement('select', "q6_show_me_point", "6.2. If Yes to any of the above: If you said \"Show me,\" would he/she point at it?", $this->yesNo);

        $this->XINRegisterRule(
            "q6_show_me_point",
            array("q6_show_me_point{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page6'));
    }

    /**
     * Page 7
     *
     * @return void
     */
    function _page7()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page7_questions = array(
                            "airplane_in_sky" => "An airplane in the sky?",
                            "truck_on_road"   => "A truck on the road?",
                            "bug_on_ground"   => "A bug on the ground?",
                            "animal_in_yard"  => "An animal in the yard?",
                           );

        $this->form->addElement('select', "q7_point_one_finger_show", "7. Does your child point with one finger to show you something interesting? <h6>(FOR EXAMPLE, pointing to an airplane in the sky or a big truck in the road)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example something he/she might point at to show you. (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>7.1. Does your child sometimes want you to see something interesting such as... (Always Required)</b>");

        foreach ($page7_questions as $field => $label) {
            $this->form->addElement('select', "q7_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addElement('select', "q7_child_draw_attention", "7.2. If Yes to any of the above: How does your child draw your attention to it? Would he/she point with one finger?", $this->yesNo);

        $this->XINRegisterRule(
            "q7_child_draw_attention",
            array("q7_child_draw_attention{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addElement('select', "q7_if_yes_show_interest_not_help", $this->indent . "7.3. If Yes to #7.2: Is this to show their interest, not to get help?", $this->yesNo);

        $this->XINRegisterRule(
            "q7_if_yes_show_interest_not_help",
            array("q7_child_draw_attention{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page7'));
    }

    /**
     * Page 8
     *
     * @return void
     */
    function _page8()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page8_questions = array(
                            "play_with_another_child"         => "Play with another child?",
                            "talk_to_another_child"           => "Talk to another child?",
                            "babble_or_make_vocal_noises"     => "Babble or make vocal noises?",
                            "watch_another_child"             => "Watch another child?",
                            "smile_at_another_child"          => "Smile at another child?",
                            "act_shy_at_first_then_smile"     => "Act shy at first but then smile?",
                            "get_excited_about_another_child" => "Get excited about another child?",
                           );

        $this->form->addElement('select', "q8_interested_other_children", "8. Is your child interested in other children? <h6>(FOR EXAMPLE, does your child watch other children, smile at them, or go to them?)</h6>", $this->yesNo);

        $this->form->addElement('select', "q8_interested_in_children_not_brother_or_sister", $this->indent . "8.1. If Yes to #8: Is he/she interested in children who are not his/her brother or sister?", $this->yesNo);

        $this->XINRegisterRule(
            "q8_interested_in_children_not_brother_or_sister",
            array("q8_interested_other_children{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('select', "q8_respond_to_other_children", "8.2. If No to #8 OR #8.1: When you are at the playground or supermarket, does your child usually respond to other children?", $this->yesNo);

        $this->XINRegisterRule(
            "q8_respond_to_other_children",
            array("q8_respond_to_other_children{@}=={@}NEVER_REQUIRED"),
            "Never Required."
        );

        $this->form->addElement('static', null, "If Yes to 8.2. How does your child respond? (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>8.3. Does your child... (Required if Yes to #8.2)</b>");

        foreach ($page8_questions as $field => $label) {
            $this->form->addElement('select', "q8_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q8_" . $field,
                array("q8_respond_to_other_children{@}=={@}yes"),
                "Required."
            );
        }

        $this->form->addElement('select', "q8_respond_to_other_children_more_than_half_the_time", "8.4. If Yes to any of the above: Does he/she respond to other children more than half of the time?", $this->yesNo);

        $this->XINRegisterRule(
            "q8_respond_to_other_children_more_than_half_the_time",
            array("q8_respond_to_other_children_more_than_half_the_time{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page8'));
    }

    /**
     * Page 9
     *
     * @return void
     */
    function _page9()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page9_questions = array(
                            "picture_or_toy_to_show_you" => "A picture or toy just to show you?",
                            "drawing_done"               => "A drawing he/she has done?",
                            "flower_has_picked"          => "A flower he/she has picked?",
                            "bug_found_in_grass"         => "A bug he/she has found in the grass?",
                            "few_blocks_put_together"    => "A few blocks he/she has put together?",
                            "other"                      => "Other (describe):",
                           );

        $this->form->addElement('select', "q9_show_things", "9. Does your child show you things by bringing them to you or holding them up for you to see – not to get help, but just to share? <h6>(FOR EXAMPLE, showing you a flower, a stuffed animal, or a toy truck)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example of something he/she might bring to show you or hold up for you to see. (<i>If parent does not give one of the following PASS examples, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>9.1. Does your child sometimes bring you... (Always Required)</b>");

        foreach ($page9_questions as $field => $label) {
            $this->form->addElement('select', "q9_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->addBasicText("q9_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q9_if_other_describe",
            array("q9_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('select', "q9_sometimes_just_to_show_you_not_get_help", "9.2. If Yes to any of the above: Is this sometimes just to show you, not to get help?", $this->yesNo);

        $this->XINRegisterRule(
            "q9_sometimes_just_to_show_you_not_get_help",
            array("q9_sometimes_just_to_show_you_not_get_help{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page9'));
    }

    /**
     * Page 10
     *
     * @return void
     */
    function _page10()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page10_pass_examples = array(
                                 "look_up"         => "Look up?",
                                 "talk_or_babble"  => "Talk or babble?",
                                 "stop_what_doing" => "Stop what he/she is doing?",
                                );

        $page10_fail_examples = array(
                                 "make_no_response"                           => "Make no response?",
                                 "seem_to_hear_but_ignores_parent"            => "Seem to hear but ignores parent?",
                                 "respond_only_if_parent_is_in_front_of_face" => "Respond only if parent is right in front of the child’s face?",
                                 "respond_only_if_touched"                    => "Respond only if touched?",
                                );

        $this->form->addElement('select', "q10_respond_by_name", "10. Does your child respond when you call his or her name? <h6>(FOR EXAMPLE, does he or she look up, talk or babble, or stop what he or she is doing when you call his or her name?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example of how he/she responds when you call his/her name. (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "If No: If he/she is not involved in something fun or interesting, what does he/she do when you call his/her name? (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>10.1. Does he/she... (Always Required)</b><h6><i>(Below are <u>PASS</u> examples)</i></h6>");

        foreach ($page10_pass_examples as $field => $label) {
            $this->form->addElement('select', "q10_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addElement('static', null, "<b>10.2. Does he/she... (Always Required)</b><h6><i>(Below are <u>FAIL</u> examples)</i></h6>");

        foreach ($page10_fail_examples as $field => $label) {
            $this->form->addElement('select', "q10_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addElement('select', "q10_yes_to_both_pass_and_fail", "10.3. If Yes to both PASS and FAIL examples, Which one does he/she do most often?:", [null => "", "pass" => "Pass example", "fail" => "Fail example"]);

        $this->XINRegisterRule(
            "q10_yes_to_both_pass_and_fail",
            array("q10_yes_to_both_pass_and_fail{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page10'));
    }

    /**
     * Page 11
     *
     * @return void
     */
    function _page11()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page11_pass_examples = array(
                                 "smile_when_you_smile"              => "Smile when you smile?",
                                 "smile_when_enter_room"             => "Smile when you enter the room?",
                                 "smile_when_return_from_being_away" => "Smile when you return from being away?",
                                );

        $page11_fail_examples = array(
                                 "always_smile"                      => "Always smile?",
                                 "smile_at_favorite_toy_or_activity" => "Smile at a favorite toy or activity?",
                                 "smile_randomly_or_nothing"         => "Smile randomly or at nothing in particular?",
                                );

        $this->form->addElement('select', "q11_smile_back", "11. When you smile at your child, does he or she smile back at you?", $this->yesNo);

        $this->form->addElement('static', null, "If No: What makes your child smile? (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>11.1. Does your child... (Required if No to #11)</b><h6><i>(Below are <u>PASS</u> examples)</i></h6>");

        foreach ($page11_pass_examples as $field => $label) {
            $this->form->addElement('select', "q11_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q11_" . $field,
                array("q11_smile_back{@}=={@}no"),
                "Required."
            );
        }

        $this->form->addElement('static', null, "<b>11.2. Does he/she... (Required if No to #11)</b><h6><i>(Below are <u>FAIL</u> examples)</i></h6>");

        foreach ($page11_fail_examples as $field => $label) {
            $this->form->addElement('select', "q11_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q11_" . $field,
                array("q11_smile_back{@}=={@}no"),
                "Required."
            );
        }

        $this->form->addElement('select', "q11_yes_to_both_pass_and_fail", "11.3. If Yes to both PASS and FAIL examples, Which one does he/she do most often?:", [null => "", "pass" => "Pass example", "fail" => "Fail example"]);

        $this->XINRegisterRule(
            "q11_yes_to_both_pass_and_fail",
            array("q11_yes_to_both_pass_and_fail{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page11'));
    }

    /**
     * Page 12
     *
     * @return void
     */
    function _page12()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page12_questions = array(
                             "washing_machine"                => "A washing machine?",
                             "babies_crying"                  => "Babies crying?",
                             "vacuum_cleaner"                 => "Vacuum cleaner?",
                             "hairdryer"                      => "Hairdryer?",
                             "traffic"                        => "Traffic?",
                             "babies_squealing_or_screeching" => "Babies squealing or screeching?",
                             "loud_music"                     => "Loud music?",
                             "telephone_doorbell_ringing"     => "Telephone/ doorbell ringing?",
                             "noisy_places"                   => "Noisy places such as a supermarket or restaurant?",
                             "other"                          => "Other (describe):",
                            );

        $page12_pass_examples = array(
                                 "calmly_cover_ears"   => "Calmly cover his/her ears?",
                                 "does_not_like_noise" => "Tell you that he/she does not like the noise?",
                                );

        $page12_fail_examples = array(
                                 "scream"                 => "Scream?",
                                 "cry"                    => "Cry?",
                                 "cover_ears_while_upset" => "Cover his/her ears while upset?",
                                );

        $this->form->addElement('select', "q12_upset_by_everyday_noises", "12. Does your child get upset by everyday noises? <h6>(FOR EXAMPLE, does your child scream or cry to noise such as a vacuum cleaner or loud music?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "<b>12.1. Does your child have a negative reaction to the sound of... (Required if Yes to #12)</b>");

        foreach ($page12_questions as $field => $label) {
            $this->form->addElement('select', "q12_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q12_" . $field,
                array("q12_upset_by_everyday_noises{@}=={@}yes"),
                "Required."
            );
        }

        $this->addBasicText("q12_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q12_if_other_describe",
            array("q12_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('static', null, "<b>12.2. Does your child... (Required if Yes to two or more in #12.1)</b><h6><i>(Below are <u>PASS</u> responses)</i></h6>");

        foreach ($page12_pass_examples as $field => $label) {
            $this->form->addElement('select', "q12_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q12_" . $field,
                array("q12_{$field}{@}=={@}NEVER_REQUIRED"),
                "Not Required."
            );
        }

        $this->form->addElement('static', null, "<b>12.3. Does your child... (Required if Yes to two or more in #12.1)</b><h6><i>(Below are <u>FAIL</u> responses)</i></h6>");

        foreach ($page12_fail_examples as $field => $label) {
            $this->form->addElement('select', "q12_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q12_" . $field,
                array("q12_{$field}{@}=={@}NEVER_REQUIRED"),
                "Not Required."
            );
        }

        $this->form->addElement('select', "q12_yes_to_both_pass_and_fail", "12.4. If Yes to both PASS and FAIL examples, Which one does he/she do most often?:", [null => "", "pass" => "Pass example", "fail" => "Fail example"]);

        $this->XINRegisterRule(
            "q12_yes_to_both_pass_and_fail",
            array("q12_yes_to_both_pass_and_fail{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page12'));
    }

    /**
     * Page 13
     *
     * @return void
     */
    function _page13()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $this->form->addElement('select', "q13_walk", "13. Does your child walk?", $this->yesNo);

        $this->form->addElement('select', "q13_walk_without_holding_anything", $this->indent . "13.1. If Yes to #13: Does he/she walk without holding on to anything?", $this->yesNo);

        $this->XINRegisterRule(
            "q13_walk_without_holding_anything",
            array("q13_walk{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page13'));
    }

    /**
     * Page 14
     *
     * @return void
     */
    function _page14()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page14_questions = array(
                             "needs_something"       => "When he/she needs something?",
                             "playing_with"          => "When you are playing with him/her?",
                             "during_feeding"        => "During feeding?",
                             "during_diaper_changes" => "During diaper changes?",
                             "when_reading_a_story"  => "When you are reading him/her a story?",
                             "when_talking"          => "When you are talking to him/her?",
                            );

        $this->form->addElement('select', "q14_look_in_eye", "14. Does your child look you in the eye when you are talking to him or her, playing with him or her, or dressing him or her?", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example of when he/she looks you in the eye. (<i>If parent does not give one of the following PASS examples, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>14.1. Does he/she look you in the eye... (Always Required)</b>");

        foreach ($page14_questions as $field => $label) {
            $this->form->addElement('select', "q14_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addElement('select', "q14_look_you_in_eye_every_day", "14.2. If Yes to only one above: Does your child look you in the eye every day?", $this->yesNo);

        $this->XINRegisterRule(
            "q14_look_you_in_eye_every_day",
            array("q14_look_you_in_eye_every_day{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addElement('select', "q14_look_you_in_eye_5_times", $this->indent . "14.3. If Yes to #14.2: On a day when you are together all day, does he/she look you in the eye at least 5 times?", $this->yesNo);

        $this->XINRegisterRule(
            "q14_look_you_in_eye_5_times",
            array("q14_look_you_in_eye_every_day{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page14'));
    }

    /**
     * Page 15
     *
     * @return void
     */
    function _page15()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page15_questions = array(
                             "stick_out_tongue"                => "Stick out your tongue?",
                             "make_funny_sound"                => "Make a funny sound?",
                             "wave_good_bye"                   => "Wave good bye?",
                             "clap_hands"                      => "Clap your hands?",
                             "put_fingers_to_lips_signal_shhh" => "Put your fingers to your lips to signal “Shhh”?",
                             "blow_kiss"                       => "Blow a kiss?",
                             "other"                           => "Other (describe):",
                            );

        $this->form->addElement('select', "q15_copy_you", "15. Does your child try to copy what you do? <h6>(FOR EXAMPLE, wave bye-bye, clap, or make a funny noise when you do)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example of something he/she would try to copy. (<i>If parent does not give one of the following pass examples, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>15.1. Does your child try to copy you if you... (Always Required)</b>");

        foreach ($page15_questions as $field => $label) {
            $this->form->addElement('select', "q15_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->addBasicText("q15_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q15_if_other_describe",
            array("q15_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page15'));
    }

    /**
     * Page 16
     *
     * @return void
     */
    function _page16()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page16_pass_examples = array(
                                 "look_toward_thing_looking_at"    => "Look toward the thing you are looking at?",
                                 "point_toward_thing_looking_at"   => "Point toward the thing you are looking at?",
                                 "look_around_see_what_looking_at" => "Look around to see what you are looking at?",
                                );

        $page16_fail_examples = array(
                                 "ignore_you"        => "Ignore you?",
                                 "look_at_your_face" => "Look at your face?",
                                );

        $this->form->addElement('select', "q16_look_around", "16. If you turn your head to look at something, does your child look around to see what you are looking at?", $this->yesNo);

        $this->form->addElement('static', null, "If No: What does he/she do when you turn to look at something? (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>16.1. Does your child... (Required if No to #16)</b><h6><i>(Below are <u>PASS</u> responses)</i></h6>");

        foreach ($page16_pass_examples as $field => $label) {
            $this->form->addElement('select', "q16_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q16_" . $field,
                array("q16_look_around{@}=={@}no"),
                "Required."
            );
        }

        $this->form->addElement('static', null, "<b>16.2. Does your child... (Required if No to #16)</b><h6><i>(Below are <u>FAIL</u> responses)</i></h6>");

        foreach ($page16_fail_examples as $field => $label) {
            $this->form->addElement('select', "q16_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q16_" . $field,
                array("q16_look_around{@}=={@}no"),
                "Required."
            );
        }

        $this->form->addElement('select', "q16_yes_to_both_pass_and_fail", "16.3. If Yes to both PASS and FAIL examples, Which one does he/she do most often?:", [null => "", "pass" => "Pass example", "fail" => "Fail example"]);

        $this->XINRegisterRule(
            "q16_yes_to_both_pass_and_fail",
            array("q16_yes_to_both_pass_and_fail{@}=={@}NEVER_REQUIRED"),
            "Not Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page16'));
    }

    /**
     * Page 17
     *
     * @return void
     */
    function _page17()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page17_questions = array(
                             "say_look_or_watch_me"           => "Say \"Look!\" or \"Watch me!\"?",
                             "babble_or_make_noise"           => "Babble or make a noise to get you to watch what he/she is doing?",
                             "look_to_get_praise_or_comment"  => "Look at you to get praise or comment?",
                             "keep_looking_to_see_if_looking" => "Keep looking to see if you are looking?",
                             "other"                          => "Other (describe):",
                            );

        $this->form->addElement('select', "q17_try_watch", "17. Does your child try to get you to watch him or her? <h6>(FOR EXAMPLE, does your child look at you for praise, or say \"look\" or \"watch me\"?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes: Please give me an example of how he/she would try to get you to watch him/her. (<i>If parent does not give a PASS example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>17.1. Does he/she... (Always Required)</b>");

        foreach ($page17_questions as $field => $label) {
            $this->form->addElement('select', "q17_" . $field, $this->indent . $label, $this->yesNo);
        }

        $this->addBasicText("q17_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q17_if_other_describe",
            array("q17_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page17'));
    }

    /**
     * Page 18
     *
     * @return void
     */
    function _page18()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $this->form->addElement('select', "q18_understand_tell_something", "18. Does your child understand when you tell him or her to do something? <h6>(FOR EXAMPLE, if you don’t point, can your child understand \"put the book on the chair\" or \"bring me the blanket\"?)</h6>", $this->yesNo);

        $this->form->addElement('static', null, "If Yes to #18: Please give me an example of how you know he/she understands you.");

        $this->form->addElement('select', "q18_follow_a_command", $this->indent . "18.1. If No to #18: When the situation gives him/her a clue, can he/she follow a command? For example when you are dressed to go out and you tell him/her to get his/her shoes, does he/she understand?", $this->yesNo);

        $this->XINRegisterRule(
            "q18_follow_a_command",
            array("q18_understand_tell_something{@}=={@}no"),
            "Required."
        );

        $this->form->addElement('select', "q18_dinnertime_food_sit_at_table", "18.2. If No to #18.1: If it is dinnertime and food is on the table, and you tell the child to sit down, will he/she come sit at the table?", $this->yesNo);

        $this->XINRegisterRule(
            "q18_dinnertime_food_sit_at_table",
            array("q18_follow_a_command{@}=={@}no"),
            "Required."
        );

        $this->form->addElement('static', null, "18.3. If Yes to #18.1 OR #18.2: When the situation does not give any clues, can he/she follow a command? For example... <h6>(<i>ask until you get a yes or use all examples</i>)</h6>");

        $page18_questions = array(
                             "1_show_me_your_shoe"         => "1. If you say, \"Show me your shoe\" without pointing, making gestures, or giving hints (when you are not going out or getting dressed), does your child show you his/her shoe?",
                             "2_bring_me_the_blanket"      => "2. If you say, \"Bring me the blanket\" or ask for another object without pointing, making gestures, or giving hints, does your child bring it to you?",
                             "3_put_the_book_on_the_chair" => "3. If you say, \"Put the book on the chair\" without pointing, making gestures, or giving any other hints , does your child put the book on the chair?",
                            );

        foreach ($page18_questions as $field => $label) {
            $this->form->addElement('select', "q18_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q18_" . $field,
                array("q18_{$field}{@}=={@}NEVER_REQUIRED"),
                "Not Required."
            );
        }

        $this->form->addFormRule(array(&$this, 'validate_page18'));
    }

    /**
     * Page 19
     *
     * @return void
     */
    function _page19()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $this->form->addElement('select', "q19_look_at_face", "19. If something new happens, does your child look at your face to see how you feel about it? <h6>(FOR EXAMPLE, if he or she hears a strange or funny noise, or sees a new toy, will he or she look at your face?)</h6>", $this->yesNo);

        $this->form->addElement('select', "q19_hears_noise_look_before_responding", $this->indent . "19.1. If No to #19: If your child hears a strange or scary noise, will he/she look at you <u>before</u> responding?", $this->yesNo);
        $this->XINRegisterRule(
            "q19_hears_noise_look_before_responding",
            array("q19_look_at_face{@}=={@}no"),
            "Required."
        );

        $this->form->addElement('select', "q19_look_at_you_when_someone_approaches", $this->indent . $this->indent . "19.2. If No to #19.1: Does your child <u>look at you</u> when someone new approaches?", $this->yesNo);
        $this->XINRegisterRule(
            "q19_look_at_you_when_someone_approaches",
            array("q19_hears_noise_look_before_responding{@}=={@}no"),
            "Required."
        );

        $this->form->addElement('select', "q19_look_at_you_when_faced_unfamiliar_or_scary", $this->indent . $this->indent . $this->indent . "19.3. If No to #19.2: Does your child <u>look at you</u> when he/she is faced with something unfamiliar or a little scary?", $this->yesNo);
        $this->XINRegisterRule(
            "q19_look_at_you_when_faced_unfamiliar_or_scary",
            array("q19_look_at_you_when_someone_approaches{@}=={@}no"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page19'));
    }

    /**
     * Page 20
     *
     * @return void
     */
    function _page20()
    {
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");

        $page20_questions = array(
                             "laugh_or_smile"                  => "Laugh or smile?",
                             "talk_or_babble"                  => "Talk or babble?",
                             "request_more_by_holding_out_arm" => "Request more by holding out his/her arms?",
                             "other"                           => "Other (describe)",
                            );

        $this->form->addElement('select', "q20_movement_activities", "20. Does your child like movement activities? <h6>(FOR EXAMPLE, being swung or bounced on your knee)</h6>", $this->yesNo);

        $this->form->addElement('select', "q20_enjoy_being_bounced_or_swung", $this->indent . "20.1. If Yes to #20: Does he/she enjoy being bounced or swung?", $this->yesNo);

        $this->XINRegisterRule(
            "q20_enjoy_being_bounced_or_swung",
            array("q20_movement_activities{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement('static', null, "When you swing or bounce him/her, how does he/she react? (<i>If parent does not give an example below, ask each individually.</i>)");

        $this->form->addElement('static', null, "<b>20.2. Does your child... (Required if No to #20 OR #20.1)</b>");

        foreach ($page20_questions as $field => $label) {
            $this->form->addElement('select', "q20_" . $field, $this->indent . $label, $this->yesNo);

            $this->XINRegisterRule(
                "q20_" . $field,
                array("q20_{$field}{@}=={@}NEVER_REQUIRED"),
                "Not Required."
            );
        }

        $this->addBasicText("q20_if_other_describe", $this->indent . $this->indent . "If other, describe:");

        $this->XINRegisterRule(
            "q20_if_other_describe",
            array("q20_other{@}=={@}yes"),
            "Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page20'));
    }

    /**
     * If array contains at least one instance that isn't == $response, return false
     * If array doesn't contain any instances that aren't == $response, return true
     *
     * @return boolean
     */
    function checkIfAll($question_array, $response, $record)
    {
        foreach ($question_array as $q) {
            if ($record[$q] != $response) {
                return false;
            }
        }

        return true;
    }

    /**
     * Counts the number of times a question in the given array is answered with a given response
     *
     * @return integer
     */
    function countResponse($question_array, $response, $record)
    {
        $count = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == $response) {
                $count++;
            }
        }

        return $count;
    }

    function validate_page1($values)
    {
        $errors = [];

        $q1_pass_yes_count = $this->countResponse(self::PAGE1_PASS_EXAMPLES, "yes", $values);
        $q1_fail_yes_count = $this->countResponse(self::PAGE1_FAIL_EXAMPLES, "yes", $values);

        if ($q1_pass_yes_count > 0 && $q1_fail_yes_count > 0) {
            if ($values["q1_yes_to_both_pass_and_fail"] == null) {
                $errors["q1_yes_to_both_pass_and_fail"] = "Required if Yes to both PASS and FAIL examples.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q1_yes_to_both_pass_and_fail"], $errors);
        }

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        $page2_questions = array(
                            "q2_often_ignore_sounds",
                            "q2_often_ignore_people",
                            "q2_hearing_tested",
                            "q2_results_of_hearing_test",
                           );

        if ($values["q2_deaf"] == "no") {
            $this->validate_empty_subquestions($values, $page2_questions, $errors);
        }

        if ($values["q2_hearing_tested"] == "no") {
            $this->validate_empty_subquestions($values, ["q2_results_of_hearing_test"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["q3_other"] == "no") {
            $this->validate_empty_subquestions($values, ["q3_if_other_describe"], $errors);
        }

        return $errors;
    }

    // No validate_page4

    function validate_page5($values)
    {
        $errors = [];

        if ($values["q5_unusual_finger_movements_near_eyes"] == "no") {
            $this->validate_empty_subquestions($values, self::PAGE5_PASS_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, self::PAGE5_FAIL_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, ["q5_if_other_describe"], $errors);
            $this->validate_empty_subquestions($values, ["q5_happen_more_than_twice_a_week"], $errors);
        } else {
            if ($values["q5_other"] == "no") {
                $this->validate_empty_subquestions($values, ["q5_if_other_describe"], $errors);
            }

            $q5_fail_yes_count = $this->countResponse(self::PAGE5_FAIL_EXAMPLES, "yes", $values);

            if ($q5_fail_yes_count > 0) {
                if ($values["q5_happen_more_than_twice_a_week"] == null) {
                    $errors["q5_happen_more_than_twice_a_week"] = "Required if Yes to any FAIL examples.";
                }
            } else {
                $this->validate_empty_subquestions($values, ["q5_happen_more_than_twice_a_week"], $errors);
            }

        }

        return $errors;
    }

    function validate_page6($values)
    {
        $errors = [];

        $q6_yes_count = $this->countResponse(self::PAGE6_QUESTIONS, "yes", $values);

        if ($values["q6_point_one_finger_for_help"] == "yes") {
            $this->validate_empty_subquestions($values, self::PAGE6_QUESTIONS, $errors);
            $this->validate_empty_subquestions($values, ["q6_show_me_point"], $errors);
        } else {
            if ($q6_yes_count > 0) {
                if ($values["q6_show_me_point"] == null) {
                    $errors["q6_show_me_point"] = "Required if Yes to any of above examples.";
                }
            } else {
                $this->validate_empty_subquestions($values, ["q6_show_me_point"], $errors);
            }
        }

        return $errors;
    }

    function validate_page7($values)
    {
        $errors = [];

        $q7_yes_count = $this->countResponse(self::PAGE7_QUESTIONS, "yes", $values);

        if ($q7_yes_count > 0) {
            if ($values["q7_child_draw_attention"] == null) {
                $errors["q7_child_draw_attention"] = "Required if Yes to any of the above.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q7_child_draw_attention"], $errors);
        }

        if ($values["q7_child_draw_attention"] == "no") {
            $this->validate_empty_subquestions($values, ["q7_if_yes_show_interest_not_help"], $errors);
        }

        return $errors;
    }

    function validate_page8($values)
    {
        $errors = [];

        if ($values["q8_interested_other_children"] == "no") {
            $this->validate_empty_subquestions($values, ["q8_interested_in_children_not_brother_or_sister"], $errors);
            if ($values["q8_respond_to_other_children"] == null) {
                $errors["q8_respond_to_other_children"] = "Required if #8 OR #8.1 is answered No.";
            }
        } else {
            if ($values["q8_interested_in_children_not_brother_or_sister"] == "yes") {
                $this->validate_empty_subquestions($values, ["q8_respond_to_other_children"], $errors);
            } else {
                if ($values["q8_respond_to_other_children"] == null) {
                    $errors["q8_respond_to_other_children"] = "Required if #8 OR #8.1 is answered No.";
                }
            }
        }

        if ($values["q8_respond_to_other_children"] != "yes") {
            $this->validate_empty_subquestions($values, self::PAGE8_QUESTIONS, $errors);
        } else {
            $q8_yes_count = $this->countResponse(self::PAGE8_QUESTIONS, "yes", $values);

            if ($q8_yes_count > 0) {
                if ($values["q8_respond_to_other_children_more_than_half_the_time"] == null) {
                    $errors["q8_respond_to_other_children_more_than_half_the_time"] = "Required if Yes to any of above examples.";
                }
            } else {
                $this->validate_empty_subquestions($values, ["q8_respond_to_other_children_more_than_half_the_time"], $errors);
            }
        }

        return $errors;
    }

    function validate_page9($values)
    {
        $errors = [];

        if ($values["q9_other"] == "no") {
            $this->validate_empty_subquestions($values, ["q9_if_other_describe"], $errors);
        }

        $q9_yes_count = $this->countResponse(self::PAGE9_QUESTIONS, "yes", $values);

        if ($q9_yes_count > 0) {
            if ($values["q9_sometimes_just_to_show_you_not_get_help"] == null) {
                $errors["q9_sometimes_just_to_show_you_not_get_help"] = "Required if Yes to any of above examples.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q9_sometimes_just_to_show_you_not_get_help"], $errors);
        }

        return $errors;
    }

    function validate_page10($values)
    {
        $errors = [];

        $q10_pass_yes_count = $this->countResponse(self::PAGE10_PASS_EXAMPLES, "yes", $values);
        $q10_fail_yes_count = $this->countResponse(self::PAGE10_FAIL_EXAMPLES, "yes", $values);

        if ($q10_pass_yes_count > 0 && $q10_fail_yes_count > 0) {
            if ($values["q10_yes_to_both_pass_and_fail"] == null) {
                $errors["q10_yes_to_both_pass_and_fail"] = "Required if Yes to both PASS and FAIL examples.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q10_yes_to_both_pass_and_fail"], $errors);
        }

        return $errors;
    }

    function validate_page11($values)
    {
        $errors = [];

        if ($values["q11_smile_back"] == "yes") {
            $this->validate_empty_subquestions($values, self::PAGE11_PASS_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, self::PAGE11_FAIL_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, ["q11_yes_to_both_pass_and_fail"], $errors);
        }

        $q11_pass_yes_count = $this->countResponse(self::PAGE11_PASS_EXAMPLES, "yes", $values);
        $q11_fail_yes_count = $this->countResponse(self::PAGE11_FAIL_EXAMPLES, "yes", $values);

        if ($q11_pass_yes_count > 0 && $q11_fail_yes_count > 0) {
            if ($values["q11_yes_to_both_pass_and_fail"] == null) {
                $errors["q11_yes_to_both_pass_and_fail"] = "Required if Yes to both PASS and FAIL examples.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q11_yes_to_both_pass_and_fail"], $errors);
        }

        return $errors;
    }

    function validate_page12($values)
    {
        $errors = [];

        if ($values["q12_other"] == "no") {
            $this->validate_empty_subquestions($values, ["q12_if_other_describe"], $errors);
        }

        if ($values["q12_upset_by_everyday_noises"] == "no") {
            $this->validate_empty_subquestions($values, self::PAGE12_QUESTIONS, $errors);
            $this->validate_empty_subquestions($values, self::PAGE12_PASS_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, self::PAGE12_FAIL_EXAMPLES, $errors);
        }

        $q12_yes_count = $this->countResponse(self::PAGE12_QUESTIONS, "yes", $values);

        if ($q12_yes_count <= 1) {
            $this->validate_empty_subquestions($values, self::PAGE12_PASS_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, self::PAGE12_FAIL_EXAMPLES, $errors);
        } else {
            foreach (self::PAGE12_PASS_EXAMPLES as $q) {
                if ($values[$q] == null) {
                    $errors[$q] = "Required if Yes to two or more above.";
                }
            }
            foreach (self::PAGE12_FAIL_EXAMPLES as $q) {
                if ($values[$q] == null) {
                    $errors[$q] = "Required if Yes to two or more above.";
                }
            }
        }

        $q12_pass_yes_count = $this->countResponse(self::PAGE12_PASS_EXAMPLES, "yes", $values);
        $q12_fail_yes_count = $this->countResponse(self::PAGE12_PASS_EXAMPLES, "yes", $values);

        if ($q12_pass_yes_count > 0 && $q12_fail_yes_count > 0) {
            if ($values["q12_yes_to_both_pass_and_fail"] == null) {
                $errors["q12_yes_to_both_pass_and_fail"] = "Required if Yes to both PASS and FAIL examples.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q12_yes_to_both_pass_and_fail"], $errors);
        }

        return $errors;
    }

    function validate_page13($values)
    {
        $errors = [];

        if ($values["q13_walk"] == "no") {
            $this->validate_empty_subquestions($values, ["q13_walk_without_holding_anything"], $errors);
        }

        return $errors;
    }

    function validate_page14($values)
    {
        $errors = [];

        $q14_yes_count = $this->countResponse(self::PAGE14_QUESTIONS, "yes", $values);

        if ($q14_yes_count == 1) {
            if ($values["q14_look_you_in_eye_every_day"] == null) {
                $errors["q14_look_you_in_eye_every_day"] = "Required if Yes to only one above.";
            }
            if ($values["q14_look_you_in_eye_every_day"] == "no") {
                $this->validate_empty_subquestions($values, ["q14_look_you_in_eye_5_times"], $errors);
            }
        } else {
            $this->validate_empty_subquestions($values, ["q14_look_you_in_eye_every_day", "q14_look_you_in_eye_5_times"], $errors);
        }

        return $errors;
    }

    function validate_page15($values)
    {
        $errors = [];

        if ($values["q15_other"] == "no") {
            $this->validate_empty_subquestions($values, ["q15_if_other_describe"], $errors);
        }

        return $errors;
    }

    function validate_page16($values)
    {
        $errors = [];

        if ($values["q16_look_around"] == "yes") {
            $this->validate_empty_subquestions($values, self::PAGE16_PASS_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, self::PAGE16_FAIL_EXAMPLES, $errors);
            $this->validate_empty_subquestions($values, ["q16_yes_to_both_pass_and_fail"], $errors);
        }

        $q16_pass_yes_count = $this->countResponse(self::PAGE16_PASS_EXAMPLES, "yes", $values);
        $q16_fail_yes_count = $this->countResponse(self::PAGE16_FAIL_EXAMPLES, "yes", $values);

        if ($q16_pass_yes_count > 0 && $q16_fail_yes_count > 0) {
            if ($values["q16_yes_to_both_pass_and_fail"] == null) {
                $errors["q16_yes_to_both_pass_and_fail"] = "Required if Yes to both PASS and FAIL examples.";
            }
        } else {
            $this->validate_empty_subquestions($values, ["q16_yes_to_both_pass_and_fail"], $errors);
        }

        return $errors;
    }

    function validate_page17($values)
    {
        $errors = [];

        if ($values["q17_other"] == "no") {
            $this->validate_empty_subquestions($values, ["q17_if_other_describe"], $errors);
        }

        return $errors;
    }


    function validate_page18($values)
    {
        $errors = [];

        if ($values["q18_understand_tell_something"] == "yes") {
            $this->validate_empty_subquestions($values, ["q18_follow_a_command", "q18_dinnertime_food_sit_at_table"], $errors);
            $this->validate_empty_subquestions($values, self::PAGE18_QUESTIONS, $errors);
        }

        if ($values["q18_understand_tell_something"] == "no") {
            if ($values["q18_follow_a_command"] == "no" && $values["q18_dinnertime_food_sit_at_table"] == "no") {
                $this->validate_empty_subquestions($values, self::PAGE18_QUESTIONS, $errors);
            }

            if ($values["q18_follow_a_command"] == "yes" || $values["q18_dinnertime_food_sit_at_table"] == "yes") {
                if ($values["q18_1_show_me_your_shoe"] == null) {
                    $errors["q18_1_show_me_your_shoe"] = "Required.";
                }

                if ($values["q18_1_show_me_your_shoe"] == "no") {
                    if ($values["q18_2_bring_me_the_blanket"] == null) {
                        $errors["q18_2_bring_me_the_blanket"] = "Required.";
                    }

                    if ($values["q18_2_bring_me_the_blanket"] == "no") {
                        if ($values["q18_3_put_the_book_on_the_chair"] == null) {
                            $errors["q18_3_put_the_book_on_the_chair"] = "Required.";
                        }
                    }
                }
            }
        }

        return $errors;
    }

    function validate_page19($values)
    {
        $errors = [];

        if ($values["q19_look_at_face"] != "no") {
            $this->validate_empty_subquestions($values, ["q19_hears_noise_look_before_responding"], $errors);
            $this->validate_empty_subquestions($values, ["q19_look_at_you_when_someone_approaches"], $errors);
            $this->validate_empty_subquestions($values, ["q19_look_at_you_when_faced_unfamiliar_or_scary"], $errors);
        }

        if ($values["q19_hears_noise_look_before_responding"] != "no") {
            $this->validate_empty_subquestions($values, ["q19_look_at_you_when_someone_approaches"], $errors);
            $this->validate_empty_subquestions($values, ["q19_look_at_you_when_faced_unfamiliar_or_scary"], $errors);
        }

        if ($values["q19_look_at_you_when_someone_approaches"] != "no") {
            $this->validate_empty_subquestions($values, ["q19_look_at_you_when_faced_unfamiliar_or_scary"], $errors);
        }

        return $errors;
    }

    function validate_page20($values)
    {
        $errors = [];

        if ($values["q20_other"] == "no") {
            $this->validate_empty_subquestions($values, ["q20_if_other_describe"], $errors);
        }

        if ($values["q20_movement_activities"] == "no") {
            $this->validate_empty_subquestions($values, ["q20_enjoy_being_bounced_or_swung"], $errors);
        }

        if ($values["q20_movement_activities"] == "yes" && $values["q20_enjoy_being_bounced_or_swung"] == "yes") {
            $this->validate_empty_subquestions($values, self::PAGE20_QUESTIONS, $errors);
        }

        if ($values["q20_movement_activities"] == "no" || $values["q20_enjoy_being_bounced_or_swung"] == "no") {
            foreach (self::PAGE20_QUESTIONS as $q) {
                if ($values[$q] == null) {
                    $errors[$q] = "Required.";
                }
            }
        }

        return $errors;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());

        $scores = array(
                   "q1_pass_or_fail"  => null,
                   "q2_pass_or_fail"  => null,
                   "q3_pass_or_fail"  => null,
                   "q4_pass_or_fail"  => null,
                   "q5_pass_or_fail"  => null,
                   "q6_pass_or_fail"  => null,
                   "q7_pass_or_fail"  => null,
                   "q8_pass_or_fail"  => null,
                   "q9_pass_or_fail"  => null,
                   "q10_pass_or_fail" => null,
                   "q11_pass_or_fail" => null,
                   "q12_pass_or_fail" => null,
                   "q13_pass_or_fail" => null,
                   "q14_pass_or_fail" => null,
                   "q15_pass_or_fail" => null,
                   "q16_pass_or_fail" => null,
                   "q17_pass_or_fail" => null,
                   "q18_pass_or_fail" => null,
                   "q19_pass_or_fail" => null,
                   "q20_pass_or_fail" => null,
                  );

        /************************
         * Question 1           *
         * q1_point_across_room *
         ************************/

        $q1_pass_yes_count = $this->countResponse(self::PAGE1_PASS_EXAMPLES, "yes", $record);
        $q1_fail_yes_count = $this->countResponse(self::PAGE1_FAIL_EXAMPLES, "yes", $record);

        // Yes to only PASS example(s)
        if ($q1_pass_yes_count > 0 && $q1_fail_yes_count == 0) {
            $scores["q1_pass_or_fail"] = "Pass";
        }
        // Yes to both PASS and FAIL examples
        if ($q1_pass_yes_count > 0 && $q1_fail_yes_count > 0) {
            if ($record["q1_yes_to_both_pass_and_fail"] == "pass") {
                $scores["q1_pass_or_fail"] = "Pass";
            } else {
                $scores["q1_pass_or_fail"] = "Fail";
            }
        }
        // Yes to only FAIL example(s)
        if ($q1_pass_yes_count == 0 && $q1_fail_yes_count > 0) {
            $scores["q1_pass_or_fail"] = "Fail";
        }

        /**************
         * Question 2 *
         * q2_deaf    *
         **************/
        $q2_all_no = $this->checkIfAll(["q2_often_ignore_sounds", "q2_often_ignore_people"], "no", $record);

        if ($record["q2_deaf"] == "yes") {
            if ($q2_all_no) {
                $scores["q2_pass_or_fail"] = "Pass";
            } elseif (!$q2_all_no) {
                $scores["q2_pass_or_fail"] = "Fail";
            }
        }

        if ($record["q2_deaf"] == "no") {
            $scores["q2_pass_or_fail"] = "N/A";
        }

        /*******************
         * Question 3      *
         * q3_play_pretend *
         *******************/

        $q3_all_no    = $this->checkIfAll(self::PAGE3_QUESTIONS, "no", $record);
        $q3_yes_count = $this->countResponse(self::PAGE3_QUESTIONS, "yes", $record);

        if ($q3_all_no) {
            $scores["q3_pass_or_fail"] = "Fail";
        } else {
            if ($q3_yes_count > 0) {
                $scores["q3_pass_or_fail"] = "Pass";
            }
        }

        /********************
         * Question 4       *
         * q4_like_climbing *
         ********************/

        $q4_all_no    = $this->checkIfAll(self::PAGE4_QUESTIONS, "no", $record);
        $q4_yes_count = $this->countResponse(self::PAGE4_QUESTIONS, "yes", $record);

        if ($q4_all_no) {
            $scores["q4_pass_or_fail"] = "Fail";
        } else {
            if ($q4_yes_count > 0) {
                $scores["q4_pass_or_fail"] = "Pass";
            }
        }

        /*****************************************
         * Question 5                            *
         * q5_unusual_finger_movements_near_eyes *
         *****************************************/

        $q5_fail_all_no    = $this->checkIfAll(self::PAGE5_FAIL_EXAMPLES, "no", $record);
        $q5_pass_yes_count = $this->countResponse(self::PAGE5_PASS_EXAMPLES, "yes", $record);
        $q5_fail_yes_count = $this->countResponse(self::PAGE5_FAIL_EXAMPLES, "yes", $record);

        if ($record["q5_unusual_finger_movements_near_eyes"] == "no") {
            $scores["q5_pass_or_fail"] = "Pass";
        }

        if ($record["q5_unusual_finger_movements_near_eyes"] == "yes") {
            if ($q5_fail_all_no) {
                $scores["q5_pass_or_fail"] = "Pass";
            } else {
                if ($q5_pass_yes_count > 0 && $q5_fail_yes_count == 0) {
                    $scores["q5_pass_or_fail"] = "Pass";
                }

                if ($q5_fail_yes_count > 0) {
                    if ($record["q5_happen_more_than_twice_a_week"] == "no") {
                        $scores["q5_pass_or_fail"] = "Pass";
                    } else {
                        $scores["q5_pass_or_fail"] = "Fail";
                    }
                }
            }
        }

        /********************************
         * Question 6                   *
         * q6_point_one_finger_for_help *
         ********************************/

        $q6_all_no    = $this->checkIfAll(self::PAGE6_QUESTIONS, "no", $record);
        $q6_yes_count = $this->countResponse(self::PAGE6_QUESTIONS, "yes", $record);

        if ($record["q6_point_one_finger_for_help"] == "yes") {
            $scores["q6_pass_or_fail"] = "Pass";
        }

        if ($record["q6_point_one_finger_for_help"] == "no") {
            if ($q6_all_no) {
                $scores["q6_pass_or_fail"] = "Fail";
            } else {
                if ($q6_yes_count > 0) {
                    if ($record["q6_show_me_point"] == "yes") {
                        $scores["q6_pass_or_fail"] = "Pass";
                    } else {
                        $scores["q6_pass_or_fail"] = "Fail";
                    }
                }
            }
        }

        /****************************
         * Question 7               *
         * q7_point_one_finger_show *
         ****************************/

        $q7_all_no    = $this->checkIfAll(self::PAGE7_QUESTIONS, "no", $record);
        $q7_yes_count = $this->countResponse(self::PAGE7_QUESTIONS, "yes", $record);

        if ($q7_all_no) {
            $scores["q7_pass_or_fail"] = "Fail";
        } else {
            if ($q7_yes_count > 0) {
                if ($record["q7_child_draw_attention"] == "no") {
                    $scores["q7_pass_or_fail"] = "Fail";
                } else {
                    if ($record["q7_if_yes_show_interest_not_help"] == "no") {
                        $scores["q7_pass_or_fail"] = "Fail";
                    } else {
                        $scores["q7_pass_or_fail"] = "Pass";
                    }
                }
            }
        }

        /********************************
         * Question 8                   *
         * q8_interested_other_children *
         ********************************/

        $q8_yes_count = $this->countResponse(self::PAGE8_QUESTIONS, "yes", $record);

        if ($record["q8_interested_other_children"] == "yes" && $record["q8_interested_in_children_not_brother_or_sister"] == "yes" ) {
            $scores["q8_pass_or_fail"] = "Pass";
        } else {
            if ($record["q8_respond_to_other_children"] == "no") {
                $scores["q8_pass_or_fail"] = "Fail";
            }

            if ($record["q8_respond_to_other_children"] == "yes") {
                if ($q8_yes_count > 0) {
                    if ($record["q8_respond_to_other_children_more_than_half_the_time"] == "yes") {
                        $scores["q8_pass_or_fail"] = "Pass";
                    } else {
                        $scores["q8_pass_or_fail"] = "Fail";
                    }
                } else {
                    $scores["q8_pass_or_fail"] = "Fail";
                }
            }
        }

        /******************
         * Question 9     *
         * q9_show_things *
         ******************/

        $q9_all_no    = $this->checkIfAll(self::PAGE9_QUESTIONS, "no", $record);
        $q9_yes_count = $this->countResponse(self::PAGE9_QUESTIONS, "yes", $record);

        if ($q9_all_no) {
            $scores["q9_pass_or_fail"] = "Fail";
        } else {
            if ($q9_yes_count > 0) {
                if ($record["q9_sometimes_just_to_show_you_not_get_help"] == "no") {
                    $scores["q9_pass_or_fail"] = "Fail";
                } else {
                    $scores["q9_pass_or_fail"] = "Pass";
                }
            }
        }

        /***********************
         * Question 10         *
         * q10_respond_by_name *
         ***********************/

        $q10_pass_yes_count = $this->countResponse(self::PAGE10_PASS_EXAMPLES, "yes", $record);
        $q10_fail_yes_count = $this->countResponse(self::PAGE10_FAIL_EXAMPLES, "yes", $record);

        // Yes to only PASS example(s)
        if ($q10_pass_yes_count > 0 && $q10_fail_yes_count == 0) {
            $scores["q10_pass_or_fail"] = "Pass";
        }
        // Yes to both PASS and FAIL examples
        if ($q10_pass_yes_count > 0 && $q10_fail_yes_count > 0) {
            if ($record["q10_yes_to_both_pass_and_fail"] == "pass") {
                $scores["q10_pass_or_fail"] = "Pass";
            } else {
                $scores["q10_pass_or_fail"] = "Fail";
            }
        }
        // Yes to only FAIL example(s)
        if ($q10_pass_yes_count == 0 && $q10_fail_yes_count > 0) {
            $scores["q10_pass_or_fail"] = "Fail";
        }

        /******************
         * Question 11    *
         * q11_smile_back *
         ******************/

        $q11_pass_yes_count = $this->countResponse(self::PAGE11_PASS_EXAMPLES, "yes", $record);
        $q11_fail_yes_count = $this->countResponse(self::PAGE11_FAIL_EXAMPLES, "yes", $record);

        if ($record["q11_smile_back"] == "yes") {
            $scores["q11_pass_or_fail"] = "Pass";
        }

        if ($record["q11_smile_back"] == "no") {
            // Yes to only PASS example(s)
            if ($q11_pass_yes_count > 0 && $q11_fail_yes_count == 0) {
                $scores["q11_pass_or_fail"] = "Pass";
            }
            // Yes to both PASS and FAIL examples
            if ($q11_pass_yes_count > 0 && $q11_fail_yes_count > 0) {
                if ($record["q11_yes_to_both_pass_and_fail"] == "pass") {
                    $scores["q11_pass_or_fail"] = "Pass";
                } else {
                    $scores["q11_pass_or_fail"] = "Fail";
                }
            }
            // Yes to only FAIL example(s)
            if ($q11_pass_yes_count == 0 && $q11_fail_yes_count > 0) {
                $scores["q11_pass_or_fail"] = "Fail";
            }

        }

        /********************************
         * Question 12                  *
         * q12_upset_by_everyday_noises *
         ********************************/

        $q12_yes_count      = $this->countResponse(self::PAGE12_QUESTIONS, "yes", $record);
        $q12_pass_yes_count = $this->countResponse(self::PAGE12_PASS_EXAMPLES, "yes", $record);
        $q12_fail_yes_count = $this->countResponse(self::PAGE12_FAIL_EXAMPLES, "yes", $record);

        if ($record["q12_upset_by_everyday_noises"] == "no") {
            $scores["q12_pass_or_fail"] = "Pass";
        }

        if ($record["q12_upset_by_everyday_noises"] == "yes") {
            if ($q12_yes_count <= 1) {
                $scores["q12_pass_or_fail"] = "Pass";
            } else {
                // Yes to only PASS example(s)
                if ($q12_pass_yes_count > 0 && $q12_fail_yes_count == 0) {
                    $scores["q12_pass_or_fail"] = "Pass";
                }
                // Yes to both PASS and FAIL examples
                if ($q12_pass_yes_count > 0 && $q12_fail_yes_count > 0) {
                    if ($record["q12_yes_to_both_pass_and_fail"] == "pass") {
                        $scores["q12_pass_or_fail"] = "Pass";
                    } else {
                        $scores["q12_pass_or_fail"] = "Fail";
                    }
                }
                // Yes to only FAIL example(s)
                if ($q12_pass_yes_count == 0 && $q12_fail_yes_count > 0) {
                    $scores["q12_pass_or_fail"] = "Fail";
                }
            }
        }

        /***************
         * Question 13 *
         * q13_walk    *
         ***************/

        if ($record["q13_walk"] == "no") {
            $scores["q13_pass_or_fail"] = "Fail";
        }
        if ($record["q13_walk"] == "yes") {
            if ($record["q13_walk_without_holding_anything"] == "yes") {
                $scores["q13_pass_or_fail"] = "Pass";
            } else {
                $scores["q13_pass_or_fail"] = "Fail";
            }
        }

        /*******************
         * Question 14     *
         * q14_look_in_eye *
         *******************/

        $q14_yes_count = $this->countResponse(self::PAGE14_QUESTIONS, "yes", $record);
        $q14_no_count  = $this->countResponse(self::PAGE14_QUESTIONS, "no", $record);

        if ($q14_yes_count == 0) {
            if ($q14_no_count > 0) {
                $scores["q14_pass_or_fail"] = "Fail";
            }
        } elseif ($q14_yes_count == 1) {
            if ($record["q14_look_you_in_eye_every_day"] == "no") {
                $scores["q14_pass_or_fail"] = "Fail";
            } else {
                if ($record["q14_look_you_in_eye_5_times"] == "yes") {
                    $scores["q14_pass_or_fail"] = "Pass";
                } else {
                    $scores["q14_pass_or_fail"] = "Fail";
                }
            }
        } else {
            $scores["q14_pass_or_fail"] = "Pass";
        }

        /****************
         * Question 15  *
         * q15_copy_you *
         ****************/

        $q15_yes_count = $this->countResponse(self::PAGE15_QUESTIONS, "yes", $record);
        $q15_no_count  = $this->countResponse(self::PAGE15_QUESTIONS, "no", $record);

        if ($q15_yes_count >= 2) {
            $scores["q15_pass_or_fail"] = "Pass";
        } else {
            if ($q15_no_count > 0) {
                $scores["q15_pass_or_fail"] = "Fail";
            }
        }

        /*******************
         * Question 16     *
         * q16_look_around *
         *******************/

        $q16_pass_yes_count = $this->countResponse(self::PAGE16_PASS_EXAMPLES, "yes", $record);
        $q16_fail_yes_count = $this->countResponse(self::PAGE16_FAIL_EXAMPLES, "yes", $record);

        if ($record["q16_look_around"] == "yes") {
            $scores["q16_pass_or_fail"] = "Pass";
        }

        if ($record["q16_look_around"] == "no") {
             // Yes to only PASS example(s)
            if ($q16_pass_yes_count > 0 && $q16_fail_yes_count == 0) {
                $scores["q16_pass_or_fail"] = "Pass";
            }
            // Yes to both PASS and FAIL examples
            if ($q16_pass_yes_count > 0 && $q16_fail_yes_count > 0) {
                if ($record["q16_yes_to_both_pass_and_fail"] == "pass") {
                    $scores["q16_pass_or_fail"] = "Pass";
                } else {
                    $scores["q16_pass_or_fail"] = "Fail";
                }
            }
            // Yes to only FAIL example(s)
            if ($q16_pass_yes_count == 0 && $q16_fail_yes_count > 0) {
                $scores["q16_pass_or_fail"] = "Fail";
            }
        }

        /*****************
         * Question 17   *
         * q17_try_watch *
         *****************/

        $q17_all_no    = $this->checkIfAll(self::PAGE17_QUESTIONS, "no", $record);
        $q17_yes_count = $this->countResponse(self::PAGE17_QUESTIONS, "yes", $record);

        if ($q17_all_no) {
            $scores["q17_pass_or_fail"] = "Fail";
        } else {
            if ($q17_yes_count > 0) {
                $scores["q17_pass_or_fail"] = "Pass";
            }
        }

        /*********************************
         * Question 18                   *
         * q18_understand_tell_something *
         *********************************/

        $q18_all_no    = $this->checkIfAll(self::PAGE18_QUESTIONS, "no", $record);
        $q18_yes_count = $this->countResponse(self::PAGE18_QUESTIONS, "yes", $record);

        if ($record["q18_understand_tell_something"] == "no") {
            if ($record["q18_follow_a_command"] == "no" && $record["q18_dinnertime_food_sit_at_table"] == "no") {
                $scores["q18_pass_or_fail"] = "Fail";
            }

            if ($record["q18_follow_a_command"] == "yes" || $record["q18_dinnertime_food_sit_at_table"] == "yes") {
                if ($q18_all_no) {
                    $scores["q18_pass_or_fail"] = "Fail";
                } else {
                    if ($q18_yes_count > 0) {
                        $scores["q18_pass_or_fail"] = "Pass";
                    } else {
                        $scores["q18_pass_or_fail"] = "Fail";
                    }
                }
            }
        }

        /********************
         * Question 19      *
         * q19_look_at_face *
         ********************/

        if ($record["q19_look_at_face"] == "yes") {
            $scores["q19_pass_or_fail"] = "Pass";
        }

        if ($record["q19_look_at_face"] == "no") {
            if ($record["q19_hears_noise_look_before_responding"] == "yes") {
                $scores["q19_pass_or_fail"] = "Pass";
            } else {
                if ($record["q19_look_at_you_when_someone_approaches"] == "yes") {
                    $scores["q19_pass_or_fail"] = "Pass";
                } else {
                    if ($record["q19_look_at_you_when_faced_unfamiliar_or_scary"] == "yes") {
                        $scores["q19_pass_or_fail"] = "Pass";
                    } else {
                        $scores["q19_pass_or_fail"] = "Fail";
                    }
                }
            }
        }

        /***************************
         * Question 20             *
         * q20_movement_activities *
         ***************************/

        $q20_yes_count = $this->countResponse(self::PAGE20_QUESTIONS, "yes", $record);

        if ($record["q20_movement_activities"] == "yes" && $record["q20_enjoy_being_bounced_or_swung"] == "yes") {
            $scores["q20_pass_or_fail"] = "Pass";
        }

        if ($record["q20_movement_activities"] == "no" || ($record["q20_movement_activities"] == "yes" && $record["q20_enjoy_being_bounced_or_swung"] == "no")) {
            if ($q20_yes_count > 0) {
                $scores["q20_pass_or_fail"] = "Pass";
            } else {
                $scores["q20_pass_or_fail"] = "Fail";
            }
        }

        $result = $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
    }

    CONST PAGE1_PASS_EXAMPLES = array(
                                 "q1_look_at_object",
                                 "q1_point_at_object",
                                 "q1_look_and_comment_on_object",
                                 "q1_look_if_you_point_and_say_look",
                                );

    CONST PAGE1_FAIL_EXAMPLES = array(
                                 "q1_ignores_you",
                                 "q1_look_around_room_randomly",
                                 "q1_look_at_your_finger",
                                );

    CONST PAGE3_QUESTIONS = array(
                             "q3_pretend_to_drink_from_toy_cup",
                             "q3_pretend_to_eat_from_toy_spoon_or_fork",
                             "q3_pretend_to_talk_on_phone",
                             "q3_pretened_to_feed_doll_or_stuffed_animal",
                             "q3_push_car_along_pretend_road",
                             "q3_pretend_to_be_robot_airplane_ballerina_or_other",
                             "q3_put_toy_pot_on_pretend_stove",
                             "q3_stir_imaginary_food",
                             "q3_put_action_figure_or_doll_into_car_or_truck",
                             "q3_pretend_to_vacuum_sweep_mow",
                             "q3_other",
                            );

    CONST PAGE4_QUESTIONS = array(
                             "q4_stairs",
                             "q4_chairs",
                             "q4_furniture",
                             "q4_playground_equipment",
                            );

    CONST PAGE5_PASS_EXAMPLES = array(
                                 "q5_look_at_hands",
                                 "q5_move_fingers_when_playing_peek_a_boo",
                                );

    CONST PAGE5_FAIL_EXAMPLES = array(
                                 "q5_ignores_you",
                                 "q5_look_around_room_randomly",
                                 "q5_look_at_your_finger",
                                 "q5_flap_hands_near_face",
                                 "q5_other",
                                );

    CONST PAGE6_QUESTIONS = array(
                             "q6_reach_for_object_with_whole_hand",
                             "q6_lead_you_to_object",
                             "q6_try_to_get_object_for_self",
                             "q6_ask_using_words_or_sounds",
                            );

    CONST PAGE7_QUESTIONS = array(
                             "q7_airplane_in_sky",
                             "q7_truck_on_road",
                             "q7_bug_on_ground",
                             "q7_animal_in_yard",
                            );

    CONST PAGE8_QUESTIONS = array(
                             "q8_play_with_another_child",
                             "q8_talk_to_another_child",
                             "q8_babble_or_make_vocal_noises",
                             "q8_watch_another_child",
                             "q8_smile_at_another_child",
                             "q8_act_shy_at_first_then_smile",
                             "q8_get_excited_about_another_child",
                            );

    CONST PAGE9_QUESTIONS = array(
                             "q9_picture_or_toy_to_show_you",
                             "q9_drawing_done",
                             "q9_flower_has_picked",
                             "q9_bug_found_in_grass",
                             "q9_few_blocks_put_together",
                             "q9_other",
                            );

    CONST PAGE10_PASS_EXAMPLES = array(
                                  "q10_look_up",
                                  "q10_talk_or_babble",
                                  "q10_stop_what_doing",
                                 );

    CONST PAGE10_FAIL_EXAMPLES = array(
                                  "q10_make_no_response",
                                  "q10_seem_to_hear_but_ignores_parent",
                                  "q10_respond_only_if_parent_is_in_front_of_face",
                                  "q10_respond_only_if_touched",
                                 );

    CONST PAGE11_PASS_EXAMPLES = array(
                                  "q11_smile_when_you_smile",
                                  "q11_smile_when_enter_room",
                                  "q11_smile_when_return_from_being_away",
                                 );

    CONST PAGE11_FAIL_EXAMPLES = array(
                                  "q11_always_smile",
                                  "q11_smile_at_favorite_toy_or_activity",
                                  "q11_smile_randomly_or_nothing",
                                 );

    CONST PAGE12_QUESTIONS = array(
                              "q12_washing_machine",
                              "q12_babies_crying",
                              "q12_vacuum_cleaner",
                              "q12_hairdryer",
                              "q12_traffic",
                              "q12_babies_squealing_or_screeching",
                              "q12_loud_music",
                              "q12_telephone_doorbell_ringing",
                              "q12_noisy_places",
                              "q12_other",
                             );

    CONST PAGE12_PASS_EXAMPLES = array(
                                  "q12_calmly_cover_ears",
                                  "q12_does_not_like_noise",
                                 );

    CONST PAGE12_FAIL_EXAMPLES = array(
                                  "q12_scream",
                                  "q12_cry",
                                  "q12_cover_ears_while_upset",
                                 );

    CONST PAGE14_QUESTIONS = array(
                              "q14_needs_something",
                              "q14_playing_with",
                              "q14_during_feeding",
                              "q14_during_diaper_changes",
                              "q14_when_reading_a_story",
                              "q14_when_talking",
                             );

    CONST PAGE15_QUESTIONS = array(
                              "q15_stick_out_tongue",
                              "q15_make_funny_sound",
                              "q15_wave_good_bye",
                              "q15_clap_hands",
                              "q15_put_fingers_to_lips_signal_shhh",
                              "q15_blow_kiss",
                              "q15_other",
                             );

    CONST PAGE16_PASS_EXAMPLES = array(
                                  "q16_look_toward_thing_looking_at",
                                  "q16_point_toward_thing_looking_at",
                                  "q16_look_around_see_what_looking_at",
                                 );

    CONST PAGE16_FAIL_EXAMPLES = array(
                                  "q16_ignore_you",
                                  "q16_look_at_your_face",
                                 );

    CONST PAGE17_QUESTIONS = array(
                              "q17_say_look_or_watch_me",
                              "q17_babble_or_make_noise",
                              "q17_look_to_get_praise_or_comment",
                              "q17_keep_looking_to_see_if_looking",
                              "q17_other",
                             );

    CONST PAGE18_QUESTIONS = array(
                              "q18_1_show_me_your_shoe",
                              "q18_2_bring_me_the_blanket",
                              "q18_3_put_the_book_on_the_chair",
                             );

    CONST PAGE20_QUESTIONS = array(
                              "q20_laugh_or_smile",
                              "q20_talk_or_babble",
                              "q20_request_more_by_holding_out_arm",
                              "q20_other",
                             );
}

/**
 * Return the HTML for the review section of the survey module
 * By default, this will show every question from the parameter_type
 * table for this instrument, but it can be overridden/customized by
 * a instrument if that isn't the desired behaviour.
 *
 * @return string The HTML to be inserted into the review section of
 *                the final page of the survey module for this instrument.
 */
function getReview()
{
    $DB = Database::singleton();

    $smarty   = new Smarty_neurodb();
    $tpl_data = array();

    $tpl_data['questions'] = $DB->pselect(
        "SELECT Description as question,
            SourceField FROM parameter_type
            WHERE SourceFrom=:TN AND
            SourceField NOT IN ('Validity', 'Administration')",
        array('TN' => $this->testName)
    );

    $Responses = $DB->pselectRow(
        "SELECT * FROM " . $this->testName . " WHERE CommentID=:CID",
        array('CID' => $this->getCommentID())
    );

    foreach ($tpl_data['questions'] as &$row) {
        if (isset($Responses[$row['SourceField']])) {
            $row['response'] = $Responses[$row['SourceField']];
        }
    }

    $smarty->assign($tpl_data);
    $html = $smarty->fetch("directentry_review.tpl");
    return $html;
}
