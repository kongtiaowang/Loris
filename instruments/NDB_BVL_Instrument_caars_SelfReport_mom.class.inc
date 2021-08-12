<?php

class NDB_BVL_Instrument_caars_SelfReport_mom extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

            var $scoreLabels = array(
                "a_raw_score",
                "b_raw_score",
                "c_raw_score",
                "d_raw_score",
                "e_raw_score",
                "index_total_score",
                "index_guide_score",
                "a_raw_percentile",
                "b_raw_percentile",
                "c_raw_percentile",
                "d_raw_percentile",
                "e_raw_percentile",
                "index_total_percentile",
                "index_guide_percentile",
            );

           var $gender = array(
                null                 => "",
                "female"               => "Female",
               );

           var $q_opts = array(
                null           => "",
                0              => "0 = Not at all, never",
                1              => "1 = Just a little, once in a while",
                2              => "2 = Pretty much, often",
                3              => "3 = Very much, very frequently",
               );
    

    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('caars_SelfReport_mom');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "caars_SelfReport_mom";           // test_names.Test_name
        $this->table    = 'caars_SelfReport_mom';              // name of database table corresponding to instrument
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


        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'q1_interrupt_others_when_talking',
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
        if (preg_match("/caars_SelfReport_mom(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use
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
        $this->addHeader("CAARS–Self-Report Scale: Self Report Mom (Send to Mom)");
 
        // automatically adds examiner & date of administration
        $this->addBasicDate('Date_taken', 'Date of Administration' , $this->dateOptions);


        $field   = 'respondent_age';
        $label   = 'Your Age <BR>(Please indicate your age in years)';
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field, array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));

        $this->addSelect('respondent_gender', "Your gender", $this->gender);
        $this->XINRegisterRule('respondent_gender', array("respondent_gender{@}=={@}NEVER_REQUIRED"));

	$label = "Please click this bubble 'Yes' to confirm that you are the enrolled child’s biological mother, reporting on yourself.";

        $this->form->addElement(
            'select',
            'respondent',
            $label,
            array(
             null       => '',
             'yes'      => 'Yes'
            )
        );

        //Scoring Table

        $this->form->addElement('header', null, "Score Summary");

        $group[] = $this->form->createElement('static', "score", null, null);
        $group[] = $this->form->createElement('static', "percentile", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
            "a_raw"            => "A. Inattention/Memory Problems (score):",
            "b_raw"            => "B. Hyperactivity/Restlessness (score):",
            "c_raw"            => "C. Impulsivity/Emotional Lability (score):",
            "d_raw"            => "D. Problems with Self-Concept (score):",
            "e_raw"            => "E. ADHD Index (score):",
            "index_total"      => "Inconsistency Index TOTAL:",
            "index_guide"      => "Is the Inconsistency Index TOTAL 8 or greater?<br>
                                   If the answer is “yes,” there may be some inconsistency<br>
                                   to the responses. The results should be interpreted with caution. :",
        );

        
        $columnHeaders = array( 
                                "score" => "Score",
                                "percentile" => "T-score",
                                );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                if ($scoreField == "score") {
                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
         elseif ($scoreField == "percentile") {
            $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
        }
    }
            $this->form->addGroup($group, "{$field}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }

    }

    function _page1(){

        $questions = array(
            "q1_interrupt_others_when_talking"                           => "1. I interrupt others when talking.",
            "q2_am_always_on_the_go_as_if"                               => "2. I am always on the go as if driven by a motor.",
            "q3_am_disorganized"                                         => "3. I’m disorganized.",
            "q4_hard_for_me_to_stay"                                     => "4. It’s hard for me to stay in one place very long.",
            "q5_hard_for_me_to_keep_track"                               => "5. It’s hard for me to keep track of several things at once.",
            "q6_am_bored_easily"                                         => "6. I’m bored easily.",
            "q7_have_a_short_fuse"                                       => "7. I have a short fuse/hot temper.",
            "q8_still_throw_tantrums"                                    => "8. I still throw tantrums.",
            "q9_avoid_new_challenges"                                    => "9. I avoid new challenges because I lack faith in my abilities.",
            "q10_seek_out_fast_paced"                                    => "10. I seek out fast paced, exciting activities.",
            "q11_feel_restless_inside"                                   => "11. I feel restless inside even if I am sitting still.",
            "q12_things_I_hear_or_see"                                   => "12. Things I hear or see distract me from what I’m doing.",
            "q13_many_things_set_me"                                     => "13. Many things set me off easily.",
            "q14_am_an_underachiever"                                    => "14. I am an underachiever.",
            "q15_get_down_on_myself"                                     => "15. I get down on myself.",
            "q16_act_okay_on_the_outside"                                => "16. I act okay on the outside, but inside I’m unsure of myself.",
            "q17_cant_get_things_done"                                   => "17. I can’t get things done unless there’s an absolute deadline.",
            "q18_have_trouble_getting"                                   => "18. I have trouble getting started on a task.",
            "q19_intrude_on_others"                                      => "19. I intrude on others’ activities.",
            "q20_my_moods_are_unpredictable"                             => "20. My moods are unpredictable.",
            "q21_absent_minded_in_daily"                                 => "21. I’m absent-minded in daily activities.",
            "q22_sometimes_my_attention"                                 => "22. Sometimes my attention narrows so much that I’m oblivious to everything else; other times it’s so broad that everything distracts me.",
            "q23_tend_to_squirm_or"                                      => "23. I tend to squirm or fidget.",
            "q24_cant_keep_my_mind_on"                                   => "24. I can’t keep my mind on something unless it’s really interesting.",
            "q25_wish_I_had_greater"                                     => "25. I wish I had greater confidence in my abilities.",
            "q26_my_past_failures_make"                                  => "26. My past failures make it hard for me to believe in myself.",
        );

        $this->addLabel(
            "<b>Instructions:</b><br>
            Listed below are items concerning behaviors or problems sometimes experienced by adults.
            Read each item carefully and decide how much or how frequently each item describes you recently.
            Indicate your response for each item by selecting the number that corresponds to your choice.
            Use the following scale:<br><br>
            0 = Not at all, never; <br>
            1 = Just a little, once in a while;<br>
            2 = Pretty much, often;<br>
            3 = Very much, very frequently.
            "
        );

        foreach ($questions as $field=>$label) {
                $this->addSelect($field, $label, $this->q_opts);
            }

    }
        

    function score(): void
    {
        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        
        $this->_nullScores($this->scoreLabels);

        //holds calculated
        $db     =& Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $score_record = $db->pselectRow($query, array());
       
        //calculate raw score for the items
        $raw_score_3_21 = array($score_record["q3_am_disorganized"], $score_record["q21_absent_minded_in_daily"],);
        $raw_score_17_18 = array($score_record["q17_cant_get_things_done"], $score_record["q18_have_trouble_getting"],);
        $raw_score_6_10 = array($score_record["q6_am_bored_easily"], $score_record["q10_seek_out_fast_paced"],);
        $raw_score_4_11 = array($score_record["q4_hard_for_me_to_stay"], $score_record["q11_feel_restless_inside"],);
        $raw_score_13_20 = array($score_record["q13_many_things_set_me"], $score_record["q20_my_moods_are_unpredictable"],);
        $raw_score_7_8 = array($score_record["q7_have_a_short_fuse"], $score_record["q8_still_throw_tantrums"],);
        $raw_score_15_16 = array($score_record["q15_get_down_on_myself"], $score_record["q16_act_okay_on_the_outside"],);
        $raw_score_9_26 = array($score_record["q9_avoid_new_challenges"], $score_record["q26_my_past_failures_make"],);

        //calculate absolute difference
        $abs_difference_3_21 = max($raw_score_3_21) - min($raw_score_3_21);
        $abs_difference_17_18 = max($raw_score_17_18) - min($raw_score_17_18);
        $abs_difference_6_10 = max($raw_score_6_10) - min($raw_score_6_10);
        $abs_difference_4_11 = max($raw_score_4_11) - min($raw_score_4_11);
        $abs_difference_13_20 = max($raw_score_13_20) - min($raw_score_13_20);
        $abs_difference_7_8 = max($raw_score_7_8) - min($raw_score_7_8);
        $abs_difference_15_16 = max($raw_score_15_16) - min($raw_score_15_16);
        $abs_difference_9_26 = max($raw_score_9_26) - min($raw_score_9_26);

        // calculate inconsistency index
    $scores["index_total_score"] = $abs_difference_3_21 + $abs_difference_17_18 + $abs_difference_6_10 + $abs_difference_4_11
                                + $abs_difference_13_20 + $abs_difference_7_8 + $abs_difference_15_16 + $abs_difference_9_26;
                                
        
    $scores['a_raw_score'] = $score_record["q3_am_disorganized"] + $score_record["q5_hard_for_me_to_keep_track"] + $score_record["q17_cant_get_things_done"]  
             + $score_record["q18_have_trouble_getting"] + $score_record["q21_absent_minded_in_daily"] ;

    $scores['b_raw_score'] =  $score_record["q4_hard_for_me_to_stay"] + $score_record["q6_am_bored_easily"] +  $score_record["q10_seek_out_fast_paced"] 
              + $score_record["q11_feel_restless_inside"] + $score_record["q23_tend_to_squirm_or"];
        
    $scores['c_raw_score'] =  $score_record["q1_interrupt_others_when_talking"] +  $score_record["q7_have_a_short_fuse"] + $score_record["q8_still_throw_tantrums"]
              + $score_record["q13_many_things_set_me"] + $score_record["q20_my_moods_are_unpredictable"];
        
    $scores['d_raw_score'] =  $score_record["q9_avoid_new_challenges"] + $score_record["q15_get_down_on_myself"] + $score_record["q16_act_okay_on_the_outside"]
              + $score_record["q25_wish_I_had_greater"] +  $score_record["q26_my_past_failures_make"];

    $scores['e_raw_score'] = $score_record["q2_am_always_on_the_go_as_if"] +  $score_record["q7_have_a_short_fuse"] + $score_record["q8_still_throw_tantrums"]
              + $score_record["q9_avoid_new_challenges"] + $score_record["q11_feel_restless_inside"] + $score_record["q12_things_I_hear_or_see"] 
              +  $score_record["q14_am_an_underachiever"] + $score_record["q17_cant_get_things_done"] + $score_record["q19_intrude_on_others"]
               + $score_record["q22_sometimes_my_attention"] + $score_record["q24_cant_keep_my_mind_on"] + $score_record["q26_my_past_failures_make"];
        

        if($scores["index_total_score"] >= 8){
            $scores["index_guide_score"] =  "yes";
        }else{
            $scores["index_guide_score"] = "no";
        }

        $a_raw_score = $scores['a_raw_score'];
        $b_raw_score = $scores['b_raw_score'];
        $c_raw_score = $scores['c_raw_score'];
        $d_raw_score = $scores['d_raw_score'];
        $e_raw_score = $scores['e_raw_score'];
        $respondent_age = $score_record['respondent_age'];
        $respondent_gender = $score_record['respondent_gender'];


        if($respondent_gender == 'male'){

        if($respondent_age >= 18 && $respondent_age <= 29 ) {
            
            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_m1='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_m1='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_m1='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_m1='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_m1='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        }
       else if($respondent_age >= 30 && $respondent_age <= 39) {
            
            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_m2='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_m2='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_m2='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_m2='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_m2='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        }

        else if($respondent_age >= 40 && $respondent_age <= 49) {
            
            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_m3='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_m3='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_m3='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_m3='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_m3='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        }
        else if($respondent_age >= 50 && $respondent_age <= 100) {

            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_m4='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_m4='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_m4='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_m4='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_m4='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        } 
        else {
            
            $scores['a_raw_percentile'] = "Too young to score";
            $scores['b_raw_percentile'] = "Too young to score";
            $scores['c_raw_percentile'] = "Too young to score";
            $scores['d_raw_percentile'] = "Too young to score";
            $scores['e_raw_percentile'] = "Too young to score";

        }

    }
    if($respondent_gender == 'female'){

        if($respondent_age >= 18 && $respondent_age <= 29) {
            
            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_f1='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_f1='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_f1='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_f1='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_f1='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        }
       else if($respondent_age >= 30 && $respondent_age <= 39) {
            
            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_f2='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_f2='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_f2='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_f2='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_f2='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        }

        else if($respondent_age >= 40 && $respondent_age <= 49) {
            
            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_f3='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_f3='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_f3='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_f3='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_f3='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        }
        else if($respondent_age >= 50 && $respondent_age <= 100) {

            $query_score_a = "SELECT * FROM caars_selfreport_lookup WHERE a_f4='$a_raw_score'";
                $score_a = $db->pselectRow($query_score_a, array());
                $scores['a_raw_percentile'] = $score_a['t'];
                
            $query_score_b = "SELECT * FROM caars_selfreport_lookup WHERE b_f4='$b_raw_score'";
                $score_b = $db->pselectRow($query_score_b, array());
                $scores['b_raw_percentile'] = $score_b['t'];

            $query_score_c = "SELECT * FROM caars_selfreport_lookup WHERE c_f4='$c_raw_score'";
                $score_c = $db->pselectRow($query_score_c, array());
                $scores['c_raw_percentile'] = $score_c['t'];

            $query_score_d = "SELECT * FROM caars_selfreport_lookup WHERE d_f4='$d_raw_score'";
                $score_d = $db->pselectRow($query_score_d, array());
                $scores['d_raw_percentile'] = $score_d['t'];

            $query_score_e = "SELECT * FROM caars_selfreport_lookup WHERE e_f4='$e_raw_score'";
                $score_e = $db->pselectRow($query_score_e, array());
                $scores['e_raw_percentile'] = $score_e['t'];
        } 
        else {
            
            $scores['a_raw_percentile'] = "Too young to score";
            $scores['b_raw_percentile'] = "Too young to score";
            $scores['c_raw_percentile'] = "Too young to score";
            $scores['d_raw_percentile'] = "Too young to score";
            $scores['e_raw_percentile'] = "Too young to score";
            
        }


    }



        // update scores
        $result = $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }    
    
}

   


?>
