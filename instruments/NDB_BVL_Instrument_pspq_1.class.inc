<?php

/**
*This file contains the NDB_BVL_Instrument_pspq_1(Send to Mom) class
*
* PHP Version 5
*
* @category Instrument
* @package  Neuropsych
* @author   Rathi Sekaran <https://github.com/rathisekaran>
* @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
* @link     https://www.github.com/aces/IBIS/
*/

/**
* Creates the form elements for the NDB_BVL_Instrument_pspq_1 instrument
*
* @category Instrument
* @package  Neuropsych
* @author   Rathi Sekaran <https://github.com/rathisekaran>
* @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
* @link     https://www.github.com/aces/IBIS/
*/

class NDB_BVL_Instrument_pspq_1 extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    use instrument_validator;

    // DECLARE GLOBAL VARIABLES

    //Commonly used level of indentation;
    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    //Variables for radio button options
    var $rating = array(
                   ''                 => null,
                   '1_very_rarely'    => "1. Very Rarely",
                   '2_rarely'         => "2. Rarely",
                   '3_occasionally'   => "3. Occasionally",
                   '4_somewhat_often' => '4. Somewhat Often',
                   '5_often'          => '5. Often',
                   '6_very_often'     => '6. Very Often',
                  );
    var $relationship_child     = array(
                                   ''           => null,
                                   'mother'     => '(Biological) Mother',
                                   'father'     => '(Biological) Father',
                                   'stepmother' => 'Step-Mother',
                                   'stepfather' => 'Step-Father',
                                   'other'      => 'Other',
                                  );
    var $informant_relationship = array(
                                   ''       => null,
                                   'spouse' => 'Spouse or partner',
                                   'other'  => 'Other',
                                  );
    var $informant_confidence   = array(
                                   ''                     => null,
                                   'extremely_confident'  => 'Extremely confident',
                                   'very_confident'       => 'Very confident',
                                   'moderately_confident' => 'Moderately Confident',
                                   'little_confident'     => 'A little confident',
                                   'not_confident'        => 'Not at all confident',
                                  );


    // Abstract function setup(?string $commentID = NULL, ?string $page = NULL): void;
    /**
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
        $this->formType = "XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label

        // set the object properties
        $this->testName = "pspq_1";           // test_names.Test_name
        $this->table    = 'pspq_1';

        // data keyed by commentID
        $this->commentID = $commentID;

        $config            =& NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );

        // setup the form
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

        if (preg_match("/pspq_1(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->form->addElement('header', 'instrument_title', "PSPQ : Personality Styles and Preferences Questionnaire (Send To Mom)");

        // Add date of administration question
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        // Instructions
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>Thank you for filling out this questionnaire. The questions you will be answering are about personality, habits, and lifestyle. There are no good or bad responses, just differences in people's preferences.<BR><BR>1. Many of these questions ask about your interactions with other people. Think about the way you are with most people, rather than the way you are in special relationships you may have with your spouse, significant other, children, siblings and parents.<BR><BR>2. Everyone changes over time, which can make it hard to fill out questions about personality. Think about the way you've been most of your adult life, rather than the way you were as a teenager, or times you may have felt differently from normal.<BR><BR>3. You must answer each question and give only one answer per question. Choose the answer that best describes how often that statement applies to you. If you are confused about a question, please give it your best guess.<BR><BR>For each question, you will be given a choice of 6 answers that describe how often the statement applies to you:<BR> 1. Very Rarely<BR>2. Rarely<BR>3. Occasionally<BR>4. Somewhat Often<BR>5. Often<BR> 6. Very Often<BR><BR>Choose the number that matches the answer that comes closest to how you feel about each statement.");

        // Indicate the name of the section
        $this->form->addElement('header', 'instrument_title1', "Self Rating");

        // Add field for respondent's age
        $this->addBasicText("respondent_age", "Your age<BR><h5><i>(Please enter a numeric value between 0-100. If you don't wish to answer, enter NA)</i></h5>");

        // Add field for respondent's relationship to child
        $this->addSelect('respondent', "Your relationship to child", $this->relationship_child);
        $group[] = $this->createText('respondent_other', $this->indent."If other please specify");
        $this->addGroup($group, "respondent_other_group", $this->indent."If other please specify", null, false);
        unset($group);
        $rules_array = array("respondent{@}=={@}other");
        $this->XINRegisterRule('respondent_other', $rules_array, "Please specify relationship", 'respondent_other_group');

        // First group of questions
        $this->form->addElement('static', null, "<br /><br />");
        $questions = array(
                      "q1_like_being_otherpeople"        => "1. I like being around other people",
                      "q2_hard_wordsout_smoothly"        => "2. I find it hard to get my words out smoothly",
                      "q3_comfortable_unexpectedchanges" => "3. I am comfortable with unexpected changes in plans",
                      "q4_hard_avoid_sidetrack"          => "4. It's hard for me to avoid getting sidetracked in conversations",
                      "q5_information_than_socialize"    => "5. I would rather talk to people to get information than to socialize",
                      "q6_talkinto_tryingnew"            => "6. People have to talk me into trying something new",
                      "q7_intune_conversation"           => "7. I am 'in-tune' with the other person during conversation",
                      "q8_warmup_unfamiliarplace"        => "8. I have to warm myself up to the idea of visiting an unfamiliar place",
                      "q9_enjoy_socialsituations"        => "9. I enjoy being in social situations",
                      "q10_voice_flat_monotone"          => "10. My voice has a flat or monotone sound to it",
                      "q11_disconnected_outofsync_convo" => "11. I feel disconnected or 'out of sync' in conversations with others",
                      "q12_easy_approach"                => "12. People find it easy to approach me",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

        // Validate text fields using instrument validator class
        $this->form->addFormRule(array(&$this, 'validate_page1'));

    }

    /**
     * Generates the second page of the form.
     *
     * @return void
     * @access private
     */
    function _page2()
    {

        // Display test name, and the name of the section
        $this->form->addElement('header', 'instrument_title', "PSPQ : Personality Styles and Preferences Questionnaire (Send To Mom)");
        $this->form->addElement('header', 'instrument_title1', "Self Rating");

        // Second group of questions
        $questions = array(
                      "q13_strongneed_sameness"         => "13. I feel a strong need for sameness from day to day",
                      "q14_others_dont_understand"      => "14. People ask me to repeat things I've said because they don't understand",
                      "q15_flexible"                    => "15. I am flexible about how things should be done",
                      "q16_situations_meetnew_people"   => "16. I look forward to situations where I can meet new people",
                      "q17_talktoomuch_certain_topics"  => "17. I have been told that I talk too much about certain topics",
                      "q18_conversation_tobe_polite"    => "18. When I make conversation it is just to be polite",
                      "q19_lookforward_newthings"       => "19. I look forward to trying new things",
                      "q20_speak_tooloud_softly"        => "20. I speak too loudly or softly",
                      "q21_tell_someone_not_interested" => "21. I can tell when someone is not interested in what I am saying",
                      "q22_hardtime_change_routine"     => "22. I have a hard time dealing with changes in my routine",
                      "q23_good_smalltalk"              => "23. I am good at making small talk",
                      "q24_act_myways"                  => "24. I act very set in my ways",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);

        }

    }

    /**
     * Generates the third page of the form.
     *
     * @return void
     * @access private
     */
    function _page3()
    {

        // Display test name, and the name of the section
        $this->form->addElement('header', 'instrument_title', "PSPQ : Personality Styles and Preferences Questionnaire (Send To Mom)");
        $this->form->addElement('header', 'instrument_title1', "Self Rating");

        // Third group of questions
        $questions = array(
                      "q25_connecting_people"           => "25. I feel like I am really connecting with other people",
                      "q26_peoplefrustrated"            => "26. People get frustrated by my unwillingness to bend",
                      "q27_conversation_boresme"        => "27. Conversation bores me",
                      "q28_warmfriendly_others"         => "28. I am warm and friendly in my interactions with others",
                      "q29_longpauses_conversations"    => "29. I leave long pauses in conversations",
                      "q30_alter_dailyroutine"          => "30. I alter my daily routine by trying something different",
                      "q31_alone_ratherthan_withothers" => "31. I prefer to be alone rather than with others",
                      "q32_losetrack_talking"           => "32. I lose track of my original point when talking to people",
                      "q33_follow_routine"              => "33. I like to closely follow a routine while working",
                      "q34_change_topic"                => "34. I can tell when it is time to change topics in conversation",
                      "q35_doingthings_knownway"        => "35. I keep doing things the way I know, even if another way might be better",
                      "q36_enjoy_chatting"              => "36. I enjoy chatting with people",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
        }

    }

    /**
     * Generates the fourth page of the form.
     *
     * @return void
     * @access private
     */
    function _page4()
    {
        // Display test name
        $this->form->addElement('header', 'instrument_title', "PSPQ : Personality Styles and Preferences Questionnaire (Send To Mom)");

        // Indicate section
        $this->form->addElement('header', 'instrument_title1', "*OBSERVER RATING SECTION IS ABOUT YOUR SPOUSE OR PARTNER*If you do not have a partner you may skip this section.");

        // Instructions for observer rating section
        $this->form->addElement('static', 'lorisSubHeader', "<BR><strong>Instructions:</strong><BR>In this section you will fill out a series of statements related to the personality and lifestyle of your spouse or partner. We will refer to this person as your partner. These sorts of observer ratings help us obtain a more well-rounded measure of your partner’s personality and lifestyle, since some traits and behaviors are most easily observed by other people. <BR><BR>For each question, circle the answer that best describes how often the statement applies to your partner’s behavior. So, if they watch the evening news once a week, you might circle #4: <i>Somewhat often.</i> <BR><BR><BR><strong>3 IMPORTANT THINGS TO REMEMBER</strong><BR><BR>#1. Many of these questions ask about your partner’s interactions with other people. Please think about the way they are with most people rather than special relationships they may have with their children, siblings, and parents.<BR><BR>#2. Everyone changes over time, which can make it hard to fill out questions about personality. Think about the way your partner has been the majority of their adult life, rather than the way they were as a teenager, or times they many have felt different than normal.<BR><BR>#3. You must answer each question, and give only one answer per question. If you are confused, please just give your best guess.<BR><BR>");

        $this->addSelect('informant_confidence', "<BR>How confident do you feel about your ability to give an accurate report on the <BR>personality traits and behaviors of your partner?", $this->informant_confidence);
        $this->XINRegisterRule('informant_confidence', array("informant_confidence{@}=={@}NEVER_REQUIRED"));

        $this->form->addElement('header', 'instrument_title2', "Observer Rating");

        // Add select for respondent's relationship to partner
        $this->addSelect('informant', "Your relationship to your partner", $this->informant_relationship);
        $group[] = $this->createText('informant_other', $this->indent."If Other please specify");
        $this->addGroup($group, "informant_other_group", $this->indent."If Other please specify", null, false);
        unset($group);
        $rules_array = array("informant{@}=={@}other");
        $this->XINRegisterRule('informant_other', $rules_array, "Please specify relationship", 'informant_other_group');
        // This question is optional as the repsondent may be single
        $this->XINRegisterRule('informant', array("informant{@}=={@}NEVER_REQUIRED"));

        // Add select for partner's relationship to child
        $this->addSelect('informant_child', "Your partner’s relationship to child", $this->relationship_child);
        $group[] = $this->createText('informant_child_other', $this->indent."If Other please specify");
        $this->addGroup($group, "informant_child_other_group", $this->indent."If Other please specify", null, false);
        unset($group);
        $rules_array = array("informant_child{@}=={@}other");
        $this->XINRegisterRule('informant_child_other', $rules_array, "Please specify relationship", 'informant_child_other_group');
        // This question is optional as the repsondent may be single
        $this->XINRegisterRule('informant_child', array("informant_child{@}=={@}NEVER_REQUIRED"));

        // Fourth group of questions
        $this->form->addElement('static', null, "<br /><br />");
        $questions = array(
                      "qi1_like_being_otherpeople"        => "1. He/She likes being around other people",
                      "qi2_hard_wordsout_smoothly"        => "2. He/She finds it hard to get his/her words out smoothly",
                      "qi3_comfortable_unexpectedchanges" => "3. He/She is comfortable with unexpected changes in plans",
                      "qi4_hard_avoid_sidetrack"          => "4. It's hard for him/her to avoid getting sidetracked in conversations",
                      "qi5_information_than_socialize"    => "5. He/She would rather talk to people to get information than to socialize",
                      "qi6_talkinto_tryingnew"            => "6. People have to talk him/her into trying something new",
                      "qi7_intune_conversation"           => "7. He/She is 'in-tune' with the other person during conversation",
                      "qi8_warmup_unfamiliarplace"        => "8. He/She has to warm himself/herself up to the idea of visiting an unfamiliar place",
                      "qi9_enjoy_socialsituations"        => "9. He/She enjoys being in social situations",
                      "qi10_voice_flat_monotone"          => "10. His/Her voice has a flat or monotone sound to it",
                      "qi11_disconnected_outofsync_convo" => "11. He/She feels disconnected or 'out of sync' in conversations with others",
                      "qi12_easy_approach"                => "12. People find it easy to approach him/her",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);

            // These questions are optional, as the informant may be single
            $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"));
        }

        // Validate text fields using instrument validator class
        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    /**
     * Generates the fifth page of the form.
     *
     * @return void
     * @access private
     */
    function _page5()
    {

        // Display test name
        $this->form->addElement('header', 'instrument_title', "PSPQ : Personality Styles and Preferences Questionnaire (Send To Mom)");

        // Indicate section
        $this->form->addElement('header', 'instrument_title1', "Observer Rating");

        // Fifth group of questions
        $questions = array(
                      "qi13_strongneed_sameness"         => "13. He/She feels a strong need for sameness from day to day",
                      "qi14_others_dont_understand"      => "14. People ask him/her to repeat things he/she has said because they don't understand",
                      "qi15_flexible"                    => "15. He/She is flexible about how things should be done",
                      "qi16_situations_meetnew_people"   => "16. He/She looks forward to situations where he/she can meet new people",
                      "qi17_talktoomuch_certain_topics"  => "17. He/She has been told that he/she talks too much about certain topics",
                      "qi18_conversation_tobe_polite"    => "18. When he/she makes conversation it is just to be polite",
                      "qi19_lookforward_newthings"       => "19. He/She looks forward to trying new things",
                      "qi20_speak_tooloud_softly"        => "20. He/She speaks too loudly or softly",
                      "qi21_tell_someone_not_interested" => "21. He/She can tell when someone is not interested in what he/she is saying",
                      "qi22_hardtime_change_routine"     => "22. He/She has a hard time dealing with changes in his/her routine",
                      "qi23_good_smalltalk"              => "23. He/She is good at making small talk",
                      "qi24_act_myways"                  => "24. He/She acts very set in his/her ways",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);

            // These questions are optional, as the informant may be single
            $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"));
        }
    }

    /**
     * Generates the sixth page of the form.
     *
     * @return void
     * @access private
     */
    function _page6()
    {

        // Display test name
        $this->form->addElement('header', 'instrument_title', "PSPQ : Personality Styles and Preferences Questionnaire (Send To Mom)");

        // Indicate section
        $this->form->addElement('header', 'instrument_title1', "Observer Rating");

        // Sixth group of questions
        $questions = array(
                      "qi25_connecting_people"           => "25. He/She feels like he/she is really connecting with other people",
                      "qi26_peoplefrustrated"            => "26. People get frustrated by his/her unwillingness to bend",
                      "qi27_conversation_boresme"        => "27. Conversation bores him/her",
                      "qi28_warmfriendly_others"         => "28. He/She is warm and friendly in his/her interactions with others",
                      "qi29_longpauses_conversations"    => "29. He/She leaves long pauses in conversations",
                      "qi30_alter_dailyroutine"          => "30. He/She alters his/her daily routine by trying something different",
                      "qi31_alone_ratherthan_withothers" => "31. He/She prefers to be alone rather than with others",
                      "qi32_losetrack_talking"           => "32. He/She loses track of his/her original point when talking to people",
                      "qi33_follow_routine"              => "33. He/She likes to closely follow a routine while working",
                      "qi34_change_topic"                => "34. He/She can tell when it is time to change topics in conversation",
                      "qi35_doingthings_knownway"        => "35. He/She keeps doing things the way he/she knows, even if another way might be better",
                      "qi36_enjoy_chatting"              => "36. He/She enjoys chatting with people",
                     );

        foreach ($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);

            // These questions are optional, as the informant may be single
            $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"));
        }

        // Add option field for any other comments
        $this->addBasicTextArea('comments', "Do you have any other comments?");
        $this->XINRegisterRule('comments', array('comments_informant{@}=={@}NEVER_REQUIRED'));
    }

    /**
     * Validates the text fields on page 1 using the instrument validator class
     *
     * @param array $values user responses to all questions
     *
     * @return array
     */
    function validate_page1($values)
    {

        $errors = [];
        $this->validate_age($values, "respondent_age", $errors);
        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_other"], $errors);
        }

        return $errors;

    }

    /**
     * Validates the text fields on page 4 using the instrument validator class
     *
     * @param array $values user responses to all questions
     *
     * @return array
     */
    function validate_page4($values)
    {

        $errors = [];
        if ($values["informant"] != "other") {
            $this->validate_empty_subquestions($values, ["informant_other"], $errors);
        }
        if ($values["informant_child"] != "other") {
            $this->validate_empty_subquestions($values, ["informant_child_other"], $errors);
        }

        return $errors;

    }

}

?>