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

       var $probe_opts = array(
            "level1" => "Level 1: Wears the actigraph with no problem. States verbally that he/she would be willing to wear the actigraph for at least one week.",
            "level2" => "Level 2: Tolerates putting the actigraph on, but appears eager to take it off or asks to remove it. Verbally states preference to not wear it for long period of time or is unable to answer question.",
            "level3" => "Level 3: Does not tolerate putting the actigraph on. Verbally states preference to not wear it for a long period of time. Parent states the possibility of child wearing it for long duration with support and interest in sleep study.",
            "level4" => "Level 4: Does not tolerate putting the actigraph on. Struggled with MRI scan and needed maximum support to complete. Parent expresses concerns about the child wearing for a long duration but is willing to try with support and training.",
            "level5" => "Level 5: Does not tolerate putting the actigraph on. Struggled with MRI scan and needed maximum support to complete. Parent is not interested in the actigraph study.",
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
        $this->form->addElement('static', null, "<i><h3><b>Section 1:</b> Probe wearing the actigraph at the last IBIS-SA visit (usually MRI). Rate child according to the following outcomes (check box next to appropriate level)</h3></i>");
        
        foreach($this->probe_opts as $probe_optsID => $probe_optsDescription) {
	      
	$this->form->addElement("advcheckbox", "$probe_optsID", null, $probe_optsDescription, null, array("not_used", "used"));
            $this->XINRegisterRule(
                "$probe_optsID",
                array("$probe_optsID{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

    $this->form->addElement('static', null, "<i><h3><b>Section 2:</b>Proceed if <b>Levels 2-4 are selected</b> to further assess the level of support and types of support that may be beneficial for the child participant to comply with wearing the actigraph for the duration of the study.</h3></i>");

    $this->addSelect("my_child_tolerates_wearing_watches", "1. My child tolerates wearing watches, a fitbit, or other types of wristbands.", $this->rate_options);
    $this->XINRegisterRule("my_child_tolerates_wearing_watches",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");
    
    $this->addSelect("my_child_has_difficulty_with_extra", "2. My child has difficulty with extra sensory stimuli.", $this->rate_options);
    $this->XINRegisterRule("my_child_has_difficulty_with_extra",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_has_difficulty_with_tags", "3. My child has difficulty with tags, tight things, or things that feel “too hot.” ", $this->rate_options);
    $this->XINRegisterRule("my_child_has_difficulty_with_tags",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_struggles_with_change", "4. My child struggles with change. ", $this->rate_options);
    $this->XINRegisterRule("my_child_struggles_with_change",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_tolerates_change_better", "5. My child tolerates change better when I can show a visual about the change.", $this->rate_options);
    $this->XINRegisterRule("my_child_tolerates_change_better",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_tolerates_when_i_can_tell", "6. My child tolerates change better when I can tell him/her about what will happen.", $this->rate_options);
    $this->XINRegisterRule("my_child_tolerates_when_i_can_tell",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_tolerates_learns_new_skills", "7. My child tolerates change or learns new skills better when we can take our time and gradually increase the amount of change rather than all at once.", $this->rate_options);
    $this->XINRegisterRule("my_child_tolerates_learns_new_skills",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_responds_well_to_reinforcement", "8. My child responds well to reinforcement. If s/he wants something badly enough s/he is willing to work hard to set goals to earn it.", $this->rate_options);
    $this->XINRegisterRule("my_child_responds_well_to_reinforcement",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_needs_reminders_about_what", "9. My child needs reminders about what s/he is working for when we have set a goal to earn a reinforcer.", $this->rate_options);
    $this->XINRegisterRule("my_child_needs_reminders_about_what",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_responds_well_to_visual_reminders", "10. My child responds well to visual reminders and expectations.", $this->rate_options);
    $this->XINRegisterRule("my_child_responds_well_to_visual_reminders",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->addSelect("my_child_responds_well_to_social_stories", "11. My child responds well to social stories when learning new skills.", $this->rate_options);
    $this->XINRegisterRule("my_child_responds_well_to_social_stories",array("level2{@}=={@}used", "level4{@}=={@}used"),"Required.");

    $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    function validate_main_page($values)
    {
	    $errors = [];
	     $nbChecked = 0;
      foreach ($this->probe_opts as $probe_optsID => $probe_optsDescription) {
                if ($values["$probe_optsID"] == 'used') {
                    $nbChecked++;
                }
            }

            if ($nbChecked == 0) {
                $errors["not_answered"] =
                    "You must check 'Not answered' if none of the choices apply or if you do not want to answer this question";
            } elseif ($nbChecked > 1 && $values["not_answered"] == 'used') {
                $errors["not_answered"] = 'If you check this box, it has to be the only one checked';
            }

            if ($values["not_answered"] == 'used') {
                $this->validate_empty_subquestions($values, ["my_child_tolerates_wearing_watches"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_has_difficulty_with_extra"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_has_difficulty_with_tags"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_struggles_with_change"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_tolerates_change_better"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_tolerates_when_i_can_tell"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_tolerates_learns_new_skills"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_responds_well_to_reinforcement"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_needs_reminders_about_what"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_responds_well_to_visual_reminders"], $errors);
                $this->validate_empty_subquestions($values, ["my_child_responds_well_to_social_stories"], $errors);
            }

         return $errors;
    }
}
?>
