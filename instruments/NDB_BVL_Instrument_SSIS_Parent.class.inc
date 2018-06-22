<?php

/**
 *This file contains the NDB_BVL_Instrument_SSIS_Parent class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Mie Beers <mie.beers@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_SSIS_Parent instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Mie Beers <mie.beers@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_SSIS_Parent extends NDB_BVL_Instrument
{
    use instrument_validator;

    /**
     * Abstract function setup($commentID, $page);
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     *     
     * @return void
     * @access public
     */
    function setup($commentID=NULL, $page=NULL){

        $this->formType = "XIN";
        $this->form     = new LorisForm('SSIS_Parent_form');
        $this->page     = $page;            // page label 
        
        // Set the object properties
        $this->testName = "SSIS_Parent";    // test_names.Test_name
        $this->table    = "SSIS_Parent"; 
        
        // Data keyed by commentID
        $this->commentID   = $commentID;

        $config            =& NDB_Config::singleton();
        $this->dateOptions = array(
                		'language'         => 'en',
                		'format'           => 'YMd',
                		'minYear'          => $config->getSetting('startYear'),
                		'maxYear'          => $config->getSetting('endYear'),
                		'addEmptyOption'   => true,
                		'emptyOptionValue' => null
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
    function _setupForm(){

        if(preg_match("/SSIS_Parent(_page[0-9]+)/", $this->page, $matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        // Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
    }

    /**
     * Generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main(){
        
	// Display test name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");
        
	// Add date of administration field
	$this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

	}

    /**
     * Allows for the setup of 2 columns of subquestions for each question
     * Used in Social Skills section
     *
     * @return void
     */        
    function _displayHeaders($category)
    {
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Frequency</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Problem</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $this->form->addGroup(
            $group,
            $category . "_group",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }	

    /**
     * Generates the first page of the form
     *
     * @return void
     */
    function _page1(){
	
	// Commonly used level of indentation
    	$indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

	// Define variables for select options
    	$respondent = array(       
                        ''         => NULL,
                        'mother'   => '(Biological) Mother',
                        'father'   => '(Biological) Father',
                        'guardian' => 'Guardian',
                        'other'    => 'Other'
                        );
	$child_sex = array(
			''       => NULL,
			'male'   => 'Male',
			'female' => 'Female'
			);
    	$adult_sex = array(     
                        ''       => NULL,
                        'male'   => 'Male',
                        'female' => 'Female',
                        'other'  => 'Other'
                        );
	$frequency = array(
                        ''                => NULL,
                        'N_never'         => 'Never (N)',
                        'S_sometimes'     => 'Seldom (S)',
                        'O_often'         => 'Often (O)',
                        'A_almost_always' => 'Almost Always (A)'
                        );
        $importance = array(
                        ''                => NULL,
                        'n_not_important' => 'not important (n)',
                        'i_important'     => 'important (i)',
                        'c_critical'      => 'critical (c)'
                        );

	// Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System"); 
 
        // Add field for child's age
	$this->addBasicText("child_age", "Child's Age <h5><i>(Please indicate your child's age in years.)</i></h5>");
     
	// Add field for child's grade
	$this->addBasicText("child_grade", "Child's Grade in School <h5><i>(Please enter a numeric value between 1-12, K, or write NA if you don't know.)</i></h5>");
	
	// Add select for sex of child
        $this->addSelect('child_sex', "Child's sex at birth", $child_sex);
	
	// Add optional field for any other data relating to the child
	$this->addBasicText("child_other_data", "Other data about your child");
	$this->XINRegisterRule('child_other_data',array("child_other_data{@}=={@}NEVER_REQUIRED"));	
	
	// Add select for sex of parent
        $this->addSelect('respondent_sex', "Your sex", $adult_sex);

	// Add field for respondent's relationship to child, including mandatory text field for "other" selection
	$this->addSelect('respondent',"Your relationship to child", $respondent);
	$group [] = $this->createText('respondent_other',$indent."If other please specify");
	$this->addGroup($group,"respondent_other_group",$indent."If other please specify",null,false);
	unset($group);
	$rules_array = array("respondent{@}=={@}other");
	$this->XINRegisterRule('respondent_other', $rules_array, "Please specify relationship", 'respondent_other_group');
 
	// Instructions
        $this->form->addElement('static','lorisSubHeader',"<strong>Instructions:</strong><BR>Please read each item and think about your child's behavior during the past two months. Then, decide <b>how often</b> your child displays the behavior. For each of the Social Skills items, please also rate <b>how important</b> you think the behavior is for your child's development." );

        // Indicate the name of the section
        $this->form->addElement('header', 'instrument_title1', "Social Skills");
	
	// First group of questions
        $this->form->addElement('static', null);
        $questions = array(
			"q1_expresses_feelings"           => "1. Expresses feelings when wronged.",
                        "q2_household_rules"              => "2. Follows household rules.",
                        "q3_understand_your_feelings"     => "3. Tries to understand how you feel.",
                        "q4_thank_you"                    => '4. Says "thank you."',
                        "q5_asks_for_help"                => "5. Asks for help from adults.",
                        "q6_borrowing_with_care"          => "6. Takes care when using other people's things.",
                        "q7_attention_to_instructions"    => "7. Pays attention to your instructions.",
                        "q8_makes_others_feel_better"     => "8. Tries to make others feel better.",
                        "q9_joins_activities"             => "9. Joins activities that have already started.",
                        "q10_takes_turns_conversation"    => "10. Takes turns in conversations.",
                        "q11_shares_problem"              => "11. Says when there is a problem.",
                        "q12_works_well_family"           => "12. Works well with family members.",
			"q13_forgives"                    => "13. Forgives others.",
			"q14_appropriate_tone"            => "14. Speaks in appropriate tone of voice.",
		        "q15_stands_up_for_others"        => "15. Stands up for others who are treated unfairly.",
			"q16_well_behaved"                => "16. Is well-behaved when unsupervised.",
			"q17_follows_directions"          => "17. Follows your directions.",
			"q18_understand_others_feelings"  => "18. Tries to understand how others feel.",
			"q19_starts_conversations"        => "19. Starts conversations with peers.",
			"q20_uses_gestures_appropriately" => "20. Uses gestures or body appropriately with others."
			);

	// Display questions with two columns, one for a frequency rating and one for an importance rating
        $this->_displayHeaders("questions"); 
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $frequency
            );
            $group[] = $this->createSelect(
                $question . "_importance",
                "",
                $importance
            );
            $this->form->addGroup(
                $group,
                $question . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        
	}   

	// Validate text fields using instrument validator class
	$this->form->addFormRule(array(&$this, 'validate_page1'));
   
    }

    /**
     * Generates the second page of the form
     *
     * @return void
     */
    function _page2(){
	
	// Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

	// Define variables for select options
	$frequency  = array(
                        ''                => NULL,
                        'N_never'         => 'Never (N)',
                        'S_sometimes'     => 'Seldom (S)',
                        'O_often'         => 'Often (O)',
                        'A_almost_always' => 'Almost Always (A)'
                        );

        $importance = array(
                        ''                => NULL,
                        'n_not_important' => 'not important (n)',
                        'i_important'     => 'important (i)',
                        'c_critical'      => 'critical (c)'
                        );
  
	// Second group of questions
        $questions = array(
			"q21_resolves_disagreements"      => "21. Resolves disagreements with you calmly.",
                        "q22_respects_property"           => "22. Respects the property of others.",
                        "q23_makes_friends"               => "23. Makes friends easily.",
                        "q24_says_please"                 => '24. Says "please."',
                        "q25_questions_unfair_rules"      => "25. Questions rules that may be unfair.",
                        "q26_takes_responsibility"        => "26. Takes responsibility for her/his own actions.",
                        "q27_completes_tasks"             => "27. Completes tasks without bothering others.",
                        "q28_comforts_others"             => "28. Tries to comfort others.",
                        "q29_interacts_with_children"     => "29. Interacts well with other children.",
                        "q30_start_conversation_activity" => "30. Responds well when others start a conversation or activity.",
                        "q31_calm_teased"                 => "31. Stays calm when teased.",
                        "q32_does_what_promised"          => "32. Does what she/he promised.",
			"q33_introduces_to_others"        => "33. Introduces herself/himself to others.",
			"q34_takes_criticism"             => "34. Takes criticism without getting upset.",
			"q35_nice_without_bragging"       => "35. Says nice things about herself/himself without bragging.",
			"q36_compromise_conflict"         => "36. Makes a compromise during a conflict.",
			"q37_follows_game_rules"          => "37. Follows rules when playing games with others.",
			"q38_shows_concern"               => "38. Shows concern for others.",
			"q39_invites_others"              => "39. Invites others to join in activities.",
			"q40_makes_eye_contact"           => "40. Makes eye contact when talking.",
			"q41_tolerates_annoying_peers"    => "41. Tolerates peers when they are annoying.",
			"q42_responsibility_for_mistakes" => "42. Takes responsibility for her/his own mistakes.",
			"q43_conversations_with_adults"   => "43. Starts conversations with adults.",
			"q44_responds_when_pushes"        => "44. Responds appropriately when pushed or hit.",
			"q45_stands_up_for_self"          => "45. Stands up for herself/himself when treated unfairly.",
			"q46_calm_disagreement"           => "46. Stays calm when disagreeing with others."
			);

	// Display questions with two columns, one for a frequency rating and one for an importance rating
        $this->_displayHeaders("questions");
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createSelect(
                $question . "_frequency",
                "",
                $frequency
            );
            $group[] = $this->createSelect(
                $question . "_importance",
                "",
                $importance
            );
            $this->form->addGroup(
                $group,
                $question . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }        

    }
    
    /**
     * Generates the third page of the form
     *
     * @return void
     */
    function _page3(){

	// Display instrument name
	$this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");
         
	// Indicate the name of the section
        $this->form->addElement('header', 'instrument_title2', "Problem Behaviors");
	
	// Define variable for select options
	$frequency  = array(
                        ''                => NULL,
                        'N_never'         => 'Never (N)',
                        'S_sometimes'     => 'Seldom (S)',
                        'O_often'         => 'Often (O)',
                        'A_almost_always' => 'Almost Always (A)'
                        );
 
	// Third group of questions
        $questions = array(
			"q47_difficulty_waiting_turn"     => "47. Has difficulty waiting for turn.",
                        "q48_repeats_same_thing"          => "48. Repeats the same thing over and over.",
                        "q49_forces_against_will"         => "49. Forces others to act against their will.",
                        "q50_stereotyped_motor_behaviors" => "50. Has stereotyped motor behaviors.",
                        "q51_fidgets_moves"               => "51. Fidgets or moves around too much.",
                        "q52_excludes_social_circles"     => "52. Keeps others out of social circles.",
                        "q53_inattentive"                 => "53. Is inattentive.",
                        "q54_acts_without_thinking"       => "54. Acts without thinking.",
                        "q55_upset_when_routines_change"  => "55. Becomes upset when routines change.",
                        "q56_aggressive_people_objects"   => "56. Is aggressive toward people or objects.",
                        "q57_withdraws_from_others"       => "57. Withdraws from others.",
                        "q58_temper_tantrums"             => "58. Has temper tantrums.",
			"q59_makes_others_scared"         => "59. Does things to make others feel scared.",
			"q60_breaks_group_activities"     => "60. Breaks into or stops group activities.",
			"q61_low_energy_lethargic"        => "61. Has low energy or is lethargic.",
			"q62_odd_gestures"                => "62. Uses odd physical gestures in interactions."
			);

        // Implement response selection for each question
	foreach($questions as $field=>$label) {
            $this->addSelect($field, $label, $frequency);
        }

    }

    /**
     * Generates the fourth page of the form
     *
     * @return void
     */
    function _page4(){

        // Display instrument name
        $this->form->addElement('header', 'instrument_title', "SSIS Parent: Social Skills Improvement System");

	// Define variable for select options
	$frequency  = array(
                        ''                => NULL,
                        'N_never'         => 'Never (N)',
                        'S_sometimes'     => 'Seldom (S)',
                        'O_often'         => 'Often (O)',
                        'A_almost_always' => 'Almost Always (A)'
                        );	

	// Fourth group of questions
        $questions = array(
			"q63_bullies"                  => "63. Bullies others.",
			"q64_anxious_with_others"      => "64. Acts anxious with others.",
			"q65_talks_back"               => "65. Talks back to adults.",
			"q66_nobody_likes_them"        => "66. Says nobody likes her/him.",
			"q67_easily_distracted"        => "67. Gets distracted easily.",
			"q68_sad_depressed"            => "68. Acts sad or depressed.",
			"q69_preoccupied_object_parts" => "69. Is preoccupied with object parts.",
			"q70_disobeys_rules"           => "70. Disobeys rules or requests.",
			"q71_sleeping_problems"        => "71. Has sleeping problems.",
			"q72_lies"                     => "72. Lies or does not tell the truth.",
			"q73_gets_embarrassed"         => "73. Gets embarrassed easily.",
			"q74_says_bad_about_self"      => "74. Says bad things about self.",
			"q75_nonfunctional_routines"   => "75. Has nonfunctional routines or rituals.",	
			"q76_cheats_games"             => "76. Cheats in games or activities.",
			"q77_acts_lonely"              => "77. Acts lonely.",
			"q78_fights_others"            => "78. Fights with others.",
			"q79_eating_problems"          => "79. Has eating problems."
			);

	// Implement response selection for each question
	foreach($questions as $field=>$label) {
            $this->addSelect($field, $label, $frequency);
        }

    }

    /**
     * Validates the text fields on page 1 using the instrument validator class
     *
     */
    function validate_page1($values){

	$errors = [];
	$this->validate_child_age($values, "child_age", $errors); 
	$this->validate_grade($values, "child_grade", $errors);
	if ($values["respondent"] != "other") {
	    $this->validate_empty_subquestions($values, ["respondent_other"], $errors);
	}
    
        return $errors;

    }

}

?>
