<?php

/**
 * This file contains the NDB_BVL_Instrument_SRS2_SchoolAge_Parent_proband
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

class NDB_BVL_Instrument_SRS2_SchoolAge_Parent_proband extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

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
     * Abstract function setup(?string $commentID = NULL, ?string $page = NULL): void;
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
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            //Page label

        //Set the object properties
        $this->testName = "SRS2_SchoolAge_Parent_proband";           //test_names.Test_name
        $this->table    = 'SRS2_SchoolAge_Parent_proband';
        $this->_requiredElements = array('q1_uncomfortable_socialsituations');

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

        if (preg_match("/SRS2_SchoolAge_Parent_proband(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        //$this->form->addFormRule(array(&$this, 'XINValidate'));
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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age Proband (Send to Mom OR Dad)");

        $this->form->addElement(
            'static',
            null,
            "<h3><i>*Please fill this form out with regard to your older child who has autism.</i></h3>"
        );

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
        for($i=1;$i<=3;$i++)
        {
            if($i==1) {
                $this->form->addElement('header', null, "SRS2 Total Score Results ");
                $domains=array("total" => "Total Raw Score",
                );
            }
            if($i==2) {
                $this->form->addElement('header', null, "DSM5 - Compatible Scales (Scores) ");
                $domains=array("DSM5_SCI" => "SCI","DSM5_RRB" => "RRB",
                );
            }
            if($i==3)
            {
                $this->form->addElement('header', null, "Treatment Subscales (Scores)");
                $domains = array("Awr" => " Social Awareness (Awr)","Cog" => "Social Cognition (Cog)","Com" => "Social Communication (Com)",
                    "Mot" => "Social Motivaton (Mot)"
                );
            }
            //scoring column headers
            $group[] = $this->form->createElement('static', "score", null, null);
            $group[] = $this->form->createElement('static', "T_score", null, null);
            $this->form->addGroup($group, 'score_header_group_'.$i, "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
            unset($group);

            //score fields

            $columnHeaders = array("score" => "Score", "T_score" => "T Score");

            foreach ($columnHeaders as $field => $label) {
                $columnHeaders[$field] .= "     ";
            }
            $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

            foreach ($domains as $field => $label) {
                foreach ($columnHeaders as $scoreField => $scoreLabel) {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
                $this->form->addGroup($group, "{$label}_score_group_{$i}", $label, $this->_GUIDelimiter, FALSE);
                unset($group);


            }

            //scoring column headers
            $group[] = $this->form->createElement('static', "score", null, null);
            $group[] = $this->form->createElement('static', "T_score", null, null);
            $this->form->addGroup($group, 'score_header_group_'.$i, "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
            unset($group);
        }
        $group[] = $this->form->createElement('static', "score_range", null, null);
        $this->form->addGroup($group, "score_range_group", "Score Range:", $this->_GUIDelimiter, FALSE);
        unset($group);

    }

    /**
     * Generates the first page of the form
     *
     * @return void
     */
    function _page1()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age Proband (Send to Mom OR Dad)");

        //Add instructions
        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Instructions:</strong><br><br>
            <i>*Please fill this form out with regard to your older child who has autism.</i><br>
            <br>
            For each question, please choose an option that best describes the child's behaviour
            <strong>over the past 6 months.</strong>"
        );

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
        //$this->form->addFormRule(array(&$this, 'validate_page1'));

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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age Proband (Send to Mom OR Dad)");

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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age Proband (Send to Mom OR Dad)");

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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - School Age Proband (Send to Mom OR Dad)");

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

    function score(): void
    {


        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $score_grid_q1=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q2=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q3=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q4=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q5=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q6=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q7=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q8=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q9=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q10=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q11=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q12=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q13=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q14=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q15=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q16=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q17=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q18=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q19=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q20=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q21=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q22=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q23=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q24=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q25=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q26=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q27=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q28=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q29=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q30=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q31=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q32=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q33=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q34=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q35=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q36=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q37=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q38=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q39=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q40=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q41=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q42=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q43=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q44=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q45=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q46=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q47=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q48=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q49=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q50=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q51=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q52=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q53=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q54=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q55=array('1_not_true'=>3,'2_sometimes_true'=>2,'3_often_true'=>1,'4_almost_always_true'=>0);
        $score_grid_q56=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q57=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q58=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q59=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q60=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q61=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q62=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q63=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q64=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);
        $score_grid_q65=array('1_not_true'=>0,'2_sometimes_true'=>1,'3_often_true'=>2,'4_almost_always_true'=>3);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());


        $Awr_array = array(
            $score_grid_q2[$record['q2_wrong_facialexpressions']],
            $score_grid_q7[$record['q7_aware_others_feeling']],
            $score_grid_q25[$record['q25_diff_wavelength']],
            $score_grid_q32[$record['q32_good_personal_hygiene']],
            $score_grid_q45[$record['q45_pay_attention']],
            $score_grid_q52[$record['q52_overly_loud']],
            $score_grid_q54[$record['q54_thinkpeople_as_objects']],
            $score_grid_q56[$record['q56_walk_btwn_people']],
        );

        $Cog_array=array(
            $score_grid_q5[$record['q5_others_take_advantage']],
            $score_grid_q10[$record['q10_takethings_literally']],
            $score_grid_q15[$record['q15_changefacialexp_understandmeaning']],
            $score_grid_q17[$record['q17_recognize_unfair']],
            $score_grid_q30[$record['q30_upset_situations']],
            $score_grid_q40[$record['q40_imaginative']],
            $score_grid_q42[$record['q42_overly_sensitive']],
            $score_grid_q44[$record['q44_chains_causation']],
            $score_grid_q48[$record['q48_goodsense_humor']],
            $score_grid_q58[$record['q58_concentration_parts']],
            $score_grid_q59[$record['q59_suspicious_ofpeople']],
            $score_grid_q62[$record['q62_reason_unusual']],
        );

        $Com_array=array(
            $score_grid_q12[$record['q12_communicate_toothers']],
            $score_grid_q13[$record['q13_awkward_turn_takingtalk']],
            $score_grid_q16[$record['q16_avoideyecontact']],
            $score_grid_q18[$record['q18_difficulty_makingfriends']],
            $score_grid_q19[$record['q19_frustrated_conveyingideas']],
            $score_grid_q21[$record['q21_imitate_actions']],
            $score_grid_q22[$record['q22_interact_appropriately']],
            $score_grid_q26[$record['q26_offer_comfort']],
            $score_grid_q33[$record['q33_socially_awkward']],
            $score_grid_q35[$record['q35_trouble_keepingup']],
            $score_grid_q36[$record['q36_difficulty_relating_adults']],
            $score_grid_q37[$record['q37_difficulty_relating_peers']],
            $score_grid_q38[$record['q38_respond_moodchange']],
            $score_grid_q41[$record['q41_wander_aimlessly']],
            $score_grid_q46[$record['q46_serious_facialexp']],
            $score_grid_q47[$record['q47_laugh_inappropriately']],
            $score_grid_q51[$record['q51_diff_directqstn']],
            $score_grid_q53[$record['q53_monotone_voice']],
            $score_grid_q55[$record['q55_invade_personalspace']],
            $score_grid_q57[$record['q57_gets_teased']],
            $score_grid_q60[$record['q60_emotionally_distant']],
            $score_grid_q61[$record['q61_inflexible']],

        );

        $Mot_array=array(
            $score_grid_q1[$record['q1_uncomfortable_socialsituations']],
            $score_grid_q3[$record['q3_self_confident']],
            $score_grid_q6[$record['q6_rather_be_alone']],
            $score_grid_q9[$record['q9_overly_dependent']],
            $score_grid_q11[$record['q11_has_selfconfidence']],
            $score_grid_q23[$record['q23_joingroups_activities']],
            $score_grid_q27[$record['q27_avoid_socialinteractions']],
            $score_grid_q34[$record['q34_avoid_emotionallyclose']],
            $score_grid_q43[$record['q43_separates_easily']],
            $score_grid_q64[$record['q64_tense_socialsituations']],
            $score_grid_q65[$record['q65_staring_gazing']],

        );

        $RRB_array=array(
            $score_grid_q4[$record['q4_rigid_inflexible']],
            $score_grid_q8[$record['q8_behave_strange_bizarre']],
            $score_grid_q14[$record['q14_notwell_coordinated']],
            $score_grid_q20[$record['q20_unusual_interests']],
            $score_grid_q24[$record['q24_diff_changeroutine']],
            $score_grid_q28[$record['q28_think_overandover']],
            $score_grid_q29[$record['q29_odd_weird']],
            $score_grid_q31[$record['q31_cant_getmind_off']],
            $score_grid_q39[$record['q39_interested_toofew_topics']],
            $score_grid_q49[$record['q49_wellat_tasks']],
            $score_grid_q50[$record['q50_repetitive_behavior']],
            $score_grid_q63[$record['q63_touching_unusual']],


        );

        $scores['Awr_score'] =$this->findRowScore($Awr_array);
        $scores['Cog_score'] =$this->findRowScore($Cog_array);
        $scores['Com_score'] =$this->findRowScore($Com_array);
        $scores['Mot_score'] =$this->findRowScore($Mot_array);
        $scores['DSM5_RRB_score'] =$this->findRowScore($RRB_array);
        $scores['DSM5_SCI_score'] =$this->findRowScore($Awr_array) + $this->findRowScore($Cog_array) + $this->findRowScore($Com_array)+ $this->findRowScore($Mot_array);
        $scores['total_score'] =$this->findRowScore($RRB_array) + $scores['DSM5_SCI_score'];



        $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID' 
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $record_gender = $db->pselectRow($query_gender, array());
        if($record_gender['Sex']=='Male')
        {
            $gender='M';
        }
        if($record_gender['Sex']=='Female')
        {
            $gender='F';
        }


        $scales = array("total", "DSM5_SCI", "DSM5_RRB", "Awr", "Cog", "Com","Mot");
        foreach ($scales as $field) {
            $field_raw_score = $scores[$field . '_score'];
            if($field_raw_score==0) {
                $query_scores1 = "SELECT * FROM SRS2_SchoolAge_lookup WHERE form_relation ='SRS2_Parent' and
                sex='$gender'  AND (scale_raw_score ='$field_raw_score'  OR  '$field_raw_score' BETWEEN SUBSTRING_INDEX
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                $record_1 = $db->pselectRow($query_scores1, array());
            }
            else{
                $query_scores1 = "SELECT * FROM SRS2_SchoolAge_lookup WHERE form_relation ='SRS2_Parent' and
                sex='$gender'  AND (scale_raw_score =$field_raw_score  OR  $field_raw_score BETWEEN SUBSTRING_INDEX
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                $record_1 = $db->pselectRow($query_scores1, array());

            }
            if (empty($record_1)) {
                $max_range = "SELECT * FROM SRS2_SchoolAge_lookup WHERE form_relation ='SRS2_Parent' and
                 sex='$gender'  AND scale_raw_score like '%>=%' AND scale='$field'";
                $max_range_array = $db->pselectRow($max_range, array());
                if(empty($max_range_array))
                {
                    $scores[$field . '_T_score'] = "NA";
                }
                else {
                    $max_number_array = explode(">=", $max_range_array['scale_raw_score']);
                    $max_number = $max_number_array[0];
                    if ($field_raw_score >= $max_number) {
                        $scores[$field . '_T_score'] = ($max_range_array['scale_T_score']);

                    }
                }
            } else{
                if (array_key_exists('scale_T_score', $record_1)) {
                    if ($record_1['scale_T_score'] == "" || ($record_1['scale_T_score'] == NULL)) {
                        $scores[$field . '_T_score'] = "NA";
                    } else {
                        $scores[$field . '_T_score'] = ($record_1['scale_T_score']);
                    }
                } else {
                    $scores[$field . '_T_score'] = "NA";
                }
            }
        }
        if($scores['total_T_score']>=76)
        {
            $scores['score_range']= "Severe";
        }
        else if(in_array($scores['total_T_score'], range(66, 75)))
        {
            $scores['score_range']= "Moderate";
        }
        else if(in_array($scores['total_T_score'], range(60, 65)))
        {
            $scores['score_range']= "Mold";
        }
        else if($scores['total_T_score']<=59)
        {
            $scores['score_range']= "Normal";
        }
        else{
            $scores['score_range']= "NA";

        }

        $scores= str_replace(">", "Greater than or ", $scores);

        $scores= str_replace("<", "Less than or", $scores);

        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));

    }

    function findRowScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
            if($val=='1')
            {
                $raw_score=$raw_score+1;
            }
            if($val=='2')
            {
                $raw_score=$raw_score+2;
            }
            if($val=='3')
            {
                $raw_score=$raw_score+3;
            }
        }

        return $raw_score;
    }
}
?>