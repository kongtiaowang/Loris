<?php
/**
 * This file contains the NDB_BVL_Instrument_TSI_SA class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the Telephone Screening Interview
 * - School Age instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_TSI_SA extends NDB_BVL_Instrument
{
    use instrument_validator;
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;
    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('TSI_SA');
        $this->page     = $page;            // page label (number or
        // string - used by user-defined child classes)
        // set the object properties
        $this->testName = "TSI_SA";           // test_names.Test_name
        $this->table    = 'TSI_SA';             // name of table containing
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields    =array("Date_taken");
        $this->_requiredElements = array(
            'CommentID',
            'Date_taken',
            'Examiner',
        );
        $config            = NDB_Config::singleton();
        $this->dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
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
    function _setupForm()
    {
        if(preg_match("/TSI_SA(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->form->addElement(
            'header',
            'instrument_title',
            "Telephone Screening Interview - School Age"
        );
        $this->form->addElement('static', null, '<BR>');
        // automatically adds examiner & date of administraton
        $this->_addMetadataFields();
        $this->form->addElement('static', null, '<BR>');
    }
    /**
     * Generates page 1 of the form
     */
    function _page1()
    {
        $this->form->addElement('header', null, "Identifying Information");
        $this->form->addElement('header', null, "<h4>This type of identifying information should not be entered in the database.</h4>");
        $non_asked_subject_questions = array(
            "Subject's Name:",
            "Subject ID:",
            "Date of Contact:",
            "Date of Birth:",
            "Examiner:",
            "Subject's Sex: $this->indent Subject's Age (in yr/mo):",
        );
        foreach ($non_asked_subject_questions as $field) {
            if($field == "Date of Contact:") {
                $this->addDateElement("contact", $field);
            }
            else {
                $this->form->addElement('static', null, $field);
            }
        }
        $yes_no = array(
            null           => "",
            "yes"          => "Yes",
            "no"           => "No",
            "not_answered" => "Not Answered",
        );
        $education_choices = array(
            null                      => "",
            "not_answered"            => "Not Answered",
            "some_hs"                 => "Some High School",
            "hs"                      => "High School",
            "some_college_2yr_degree" => "Some College/2yr. Degree",
            "college_degree"          => "College Degree",
            "some_grad_school"        => "Some Graduate School",
            "grad_degree"             => "Graduate Degree",
        );
        $ses_income = array(
            null            => "",
            "less_than_25K" => "less than $24,999",
            "25K-35K"       => "$25,000 - 34,999",
            "35K-50K"       => "$35,000 - 49,999",
            "50K-75K"       => "$50,000 - 74,999",
            "75K-100K"      => "$75,000 - 99,999",
            "100K-150K"     => "$100,000 - 149,999",
            "150K-200K"     => "$150,000 - 199,000",
            "over_200K"     => "over $200,000",
            "not_answered"  => "Not Answered",
        );
        $this->form->addElement('header', null, "Parent's Information:");
        $this->form->addElement("select", "same_home", "Parents living in the same home?", $yes_no);
        $this->form->addElement("select", "divorced_or_separated", "Parents divorced or separated?", $yes_no);
        $this->form->addElement('header', null, "MOTHER:");
        $this->form->addElement('static', null, "Name:");
        $this->form->addElement('static', null, "DOB:");
        $this->form->addElement('static', null, "Occupation:");
        $this->form->addElement("select", "mother_education", "Education:", $education_choices);
        $this->form->addElement('header', null, "FATHER:");
        $this->form->addElement('static', null, "Name:");
        $this->form->addElement('static', null, "DOB:");
        $this->form->addElement('static', null, "Occupation:");
        $this->form->addElement("select", "father_education", "Education:", $education_choices);
        $this->form->addElement('static', null, "<BR><BR>");
        $this->form->addElement("select", "household_ses_1", "Household SES 1 (or combined):", $ses_income);
        $this->form->addElement("select", "household_ses_2", "Household SES 2 (if 2 households):", $ses_income);
        $this->XINRegisterRule("household_ses_2", array("same_home{@}=={@}no"), "Required if parents not cohabitating.");
        $this->form->addElement('header', null, "Parent's Telephone:");
        $this->form->addElement('static', null, "Home:");
        $this->form->addElement('static', null, "Work: $this->indent days/hrs");
        $this->form->addElement('static', null, "OK to leave msg?");
        $this->form->addElement('static', null, "Cell: $this->indent (Mom) $this->indent (Dad)");
        $this->form->addElement('static', null, "Email Y N:");
        $this->form->addElement('static', null, "Best time to call:");
        $this->form->addElement('static', null, "Additional contact: $this->indent relationship:");
        $this->form->addElement('static', null, "Parent 1 (or combined) Address:");
        $this->form->addElement('static', null, "Parent 2 Address (if 2 households):");
        $this->form->addElement('header', null, "*** Only for Subjects with Autism ***");
        $this->form->addElement('header', null, "<h4>Proband with autism</h4>");
        $this->form->addElement('static', null, "Name:");
        $this->form->addElement('static', null, "Gender: M F");
        $this->form->addElement('static', null, "Living in the home? Y N");
        $this->form->addElement('static', null, "Current diagnoses: $this->indent by");
        $this->form->addElement('static', null, "Other siblings:");
        $this->form->addElement('static', null, "Enrolled in any other Research Studies?");
        $this->form->addElement('static', null, "If yes, list:");
        $this->form->addElement('header', null, "Developmental Factors Younger Sibling SUBJECT:");
        $this->form->addElement('select', "neurological_problems", "Any specific neurological problems in SUBJECT?", $yes_no);
        $this->form->addElement('text', "neurological_problems_list", "$this->indent<i>List:</i>");
        $this->XINRegisterRule("neurological_problems_list", array("neurological_problems{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "genetic_conditions", "Diagnosed/suspected genetic conditions or syndromes?", $yes_no);
        $this->form->addElement('text', "genetic_conditions_list", "$this->indent<i>List:</i>");
        $this->XINRegisterRule("genetic_conditions_list", array("genetic_conditions{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "seizures", "Seizures or other neurological disorder?", $yes_no);
        $this->form->addElement('select', "cns_problems", "CNS problems? \n <h6>Depression and/or problems with sleeping, balance, walking, thinking, and memory</h6>", $yes_no);
        $this->form->addElement('text', "cns_problems_list", "$this->indent<i>List:</i>");
        $this->XINRegisterRule("cns_problems_list", array("cns_problems{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "congenital_problems", "Congenital or other heart problems?", $yes_no);
        $this->form->addElement('text', "congenital_problems_list", "$this->indent<i>List:</i>");
        $this->XINRegisterRule("congenital_problems_list", array("congenital_problems{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "hearing_vision_problems", "Any hearing/vision problems?", $yes_no);
        $this->form->addElement('text', "hearing_vision_problems_desc", "$this->indent<i>Describe:</i>");
        $this->XINRegisterRule("hearing_vision_problems_desc", array("hearing_vision_problems{@}=={@}yes"), "Required.");
        $this->form->addElement('static', null, "Current weight? (lbs/oz)");
        $this->form->addElement('text', "weight_pounds", "$this->indent Pounds:");
        $this->form->addElement('text', "weight_ounces", "$this->indent Ounces:");
        $this->form->addElement('header', null, "<h4>If yes to any of the above, obtain further information.</h4>");
        $this->form->addElement('header', null, "Medical History Pertaining to MRI/Sedation");
        $this->form->addElement('select', "surgical_problems", "1. Has X ever had any other serious medical or surgical problems?", $yes_no);
        $this->form->addElement('select', "ever_hospitalized", "2. Has X ever been hospitalized?", $yes_no);
        $this->form->addElement('select', "surgery", "3. Surgery of any type?", $yes_no);
        $this->form->addElement('text', "surgery_desc", "$this->indent <i>Describe:</i>");
        $this->XINRegisterRule("surgery_desc", array("surgery{@}=={@}yes"), "Required.");
        $this->form->addElement('text', "surgery_when", "$this->indent <i>When was this surgery completed?:</i>");
        $this->XINRegisterRule("surgery_when", array("surgery{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "metal_implants", "4. Does X have any metal plates, clips, implanted devices etc. from surgery? \n <h6>(Pacemaker, vascular stents, metallic ear tubes, insulin pump, or other metal implants)</h6>", $yes_no);
        $this->form->addElement('select', "dental_implants", "5. Does X have any dental implants or braces?", $yes_no);
        $this->form->addElement('text', "dental_implants_remove", "$this->indent <i>If yes, when are they scheduled to be removed?</i>");
        $this->XINRegisterRule("dental_implants_remove", array("dental_implants{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "medications", "6. Is X currently taking any medications?", $yes_no);
        $this->form->addElement('text', "medications_list", "$this->indent <i>If yes, list medications:</i>");
        $this->XINRegisterRule("medications_list", array("medications{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "allergies", "7. Does X have any allergies to  medicines?", $yes_no);
        $this->form->addElement('text', "allergies_desc", "$this->indent <i>If yes, describe:</i>");
        $this->XINRegisterRule("allergies_desc", array("allergies{@}=={@}yes"), "Required.");
        $this->form->addElement('select', "seen_doctor", "8. Has X seen a doctor for something besides a well-child visit over the last 12 months?", $yes_no);
        $this->form->addElement('text', "seen_doctor_desc", "$this->indent <i>If yes, describe:</i>");
        $this->XINRegisterRule("seen_doctor_desc", array("seen_doctor{@}=={@}yes"), "Required.");
        $this->form->addElement('header', null, "Medical Records:");
        $this->form->addElement('text', "new_diagnoses", "Any new diagnoses, dates, and locations:");
        $this->XINRegisterRule(
            "new_diagnoses",
            array("new_diagnoses{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }
    /**
     * Contains special numeric validations for weight fields on page 1
     */
    function validate_page1($values)
    {
        $errors = [];
        $this->validate_numeric($values, "weight_pounds", $errors, 0, 120);
        $this->validate_numeric($values, "weight_ounces", $errors, 0, 15);
        return $errors;
    }
}