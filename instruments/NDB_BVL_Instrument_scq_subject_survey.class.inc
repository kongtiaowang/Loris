<?php
/*
 * This file contains the NDB_BVL_Instrument_scq_subject_survey
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the scq_subject_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_scq_subject_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    var $yesNo     = array(
                      null  => "",
                      "yes" => "Yes",
                      "no"  => "No",
                     );
    var $onlyYesNo = array(
                      null  => "",
                      "yes" => "Yes",
                      "no"  => "No",
                     );
    var $scoreCols = array(
                      "score",
                      "scq_diagnosis",
                     );

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
        $this->formType ="XIN";
        $this->form     = new LorisForm('scq_subject_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = 'scq_subject_survey';           // test_names.Test_name
        $this->table    = 'scq_subject_survey';
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();
        // required fields for data entry completion status
        $this->_requiredElements = array("q1_talk_short_phrases");
        $this->_doubleDataEntryDiffIgnoreColumns = array(
                                                    'CommentID',
                                                    'UserID',
                                                    'Testdate',
                                                    'Window_Difference',
                                                    'Candidate_Age',
                                                    'Data_entry_completion_status',
                                                    'score',
                                                    'scq_diagnosis',
                                                   );
        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.
    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/scq_subject_survey(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
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
        $this->addHeader("Social Communication Questionnaire - Lifetime");

        $this->form->addElement(
            'static',
            null,
            "<h3><i>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism.</i></h3>"
        );

        $config            =& NDB_Config::singleton();
        $dateOptions       = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );
        $this->dateOptions = $dateOptions;
        $this->addBasicDate('Date_taken', 'Date of Administration', $dateOptions);

        $opts = array(
                 null          => "",
                 "mother"      => "Mother",
                 "father"      => "Father",
                 "step_mother" => "Step Mother",
                 "step_father" => "Step Father",
                 "other"       => "Other",
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

    private const PG1_questionArray = array(
                                       "q2_to_and_fro"             => "2. Can you have a to and fro \"conversation\" with her/him that involves taking turns or building on what you have said?",
                                       "q3_odd_phrases"            => "3. Has he/she ever used odd phrases or said the same thing over and over in almost exactly the same way (either phrases that she/he has heard other people use or ones that she/he has made up)?",
                                       "q4_socially_inappropriate" => "4. Has she/he ever used socially inappropriate questions or statements? For example, has she/he ever regularly asked personal questions or made personal comments at weird times?",
                                       "q5_pronouns_mixed"         => "5. Has she/he ever got her/his pronouns mixed up (e.g., saying <i>you</i> or <i>she/he</i> for <i>I</i>)?",
                                       "q6_words_invented"         => "6. Has she/he ever used words that she/he seemed to have invented or made up her/himself; put things in odd, indirect ways; or used metaphorical ways of saying things (e.g., saying <i>hot rain</i> for <i>steam</i>)?",
                                       "q7_said_same_thing"        => "7. Has she/he ever said the same thing over and over in exactly the same way or insisted that you say the same thing over and over again?",
                                      );

    function _page1()
    {
        $this->form->addElement(
            'static',
            null,
            "<h3><i>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism.</i></h3>"
        );

        $this->form->addElement("header", null, "Capable of phrase speech");
        $this->form->addElement("select", "q1_talk_short_phrases", "1. Is she/he now able to talk using short phrases or sentences? If <i>no</i>, skip to question 8.", $this->onlyYesNo);
        //Phrase speech
        $this->form->addElement("header", null, "Phrase speech");

        foreach (self::PG1_questionArray as $field=>$label) {
            $this->form->addElement("select", $field, $this->indent . $label, $this->yesNo);
            $this->XINRegisterRule($field, array("q1_talk_short_phrases{@}=={@}yes"), "This field is required if she/he is capable of phrase speech");
        }

        //Non-phrase speech questions
        $this->form->addElement("header", null, "Non-phrase speech questions");
        //$this->form->addElement("static", null, "Has she/he ever...");
        $questionArray = array(
                          "q8_particular_way"            => "8. Has she/he ever had things that she/he seemed to have to do in a very particular way or order or rituals that she/he insisted that you go through?",
                          "q9_facial_expressions"        => "9. Has her/his facial expression usually seemed appropriate to the particular situation, as far as you could tell?",
                          "q10_hand_like_tool"           => "10. Has she/he ever used your hand like a tool or as if it were part of her/his own body (e.g., pointing with your finger, putting your hand on a doorknob to get you to open the door)?",
                          "q11_interests_that_preoccupy" => "11. Has she/he ever had any interests that preoccupy her/him and might seem odd to other people (e.g., traffic lights, drainpipes, or timetables)?",
                          "q12_interested_in_parts"      => "12. Has she/he ever seemed to be more interested in parts of a toy or an object (e.g., spinning the wheels of a car), rather than in using the object as it was intended?",
                          "q13_intense_interests"        => "13. Has she/he ever had any special interests that were <i>unusual</i> in their intensity but otherwise appropriate for her/his age and peer group (e.g., trains, dinosaurs)?",
                          "q14_sight_feel_sound"         => "14. Has she/he ever seemed to be <i>unusually</i> interested in the sight, feel, sound, taste, or smell of things or people?",
                          "q15_mannerisms"               => "15. Has she/he ever had any mannerisms or odd ways of moving her/his hands or fingers, such as flapping or moving her/his fingers in front of her/his eyes?",
                          "q16_complicated_movements"    => "16. Has she/he ever had any complicated movements of her/his whole body such as spinning or repeatedly bouncing up and down?",
                          "q17_deliberate_injury"        => "17. Has she/he ever injured her/himself deliberately, such as by biting her/his arm or banging her/his head?",
                          "q18_carry_objects"            => "18. Has she/he ever had any objects (other than a soft toy or comfort blanket) that she/he <i>had</i> to carry around?",
                          "q19_particular_friends"       => "19. Does she/he have any particular friends or a best friend?",
                         );
        foreach ($questionArray as $field=>$label) {
            $this->form->addElement("select", $field, $this->indent . $label, $this->yesNo);
        }
        //Questions 20-40
        $this->form->addElement("header", null, "Between ages 4 and 5");
        //$this->form->addElement("static", null, "When she/he was 4 to 5, did she/he...");
        $questionArray = array(
                          "q20_talk_friendly"       => "20. When she/he was 4 to 5, did she/he ever talk with you just to be friendly (rather than to get something)?",
                          "q21_spontaneously_copy"  => "21. When she/he was 4 to 5, did she/he ever <i>spontaneously</i> copy you (or other people) or what you were doing (such as vacuuming, gardening, or mending things)?",
                          "q22_spontaneously_point" => "22. When she/he was 4 to 5, did she/he ever <i>spontaneously</i> point at things around her/him just to show you things (not because she/he wanted them)?",
                          "q23_gestures"            => "23. When she/he was 4 to 5, did she/he ever use gestures other than pointing or pulling your hand, to let you know what she/he wanted?",
                          "q24_nod_yes"             => "24. When she/he was 4 to 5, did she/he nod her/his head to mean <i>yes</i>?",
                          "q25_shake_no"            => "25. When she/he was 4 to 5, did she/he shake her/his head to mean <i>no</i>?",
                          "q26_look_directly"       => "26. When she/he was 4 to 5, did she/he usually look at you directly in the face when doing things with you or talking with you?",
                          "q27_smile_back"          => "27. When she/he was 4 to 5, did she/he smile back if someone smiled at her/him?",
                          "q28_show_things"         => "28. When she/he was 4 to 5, did she/he ever show you things that interested her/him to engage your attention?",
                          "q29_offer_share"         => "29. When she/he was 4 to 5, did she/he offer to share things other than food with you?",
                          "q30_join_enjoyment"      => "30. When she/he was 4 to 5, did she/he ever seem to want you to join in her/his enjoyment of something?",
                          "q31_comfort"             => "31. When she/he was 4 to 5, did she/he ever try to comfort you if you were sad or hurt?",
                          "q32_wanted_something"    => "32. When she/he was 4 to 5, when she/he wanted something or wanted help, did she/he look at you and use gestures with sounds or words to get your attention?",
                          "q33_facial_expressions"  => "33. When she/he was 4 to 5, did she/he show a normal range of facial expressions?",
                          "q34_spontaneously_join"  => "34. When she/he was 4 to 5, did she/he ever spontaneously join in and try to copy the actions in social games?",
                          "q35_play_pretend"        => "35. When she/he was 4 to 5, did she/he play pretend or make-believe games?",
                          "q36_seem_interested"     => "36. When she/he was 4 to 5, did she/he seem interested in other children of approximately the same age whom she/he did not know?",
                          "q37_respond_positively"  => "37. When she/he was 4 to 5, did she/he respond positively when another child approached her/him?",
                          "q38_came_into_room"      => "38. When she/he was 4 to 5, if you came into a room and started talking to her/him without calling her/his name, did she/he usually look up and pay attention to you?",
                          "q39_play_imaginative"    => "39. When she/he was 4 to 5, did she/he ever play imaginative games with another child in such a way that you could tell that each child understood what the other was pretending?",
                          "q40_play_cooperatively"  => "40. When she/he was 4 to 5, did she/he play cooperatively in games that required joining in with a group of other children, such as hide-and-seek or ball games?",
                         );
        foreach ($questionArray as $field=>$label) {
            $this->form->addElement("select", $field, $this->indent . $label, $this->yesNo);
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    function validate_page1($values)
    {
        $errors = [];
        if ($values['q1_talk_short_phrases'] == 'no') {
            foreach (array_keys(self::PG1_questionArray) as $key) {
                if (!empty($values[$key])) {
                    $errors[$key] = 'You can not choose any value here if she/he is not capable of phrase speech.';
                }
            }
        }
        return $errors;
    }

    function score(): void
    {
        //skip scoring if all data has not yet been entered.
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $db =& Database::singleton();
        // null scores
        $this->_nullScores($this->scoreCols);
        // Get the item scores
        $query  = "SELECT * FROM $this->table WHERE CommentID=:commentID";
        $params =array('commentID' => $this->getCommentID());
        $record = $db->pselectRow($query, $params);

        //take only question fields, not metadata
        foreach ($record as $field=>$value) {
            // This was written this way before -- added substr to strip off the "q"
            if (intval(substr($field, 1)) == 0) {
                continue;  //not a question field
            } else {
                $scores[intval(substr($field, 1))] = $value;
            }
        }

        //check if phrase speech questions (#2-#7) need to be scored
        if ($scores[1] == "no") {
            for ($i = 2; $i <= 7; $i++) {
                unset($scores[$i]);
            }
        }

        //remove question 1, which is never scored...
        unset($scores[1]);

        //Questions where `yes` scores 1, otherwise `no` scores 1
        $yesIs1           = array_diff(range(2, 19), array(2, 9, 19));
        $calculatedScores = array("score" => 0);
        //Sum point value of all questions

        foreach ($scores as $question=>$answer) {
            //Currently, "not_answered" questions count as 0 towards the score
            if ((in_array($question, $yesIs1) && $answer == "yes")
                || (!in_array($question, $yesIs1) && $answer == "no")
            ) {
                $calculatedScores["score"]++;
            }
        }

        //enforce ASD diagnosis cutoff
        $calculatedScores["scq_diagnosis"] = $calculatedScores["score"] >= 11 ? "ASD Positive" : "ASD Negative";
        //save the resultant total
        $result = $db->update($this->table, $calculatedScores, array('CommentID' => $this->getCommentID()));
    }
}
?>