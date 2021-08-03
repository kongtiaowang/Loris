<?php
/**
 * This file contains the NDB_BVL_Instrument_SIHI class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  SIHI
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

/**
 * Creates the form elements for the SIHI instrument
 *
 * @category Instrument
 * @package  SIHI
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */
class NDB_BVL_Instrument_SIHI extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;
    

       var  $yes_no_options = array(
                           "yes" => "Yes",
                           "no"  => "No",
                          );

       var  $rate_concern_options = array(
                                 null         => "",
                                 "1"          => "1 - Mild",
                                 "2"          => "2",
                                 "3"          => "3",
                                 "4"          => "4",
                                 "5"          => "5",
                                 "6"          => "6",
                                 "7"          => "7",
                                 "8"          => "8",
                                 "9"          => "9",
                                 "10"         => "10 - Extreme",
                         );

       var  $option4_source = array(
                            null                        => "",
                            "non_professional"          => "Non-professional (friends, books)",
                            "non_medical_proffesional"  => "Non-medical professional (e.g., acupuncture)",
                            "pediatrician"              => "Pediatrician",
                            "sleep_specialist"          => "Sleep specialist",
                    );
       var  $option4_specialist = array(
                              null         => "",
                              "short_term" => "Short Term (1 to 2 sessions)",
                              "long_term"  => "Long Term (3 or more sessions)",
                      );

       var  $option5_select =  array(
            null                          => "",
            "behavioral_intervention"     => "Behavioral intervention (e.g., CBT-I)",
            "nonpharmacological_medical"  => "Nonpharmacological medical (e.g., CPAP)",
            "medication"                  => "Medication (e.g., melatonin, clonidine, trazodone, remeron, risperdal, seroqual, ambien, benzodiazepines)",
            "dietary_supplements"         => "Dietary supplements (e.g., magnesium, iron)",
        );

       var  $option5_medication = array(
            null           => "",
            "melatonin"    => "Melatonin",
            "clonidine"    => "Clonidine (Catapres, Kapvay, Nexiclon)",
            "trazodone"    => "Trazodone (Desyrel, Desyrel Dividose, Oleptro,Trazodone D)",
            "mirtazapine"  => "Mirtazapine (Remeron, Remeron SolTab)",
            "risperidone"  => "Risperidone (Risperdal, Risperdal Consta, Risperdal M-Tab)",
            "quetiapine"   => "Quetiapine (Seroquel, Seroquel XR)",
            "zolpidem"     => "Zolpidem (Ambien, Ambien CR, Edluar, Zolpimist, Intermezzo)",
            "zaleplon"     => "Zaleplon (Sonata)",
            "temazepam"    => "Temazepam (Restoril)",
            "eszopiclone"  => "Eszopiclone (Lunesta)",
            "clonazepam"   => "Clonazepam (Klonopin)",
        );


    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('SIHI', "SIHI (Sleep Intervention History Interview)", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SIHI','SIHI_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SIHI','SIHI_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SIHI','SIHI_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SIHI','SIHI_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SIHI','SIHI_page5', "Page 5", 5);
     */
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
        $this->form     = new LorisForm('SIHI');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        // Corresponds to the Test_name column in test_names table
        $this->testName = "SIHI";
        // name of database table corresponding to instrument
        $this->table = 'SIHI';
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
	$this->_selectMultipleElements = array(
		      'i_q4_if_yes_select_source',
		      'i_q5_if_yes_select',
		      'i_q5_if_medication_select_which_medicine_your_child_used',
		      'ii_q4_if_yes_select_source',
		      'ii_q5_if_yes_select',
		      'ii_q5_if_medication_select_which_medicine_your_child_used',
		      'iii_q4_if_yes_select_source',
		      'iii_q5_if_yes_select',
		      'iii_q5_if_medication_select_which_medicine_your_child_used',
		      'iv_q4_if_yes_select_source',
		      'iv_q5_if_yes_select',
		      'iv_q5_if_medication_select_which_medicine_your_child_used',
		      'v_q4_if_yes_select_source',
		      'v_q5_if_yes_select',
		      'v_q5_if_medication_select_which_medicine_your_child_used');
        // required fields for data entry completion status
        $this->_requiredElements = array(
            'i_q1_any_concerns_about_childs_nighttime_sleep',
            'ii_q1_any_concerns_about_childs_nighttime_sleep',
            'iii_q1_any_concerns_about_childs_nighttime_sleep',
            'iv_q1_any_concerns_about_childs_nighttime_sleep',
            'v_q1_any_concerns_about_childs_nighttime_sleep');
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
        if (preg_match("/SIHI(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("SIHI (Sleep Intervention History Interview)");

        $config      =& NDB_Config::singleton();
        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );
        $this->addBasicDate('Date_taken', 'Date of Administration', $dateOptions);

        $this->form->addElement(
            'select',
            'respondent',
            'What is your relationship to the child',
            array(
             ''            => '',
             'mother'      => 'Mother',
             'father'      => 'Father',
             'step_mother' => 'Step Mother',
             'step_father' => 'Step Father',
             'other'       => 'Other',
            )
        );
        $this->form->addElement('text', 'respondent_specify', 'If other, specify:');
        $this->XINRegisterRule('respondent_specify', array('respondent{@}=={@}other'), 'Required if other');

        $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    /**
     * Generates the first page of the form.
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("SIHI (Sleep Intervention History Interview)");

        $this->form->addElement(
            'static',
            lorisSubHeader,
            "Use the following questions to anchor each time period:<br>" . $this->indent .
            "What month/year was your child born? [first time period only]<br>" . $this->indent .
            "Where were you living at the time?<br>" . $this->indent .
            "Where did your child sleep (own/shared room)?<br>" . $this->indent .
            "Any significant family events (change of job, birth of sibling, moved) during that time?"
        );

        $this->form->addElement(
            'static',
            null,
            "<h3><b>I. First year of life:</b></h3>"
        );

        $this->addSelect("i_q1_any_concerns_about_childs_nighttime_sleep", "1. Any concerns about your child's nighttime sleep?", $this->yes_no_options);

        $this->addSelect("i_q1_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('i_q1_if_yes_rate_concern', array('i_q1_any_concerns_about_childs_nighttime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addSelect("i_q2_any_concerns_about_childs_daytime_sleep", "2. Any concerns about your child's daytime sleep (i.e., naps)?", $this->yes_no_options);

        $this->addSelect("i_q2_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('i_q2_if_yes_rate_concern', array('i_q2_any_concerns_about_childs_daytime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addTextAreaElement("i_q3_any_external_influences_affected_sleep", "3. Any external influences that might have affected sleep (e.g., schedule, siblings, etc.)?");

        $this->addSelect("i_q4_seek_information_to_help_child_sleep_better", "4. Seek out information to help your child sleep better (e.g., books, professional help)?", $this->yes_no_options);

        $this->addSelect(
            "i_q4_if_yes_select_source",
            $this->indent . "If yes, select source:",
	    $this->option4_source,
            ["multiple"]
            );
	
      	$this->XINRegisterRule('i_q4_if_yes_select_source', array('i_q4_seek_information_to_help_child_sleep_better{@}=={@}yes'), 'Required if yes');
	
	$this->addSelect(
            "i_q4_if_sleep_specialist",
            $this->indent . "If sleep specialist, was it a short term or long-term consult?",
	    $this->option4_specialist
        );

        $this->XINRegisterRule('i_q4_if_sleep_specialist', array('i_q4_if_yes_select_source{@}=={@}sleep_specialist'), 'Required if Sleep specialist');

        $this->addSelect("i_q5_did_child_receive_intervention", "5. Did your child receive any intervention or take medication or supplements for sleep?", $this->yes_no_options);

        $this->addSelect(
            "i_q5_if_yes_select",
            $this->indent . "If yes, select:",
	    $this->option5_select,
	    ["multiple"]
            );
	
        $this->XINRegisterRule('i_q5_if_yes_select', array('i_q5_did_child_receive_intervention{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "i_q5_if_medication_select_which_medicine_your_child_used",
            $this->indent . "If medication, select which medicine your child used:",
	    $this->option5_medication,
	    ["multiple"]
        );

        $this->XINRegisterRule('i_q5_if_medication_select_which_medicine_your_child_used', array('i_q5_if_yes_select{@}=={@}medication'), 'Required if medication');

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    function _page2()
    {
        $this->addHeader("SIHI (Sleep Intervention History Interview)");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>II. Toddler years (age 2-3):</b></h3>"
        );

        $this->addSelect("ii_q1_any_concerns_about_childs_nighttime_sleep", "1. Any concerns about your child's nighttime sleep?", $this->yes_no_options);

        $this->addSelect("ii_q1_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('ii_q1_if_yes_rate_concern', array('ii_q1_any_concerns_about_childs_nighttime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addSelect("ii_q2_any_concerns_about_childs_daytime_sleep", "2. Any concerns about your child's daytime sleep (i.e., naps)?", $this->yes_no_options);

        $this->addSelect("ii_q2_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('ii_q2_if_yes_rate_concern', array('ii_q2_any_concerns_about_childs_daytime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addTextAreaElement("ii_q3_any_external_influences_affected_sleep", "3. Any external influences that might have affected sleep (e.g., schedule, siblings, etc.)?");

        $this->addSelect("ii_q4_seek_information_to_help_child_sleep_better", "4. Seek out information to help your child sleep better (e.g., books, professional help)?", $this->yes_no_options);

        $this->addSelect(
            "ii_q4_if_yes_select_source",
            $this->indent . "If yes, select source:",
	    $this->option4_source,
	    ["multiple"]
    );

        $this->XINRegisterRule('ii_q4_if_yes_select_source', array('ii_q4_seek_information_to_help_child_sleep_better{@}=={@}yes'), 'Required if yes');

	 $this->addSelect(
            "ii_q4_if_sleep_specialist",
            $this->indent . "If sleep specialist, was it a short term or long-term consult?",
	    $this->option4_specialist
        );
        
        $this->XINRegisterRule('ii_q4_if_sleep_specialist', array('ii_q4_if_yes_select_source{@}=={@}sleep_specialist'), 'Required if Sleep specialist');

        $this->addSelect("ii_q5_did_child_receive_intervention", "5. Did your child receive any intervention or take medication or supplements for sleep?", $this->yes_no_options);

        $this->addSelect(
            "ii_q5_if_yes_select",
            $this->indent . "If yes, select:",
	    $this->option5_select,
	    ["multiple"]
        );
        $this->XINRegisterRule('ii_q5_if_yes_select', array('ii_q5_did_child_receive_intervention{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "ii_q5_if_medication_select_which_medicine_your_child_used",
            $this->indent . "If medication, select which medicine your child used:",
	    $this->option5_medication,
	    ["multiple"]
        );

        $this->XINRegisterRule('ii_q5_if_medication_select_which_medicine_your_child_used', array('ii_q5_if_yes_select{@}=={@}medication'), 'Required if medication');

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    function _page3()
    {
        $this->addHeader("SIHI (Sleep Intervention History Interview)");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>III. Preschool/kindergarten (age 4-6):</b></h3>"
        );

        $this->addSelect("iii_q1_any_concerns_about_childs_nighttime_sleep", "1. Any concerns about your child's nighttime sleep?", $this->yes_no_options);

        $this->addSelect("iii_q1_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('iii_q1_if_yes_rate_concern', array('iii_q1_any_concerns_about_childs_nighttime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addSelect("iii_q2_any_concerns_about_childs_daytime_sleep", "2. Any concerns about your child's daytime sleep (i.e., naps)?", $this->yes_no_options);

        $this->addSelect("iii_q2_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('iii_q2_if_yes_rate_concern', array('iii_q2_any_concerns_about_childs_daytime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addTextAreaElement("iii_q3_any_external_influences_affected_sleep", "3. Any external influences that might have affected sleep (e.g., schedule, siblings, etc.)?");

        $this->addSelect("iii_q4_seek_information_to_help_child_sleep_better", "4. Seek out information to help your child sleep better (e.g., books, professional help)?", $this->yes_no_options);

        $this->addSelect(
            "iii_q4_if_yes_select_source",
            $this->indent . "If yes, select source:",
	    $this->option4_source,
	    ["multiple"]
        );
        $this->XINRegisterRule('iii_q4_if_yes_select_source', array('iii_q4_seek_information_to_help_child_sleep_better{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "iii_q4_if_sleep_specialist",
            $this->indent . "If sleep specialist, was it a short term or long-term consult?",
	    $this->option4_specialist
        );
        
        $this->XINRegisterRule('iii_q4_if_sleep_specialist', array('iii_q4_if_yes_select_source{@}=={@}sleep_specialist'), 'Required if Sleep specialist');

        $this->addSelect("iii_q5_did_child_receive_intervention", "5. Did your child receive any intervention or take medication or supplements for sleep?", $this->yes_no_options);

        $this->addSelect(
            "iii_q5_if_yes_select",
            $this->indent . "If yes, select:",
	    $this->option5_select,
	    ["multiple"]
    );

        $this->XINRegisterRule('iii_q5_if_yes_select', array('iii_q5_did_child_receive_intervention{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "iii_q5_if_medication_select_which_medicine_your_child_used",
            $this->indent . "If medication, select which medicine your child used:",
	    $this->option5_medication,
	    ["multiple"]
        );

        $this->XINRegisterRule('iii_q5_if_medication_select_which_medicine_your_child_used', array('iii_q5_if_yes_select{@}=={@}medication'), 'Required if medication');

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    function _page4()
    {
        $this->addHeader("SIHI (Sleep Intervention History Interview)");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>IV. Early elementary school (grade 1-3)</b></h3>"
        );

        $this->addSelect("iv_q1_any_concerns_about_childs_nighttime_sleep", "1. Any concerns about your child's nighttime sleep?", $this->yes_no_options);

        $this->addSelect("iv_q1_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('iv_q1_if_yes_rate_concern', array('iv_q1_any_concerns_about_childs_nighttime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addSelect("iv_q2_any_concerns_about_childs_daytime_sleep", "2. Any concerns about your child's daytime sleep (i.e., naps)?", $this->yes_no_options);

        $this->addSelect("iv_q2_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('iv_q2_if_yes_rate_concern', array('iv_q2_any_concerns_about_childs_daytime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addTextAreaElement("iv_q3_any_external_influences_affected_sleep", "3. Any external influences that might have affected sleep (e.g., schedule, siblings, etc.)?");

        $this->addSelect("iv_q4_seek_information_to_help_child_sleep_better", "4. Seek out information to help your child sleep better (e.g., books, professional help)?", $this->yes_no_options);

        $this->addSelect(
            "iv_q4_if_yes_select_source",
            $this->indent . "If yes, select source:",
	    $this->option4_source,
	    ["multiple"]
        );
        $this->XINRegisterRule('iv_q4_if_yes_select_source', array('iv_q4_seek_information_to_help_child_sleep_better{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "iv_q4_if_sleep_specialist",
            $this->indent . "If sleep specialist, was it a short term or long-term consult?",
	    $this->option4_specialist
        );
        
        $this->XINRegisterRule('iv_q4_if_sleep_specialist', array('iv_q4_if_yes_select_source{@}=={@}sleep_specialist'), 'Required if Sleep specialist');

        $this->addSelect("iv_q5_did_child_receive_intervention", "5. Did your child receive any intervention or take medication or supplements for sleep?", $this->yes_no_options);

        $this->addSelect(
            "iv_q5_if_yes_select",
            $this->indent . "If yes, select:",
	    $this->option5_select,
	    ["multiple"]
    );

        $this->XINRegisterRule('iv_q5_if_yes_select', array('iv_q5_did_child_receive_intervention{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "iv_q5_if_medication_select_which_medicine_your_child_used",
            $this->indent . "If medication, select which medicine your child used:",
	    $this->option5_medication,
	    ["multiple"]
        );

        $this->XINRegisterRule('iv_q5_if_medication_select_which_medicine_your_child_used', array('iv_q5_if_yes_select{@}=={@}medication'), 'Required if medication');

        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    function _page5()
    {
        $this->addHeader("SIHI (Sleep Intervention History Interview)");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>V. Late elementary school (grade 4-5)</b></h3>"
        );

        $this->addSelect("v_q1_any_concerns_about_childs_nighttime_sleep", "1. Any concerns about your child's nighttime sleep?", $this->yes_no_options);

        $this->addSelect("v_q1_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('v_q1_if_yes_rate_concern', array('v_q1_any_concerns_about_childs_nighttime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addSelect("v_q2_any_concerns_about_childs_daytime_sleep", "2. Any concerns about your child's daytime sleep (i.e., naps)?", $this->yes_no_options);

        $this->addSelect("v_q2_if_yes_rate_concern", $this->indent . "If yes, rate concern:", $this->rate_concern_options);
        $this->XINRegisterRule('v_q2_if_yes_rate_concern', array('v_q2_any_concerns_about_childs_daytime_sleep{@}=={@}yes'), 'Required if yes');

        $this->addTextAreaElement("v_q3_any_external_influences_affected_sleep", "3. Any external influences that might have affected sleep (e.g., schedule, siblings, etc.)?");

        $this->addSelect("v_q4_seek_information_to_help_child_sleep_better", "4. Seek out information to help your child sleep better (e.g., books, professional help)?", $this->yes_no_options);

        $this->addSelect(
            "v_q4_if_yes_select_source",
            $this->indent . "If yes, select source:",
	    $this->option4_source,
	    ["multiple"]
        );
	
	$this->XINRegisterRule('v_q4_if_yes_select_source', array('v_q4_seek_information_to_help_child_sleep_better{@}=={@}yes'), 'Required if yes');

	 $this->addSelect(
            "v_q4_if_sleep_specialist",
            $this->indent . "If sleep specialist, was it a short term or long-term consult?",
	    $this->option4_specialist
        );
        
        $this->XINRegisterRule('v_q4_if_sleep_specialist', array('v_q4_if_yes_select_source{@}=={@}sleep_specialist'), 'Required if Sleep specialist');

        $this->addSelect("v_q5_did_child_receive_intervention", "5. Did your child receive any intervention or take medication or supplements for sleep?", $this->yes_no_options);

        $this->addSelect(
            "v_q5_if_yes_select",
            $this->indent . "If yes, select:",
	    $this->option5_select,
	    ["multiple"]
        );
	
	$this->XINRegisterRule('v_q5_if_yes_select', array('v_q5_did_child_receive_intervention{@}=={@}yes'), 'Required if yes');

	$this->addSelect(
            "v_q5_if_medication_select_which_medicine_your_child_used",
            $this->indent . "If medication, select which medicine your child used:",
	    $this->option5_medication,
	    ["multiple"]
        );

        $this->XINRegisterRule('v_q5_if_medication_select_which_medicine_your_child_used', array('v_q5_if_yes_select{@}=={@}medication'), 'Required if medication');

        $this->form->addFormRule(array(&$this, 'validate_page5'));
    }

    function validate_main_page($values)
    {
        $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

        return $errors;
    }

    function validate_page1($values)
    {
        $errors = [];

        if ($values["i_q1_any_concerns_about_childs_nighttime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["i_q1_if_yes_rate_concern"], $errors);
        }

        if ($values["i_q2_any_concerns_about_childs_daytime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["i_q2_if_yes_rate_concern"], $errors);
	}

	if (strpos(implode(",",$values["i_q4_if_yes_select_source"]), "sleep_specialist") === false ) {
            $this->validate_empty_subquestions($values, ["i_q4_if_sleep_specialist"], $errors);
	}

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        if ($values["ii_q1_any_concerns_about_childs_nighttime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["ii_q1_if_yes_rate_concern"], $errors);
        }

        if ($values["ii_q2_any_concerns_about_childs_daytime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["ii_q2_if_yes_rate_concern"], $errors);
	}

	if (strpos(implode(",",$values["ii_q4_if_yes_select_source"]), "sleep_specialist") === false) {
            $this->validate_empty_subquestions($values, ["ii_q4_if_sleep_specialist"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["iii_q1_any_concerns_about_childs_nighttime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["iii_q1_if_yes_rate_concern"], $errors);
        }

        if ($values["iii_q2_any_concerns_about_childs_daytime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["iii_q2_if_yes_rate_concern"], $errors);
	}

	if (strpos(implode(",",$values["iii_q4_if_yes_select_source"]), "sleep_specialist") === false) {
            $this->validate_empty_subquestions($values, ["iii_q4_if_sleep_specialist"], $errors);
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        if ($values["iv_q1_any_concerns_about_childs_nighttime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["iv_q1_if_yes_rate_concern"], $errors);
        }

        if ($values["iv_q2_any_concerns_about_childs_daytime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["iv_q2_if_yes_rate_concern"], $errors);
	}

	if (strpos(implode(",",$values["iv_q4_if_yes_select_source"]), "sleep_specialist") === false) {
           $this->validate_empty_subquestions($values, ["iv_q4_if_sleep_specialist"], $errors);
        }

        return $errors;
    }

    function validate_page5($values)
    {
        $errors = [];

        if ($values["v_q1_any_concerns_about_childs_nighttime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["v_q1_if_yes_rate_concern"], $errors);
        }

        if ($values["v_q2_any_concerns_about_childs_daytime_sleep"] != "yes") {
            $this->validate_empty_subquestions($values, ["v_q2_if_yes_rate_concern"], $errors);
	}

	if (strpos(implode(",",$values["v_q4_if_yes_select_source"]), "sleep_specialist") === false ) {
            $this->validate_empty_subquestions($values, ["v_q4_if_sleep_specialist"], $errors);
        }

        return $errors;
    }
}
?>
