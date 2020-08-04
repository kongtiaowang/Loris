<?php
/**
 * This file contains the NDB_BVL_Instrument_RBS_EC_G_V12_V24_Survey class
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
 * Creates the form elements for the RBS_EC_G_V12_V24_Survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_RBS_EC_G_V12_V24_Survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    const OPTIONS_1 = array(
                       "0_behavior_does_not_occur"              => "0 - Behavior does not occur",
                       "1_behavior_occurs_weekly_or_less"       => "1 - Behavior occurs about weekly or less",
                       "2_behavior_occurs_several_times_a_week" => "2 - Behavior occurs several times a week",
                       "3_behavior_occurs_about_daily"          => "3 - Behavior occurs about daily",
                       "4_behavior_occurs_many_times_a_day"     => "4 - Behavior occurs many times a day",
                       "not_answered"                           => "Not Answered",
                      );

    const OPTIONS_2 = array(
                       "0_never"      => "Never",
                       "1_rarely"     => "Rarely",
                       "2_sometimes"  => "Sometimes",
                       "3_often"      => "Often",
                       "4_always"     => "Always",
                       "not_answered" => "Not Answered",
                      );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('RBS_EC_G_V12_V24_Survey', "RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('RBS_EC_G_V12_V24_Survey','RBS_EC_G_V12_V24_Survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('RBS_EC_G_V12_V24_Survey','RBS_EC_G_V12_V24_Survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('RBS_EC_G_V12_V24_Survey','RBS_EC_G_V12_V24_Survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('RBS_EC_G_V12_V24_Survey','RBS_EC_G_V12_V24_Survey_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('RBS_EC_G_V12_V24_Survey','RBS_EC_G_V12_V24_Survey_page5', "Page 5", 5);
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
        $this->form     = new LorisForm('RBS_EC_G_V12_V24_Survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "RBS_EC_G_V12_V24_Survey";           // test_names.Test_name
        $this->table    = 'RBS_EC_G_V12_V24_Survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "q1_legs",
                                    "q25_arranging",
                                    "q17_limited_intense_interests",
                                    "q10_hits_self_with_body_part",
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
        if (preg_match("/RBS_EC_G_V12_V24_Survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b><br>
                <br>
                Please rate your child’s behavior for each of the 34 items listed by selecting the score that best describes how <u>often</u> the behavior occurs.
                Be sure to read and score all items. Make your ratings based on your child’s behavior over the past month. Use the definitions given below to score each item:<br>
                <br>
                $this->indent 0 = Behavior <u>does not occur</u><br>
                $this->indent 1 = Behavior occurs about weekly or less<br>
                $this->indent 2 = Behavior occurs several times a week<br>
                $this->indent 3 = Behavior occurs about daily<br>
                $this->indent 4 = Behavior occurs many times a day<br>
                <br>
                If an item is \"not applicable\" because your child cannot yet perform a particular behavior (for instance, he or she is not yet grasping objects),
                the item should be scored as \"0\" (behavior does not occur).
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

        $this->addBasicDate('child_birthdate', "Child's Date of Birth");

        $this->addBasicText("child_age", "Child's Age <br><h5><i>(Please enter a numeric value between 0-100.)</i></h5>");

        $gender_options = array(
                           null     => "",
                           "male"   => "Male",
                           "female" => "Female",
                          );

        $this->addSelect("child_gender", "Child's Sex", $gender_options);

        $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                Read each of the items listed and select the score that best describes how <u>often</u> the behavior occurs.
                Be sure to read and score all items. Make your ratings based on your child’s behavior over the past <u>month</u>.
                <br><br>
                $this->indent 0 = Behavior <u>does not occur</u><br>
                $this->indent 1 = Behavior occurs about weekly or less<br>
                $this->indent 2 = Behavior occurs several times a week<br>
                $this->indent 3 = Behavior occurs about daily<br>
                $this->indent 4 = Behavior occurs many times a day
            </h3>"
        );

        $this->form->addElement(
            'static',
            null,
            "<h3><b><u>I. Repetitive Motor</u></b></h3>
            <b>DEFINITION: consecutive, non-social movements or actions that are repeated in a similar manner</b>"
        );

        $page1_questions = array(
                            "q1_legs"               => "1. LEGS <h4>(kicking, flexing, bouncing, swinging, foot tapping)</h4>",
                            "q2_head"               => "2. HEAD <h4>(head rolling, nodding, shaking - <i>do not count nodding or shaking to communicate 'yes' or 'no'</i>)</h4>",
                            "q3_whole_body_torso"   => "3. WHOLE BODY/TORSO <h4>(rocking, bouncing, swaying, arching)",
                            "q4_arms_hands_fingers" => "4. ARMS/HANDS/FINGERS <h4>(flaps or flutters hands or arms in air; wiggles or flicks fingers; shakes or claps - <i>do not count social clapping or waving 'hello' or 'goodbye'</i>)</h4>",
                            "q5_arms_hands_fingers" => "5. ARMS/HANDS/FINGERS ON SURFACES <h4>(slaps, taps, or drums against objects, walls, floors, tables, or other furniture)</h4>",
                            "q6_object_usage"       => "6. OBJECT USAGE <h4>(bangs, spins, twirls, shakes, drops or rolls toys or other objects)</h4>",
                            "q7_mouthing_objects"   => "7. MOUTHING OBJECTS <h4>(mouths, bites, licks, or sucks objects - <i>do not count bottles, pacifiers, cups or utensils</i>)</h4>",
                            "q8_locomotion"         => "8. LOCOMOTION <h4>(repeatedly spins, scoots, crawls, walks, hops or runs in circles or back & forth)</h4>",
                            "q9_vocalizations"      => "9. VOCALIZATIONS <h4>(repeats same sound, word or phrase - <i>do not count attempts at communication</i>)</h4>",
                           );

        foreach ($page1_questions as $key => $question) {
            $this->addSelect($key, $question, self::OPTIONS_1);
        }

        $this->addSelect("i_repetitive_motor_how_often_do_the_behaviors_interfere", "<b>In total</b>, how often do the above behaviors <u>interfere with other activities or interactions</u>? Select the best answer.", self::OPTIONS_2);
    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                Read each of the items listed and select the score that best describes how <u>often</u> the behavior occurs.
                Be sure to read and score all items. Make your ratings based on your child’s behavior over the past <u>month</u>.
                <br><br>
                $this->indent 0 = Behavior <u>does not occur</u><br>
                $this->indent 1 = Behavior occurs about weekly or less<br>
                $this->indent 2 = Behavior occurs several times a week<br>
                $this->indent 3 = Behavior occurs about daily<br>
                $this->indent 4 = Behavior occurs many times a day
            </h3>"
        );

        $this->form->addElement(
            'static',
            null,
            "<h3><b><u>II. Ritual & Routine</u></b></h3>
            <b>DEFINITION: resistant to change; engages in fixed patterns of behavior; strongly prefers that daily activities are performed in the same way</b>"
        );

        $page2_questions = array(
                            "q25_arranging"                 => "25. ARRANGING <h4>(lines up or arranges toys or other objects)</h4>",
                            "q26_placement_of_objects"      => "26. PLACEMENT OF OBJECTS <h4>(insists that things remain in the same place, e.g. toys, furniture; returns items to \"correct\" location when disturbed by others)</h4>",
                            "q27_upset_visiting_new_places" => "27. UPSET VISITING NEW PLACES <h4>(cries or \"melts down\" when visiting an unfamiliar place; refuses to enter new settings)</h4>",
                            "q28_upset_if_interrupted"      => "28. UPSET IF INTERRUPTED <h4>(cries or \"melts down\" when an activity is interrupted; difficulty with transitions even with advance warning)</h4>",
                            "q29_appearance_of_others"      => "29. APPEARANCE OF OTHERS <h4>(dislikes or upset by change in appearance of others, e.g. hairstyle, hats, clothes)</h4>",
                            "q30_inflexible_routine"        => "30. INFLEXIBLE ROUTINE <h4>(overly upset by changes to daily routine, e.g. schedule, people involved, or order of activities; insists that events occur in a specific order)</h4>",
                            "q31_eating_mealtime"           => "31. EATING/MEALTIME <h4>(insists on set meal routine, e.g. eats only specific foods or brands, eats/drinks in a set order or at a specific place/time; refuses food items that are “touching”)</h4>",
                            "q32_sleeping_bedtime"          => "32. SLEEPING/BEDTIME <h4>(refuses to sleep in new places; insists that room or bed is \"just so\" at bedtime; insists that specific activities precede bedtime)</h4>",
                            "q33_play"                      => "33. PLAY <h4>(follows a strict play routine; insists that others play in a specific way; upset if play routine is altered)</h4>",
                            "q34_social_interaction"        => "34. SOCIAL INTERACTION <h4>(insists that others respond in a specific way; follows a set verbal script or routine regardless of context or social behavior of other children or adults)</h4>",
                           );

        foreach ($page2_questions as $key => $question) {
            $this->addSelect($key, $question, self::OPTIONS_1);
        }

        $this->addSelect("ii_ritual_and_routine_how_often_do_the_behaviors_interfere", "<b>In total</b>, how often do the above behaviors <u>interfere with other activities or interactions</u>? Select the best answer.", self::OPTIONS_2);
    }

    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->addHeader("RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                Read each of the items listed and select the score that best describes how <u>often</u> the behavior occurs.
                Be sure to read and score all items. Make your ratings based on your child’s behavior over the past <u>month</u>.
                <br><br>
                $this->indent 0 = Behavior <u>does not occur</u><br>
                $this->indent 1 = Behavior occurs about weekly or less<br>
                $this->indent 2 = Behavior occurs several times a week<br>
                $this->indent 3 = Behavior occurs about daily<br>
                $this->indent 4 = Behavior occurs many times a day
            </h3>"
        );

        $this->form->addElement(
            'static',
            null,
            "<h3><b><u>III. Restricted Interests & Behavior</u></b></h3>
            <b>DEFINITION: behaviors with a limited or inflexible range of focus; intense or unusual interests or activities</b>"
        );

        $page3_questions = array(
                            "q17_limited_intense_interests"            => "17. LIMITED & INTENSE INTERESTS <h4>(narrow preoccupation with one subject or activity, e.g., trains, dinosaurs, collecting items, e.g. rocks, sticks, strings; plays only with specific toys)</h4>",
                            "q18_restricted_use_of_media"              => "18. RESTRICTED USE OF MEDIA <h4>(strongly insists on same music, book, app, program, movie or part of program/movie etc.; firmly refuses new books/apps/movies etc.)</h4>",
                            "q19_sensory_interests"                    => "19. SENSORY INTERESTS <h4>(seeks specific tactile, auditory, or visual sensations, e.g. smells or rubs specific objects; intense fascination with specific sounds, lights, or textures)</h4>",
                            "q20_strongly_attached_to_specific_object" => "20. STRONGLY ATTACHED TO SPECIFIC OBJECT <h4>(insists on bringing/carrying one specific toy or other object)</h4>",
                            "q21_preoccupation_with_parts_of_objects"  => "21. PREOCCUPATION W/ PARTS OF OBJECTS <h4>(focuses on parts of objects rather than the whole object, e.g. wheels on toy cars, eyes on dolls or stuffed animals)</h4>",
                            "q22_stillness"                            => "22. STILLNESS <h4>(lays or sits still for extended periods of time while alone; content to do “nothing” – <i>do not count naps/bedtime)</i></h4>",
                            "q23_visual_inspection"                    => "23. VISUAL INSPECTION <h4>(closely inspects objects; views toys and other objects from an unusual angle)</h4>",
                            "q24_fascination_with_movement"            => "24. FASCINATION WITH MOVEMENT <h4>(intense interest or focus on things that move; e.g. fans, toys that spin, bounce, roll, flutter, etc.)</h4>",
                           );

        foreach ($page3_questions as $key => $question) {
            $this->addSelect($key, $question, self::OPTIONS_1);
        }

        $this->addSelect("iii_restricted_interests_how_often_do_the_behaviors_interfere", "<b>In total</b>, how often do the above behaviors <u>interfere with other activities or interactions</u>? Select the best answer.", self::OPTIONS_2);
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $this->addHeader("RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
                <b>Instructions:</b>
                <br><br>
                Read each of the items listed and select the score that best describes how <u>often</u> the behavior occurs.
                Be sure to read and score all items. Make your ratings based on your child’s behavior over the past <u>month</u>.
                <br><br>
                $this->indent 0 = Behavior <u>does not occur</u><br>
                $this->indent 1 = Behavior occurs about weekly or less<br>
                $this->indent 2 = Behavior occurs several times a week<br>
                $this->indent 3 = Behavior occurs about daily<br>
                $this->indent 4 = Behavior occurs many times a day
            </h3>"
        );

        $this->form->addElement(
            'static',
            null,
            "<h3><b><u>IV. Self-Directed Behavior</u></b></h3>
            <b>DEFINITION: repeated movements or actions directed toward the body that have the <u>potential</u> to cause redness, bruising, or other injury.</b>"
        );

        $page4_questions = array(
                            "q10_hits_self_with_body_part"          => "10. HITS SELF WITH BODY PART <h4>(hits or slaps head, arms, legs or other body part)</h4>",
                            "q11_hits_self_with_object"             => "11. HITS SELF WITH OBJECT <h4>(hits or bangs head or other body area with objects, e.g. toys)</h4>",
                            "q12_hits_self_against_surface"         => "12. HITS SELF AGAINST SURFACE <h4>(hits or bangs head or other body part on furniture, walls, floors, or other surfaces)</h4>",
                            "q13_bites_self"                        => "13. BITES SELF <h4>(bites hand, fingers, arm, lips or tongue)</h4>",
                            "q14_rubs_scratches_pokes_pinches_self" => "14. RUBS, SCRATCHES, POKES OR PINCHES SELF <h4>(<i>do not count itching of bug bites, eczema or other skin irritation</i>)</h4>",
                            "q15_pulls_own_hair"                    => "15. PULLS OWN HAIR",
                            "q16_skin_picking"                      => "16. SKIN PICKING <h4>(picks at marks, scabs, cuticles, or healthy skin on face, hands, arms or torso)</h4>",
                           );

        foreach ($page4_questions as $key => $question) {
            $this->addSelect($key, $question, self::OPTIONS_1);
        }

        $this->addSelect("iv_self_directed_how_often_do_the_behaviors_interfere", "<b>In total</b>, how often do the above behaviors <u>interfere with other activities or interactions</u>? Select the best answer.", self::OPTIONS_2);
    }

    /**
     * Page 5
     *
     * @return void
     */
    function _page5()
    {
        $this->addHeader("RBS - EC - G (Repetitive Behavior Scale for Early Childhood - General Version) - Survey");

        $this->addBasicText("comments", "Comments (optional):");

        $this->XINRegisterRule(
            "comments",
            array("comments{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
    }

    function validate_main_page($values)
    {
         $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

        $this->validate_child_age($values, "child_age", $errors);

        return $errors;
    }
}
?>