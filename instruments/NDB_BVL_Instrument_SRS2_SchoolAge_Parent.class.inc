<?php

/**
 * This file contains the NDB_BVL_Instrument_SRS2_SchoolAge_Parent
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the SRS2 School-Age instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_SRS2_SchoolAge_Parent extends NDB_BVL_Instrument
{
    use instrument_validator;
    //Commonly used level of indentation;
    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    var $rating    = array(
                      ''                     => null,
                      '1_not_true'           => "1. Not True",
                      '2_sometimes_true'     => "2. Sometimes True",
                      '3_often_true'         => "3. Often True",
                      '4_almost_always_true' => "4. Almost Always True",
                      'refused_dontknow'     => "Refused/I Don't Know",
                     );
    var $informant = array(
                      ''                      => null,
                      'mother'                => "Mother",
                      'father'                => "Father",
                      'other_custodial_adult' => "Other Custodial Adult",
                      'teacher'               => "Teacher",
                      'other'                 => "Other",
                     );
    var $gender    = array(
                      ''       => null,
                      'male'   => "Male",
                      'female' => "Female",
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
    function setup($commentID, $page)
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            //Page label

        //Set the object properties
        $this->testName = "SRS2_SchoolAge_Parent";           //test_names.Test_name
        $this->table    = 'SRS2_SchoolAge_Parent';

        //Data keyed by commentID
        $this->commentID   = $commentID;
        $config            =& NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
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

        if (preg_match("/SRS2_SchoolAge_Parent(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age (Send to Mom OR Dad)");

        //Add date of administration field
        $this->addBasicDate('Date_taken', "Date of Administration", $this->dateOptions);
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
     * Generates the first page of the form
     *
     * @return void
     */
    function _page1()
    {

        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age (Send to Mom OR Dad)");

        //Add field for Age
        $field = 'child_age';$label = "Child's age in years <br><h5><i>(Please enter a numeric value between 0-100 or write NA.)</i></h5>";
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);

        //Add field for Grade
        $field = 'child_grade';$label = "Child's grade in school <br><h5><i>(Please enter a numeric value between 1-12, K, or write NA if you don't know.)</i></h5>";
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);

        //Add select for Sex
        $this->addSelect('child_gender', "Child's sex", $this->gender);

        //Add select for Relationship to Child
        $this->addSelect('informant', "Relationship to rated individual", $this->informant);
        $group[] = $this->createText('informant_other', $this->indent."If Other please specify");
        $this->addGroup($group, "informant_other_group", $this->indent."If Other please specify", null, false);
        unset($group);
        $rules_array = array("informant{@}=={@}other");
        $this->XINRegisterRule('informant_other', $rules_array, "Please specify relationship", 'informant_other_group');

        //Add instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>For each question, please choose an option that best describes the child's behaviour <strong>over the past 6 months.</strong>");

        //First block of questions
        $questions = array(
                      "q1_uncomfortable_socialsituations"     => "1. Seems much more fidgety in social situations than when alone",
                      "q2_wrong_facialexpressions"            => "2. Expressions on his or her face don't match what he or she is saying",
                      "q3_self_confident"                     => "3. Seems self-confident when interacting with others",
                      "q4_rigid_inflexible"                   => "4. When under stress, he or she shows rigid or inflexible patterns of behavior that seem odd",
                      "q5_others_take_advantage"              => "5. Doesn't recognize when others are trying to take advantage of him or her",
                      "q6_rather_be_alone"                    => "6. Would rather be alone than with others",
                      "q7_aware_others_feeling"               => "7. Is aware of what others are thinking or feeling",
                      "q8_behave_strange_bizarre"             => "8. Behaves in ways that seem strange or bizarre",
                      "q9_overly_dependent"                   => "9. Clings to adults, seems too dependent on them",
                      "q10_takethings_literally"              => "10. Takes things too literally, and doesn't get the real meaning of a conversation",
                      "q11_has_selfconfidence"                => "11. Has good self-confidence",
                      "q12_communicate_toothers"              => "12. Is able to communicate his or her feelings to others",
                      "q13_awkward_turn_takingtalk"           => "13. Is awkward in turn-taking interactions with peers (for example, doesn't seem to understand the give-and-take of conversations)",
                      "q14_notwell_coordinated"               => "14. Is not well coordinated",
                      "q15_changefacialexp_understandmeaning" => "15. Is able to understand the meaning of other people's tone of voice and facial expressions",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }
        $this->form->addFormRule(array(&$this, 'validate_page1'));

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader1', "<h4>SRS-2 School-Age Report copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the second page of the form
     *
     * @return void
     */
    function _page2()
    {

        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age (Send to Mom OR Dad)");

        //Second block of questions
        $questions = array(
                      "q16_avoideyecontact"           => "16. Avoids eye contact or has unusual eye contact",
                      "q17_recognize_unfair"          => "17. Recognizes when something is unfair",
                      "q18_difficulty_makingfriends"  => "18. Has difficulty making friends, even when trying his or her best",
                      "q19_frustrated_conveyingideas" => "19. Gets frustrated trying to get ideas across in conversations",
                      "q20_unusual_interests"         => "20. Shows unusual sensory interests (for example, mouthing or spinning objects) or strange ways of playing with toys",
                      "q21_imitate_actions"           => "21. Is able to imitate others' actions",
                      "q22_interact_appropriately"    => "22. Plays appropriately with children his or her age",
                      "q23_joingroups_activities"     => "23. Does not join group activities unless told to do so",
                      "q24_diff_changeroutine"        => "24. Has more difficulty than other children with changes in his or her routine",
                      "q25_diff_wavelength"           => "25. Doesn't seem to mind being out of step with or \"not on the same wavelength\" as others",
                      "q26_offer_comfort"             => "26. Offers comfort to others when they are sad",
                      "q27_avoid_socialinteractions"  => "27. Avoids starting social interactions with peers or adults",
                      "q28_think_overandover"         => "28. Thinks or talks about the same thing over and over",
                      "q29_odd_weird"                 => "29. Is regarded by other children as odd or weird",
                      "q30_upset_situations"          => "30. Becomes upset in a situation with lots of things going on",
                      "q31_cant_getmind_off"          => "31. Can't get his or her mind off something once he or she starts thinking about it",
                      "q32_good_personal_hygiene"     => "32. Has good personal hygiene",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader1', "<h4>SRS-2 School-Age Report copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3()
    {

        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age (Send to Mom OR Dad)");

        //Third block of questions
        $questions = array(
                      "q33_socially_awkward"           => "33. Is socially awkward, even when he or she is trying to be polite",
                      "q34_avoid_emotionallyclose"     => "34. Avoids people who want to be emotionally close to him or her",
                      "q35_trouble_keepingup"          => "35. Has trouble keeping up with the flow of a normal conversation",
                      "q36_difficulty_relating_adults" => "36. Has difficulty relating to adults",
                      "q37_difficulty_relating_peers"  => "37. Has difficulty relating to peers",
                      "q38_respond_moodchange"         => "38. Responds appropriately to mood changes in others (for example when a friend's or playmate's mood changes from happy to sad)",
                      "q39_interested_toofew_topics"   => "39. Has an unusually narrow range of interests",
                      "q40_imaginative"                => "40. Is imaginative, good at pretending (without losing touch with reality)",
                      "q41_wander_aimlessly"           => "41. Wanders aimlessly from one activity to another",
                      "q42_overly_sensitive"           => "42. Seems overly sensitive to sounds, textures, or smells",
                      "q43_separates_easily"           => "43. Separates easily from caregivers",
                      "q44_chains_causation"           => "44. Doesn't understand how events relate to one another (cause and effect) the way other children his or her age do",
                      "q45_pay_attention"              => "45. Focuses his or her attention to where others are looking or listening",
                      "q46_serious_facialexp"          => "46. Has overly serious facial expressions",
                      "q47_laugh_inappropriately"      => "47. Is too silly or laughs inappropriately",
                      "q48_goodsense_humor"            => "48. Has a sense of humor, understands jokes",
                      "q49_wellat_tasks"               => "49. Does extremely well at a few tasks, but does not do as well at most other tasks",
                      "q50_repetitive_behavior"        => "50. Has repetitive, odd behaviors such as hand flapping or rocking",
                      "q51_diff_directqstn"            => "51. Has difficulty answering questions directly and ends up talking around the subject",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader1', "<h4>SRS-2 School-Age Report copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the fourth page of the form
     *
     * @return void
     */
    function _page4()
    {

        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age (Send to Mom OR Dad)");

        //Fourth block of questions
        $questions = array(
                      "q52_overly_loud"            => "52. Knows when he or she is talking too loud or making too much noise",
                      "q53_monotone_voice"         => "53. Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture)",
                      "q54_thinkpeople_as_objects" => "54. Seems to react to people as if they are objects",
                      "q55_invade_personalspace"   => "55. Knows when he or she is too close to someone or is invading someone's space",
                      "q56_walk_btwn_people"       => "56. Walks in between two people who are talking",
                      "q57_gets_teased"            => "57. Gets teased a lot",
                      "q58_concentration_parts"    => "58. Concentrates too much on parts of things rather than seeing the whole picture. For example, if asked to describe what happened in a story, he or she may talk only about the kind of clothes the characters were wearing",
                      "q59_suspicious_ofpeople"    => "59. Is overly suspicious",
                      "q60_emotionally_distant"    => "60. Is emotionally distant, doesn't show his or her feelings",
                      "q61_inflexible"             => "61. Is inflexible, has a hard time changing his or her mind ",
                      "q62_reason_unusual"         => "62. Gives unusual or illogical reasons for doing things",
                      "q63_touching_unusual"       => "63. Touches or greets others in an unusual way (for example, he or she may touch someone just to make contact and then walk away without saying anything)",
                      "q64_tense_socialsituations" => "64. Is too tense in social settings",
                      "q65_staring_gazing"         => "65. Stares or gazes off into space",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 School-Age Report copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    function validate_page1($values)
    {
        $errors = [];
        // NA option because this is a Teacher form
        $this->validate_age($values, "child_age", $errors);

        $this->validate_grade($values, "child_grade", $errors);

        if ($values["informant"] != "other") {
            $this->validate_empty_subquestions($values, ["informant_other"], $errors);
        }

        return $errors;
    }

}
?>
