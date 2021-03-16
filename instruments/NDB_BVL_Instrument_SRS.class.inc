<?php




class NDB_BVL_Instrument_SRS extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /*
    INSERT INTO test_names (Test_name, Full_name, LimitAge, Sub_Group)
        VALUES ('SRS', 'Social Responsiveness Scale (Preschool Version for 3-Year-Olds)', '0', '1');

    INSERT INTO instrument_subtests VALUES('', 'SRS', 'SRS_page1', 'Page 1 (1-32)', 1);
    INSERT INTO instrument_subtests VALUES('', 'SRS', 'SRS_page2', 'Page 2 (33-65', 2);
    -- No more page 3.
    -- INSERT INTO instrument_subtests VALUES('', 'SRS', 'SRS_page3', 'Page 3', 3);
    */

    /*
Subscale
Items

Social Awareness
Raw Score
2, 7, 25, 32, 45, 52, 54, 56
SUMIF (Q2=>0 and Q7=>0 and Q25=>0 and Q32=>0 and Q45=>0 and Q52=>0 and Q54=>0 and Q56=>0);

Social Cognition
Raw Score
5, 10, 15, 17, 30, 40, 42, 44, 48, 58, 59, 62
SUMIF (Q5=>0 and Q10=>0 and Q15=>0 and Q17=>0 and Q30=>0 and Q40=>0 and Q42=>0 and Q44=>0 and Q48=>0 and Q58=>0 and Q59=>0 and Q62=>0);

Social Communication
Raw Score
12, 13, 16, 18, 19, 21, 22, 26, 33, 35, 36, 37, 38, 41, 46, 47, 51, 53, 55, 57, 60, 61
SUMIF (Q12=>0 and Q13=>0 and Q16=>0 and Q18=>0 and Q19=>0 and Q21=>0 and Q22=>0 and Q26=>0 and Q33=>0 and Q35=>0 and Q36=>0 and Q37=>0 and Q38=>0 and Q41=>0 and Q46=>0 and Q47=>0 and Q51=>0 and Q53=>0 and Q55=>0 and Q57=>0 and Q60=>0 and Q61=>0);

Social Motivation
Raw Score
1, 3, 6, 9, 11, 23, 27, 34, 43, 64, 65
SUMIF (Q1=>0 and Q3=>0 and Q6=>0 and Q9=>0 and Q11=>0 and Q23=>0 and Q27=>0 and Q34=>0 and Q43=>0 and Q64=>0 and Q65=>0);

Autistic Mannerisms
Raw Score
4, 8, 14, 20, 24, 28, 29, 31, 39, 49, 50, 63
SUMIF ( Q4=>0 and Q8=>0 and Q14=>0 and Q20=>0 and Q24=>0 and Q28=>0 and Q29=>0 and Q31=>0 and Q39=>0 and Q49=>0 and Q50=>0 and Q63=>0);
    */


    /* array indexing from page number to question array for that page.
     * the _page($pageNum) function takes the appropriate page, and adds
     * all the questions to the page.
     */

    var $questions = array(
        1 => array(
            'q1_fidgety_social_situations' => 'Seems much more fidgety in social situations than when alone',
            'q2_expressions_dont_match' => "Expressions on his/her face don't match what he/she is saying",
            'q3_seems_self_confident' => 'Seems self confident when interacting with others',
            'q4_auto_pilot_under_stress' => 'When under stress, child seems to go on "auto-pilot"',
            'q5_no_recognize_take_advantage' => "Doesn't recognize when others are trying to take advantage of him/her",
            'q6_rather_be_alone' => 'Would rather be alone than with others',
            'q7_aware_others_feeling' => 'Is aware of what others are thinking or feeling',
            'q8_behaves_strange' => "Behaves in ways which seem strange or bizarre",
            'q9_clings_to_adults' => "Clings to adults, seems too dependent on them",
            "q10_unable_pickup_meaning" => "Unable to pick up on any of the meaning of conversations of older children or adults",
            "q11_good_self_confidence" => "Has good self-confidence",
            "q12_able_communicate_feelings" => "Is able to communicate his or her feelings to others in words or gestures",
            "q13_slow_turntaking_interactions" => "Is slow or awkward in turn-taking interactions with peers",
            "q14_not_well_coordinated" => "Is not well coordinated in physical activities",
            "q15_able_understand_meaning" => "Is able to understand the meaning of other people's tone of voice and facial expressions",
            "q16_avoids_eye_contact" => "Avoids eye contact, or has unusual eye contact",
            /* ),
            2 => array( */
            "q17_recognizes_unfair" => "Recognizes when something is unfair",
            "q18_playground_no_interaction" => "When on the playground or in a group with other young children, child does not attempt to interact with the other children",
            "q19_frustrated_conversations" => "Gets frustrated trying to get ideas across in conversations",
            "q20_strange_playing" => "Has strange way of playing with toys",
            "q21_able_imitate_others" => "Is able to imitate others' actions",
            "q22_play_appropriately" => "Plays appropriately with children his/her age",
            "q23_no_group_activities" => "Does not join group activities unless told to do so",
            "q24_more_difficulty_routine" => "Has more difficulty than other children with changes in his/her routine",
            "q25_doesnt_mind_out_of_step" => 'Doesn\'t seem to mind being "out of step" or not on the "same wavelength" as others',
            "q26_offers_comfort_to_others" => "Offers comfort to others when they are sad",
            "q27_avoids_social_interactions" => "Avoids starting social interactions with peers or adults",
            "q28_talks_about_same_thing" => "Thinks or talks about the same thing over and over",
            "q29_regarded_as_weird" => "Is regarded by others as odd or weird",
            "q30_becomes_upset" => "Becomes upset in a situation with lots of things going on",
            "q31_cant_get_mind_off_something" => "Can't get his/her mind off something once he/she starts thinking about it",
            "q32_wants_to_be_changed" => "Wants to be changed when diaper or underwear are soiled or wet"),
        2 => array(
            "q33_socially_awkward" => "Is socially awkward",
            "q34_avoids_emotional_close" => "Avoids people who want to be emotionally close to him/her",
            "q35_trouble_keeping_flow" => "Has trouble keeping up with the flow of a normal interaction with other children",
            "q36_difficulty_relating_adults" => 'Has difficulty "relating" to adults',
            "q37_difficulty_relating_peers" => 'Has difficulty "relating" to peers',
            "q38_responds_to_mood_changes" => "Responds appropriately to mood changes in others",
            "q39_restricted_interests" => "Has a restricted (or unusually narrow) range of interests",
            "q40_imaginative" => "Is imaginative, good at pretending (without losing touch with reality)",
            "q41_wanders_aimlessly_activities" => "Wanders aimlessly from one activity to another",
            "q42_overly_sensitive_sounds_smells" => "Seems overly sensitive to sounds, textures, or smells",
            /* ),
            3 => array( */
            "q43_separates_from_caregivers" => "Separates easily from caregivers",
            "q44_doesnt_understand_events" => "Doesn't understand how events are related to one another the way other children his/her age do",
            "q45_focuses_attention_others" => "Focuses his/her attention to where others are looking or listening",
            "q46_overly_serious_expressions" => "Has overly serious facial expressions",
            "q47_too_silly" => "Is too silly or laughs inappropriately",
            "q48_sense_of_humor" => "Has a sense of humor, understands jokes",
            "q49_does_well_few_tasks" => "Does extremely well at a few tasks, but does not do as well at most other tasks",
            "q50_repetitive_odd_behaviors" => "Has repetitive, odd behaviors such as hand flapping or rocking",
            "q51_responds_odd_ways" => "Responds to clear, direct questions in ways that don't seem to make any sense",
            "q52_knows_talking_too_loud" => "Knows when he/she is talking too loud or making too much noise",
            "q53_talks_unusual_tone_of_voice" => "Talks to people with an unusual tone of voice (for example, talks like a robot or like he/she is giving a lecture)",
            "q54_reacts_people_as_objects" => "Seems to react to people as if they are objects",
            "q55_knows_invading_space" => "Knows when he/she is too close to someone or is invading someone's space",
            "q56_walks_between_people" => "Walks in between two people who are talking",
            "q57_other_children_dont_like" => "Other children do not like to play with him/her",
            "q58_concentrates_on_parts" => "Concentrates too much on parts of things rather than \"seeing the whole picture\"",
            "q59_overly_suspicious" => "Is overly suspicious",
            "q60_is_emotionally_distant" => "Is emotionally distant, doesn't show his/her emotions",
            "q61_inflexible" => "Is inflexible, has a hard time changing his/her mind",
            "q62_unusual_reasons" => "Gives unusual or illogical reasons for doing things",
            "q63_touches_others_usually" => "Touches others in an unusual way",
            "q64_tense_social_settings" => "Is too tense in social settings",
            "q65_stares_into_space" => "Stares or gazes off into space"
        )
    );

    var $scoreCols = array("srs_score", "awareness_score", "cognition_score", "communication_score",
        "motivation_score", "mannerisms_score");

    // Question numbers where not true = 0 and always true = 3
    // in the scoring algorithm
    var $ForwardCoded = array(1, 2, 4, 5, 6, 8, 9, 10, 13, 14,
        16, 18, 19, 20, 23, 24, 25, 27, 28, 29, 30, 31, 33,
        34, 35, 36, 37, 39, 41, 42, 44, 46, 47, 49, 50, 51,
        53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65);
    // Question numbers where not true = 3 and always true = 0
    // in the scoring algorithm
    var $ReverseCoded = array(3, 7, 11, 12, 15, 17, 21, 22, 26,
        32, 38, 40, 43, 45, 48, 52, 55);

    var $subscales = array(
        'awareness_score' => array(2, 7, 25, 32, 45, 52, 54, 56),
        'cognition_score' => array(5, 10, 15, 17, 30, 40, 42, 44, 48, 58, 59, 62),
        'communication_score' => array(12, 13, 16, 18, 19, 21, 22,
            26, 33, 35, 36,37, 38, 41, 46, 47, 51, 53, 55, 57, 60, 61),
        'motivation_score' => array(1, 3, 6, 9, 11, 23, 27, 34, 43, 64, 65),
        'mannerisms_score' => array(4, 8, 14, 20, 24, 28, 29, 31, 39, 49, 50, 63)
    );


    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "SRS";           // test_names.Test_name
        $this->table = 'SRS';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // Get the subject age in months for scoring

        $db =& Database::singleton();
        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner', "Date_taken", 'q1_fidgety_social_situations',
            "q17_recognizes_unfair",
            "q43_separates_from_caregivers"
        );

        //MODIFY THIS WHEN THE SCORING IS IMPLEMENTED

        $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age',
            'Data_entry_completion_status',
            'srs_score',
            "awareness_score",
            "cognition_score",
            "communication_score",
            "motivation_score",
            "mannerisms_score"

        );

        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/SRS_page([0-9]+)/", $this->page, $matches)) {
            $this->_page($matches[1]);
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function _addDropdown($question_name, $question)
    {
        $this->form->addElement("select", "$question_name", $question,
            array('' => '',
                'not_true' => "Not True",
                'sometimes_true' => "Sometimes True",
                'often_true' => "Often True",
                'always_true' => "Almost Always True",
                'not_answered' => "Not Answered"
            )
        );

    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {
        // display test name
        $this->form->addElement('header', 'instrument_title', "Social Responsiveness Scale");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement("select", "completed_by", "This form filled out by",
            array('' => '', 'mother' => "Mother", 'father' => "Father", 'other' => "Other", 'not_answered' => "Not Answered")
        );
        $this->addTextElement("completed_by_other", "Specify (if other):",
            array("completed_by{@}=={@}other"), "Required if filled out by other"
        );


     /*   $this->form->addElement("static", "srs_score", "SRS Total Score:");
        $this->form->addElement("static", "awareness_score", "Social Awareness Score:");
        $this->form->addElement("static", "cognition_score", "Social Cognition Score:");
        $this->form->addElement("static", "communication_score", "Social Communication Score:");
        $this->form->addElement("static", "motivation_score", "Social Motivation Score:");
        $this->form->addElement("static", "mannerisms_score", "Autistic Mannerisms Score:");*/


        $this->form->addElement('header', null, "Score Summary");

        //scoring column headers
        $group[] = $this->form->createElement('static', "score", null, null);
        $group[] = $this->form->createElement('static', "t_score", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
            'srs'   => "SRS Total Score",
            'awareness'     => "Social Awareness Score",
            'cognition'     => "Social Cognition Score",
            'communication'     => "Social Communication Score",
            'motivation'     => "Social Motivation Score",
            'mannerisms'     => "Autistic Mannerisms Score"
        );

        $columnHeaders = array(
            "score" => "Score",
            "t_score"   => "T Score",
        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }

        $this->form->addElement('static', null, "");


        $group[] = $this->form->createElement('static', "score_range", null, null);
        $this->form->addGroup($group, "score_range_score_group", "Score Range", $this->_GUIDelimiter, false);
        unset($group);
        /*   function _page($pageNum) { */
        //$this->form->addElement('header', 'instrument_title', "Social Responsiveness Scale Page (SRS) - Page $pageNum");
        $this->form->addElement('header', 'instrument_title', "Social Responsiveness Scale Page (SRS)");
        $this->form->addElement('static', '', '<br />');
        $this->form->addElement('static', '', '<br />');

        $qNum = 1;
        $page_questions = array_merge($this->questions[1], $this->questions[2]);

        foreach ($page_questions as $field => $question) {
            $this->_addDropdown($field, $qNum . '. ' . $question);
            $qNum++;
        }
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        $this->_nullScores($this->scoreCols);
        $db =& Database::singleton();
        $Answers = $db->pselectRow("SELECT * FROM " . $this->table . " WHERE CommentID=:cid", array("cid" => $this->getCommentID()));

        if ($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $dob = $timepoint->getEffectiveDateOfBirth();
        }

        if (!empty($dob) && !empty($Answers['Date_taken'])) {
            $age = Utility::calculateAge($dob, $Answers["Date_taken"]);
            if (is_array($age)) {
                $age_months = $age['year'] * 12 + $age['mon'];
            } else {
                $scores['srs_score'] = "Error calculating age. Must specify date of administration.";
                $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
                return;
            }
        }

        if ($age_months < 33) {
            $scores['srs_score'] = "Child too young to score.";
            $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
            return;
        } else if ($age_months > 48) {
            $scores['srs_score'] = "Child too old to score.";
            $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
            return;
        }

        $scores = array();

        // add an arbitrary 0 index, so that index n maps to question n
        $fields_array = array(0 => "no question zero");
        foreach ($this->questions as $page => $questions) {
            $fields_array = array_merge($fields_array, array_keys($questions));
        }

        $score = 0;
        $not_answered = 0;

        $currentSubscale = null;
        $totals = array();

        // ignored in subscale scoring
        //Remove this as per redmine 18744
        //$ignored = array(35, 36);
        $ignored = array(0);

        foreach ($this->ForwardCoded as $QuestionNumber) {

            foreach ($this->subscales as $subscale => $questions) {
                if (in_array($QuestionNumber, $questions)) {
                    $currentSubscale = $subscale;
                }
                if ($currentSubscale != null) {
                    break;
                }
            }

            switch ($Answers[$fields_array[$QuestionNumber]]) {
                case 'not_true':
                    $score += 0;
                    if (!in_array($QuestionNumber, $ignored)) {
                        $totals[$currentSubscale] += 0;
                    }
                    break;
                case 'sometimes_true':
                    $score += 1;
                    if (!in_array($QuestionNumber, $ignored)) {
                        $totals[$currentSubscale] += 1;
                    }
                    break;
                case 'often_true':
                    $score += 2;
                    if (!in_array($QuestionNumber, $ignored)) {
                        $totals[$currentSubscale] += 2;
                    }
                    break;
                case 'always_true':
                    $score += 3;
                    if (!in_array($QuestionNumber, $ignored)) {
                        $totals[$currentSubscale] += 3;
                    }
                    break;
                case 'not_answered':
                    $not_answered += 1;
                    if (!in_array($QuestionNumber, $ignored)) {
                        $val=$this->getMisssingValueScore($QuestionNumber);
                        $score += $val;
                        $totals[$currentSubscale] += $val;
                        //$scores[$currentSubscale] = 0;
                    }
                    break;
            }

            $currentSubscale = null;
        }

        foreach ($this->ReverseCoded as $QuestionNumber) {

            foreach ($this->subscales as $subscale => $questions) {
                if (in_array($QuestionNumber, $questions)) {
                    $currentSubscale = $subscale;
                }
                if ($currentSubscale != null) {
                    break;
                }
            }

            switch ($Answers[$fields_array[$QuestionNumber]]) {
                case 'not_true':
                    $score += 3;
                    $totals[$currentSubscale] += 3;
                    break;
                case 'sometimes_true':
                    $score += 2;
                    $totals[$currentSubscale] += 2;
                    break;
                case 'often_true':
                    $score += 1;
                    $totals[$currentSubscale] += 1;
                    break;
                case 'always_true':
                    $score += 0;
                    $totals[$currentSubscale] += 0;
                    break;
                case 'not_answered':
                    $val=$this->getMisssingValueScore($QuestionNumber);
                    $score += $val;
                    $totals[$currentSubscale] += $val;
                    $not_answered += 1;
                    //$scores[$currentSubscale] = 0;
                    break;
            }
            $currentSubscale = null;
        }

        foreach($scores as $key=>$value)
        {
            if(is_null($key) || $key == '')
                unset($scores[$key]);
        }
        $scores['srs_score'] = $score;
        if ($not_answered > 6) {
            $scores['srs_score'] = "Greater than 10% responses missing/Not Answered; So cannot score";
            $scores['srs_t_score']="Unable to score/Data Insufficient";
            $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
            return;
        }
        else{
            $query = "
                        SELECT
                            T_Score
                        from
                            SRS2_Preschool_lookup
                        WHERE
                            Raw_Score = :raw_score
                        AND
                            Scale = 'Total'
                    ";

            $where = array(
                'raw_score' => $scores['srs_score']
            );



            $query_result_total = $db->pselectRow($query, $where);
            $scores['srs_t_score']=$query_result_total['T_Score'];
            if($scores['srs_t_score']==90)
            {
                $scores['srs_t_score']='Greater than or equal to 90';
            }

        }

        foreach ($this->scoreCols as $scoreCol) {
            $lookup_scale_name=$this->getLookupScaleName($scoreCol);
            $key=explode("_",$scoreCol);
            $scale=$key[0];
            if ($scoreCol != 'srs_score') {
                if ($scores[$scoreCol] === 0 || $totals[$scoreCol] === null) {
                    $scores[$scoreCol] = "Not all questions in the subscale were answered. Score is invalid.";
                    $scores[$scale . "_t_score"]="Unable to score/Data Insufficient";
                } else {
                    $scores[$scoreCol] = $totals[$scoreCol];
                    $query = "
                        SELECT
                            T_Score
                        from
                            SRS2_Preschool_lookup
                        WHERE
                            Raw_Score = :raw_score
                        AND
                            Scale = :scale
                    ";

                    $where = array(
                        'raw_score' => $scores[$scoreCol],
                        'scale' => $lookup_scale_name,
                    );



                    $query_result = $db->pselectRow($query, $where);

                    $field_t_score = $scale . "_t_score";
                    $scores[$field_t_score] = $query_result['T_Score'];
                    if($scores[$field_t_score]==90)
                    {
                        $scores[$field_t_score]="Greater than or equal to 90";
                    }
                    if($scores[$field_t_score]==30)
                    {
                        $scores[$field_t_score]="Less than or equal to 30";
                    }
                }
            }
        }
        if( $scores['srs_t_score']==="Unable to score/Data Insufficient") {
            $scores['score_range'] = "NA";
        }
        else {

            if ($scores['srs_t_score'] >= 76) {
                $scores['score_range'] = "Severe";
            } else if (in_array($scores['srs_t_score'], range(66, 75))) {
                $scores['score_range'] = "Moderate";
            } else if (in_array($scores['srs_t_score'], range(60, 65))) {
                $scores['score_range'] = "Mild";
            } else if ($scores['srs_t_score'] <= 59) {
                $scores['score_range'] = "Normal";
            } else {
                $scores['score_range'] = "NA";
            }
        }



        // save the resultant total
        $result = $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
    }


function getLookupScaleName($scale)
{

    if ($scale == 'srs_score') {
        $scale_name = "Total";
    }
    if ($scale == 'awareness_score') {
        $scale_name = "Awr";
    }
    if ($scale == 'cognition_score') {
        $scale_name = "Cog";
    }
    if ($scale == 'communication_score') {
        $scale_name = "Com";
    }
    if ($scale == 'motivation_score') {
        $scale_name = "Mot";
    }
    if ($scale == 'mannerisms_score') {
        $scale_name = "DSM_RRB";
    }

    return $scale_name;

}

function getMisssingValueScore($qno)
{
    $one_value_array=array(3,5,7,9,11,12,15,17,19,22,22,25,26,28,31,38,40,43,45,48,56);
    $two_value_array=array(52,55);

    if(in_array($qno,$one_value_array))
    {
        $value=1;
    }
    else if(in_array($qno,$two_value_array))
    {
        $value=1;
    }
    else{
        $value=0;

    }
    return $value;
}

}

?>
