<?php
/**
 *This file contains the NDB_BVL_Instrument_BRIEF2_Parent class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_BRIEF2_Parent instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BRIEF2_Parent extends NDB_BVL_Instrument
{
    /**
    * Sets up basic data, such as the HTML_Quickform object, and so on.
    *
    * @param string $commentID the CommentID identifying the data to load
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    * @access public
    */
    function setup($commentID, $page)
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BRIEF2_Parent";           // test_names.Test_name
        $this->table    = 'BRIEF2_Parent';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array(
                                "birth_date",
                                "date_today",
                               );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'q1_is_fidgety',
                                    'q33_has_poor_handwriting',
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
        if (preg_match("/BRIEF2_Parent(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("BRIEF-2 Parent Form");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
    }

    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        $this->addHeader("BRIEF-2 Parent Form");

        $this->form->addElement("static", null, "<br/>");

        $this->addBasicDate('birth_date', 'Date of Birth');

        $this->addBasicText("childs_gender", "Gender");

        $this->addNumericElement("childs_age", "Age");

        $this->addNumericElement("childs_grade", "Grade");

        $this->addBasicText("relationship_to_child", "Relationship to child");

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h4><b>$this->indent N = Never $this->indent S = Sometimes $this->indent O = Often</b></h4>");

        $options = array(
                    null => "",
                    "N"  => "N",
                    "S"  => "S",
                    "O"  => "O",
                   );

        $questions = array(
                      "q1_is_fidgety"                                               => "1. Is fidgety",
                      "q2_resists_accepting_different_way_to_solve_problem"         => "2. Resists or has trouble accepting a different way to solve a problem with schoolwork, friends, tasks, etc.",
                      "q3_given_three_things_remembers_only_first_or_last"          => "3. When given three things to do, remembers only the first or last",
                      "q4_unaware_of_how_behavior_affects_bothers_others"           => "4. Is unaware of how his/her behavior affects or bothers others",
                      "q5_work_is_sloppy"                                           => "5. Work is sloppy",
                      "q6_has_explosive_angry_outbursts"                            => "6. Has explosive, angry outbursts",
                      "q7_does_not_plan_ahead_school_assignments"                   => "7. Does not plan ahead for school assignments",
                      "q8_cannot_find_things_in_room_or_school_desk"                => "8. Cannot find things in room or school desk",
                      "q9_is_not_a_self_starter"                                    => "9. Is not a self-starter",
                      "q10_does_not_think_before_doing_impulsive"                   => "10. Does not think before doing (is impulsive)",
                      "q11_has_trouble_getting_used_to_new_situations"              => "11. Has trouble getting used to new situations (classes, groups, friends, etc.)",
                      "q12_has_a_short_attention_span"                              => "12. Has a short attention span",
                      "q13_has_poor_understanding_of_own_strengths_weaknesses"      => "13. Has poor understanding of own strengths and weaknesses",
                      "q14_has_outbursts_for_little_reason"                         => "14. Has outbursts for little reason",
                      "q15_gets_caught_up_in_details_misses_big_picture"            => "15. Gets caught up in details and misses the big picture",
                      "q16_gets_out_of_control_more_than_friends"                   => "16. Gets out of control more than friends",
                      "q17_gets_stuck_on_one_topic_activity"                        => "17. Gets stuck on one topic or activity",
                      "q18_forgets_his_her_name"                                    => "18. Forgets his/her name",
                      "q19_has_trouble_with_chores_tasks_more_than_one_step"        => "19. Has trouble with chores or tasks that have more than one step",
                      "q20_does_not_realize_certain_actions_bother_others"          => "20. Does not realize that certain actions bother others",
                      "q21_written_work_is_poorly_organized"                        => "21. Written work is poorly organized",
                      "q22_small_events_trigger_big_reactions"                      => "22. Small events trigger big reactions",
                      "q23_has_good_ideas_lacks_follow_through"                     => "23. Has good ideas but does not get job done (lacks follow-through)",
                      "q24_talks_at_wrong_time"                                     => "24. Talks at the wrong time",
                      "q25_has_trouble_finishing_tasks"                             => "25. Has trouble finishing tasks (chores, homework, etc.)",
                      "q26_does_not_notice_when_behavior_causes_negative_reactions" => "26. Does not notice when his/her behavior causes negative reactions",
                      "q27_reacts_more_strongly_than_other_children"                => "27. Reacts more strongly to situations than other children",
                      "q28_has_trouble_remembering_things_even_for_minutes"         => "28. Has trouble remembering things, even for a few minutes",
                      "q29_makes_careless_errors"                                   => "29. Makes careless errors",
                      "q30_gets_out_of_seat_at_wrong_times"                         => "30. Gets out of seat at the wrong times",
                      "q31_becomes_upset_with_new_situations"                       => "31. Becomes upset with new situations",
                      "q32_has_trouble_concentrating_tasks_schoolwork"              => "32. Has trouble concentrating on tasks, schoolwork, etc.",
                     );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }

    /**
    * Generates the second page of the form.
    *
    *@return void
    */
    function _page2()
    {
        $this->addHeader("BRIEF-2 Parent Form");

        $this->addLabel("<h4><b>$this->indent N = Never $this->indent S = Sometimes $this->indent O = Often</b></h4>");

        $options = array(
                    null => "",
                    "N"  => "N",
                    "S"  => "S",
                    "O"  => "O",
                   );

        $questions = array(
                      "q33_has_poor_handwriting"                            => "33. Has poor handwriting",
                      "q34_mood_changes_frequently"                         => "34. Mood changes frequently",
                      "q35_has_good_ideas_cannot_get_on_paper"              => "35. Has good ideas but cannot get them on paper",
                      "q36_has_trouble_counting_to_three"                   => "36. Has trouble counting to three",
                      "q37_leaves_messes_others_clean_up"                   => "37. Leaves messes that others have to clean up",
                      "q38_needs_to_be_told_to_begin_task"                  => "38. Needs to be told to begin a task even when willing",
                      "q39_acts_too_wild_or_out_of_control"                 => "39. Acts too wild or \"out of control\"",
                      "q40_thinks_too_much_about_same_topic"                => "40. Thinks too much about the same topic",
                      "q41_forgets_what_he_she_was_doing"                   => "41. Forgets what he/she was doing",
                      "q42_does_not_check_work_for_mistakes"                => "42. Does not check work for mistakes",
                      "q43_angry_or_tearful_outbursts_intense_end_suddenly" => "43. Angry or tearful outbursts are intense but end suddenly",
                      "q44_becomes_overwhelmed_by_large_assignments"        => "44. Becomes overwhelmed by large assignments",
                      "q45_loses_lunch_box_money_permission_slips_homework" => "45. Loses lunch box, lunch money, permission slips, homework, etc.",
                      "q46_needs_help_from_adult_to_stay_on_task"           => "46. Needs help from an adult to stay on task",
                      "q47_forgets_to_hand_in_homework_even_when_completed" => "47. Forgets to hand in homework, even when completed",
                      "q48_has_trouble_putting_brakes_on_actions"           => "48. Has trouble putting the brakes on his/her actions",
                      "q49_resists_change_of_routine_foods_places"          => "49. Resists change of routine, foods, places, etc.",
                      "q50_has_trouble_getting_started_on_homework_tasks"   => "50. Has trouble getting started on homework or tasks",
                      "q51_mood_easily_influenced_by_situation"             => "51. Mood is easily influenced by the situation",
                      "q52_underestimates_time_needed_to_finish_tasks"      => "52. Underestimates time needed to finish tasks",
                      "q53_does_not_bring_home_homework_sheets_materials"   => "53. Does not bring home homework, assignment sheets, materials, etc.",
                      "q54_cannot_find_front_door_of_home"                  => "54. Cannot find the front door of home",
                      "q55_does_not_take_initiative"                        => "55. Does not take initiative",
                      "q56_becomes_upset_too_easily"                        => "56. Becomes upset too easily",
                      "q57_starts_assignments_tasks_last_minute"            => "57. Starts assignments or tasks at the last minute",
                      "q58_has_trouble_moving_from_one_activity_to_another" => "58. Has trouble moving from one activity to another",
                      "q59_has_trouble_carrying_out_actions_to_reach_goals" => "59. Has trouble carrying out the actions needed to reach goals (saving money for special item, studying to get a good grade, etc.)",
                      "q60_is_disturbed_by_change_of_teacher_or_class"      => "60. Is disturbed by change of teacher or class",
                      "q61_has_trouble_organizing_activities_with_friends"  => "61. Has trouble organizing activities with friends",
                      "q62_becomes_too_silly"                               => "62. Becomes too silly",
                      "q63_leaves_trail_of_belongings"                      => "63. Leaves a trail of belongings wherever he/she goes",
                     );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }
}
?>
