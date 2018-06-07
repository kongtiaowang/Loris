<?php

/**
 * This file contains the NDB_BVL_Instrument_SRS2_1 class
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
 * Creates the form elements for the SRS2-1 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_SRS2_1 extends NDB_BVL_Instrument
{
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
                      'mother'         => 'Mother',
                      'father'         => 'Father',
                      'other_relative' => 'Other Relative',
                      'spouse'         => 'Spouse',
                      'other'          => 'Other',
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
        $this->testName = "SRS2_1";           // test_names.Test_name
        $this->table    = 'SRS2_1';

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

        if (preg_match("/SRS2_1(_page[0-9]+)/", $this->page, $matches) ) {
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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Self Report");

        //Add date of administration field
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        //Add field for Age
        $this->addBasicText('respondent_age', "Your age<BR><h5><i>(Please enter a numeric value between 0-100. If you don't wish to answer, enter NA)</i></h5>");

        //Add Special Rules
        $this->form->addFormRule(array(&$this, 'srs2SpecialRules'));

        //Add select for Sex
        $this->addSelect('respondent_gender', "Sex", $this->gender);

        //Display informant section
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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Self Report");

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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Self Report");

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
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Self Report");

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
     * Generates the fifth page of the form
     *
     * @return void
     */
    function _page5()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report");

        //Add select for Relationship to rated individual
        $this->addSelect('informant', "Relationship to rated individual", $this->informant);
        $group[] = $this->createText('informant_other', $this->indent."If Other please specify");
        $this->addGroup($group, "informant_other_group", $this->indent."If Other please specify", null, false);

        unset($group);
        $rules_array = array("informant{@}=={@}other");
        $this->XINRegisterRule('informant_other', $rules_array, "Please specify relationship", 'informant_other_group');

        //Add Special Rules
        $this->form->addFormRule(array(&$this, 'srs2SpecialRules'));
        
        //Display informant section
        $this->form->addElement('header', 'instrument_title1', "Informant Rating");

        //Add instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>For each question, please choose an option that best describes the rated individual's behavior <strong>over the past 6 months </strong>");

        //First block of questions
        $questions = array(
                      "q1i_uncomfortable_socialsituations"     => "1. Seems much more uncomfortable in social situations than when alone",
                      "q2i_wrong_facialexpressions"            => "2. Expressions on his or her face don't match what he or she is saying",
                      "q3i_self_confident"                     => "3. Seems self-confident when interacting with others",
                      "q4i_rigid_inflexible"                   => "4. When under stress, he or she shows rigid or inflexible patterns of behavior that seem odd",
                      "q5i_others_take_advantage"              => "5. Doesn't recognize when others are trying to take advantage of him or her",
                      "q6i_rather_be_alone"                    => "6. Would rather be alone than with others",
                      "q7i_aware_others_feeling"               => "7. Is aware of what others are thinking or feeling",
                      "q8i_behave_strange_bizarre"             => "8. Behaves in ways that seem strange or bizarre",
                      "q9i_overly_dependent"                   => "9. Seems too dependent on others for help with meeting basic needs",
                      "q10i_takethings_literally"              => "10. Takes things too literally, and doesn't get the real meaning of a conversation",
                      "q11i_have_selfconfidence"               => "11. Has good self-confidence",
                      "q12i_communicate_toothers"              => "12. Is able to communicate his or her feelings to others",
                      "q13i_awkward_turn_takingtalk"           => "13. Is awkward in turn-taking interactions with others (for example, doesn't seem to understand the give-and-take of conversations)",
                      "q14i_notwell_coordinated"               => "14. Is not well coordinated",
                      "q15i_changefacialexp_understandmeaning" => "15. Recognizes and appropriately responds to changes in other people's tone of voice and facial expressions",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader1', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the sixth page of the form
     *
     * @return void
     */
    function _page6()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report");

        //Second block of questions
        $questions = array(
                      "q16i_avoideyecontact"            => "16. Avoids eye contact or has unusual eye contact",
                      "q17i_recognize_unfair"           => "17. Recognizes when something is unfair",
                      "q18i_difficulty_makingfriends"   => "18. Has difficulty making friends, even when trying his or her best",
                      "q19i_frustrated_conveyingideas" => "19. Gets frustrated trying to get ideas across in conversations",
                      "q20i_unusual_interests"          => "20. Shows unusual sensory interests (for example, smelling his or her fingers frequently) or strange repetitive ways of handling or manipulating small items within reach",
                      "q21i_imitate_actionsexpressions" => "21. Is able to imitate others' actions and demeanor when it is socially appropriate to do so",
                      "q22i_interact_appropriately"     => "22. Interacts appropriately with other adults",
                      "q23i_joingroups_activities"      => "23. Does not join group activities or social events unless forced to do so",
                      "q24i_diff_changeroutine"         => "24. Has more difficulty than others with changes in his or her routine",
                      "q25i_diff_wavelength"            => "25. Doesn't mind being out of step with or \"not on the same wavelength\" as others",
                      "q26i_offer_comfort"              => "26. Offers comfort to others when they are sad",
                      "q27i_avoid_socialinteractions"   => "27. Avoids starting social interactions with other adults",
                      "q28i_think_overandover"          => "28. Thinks or talks about the same thing over and over",
                      "q29i_odd_weird"                  => "29. Is regarded by others as odd or weird",
                      "q30i_upset_situations"           => "30. Becomes upset in a situation with lots of things going on",
                      "q31i_cant_getmind_off"           => "31. Can't get his or her mind off something once he or she starts thinking about it",
                      "q32i_good_personal_hygiene"      => "32. Has good personal hygiene",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the seventh page of the form
     *
     * @return void
     */
    function _page7()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report");

        //Third block of questions
        $questions = array(
                      "q33i_socially_awkward"           => "33. Is socially awkward, even when trying to be polite",
                      "q34i_avoid_emotionallyclose"     => "34. Avoids people who want to be emotionally close to him or her",
                      "q35i_trouble_keepingup"          => "35. Has trouble keeping up with the flow of a normal conversation",
                      "q36i_difficulty_relating_family" => "36. Has difficulty relating to family members",
                      "q37i_difficulty_relating_adults" => "37. Has difficulty relating to other adults",
                      "q38i_respond_moodchange"         => "38. Responds appropriately to mood changes in others (for example when a friend's mood changes from happy to sad)",
                      "q39i_interested_toofew_topics"   => "39. Has an unusually narrow range of interests",
                      "q40i_imaginative"                => "40. Is imaginative without losing touch with reality",
                      "q41i_wander_aimlessly"           => "41. Wanders aimlessly from one activity to another",
                      "q42i_overly_sensitive"           => "42. Seems overly sensitive to sounds, textures, or smells",
                      "q43i_enjoy_smalltalk"            => "43. Enjoys and is competent with small talk (casual conversation with others)",
                      "q44i_trouble_chains_causation"    => "44. Doesn't understand how events relate to one another (cause and effect) the way other adults do",
                      "q45i_pay_attention"              => "45. Generally gets interested in what others nearby are paying attention to",
                      "q46i_serious_facialexp"          => "46. Has overly serious facial expressions",
                      "q47i_laugh_inappropriate"       => "47. Laughs at inappropriate times",
                      "q48i_goodsense_humor"            => "48. Has a sense of humor, understands jokes",
                      "q49i_wellat_intellectualtasks"   => "49. Does extremely well at a few intellectual or computational tasks, but does not do as well at most other tasks",
                      "q50i_repetitive_behavior"        => "50. Has repetitive, odd behaviors",
                      "q51i_diff_directqstn"            => "51. Has difficulty answering questions directly and ends up talking around the subject",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        //Add copyright message
        $this->form->addElement('static', 'lorisSubHeader', "<h4>SRS-2 copyright © 2012 by Western Psychological Services. Reprint authorized by the author, J. Constantino, under WPS agreement for the sole use in registered scholarly study. Not to be reprinted in whole or in part, for any additional purpose, without the prior written authorization of WPS. All rights reserved. (rights@wpspublish.com)</h4>");

    }

    /**
     * Generates the eighth page of the form
     *
     * @return void
     */
    function _page8()
    {
        //Display test name
        $this->form->addElement('header', 'instrument_title', "SRS-2 - Informant Report");

        //Fourth block of questions
        $questions = array(
                      "q52i_overly_loud"            => "52. Knows when he or she is talking too loud or making too much noise",
                      "q53i_monotone_voice"         => "53. Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture)",
                      "q54i_thinkpeople_as_objects" => "54. Seems to react to people as if they are objects",
                      "q55i_invade_personalspace"   => "55. Knows when he or she is too close to someone or is invading someone's space",
                      "q56i_walk_btwn_people"       => "56. Walks in between two people who are talking",
                      "q57i_isolate_myself"         => "57. Isolative; tends not to leave his or her home",
                      "q58i_concentration_parts"    => "58. Concentrates too much on parts of things rather than seeing the whole picture",
                      "q59i_suspicious_ofpeople"    => "59. Is overly suspicious",
                      "q60i_emotionally_distant"    => "60. Is emotionally distant, doesn't show his or her feelings",
                      "q61i_inflexible"             => "61. Is inflexible, has a hard time changing his or her mind ",
                      "q62i_reason_unusual"         => "62. Gives unusual or illogical reasons for doing things",
                      "q63i_greeting_unusual"       => "63. Touches or greets others in an unusual way",
                      "q64i_tense_socialsituations"  => "64. Is too tense in social settings",
                      "q65i_staring_gazing"         => "65. Stares or gazes off into space",
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
