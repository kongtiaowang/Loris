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
     * INSERT INTO survey_test_battery (Test_name, Visit_label) VALUES ('BSRC_survey', 'V06');
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
        $this->dateTimeFields = array(
            "Date_taken",
            "child_birth_date",
            "today_date",
            "date_last_visit",
            "occupational_therapy_date",
            "occupational_therapy_stopped_date",
            "physical_therapy_date",
            "physical_therapy_stopped_date",
            "speech_language_therapy_date",
            "speech_language_therapy_stopped_date",
            "comprehensive_behavioral_date",
            "comprehensive_behavioral_stopped_date",
            "other_date",
            "other_stopped_date",
            );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array(
            "occupational_therapy_individual_group",
            "physical_therapy_individual_group",
            "speech_language_therapy_individual_group",
            "comprehensive_behavioral_individual_group",
            "other_individual_group",
            "if_checked_9_please_check"
        );

        // required fields for data entry completion status
        $this->_requiredElements = array(
            "CommentID",
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
                    $this->addNumericElement($q2Key, $q2Question);
                    $this->XINRegisterRule("$q2Key", array("did_child_receive_early_intervention{@}=={@}NEVER_REQUIRED"));
                }
            } elseif ($name == "did_child_receive_developmental_delays") {
                $this->addLabel("<BR> If YES to #5, please complete the following:");

                foreach (self::SERVICE_TYPE_OPTIONS as $q5Key => $q5Question) {
                    $this->addHeader($q5Question);
                    $this->addOptionalSelect("{$q5Key}_received", "Received {$q5Question}", self::YES_NO_OPTIONS,
                        "did_child_receive_developmental_delays", "yes", "Required if your child receive services for developmental delays.");
                    $this->addOptionalDate("{$q5Key}_date", "Date Started",
                        "{$q5Key}_received", "yes", "Required if you received {$q5Question}.");
                    $this->addOptionalSelect("{$q5Key}_intervention", "Still receiving intervention?", self::YES_NO_OPTIONS,
                        "{$q5Key}_intervention", "NEVER_REQUIRED");
                    $this->addOptionalDate("{$q5Key}_stopped_date", "If, NO, date stopped:",
                        "{$q5Key}_intervention", "no", "Required if you have stopped receiving intervention.");
                    $this->addSelect("{$q5Key}_individual_group", "Individual or Group", self::INDIVIDUAL_GROUP_OPTIONS, array("multiple"));
                    $this->XINRegisterRule("{$q5Key}_individual_group", array("{$q5Key}_received{@}=={@}yes"), "Required");
                    $this->addOptionalSelect("{$q5Key}_setting", "Setting", self::SETTING_OPTIONS,
                        "{$q5Key}_received", "yes", "Required if you received {$q5Question}.");
                    $this->addOptionalText("{$q5Key}_other_setting", "Other:",
                        "{$q5Key}_setting", "other", "Required if other.");
                    $this->addOptionalText("{$q5Key}_average_hours", "Average hours per week",
                        "{$q5Key}_average_hours", "NEVER_REQUIRED");
                }

            } elseif ($name == "how_many_hours_child_intervention") {
                $this->addLabel($label);
                foreach ($hours_intervention_services as $q6Key => $q6Question) {
                    $this->addNumericElement($q6Key, $q6Question);
                }
            } elseif ($name == "did_child_receive_complementary_therapies_autism") {
                $this->addTextAreaElement("q7_specify", "If YES, please specify", array("did_child_receive_complementary_therapies_autism{@}=={@}yes"), "If Yes, please specify:");
            } elseif ($name == "did_child_receive_medical_therapies_autism") {
                $this->addTextAreaElement("q8_specify", "if YES, please specify", array("did_child_receive_medical_therapies_autism{@}=={@}yes"), "If Yes, please specify:");
            } elseif ($name == "if_checked_9_please_check") {
                $this->addSelect($name, $label, self::CHILD_ENROLLMENT_OPTIONS, array("multiple"));
                $this->XINRegisterRule($name, array("do_you_continue_enrollment_intervention{@}=={@}yes"), "Required");
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
        $errors = array();

        $datetaken = $values['Date_taken'];
        $datelastvisit = $values['date_last_visit'];

        $list_of_fields = array('average_hours_per_week', 'since_yours_last_visit',
            'in_past_year', 'occupational_therapy_average_hours', 'physical_therapy_average_hours',
            'speech_language_therapy_average_hours', 'comprehensive_behavioral_average_hours', 'other_average_hours');
        foreach ($list_of_fields as $field) {
            if ($values[$field] < 0 || $values[$field] > 168) {
                $error = $field . "_group";
                $errors[$error] = 'Please enter a value between 0 and 168';

            }
        }
        if ($values['do_you_continue_enrollment_intervention'] == 'yes' &&
            ($values['if_checked_9_please_check'] == "" || $values['if_checked_9_please_check'] == null)) {

            $errors['if_checked_9_please_check'] = 'Required if #9 is checked as Yes';
        }

        if ($datelastvisit > $datetaken) {

            $errors['date_lastVisit_date_group'] = 'Date last visit should be before Date Taken';
        }

        if ($values['occupational_therapy_received'] == 'yes'
            && ($values['occupational_therapy_average_hours'] == null || $values['occupational_therapy_average_hours'] == "")
            && ($values['occupational_therapy_average_hours_status'] == null
                || $values['occupational_therapy_average_hours_status'] == "")) {

            $errors['occupational_therapy_average_hours_group'] = 'Required';
        }
        if ($values['physical_therapy_received'] == 'yes'
            && ($values['physical_therapy_average_hours'] == null || $values['physical_therapy_average_hours'] == "")
            && ($values['physical_therapy_average_hours_status'] == null
                || $values['physical_therapy_average_hours_status'] == "")) {

            $errors['physical_therapy_average_hours_group'] = 'Required';
        }

        if ($values['speech_language_therapy_received'] == 'yes'
            && ($values['speech_language_therapy_average_hours'] == null || $values['speech_language_therapy_average_hours'] == "")
            && ($values['speech_language_therapy_average_hours_status'] == null
                || $values['speech_language_therapy_average_hours_status'] == "")) {

            $errors['speech_language_therapy_average_hours_group'] = 'Required';
        }
        if ($values['comprehensive_behavioral_received'] == 'yes'
            && ($values['comprehensive_behavioral_average_hours'] == null || $values['comprehensive_behavioral_average_hours'] == "")
            && ($values['comprehensive_behavioral_average_hours_status'] == null
                || $values['comprehensive_behavioral_average_hours_status'] == "")) {

            $errors['comprehensive_behavioral_average_hours_group'] = 'Required';
        }
        if ($values['other_received'] == 'yes'
            && ($values['other_average_hours'] == null || $values['other_average_hours'] == "")
            && ($values['other_average_hours_status'] == null || $values['other_average_hours_status'] == "")) {

            $errors['other_average_hours_group'] = 'Required';
        }
        if ($values['did_child_receive_early_intervention'] == 'yes'
            && ($values['average_hours_per_week'] == null
                || $values['average_hours_per_week'] == "")
            && ($values['average_hours_per_week_status'] == null
                || $values['average_hours_per_week_status'] == "")) {

            $errors['average_hours_per_week_group'] = 'Required';
        }

        if ($values['did_child_receive_early_intervention'] == 'yes'
            && ($values['total_hours_since_last_visit'] == null
                || $values['total_hours_since_last_visit'] == "")
            && ($values['total_hours_since_last_visit_status'] == null
                || $values['total_hours_since_last_visit_status'] == "")) {

            $errors['total_hours_since_last_visit_group'] = 'Required';
        }

        $servicelist = array('occupational_therapy', 'physical_therapy',
            'speech_language_therapy', 'comprehensive_behavioral', 'other');

        foreach ($servicelist as $list) {
            $service = $list . '_received';
            if ($values['did_child_receive_developmental_delays'] == 'yes'
                && ($values[$service] == null || $values[$service] == "")) {

                $errors[$service] = "Required";
            }
            $continue = $list.'_intervention';
            if ($values['did_child_receive_developmental_delays'] == 'yes' && $values[$service] == 'yes'
                && ($values[$continue] == null || $values[$continue] == "")) {

                $errors[$continue] = "Required";
            }
            if ($values['did_child_receive_developmental_delays'] == 'yes' && $values[$service] == 'yes'
                && $values[$continue] == "yes" && $values[$list . '_stopped_date'] != null) {
                $errors[$list . '_stopped_date'] = "You must leave this field since you entered yes above.";
            }
//            $start = $values[$list . '_date'];
//            $stop = $values[$list . '_stopped_date'];
//            if (!empty($start && $stop)) {
//                if ($start >= $stop) {
//                    $errors[$list . '_stopped_date'] = "Intervention stop date should be after intervention start date";
//                }
//            }

        }

        return $errors;
    }

    function addOptionalSelect(string $name, string $label, array $options, $dependencyName, $dependencyValue, $message = null)
    {
        if ($message == null) {
            $this->addSelect($name, $label, $options);
            $this->XINRegisterRule($name, array("{$dependencyName}{@}=={@}{$dependencyValue}"));
        } else {
            $this->addSelect($name, $label, $options);
            $this->XINRegisterRule($name, array("{$dependencyName}{@}=={@}{$dependencyValue}"), $message);
        }
    }

    function addOptionalDate(string $name, string $label, $dependencyName, $dependencyValue, $message)
    {
        $this->addMonthYear($name, $label);
        $this->XINRegisterRule($name, array("{$dependencyName}{@}=={@}{$dependencyValue}"), $message);
    }

    function addOptionalText(string $name, string $label, $dependencyName, $dependencyValue, $message = null)
    {
        if ($message == null) {
            $this->addTextElement($name, $label);
            $this->XINRegisterRule($name, array("{$dependencyName}{@}=={@}{$dependencyValue}"));
        } else {
            $this->addTextElement($name, $label);
            $this->XINRegisterRule($name, array("{$dependencyName}{@}=={@}{$dependencyValue}"), $message);
        }
    }
}

?>
