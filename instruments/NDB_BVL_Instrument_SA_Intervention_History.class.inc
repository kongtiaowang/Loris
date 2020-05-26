<?php
/*
 * This file contains the NDB_BVL_Instrument_CSHQ
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
 * Creates the form elements for the SA_Intervention_History instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_SA_Intervention_History extends NDB_BVL_Instrument
{
    var $ValidityEnabled = false;
    var $ValidityRequired = false;
    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('SA_Intervention_History_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = 'SA_Intervention_History';           // test_names.Test_name
        $this->table = 'SA_Intervention_History';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();
        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
        );
        $config = NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null,
        );
        // setup the form
        $this->_setupForm();
    }
    /*
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/SA_Intervention_History(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
       // $this->form->addFormRule(array(&$this, 'XINValidate'));
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
        $this->addHeader("EDUCATIONAL/INTERVENTION HISTORY<br>
                         <h5>Adapted from HISTORY QUESTIONNAIRE: Long-term Outcomes in Autism Study</h5>");
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");
        $this->_addMetadataFields();
        $opts = array(
            null              => "",
            "mother"             => "Mother",
            "father"             => "Father",
            "step_mother"        => "Step Mother",
            "step_father"        => "Step Father",
            "other"             => "Other",
        );
        $this->addSelect("relationship_to_child", "Your relationship to the child:", $opts);
        $this->addBasicText("relationship_to_child_other", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "relationship_to_child_other",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "relationship_to_child_other"
        );
        $this->addBasicText("interviewer_initials", "Interviewer's initials:");
    }
    function _page1()
    {
        $this->addLabel("<h4>We’re going to discuss any special services or supports your child has received since 
                                 he/she was a baby.  If there are any details you are unsure of, do your best to give an 
                                 estimate. As with all the information you provide to us, your responses will remain
                                 confidential and will be used only for the purposes of the study.<br><br></h4>");
        $yesNoOptions =
            array(
                null => "",
                "yes" => "Yes",
                "no" => "No",
                "dont_know" => "Don't know"
            );
        $minutes_array =
            array(
                null => "",
                30 => "30",
                60 => "60",
                90 => "90",
                120 => "120",
                180 => "180"
            );
        $num_times_array =
            array(
                null=>"",
                1=>"1",
                2=>"2",
                3=>"3",
                4=>"4",
                5=>"5",
                6=>"6",
                7=>"7"
            );
        $years_array =
            array(
                null => "",
                0 => "0",
                1 => "1",
                2 => "2",
                3 => "3",
                4 => "4",
                5 => "5",
                6 => "6",
                7 => "7",
                8 => "8",
                9 => "9",
                10 => "10"
            );
        $months_array =
            array(
                null=>"",
                1=>"1",
                2=>"2",
                3=>"3",
                4=>"4",
                5=>"5",
                6=>"6",
                7=>"7",
                8=>"8",
                9=>"9",
                10=>"10",
                11=>"11"
            );
        ####### QUESTION 1 #######
        $this->addSelect(
            "birth_to_three_services",
            "1. Has [child's name] ever received Birth to Three services?",
            $yesNoOptions
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Minutes");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Times per week");
        $this->addGroup(
            $group,
            "q1_frequency_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $group[] =& $this->createSelect(
            "birth_to_three_services_minutes",
            "",
            $minutes_array
        );
        $this->XINRegisterRule(
            "birth_to_three_services_minutes",
            array("birth_to_three_services{@}=={@}yes"),
            "Minutes per session required if answer to question is yes.",
            "q1_frequency"
        );
        $group[] =& $this->createSelect(
            "birth_to_three_services_times_per_week",
            "",
            $num_times_array
        );
        $this->XINRegisterRule(
            "birth_to_three_services_times_per_week",
            array("birth_to_three_services{@}=={@}yes"),
            "Times per week required if answer to question is yes.",
            "q1_frequency"
        );
        $this->addGroup(
            $group,
            "q1_frequency",
            "If YES, please specify",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Years");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Months");
        $this->addGroup(
            $group,
            "q1_duration_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $group[] =& $this->createSelect(
            "birth_to_three_services_years",
            "",
            $years_array
        );
        $this->XINRegisterRule(
            "birth_to_three_services_years",
            array("birth_to_three_services{@}=={@}yes"),
            "Times per week required if answer to question is yes.",
            "q1_duration"
        );
        $group[] =& $this->createSelect(
            "birth_to_three_services_months",
            "",
            $months_array
        );
        $this->XINRegisterRule(
            "birth_to_three_services_months",
            array("birth_to_three_services{@}=={@}yes"),
            "Times per week required if answer to question is yes.",
            "q1_duration"
        );
        $this->addGroup(
            $group,
            "q1_duration",
            "For how long:",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        ####### QUESTION 2 #######
        $this->addSelect(
            "day_care",
            "<b>2. Has she/he ever attended a <u>day care</u></b>",
            $yesNoOptions
        );
        $this->addSelect(
            "day_care_age",
            "If YES, age started attending:",
            $years_array
        );
        $this->XINRegisterRule(
            "day_care_age",
            array("day_care{@}=={@}yes"),
            "Required if she/he ever attended a day care."
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Years");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Months");
        $this->addGroup(
            $group,
            "q2_duration_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $group[] =& $this->createSelect(
            "day_care_years",
            "Years:",
            $years_array
        );
        $this->XINRegisterRule(
            "day_care_years",
            array("day_care{@}=={@}yes"),
            "Required if she/he ever attended a day care.",
            "q2_day_care_duration"
        );
        $group[] =& $this->createSelect(
            "day_care_months",
            "Months:",
            $months_array
        );
        $this->XINRegisterRule(
            "day_care_months",
            array("day_care{@}=={@}yes"),
            "Required if she/he ever attended a day care.",
            "q2_day_care_duration"
        );
        $this->addGroup(
            $group,
            "q2_day_care_duration",
            "For how long:",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $this->addSelect(
            "day_care_hours_per_week",
            "How many hours a week?",
            range(0, 40)
        );
        ######## QUESTION #3 ########
        $this->addSelect(
            "nursery_school_preschool",
            "<b>3. Did he/she ever attend <u>nursery school</u>?</b>",
            $yesNoOptions
        );
        $this->addSelect(
            "nursery_school_preschool_age",
            "If YES, age started attending:",
            range(0, 10)
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Years");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Months");
        $this->addGroup(
            $group,
            "q3_duration_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $group[] =& $this->createSelect(
            "nursery_school_preschool_years",
            "years",
            $years_array
        );
        $this->XINRegisterRule(
            "nursery_school_preschool_years",
            array("nursery_school_preschool{@}=={@}yes"),
            "Required if nursery school/preschool was attended.",
            "q3_preschool_duration"
        );
        $group[] =& $this->createSelect(
            "nursery_school_preschool_months",
            "months",
            $months_array
        );
        $this->XINRegisterRule(
            "nursery_school_preschool_months",
            array("nursery_school_preschool{@}=={@}yes"),
            "Required if nursery school/preschool was attended.",
            "q3_preschool_duration"
        );
        $this->addGroup(
            $group,
            "q3_preschool_duration",
            "For how long:",
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $this->addSelect(
            "nursery_school_hours_per_week",
            "How many hours a week?",
            range(0, 40)
        );
    }
    function _page2Headers($age_range) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Type of intervention");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Hours per week");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Mins");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Location (e.g. school, home)");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Description");
        $this->addGroup(
            $group,
            $age_range . "_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }
    function _page2Questions($age_range, $i, $type_of_intervention, $hours_array, $mins_array) {
        $group[] =& $this->createSelect(
            "{$age_range}_type_of_intervention_{$i}",
            "",
            $type_of_intervention
        );
        $group[] =& $this->createSelect(
            "{$age_range}_hours_{$i}",
            "",
            $hours_array
        );
        $group[] =& $this->createSelect(
            "{$age_range}_min_{$i}",
            "",
            $mins_array
        );
        $group[] =& $this->createText(
            "{$age_range}_location_{$i}",
            ""
        );
        $group[] =& $this->createText(
            "{$age_range}_description_{$i}",
            ""
        );
        if ($i == 1) {
            $this->XINRegisterRule(
                "{$age_range}_type_of_intervention_{$i}",
                array("support_in_school{@}=={@}yes|support_outside_school{@}=={@}yes"),
                "At least one intervention is required if the answer is yes to question 4 or 5.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_hours_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_min_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_location_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_description_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
        } else {
            $this->XINRegisterRule(
                "{$age_range}_type_of_intervention_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}=={@}NEVER_REQUIRED"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_hours_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}", "{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_min_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}", "{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_location_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}", "{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "Not required.",
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
            $this->XINRegisterRule(
                "{$age_range}_description_{$i}",
                array("{$age_range}_type_of_intervention_{$i}{@}!={@}", "{$age_range}_type_of_intervention_{$i}{@}!={@}13"),
                "All the fields in the row are required if a type of intervention is specified.",
                "{$age_range}_{$i}_headers"
            );
        }
        $this->addGroup(
            $group,
            "{$age_range}_{$i}_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }
    function _page2() {
        $yesNoOptions =
            array(
                null => "",
                "yes" => "Yes",
                "no" => "No"
            );
        ###### QUESTION 4 #######
        $this->addSelect(
            "support_in_school",
            "<b>4. Has he/she ever received any supports or special services <u>in school</u></b>?",
            $yesNoOptions
        );
        ###### QUESTION 5 ########
        $this->addSelect(
            "support_outside_school",
            "<b>5. Has your child ever received any supports or special services outside school,
             such as at home or in a clinic or other community setting?</b>",
            $yesNoOptions
        );
        $this->addHeader("<h4>If YES selected for either 4 or 5, go through each age interval
                         on this page to catalog services received, beginning with the interval 
                         child's current age. Use the following codes to categorize each service received.
                         If uncertain, code 12 for Other and briefly describe. If no services were received for a given
                         interval, pick N/A.</h4>");

        $this->addHeader("<h4>For the intervals below, please indicate which of the following services the child
                         has received:<br><br>
                         $this->indent 1. ABA/Lovaas/naturalistic behavioral (PRT, ESDM)<br>
                         $this->indent 2. Counseling/psychological<br>
                         $this->indent 3. Developmental (RDI, Floortime)<br>
                         $this->indent 4. Occupational therapy<br>
                         $this->indent 5. Physical therapy<br>
                         $this->indent 6. Recreational<br>
                         $this->indent 7. Sensory/sensory integration<br>
                         $this->indent 8. Social skills in training<br>
                         $this->indent 9. Speech language<br>
                         $this->indent 10. TEACCH<br>
                         $this->indent 11. Special education (for non-specific in-school services<br>
                         $this->indent 12. Other (biomedical/nutritional/alternative); If 'Other' specify<br><br><br>
                         
                         Please fill in as much detail as possible about the child’s intervention including the type of 
                         service/intervention (using codes above), estimate of hours/minutes per week, and where the service
                         was provided. If '12' is selected for 'Type of Intervention', please describe it
                         further in 'Description'</h4>");
        $type_of_intervention =
            array(
                null => "",
                1 => "1. ABA/Lovaas/naturalistic behavioral (PRT, ESDM)",
                2 => "2. Counseling/psychological",
                3 => "3. Developmental (RDI, Floortime)",
                4 => "4. Occupational therapy",
                5 => "5. Physical therapy",
                6 => "6. Recreational",
                7 => "7. Sensory/sensory integration",
                8 => "8. Social skills in training",
                9 => "9. Speech language",
                10 => "10. TEACCH",
                11 => "11. Special education (for non-specific in-school services",
                12 => "12. Other (biomedical/nutritional/alternative/)",
                13 => "13. N/A"
            );
        $hours_array = array(null => "");
        for ($i=0; $i <= 50; $i++) {
            array_push($hours_array, $i);
        }
        $mins_array = array(null => "");
        foreach (array(0, 15, 30, 45) as $min) {
            array_push($mins_array, $min);
        }
        ##### 6. Age 10-11 ######
        $this->addHeader("<h4>6. Age 10-11 (fifth grade):</h4>");
        $this->_page2Headers("age_10_11");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_10_11", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 7. Age 9-10 ######
        $this->addHeader("<h4>7. Age 9-10 (fourth grade):</h4>");
        $this->_page2Headers("age_9_10");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_9_10", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 8. Age 8-9 ######
        $this->addHeader("<h4>8. Age 8-9 (third grade):</h4>");
        $this->_page2Headers("age_8_9");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_8_9", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 9. Age 7-8 ######
        $this->addHeader("<h4>9. Age 7-8 (second grade):</h4>");
        $this->_page2Headers("age_7_8");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_7_8", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 10. Age 6-7 ######
        $this->addHeader("<h4>10. Age 6-7 (first grade):</h4>");
        $this->_page2Headers("age_6_7");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_6_7", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 11. Age 5-6 ######
        $this->addHeader("<h4>11. Age 5-6 (kindergarten):</h4>");
        $this->_page2Headers("age_5_6");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_5_6", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 12. Age 4-5 ######
        $this->addHeader("<h4>12. Age 4-5:</h4>");
        $this->_page2Headers("age_4_5");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_4_5", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 13. Age 3-4 ######
        $this->addHeader("<h4>13. Age 3-4:</h4>");
        $this->_page2Headers("age_3_4");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_3_4", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        ##### 14. Age 2-3 ######
        $this->addHeader("<h4>14. Age 2-3:</h4>");
        $this->_page2Headers("age_2_3");
        for ($i=1; $i <= 6; $i++) {
            $this->_page2Questions("age_2_3", $i, $type_of_intervention, $hours_array, $mins_array);
        }
        $this->addTextAreaElement(
            "q15_additional_info",
            "15. Is there any other information you would like to share with us about
                   your child?"
        );
    }
}