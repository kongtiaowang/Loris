<?php
/**
 * This file contains the NDB_BVL_Instrument_BRIEF class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the BRIEF instrument
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BRIEF extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name,Sub_group,isDirectEntry) VALUES ('<TEST_NAME>','<INSTRUMENT_TITLE>',1, false);
     * INSERT INTO instrument_subtests(Test_name, Subtest_name, Description, Order_number) VALUES('<TEST_NAME>', '<TEST_NAME>_page1', 'Page1', 1);
     */

    /**
    * Sets up basic data, such as the HTML_Quickform object, and so on.
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
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BRIEF";           // test_names.Test_name
        $this->table    = 'BRIEF';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'Examiner',
                                    'child_name',
                                    '30_trouble_new_situations',
                                    '60_work_sloppy',
                                   );

        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the HTML_Quickform object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/BRIEF(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("BRIEF (Behaviour Rating Inventory of Executive Function)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
    }

    /**
    * Generates the first page of the form.
     *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("BRIEF (Behaviour Rating Inventory of Executive Function)");

        $this->addBasicText("child_name", "Child's Name");

        $this->addBasicText("gender", "Gender");

        $this->addNumericElement("grade", "Grade");

        $this->addNumericElement("age", "Age");

        $this->addDateElement('birth_date', 'Birth Date');

        $this->addBasicText("your_name", "Your Name");

        $this->addBasicText("relationship_to_child", "Relationship to Child");

        $this->addDateElement('today_date', 'Today\'s Date');

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h4>N = Never S = Sometimes O = Often</h4>");

        $this->form->addElement("static", null, "<br/>");

        $options = array(
                    null => "",
                    "N"  => "N",
                    "S"  => "S",
                    "O"  => "O",
                   );

        $this->addSelect("1_overreact_small", "1. Overreacts to small problems", $options);

        $this->addSelect("2_first_or_last", "2. When given three things to do, remembers only the first or last", $options);

        $this->addSelect("3_not_self_starter", "3. Is not a self-starter", $options);

        $this->addSelect("4_playroom_mess", "4. Leaves playroom a mess", $options);

        $this->addSelect("5_trouble_with_ways_to_solve", "5. Resists or has trouble accepting a different way to solve a problem with schoolwork, friends, chores, etc.", $options);

        $this->addSelect("6_upset_with_new_situations", "6. Becomes upset with new situations", $options);

        $this->addSelect("7_angry_outbursts", "7. Has explosive, angry outbursts", $options);

        $this->addSelect("8_tries_same_approach_over", "8. Tries the same approach to a problem over and over even when it does not work", $options);

        $this->addSelect("9_short_attention_span", "9. Has a short attention span", $options);

        $this->addSelect("10_told_to_begin_task", "10. Needs to be told to begin a task even when willing", $options);

        $this->addSelect("11_does_not_bring_homework", "11. Does not bring home homework, assignment sheets, materials, etc.", $options);

        $this->addSelect("12_upset_by_plan_changes", "12. Acts upset by a change in plans", $options);

        $this->addSelect("13_disturbed_by_teacher_change", "13. Is disturbed by change of teacher or class", $options);

        $this->addSelect("14_does_not_check_for_mistakes", "14. Does not check work for mistakes", $options);

        $this->addSelect("15_cannot_get_ideas_on_paper", "15. Has good ideas but cannot get them on paper", $options);

        $this->addSelect("16_trouble_with_ideas", "16. Has trouble coming up with ideas for what to do in play or free time", $options);

        $this->addSelect("17_trouble_concentrating", "17. Has trouble concentrating on chores, schoolwork, etc.", $options);

        $this->addSelect("18_doesnt_connect_homework_to_grades", "18. Does not connect doing tonight's homework with grades", $options);

        $this->addSelect("19_easily_distracted", "19. Is easily distracted by noises, activity, sights, etc.", $options);

        $this->addSelect("20_easily_tearful", "20. Becomes tearful easily", $options);

        $this->addSelect("21_careless_errors", "21. Makes careless errors", $options);

        $this->addSelect("22_forgets_hand_in_homework", "22. Forgets to hand in homework, even when completed", $options);

        $this->addSelect("23_resists_change", "23. Resists change of routine, foods, places, etc.", $options);

        $this->addSelect("24_trouble_with_multistep_chores", "24. Has trouble with chores or tasks that have more than one step", $options);

        $this->addSelect("25_outbursts_without_reason", "25. Has outbursts for little reason", $options);

        $this->addSelect("26_frequent_mood_change", "26. Mood changes frequently", $options);

        $this->addSelect("27_needs_adult_help_for_tasks", "27. Needs help from an adult to stay on task", $options);

        $this->addSelect("28_misses_big_picture", "28. Gets caught up in details and misses the big picture", $options);

        $this->addSelect("29_messy_room", "29. Keeps room messy", $options);
    }

    /**
    * Generates the second page of the form.
     *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("BRIEF (Behaviour Rating Inventory of Executive Function)");

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h4>N = Never S = Sometimes O = Often</h4>");

        $this->form->addElement("static", null, "<br/>");

        $options = array(
                    null => "",
                    "N"  => "N",
                    "S"  => "S",
                    "O"  => "O",
                   );

        $this->addSelect("30_trouble_new_situations", "30. Has trouble getting used to new situations (classes, groups, friends)", $options);

        $this->addSelect("31_poor_handwriting", "31. Has poor handwriting", $options);

        $this->addSelect("32_forgets_tasks_while_doing", "32. Forgets what he/she was doing", $options);

        $this->addSelect("33_forgets_what_to_get", "33. When sent to get something, forgets what he/she is supposed to get", $options);

        $this->addSelect("34_unaware_bothersome_behaviours", "34. Is unaware of how his/her behavior affects or bothers others", $options);

        $this->addSelect("35_lacks_follow_through", "35. Has good ideas but does not get job done (lacks follow-through)", $options);

        $this->addSelect("36_overwhelmed_by_assignments", "36. Becomes overwhelmed by large assignments", $options);

        $this->addSelect("37_trouble_finishing_tasks", "37. Has trouble finishing tasks (chores, homework)", $options);

        $this->addSelect("38_wilder_than_others_in_groups", "38. Acts wilder or sillier than others in groups (birthday parties, recess)", $options);

        $this->addSelect("39_thinks_too_much", "39. Thinks too much about the same topic", $options);

        $this->addSelect("40_underestimates_time_needed", "40. Underestimates time needed to finish tasks", $options);

        $this->addSelect("41_interrupts_others", "41. Interrupts others", $options);

        $this->addSelect("42_does_not_notice_negative_reactions", "42. Does not notice when his/her behavior causes negative reactions", $options);

        $this->addSelect("43_gets_out_of_seat_at_wrong_time", "43. Gets out of seat at the wrong times", $options);

        $this->addSelect("44_out_of_control_more_than_friends", "44. Gets out of control more than friends", $options);

        $this->addSelect("45_reacts_more_strongly_than_others", "45. Reacts more strongly to situations than other children", $options);

        $this->addSelect("46_starts_last_minute", "46. Starts assignments or chores at the last minute", $options);

        $this->addSelect("47_trouble_starting_tasks", "47. Has trouble getting started on homework or chores", $options);

        $this->addSelect("48_toruble_organizing_activities", "48. Has trouble organizing activities with friends", $options);

        $this->addSelect("49_blurts_things", "49. Blurts things out", $options);

        $this->addSelect("50_mood_easily_influenced", "50. Mood is easily influenced by the situation", $options);

        $this->addSelect("51_does_not_plan_ahead", "51. Does not plan ahead for school assignments", $options);

        $this->addSelect("52_poor_understanding_strength_weaknesses", "52. Has poor understanding of own strengths and weaknesses", $options);

        $this->addSelect("53_writing_poorly_organized", "53. Written work is poorly organized", $options);

        $this->addSelect("54_acts_out_of_control", "54. Acts too wild or \"out of control\"", $options);

        $this->addSelect("55_trouble_brakes_on_actions", "55. Has trouble putting the brakes on his/her actions", $options);

        $this->addSelect("56_trouble_without_adult_supervision", "56. Gets in trouble if not supervised by an adult", $options);

        $this->addSelect("57_trouble_remembering_things", "57. Has trouble remembering things, even for a few minutes", $options);

        $this->addSelect("58_trouble_reaching_goals", "58. Has trouble carrying out the actions needed to reach goals (saving money for special item, studying to get a good grade)", $options);

        $this->addSelect("59_too_silly", "59. Becomes too silly", $options);
    }

    /**
    * Generates the third page of the form.
     *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("BRIEF (Behaviour Rating Inventory of Executive Function)");

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h4>N = Never S = Sometimes O = Often</h4>");

        $this->form->addElement("static", null, "<br/>");

        $options = array(
                    null => "",
                    "N"  => "N",
                    "S"  => "S",
                    "O"  => "O",
                   );

        $this->addSelect("60_work_sloppy", "60. Work is sloppy", $options);

        $this->addSelect("61_no_initiative", "61. Does not take initiative", $options);

        $this->addSelect("62_intense_outbursts", "62. Angry or tearful outbursts are intense but end suddenly", $options);

        $this->addSelect("63_dont_realize_actions_bother_others", "63. Does not realize that certain actions bother others", $options);

        $this->addSelect("64_events_trigger_reactions", "64. Small events trigger big reactions", $options);

        $this->addSelect("65_talks_wrong_time", "65. Talks at the wrong time", $options);

        $this->addSelect("66_complains_nothing_to_do", "66. Complains there is nothing to do", $options);

        $this->addSelect("67_cannot_find_things", "67. Cannot find things in room or school desk", $options);

        $this->addSelect("68_leaves_trail_of_belongings", "68. Leaves a trail of belongings wherever he/she goes", $options);

        $this->addSelect("69_leaves_messes_others_clean", "69. Leaves messes that others have to clean up", $options);

        $this->addSelect("70_upset_easily", "70. Becomes upset too easily", $options);

        $this->addSelect("71_couch_potato", "71. Lies around the house a lot (\"couch potato\")", $options);

        $this->addSelect("72_messy_closet", "72. Has a messy closet", $options);

        $this->addSelect("73_trouble_waiting_for_turn", "73. Has trouble waiting for turn", $options);

        $this->addSelect("74_loses_things", "74. Loses lunch box, lunch money, permission slips, homework, etc.", $options);

        $this->addSelect("75_cannot_find_things", "75. Cannot find clothes, glasses, shoes, toys, books, pencils, etc.", $options);

        $this->addSelect("76_tests_poorly", "76. Tests poorly even when knows correct answers", $options);

        $this->addSelect("77_does_not_finish_projects", "77. Does not finish long-term projects", $options);

        $this->addSelect("78_needs_close_supervision", "78. Has to be closely supervised", $options);

        $this->addSelect("79_does_not_think_before_doing", "79. Does not think before doing", $options);

        $this->addSelect("80_trouble_changing_activities", "80. Has trouble moving from one activity to another", $options);

        $this->addSelect("81_fidgety", "81. Is fidgety", $options);

        $this->addSelect("82_impulsive", "82. Is impulsive", $options);

        $this->addSelect("83_cannot_stay_on_topic", "83. Cannot stay on the same topic when talking", $options);

        $this->addSelect("84_stuck_on_topic", "84. Gets stuck on one topic or activity", $options);

        $this->addSelect("85_repetitive", "85. Says the same things over and over", $options);

        $this->addSelect("86_trouble_getting_ready", "86. Has trouble getting through morning routine in getting ready for school", $options);
    }
}
?>
