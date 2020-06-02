<?php
/**
 * This file contains the NDB_BVL_Instrument_ECBQ_survey class
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
 * Creates the form elements for the ECBQ_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_ECBQ_survey extends NDB_BVL_Instrument
{
    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('ECBQ_survey', "ECBQ (Early Childhood Behavior Questionnaire) - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page5', "Page 5", 5);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page6', "Page 6", 6);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page7', "Page 7", 7);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ECBQ_survey','ECBQ_survey_page8', "Page 8", 8);
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
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('ECBQ_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "ECBQ_survey";           // test_names.Test_name
        $this->table    = 'ECBQ_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array();

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
        if (preg_match("/ECBQ_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $this->addHeader(
            "<h3><b>Instructions:</b><br><br>
            <i>Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism.</i><br><br>
            Please read carefully before starting.
            As you read each description of the child's behavior below, please indicate <u>how often</u> the child did this during the <u>last two weeks</u>.
            These numbers indicate how often you observed the behavior described during the <u>last two weeks</u>.<br><br>
            $this->indent 1 = Never<br>
            $this->indent 2 = Very rarely<br>
            $this->indent 3 = Less than half the time<br>
            $this->indent 4 = About half the time<br>
            $this->indent 5 = More than half the time<br>
            $this->indent 6 = Almost always<br>
            $this->indent 7 = Always<br>
            $this->indent Does not apply - NA<br><br>
            The \"Does Not Apply\" column (NA) is used when you did not see the child in the <u>situation</u> described during the last two weeks.
            For example, if the situation mentions the child going to the doctor and there was no time during the last two weeks when the child went to the doctor, select the (NA) option.
            \"Does Not Apply\" (NA) is different from \"NEVER\" (1).
            \"Never\" is used when you saw the child in the situation but the child never engaged in the behavior mentioned in the last two weeks.
            Please be sure to select an option for <u>every</u> item.
            </h3><br>"
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
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $this->addHeader(
            "<h3><b>Instructions:</b><br><br>
            <i>Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism.</i><br><br>
            Please read carefully before starting.
            As you read each description of the child's behavior below, please indicate <u>how often</u> the child did this during the <u>last two weeks</u>.
            These numbers indicate how often you observed the behavior described during the <u>last two weeks</u>.<br><br>
            $this->indent 1 = Never<br>
            $this->indent 2 = Very rarely<br>
            $this->indent 3 = Less than half the time<br>
            $this->indent 4 = About half the time<br>
            $this->indent 5 = More than half the time<br>
            $this->indent 6 = Almost always<br>
            $this->indent 7 = Always<br>
            $this->indent Does not apply - NA<br><br>
            The \"Does Not Apply\" column (NA) is used when you did not see the child in the <u>situation</u> described during the last two weeks.
            For example, if the situation mentions the child going to the doctor and there was no time during the last two weeks when the child went to the doctor, select the (NA) option.
            \"Does Not Apply\" (NA) is different from \"NEVER\" (1).
            \"Never\" is used when you saw the child in the situation but the child never engaged in the behavior mentioned in the last two weeks.
            Please be sure to select an option for <u>every</u> item.
            </h3><br>"
        );

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page1_questions = array(
                            // When told that it was time for bed or a nap, how often did your child
                            "q1_react_with_anger"                            => "1. React with anger?",
                            "q2_get_irritable"                               => "2. Get irritable?",
                            // When approached by an unfamiliar person in a public place (for example, the grocery store), how often did your child
                            "q3_remain_calm"                                 => "3. Remain calm?",
                            "q4_pull_back_and_avoid_the_person"              => "4. Pull back and avoid the person?",
                            "q5_cling_to_a_parent"                           => "5. Cling to a parent?",
                            // During everyday activities, how often did your child
                            "q6_startle_at_loud_noises"                      => "6. Startle at loud noises (such as a fire engine siren)?",
                            "q7_tap_or_drum_fingers_on_table"                => "7. Tap or drum with fingers on tables or other objects?",
                            "q8_get_irritated_by_scratchy_sounds"            => "8. Get irritated by scratchy sounds?",
                            "q9_become_uncomfortable_when_socks_not_aligned" => "9. Become uncomfortable when his/her socks were not aligned properly on his/her feet?",
                            // After getting a bump or scrape, how often did your child
                            "q10_forget_in_a_few_minutes"                    => "10. Forget about it in a few minutes?",
                            // While playing outdoors, how often did your child
                            "q11_like_making_lots_of_noise"                  => "11. Like making lots of noise?",
                            "q12_enjoy_sitting_quietly_in_sunshine"          => "12. Enjoy sitting quietly in the sunshine?",
                            "q13_want_to_climb_to_high_places"               => "13. Want to climb to high places (for example, up a tree or on the jungle gym?)",
                           );

        $page1_question_headers = array(
                                   "q1_react_with_anger"           => "When told that it was time for bed or a nap, how often did your child",
                                   "q3_remain_calm"                => "When approached by an unfamiliar person in a public place (for example, the grocery store), how often did your child",
                                   "q6_startle_at_loud_noises"     => "During everyday activities, how often did your child",
                                   "q10_forget_in_a_few_minutes"   => "After getting a bump or scrape, how often did your child",
                                   "q11_like_making_lots_of_noise" => "While playing outdoors, how often did your child",
                                  );

        foreach ($page1_questions as $key => $question) {
            if (array_key_exists($key, $page1_question_headers)) {
                $this->addHeader("<h4><b>" . $page1_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page2_questions = array(
                            // When s/he was carried, how often did your child
                            "q14_like_to_be_held"                               => "14. Like to be held?",
                            "q15_push_against_you_until_put_down"               => "15. Push against you until put down?",
                            "q16_squirm"                                        => "16. Squirm?",
                            "q17_struggle_to_get_away"                          => "17. Struggle to get away?",
                            "q18_snuggle_up_next_to_you"                        => "18. Snuggle up next to you?",
                            // While having trouble completing a task (e.g., building, drawing, dressing), how often did your child
                            "q19_get_easily_irritated"                          => "19. Get easily irritated?",
                            "q20_become_sad"                                    => "20. Become sad?",
                            // When a familiar child came to your home, how often did your child
                            "q21_engage_in_an_activity_with_child"              => "21. Engage in an activity with the child?",
                            "q22_seek_out_company_of_child"                     => "22. Seek out the company of the child?",
                            // When offered a choice of activities, how often did your child
                            "q23_stop_and_think_before_deciding"                => "23. Stop and think before deciding?",
                            "q24_decide_what_to_do_quickly_and_go_after_it"     => "24. Decide what to do very quickly and go after it?",
                            "q25_seem_slow_and_unhurried_about_what_to_do_next" => "25. Seem slow and unhurried about what to do next?",
                            // When asked NOT to, how often did your child
                            "q26_run_around_your_house_or_apartment_anyway"     => "26. Run around your house or apartment anyway?",
                            "q27_touch_an_attractive_item"                      => "27. Touch an attractive item (such as an ornament) anyway?",
                            "q28_play_with_something_anyway"                    => "28. Play with something anyway?",
                            // During daily or evening quiet time with you and your child, how often did your child
                            "q29_enjoy_just_being_quietly_sung_to"              => "29. Enjoy just being quietly sung to?",
                            "q30_smile_at_sound_of_words"                       => "30. Smile at the sound of words, as in nursery rhymes?",
                            "q31_enjoy_just_being_talked_to"                    => "31. Enjoy just being talked to?",
                            "q32_enjoy_rhythmic_activities"                     => "32. Enjoy rhythmic activities, such as rocking or swaying?",
                            // During everyday activities, how often did your child
                            "q33_become_distressed_when_hands_dirty_sticky"     => "33. Become distressed when his/her hands were dirty and/or sticky?",
                            "q34_notice_that_material_was_soft_or_rough"        => "34. Notice that material was very soft (cotton) or rough (wool)?",
                            "q35_notice_low_pitched_noises"                     => "35. Notice low-pitched noises such as the air-conditioner, heater, or refrigerator running or starting up?",
                            "q36_blink_a_lot"                                   => "36. Blink a lot?",
                            "q37_get_very_enthusiastic_about_things"            => "37. Get very enthusiastic about the things s/he was going to do?",
                            // While at home, how often did your child
                            "q38_show_fear_at_a_loud_sound"                     => "38. Show fear at a loud sound (blender, vacuum cleaner, etc.)?",
                            "q39_seem_afraid_of_the_dark"                       => "39. Seem afraid of the dark?",
                            // When visiting the home of a familiar adult, such as a relative or friend, how often did your child
                            "q40_want_to_interact_with_adult"                   => "40. Want to interact with the adult?",
                            // While bathing, how often did your child
                            "q41_sit_quietly"                                   => "41. Sit quietly?",
                            "q42_splash_kick_try_to_jump"                       => "42. Splash, kick, or try to jump?",
                           );

        $page2_question_headers = array(
                                   "q14_like_to_be_held"                           => "When s/he was carried, how often did your child",
                                   "q19_get_easily_irritated"                      => "While having trouble completing a task (e.g., building, drawing, dressing), how often did your child",
                                   "q21_engage_in_an_activity_with_child"          => "When a familiar child came to your home, how often did your child",
                                   "q23_stop_and_think_before_deciding"            => "When offered a choice of activities, how often did your child",
                                   "q26_run_around_your_house_or_apartment_anyway" => "When asked NOT to, how often did your child",
                                   "q29_enjoy_just_being_quietly_sung_to"          => "During daily or evening quiet time with you and your child, how often did your child",
                                   "q33_become_distressed_when_hands_dirty_sticky" => "During everyday activities, how often did your child",
                                   "q38_show_fear_at_a_loud_sound"                 => "While at home, how often did your child",
                                   "q40_want_to_interact_with_adult"               => "When visiting the home of a familiar adult, such as a relative or friend, how often did your child",
                                   "q41_sit_quietly"                               => "While bathing, how often did your child",
                                  );

        foreach ($page2_questions as $key => $question) {
            if (array_key_exists($key, $page2_question_headers)) {
                $this->addHeader("<h4><b>" . $page2_question_headers[$key] . "</b></h4>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page3_questions = array(
                            // While playing outdoors, how often did your child
                            "q43_look_immediately_when_you_pointed"              => "43. Look immediately when you pointed at something?",
                            "q44_choose_to_take_chances_for_fun_and_excitement"  => "44. Choose to take chances for the fun and excitement of it?",
                            "q45_not_like_going_down_high_slides"                => "45. <u>Not</u> like going down high slides at the amusement park or playground?",
                            // When s/he was upset, how often did your child
                            "q46_change_to_feeling_better_within_minutes"        => "46. Change to feeling better within a few minutes?",
                            "q47_soothe_only_with_difficulty"                    => "47. Soothe only with difficulty?",
                            "q48_stay_upset_for_10_minutes_or_longer"            => "48. Stay upset for 10 minutes or longer?",
                            // When engaged in play with his/her favorite toy, how often did your child
                            "q49_play_for_5_minutes_or_less"                     => "49. Play for 5 minutes or less?",
                            "q50_play_for_more_than_10_minutes"                  => "50. Play for more than 10 minutes?",
                            "q51_continue_to_play_while_responding"              => "51. Continue to play <u>while at the same time</u> responding to your remarks or questions?",
                            // When approaching unfamiliar children playing, how often did your child
                            "q52_watch_rather_than_join"                         => "52. Watch rather than join?",
                            "q53_approach_slowly"                                => "53. Approach slowly?",
                            "q54_seem_uncomfortable"                             => "54. Seem uncomfortable?",
                            // During everyday activities, how often did your child
                            "q55_complain_about_odors_on_others"                 => "55. Complain about odors on others, such as perfume?",
                            "q56_seem_to_be_bothered_by_bright_light"            => "56. Seem to be bothered by bright light?",
                            "q57_move_quickly_from_one_place_to_another"         => "57. Move quickly from one place to another?",
                            "q58_notice_smoothness_or_roughness_of_objects"      => "58. Notice the smoothness or roughness of objects s/he touched?",
                            "q59_become_sad_or_blue_for_no_reason"               => "59. Become sad or blue for no apparent reason?",
                            // After having been interrupted, how often did your child
                            "q60_return_to_previous_activity"                    => "60. Return to a previous activity?",
                            "q61_have_difficulty_returning_to_previous_activity" => "61. Have difficulty returning to the previous activity?",
                            // While watching TV or hearing a story, how often did your child
                            "q62_seem_frightened_by_monster_characters"          => "62. Seem frightened by ‘monster’ characters?",
                            // When you suggested an outdoor activity that s/he really likes, how often did your child
                            "q63_respond_immediately"                            => "63. Respond immediately?",
                            "q64_run_to_door_before_getting_ready"               => "64. Run to the door before getting ready?",
                            // When told that loved adults would visit, how often did your child
                            "q65_get_very_excited"                               => "65. Get very excited?",
                            "q66_become_very_happy"                              => "66. Become very happy?",
                            // When taking a quiet, warm bath, how often did your child
                            "q67_seem_to_relax_and_enjoy"                        => "67. Seem to relax and enjoy him/herself?",
                            // When s/he couldn’t find something to play with, how often did your child
                            "q68_get_angry"                                      => "68. Get angry?",
                           );

        $page3_question_headers = array(
                                   "q43_look_immediately_when_you_pointed"       => "While playing outdoors, how often did your child",
                                   "q46_change_to_feeling_better_within_minutes" => "When s/he was upset, how often did your child",
                                   "q49_play_for_5_minutes_or_less"              => "When engaged in play with his/her favorite toy, how often did your child",
                                   "q52_watch_rather_than_join"                  => "When approaching unfamiliar children playing, how often did your child",
                                   "q55_complain_about_odors_on_others"          => "During everyday activities, how often did your child",
                                   "q60_return_to_previous_activity"             => "After having been interrupted, how often did your child",
                                   "q62_seem_frightened_by_monster_characters"   => "While watching TV or hearing a story, how often did your child",
                                   "q63_respond_immediately"                     => "When you suggested an outdoor activity that s/he really likes, how often did your child",
                                   "q65_get_very_excited"                        => "When told that loved adults would visit, how often did your child",
                                   "q67_seem_to_relax_and_enjoy"                 => "When taking a quiet, warm bath, how often did your child",
                                   "q68_get_angry"                               => "When s/he couldn’t find something to play with, how often did your child",
                                  );

        foreach ($page3_questions as $key => $question) {
            if (array_key_exists($key, $page3_question_headers)) {
                $this->addHeader("<h4><b>" . $page3_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page4_questions = array(
                            // During sleep, how often did your child
                            "q69_toss_about_in_bed"                           => "69. Toss about in the bed?",
                            "q70_sleep_in_one_position_only"                  => "70. Sleep in one position only?",
                            // During quiet activities, such as reading a story, how often did your child
                            "q71_swing_or_tap_foot"                           => "71. Swing or tap his/her foot?",
                            "q72_fiddle_with_hair_clothing_etc"               => "72. Fiddle with his/her hair, clothing, etc.?",
                            "q73_show_repeated_movements"                     => "73. Show repeated movements like squinting, hunching up the shoulders, or twitching the facial muscles?",
                            // While playing indoors, how often did your child
                            "q74_like_rough_and_rowdy_games"                  => "74. Like rough and rowdy games?",
                            "q75_enjoy_playing_boisterous_games"              => "75. Enjoy playing boisterous games like ‘chase’?",
                            "q76_enjoy_vigorously_jumping_on_couch_or_bed"    => "76. Enjoy vigorously jumping on the couch or bed?",
                            // In situations where she is meeting new people, how often did your child
                            "q77_turn_away"                                   => "77. Turn away?",
                            "q78_become_quiet"                                => "78. Become quiet?",
                            "q79_seem_comfortable"                            => "79. Seem comfortable?",
                            // When being gently rocked or hugged, how often did your child
                            "q80_seem_eager_to_get_away"                      => "80. Seem eager to get away?",
                            "q81_make_protesting_noises"                      => "81. Make protesting noises?",
                            // When encountering a new activity, how often did your child
                            "q82_sit_on_sidelines_and_observe_before_joining" => "82. Sit on the sidelines and observe before joining in?",
                            "q83_get_involved_immediately"                    => "83. Get involved immediately?",
                            // When visiting the home of a familiar child, how often did your child
                            "q84_engage_in_activity_with_child"               => "84. Engage in an activity with the child?",
                            "q85_seek_out_company_of_child"                   => "85. Seek out the company of the child?",
                            // When another child took away his/her favorite toy, how often did your child
                            "q86_scream_with_anger"                           => "86. Scream with anger?",
                            "q87_not_become_angry"                            => "87. <u>Not</u> become angry?",
                            "q88_sadly_cry"                                   => "88. Sadly cry?",
                            "q89_not_react_with_sadness"                      => "89. <u>Not</u> react with sadness?",
                            // When engaged in an activity requiring attention, such as building with blocks, how often did your child
                            "q90_move_quickly_to_another_activity"            => "90. Move quickly to another activity?",
                            "q91_stay_involved_for_10_minutes_or_more"        => "91. Stay involved for 10 minutes or more?",
                            "q92_tire_of_the_activity_quickly"                => "92. Tire of the activity relatively quickly?",
                            // During everyday activities, how often did your child
                            "q93_pay_attention_to_you_right_away_when_called" => "93. Pay attention to you right away when you called to him/her?",
                            "q94_seem_to_be_disturbed_by_loud_sounds"         => "94. Seem to be disturbed by loud sounds?",
                            "q95_stop_going_after_forbidden_object"           => "95. Stop going after a forbidden object (such as a VCR) when you used a toy to distract her/him?",
                            "q96_notice_small_things_on_clothes"              => "96. Notice small things, such as dirty or a stain, on his/her clothes?",
                           );

        $page4_question_headers = array(
                                   "q69_toss_about_in_bed"                           => "During sleep, how often did your child",
                                   "q71_swing_or_tap_foot"                           => "During quiet activities, such as reading a story, how often did your child",
                                   "q74_like_rough_and_rowdy_games"                  => "While playing indoors, how often did your child",
                                   "q77_turn_away"                                   => "In situations where she is meeting new people, how often did your child",
                                   "q80_seem_eager_to_get_away"                      => "When being gently rocked or hugged, how often did your child",
                                   "q82_sit_on_sidelines_and_observe_before_joining" => "When encountering a new activity, how often did your child",
                                   "q84_engage_in_activity_with_child"               => "When visiting the home of a familiar child, how often did your child",
                                   "q86_scream_with_anger"                           => "When another child took away his/her favorite toy, how often did your child",
                                   "q90_move_quickly_to_another_activity"            => "When engaged in an activity requiring attention, such as building with blocks, how often did your child",
                                   "q93_pay_attention_to_you_right_away_when_called" => "During everyday activities, how often did your child",
                                  );

        foreach ($page4_questions as $key => $question) {
            if (array_key_exists($key, $page4_question_headers)) {
                $this->addHeader("<h4><b>" . $page4_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page5_questions = array(
                            // While in a public place, how often did your child
                            "q97_seem_uneasy_about_elevator_or_escalator"              => "97. Seem uneasy about approaching an elevator or escalator?",
                            "q98_cry_distress_when_approached_by_unfamiliar_animal"    => "98. Cry or show distress when approached by an unfamiliar animal?",
                            "q99_seem_afraid_of_large_noisy_vehicles"                  => "99. Seem afraid of large, noisy vehicles?",
                            "q100_show_fear_when_caregiver_stepped_out_of_sight"       => "100. Show fear when the caregiver stepped out of sight?",
                            // When playing outdoors with other children, how often did your child
                            "q101_seem_to_be_one_of_the_most_active_children"          => "101. Seem to be one of the most active children?",
                            "q102_sit_quietly_and_watch"                               => "102. Sit quietly and watch?",
                            // During daily or evening quiet time with you and your child, how often did your child
                            "q103_want_to_be_cuddled"                                  => "103. Want to be cuddled?",
                            // During everyday activities, how often did your child
                            "q104_seem_frightened_for_no_apparent_reason"              => "104. Seem frightened for no apparent reason?",
                            "q105_seem_to_be_irritated_by_tags_in_clothes"             => "105. Seem to be irritated by tags in his/her clothes?",
                            "q106_notice_when_you_were_wearing_new_clothing"           => "106. Notice when you were wearing new clothing?",
                            "q107_react_to_beeping_sounds"                             => "107. React to beeping sounds (such as when the microwave or oven is done cooking?",
                            "q108_show_repeated_movements"                             => "108. Show repeated movements like squinting, hunching up the shoulders, or twitching the facial muscles?",
                            // When being dressed or undressed, how often did your child
                            "q109_squirm_and_try_to_get_away"                          => "109. Squirm and try to get away?",
                            "q110_stay_still"                                          => "110. Stay still?",
                            // When told “no”, how often did your child
                            "q111_stop_an_activity_quickly"                            => "111. Stop an activity quickly?",
                            "q112_stop_the_forbidden_activity"                         => "112. Stop the forbidden activity?",
                            "q113_ignore_your_warning"                                 => "113. Ignore your warning?",
                            "q114_become_sadly_tearful"                                => "114. Become sadly tearful? ",
                            // Following an exciting activity or event, how often did your child
                            "q115_calm_down_quickly"                                   => "115. Calm down quickly?",
                            "q116_have_a_hard_time_settling_down"                      => "116. Have a hard time settling down?",
                            "q117_seem_to_feel_down_or_blue"                           => "117. Seem to feel down or blue?",
                            "q118_become_sadly_tearful"                                => "118. Become sadly tearful?",
                            // When given something to eat that s/he didn’t like, how often did your child
                            "q119_become_angry"                                        => "119. Become angry?",
                            // During everyday activities, how often did your child seem able to
                            "q120_easily_shift_attention_from_one_activity_to_another" => "120. Easily shift attention from one activity to another?",
                            "q121_do_more_than_one_thing_at_a_time"                    => "121. Do more than one thing at a time (such as playing with a toy while watching TV)?",
                            // While playing indoors, how often did your child
                            "q122_run_through_the_house"                               => "122. Run through the house?",
                            "q123_climb_over_furniture"                                => "123. Climb over furniture?",
                            "q124_not_care_for_rough_rowdy_games"                      => "124. <u>Not</u> care for rough and rowdy games?",
                            "q125_enjoy_activities_such_as_being_spun"                 => "125. Enjoy activities such as being spun, etc.?",
                           );

        $page5_question_headers = array(
                                   "q97_seem_uneasy_about_elevator_or_escalator"              => "While in a public place, how often did your child",
                                   "q101_seem_to_be_one_of_the_most_active_children"          => "When playing outdoors with other children, how often did your child",
                                   "q103_want_to_be_cuddled"                                  => "During daily or evening quiet time with you and your child, how often did your child",
                                   "q104_seem_frightened_for_no_apparent_reason"              => "During everyday activities, how often did your child",
                                   "q109_squirm_and_try_to_get_away"                          => "When being dressed or undressed, how often did your child",
                                   "q111_stop_an_activity_quickly"                            => "When told “no”, how often did your child",
                                   "q115_calm_down_quickly"                                   => "Following an exciting activity or event, how often did your child",
                                   "q119_become_angry"                                        => "When given something to eat that s/he didn’t like, how often did your child",
                                   "q120_easily_shift_attention_from_one_activity_to_another" => "During everyday activities, how often did your child seem able to",
                                   "q122_run_through_the_house"                               => "While playing indoors, how often did your child",
                                  );

        foreach ($page5_questions as $key => $question) {
            if (array_key_exists($key, $page5_question_headers)) {
                $this->addHeader("<h4><b>" . $page5_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    function _page6()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page6_questions = array(
                            // When playing alone, how often did your child
                            "q126_become_easily_distracted"                         => "126. Become easily distracted?",
                            "q127_play_with_set_of_objects_for_5_minutes_or_longer" => "127. Play with a set of objects for 5 minutes or longer at a time?",
                            "q128_scratch_himself_herself"                          => "128. Scratch him/herself?",
                            "q129_tear_materials_close_at_hand"                     => "129. Tear materials close at hand?",
                            // Before an exciting event (such as receiving a new toy), how often did your child
                            "q130_get_so_worked_up_trouble_sitting_still"           => "130. Get so worked up that s/he had trouble sitting still?",
                            "q131_get_very_excited_about_getting_it"                => "131. Get very excited about getting it?",
                            "q132_remain_pretty_calm"                               => "132. Remain pretty calm?",
                            "q133_seem_eager_to_have_it_right_away"                 => "133. Seem eager to have it right away?",
                            // When s/he asked for something and you said “no”, how often did your child
                            "q134_become_frustrated"                                => "134. Become frustrated?",
                            "q135_protest_with_anger"                               => "135. Protest with anger?",
                            "q136_have_a_temper_tantrum"                            => "136. Have a temper tantrum?",
                            "q137_become_sad"                                       => "137. Become sad?",
                            // While playing or walking outdoors, how often did your child
                            "q138_notice_sighs_or_sounds"                           => "138. Notice sights or sounds (for example, wind chimes or water sprinklers)?",
                            "q139_notice_flying_or_crawling_insects"                => "139. Notice flying or crawling insects?",
                            // When you gave your child an attractive toy, how often did your child
                            "q140_grab_the_object_as_soon_as_it_was_set_down"       => "140. Grab the object as soon as it was set down?",
                            "q141_look_the_object_over_before_touching_it"          => "141. Look the object over before touching it?",
                            // When asked to wait for a desirable item (such as ice cream), how often did your child
                            "q142_seem_unable_to_wait_for_as_long_as_1_minute"      => "142. Seem unable to wait for as long as 1 minute?",
                            "q143_go_after_it_anyway"                               => "143. Go after it anyway?",
                            "q144_wait_patiently"                                   => "144. Wait patiently?",
                            "q145_whimper_and_cry"                                  => "145. Whimper and cry?",
                            // When being gently rocked, how often did your child
                            "q146_smile"                                            => "146. Smile?",
                            "q147_make_sounds_of_pleasure"                          => "147. Make sounds of pleasure?",
                            // While visiting relatives or adult family friends s/he sees infrequently, how often did your child
                            "q148_stay_back_and_avoid_eye_contact"                  => "148. Stay back and avoid eye contact?",
                            "q149_hide_his_her_face"                                => "149. Hide his/her face?",
                            "q150_warm_up_to_the_person_within_a_few_minutes"       => "150. \"Warm up\" to the person within a few minutes?",
                            // When you removed something s/he should not have been playing with, how often did your child
                            "q151_become_sad"                                       => "151. Become sad?",
                            // During everyday activities, how often did your child
                            "q152_become_bothered_by_sounds_in_noisy_environments"  => "152. Become bothered by sounds while in noisy environments?",
                            "q153_become_bothered_by_scratchy_materials_like_wool"  => "153. Become bothered by scratchy materials like wool?",
                            "q154_notice_changes_in_your_appearances"               => "154. Notice changes in your appearances (such as wet hair, a hat, or jewelry)?",
                            "q155_appear_to_listen_to_even_very_quiet_sounds"       => "155. Appear to listen to even very quiet sounds?",
                            "q156_seem_full_of_energy_even_in_evening"              => "156. Seem full of energy, even in the evening?",
                           );

        $page6_question_headers = array(
                                   "q126_become_easily_distracted"                        => "When playing alone, how often did your child",
                                   "q130_get_so_worked_up_trouble_sitting_still"          => "Before an exciting event (such as receiving a new toy), how often did your child",
                                   "q134_become_frustrated"                               => "When s/he asked for something and you said “no”, how often did your child",
                                   "q138_notice_sighs_or_sounds"                          => "While playing or walking outdoors, how often did your child",
                                   "q140_grab_the_object_as_soon_as_it_was_set_down"      => "When you gave your child an attractive toy, how often did your child",
                                   "q142_seem_unable_to_wait_for_as_long_as_1_minute"     => "When asked to wait for a desirable item (such as ice cream), how often did your child",
                                   "q146_smile"                                           => "When being gently rocked, how often did your child",
                                   "q148_stay_back_and_avoid_eye_contact"                 => "While visiting relatives or adult family friends s/he sees infrequently, how often did your child",
                                   "q151_become_sad"                                      => "When you removed something s/he should not have been playing with, how often did your child",
                                   "q152_become_bothered_by_sounds_in_noisy_environments" => "During everyday activities, how often did your child",
                                  );

        foreach ($page6_questions as $key => $question) {
            if (array_key_exists($key, $page6_question_headers)) {
                $this->addHeader("<h4><b>" . $page6_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the seventh page of the form.
    *
    * @return void
    */
    function _page7()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page7_questions = array(
                            // When interrupted during a favorite TV show, how often did your child
                            "q157_immediately_return_to_watching_TV_program"        => "157. Immediately return to watching the TV program?",
                            "q158_not_finish_watching_the_program"                  => "158. <u>Not</u> finish watching the program?",
                            // While being held on your lap, how often did your child
                            "q159_pull_away_and_kick"                               => "159. Pull away and kick? ",
                            "q160_seem_to_enjoy_himself_herself"                    => "160. Seem to enjoy him/herself?",
                            "q161_mold_to_your_body"                                => "161. Mold to your body? ",
                            "q162_seek_hugs_and_kisses"                             => "162. Seek hugs and kisses? ",
                            // While a story was being read to your child, how often did s/he
                            "q163_enjoy_listening_to_the_story"                     => "163. Enjoy listening to the story?",
                            // When hearing about a future family outing (such as a trip, to the playground), how often did your child
                            "q164_become_very_enthusiastic"                         => "164. Become very enthusiastic?",
                            "q165_look_forward_to_it"                               => "165. Look forward to it?",
                            "q166_remain_pretty_calm"                               => "166. Remain pretty calm?",
                            // While looking at picture books on his/her own, how often did your child
                            "q167_stay_interested_in_book_for_5_minutes_or_less"    => "167. Stay interested in the book for 5 minutes or less?",
                            "q168_stay_interested_in_book_for_more_than_10_minutes" => "168. Stay interested in the book for more than 10 minutes at a time? ",
                            "q169_become_easily_distracted"                         => "169. Become easily distracted?",
                            "q170_enjoy_looking_at_the_books"                       => "170. Enjoy looking at the books? ",
                            // When tired after a long day of activities, how often did your child
                            "q171_become_easily_frustrated"                         => "171. Become easily frustrated? ",
                            // When a familiar adult, such as a relative or friend, visited your home, how often did your child
                            "q172_want_to_interact_with_the_adult"                  => "172. Want to interact with the adult?",
                            // When asked to do so, how often was your child able to
                            "q173_stop_an_ongoing_activity"                         => "173. Stop an ongoing activity?",
                            "q174_lower_his_or_her_voice"                           => "174. Lower his or her voice?",
                            "q175_be_careful_with_something_breakable"              => "175. Be careful with something breakable?",
                            // When visiting a new place, how often did your child
                            "q176_not_want_to_enter"                                => "176. <u>Not</u> want to enter?",
                            "q177_go_right_in"                                      => "177. Go right in?",
                            // While you were showing your child how to do something, how often did your child
                            "q178_jump_into_the_task_before_fully_explained"        => "178. Jump into the task before it was fully explained?",
                            // While you were talking with someone else, how often did your child
                            "q179_easily_switch_attention_from_speaker_to_speaker"  => "179. Easily switch attention from speaker to speaker?",
                            // During everyday activities, how often did your child
                            "q180_become_irritated_when_clothes_were_tight"         => "180. Become irritated when his/her clothes were tight?",
                            "q181_notice_something_smells_from_cooking"             => "181. Notice something smells from cooking?",
                            "q182_rock_back_and_forth_while_sitting"                => "182. Rock back and forth while sitting?",
                            "q183_notice_sirens_from_fire_trucks_or_ambulances"     => "183. Notice sirens from fire trucks or ambulances at a distance?",
                           );

        $page7_question_headers = array(
                                   "q157_immediately_return_to_watching_TV_program"       => "When interrupted during a favorite TV show, how often did your child",
                                   "q159_pull_away_and_kick"                              => "While being held on your lap, how often did your child",
                                   "q163_enjoy_listening_to_the_story"                    => "While a story was being read to your child, how often did s/he",
                                   "q164_become_very_enthusiastic"                        => "When hearing about a future family outing (such as a trip, to the playground), how often did your child",
                                   "q167_stay_interested_in_book_for_5_minutes_or_less"   => "While looking at picture books on his/her own, how often did your child",
                                   "q171_become_easily_frustrated"                        => "When tired after a long day of activities, how often did your child",
                                   "q172_want_to_interact_with_the_adult"                 => "When a familiar adult, such as a relative or friend, visited your home, how often did your child",
                                   "q173_stop_an_ongoing_activity"                        => "When asked to do so, how often was your child able to",
                                   "q176_not_want_to_enter"                               => "When visiting a new place, how often did your child",
                                   "q178_jump_into_the_task_before_fully_explained"       => "While you were showing your child how to do something, how often did your child",
                                   "q179_easily_switch_attention_from_speaker_to_speaker" => "While you were talking with someone else, how often did your child",
                                   "q180_become_irritated_when_clothes_were_tight"        => "During everyday activities, how often did your child",
                                  );

        foreach ($page7_questions as $key => $question) {
            if (array_key_exists($key, $page7_question_headers)) {
                $this->addHeader("<h4><b>" . $page7_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the eighth page of the form.
    *
    * @return void
    */
    function _page8()
    {
        $this->addHeader("ECBQ (Early Childhood Behavior Questionnaire) - Survey");

        $options = array(
                    null               => '',
                    '1_never'          => "1 - Never",
                    '2_very_rarely'    => "2 - Very rarely",
                    '3_less_than_half' => "3 - Less than half the time",
                    '4_about_half'     => "4 - About half the time",
                    '5_more_than_half' => "5 - More than half the time",
                    '6_almost_always'  => "6 - Almost always",
                    '7_always'         => "7 - Always",
                    'not_answered'     => "Does not apply - NA",
                   );

        $page8_questions = array(
                            // When you mildly criticized or corrected his/her behavior, how often did your child
                            "q184_get_mad"                                          => "184. Get mad?",
                            "q185_have_hurt_feelings"                               => "185. Have hurt feelings?",
                            // When s/he was upset, how often did your child
                            "q186_cry_for_more_than_3_minutes_even_when_comforted"  => "186. Cry for more than 3 minutes, even when being comforted?",
                            "q187_cheer_up_within_minute_or_two_when_comforted"     => "187. Cheer up within a minute or two when being comforted?",
                            "q188_become_easily_soothed"                            => "188. Become easily soothed?",
                            // When you were busy, how often did your child
                            "q189_find_another_activity_to_do_when_asked"           => "189. Find another activity to do when asked?",
                            // While playing outdoors, how often did your child
                            "q190_want_to_jump_from_heights"                        => "190. Want to jump from heights?",
                            "q191_want_to_go_down_slide_in_unusual_ways"            => "191. Want to go down the slide in unusual ways (for example, head first)?",
                            "q192_enjoy_being_pushed_fast_on_wheeled_vehicle"       => "192. Enjoy being pushed fast on a wheeled vehicle?",
                            "q193_enjoy_sitting_down_and_playing_quietly"           => "193. Enjoy sitting down and playing quietly?",
                            // When playing alone, how often did your child
                            "q194_chew_his_her_lower_lip"                           => "194. Chew his/her lower lip?",
                            "q195_stick_out_tongue_when_concentrating"              => "195. Stick out his/her tongue when concentrating?",
                            "q196_move_from_task_to_another_without_completing_any" => "196. Move from one task or activity to another without completing any?",
                            "q197_have_trouble_focusing_on_a_task_without_guidance" => "197. Have trouble focusing on a task without guidance?",
                            // When given a wrapped present, how often did your child
                            "q198_become_extremely_animated"                        => "198. Become extremely animated?",
                            // When around large gatherings of familiar adults or children, how often did your child
                            "q199_want_to_be_involved_in_a_group_activity"          => "199. Want to be involved in a group activity?",
                            "q200_enjoy_playing_with_a_number_of_different_people"  => "200. Enjoy playing with a number of different people?",
                            // When s/he was asked to share his/her toys, how often did your child
                            "q201_become_sad"                                       => "201. Become sad?",
                           );

        $page8_question_headers = array(
                                   "q184_get_mad"                                         => "When you mildly criticized or corrected his/her behavior, how often did your child",
                                   "q186_cry_for_more_than_3_minutes_even_when_comforted" => "When s/he was upset, how often did your child",
                                   "q189_find_another_activity_to_do_when_asked"          => "When you were busy, how often did your child",
                                   "q190_want_to_jump_from_heights"                       => "While playing outdoors, how often did your child",
                                   "q194_chew_his_her_lower_lip"                          => "When playing alone, how often did your child",
                                   "q198_become_extremely_animated"                       => "When given a wrapped present, how often did your child",
                                   "q199_want_to_be_involved_in_a_group_activity"         => "When around large gatherings of familiar adults or children, how often did your child",
                                   "q201_become_sad"                                      => "When s/he was asked to share his/her toys, how often did your child",
                                  );

        foreach ($page8_questions as $key => $question) {
            if (array_key_exists($key, $page8_question_headers)) {
                $this->addHeader("<h4><b>" . $page8_question_headers[$key] . "</h4></b>");
            }
            $this->addSelect($key, $question, $options);
        }
    }
}
?>