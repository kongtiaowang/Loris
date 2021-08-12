<?php
/**
 * This file contains the NDB_BVL_Instrument_TSI_EP class
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
 * Creates the form elements for the IBIS EP - Telephone Screening Interview
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_TSI_EP extends NDB_BVL_Instrument
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

    const HOUSEHOLD_SES_OPTIONS = array(
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

    const IN_UTERO_AND_BREASTFEEDING_OPTIONS = array(
                                                null            => '',
                                                "1st_trimester" => "1st Trimester",
                                                "2nd_trimester" => "2nd Trimester",
                                                "3rd_trimester" => "3rd Trimester",
                                                "breastfeeding" => "Breastfeeding",
                                                "not_answered"  => "Not Answered",
                                               );

    const Q5_MED_HIST_PROBAND_OPTIONS = array(
                                         null                         => '',
                                         "arachnoid_cyst"             => "Arachnoid Cyst",
                                         "cat_i_chiari_malformation"  => "Cat I chiari malformation",
                                         "cat_ii_chiari_malformation" => "Cat II chiari malformation",
                                         "nasal_dermoid_cyst"         => "Nasal Dermoid Cyst",
                                         "other"                      => "Other",
                                        );

    const Q9_MED_HIST_INFANT_OPTIONS = array(
                                        null                         => '',
                                        "arachnoid_cyst"             => "Arachnoid Cyst",
                                        "cat_i_chiari_malformation"  => "Cat I chiari malformation",
                                        "cat_ii_chiari_malformation" => "Cat II chiari malformation",
                                        "nasal_dermoid_cyst"         => "Nasal Dermoid Cyst",
                                       );

    const Q5_DEV_FACTORS_OPTIONS = array(
                                    null                                    => '',
                                    "choreoathetosis"                       => "Choreoathetosis",
                                    "encephalitis"                          => "Encephalitis",
                                    "family_history_of_huntingtons_disease" => "Family history of Huntington’s disease",
                                    "meningitis"                            => "Meningitis",
                                    "joubert_syndrome"                      => "Joubert syndrome",
                                    "landau_kleffner"                       => "Landau Kleffner",
                                    "other"                                 => "Other",
                                   );

    const Q6_DEV_FACTORS_OPTIONS = array(
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

    const Q12_DEV_FACTORS_TABLE = array(
                                   "alcohol"                         => "Alcohol (>2 drinks/day regularly or 1 instance of >4 drinks is exclusionary)",
                                   "smoking_vaping"                  => "Smoking/vaping",
                                   "cannabis_illicit_drugs"          => "Cannabis/illicit drugs",
                                   "prenatal_vitamins"               => "Prenatal vitamins",
                                   "herbal_other"                    => "Herbal/other",
                                   "cold_allergy_medicine"           => "Cold medicine/allergy medicine", // specify
                                   "antibiotics"                     => "Antibiotics (e.g. Cipro, Diflucan, etc.)", // type, dose
                                   "antidepressants"                 => "Antidepressants",// type, dose
                                   "mood_stabilizer_anti_psychotics" => "Mood stabilizer or anti-psychotics",// type, dose
                                   "otc_1"                           => "OTC/prescription/dose",// specify
                                   "otc_2"                           => "OTC/prescription/dose",// specify
                                   "otc_3"                           => "OTC/prescription/dose",// specify
                                   "otc_4"                           => "OTC/prescription/dose",// specify
                                  );

    const Q13_DEV_FACTORS_PROBAND_OPTIONS = array(
                                             null                                                   => '',
                                             "benign_kidney_enlargement"                            => "Benign kidney enlargement",
                                             "cancer"                                               => "Cancer",
                                             "cytomegalovirus_CMV_infection"                        => "Cytomegalovirus CMV infection",
                                             "gestational_diabetes_requiring_insulin_or_medication" => "Gestational diabetes requiring insulin or medication",
                                             "herpes_while_pregnant_and_infant_delivered_vaginally" => "Herpes while pregnant and infant delivered vaginally",
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
                                             "vacuum_extraction"                                    => "Vacuum extraction",
                                             "other"                                                => "Other",
                                            );

    const Q14_DEV_FACTORS_OPTIONS = array(
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
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('TSI_EP', "Telephone Screening Interview - EP", 1, 0);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page5', "Page 5", 5);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page6', "Page 6", 6);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_EP','TSI_EP_page7', "Page 7", 7);
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
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('TSI_EP_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "TSI_EP";           // test_names.Test_name
        $this->table    = 'TSI_EP';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array(
                                          "pro_devfactors_q1_exclusionary_conditions",
                                          "pro_devfactors_q5_exclusionary_conditions",
                                          "pro_devfactors_q6_exclusionary_conditions",
                                          "pro_devfactors_q14_method_of_delivery",
                                          "pro_medhist_q5_results",
                                          "inf_devfactors_q1_exclusionary_conditions",
                                          "inf_devfactors_q5_exclusionary_conditions",
                                          "inf_devfactors_q6_exclusionary_conditions",
                                          "inf_devfactors_q14_method_of_delivery",
                                          "inf_medhist_q1_exclusionary_conditions",
                                          "inf_medhist_q6_metal_options",
                                          "inf_medhist_q9_results",
                                          "candidate_race",
                                          "bio_mother_race",
                                          "bio_father_race",
                                         );

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "subject_dob",
                                    "proband_dob2",
                                    "pro_devfactors_q1_specific_neurological_problems",
                                    "pro_medhist_q1_had_serious_medical_or_surgical_problems",
                                    "inf_devfactors_q1_specific_neurological_problems",
                                    "inf_medhist_q1_had_serious_medical_or_surgical_problems",
                                    "candidate_race",
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
        if (preg_match("/TSI_EP(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("Telephone Screening Interview - EP");
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

        $this->addBasicDate('date_of_first_contact', 'Date of First Contact (1st time speak with the family)', $dateOptions);

        $this->form->addElement('text', null, "City/State of Birth", ['disabled' => 'disabled']);
        $this->XINRegisterRule("date_of_first_contact", array("not_finish0{@}!={@}1"), 'Required.');

    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish1', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, '<h4><i>*Identifying information should not be entered in the database</i></h4>');

        $this->form->addElement('static', null, '<h4><b>CONTACT INFORMATION</b></h4>');

        $pii_contact = array(
                        "First Name",
                        "Middle Name",
                        "Last Name",
                        "Maiden Name",
                        "Email Address",
                        "Cell Phone",
                        "Home Phone",
                        "Work Phone",
                        "Date of Birth",
                       );

        $page1_questions = array(
                            "is_english_primary_language_spoken_in_home" => "Is English the primary language spoken in the home?<h6><i>English <b>must</b> be primary language spoken in the home.</i></h6>",
                            "are_infant_and_or_proband_adopted"          => "Are the infant and/or proband adopted?<h6><i>Adopted <b>AND</b> no family history of the subject.</i></h6>",
                            "is_infant_a_multiple"                       => "Is infant a multiple (i.e. twin or triplet)?<h6><i>Multiple births (twin, triplet) are excluded from the study.</i></h6>",
                            "is_proband_a_multiple"                      => "Is the proband a multiple (i.e. twin or triplet)?<h6><i>Multiple births (twin, triplet) are excluded from the study.</i></h6>",
                            "are_bio_parents_living_in_same_home"        => "Are biological parents living in the same home?",
                            "are_parents_divorced_or_separated"          => "Are parents divorced or separated?",
                           );

        $pii_address = array(
                        "Street Address",
                        "City",
                        "State",
                        "Zip Code",
                       );

        // SUBJECT INFORMATION
        $this->form->addElement('static', null, "SUBJECT<h6><i>Exclude if born less < 36 or > 42.5 weeks gestation or birth weight < 2000g (4lbs 4oz).</i></h6>");

        $this->form->addElement('text', null, $this->indent . "First Name", ['disabled' => 'disabled']);
        $this->form->addElement('text', null, $this->indent . "Middle Name", ['disabled' => 'disabled']);
        $this->form->addElement('text', null, $this->indent . "Last Name", ['disabled' => 'disabled']);

        $this->addBasicDate("subject_dob", $this->indent . 'Date of Birth', $this->dateOptions);
        $this->addBasicDate("subject_expected_due_date", $this->indent . 'Expected Due Date', $this->dateOptions);


        $this->form->addElement('text', "subject_birth_weight_lbs", $this->indent . "Birth weight (lbs)");
        $this->form->addElement('text', "subject_birth_weight_oz", $this->indent . "Birth weight (oz)");

        $this->addSelect("subject_gender", $this->indent . "Gender", self::GENDER_OPTIONS);

        $this->addSelect("subject_premature", $this->indent . "Was infant premature?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "subject_how_many_weeks_gestation", $this->indent . "Born at how many weeks of gestation?");

        // V06 OPTIMAL WINDOW (-1 weeks/+3 weeks)
        $this->form->addElement('static', null, $this->indent . "V06 OPTIMAL WINDOW (-1 weeks/+3 weeks)");
        $this->addBasicDate("v06_optimal_window_lower", $this->indent . $this->indent . '-1 weeks', $this->dateOptions);
        $this->addBasicDate("v06_optimal_window_upper", $this->indent . $this->indent . '+3 weeks', $this->dateOptions);

        // V06 PERMITTED WINDOW (-2 weeks/+12 weeks)
        $this->form->addElement('static', null, $this->indent . "V06 PERMITTED WINDOW (-2 weeks/+12 weeks)");
        $this->addBasicDate("v06_permitted_window_lower", $this->indent . $this->indent . '-2 weeks', $this->dateOptions);
        $this->addBasicDate("v06_permitted_window_upper", $this->indent . $this->indent . '+12 weeks', $this->dateOptions);

        // V12 OPTIMAL WINDOW (-1 weeks/+3 weeks)
        $this->form->addElement('static', null, $this->indent . "V12 OPTIMAL WINDOW (-1 weeks/+3 weeks)");
        $this->addBasicDate("v12_optimal_window_lower", $this->indent . $this->indent . '-1 weeks', $this->dateOptions);
        $this->addBasicDate("v12_optimal_window_upper", $this->indent . $this->indent . '+3 weeks', $this->dateOptions);

        // V12 PERMITTED WINDOW (-4 weeks/+8 weeks)
        $this->form->addElement('static', null, $this->indent . "V12 PERMITTED WINDOW (-4 weeks/+8 weeks)");
        $this->addBasicDate("v12_permitted_window_lower", $this->indent . $this->indent . '-4 weeks', $this->dateOptions);
        $this->addBasicDate("v12_permitted_window_upper", $this->indent . $this->indent . '+8 weeks', $this->dateOptions);

        // V24 OPTIMAL WINDOW (-1 weeks/+3 weeks)
        $this->form->addElement('static', null, $this->indent . "V24 OPTIMAL WINDOW (-1 weeks/+3 weeks)");
        $this->addBasicDate("v24_optimal_window_lower", $this->indent . $this->indent . '-1 weeks', $this->dateOptions);
        $this->addBasicDate("v24_optimal_window_upper", $this->indent . $this->indent . '+3 weeks', $this->dateOptions);

        // V24 PERMITTED WINDOW (-4 weeks/+8 weeks)
        $this->form->addElement('static', null, $this->indent . "V24 PERMITTED WINDOW (-4 weeks/+8 weeks)");
        $this->addBasicDate("v24_permitted_window_lower", $this->indent . $this->indent . '-4 weeks', $this->dateOptions);
        $this->addBasicDate("v24_permitted_window_upper", $this->indent . $this->indent . '+8 weeks', $this->dateOptions);

        $this->form->addElement('static', null, null);

        // PROBAND DEFINITION
        $this->form->addElement('static', null, "Proband is the next oldest full sibling with ASD diagnosis. If next oldest sibling fails to meet criteria on m-CHAT or SCQ, go to next oldest affected sibling or most severely affected sibling to use as proband.");

        $this->form->addElement('static', null, null);

        // PROBAND INFORMATION
        $this->form->addElement('static', null, "PROBAND<h6><i>Exclude if born less < 35 or > 42.5 weeks gestation or birth weight < 2000g (4lbs 4oz).</i></h6>");

        $this->form->addElement('text', null, $this->indent . "First Name", ['disabled' => 'disabled']);
        $this->form->addElement('text', null, $this->indent . "Middle Name", ['disabled' => 'disabled']);
        $this->form->addElement('text', null, $this->indent . "Last Name", ['disabled' => 'disabled']);

        $this->addBasicDate("proband_dob", $this->indent . 'Date of Birth', $this->dateOptions);
        $this->form->addElement('text', null, $this->indent . "City of Birth", ['disabled' => 'disabled']);

        $this->form->addElement('text', "proband_birth_weight_lbs", $this->indent . "Birth weight (lbs)");
        $this->form->addElement('text', "proband_birth_weight_oz", $this->indent . "Birth weight (oz)");

        $this->addSelect("proband_gender", $this->indent . "Gender", self::GENDER_OPTIONS);

        $this->addSelect("proband_premature", $this->indent . "Was proband premature?", self::YES_NO_OPTIONS);

        $this->form->addElement('text', "proband_how_many_weeks_gestation", $this->indent . "Born at how many weeks of gestation?");

        $this->addSelect("proband_infant_full_siblings", $this->indent . "Are the proband and infant full siblings?", self::YES_NO_OPTIONS);

        $this->form->addElement('text', "when_diagnosed_with_autism", $this->indent . 'When were they diagnosed with autism?');
        $this->form->addElement('text', "diagnosed_with_autism_by", $this->indent . $this->indent . "By whom?");

        $this->form->addElement('static', null, "<i>If proband is 31 months or older, administer SCQ. If 30 months or younger, administer m-CHAT.</i>");

        $this->form->addElement('static', null, null);

        // BIOLOGICAL MOTHER INFORMATION
        $this->form->addElement('static', null, "BIOLOGICAL MOTHER");

        foreach ($pii_contact as $field) {
            if ($field == "Date of Birth") {
                $this->addDateElement("mother_dob", $this->indent . $field);
            } else {
                $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
            }
        }
        $this->XINRegisterRule("mother_dob_date", array("mother_dob_date{@}=={@}never_required"), 'Not Required.');

        $this->addTextElement("mother_occupation", $this->indent . "Occupation");
        $this->addSelect("mother_education", $this->indent . "Education", self::EDUCATION_OPTIONS);
        $this->XINRegisterRule("mother_occupation", array("mother_occupation{@}=={@}never_required"), 'Not Required.');

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
        $this->XINRegisterRule("father_dob_date", array("father_dob_date{@}=={@}never_required"), 'Not Required.');

        $this->addTextElement("father_occupation", $this->indent . "Occupation");
        $this->XINRegisterRule("father_occupation", array("father_occupation{@}=={@}never_required"), 'Not Required.');

        $this->addSelect("father_education", $this->indent . "Education", self::EDUCATION_OPTIONS);

        $this->form->addElement('static', null, null);

        foreach ($page1_questions as $field => $label) {
            $this->addSelect($field, $label, self::YES_NO_OPTIONS);

            if ($field == "are_bio_parents_living_in_same_home") {
                $this->addSelect("if_not_in_same_home_childs_primary_address_with", $this->indent . "If biological parents not in the same home, child’s primary address is with", array(null => "", "mother" => "Mother", "father" => "Father"));
                $this->XINRegisterRule("if_not_in_same_home_childs_primary_address_with", array("are_bio_parents_living_in_same_home{@}=={@}no"), 'Required if no');
            }
        }

        $this->form->addElement('static', null, null);

        // CHILD PRIMARY ADDRESS
        $this->form->addElement('static', null, "CHILD PRIMARY ADDRESS");

        foreach ($pii_address as $field) {
            $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
        }

        $this->form->addElement('static', null, null);

        // SECONDARY ADDRESS
        $this->form->addElement('static', null, "SECONDARY ADDRESS<br>(if 2 households)");

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
        $this->addTextAreaElement("additional_info_about_childs_home", "Additional information about child’s home:");
        $this->XINRegisterRule("subject_dob", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_expected_due_date", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_birth_weight_lbs", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_birth_weight_oz", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_gender", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_premature", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("subject_how_many_weeks_gestation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v06_optimal_window_lower", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v06_optimal_window_upper", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v06_permitted_window_lower", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v06_permitted_window_upper", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v12_optimal_window_lower", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v12_optimal_window_upper", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v12_permitted_window_lower", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v12_permitted_window_upper", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v24_optimal_window_lower", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v24_optimal_window_upper", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v24_permitted_window_lower", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("v24_permitted_window_upper", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_dob", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_birth_weight_lbs", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_birth_weight_oz", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_gender", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_premature", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_how_many_weeks_gestation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_infant_full_siblings", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("when_diagnosed_with_autism", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("diagnosed_with_autism_by", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("mother_dob_date", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("mother_occupation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("mother_education", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("father_dob_date", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("father_occupation", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("father_education", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("is_english_primary_language_spoken_in_home", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("are_infant_and_or_proband_adopted", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("is_infant_a_multiple", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("is_proband_a_multiple", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("are_bio_parents_living_in_same_home", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("are_parents_divorced_or_separated", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("relationship_to_family", array("not_finish1{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("additional_info_about_childs_home", array("not_finish1{@}!={@}1"), 'Required.');
        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish2', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, '<h4><i>*Identifying information should not be entered in the database</i></h4>');

        $this->form->addElement('static', null, "<h4><b>List PROBAND followed by additional siblings from oldest to youngest.</b></h4>");

        $sibling_options = array(
                            null      => '',
                            "half"    => "Half",
                            "full"    => "Full",
                            "step"    => "Step",
                            "adopted" => "Adopted",
                           );

        // PROBAND
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Proband First Name"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Proband Last Name"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Proband DOB"
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
            "Proband must have Autism"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Proband must be full sibling"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Live in home?"
        );
        $this->addGroup(
            $group,
            "page2_proband_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

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
            "proband_dob2",
            ""
        );
        $group[] =& $this->createSelect(
            "proband_gender2",
            "M/F",
            self::GENDER_OPTIONS
        );
        $group[] =& $this->createText(
            null,
            "",
            ['disabled' => 'disabled']
        );
        $group[] =& $this->createSelect(
            null,
            "Half/full/step/adopted",
            $sibling_options,
            ['disabled' => 'disabled']
        );
        $group[] =& $this->createSelect(
            "proband_live_in_home",
            "Live in home?",
            self::YES_NO_OPTIONS
        );

        $this->addGroup(
            $group,
            "proband_group",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $this->form->addElement('static', null, null);

        // PROBAND'S SIBLINGS
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

        $this->addTextAreaElement("how_did_you_find_out_about_the_study", "How did you find out about the study?");

        $this->XINRegisterRule("proband_dob2", array("not_finish2{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_gender2", array("not_finish2{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("proband_live_in_home", array("not_finish2{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("enrolled_in_other_studies_or_registries", array("not_finish2{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("how_did_you_find_out_about_the_study", array("not_finish2{@}!={@}1"), 'Required.');

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish3', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->form->addElement('static', null, "<h4><b>Development Factors in PROBAND</b></h4>");

        $this->form->addElement('static', null, null);

        $q1_exclusionary_options = array(
                                    null                                => "",
                                    "cerebral_palsy"                    => "Cerebral palsy",
                                    "cleft_palate"                      => "Cleft palate",
                                    "craniosynostosis"                  => "Craniosynostosis",
                                    "epilepsy"                          => "Epilepsy (not exclusionary in PROBAND)",
                                    "facial_abnormalities"              => "Facial abnormalities (cleft ear or cleft palate)",
                                    "hydrocephaly"                      => "Hydrocephaly",
                                    "family_history_of_marfan_syndrome" => "Family history of Marfan syndrome",
                                    "marfan_syndrome"                   => "Marfan syndrome",
                                    "muscular_dystrophy"                => "Muscular dystrophy",
                                    "mytonic_dystrophy"                 => "Mytonic dystrophy",
                                    "neural_tube_defect"                => "Neural tube defect",
                                    "neurofibromatosis"                 => "Neurofibromatosis",
                                    "spina_bifida"                      => "Spina bifida",
                                    "stroke"                            => "Stroke",
                                    "sturge_weber_syndrome"             => "Sturge Weber syndrome",
                                    "tuberous_sclerosis"                => "Tuberous sclerosis",
                                    "family_history_of_turner_syndrome" => "Family history of Turner syndrome",
                                    "family_history_of_soto_syndrome"   => "Family history of Soto syndrome",
                                    "vater_syndrome"                    => "Vater syndrome",
                                    "family_history_of_vater_syndrome"  => "Family history of Vater syndrome",
                                    "von_willebrands_disease"           => "Von Willebrand’s Disease",
                                    "williams_syndrome"                 => "William’s syndrome",
                                    "other"                             => "Other",
                                   );

        $q2_exclusionary_options = array(
                                    null                           => "",
                                    "chromosome_15q11_13_deletion" => "Chromosome 15q11-13 deletion",
                                    "fragile_x"                    => "Fragile X",
                                   );

        $q4_non_exclusionary_options = array(
                                        null               => "",
                                        "febrile_seizures" => "Febrile seizures (not exclusionary)",
                                       );

        $q7_exclusionary_options = array(
                                    null                                   => "",
                                    "bilateral_sensorineural_hearing_loss" => "Bilateral sensorineural hearing loss",
                                   );

        // Q1
        $this->addSelect("pro_devfactors_q1_specific_neurological_problems", "1. Any specific neurological problems in PROBAND?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "pro_devfactors_q1_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted. Please review most recent version of exclusionary list.
            Any additional neurological problems reported by family should be reviewed by exclusionary committee.
            Email concerns to botteronk@wustl.edu and cc:\ flakel@wustl.edu and terescook-guercio@wustl.edu.</i></h6>",
            $q1_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule("pro_devfactors_q1_exclusionary_conditions", array("pro_devfactors_q1_specific_neurological_problems{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "pro_devfactors_q1_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_devfactors_q1_other", array("pro_devfactors_q1_exclusionary_conditions{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q2
        $this->addSelect("pro_devfactors_q2_diagnosed_suspected_genetic_conditions", "2. Diagnosed/suspected genetic conditions in PROBAND?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_devfactors_q2_list", $this->indent . 'If yes, list:<h6>(send to exclusionary committee for review)</h6>');
        $this->XINRegisterRule("pro_devfactors_q2_list", array("pro_devfactors_q2_diagnosed_suspected_genetic_conditions{@}=={@}yes"), 'Required if yes');

        $this->addSelect(
            "pro_devfactors_q2_exclusionary_conditions",
            "",
            $q2_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "pro_devfactors_q2_exclusionary_conditions",
            array("pro_devfactors_q2_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement('static', null, null);

        // Q2A
        $this->addSelect("pro_devfactors_q2a_family_history_of_genetic_disorders", "2a. Family history of genetic disorders?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_devfactors_q2a_list", $this->indent . 'If yes, list:<h6>(send to exclusionary committee for review)</h6>');
        $this->XINRegisterRule("pro_devfactors_q2a_list", array("pro_devfactors_q2a_family_history_of_genetic_disorders{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q3
        $this->addSelect("pro_devfactors_q3_genetic_testing_completed", "3. Genetic testing completed on PROBAND?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_devfactors_q3_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("pro_devfactors_q3_list", array("pro_devfactors_q3_genetic_testing_completed{@}=={@}yes"), 'Required if yes');
        $this->form->addElement('text', "pro_devfactors_q3_by_who", $this->indent . 'By who:');
        $this->XINRegisterRule("pro_devfactors_q3_by_who", array("pro_devfactors_q3_genetic_testing_completed{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q4
        $this->addSelect("pro_devfactors_q4_history_of_seizures", "4. History of seizures in PROBAND?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_devfactors_q4_list", $this->indent . 'If yes, list:<h6>(send to exclusionary committee for review)</h6>');
        $this->XINRegisterRule("pro_devfactors_q4_list", array("pro_devfactors_q4_history_of_seizures{@}=={@}yes"), 'Required if yes');

        $this->addSelect(
            "pro_devfactors_q4_non_exclusionary_conditions",
            "",
            $q4_non_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "pro_devfactors_q4_non_exclusionary_conditions",
            array("pro_devfactors_q4_non_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement('static', null, null);

        // Q5
        $this->addSelect("pro_devfactors_q5_central_nervous_system_problems", "5. Central nervous system problems in PROBAND?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "pro_devfactors_q5_exclusionary_conditions",
            "<h6><i>Conditions are exclusionary unless otherwise noted.</i></h6>",
            self::Q5_DEV_FACTORS_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule("pro_devfactors_q5_exclusionary_conditions", array("pro_devfactors_q5_central_nervous_system_problems{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "pro_devfactors_q5_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_devfactors_q5_other", array("pro_devfactors_q5_central_nervous_system_problems{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q5A
        $this->addSelect("pro_devfactors_q5a_head_injury", "5a. Head injury in PROBAND?<h6><i>(Send details to exclusionary committee for review – loss of consciousness, finding on any scan completed)</i></h6>", self::YES_NO_OPTIONS);

        $this->form->addElement('static', null, null);

        // Q6
        $this->addSelect("pro_devfactors_q6_congenital_heart_problems_abnormalities", "6. Congenital heart problems or abnormalities in PROBAND?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "pro_devfactors_q6_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted.</i></h6>",
            self::Q6_DEV_FACTORS_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule("pro_devfactors_q6_exclusionary_conditions", array("pro_devfactors_q6_congenital_heart_problems_abnormalities{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "pro_devfactors_q6_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_devfactors_q6_other", array("pro_devfactors_q6_exclusionary_conditions{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q7
        $this->addSelect("pro_devfactors_q7_significant_hearing_vision_problems", "7. Significant Hearing/Vision problems in PROBAND?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_devfactors_q7_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("pro_devfactors_q7_list", array("pro_devfactors_q7_significant_hearing_vision_problems{@}=={@}yes"), 'Required if yes');

        $this->addSelect(
            "pro_devfactors_q7_exclusionary_conditions",
            "",
            $q7_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "pro_devfactors_q7_exclusionary_conditions",
            array("pro_devfactors_q7_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement('static', null, null);

        // Q8
        $this->addSelect("pro_devfactors_q8_mother_gestational_diabetes", "8. Did mother have gestational diabetes while pregnant with PROBAND?<h6><i>Gestational diabetes requiring insulin or medication is exclusionary.</i></h6>", self::YES_NO_OPTIONS);

        $this->form->addElement('static', null, null);

        // Q8A
        $this->addSelect("pro_devfactors_q8a_if_yes_did_require_insulin_or_medication", "8a. If yes, did gestational diabetes require insulin or medication?", self::YES_NO_NA_OPTIONS);
        $this->XINRegisterRule("pro_devfactors_q8a_if_yes_did_require_insulin_or_medication", array("pro_devfactors_q8_mother_gestational_diabetes{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q8B
        $this->addSelect("pro_devfactors_q8b_have_diabetes", "8b. Does PROBAND have diabetes?<h6><i>Diabetes in infant is exclusionary.</i></h6>", self::YES_NO_OPTIONS);

        $this->form->addElement('static', null, null);

        // Q11A
        $this->addSelect("pro_devfactors_q11a_did_you_breastfeed", "11a. Did you breastfeed PROBAND?", self::YES_NO_OPTIONS);

        $this->form->addElement('static', null, null);

        // Q11B
        $this->form->addElement('static', null, "11b. If so, how long did you breastfeed proband?");

        $this->form->addElement('text', "pro_devfactors_q11b_how_long_breastfeed_weeks", $this->indent . 'Weeks');
        $this->form->addElement('text', "pro_devfactors_q11b_how_long_breastfeed_months", $this->indent . 'Months');

        $this->XINRegisterRule("pro_devfactors_q11b_how_long_breastfeed_weeks", array("pro_devfactors_q11a_did_you_breastfeed{@}=={@}yes"), 'Required if yes');
        $this->XINRegisterRule("pro_devfactors_q11b_how_long_breastfeed_months", array("pro_devfactors_q11a_did_you_breastfeed{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('static', null, null);

        // Q12
        $this->addSelect("pro_devfactors_q12_exposure_to_medication_alcohol_drugs", "12. Exposure in-utero and breastfeeding to medication, alcohol, or drugs?", self::YES_NO_OPTIONS);

        $this->q12_table(3, "pro_devfactors", "pro_devfactors_q12_exposure_to_medication_alcohol_drugs");

        $this->form->addElement('static', null, null);

        // Q13
        $this->addSelect("pro_devfactors_q13_complications_during_pregnancy_delivery", "13. Complications during pregnancy/delivery?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "pro_devfactors_q13_exclusionary_conditions",
            "",
            self::Q13_DEV_FACTORS_PROBAND_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule("pro_devfactors_q13_exclusionary_conditions", array("pro_devfactors_q13_complications_during_pregnancy_delivery{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "pro_devfactors_q13_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_devfactors_q13_other", array("pro_devfactors_q13_exclusionary_conditions{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q14
        $this->addSelect("pro_devfactors_q14_method_of_delivery", "14. Proband method of delivery", self::Q14_DEV_FACTORS_OPTIONS, array("multiple"));

        $this->form->addElement('text', "pro_devfactors_q14_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_devfactors_q14_other", array("pro_devfactors_q14_method_of_delivery{@}=={@}other"), 'Required if other');

        $this->form->addElement('static', null, null);

        // Q15
        $q15_subquestions = array(
                             "intellectual_disability" => "Intellectual disability (Except in proband with autism)",
                             "schizophrenia"           => "Schizophrenia",
                             "bipolar_disorder"        => "Bipolar Disorder",
                             "psychosis"               => "Psychosis",
                            );

        $this->addSelect("pro_devfactors_q15_first_degree_relative", "15. First degree relative (mom, dad, or full siblings) with:", self::YES_NO_OPTIONS);

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Mother"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Father"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Full sibling"
        );
        $this->addGroup(
            $group,
            "page3_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach ($q15_subquestions as $key => $value) {
            $group[] = $this->createLabel($value);

            $group[] =& $this->createSelect(
                "pro_devfactors_q15_{$key}_mother",
                "Mother",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                "pro_devfactors_q15_{$key}_father",
                "Father",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                "pro_devfactors_q15_{$key}_full_sibling",
                "Full Sibling",
                self::YES_NO_OPTIONS
            );

            $this->XINRegisterRule(
                "pro_devfactors_q15_{$key}_mother",
                array("pro_devfactors_q15_first_degree_relative{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page3_" . $key . "_group"
            );

            $this->XINRegisterRule(
                "pro_devfactors_q15_{$key}_father",
                array("pro_devfactors_q15_first_degree_relative{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page3_" . $key . "_group"
            );

            $this->XINRegisterRule(
                "pro_devfactors_q15_{$key}_full_sibling",
                array("pro_devfactors_q15_first_degree_relative{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page3_" . $key . "_group"
            );

            $this->addGroup(
                $group,
                "page3_" . $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect("pro_devfactors_q15_second_degree_relatives_schizophrenia", $this->indent . "2 or more second degree relatives with schizophrenia?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule("pro_devfactors_q15_second_degree_relatives_schizophrenia", array("pro_devfactors_q15_first_degree_relative{@}=={@}yes"), 'Required if yes');

        $this->form->addElement(
            'static',
            null,
            "<h6><i>All above are exclusionary if any is present except intellectual disability in proband with autism.</i></h6>"
        );
        $this->XINRegisterRule("pro_devfactors_q5a_head_injury", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q1_specific_neurological_problems", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q2_diagnosed_suspected_genetic_conditions", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q2a_family_history_of_genetic_disorders", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q3_genetic_testing_completed", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q4_history_of_seizures", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q5_central_nervous_system_problems", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q6_congenital_heart_problems_abnormalities", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q7_significant_hearing_vision_problems", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q8_mother_gestational_diabetes", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q8b_have_diabetes", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q11a_did_you_breastfeed", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q12_exposure_to_medication_alcohol_drugs", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q13_complications_during_pregnancy_delivery", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q14_method_of_delivery", array("not_finish3{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_devfactors_q15_first_degree_relative", array("not_finish3{@}!={@}1"), 'Required.');

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish4', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));


        $this->form->addElement('static', null, "<h4><b>PROBAND Medical History</b></h4>");

        $this->form->addElement('static', null, null);

        $q1_non_exclusionary_options = array(
                                        null               => "",
                                        "febrile_seizure"  => "febrile seizure",
                                        "rho_gam_exposure" => "Rho gam exposure",
                                        "rsv"              => "RSV",
                                       );

        $q1_exclusionary_options = array(
                                    null                                       => '',
                                    "brain_infection"                          => "Brain infection",
                                    "cancer"                                   => "Cancer",
                                    "drowning_episode_requiring_resuscitation" => "Drowning episode requiring resuscitation prior to autism diagnosis",
                                    "encephalitis"                             => "Encephalitis",
                                    "hypothyroidism"                           => "Hypothyroidism",
                                    "hyperthyroidism"                          => "Hyperthyroidism",
                                    "lead_poisoning"                           => "Lead poisoning",
                                    "meningitis"                               => "Meningitis",
                                    "mitochondrial_disease"                    => "Mitochondrial disease",
                                    "osteogenesis_imperfecta"                  => "Osteogenesis imperfecta",
                                    "phenylketoneuria_PKU"                     => "Phenylketoneuria (PKU)",
                                    "rh_incompatibility_untreated"             => "Rh incompatibility untreated",
                                    "rheumatologic_disorders"                  => "Rheumatologic disorders",
                                    "rubella"                                  => "Rubella",
                                    "shaken_baby_syndrome"                     => "Shaken baby syndrome",
                                    "sickle_cell_anemia"                       => "Sickle cell anemia",
                                    "turner_syndrome"                          => "Turner syndrome",
                                    "other"                                    => "Other",
                                   );

        // Q1
        $this->addSelect("pro_medhist_q1_had_serious_medical_or_surgical_problems", "1. Has PROBAND ever had any serious medical or surgical problems?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_medhist_q1_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("pro_medhist_q1_list", array("pro_medhist_q1_had_serious_medical_or_surgical_problems{@}=={@}yes"), 'Required if yes');

        $this->addSelect(
            "pro_medhist_q1_non_exclusionary_conditions",
            $this->indent . "Non-Exclusionary:",
            $q1_non_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "pro_medhist_q1_non_exclusionary_conditions",
            array("pro_medhist_q1_non_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addSelect(
            "pro_medhist_q1_exclusionary_conditions",
            "",
            $q1_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "pro_medhist_q1_exclusionary_conditions",
            array("pro_medhist_q1_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement('text', "pro_medhist_q1_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_medhist_q1_other", array("pro_medhist_q1_exclusionary_conditions{@}=={@}other"), 'Required if other');

        // Q2
        $this->addSelect("pro_medhist_q2_been_hospitalized", "2. Has PROBAND ever been hospitalized?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_medhist_q2_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("pro_medhist_q2_list", array("pro_medhist_q2_been_hospitalized{@}=={@}yes"), 'Required if yes');

        // Q3
        $this->addSelect("pro_medhist_q3_diagnosed_with_jaundice", "3. Was PROBAND diagnosed with jaundice (hyperbilirubinemia)?<h6><i>Exclusionary if phototherapy greater than 3 days or jaundice related to Rh incompatibility.</i></h6>", self::YES_NO_OPTIONS);
        $this->addSelect("pro_medhist_q3_light_therapy_required", $this->indent . "If yes, light therapy required?", self::YES_NO_NA_OPTIONS);
        $this->XINRegisterRule("pro_medhist_q3_light_therapy_required", array("pro_medhist_q3_diagnosed_with_jaundice{@}=={@}yes"), 'Required if yes');
        $this->form->addElement('text', "pro_medhist_q3_number_of_days", $this->indent . $this->indent . 'If yes, # of days');
        $this->XINRegisterRule("pro_medhist_q3_number_of_days", array("pro_medhist_q3_light_therapy_required{@}=={@}yes"), 'Required if yes');

        // Q4
        $this->addSelect("pro_medhist_q4_had_surgery", "4. Has PROBAND had any surgery?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "pro_medhist_q4_list_with_dates", $this->indent . 'If yes, list with dates:');
        $this->XINRegisterRule("pro_medhist_q4_list_with_dates", array("pro_medhist_q4_had_surgery{@}=={@}yes"), 'Required if yes');

        // Q5
        $this->addSelect("pro_medhist_q5_had_an_MRI_of_the_brain", "5. Has PROBAND ever had an MRI of the brain?", self::YES_NO_OPTIONS);
        $this->addSelect("pro_medhist_q5_results", $this->indent . "If yes, what were the results?", self::Q5_MED_HIST_PROBAND_OPTIONS, array("multiple"));
        $this->XINRegisterRule("pro_medhist_q5_results", array("pro_medhist_q5_had_an_MRI_of_the_brain{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "pro_medhist_q5_other", $this->indent . 'Other:');
        $this->XINRegisterRule("pro_medhist_q5_other", array("pro_medhist_q5_results{@}=={@}other"), 'Required if other');
        $this->XINRegisterRule("pro_medhist_q1_had_serious_medical_or_surgical_problems", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_medhist_q2_been_hospitalized", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_medhist_q3_diagnosed_with_jaundice", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_medhist_q4_had_surgery", array("not_finish4{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("pro_medhist_q5_had_an_MRI_of_the_brain", array("not_finish4{@}!={@}1"), 'Required.');
        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    /**
     * Page 5
     *
     * @return void
     */
    function _page5()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish5', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));


        $this->form->addElement('static', null, "<h4><b>Developmental Factors in INFANT</b></h4>");

        $this->form->addElement('static', null, null);

        $q1_exclusionary_options = array(
                                    null                                  => "",
                                    "cerebral_palsy"                      => "Cerebral palsy",
                                    "cleft_palate"                        => "Cleft palate",
                                    "congenital_hypoventilation_syndrome" => "Congenital hypoventilation syndrome",
                                    "craniosynostosis"                    => "Craniosynostosis",
                                    "epilepsy"                            => "Epilepsy",
                                    "facial_abnormalities"                => "Facial abnormalities (cleft ear or cleft palate)",
                                    "hydrocephaly"                        => "Hydrocephaly",
                                    "family_history_of_marfan_syndrome"   => "Family history of Marfan syndrome",
                                    "muscular_dystrophy"                  => "Muscular dystrophy",
                                    "mytonic_dystrophy"                   => "Mytonic dystrophy",
                                    "neural_tube_defect"                  => "Neural tube defect",
                                    "neurofibromatosis"                   => "Neurofibromatosis",
                                    "spina_bifida"                        => "Spina bifida",
                                    "stroke"                              => "Stroke",
                                    "sturge_weber_syndrome"               => "Sturge Weber syndrome",
                                    "tuberous_sclerosis"                  => "Tuberous sclerosis",
                                    "family_history_of_turner_syndrome"   => "Family history of Turner syndrome",
                                    "family_history_of_soto_syndrome"     => "Family history of Soto syndrome",
                                    "vater_syndrome"                      => "Vater syndrome",
                                    "family_history_of_vater_syndrome"    => "Family history of Vater syndrome",
                                    "von_willebrands_disease"             => "Von Willebrand’s Disease",
                                    "williams_syndrome"                   => "William’s syndrome",
                                    "other"                               => "Other",
                                   );

        // Q1
        $this->addSelect("inf_devfactors_q1_specific_neurological_problems", "1. Any specific neurological problems in infant?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "inf_devfactors_q1_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted. Please review most recent version of exclusionary list.
            Any additional neurological problems reported by family should be reviewed by exclusionary committee.
            Email concerns to botteronk@wustl.edu and cc:\ flakel@wustl.edu and terescook-guercio@wustl.edu.</i></h6>",
            $q1_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q1_exclusionary_conditions",
            array("inf_devfactors_q1_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
        $this->form->addElement('text', "inf_devfactors_q1_other", $this->indent . 'Other:');
        $this->XINRegisterRule("inf_devfactors_q1_other", array("inf_devfactors_q1_exclusionary_conditions{@}=={@}other"), 'Required if other');

        // Q2
        $this->addSelect("inf_devfactors_q2_diagnosed_suspected_genetic_conditions", "2. Diagnosed/suspected genetic conditions in INFANT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q2_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q2_list", array("inf_devfactors_q2_diagnosed_suspected_genetic_conditions{@}=={@}yes"), 'Required if yes');

        // Q3
        $this->addSelect("inf_devfactors_q3_genetic_testing_completed", "3. Genetic testing completed on INFANT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q3_when_and_where", $this->indent . 'If yes, when and where?');
        $this->XINRegisterRule("inf_devfactors_q3_when_and_where", array("inf_devfactors_q3_genetic_testing_completed{@}=={@}yes"), 'Required if yes');

        // Q4
        $this->addSelect("inf_devfactors_q4_had_seizures", "4. Has infant had any seizures?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q4_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q4_list", array("inf_devfactors_q4_had_seizures{@}=={@}yes"), 'Required if yes');

        $q4_non_exclusionary_options = array("febrile_seizures" => "Febrile seizures (not exclusionary)");

        $this->addSelect(
            "inf_devfactors_q4_non_exclusionary_conditions",
            "",
            $q4_non_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q4_non_exclusionary_conditions",
            array("inf_devfactors_q4_non_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        // Q5
        $this->addSelect("inf_devfactors_q5_central_nervous_system_problems", "5. Central nervous system problems in INFANT?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "inf_devfactors_q5_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted.</i></h6>",
            self::Q5_DEV_FACTORS_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q5_exclusionary_conditions",
            array("inf_devfactors_q5_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
        $this->form->addElement('text', "inf_devfactors_q5_other", $this->indent . 'Other:');
        $this->XINRegisterRule("inf_devfactors_q5_other", array("inf_devfactors_q5_exclusionary_conditions{@}=={@}other"), 'Required if other');

        // Q5A
        $this->addSelect("inf_devfactors_q5a_history_of_head_injury", "5a. History of head injury in INFANT?<h6><i>Loss of consciousness or reported findings on any scans exclusionary</i></h6>", self::YES_NO_OPTIONS);

        // Q6
        $this->addSelect("inf_devfactors_q6_congenital_heart_problems_or_abnormalities", "6. Congenital heart problems or abnormalities in INFANT?", self::YES_NO_OPTIONS);
        $this->addSelect(
            "inf_devfactors_q6_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted. Please review most recent version of exclusionary list.
                        Any additional neurological problems reported by family should be reviewed by exclusionary committee.
                        Email concerns to botteronk@wustl.edu and cc:\ flakel@wustl.edu and terescook-guercio@wustl.edu.</i></h6>",
            self::Q6_DEV_FACTORS_OPTIONS,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q6_exclusionary_conditions",
            array("inf_devfactors_q6_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
        $this->form->addElement('text', "inf_devfactors_q6_other", $this->indent . 'Other:');
        $this->XINRegisterRule("inf_devfactors_q6_other", array("inf_devfactors_q6_exclusionary_conditions{@}=={@}other"), 'Required if other');

        // Q7
        $this->addSelect("inf_devfactors_q7_significant_hearing_vision_problems", "7. Significant Hearing/Vision problems in INFANT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q7_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q7_list", array("inf_devfactors_q7_significant_hearing_vision_problems{@}=={@}yes"), 'Required if yes');

        $q7_exclusionary_options = array("bilateral_sensorineural_hearing_loss" => "Bilateral sensorineural hearing loss (exclusionary)");

        $this->addSelect(
            "inf_devfactors_q7_exclusionary_conditions",
            "",
            $q7_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q7_exclusionary_conditions",
            array("inf_devfactors_q7_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        // Q8
        $this->addSelect("inf_devfactors_q8_mother_gestational_diabetes", "8. Did mother have gestational diabetes while pregnant with INFANT?<h6><i>Gestational diabetes requiring insulin or medication is exclusionary.</i></h6>", self::YES_NO_OPTIONS);
        $this->addSelect("inf_devfactors_q8a_if_yes_did_require_insulin_or_medication", "8a. If yes, did gestational diabetes require insulin or medication?", self::YES_NO_NA_OPTIONS);
        $this->XINRegisterRule("inf_devfactors_q8a_if_yes_did_require_insulin_or_medication", array("inf_devfactors_q8_mother_gestational_diabetes{@}=={@}yes"), 'Required if yes');
        $this->addSelect("inf_devfactors_q8b_have_diabetes", "8b. Does INFANT have diabetes?<h6><i>Diabetes in infant is exclusionary.</i></h6>", self::YES_NO_OPTIONS);

        // Q9
        $this->addSelect("inf_devfactors_q9_problems_with_sleep_apnea_or_breathing", "9. Any problems with sleep apnea or breathing during sleep in INFANT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q9_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q9_list", array("inf_devfactors_q9_problems_with_sleep_apnea_or_breathing{@}=={@}yes"), 'Required if yes');

        // Q10
        $this->addSelect("inf_devfactors_q10_gastrointestinal_condition", "10. Any gastrointestinal condition in INFANT?", self::YES_NO_OPTIONS);
        $this->form->addElement('text',  "inf_devfactors_q10_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q10_list", array("inf_devfactors_q10_gastrointestinal_condition{@}=={@}yes"), 'Required if yes');

        $q11_weaned_options = array(
                               null           => "",
                               "weaned"       => "Weaned",
                               "not_weaned"   => "Not Weaned",
                               "not_answered" => "Not Answered",
                              );

        // Q11
        $this->addSelect("inf_devfactors_q11_breastfeeding", "11. Are you breastfeeding INFANT?", self::YES_NO_OPTIONS);
        $this->addSelect("inf_devfactors_q11a_did_you_breastfeed", "11a. Did you ever breastfeed your INFANT?", self::YES_NO_NA_OPTIONS);
        $this->addSelect("inf_devfactors_q11b_if_weaned_how_long_breastfeed", "11b. If weaned, how long did you breastfeed in total?", $q11_weaned_options);

        $this->form->addElement('text', "inf_devfactors_q11b_how_long_breastfeed_weeks", $this->indent . 'Weeks');
        $this->form->addElement('text', "inf_devfactors_q11b_how_long_breastfeed_months", $this->indent . 'Months');

        $this->XINRegisterRule("inf_devfactors_q11b_how_long_breastfeed_weeks", array('inf_devfactors_q11b_if_weaned_how_long_breastfeed{@}=={@}weaned'), 'Required if weaned');
        $this->XINRegisterRule("inf_devfactors_q11b_how_long_breastfeed_months", array('inf_devfactors_q11b_if_weaned_how_long_breastfeed{@}=={@}weaned'), 'Required if weaned');

        // Q12
        $this->addSelect("inf_devfactors_q12_exposure_to_medication_alcohol_drugs", "12. INFANT exposure in-utero or breastfeeding to medication, alcohol, or drugs?", self::YES_NO_OPTIONS);

        $this->q12_table(5, "inf_devfactors", "inf_devfactors_q12_exposure_to_medication_alcohol_drugs");

        $q13_exclusionary_options = array(
                                     null                                                             => '',
                                     "cancer"                                                         => "Cancer",
                                     "cytomegalovirus_CMV_infection"                                  => "Cytomegalovirus CMV infection",
                                     "herpes_infection_while_pregnant_and_infant_delivered_vaginally" => "Herpes infection while pregnant and infant delivered vaginally",
                                     "hypertension_treated_with_medication"                           => "Hypertension treated with medication",
                                     "hypothyroidism"                                                 => "Hypothyroidism",
                                     "placental_abruption"                                            => "Placental abruption",
                                     "sickle_cell_anemia"                                             => "Sickle cell anemia",
                                     "single_umbilical_artery"                                        => "Single umbilical artery",
                                     "umbilical_artery_malformation"                                  => "Umbilical artery malformation",
                                    );

        $q13_review_by_committee_options = array(
                                            null                                => '',
                                            "hyperthyroidism"                   => "Hyperthyroidism",
                                            "parvovirus"                        => "Parvovirus",
                                            "placenta_previa"                   => "Placenta previa",
                                            "preterm_labor"                     => "Preterm labor",
                                            "maternal_prenatal_hospitalization" => "Maternal prenatal hospitalization",
                                            "toxemia_pre_eclampsia"             => "Toxemia (aka pre-eclampsia)",
                                            "other"                             => "Other",
                                           );

        // Q13
        $this->addSelect("inf_devfactors_q13_complications_during_pregnancy_delivery", "13. Complications during pregnancy/delivery?", self::YES_NO_OPTIONS);

        $this->addSelect(
            "inf_devfactors_q13_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted. Please review most recent version of exclusionary list.</i></h6>",
            $q13_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q13_exclusionary_conditions",
            array("inf_devfactors_q13_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addSelect(
            "inf_devfactors_q13_review_by_committee",
            "<h6>All below reviewed by exclusionary committee:</h6>",
            $q13_review_by_committee_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_devfactors_q13_review_by_committee",
            array("inf_devfactors_q13_review_by_committee{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement('text', "inf_devfactors_q13_other", $this->indent . 'Other:');
        $this->XINRegisterRule("inf_devfactors_q13_other", array("inf_devfactors_q13_review_by_committee{@}=={@}other"), 'Required if other');

        // Q14
        $this->addSelect("inf_devfactors_q14_method_of_delivery", "14. Infant method of delivery", self::Q14_DEV_FACTORS_OPTIONS, array("multiple"));
        $this->form->addElement('text', "inf_devfactors_q14_other", $this->indent . 'Other:');
        $this->XINRegisterRule("inf_devfactors_q14_other", array("inf_devfactors_q14_method_of_delivery{@}=={@}yes"), 'Required if other');


        $this->XINRegisterRule("inf_devfactors_q1_specific_neurological_problems", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q2_diagnosed_suspected_genetic_conditions", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q3_genetic_testing_completed", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q4_had_seizures", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q5_central_nervous_system_problems", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q5a_history_of_head_injury", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q6_congenital_heart_problems_or_abnormalities", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q7_significant_hearing_vision_problems", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q8_mother_gestational_diabetes", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q8b_have_diabetes", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q9_problems_with_sleep_apnea_or_breathing", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q10_gastrointestinal_condition", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q11_breastfeeding", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q11a_did_you_breastfeed", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q11b_if_weaned_how_long_breastfeed", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q12_exposure_to_medication_alcohol_drugs", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q13_complications_during_pregnancy_delivery", array("not_finish5{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_devfactors_q14_method_of_delivery", array("not_finish5{@}!={@}1"), 'Required.');
        $this->form->addFormRule(array(&$this, 'validate_page5'));
    }

    /**
     * Page 6
     *
     * @return void
     */
    function _page6()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish6', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));


        $this->form->addElement('static', null, "<h4><b>Medical History in INFANT</b></h4>");

        $this->form->addElement('static', null, null);

        $q1_exclusionary_options = array(
                                    null                                       => '',
                                    "brain_infection"                          => "Brain infection",
                                    "cancer"                                   => "Cancer",
                                    "drowning_episode_requiring_resuscitation" => "Drowning episode requiring resuscitation prior to autism diagnosis",
                                    "encephalitis"                             => "Encephalitis",
                                    "hypothyroidism"                           => "Hypothyroidism",
                                    "hyperthyroidism"                          => "Hyperthyroidism",
                                    "lead_poisoning"                           => "Lead poisoning",
                                    "meningitis"                               => "Meningitis",
                                    "mitochondrial_disease"                    => "Mitochondrial disease",
                                    "osteogenesis_imperfecta"                  => "Osteogenesis imperfecta",
                                    "phenylketoneuria_PKU"                     => "Phenylketoneuria (PKU)",
                                    "rh_incompatibility_untreated"             => "Rh incompatibility untreated",
                                    "rheumatologic_disorders"                  => "Rheumatologic disorders",
                                    "rubella"                                  => "Rubella",
                                    "shaken_baby_syndrome"                     => "Shaken baby syndrome",
                                    "sickle_cell_anemia"                       => "Sickle cell anemia",
                                    "turner_syndrome"                          => "Turner syndrome",
                                   );

        $q6_options = array(
                       null                             => '',
                       "metallic_ear_tubes"             => "Metallic Ear Tubes",
                       "pacemaker"                      => "Pacemaker",
                       "vascular_stints"                => "Vascular Stints",
                       "other_metal_implants_or_braces" => "Other metal implants or braces",
                      );

        // Q1
        $this->addSelect("inf_medhist_q1_had_serious_medical_or_surgical_problems", "1. Has INFANT ever had any serious medical or surgical problems?", self::YES_NO_OPTIONS);

        $this->form->addElement('text', "inf_medhist_q1_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q1_list", array("inf_medhist_q1_had_serious_medical_or_surgical_problems{@}=={@}yes"), 'Required if yes');

        $this->addSelect(
            "inf_medhist_q1_exclusionary_conditions",
            "<h6><i>Conditions below are exclusionary unless otherwise noted. Please review most recent version of exclusionary list.</i></h6>",
            $q1_exclusionary_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "inf_medhist_q1_exclusionary_conditions",
            array("inf_medhist_q1_exclusionary_conditions{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        // Q2
        $this->addSelect("inf_medhist_q2_been_hospitalized", "2. Has INFANT ever been hospitalized?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q2_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q2_list", array("inf_medhist_q2_been_hospitalized{@}=={@}yes"), 'Required if yes');

        // Q3
        $this->addSelect("inf_medhist_q3_complications_with_birth", "3. Were there complications with INFANT’s birth?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q3_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q3_list", array("inf_medhist_q3_complications_with_birth{@}=={@}yes"), 'Required if yes');

        // Q4
        $this->addSelect("inf_medhist_q4_diagnosed_with_jaundice", "4. Was INFANT diagnosed with jaundice (hyperbilirubinemia)?<h6><i>Exclusionary if phototherapy greater than 3 days or jaundice related to Rh incompatibility.</i></h6>", self::YES_NO_OPTIONS);
        $this->addSelect("inf_medhist_q4_light_therapy_required", $this->indent . "If yes, light therapy required?", self::YES_NO_NA_OPTIONS);
        $this->XINRegisterRule("inf_medhist_q4_light_therapy_required", array("inf_medhist_q4_diagnosed_with_jaundice{@}=={@}yes"), 'Required if yes');
        $this->form->addElement('text', "inf_medhist_q4_number_of_days", $this->indent . $this->indent . 'If yes, # of days');
        $this->XINRegisterRule("inf_medhist_q4_number_of_days", array("inf_medhist_q4_light_therapy_required{@}=={@}yes"), 'Required if yes');

        // Q5
        $this->addSelect("inf_medhist_q5_had_surgery", "5. Has INFANT had any surgery?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q5_list_with_dates", $this->indent . 'If yes, list with dates:');
        $this->XINRegisterRule("inf_medhist_q5_list_with_dates", array("inf_medhist_q5_had_surgery{@}=={@}yes"), 'Required if yes');

        // Q6
        $this->addSelect("inf_medhist_q6_have_metal_plates_clips_etc_from_surgery", "6. Does INFANT have any metal plates, clips, etc. from surgery?", self::YES_NO_OPTIONS);
        $this->addSelect("inf_medhist_q6_metal_options", $this->indent . "", $q6_options, array("multiple"));
        $this->XINRegisterRule("inf_medhist_q6_metal_options", array("inf_medhist_q6_have_metal_plates_clips_etc_from_surgery{@}=={@}yes"), 'Required if yes');

        // Q7
        $this->addSelect("inf_medhist_q7_taken_medications_since_birth", "7. Has INFANT taken medications since birth?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q7_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q7_list", array("inf_medhist_q7_taken_medications_since_birth{@}=={@}yes"), 'Required if yes');

        // Q8
        $this->addSelect("inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit", "8. Has INFANT seen doctor for more than a well-baby visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q8_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q8_list", array("inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit{@}=={@}yes"), 'Required if yes');

        // Q9
        $this->addSelect("inf_medhist_q9_had_an_MRI_of_the_brain", "9. Has INFANT ever had an MRI of the brain?", self::YES_NO_OPTIONS);
        $this->addSelect("inf_medhist_q9_results", $this->indent . "If yes, what were the results?", self::Q9_MED_HIST_INFANT_OPTIONS, array("multiple"));
        $this->XINRegisterRule("inf_medhist_q9_results", array("inf_medhist_q9_had_an_MRI_of_the_brain{@}=={@}yes"), 'Required if yes');

        // Q10
        $this->addSelect("inf_medhist_q10_had_anesthesia_or_other_sedation", "10. Has INFANT ever had anesthesia or other forms of sedation?", self::YES_NO_OPTIONS);

        // Q11
        $this->addSelect("inf_medhist_q11_nap_during_the_day", "11. Does infant nap during the day?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q11_when", $this->indent . 'If yes, when?');
        $this->form->addElement('text', "inf_medhist_q11_how_long", $this->indent . 'If yes, how long:');
        $this->XINRegisterRule("inf_medhist_q11_when", array("inf_medhist_q11_nap_during_the_day{@}=={@}yes"), 'Required if yes');
        $this->XINRegisterRule("inf_medhist_q11_how_long", array("inf_medhist_q11_nap_during_the_day{@}=={@}yes"), 'Required if yes');

        $this->addBasicText("inf_medhist_q12_what_time_does_X_go_to_sleep_at_night", "12. What time does X go to sleep at night?");
        $this->XINRegisterRule("inf_medhist_q1_had_serious_medical_or_surgical_problems", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q2_been_hospitalized", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q3_complications_with_birth", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q4_diagnosed_with_jaundice", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q5_had_surgery", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q6_have_metal_plates_clips_etc_from_surgery", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q7_taken_medications_since_birth", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q9_had_an_MRI_of_the_brain", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q10_had_anesthesia_or_other_sedation", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q11_nap_during_the_day", array("not_finish6{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("inf_medhist_q12_what_time_does_X_go_to_sleep_at_night", array("not_finish6{@}!={@}1"), 'Required.');
        $this->form->addFormRule(array(&$this, 'validate_page6'));
    }

    /**
     * Page 7
     *
     * @return void
     */
    function _page7()
    {
        $this->addHeader("Telephone Screening Interview - EP");
        $this->addCheckbox('not_finish7', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));


        $this->form->addElement('static', null, null);

        $race_questions = array(
                           "candidate_race"  => "Candidate Race:",
                           "bio_mother_race" => "Bio-Mother Race:",
                           "bio_father_race" => "Bio-Father Race:",
                          );

        foreach ($race_questions as $key => $question) {
            $this->addSelect($key, $question, self::RACE_OPTIONS, array("multiple"));
        }

        $this->form->addElement('static', null, null);

        $ethnicity_questions = array(
                                "candidate_ethnicity"  => "Candidate Ethnicity:",
                                "bio_mother_ethnicity" => "Bio-Mother Ethnicity:",
                                "bio_father_ethnicity" => "Bio-Father Ethnicity:",
                               );

        foreach ($ethnicity_questions as $key => $question) {
            $this->addSelect($key, $question, self::ETHNICITY_OPTIONS);
        }

        $this->form->addElement('static', null, null);

        $this->addSelect("household_ses_mother_or_combined", "Household SES Mother or combined", self::HOUSEHOLD_SES_OPTIONS);
        $this->addSelect("household_ses_father_if_2_households", "Household SES Father if 2 households", self::HOUSEHOLD_SES_OPTIONS);

        $this->XINRegisterRule("household_ses_mother_or_combined", array("household_ses_mother_or_combined{@}=={@}NEVER_REQUIRED"));
        $this->XINRegisterRule("household_ses_father_if_2_households", array("household_ses_father_if_2_households{@}=={@}NEVER_REQUIRED"));

        $this->form->addElement('static', null, null);

        $scale_of_1_to_10 = array(
                             null                  => "",
                             "0_not_at_all_likely" => "0 - Not at all likely",
                             "1"                   => "1",
                             "2"                   => "2",
                             "3"                   => "3",
                             "4"                   => "4",
                             "5"                   => "5",
                             "6"                   => "6",
                             "7"                   => "7",
                             "8"                   => "8",
                             "9"                   => "9",
                             "10_very_likely"      => "10 - Very likely",
                            );

        $this->addSelect("likelihood_of_child_sleeping_through_a_scan_rating", "On a scale of 1 – 10, please rate the likelihood of your child sleeping through a scan.", $scale_of_1_to_10);

        $this->form->addElement('static', null, null);

        $research_staff_questions = array(
                                     "q1_infant_meets_any_medical_neurological_exclusion_criteria" => "1. This infant meets any of the medical or neurological exclusion criteria for this study.",
                                     "q2_subject_has_evidence_for_contraindication_to_MRI"         => "2. This subject has evidence for contraindication to MRI.",
                                     "q3_proceed_to_next_level_beyond_screening"                   => "3. Proceed to next level beyond screening.",
                                    );

        $this->form->addElement('static', null, "<h4><b>For Research Staff to Complete</b></h4>");

        foreach ($research_staff_questions as $key => $question) {
            $this->addSelect($key, $question, self::YES_NO_OPTIONS);
        }

        $this->addTextAreaElement("if_reviewed_decision", "If reviewed, what was reviewed and what decision was made?");

        $this->addDateElement("date_received_exclusion_review_decision", "Date received exclusion review decision:");
        $this->XINRegisterRule("date_received_exclusion_review_decision", array("date_received_exclusion_review_decision{@}=={@}never_required"), 'Not Required.');


        $this->XINRegisterRule("candidate_race", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_mother_race", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_father_race", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("candidate_ethnicity", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_mother_ethnicity", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("bio_father_ethnicity", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("likelihood_of_child_sleeping_through_a_scan_rating", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q1_infant_meets_any_medical_neurological_exclusion_criteria", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q2_subject_has_evidence_for_contraindication_to_MRI", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("q3_proceed_to_next_level_beyond_screening", array("not_finish7{@}!={@}1"), 'Required.');
        $this->XINRegisterRule("if_reviewed_decision", array("not_finish7{@}!={@}1"), 'Required.');
    }

    function q12_table($page_number, $section_name, $parent_question)
    {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Medication/Alcohol/Drug"
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
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Type"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Dose"
        );
        $this->addGroup(
            $group,
            "page" . $page_number . "_q12_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach (self::Q12_DEV_FACTORS_TABLE as $key => $value) {
            $group[] = $this->createLabel($value);

            $group[] =& $this->createSelect(
                $section_name . "_q12_{$key}_1st_trimester",
                "First Trimester",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                $section_name . "_q12_{$key}_2nd_trimester",
                "Second Trimester",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                $section_name . "_q12_{$key}_3rd_trimester",
                "Third Trimester",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                $section_name . "_q12_{$key}_breastfeeding",
                "Breastfeeding",
                self::YES_NO_OPTIONS
            );

            if (substr($key, 0, 4) == "anti" || substr($key, 0, 3) == "otc" || $key == "mood_stabilizer_anti_psychotics" || $key == "cold_allergy_medicine") {
                $group[] =& $this->createText(
                    $section_name . "_q12_{$key}_type",
                    null,
                    "Type"
                );
                $group[] =& $this->createText(
                    $section_name . "_q12_{$key}_dose",
                    null,
                    "Dose"
                );

                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_type",
                    array("{$section_name}_q12_{$key}_1st_trimester{@}=={@}yes"),
                    "Type Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_type",
                    array("{$section_name}_q12_{$key}_2nd_trimester{@}=={@}yes"),
                    "Type Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_type",
                    array("{$section_name}_q12_{$key}_3rd_trimester{@}=={@}yes"),
                    "Type Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_type",
                    array("{$section_name}_q12_{$key}_breastfeeding{@}=={@}yes"),
                    "Type Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_dose",
                    array("{$section_name}_q12_{$key}_1st_trimester{@}=={@}yes"),
                    "Dose Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_dose",
                    array("{$section_name}_q12_{$key}_2nd_trimester{@}=={@}yes"),
                    "Dose Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_dose",
                    array("{$section_name}_q12_{$key}_3rd_trimester{@}=={@}yes"),
                    "Dose Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
                $this->XINRegisterRule(
                    $section_name . "_q12_{$key}_dose",
                    array("{$section_name}_q12_{$key}_breastfeeding{@}=={@}yes"),
                    "Dose Required.",
                    "page" . $page_number . "_q12_" . $key . "_group"
                );
            }

            $this->XINRegisterRule(
                $section_name . "_q12_{$key}_1st_trimester",
                array("{$parent_question}{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page" . $page_number . "_q12_" . $key . "_group"
            );

            $this->XINRegisterRule(
                $section_name . "_q12_{$key}_2nd_trimester",
                array("{$parent_question}{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page" . $page_number . "_q12_" . $key . "_group"
            );

            $this->XINRegisterRule(
                $section_name . "_q12_{$key}_3rd_trimester",
                array("{$parent_question}{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page" . $page_number . "_q12_" . $key . "_group"
            );

            $this->XINRegisterRule(
                $section_name . "_q12_{$key}_breastfeeding",
                array("{$parent_question}{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page" . $page_number . "_q12_" . $key . "_group"
            );

            $this->addGroup(
                $group,
                "page" . $page_number . "_q12_" . $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement(
            'static',
            null,
            "<h6><i>Medications that are Category D or X are exclusionary. Category C medications are usually exclusionary but best handled on a case-by-case basis.
            Category C exceptions: SSRI treatment during pregnancy or breastfeeding is not exclusionary. Does count as one class C medication exposure.
            Cigarette smoking of greater than 1⁄2 pack (10 cigarettes) per day at any point during pregnancy is exclusionary.</i></h6>"
        );
    }

    function validate_page1($values)
    {
        $errors = [];
        
    if ($values["not_finish0"]!="1"){
        $this->validate_positive_numeric($values, "subject_birth_weight_lbs", $errors);
        $this->validate_positive_numeric($values, "subject_birth_weight_oz", $errors);
        $this->validate_positive_numeric($values, "subject_how_many_weeks_gestation", $errors);

        $this->validate_positive_numeric($values, "proband_birth_weight_lbs", $errors);
        $this->validate_positive_numeric($values, "proband_birth_weight_oz", $errors);
        $this->validate_positive_numeric($values, "proband_how_many_weeks_gestation", $errors);

        if ($values["are_bio_parents_living_in_same_home"] != "no") {
            $this->validate_empty_subquestions($values, ["if_not_in_same_home_childs_primary_address_with"], $errors);
        }
     }    
        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];
        $proband_fields = array();

        if ($values["proband_dob2"] == "" ) {
            if ($values["not_finish2"] != "1") {
            array_push($proband_fields, "Proband Date of Birth");
            }
        }

        if ($values["proband_gender2"] == "") {
            if ($values["not_finish2"] != "1") {
            array_push($proband_fields, "Proband Gender");
            }
        }

        if ($values["proband_live_in_home"] == "") {
            if ($values["not_finish2"] != "1") {
            array_push($proband_fields, "Proband Live in Home");
            }
        }

        $count = count($proband_fields);

        if (!empty($proband_fields)) {
            $errors["proband_group"] = "Required: ";

            foreach ($proband_fields as $field) {
                $errors["proband_group"] .= $field;

                if ($count > 1) {
                    $errors["proband_group"] .= ", ";
                }

                $count--;
            }

            $errors["proband_group"] .= ".";
        }

        if ($values["enrolled_in_other_studies_or_registries"] != "yes") {
            $this->validate_empty_subquestions($values, ["enrolled_in_other_studies_or_registries_list"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["pro_devfactors_q1_exclusionary_conditions"] != "other") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q1_other"], $errors);
        }

        if ($values["pro_devfactors_q2_diagnosed_suspected_genetic_conditions"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q2_list"], $errors);
        }

        if ($values["pro_devfactors_q2a_family_history_of_genetic_disorders"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q2a_list"], $errors);
        }

        if ($values["pro_devfactors_q3_genetic_testing_completed"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q3_list"], $errors);
            $this->validate_empty_subquestions($values, ["pro_devfactors_q3_by_who"], $errors);
        }

        if ($values["pro_devfactors_q4_history_of_seizures"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q4_list"], $errors);
        }

        if ($values["pro_devfactors_q5_exclusionary_conditions"] != "other") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q5_other"], $errors);
        }

        if ($values["pro_devfactors_q6_exclusionary_conditions"] != "other") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q6_other"], $errors);
        }

        if ($values["pro_devfactors_q7_significant_hearing_vision_problems"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q7_list"], $errors);
        }

        if ($values["pro_devfactors_q8_mother_gestational_diabetes"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q8a_if_yes_did_require_insulin_or_medication"], $errors);
        }

        if ($values["pro_devfactors_q11a_did_you_breastfeed"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q11b_how_long_breastfeed_weeks"], $errors);
            $this->validate_empty_subquestions($values, ["pro_devfactors_q11b_how_long_breastfeed_months"], $errors);
        }

        $this->validate_positive_numeric($values, "pro_devfactors_q11b_how_long_breastfeed_weeks", $errors);
        $this->validate_positive_numeric($values, "pro_devfactors_q11b_how_long_breastfeed_months", $errors);

        $q12_subquestions_1 = array(
                               "alcohol",
                               "smoking_vaping",
                               "cannabis_illicit_drugs",
                               "prenatal_vitamins",
                               "herbal_other",
                              );

        $q12_subquestions_2 = array(
                               "cold_allergy_medicine",
                               "antibiotics",
                               "antidepressants",
                               "mood_stabilizer_anti_psychotics",
                               "otc_1",
                               "otc_2",
                               "otc_3",
                               "otc_4",
                              );

        foreach ($q12_subquestions_1 as $key) {
            if ($values["pro_devfactors_q12_exposure_to_medication_alcohol_drugs"] != "yes"
                && ($values["pro_devfactors_q12_" . $key . "_1st_trimester"] != ""
                || $values["pro_devfactors_q12_" . $key . "_2nd_trimester"] != ""
                || $values["pro_devfactors_q12_" . $key . "_3rd_trimester"] != ""
                || $values["pro_devfactors_q12_" . $key . "_breastfeeding"] != "")
            ) {
                $errors["page3_q12_" . $key . "_group"] = $this->indent . "This field should be left blank OR response in the related question should be changed.";
            }
        }

        foreach ($q12_subquestions_2 as $key) {
            // table should be empty
            if ($values["pro_devfactors_q12_exposure_to_medication_alcohol_drugs"] != "yes"
                && ($values["pro_devfactors_q12_" . $key . "_1st_trimester"] != ""
                || $values["pro_devfactors_q12_" . $key . "_2nd_trimester"] != ""
                || $values["pro_devfactors_q12_" . $key . "_3rd_trimester"] != ""
                || $values["pro_devfactors_q12_" . $key . "_breastfeeding"] != ""
                || $values["pro_devfactors_q12_" . $key . "_type"] != ""
                || $values["pro_devfactors_q12_" . $key . "_dose"] != "")
            ) {
                $errors["page3_q12_" . $key . "_group"] = $this->indent . "This field should be left blank OR response in the related question should be changed.";
            }

            // table should be filled out
            if ($values["pro_devfactors_q12_exposure_to_medication_alcohol_drugs"] == "yes"
                && ($values["pro_devfactors_q12_" . $key . "_1st_trimester"] == "yes"
                || $values["pro_devfactors_q12_" . $key . "_2nd_trimester"] == "yes"
                || $values["pro_devfactors_q12_" . $key . "_3rd_trimester"] == "yes"
                || $values["pro_devfactors_q12_" . $key . "_breastfeeding"] == "yes")
                && ($values["pro_devfactors_q12_" . $key . "_type"] == ""
                || $values["pro_devfactors_q12_" . $key . "_dose"] == "")
            ) {
                $errors["page3_q12_" . $key . "_group"] = $this->indent . "Type & Dose Required.";
            }
        }

        $q15_subquestions = array(
                             "intellectual_disability",
                             "schizophrenia",
                             "bipolar_disorder",
                             "psychosis",
                            );

        foreach ($q15_subquestions as $key) {
            if ($values["pro_devfactors_q15_first_degree_relative"] != "yes" && ($values["pro_devfactors_q15_" . $key . "_mother"] != "" || $values["pro_devfactors_q15_" . $key . "_father"] != "" || $values["pro_devfactors_q15_" . $key . "_full_sibling"] != "")) {
                $errors["page3_" . $key . "_group"] = $this->indent . "This field should be left blank OR response in the related question should be changed.";
            }
        }

        if ($values["pro_devfactors_q15_first_degree_relative"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_devfactors_q15_second_degree_relatives_schizophrenia"], $errors);
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        if ($values["pro_medhist_q1_had_serious_medical_or_surgical_problems"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_medhist_q1_list"], $errors);
        }

        if ($values["pro_medhist_q2_been_hospitalized"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_medhist_hist_q2_list"], $errors);
        }

        if ($values["pro_medhist_q3_diagnosed_with_jaundice"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_medhist_q3_light_therapy_required"], $errors);
            $this->validate_empty_subquestions($values, ["pro_medhist_q3_number_of_days"], $errors);
        }

        if ($values["pro_medhist_q3_light_therapy_required"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_medhist_q3_number_of_days"], $errors);
        }

        if ($values["pro_medhist_q4_had_surgery"] != "yes") {
            $this->validate_empty_subquestions($values, ["pro_medhist_q4_list_with_dates"], $errors);
        }

        return $errors;
    }

    function validate_page5($values)
    {
        $errors = [];

        if ($values["inf_devfactors_q2_diagnosed_suspected_genetic_conditions"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q2_list"], $errors);
        }

        if ($values["inf_devfactors_q3_genetic_testing_completed"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q3_when_and_where"], $errors);
        }

        if ($values["inf_devfactors_q4_had_seizures"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q4_list"], $errors);
        }

        if ($values["inf_devfactors_q7_significant_hearing_vision_problems"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q7_list"], $errors);
        }

        if ($values["inf_devfactors_q8_mother_gestational_diabetes"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q8_list"], $errors);
            $this->validate_empty_subquestions($values, ["inf_devfactors_q8a_if_yes_did_require_insulin_or_medication"], $errors);
        }

        if ($values["inf_devfactors_q9_problems_with_sleep_apnea_or_breathing"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q9_list"], $errors);
        }

        if ($values["inf_devfactors_q10_gastrointestinal_condition"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q10_list"], $errors);
        }

        if ($values["inf_devfactors_q11_breastfeeding"] == "yes" && $values["inf_devfactors_q11b_if_weaned_how_long_breastfeed"] == "weaned") {
            $errors["inf_devfactors_q11_breastfeeding"] = "11. and 11b. cannot both be answered 'Yes'";
            $errors["inf_devfactors_q11b_if_weaned_how_long_breastfeed"] = "11. and 11b. cannot both be answered 'Yes'";
        }

        if ($values["inf_devfactors_q11b_if_weaned_how_long_breastfeed"] != "weaned") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q11b_how_long_breastfeed_weeks"], $errors);
            $this->validate_empty_subquestions($values, ["inf_devfactors_q11b_how_long_breastfeed_months"], $errors);
        }

        $this->validate_positive_numeric($values, "inf_devfactors_q11b_how_long_breastfeed_weeks", $errors);
        $this->validate_positive_numeric($values, "inf_devfactors_q11b_how_long_breastfeed_months", $errors);

        $q12_subquestions_1 = array(
                               "alcohol",
                               "smoking_vaping",
                               "cannabis_illicit_drugs",
                               "prenatal_vitamins",
                               "herbal_other",
                              );

        $q12_subquestions_2 = array(
                               "cold_allergy_medicine",
                               "antibiotics",
                               "antidepressants",
                               "mood_stabilizer_anti_psychotics",
                               "otc_1",
                               "otc_2",
                               "otc_3",
                               "otc_4",
                              );

        foreach ($q12_subquestions_1 as $key) {
            if ($values["inf_devfactors_q12_exposure_to_medication_alcohol_drugs"] != "yes"
                && ($values["inf_devfactors_q12_" . $key . "_1st_trimester"] != ""
                || $values["inf_devfactors_q12_" . $key . "_2nd_trimester"] != ""
                || $values["inf_devfactors_q12_" . $key . "_3rd_trimester"] != ""
                || $values["inf_devfactors_q12_" . $key . "_breastfeeding"] != "")
            ) {
                $errors["page5_q12_" . $key . "_group"] = $this->indent . "This field should be left blank OR response in the related question should be changed.";
            }
        }

        foreach ($q12_subquestions_2 as $key) {
            // table should be empty
            if ($values["inf_devfactors_q12_exposure_to_medication_alcohol_drugs"] != "yes"
                && ($values["inf_devfactors_q12_" . $key . "_1st_trimester"] != ""
                || $values["inf_devfactors_q12_" . $key . "_2nd_trimester"] != ""
                || $values["inf_devfactors_q12_" . $key . "_3rd_trimester"] != ""
                || $values["inf_devfactors_q12_" . $key . "_breastfeeding"] != ""
                || $values["inf_devfactors_q12_" . $key . "_type"] != ""
                || $values["inf_devfactors_q12_" . $key . "_dose"] != "")
            ) {
                $errors["page5_q12_" . $key . "_group"] = $this->indent . "This field should be left blank OR response in the related question should be changed.";
            }

            // table should be filled out
            if ($values["inf_devfactors_q12_exposure_to_medication_alcohol_drugs"] == "yes"
                && ($values["inf_devfactors_q12_" . $key . "_1st_trimester"] == "yes"
                || $values["inf_devfactors_q12_" . $key . "_2nd_trimester"] == "yes"
                || $values["inf_devfactors_q12_" . $key . "_3rd_trimester"] == "yes"
                || $values["inf_devfactors_q12_" . $key . "_breastfeeding"] == "yes")
                && ($values["inf_devfactors_q12_" . $key . "_type"] == ""
                || $values["inf_devfactors_q12_" . $key . "_dose"] == "")
            ) {
                $errors["page5_q12_" . $key . "_group"] = $this->indent . "Type & Dose Required.";
            }
        }

        return $errors;
    }

    function validate_page6($values)
    {
        $errors = [];

        if ($values["inf_medhist_q1_had_serious_medical_or_surgical_problems"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q1_list"], $errors);
        }

        if ($values["inf_medhist_q2_been_hospitalized"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q2_list"], $errors);
        }

        if ($values["inf_medhist_q3_complications_with_birth"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q3_list"], $errors);
        }

        if ($values["inf_medhist_q4_diagnosed_with_jaundice"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q4_light_therapy_required"], $errors);
            $this->validate_empty_subquestions($values, ["inf_medhist_q4_number_of_days"], $errors);
        }

        if ($values["inf_medhist_q4_light_therapy_required"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q4_number_of_days"], $errors);
        }

        $this->validate_positive_numeric($values, "inf_medhist_q4_number_of_days", $errors);

        if ($values["inf_medhist_q5_had_surgery"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q5_list_with_dates"], $errors);
        }

        if ($values["inf_medhist_q7_taken_medications_since_birth"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q7_list"], $errors);
        }

        if ($values["inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q8_list"], $errors);
        }

        if ($values["inf_medhist_q11_nap_during_the_day"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q11_when"], $errors);
            $this->validate_empty_subquestions($values, ["inf_medhist_q11_how_long"], $errors);
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
       for($i=0;$i<=7;$i++){
            $checkbox= "not_finish".$i;
            if (!isset($values["$checkbox"])) {
                $values["$checkbox"] = '0';
            }
       } 
        parent::_save($values);
    }
}

