<?php
/**
 * This file contains the NDB_BVL_Instrument_FXS_Genetic_Testing_Form class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  FXS_Genetic_Testing_Form
 * @author   Moshood Kolawole <moshood.abiola@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

/**
 * Creates the form elements for the FXS_Genetic_Testing_Form instrument
 *
 * @category Instrument
 * @package  FXS_Genetic_Testing_Form
 * @author   Moshood Kolawole <moshood.abiola@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

class NDB_BVL_Instrument_FXS_Genetic_Testing extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;


    /**
     * Sets up basic data such as the HTML_Quickform object, database references
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('FXS_Genetic_Testing');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        // Corresponds to the Test_name column in test_names table
        $this->testName = "FXS_Genetic_Testing";
        // name of database table corresponding to instrument
        $this->table = 'FXS_Genetic_Testing';
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();
        // setup the form
        $this->_setupForm();
    }

    /**
     * Builds the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/FXS_Genetic_Testing(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        // Defines the call back function for HTML Quickform to use in validation
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
        $this->addHeader("FRAGILE X GENETIC TESTING AND FAMILY HISTORY FORM");

        $this->_addMetadataFields();

    }

    /**
     * Generates the first page of the form.
     *
     * @return void
     */
    function _page1()
    {

        $this->addHeader("SECTION 1: GENETIC TESTING");

        $field   = 'no_of_siblings';
        $label   = 'How many siblings does the subject have (including the enrolled sibling)?';
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        $this->XINRegisterRule($field, array("$field{@}=={@}"),"Required.", $field . "_group");
        unset($group);
        $this->addGroupRule($field . "_group", array(array(array("Value must be numeric.", 'numeric'))));

        $this->addHeader("<h3>Immediate Family (i.e. parents and siblings on enrolled child with FXS)</h3>");

        $table_heading = array('family_member' => 'Family Member', 'relationship_to_fxs' => 'Relationship to FXS child in study',
                                'sex' => 'Sex', 'date_of_birth' => 'Date of Birth', 'genetic_testing' => 'FXS Genetic Testing Complete?',
                                'result' => 'Results');
        
        $questions = array('header' => null, 'mother' => 'Mother', 'father' => 'Father', 'sibling' => 'Sibling (enrolled)', 'sibling1' => 'Sibling (other)',
                            'sibling2' => 'Sibling (other)', 'sibling3' => 'Sibling (other)', 'sibling4' => 'Sibling (other)', 'sibling5' => 'Sibling (other)',
                            'sibling6' => 'Sibling (other)');

        $relation = array(null => '', 'full_sibling' => 'Full', 'maternal_half' => 'Maternal Half', 'paternal_half' => 'Paternal Half');
        $gender = array(null => '', 'male' => 'Male', 'female' => 'Female');
        $yes_no_option = array(null => '', 'yes' => 'Yes', 'no' => 'No', 'unknown' => 'Unknown');
        $options = array('full_mutation' => 'Full Mutation', 'premutation' => 'Premutation/Carrier', 'negative' => 'Negative (not carrier)', 'unknown' => 'Unknown');
        foreach ($questions as $key => $val) {
            $groupname = $key . "_group";

            foreach ($table_heading as $k => $v) {
                if ($key == 'header') {
                    $group[] = $this->form->createElement("static", null, null, $v);
                } else {
                    $field = $key . "_" . $k;
                    if ($key == 'mother') {
                        if($k == 'family_member'){
                        $group[] = $this->form->createElement("static", null, null, $val);
                        }elseif($k == 'relationship_to_fxs'){
                        $group[] = $this->form->createElement("static", null, null, "Biological Mother");
                        }elseif($k == 'sex'){
                            $group[] = $this->form->createElement("static", null, null, "Female");
                            }elseif($k == 'date_of_birth'){
                                $group[] = $this->form->createElement("date", $field, null);
                                $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                }elseif($k == 'genetic_testing'){
                                    $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                    }else{
                                        $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]); 
                                        $this->XINRegisterRule($field, array("$field{@}=={@}"), "Required. ", "{$field}_group"); 
                                    }
                    }elseif($key == 'father') {
                        if($k == 'family_member'){
                        $group[] = $this->form->createElement("static", null, null, $val);
                        }elseif($k == 'relationship_to_fxs'){
                            $group[] = $this->form->createElement("static", null, null, "Biological Father");
                            }elseif($k == 'sex'){
                                $group[] = $this->form->createElement("static", null, null, "Male");
                                }elseif($k == 'date_of_birth'){
                                    $group[] = $this->form->createElement("date", $field, null);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                    }elseif($k == 'genetic_testing'){
                                        $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                        $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                        }else{
                                            $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]);  
                                            $this->XINRegisterRule($field, array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                        } 
                    }else{
                        if($k == 'family_member'){
                            $group[] = $this->form->createElement("static", null, null, $val);
                            }elseif($k == 'relationship_to_fxs'){
                            $group[] = $this->form->createElement("select", $field, null, $relation);
                            $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                            }elseif($k == 'sex'){
                                $group[] = $this->form->createElement("select", $field, null, $gender);
                                $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                }elseif($k == 'date_of_birth'){
                                    $group[] = $this->form->createElement("date", $field, null);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                    }elseif($k == 'genetic_testing'){
                                        $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                        $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                        }else{
                                            $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]);  
                                            $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                        }
                        
                    }
                }
            }
            $this->form->addGroup($group, $groupname, null, $this->_GUIDelimiter, false);
            unset($group);
        }
        
        $this->addHeader("<h3>Extended MATERNAL family (i.e. maternal grandparents, maternal aunts/uncles)</h3>");

        $extended_questions = array('header' => null,'grand_mother' => 'Grandmother (Mom’s Mother)', 'grand_father' => 'Grandfather (Mom’s Father)', 'aunt1' => 'Aunt (Mom’s Sister)',
        'aunt2' => 'Aunt (Mom’s Sister)', 'aunt3' => 'Aunt (Mom’s Sister)', 'uncle1' => 'Uncle (Mom’s Brother)', 'uncle1' => 'Uncle (Mom’s Brother)', 'uncle2' => 'Uncle (Mom’s Brother)',
        'uncle3' => 'Uncle (Mom’s Brother)');

        foreach ($extended_questions as $key => $val) {
            $groupname = $key . "_group";

            foreach ($table_heading as $k => $v) {
                if ($key == 'header') {
                    $group[] = $this->form->createElement("static", null, null, $v);
                } else {
                    $field = $key . "_" . $k;
                    if ($key == 'grand_mother') {
                        if($k == 'family_member'){
                        $group[] = $this->form->createElement("static", null, null, $val);
                        }elseif($k == 'relationship_to_fxs'){
                        $group[] = $this->form->createElement("static", null, null, "Maternal Grandmother");
                        }elseif($k == 'sex'){
                            $group[] = $this->form->createElement("static", null, null, "Female");
                            }elseif($k == 'date_of_birth'){
                                $group[] = $this->form->createElement("date", $field, null);
                                $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                }elseif($k == 'genetic_testing'){
                                    $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                    }else{
                                        $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]); 
                                        $this->XINRegisterRule($field, array("$field{@}=={@}"), "Required. ", "{$field}_group"); 
                                    }
                    }elseif($key == 'grand_father') {
                        if($k == 'family_member'){
                            $group[] = $this->form->createElement("static", null, null, $val);
                            }elseif($k == 'relationship_to_fxs'){
                            $group[] = $this->form->createElement("static", null, null, "Maternal Grandfather");
                            }elseif($k == 'sex'){
                                $group[] = $this->form->createElement("static", null, null, "Male");
                                }elseif($k == 'date_of_birth'){
                                    $group[] = $this->form->createElement("date", $field, null);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                    }elseif($k == 'genetic_testing'){
                                        $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                        $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                        }else{
                                            $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]);  
                                            $this->XINRegisterRule($field, array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                        } 
                    }elseif($key == 'aunt1' || $key == 'aunt2'  || $key == 'aunt3'){
                        if($k == 'family_member'){
                            $group[] = $this->form->createElement("static", null, null, $val);
                            }elseif($k == 'relationship_to_fxs'){
                            $group[] = $this->form->createElement("static", null, null, "Maternal aunt");
                            }elseif($k == 'sex'){
                                $group[] = $this->form->createElement("static", null, null, "Female");
                                }elseif($k == 'date_of_birth'){
                                    $group[] = $this->form->createElement("date", $field, null);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                    }elseif($k == 'genetic_testing'){
                                        $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                        $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                        }else{
                                            $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]);  
                                            $this->XINRegisterRule($field, array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                        } 
                    }elseif($key == 'uncle1' || $key == 'uncle2' || $key == 'uncle3'){
                        if($k == 'family_member'){
                            $group[] = $this->form->createElement("static", null, null, $val);
                            }elseif($k == 'relationship_to_fxs'){
                            $group[] = $this->form->createElement("static", null, null, "Maternal uncle");
                            }elseif($k == 'sex'){
                                $group[] = $this->form->createElement("static", null, null, "Male");
                                }elseif($k == 'date_of_birth'){
                                    $group[] = $this->form->createElement("date", $field, null);
                                    $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                    }elseif($k == 'genetic_testing'){
                                        $group[] = $this->form->createElement("select", $field, null,$yes_no_option);
                                        $this->XINRegisterRule("$field", array("$field{@}=={@}"), "Required.", "{$field}_group");
                                        }else{
                                            $group[] = $this->form->createElement("select", $field, null,$options,["multiple"]);  
                                            $this->XINRegisterRule($field, array("$field{@}=={@}"), "Required. ", "{$field}_group");
                                        } 
                    }
                }
            }
            $this->form->addGroup($group, $groupname, null, $this->_GUIDelimiter, false);
            unset($group);
        }

	    for ($i = 1; $i <=4; $i++) {
            $group[] = $this->form->createElement("text","moms_family_member".$i, null, "Mom's");
            $this->XINRegisterRule("moms_family_member{$i}", array("moms_family_member{$i}{@}=={@}"), "Required. ", "moms_family_member{$i}_group");
	    $group[] = $this->form->createElement("text","moms_relationship_to_fxs".$i, null, "Maternal");
            $this->XINRegisterRule("moms_relationship_to_fxs{$i}", array("moms_relationship_to_fxs{$i}{@}=={@}"), "Required. ", "moms_relationship_to_fxs{$i}_group");
	    $group[] = $this->form->createElement("select", "moms_sex".$i, null, $gender);
            $this->XINRegisterRule("moms_sex{$i}", array("moms_sex{$i}{@}=={@}"), "Required.", "moms_sex{$i}_group");
	    $group[] = $this->form->createElement("date","moms_date_of_birth".$i, null);
            $this->XINRegisterRule("moms_date_of_birth{$i}", array("moms_date_of_birth{$i}{@}=={@}"), "Required.", "moms_date_of_birth{$i}_group");
	    $group[] = $this->form->createElement("select", "moms_genetic_testing".$i, null,$yes_no_option);
            $this->XINRegisterRule("moms_genetic_testing{$i}", array("moms_genetic_testing{$i}{@}=={@}"), "Required.", "moms_genetic_testing{$i}_group");
	    $group[] = $this->form->createElement("select", "moms_result".$i, null,$options,["multiple"]); 
            $this->XINRegisterRule("moms_result{$i}", array("(moms_result{$i}{@}=={@}"), "Required. ", "moms_result{$i}_group");
            $this->form->addGroup($group, "moms".$i."_group", null, $this->_GUIDelimiter, false);
            unset($group);
            }



    }

    function _page2(){

        $this->addHeader("SECTION 2: FAMILY SCREENING FOR FRAGILE X ASSOCIATED DISORDERS");

        $table_heading = array('family_member' => 'Family Member', 'relationship_to_fxs' => 'Relationship to FXS child in study',
                                'sex' => 'Sex', 'date_of_birth' => 'Date of Birth', 'diagnosed' => 'Diagnosed with FXPOI/ FAXTAS',
                                'symptoms' => 'Symptoms');
        $questions =array('aunt1' => 'Aunt (Mom’s Sister)', 'aunt2' => 'Aunt (Mom’s Sister)', 'aunt3' => 'Aunt (Mom’s Sister)', 'aunt4' => 'Aunt (Mom’s Sister)', 
                          'aunt5' => 'Aunt (Mom’s Sister)' );

        $extended_questions =array('uncle1' => 'Uncle (Mom’s Brother)', 'uncle2' => 'Uncle (Mom’s Brother)', 'uncle3' => 'Uncle (Mom’s Brother)', 
                                    'uncle4' => 'Uncle (Mom’s Brother)','uncle5' => 'Uncle (Mom’s Brother)' );

        $yes_no_option = array(null => '', 'yes' => 'Yes', 'no' => 'No', 'unknown' => 'Unknown');
        $symptoms1 = array('irregular_menstrual_cycles' => 'Irregular menstrual cycles', 'infertility_having_children' => 'Infertility/difficulty having children', 'hot_flashes' => 'Hot flashes', 'premature_ovarian_failure' => 'Premature ovarian failure');
        $symptoms2 = array('intention_tremor' => 'Intention tremor', 'gait_ataxias' => 'Gait ataxias', 'parkinsonism' => 'Parkinsonism', 'short_term_memory' => 'Short-term memory problems', 'executive_function_problems' => 'Executive function problems');
        

        $group[] = $this->form->createElement("static",null,null,"Family Member");
        $group[] = $this->form->createElement("static",null,null,"Relationship to FXS <br> child in study");
        $group[] = $this->form->createElement("static",null,null,"Sex");
        $group[] = $this->form->createElement("static",null,null,"Date of Birth");
        $group[] = $this->form->createElement("static",null,null,"Diagnosed with <br> FXPOI/ FAXTAS");
        $group[] = $this->form->createElement("static",null,null,"Symptoms");
        $this->form->addGroup($group,"page_2_header",null,$this->_GUIDelimiter,false);
        unset($group);

        $this->addHeader("<h3>MOTHER OF CHILD WITH FXS</h3>");

	$group[] = $this->form->createElement("static",null,null, "Mother".$this->indent.$this->indent.$this->indent.$this->indent);
        $group[] = $this->form->createElement("static",null, null, "Mother".$this->indent.$this->indent.$this->indent.$this->indent);
        $group[] = $this->form->createElement("static",null, null, "Female".$this->indent.$this->indent.$this->indent.$this->indent);
        $group[] = $this->form->createElement("date", "mother_section2_date_of_birth", null);
        $this->XINRegisterRule("mother_section2_date_of_birth", array("mother_section2_date_of_birth{@}=={@}"), "Required.", "mother_section2_genetic_testing_group");
        $group[] = $this->form->createElement("select", "mother_section2_genetic_testing", null,$yes_no_option);
        $this->XINRegisterRule("mother_section2_genetic_testing", array("mother_section2_genetic_testing{@}=={@}"), "Required.", "mother_section2_genetic_testing_group");
        $group[] = $this->form->createElement("select", "mother_section2_result", null,$symptoms1,["multiple"]); 
        $this->XINRegisterRule("mother_section2_result", array("mother_section2_result{@}=={@}"), "Required. ", "mother_section2_result_group");
        $this->form->addGroup($group, "mother_section2_group", null, $this->_GUIDelimiter, false);
        unset($group);

        $this->addHeader("<h3>GRANDMOTHER, AUNT(S) OF CHILD WITH FXS</h3>");

        $group[] = $this->form->createElement("static",null, null, "Grandmother (Mom’s Mother)");
        $group[] = $this->form->createElement("static",null, null, "Maternal grandMother");
        $group[] = $this->form->createElement("static", null, null, "Female");
        $group[] = $this->form->createElement("date", "grandmother_section2_date_of_birth", null);
        $this->XINRegisterRule("grandmother_section2_date_of_birth", array("grandmother_section2_date_of_birth{@}=={@}"), "Required.", "grandmother_section2_date_of_birth_group");
        $group[] = $this->form->createElement("select", "grandmother_section2_genetic_testing", null,$yes_no_option);
        $this->XINRegisterRule("grandmother_section2_genetic_testing", array("grandmother_section2_genetic_testing{@}=={@}"), "Required.", "grandmother_section2_genetic_testing_group");
        $group[] = $this->form->createElement("select", "grandmother_section2_result", null,$symptoms1,["multiple"]); 
        $this->XINRegisterRule("grandmother_section2_result", array("grandmother_section2_result{@}=={@}"), "Required. ", "grandmother_section2_result_group");
        $this->form->addGroup($group, "grandmother_section2_group", null, $this->_GUIDelimiter, false);
        unset($group);

        for($i=1; $i<=5;$i++){
        $group[] = $this->form->createElement("static",null, null, "Aunt (Mom’s Sister)");
        $group[] = $this->form->createElement("static",null, null, "Maternal aunt");
        $group[] = $this->form->createElement("static", null, null, "Female");
        $group[] = $this->form->createElement("date", "moms_sister_date_of_birth".$i, null);
        $this->XINRegisterRule("moms_sister_date_of_birth{$i}", array("moms_sister_date_of_birth{$i}{@}=={@}"), "Required.", "moms_sister_date_of_birth{$i}_group");
        $group[] = $this->form->createElement("select", "moms_sister_genetic_testing".$i, null,$yes_no_option);
        $this->XINRegisterRule("moms_sister_genetic_testing{$i}", array("moms_sister_genetic_testing{$i}{@}=={@}"), "Required.", "moms_sister_genetic_testing{$i}_group");
        $group[] = $this->form->createElement("select", "moms_sister_result".$i, null,$symptoms1,["multiple"]); 
        $this->XINRegisterRule("moms_sister_result{$i}", array("moms_sister_result{$i}{@}=={@}"), "Required. ", "moms_sister_result{$i}_group");
        $this->form->addGroup($group, "moms_sister".$i."_group", null, $this->_GUIDelimiter, false);
        unset($group);
        }

        $this->addHeader("<h3>GRANDFATHER, UNCLE(S) OF CHILD WITH FXS</h3>");

        $group[] = $this->form->createElement("static",null, null, "Grandfather (Mom’s father)");
        $group[] = $this->form->createElement("static",null, null, "Maternal grandfather");
        $group[] = $this->form->createElement("static", null, null, "Male");
        $group[] = $this->form->createElement("date", "grandfather_section2_date_of_birth", null);
        $this->XINRegisterRule("grandfather_section2_date_of_birth", array("grandfather_section2_date_of_birth{@}=={@}"), "Required.", "grandfather_section2_date_of_birth_group");
        $group[] = $this->form->createElement("select", "grandfather_section2_genetic_testing", null,$yes_no_option);
        $this->XINRegisterRule("grandfather_section2_genetic_testing", array("grandfather_section2_genetic_testing{@}=={@}"), "Required.", "grandfather_section2_genetic_testing_group");
        $group[] = $this->form->createElement("select", "grandfather_section2_result", null,$symptoms2,["multiple"]); 
        $this->XINRegisterRule("grandfather_section2_result", array("grandfather_section2_result{@}=={@}"), "Required. ", "grandfather_section2_result_group");
        $this->form->addGroup($group, "grandfather_section2_group", null, $this->_GUIDelimiter, false);
        unset($group);

        for($i=1; $i<=5;$i++){
        $group[] = $this->form->createElement("static",null, null, "Uncle (Mom’s Brother)");
        $group[] = $this->form->createElement("static",null, null, "Maternal uncle");
        $group[] = $this->form->createElement("static", null, null, "Male");
        $group[] = $this->form->createElement("date", "moms_brother_date_of_birth".$i, null);
        $this->XINRegisterRule("moms_brother_date_of_birth{$i}", array("moms_brother_date_of_birth{$i}{@}=={@}"), "Required.", "moms_brother_date_of_birth{$i}_group");
        $group[] = $this->form->createElement("select", "moms_brother_genetic_testing".$i, null,$yes_no_option);
        $this->XINRegisterRule("moms_brother_genetic_testing{$i}", array("moms_brother_genetic_testing{$i}{@}=={@}"), "Required.", "moms_brother_genetic_testing{$i}_group");
        $group[] = $this->form->createElement("select", "moms_brother_result".$i, null,$symptoms2,["multiple"]); 
        $this->XINRegisterRule("moms_brother_result{$i}", array("moms_brother_result{$i}{@}=={@}"), "Required. ", "moms_brother_result{$i}_group");
        $this->form->addGroup($group, "moms_brother".$i."_group", null, $this->_GUIDelimiter, false);
        unset($group);
        }


    }


}
?>
