<?php

/**
 * This file contains the NDB_BVL_Instrument_SRS2_InformantReport (Dad's Report on Mom)
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
 * Creates the form elements for the SRS2 Informant Report instrument (Mom's Report on Dad)
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_SRS2_InformantReport_Dad_On_Mom extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    //Commonly used level of indentation;
    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    var $rating    = array(
                      ''                     => null,
                      '1_not_true'           => '1. Not True',
                      '2_sometimes_true'     => '2. Sometimes True',
                      '3_often_true'         => "3. Often True",
                      '4_almost_always_true' => '4. Almost Always True',
                      'refused_dontknow'     => 'Refused/I Don\'t Know',
                     );
    var $informant = array(
                      ''               => null,
                      'spouse_partner' => 'Spouse/Partner',
                      'other'          => 'Other',
                     );

    var $gender = array(
                   ''       => null,
                   'male'   => 'Male',
                   'female' => 'Female',
                   'other'  => 'Other',
                  );
    var $scoreCols = array("total_score", "DSM5_SCI_score", "DSM5_RRB_score", "Awr_score",
        "Cog_score", "Com_score","Mot_score","total_T_score", "DSM5_SCI_T_score", "DSM5_RRB_T_score", "Awr_T_score",
        "Cog_T_score", "Com_T_score","Mot_T_score","score_range");
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
        $this->page     = $page;            // Page label

        // Set the object properties
        $this->testName = "SRS2_InformantReport_Dad_On_Mom";           // test_names.Test_name
        $this->table    = 'SRS2_InformantReport_Dad_On_Mom';

        // Data keyed by commentID
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

        // Setup the form
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

        if (preg_match("/SRS2_InformantReport_Dad_On_Mom(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
	}

	$this->form->addFormRule(array(&$this, 'XINValidate'));

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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report (Dad's Report on Mom)");

        $label = "Please click this bubble 'Yes' to confirm that you are filling out this survey about the child’s biological mother.";

        $this->form->addElement(
            'select',
            'respondent',
            $label,
            array(
             null       => '',
             'Yes'      => 'Yes'
            )
        );

        //Add date of administration field
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        //Add field for Age
        $this->addBasicText('informant_age', "Your age<BR><h5><i>(Please enter a numeric value between 0-100. If you don't wish to answer, enter NA)</i></h5>");

        //Add Special Rules
        //$this->form->addFormRule(array(&$this, 'srs2SpecialRules'));

        //Add select for Sex
        $this->addSelect('informant_gender', "Your sex", $this->gender);

        //Add select for Relationship to rated individual
        $this->addSelect('informant', "Your relationship to the child’s biological mother", $this->informant);
        $group[] = $this->createText('informant_other', $this->indent."If Other please specify");
        $this->addGroup($group, "informant_other_group", $this->indent."If Other please specify", null, false);

        unset($group);
        $rules_array = array("informant{@}=={@}other");
        $this->XINRegisterRule('informant_other', $rules_array, "Please specify relationship", 'informant_other_group');
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
        //Display informant rating section
        $this->form->addElement('header', 'instrument_title1', "Informant Section");       
        //Add instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>For each question, please choose an option that best describes the rated individual's behaviour <strong>over the past 6 months </strong>");

        //First block of questions
        $questions = array(
                      "q1_uncomfortable_socialsituations"     => "1. Seems much more uncomfortable in social situations than when alone",
                      "q2_wrong_facialexpressions"            => "2. Expressions on his or her face don't match what he or she is saying",
                      "q3_self_confident"                     => "3. Seems self-confident when interacting with others",
                      "q4_rigid_inflexible"                   => "4. When under stress, he or she shows rigid or inflexible patterns of behavior that seem odd",
                      "q5_others_take_advantage"              => "5. Doesn't recognize when others are trying to take advantage of him or her",
                      "q6_rather_be_alone"                    => "6. Would rather be alone than with others",
                      "q7_aware_others_feeling"               => "7. Is aware of what others are thinking or feeling",
                      "q8_behave_strange_bizarre"             => "8. Behaves in ways that seem strange or bizarre",
                      "q9_overly_dependent"                   => "9. Seems too dependent on others for help with meeting basic needs",
                      "q10_takethings_literally"              => "10. Takes things too literally, and doesn't get the real meaning of a conversation",
                      "q11_have_selfconfidence"               => "11. Has good self-confidence",
                      "q12_communicate_toothers"              => "12. Is able to communicate his or her feelings to others",
                      "q13_awkward_turn_takingtalk"           => "13. Is awkward in turn-taking interactions with others (for example, doesn't seem to understand the give-and-take of conversations)",
                      "q14_notwell_coordinated"               => "14. Is not well coordinated",
                      "q15_changefacialexp_understandmeaning" => "15. Recognizes and appropriately responds to changes in other people's tone of voice and facial expressions",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader1', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the second page of the form
     *
     * @return void
     */
    function _page2()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report (Dad's Report on Mom)");

        //Second block of questions

        $questions = array(
                      "q16_avoideyecontact"            => "16. Avoids eye contact or has unusual eye contact",
                      "q17_recognize_unfair"           => "17. Recognizes when something is unfair",
                      "q18_difficulty_makingfriends"   => "18. Has difficulty making friends, even when trying his or her best",
                      "q19_frustrated_conveyingideas" => "19. Gets frustrated trying to get ideas across in conversations",
                      "q20_unusual_interests"          => "20. Shows unusual sensory interests (for example, smelling his or her fingers frequently) or strange repetitive ways of handling or manipulating small items within reach",
                      "q21_imitate_actionsexpressions" => "21. Is able to imitate others' actions and demeanor when it is socially appropriate to do so",
                      "q22_interact_appropriately"     => "22. Interacts appropriately with other adults",
                      "q23_joingroups_activities"      => "23. Does not join group activities or social events unless forced to do so",
                      "q24_diff_changeroutine"         => "24. Has more difficulty than others with changes in his or her routine",
                      "q25_diff_wavelength"            => "25. Doesn't mind being out of step with or \"not on the same wavelength\" as others",
                      "q26_offer_comfort"              => "26. Offers comfort to others when they are sad",
                      "q27_avoid_socialinteractions"   => "27. Avoids starting social interactions with other adults",
                      "q28_think_overandover"          => "28. Thinks or talks about the same thing over and over",
                      "q29_odd_weird"                  => "29. Is regarded by others as odd or weird",
                      "q30_upset_situations"           => "30. Becomes upset in a situation with lots of things going on",
                      "q31_cant_getmind_off"           => "31. Can't get his or her mind off something once he or she starts thinking about it",
                      "q32_good_personal_hygiene"      => "32. Has good personal hygiene",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report (Dad's Report on Mom)");

        //Third block of questions
        $questions = array(
                      "q33_socially_awkward"           => "33. Is socially awkward, even when trying to be polite",
                      "q34_avoid_emotionallyclose"     => "34. Avoids people who want to be emotionally close to him or her",
                      "q35_trouble_keepingup"          => "35. Has trouble keeping up with the flow of a normal conversation",
                      "q36_difficulty_relating_family" => "36. Has difficulty relating to family members",
                      "q37_difficulty_relating_adults" => "37. Has difficulty relating to other adults",
                      "q38_respond_moodchange"         => "38. Responds appropriately to mood changes in others (for example when a friend's mood changes from happy to sad)",
                      "q39_interested_toofew_topics"   => "39. Has an unusually narrow range of interests",
                      "q40_imaginative"                => "40. Is imaginative without losing touch with reality",
                      "q41_wander_aimlessly"           => "41. Wanders aimlessly from one activity to another",
                      "q42_overly_sensitive"           => "42. Seems overly sensitive to sounds, textures, or smells",
                      "q43_enjoy_smalltalk"            => "43. Enjoys and is competent with small talk (casual conversation with others)",
                      "q44_trouble_chains_causation"    => "44. Doesn't understand how events relate to one another (cause and effect) the way other adults do",
                      "q45_pay_attention"              => "45. Generally gets interested in what others nearby are paying attention to",
                      "q46_serious_facialexp"          => "46. Has overly serious facial expressions",
                      "q47_laugh_inappropriate"       => "47. Laughs at inappropriate times",
                      "q48_goodsense_humor"            => "48. Has a sense of humor, understands jokes",
                      "q49_wellat_intellectualtasks"   => "49. Does extremely well at a few intellectual or computational tasks, but does not do as well at most other tasks",
                      "q50_repetitive_behavior"        => "50. Has repetitive, odd behaviors",
                      "q51_diff_directqstn"            => "51. Has difficulty answering questions directly and ends up talking around the subject",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the fourth page of the form
     *
     * @return void
     */
    function _page4()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report (Dad's Report on Mom)");

        //Fourth block of questions
        $questions = array(
                      "q52_overly_loud"            => "52. Knows when he or she is talking too loud or making too much noise",
                      "q53_monotone_voice"         => "53. Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture)",
                      "q54_thinkpeople_as_objects" => "54. Seems to react to people as if they are objects",
                      "q55_invade_personalspace"   => "55. Knows when he or she is too close to someone or is invading someone's space",
                      "q56_walk_btwn_people"       => "56. Walks in between two people who are talking",
                      "q57_isolate_myself"         => "57. Isolative; tends not to leave his or her home",
                      "q58_concentration_parts"    => "58. Concentrates too much on parts of things rather than seeing the whole picture",
                      "q59_suspicious_ofpeople"    => "59. Is overly suspicious",
                      "q60_emotionally_distant"    => "60. Is emotionally distant, doesn't show his or her feelings",
                      "q61_inflexible"             => "61. Is inflexible, has a hard time changing his or her mind ",
                      "q62_reason_unusual"         => "62. Gives unusual or illogical reasons for doing things",
                      "q63_greeting_unusual"       => "63. Touches or greets others in an unusual way",
                      "q64_tense_socialsituations"  => "64. Is too tense in social settings",
                      "q65_staring_gazing"         => "65. Stares or gazes off into space",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * SRS2 Special Rules
     *
     * @param array $values
     *
     * @return array
     */
    function srs2SpecialRules($values)
    {
        $errors        = array();
        $error_message = "This field should be left blank OR please change the response in the above question.";
        if (($values['informant_other'] ?? '') != '') {
            if (($values['informant'] ?? '') != 'other') {
                $errors['informant_other_group'] = $error_message;
            }
        }
        $this->ageValidator($values, 'informant_age', $errors);
        return $errors;
    }
 
    /**
     * Age validator
     *
     * @param array
     *
     * @return array
     */
    function ageValidator($array,$string, &$errors)
    {
        if (isset($array[$string])) {
            if (is_numeric($array[$string])) {
                if (intval($array[$string]) > 100 || intval($array[$string]) < 0) {
                    $errors[$string] = "Specify age between 0 and 100 or NA";
                }
            } else {
                if(strcasecmp($array[$string], "NA")) {
                    $errors[$string] = "Specify age between 0 and 100 or NA";
                }
            }
        }
    }

    /**
     * Get review
     *
     * @return void
     */
    function getReview(): string
    {
        $DB       = Database::singleton();
        $smarty   = new Smarty_neurodb();

        $tpl_data = array();

        $tpl_data['questions'] = $DB->pselect(
            "SELECT Description as question,
            SourceField FROM parameter_type 
            WHERE SourceFrom=:TN AND 
            SourceField NOT IN ('Validity', 'Administration')",
            array(
             'TN' => $this->testName,
            )
        );

        $Responses = $DB->pselectRow(
            "SELECT * FROM " . $this->testName . " WHERE CommentID=:CID",
            array('CID' => $this->getCommentID())
        );
        foreach ($tpl_data['questions'] as $key=>&$row) {
            //questions stored in the database with htmlentities should get decoded for the proper display.
                 $row['question'] =html_entity_decode($row['question']);
            if($row['SourceField'] == 'informant_other' && $Responses['informant'] != 'other') {
                unset($tpl_data['questions'][$key]);
            } else {
                $row['response'] = $Responses[$row['SourceField']];
            }

        }

        $smarty->assign($tpl_data);
        $html = $smarty->fetch("directentry_review.tpl");
        return $html;
    }
    function score(): void
    {


        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        $this->_nullScores($this->scoreCols);

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
            $score_grid_q44[$record['q44_trouble_chains_causation']],
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
            $score_grid_q21[$record['q21_imitate_actionsexpressions']],
            $score_grid_q22[$record['q22_interact_appropriately']],
            $score_grid_q26[$record['q26_offer_comfort']],
            $score_grid_q33[$record['q33_socially_awkward']],
            $score_grid_q35[$record['q35_trouble_keepingup']],
            $score_grid_q36[$record['q36_difficulty_relating_family']],
            $score_grid_q37[$record['q37_difficulty_relating_adults']],
            $score_grid_q38[$record['q38_respond_moodchange']],
            $score_grid_q41[$record['q41_wander_aimlessly']],
            $score_grid_q46[$record['q46_serious_facialexp']],
            $score_grid_q47[$record['q47_laugh_inappropriate']],
            $score_grid_q51[$record['q51_diff_directqstn']],
            $score_grid_q53[$record['q53_monotone_voice']],
            $score_grid_q55[$record['q55_invade_personalspace']],
            $score_grid_q57[$record['q57_isolate_myself']],
            $score_grid_q60[$record['q60_emotionally_distant']],
            $score_grid_q61[$record['q61_inflexible']],

        );

        $Mot_array=array(
            $score_grid_q1[$record['q1_uncomfortable_socialsituations']],
            $score_grid_q3[$record['q3_self_confident']],
            $score_grid_q6[$record['q6_rather_be_alone']],
            $score_grid_q9[$record['q9_overly_dependent']],
            $score_grid_q11[$record['q11_have_selfconfidence']],
            $score_grid_q23[$record['q23_joingroups_activities']],
            $score_grid_q27[$record['q27_avoid_socialinteractions']],
            $score_grid_q34[$record['q34_avoid_emotionallyclose']],
            $score_grid_q43[$record['q43_enjoy_smalltalk']],
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
            $score_grid_q49[$record['q49_wellat_intellectualtasks']],
            $score_grid_q50[$record['q50_repetitive_behavior']],
            $score_grid_q63[$record['q63_greeting_unusual']],


        );
        $all_response_array=array_merge($Awr_array,$Cog_array,$Com_array,$Mot_array,$RRB_array);
        $missing=0;
        foreach ($all_response_array as $val)
        {
            if($val===NULL)
            {
                $missing++;
            }
        }

        if($missing>6)
        {
            $scores['total_score']="Greater than 10% responses missing/Not Answered/Don't know; So cannot score";
            $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
            return;
        }

        //Missing values for the below questions are considered with score 1
        //1,3,6,7,11,12,15,19,21,25,26,31,38,40,43,45,52,55


        if($Mot_array[0]===NULL)
        {
            $Mot_array[0]=1;
        }
        if($Mot_array[1]===NULL)
        {
            $Mot_array[1]=1;
        }
        if($Mot_array[2]===NULL)
        {
            $Mot_array[2]=1;
        }
        if($Awr_array[1]===NULL)
        {
            $Awr_array[1]=1;
        }
        if($Mot_array[4]===NULL)
        {
            $Mot_array[4]=1;
        }
        if($Com_array[0]===NULL)
        {
            $Com_array[0]=1;
        }
        if($Cog_array[2]===NULL)
        {
            $Cog_array[2]=1;
        }
        if($Com_array[4]===NULL)
        {
            $Com_array[4]=1;
        }
        if($Com_array[5]===NULL)
        {
            $Com_array[5]=1;
        }
        if($Awr_array[2]===NULL)
        {
            $Awr_array[2]=1;
        }
        if($RRB_array[7]===NULL)
        {
            $RRB_array[7]=1;
        }
        if($Com_array[12]===NULL)
        {
            $Com_array[12]=1;
        }
        if($Cog_array[5]===NULL)
        {
            $Cog_array[5]=1;
        }
        if($Mot_array[8]===NULL)
        {
            $Mot_array[8]=1;
        }
        if($Awr_array[4]===NULL)
        {
            $Awr_array[4]=1;
        }
        if($Awr_array[5]===NULL)
        {
            $Awr_array[5]=1;
        }
        if($Com_array[18]===NULL)
        {
            $Com_array[18]=1;
        }

        $scores['Awr_score'] =$this->findRowScore($Awr_array);
        $scores['Cog_score'] =$this->findRowScore($Cog_array);
        $scores['Com_score'] =$this->findRowScore($Com_array);
        $scores['Mot_score'] =$this->findRowScore($Mot_array);
        $scores['DSM5_RRB_score'] =$this->findRowScore($RRB_array);
        $scores['DSM5_SCI_score'] = $this->findRowScore($Awr_array) +
                $this->findRowScore($Cog_array) + $this->findRowScore($Com_array) + $this->findRowScore($Mot_array);

        $scores['total_score'] = $this->findRowScore($RRB_array) + $scores['DSM5_SCI_score'];




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
                if ($field_raw_score == 0) {
                    $query_scores1 = "SELECT * FROM SRS2_SchoolAge_lookup WHERE form_relation ='SRS2_Adult' and 
                sex='M/F'  AND (scale_raw_score ='$field_raw_score'  OR  '$field_raw_score' BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                    $record_1 = $db->pselectRow($query_scores1, array());
                } else {
                    $query_scores1 = "SELECT * FROM SRS2_SchoolAge_lookup WHERE form_relation ='SRS2_Adult' and 
                sex='M/F'  AND (scale_raw_score =$field_raw_score  OR  $field_raw_score BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                    $record_1 = $db->pselectRow($query_scores1, array());

                }
                if (empty($record_1)) {
                    $max_range = "SELECT * FROM SRS2_SchoolAge_lookup WHERE form_relation ='SRS2_Adult' and 
                 sex='M/F'  AND scale_raw_score like '%>=%' AND scale='$field'";
                    $max_range_array = $db->pselectRow($max_range, array());
                    if (empty($max_range_array)) {
                        $scores[$field . '_T_score'] = "NA";
                    } else {
                        $max_number_array = explode(">=", $max_range_array['scale_raw_score']);
                        $max_number = $max_number_array[0];
                        if ($field_raw_score >= $max_number) {
                            $scores[$field . '_T_score'] = ($max_range_array['scale_T_score']);

                        }
                    }
                } else {
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

            if ($scores['total_T_score'] >= 76) {
                $scores['score_range'] = "Severe";
            } else if (in_array($scores['total_T_score'], range(66, 75))) {
                $scores['score_range'] = "Moderate";
            } else if (in_array($scores['total_T_score'], range(60, 65))) {
                $scores['score_range'] = "Mild";
            } else if ($scores['total_T_score'] <= 59) {
                $scores['score_range'] = "Normal";
            } else {
                $scores['score_range'] = "NA";

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
