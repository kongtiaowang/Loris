<?php

/**
 * This file contains the NDB_BVL_Instrument_SRS2_SelfReport for Dad
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
 * Creates the form elements for the SRS2 Self Report instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_SRS2_SelfReport_Dad extends NDB_BVL_Instrument
{
    //Commonly used level of indentation;
    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    var $rating = array(
                   ''                     => null,
                   '1_not_true'           => '1. Not True',
                   '2_sometimes_true'     => '2. Sometimes True',
                   '3_often_true'         => '3. Often True',
                   '4_almost_always_true' => '4. Almost Always True',
                   'refused_dontknow'     => 'Refused/I Don\'t Know',
                  );

    var $gender = array(
                   ''       => null,
                   'male'   => 'Male',
                   'female' => 'Female',
                   'other'  => 'Other',
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
        $this->page     = $page;            // Page label

        // Set the object properties
        $this->testName = "SRS2_SelfReport_Dad";           // test_names.Test_name
        $this->table    = 'SRS2_SelfReport_Dad';

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

        if(preg_match("/SRS2_SelfReport_Dad(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
       // $this->form->addFormRule(array(&$this, 'XINValidate'));
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
        $this->form->addElement('header', 'instrument_title', "SRS2 Dad Self Report");

        //Add date of administration field
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        //Add field for Age
        $this->addBasicText('respondent_age', "Your age<BR><h5><i>(Please enter a numeric value between 0-100. If you don't wish to answer, enter NA)</i></h5>");

        //Add Special Rules
       // $this->form->addFormRule(array(&$this, 'srs2SpecialRules'));

        //Add select for Sex
        $this->addSelect('respondent_gender', "Sex", $this->gender);

        //Display self rating section
        $this->form->addElement('header', 'instrument_title1', "Self Rating");

        //Add instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>For each question, please choose an option that best describes your behavior <strong>over the past 6 months </strong>");

        //First block of questions
        $questions = array(
                      "q1_uncomfortable_socialsituations"     => "1. I am much more uncomfortable in social situations than when I am by myself",
                      "q2_wrong_facialexpressions"            => "2. My facial expressions send the wrong message to others about how I actually feel",
                      "q3_self_confident"                     => "3. I feel self-confident when interacting with others",
                      "q4_rigid_inflexible"                   => "4. When under stress, I engage in rigid or inflexible patterns of behavior that seem odd to people",
                      "q5_others_take_advantage"              => "5. I do not recognize when others are trying to take advantage of me",
                      "q6_rather_be_alone"                    => "6. I would rather be alone than with others",
                      "q7_aware_others_feeling"               => "7. I am usually aware of how others are feeling",
                      "q8_behave_strange_bizarre"             => "8. I behave in ways that seem strange or bizarre to others",
                      "q9_overly_dependent"                   => "9. I am overly dependent on others for help with meeting my everyday needs",
                      "q10_takethings_literally"              => "10. I take things too literally, and because of that, I misinterpret the intended meaning of parts of a conversation",
                      "q11_have_selfconfidence"               => "11. I have good self-confidence",
                      "q12_communicate_toothers"              => "12. I am unable to communicate my feelings to others",
                      "q13_awkward_turn_takingtalk"           => "13. I am awkward in turn-taking interactions with others (for example, I have a hard time keeping up with the give-and-take of a conversation)",
                      "q14_notwell_coordinated"               => "14. I am not well coordinated",
                      "q15_changefacialexp_understandmeaning" => "15. When people change their tone or facial expression, I usually pick up on that and understand what it means",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader1', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates second page of form
     *
     * @return void
     */
    function _page2()
    {

        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS2 Dad Self Report");

        //Second block of questions
        $questions = array(
                      "q16_avoideyecontact"            => "16. I avoid eye contact or am told that I have unusual eye contact",
                      "q17_recognize_unfair"           => "17. I recognize when something is unfair",
                      "q18_difficulty_makingfriends"   => "18. I have difficulty making friends, even when trying my best",
                      "q19_frustrated_conveyingideas" => "19. I get frustrated trying to get ideas across in conversations",
                      "q20_unusual_interests"          => "20. I have sensory interests that others find unusual (for example, smelling or looking at things in a special way)",
                      "q21_imitate_actionsexpressions" => "21. I am able to imitate others' actions and expressions when it is socially appropriate to do so",
                      "q22_interact_appropriately"     => "22. I interact appropriately with other adults",
                      "q23_joingroups_activities"      => "23. I do not join group activities or social events unless prompted or strongly urged to do so",
                      "q24_diff_changeroutine"         => "24. I have more difficulty than others with changes in my routine",
                      "q25_diff_wavelength"            => "25. I do not mind being out of step with or \"not on the same wavelength\" as others",
                      "q26_offer_comfort"              => "26. I offer comfort to others when they are sad",
                      "q27_avoid_socialinteractions"   => "27. I avoid starting social interactions with other adults",
                      "q28_think_overandover"          => "28. I think or talk about the same thing over and over",
                      "q29_odd_weird"                  => "29. I am regarded by others as odd or weird",
                      "q30_upset_situations"           => "30. I become upset in situations with lots of things going on",
                      "q31_cant_getmind_off"           => "31. I can't get my mind off something once I start thinking about it",
                      "q32_good_personal_hygiene"      => "32. I have good personal hygiene",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);

        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates third page of the form
     *
     * @return void
     */
    function _page3()
    {

        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS2 Dad Self Report");

        //Third block of questions
        $questions = array(
                      "q33_socially_awkward"           => "33. My behavior is socially awkward, even when trying to be polite",
                      "q34_avoid_emotionallyclose"     => "34. I avoid people who want to be emotionally close to me",
                      "q35_trouble_keepingup"          => "35. I have trouble keeping up with the flow of a normal conversation",
                      "q36_difficulty_relating_family" => "36. I have difficulty relating to family members",
                      "q37_difficulty_relating_adults" => "37. I have difficulty relating to adults outside of my family",
                      "q38_respond_moodchange"         => "38. I respond appropriately to mood changes in others (for example when a friend's mood changes from happy to sad)",
                      "q39_interested_toofew_topics"   => "39. People think I am interested in too few topics, or that I get too carried away with those topics",
                      "q40_imaginative"                => "40. I am imaginative",
                      "q41_wander_aimlessly"           => "41. I sometimes seem to wander aimlessly from one activity to another",
                      "q42_overly_sensitive"           => "42. I am overly sensitive to certain sounds, textures, or smells",
                      "q43_enjoy_smalltalk"            => "43. I enjoy small talk (casual conversation with others)",
                      "q44_trouble_chains_causation"    => "44. I have more trouble than most people with understanding chains of causation (in other words, how events are related to one another)",
                      "q45_pay_attention"              => "45. When others around me are paying attention to something, I get interested in what they are attending to",
                      "q46_serious_facialexp"          => "46. Others feel that I have overly serious facial expressions",
                      "q47_laugh_inappropriate"       => "47. I laugh at inappropriate times",
                      "q48_goodsense_humor"            => "48. I have a good sense of humor and can understand jokes",
                      "q49_wellat_intellectualtasks"   => "49. I do extremely well at certain kinds of intellectual tasks, but do not do as well at most other tasks",
                      "q50_repetitive_behavior"        => "50. I have repetitive behaviors that others consider odd",
                      "q51_diff_directqstn"            => "51. I have difficulty answering questions directly and end up talking around the subject",
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
        $this->form->addElement('header', 'instrument_title', "SRS2 Dad Self Report");

        //Fourth block of questions
        $questions = array(
                      "q52_overly_loud"            => "52. I get overly loud without realizing it",
                      "q53_monotone_voice"         => "53. I tend to talk in a monotone voice (in other words, less inflection of voice than most people demonstrate)",
                      "q54_thinkpeople_as_objects" => "54. I tend to think about people in the same way that I do objects",
                      "q55_invade_personalspace"   => "55. I get too close to others or invade their personal space without realizing it",
                      "q56_walk_btwn_people"       => "56. I sometimes make the mistake of walking between two people who are trying to talk to one another",
                      "q57_isolate_myself"         => "57. I tend to isolate myself",
                      "q58_concentration_parts"    => "58. I concentrate too much on parts of things than seeing the whole picture",
                      "q59_suspicious_ofpeople"    => "59. I am more suspicious than most people",
                      "q60_emotionally_distant"    => "60. Other people think I am emotionally distant and do not show my feelings",
                      "q61_inflexible"             => "61. I tend to be inflexible",
                      "q62_reason_unusual"         => "62. When I tell someone my reason for doing something, it strikes the person as unusual or illogical",
                      "q63_greeting_unusual"       => "63. My way of greeting another person is unusual",
                      "q64_tense_socialsituations"  => "64. I am much more tense in social settings than when I am by myself",
                      "q65_staring_gazing"         => "65. I find myself staring or gazing off into space",
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
        //if (($values['informant_other'] ?? '') != '') {
          //if (($values['informant'] ?? '') != 'other') {
            //$errors['informant_other_group'] = $error_message
          //}
        //}
        $this->ageValidator($values, 'respondent_age', $errors);
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
    function getReview()
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


}
?>
