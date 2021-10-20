<?php
/**
 *This file contains the NDB_BVL_Instrument_Aberrant_Behavior_Checklist class
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
 * Creates the form elements for the Aberrant_Behavior_Checklist instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Aberrant_Behavior_Checklist extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

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
        $this->testName = "Aberrant_Behavior_Checklist";           // test_names.Test_name
        $this->table    = 'Aberrant_Behavior_Checklist';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array(
                                "Date_taken",
                                "date_today",
                               );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'Examiner',
                                    'q1_excessively_active',
                                    'q26_resists_physical_contact',
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
        if (preg_match("/Aberrant_Behavior_Checklist(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("ABC (Aberrant Behavior Checklist)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
    }

    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {

        $this->addHeader("ABC (Aberrant Behavior Checklist)");

        $this->form->addElement("static", null, "<br/>");

        $this->addBasicText('subject_id', 'Subject ID:');

        $this->addBasicDate('date_today', 'Date:');

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("Please rate your child's behavior for the last 4 weeks according to the scale below.");

        $this->addLabel("<h4><b>$this->indent 0 = Not at all a problem</b></h4>");
        $this->addLabel("<h4><b>$this->indent 1 = The behavior is a problem, but slight in degree</b></h4>");
        $this->addLabel("<h4><b>$this->indent 2 = The problem is moderately serious</b></h4>");
        $this->addLabel("<h4><b>$this->indent 3 = The problem is severe in degree</b></h4>");

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<i>Please try to keep the following points in mind:</i>");

        $this->addLabel("(a) Take relative frequency into account for each behavior specified. For example, if your child averages more temper outbursts that most other children, it's probably moderately serious or severe, even if it occurs only once or twice a week. Other behaviors, such as noncompliance, would probably have to occur more often to merit an extreme rating.");

        $this->addLabel("(b) Consider how your child behavior with others, not just with you. Try to take the whole picture into account.");

        $this->addLabel("(c) Try to consider whether a given behavior interferes with your child's <i>development, functioning, or relationships</i>. For example body rocking or social withdrawal might not disrupt other people, but it probably hinders individual development or functioning.");

        $this->form->addElement("static", null, "<br/>");

        $options = array(
                    null => "",
                    "0"  => "0",
                    "1"  => "1",
                    "2"  => "2",
                    "3"  => "3",
                   );

        $questions = array(
                      "q1_excessively_active"                        => "1. Excessively active at home, school, work, or elsewhere",
                      "q2_injures_self_on_purpose"                   => "2. Injures self on purpose",
                      "q3_listless_sluggish_inactive"                => "3. Listless, sluggish, inactive",
                      "q4_aggressive_to_others"                      => "4. Aggressive to other children or adults (verbally or physically)",
                      "q5_seeks_isolation"                           => "5. Seeks isolation from others",
                      "q6_meaningless_recurring_movements"           => "6. Meaningless, recurring body movements",
                      "q7_boisterous_noisy_rough"                    => "7. Boisterous (inappropriately noisy and rough)",
                      "q8_screams_inappropriately"                   => "8. Screams inappropriately",
                      "q9_talks_excessively"                         => "9. Talks excessively",
                      "q10_temper_tantrums_outbursts"                => "10. Temper tantrums/outbursts",
                      "q11_stereotyped_behavior_abnormal_repetitive" => "11. Stereotyped behavior; abnormal, repetitive movements",
                      "q12_preoccupied_stares_into_space"            => "12. Preoccupied, stares into space",
                      "q13_impulsive"                                => "13. Impulsive (acts without thinking)",
                      "q14_irritable_and_whiny"                      => "14. Irritable and whiny",
                      "q15_restless"                                 => "15. Restless, unable to sit still",
                      "q16_withdrawn"                                => "16. Withdrawn; prefers solitary activities",
                      "q17_odd_bizarre_behavior"                     => "17. Odd, bizarre in behavior",
                      "q18_disobedient"                              => "18. Disobedient, difficult to control",
                      "q19_yells_at_inappropriate_times"             => "19. Yells at inappropriate times",
                      "q20_fixed_facial_expression"                  => "20. Fixed facial expression; lacks emotional responsiveness",
                      "q21_disturbs_others"                          => "21. Disturbs others",
                      "q22_repetitive_speech"                        => "22. Repetitive speech",
                      "q23_does_nothing_watch_others"                => "23. Does nothing but sit and watch others",
                      "q24_uncooperative"                            => "24. Uncooperative",
                      "q25_depressed_mood"                           => "25. Depressed mood",
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

        $this->addHeader("ABC (Aberrant Behavior Checklist)");

        $this->addLabel("<h4><b>$this->indent 0 = Not at all a problem</b></h4>");
        $this->addLabel("<h4><b>$this->indent 1 = The behavior is a problem, but slight in degree</b></h4>");
        $this->addLabel("<h4><b>$this->indent 2 = The problem is moderately serious</b></h4>");
        $this->addLabel("<h4><b>$this->indent 3 = The problem is severe in degree</b></h4>");

        $this->form->addElement("static", null, "<br/>");

        $options = array(
                    null => "",
                    "0"  => "0",
                    "1"  => "1",
                    "2"  => "2",
                    "3"  => "3",
                   );

        $questions = array(
                      "q26_resists_physical_contact"              => "26. Resists any form of physical contact",
                      "q27_moves_head_repetitively"               => "27. Moves or rolls head back and forth repetitively",
                      "q28_does_not_pay_attention_instructions"   => "28. Does not pay attention to instructions",
                      "q29_demands_immediately"                   => "29. Demands must be met immediately",
                      "q30_isolates_self_from_others"             => "30. Isolates himself/herself from other children or adults",
                      "q31_disrupts_group_activities"             => "31. Disrupts group activities",
                      "q32_sits_stands_one_position_long_time"    => "32. Sits or stands in one position for a long time",
                      "q33_talks_to_self_loudly"                  => "33. Talk to self loudly",
                      "q34_cries_over_minor_hurts"                => "34. Cries over minor annoyances and hurts",
                      "q35_repetitive_movements"                  => "35. Repetitive hand, body, or head movements",
                      "q36_mood_changes_quickly"                  => "36. Mood changes quickly",
                      "q37_unresponsive_to_structured_activities" => "37. Unresponsive to structured activities (does not react)",
                      "q38_does_not_stay_in_seat"                 => "38. Does not stay in seat (during lesson, training session, meals, etc)",
                      "q39_will_not_sit_still_any_length_of_time" => "39. Will not sit still for any length of time",
                      "q40_difficult_to_reach_contact"            => "40. Is difficult to reach, contact, or get through to",
                      "q41_cries_and_screams_inappropriately"     => "41. Cries and screams inappropriately",
                      "q42_prefers_to_be_alone"                   => "42. Prefers to be alone",
                      "q43_does_not_try_to_communicate"           => "43. Does not try to communicate by words or gestures",
                      "q44_easily_distractible"                   => "44. Easily distractible",
                      "q45_waves_shakes_extremities_repeatedly"   => "45. Waves or shakes the extremities repeatedly",
                      "q46_repeats_word_phrase_over_and_over"     => "46. Repeats a word or phrase over and over",
                      "q47_stamps_feet_bangs_objects"             => "47. Stamps feet or bangs objects or slams doors",
                      "q48_constantly_runs_or_jumps"              => "48. Constantly runs or jumps around the room",
                      "q49_rocks_body_repeatedly"                 => "49. Rocks body back and forth repeatedly",
                      "q50_deliberately_hurts_self"               => "50. Deliberately hurts himself/herself",
                      "q51_pays_no_attention"                     => "51. Pays no attention when spoken to",
                      "q52_physical_violence_to_self"             => "52. Does physical violence to self",
                      "q53_inactive"                              => "53. Inactive, never moves spontaneously",
                      "q54_excessively_active"                    => "54. Tends to be excessively active",
                      "q55_responds_negatively_to_affection"      => "55. Responds negatively to affection",
                      "q56_deliberately_ignores_directions"       => "56. Deliberately ignores directions",
                      "q57_temper_outbursts_tantrums"             => "57. Has temper outbursts or tantrums when does not get own way",
                      "q58_shows_few_social_reactions"            => "58. Shows few social reactions to others",
                     );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }
    }
}
?>
