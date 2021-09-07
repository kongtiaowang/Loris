<?php
/*
 * This file contains the NDB_BVL_Instrument_Actigraph_Support_Protocol
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   moshood.abiola@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the Actigraph Support Protocol instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   moshood.abiola@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Actigraph_Support_Protocol extends NDB_BVL_Instrument
{
	use LegacyInstrumentTrait;
	use instrument_validator;

	var $probe_opts = array(
	    null     => "",
            "level1" => "Level 1",
            "level2" => "Level 2",
            "level3" => "Level 3",
            "level4" => "Level 4",
            "level5" => "Level 5",
            "not_answered" => "Not Known",
        );

       var $rate_options = array(
            null         => "",
            "1"          => "1",
            "2"          => "2",
            "3"          => "3",
            "4"          => "4",
            "5"          => "5",
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
        $this->form = new LorisForm('Actigraph_Support_Protocol');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "Actigraph_Support_Protocol";           // test_names.Test_name
        $this->table = 'Actigraph_Support_Protocol';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();
        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');
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
        //determine page to display
        if (preg_match(
            "/Actigraph_Support_Protocol(_page[0-9]+)/",
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
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {

	$this->addHeader("Actigraph Support Protocol");
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        // display test name
        $this->form->addElement('static', null, "<i><h3><b>Section 1:</b> Probe wearing the actigraph at the last IBIS-SA visit (usually MRI). Rate child according to the following outcomes (select appropriate level)</h3></i>");
        
       $this->form->addElement('static', null, "<i>Level 1: Wears the actigraph with no problem. States verbally that he/she would be willing to wear the actigraph for at least one week.
        <br>Level 2: Tolerates putting the actigraph on, but appears eager to take it off or asks to remove it. Verbally states preference to not wear it for long period of time or is unable to answer question.
        <br>Level 3: Does not tolerate putting the actigraph on. Verbally states preference to not wear it for a long period of time. Parent states the possibility of child wearing it for long duration with support and interest in sleep study.
        <br>Level 4: Does not tolerate putting the actigraph on. Struggled with MRI scan and needed maximum support to complete. Parent expresses concerns about the child wearing for a long duration but is willing to try with support and training.
        <br>Level 5: Does not tolerate putting the actigraph on. Struggled with MRI scan and needed maximum support to complete. Parent is not interested in the actigraph study.</i>");

         $this->form->addElement('static', null,null);         

        $this->addSelect("section1_probe", "Select appropriate level",$this ->probe_opts);

    $this->form->addElement('static', null, "<i><h3><b>Section 2: </b>Proceed if <b>Levels 2-4 are selected</b> to further assess the level of support and types of support that may be beneficial for the child participant to comply with wearing the actigraph for the duration of the study.</h3></i>");

     $this->form->addElement('static', null, "<i>Scoring note: A higher score indicates that more support is indicated. Individual items identify the types of support that may be more beneficial. Questions 2, 10, 11 refer to visual supports that may be helpful. Question 6 refers to priming for the actigraph wearing. Question 7 refers to utilizing the shaping protocol. Questions 8 and 9 refer to the use of reinforcement. Boxes checked below (section 3) indicate supports that will be used for the participant.</i>");

    $this->form->addElement('static', null,null);

    $this->addSelect("q1_my_child_tolerates_wearing_watches", "1. My child tolerates wearing watches, a fitbit, or other types of wristbands.", $this->rate_options);
    $this->XINRegisterRule("q1_my_child_tolerates_wearing_watches",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");
    
    $this->addSelect("q2_my_child_has_difficulty_with_extra", "2. My child has difficulty with extra sensory stimuli.", $this->rate_options);
    $this->XINRegisterRule("q2_my_child_has_difficulty_with_extra",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q3_my_child_has_difficulty_with_tags", "3. My child has difficulty with tags, tight things, or things that feel “too hot.” ", $this->rate_options);
    $this->XINRegisterRule("q3_my_child_has_difficulty_with_tags",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q4_my_child_struggles_with_change", "4. My child struggles with change. ", $this->rate_options);
    $this->XINRegisterRule("q4_my_child_struggles_with_change",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q5_my_child_tolerates_change_better", "5. My child tolerates change better when I can show a visual about the change.", $this->rate_options);
    $this->XINRegisterRule("q5_my_child_tolerates_change_better",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q6_my_child_tolerates_when_i_can_tell", "6. My child tolerates change better when I can tell him/her about what will happen.", $this->rate_options);
    $this->XINRegisterRule("q6_my_child_tolerates_when_i_can_tell",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q7_my_child_tolerates_learns_new_skills", "7. My child tolerates change or learns new skills better when we can take our time and gradually increase the amount of change rather than all at once.", $this->rate_options);
    $this->XINRegisterRule("q7_my_child_tolerates_learns_new_skills",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q8_my_child_responds_well_to_reinforcement", "8. My child responds well to reinforcement. If s/he wants something badly enough s/he is willing to work hard to set goals to earn it.", $this->rate_options);
    $this->XINRegisterRule("q8_my_child_responds_well_to_reinforcement",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q9_my_child_needs_reminders_about_what", "9. My child needs reminders about what s/he is working for when we have set a goal to earn a reinforcer.", $this->rate_options);
    $this->XINRegisterRule("q9_my_child_needs_reminders_about_what",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q10_my_child_responds_well_to_visual_reminders", "10. My child responds well to visual reminders and expectations.", $this->rate_options);
    $this->XINRegisterRule("q10_my_child_responds_well_to_visual_reminders",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

    $this->addSelect("q11_my_child_responds_well_to_social_stories", "11. My child responds well to social stories when learning new skills.", $this->rate_options);
    $this->XINRegisterRule("q11_my_child_responds_well_to_social_stories",array("section1_probe{@}=={@}level2|level3|level4"),"Required.");

   $this->form->addElement('static', null, "<i><h3><b>Section 3:</b> This section identifies a “tool kit” to be utilized on an individualized basis based on results of the probe and survey. Participants could end up needing all, some, or only one of the following tools to support the consistent wearing of the actigraph. Check all that apply.</h3></i>");

    $this->form->addElement("advcheckbox", "visual_supports", "<U>Visual supports:</U> The following section should be completed collaboratively with parents to identify which visuals will be the most beneficial for their child, keeping in mind that visuals can be modified or individualized to further increase participation.", "Visual supports", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "visual_supports",
                array("visual_supports{@}=={@}NEVER_REQUIRED"),
                "Not required"
	);

    $this->form->addElement('static',null, "<h3>Examples of visual supports include:</h3>");

     $this->form->addElement("advcheckbox", "weekly_countdown_schedule_token_system", $this->indent . "<U>Weekly countdown schedule/Token System:</U> Each day of the week will either be marked off by a sticker, crossed off, or otherwise marked complete.", "Weekly countdown schedule/Token System", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "weekly_countdown_schedule_token_system",
                array("weekly_countdown_schedule_token_system{@}=={@}NEVER_REQUIRED"),
                "Not required"
        );

   $this->form->addElement("advcheckbox", "social_story", $this->indent . "<U>Social story:</U> The social story will introduce the actigraph and talk about wearing the actigraph day and night for over a week in order to earn a prize at the end.", "Social story", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "social_story",
                array("social_story{@}=={@}NEVER_REQUIRED"),
                "Not required"
	);
     $this->form->addElement("advcheckbox", "visual_of_keeping_actigraph_on", $this->indent . "<U>Visual of keeping actigraph on:</U> Parents will receive small portable laminated cards with a picture of someone taking a watch/actigraph off on one side and a red circle with a slash through it to represent “don’t remove the actigraph.”", "Visual of keeping actigraph on", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "visual_of_keeping_actigraph_on",
                array("visual_of_keeping_actigraph_on{@}=={@}NEVER_REQUIRED"),
                "Not required"
	);

     $this->form->addElement("advcheckbox", "verbal_prompts_priming", $this->indent . "<U>Verbal prompts/Priming:</U> Some participants will benefit from verbal prompting prior to and during the 7-day period of wearing the actigraph.", "Verbal prompts/Priming", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "verbal_prompts_priming",
                array("verbal_prompts_priming{@}=={@}NEVER_REQUIRED"),
                "Not required"
	);

     $this->form->addElement('static',null,"<h3>Examples of verbal prompts/priming include:</h3>");

     $this->form->addElement("advcheckbox", "scripts_about_wearing_the_actigraph", $this->indent . "<U>Scripts about wearing the actigraph:</U> Scripts about wearing the actigraph will explain (a) what the actigraph is, (b) why the child is wearing the actigraph, (c) how long the child will have to wear the actigraph (including information about wearing it during the day, showers, and to sleep, (d) and what he/she can earn at the end of the wearing period. Parents should read the script in the days leading up to wearing the actigraph", "Scripts about wearing the actigraph", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "scripts_about_wearing_the_actigraph",
                array("scripts_about_wearing_the_actigraph{@}=={@}NEVER_REQUIRED"),
                "Not required"
        );

      $this->form->addElement("advcheckbox", "verbal_reminders", $this->indent . "<U>Verbal reminders:</U> Some children may not need a fully detailed script to remind them about wearing the actigraph, but instead may benefit from a verbal reminder.", "Verbal reminders", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "verbal_reminders",
                array("verbal_reminders{@}=={@}NEVER_REQUIRED"),
                "Not required"
        );

     $this->form->addElement("advcheckbox", "reinforcement", "<U>Reinforcement:</U> It is recommended that all child participants receive some type of reinforcer for complying with wearing the actigraph for the duration of the study.","Reinforcement", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "reinforcement",
                array("reinforcement{@}=={@}NEVER_REQUIRED"),
                "Not required"
        );

      $this->form->addElement("advcheckbox", "weekly_countdown_schedule_token_system", $this->indent . "<U>Weekly countdown schedule/Token System:</U> Each day of the week would either be marked off by a sticker, crossed off, or otherwise marked as complete.","Weekly countdown schedule/Token System", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "weekly_countdown_schedule_token_system",
                array("weekly_countdown_schedule_token_system{@}=={@}NEVER_REQUIRED"),
                "Not required"
	);

      $this->form->addElement("advcheckbox", "sample_shaping_protocol", "<U>Sample Shaping Protocol:</U> An individualized shaping protocol will be developed and implemented for those individuals needing the highest level of support to wear the actigraph.","Sample Shaping Protocol", null, array("not_checked", "checked"));
            $this->XINRegisterRule(
                "sample_shaping_protocol",
                array("sample_shaping_protocol{@}=={@}NEVER_REQUIRED"),
                "Not required"
        );

      $this->form->addElement('static',null, $this->indent . "<h3>Example shaping steps</h3>");

     $this->form->addElement('static',null, $this->indent . "Each step will likely be supported by all of the above support strategies in addition to the shaping process.<br>  $this->indent  Step 1: Put a digitial watch (to simulate an actigraph) on and wear for 30 minutes – earn reinforcer<br>  $this->indent  Step 2: Wear watch for 1 hour – earn reinforcer <br>  $this->indent   Step 3: Wear watch for an activity lasting between 2 and 3 hours – earn reinforcer <br>  $this->indent  Step 4: Wear watch for full school day – earn reinforcer <br>  $this->indent  Step 5: Wear watch for 24 hour period – earn reinforcer <br>  $this->indent  Step 6: Wear REAL actigraph for full 10 day period (with intermittent rewards/reinforcers) – earn BIG reinforcer at the end of the week.");


    $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    function validate_main_page($values)
    {

	    $errors = [];
            if ($values["section1_probe"] != "level2" && $values["section1_probe"] != "level3" && $values["section1_probe"] != "level4") {
                $this->validate_empty_subquestions($values, ["q1_my_child_tolerates_wearing_watches"], $errors);	    
		$this->validate_empty_subquestions($values, ["q2_my_child_has_difficulty_with_extra"], $errors);	    
		$this->validate_empty_subquestions($values, ["q3_my_child_has_difficulty_with_tags"], $errors);
                $this->validate_empty_subquestions($values, ["q4_my_child_struggles_with_change"], $errors);
                $this->validate_empty_subquestions($values, ["q5_my_child_tolerates_change_better"], $errors);
                $this->validate_empty_subquestions($values, ["q6_my_child_tolerates_when_i_can_tell"], $errors);
                $this->validate_empty_subquestions($values, ["q7_my_child_tolerates_learns_new_skills"], $errors);
                $this->validate_empty_subquestions($values, ["q8_my_child_responds_well_to_reinforcement"], $errors);
                $this->validate_empty_subquestions($values, ["q9_my_child_needs_reminders_about_what"], $errors);
                $this->validate_empty_subquestions($values, ["q10_my_child_responds_well_to_visual_reminders"], $errors);
                $this->validate_empty_subquestions($values, ["q11_my_child_responds_well_to_social_stories"], $errors);
            }

         return $errors;
    }
}
?>
