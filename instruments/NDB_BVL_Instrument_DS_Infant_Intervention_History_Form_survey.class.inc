<?php
/**
 * This file contains the NDB_BVL_Instrument_DS_Infant_Intervention_History_Form_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the DS_Infant_Intervention_History_Form_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_DS_Infant_Intervention_History_Form_survey extends NDB_BVL_Instrument
{
    use instrument_validator;

    const YES_NO_OPTIONS = array(
                            null  => "",
                            "yes" => "Yes",
                            "no"  => "No",
                           );

    const WHERE_OPTIONS = array(
                           null                      => "",
                           "providers_office_clinic" => "Provider’s office/clinic",
                           "home"                    => "Home",
                           "daycare_preschool"       => "Daycare/preschool",
                           "other"                   => "Other:",
                          );

    const MINUTES_OPTIONS_1 = array(
                               null                      => "",
                               "0_to_30_minutes"         => "0 – 30 min",
                               "30_to_60_minutes"        => "30 – 60 min",
                               "60_to_90_minutes"        => "60 – 90 min",
                               "greater_than_90_minutes" => "> 90 min",
                              );

    const MINUTES_OPTIONS_2 = array(
                               null                       => "",
                               "0_to_30_minutes"          => "0 – 30 min",
                               "30_to_60_minutes"         => "30 – 60 min",
                               "60_to_90_minutes"         => "60 – 90 min",
                               "90_to_120_minutes"        => "90 – 120 min",
                               "120_to_150_minutes"       => "120 – 150 min",
                               "greater_than_150_minutes" => "> 150 min",
                              );

    const MINUTES_OPTIONS_3 = array(
                               null                       => "",
                               "0_to_30_minutes"          => "0 – 30 min",
                               "30_to_60_minutes"         => "30 – 60 min",
                               "60_to_90_minutes"         => "60 – 90 min",
                               "90_to_120_minutes"        => "90 – 120 min",
                               "120_to_150_minutes"       => "120 – 150 min",
                               "150_to_180_minutes"       => "150 – 180 min",
                               "greater_than_180_minutes" => "> 180 min",
                              );

    const SERVICE_OPTIONS = array(
                             "occupational_therapy"                   => "Occupational Therapy",
                             "physical_therapy"                       => "Physical Therapy",
                             "speech_language_therapy"                => "Speech-language Therapy",
                             "developmental_therapy_special_educator" => "Developmental Therapy/Special Educator",
                             "behavioral_educational_interventions"   => "Comprehensive behavioral/educational interventions",
                             "skilled_nursing"                        => "Skilled Nursing",
                             "other"                                  => "Other Service",
                            );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('DS_Infant_Intervention_History_Form_survey', "Intervention History Form – Infant DS - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page5', "Page 5", 5);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page6', "Page 6", 6);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page7', "Page 7", 7);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page8', "Page 8", 8);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page9', "Page 9", 9);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('DS_Infant_Intervention_History_Form_survey','DS_Infant_Intervention_History_Form_survey_page10', "Page 10", 10);
     */

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('DS_Infant_Intervention_History_Form_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "DS_Infant_Intervention_History_Form_survey";           // test_names.Test_name
        $this->table    = 'DS_Infant_Intervention_History_Form_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array("q1_a_what_was_the_outcome_of_pregnancy_1");

        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/DS_Infant_Intervention_History_Form_survey(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
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
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
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
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            This form should be filled out by the child’s primary caretaker."
        );

        $this->form->addElement(
            'static',
            null,
            "<h3>Between <b><u>birth and 1 month</u></b> of age, did your child receive?</h3>"
        );

        $this->create_table("1", "birth and 1 month");

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->addSelect("page2_same_as_previous", "Same as previous month? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

        $this->form->addElement(
            'static',
            null,
            "<h3>Between <b><u>1 month and 2 months</u></b> of age, did your child receive?</h3>"
        );

        $this->create_table("2", "1 month and 2 months");

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->addSelect("page3_same_as_previous", "Same as previous month? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

        $this->form->addElement(
            'static',
            null,
            "<h3>Between <b><u>2 months and 3 months</u></b> of age, did your child receive?</h3>"
        );

        $this->create_table("3", "2 months and 3 months");

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->addSelect("page4_same_as_previous", "Same as previous month? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

        $this->form->addElement(
            'static',
            null,
            "<h3>Between <b><u>3 months and 4 months</u></b> of age, did your child receive?</h3>"
        );

        $this->create_table("4", "3 months and 4 months");

        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->addSelect("page5_same_as_previous", "Same as previous month? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

        $this->form->addElement(
            'static',
            null,
            "<h3>Between <b><u>4 months and 5 months</u></b> of age, did your child receive?</h3>"
        );

        $this->create_table("5", "4 months and 5 months");

        $this->form->addFormRule(array(&$this, 'validate_page5'));
    }

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    function _page6()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        $this->addSelect("page6_same_as_previous", "Same as previous month? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

        $this->form->addElement(
            'static',
            null,
            "<h3>Between <b><u>5 months and 6 months</u></b> of age, did your child receive?</h3>"
        );

        $this->create_table("6", "5 months and 6 months");

        if ($this->getTimepoint() == "V06" || $this->getTimepoint() == "V6-CVD") {
            $this->addBasicDate('Date_completed_6_months', 'STOP HERE for 6 month visit. DATE COMPLETED:', $this->dateOptions);
        }

        $this->form->addFormRule(array(&$this, 'validate_page6'));
    }

    /**
    * Generates the seventh page of the form.
    *
    * @return void
    */
    function _page7()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        if ($this->getTimepoint() != "V06" && $this->getTimepoint() != "V6-CVD") {
            $this->addSelect("page7_same_as_previous", "Same as previous month? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

            $this->form->addElement(
                'static',
                null,
                "<h3>Between <b><u>6 months and 9 months</u></b> of age, did your child receive?</h3>"
            );

            $this->create_table("7", "6 months and 9 months");

            $this->form->addFormRule(array(&$this, 'validate_page7'));
        } else {
            $this->form->addElement(
                'static',
                null,
                "<h3>Skip to end of survey</h3>"
            );
        }
    }

    /**
    * Generates the eighth page of the form.
    *
    * @return void
    */
    function _page8()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        if ($this->getTimepoint() != "V06" && $this->getTimepoint() != "V6-CVD") {
            $this->addSelect("page8_same_as_previous", "Same as 6-9 months? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

            $this->form->addElement(
                'static',
                null,
                "<h3>Between <b><u>9 months and 12 months</u></b> of age, did your child receive?</h3>"
            );

            $this->create_table("8", "9 months and 12 months");

            if ($this->getTimepoint() == "V12" || $this->getTimepoint() == "V12-CVD") {
                $this->addBasicDate('Date_completed_12_months', 'STOP HERE for 12 month visit. DATE COMPLETED:', $this->dateOptions);
            }

            $this->form->addFormRule(array(&$this, 'validate_page8'));
        } else {
            $this->form->addElement(
                'static',
                null,
                "<h3>Skip to end of survey</h3>"
            );
        }
    }

    /**
    * Generates the ninth page of the form.
    *
    * @return void
    */
    function _page9()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        if ($this->getTimepoint() == "V24" || $this->getTimepoint() == "V24-CVD") {
            $this->addSelect("page9_same_as_previous", "Same as 9-12 months? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

            $this->form->addElement(
                'static',
                null,
                "<h3>Between <b><u>12 months and 18 months</u></b> of age, did your child receive?</h3>"
            );

            $this->create_table("9", "12 months and 18 months");

            $this->form->addFormRule(array(&$this, 'validate_page9'));
        } else {
            $this->form->addElement(
                'static',
                null,
                "<h3>Skip to end of survey</h3>"
            );
        }
    }

    /**
    * Generates the tenth page of the form.
    *
    * @return void
    */
    function _page10()
    {
        $this->addHeader("Intervention History Form – Infant DS - Survey");

        if ($this->getTimepoint() == "V24" || $this->getTimepoint() == "V24-CVD") {
            $this->addSelect("page10_same_as_previous", "Same as 12-18 months? <h4><i>If yes, skip to next page</i></h4>", self::YES_NO_OPTIONS);

            $this->form->addElement(
                'static',
                null,
                "<h3>Between <b><u>18 months and 24 months</u></b> of age, did your child receive?</h3>"
            );

            $this->create_table("10", "18 months and 24 months");

            $this->addBasicDate('Date_completed_24_months', 'STOP HERE for 24 month visit. DATE COMPLETED:', $this->dateOptions);

            $this->form->addFormRule(array(&$this, 'validate_page10'));
        } else {
            $this->form->addElement(
                'static',
                null,
                "<h3>Skip to end of survey</h3>"
            );
        }
    }

    function create_table($page_number, $age_range)
    {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Service"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Yes/No"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "If Yes, where did your child receive most services?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "If Other, specify:"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "How many minutes of services per week?"
        );
        $this->addGroup(
            $group,
            "page" . $page_number . "_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach (self::SERVICE_OPTIONS as $key => $value) {

            $group[] = $this->createLabel($value);

            $group[] =& $this->createSelect(
                "page{$page_number}_{$key}_yes_no",
                "Between <b>" . $age_range . "</b>, did your child receive: <b>" . $value . "</b>?",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                "page{$page_number}_{$key}_if_yes_where",
                "If Yes, where did your child receive most services?",
                self::WHERE_OPTIONS
            );
            $group[] =& $this->createText(
                "page{$page_number}_{$key}_if_yes_where_other",
                "If Other, specify:",
                "If Other, specify:"
            );

            if ($page_number == "9" || $page_number == "10") {
                $group[] =& $this->createSelect(
                    "page{$page_number}_{$key}_minutes_per_week",
                    "How many minutes of services per week?",
                    self::MINUTES_OPTIONS_3
                );
            } elseif ($page_number == "7" || $page_number == "8") {
                $group[] =& $this->createSelect(
                    "page{$page_number}_{$key}_minutes_per_week",
                    "How many minutes of services per week?",
                    self::MINUTES_OPTIONS_2
                );
            } else {
                $group[] =& $this->createSelect(
                    "page{$page_number}_{$key}_minutes_per_week",
                    "How many minutes of services per week?",
                    self::MINUTES_OPTIONS_1
                );
            }

            // Questions are only required if "Same as previous month" is answered "no"
            if ($page_number >= "2") {
                $this->XINRegisterRule(
                    "page{$page_number}_{$key}_yes_no",
                    array("page{$page_number}_same_as_previous{@}!={@}yes"),
                    "Required.",
                    "page" . $page_number . "_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    "page{$page_number}_{$key}_if_yes_where",
                    array("page{$page_number}_same_as_previous{@}!={@}yes"),
                    "Required.",
                    "page" . $page_number . "_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    "page{$page_number}_{$key}_if_yes_where_other",
                    array("page{$page_number}_same_as_previous{@}!={@}yes"),
                    "Required.",
                    "page" . $page_number . "_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    "page{$page_number}_{$key}_minutes_per_week",
                    array("page{$page_number}_same_as_previous{@}!={@}yes"),
                    "Required.",
                    "page" . $page_number . "_" . $key . "_group"
                );
            }

            $this->XINRegisterRule(
                "page{$page_number}_{$key}_if_yes_where",
                array("page{$page_number}_{$key}_yes_no{@}=={@}yes"),
                "Required if yes",
                "page" . $page_number . "_" . $key . "_group"
            );

            $this->XINRegisterRule(
                "page{$page_number}_{$key}_if_yes_where_other",
                array("page{$page_number}_{$key}_if_yes_where{@}=={@}other"),
                "Required if other, specify",
                "page" . $page_number . "_" . $key . "_group"
            );

            $this->XINRegisterRule(
                "page{$page_number}_{$key}_minutes_per_week",
                array("page{$page_number}_{$key}_yes_no{@}=={@}yes"),
                "Minutes per Week Required",
                "page" . $page_number . "_" . $key . "_group"
            );

            $this->addGroup(
                $group,
                "page" . $page_number . "_" . $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement('text', "page" . $page_number . "_other_service_specify", 'Other Service, specify:');
        $this->XINRegisterRule("page" . $page_number . "_other_service_specify", array("page{$page_number}_other_yes_no{@}=={@}yes"), 'Required if other');
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

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page1_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page1_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page1_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page1_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page1_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page1_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page1_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page1_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        if ($values["page2_same_as_previous"] != "no") {
            // validate empty subquestion
            foreach (self::SERVICE_OPTIONS as $key => $value) {
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_yes_no"], $errors);
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_minutes_per_week"], $errors);
            }
            $this->validate_empty_subquestions($values, ["page2_other_service_specify"], $errors);
        }

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page2_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page2_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page2_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page2_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page2_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page3_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page3_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page3_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page3_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page3_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page3_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page3_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page3_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page4_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page4_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page4_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page4_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page4_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page4_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page4_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page4_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page5($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page5_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page5_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page5_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page5_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page5_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page5_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page5_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page5_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page6($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page6_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page6_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page6_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page6_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page6_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page6_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page6_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page6_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page7($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page7_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page7_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page7_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page7_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page7_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page7_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page7_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page7_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page8($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page8_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page8_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page8_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page8_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page8_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page8_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page8_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page8_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page9($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page9_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page9_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page9_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page9_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page9_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page9_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page9_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page9_other_service_specify"], $errors);
        }

        return $errors;
    }

    function validate_page10($values)
    {
        $errors = [];

        foreach (self::SERVICE_OPTIONS as $key => $value) {
            if ($values["page10_" . $key . "_yes_no"] != "yes") {
                $this->validate_empty_subquestions($values, ["page10_" . $key . "_if_yes_where"], $errors);
                $this->validate_empty_subquestions($values, ["page10_" . $key . "_if_yes_where_other"], $errors);
                $this->validate_empty_subquestions($values, ["page10_" . $key . "_minutes_per_week"], $errors);
            }

            if ($values["page10_" . $key . "_if_yes_where"] != "other") {
                $this->validate_empty_subquestions($values, ["page10_" . $key . "_if_yes_where_other"], $errors);
            }
        }

        if ($values["page10_other_yes_no"] != "yes") {
            $this->validate_empty_subquestions($values, ["page10_other_service_specify"], $errors);
        }

        return $errors;
    }

    function getTimepoint()
    {
        $db     =& Database::singleton();
        $query  = "SELECT Visit_label FROM session WHERE ID IN (SELECT SessionID FROM flag WHERE CommentID = '$this->commentID')";
        $record = $db->pselectRow($query, array());

        return $record["Visit_label"];
    }
}
?>