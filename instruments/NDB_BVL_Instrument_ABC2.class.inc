<?php
/**
 * Creates the form elements for the ABC-2 instrument
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
 * Creates the form elements for the ABC-2 instrument
 *
 * @category Instrument
 * @package  Main
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_ABC2 extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityRequired = false;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('ABC2', "ABC-2", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ABC2','ABC2_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('ABC2','ABC2_page2', "Page 2", 2);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('ABC2', '0', '0', 'Y', 'Visit', '1', 'V06', NULL);
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
        $this->formType = "XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "ABC2";           // test_names.Test_name
        $this->table    = 'ABC2';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

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
        if (preg_match("/ABC2(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("ABC-2");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
            null              => "",
            "mother"             => "Mother",
            "father"             => "Father",
            "step_mother"        => "Step Mother",
            "step_father"        => "Step Father",
            "other"             => "Other",
        );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("ABC-2");

        $this->addLabel("<h3><b>INSTRUCTIONS</b></h3>");

        $this->addLabel("The ABC-Community rating scale is designed to be used with clients living in the community. Please note that the term <i>client</i> is used throughout to refer to the person being rated. This may be a child of school age, an adolescent, or an adult.");

        $this->addLabel("Please rate this client's behavior for the last four weeks.");

        $this->addLabel("<h3><b>When judging this client's behavior, please keep the following points in mind:</b></h3>");

        $this->addLabel("(a) Take <b><i>relative frequency</i></b> into account or each behavior specified. That is, <i>consider this person with respect to others of similar age and sex, in general.</i> For example, if the client averages more temper outbursts than most other people you know of similar age and sex or most others in his/her class, it is probably moderately serious (2) or severe (3) even if these occur only once or twice a week. Other behaviors, such as noncompliance, would probably have to occur more frequently to merit a high rating.");

        $this->addLabel("(b) If you have access to this information, consider the experiences of other caregivers with this client. If the client has problems with others but not with you, try to take the whole picture into account.");

        $this->addLabel("(c) Try to consider whether a given behavior interferes with his/her <i>development, functioning or relationships.</i> For example, body rocking or social withdrawal may not disrupt other children or adults, but it almost certainly hinders individual development or functioning.");

        $this->addLabel("<i>Do not spend too much time on each item - your first reaction is usually the right one.</i>");

        $options = array(
                    null => "",
                    "0"  => "0 = not at all a problem",
                    "1"  => "1 = the behavior is a problem but slight in degree",
                    "2"  => "2 = the problem is moderately serious",
                    "3"  => "3 = the problem is severe in degree",
                   );

        $questions = array(
                      "q1_excessively_active"              => "1. Excessively active at home, school, work, or elsewhere",
                      "q2_injures_self_on_purpose"         => "2. Injures self on purpose",
                      "q3_listless_sluggish_inactive"      => "3. Listless, sluggish, inactive",
                      "q4_aggressive_to_others"            => "4. Aggressive to other children or adults (verbally or physically)",
                      "q5_seeks_isolation"                 => "5. Seeks isolation from others",
                      "q6_meaningless_recurring_movements" => "6. Meaningless, recurring body movements",
                      "q7_boisterous"                      => "7. Boisterous (inappropriately noisy and rough)",
                      "q8_screams_inappropriately"         => "8. Screams inappropriately",
                      "q9_talks_excessively"               => "9. Talks excessively",
                      "q10_temper_tantrums_outbursts"      => "10. Temper tantrums/outbursts",
                      "q11_stereotyped_behavior"           => "11. Stereotyped behavior; abnormal, repetitive movements",
                      "q12_preoccupied"                    => "12. Preoccupied; stares into space",
                      "q13_impulsive"                      => "13. Impulsive (acts without thinking)",
                      "q14_irritable_whiny"                => "14. Irritable and whiny",
                      "q15_restless"                       => "15. Restless, unable to sit still",
                      "q16_withdrawn"                      => "16. Withdrawn; prefers solitary activities ",
                      "q17_odd_bizarre_behavior"           => "17. Odd, bizarre in behavior",
                      "q18_disobedient"                    => "18. Disobedient; difficult to control",
                      "q19_yells_at_inappropriate_times"   => "19. Yells at inappropriate times",
                     );

        foreach ($questions as $key => $question) {

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
        $this->addHeader("ABC-2");

        $options = array(
                    null => "",
                    "0"  => "0 = not at all a problem",
                    "1"  => "1 = the behavior is a problem but slight in degree",
                    "2"  => "2 = the problem is moderately serious",
                    "3"  => "3 = the problem is severe in degree",
                   );

        $questions = array(
                      "q20_fixed_facial_expressions"             => "20. Fixed facial expression; lacks emotional responsiveness",
                      "q21_disturbs_others"                      => "21. Disturbs others",
                      "q22_repetitive_speech"                    => "22. Repetitive speech",
                      "q23_does_nothing_sit_watch_others"        => "23. Does nothing but sit and watch others",
                      "q24_uncooperative"                        => "24. Uncooperative",
                      "q25_depressed_mood"                       => "25. Depressed mood",
                      "q26_resists_any_physical_contact"         => "26. Resists any form of physical contact",
                      "q27_moves_rolls_head_back_repetitively"   => "27. Moves or rolls head back and forth repetitively",
                      "q28_does_not_pay_attention_instructions"  => "28. Does not pay attention to instructions",
                      "q29_demands_must_be_met_immediately"      => "29. Demands must be met immediately",
                      "q30_isolates_self_from_others"            => "30. Isolates himself/herself from other children or adults",
                      "q31_disrupts_group_activities"            => "31. Disrupts group activities",
                      "q32_sits_stands_one_position_long_time"   => "32. Sits or stands in one position for a long time",
                      "q33_talks_to_self_loudly"                 => "33. Talks to self loudly",
                      "q34_cries_over_minor_annoyances"          => "34. Cries over minor annoyances and hurts",
                      "q35_repetitive_hand_body_head_movements"  => "35. Repetitive hand, body, or head movements",
                      "q36_mood_changes_quickly"                 => "36. Mood changes quickly",
                      "q37_unresponsive_structured_activities"   => "37. Unresponsive to structured activities (does not react)",
                      "q38_does_not_stay_in_seat"                => "38. Does not stay in seat (e.g., during lesson or learning periods, meals, etc.)",
                      "q39_will_not_sit_still_any_length_time"   => "39. Will not sit still for any length of time",
                      "q40_difficult_to_reach_contact"           => "40. Is difficult to reach, contact, or get through to",
                      "q41_cries_screams_inappropriately"        => "41. Cries and screams inappropriately",
                      "q42_prefers_to_be_alone"                  => "42. Prefers to be alone",
                      "q43_does_not_communicate_words_gestures"  => "43. Does not try to communicate by words or gestures",
                      "q44_easily_distractable"                  => "44. Easily distractable",
                      "q45_waves_shakes_extremities_repeatedly"  => "45. Waves or shakes the extremities repeatedly",
                      "q46_repeats_word_phrase"                  => "46. Repeats a word or phrase over and over",
                      "q47_stamps_feet_bangs_objects_slam_doors" => "47. Stamps feet or bangs objects or slams doors",
                      "q48_constantly_runs_jumps_around_room"    => "48. Constantly runs or jumps around the room",
                      "q49_rocks_body_repeatedly"                => "49. Rocks body back and forth repeatedly",
                      "q50_deliberately_hurts_self"              => "50. Deliberately hurts himself/herself",
                      "q51_pays_no_attention_when_spoken_to"     => "51. Pays no attention when spoken to",
                      "q52_does_physical_violence_to_self"       => "52. Does physical violence to self",
                      "q53_inactive"                             => "53. Inactive, never moves spontaneously",
                      "q54_excessively_active"                   => "54. Tends to be excessively active",
                      "q55_responds_negatively_affection"        => "55. Responds negatively to affection",
                      "q56_deliberately_ignores_directions"      => "56. Deliberately ignores directions",
                      "q57_has_temper_tantrums_not_get_own_way"  => "57. Has temper outbursts or tantrums when he/she does not get own way",
                      "q58_shows_few_social_reactions"           => "58. Shows few social reactions to others",
                     );

        foreach ($questions as $key => $question) {

            $this->addSelect($key, $question, $options);

        }
    }
}
?>
