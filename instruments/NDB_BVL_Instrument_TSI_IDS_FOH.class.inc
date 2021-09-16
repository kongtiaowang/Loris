<?php
/**
 * This file contains the NDB_BVL_Instrument_TSI_IDS_FOH class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Moshood Kolawole <moshood.abiola@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

 /**
 * Creates the form elements for the IDS - FOH - Telephone Screening Interview
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Moshood Kolawole <moshood.abiola@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_TSI_IDS_FOH extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    const YES_NO_NA_OPTIONS = array(
                               null           => "",
                               "yes"          => "Yes",
                               "no"           => "No",
                               "not_answered" => "Not Answered",
                              );

    const YES_NO_OPTIONS = array(
                            null  => "",
                            "yes" => "Yes",
                            "no"  => "No",
                           );

    const GENDER_OPTIONS = array(
                            null     => "",
                            "male"   => "Male",
                            "female" => "Female",
                           );

    const EDUCATION_OPTIONS = array(
                               null                      => "",
                               'some_high_school'        => 'Some High School',
                               'high_school'             => 'High School',
                               'some_college_2yr_degree' => 'Some College/2yr. Degree',
                               'college_degree'          => 'College Degree',
                               'some_grad_school'        => 'Some Graduate School',
                               'grad_degree'             => 'Graduate Degree',
                               'not_answered'            => 'Not Answered',
                              );

    const RACE_OPTIONS = array(
                           null                              => "",
                          'white'                            => 'White',
                          'black_african_american'           => 'Black or African American',
                          'asian'                            => 'Asian',
                          'unknown_not_reported'             => 'Unknown or not Reported',
                          'american_indian_alaska_native'    => 'American Indian / Alaska Native',
                          'native_hawaiian_pacific_islander' => 'Native Hawaiian / Other Pacific Islander',
                          'not_answered'                     => 'Not Answered',
                         );

    const ETHNICITY_OPTIONS = array(
                               null           => '',
                               'hispanic'     => 'Hispanic',
                               'non_hispanic' => 'Non-Hispanic',
                               'not_answered' => 'Not Answered',
		       );

    const HOUSEHOLD_SES_OPTIONS_MOTHER = array(
	                                null        => "",
                                        "combined"  => "Combined",
					"mother"    => "Mother",
				       );

    const HOUSEHOLD_SES_OPTIONS_FATHER = array(
	                                null      => "",
                                        "na"      => "N/A",
                                        "father"  =>"Father (if two households)",
                                       );

    const HOUSEHOLD_SES_OPTIONS_AMOUNT = array(
                                   null            => '',
                                   'less_than_25K' => 'less than $24,999',
                                   '25K-35K'       => '$25,000 - 34,999',
                                   '35K-50K'       => '$35,000 - 49,999',
                                   '50K-75K'       => '$50,000 - 74,999',
                                   '75K-100K'      => '$75,000 - 99,999',
                                   '100K-150K'     => '$100,000 - 149,999',
                                   '150K-200K'     => '$150,000 - 199,000',
                                   'over_200K'     => 'over $200,000',
                                   'not_answered'  => 'Not Answered',
                                  );

    const Q9_DEV_FACTORS_OPTIONS = array(
                                    null                            => '',
                                    "atrial_septal_defect_ASD"      => "Atrial septal defect (ASD)",
                                    "ventricular_septal_defect_VSD" => "Ventricular septal defect (VSD)",
                                    "av_canal_defect"               => "AV canal defect",
                                    "coarctation_of_the_aorta"      => "Coarctation of the aorta",
                                    "patent_ductus_arteriosus_PDA"  => "Patent ductus arteriosus (PDA)",
                                    "patent_foramen_ovale_PFO"      => "Patent foramen ovale (PFO)",
                                    "tetralogy_of_fallot"           => "Tetralogy of Fallot",
                                    "other"                         => "Other",
                                   );

    const Q15_DEV_FACTORS_PROBAND_OPTIONS = array(
                                             null                                                   => '',
                                             "cancer"                                               => "Cancer",
                                             "cytomegalovirus_CMV_infection"                        => "Cytomegalovirus CMV infection",
                                             "herpes_while_pregnant_and_infant_delivered_vaginally" => "Herpes infection while pregnant and infant delivered vaginally",
                                             "hypertension_treated_with_medication"                 => "Hypertension treated with medication",
                                             "hypothyroidism"                                       => "Hypothyroidism",
                                             "hyperthyroidism"                                      => "Hyperthyroidism",
                                             "parvovirus"                                           => "Parvovirus",
                                             "placental_abruption"                                  => "Placental abruption",
                                             "placenta_previa"                                      => "Placenta previa",
                                             "preterm_labor"                                        => "Preterm labor",
                                             "maternal_prenatal_hospitalization"                    => "Maternal prenatal hospitalization",
                                             "sickle_cell_anemia"                                   => "Sickle cell anemia",
                                             "single_umbilical_artery"                              => "Single umbilical artery",
                                             "toxemia_pre_eclampsia"                                => "Toxemia (aka pre-eclampsia)",
                                             "umbilical-artery-malformation"                        => "Umbilical artery malformation",
                                             "other"                                                => "Other",
                                            );

    const Q16_DEV_FACTORS_OPTIONS = array(
                                     null                  => '',
                                     "emergency_c_section" => "Emergency C-section",
                                     "forceps"             => "Forceps",
                                     "planned_c_section"   => "Planned C-section",
                                     "planned_induction"   => "Planned Induction",
                                     "vacuum_extraction"   => "Vacuum Extraction",
                                     "vaginal_delivery"    => "Vaginal Delivery",
                                     "other"               => "Other (explain)",
                                     "not_answered"        => "Not Answered",
                                    );
    
        /**
     * Sets up basic data, such as the LorisForm object, and so on.
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
        $this->form     = new LorisForm('TSI_IDS_FOH_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "TSI_IDS_FOH";           // test_names.Test_name
        $this->table    = 'TSI_IDS_FOH';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array(
                                          "q9a_exclusionary_conditions",
                                          "q15a_exclusionary_conditions",
                                          "q16_method_of_delivery",
                                          "subject_race",
                                          "sibling_race",
                                          "bio_mother_race",
                                          "bio_father_race",
                                         );

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "subject_dob",
                                    "enrolled_in_other_studies_or_registries",
                                    "q1_has_subject_had_any_genetic_testing_done",
                                    "q1_has_sibling_had_any_genetic_testing_done",
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
        if (preg_match("/TSI_IDS_FOH(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("TSI (Telephone Screening Interview ) - iDS - FOH");
        $this->addCheckbox('not_finish0', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, '<h4><i>*Identifying information should not be entered in the database</i></h4>');

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $config      =& NDB_Config::singleton();
        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );

        $this->form->addElement('static', null, null);

	$this->addBasicDate('date_of_most_recent_visit', 'Date of most recent IBIS visit: ', $dateOptions);
	
	$this->form->addElement('text', null, "City/State of Birth", ['disabled' => 'disabled']);
        $this->XINRegisterRule("date_of_most_recent_visit", array("not_finish0{@}!={@}1"), 'Required.');


    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("TSI (Telephone Screening Interview ) - iDS - FOH");
        $this->addCheckbox('not_finish1', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, '<h4><i>*Identifying information should not be entered in the database</i></h4>');

        $this->form->addElement('static', null, '<h4><b>CONTACT INFORMATION</b></h4>');

        $pii_contact = array(
                        "First Name",
                        "Middle Name",
                        "Last Name",
                        "Maiden Name",
                        "Date of Birth",
                        "Cell Phone",
                        "Home Phone",
                        "Work Phone",
                        "Email Address",
                       );

        $page1_questions = array(
                            "are_parents_divorced_or_separated"          => "Are parents divorced or separated?",
                             );

        $pii_address = array(
                        "Street Address",
                        "City",
                        "State",
                        "Zip Code",
                       );
        
        $this->form->addElement('text', null, $this->indent . "First Name", ['disabled' => 'disabled']);
        $this->form->addElement('text', null, $this->indent . "Middle Name", ['disabled' => 'disabled']);
        $this->form->addElement('text', null, $this->indent . "Last Name", ['disabled' => 'disabled']);

        $this->addBasicDate("subject_dob", $this->indent . 'Date of Birth', $this->dateOptions);
        $this->addBasicDate("subject_expected_due_date", $this->indent . 'Expected Due Date', $this->dateOptions);

        $this->addSelect("subject_premature", $this->indent . "Was infant premature?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "subject_how_many_weeks_gestation", $this->indent . "Born at how many weeks of gestation?");
             
        $this->addSelect("subject_gender", $this->indent . "Gender", self::GENDER_OPTIONS);

        $this->addSelect("subject_adopted", $this->indent . "Subject adopted?", self::YES_NO_OPTIONS);
        $this->addSelect("subject_multiple", $this->indent . "Subject a multiple?", self::YES_NO_OPTIONS);

        $this->form->addElement('text', "subject_birth_weight_lbs", $this->indent . "Birth weight (lbs)");
        $this->form->addElement('text', "subject_birth_weight_oz", $this->indent . "Birth weight (oz)");
        $this->form->addElement('text', "current_weight_lbs", $this->indent . "Current weight (lbs)");

        $this->form->addElement('text', "current_height_ft", $this->indent . "Current height (ft.)");
        $this->form->addElement('text', "current_height_in", $this->indent . "Current height (in.)");

        $this->form->addElement('text', "current_age_year", $this->indent . "Current age (year(s))");
        $this->form->addElement('text', "current_age_mon", $this->indent . "Current age (month(s))");

       // BIOLOGICAL MOTHER INFORMATION
       $this->form->addElement('static', null, "BIOLOGICAL MOTHER");

        foreach ($pii_contact as $field) {
            if ($field == "Date of Birth") {
                $this->addDateElement("mother_dob", $this->indent . $field);
            } else {
                $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
            }
        }
	$this->XINRegisterRule("mother_dob_date", array("mother_dob_date{@}=={@}"), 'Required.');

	$this->addSelect("preferred_method_contact_mother", $this->indent . "Preferred method of contact", array(null,"Phone","Email"));
        $this->XINRegisterRule("preferred_method_contact_mother", array("preferred_method_contact_mother{@}=={@}never_required"), 'Not Required.');
        $this->addSelect("best_call_number_mother", $this->indent . "Best number to call",array(null,'Cell','Work','Home'));
        $this->XINRegisterRule("best_call_number_mother", array("best_call_number_mother{@}=={@}never_required"), 'Not Required.');
        $this->addSelect("best_time_call_mother", $this->indent . "Best time to call",array(null,'AM','PM'));
        $this->XINRegisterRule("best_time_call_mother", array("best_time_call_mother{@}=={@}never_required"), 'Not Required.');
        $this->addSelect("okay_leave_message_mother", $this->indent . "Okay to leave message?", self::YES_NO_OPTIONS);
        $this->XINRegisterRule("okay_leave_message_mother", array("okay_leave_message_mother{@}=={@}never_required"), 'Not Required.');
        
        $this->form->addElement('static', null, null);

        // BIOLOGICAL FATHER INFORMATION
        $this->form->addElement('static', null, "BIOLOGICAL FATHER");

        foreach ($pii_contact as $field) {
            if ($field == "Date of Birth") {
                $this->addDateElement("father_dob", $this->indent . $field);
            } elseif ($field != "Maiden Name") {
                $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
            }
        }
	$this->XINRegisterRule("father_dob_date", array("father_dob_date{@}=={@}"), 'Required');

	$this->addSelect("preferred_method_contact_father", $this->indent . "Preferred method of contact", array("","Phone","Email"));
        $this->XINRegisterRule("preferred_method_contact_father", array("preferred_method_contact_father{@}=={@}never_required"), 'Not Required.');
        $this->addTextElement("best_call_number_father", $this->indent . "Best number to call");
        $this->XINRegisterRule("best_call_number_father", array("best_call_number_father{@}=={@}never_required"), 'Not Required.');
        $this->addTextElement("best_time_call_father", $this->indent . "Best time to call (AM/PM)");
        $this->XINRegisterRule("best_time_call_father", array("best_time_call_father{@}=={@}never_required"), 'Not Required.');
        $this->addSelect("okay_leave_message_father", $this->indent . "Okay to leave message?", self::YES_NO_OPTIONS);
        $this->XINRegisterRule("okay_leave_message_father", array("okay_leave_message_father{@}=={@}never_required"), 'Not Required.');
        
        $this->form->addElement('static', null, null);

        // HOUSEHOLD INFO
        foreach ($page1_questions as $field => $label) {
            $this->addSelect($field, $label, self::YES_NO_OPTIONS);

            }

	$this->form->addElement('static', null, null);

        // CHILD PRIMARY ADDRESS
        $this->form->addElement('static', null, "CHILD PRIMARY ADDRESS");

        $this->addSelect("child_primary_address", $this->indent . "Child's primary address", array(null => "", "both_parents" => "Both parents", "mother" => "Mother", "father" => "Father","other" => "Other"));        
        $this->form->addElement('text', 'address_specify', 'If other, specify:');
        $this->XINRegisterRule('address_specify', array('child_primary_address{@}=={@}other'), 'Required if other');

        foreach ($pii_address as $field) {
            $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
        }

        $this->form->addElement('static', null, null);

        // SECONDARY ADDRESS
        $this->form->addElement('static', null, "SECONDARY ADDRESS<br>(if 2 households)");

        $this->addSelect("child_primary_address2", $this->indent . "Child's secondary address", array(null => "", "mother" => "Mother", "father" => "Father","other" => "Other"));        
        $this->form->addElement('text', 'address_specify2', 'If other, specify:');
        $this->XINRegisterRule('address_specify2', array('child_primary_address2{@}=={@}other'), 'Required if other');

        foreach ($pii_address as $field) {
            $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
        }

        $this->form->addElement('static', null, null);

        // ALTERNATE CONTACT INFORMATION
        $this->form->addElement('static', null, "ALTERNATE CONTACT");

        foreach ($pii_contact as $field) {
            if ($field != "Maiden Name" && $field != "Date of Birth") {
                $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
            }
        }

        $this->form->addElement('text', "relationship_to_family", $this->indent . "Relationship to family:");

        $this->form->addElement('static', null, null);

	// ADDITIONAL INFORMATION
	$this->form->addElement("textarea","additional_info_about_childs_home", "Additional information about child’s home:", array('cols'=>25, 'rows'=>4));

	//MOTHER & FATHER OCCUPATION/EDUCATION
	$this->addTextElement("mother_occupation", "Mother Occupation");
	$this->addSelect("mother_education", "Mother Education", self::EDUCATION_OPTIONS);
	$this->XINRegisterRule("mother_occupation", array("mother_occupation{@}=={@}never_required"), 'Not Required.');

	$this->addTextElement("father_occupation", "Father Occupation");
        $this->XINRegisterRule("father_occupation", array("father_occupation{@}=={@}never_required"), 'Not Required.');

        $this->addSelect("father_education", "Father Education", self::EDUCATION_OPTIONS);

	//HOUSEOLD SES

        //HOUSEOLD SES
        $this->form->addElement('static', null, "HOUSEHOLD SES");

	$this->addSelect("household_ses_mother", "Household SES Mother", self::HOUSEHOLD_SES_OPTIONS_MOTHER);
	$this->addSelect("household_ses_mother_or_combined", $this->indent . "Amount", self::HOUSEHOLD_SES_OPTIONS_AMOUNT);
	$this->addSelect("household_ses_father", "Household SES Father", self::HOUSEHOLD_SES_OPTIONS_FATHER);
	$this->addSelect("household_ses_father_if_2_households", $this->indent .  "Amount", self::HOUSEHOLD_SES_OPTIONS_AMOUNT);

        $this->XINRegisterRule("household_ses_mother_or_combined", array("household_ses_mother_or_combined{@}=={@}NEVER_REQUIRED"));
	$this->XINRegisterRule("household_ses_father_if_2_households", array("household_ses_father_if_2_households{@}=={@}NEVER_REQUIRED"));
	$this->XINRegisterRule("household_ses_mother", array("household_ses_mother_or_combined_amount{@}=={@}NEVER_REQUIRED"));
	$this->XINRegisterRule("household_ses_father", array("household_ses_father_if_2_households_amount{@}=={@}NEVER_REQUIRED"));

        $this->form->addElement('static', null, null);

        //RACE
        $race_questions = array(
            "subject_race"  => "Subject Race:",
            "sibling_race"  => "Sibling Race:",
            "bio_mother_race" => "Bio-Mother Race:",
            "bio_father_race" => "Bio-Father Race:",
           );

        foreach ($race_questions as $key => $question) {
        $this->addSelect($key, $question, self::RACE_OPTIONS, array("multiple"));
        }

        $this->form->addElement('static', null, null);

        //ETHNIC
        $ethnicity_questions = array(
                 "subject_ethnicity"  => "Subject Ethnicity:",
                 "sibling_ethnicity"  => "Sibling Ethnicity:",
                 "bio_mother_ethnicity" => "Bio-Mother Ethnicity:",
                 "bio_father_ethnicity" => "Bio-Father Ethnicity:",
                );

        foreach ($ethnicity_questions as $key => $question) {
        $this->addSelect($key, $question, self::ETHNICITY_OPTIONS);
        }

        $this->addSelect("is_english_primary_language_spoken_in_home", "Is English the primary language spoken in the home?", self::YES_NO_OPTIONS); 
        
        $this->form->addElement('static', null, null);

        $this->XINRegisterRule("subject_dob", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_expected_due_date", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_birth_weight_lbs", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_birth_weight_oz", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_adopted", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_multiple", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("current_weight_lbs", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("current_height_ft", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("current_height_in", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("current_age_mon", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("current_age_year", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_gender", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_premature", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_how_many_weeks_gestation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("mother_dob_date", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("mother_occupation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("mother_education", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("father_dob_date", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("father_occupation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("father_education", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("child_primary_address", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("child_primary_address2", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("are_parents_divorced_or_separated", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("relationship_to_family", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("additional_info_about_childs_home", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_race", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("sibling_race", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_mother_race", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_father_race", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_ethnicity", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("sibling_ethnicity", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_mother_ethnicity", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_father_ethnicity", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("is_english_primary_language_spoken_in_home", array("not_finish1{@}!={@}1"), 'Required.');
        $this->form->addFormRule(array(&$this, 'validate_page1'));

    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("TSI (Telephone Screening Interview ) - iDS - FOH");
        $this->addCheckbox('not_finish2', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, '<h4><i>*Identifying information should not be entered in the database</i></h4>');

        $this->form->addElement('static', null, "<h4> ***For All Subjects*** </h4>");

        //SUBJECTS
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Current diagnoses"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Example: ADHD"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "by"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "School Psychologist"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Date"
        );
        $this->addGroup(
            $group,
            "page2_subject_example",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for($i=1; $i<=4; $i++){
            $group[] =& $this->form->createElement(
                "static",
                null,
                null,
                null
            );
            $group[] = $this->form->createElement(
                "text",
                "diagnose_".$i,
                null,
                null
            );
            $this->XINRegisterRule(
                "diagnose_" . $i,
                array("diagnose_{$i}{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "diagnose_" . $i . "_group"
            );
            $group[] =& $this->form->createElement(
                "static",
                null,
                null,
                "by"
            );
            $group[] = $this->form->createElement(
                "text",
                "who_".$i,
                null,
                null
            );
            $this->XINRegisterRule(
                "who_" . $i,
                array("who_{$i}{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "who_" . $i . "_group"
            );
            $group[] =& $this->form->createElement(
                "date",
                "date_".$i,
                null
            );
            $this->XINRegisterRule(
                "date_" . $i,
                array("date_{$i}{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "date_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "page2_subject".$i,
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement('static', null, null);

        $this->form->addElement('static', null, "<h4><b>List siblings from oldest to youngest. (FOH: Put a * next to chosen sibling subject)</b></h4>");

        $sibling_options = array(
                            null      => '',
                            "half"    => "Half",
                            "full"    => "Full",
                            "step"    => "Step",
                            "adopted" => "Adopted",
                           );

        // SUBJECT'S SIBLINGS
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "First Name"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Last Name"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "DOB"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "M/F"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Any developmental disabilities or chronic medical diagnoses?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Half/full/step/adopted"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Live in home?"
        );
	$group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "FOH Sibling Subject?"
        );
        $this->addGroup(
            $group,
            "page2_sibling_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i = 1; $i <= 8; $i++) {

            $group[] =& $this->createText(
                null,
                "",
                ['disabled' => 'disabled']
            );
            $group[] =& $this->createText(
                null,
                "",
                ['disabled' => 'disabled']
            );
            $group[] =& $this->createDate(
                "sibling_{$i}_dob",
                ""
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_gender",
                "M/F",
                self::GENDER_OPTIONS
            );
            $group[] =& $this->createText(
                "sibling_{$i}_diagnoses",
                null,
                ""
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_type",
                "Half/full/step/adopted",
                $sibling_options
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_live_in_home",
                "Live in home?",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_foh_sibling_subject",
                "FOH Sibling Subject?",
                self::YES_NO_OPTIONS
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_dob",
                array("sibling_{$i}_dob{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "sibling_" . $i . "_gender",
                array("sibling_{$i}_gender{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "sibling_" . $i . "_diagnoses",
                array("sibling_{$i}_diagnoses{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "sibling_" . $i . "_type",
                array("sibling_{$i}_type{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "sibling_" . $i . "_live_in_home",
                array("sibling_{$i}_live_in_home{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_foh_sibling_subject",
                array("sibling_{$i}_live_in_home{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "sibling_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement('static', null, null);

        $this->addSelect("enrolled_in_other_studies_or_registries", "Enrolled in any other Research Studies or Registries?", self::YES_NO_OPTIONS);

        $this->form->addElement('text', "enrolled_in_other_studies_or_registries_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("enrolled_in_other_studies_or_registries_list", array("enrolled_in_other_studies_or_registries{@}=={@}yes"), 'Required if yes');

        $this->XINRegisterRule("enrolled_in_other_studies_or_registries", array("not_finish2{@}!={@}1"), 'Required.');

       // $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->addHeader("TSI (Telephone Screening Interview ) - iDS - FOH");
        $this->addCheckbox('not_finish3', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, "<h4><b>Developmental Factors in SUBJECT </b>(If yes to any, obtain further info)</h4>");

        $this->form->addElement('static', null, null);

        $q13_breastfeeding_options = array(
                                    null      => "",
                                    "weaned"  => "Weaned",
                                    "current" => "Current",
                                    "never"   => "Never",
                                   );

        // Q1
        $this->addSelect("q1_has_subject_had_any_genetic_testing_done", "1. Has SUBJECT had any genetic testing done (other than for DS)?", self::YES_NO_OPTIONS);
        $this->form->addElement("textarea","q1a_subject_had_testing_done_when_where", $this->indent . "If yes, when and where?", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("q1a_subject_had_testing_done_when_where", array("q1_has_subject_had_any_genetic_testing_done{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        //Q2
        $this->form->addSelect("q2_diagnosed_suspected_genetic_conditions","2. Diagnosed/suspected genetic conditions/syndromes (other than DS)?", self::YES_NO_OPTIONS);
        $this->form->addElement(
            "text",
            "q2a_diagnosed_suspected_genetic_conditions_list",
            $this->indent . "If yes, list:"
        );
        $this->XINRegisterRule("q2a_diagnosed_suspected_genetic_conditions_list", array("q2_diagnosed_suspected_genetic_conditions{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q3
        $this->addSelect("q3_seizures_or_other_neurological_disorder", "3. Seizures or other neurological disorder?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q3a_seizures_or_other_neurological_disorder_how_often", $this->indent . 'How often? (#/day, #/week)</h6>');
        $this->XINRegisterRule("q3a_seizures_or_other_neurological_disorder_how_often", array("q3_seizures_or_other_neurological_disorder{@}=={@}yes"), 'Required if yes');

        $this->form->addElement(
            "text",
            "q3b_are_the_seizures_under_control",
            $this->indent . "Are the seizures under control (i.e., stable)?"
        );
        $this->XINRegisterRule(
            "q3b_are_the_seizures_under_control",
            array("q3b_are_the_seizures_under_control{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
        $this->form->addElement(
            "text",
            "q3c_medication_for_seizures",
            $this->indent . "Medication for seizures (& dosage)"
        );
        $this->XINRegisterRule(
            "q3c_medication_for_seizures",
            array("q3c_medication_for_seizures{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
        $this->form->addElement(
            "text",
            "q3d_last_time_medication_dosage_was_changed",
            $this->indent . "Last time medication/dosage was changed "
        );
        $this->XINRegisterRule(
            "q3d_last_time_medication_dosage_was_changed",
            array("q3d_last_time_medication_dosage_was_changed{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement('static', null, null);

        // Q4
        $this->addSelect("q4_history_of_head_injury_in_subject", '4. History of head injury in SUBJECT?',self::YES_NO_OPTIONS);
	$this->form->addElement("textarea","q4a_if_yes_explain",  $this->indent . "If yes, explain:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("q4a_if_yes_explain", array("q4_history_of_head_injury_in_subject{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q5
        $this->addSelect("q5_significant_hearing_vision_problems_in_subject", "5. Significant Hearing/Vision problems in SUBJECT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q5a_significant_hearing_vision_problems_in_subject_lists", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q5a_significant_hearing_vision_problems_in_subject_lists", array("q5_significant_hearing_vision_problems_in_subject{@}=={@}yes"), 'Required if yes');
    
        $this->form->addElement('static', null, null);

        // Q6
        $this->addSelect(
            "q6_does_subject_currently_take_any_medications",
            "6. Does SUBJECT currently take any medications?",
            self::YES_NO_OPTIONS
        );
        $this->form->addElement('text', "q6a_does_subject_currently_take_any_medications_list", 'If yes, list:');
        $this->XINRegisterRule("q6a_does_subject_currently_take_any_medications_list", array("q6_does_subject_currently_take_any_medications{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q7
        $this->addSelect("q7_has_your_child_ever_had_an_iq_test", "7. Has your child ever had an IQ test (other than in IBIS)?", self::YES_NO_OPTIONS);
	$this->form->addElement("textarea","q7a_has_your_child_ever_had_an_iq_test_when_where", $this->indent . "If yes, when and where?", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("q7a_has_your_child_ever_had_an_iq_test_when_where", array("q7_has_your_child_ever_had_an_iq_test{@}=={@}yes"), 'Required if yes');
        $this->form->addElement('text', "q7b_results_and_test_if_known", $this->indent . 'Results and test if known: IQ:');
        $this->XINRegisterRule("q7b_results_and_test_if_known", array("q7b_results_and_test_if_known{@}=={@}NEVER_REQUIRED"), 'Never Required');

        $this->form->addElement('text', "q7c_test", $this->indent . 'Test: ');
        $this->XINRegisterRule("q7c_test", array("q7c_test{@}=={@}NEVER_REQUIRED"), 'Never Required');

        $this->form->addElement('static', null, null);

        // Q8
        $this->addSelect("q8_any_specific_neurological_problems_in_subject", "8. Any specific neurological problems in SUBJECT (e.g., sleep, balance, walking)?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q8a_if_yes_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q8a_if_yes_list", array("q8_any_specific_neurological_problems_in_subject{@}=={@}yes"), 'Required if yes');

        // Q9
        $this->addSelect("q9_congenital_heart_problems_or_abnormalities_in_subject", "9. Congenital heart problems or abnormalities in SUBJECT?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "q9a_exclusionary_conditions",
            "if yes select",
            self::Q9_DEV_FACTORS_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule("q9a_exclusionary_conditions", array("q9_congenital_heart_problems_or_abnormalities_in_subject{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "q9b_other", $this->indent . 'Other:');
        $this->XINRegisterRule("q9b_other", array("q9a_exclusionary_conditions{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q10
        $this->addSelect("q10_any_problems_with_sleep_apnea_or_breathing", "10. Any problems with sleep apnea or breathing during sleep in SUBJECT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q10a_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q10a_list", array("q10_any_problems_with_sleep_apnea_or_breathing{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q11
        $this->addSelect("q11_any_gastrointestinal_condition_in_subject", "11. Any gastrointestinal condition in SUBJECT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q11a_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q11a_list", array("q11_any_gastrointestinal_condition_in_subject{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q12
        $this->addSelect("q12_did_mother_have_gestational_diabetes_while_pregnant", "12. Did mother have gestational diabetes while pregnant with SUBJECT?", self::YES_NO_NA_OPTIONS);
        $this->form->addSelect("q12a_did_gestational_diabetes_require_insulin",'12a. If yes, did gestational diabetes require insulin or medication?',self::YES_NO_OPTIONS);
        $this->XINRegisterRule("q12a_did_gestational_diabetes_require_insulin", array("q12_did_mother_have_gestational_diabetes_while_pregnant{@}=={@}yes"), 'Required if yes');
        $this->addSelect("q12b_have_diabetes", "12b. Does SUBJECT have diabetes?<h6><i>Diabetes in subject is not exclusionary.</i></h6>", self::YES_NO_OPTIONS); 
                
        $this->form->addElement('static', null, null);

        // Q13
        $this->addSelect("q13_are_you_breastfeeding_child", "13. Have you ever or are you currently breastfeeding your child?", $q13_breastfeeding_options);
        $this->form->addElement('text', "q13a_how_long_did_you_breastfeed_for", $this->indent . 'If weaned, how long did you breastfeed for?');
        $this->XINRegisterRule("q13a_how_long_did_you_breastfeed_for", array("q13_are_you_breastfeeding_child{@}=={@}weaned"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q14
        $this->addSelect("q14_exposure_to_medication_alcohol_drugs", "14. SUBJECT exposure in-utero and breastfeeding to medication, alcohol, or drugs?", self::YES_NO_OPTIONS);

        $this->q14_table(3, "q14a_sub_devfactors", "q14a_exposure_to_medication_alcohol_drugs");

        $this->form->addElement('static', null, null);

        // Q15
        $this->addSelect("q15_complications_during_pregnancy_delivery", "15. Complications during pregnancy/delivery?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "q15a_exclusionary_conditions",
            "",
            self::Q15_DEV_FACTORS_PROBAND_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule("q15a_exclusionary_conditions", array("q15_complications_during_pregnancy_delivery{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "q15b_other", $this->indent . 'Other:');
        $this->XINRegisterRule("q15b_other", array("q15a_exclusionary_conditions{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q16
        $this->addSelect("q16_method_of_delivery", "16. SUBJECT method of delivery", self::Q16_DEV_FACTORS_OPTIONS, array("multiple"));
	$this->form->addElement("textarea","q16a_other", $this->indent . "Other (explain):", array('cols'=>25, 'rows'=>4));
	$this->XINRegisterRule("q16a_other", array("q16_method_of_delivery{@}=={@}other"), 'Required if other');

        // Q17
        $this->addSelect("q17_has_subject_taken_medications_since_birth", "17. Has SUBJECT taken medications since birth?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q17a_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q17a_list", array("q17_has_subject_taken_medications_since_birth{@}=={@}yes"), 'Required if yes');

        // Q18
        $this->addSelect("q18_has_subject_ever_had_any_serious_medical", "18. Has SUBJECT ever had any serious medical or surgical problems?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q18a_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q18a_list", array("q18_has_subject_ever_had_any_serious_medical{@}=={@}yes"), 'Required if yes');

        // Q19
        $this->addSelect("q19_has_subject_ever_been_hospitalized", "19. Has SUBJECT ever been hospitalized?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q19a_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q19a_list", array("q19_has_subject_ever_been_hospitalized{@}=={@}yes"), 'Required if yes');

        // Q20
        $this->addSelect("q20_has_subject_had_any_surgery", "20. Has SUBJECT had any surgery?", self::YES_NO_OPTIONS);
	$this->form->addElement("textarea","q20a_list", $this->indent . "If yes, list with dates:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("q20a_list", array("q20_has_subject_had_any_surgery{@}=={@}yes"), 'Required if yes');

        // Q21
        $this->addSelect("q21_has_subject_seen_doctor_for_something", "21. Has SUBJECT seen doctor for something other than a well-baby visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q21a_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q21a_list", array("q21_has_subject_seen_doctor_for_something{@}=={@}yes"), 'Required if yes');

        // Q22
        $this->addSelect("q22_has_subject_ever_had_anesthesia", "22. Has SUBJECT ever had anesthesia or other forms of sedation?", self::YES_NO_OPTIONS);

        $this->form->addElement('static', null, null);


        $this->XINRegisterRule("q1_has_subject_had_any_genetic_testing_done", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q2_diagnosed_suspected_genetic_conditions", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q3_seizures_or_other_neurological_disorder", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q4_history_of_head_injury_in_subject", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q5_significant_hearing_vision_problems_in_subject", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q6_does_subject_currently_take_any_medications", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q7_has_your_child_ever_had_an_iq_test", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q8_any_specific_neurological_problems_in_subject", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q9_congenital_heart_problems_or_abnormalities_in_subject", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q10_any_problems_with_sleep_apnea_or_breathing", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q11_any_gastrointestinal_condition_in_subject", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q12_did_mother_have_gestational_diabetes_while_pregnant", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q12b_have_diabetes", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q13_are_you_breastfeeding_child", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q14_exposure_to_medication_alcohol_drugs", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q15_complications_during_pregnancy_delivery", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q16_method_of_delivery", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q17_has_subject_taken_medications_since_birth", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q18_has_subject_ever_had_any_serious_medical", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q19_has_subject_ever_been_hospitalized", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q20_has_subject_had_any_surgery", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q21_has_subject_seen_doctor_for_something", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q22_has_subject_ever_had_anesthesia", array("not_finish3{@}!={@}1"), 'Required.');

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $this->addHeader("TSI (Telephone Screening Interview ) - iDS - FOH");
        $this->addCheckbox('not_finish4', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));


        $this->form->addElement('static', null, "<h4><b>Developmental Factors in SIBLING</b></h4>");

	$this->form->addElement('date', "re_confirm_sibling_subject_dob", "<b>Re-confirm sibling subject DOB:</b>");
	$this->XINRegisterRule("re_confirm_sibling_subject_dob", array("re_confirm_sibling_subject_dob{@}=={@}"), 'Required.');

        $this->form->addElement('static', null, null);

        // Q1
        $this->addSelect("q1_has_sibling_had_any_genetic_testing_done", "1. Has SIBLING had any genetic testing done?", self::YES_NO_OPTIONS);
	$this->form->addElement("textarea","q1a_has_sibling_had_any_genetic_when_where", $this->indent . "If yes, when and where?", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("q1a_has_sibling_had_any_genetic_when_where", array("q1_has_sibling_had_any_genetic_testing_done{@}=={@}yes"), 'Required if yes');

        // Q2
        $this->addSelect("q2_diagnosed_suspected_genetic_conditions_syndromes", "2. Diagnosed/suspected genetic conditions/syndromes (other than covered on med hist form)?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q2a_diagnosed_suspected_genetic_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q2a_diagnosed_suspected_genetic_list", array("q2_diagnosed_suspected_genetic_conditions_syndromes{@}=={@}yes"), 'Required if yes');

        // Q3
        $this->form->addElement("static",null, "3. If yes to seizures on Family Medical History Form…");
        $this->form->addElement("text","q3a_how_often", $this->indent . "How often? (#/day, #/week)");
        $this->XINRegisterRule("q3a_how_often", array("q3a_how_often{@}=={@}NEVER_REQUIRED"), 'Never Required');
        $this->form->addElement('text', "q3b_are_the_seizures_under_control", $this->indent . "Are the seizures under control (i.e., stable)?");
        $this->XINRegisterRule("q3b_are_the_seizures_under_control", array("q3b_are_the_seizures_under_control{@}=={@}NEVER_REQUIRED"), 'Never Required');
        $this->form->addElement("text","q3c_medication_for_seizures", $this->indent . "Medication for seizures (& dosage)");
        $this->XINRegisterRule("q3c_medication_for_seizures", array("q3c_medication_for_seizures{@}=={@}NEVER_REQUIRED"), 'Never Required');
        $this->form->addElement("text","q3d_last_time_medication_dosage_was_changed", $this->indent . "Last time medication/dosage was changed");
        $this->XINRegisterRule("q3d_last_time_medication_dosage_was_changed", array("q3d_last_time_medication_dosage_was_changed{@}=={@}NEVER_REQUIRED"), 'Never Required');

        // Q4
        $this->addSelect("q4_significant_vision_problems_in_sibling", "4. Significant vision problems in SIBLING?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q4a_significant_vision_problems_in_sibling_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q4a_significant_vision_problems_in_sibling_list", array("q4_significant_vision_problems_in_sibling{@}=={@}yes"), 'Required if yes');

        // Q5
        $this->addSelect("q5_does_sibling_currently_take_any_medications", "5. Does SIBLING currently take any medications?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "q5a_does_sibling_currently_take_any_medications_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("q5a_does_sibling_currently_take_any_medications_list", array("q5_does_sibling_currently_take_any_medications{@}=={@}yes"), 'Required if yes');

        // Q6
        $this->addSelect("q6_has_siblin_ever_had_an_iq_test", "6. Has SIBLING ever had an IQ test (or developmental assessment)?", self::YES_NO_OPTIONS);
	$this->form->addElement("textarea","q6a_has_siblin_ever_had_an_iq_test_when_where", $this->indent .  "If yes, when and where?", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("q6a_has_siblin_ever_had_an_iq_test_when_where", array("q6_has_siblin_ever_had_an_iq_test{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "q6b_results_and_test_if_known", $this->indent . 'Results and test if known: IQ:');
        $this->XINRegisterRule("q6b_results_and_test_if_known", array("q6b_results_and_test_if_known{@}=={@}NEVER_REQUIRED"), 'Never Required');

        $this->form->addElement('text', "q6c_test", $this->indent . 'Test: ');
        $this->XINRegisterRule("q6c_test", array("q6c_test{@}=={@}NEVER_REQUIRED"), 'Never Required');

        $this->form->addElement('static', null, null);

        $this->XINRegisterRule("re_confirm_sibling_subject_dob", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q1_has_sibling_had_any_genetic_testing_done", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q2_diagnosed_suspected_genetic_conditions_syndromes", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q4_significant_vision_problems_in_sibling", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q5_does_sibling_currently_take_any_medications", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q6_has_siblin_ever_had_an_iq_test", array("not_finish4{@}!={@}1"), 'Required.');
        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    function q14_table($page_number, $section_name, $parent_question)
    {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Name of substance/medication"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "1st Trimester"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "2nd Trimester"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "3rd Trimester"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Breastfeeding"
        );
        $this->addGroup(
            $group,
            "page" . $page_number . "_q14_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1;$i<6;$i++) {
            $group[] =& $this->form->createElement('text', $section_name ."_" . $i);

            $group[] =& $this->createSelect(
                $section_name . "_q14_{$i}_1st_trimester",
                "First Trimester",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                $section_name . "_q14_{$i}_2nd_trimester",
                "Second Trimester",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                $section_name . "_q14_{$i}_3rd_trimester",
                "Third Trimester",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                $section_name . "_q14_{$i}_breastfeeding",
                "Breastfeeding",
                self::YES_NO_OPTIONS
            );

            $this->XINRegisterRule("{$section_name}_{$i}", array("{$section_name}_{$i}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("{$section_name}_q14_{$i}_1st_trimester", array("{$section_name}_q14_{$i}_1st_trimester{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("{$section_name}_q14_{$i}_2nd_trimester", array("{$section_name}_q14_{$i}_2nd_trimester{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("{$section_name}_q14_{$i}_3rd_trimester", array("{$section_name}_q14_{$i}_3rd_trimester{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("{$section_name}_q14_{$i}_breastfeeding", array("{$section_name}_q14_{$i}_breastfeeding{@}=={@}NEVER_REQUIRED"));
            $this->addGroup(
                $group,
                $section_name . "_" . $i . "_q14_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);    
        }
    }

    function validate_page1($values)
    {
        $errors = [];
        
    if ($values["not_finish0"]!="1"){
        $this->validate_positive_numeric($values, "subject_birth_weight_lbs", $errors);
        $this->validate_positive_numeric($values, "subject_birth_weight_oz", $errors);
        $this->validate_positive_numeric($values, "subject_how_many_weeks_gestation", $errors);

        $this->validate_positive_numeric($values, "current_weight_lbs", $errors);
        $this->validate_positive_numeric($values, "current_height_in", $errors);
        $this->validate_positive_numeric($values, "current_age_mon", $errors);
        $this->validate_positive_numeric($values, "current_age_year", $errors);

        if ($values["are_bio_parents_living_in_same_home"] != "no") {
            $this->validate_empty_subquestions($values, ["if_not_in_same_home_childs_primary_address_with"], $errors);
        }
     }    
        return $errors;
    }


    function validate_page3($values)
    {
        $errors = [];

        if ($values["q1_has_subject_had_any_genetic_testing_done"] != "yes") {
            $this->validate_empty_subquestions($values, ["q1a_subject_had_testing_done_when_where"], $errors);
        }

        if ($values["q2_diagnosed_suspected_genetic_conditions"] != "yes") {
            $this->validate_empty_subquestions($values, ["q2a_diagnosed_suspected_genetic_conditions_list"], $errors);
        }
        if ($values["q3_seizures_or_other_neurological_disorder"] != "yes") {
            $this->validate_empty_subquestions($values, ["q3a_seizures_or_other_neurological_disorder_how_often"], $errors);
            $this->validate_empty_subquestions($values, ["q3b_are_the_seizures_under_control"], $errors);
            $this->validate_empty_subquestions($values, ["q3c_medication_for_seizures"], $errors);
            $this->validate_empty_subquestions($values, ["q3d_last_time_medication_dosage_was_changed"], $errors);
        }
        if ($values["q5_significant_hearing_vision_problems_in_subject"] != "yes") {
            $this->validate_empty_subquestions($values, ["q5a_significant_hearing_vision_problems_in_subject_lists"], $errors);
            $this->validate_empty_subquestions($values, ["q5b_bilateral_sensorineural_hearing_loss"], $errors);
        }
        if ($values["q6_does_subject_currently_take_any_medications"] != "yes") {
            $this->validate_empty_subquestions($values, ["q6a_does_subject_currently_take_any_medications_list"], $errors);
        }
        if ($values["q7_has_your_child_ever_had_an_iq_test"] != "other") {
            $this->validate_empty_subquestions($values, ["q7a_has_your_child_ever_had_an_iq_test_when_where"], $errors);
            $this->validate_empty_subquestions($values, ["q7b_results_and_test_if_known"], $errors);
            $this->validate_empty_subquestions($values, ["q7c_test"], $errors);
        }
        if ($values["q8_any_specific_neurological_problems_in_subject"] != "other") {
            $this->validate_empty_subquestions($values, ["q8a_if_yes_list"], $errors);
        }
        if ($values["q10_any_problems_with_sleep_apnea_or_breathing"] != "yes") {
            $this->validate_empty_subquestions($values, ["q10a_list"], $errors);
        } 
        if ($values["q11_any_gastrointestinal_condition_in_subject"] != "yes") {
            $this->validate_empty_subquestions($values, ["q11a_list"], $errors);
        }
        if ($values["q12_did_mother_have_gestational_diabetes_while_pregnant"] != "yes") {
            $this->validate_empty_subquestions($values, ["q12a_did_gestational_diabetes_require_insulin"], $errors);
        }
        if ($values["q16_method_of_delivery"] != "other") {
            $this->validate_empty_subquestions($values, ["q16a_other"], $errors);
        }
        if ($values["q13_are_you_breastfeeding_child"] != "weaned") {
            $this->validate_empty_subquestions($values, ["q13a_how_long_did_you_breastfeed_for"], $errors);
        }
        if ($values["q17_has_subject_taken_medications_since_birth"] != "yes") {
            $this->validate_empty_subquestions($values, ["q17a_list"], $errors);
        }
        if ($values["q18_has_subject_ever_had_any_serious_medical"] != "yes") {
            $this->validate_empty_subquestions($values, ["q18a_list"], $errors);
        }
        if ($values["q19_has_subject_ever_been_hospitalized"] != "yes") {
            $this->validate_empty_subquestions($values, ["q19a_list"], $errors);
        }
        if ($values["q20_has_subject_had_any_surgery"] != "yes") {
            $this->validate_empty_subquestions($values, ["q20a_list"], $errors);
        }
        if ($values["q21_has_subject_seen_doctor_for_something"] != "yes") {
            $this->validate_empty_subquestions($values, ["q21a_list"], $errors);
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        if ($values["q1_has_sibling_had_any_genetic_testing_done"] != "yes") {
            $this->validate_empty_subquestions($values, ["q1a_has_sibling_had_any_genetic_when_where"], $errors);
        }
        
        if ($values["q2_diagnosed_suspected_genetic_conditions_syndromes"] != "yes") {
            $this->validate_empty_subquestions($values, ["q2a_diagnosed_suspected_genetic_list"], $errors);
        }
        
        if ($values["q4_significant_vision_problems_in_sibling"] != "yes") {
            $this->validate_empty_subquestions($values, ["q4a_significant_vision_problems_in_sibling_list"], $errors);
        }
        
        if ($values["q5_does_sibling_currently_take_any_medications"] != "yes") {
            $this->validate_empty_subquestions($values, ["q5a_does_sibling_currently_take_any_medications_list"], $errors);
        }
        
        if ($values["q6_has_siblin_ever_had_an_iq_test"] != "yes") {
            $this->validate_empty_subquestions($values, ["q6a_has_siblin_ever_had_an_iq_test_when_where"], $errors);
        }
        if ($values["q6_has_siblin_ever_had_an_iq_test"] != "yes") {
            $this->validate_empty_subquestions($values, ["q6a_has_siblin_ever_had_an_iq_test_when_where"], $errors);
            $this->validate_empty_subquestions($values, ["q6b_results_and_test_if_known"], $errors);
            $this->validate_empty_subquestions($values, ["q6c_test"], $errors);
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
    function _save(array $values): void
    {  
       for($i=0;$i<=4;$i++){
            $checkbox= "not_finish".$i;
            if (!isset($values["$checkbox"])) {
                $values["$checkbox"] = '0';
            }
       } 
        parent::_save($values);
    }
}
?>
