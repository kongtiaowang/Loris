<?php
/**
 *This file contains the NDB_BVL_Instrument_BRIEF2_Teacher class
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
 * Creates the form elements for the NDB_BVL_Instrument_BRIEF2_Teacher instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BRIEF2_Teacher extends NDB_BVL_Instrument
{
    use instrument_validator;

    var $scoreLabels = array(
        'inhibit_raw_score',
        'shift_raw_score',
        'emotional_control_raw_score',
        'initiate_raw_score',
        'working_memory_raw_score',
        'plan_raw_score',
        'self_monitor_raw_score',
        'task_monitor_raw_score',
        'material_org_raw_score',
        'GEC_raw_score',
        'behav_reg_index_raw_score',
        'emotion_reg_index_raw_score',
        'cogn_reg_index_raw_score'
    );
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
        $this->testName = "BRIEF2_Teacher";           // test_names.Test_name
        $this->table    = 'BRIEF2_Teacher';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array("birth_date");

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
        if (preg_match("/BRIEF2_Teacher(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("BRIEF-2 Teacher Form");
        $this->addHeader("<h3>Adapted and reproduced by special permission of the Publisher, Psychological Assessment Resources, Inc. (PAR),
                          16204 North Florida Avenue, Lutz, Florida 33549, from the Behavior Rating Inventory of Executive Function, Second
                          Edition by Gerard A. Gioia, PhD, Peter K. Isquith, PhD, Steven C. Guy, PhD, and Lauren Kenworthy, PhD, Copyright 
                          1996, 1998, 2000, 2015 by PAR. Further reproduction is prohibited without permission from PAR.</h3>");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->form->addElement('header', null, "Score Summary");


        //scoring column headers
        $group[] = $this->form->createElement('static', "raw_score", null, null);
        $group[] = $this->form->createElement('static', "T_score", null, null);
        $group[] = $this->form->createElement('static', "percentile", null, null);
        $group[] = $this->form->createElement('static', "CI", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
       $domains= array("inhibit" => "Inhibit","self_monitor" => "Self Monitor", "behav_reg_index"=>"Behavior Regulation Index",
        "shift" => "Shift", "emotional_control" => "Emotional Control", "emotion_reg_index" =>"Emotion Regulation Index",
        "initiate" => "Initiate", "working_memory" => "Working Memory", "plan" => "Plan/Organize","task_monitor" => "Task Monitor","material_org" => "Material Organization",
        "cogn_reg_index"=> "Cognitive Regulation Index",
        "GEC" => "Global Executive Composite",

    );
        $columnHeaders = array("raw_score" => "Raw Score", "T_score" => "T Score",
            "percentile" => "Percentile", "CI" => "90 % Confidence Interval",
        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field=>$label)  {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }
    }

    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        $this->addHeader("BRIEF-2 Teacher Form");

       // $this->addBasicDate('birth_date', "Student's Date of Birth");

        $gender_options = array(
                           null     => "",
                           "male"   => "Male",
                           "female" => "Female",
                           "not_answered" =>"Prefer not to answer"
                          );

        $this->addSelect("student_gender", "Student's Sex", $gender_options);

        $this->addBasicText("student_age", "Student's Age <br><h5><i>(Please enter a numeric value between 0-100. If you don't wish to answer, enter NA.)</i></h5>");

        $this->addBasicText("student_grade", "Grade <br><h5><i>(Please enter a numeric value between 1-12 or K. If you don't wish to answer, enter NA.)</i></h5>");

        $relationship_options = array(
                                 null        => "",
                                 "teacher"   => "Teacher",
                                 "counselor" => "Counselor",
                                 "other"     => "Other",
                                );

        $this->addSelect("relationship_to_student", "Relationship to student:", $relationship_options);

        $this->addBasicText("if_other_relationship", "Other:");

        $this->XINRegisterRule(
            "if_other_relationship",
            array("relationship_to_student{@}=={@}other"),
            "Required."
        );

        $rater_options = array(
                          null              => "",
                          "not_well"        => "Not Well",
                          "moderately_well" => "Moderately Well",
                          "very_well"       => "Very Well",
                           "not_answered"   => "Prefer not to answer"
                         );

        $this->addSelect("how_well_do_you_know_student", "How well do you know this student?", $rater_options);

        $this->addBasicText("how_long_have_you_known_student", "How long have you known this student? (months) <br><h5><i>(Please enter a numeric value between 0-120. If you don't wish to answer, enter NA.)</i></h5>");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                           "not_answered"   => "Prefer not to answer"
                          );

        $this->addSelect("does_student_receive_special_education_services", "Does this student receive special education services?", $yes_no_options);

        $options = array(
                    null => "",
                    "N"  => "Never(N)",
                    "S"  => "Sometimes(S)",
                    "O"  => "Often(O)",
                    "not_answered"   => "Prefer not to answer"
                   );

        $questions = array(
                      "q1_is_fidgety"                                               => "1. Is fidgety",
                      "q2_resists_accepting_different_way_to_solve_problem"         => "2. Resists or has trouble accepting a different way to solve a problem with schoolwork, friends, tasks, etc.",
                      "q3_given_three_things_remembers_only_first_or_last"          => "3. When given three things to do, remembers only the first or last",
                      "q4_unaware_of_how_behavior_affects_bothers_others"           => "4. Is unaware of how his/her behavior affects or bothers others",
                      "q5_work_is_sloppy"                                           => "5. Work is sloppy",
                      "q6_has_explosive_angry_outbursts"                            => "6. Has explosive, angry outbursts",
                      "q7_does_not_plan_ahead_school_assignments"                   => "7. Does not plan ahead for school assignments",
                      "q8_cannot_find_things_in_desk"                               => "8. Cannot find things in desk",
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
                      "q19_has_trouble_with_tasks_more_than_one_step"               => "19. Has trouble with tasks that have more than one step",
                      "q20_does_not_realize_certain_actions_bother_others"          => "20. Does not realize that certain actions bother others",
                      "q21_written_work_is_poorly_organized"                        => "21. Written work is poorly organized",
                      "q22_small_events_trigger_big_reactions"                      => "22. Small events trigger big reactions",
                      "q23_has_good_ideas_lacks_follow_through"                     => "23. Has good ideas but does not get job done (lacks follow-through)",
                      "q24_talks_at_wrong_time"                                     => "24. Talks at the wrong time",
                      "q25_has_trouble_finishing_tasks"                             => "25. Has trouble finishing tasks (assignments, homework, etc.)",
                      "q26_does_not_notice_when_behavior_causes_negative_reactions" => "26. Does not notice when his/her behavior causes negative reactions",
                      "q27_reacts_more_strongly_than_other_children"                => "27. Reacts more strongly to situations than other children",
                      "q28_has_trouble_remembering_things_even_for_minutes"         => "28. Has trouble remembering things, even for a few minutes",
                      "q29_makes_careless_errors"                                   => "29. Makes careless errors",
                      "q30_gets_out_of_seat_at_wrong_times"                         => "30. Gets out of seat at the wrong times",
                      "q31_becomes_upset_with_new_situations"                       => "31. Becomes upset with new situations",
                      "q32_has_trouble_concentrating_on_schoolwork"                 => "32. Has trouble concentrating on schoolwork, etc.",
                     );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    *@return void
    */
    function _page2()
    {
        $this->addHeader("BRIEF-2 Teacher Form");

        $options = array(
                    null => "",
                    "N"  => "Never(N)",
                    "S"  => "Sometimes(S)",
                    "O"  => "Often(O)",
                    "not_answered"   => "Prefer not to answer"
                   );

        $questions = array(
                      "q33_has_poor_handwriting"                                => "33. Has poor handwriting",
                      "q34_mood_changes_frequently"                             => "34. Mood changes frequently",
                      "q35_has_good_ideas_cannot_get_on_paper"                  => "35. Has good ideas but cannot get them on paper",
                      "q36_has_trouble_counting_to_three"                       => "36. Has trouble counting to three",
                      "q37_leaves_messes_others_clean_up"                       => "37. Leaves messes that others have to clean up",
                      "q38_needs_to_be_told_to_begin_task"                      => "38. Needs to be told to begin a task even when willing",
                      "q39_acts_too_wild_or_out_of_control"                     => "39. Acts too wild or \"out of control\"",
                      "q40_thinks_too_much_about_same_topic"                    => "40. Thinks too much about the same topic",
                      "q41_forgets_what_he_she_was_doing"                       => "41. Forgets what he/she was doing",
                      "q42_does_not_check_work_for_mistakes"                    => "42. Does not check work for mistakes",
                      "q43_angry_or_tearful_outbursts_intense_end_suddenly"     => "43. Angry or tearful outbursts are intense but end suddenly",
                      "q44_becomes_overwhelmed_by_large_assignments"            => "44. Becomes overwhelmed by large assignments",
                      "q45_loses_lunch_box_money_permission_slips_homework"     => "45. Loses lunch box, lunch money, permission slips, homework, etc.",
                      "q46_needs_help_from_adult_to_stay_on_task"               => "46. Needs help from an adult to stay on task",
                      "q47_forgets_to_hand_in_homework_even_when_completed"     => "47. Forgets to hand in homework, even when completed",
                      "q48_has_trouble_putting_brakes_on_actions"               => "48. Has trouble putting the brakes on his/her actions",
                      "q49_resists_change_of_routine_foods_places"              => "49. Resists change of routine, foods, places, etc.",
                      "q50_q50_has_trouble_getting_started_on_work"             => "50. Has trouble getting started on work",
                      "q51_mood_easily_influenced_by_situation"                 => "51. Mood is easily influenced by the situation",
                      "q52_underestimates_time_needed_to_finish_tasks"          => "52. Underestimates time needed to finish tasks",
                      "q53_does_not_bring_home_homework_sheets_materials"       => "53. Does not bring home homework, assignment sheets, materials, etc.",
                      "q54_cannot_find_front_door_of_school"                    => "54. Cannot find the front door of school",
                      "q55_does_not_take_initiative"                            => "55. Does not take initiative",
                      "q56_becomes_upset_too_easily"                            => "56. Becomes upset too easily",
                      "q57_starts_assignments_at_last_minute"                   => "57. Starts assignments at the last minute",
                      "q58_does_not_think_of_consequences_before_acting"        => "58. Does not think of consequences before acting",
                      "q59_is_unaware_of_own_behavior_when_in_group"            => "59. Is unaware of own behavior when in a group",
                      "q60_has_problems_with_differeny_ways_solving_problem"    => "60. Has problems coming up with different ways of solving a problem",
                      "q61_tests_poorly_even_when_knows_correct_answers"        => "61. Tests poorly even when knows correct answers",
                      "q62_leaves_work_incomplete"                              => "62. Leaves work incomplete",
                      "q63_has_trouble_thinking_different_way_to_solve_problem" => "63. Has trouble thinking of a different way to solve a problem when stuck",
                     );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }

    function validate_page1($values)
    {

        $errors = [];

        // NA option because this is a Teacher form
        $this->validate_age($values, "student_age", $errors);

        $this->validate_grade($values, "student_grade", $errors);

        if ($values["relationship_to_student"] != "other") {
            $this->validate_empty_subquestions($values, ["if_other_relationship"], $errors);
        }

        $this->validate_numeric($values, "how_long_have_you_known_student", $errors, 0, 120);

        return $errors;
    }
    function score()
    {
        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());
        $inhibit_array=array($record['q1_is_fidgety'],
            $record['q10_does_not_think_before_doing_impulsive'],
            $record['q16_gets_out_of_control_more_than_friends'],
            $record['q24_talks_at_wrong_time'],
            $record['q30_gets_out_of_seat_at_wrong_times'],
            $record['q39_acts_too_wild_or_out_of_control'],
            $record['q48_has_trouble_putting_brakes_on_actions'],
            $record['q58_does_not_think_of_consequences_before_acting'],
        );
        $self_monitor_array=array($record['q4_unaware_of_how_behavior_affects_bothers_others'],
            $record['q13_has_poor_understanding_of_own_strengths_weaknesses'],
            $record['q20_does_not_realize_certain_actions_bother_others'],
            $record['q26_does_not_notice_when_behavior_causes_negative_reactions'],
            $record['q59_is_unaware_of_own_behavior_when_in_group'],
        );

        $shift_array=array($record['q2_resists_accepting_different_way_to_solve_problem'],
            $record['q11_has_trouble_getting_used_to_new_situations'],
            $record['q17_gets_stuck_on_one_topic_activity'],
            $record['q31_becomes_upset_with_new_situations'],
            $record['q40_thinks_too_much_about_same_topic'],
            $record['q49_resists_change_of_routine_foods_places'],
            $record['q60_has_problems_with_differeny_ways_solving_problem'],
            $record['q63_has_trouble_thinking_different_way_to_solve_problem'],
        );
        $emotional_control_array=array($record['q6_has_explosive_angry_outbursts'],
            $record['q14_has_outbursts_for_little_reason'],
            $record['q22_small_events_trigger_big_reactions'],
            $record['q27_reacts_more_strongly_than_other_children'],
            $record['q34_mood_changes_frequently'],
            $record['q43_angry_or_tearful_outbursts_intense_end_suddenly'],
            $record['q51_mood_easily_influenced_by_situation'],
            $record['q56_becomes_upset_too_easily'],
        );
        $initiate_array=array($record['q9_is_not_a_self_starter'],
            $record['q38_needs_to_be_told_to_begin_task'],
            $record['q50_q50_has_trouble_getting_started_on_work'],
            $record['q55_does_not_take_initiative'],
        );
        $working_memory_array=array($record['q3_given_three_things_remembers_only_first_or_last'],
            $record['q12_has_a_short_attention_span'],
            $record['q19_has_trouble_with_tasks_more_than_one_step'],
            $record['q25_has_trouble_finishing_tasks'],
            $record['q28_has_trouble_remembering_things_even_for_minutes'],
            $record['q32_has_trouble_concentrating_on_schoolwork'],
            $record['q41_forgets_what_he_she_was_doing'],
            $record['q46_needs_help_from_adult_to_stay_on_task'],
        );
        $plan_array=array($record['q7_does_not_plan_ahead_school_assignments'],
            $record['q15_gets_caught_up_in_details_misses_big_picture'],
            $record['q23_has_good_ideas_lacks_follow_through'],
            $record['q35_has_good_ideas_cannot_get_on_paper'],
            $record['q44_becomes_overwhelmed_by_large_assignments'],
            $record['q52_underestimates_time_needed_to_finish_tasks'],
            $record['q57_starts_assignments_at_last_minute'],
            $record['q61_tests_poorly_even_when_knows_correct_answers'],
        );
        $task_monitor_array=array($record['q5_work_is_sloppy'],
            $record['q21_written_work_is_poorly_organized'],
            $record['q29_makes_careless_errors'],
            $record['q33_has_poor_handwriting'],
            $record['q42_does_not_check_work_for_mistakes'],
            $record['q62_leaves_work_incomplete'],
        );
        $material_org_array=array($record['q8_cannot_find_things_in_desk'],
            $record['q37_leaves_messes_others_clean_up'],
            $record['q45_loses_lunch_box_money_permission_slips_homework'],
            $record['q47_forgets_to_hand_in_homework_even_when_completed'],
            $record['q53_does_not_bring_home_homework_sheets_materials'],
        );
        $scores['inhibit_raw_score']=$this->findRowScore($inhibit_array);
        $scores['self_monitor_raw_score'] =$this->findRowScore($self_monitor_array);
        $scores['behav_reg_index_raw_score'] = $scores['inhibit_raw_score'] + $scores['self_monitor_raw_score'];

        $scores['shift_raw_score'] =$this->findRowScore($shift_array);
        $scores['emotional_control_raw_score'] =$this->findRowScore($emotional_control_array);
        $scores['emotion_reg_index_raw_score'] =$scores['shift_raw_score'] +  $scores['emotional_control_raw_score'];

        $scores['initiate_raw_score']=$this->findRowScore($initiate_array);
        $scores['working_memory_raw_score']=$this->findRowScore($working_memory_array);
        $scores['plan_raw_score']=$this->findRowScore($plan_array);
        $scores['task_monitor_raw_score']=$this->findRowScore($task_monitor_array);
        $scores['material_org_raw_score']=$this->findRowScore($material_org_array);
        $scores['cogn_reg_index_raw_score']= $scores['initiate_raw_score'] + $scores['working_memory_raw_score'] +  $scores['plan_raw_score'] +  $scores['task_monitor_raw_score'] + $scores['material_org_raw_score'];

        $scores['GEC_raw_score']= $scores['inhibit_raw_score'] + $scores['shift_raw_score'] +
            $scores['emotional_control_raw_score'] +  $scores['initiate_raw_score']
            + $scores['working_memory_raw_score'] +  $scores['plan_raw_score']
            + $scores['self_monitor_raw_score'] + $scores['task_monitor_raw_score']
            +  $scores['material_org_raw_score'];

        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

        $age = Utility::calculateAge($dob, $record["Date_taken"]);
        $age_months = $age['year'] * 12 + $age['mon'] + ($age['day']/30);
        $age_years=$age_months/12;
        $age_years=floor($age_years);
        if(in_array($age_years, range(5, 7))) {
            $age_range="5 to 7";
        }
        if(in_array($age_years, range(8, 10))) {
            $age_range="8 to 10";
        }
        if(in_array($age_years, range(11, 13))) {
            $age_range="11 to 13";
        }
        if(in_array($age_years, range(14, 18))) {
            $age_range="14 to 18";
        }
        $query_gender = "SELECT Gender FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID' 
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $record_gender = $db->pselectRow($query_gender, array());
        if($record_gender['Gender']=='Male')
        {
            $gender='M';
        }
        if($record_gender['Gender']=='Female')
        {
            $gender='F';
        }

        $scales=array("inhibit","self_monitor","behav_reg_index","shift","emotional_control","emotion_reg_index","initiate","working_memory","plan","task_monitor","material_org","cogn_reg_index","GEC");


        foreach ($scales as $field) {
            $fied_raw_score=$scores[$field.'_raw_score'];


            $query_scores1 = "SELECT * FROM BRIEF2_Teacher_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND scale_raw_score= '$fied_raw_score' AND scale='$field'";
            $record_1 = $db->pselectRow($query_scores1, array());
            if (array_key_exists('scale_T_score',$record_1)) {
                $scores[$field.'_T_score']=($record_1['scale_T_score']);
            }
            if (array_key_exists('scale_percentile',$record_1)) {
                $scores[$field.'_percentile']=($record_1['scale_percentile']);
            }
            if (array_key_exists('scale_CI',$record_1)) {
                $scores[$field.'_CI']= ($record_1['scale_T_score']-$record_1['scale_CI'])."-".($record_1['scale_T_score']+$record_1['scale_CI']);
            }

        }
        $scores= str_replace(">", "Greater than ", $scores);

        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }


    function findRowScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
            if($val=='N')
            {
                $raw_score=$raw_score+1;
            }
            if($val=='S')
            {
                $raw_score=$raw_score+2;
            }
            if($val=='O')
            {
                $raw_score=$raw_score+3;
            }
        }
        return $raw_score;
    }
}
?>
