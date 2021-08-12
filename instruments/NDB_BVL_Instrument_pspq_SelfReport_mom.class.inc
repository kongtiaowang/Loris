<?php

class NDB_BVL_Instrument_pspq_SelfReport_mom extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
                        "aloof_score",
                        "prs_score",
                        "rigid_score",
                        "total_score",
                       );

    //Commonly used level of indentation;
    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    var $rating = array(
                   ''                 => null,
                   '1_very_rarely'    => "1. Very Rarely",
                   '2_rarely'         => "2. Rarely",
                   '3_occasionally'   => "3. Occasionally",
                   '4_somewhat_often' => '4. Somewhat Often',
                   '5_often'          => '5. Often',
                   '6_very_often'     => '6. Very Often',
                  );

    var $rating_na = array(
                      ''                 => null,
                      '1_very_rarely'    => "1. Very Rarely",
                      '2_rarely'         => "2. Rarely",
                      '3_occasionally'   => "3. Occasionally",
                      '4_somewhat_often' => '4. Somewhat Often',
                      '5_often'          => '5. Often',
                      '6_very_often'     => '6. Very Often',
                      'na'               => 'Not Applicable',
                     );


    var $informant = array(
                      ''       => null,
                      'spouse' => 'Spouse',
                      'other'  => 'Other',
                     );

    var $informant_confidence = array(
                                 ''                     => null,
                                 'extremely_confident'  => 'Extremely confident',
                                 'very_confident'       => 'Very confident',
                                 'moderately_confident' => 'Moderately Confident',
                                 'little_confident'     => 'A little confident',
                                 'not_confident'        => 'Not at all confident',
                                );

    var $gender = array(
                   ''       => null,
                   'female' => 'Female',
                  );

    //abstract function setup($commentID, $page);
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or

        // set the object properties
        $this->testName = "pspq_SelfReport_mom";           // test_names.Test_name
        $this->table    = 'pspq_SelfReport_mom';

        // data keyed by commentID
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

        // setup the form
        $this->_setupForm();
    }

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/pspq_SelfReport_mom(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // display test name
        $this->form->addElement('header', 'instrument_title_1', "PSPQ: Personality Styles and Preferences Questionnaire - Self Report Mom (Send To Mom)");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        // $this->addNumericElement('respondent_age','Your Age <BR>(Please indicate your age in years)');
        $field = 'respondent_age';$label = 'Your Age <BR>(Please indicate your age in years)';
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));
        
	$label = "Please click this bubble 'Yes' to confirm that you are the enrolled child’s biological mother, reporting on yourself.";

        $this->form->addElement(
            'select',
            'respondent',
            $label,
            array(
             null       => '',
             'Yes'      => 'Yes'
            )
        );

        $this->addSelect('respondent_gender', "Your gender", $this->gender);
        $this->XINRegisterRule('respondent_gender', array("respondent_gender{@}=={@}NEVER_REQUIRED"));

        // SCORING TABLE

        $this->form->addElement('header', 'score', "Score Summary");

        $group[] = $this->form->createElement('static', "score", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   "aloof" => "Aloof",
                   "prs"   => "Pragmatic Language (PRS)",
                   "rigid" => "Rigid",
                   "total" => "Total",
                  );

        $columnHeaders = array("score" => "Score");

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$field}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }
    }

    /**
     * Generates the first page of the form
     *
     * @return void
     */
    function _page1()
    {
        $this->form->addElement('header', 'instrument_title_2', "PSPQ: Personality Styles and Preferences Questionnaire Page 2 - Self Report Mom (Send To Mom)");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Instructions:</strong>
            <BR><BR>
            Thank you for filling out this questionnaire. The questions you will be answering are about personality,
            habits, and lifestyle. There are no good or bad responses, just differences in people's preferences.
            <BR><BR>
            1. Many of these questions ask about your interactions with other people. <strong>Think about the way you
            are with <i>most</i> people, rather than the way you are in special relationships </strong>you may have
            with your spouse, significant other, children, siblings and parents.
            <BR><BR>
            2. Everyone changes over time, which can make it hard to fill out questions about personality.
            <strong>Think about the way you've been most of your adult life,</strong>
            rather than the way you were as a teenager,or times you many have felt differently from normal.
            <BR><BR>
            3.<strong> You must answer each question</strong> and give only one answer per question. Choose the answer that
            best describes how often that statement applies to you. If you are confused about a question, please give it your best guess.
            <BR><BR>
            For each question, you will be given a choice of 6 answers that describe how often the statement applies to you:
            <BR><BR>
            1.Very Rarely<BR>2.Rarely<BR>3.Occasionally<BR>4.Somewhat Often<BR>5.Often<BR>6.Very Often
            <BR><BR>
            Choose the number that matches the answer that comes closest to how you feel about each statement."
        );

        $this->form->addElement('header', 'instrument_title_3', "Self Rating");

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
            if ($field=='q4_hard_avoid_sidetrack') {
                $this->addSelect($field, $label, $this->rating_na);
            } else {
                $this->addSelect($field, $label, $this->rating);
            }
        }

        // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
    }

    /**
     * Generates the second page of the form
     *
     * @return void
     */
    function _page2()
    {
        $this->form->addElement('header', 'instrument_title_4', "PSPQ: Personality Styles and Preferences Questionnaire Page 2 - Self Report Mom (Send To Mom)");
        $this->form->addElement('header', 'instrument_title_5', "Self Rating");

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

        //  $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
    }

    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3()
    {
         $this->form->addElement('header', 'instrument_title_6', "PSPQ : Personality Styles and Preferences Questionnaire Page 3 - Self Report Mom (Send To Mom)");
         $this->form->addElement('header', 'instrument_title_7', "Self Rating");

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
            if ($field=='q25_connecting_people'|| $field=='q29_longpauses_conversations') {
                $this->addSelect($field, $label, $this->rating_na);
            } else {
                $this->addSelect($field, $label, $this->rating);
            }
        }

        // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
    }

    function PSPQ_Rules($values)
    {
        // commenting out the warnings
         $errors    = array();
         $DB        = Database::singleton();
         $questions = array();
         $questions = $DB->pselect(
             "SELECT Description as question,
            SourceField FROM parameter_type
            WHERE SourceFrom=:TN AND
            SourceField NOT IN ('Validity', 'Administration')",
             array(
              'TN' => $this->testName,
             )
         );
         $list_questions = array();
        foreach ($values as $key=>$val) {
            if (empty($val)) {
                foreach ($questions as $row) {
                    if ($row['SourceField'] == $key) {
                        // $q_display = $row['question'];break;
                        $list_questions[$key] = $row['question'];
                    }
                }
            }
        }
        foreach ($list_questions as $key=>$row) {
            if ($key == 'respondent_other' && $questions['respondent'] != 'other') {
                unset($list_questions[$key]);
            } elseif (empty($row) ) {
                unset($list_questions[$key]);
            }
        }
        if (isset($_GET["key"])) {
              $url_key = $_GET["key"];
        }

        if (isset($_GET["pageNum"])) {
             $page = $_GET["pageNum"];
            if ($page == 'top') {
                  $page_verbose = 1;
            } else {
                    $page_verbose = $page +1;
            }
                $goback_url = "survey.php?key=$url_key&pageNum=$page";
        }

        if (!empty($list_questions)) {
              setcookie("MissingResponses", "", time()-3600);
              $value = "<font color='Red'>Note: You have missed a few questions on the previous page :</font> <BR><BR>";
            foreach ($list_questions as $key=>$question) {
                    $value .= $question."<BR><BR>";
            }
                setcookie("MissingResponses", $value);
                setCookie("PrevPage", $page);
                setCookie("URLKey", $url_key);
        }

        if (intval($values['respondent_age']) > 100) {
               $errors['respondent_age_group'] = "Specify age between 0 and 100";
        }

        return $errors;
    }

    function sumSubscaleScores($question_array, $record)
    {
        $sum = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "1_very_rarely") {
                $sum++;
            } elseif ($record[$q] == "2_rarely") {
                $sum += 2;
            } elseif ($record[$q] == "3_occasionally") {
                $sum += 3;
            } elseif ($record[$q] == "4_somewhat_often") {
                $sum += 4;
            } elseif ($record[$q] == "5_often") {
                $sum += 5;
            } elseif ($record[$q] == "6_very_often") {
                $sum += 6;
            } else {
                return null;
            }
        }

        return $sum;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // Null scores
        $this->_nullScores($this->scoreLabels);

        // Get the saved scores
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());

        $scores = array(
                   "aloof_score" => null,
                   "prs_score"   => null,
                   "rigid_score" => null,
                   "total_score" => null,
                  );

        // Reverse score items
        foreach (self::REVERSE as $r) {
            if ($record[$r] == "1_very_rarely") {
                $record[$r] = "6_very_often";
            } elseif ($record[$r] == "2_rarely") {
                $record[$r] = "5_often";
            } elseif ($record[$r] == "3_occasionally") {
                $record[$r] = "4_somewhat_often";
            } elseif ($record[$r] == "4_somewhat_often") {
                $record[$r] = "3_occasionally";
            } elseif ($record[$r] == "5_often") {
                $record[$r] = "2_rarely";
            } elseif ($record[$r] == "6_very_often") {
                $record[$r] = "1_very_rarely";
            }
        }

        $aloof_sum = $this->sumSubscaleScores(self::ALOOF, $record);
        $prs_sum   = $this->sumSubscaleScores(self::PRS, $record);
        $rigid_sum = $this->sumSubscaleScores(self::RIGID, $record);
        $total_sum = 0;

        if (!is_null($aloof_sum)) {
            $scores["aloof_score"] = round($aloof_sum/12, 12);
        }

        if (!is_null($prs_sum)) {
            $scores["prs_score"] = round($prs_sum/12, 12);
        }

        if (!is_null($rigid_sum)) {
            $scores["rigid_score"] = round($rigid_sum/12, 12);
        }

        if (!is_null($aloof_sum) && !is_null($prs_sum) && !is_null($rigid_sum)) {
            $total_sum = $aloof_sum + $prs_sum + $rigid_sum;
            $scores["total_score"] = round($total_sum/36, 12);
        }

        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    // (1, 5, 9, 12, 16, 18, 23, 25, 27, 28, 31, 36)
    CONST ALOOF = [
                   "q1_like_being_otherpeople",
                   "q5_information_than_socialize",
                   "q9_enjoy_socialsituations",
                   "q12_easy_approach",
                   "q16_situations_meetnew_people",
                   "q18_conversation_tobe_polite",
                   "q23_good_smalltalk",
                   "q25_connecting_people",
                   "q27_conversation_boresme",
                   "q28_warmfriendly_others",
                   "q31_alone_ratherthan_withothers",
                   "q36_enjoy_chatting",
                  ];

    // (2,4,7,10,11,14,17,20,21,29,32,34)
    CONST PRS = [
                 "q2_hard_wordsout_smoothly",
                 "q4_hard_avoid_sidetrack",
                 "q7_intune_conversation",
                 "q10_voice_flat_monotone",
                 "q11_disconnected_outofsync_convo",
                 "q14_others_dont_understand",
                 "q17_talktoomuch_certain_topics",
                 "q20_speak_tooloud_softly",
                 "q21_tell_someone_not_interested",
                 "q29_longpauses_conversations",
                 "q32_losetrack_talking",
                 "q34_change_topic",
                ];

    // (3, 6, 8, 13, 15, 19, 22, 24, 26, 30, 33, 35)
    CONST RIGID = [
                   "q3_comfortable_unexpectedchanges",
                   "q6_talkinto_tryingnew",
                   "q8_warmup_unfamiliarplace",
                   "q13_strongneed_sameness",
                   "q15_flexible",
                   "q19_lookforward_newthings",
                   "q22_hardtime_change_routine",
                   "q24_act_myways",
                   "q26_peoplefrustrated",
                   "q30_alter_dailyroutine",
                   "q33_follow_routine",
                   "q35_doingthings_knownway",
                  ];

    // 1, 3, 7, 9, 12, 15, 16, 19, 21, 23, 25, 28, 30, 34, 36
    CONST REVERSE = [
                     "q1_like_being_otherpeople",
                     "q3_comfortable_unexpectedchanges",
                     "q7_intune_conversation",
                     "q9_enjoy_socialsituations",
                     "q12_easy_approach",
                     "q15_flexible",
                     "q16_situations_meetnew_people",
                     "q19_lookforward_newthings",
                     "q21_tell_someone_not_interested",
                     "q23_good_smalltalk",
                     "q25_connecting_people",
                     "q28_warmfriendly_others",
                     "q30_alter_dailyroutine",
                     "q34_change_topic",
                     "q36_enjoy_chatting",
                    ];

    CONST CUTOFFS = [
                     'f_s_aloof'  => 3.46,
                     'f_s_prs'    => 2.93,
                     'f_s_rigid'  => 3.73,
                     'f_i_aloof'  => 3.65,
                     'f_i_prs'    => 3.22,
                     'f_i_rigid'  => 4.32,
                     'f_be_aloof' => 3.39,
                     'f_be_prs'   => 2.89,
                     'f_be_rigid' => 3.89,
                     'm_s_aloof'  => 4.13,
                     'm_s_prs'    => 3.25,
                     'm_s_rigid'  => 3.94,
                     'm_i_aloof'  => 4.19,
                     'm_i_prs'    => 3.3,
                     'm_i_rigid'  => 4.20,
                     'm_be_aloof' => 4.02,
                     'm_be_prs'   => 3.10,
                     'm_be_rigid' => 3.89,
                    ];
}
