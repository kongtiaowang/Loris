<?php




class NDB_BVL_Instrument_pspq_InformantReport_mom_on_dad extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    //Commonly used level of indentation;
    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    var $rating = array(''=>NULL, '1_very_rarely'=>"1. Very Rarely", '2_rarely'=>"2. Rarely", 
                        '3_occasionally'=>"3. Occasionally",'4_somewhat_often'=>'4. Somewhat Often',
                        '5_often'=>'5. Often','6_very_often'=>'6. Very Often');
    var $respondent = array(''=>NULL,'mother'=>'Mother','father'=>'Father','stepmother'=>'Step-Mother',
                            'stepfather'=>'Step-Father','other'=>'Other');

    var $informant = array(''=>NULL,'spouse'=>'Spouse','other'=>'Other');
    var $informant_confidence = array(''=>NULL,'extremely_confident'=>'Extremely confident','very_confident'=>'Very confident',
                                      'moderately_confident'=>'Moderately Confident','little_confident'=>'A little confident',
                                      'not_confident'=>'Not at all confident');

    var $gender = array(''=>NULL,'male'=>'Male','female'=>'Female');

    //abstract function setup($commentID, $page);
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        
        // set the object properties
        $this->testName = "pspq_InformantReport_mom_on_dad";           // test_names.Test_name
        $this->table = 'pspq_InformantReport_mom_on_dad';
        
        // data keyed by commentID
        $this->commentID = $commentID;
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
                'language' => 'en',
                'format'   => 'YMd',
                'minYear'  => $config->getSetting('startYear'),
                'maxYear'  => $config->getSetting('endYear'),
                'addEmptyOption' => true,
                'emptyOptionValue' => null
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
    function _setupForm(){

        if(preg_match("/pspq_InformantReport_mom_on_dad(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
    }


    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main(){
        // display test name
        $this->form->addElement('header', 'instrument_title_1', "PSPQ: Personality Styles and Preferences Questionnaire - Informant Report Mom on Dad (Send to Mom)");

        $this->form->addElement('header', 'instrument_title_2', "Observer Rating");

        $this->form->addElement('static', null, "<br /><br />");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

       // $this->addNumericElement('respondent_age','Your Age <BR>(Please indicate your age in years)');
        $field = 'respondent_age';$label = 'Your Age <BR>(Please indicate your age in years)';
        $group [] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));
        
        $this->addSelect('respondent',"Your relationship to child", $this->respondent);
        $group [] = $this->createText('respondent_other',$this->indent."If Other please specify");
        $this->addGroup($group,"respondent_other_group",$this->indent."If Other please specify",null,false);
        unset($group);
        $rules_array = array("respondent{@}=={@}other");
        $this->XINRegisterRule('respondent_other', $rules_array, "Please specify relationship", 'respondent_other_group');

        $this->addSelect('respondent_gender',"Your gender", $this->gender);
        $this->XINRegisterRule('respondent_gender',array("respondent_gender{@}=={@}NEVER_REQUIRED"));

    }


    function _page2(){
        // display test name
        $this->form->addElement('header', 'instrument_title_3', "PSPQ: Personality Styles and Preferences Questionnaire Page 2- Informant Report Mom on Dad (Send to Mom)");
        $this->form->addElement('static','lorisSubHeader',"<strong>Instructions:</strong><BR>You are about to fill out a series of statements related to personality and lifestyle of the other biological parent <BR>of your child. For each question, you will be given a choice of 6 answers that describe how often the statement<BR> applies to the other biological parent:<BR> 1.Very Rarely<BR>2.Rarely<BR>3.Occasionally<BR>4.Somewhat Often<BR>5.Often<BR> 6.Very Often<BR><BR>Choose the number that matches the answer that comes closest to how you feel about each statement.<BR>So, if they watch the evening news once a week, you might circle #4: Somewhat often.<BR><BR><strong>3 IMPORTANT THINGS TO REMEMBER</strong><BR><BR>#1. Many of these questions ask about their interactions with other people. Please <strong>think about the <BR> way they are with <i>most</i> people rather than special relationships</strong> they may have with spouses or <BR> significant others, children, siblings, and parents.<BR> <BR>#2. Everyone changes over time, which can make it hard to fill out questions about personality. <BR><strong>Think about the way they have been the majority of their adult life</strong>, rather than the way they were <BR> as a teenager, or times they many have felt different than normal.<BR><BR>#3. <strong>You must answer each question,</strong> and give only one answer per question. If you are confused,<BR> please just give it a guess.<BR><BR>Observer ratings help us obtain a more well-rounded measure of personality and lifestyle, since <BR>some traits and behaviors are most easily observed by other people.");

        $this->addSelect('informant_confidence',"<BR>How confident do you feel about your ability to give an accurate report on the <BR>personality traits and behaviors of the other biological parent?", $this->informant_confidence);

        $this->form->addElement('header', 'instrument_title_4', "Observer Rating");
/*
        $field = 'informant_age';$label = 'Your Age <BR>(Please indicate your age in years)';
        $group [] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));
  */    
        $this->addSelect('informant',"Relationship to the other biological parent of the child", $this->informant);
        
        $group [] = $this->createText('informant_other',$this->indent."If Other please specify");
        $this->addGroup($group,"informant_other_group",$this->indent."If Other please specify",null,false);
        unset($group);
        $rules_array = array("informant{@}=={@}other");
        $this->XINRegisterRule('informant_other', $rules_array, "Please specify relationship", 'informant_other_group');
        $this->addSelect('informant_gender',"Gender of the other biological parent of the child", $this->gender); 
        $this->XINRegisterRule('informant_gender',array("informant_gender{@}=={@}NEVER_REQUIRED"));

        $this->form->addElement('static', null, "<br /><br />");
        $questions = array("qi1_like_being_otherpeople" => "1. He/She likes being around other people",
                           "qi2_hard_wordsout_smoothly" =>"2. He/She finds it hard to get his/her words out smoothly",
                           "qi3_comfortable_unexpectedchanges"=>"3. He/She is comfortable with unexpected changes in plans",
                           "qi4_hard_avoid_sidetrack"=>"4. It's hard for him/her to avoid getting sidetracked in conversations",
                           "qi5_information_than_socialize"=>"5. He/She would rather talk to people to get information than to socialize",
                           "qi6_talkinto_tryingnew"=>"6. People have to talk him/her into trying something new",
                           "qi7_intune_conversation"=>"7. He/She is 'in-tune' with the other person during conversation",
                           "qi8_warmup_unfamiliarplace"=>"8. He/She has to warm himself/herself up to the idea of visiting an unfamiliar place",
                           "qi9_enjoy_socialsituations"=>"9. He/She enjoys being in social situations",
                           "qi10_voice_flat_monotone"=>"10. His/Her voice has a flat or monotone sound to it",
                           "qi11_disconnected_outofsync_convo"=>"11. He/She feels disconnected or 'out of sync' in conversations with others",
                           "qi12_easy_approach"=>"12. People find it easy to approach him/her");

        foreach($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
            $this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"));
        }
   
       // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));

    }

    function _page3() {
       
       $this->form->addElement('header', 'instrument_title_5', "PSPQ: Personality Styles and Preferences Questionnaire Page3 - Informant Report Mom on Dad (Send to Mom)");
       $this->form->addElement('header', 'instrument_title_6', "Observer Rating");

       $questions = array("qi13_strongneed_sameness"=>"13. He/She feels a strong need for sameness from day to day",
                           "qi14_others_dont_understand"=>"14. People ask him/her to repeat things he/she has said because they don't understand",
                           "qi15_flexible"=>"15. He/She is flexible about how things should be done",
                           "qi16_situations_meetnew_people"=>"16. He/She looks forward to situations where he/she can meet new people",
                           "qi17_talktoomuch_certain_topics"=>"17. He/She has been told that he/she talks too much about certain topics",
                           "qi18_conversation_tobe_polite"=>"18. When he/she makes conversation it is just to be polite",
                           "qi19_lookforward_newthings"=>"19. He/She looks forward to trying new things",
                           "qi20_speak_tooloud_softly"=>"20. He/She speaks too loudly or softly",
                           "qi21_tell_someone_not_interested"=>"21. He/She can tell when someone is not interested in what he/she is saying",
                           "qi22_hardtime_change_routine"=>"22. He/She has a hard time dealing with changes in his/her routine",
                           "qi23_good_smalltalk"=>"23. He/She is good at making small talk",
                           "qi24_act_myways"=>"24. He/She acts very set in his/her ways");

        foreach($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
            $this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"));
        }
   
       // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
     
    }
    
    function _page4() {
       
       $this->form->addElement('header', 'instrument_title_7', "PSPQ: Personality Styles and Preferences Questionnaire Page 4 - Informant Report Mom on Dad (Send to Mom)");
       $this->form->addElement('header', 'instrument_title_8', "Observer Rating");

       $questions = array("qi25_connecting_people"=>"25. He/She feels like he/she is really connecting with other people",
                           "qi26_peoplefrustrated"=>"26. People get frustrated by his/her unwillingness to bend",
                           "qi27_conversation_boresme"=>"27. Conversation bores him/her",
                           "qi28_warmfriendly_others"=>"28. He/She is warm and friendly in his/her interactions with others",
                           "qi29_longpauses_conversations"=>"29. He/She leaves long pauses in conversations",
                           "qi30_alter_dailyroutine"=>"30. He/She alters his/her daily routine by trying something different",
                           "qi31_alone_ratherthan_withothers"=>"31. He/She prefers to be alone rather than with others",
                           "qi32_losetrack_talking"=>"32. He/She loses track of his/her original point when talking to people",
                           "qi33_follow_routine"=>"33. He/She likes to closely follow a routine while working",
                           "qi34_change_topic"=>"34. He/She can tell when it is time to change topics in conversation",
                           "qi35_doingthings_knownway"=>"35. He/She keeps doing things the way he/she knows, even if another way might be better",
                           "qi36_enjoy_chatting"=>"36. He/She enjoys chatting with people");

        foreach($questions as $field=>$label) {
            $this->addSelect($field, $label, $this->rating);
            $this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"));
        }
       $this->addBasicTextArea("comments", "Do you have any other comments?");
       $this->XINRegisterRule('comments', array('comments{@}=={@}NEVER_REQUIRED'));
   
       // $this->form->addFormRule(array(&$this, 'PSPQ_Rules'));
     
    }

   function PSPQ_Rules($values) {
      // commenting out the warnings
         $errors = array();
         $DB = Database::singleton();
         $questions = array();
         $questions = $DB->pselect(
            "SELECT  Description as question,
            SourceField FROM parameter_type  
            WHERE SourceFrom=:TN AND 
            SourceField NOT IN ('Validity', 'Administration')",
                array(
                    'TN' => $this->testName
                )
            );
       $list_questions = array();
       foreach($values as $key=>$val) {
	       if(empty($val)) {
		       foreach($questions as $row) {
			       if($row['SourceField'] == $key) {
				       // $q_display = $row['question'];break;
				       $list_questions[$key] = $row['question'];
			       }
		       }
	       }
       }
       foreach ($list_questions as $key=>$row) {
                if($key == 'respondent_other' && $questions['respondent'] != 'other') {
                   unset($list_questions[$key]);
                } else if($key == 'informant_other' && $questions['informant'] != 'other') {
                   unset($list_questions[$key]);
                } elseif (empty ($row) )  {
                   unset($list_questions[$key]);
                } 
        }
        if(isset($_GET["key"])) {
            $url_key = $_GET["key"];
        }
       if(isset($_GET["pageNum"])) { 
          $page = $_GET["pageNum"]; 
          if($page == 'top') {
               $page_verbose = 1;
           } else {
               $page_verbose= $page +1;
           }
          $goback_url = "survey.php?key=$url_key&pageNum=$page";
       }
//print_r($list_questions);
	if(!empty($list_questions)) {
                setcookie("MissingResponses","", time()-3600);
                $value = "<font color='Red'>Note: You have missed a few questions on the previous page :</font> <BR><BR>";
		foreach($list_questions as $key=>$question) {
                    $value  .= $question."<BR><BR>";
		}
          setcookie("MissingResponses",$value);
          setCookie("PrevPage", $page);
          setCookie("URLKey", $url_key);
	}
       if(intval($values['respondent_age']) > 100) {
           $errors['respondent_age_group'] = "Specify age between 0 and 100";    
       }
       if(intval($values['informant_age']) > 100) {
           $errors['informant_age_group'] = "Specify age between 0 and 100";
       }

       return $errors;
    }

  
}