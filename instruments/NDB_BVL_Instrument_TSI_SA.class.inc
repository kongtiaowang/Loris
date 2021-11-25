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
    use LegacyInstrumentTrait;

    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array('adjusted_income');

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
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
        $this->dateTimeFields    = array(
                                    "Date_taken",
                                    "sibling_dob_1",
                                    "sibling_dob_2",
                                    "sibling_dob_3",
                                    "sibling_dob_4",
                                    "sibling_dob_5",
                                    "sibling_dob_6",
                                    "sibling_dob_7",
                                    "sibling_dob_8",
                                    "sibling_dob_9",
                                    "sibling_dob_10",
                                   );
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
        if (preg_match("/TSI_SA(_page[0-9]+)/", $this->page, $matches)) {
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
     * Scores the instrument: computes the adjusted income and saves it
     * in the database
     *
     * @return void
     * @access private
     */
    function score(): void
    {
        //null scores
        $this->_nullScores($this->scoreLabels);
        $db =& Database::singleton();
        // Get the item scores
        $record = $db->pselectRow(
            "SELECT * FROM $this->table WHERE CommentID=:cid",
            array('cid' => $this->getCommentID())
        );
        $scores = array();

        $scores['adjusted_income'] = null;
        $invalidFields = $this->_getInvalidFieldsForAdjustedIncome($record);

        // If there are no invalid fields, compute the adjusted income. Otherwise
        // leave it as NULL
        if (count($invalidFields) == 0) {
            $scores['adjusted_income'] = $this->_getAdjustedIncome(
                $record['household_ses_1'],
                $record['zip_code_1']
            );

            // When the parents are not living together, compute the mean of
            // both adjusted incomes
            if (isset($record['same_home']) && $record['same_home'] == 'no') {
                $adjustedIncome2           = $this->_getAdjustedIncome(
                    $record['household_ses_2'],
                    $record['zip_code_2']
                );
                $scores['adjusted_income'] = ($scores['adjusted_income'] + $adjustedIncome2) / 2;
            }
        }

        $result = $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
    }

    /**
     * Sets the values that will appear in the form when it is reloaded.
     *
     * @return void
     * @access private
     */
    function _setDefaultsArray($defaults): array
    {
        $realValuesOnForm = count($this->form->getSubmitValues()) == 0
            ? $defaults : $this->form->getSubmitValues();
        $invalidFields    = $this->_getInvalidFieldsForAdjustedIncome($realValuesOnForm);
        if (count($invalidFields) != 0) {
            $errorMessages = array_values($invalidFields);
            $defaults['adjusted_income'] = "Not computed: $errorMessages[0]";
        }

        return parent::_setDefaultsArray($defaults);
    }


    /**
     * Computes the adjusted income for a given income and zip code.
     *
     * @param $income  one of the selected incomes in the form.
     * @param $zipCode houshold zip code.
     *
     * @return float The adjusted income
     *
     * @access private
     */
    function _getAdjustedIncome($income, $zipCode)
    {
        $midPoint = 0;
        switch ($income) {
        case "less_than_25K":
            $midPoint = 12500;
            break;
        case "25K-35K"      :
            $midPoint = 30000;
            break;
        case "35K-50K"      :
            $midPoint = 42750;
            break;
        case "50K-75K"      :
            $midPoint = 62500;
            break;
        case "75K-100K"     :
            $midPoint = 87500;
            break;
        case "100K-150K"    :
            $midPoint = 125000;
            break;
        case "150K-200K"    :
            $midPoint = 175000;
            break;
        case "over_200K"    :
            $midPoint = 200000;
            break;
        default             :
            throw new LorisException("Cannot compute adjusted income: unexpected income $income");
        }

        $medianIncome = $this->_getMedianIncome($zipCode);
        if (is_null($medianIncome)) {
            throw new LorisException("Invalid zip code $zipCode");
        }
        if (is_null($medianIncome[$zipCode]) || $medianIncome[$zipCode] == '') {
            throw new LorisException("Median income for zip code $zipCode is unknown");
        }

        return ($midPoint + (0.0)) / $medianIncome[$zipCode];
    }

    /**
     * Gets the median income for a given zip code.
     *
     * @param $zipCode houshold zip code.
     *
     * @return array a hash with one key (the zip code) and one value (the median
     *               income, which can be null). This method will return null if
     *               the zip code is unknown/invalid.
     *
     * @access private
     */
    function _getMedianIncome($zipCode)
    {
        $db  =& Database::singleton();
        $row = $db->pselectRow(
            "SELECT MedianIncome FROM median_income WHERE ZipCode=:zip",
            array('zip' => $zipCode)
        );

        // No info in the database for this zip code: return null
        if (count($row) == 0) {
            return null;
        }

        return array($zipCode => $row['MedianIncome']);
    }


    /**
     * Checks that all fields used to compute the adjusted income are valid
     *
     * @param $values all the cvalues entered in the form
     *
     * @return array a hash where the keys are the invalid field names and the values
     *               are the error messages why they are invalid.
     * @access private
     */
    function _getInvalidFieldsForAdjustedIncome($values)
    {
        $invalidFields = array();

        // -----------------------------------------------------------------#
        // SES and zip code of household 1 have to be defined all the time #
        // -----------------------------------------------------------------#
        if (!$this->_isValidForAdjustedIncome($values, 'household_ses_1')) {
            $invalidFields['household_ses_1'] = "the income for household 1 is unknown";
        }
        if (!$this->_isValidForAdjustedIncome($values, 'zip_code_1')) {
            $invalidFields['zip_code_1'] = "the zip code for household 1 is unknown";
        }

        // -----------------------------------------------------------------#
        // SES and zip code of household 2 have to be defined only if the  #
        // parents do not live in the same home                            #
        // -----------------------------------------------------------------#
        if (isset($values['same_home']) && $values['same_home'] == 'no') {
            if (!$this->_isValidForAdjustedIncome($values, 'household_ses_2')) {
                $invalidFields['household_ses_2'] = "the income for household 2 is unknown";
            }
            if (!$this->_isValidForAdjustedIncome($values, 'zip_code_2')) {
                $invalidFields['zip_code_2'] = "the zip code for household 2 is unknown";
            }
        }

        if (count($invalidFields) != 0) {
            return $invalidFields;
        }

        // --------------------------------------------------------#
        // Checks that we have the median income associated to    #
        // zip code 1                                             #
        // --------------------------------------------------------#
        $medianIncome = $this->_getMedianIncome($values['zip_code_1']);
        if (is_null($medianIncome)) {
            $invalidFields['zip_code_1'] = "zip code " . $values['zip_code_1'] . " is invalid";
        } else if (is_null($medianIncome[$values['zip_code_1']]) || $medianIncome[$values['zip_code_1']] == '') {
            $invalidFields['zip_code_1'] = "Median income for zip code " . $values['zip_code_1'] . " is unknown";
        }

        // --------------------------------------------------------#
        // Checks that we have the median income associated to    #
        // zip code 2 only if the parents are not living in the   #
        // same household                                         #
        // --------------------------------------------------------#
        if (isset($values['same_home']) && $values['same_home'] == 'no') {
            $medianIncome = $this->_getMedianIncome($values['zip_code_2']);
            if (is_null($medianIncome)) {
                $invalidFields['zip_code_1'] = "zip code " . $values['zip_code_2'] . " is invalid";
            } else if (is_null($medianIncome[$values['zip_code_2']]) || $medianIncome[$values['zip_code_2']] == '') {
                $invalidFields['zip_code_2'] = "Median income for zip code " . $values['zip_code_2'] . " is unknown";
            }
        }

        return $invalidFields;
    }

    /**
     * Checks if a field is valid (i.e can be used) for the computation of the
     * adjusted income.
     *
     * @param $values array of the values entered in the form.
     * @param $key    name of the field to check.
     *
     * @return boolean true if the field is valid, false otherwise.
     *
     * @access private
     */

    function _isValidForAdjustedIncome($values, $key)
    {
        return isset($values[$key]) && $values[$key] != '' && $values[$key] != 'not_answered';
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
            if ($field == "Date of Contact:") {
                $this->addDateElement("contact", $field);
            } else {
                $this->form->addElement('static', null, $field);
            }
        }
        $yes_no            = array(
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
        $ses_income        = array(
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

        $days_choices = array(
                         null           => "",
                         "0"            => "0",
                         "0.5"          => "0.5",
                         "1"            => "1",
                         "1.5"          => "1.5",
                         "2"            => "2",
                         "2.5"          => "2.5",
                         "3"            => "3",
                         "3.5"          => "3.5",
                         "4"            => "4",
                         "4.5"          => "4.5",
                         "5"            => "5",
                         "5.5"          => "5.5",
                         "6"            => "6",
                         "6.5"          => "6.5",
                         "7"            => "7",
                         "not_answered" => "Not Answered",
                        );

        $this->form->addElement("select", "household_ses_1", "Household SES 1 (or combined):", $ses_income);
        $this->addTextElement("zip_code_1", "$this->indent Household Zip Code:");
        $this->form->addElement('select', "days_at_house_1", "$this->indent Days per week child spends at this address:", $days_choices);
        $this->form->addElement('static', null, "<BR>");

        $this->form->addElement("select", "household_ses_2", "Household SES 2 (if 2 households):", $ses_income);
        $this->addTextElement("zip_code_2", "$this->indent Household Zip Code:");
        $this->form->addElement('select', "days_at_house_2", "$this->indent Days per week child spends at this address:", $days_choices);
        $this->XINRegisterRule("household_ses_2", array("same_home{@}=={@}no"), "Required if parents not cohabitating.");
        $this->XINRegisterRule("zip_code_2", array("zip_code_2{@}=={@}NEVER_REQUIRED"));
        $this->XINRegisterRule("days_at_house_2", array("same_home{@}=={@}no"), "Required if parents not cohabitating.");

        $this->addScoreColumn("adjusted_income", "Adjusted Income (<i>using the U.S. Census Bureau, 2013-2017 American Community Survey 5-Year Estimates</i>):");

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
        $this->form->addElement('header', null, "Proband");
        $this->form->addElement('static', null, "Name:");
        //        $this->form->addText('subject_firstname', "First name");
        //        $this->XINRegisterRule("subject_firstname", array("subject_firstname{@}=={@}NEVER_REQUIRED"));
        //        $this->form->addText('subject_middlename', "Middle name");
        //        $this->XINRegisterRule("subject_middlename", array("subject_middlename{@}=={@}NEVER_REQUIRED"));
        //        $this->form->addText('subject_lastname', "Last name");
        //        $this->XINRegisterRule("subject_lastname", array("subject_lastname{@}=={@}NEVER_REQUIRED"));
        $this->form->addSelect('subject_gender', "Gender:", array(null => "", "m" => "M", "f" => "F"));
        $this->XINRegisterRule("subject_gender", array("subject_gender{@}=={@}NEVER_REQUIRED"));
        $this->form->addSelect('subject_living_in_home', "Living in the home?", array(null => "", "y" => "Y", "n" => "N"));
        $this->XINRegisterRule("subject_living_in_home", array("subject_living_in_home{@}=={@}NEVER_REQUIRED"));
        $this->form->addSelect('proband_with_autism', "Proband with autism?", array(null => "", "y" => "Y", "n" => "N"));
        $this->XINRegisterRule("proband_with_autism", array("proband_with_autism{@}=={@}NEVER_REQUIRED"));
        $this->form->addText('subject_current_diagnoses', "Current diagnoses:");
        $this->XINRegisterRule("subject_current_diagnoses", array("subject_current_diagnoses{@}=={@}NEVER_REQUIRED"));
        $this->form->addText('subject_current_diagnoses_by', "Diagnoses by:");
        $this->XINRegisterRule("subject_current_diagnoses_by", array("subject_current_diagnoses_by{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "Other siblings:");
        $group[] =& $this->form->createElement("static", null, null, "Name");
        $group[] =& $this->form->createElement("static", null, null, "DOB");
        $group[] =& $this->form->createElement("static", null, null, "Gender");
        $group[] =& $this->form->createElement("static", null, null, "Any diagnoses?");
        $group[] =& $this->form->createElement("static", null, null, "Half/full/step");
        $group[] =& $this->form->createElement("static", null, null, "Live in home?");
        $this->addGroup($group, "other_siblings_headers", null, $this->_GUIDelimiter, false);
        unset($group);
        for ($i = 1; $i <= 10; $i++) {
            $group[] =& $this->createText("sibiling_name_{$i}", "", ['disabled' => 'disabled']);
            $group[] =& $this->createDate("sibling_dob_{$i}", "");
            $group[] =& $this->createSelect("sibling_gender_{$i}", "", array(null => "", "m" => "M", "f" => "F"));
            $group[] =& $this->createText("sibiling_dx_{$i}", "");
            $group[] =& $this->createSelect("sibling_half_full_step_{$i}", "", array(null => "", "half" => "Half", "full" => "Full", "step" => "Step"));
            $group[] =& $this->createSelect("sibling_live_in_home_{$i}", "", array(null => "", "y" => "Y", "n" => "N"));
            $this->XINRegisterRule("sibiling_name_{$i}", array("sibiling_name_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("sibling_dob_{$i}", array("sibling_dob_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("sibling_gender_{$i}", array("sibling_gender_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("sibiling_dx_{$i}", array("sibiling_dx_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("sibling_half_full_step_{$i}", array("sibling_half_full_step_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("sibling_live_in_home_{$i}", array("sibling_live_in_home_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->addGroup($group, "sibling_group_{$i}", null, $this->_GUIDelimiter, false);
            unset($group);
        }
        $this->form->addElement('select', "enrolled_in_other_studies", "Enrolled in any other Research Studies?", $yes_no);
        $this->form->addElement('text', "other_studies_list", "$this->indent<i>If yes, list:</i>");
        $this->XINRegisterRule("other_studies_list", array("enrolled_in_other_studies{@}=={@}yes"), "Required.");
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
        $this->validate_numeric($values, "weight_pounds", $errors, 0, 220);
        $this->validate_numeric($values, "weight_ounces", $errors, 0, 15);

        // If the parents are not living together
        if ($values['same_home'] == 'no') {
            $zipCode2Unset       = !isset($values['zip_code_2']) || $values['zip_code_2'] == '';
            $zipCode2StatusUnset = !isset($values['zip_code_2_status']) || $values['zip_code_2_status'] == '';

            // Checks that zip_code_2 was answered
            if ($zipCode2Unset && $zipCode2StatusUnset) {
                $errors['zip_code_2_group'] = 'Required if the parent are not cohabitating';
            }

            if ($values['days_at_house_1'] + $values['days_at_house_2'] > 7) {
                $errors['days_at_house_1'] = 'The sum of the days spent at both households cannot exceed 7';
                $errors['days_at_house_2'] = 'The sum of the days spent at both households cannot exceed 7';
            }
            // Parents are living together: validate the section pertaining to household 2 is empty
        } else {
            if ($values['household_ses_2'] != '') {
                $errors['household_ses_2'] = "Must be left blank unless the parents are "
                    . "not cohabitating (section Parent's information, above)";
            }
            if ($values['zip_code_2'] != '' || $values['zip_code_2_status'] != '') {
                $errors['zip_code_2_group'] = "Must be left blank unless the parents are "
                    . "not cohabitating (section Parent's information, above)";
            }
            if ($values['days_at_house_2'] != '') {
                $errors['days_at_house_2'] = "Must be left blank unless the parents are "
                    . "not cohabitating (section Parent's information, above)";
            }
        }

        // Check that we have information on each entered zip code in the database.
        $this->validate_zip_code($values, "zip_code_1", $errors, "zip_code_1_group");
        if (!isset($errors['zip_code_1_group']) && isset($values['zip_code_1']) && $values['zip_code_1'] != '') {
            if (is_null($this->_getMedianIncome($values['zip_code_1']))) {
                $errors['zip_code_1_group'] = "Zip code does not exist";
            }
        }

        $this->validate_zip_code($values, "zip_code_2", $errors, "zip_code_2_group");
        if (!isset($errors['zip_code_2_group']) && isset($values['zip_code_2']) && $values['zip_code_2'] != '') {
            if (is_null($this->_getMedianIncome($values['zip_code_2']))) {
                $errors['zip_code_2_group'] = "Zip code does not exist";
            }
        }

        return $errors;
    }
}
