<?php

class NDB_BVL_Instrument_pspq_InformantReport_mom_on_dad extends NDB_BVL_Instrument
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

    var $rating     = array(
                       ''                 => null,
                       '1_very_rarely'    => "1. Very Rarely",
                       '2_rarely'         => "2. Rarely",
                       '3_occasionally'   => "3. Occasionally",
                       '4_somewhat_often' => '4. Somewhat Often',
                       '5_often'          => '5. Often',
                       '6_very_often'     => '6. Very Often',
                      );
    var $respondent = array(
                       ''           => null,
                       'mother'     => 'Mother',
                       'father'     => 'Father',
                       'stepmother' => 'Step-Mother',
                       'stepfather' => 'Step-Father',
                       'other'      => 'Other',
                      );

    var $informant            = array(
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
                   'male'   => 'Male',
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
        $this->testName = "pspq_InformantReport_mom_on_dad";           // test_names.Test_name
        $this->table    = 'pspq_InformantReport_mom_on_dad';

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

        if (preg_match("/pspq_InformantReport_mom_on_dad(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->form->addElement('header', 'instrument_title_1', "PSPQ: Personality Styles and Preferences Questionnaire - Informant Report Mom on Dad (Send to Mom)");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        // $this->addNumericElement('respondent_age','Your Age <BR>(Please indicate your age in years)');
        $field = 'respondent_age';$label = 'Your Age <BR>(Please indicate your age in years)';
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));

        $this->addSelect('respondent', "Your relationship to child", $this->respondent);
        $group[] = $this->createText('respondent_other', $this->indent."If Other please specify");
        $this->addGroup($group, "respondent_other_group", $this->indent."If Other please specify", null, false);
        unset($group);
        $rules_array = array("respondent{@}=={@}other");
        $this->XINRegisterRule('respondent_other', $rules_array, "Please specify relationship", 'respondent_other_group');

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
        // display test name
        $this->form->addElement('header', 'instrument_title_2', "PSPQ: Personality Styles and Preferences Questionnaire Page 1 - Informant Report Mom on Dad (Send to Mom)");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            "<strong>Instructions:</strong>
            <BR><BR>
            You are about to fill out a series of statements related to personality and lifestyle of the other biological parent of your child.
            For each question, you will be given a choice of 6 answers that describe how often the statement applies to the other biological parent:
            <BR><BR>
            1. Very Rarely<BR>2. Rarely<BR>3. Occasionally<BR>4. Somewhat Often<BR>5. Often<BR> 6. Very Often
            <BR><BR>
            Choose the number that matches the answer that comes closest to how you feel about each statement.
            <BR>
            So, if they watch the evening news once a week, you might circle #4: Somewhat often.
            <BR><BR>
            <strong>3 IMPORTANT THINGS TO REMEMBER</strong>
            <BR><BR>
            #1. Many of these questions ask about their interactions with other people. Please <strong>think about the way they are with <i>most</i> people rather than special relationships</strong> they may have with spouses or significant others, children, siblings, and parents.
            <BR><BR>
            #2. Everyone changes over time, which can make it hard to fill out questions about personality. <strong>Think about the way they have been the majority of their adult life</strong>, rather than the way they were as a teenager, or times they many have felt different than normal.
            <BR><BR>
            #3. <strong>You must answer each question,</strong> and give only one answer per question. If you are confused, please just give it a guess.
            <BR><BR>
            Observer ratings help us obtain a more well-rounded measure of personality and lifestyle, since some traits and behaviors are most easily observed by other people."
        );

        $this->addSelect('informant_confidence', "<BR>How confident do you feel about your ability to give an accurate report on the <BR>personality traits and behaviors of the other biological parent?", $this->informant_confidence);

        $this->form->addElement('header', 'instrument_title_3', "Observer Rating");
        /*
        $field = 'informant_age';$label = 'Your Age <BR>(Please indicate your age in years)';
        $group [] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));
        */
        $this->addSelect('informant', "Relationship to the other biological parent of the child", $this->informant);

        $group[] = $this->createText('informant_other', $this->indent."If Other please specify");
        $this->addGroup($group, "informant_other_group", $this->indent."If Other please specify", null, false);
        unset($group);
        $rules_array = array("informant{@}=={@}other");
        $this->XINRegisterRule('informant_other', $rules_array, "Please specify relationship", 'informant_other_group');
        $this->addSelect('informant_gender', "Gender of the other biological parent of the child", $this->gender);
        $this->XINRegisterRule('informant_gender', array("informant_gender{@}=={@}NEVER_REQUIRED"));

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
            $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"));
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
        $this->form->addElement('header', 'instrument_title_4', "PSPQ: Personality Styles and Preferences Questionnaire Page 2 - Informant Report Mom on Dad (Send to Mom)");
        $this->form->addElement('header', 'instrument_title_5', "Observer Rating");

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
            $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"));
        }

        // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
    }

    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3()
    {
        $this->form->addElement('header', 'instrument_title_6', "PSPQ: Personality Styles and Preferences Questionnaire Page 3 - Informant Report Mom on Dad (Send to Mom)");
        $this->form->addElement('header', 'instrument_title_7', "Observer Rating");

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
            $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"));
        }
        $this->addBasicTextArea("comments", "Do you have any other comments?");
        $this->XINRegisterRule('comments', array('comments{@}=={@}NEVER_REQUIRED'));

        // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
    }

    function PSPQ_Rules($values)
    {
        // commenting out the warnings
         $errors    = array();
         $DB        = Database::singleton();
         $questions = array();
         $questions = $DB->pselect(
             "SELECT  Description as question,
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
            } else if ($key == 'informant_other' && $questions['informant'] != 'other') {
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
        //print_r($list_questions);
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
        if (intval($values['informant_age']) > 100) {
            $errors['informant_age_group'] = "Specify age between 0 and 100";
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
                   "aloof_score" => 0,
                   "prs_score"   => 0,
                   "rigid_score" => 0,
                   "total_score" => 0,
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
        $total_sum = $aloof_sum + $prs_sum + $rigid_sum;

        $scores["aloof_score"] = round($aloof_sum/12, 12);
        $scores["prs_score"]   = round($prs_sum/12, 12);
        $scores["rigid_score"] = round($rigid_sum/12, 12);
        $scores["total_score"] = round($total_sum/36, 12);

        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    // (1, 5, 9, 12, 16, 18, 23, 25, 27, 28, 31, 36)
    CONST ALOOF = [
        "qi1_like_being_otherpeople",
        "qi5_information_than_socialize",
        "qi9_enjoy_socialsituations",
        "qi12_easy_approach",
        "qi16_situations_meetnew_people",
        "qi18_conversation_tobe_polite",
        "qi23_good_smalltalk",
        "qi25_connecting_people",
        "qi27_conversation_boresme",
        "qi28_warmfriendly_others",
        "qi31_alone_ratherthan_withothers",
        "qi36_enjoy_chatting",
        ];

    // (2,4,7,10,11,14,17,20,21,29,32,34)
    CONST PRS = [
            "qi2_hard_wordsout_smoothly",
            "qi4_hard_avoid_sidetrack",
            "qi7_intune_conversation",
            "qi10_voice_flat_monotone",
            "qi11_disconnected_outofsync_convo",
            "qi14_others_dont_understand",
            "qi17_talktoomuch_certain_topics",
            "qi20_speak_tooloud_softly",
            "qi21_tell_someone_not_interested",
            "qi29_longpauses_conversations",
            "qi32_losetrack_talking",
            "qi34_change_topic",
            ];


    // (3, 6, 8, 13, 15, 19, 22, 24, 26, 30, 33, 35)
    CONST RIGID = [
                "qi3_comfortable_unexpectedchanges",
                "qi6_talkinto_tryingnew",
                "qi8_warmup_unfamiliarplace",
                "qi13_strongneed_sameness",
                "qi15_flexible",
                "qi19_lookforward_newthings",
                "qi22_hardtime_change_routine",
                "qi24_act_myways",
                "qi26_peoplefrustrated",
                "qi30_alter_dailyroutine",
                "qi33_follow_routine",
                "qi35_doingthings_knownway",
            ];

    // 1, 3, 7, 9, 12, 15, 16, 19, 21, 23, 25, 28, 30, 34, 36
    CONST REVERSE = [
                "qi1_like_being_otherpeople",
                "qi3_comfortable_unexpectedchanges",
                "qi7_intune_conversation",
                "qi9_enjoy_socialsituations",
                "qi12_easy_approach",
                "qi15_flexible",
                "qi16_situations_meetnew_people",
                "qi19_lookforward_newthings",
                "qi21_tell_someone_not_interested",
                "qi23_good_smalltalk",
                "qi25_connecting_people",
                "qi28_warmfriendly_others",
                "qi30_alter_dailyroutine",
                "qi34_change_topic",
                "qi36_enjoy_chatting",
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