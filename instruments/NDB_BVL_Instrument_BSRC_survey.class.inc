<?php
/**
 * This file contains the NDB_BVL_Instrument_BSRC_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the BSRC Intervention History Form - Survey
 *
 * @category Instrument
 * @package  BSRC_survey
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BSRC_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    use instrument_validator;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    const YES_NO_OPTIONS = array(
        null => "",
        "yes" => "Yes",
        "no" => "No",
    );

    const INDIVIDUAL_GROUP_OPTIONS = array(
        null => "",
        "individual" => "Individual",
        "group" => "Group",
    );

    const SETTING_OPTIONS = array(
        null => "",
        "office_clinic" => "Office/clinic",
        "home" => "Home",
        "daycare_preschool" => "Daycare/preschool",
        "other" => "Other",
    );

    const SERVICE_TYPE_OPTIONS = array(
        'occupational_therapy' => 'Occupational Therapy',
        'physical_therapy' => 'Physical Therapy',
        'speech_language_therapy' => 'Speech-language therapy',
        'comprehensive_behavioral' => 'Comprehensive behavioral/educational interventions',
        'other' => 'Other',
    );

    const CHILD_ENROLLMENT_OPTIONS = array(
        null => "",
        'speech_language_therapy' => 'Speech-language therapy',
        'occupational_therapy' => 'Occupational therapy',
        'physical_therapy' => 'Physical therapy',
        'comprehensive_behavioral' => 'Comprehensive behavioral intervention/special educational services',
        'other' => 'Other',
    );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('BSRC_survey', "BSRC Intervention History Form - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('BSRC_survey', 'BSRC_survey_page1', "Page 1", 1);
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V6');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V6-CVD');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V12');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V12-CVD');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V24');
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V24-CVD');
     *
     */

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('BSRC_survey');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "BSRC_survey";           // test_names.Test_name
        $this->table = 'BSRC_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array(
            "if_checked_9_please_check"
        );

        // required fields for data entry completion status
        $this->_requiredElements = array(
            "did_professional_refer_early_intervention"
        );

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
        if (preg_match("/BSRC_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("BSRC Intervention History Form - Survey");

        $config =& NDB_Config::singleton();
        $dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null,
        );

        $this->form->addElement('static', null, null);

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->addBasicDate('child_birth_date', 'CHILD\'S BIRTH DATE', $dateOptions);

        $this->addBasicDate('today_date', 'TODAY\'S DATE', $dateOptions);

        $this->addBasicDate('date_last_visit', 'DATE OF LAST VISIT', $dateOptions);
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("BSRC Intervention History Form - Survey");

        $this->form->addElement('static', null, '<h4><b>This form should be filled out by the child’s primary caretaker</b></h4>');

        $early_intervention_services = array(
            "average_hours_per_week" => "Average hours per week",
            "total_hours_since_last_visit" => "Total hours since last visit",
        );

        $hours_intervention_services = array(
            "since_yours_last_visit" => "a. since your last visit to our research program?",
            "in_past_year" => "b. in the past year?",
        );

        $page1_questions = array(
            "did_professional_refer_early_intervention" => "1) Since your last visit, did <u>a professional refer</u> your child to an <u>“early intervention” or “birth-to-three” program?</u> (Depending on where you live, these programs may have different names.)",
            "did_child_receive_early_intervention" => "2) Since your last visit, did your child <u>receive</u> any <u>“early intervention” or “birth-to-three” program</u> services?",
            "did_professional_recommend_child_socialization" => "3) Since your last visit, did <u>a professional recommend</u> that your child attend any community based <u>classes/activities designed to increase socialization</u> (eg. MommyandMe, Gymboree, etc.)",
            "did_child_participate_socialization" => "4) Since your last visit, did your child <u>participate</u> in any classes/activities designed to increase socialization whether or not recommended by a professional (eg. MommyandMe, Gymboree, etc.).",
            "did_child_receive_developmental_delays" => "5) Since your last visit, did your child receive services for developmental delays of any kind (such as motor or language delays) or concerns about delay?",
            "how_many_hours_child_intervention" => "6) On average, how many hours per week has your child been in intervention",
            "did_child_receive_complementary_therapies_autism" => "7) At any point since your last visit, did your child <u>receive complementary or alternative therapies used to treat symptoms of autism?</u>",
            "did_child_receive_medical_therapies_autism" => "8) At any point since your last visit, did your child <u>receive medical or pharmacological interventions used to treat symptoms of autism?</u>",
            "do_you_continue_enrollment_intervention" => "9) If this is your child’s 36-month assessment, do you plan to continue your child’s enrollment in intervention during the next year?",
            "if_checked_9_please_check" => "10) If you checked yes in #9, please check all that apply below:",
        );

        foreach ($page1_questions as $name => $label) {
            if ($name != "how_many_hours_child_intervention") {
                if ($name != "if_checked_9_please_check") {
                    $this->addSelect($name, $label, self::YES_NO_OPTIONS);
                }
            }

            if ($name != "if_checked_9_please_check") {
                if ($name != "how_many_hours_child_intervention") {
                    $this->addSelect($name, $label, self::YES_NO_OPTIONS);
                }
            }

            if ($name == "did_child_receive_early_intervention") {
                foreach ($early_intervention_services as $q2Key => $q2Question) {
                    $this->form->addElement('text', $q2Key, $q2Question, ['disabled' => 'disabled']);
                    $this->XINRegisterRule("$q2Key", array("did_child_receive_early_intervention{@}=={@}yes"), 'Required if yes');
                }
            } elseif ($name == "did_child_receive_developmental_delays") {
                $group = array();
                $group[] = $this->form->createElement("static", null, null, "Service Type");
                $group[] = $this->form->createElement("static", null, null, "Date Started");
                $group[] = $this->form->createElement("static", null, null, "Still receiving intervention?");
                $group[] = $this->form->createElement("static", null, null, "Individual or Group");
                $group[] = $this->form->createElement("static", null, null, "Setting");
                $group[] = $this->form->createElement("static", null, null, "Average hours per week");
                $this->addGroup($group, "q5_headers", null, $this->_GUIDelimiter, false);
                unset($group);

                foreach (self::SERVICE_TYPE_OPTIONS as $q5Key => $q5Question) {
                    $group[] = $this->createSelect($q5Key, $q5Question, self::YES_NO_OPTIONS);
                    $group[] = $this->createDate("date_{$q5Key}", "Date Started");
                    $group[] = $this->createSelect("still_receiving_intervention_{$q5Key}", "Still receiving intervention?", self::YES_NO_OPTIONS);
                    $group[] = $this->createDate("stopped_date_{$q5Key}", "If, NO, date stopped:");
                    $group[] = $this->createSelect("individual_group_{$q5Key}", "Individual or Group", self::INDIVIDUAL_GROUP_OPTIONS);
                    $group[] = $this->createSelect("setting_{$q5Key}", "Setting", self::SETTING_OPTIONS);
                    $group[] = $this->createText("other_setting_{$q5Key}", "Other:");
                    $group[] = $this->createText("average_hours_{$q5Key}", "Average hours per week");
                    $this->XINRegisterRule("stopped_date_{$q5Key}", array("still_receiving_intervention_{$q5Key}{@}=={@}no"), $this->indent . "Required if no.", "q5_" . $q5Key . "_group");
                    $this->XINRegisterRule("other_setting_{$q5Key}", array("setting_{$q5Key}{@}=={@}other"), $this->indent . "Required if other.", "q5_" . $q5Key . "_group");
                    $this->addGroup($group, "group_{$q5Key}", $q5Question, $this->_GUIDelimiter, false);
                    unset($group);
                }

            } elseif ($name == "how_many_hours_child_intervention") {
                $this->addLabel($label);
                foreach ($hours_intervention_services as $q6Key => $q6Question) {
                    $this->form->addElement('text', $q6Key, $q6Question);
                }
            } elseif ($name == "did_child_receive_complementary_therapies_autism") {
                $this->form->addElement('text', "q7_specify", "if YES, please specify", ['disabled' => 'disabled']);
                $this->XINRegisterRule("q7_specify", array("did_child_receive_complementary_therapies_autism{@}=={@}yes"), 'Required if yes');
            } elseif ($name == "did_child_receive_medical_therapies_autism") {
                $this->form->addElement('text', "q8_specify", "if YES, please specify", ['disabled' => 'disabled']);
                $this->XINRegisterRule("q8_specify", array("did_child_receive_medical_therapies_autism{@}=={@}yes"), 'Required if yes');
            } elseif ($name == "if_checked_9_please_check") {
                $this->addSelect($name, $label, self::CHILD_ENROLLMENT_OPTIONS, ["multiple"]);
            }
        }

        $this->form->addElement('static', null, null);

        // ADDITIONAL INFORMATION
        $this->addTextAreaElement("additional_info_about_services", "IF THERE IS ANYTHING ELSE YOU WOULD LIKE TO TELL US ABOUT SERVICES YOUR CHILD HAS RECEIVED:");

        $this->addLabel("THANK YOU!");

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    function validate_page1($values)
    {
        $errors = [];

        if ($values["did_child_receive_early_intervention"] != "yes") {
            $this->validate_empty_subquestions($values, ["average_hours_per_week"], $errors);
            $this->validate_empty_subquestions($values, ["total_hours_since_last_visit"], $errors);
        } else {
            $this->validate_positive_numeric($values, ["average_hours_per_week"], $errors);
            $this->validate_positive_numeric($values, ["total_hours_since_last_visit"], $errors);
        }

        $this->validate_positive_numeric($values, ["since_yours_last_visit"], $errors);
        $this->validate_positive_numeric($values, ["in_past_year"], $errors);

        if ($values["did_child_receive_complementary_therapies_autism"] != "yes") {
            $this->validate_empty_subquestions($values, ["q7_specify"], $errors);
        }

        if ($values["did_child_receive_medical_therapies_autism"] != "yes") {
            $this->validate_empty_subquestions($values, ["q8_specify"], $errors);
        }

        return $errors;
    }

    function validate_positive_numeric($values, $question, &$errors)
    {
        if (isset($values[$question])) {
            $user_input = $values[$question];
            if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                $errors[$question] = "Specify a positive number";
            }
        }
    }
}

?>
