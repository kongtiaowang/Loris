<?php

class NDB_BVL_Instrument_csbs extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    const ACTIVITIES = array('wind_up', 'balloon', 'bubbles', 'jar', 'books', 'play');

/*
INSERT INTO instrument_subtests VALUES('', 'csbs', 'csbs_page1', 'Scoring Worksheet', 1);
INSERT INTO instrument_subtests VALUES('', 'csbs', 'csbs_page2', 'Symbolic Behaviour Scales', 2);
*/
    var $scoreLabels = array("q_1_gaze_shifts_raw_score",
        "q_2_shared_positive_affect_raw_score",
        "q_3_gaze_point_following_raw_score",
        "q_4_rate_of_communicating_raw_score",
        "q_5_behaviour_regulation_raw_score",
        "q_6_social_interaction_raw_score",
        "q_7_joint_attention_raw_score",
        "q_8_conventional_gestures_raw_score",
        "q_9_distal_gestures_raw_score",
        "q_10_syllables_consonants_raw_score",
        "q_11_inventory_of_consonants_raw_score",
        "q_12_words_raw_score",
        "q_13_words_raw_score",
        "q_14_word_combos_raw_score",
        "q_15_word_combos_raw_score",
        "q_16_language_comp_body_parts_raw_score",
        "q_17_action_schemes_raw_score",
        "q_18_actions_towards_other_raw_score",
        "q_19_sequence_action_schemes_raw_score",
        "q_20_stacks_tower_raw_score",
        "emotion_eye_gaze_weighted",
        "communication_weighted",
        "gestures_weighted",
        "sounds_weighted",
        "words_weighted",
        "understanding_weighted",
        "object_use_weighted");

        var $dateOptions = array(
                'language' => 'en',
                'format'   => 'YMd',
                'minYear'  =>  '2006',
                'maxYear'  => '2017',
                'addEmptyOption' => true,
                'emptyOptionValue' => null);


    /**
    * sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "csbs";           // test_names.Test_name
        $this->table = 'csbs';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner', "q_4_rate_of_communicating_1", "q_20_stacks_tower");


        /**
         * Array of column names to be ignored by the double data entry conflict detector.
         */
        $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age',
            'comments_status',
            'comments',
            'communication_percentile',
            'communication_standard',
            'communication_weighted',
            'Data_entry_completion_status',
            'emotion_eye_gaze_percentile',
            'emotion_eye_gaze_standard',
            'emotion_eye_gaze_weighted',
            'general_comments',
            'gestures_percentile',
            'gestures_standard',
            'gestures_weighted',
            'object_use_percentile',
            'object_use_standard',
            'object_use_weighted',
            'q_1_gaze_shifts_raw_score',
            'q_10_syllables_consonants_raw_score',
            'q_11_inventory_of_consonants_raw_score',
            'q_12_words_raw_score',
            'q_13_words_1',
            'q_13_words_10',
            'q_13_words_11',
            'q_13_words_12',
            'q_13_words_13',
            'q_13_words_14',
            'q_13_words_15',
            'q_13_words_16',
            'q_13_words_2',
            'q_13_words_3',
            'q_13_words_4',
            'q_13_words_5',
            'q_13_words_6',
            'q_13_words_7',
            'q_13_words_8',
            'q_13_words_9',
            'q_13_words_raw_score',
            'q_14_word_combos_raw_score',
            'q_15_word_combos_1',
            'q_15_word_combos_2',
            'q_15_word_combos_3',
            'q_15_word_combos_4',
            'q_15_word_combos_5',
            'q_15_word_combos_6',
            'q_15_word_combos_7',
            'q_15_word_combos_8',
            'q_15_word_combos_raw_score',
            'q_16_language_comp_body_parts_1',
            'q_16_language_comp_body_parts_2',
            'q_16_language_comp_body_parts_3',
            'q_16_language_comp_body_parts_4',
            'q_16_language_comp_body_parts_raw_score',
            'q_16_language_comp_objects_1',
            'q_16_language_comp_objects_2',
            'q_16_language_comp_objects_3',
            'q_16_language_comp_objects_4',
            'q_16_language_comp_person_1',
            'q_16_language_comp_person_2',
            'q_16_language_comp_person_3',
            'q_16_language_comp_raw_score',
            'q_16a_language_comp_object_raw_score',
            'q_16b_language_comp_person_name_raw_score',
            'q_16c_language_comp_body_parts_raw_score',
            'q_17_action_schemes_raw_score',
            'q_18_actions_towards_other_1',
            'q_18_actions_towards_other_2',
            'q_18_actions_towards_other_3',
            'q_18_actions_towards_other_4',
            'q_18_actions_towards_other_5',
            'q_18_actions_towards_other_6',
            'q_18_actions_towards_other_raw_score',
            'q_19_sequence_action_schemes_1',
            'q_19_sequence_action_schemes_2',
            'q_19_sequence_action_schemes_3',
            'q_19_sequence_action_schemes_4',
            'q_19_sequence_action_schemes_5',
            'q_19_sequence_action_schemes_6',
            'q_19_sequence_action_schemes_raw_score',
            'q_2_shared_positive_affect_raw_score',
            'q_20_stacks_tower_raw_score',
            'q_3_gaze_point_following_raw_score',
            'q_4_rate_of_communicating_raw_score',
            'q_5_behaviour_regulation_raw_score',
            'q_6_social_interaction_raw_score',
            'q_7_joint_attention_raw_score',
            'q_8_conventional_gestures_raw_score',
            'q_9_distal_gestures_raw_score',
            'relationship_to_child_status',
            'relationship_to_child',
            'social_composite_percentile',
            'social_composite_score',
            'social_composite_standard',
            'sounds_percentile',
            'sounds_standard',
            'sounds_weighted',
            'speech_composite_percentile',
            'speech_composite_score',
            'speech_composite_standard',
            'symbolic_composite_percentile',
            'symbolic_composite_score',
            'symbolic_composite_standard',
            'total_percentile',
            'total_standard',
            'total_weighted_raw_score',
            'understanding_percentile',
            'understanding_standard',
            'understanding_weighted',
            'words_percentile',
            'words_standard',
            'words_weighted'
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
    function _setupForm(){
        if(preg_match("/csbs(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array($this,'XINValidate'));
    }

    /**
    * generates the main page of the form.
    *
    * @return void
    * @access private
    *
    */
    function _main(){
        //display test name
        $this->form->addElement('header', 'instrument_title', "Communication and Symbolic Behaviour Scales - Development Profile");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->form->addElement("static", null, "<br/>");

        $this->form->addElement('static', null, "The following two fields refer to Date and Coder for the CSBS");
        $this->addDateElement("date_coded", "Date of Coding:", $this->dateOptions);
        $this->addTextElement("coder", "Coder:");

        $this->addTextAreaElement("comments", "Comments:");

	$this->form->addElement("header",null,"Summary Scores:");
        $this->form->addElement("static",null,"</br>");
	$this->form->addElement("header","score_validity",null);
	$this->form->addElement("static",null,"</br>");

	$group[]= $this->form->createElement("static", null, null,"Weighted Score");
        $group[]= $this->form->createElement("static", null, null, "Standard Score");
        $group[]= $this->form->createElement("static", null, null, "Percentile Rank");
  	$this->form->addGroup($group, null, 'Subscale', $this->_GUIDelimiter, false);
        unset($group);

	$group[]= $this->form->createElement("static", "emotion_eye_gaze_weighted", null);
        $group[]= $this->form->createElement("static", "emotion_eye_gaze_standard", null);
        $group[]= $this->form->createElement("static", "emotion_eye_gaze_percentile", null);
  	$this->form->addGroup($group, null, "Emotion and Eye Gaze", $this->_GUIDelimiter, false);
        unset($group);

        $group[]= $this->form->createElement("static", "communication_weighted", null);
        $group[]= $this->form->createElement("static", "communication_standard", null);
        $group[]= $this->form->createElement("static", "communication_percentile", null);
  	$this->form->addGroup($group, null, "Communication", $this->_GUIDelimiter, false);
        unset($group);


	$group[]= $this->form->createElement("static", "gestures_weighted", null);
        $group[]= $this->form->createElement("static", "gestures_standard", null);
        $group[]= $this->form->createElement("static", "gestures_percentile", null);
  	$this->form->addGroup($group, null, "Gestures", $this->_GUIDelimiter, false);
        unset($group);


	$group[]= $this->form->createElement("static", "sounds_weighted", null);
        $group[]= $this->form->createElement("static", "sounds_standard", null);
        $group[]= $this->form->createElement("static", "sounds_percentile", null);
  	$this->form->addGroup($group, null, "Sounds", $this->_GUIDelimiter, false);
        unset($group);

	$group[]= $this->form->createElement("static", "words_weighted", null);
        $group[]= $this->form->createElement("static", "words_standard", null);
        $group[]= $this->form->createElement("static", "words_percentile", null);
  	$this->form->addGroup($group, null, "Words", $this->_GUIDelimiter, false);
        unset($group);


	$group[]= $this->form->createElement("static", "understanding_weighted", null);
        $group[]= $this->form->createElement("static", "understanding_standard", null);
        $group[]= $this->form->createElement("static", "understanding_percentile", null);
  	$this->form->addGroup($group, null, "Understanding", $this->_GUIDelimiter, false);
        unset($group);


        $group[]= $this->form->createElement("static", "object_use_weighted", null);
        $group[]= $this->form->createElement("static", "object_use_standard", null);
        $group[]= $this->form->createElement("static", "object_use_percentile", null);
        $this->form->addGroup($group, null, "Object Use", $this->_GUIDelimiter, false);
        unset($group);


        $group[]= $this->form->createElement("static", "social_composite_score", null);
        $group[]= $this->form->createElement("static", "social_composite_standard", null);
        $group[]= $this->form->createElement("static", "social_composite_percentile", null);
        $this->form->addGroup($group, null, "Social Composite", $this->_GUIDelimiter, false);
        unset($group);


        $group[]= $this->form->createElement("static", "speech_composite_score", null);
        $group[]= $this->form->createElement("static", "speech_composite_standard", null);
        $group[]= $this->form->createElement("static", "speech_composite_percentile", null);
        $this->form->addGroup($group, null, "Speech Composite", $this->_GUIDelimiter, false);
        unset($group);


        $group[]= $this->form->createElement("static", "symbolic_composite_score", null);
        $group[]= $this->form->createElement("static", "symbolic_composite_standard", null);
        $group[]= $this->form->createElement("static", "symbolic_composite_percentile", null);
        $this->form->addGroup($group, null, "Symbolic Composite", $this->_GUIDelimiter, false);
        unset($group);


	$group[]= $this->form->createElement("static", "total_weighted_raw_score", null);
        $group[]= $this->form->createElement("static", "total_standard", null);
        $group[]= $this->form->createElement("static", "total_percentile", null);
  	$this->form->addGroup($group, null, "Total", $this->_GUIDelimiter, false);
        unset($group);
    }

    function score(): void{
    	if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
    		return;
    	}

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
    	$db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());
        $scores['score_validity'] = null;

        //=========================================================================//
        //                                                                         //
        //             Get the subject age in months for scoring                   //
        //                                                                         //
        //=========================================================================//
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

	$age = Utility::calculateAge($dob, $record["Date_taken"]);
        $age_months = $age['year'] * 12 + $age['mon'] + ($age['day']/30);
        //between 11.75 and 12
	if ($age_months >= 11.75 && $age_months <= 12)
        {
            $age_months = 12;
        }
        //between 12 and 24.75
        elseif ($age_months >12 && $age_months <= 24.75)
        {
            $age_months = 24;
        }
        //between 24.75 and 36
        elseif ($age_months > 24.75 && $age_months <= 36)
        {
            $age_months = 36;
        }

        else if($age_months>36)
        {
            $scores['score_validity'] ="Age not valid for scoring";
        }
        $age_months = round($age_months);

        if($scores['score_validity']!=null) {
            echo "Age not valid for the scoring. Please correct the age and try again. Don't worry, your data will be saved";
            echo "\n";
            return;
        }

        //============================================================================//
        //                                                                            //
  	//                             Calculate raw scores                           //
        //                                                                            //
        //============================================================================//
        $scores["q_1_gaze_shifts_raw_score"]              = $this->_countChecked($record, "q_1_gaze_shifts", [1,2,3,4,5,6]);
        $scores["q_2_shared_positive_affect_raw_score"]   = $this->_countChecked($record, "q_2_shared_positive_affect", [1,2,3,4,5,6]);
        $scores["q_3_gaze_point_following_raw_score"]     = $this->_countChecked($record, "q_3_gaze_point_following", [2,5]);

        $score = 0;
        for($i=1; $i<=6; $i++) {
             $wasActivityAdministered = $this->_wasActivityAdministered($record, "q_4_rate_of_communicating", $i);
             if (is_null($wasActivityAdministered)) {
                 $score = null;
                 break;
             }
             if (!$wasActivityAdministered) {
                $score = "Unable to score";
                break;
             }

             $score += (float) $record["q_4_rate_of_communicating_$i"];
        }
        $scores["q_4_rate_of_communicating_raw_score"] = $score;

        $scores["q_5_behaviour_regulation_raw_score"]     = $this->_countChecked($record, "q_5_behaviour_regulation", [1,2,3,4,5,6]);
        $scores["q_6_social_interaction_raw_score"]       = $this->_countChecked($record, "q_6_social_interaction", [1,2,3,4,5,6]);
        $scores["q_7_joint_attention_raw_score"]          = $this->_countChecked($record, "q_7_joint_attention", [1,2,3,4,5,6]);
        $scores["q_8_conventional_gestures_raw_score"]    = $this->_countChecked(
            $record,
            "q_8_conventional_gestures",
            ["gives", "shows", "pushes_pulls", "reaches", "points", "waves", "nods_head", "shakes_head"]
        );
        $scores["q_9_distal_gestures_raw_score"]          = $this->_countChecked($record, "q_9_distal_gestures", [1,2,3,4,5,6]);
        $scores["q_10_syllables_consonants_raw_score"]    = $this->_countChecked($record, "q_10_syllables_consonants", [1,2,3,4,5,6]);
        $scores["q_11_inventory_of_consonants_raw_score"] = $this->_countChecked(
            $record,
            "q_11_inventory_of_consonants",
            ["m", "n", "b_p", "d_t", "g_k", "w", "l", "y", "s", "sh"],
            false
        );
        $scores["q_12_words_raw_score"]                   = $this->_countChecked($record, "q_12_words", [1,2,3,4,5,6]);

        $scores["q_13_words_raw_score"] = $this->_countWords($record, "q_13_words_");
        if(empty($scores["q_13_words_raw_score"])){
            $scores["q_13_words_raw_score"]  = 0;
        }
        $scores["q_14_word_combos_raw_score"] = $this->_countChecked($record, "q_14_word_combos", [1,2,3,4,5,6]);
        $scores["q_15_word_combos_raw_score"] = $this->_countWords($record, "q_15_word_combos_");
        if(empty($scores["q_15_word_combos_raw_score"])){
            $scores["q_15_word_combos_raw_score"]  = 0;
        }

        $scores["q_17_action_schemes_raw_score"] = $this->_countCheckedNone($record, "q_17_action_schemes_", "q_17_action_schemes_none");
        $scores["q_18_actions_towards_other_raw_score"] = $this->_countActionTowardsOther($record, 6);
        $scores["q_19_sequence_action_schemes_raw_score"] = $this->_countAction1($record, 6);
        if($record["q_20_stacks_tower"]==="not_administered" || $record["q_20_stacks_tower"]==="probe_not_administered")
        {
            $scores["q_20_stacks_tower_raw_score"] = "Unable to score";
        }
        else{
            $scores["q_20_stacks_tower_raw_score"] = intval(substr($record["q_20_stacks_tower"], 0, 1));
        }

        $q_16_BestObject = null;
        $q_16_BestPerson = null;
        $q_16_BestBody   = null;

        // Q16: objects section
        if (!$this->_hasEmptyAnswer($record, "objects", 4)) {
            $nbNotAdministered = $this->_countUnanswered($record, "objects", 4);
            $prefix = "q_16_language_comp_objects";
            if ($nbNotAdministered == 1) {
                $q_16_BestObject = $record["{$prefix}_1"] == 1 && $record["{$prefix}_2"] == 1 && $record["{$prefix}_3"] == 1
                    ? $this->_sumBestRows($record, "objects", 3, 4)
                    : "Unable to score";
            } elseif ($nbNotAdministered == 2) {
                $q_16_BestObject = $record["{$prefix}_1"] == 0 && $record["{$prefix}_2"] == 0
                    ? $this->_sumBestRows($record, "objects", 3, 4)
                    : "Unable to score";
            } else {
                $q_16_BestObject = $nbNotAdministered != 0
                    ? "Unable to score"
                    : $this->_sumBestRows($record, "objects", 3, 4);
            }
        }

        // Q16: person section
        if (!$this->_hasEmptyAnswer($record, "person", 3)) {
            $nbNotAdministered = $this->_countUnanswered($record, "person", 3);
            $prefix = "q_16_language_comp_person";
            if ($nbNotAdministered == 1) {
                $q_16_BestPerson = ($record["{$prefix}_1"] == 0 && $record["{$prefix}_2"] == 0) || ($record["{$prefix}_1"] == 1 && $record["{$prefix}_2"] == 1)
                    ? $this->_sumBestRows($record, "person", 2, 3)
                    : "Unable to score";
            } else {
                $q_16_BestPerson = $nbNotAdministered != 0
                    ? "Unable to score"
                    : $this->_sumBestRows($record, "person", 2, 3);
            }
        }

        // Q16: body parts section
        if (!$this->_hasEmptyAnswer($record, "body_parts", 4)) {
            $nbNotAdministered = $this->_countUnanswered($record, "body_parts", 4);
            $prefix = "q_16_language_comp_body_parts";
            if ($nbNotAdministered == 1) {
                $q_16_BestBody = $record["{$prefix}_1"] == 1 && $record["{$prefix}_2"] == 1 && $record["{$prefix}_3"] == 1
                    ? $this->_sumBestRows($record, "body_parts", 3, 4)
                    : "Unable to score";
            } elseif ($nbNotAdministered == 2) {
                $q_16_BestBody = $record["{$prefix}_1"] == 0 && $record["{$prefix}_2"] == 0
                    ? $this->_sumBestRows($record, "body_parts", 3, 4)
                    : "Unable to score";
            } else {
                $q_16_BestBody = $nbNotAdministered != 0
                    ? "Unable to score"
                    : $this->_sumBestRows($record, "body_parts", 3, 4);
            }
        }

        $scores["q_16a_language_comp_object_raw_score"]      = $q_16_BestObject;
        $scores["q_16b_language_comp_person_name_raw_score"] = $q_16_BestPerson;
        $scores["q_16c_language_comp_body_parts_raw_score"]  = $q_16_BestBody;
	$scores["q_16_language_comp_body_parts_raw_score"]   = $this->_getWeightedSum($scores, [
            "q_16a_language_comp_object_raw_score"      => 1,
            "q_16b_language_comp_person_name_raw_score" => 1,
            "q_16c_language_comp_body_parts_raw_score"  => 1,
        ]);


        //======================================================================//
        //                                                                      //
    	//                       Calculate weighted scores                      //
        //                                                                      //
        //======================================================================//

        //--------------------------------//
        //     Gaze point following       //
        //--------------------------------//
        if (is_null($record["q_3_gaze_point_following_admin"])) {
            $scores["emotion_eye_gaze_weighted"] = null;
        } else {
            $scores["emotion_eye_gaze_weighted"] = $record["q_3_gaze_point_following_admin"] == 'no'
                ? 'Unable to score'
                : $this->_getWeightedSum($scores, [
                     "q_1_gaze_shifts_raw_score"            => 1,
                     "q_2_shared_positive_affect_raw_score" => 1,
                     "q_3_gaze_point_following_raw_score"   => 3
                  ]);
       }

        //--------------------------------//
        //         Communication          //
        //--------------------------------//
        $scores["communication_weighted"] = $this->_getWeightedSum(
            $scores,
            [
                "q_4_rate_of_communicating_raw_score" => ((float)1/3),
                "q_5_behaviour_regulation_raw_score" => 1,
                "q_6_social_interaction_raw_score"   => 1,
                "q_7_joint_attention_raw_score"      => 1
            ]
        );

        //--------------------------------//
        //             Gestures           //
        //--------------------------------//
        $scores["gestures_weighted"] = $this->_getWeightedSum(
            $scores,
            ["q_8_conventional_gestures_raw_score" => 2, "q_9_distal_gestures_raw_score" => 1]
        );

        //--------------------------------//
        //             Sounds             //
        //--------------------------------//
        $scores["sounds_weighted"] = $this->_getWeightedSum(
            $scores,
            ["q_10_syllables_consonants_raw_score" => 1, "q_11_inventory_of_consonants_raw_score" => 2]
        );

        //--------------------------------//
        //             Words              //
        //--------------------------------//
        $scores["words_weighted"] = $this->_getWeightedSum(
            $scores,
            [
              "q_12_words_raw_score"       => 1,
              "q_13_words_raw_score"       => 0.5,
              "q_14_word_combos_raw_score" => 1,
              "q_15_word_combos_raw_score" => 1
            ]
        );

        //-----------------------------------//
        //          Understanding            //
        //-----------------------------------//
        $scores["understanding_weighted"] = $this->_getWeightedSum(
            $scores,
            [
              "q_16a_language_comp_object_raw_score"      => 3,
              "q_16b_language_comp_person_name_raw_score" => 3,
              "q_16c_language_comp_body_parts_raw_score"  => 3,
            ]
        );


        //--------------------------------//
        //          Object Use            //
        //--------------------------------//
        if($record["q_20_stacks_tower"]==="not_administered" || $record["q_20_stacks_tower"]==="probe_not_administered") {
            $scores["object_use_weighted"] = "Unable to score";
        } else {
            $scores["object_use_weighted"] =  $this->_getWeightedSum(
                $scores,
                [
                  "q_17_action_schemes_raw_score"          => 1,
                  "q_18_actions_towards_other_raw_score"   => 1,
                  "q_19_sequence_action_schemes_raw_score" => 1,
                  "q_20_stacks_tower_raw_score"            => 1
                ]
            );
        }

        //--------------------------------//
        //       Social Composite         //
        //--------------------------------//
        if (is_null($record["q_3_gaze_point_following_admin"])) {
           $scores["social_composite_score"] = null;
        } else {
            $scores["social_composite_score"] = $record["q_3_gaze_point_following_admin"] == 'no'
                ? 'Unable to score'
                : $this->_getWeightedSum(
                      $scores,
                      ["emotion_eye_gaze_weighted" => 1, "communication_weighted" => 1, "gestures_weighted" => 1]
                  );
        }

        //--------------------------------//
        //       Speech Composite         //
        //--------------------------------//
	$scores["speech_composite_score"] = $this->_getWeightedSum(
            $scores,
            ["sounds_weighted" => 1, "words_weighted" => 1]
        );

        //--------------------------------//
        //       Symbolic Composite       //
        //--------------------------------//
        if($record["q_20_stacks_tower"]==="not_administered" || $record["q_20_stacks_tower"]==="probe_not_administered") {
            $scores["symbolic_composite_score"] = "Unable to score";
        } else {
	    $scores["symbolic_composite_score"] = $this->_hasActivityNotAdministered($record)
                ? "Unable to score"
                : $this->_getWeightedSum(
                      $scores,
                      ["understanding_weighted" => 1, "object_use_weighted" => 1]
                  );
        }

        //--------------------------------//
        //              Total             //
        //--------------------------------//
	$scores["total_weighted_raw_score"] = $this->_hasActivityNotAdministered($record)
            ? "Unable to score"
            : $this->_getWeightedSum(
                  $scores,
                  ["social_composite_score" => 1, "speech_composite_score" => 1, "symbolic_composite_score" => 1]
              );

        //=================================================================================//
        //                                                                                 //
	//                Compute standard scores and percentile ranks                     //
        //                                                                                 //
        //=================================================================================//
        list($scores["emotion_eye_gaze_standard"], $scores["emotion_eye_gaze_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "emotion_eye_gaze_weighted", $age_months);
        list($scores["communication_standard"], $scores["communication_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "communication_weighted", $age_months);
        list($scores["gestures_standard"], $scores["gestures_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "gestures_weighted", $age_months);
        list($scores["sounds_standard"], $scores["sounds_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "sounds_weighted", $age_months);
        list($scores["words_standard"], $scores["words_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "words_weighted", $age_months);
        list($scores["understanding_standard"], $scores["understanding_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "understanding_weighted", $age_months);
        list($scores["object_use_standard"], $scores["object_use_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "object_use_weighted", $age_months);
        list($scores["social_composite_standard"], $scores["social_composite_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "social_composite_score", $age_months);
        list($scores["speech_composite_standard"], $scores["speech_composite_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "speech_composite_score", $age_months);
        list($scores["symbolic_composite_standard"], $scores["symbolic_composite_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "symbolic_composite_score", $age_months);
        list($scores["total_standard"], $scores["total_percentile"]) =
            $this->_getStdAndPercentile($db, $scores, "total_weighted_raw_score", $age_months);


	// save scores
	$result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));

    }    // end score function

    /**
     * Determines if one of the understanding sexction has an empty answer or not.
     *
     * @param array  $record  form values.
     * @param string $section section ID.
     * @param int    $nbRows  number of rows in the section.
     *
     * @return bool true if the section has an empty answer, false otherwise.
     */
    function _hasEmptyAnswer(array $record, string $section, int $nbRows)
    {
        for ($i=1; $i<=$nbRows; $i++) {
            if ($record["q_16_language_comp_{$section}_$i"] == "") {
                return true;
            }
        }

        return false;
    }

    /**
     * Sets the std score and percentile associated to a given subscale (raw score).
     *
     * @param        $db        database handle.
     * @param array  $scores    array of score values.
     * @param string $subScale  a subScale.
     * @param string $ageMonths age of candidate in months.
     *
     * @return bool true if the section has an empty answer, false otherwise.
     */
    function _getStdAndPercentile($db, array $scores, string $subScale, string $age_months) {
        if (is_null($scores[$subScale])) {
            return [null, null];
        }
        if ($scores[$subScale] === "Unable to score") {
            return ["Unable to score", "Unable to score"];
        }

        $std        = null;
        $percentile = null;
        $query = "SELECT * FROM csbs_lookup WHERE age_months=$age_months  AND score_weighted=$scores[$subScale] AND subscale='$subScale'";
        $record = $db->pselectRow($query, array());
        if (array_key_exists('score_standard',$record)) {
            $std = $record['score_standard'];
        }
        if (array_key_exists('score_percentile',$record)) {
            $percentile = $record['score_percentile'];
        }

        return [$std, $percentile];
    }

    /**
     * Determines if at least one of the activities was not administered.
     * 
     * @param array $record array of form values.
     *
     * @return bool true if there is at least an activity that was not administered, false otherwise.
     */
    function _hasActivityNotAdministered(array $record)
    {
        foreach (self::ACTIVITIES as $activity) {
            if ($record["{$activity}_admin"] === "not_admin") {
                return true;
            }
        }

        return false;
    }

    /**
     * Compute the weighted sum of a set of scores.
     *
     * @param array $scores      all the score values.
     * @param array $weightedIDs set of IDs (with associated weigh) of the scores to sum.
     *
     * @return float weighted sum.
     */
    function _getWeightedSum(array $scores, array $weightedIDs)
    {
        $totalScore = 0;
        foreach($weightedIDs as $id => $weight) {
            $currentScore = $scores[$id];
            if (is_null($currentScore) || $currentScore === "Unable to score") {
                return $currentScore;
            }

            $totalScore += $currentScore * (float)$weight;
        }

        // Round up to next integer
        return number_format($totalScore, 0);
    }

    function _page1(){
        //====================================
        //
	//    Administration of activities
        //
        //====================================
        $this->form->addElement("header", null, "Administration of activities");

        //----------------
        // Section header
        //----------------
        $group = [];
        $group[] = $this->createLabel("Administration");
        $group[] = $this->createLabel("");
        $group[] = $this->createLabel("Comments");
        $this->addGroup($group, "blank_header_group", "Activity", false, null);
        unset($group);

        //----------------------------
        // Line for each activity
        //----------------------------
        $this->addActivityAdminSection("wind_up", "1. Wind-up toy");
        $this->addActivityAdminSection("balloon", "2. Balloon");
        $this->addActivityAdminSection("bubbles", "3. Bubbles");
        $this->addActivityAdminSection("jar"    , "4. Jar");
        $this->addActivityAdminSection("books"  , "5. Books");
        $this->addActivityAdminSection("play"   , "6. Play");


        //=========================================
        //
        //          Emotion and Eye Gaze
        //
        //=========================================
        $this->form->addElement("header", null, "Emotion and Eye Gaze");
        $this->_printHeaderCols(
            "emotion_eye_glaze",
            [
             "Wind-up toy" => 0,
             "Balloon"     => 0,
             "Bubbles"     => 0,
             "Jar"         => 0,
             "Books"       => 0,
             "Play"        => 0,
             "Score"       => 0
            ]
        );

        //-----------------
        // 1. Gaze shifts
        //-----------------
        $group = [];
        for($int = 1; $int <= 6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_1_gaze_shifts_$int", null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_1_gaze_shifts_raw_score");
        $this->addGroup($group, "q_1_gaze_shifts_group", "1. Gaze shifts", null, false);
        unset($group);

        //---------------------------
        // 2. Shared Positive Affect
        //---------------------------
        for($int = 1; $int <= 6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_2_shared_positive_affect_$int", null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_2_shared_positive_affect_raw_score");
        $this->form->addGroup($group, "q_2_shared_positive_affect_group", "2. Shared positive affect", null, false);
        unset($group);

        //--------------------------
        // 3. Gaze point/following
        //--------------------------
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("advcheckbox", "q_3_gaze_point_following_2", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("advcheckbox", "q_3_gaze_point_following_5", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", "q_3_gaze_point_following_raw_score");

        $this->form->addGroup($group, "q_3_gaze_point_following_2_group", "3. Gaze/point following", null, false);
        unset($group);

        $group[] = $this->form->createElement("select", "q_3_gaze_point_following_admin", "", [null=>"", "yes"=>"Yes", "no"=>"No"]);
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $this->form->addGroup($group, "q_3_gaze_point_following_admin_group", "&emsp;Gaze/point following was administered", null, false);
        unset($group);

        $group[] = $this->form->createElement("static", "emotion_eye_gaze_weighted");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $this->form->addGroup($group, "emotion_eye_gaze_weighted_group", "&emsp;<u>Emotion and eye gaze weighted score</u>:", null, false);
        unset($group);

        //=========================================
        //
        //            Communication
        //
        //=========================================
        $this->form->addElement("header", null, "Communication");
        $this->_printHeaderCols(
            "communication",
            [
             "Wind-up toy" => 0,
             "Balloon"     => 0,
             "Bubbles"     => 0,
             "Jar"         => 0,
             "Books"       => 0,
             "Play"        => 0,
             "Score"       => 0
            ]
        );

        $group = [];
        for($int = 1; $int <=6; $int++) {
            $group[] = $this->form->createElement("select", "q_4_rate_of_communicating_" . $int, "", array(null=>"", "not_answered"=>"N/A", "0"=>"0", "1"=>"1", "2"=>"2", "3"=>"3+"));
            $this->XINRegisterRule("q_4_rate_of_communicating_" . $int, array("q_4_rate_of_communicating_" . $int . "{@}=={@}"), "Responses are required for each sampling opportunity.", "q_4_rate_of_communicating_group");
        }
        $group[] = $this->form->createElement("static", "q_4_rate_of_communicating_raw_score");
        $this->form->addGroup($group, "q_4_rate_of_communicating_group", "4. Rate of communication", null, false);
        unset($group);

        for($int = 1; $int <= 6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_5_behaviour_regulation_" . $int, null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_5_behaviour_regulation_raw_score");
        $this->form->addGroup($group, null, "5. Behaviour regulation", null, false);
        unset($group);

        for($int = 1; $int <= 6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_6_social_interaction_" . $int, null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_6_social_interaction_raw_score");
        $this->form->addGroup($group, null, "6. Social interaction", null, false);
        unset($group);

        for($int = 1; $int <= 6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_7_joint_attention_" . $int, null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_7_joint_attention_raw_score");
        $this->form->addGroup($group, null, "7. Joint attention", null, false);
        unset($group);

        $group[] = $this->form->createElement("static", "communication_weighted");
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $this->form->addGroup($group, "communication_weighted_group", "&nbsp;&emsp;<u>Communication weighted score</u>:", null, false);
        unset($group);

        //***********************************************************************//
        //                                                                       //
        //                                 Gestures                              //
        //                                                                       //
        //***********************************************************************//
        $this->form->addElement("header", null, "Gestures");
        $this->_printHeaderCols(
            "gestures",
            [
             "Wind-up toy<br>(gives)"          => 0,
             "Balloon<br>(shows)"              => 0,
             "Bubbles/Jar<br>(pushes/pulls)"   => 0,
             "Books/Play<br>(reaches)"         => 0,
            ]
        );

        //---------------------------------------------//
        //     8. Inventory of conventional gestures   //
        //---------------------------------------------//
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_gives", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_shows", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_pushes_pulls", null, null, null, array("unchecked", "checked"));
	$group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_reaches", null, null, null, array("unchecked", "checked"));
        $this->form->addGroup($group, "q_8_conventional_gestures_group1", "8. Inventory of conventional gestures", null, false);
        unset($group);

        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "gestures2",
            [
             "Wind-up toy<br>(points)"       => 0,
             "Balloon<br>(waves)"            => 0,
             "Bubbles/Jar<br>(nods head)"    => 0,
             "Books/Play<br>(shakes head)"   => 0,
            ]
        );
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_points", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_waves", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_nods_head", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_8_conventional_gestures_shakes_head", null, null, null, array("unchecked", "checked"));
        $this->form->addGroup($group, "q_8_conventional_gestures_group2", "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;", null, false);
        unset($group);

        // This adition of an empty group adds a blank line
        $this->form->addGroup([], null, "&emsp;", null, false);

        //---------------------------------------------//
        //             9. Distal gestures              //
        //---------------------------------------------//
        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "distgest",
            [
             "Wind-up toy" => 0,
             "Balloon"     => 0,
             "Bubbles"     => 0,
             "Jar"         => 0,
             "Books"       => 0,
             "Play"        => 0,
             "Score"       => 0
            ]
        );

        for($int = 1; $int <=6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_9_distal_gestures_$int", null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_9_distal_gestures_raw_score");
        $this->form->addGroup($group, "q_9_distal_gestures_group", "9. Distal gestures", null, false);
        unset($group);

        $group[] = $this->form->createElement("static", "gestures_weighted");
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $this->form->addGroup($group, "gestures_weighted_group", "&nbsp;&emsp;<u>Gestures weighted score</u>:", null, false);
        unset($group);

        //***********************************************************************//
        //                                                                       //
        //                                   Sounds                              //
        //                                                                       //
        //***********************************************************************//
        $this->form->addElement("header", null, "Sounds");
        $this->_printHeaderCols(
            "sounds",
            [
             "Wind-up toy" => 0,
             "Balloon"     => 0,
             "Bubbles"     => 0,
             "Jar"         => 0,
             "Books"       => 0,
             "Play"        => 0,
             "Score"       => 0
            ]
        );

        //---------------------------------------//
        //      10. Syllables with consonants    //
        //---------------------------------------//
        for($int = 1; $int <=6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_10_syllables_consonants_$int", null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_10_syllables_consonants_raw_score");
        $this->form->addGroup($group, "q_10_syllables_consonants_group1", "10. Syllables with consonants", null, false);
        unset($group);

        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "sounds_1",
            [
             "/m/"    => 12,
             "/n/"    => 5,
             "/b|p/"  => 10,
             "/d|t/"  => 5,
             "/g|k/"  => 5,
             "Score"  => 0
            ]
        );

        //---------------------------------------//
        //      11. Inventory of consonants      //
        //---------------------------------------//
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_m", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_n", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_b_p", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_d_t", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_g_k", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("static", "q_11_inventory_of_consonants_raw_score");
        $this->form->addGroup($group, "q_11_inventory_of_consonants_group1", "11. Inventory of consonants", null, false);
        unset($group);

        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "sounds_2",
            [
             "/w/"                => 15,
             "/l/"                => 5,
             "/y/"                => 5,
             "/s/"                => 5,
             "/sh/"               => 5,
             "&emsp;&emsp;&emsp;" => 0,
            ]
        );
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_w", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_l", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_y", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_s", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_11_inventory_of_consonants_sh", null, null, null, array("unchecked", "checked"));
        $this->form->addGroup($group, "q_11_inventory_of_consonants_group2", "&emsp;", null, false);
        unset($group);

        //---------------------------------------//
        //      Sounds weighted score            //
        //---------------------------------------//
        $group[] = $this->form->createElement("static", "sounds_weighted");
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $this->form->addGroup($group, "sounds_weighted_group", "&emsp;&emsp;<u>Sounds weighted score</u>:", null, false);
        unset($group);

        //***********************************************************************//
        //                                                                       //
        //                                   Words                               //
        //                                                                       //
        //***********************************************************************//
        $this->form->addElement("header", null, "Words");
        $this->_printHeaderCols(
            "words",
            [
             "Wind-up toy" => 0,
             "Balloon"     => 5,
             "Bubbles"     => 5,
             "Jar"         => 10,
             "Books"       => 3,
             "Play"        => 5,
             "Raw Score"   => 0
            ]
        );

        //---------------------------------------//
        //              12. Words                //
        //---------------------------------------//
        for($int = 1; $int <=6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_12_words_" . $int, null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_12_words_raw_score");
        $this->form->addGroup($group, "q_12_words_group", "12. Words", null, false);
        unset($group);

        //---------------------------------------//
        //     13. Inventory of words            //
        //---------------------------------------//
        for($row = 0; $row <= 3; $row++) {
            for($col = 1; $col <= 4; $col++) {
                $group[] = $this->form->createElement("text", "q_13_words_" . ($col + ($row * 4)) );
            }
            if ($row == 0) {
                $label = "13. Inventory of words";
                $group[] = $this->form->createElement("static", null, null,"");
                $group[] = $this->form->createElement("static", null, null,"");
                $group[] = $this->form->createElement("static", "q_13_words_raw_score");
            } else {$label = null;}
            $this->form->addGroup($group, "q_13_words_{$row}_group", $label, null, false);
            unset($group);
            for($int = 1; $int <= 16; $int++) {
               $this->XINRegisterRule("q_13_words_" . $int, array("q_13_words_" . $int . "{@}=={@}NEVER_REQUIRED"), '', "q_13_words_" . intval($int / 4) . "_group");
            }
        }

        //---------------------------------------//
        //      14. Word combinations            //
        //---------------------------------------//
        for($int = 1; $int <=6; $int++) {
            $group[] = $this->form->createElement("advcheckbox", "q_14_word_combos_" . $int, null, null, null, array("unchecked", "checked"));
        }
        $group[] = $this->form->createElement("static", "q_14_word_combos_raw_score");
        $this->form->addGroup($group, "q_14_word_combos_group", "14. Word combinations", null, false);
        unset($group);

        //---------------------------------------//
        //   15. Inventory of word combos        //
        //---------------------------------------//
        for($row = 0; $row <= 3; $row++) {
            for($col = 1; $col <= 2; $col++) {
                $group[] = $this->form->createElement("text", "q_15_word_combos_" . ($col + ($row * 2)) );
            }
            if ($row == 0) {$label = "15. Inventory of word combos";
                $group[] = $this->form->createElement("static", null, null,"");
                $group[] = $this->form->createElement("static", null, null,"");
                $group[] = $this->form->createElement("static", null, null,"");
                $group[] = $this->form->createElement("static", null, null,"");
                $group[] = $this->form->createElement("static", "q_15_word_combos_raw_score");
            } else {$label = null;}
            $this->form->addGroup($group, "q_15_word_combos_{$row}_group", $label, null, false);
            unset($group);
            for($int = 1; $int <= 8; $int++) {
               $this->XINRegisterRule("q_15_word_combos_" . $int, array("q_15_word_combos_" . $int . "{@}=={@}NEVER_REQUIRED"), '', "q_15_word_combos_" . intval($int / 2) . "_group");
            }
        }

        //---------------------------------------//
        //      Words weighted score             //
        //---------------------------------------//
        $group[] = $this->form->createElement("static", "words_weighted");
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $group[] = $this->form->createElement("static", null, null, null);
        $this->form->addGroup($group, "words_weighted_group", "<u>Words weighted score</u>:", null, false);
        unset($group);
        $this->form->addFormRule(array($this,'validatePage1'));
    }

    function addActivityAdminSection(string $adminSectionID, string $adminSectionLabel) {
        $adminChoices =  array(
            null              => "",
            "fully_admin"     => "Fully Administered",
            "partially_admin" => "Partially Administered (please specify)",
            "not_admin"       => "Not Administered"
        );

        $group = [];
        $group[] = $this->createSelect("{$adminSectionID}_admin", null, $adminChoices);
        $group[] = $this->createLabel("If partially administered, specify:");
        $group[] = $this->createTextArea("{$adminSectionID}_admin_comment", null);
        $this->addGroup($group, "{$adminSectionID}_admin_group", $adminSectionLabel, false, null);
        $this->XINRegisterRule(
            "{$adminSectionID}_admin",
            ["{$adminSectionID}_admin_comment{@}=={@}"],
            "Please select an administration status",
            "{$adminSectionID}_admin_group");
        $this->XINRegisterRule("{$adminSectionID}_admin_comment", array("{$adminSectionID}_admin_comment{@}=={@}NEVER_REQUIRED"));
    }

    function _sumBestRows($values, $name, $bestrows, $numrows) {
        $BestSoFar = array();
        for($row = 1; $row <= $numrows; $row++) {
            if(!is_numeric($values["q_16_language_comp_{$name}_{$row}"])) {
                continue;
            }

            if(count($BestSoFar) == $bestrows) {
                // If we've already found n numbers, check if this one's better than
                // one of the previous ones
                for($i = 0; $i < count($BestSoFar); $i++) {
                    if($BestSoFar[$i] < $values["q_16_language_comp_{$name}_{$row}"]) {
                        $BestSoFar[$i] = $values["q_16_language_comp_{$name}_{$row}"];
                        break;
                    }
                }
            } else {
                // Otherwise, just take this row since we haven't even found n
                // yet
                $BestSoFar[] = $values["q_16_language_comp_{$name}_{$row}"];
            }
        }
        return array_sum($BestSoFar);
    }

    // For scoring q_16
    function _countUnanswered($values, $name, $rows) {
        $number = 0;
        for($row = 1; $row <= $rows; $row++) {
            if($values["q_16_language_comp_{$name}_{$row}"] === null || $values["q_16_language_comp_{$name}_{$row}"] === '' ||
                $values["q_16_language_comp_{$name}_{$row}"] === 'NA') {
                $number++;
            }
        }
        return $number;
    }
    // For scoring q_18
    function _countActionTowardsOther($values, $rows) {
        $number = 0;
        for($row = 1; $row <= $rows; $row++) {
            if($values["q_18_action_towards_other_{$row}"] !== '' && 
                    $values["q_18_action_towards_other_{$row}"] !== 'none' && !is_null($values["q_18_action_towards_other_{$row}"])) {
                $number++;
            }
        }
        return $number;
    }
    // For scoring q_19
    function _countAction1($values, $rows) {
        $number = 0;
        for($row = 1; $row <= $rows; $row++) {
            if($values["q_19_sequence_action_schemes_{$row}_action1"] !== '' && 
                    $values["q_19_sequence_action_schemes_{$row}_action1"] !== 'none' && !is_null($values["q_19_sequence_action_schemes_{$row}_action1"])) {
                $number++;
            }
        }
        return $number;
    }

    function _countTableZeros($values, $name, $rows) {
        $number = 0;
        for($row = 1; $row <= $rows; $row++) {
            // Use === to ensure that null isn't interpreted as 0.
            // Always getting a string, since we're getting values from a form.
            // But add or === to 0 too, just in case somehow the data gets converted
            // to an int (ie when pulling from the database)
            if($values["q_16_language_comp_{$name}_{$row}"] === "0" || $values["q_16_language_comp_{$name}_{$row}"] === 0) {
                $number++;
            }
        }
        return $number;
    }

    function _addTableRow($desc, $name, $rows, $scoreID, $scoreTitle) {
        for($row = 1; $row <= $rows; $row++) {
            $groupname = "q_16_language_comp_{$name}_{$row}_group";
            $elname    = "q_16_language_comp_{$name}_{$row}_name";
            $scorename = "q_16_language_comp_{$name}_{$row}";

            $group[] = $this->form->createElement('static', null, null, "$desc #$row");
            $group[] = $this->form->createElement("text", $elname);
            $group[] = $this->form->createElement("select", $scorename, null, array('' => '', 0 => 0, 1 => 1, 'NA' => 'Not Administered'));
            // Require score

            $this->XINRegisterRule($scorename, array("$elname{@}!={@}NULL"), "Score required.", $groupname);
            $this->XINRegisterRule($elname, array("$elname{@}=={@}NEVER_REQUIRED"), "Name required.", $groupname);
            $this->form->addGroup($group, $groupname, null, null, false);
            unset($group);
        }

        $group[] = $this->form->createElement("static", $scoreID);
        $group[] = $this->form->createElement("static", null, null, null,"");
        $group[] = $this->form->createElement("static", null, null, null,"");

        $this->form->addGroup($group, "{$scoreID}_group", "&emsp;&emsp;<u>$scoreTitle</u>", null, false);
        unset($group);

    }

    function _addNoActionsPerformed($element, $actions_array, $row=1) {
        if($row == 1) {
            return $this->form->createElement("select", $element, null, array_merge($actions_array, array('none' => "No actions performed")));
        }
        return $this->form->createElement("select", $element, null, array_merge($actions_array, array('none' => "No more actions performed")));
    }
    function _page2() {
        //===========================================================//
        //                                                           //
        //                      Understanding                        //
        //                                                           //
        //===========================================================//
        $this->form->addElement("header", null, "Understanding");
        $this->_printHeaderCols(
            "understanding",
            [
             ""      => 0,
             "Item"  => 0,
             "Score"  => 0,
            ]
        );

        //-----------------------------------------//
        //      16. Language comprehension         //
        //-----------------------------------------//
        $group[] = $this->form->createElement("static", null, null, null,"");
        $group[] = $this->form->createElement("static", null, null, null,"");
        $group[] = $this->form->createElement("static", null, null, null,"");

        $this->form->addGroup($group, "q_16_language_comp_objects_headers", "16. Language comprehension", null, false);
        unset($group);

        $this->_addTableRow("Object", "objects", 4, "q_16a_language_comp_object_raw_score", "Object Raw Score:");
        $this->_addTableRow("Person Name", "person", 3, "q_16b_language_comp_person_name_raw_score", "Person Name Raw Score:");
        $this->_addTableRow("Body Parts", "body_parts", 4, "q_16c_language_comp_body_parts_raw_score", "Body Parts Raw Score:");


        //===========================================================//
        //                                                           //
        //                   Object Use                              //
        //                                                           //
        //===========================================================//
        $this->form->addElement("header", null, "Object Use");
        $this->_printHeaderCols(
            "object_use_1",
            [
             "puts in"             => 0,
             "puts on"             => 0,
             "drinks with bottle"  => 0,
             "drinks with cup"     => 0,
             "hugs"                => 0,
             "kisses"              => 0
            ]
        );

        //---------------------------------------------------//
        //    17. Inventory of action schemes - Line 1       //
        //---------------------------------------------------//
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_puts_in", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_puts_on", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_drinks_with_bottle", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_drinks_with_cup", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_hugs", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_kisses", null, null, null, array("unchecked", "checked"));

        $this->form->addGroup($group, "q_17_action_schemes_group_1", "17. Inventory of action<br>schemes", null, false);
        unset($group);

        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "object_use_2",
            [
             "feeds with utensils"  => 0,
             "feeds with bowl"  => 0,
             "stirs"  => 0,
             "scoops"  => 0,
             "pours"  => 0,
             "other" => 0,
             "(if other, specify)" => 0,
             "none" => 0
            ]
        );

        //---------------------------------------------------//
        //    17. Inventory of action schemes - Line 2       //
        //---------------------------------------------------//
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_feeds_with_utensil", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_feeds_with_bowl", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_stirs", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_scoops", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_pours", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("advcheckbox", "q_17_action_schemes_other", null, null, null, array("unchecked", "checked"));
        $group[] = $this->form->createElement("text", "q_17_action_schemes_other_specify");
        $group[] =& $this->form->createElement("advcheckbox", "q_17_action_schemes_none", null, null, null, array("unchecked", "checked"));

        $this->form->addGroup($group, "q_17_action_schemes_group_2", "&emsp;", null, false);
        unset($group);

        $this->XINRegisterRule("q_17_action_schemes_other_specify", array("q_17_action_schemes_other{@}=={@}checked"), "Must specify other", "q_17_action_schemes_group_2");

        // This adition of an empty group adds a blank line 
        $this->form->addGroup($group, null, "&emsp;", null, false);

        //------------------------------------------------------//
        //    17. Inventory of action schemes - Raw score       //
        //------------------------------------------------------//
        $group[] = $this->form->createElement("static", "q_17_action_schemes_raw_score");
        for ($i=1; $i<=7; $i++) {
            $group[] = $this->form->createElement("static", null, null, null,"");
        }
        $this->form->addGroup($group, "q_17_action_schemes_raw_score_group", "&emsp;<u>Object Use Raw Score</u>:", null, false);
        unset($group);


        //------------------------------------------------------//
        //    18. Action schemes towards other                  //
        //------------------------------------------------------//
        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "action_towards_other",
            [
             "Action"       => 0,
             "Agent"        => 0,
             "Other Agent"  => 0,
            ]
        );

        $this->form->addGroup($group, "q_18_action_towards_other_group{$i}", "18. Action schemes towards other", null, false);

        //------------------------------------------------------//
        //    18. Action schemes towards other - Lines 1..6     //
        //------------------------------------------------------//
        $actions_array = array(
            '' => '',
            'puts_in' => '1. Puts in',
            'puts_on' => '2. Puts on',
            'drinks_with_bottle' => '3. Drinks with bottle',
            'drinks_with_cup' => '4. Drinks with cup',
            'hugs' => '5. Hugs',
            'kisses' => '6. Kisses',
            'feeds_with_utensil' => '7. Feeds with utensil',
            'feeds_with_bowl' => '8. Feeds with bowl',
            'stirs' => '9. Stirs',
            'scoops' => '10. Scoops',
            'pours' => '11. Pours',
            'other' => '12. Other'
        );
        for($i = 1; $i <= 6; $i++) {
            $group[] = $this->_addNoActionsPerformed("q_18_action_towards_other_{$i}", $actions_array, $i);
            $group[] = $this->form->createElement("select", "q_18_action_towards_other_{$i}_agent", null, array(
                '' => '',
                'parent' => 'Parent',
                'clinician' => 'Clinician',
                'toy' => 'Toy',
                'other' => 'Other (Specify)'
            ));
            $group[] = $this->form->createElement("text", "q_18_action_towards_other_{$i}_agent_specify");
            $this->XINRegisterRule("q_18_action_towards_other_{$i}_agent_specify", array("q_18_action_towards_other_{$i}_agent{@}=={@}other"), "Specify agent required.", "q_18_action_towards_other_group{$i}");
            // Require the first dropdown. Even though XIN rules requires things by default, we explicitly require it
            // to make sure the error message shows up, since it's part of a group.
            if($i == 1) {
                $this->XINRegisterRule("q_18_action_towards_other_{$i}", array("q_18_action_towards_other_{$i}{@}=={@}"), "Required.", "q_18_action_towards_other_group{$i}");
            } else {
                // Require dropdown n if n-1 is answered and not 'No (more) actions performed'
                $this->XINRegisterRule("q_18_action_towards_other_{$i}", array("q_18_action_towards_other_" . ($i-1) . "{@}!={@}none", "q_18_action_towards_other_" . ($i-1) . "{@}!={@}"), "Required.", "q_18_action_towards_other_group{$i}");
            }
            // Require the second dropdown if the first one is answered
            $this->XINRegisterRule("q_18_action_towards_other_{$i}_agent", array("q_18_action_towards_other_{$i}{@}!={@}", "q_18_action_towards_other_{$i}{@}!={@}none"), "Agent required.", "q_18_action_towards_other_group{$i}");
            $this->form->addGroup($group, "q_18_action_towards_other_group{$i}", null, null, false);
            unset($group);
        }

        //------------------------------------------------------//
        //    18. Action schemes towards other - Raw score      //
        //------------------------------------------------------//
        $group[] = $this->form->createElement("static", "q_18_actions_towards_other_raw_score");
        $group[] = $this->form->createElement("static", null, null, "");
        $group[] = $this->form->createElement("static", null, null, "");
        $this->form->addGroup($group,"q_18_actions_towards_other_raw_score_group","&emsp;&emsp;<u>Actions Towards Other Raw Score</u>:", null, false);
        unset($group);


        //------------------------------------------------------//
        //    19. Sequence action schemes                       //
        //------------------------------------------------------//
        $this->form->addElement("header", null, "");
        $this->_printHeaderCols(
            "sequence_action_schemes",
            [
             "1st Action"   => 0,
             "2nd Action"   => 0,
            ]
        );

        //------------------------------------------------------//
        //    19. Sequence action schemes - Lines 1..6          //
        //------------------------------------------------------//
        $this->form->addGroup($group, "q_19_sequence_action_schemes_headers", "19. Sequence action schemes", null, false);
        unset($group);
        for($i = 1; $i <= 6; $i++) {
            $group[] = $this->_addNoActionsPerformed("q_19_sequence_action_schemes_{$i}_action1", $actions_array, $i);
            $group[] = $this->form->createElement("select", "q_19_sequence_action_schemes_$i" . "_action2", null, $actions_array);
            // Require the first dropdown. Even though XIN rules requires things by default, we explicitly require it
            // to make sure the error message shows up, since it's part of a group.
            if($i == 1) {
                $this->XINRegisterRule("q_19_sequence_action_schemes_{$i}_action1", array("q_19_sequence_action_schemes_{$i}_action1{@}=={@}"), "Required.", "q_19_sequence_action_schemes_group{$i}");
            } else {
                // Require dropdown n if n-1 is answered and not 'No (more) actions performed'
                $this->XINRegisterRule("q_19_sequence_action_schemes_{$i}_action1", array("q_19_sequence_action_schemes_" . ($i-1) . "_action1{@}!={@}none", "q_19_sequence_action_schemes_" . ($i-1) . "_action1{@}!={@}"), "Required.", "q_19_sequence_action_schemes_group{$i}");
            }
            $this->XINRegisterRule("q_19_sequence_action_schemes_{$i}_action2", array("q_19_sequence_action_schemes_{$i}_action1{@}!={@}none", "q_19_sequence_action_schemes_{$i}_action1{@}!={@}"), "Action 2 Required.", "q_19_sequence_action_schemes_group{$i}");
            $this->form->addGroup($group, "q_19_sequence_action_schemes_group{$i}", null, $this->_GUIDelimiter, false);
            unset($group);
        }

        //------------------------------------------------------//
        //    19. Sequence action schemes - Raw score           //
        //------------------------------------------------------//
        $group[] = $this->form->createElement("static", "q_19_sequence_action_schemes_raw_score");
        $group[] = $this->form->createElement("static", null, null, "");
        $this->form->addGroup($group,"q_19_sequence_action_schemes_raw_score_group","&emsp;&emsp;<u>Sequence Action Schemes Raw Score</u>:", null, false);
        unset($group);


 
        $this->form->addGroup([], "q_20_stacks_tower_group1", "&emsp;", null, false);
        $this->form->addGroup([], "q_20_stacks_tower_group2", "&emsp;", null, false);

        //------------------------------------------------------//
        //   20. Stacks tower fo blocks                         //
        //------------------------------------------------------//
        $group[] = $this->form->createElement("select", "q_20_stacks_tower", null, array(null=>"", "0_refuses"=>"0 - Refuses",
                                "1_tries_but_fails"      => "1 - Tries but fails",
                                "2_stacks"               => "Stacks 2",
                                "3_stacks"               => "Stacks 3",
                                "4_stacks"               => "Stacks 4",
                                "5_stacks"               => "Stacks 5",
                                "not_administered"       => "Not Administered",
                                "probe_not_administered" => "Constructive play probe not administered"));
        $group[] = $this->form->createElement("static", null, null,"");
        $group[] = $this->form->createElement("static", null, null,"");
        $this->form->addGroup($group, "q_20_stacks_tower_group", "20. Stacks tower of blocks", null, false);
        unset($group);

        $group[] = $this->form->createElement("static", "q_20_stacks_tower_raw_score");
        $group[] = $this->form->createElement("static", null, null,"");
        $this->form->addGroup($group, "q_20_stacks_tower_raw_score_group", "&emsp;&emsp;<u>Stacks tower raw score</u>:", null, false);
        unset($group);

        $this->form->addFormRule(array($this,'validatePage2'));
    }

    function _countChecked($record, $genericLabel, array $suffixes, bool $checkActivityAdministration = true) {
        $score = 0;
        foreach ($suffixes as $suffix) {
            if ($checkActivityAdministration) {
                $activityWasAdministered = $this->_wasActivityAdministered($record, $genericLabel, $suffix);
                if (is_null($activityWasAdministered)) {
                    return null;
                }
                if (!$activityWasAdministered) {
                    return "Unable to score";
                }
            }

            $value = $record["{$genericLabel}_$suffix"];
            if (is_null($value)) {
                return null;
            }

            $score += ($value === "checked");
        }

        return $score;
    }

    function  _wasActivityAdministered(array $record, string $genericLabel, string $suffix)
    {
        $adminID = null;
        if (preg_match("/^[1-6]$/", $suffix)) {
            $adminID = sprintf("%s_admin", self::ACTIVITIES[(int)$suffix - 1]);
            return is_null($record[$adminID]) ? null : $record[$adminID] != "not_admin";
        } elseif ($suffix === "gives"        || $suffix === "points") {
           return is_null($record["wind_up_admin"]) ? null : $record["wind_up_admin"] !== "not_admin";
        } elseif ($suffix == "shows"        || $suffix == "waves") {
           return is_null($record["balloon_admin"]) ? null : $record["balloon_admin"] !== "not_admin";
        } elseif ($suffix === "pushes_pulls" || $suffix === "nods_head") {
           if(is_null($record["bubbles_admin"]) || is_null($record["jar_admin"])) {
               return null;
           }
           return $record["bubbles_admin"] !== "not_admin" && $record["jar_admin"] !== "not_admin";
        } elseif ($suffix === "reaches"      || $suffix === "shakes_head") {
           if(is_null($record["books_admin"]) || is_null($record["play_admin"])) {
               return null;
           }
           return $record["books_admin"] !== "not_admin" && $record["play_admin"] !== "not_admin";
        }
    }

    function _countCheckedNone($record, $genericLabel, $option)
    {
        $score = 0;
	foreach ($record as $field=>$value)
	{
        	if (preg_match("/$genericLabel/", $field) && $field != $option)
		{
                	$score += ($value == "checked");
		}
	}
	return $score;
    }


    function _countWords($record, $genericLabel, $excludedWords = array()) {
        $score = 0;
        foreach($record as $field=>$value) {
            if(preg_match("/$genericLabel/", $field) && !is_null($value) && $value !== '') {
                if(!in_array($value, $excludedWords)) {
                    $score++;
                }
            }
        }
        return $score;
    }

    function _printHeaderCols(string $groupLabelPrefix, array $headerSpacing) {
        $group = [];
        // That's the category header (Gaze shift, rate of comm. etc, ...)
        foreach ($headerSpacing as $header => $nbSpaces) {
            $group[] = $this->createLabel($this->getStringPrefixedBySpaces($header, $nbSpaces));
        }
        $this->form->addGroup($group, "{$groupLabelPrefix}_group", "", null, false);
    }

    function getStringPrefixedBySpaces(string $s, int $nbSpaces)
    {
        return sprintf(
                "%s%s",
                str_repeat("&nbsp;", $nbSpaces),
                $s
        );
    }

    function validatePage1($values) {
        $errors = [];

        $activities = [ "wind_up", "balloon", "bubbles", "books", "jar", "play" ];
        foreach ($activities as $activity) {
            $admin        = $values["{$activity}_admin"];
            $adminComment = $values["{$activity}_admin_comment"];
            if ($admin == 'partially_admin' && empty($adminComment)) {
                $errors["{$activity}_admin_group"] = "Please specifiy why the activity was partially administered";
            } elseif ($admin != 'partially_admin' && !empty($adminComment)) {
                $errors["{$activity}_admin_group"]
                    = "You can only fill the comment field if the activity was partially administered";
            }
        }

        return $errors;
    }

   function validatePage2($values) {
       // Check that all scores are non null (validated with XINValidate)
       foreach (["objects", "person", "body_parts"] as $section) {
           $nbRows = $section == "person" ? 3 : 4;
           for ($r=1; $r<=$nbRows; $r++) {
               if ($values["q_16_language_comp_{$section}_$r"] == "") {
                   // If we found a null score, then XINVAlidate will have
                   // issued an error. No need to perform any more validations.
                   // We'll wait until the form is completely filled out.
                   return [];
               }
           }
       }

       // Form is completely filled out: validation can take place.
       $error = [];

       foreach (["objects", "person", "body_parts"] as $section) {
           $nbRows = $section == "person" ? 3 : 4;
           $hasNA = false;
           for ($r=1; $r<=$nbRows; $r++) {
               $probe = $values["q_16_language_comp_{$section}_$r"];
               if ($probe == "NA") {
                   $hasNA = true;
               } elseif ($hasNA) {
                   if ($probe != "NA") {
                       $errors["q_16_language_comp_{$section}_{$r}_group"]
                           = "A scored probe cannot follow a probe that was not administered";
                   }
               }
           }
       }

       return $errors;
   }
}
?>
